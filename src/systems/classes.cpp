#include "systems/classes.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/optical.hpp"
#include "pros/colors.hpp"

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
// void Intake::setSortColor(pros::Color setColor) {
//     setColor;
// }
// void Intake::colorSort(void* param) {
//     pros::Color oldColor = pros::Color::green;
//     if ((ringColorSensor.get_hue() > 200 && ringColorSensor.get_hue() < 230) && ringColorSensor.get_proximity() > 25) {
//         currentRingColor = pros::Color::blue;
//     }
//     else if ((ringColorSensor.get_hue() > 350 || ringColorSensor.get_hue() < 20) && ringColorSensor.get_proximity() > 50) {
//         currentRingColor = pros::Color::red;
//     }
//     else {
//         currentRingColor = pros::Color::green;
//     };
//     if (currentRingColor != setColor && oldColor != currentRingColor) {
//         sortNeeded = true;
//         oldColor = currentRingColor;
//     }
//     else {
//         sortNeeded = false;
//     }
//     oldColor = currentRingColor;
// }

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
