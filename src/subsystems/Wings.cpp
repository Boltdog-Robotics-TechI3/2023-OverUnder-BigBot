#include "main.h"
#include <iostream>
using namespace std;

// bool wingsOut = false;

void wingsInitialize() {
	leftWingMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
	rightWingMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
}

void wingsPeriodic(bool override) {

	if (driverController.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
		// flipLeftWing(300);
		manualOpenLeftWing();
	}
	else if (driverController.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
		// flipLeftWing(0);
		manualCloseLeftWing();
	}
	else if (coachController.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
		// flipWings(300);
		manualOpenWings();
	}
	else if (coachController.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
		// flipWings(300);
		manualCloseWings();
	}
	else {
		stopLeftWing();
	}
	
	if (driverController.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		// flipLeftWing(300);
		manualOpenRightWing();
	}
	else if (driverController.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
		// flipLeftWing(0);
		manualCloseRightWing();
	}
	else {
		stopRightWing();
	}

	// currentLock();

    pros::lcd::set_text(1, "Left Wing Encoder: " + to_string(leftWingMotor.get_position()));
	pros::lcd::set_text(2, "Right Wing Encoder: " + to_string(leftWingMotor.get_position()));
	pros::lcd::set_text(4, "Right Wing Current Draw " + to_string(leftWingMotor.get_current_draw()));
}

// Position-Controlled Wings
void flipWings(int position, int speed) {
	flipLeftWing(position, speed);
	flipRightWing(position, speed);
}

void flipLeftWing(int position, int speed) {
	leftWingMotor.move_absolute(position, speed);
}

void flipRightWing(int position, int speed) {
	rightWingMotor.move_absolute(position, speed);
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

