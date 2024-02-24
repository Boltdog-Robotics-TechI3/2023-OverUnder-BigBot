#include "main.h"
#include <iostream>
using namespace std;

// bool wingsOut = false;
bool lWingOut = false;
bool rWingOut = false;

void wingsInitialize() {
	leftWingMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
	rightWingMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);

	leftWingMotor.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
	rightWingMotor.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
}

void wingsPeriodic(bool override) {
		if(driverController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
			if(rWingOut){
				flipRightWing(0, 3000);
				rWingOut = false;
			}else{
				flipRightWing(1400, 3000);
				rWingOut = true;
			}
		}
		if(driverController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
			if(lWingOut){
				flipLeftWing(0, 3000);
				lWingOut = false;
			}else{
				flipLeftWing(1400, 3000);
				lWingOut = true;
			}
		}
	

	// currentLock();

    // pros::lcd::set_text(1, "Left Wing Encoder: " + to_string(leftWingMotor.get_position()));
	// pros::lcd::set_text(2, "Right Wing Encoder: " + to_string(leftWingMotor.get_position()));
	// pros::lcd::set_text(4, "Right Wing Current Draw " + to_string(leftWingMotor.get_current_draw()));
}

// Position-Controlled Wings
void flipWings(int position, int speed) {
	flipLeftWing(position, speed);
	flipRightWing(position, speed);
}

void flipLeftWing(int degrees, int speed) {
	leftWingMotor.move_absolute(degrees, speed);
}

void flipRightWing(int degrees, int speed) {
	rightWingMotor.move_absolute(degrees, speed);
}


// Move Motor Directly (would be used for testing)
void manualOpenLeftWing() {
	leftWingMotor.move(100);
}

void manualOpenRightWing() {
	rightWingMotor.move(100);
}

void manualOpenWings() {
	manualOpenLeftWing();
	manualOpenRightWing();
}

// Move Motor Directly (would be used for testing)
void manualCloseLeftWing() {
	leftWingMotor.move(-100);
}

void manualCloseRightWing() {
	rightWingMotor.move(-100);
}

void manualCloseWings() {
	manualCloseLeftWing();
	manualCloseRightWing();
}

// Stop Wing Movement

void stopLeftWing() {
	leftWingMotor.brake();
}

void stopRightWing() {
	rightWingMotor.brake();
}

void stopWings() {
	stopLeftWing();
	stopRightWing();
}





// Brake the motors if they are trying to come in with too high of a current (aka if they caught a triball)
void currentLock() {
	if ((leftWingMotor.get_current_draw() > 2500) && (leftWingMotor.get_direction() == -1)) {
		leftWingMotor.brake();
	}
	if ((rightWingMotor.get_current_draw() > 2500) && (rightWingMotor.get_direction() == -1)) {
		rightWingMotor.brake();
	}


}

