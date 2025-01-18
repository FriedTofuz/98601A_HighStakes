#include "main.h"
#include "systems/classes.hpp"
#include "systems/hardware.hpp"

const int numStates = 3;
int states[3] = {0, 325, 2000};
int currState = 0;
int target = 0;

void nextState() {
    currState += 1;
    if (currState == numStates) {
        currState = 0;
    }
    target = states[currState];
}

void liftControl() {
    double kp = 1.2;
    double error = target - ladybrownMotor.get_position();
    double velocity = kp * error;
    ladybrownMotor.move(velocity);
}

void disabled() {} // DO NOT DELETE

void initialize() {
    chassis.calibrate();
    //initialize_display();

    pros::Task liftControlTask([]{
        while (true) {
            liftControl();
            pros::delay(10);
        }
    });

    /*PID Tuning Setup
    chassis.setPose(0,0,0); // coordinates + heading to 0
    chassis.turnToHeading(90,3000);
    chassis.moveToPoint(0, 24, 3000);
    */

    // Intialize brake mode & postitions
    stageOneMotor.set_brake_mode(pros::MotorBrake::coast);
    stageTwoMotor.set_brake_mode(pros::MotorBrake::coast);
    ladybrownMotor.set_brake_mode(pros::MotorBrake::hold);
    leftMotors.set_brake_mode_all(pros::MotorBrake::brake);
    rightMotors.set_brake_mode_all(pros::MotorBrake::brake);
    ladybrownMotor.set_zero_position(0); 
	Intake.setIntakeSpeed(127);

}

void autonomous() {}

void opcontrol() {
	while (true) {
						 
		driveControl();
		intakeControl();
		mogoControl();
		doinkerControl();
		if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) { 
            nextState();
            pros::delay(200);
        }
		pros::delay(20); // Run for 20 ms then update
	}
}