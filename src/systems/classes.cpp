#include "systems/classes.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"
#include "pros/colors.hpp"
#include "gui.hpp"
#include <cstring>

// Intake
Intake::Intake(pros::Motor stageOneMotor_, pros::Motor stageTwoMotor_, pros::Optical ringColorSensor_)
    : stageOneMotor(stageOneMotor_), stageTwoMotor(stageTwoMotor_), ringColorSensor(ringColorSensor_) {
    
    intakeTask = std::make_unique<pros::Task>(intakeTaskFn, this, "Intake Task");
}

void Intake::intakeTaskFn(void* param) {
    Intake* self = static_cast<Intake*>(param);

    while (true) {
        if (self->intakeRunning) {
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
            self->stageOneMotor.move(0);
            self->stageTwoMotor.move(0);
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
    if (ringColorSensor.get_proximity() < 200) {
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
    ladybrownMotor.move(kp * (target - ladybrownMotor.get_position()));
}
void LadyBrown::nextState() {
    currState += 1;
        if (currState == 3) {
            currState = 0;
        }
    target = states[currState];
}
void LadyBrown::setState(int State) {
    target = states[State];
}
