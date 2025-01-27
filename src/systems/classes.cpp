#include "systems/classes.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"
#include "pros/colors.hpp"
#include "gui.hpp"

// Intake
Intake::Intake(pros::Motor stageOneMotor_, pros::Motor stageTwoMotor_, pros::Optical ringColorSensor_) 
    : stageOneMotor(stageOneMotor_), stageTwoMotor(stageTwoMotor_), ringColorSensor(ringColorSensor_) {}

void Intake::in(bool stageOneOnly, bool stageTwoOnly) {
    if (stageOneOnly) {
        stageOneMotor.move(intakeSpeed);
    } else if (stageTwoOnly) {
        stageTwoMotor.move(intakeSpeed);
    } else {
        stageOneMotor.move(intakeSpeed);
        stageTwoMotor.move(intakeSpeed);
    }
}
void Intake::out() {
    stageOneMotor.move(-intakeSpeed);
    stageTwoMotor.move(-intakeSpeed);
}
void Intake::setIntakeSpeed(int voltage) {
    intakeSpeed = voltage;
}
void Intake::stop() {
    stageOneMotor.move(0);
    stageTwoMotor.move(0);
}
bool Intake::discardRing() {
    std::string color;

    if (ringColorSensor.get_hue() > 340 || ringColorSensor.get_hue() < 20) {
        color = "Red";
    } else if (ringColorSensor.get_hue() > 200 && ringColorSensor.get_hue() < 260) {
        color = "Blue";
    } else {
        color = "None";
    }

    if (color == "None") {
        return false;
    }

    if (color == team) {
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
    ladybrownMotor.move_absolute(target, 100);
}
