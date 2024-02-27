#include "main.h"
#include <iostream>
using namespace std;

void puncherInit(){
  puncher1.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  puncher2.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

void puncherPeriodic(bool override) {
  	if(driverController.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
			spinPuncher(127 * .8);
		}else{
			spinPuncher(0);
		}
}

// void stopKicker() {
//   kickerMotor.brake();
// }

void spinPuncher(int speed) {
  puncher.move(speed);
}
