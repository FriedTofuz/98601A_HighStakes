#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include "systems/classes.hpp"
#include "systems/hardware.hpp"

/*  
    Mogomech - L1
    Lady brown - L2
    Intake - R1 (in), R2 (out)
    Doinker - Right Arrow 
*/

// Mogo Mech Controls
void mogoControl() {
    if (Master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
        currInput = "Mogo";
        MogoMech.toggle();
    }
}

// Intake Controls
void intakeControl() {
    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        Intake.in(false, false);
        currInput = "In";
    } else if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        currInput = "Out";
        Intake.out();
    } else {
        Intake.stop();
    }

    // if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    //     Intake.nextState();
    //     pros::delay(200);
    // }
}
//Intake.colorSort(NULL);

// Arm Controls
void armControl() {
    if (Master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        currInput = "Doinker";
        armPiston.toggle();
    }
}

bool forwards;

void resetLadyBrownTask() {
    LadyBrown.resetting = true;
    LadyBrown.moving = true;
    ladybrownMotor.move(-127);
    pros::delay(1000);
    ladybrownMotor.set_zero_position(-165);
    ladybrownMotor.move_velocity(0);
    LadyBrown.resetting = false;

}

// Lady Brown Controls
void ladybrownControl() {
    if (LadyBrown.goNext) {
        if (forwards) {
            for (int i = 0; i < sizeof(LadyBrown.states) / sizeof(LadyBrown.states[0]); i++) {
                if (LadyBrown.states[i] > ladybrownMotor.get_position()) {

                    if (i == 2 && ladybrownMotor.get_position() < 700 && LadyBrown.currState != 1) { // qol for sai bc he has a skill issue
                        LadyBrown.currState = 1;
                        LadyBrown.target = LadyBrown.states[1];
                        break;
                    }

                    LadyBrown.currState = i;
                    LadyBrown.target = LadyBrown.states[i];
                    break;
                }
            }
        } else {
            for (int i = sizeof(LadyBrown.states) / sizeof(LadyBrown.states[0]) - 1; i >= 0; i--) {
                if (LadyBrown.states[i] < ladybrownMotor.get_position()) {
                    LadyBrown.currState = i;
                    LadyBrown.target = LadyBrown.states[i];
                    break;
                }
            }
        }
        LadyBrown.goNext = false;
    }

    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        forwards = true;
        LadyBrown.moving = true;
        currInput = "Ladybrown";

        ladybrownMotor.move(127);
        LadyBrown.goNext = true;
        
    } else if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        forwards = false;
        LadyBrown.moving = true;
        ladybrownMotor.move(-127);
        
        LadyBrown.goNext = true;

    } else {
        if (!LadyBrown.resetting) {
            LadyBrown.moving = false;
        }
    }

    if (Master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
        pros::Task ladybrownTask(resetLadyBrownTask);
    }

    std::cout << ladybrownMotor.get_position() << " " << LadyBrown.currState << std::endl;

    pros::delay(10);
}