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
    MogoMech.release();
    chassis.moveToPoint(13.5, 3.75, 3000, {.maxSpeed=90, .earlyExitRange=3}, false);
    LadyBrown.setState(2);
    pros::delay(500);
    chassis.moveToPoint(0, -30.5, 2000, {.forwards=false, .maxSpeed=80}, false);
    MogoMech.clamp(); // grab mogo
    LadyBrown.setState(0);
    pros::delay(200);
    chassis.turnToHeading(-126.75, 1000, {.minSpeed=100, .earlyExitRange=25}); //turn to first ring
    Intake.setIntakeSpeed(100);
    Intake.in(false, false);
    chassis.moveToPoint(-16, -38, 2000, {.earlyExitRange=15});
    chassis.swingToHeading(-90, lemlib::DriveSide::RIGHT, 500, {.earlyExitRange=25});
    chassis.moveToPoint(-27, -41.5, 2000, {.earlyExitRange=10});
    chassis.swingToHeading(55, lemlib::DriveSide::RIGHT, 500, {.earlyExitRange=25});
    chassis.moveToPoint(-26, -28.5, 2000, {.earlyExitRange=10});
    chassis.turnToHeading(-35, 500, {.earlyExitRange=40});
    // chassis.moveToPoint(-32, -30, 2000);
    chassis.moveToPoint(-37, 10,2000, {.minSpeed=100, .earlyExitRange=10});
    MogoArm.down();
    chassis.turnToHeading(90, 2000, {.maxSpeed=80, .direction=lemlib::AngularDirection::CW_CLOCKWISE, .earlyExitRange=20});
    MogoArm.toggle();
    //chassis.moveToPoint(-23, 2, 2000, {.earlyExitRange=8});
    chassis.moveToPoint(10, -20, 2000, {.earlyExitRange=10});
}

void ringSideRedAWP() {
    //x=-11, y=2.75, 38.5 
    chassis.setPose(-8.7, -0.5,-50.25);
    chassis.moveToPoint(-13.5, 3.75, 3000, {.maxSpeed=50});
    LadyBrown.setState(2);
    chassis.moveToPoint(0, -31, 2000, {.forwards=false, .maxSpeed=80}, false);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToHeading(125.75, 1000);
    Intake.setIntakeSpeed(100);
    Intake.in(false, false);

    chassis.moveToPoint(14.5, -36, 2000, {.earlyExitRange=8});
    chassis.swingToHeading(90, lemlib::DriveSide::LEFT, 2000, {.earlyExitRange=8});
    chassis.moveToPoint(30, -41, 2000, {.earlyExitRange=8});
    chassis.swingToHeading(-50, lemlib::DriveSide::LEFT, 2000, {.earlyExitRange=8});
    chassis.moveToPoint(26, -28.5, 2000, {.earlyExitRange=8});
    chassis.moveToPoint(32, 10, 2000, {.earlyExitRange=8});
    MogoArm.down();
    chassis.turnToHeading(-90, 2000, {.direction=lemlib::AngularDirection::CW_CLOCKWISE, .maxSpeed=50});
    chassis.moveToPoint(23, 2, 2000, {.earlyExitRange=8});
    chassis.moveToPoint(-10, -20, 2000, {.earlyExitRange=8});
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
