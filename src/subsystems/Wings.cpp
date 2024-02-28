#include "main.h"
#include <iostream>
using namespace std;

// bool wingsOut = false;
bool lWingOut = false;
bool rWingOut = false;

void wingsInitialize(){
	leftWingMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
	rightWingMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);

	leftWingMotor.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
	rightWingMotor.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
}

void wingsPeriodic(bool override)
{
	if (driverController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1))
	{
		flipRightWing();
	}
	if (driverController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1))
	{
		flipLeftWing();
	}

	// currentLock();

	// pros::lcd::set_text(1, "Left Wing Encoder: " + to_string(leftWingMotor.get_position()));
	// pros::lcd::set_text(2, "Right Wing Encoder: " + to_string(leftWingMotor.get_position()));
	// pros::lcd::set_text(4, "Right Wing Current Draw " + to_string(leftWingMotor.get_current_draw()));
}

// Position-Controlled Wings
void flipWings(){
	flipLeftWing();
	flipRightWing();
}

void positionLeftWing(int degrees, int speed)
{
	leftWingMotor.move_absolute(degrees, speed);
}

void positionRightWing(int degrees, int speed)
{
	rightWingMotor.move_absolute(degrees, speed);
}

void flipLeftWing()
{
	if (lWingOut)
	{
		positionLeftWing(0, 3000);
		lWingOut = false;
	}
	else
	{
		positionLeftWing(1800, 3000);
		lWingOut = true;
	}
}

void flipRightWing()
{
	if (rWingOut)
	{
		positionRightWing(0, 3000);
		rWingOut = false;
	}
	else
	{
		positionRightWing(1800, 3000);
		rWingOut = true;
	}
}

// Move Motor Directly (would be used for testing)
void manualOpenLeftWing()
{
	leftWingMotor.move(100);
}

void manualOpenRightWing()
{
	rightWingMotor.move(100);
}

void manualOpenWings()
{
	manualOpenLeftWing();
	manualOpenRightWing();
}

// Move Motor Directly (would be used for testing)
void manualCloseLeftWing()
{
	leftWingMotor.move(-100);
}

void manualCloseRightWing()
{
	rightWingMotor.move(-100);
}

void manualCloseWings()
{
	manualCloseLeftWing();
	manualCloseRightWing();
}

// Stop Wing Movement

void stopLeftWing()
{
	leftWingMotor.brake();
}

void stopRightWing()
{
	rightWingMotor.brake();
}

void stopWings()
{
	stopLeftWing();
	stopRightWing();
}

// Brake the motors if they are trying to come in with too high of a current (aka if they caught a triball)
void currentLock()
{
	if ((leftWingMotor.get_current_draw() > 2500) && (leftWingMotor.get_direction() == -1))
	{
		leftWingMotor.brake();
	}
	if ((rightWingMotor.get_current_draw() > 2500) && (rightWingMotor.get_direction() == -1))
	{
		rightWingMotor.brake();
	}
}
