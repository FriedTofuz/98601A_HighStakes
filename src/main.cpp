#include "main.h"
#include "pros/device.hpp"
#include "pros/rtos.hpp"
#include "systems/classes.hpp"
#include "systems/hardware.hpp"
#include "systems/gui.hpp"


void disabled() {} // DO NOT DELETE

void initialize() {
    chassis.calibrate();
    initialize_display();

    // Intialize hardware settings
    ladybrownMotor.set_brake_mode(pros::MotorBrake::hold);
    ladybrownMotor.set_zero_position(0); 
    leftMotors.set_brake_mode_all(pros::MotorBrake::coast);
    rightMotors.set_brake_mode_all(pros::MotorBrake::coast);
    Intake.allowed = true;
    LadyBrown.currState = 0;

    //Lambda functions (background functions)
    pros::Task backgroundTasks([]{
        float old;
        float delay;
        Intake.discarding = false;
        while (true) {
            LadyBrown.liftControl();
            pros::delay(10);
            if (Intake.discardRing() && LadyBrown.currState != 1) {
                if (!Intake.discarding) {
                    old = stageTwoMotor.get_position();
                    delay = .825;
                    Intake.discarding = true;
                }
            }

            if (Intake.discarding) {
                if (stageTwoMotor.get_position() - old > delay) {
                    Intake.allowed = false;
                    pros::delay(300);
                    Intake.allowed = true;
                    Intake.discarding = false;
                }
            }

            std::cout << ladybrownMotor.get_position() << std::endl;
        };
    });

    //PID Tuning Setup
    // chassis.setPose(0,0,0); // coordinates + heading to 0
    // // chassis.turnToHeading(90,3000);
    // chassis.moveToPoint(0, 24, 3000);
    
}

void autonomous() {
    Intake.setIntakeSpeed(127);
    leftMotors.set_brake_mode_all(pros::MotorBrake::brake);
    rightMotors.set_brake_mode_all(pros::MotorBrake::brake);
    runAuton();
    
}

void opcontrol() {
    Intake.setIntakeSpeed(127);
    leftMotors.set_brake_mode_all(pros::MotorBrake::coast);
    rightMotors.set_brake_mode_all(pros::MotorBrake::coast);

	while (true) {					 
        chassis.arcade(Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), Master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
        intakeControl();
		mogoControl();
		ladybrownControl();
        armControl();
		pros::delay(20); // Run for 30 ms then update
	}
}