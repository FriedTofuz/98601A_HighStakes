#include "pros/misc.h"
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
    if (Master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
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

// Lady Brown Controls
void ladybrownControl() { 
    if (Master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) { 
        currInput = "Ladybrown";
        LadyBrown.nextState();
    }
}