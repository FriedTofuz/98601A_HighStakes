#include "liblvgl/extra/widgets/chart/lv_chart.h"
#include "pros/device.hpp"
#include "pros/rtos.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "autons.hpp"
#include "systems/hardware.hpp"
#include "systems/classes.hpp"

//progress, need corner
void ringSideBlue() { 
    chassis.setPose(12.5, -12,180);
    LadyBrown.setState(1);
    chassis.turnToHeading(230,400, {}, false);
    Intake.in(false, false, 0);
    MogoMech.release();
    chassis.moveToPoint(9, -15, 1000, {}, false);
    Intake.stop();
    LadyBrown.setState(4);
    pros::delay(800); 
    chassis.moveToPoint(20, 21, 1500, {.forwards=false, .maxSpeed=75}, false); //move to mogo
    LadyBrown.setState(0);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToPoint(38, 27, 800, {.earlyExitRange=30});
    Intake.in(false, false, 0);
    chassis.moveToPoint(34, 27.5, 2000); // eat first ring
    pros::delay(500);
    chassis.moveToPoint(46, 30.5, 2000);
    chassis.moveToPoint(21.5,21,1300,{.forwards = false}, false);
    chassis.moveToPoint(40,15.75,2000, {}, false); //eat ring (by itself in middle)
    chassis.turnToHeading(180, 800);
    chassis.moveToPoint(40, -4, 1000);
    chassis.turnToHeading(135, 800);
    chassis.moveToPoint(52, -20, 1000);
    chassis.swingToHeading(150, lemlib::DriveSide::LEFT, 500);
    chassis.swingToHeading(135, lemlib::DriveSide::LEFT, 500);
    // chassis.moveToPoint(-40, -4, 1000, {.forwards=false});
    // chassis.moveToPoint(-48, -13, 1000);

}

//progress, need corner 
void ringSideRed() {
    chassis.setPose(-12.5, -12,-180);
    LadyBrown.setState(1);
    Intake.in(false, false, 0);
    MogoMech.release();
    chassis.moveToPoint(-6.25, -17.25, 1000, {}, false);
    Intake.stop();
    chassis.turnToHeading(-225,400, {});
    LadyBrown.setState(4);
    pros::delay(800); 
    chassis.moveToPoint(-19, 21, 1500, {.forwards=false, .maxSpeed=75}, false); //move to mogo
    LadyBrown.setState(0);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToPoint(-28, 31, 800, {.earlyExitRange=30});
    Intake.in(false, false, 0);
    chassis.moveToPoint(-26, 30, 2000); // eat first ring
    pros::delay(500);
    chassis.moveToPoint(-48, 35, 2000);
    chassis.moveToPoint(-21.5,21,1300,{.forwards = false}, false);
    chassis.moveToPoint(-40.5,19,2000, {}, false); //eat ring (by itself in middle)
    chassis.moveToPoint(-21.5,21,1300,{.forwards = false}, false);
    chassis.moveToPoint(-40, -10, 1500);
    chassis.turnToHeading(-135, 800);
    chassis.moveToPoint(-57, -21, 1000, {.maxSpeed=60});
    chassis.moveToPoint(-36, -4, 1000, {.forwards=false});
    chassis.moveToPoint(-50, -15, 1000);


}

//
void goalSideBlue() {
    Intake.allowed = true;
    Intake.stop();
    chassis.setPose(.3,0,0);
    MogoMech.release();
    Intake.setIntakeSpeed(127);
    Intake.in(true, false, 0);
    chassis.moveToPoint(0, 32.5, 800, {.minSpeed=110},false);
    MogoArm.down();
    chassis.moveToPoint(0, 18, 3000, {.forwards=false}, false);
    MogoArm.up();
    pros::delay(400);
    chassis.moveToPoint(28, 45, 2000, {.forwards=false, .maxSpeed=80}, false);
    MogoMech.clamp();
    pros::delay(500);
    Intake.in(false, false, 0);
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

//progress
void goalSideRed() {
    Intake.jam = false;
    Intake.stop();
    chassis.setPose(-25, 9.5,46);
    MogoMech.release();
    Intake.setIntakeSpeed(127);
    Intake.in(true, false, 0);
    chassis.moveToPoint(0, 35, 800, {.minSpeed=110},false);
    chassis.turnToHeading(46, 500);
    MogoArm.down();
    Intake.jam=true;
    chassis.moveToPoint(-10, 18, 3000, {.forwards=false}, false);
    MogoArm.up();
    pros::delay(400);
    chassis.moveToPoint(-28, 45, 2000, {.forwards=false, .maxSpeed=80}, false);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToHeading(90, 700, {});
    Intake.in(false, false, 350);
    pros::delay(500);
    MogoMech.release();
    chassis.moveToPoint(11, 36, 2000, {.forwards=false, .maxSpeed=70}, false); //second mogo
    MogoMech.clamp();
    pros::delay(300);
    Intake.in(false, false, 0);
    chassis.moveToPoint(-8, 7, 1500);
    chassis.turnToHeading(-210, 400);
    chassis.moveToPoint(-6.6, -8, 1000, {.maxSpeed=60});
    chassis.moveToPoint(-10, 11, 1500, {.forwards=false, .maxSpeed=70});
    LadyBrown.setState(1);
    Intake.in(false, false, 0);
    pros::delay(700);
    chassis.turnToHeading(23, 1000);
    chassis.moveToPoint(18.5, 36.75, 2000);
    chassis.turnToHeading(-290, 500);
    LadyBrown.setState(3);
}

//DONE, solo wp 12pts
void ringSideBlueAWP() { 
    chassis.setPose(12.5, -12,180);
    LadyBrown.setState(1);
    chassis.turnToHeading(230,400, {}, false);
    Intake.in(false, false, 0);
    MogoMech.release();
    chassis.moveToPoint(7.5, -12, 1000, {.minSpeed = 110}, false);
    Intake.stop();
    LadyBrown.setState(4);
    pros::delay(800); 
    chassis.moveToPoint(20, 21, 1500, {.forwards=false, .maxSpeed=75}, false); //move to mogo
    LadyBrown.setState(0);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToPoint(38, 27, 800, {.earlyExitRange=30});
    Intake.in(false, false, 0);
    chassis.moveToPoint(37.5, 27.5, 2000); // eat first ring
    pros::delay(500);
    chassis.moveToPoint(46, 30.5, 2000);
    chassis.moveToPoint(21.5,21,1300,{.forwards = false}, false);
    chassis.moveToPoint(40,15.75,2000, {}, false); //eat ring (by itself in middle)
    chassis.moveToPoint(7,0,2000, {}, false);
    MogoMech.release();
    Intake.in(false, false, 0);
    chassis.moveToPoint(-18,-9,1000, {}, false);
    Intake.in(true, false, 0);
    chassis.moveToPoint(-31,21,2000, {.forwards=false, .maxSpeed=75}, false);
    MogoMech.clamp();
    pros::delay(300);
    Intake.in(false, false, 0);
    chassis.moveToPoint(-48,18,2000,{}, false);
    chassis.moveToPoint(-28, 21,2000, {.minSpeed=127});
    Intake.in(false, true, 0);
    LadyBrown.setState(3);
}

//DONE, solo wp 12pts
void ringSideRedAWP() { 
    chassis.setPose(-12.5, -12,-180);
    LadyBrown.setState(1);
    chassis.turnToHeading(-230,400, {}, false);
    Intake.in(false, false, 0);
    MogoMech.release();
    chassis.moveToPoint(-6.5, -16, 1000, {.minSpeed = 110}, false);
    Intake.stop();
    LadyBrown.setState(4);
    pros::delay(800); 
    chassis.moveToPoint(-19, 21, 1500, {.forwards=false, .maxSpeed=75}, false); //move to mogo
    LadyBrown.setState(0);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToPoint(-28, 31, 800, {.earlyExitRange=30});
    Intake.in(false, false, 0);
    chassis.moveToPoint(-28.5, 32, 2000); // eat first ring
    pros::delay(500);
    chassis.moveToPoint(-47, 33.5, 2000);
    chassis.moveToPoint(-21.5,21,1300,{.forwards = false}, false);
    chassis.moveToPoint(-40,15.75,2000, {}, false); //eat ring (by itself in middle)
    chassis.moveToPoint(-5,-7,2000, {}, false);
    MogoMech.release();
    Intake.in(false, false, 0);
    chassis.moveToPoint(22.5,-11,1000, {}, false);
    Intake.in(true, false, 0);
    chassis.moveToPoint(31,21,2000, {.forwards=false, .maxSpeed=75}, false);
    MogoMech.clamp();
    pros::delay(300);
    Intake.in(false, false, 0);
    chassis.turnToPoint(58.5, 14, 500, {.earlyExitRange=20});
    chassis.moveToPoint(50,14,2000,{}, false);
    chassis.moveToPoint(35, 31,2000, {.minSpeed=127}, false);
    Intake.in(false, true, 0);
    LadyBrown.setState(3);
}

//DONE solo wp 12pts
void goalSideRedAWP() {
    chassis.setPose(-12.5, -12,-180);
    LadyBrown.setState(1);
    chassis.turnToHeading(-230,400, {}, false);
    Intake.in(false, false, 0);
    MogoMech.release();
    chassis.moveToPoint(-6.5, -16, 1000, {.minSpeed = 110}, false);
    Intake.stop();
    LadyBrown.setState(4);
    pros::delay(800); 
    chassis.moveToPoint(-19, 21, 1500, {.forwards=false, .maxSpeed=75}, false); //move to mogo
    LadyBrown.setState(0);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToPoint(-28, 31, 800, {.earlyExitRange=30});
    Intake.in(false, false, 0);
    chassis.moveToPoint(-28.5, 32, 2000); // eat first ring
    pros::delay(500);
    chassis.moveToPoint(-47, 33.5, 2000);
    chassis.moveToPoint(-21.5,21,1300,{.forwards = false}, false);
    chassis.moveToPoint(-40,15.75,2000, {}, false); //eat ring (by itself in middle)
    chassis.moveToPoint(-5,-7,2000, {}, false);
    MogoMech.release();
    Intake.in(false, false, 0);
    chassis.moveToPoint(22.5,-11,1000, {}, false);
    Intake.in(true, false, 0);
    chassis.moveToPoint(31,21,2000, {.forwards=false, .maxSpeed=75}, false);
    MogoMech.clamp();
    pros::delay(300);
    Intake.in(false, false, 0);
    chassis.turnToPoint(58.5, 14, 500, {.earlyExitRange=20});
    chassis.moveToPoint(50,14,2000,{}, false);
    chassis.moveToPoint(35, 31,2000, {.minSpeed=127}, false);
    Intake.in(false, true, 0);
    LadyBrown.setState(3);
}

//DONE Solo wp 12pts
void goalSideBlueAWP() { 
    chassis.setPose(12.5, -12,180);
    LadyBrown.setState(1);
    chassis.turnToHeading(230,400, {}, false);
    Intake.in(false, false, 0);
    MogoMech.release();
    chassis.moveToPoint(7.5, -12, 1000, {.minSpeed = 110}, false);
    Intake.stop();
    LadyBrown.setState(4);
    pros::delay(800); 
    chassis.moveToPoint(20, 21, 1500, {.forwards=false, .maxSpeed=75}, false); //move to mogo
    LadyBrown.setState(0);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToPoint(38, 27, 800, {.earlyExitRange=30});
    Intake.in(false, false, 0);
    chassis.moveToPoint(37.5, 27.5, 2000); // eat first ring
    pros::delay(500);
    chassis.moveToPoint(46, 30.5, 2000);
    chassis.moveToPoint(21.5,21,1300,{.forwards = false}, false);
    chassis.moveToPoint(40,15.75,2000, {}, false); //eat ring (by itself in middle)
    chassis.moveToPoint(7,0,2000, {}, false);
    MogoMech.release();
    Intake.in(false, false, 0);
    chassis.moveToPoint(-18,-9,1000, {}, false);
    Intake.in(true, false, 0);
    chassis.moveToPoint(-31,21,2000, {.forwards=false, .maxSpeed=75}, false);
    MogoMech.clamp();
    pros::delay(300);
    Intake.in(false, false, 0);
    chassis.moveToPoint(-48,18,2000,{}, false);
    chassis.moveToPoint(-28, 21,2000, {.minSpeed=127});
    Intake.in(false, true, 0);
    LadyBrown.setState(3);
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
    Intake.in(false, false, 0);
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
    Intake.in(false, false, 0);
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