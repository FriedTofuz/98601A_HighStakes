#include "liblvgl/extra/widgets/chart/lv_chart.h"
#include "pros/device.hpp"
#include "pros/rtos.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "autons.hpp"
#include "systems/hardware.hpp"
#include "systems/classes.hpp"

//DONE
void ringSideBlue() { 
    Intake.allowed = true;

    chassis.setPose(8.7, -0.5,50.25);
    MogoMech.release();
    chassis.moveToPoint(13.5, 3.75, 3000, {.maxSpeed=80, .earlyExitRange=3});
    pros::delay(200);
    LadyBrown.setState(2);
    pros::delay(700);
    LadyBrown.setState(0);
    chassis.moveToPoint(0, -30.5, 2000, {.forwards=false, .maxSpeed=70}, false);
    MogoMech.clamp(); // grab mogo
    pros::delay(200);
    chassis.turnToHeading(-126.75, 1000, {.minSpeed=100, .earlyExitRange=25}); //turn to first ring
    Intake.setIntakeSpeed(127);
    Intake.in(false, false);
    chassis.moveToPoint(-14, -36, 2000, {.maxSpeed=70, .earlyExitRange=15}); //move to line 
    chassis.swingToHeading(-90, lemlib::DriveSide::RIGHT, 500, {.earlyExitRange=25});
    chassis.moveToPoint(-23, -38, 2000, {.maxSpeed=70, .earlyExitRange=5});
    chassis.swingToHeading(85, lemlib::DriveSide::RIGHT, 1500, {.direction=lemlib::AngularDirection::CW_CLOCKWISE, .earlyExitRange=25}); //take third ring
    chassis.turnToHeading(0, 1000);
    chassis.moveToPoint(-10, -3, 1500);   
    chassis.turnToHeading(90, 400);
    chassis.moveToPoint(35, -3, 2500, {.maxSpeed=65});
}

//DONE
void ringSideRed() {
    Intake.allowed = true;

    chassis.setPose(-8.7, -0.5,-50.25);
    MogoMech.release();
    chassis.moveToPoint(-13.5, 3.75, 3000, {.maxSpeed=80, .earlyExitRange=3});
    pros::delay(200);
    LadyBrown.setState(2);
    pros::delay(700);
    LadyBrown.setState(0);
    chassis.moveToPoint(0, -30.5, 2000, {.forwards=false, .maxSpeed=70}, false);
    MogoMech.clamp(); // grab mogo
    pros::delay(200);
    chassis.turnToHeading(126.75, 1000, {.minSpeed=100, .earlyExitRange=25}); //turn to first ring
    Intake.setIntakeSpeed(127);
    Intake.in(false, false);
    chassis.moveToPoint(14, -45, 2000, {.maxSpeed=70, .earlyExitRange=15}); //move to line 
    chassis.swingToHeading(90, lemlib::DriveSide::LEFT, 500, {.earlyExitRange=25});
    chassis.moveToPoint(23, -47, 2000, {.maxSpeed=70, .earlyExitRange=5});
    chassis.swingToHeading(-85, lemlib::DriveSide::LEFT, 1500, {.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE, .earlyExitRange=25}); //take third ring
    chassis.turnToHeading(0, 1000);
    chassis.moveToPoint(10, -3, 1500);   
    chassis.turnToHeading(-90, 400);
    chassis.moveToPoint(-35, -3, 2500, {.maxSpeed=65});
}

//DONE
void goalSideBlue() {
    Intake.allowed = true;
    Intake.stop();
    chassis.setPose(.3,0,0);
    MogoMech.release();
    Intake.setIntakeSpeed(127);
    Intake.in(1, 0);
    chassis.moveToPoint(0, 32.5, 800, {.minSpeed=110},false);
    MogoArm.down();
    chassis.moveToPoint(0, 18, 3000, {.forwards=false}, false);
    MogoArm.up();
    pros::delay(400);
    chassis.moveToPoint(28, 45, 2000, {.forwards=false, .maxSpeed=80}, false);
    MogoMech.clamp();
    pros::delay(500);
    Intake.in(0, 0);
    chassis.turnToHeading(-90, 1000, {.earlyExitRange=20}, false);
    MogoMech.release();
    chassis.moveToPoint(-11, 36, 2000, {.forwards=false, .maxSpeed=70}, false); //second mogo
    MogoMech.clamp();
    pros::delay(300);
    chassis.moveToPoint(22, 13, 1200, {.minSpeed=110, .earlyExitRange=10});
    chassis.turnToHeading(235, 700, {}, false);
    MogoArm.down();
    chassis.moveToPoint(8, -6.5, 1800, {}, false);
    chassis.turnToHeading(320, 2000, {.maxSpeed=70}, false);
    chassis.moveToPoint(0, 24, 1500, {.minSpeed=100, .earlyExitRange=15});
    MogoArm.up();
}

//DONE
void goalSideRed() {
    Intake.allowed = true;
    Intake.stop();
    chassis.setPose(-25, 9.5,46);
    MogoMech.release();
    Intake.setIntakeSpeed(127);
    Intake.in(1, 0);
    chassis.moveToPoint(0, 32, 800, {.minSpeed=110},false);
    MogoArm.down();
    chassis.moveToPoint(0, 18, 3000, {.forwards=false}, false);
    MogoArm.up();
    pros::delay(400);
    chassis.moveToPoint(-28, 45, 2000, {.forwards=false, .maxSpeed=80}, false);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToHeading(90, 700, {});
    Intake.in(0, 0);
    pros::delay(1300);
    MogoMech.release();
    chassis.moveToPoint(11, 36, 2000, {.forwards=false, .maxSpeed=70}, false); //second mogo
    MogoMech.clamp();
    pros::delay(300);
    chassis.turnToHeading(-170, 700);
    MogoArm.down();
    Intake.setIntakeSpeed(-127);
    chassis.moveToPoint(-2.75, 0, 1500);
    chassis.turnToHeading(-120,800, {.maxSpeed=55});
    Intake.setIntakeSpeed(127);
    chassis.moveToPoint(-14, -2.5, 600, {}, false);
    chassis.swingToHeading(-74, lemlib::DriveSide::RIGHT, 1000, {.maxSpeed=55});
    chassis.moveToPoint(-17, 5, 1500);
    MogoArm.up();
}

//DONE
void ringSideBlueAWP() { 
    Intake.allowed = true;

    chassis.setPose(8.7, -0.5,50.25);
    MogoMech.release();
    chassis.moveToPoint(13.5, 3.75, 3000, {.maxSpeed=80, .earlyExitRange=3});
    pros::delay(200);
    LadyBrown.setState(2);
    pros::delay(700);
    LadyBrown.setState(0);
    chassis.moveToPoint(0, -30.5, 2000, {.forwards=false, .maxSpeed=70}, false);
    MogoMech.clamp(); // grab mogo
    pros::delay(200);
    chassis.turnToHeading(-126.75, 1000, {.minSpeed=100, .earlyExitRange=25}); //turn to first ring
    Intake.setIntakeSpeed(127);
    Intake.in(false, false);
    chassis.moveToPoint(-14, -36, 2000, {.maxSpeed=70, .earlyExitRange=15}); //move to line 
    chassis.swingToHeading(-90, lemlib::DriveSide::RIGHT, 500, {.earlyExitRange=25});
    chassis.moveToPoint(-23, -38, 2000, {.maxSpeed=70, .earlyExitRange=5});
    chassis.swingToHeading(85, lemlib::DriveSide::RIGHT, 1500, {.direction=lemlib::AngularDirection::CW_CLOCKWISE, .earlyExitRange=25}); //take third ring
    chassis.turnToHeading(0, 1000);
    chassis.moveToPoint(-10, -3, 1500);   
    chassis.turnToHeading(90, 400);
    chassis.moveToPoint(35, -3, 2500, {.maxSpeed=65});
    chassis.turnToPoint(15, -25, 2000);
    pros::delay(500);
    chassis.moveToPoint(15, -25, 2000, {.maxSpeed=45});
}

//DONE
void ringSideRedAWP() { 
    Intake.allowed = true;

    chassis.setPose(-8.7, -0.5,-50.25);
    MogoMech.release();
    chassis.moveToPoint(-13.5, 3.75, 3000, {.maxSpeed=80, .earlyExitRange=3});
    pros::delay(200);
    LadyBrown.setState(2);
    pros::delay(700);
    LadyBrown.setState(0);
    chassis.moveToPoint(0, -30.5, 2000, {.forwards=false, .maxSpeed=70}, false);
    MogoMech.clamp(); // grab mogo
    pros::delay(200);
    chassis.turnToHeading(126.75, 1000, {.minSpeed=100, .earlyExitRange=25}); //turn to first ring
    Intake.setIntakeSpeed(127);
    Intake.in(false, false);
    chassis.moveToPoint(14, -45, 2000, {.maxSpeed=70, .earlyExitRange=15}); //move to line 
    chassis.swingToHeading(90, lemlib::DriveSide::LEFT, 500, {.earlyExitRange=25});
    chassis.moveToPoint(23, -47, 2000, {.maxSpeed=70, .earlyExitRange=5});
    chassis.swingToHeading(-85, lemlib::DriveSide::LEFT, 1500, {.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE, .earlyExitRange=25}); //take third ring
    chassis.turnToHeading(0, 1000);
    chassis.moveToPoint(10, -3, 1500);   
    chassis.turnToHeading(-90, 400);
    chassis.moveToPoint(-35, -3, 2500, {.maxSpeed=65});
    pros::delay(500);
    chassis.moveToPoint(-25, -25, 2000, {.maxSpeed=45});
}

//DONE
void goalSideRedAWP() {
    Intake.allowed = true;
    chassis.setPose(0,0,0);

    Intake.in(0,0);
    chassis.moveToPose(10, 24, 40.4, 3000, {.minSpeed = 30, .earlyExitRange = 8});
    pros::delay(2575);
    Intake.stop();
    chassis.moveToPose(17, 40, 26.7, 2000, {.minSpeed = 30, .earlyExitRange = 8});
    pros::delay(1500);
    MogoArm.down();
    pros::delay(800);
    chassis.moveToPose(5, -15, 30.83, 2000, {.forwards=false, .minSpeed = 30, .earlyExitRange = 8});
    pros::delay(1000);
    MogoArm.up();
    pros::delay(200);
    chassis.turnToHeading(90, 2000, {.minSpeed = 30, .earlyExitRange = 8});
    chassis.moveToPoint(-26, 1.9, 2000, {.forwards=false, .minSpeed = 30, .earlyExitRange = 8});
    pros::delay(300);
    chassis.turnToHeading(180, 2000, {.minSpeed = 30, .earlyExitRange = 8});
    pros::delay(800);
    LadyBrown.setState(2);
    pros::delay(700);
    chassis.turnToHeading(190, 2000, {.minSpeed = 30, .earlyExitRange = 8});
    pros::delay(200);
    chassis.turnToHeading(170, 2000, {.minSpeed = 30, .earlyExitRange = 8});
    pros::delay(200);
    LadyBrown.setState(0);
    chassis.moveToPoint(-25.5, 20, 2000, {.forwards=false, .minSpeed = 30, .earlyExitRange = 8});
    pros::delay(1000);
    chassis.moveToPose(-10.13, 37.5, 210.15, 2000, {.forwards=false, .minSpeed = 30, .earlyExitRange = 8});
    pros::delay(1200);
    MogoMech.clamp();
    Intake.in(0,0);
    chassis.turnToHeading(-25, 2000, {.minSpeed = 30, .earlyExitRange = 8});
    chassis.moveToPoint(-10, 55, 3000, {.minSpeed = 30, .earlyExitRange = 8});










    // Intake.stop();
    // chassis.setPose(-25, 9.5,46);
    // MogoMech.release();
    // Intake.setIntakeSpeed(127);
    // Intake.in(1, 0);
    // chassis.moveToPoint(8, 46, 800, {.maxSpeed=75},false); //go get the first mogo
    // MogoArm.down();
    // pros::delay(1000);
    // chassis.moveToPose(0, 16, 60, 3000, {.forwards=false}, false); //goal rush swing
    // MogoArm.up();
    // pros::delay(300);
    // chassis.moveToPoint(-28, 45, 2000, {.forwards=false, .maxSpeed=80}, false);
    // MogoMech.clamp();
    // pros::delay(200);
    // chassis.turnToHeading(90, 700, {});
    // Intake.in(0, 0);
    // pros::delay(800);
    // MogoMech.release();
    // chassis.moveToPoint(11, 36, 2000, {.forwards=false, .maxSpeed=70}, false); //second mogo
    // MogoMech.clamp();
    // pros::delay(300);
    // MogoArm.down();
    // chassis.turnToHeading(-170, 700);
    // Intake.setIntakeSpeed(-127);
    // chassis.moveToPoint(-2.75, -3, 1500); //go to the corner?
    // chassis.turnToHeading(-145,800, {.maxSpeed=55});
    // Intake.setIntakeSpeed(127);
    // chassis.moveToPoint(-14, -2.5, 600, {}, false);
    // chassis.swingToHeading(-80, lemlib::DriveSide::RIGHT, 1000, {.maxSpeed=55});
    // chassis.moveToPoint(-17, 5, 1500);
    // MogoArm.up();
    // chassis.moveToPoint(-15, 55, 1500);
}

//DONE
void goalSideBlueAWP() { 
    Intake.allowed = true;
    Intake.stop();
    chassis.setPose(.3,0,0);
    MogoMech.release();
    Intake.setIntakeSpeed(127);
    Intake.in(1, 0);
    chassis.moveToPoint(2.5, 54, 800, {.minSpeed=110},false);
    MogoArm.down();
    chassis.moveToPoint(0, 20, 3000, {.forwards=false}, false);
    MogoArm.up();
    pros::delay(400);
    chassis.moveToPose(20, 46, -141,2000, {.forwards=false, .maxSpeed=80}, false); // 15, 38
    MogoMech.clamp();
    pros::delay(500);
    Intake.in(0, 0);
    pros::delay(800);
    chassis.turnToHeading(-90, 1000, {.earlyExitRange=20}, false);
    MogoMech.release();
    chassis.moveToPoint(-11, 38, 2000, {.forwards=false, .maxSpeed=70}, false); //second mogo
    MogoMech.clamp();
    pros::delay(300);
    chassis.moveToPoint(22, 13, 1200, {.minSpeed=110, .earlyExitRange=10});
    chassis.turnToHeading(235, 700, {}, false);
    MogoArm.down();
    chassis.moveToPoint(8, -6.5, 1800, {}, false);
    chassis.turnToHeading(320, 2000, {.maxSpeed=70}, false);
    chassis.moveToPoint(0, 24, 1500, {.minSpeed=100, .earlyExitRange=15});
    MogoArm.up();
}

void skills() {
    // first quadrant 
    Intake.allowed = true;
    chassis.setPose(-11.5,-1.5,51);
    Intake.setIntakeSpeed(127);
    MogoMech.release();
    LadyBrown.setState(2);
    pros::delay(750);
    LadyBrown.setState(0);
    chassis.moveToPoint(-26, -16, 1000, {.forwards=false, .maxSpeed=95}, false);
    MogoMech.clamp();
    pros::delay(300);
    chassis.turnToHeading(170,400, {.earlyExitRange=10}); //face 1st ring
    Intake.in(false, false);
    chassis.moveToPoint(-28,-26,800, {.earlyExitRange=10}); //move to first ring, eat first ring
    chassis.turnToHeading(210,400, {.earlyExitRange=10}); // turn to far quadrant ring (right)
    chassis.moveToPoint(-43.5,-76,2000, {.maxSpeed=100}); // move to far quadrant ring (right)
    chassis.turnToHeading(360,600, {.earlyExitRange=30}); // turn to face 3rd ring
    LadyBrown.setState(1); 
    chassis.moveToPoint(-37,-61,700, {}); // go toward the thing
    chassis.turnToHeading(265,600,{.earlyExitRange=25});
    chassis.moveToPoint(-56,-56.5,1500, {}, false);
    Intake.setIntakeSpeed(-127);
    pros::delay(30);
    LadyBrown.setState(2); // put down lady brown on wall
    pros::delay(100);
    Intake.setIntakeSpeed(127);
    pros::delay(700);
    chassis.moveToPoint(-43.5,-54,1000, {.forwards=false, .earlyExitRange=10}); //move back out after wall
    chassis.turnToHeading(360,600, {.earlyExitRange=30}); //turn to face 3 rings in a row
    LadyBrown.setState(0);
    chassis.moveToPoint(-46, -20, 2000, {.minSpeed=80, .earlyExitRange=20});
    chassis.moveToPoint(-46,-4,2000, {.maxSpeed=40}); //move forward to eat 3 rings in a row
    chassis.swingToHeading(150, lemlib::DriveSide::LEFT, 1700, {.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE, .maxSpeed=55});
    chassis.moveToPoint(-63, -13, 1500);
    pros::delay(500);
    chassis.moveToPoint(-68, 0,1000, {.forwards=false}, false);
    MogoMech.release();

    chassis.moveToPoint(-25, -8, 1500);
    Intake.stop();
    chassis.turnToHeading(-90, 800);
    // second quadrant 

    chassis.moveToPoint(26, -3, 2500, {.forwards=false, .maxSpeed=75}, false);
    MogoMech.clamp();
    pros::delay(300);
    chassis.turnToHeading(-180,500, {.earlyExitRange=10}); //face 1st ring
    Intake.in(false, false);
    chassis.moveToPoint(22,-26,800, {}); //move to first ring, eat first ring
    chassis.turnToHeading(-225,400, {.earlyExitRange=10}); // turn to far quadrant ring (right)
    chassis.moveToPoint(43.5,-76,2000, {.maxSpeed=100}); // move to far quadrant ring (right)
    chassis.turnToHeading(-360,600, {.earlyExitRange=30}); // turn to face 3rd ring
    LadyBrown.setState(1); 
    chassis.moveToPoint(46,-55.5,800, {}); // go toward the thing
    chassis.turnToHeading(-265,600,{.earlyExitRange=25});
    chassis.moveToPoint(58,-53,2000, {}, false);
    Intake.setIntakeSpeed(-127);
    pros::delay(30);
    LadyBrown.setState(2); // put down lady brown on wall
    pros::delay(100);
    Intake.setIntakeSpeed(127);
    pros::delay(800);
    chassis.moveToPoint(47,-54,1000, {.forwards=false, .earlyExitRange=10}); //move back out after wall
    chassis.turnToHeading(360,600, {.earlyExitRange=30}); //turn to face 3 rings in a row
    LadyBrown.setState(0);
    chassis.moveToPoint(52, -20, 2000, {.minSpeed=80, .earlyExitRange=20});
    chassis.moveToPoint(52,-3,2000, {.maxSpeed=40}); //move forward to eat 3 rings in a row
    chassis.swingToHeading(150, lemlib::DriveSide::RIGHT, 1500, {.direction=lemlib::AngularDirection::CW_CLOCKWISE, .maxSpeed=60});
    chassis.moveToPoint(62, -13, 1500);
    pros::delay(500);
    chassis.moveToPoint(62, 0,1000, {.forwards=false}, false);
    MogoMech.release();
    chassis.moveToPoint(30, -20, 1000);
}