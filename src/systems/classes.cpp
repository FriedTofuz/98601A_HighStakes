#include "systems/classes.hpp"
#include "liblvgl/core/lv_obj_draw.h"
#include "systems/hardware.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"
#include "pros/colors.hpp"
#include "gui.hpp"
#include "pros/rtos.hpp"
#include <cstdlib>
#include <cstring>

// Intake
Intake::Intake(pros::Motor stageOneMotor_, pros::Motor stageTwoMotor_, pros::Optical ringColorSensor_)
    : stageOneMotor(stageOneMotor_), stageTwoMotor(stageTwoMotor_), ringColorSensor(ringColorSensor_) {
    
    intakeTask = std::make_unique<pros::Task>(intakeTaskFn, this, "Intake Task");
}

int LadyBrown::currState = 0;

void Intake::intakeTaskFn(void* param) {
    Intake* self = static_cast<Intake*>(param);

    pros::delay(3000);
    while (true) {
        if (self->intakeRunning && self->allowed) {
            if (self->stageOne) {
                self->stageOneMotor.move(self->intakeSpeed);
                self->stageTwoMotor.move(0);
            } else if (self->stageTwo) {
                self->stageOneMotor.move(0);
                self->stageTwoMotor.move(self->intakeSpeed);
            } else {
                self->stageOneMotor.move(self->intakeSpeed);
                self->stageTwoMotor.move(self->intakeSpeed);
            }
        } else {
            if (self->allowed == 0) {
                // self->setIntakeSpeed(-127);
                // self->stageOneMotor.move(-127);
                // self->stageTwoMotor.move(-127);
                self->stageTwoMotor.move(0);
            } else {
                self->setIntakeSpeed(0);
                self->stageOneMotor.move(0);
                self->stageTwoMotor.move(0);
            }
        }

        if (self->intakeRunning && self->stageTwoMotor.get_actual_velocity() < 5 && self->discarding == false && LadyBrown.currState != 1) {
            pros::delay(500);
            if (self->intakeRunning && self->stageTwoMotor.get_actual_velocity() < 5 && self->discarding == false && LadyBrown.currState != 1) {
                self->intakeRunning = false;
                self->stageTwoMotor.move(-127);
                pros::delay(200);
                self->intakeRunning = true;
            }
        }

        pros::delay(10);
    }
}


void Intake::in(bool stageOneOnly, bool stageTwoOnly) {
    // if (stageOneOnly) {
    //     stageOneMotor.move(intakeSpeed);
    // } else if (stageTwoOnly) {
    //     stageTwoMotor.move(intakeSpeed);
    // } else {
    //     stageOneMotor.move(intakeSpeed);
    //     stageTwoMotor.move(intakeSpeed);
    // }
    // pros::delay(10);

    intakeSpeed = 127;
    stageOneOnly = stageOne;
    stageTwoOnly = stageTwo;
    intakeRunning = true; 
}

void Intake::out() {
    // stageOneMotor.move(-intakeSpeed);
    // stageTwoMotor.move(-intakeSpeed);
    
    intakeSpeed = -127;
    intakeRunning = true;
}
void Intake::setIntakeSpeed(int voltage) {
    intakeSpeed = voltage;
}
void Intake::stop() {
    intakeRunning = false;
}

bool Intake::discardRing() {
    ringColorSensor.set_led_pwm(100);

    if (ringColorSensor.get_proximity() < 180) {
        return false;
    }

    if (ringColorSensor.get_hue() > 340 || ringColorSensor.get_hue() < 20) {
        color = "Red";
    } else if (ringColorSensor.get_hue() > 200 && ringColorSensor.get_hue() < 260) {
        color = "Blue";
    } else {
        color = "None";
    }
    
    if (team == nullptr) {
        return false;
    }

    if (color == "None") {
        return false;
    }

    if (team == color) {
        return false;
    } else {
        return true;
    }
}

std::string Intake::getColor() {
    if (ringColorSensor.get_hue() > 340 || ringColorSensor.get_hue() < 20) {
        color = "Red";
    } else if (ringColorSensor.get_hue() > 200 && ringColorSensor.get_hue() < 260) {
        color = "Blue";
    } else {
        color = "None";
    }
    return color;
}

// Mogo Arm (for goal rush)
Arm::Arm(pros::adi::Pneumatics armPiston_, pros::adi::Pneumatics armClampPiston_) 
    : armPiston(armPiston_), armClampPiston(armClampPiston_) {}
void Arm::up() {
    armPiston.retract();
}
void Arm::down() {
    armPiston.extend();
}
void Arm::clamp() {
    armClampPiston.extend();
}
void Arm::release() {
    armClampPiston.retract();
}
void Arm::toggle() {
    armPiston.toggle();
}

// Mogo Mech
MogoMech::MogoMech(pros::adi::Pneumatics mogomechPiston_) 
    : mogomechPiston(mogomechPiston_) {}
void MogoMech::clamp() {
    mogomechPiston.extend();
}
void MogoMech::release() {
    mogomechPiston.retract();
}
void MogoMech::toggle() {
    mogomechPiston.toggle();
}

// Lady Brown 
LadyBrown::LadyBrown(pros::Motor ladybrownMotor_) 
    : ladybrownMotor(ladybrownMotor_) {}
void LadyBrown::liftControl() {
    if (!resetting) {
        if (moveIntake) {
            Intake.out();
            ladybrownMotor.move(kp * (target - ladybrownMotor.get_position()));
            pros::delay(500);
            Intake.stop();
            moveIntake = false;
        } else {
            ladybrownMotor.move(kp * (target - ladybrownMotor.get_position()));
            // if (currState == 3) {
            //     ladybrownMotor.move(-127);
            //     pros::delay(50);
            //     ladybrownMotor.move(0);
            //     ladybrownMotor.set_zero_position(0);
            //     nextState();
            // }
        }
    } else {
        ladybrownMotor.move(-127);
        pros::delay(900);
        ladybrownMotor.move(0);
        pros::delay(300);
        ladybrownMotor.set_zero_position(0);
        resetting = false;
    }
}
void LadyBrown::nextState() {
    currState += 1;

    if (currState == 2) {
        moveIntake = true;
    }

    if (currState == 3) {
        currState = 0;
        resetting = true;
    }

    target = states[currState];
}
void LadyBrown::setState(int State) {
    target = states[State];
}