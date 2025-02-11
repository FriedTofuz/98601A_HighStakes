#include "pros/device.hpp"
#include "pros/rtos.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "autons.hpp"
#include "systems/hardware.hpp"
#include "systems/classes.hpp"

void ringSideBlue() {
    //code here
}

void ringSideRed() {
    //code here
}

void goalSideBlue() {
    //code here
}

void goalSideRed() {
    //code here
}

void ringSideBlueAWP() {
    chassis.setPose(8.7, -0.5,50.25);
    chassis.moveToPoint(13.5, 3.75, 3000, {.maxSpeed=50});
    LadyBrown.setState(2);
    chassis.moveToPoint(0, -30.5, 2000, {.forwards=false, .maxSpeed=80}, false);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToHeading(-126.75, 1000);
    Intake.setIntakeSpeed(100);
    Intake.in(false, false);
    chassis.moveToPoint(-14.5, -37.25, 2000, {.earlyExitRange=8});
    chassis.swingToHeading(-90, lemlib::DriveSide::RIGHT, 2000, {.earlyExitRange=8});
    chassis.moveToPoint(-30, -41, 2000, {.earlyExitRange=8});
    chassis.swingToHeading(50, lemlib::DriveSide::RIGHT, 2000, {.earlyExitRange=8});
    chassis.moveToPoint(-26, -28.5, 2000, {.earlyExitRange=8});
    chassis.moveToPoint(-32, 10, 2000, {.earlyExitRange=8});
    MogoArm.down();
    chassis.turnToHeading(90, 2000, {.direction=lemlib::AngularDirection::CW_CLOCKWISE, .maxSpeed=50});
    chassis.moveToPoint(-23, 2, 2000, {.earlyExitRange=8});
    chassis.moveToPoint(10, -20, 2000, {.earlyExitRange=8});
}

void ringSideRedAWP() {
    chassis.setPose(0, 0, 0);
    MogoMech.release();
    chassis.moveToPoint(0, -32, 2000, {.forwards=false, .maxSpeed=80}, false);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToHeading(130, 2000);
    pros::delay(300);
    Intake.in(false, false);
}

void goalSideRedAWP() {
    //code here
}

void goalSideBlueAWP() {
    //code here
}

void skills() {
    //code here
}
