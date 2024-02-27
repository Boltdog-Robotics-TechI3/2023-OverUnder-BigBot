#include "main.h"

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
		
}

void spinIntake(int speed) {
  intake.move(speed);
}

void holdIntake(){
  intake.move_relative(0, 100);
}