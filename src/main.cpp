#include "main.h"
#include "systems/classes.hpp"
#include "systems/hardware.hpp"
#include "systems/gui.hpp"


void disabled() {} // DO NOT DELETE

void initialize() {
    chassis.calibrate();
    initialize_display();

    //Lambda functions (background functions)
    pros::Task liftControlTask([]{
        while (true) {
            LadyBrown.liftControl();
            pros::delay(10);
        }
    });

    /*PID Tuning Setup
    chassis.setPose(0,0,0); // coordinates + heading to 0
    chassis.turnToHeading(90,3000);
    chassis.moveToPoint(0, 24, 3000);
    */

    // Intialize hardware settings
    stageOneMotor.set_brake_mode(pros::MotorBrake::coast);
    stageTwoMotor.set_brake_mode(pros::MotorBrake::coast);
    ladybrownMotor.set_brake_mode(pros::MotorBrake::hold);
    ladybrownMotor.set_zero_position(0); 
	Intake.setIntakeSpeed(127);

}

void autonomous() {
    leftMotors.set_brake_mode_all(pros::MotorBrake::brake);
    rightMotors.set_brake_mode_all(pros::MotorBrake::brake);
    runAuton();
}

void opcontrol() {
	while (true) {					 
		driveControl();
		intakeControl();
		mogoControl();
		doinkerControl();
		ladybrownControl();
		pros::delay(20); // Run for 20 ms then update
	}
}