#include "main.h"
#include <iostream>
using namespace std;

void intakeInit(){
    intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void intakePeriodic(bool override) {
  
		if(driverController.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
			spinIntake(127);
			
		} else if(driverController.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
			spinIntake(-70);
		} else {
			holdIntake();
		}
		
		pros::lcd::set_text(4, "intake current" + to_string(intake.get_current_draw()));

}

void spinIntake(int speed) {
  intake.move(speed);
}

void holdIntake(){
  intake.move_relative(0, 100);
}