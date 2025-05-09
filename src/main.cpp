#include "main.h"
#include "pros/misc.h"
#include "pros/motors.hpp"
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
    stageTwoMotor.set_zero_position(0);
    Intake.allowed = true;
    LadyBrown.currState = 0;
    Master.clear();


    //Lambda functions (background functions)
    pros::Task backgroundTasks([]{
        float old;
        float delay;
        Intake.discarding = false;
        while (true) {
            LadyBrown.liftControl();
            // Intake.intakeControl();

            pros::delay(10);

            if (Intake.discardRing() && LadyBrown.currState != 1) {
                if (!Intake.discarding) {
                    Intake.discarding = true;
                }
            }

            if (Intake.discarding) {
                std::cout << "Discarding" << std::endl;
                Intake.allowed = false;
                stageTwoMotor.move(-127);
                pros::delay(1100);
                Intake.allowed = true;
                Intake.discarding = false; 
            }

            int overheat_count = 0;
            std::string motor = "";

            if (stageOneMotor.is_over_temp()) {
                overheat_count++;
                motor = "Stage 1";
            }

            if (stageTwoMotor.is_over_temp()) {
                overheat_count++;
                motor = "Stage 2";
            }

            if (ladybrownMotor.is_over_temp()) {
                overheat_count++;
                motor = "Lady Brown";
            }

            if (leftMotors.is_over_temp()) {
                overheat_count++;
                motor = "Left Motors";
            }

            if (rightMotors.is_over_temp()) {
                overheat_count++;
                motor = "Right Motors";
            }

            if (overheat_count > 1) {
                Master.set_text(1, 0, "Multiple OH            ");
            }

            if (overheat_count == 1) {
                Master.set_text(1, 0, motor + " OH          ");
            }

            // if (Intake.discardRing()) {
            //     if (!Intake.discarding) {
            //         Intake.discarding = true;
            //         Intake.nextState();
            //         pros::delay(2000);
            //         Intake.discarding = false;
            //     }
            // }
        };
    });

    //PID Tuning Setup
    // chassis.setPose(0,0,0); // coordinates + heading to 0
    // // chassis.turnToHeading(90,3000);
    // chassis.moveToPoint(0, 24, 3000);
    
}

void autonomous() {
    Intake.setIntakeSpeed(127);
    leftMotors.set_brake_mode_all(pros::MotorBrake::coast);
    rightMotors.set_brake_mode_all(pros::MotorBrake::coast);
    Intake.jam = true;
    Intake.allowed = true;
    runAuton();
}

void opcontrol() {
    Intake.jam = true;

    Intake.setIntakeSpeed(127);
    leftMotors.set_brake_mode_all(pros::MotorBrake::coast);
    rightMotors.set_brake_mode_all(pros::MotorBrake::coast);

	while (true) {
        float speed = (driveTrain.leftMotors->get_actual_velocity() + driveTrain.rightMotors->get_actual_velocity()) / 2;
        std::string current;
        bool manual = Master.get_digital(pros::E_CONTROLLER_DIGITAL_Y);

        if (speed > 250 && !manual) {
            current = "Curvature";

            int leftY = Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            int rightX = Master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * 1.1;

            chassis.curvature(leftY, rightX);
        } else {
            current = "Arcade";

            chassis.arcade(Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), Master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
        }

        Master.set_text(1, 0, current + "                        ");

        intakeControl();
		mogoControl();
		ladybrownControl();
        armControl();
		pros::delay(20); // Run for 30 ms then update
	}
}