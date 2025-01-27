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
        MogoMech.toggle();
    }
}

// Intake Controls
void intakeControl() {
    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        Intake.in(false, false);
    } else if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        Intake.out();
    } else {
        Intake.stop();
    }
}
//Intake.colorSort(NULL);

// Arm Controls
void armControl() {
    if (Master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        armPiston.toggle();
    }
}

// Lady Brown Controls
void ladybrownControl() { 
    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) { 
        LadyBrown.nextState();
    }
    pros::delay(20);
}