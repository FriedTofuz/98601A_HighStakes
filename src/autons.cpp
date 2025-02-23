#include "liblvgl/extra/widgets/chart/lv_chart.h"
#include "pros/device.hpp"
#include "pros/rtos.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "autons.hpp"
#include "systems/hardware.hpp"
#include "systems/classes.hpp"

void ringSideBlue() {
    //code here
    Intake.allowed = true;

    Intake.in(false, false);
    pros::delay(500);
    Intake.stop();
    pros::delay(500);
    Intake.in(false, false);
}

void ringSideRed() {
    MogoArm.down();
    pros::delay(1000);
    MogoArm.up();
    pros::delay(1000);
}

void goalSideBlue() {
    //code here
    Intake.allowed = true;
}

void goalSideRed() {
    //code here
    Intake.allowed = true;
}

void ringSideBlueAWP() {
    Intake.allowed = true;

    chassis.setPose(8.7, -0.5,50.25);
    MogoMech.release();
    chassis.moveToPoint(13.5, 3.75, 3000, {.maxSpeed=80, .earlyExitRange=3}, false);
    LadyBrown.setState(2);
    pros::delay(500);
    chassis.moveToPoint(0, -30.5, 2000, {.forwards=false, .maxSpeed=80}, false);
    MogoMech.clamp(); // grab mogo
    LadyBrown.setState(0);
    pros::delay(200);
    chassis.turnToHeading(-126.75, 1000, {.minSpeed=100, .earlyExitRange=25}); //turn to first ring
    Intake.setIntakeSpeed(127);
    Intake.in(false, false);
    chassis.moveToPoint(-16, -38, 2000, {.earlyExitRange=15});
    chassis.swingToHeading(-90, lemlib::DriveSide::RIGHT, 500, {.earlyExitRange=25});
    chassis.moveToPoint(-27, -40, 2000, {.maxSpeed=70, .earlyExitRange=5});
    chassis.swingToHeading(55, lemlib::DriveSide::RIGHT, 500, {.earlyExitRange=25});
    chassis.moveToPoint(-26, -28.5, 1500, {.earlyExitRange=10});
    chassis.turnToHeading(-35, 500, {.earlyExitRange=40});
    chassis.moveToPoint(-36, 8,1500, {.maxSpeed=80, .earlyExitRange=10});
    MogoArm.down();
    chassis.turnToHeading(90, 2000, {.direction=lemlib::AngularDirection::CW_CLOCKWISE, .maxSpeed=30, .earlyExitRange=20});
    chassis.moveToPoint(10, -18, 2000, {.earlyExitRange=10});
    MogoArm.up();
}
void ringSideRedAWP() {
    Intake.allowed = true;

    chassis.setPose(-8.7, -0.5,-50.25);
    MogoMech.release();
    chassis.moveToPoint(-13.5, 3.75, 3000, {.maxSpeed=80, .earlyExitRange=3}, false);
    LadyBrown.setState(2);
    pros::delay(500);
    chassis.moveToPoint(5, -30.5, 2000, {.forwards=false, .maxSpeed=80}, false);
    MogoMech.clamp(); // grab mogo
    LadyBrown.setState(0);
    pros::delay(200);
    chassis.turnToHeading(126.75, 1000, {.minSpeed=100, .earlyExitRange=25}); //turn to first ring
    Intake.setIntakeSpeed(127);
    Intake.in(false, false);
    chassis.moveToPoint(14, -43, 2000, {.earlyExitRange=15});
    chassis.swingToHeading(90, lemlib::DriveSide::LEFT, 500, {.earlyExitRange=25});
    chassis.moveToPoint(30, -44, 2000, {.maxSpeed=70, .earlyExitRange=5});
    chassis.swingToHeading(-40, lemlib::DriveSide::LEFT, 500, {.earlyExitRange=25});
    chassis.moveToPoint(26, -22, 1500, {.earlyExitRange=10});
    chassis.turnToHeading(45, 500, {.earlyExitRange=40});
    chassis.moveToPoint(43, 4,1500, {.maxSpeed=80, .earlyExitRange=10});
    MogoArm.down();
    chassis.turnToHeading(-90, 2000, {.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed=30, .earlyExitRange=20});
    chassis.moveToPoint(-12, -18, 2000, {.earlyExitRange=10});
    MogoArm.up();
}

void goalSideRedAWP() {
    //code here
    Intake.allowed = true;
}

void goalSideBlueAWP() {
    Intake.allowed = true;
    chassis.setPose(0,0,0);
    MogoArm.down();
    MogoMech.release();
    MogoArm.release();
    Intake.setIntakeSpeed(127);
    Intake.in(true, 0);
    chassis.moveToPoint(0, 33, 2000, {.earlyExitRange=5},false);
    MogoArm.clamp();
    pros::delay(2000);
    chassis.moveToPoint(0, 23, 3000, {.forwards=false});
    MogoArm.release();
    MogoArm.up();
    chassis.moveToPoint(27, 44.75, 2000, {.forwards=false, .maxSpeed=80}, false);
    MogoMech.clamp();
    Intake.in(0, 0);
    chassis.moveToPoint(29.5, 25.5, 2000);
    Intake.stop();
    MogoMech.release();
    chassis.moveToPoint(-5.25, 40, 2000, {.forwards=false}, false);
    MogoMech.clamp();
    Intake.in(false, false);
}

void skills() {
    Intake.allowed = true;

    // chassis.setPose(0,0,0);
    // Intake.setIntakeSpeed(127);
    // MogoMech.release();
    // Intake.setIntakeSpeed(127);
    // Intake.in(false, false);
    // pros::delay(1000);
    // Intake.stop();
    // chassis.moveToPoint(float x, float y, int timeout);
    // chassis.turnToHeading(-90, 1000);
    // chassis.moveToPoint(float x, float y, int timeout, {.forward=false});
    // MogoMech.clamp();
    // pros::delay(300);
    // chassis.turnToHeading(0, 1000);
    // chassis.moveToPoint(float x, float y, int timeout);
    // chassis.turnToHeading(float theta, int timeout);
    // chassis.moveToPoint(float x, float y, int timeout);
    // chassis.turnToHeading(180, 2000);
    // chassis.moveToPoint(float x, float y, int timeout); //move in front of first wall stake 
    // chassis.turnToHeading(90, 1000);
    // chassis.moveToPoint(float x, float y, int timeout);
    // LadyBrown.setState(2);
    // pros::delay(const uint32_t milliseconds);

}
