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

// progress
void goalSideBlue() {
Intake.jam = false;
    Intake.stop();
    chassis.setPose(25, 9.5,-46);
    MogoMech.release();
    Intake.setIntakeSpeed(127);
    Intake.in(true, false, 0);
    chassis.moveToPoint(0, 35, 800, {.minSpeed=110},false);
    chassis.turnToHeading(-46, 500);
    MogoArm.down();
    Intake.jam=true;
    chassis.moveToPoint(10, 18, 3000, {.forwards=false}, false);
    MogoArm.up();
    pros::delay(400);
    chassis.moveToPoint(15, 48, 2000, {.forwards=false, .maxSpeed=80}, false);
    MogoMech.clamp();
    pros::delay(200);
    Intake.in(false, false, 350);
    pros::delay(500);
    MogoMech.release();
    chassis.turnToHeading(0, 700, {});
    chassis.moveToPoint(-13, 36, 2000, {.forwards=false, .maxSpeed=70}, false); //second mogo
    MogoMech.clamp();
    pros::delay(300);
    Intake.in(false, false, 0);
    
    chassis.moveToPoint(25 , 13, 2000, {.maxSpeed=100});
    chassis.turnToHeading(149, 400);
    chassis.moveToPoint(28, 10, 1000, {.maxSpeed=60});
    chassis.moveToPoint(25 , 13, 1500, {.forwards=false, .maxSpeed=70});
    LadyBrown.setState(1);
    Intake.in(false, false, 0);
    pros::delay(700);
    chassis.turnToHeading(290, 1000);
    chassis.moveToPoint(-16, 27, 2000);
    chassis.turnToHeading(241, 500);
    LadyBrown.setState(3);
}

// DONE 9pts
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
    Intake.discard = false;
    chassis.setPose(12.5, -12,180);
    LadyBrown.setState(1);
    chassis.turnToHeading(228,300, {}, false);
    Intake.in(false, false, 0);
    MogoMech.release();
    chassis.moveToPoint(7.25, -12.25, 800, {.minSpeed = 110}, false);
    Intake.stop();
    LadyBrown.setState(4);
    pros::delay(800); 
    chassis.turnToHeading(235, 300);
    chassis.moveToPoint(20, 21, 2000, {.forwards=false, .maxSpeed=80}, false); //move to mogo
    LadyBrown.setState(0);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToPoint(38, 27, 1000, {.earlyExitRange=30});
    Intake.in(false, false, 0);
    chassis.moveToPoint(37.5, 27.5, 2000); // eat first ring
    pros::delay(500);
    chassis.moveToPoint(45.5, 29, 2000);
    chassis.moveToPoint(21.5,21,1300,{.forwards = false}, false);
    chassis.moveToPoint(40,15.75,2000, {}, false); //eat ring (by itself in middle)
    chassis.moveToPoint(7,0,2000, {}, false);
    MogoMech.release();
    Intake.in(false, false, 0);
    chassis.moveToPoint(-18,-11,1000, {}, false);
    Intake.in(true, false, 0);
    chassis.moveToPoint(-31,21,1500, {.forwards=false, .maxSpeed=75}, false);
    MogoMech.clamp();
    pros::delay(300);
    Intake.in(false, false, 0);
    chassis.moveToPoint(-48,18,2000,{}, false);
    chassis.moveToPoint(-28, 21,2000, {.minSpeed=127});
    Intake.in(false, true, 0);
    pros::delay(750);
    LadyBrown.setState(3);
}

//DONE Solo wp 12pts
void goalSideBlueAWP() { 
    Intake.discard = false;
    chassis.setPose(12.5, -12,180);
    LadyBrown.setState(1);
    chassis.turnToHeading(228,300, {}, false);
    Intake.in(false, false, 0);
    MogoMech.release();
    chassis.moveToPoint(7.25, -12.25, 800, {.minSpeed = 110}, false);
    Intake.stop();
    LadyBrown.setState(4);
    pros::delay(800); 
    chassis.turnToHeading(235, 300);
    chassis.moveToPoint(20, 21, 2000, {.forwards=false, .maxSpeed=80}, false); //move to mogo
    LadyBrown.setState(0);
    MogoMech.clamp();
    pros::delay(200);
    chassis.turnToPoint(38, 27, 1000, {.earlyExitRange=30});
    Intake.in(false, false, 0);
    chassis.moveToPoint(37, 27.5, 2000); // eat first ring
    chassis.moveToPoint(45.5, 28.75, 2000, {.maxSpeed=60});
    chassis.moveToPoint(21.5,21,1300,{.forwards = false}, false);
    chassis.moveToPoint(40,15.75,2000, {}, false); //eat ring (by itself in middle)
    chassis.moveToPoint(7,0,2000, {}, false);
    MogoMech.release();
    Intake.in(false, false, 0);
    chassis.moveToPoint(-18,-11,1000, {}, false);
    Intake.in(true, false, 0);
    chassis.moveToPoint(-31,21,1500, {.forwards=false, .maxSpeed=75}, false);
    MogoMech.clamp();
    pros::delay(300);
    Intake.in(false, false, 0);
    chassis.moveToPoint(-48,18,2000,{}, false);
    chassis.moveToPoint(-28, 21,2000, {.minSpeed=127});
    Intake.in(false, true, 0);
    pros::delay(750);
    LadyBrown.setState(3);
}

//DONE, solo wp 12pts
void ringSideRedAWP() { 
    Intake.discard = false;
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
    chassis.moveToPoint(-28.5, 32.6, 2000); // eat first ring
    chassis.moveToPoint(-48, 34.5, 2000, {.maxSpeed=50});
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
    chassis.moveToPoint(52,14,2000,{}, false);
    chassis.moveToPoint(43, 28,2000, {.minSpeed=127});
    Intake.in(false, true, 0);
    pros::delay(500);
    LadyBrown.setState(3);
}

//DONE, solo wp 12pts
void goalSideRedAWP() {
    Intake.discard = false;
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
    chassis.moveToPoint(-28.5, 32.6, 2000); // eat first ring
    chassis.moveToPoint(-48, 34.5, 2000, {.maxSpeed=50});
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
    chassis.moveToPoint(52,14,2000,{}, false);
    chassis.moveToPoint(43, 28,2000, {.minSpeed=127});
    Intake.in(false, true, 0);
    pros::delay(500);
    LadyBrown.setState(3);
}


void skills() {
    chassis.setPose(0,0,0);
    LadyBrown.setState(1);
    pros::delay(100);
    Intake.in(false, false, 0);
    pros::delay(300);
    Intake.stop();
    pros::delay(500);
    LadyBrown.setState(4);
    pros::delay(1500);
    Intake.in(false, false, 0);
    chassis.moveToPoint(-26, -6, 1500, {.forwards=false, .maxSpeed=70}, false); //first mogo 
    LadyBrown.setState(0);
    MogoMech.clamp();
    chassis.turnToHeading(180, 1000); //first ring
    chassis.moveToPoint(-26, -25.5, 1500); 
    chassis.turnToHeading(210, 1000); 
    chassis.moveToPoint(-44.5, -55, 1500, {.earlyExitRange=20});
    chassis.moveToPoint(-47, -75, 1500, {}, false);  // far second ring
    pros::delay(600); 
    chassis.moveToPoint(-41, -52, 1500, {.forwards=false}); 
    chassis.turnToHeading(270, 1000, {},false);
    LadyBrown.setState(1);
    chassis.moveToPoint(-57.5, -52, 1500, {}, false); //move to wall stake 1
    pros::delay(1000);
    LadyBrown.setState(5);
    pros::delay(1500);
    Intake.in(false, false, 0);
    chassis.moveToPoint(-43.5, -54, 1500, {.forwards=false});
    LadyBrown.setState(0);
    chassis.turnToHeading(360, 1000);
    Intake.in(false, false, 0);
    chassis.moveToPoint(-45.5, -24, 1500, {.maxSpeed=80}); //three rings
    chassis.moveToPoint(45.5, 2, 1500, {.maxSpeed=40}); 
    chassis.turnToHeading(245, 1000);
    chassis.moveToPoint(-58, -2, 1500);
    chassis.turnToHeading(150, 700);
    chassis.moveToPoint(-65, 1, 1500, {.forwards=false});
    pros::delay(300);
    MogoMech.release();
    chassis.moveToPoint(1, -3.5, 1500);
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPoint(19.5, -3.5, 1500, {.forwards=false, .maxSpeed=60});
    MogoMech.clamp();
    chassis.turnToHeading(-180, 1000);
    chassis.moveToPoint(19, -28, 1000); // 2nd quad first ring 
    chassis.turnToHeading(-220, 700);
    chassis.moveToPoint(35, -55, 1000);
    chassis.turnToHeading(-190, 1000);
    chassis.moveToPoint(40.5, -76.5, 1000); // 2nd quad far 2 ring
    chassis.moveToPoint(37.5, -58.5, 1000, {.forwards=false});
    chassis.turnToHeading(-270, 800);
    LadyBrown.setState(1);  
    chassis.moveToPoint(54, -59, 1000, {}, false);
    LadyBrown.setState(5);  
    pros::delay(2000);
    chassis.moveToPoint(46, -58, 1000, {.forwards=false});
    LadyBrown.setState(0);
    chassis.turnToHeading(-360, 1000);
    chassis.moveToPoint(46, -30, 1500);
    chassis.moveToPoint(46, -2, 1500, {.maxSpeed=40});
    chassis.turnToHeading(-220, 1000);
    chassis.moveToPoint(54, -8, 1000);
    chassis.turnToHeading(-150, 1000);
    chassis.moveToPoint(58, 1, 1000, {.forwards=false});    
    MogoMech.release(); 
}