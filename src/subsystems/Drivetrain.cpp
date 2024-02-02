#include "main.h"
#include <iostream>
using namespace std;

void drivetrainInitialize() {
    fLDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    mLDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    bLDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    fRDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    mRDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    bRDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
}

void drivetrainPeriodic(bool override) {
    int y1 = 0;
    int x2 = 0;


    //add a dead zone
    // if(abs(y1) < 10) 
    //     y1 = 0;
    // if(abs(x2) < 10) 
    //     x2 = 0;

    if (override) {
        if (coachController.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            //get joysticks for arcade
            y1 = coachController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            x2 = coachController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        }
        else{
            y1 = (coachController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) * .6);
            x2 = (coachController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) * .6);
        }
        tankDrive(x2, y1);
    }
    else {
        if (driverController.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            //get joysticks for arcade
            y1 = driverController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            x2 = driverController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        }
        else{
            y1 = (driverController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) * .6);
            x2 = (driverController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * .6);
        }
        arcadeDrive(y1, x2);
    }

    // pros::lcd::set_text(0, "Drivetrain Left Encoder: " + to_string(fLDrive.get_position()));
    pros::lcd::set_text(6, "Drivetrain Right Encoder: " + to_string(fRDrive.get_position()));


    //arcade drive 


}

//bad
void tankDrive(int left, int right) {
    //brings any numbers out side of range into range
    // left = max(-127, min(127, left));
    // right = max(-127, min(127, right));
    //sets motor speeds
    leftDrive.move(left);
    rightDrive.move(right);
}

//good
void arcadeDrive(int moveValue, int rotateValue) {
    //mixes the numbers
    int leftMotorSpeed = moveValue - rotateValue;
    int rightMotorSpeed = moveValue + rotateValue;
    //determines which is higher
    int mx = max(abs(leftMotorSpeed), abs(rightMotorSpeed));
    //scales both sides evenly based on if max > 127
    if (mx > 127) {
        leftMotorSpeed = (leftMotorSpeed / mx) * 127;
        rightMotorSpeed = (rightMotorSpeed / mx) * 127;
    }
    tankDrive(leftMotorSpeed, rightMotorSpeed);
}

/*
Autonomous Commands
*/

void evenBotWithBeam() {
    if(!(leftBumpSwitch.get_value() && rightBumpSwitch.get_value())) {
        rightDrive = 127;
        leftDrive = 127;
    }
    else{
        if(leftBumpSwitch.get_value()) 
            rightDrive = 127;
        if(rightBumpSwitch.get_value()) 
            leftDrive = 127;
    }

}



void driveStraightDistanceVoltage(int distance) {
	int kP = .1;
	int error = distance - fLDrive.get_position();

	while (abs(error) < 100) {
		int motorVal = error * kP;
		leftDrive.move(motorVal);
		rightDrive.move(motorVal);
	    error = distance - fLDrive.get_position();
	}

	leftDrive.move(0);
	rightDrive.move(0);
}

void driveStraightDistance(int distance, int speed) {
    double targetDistanceLeft = fLDrive.get_position() + distance;
    double targetDistanceRight = fRDrive.get_position() + distance;

    // leftDrive.move_absolute(targetDistanceLeft, speed);
    // rightDrive.move_absolute(targetDistanceRight, speed);

    leftDrive.move_relative(distance, speed);
    rightDrive.move_relative(distance, speed);

    while (abs(abs(targetDistanceLeft) - abs(fLDrive.get_position())) > 20) {
    }

    tankDrive(0, 0);
    pros::delay(200);
}

// Target angle is relative to the robot's current heading, so a 90 will mean the robot will turn 90 degrees
void rotateToHeading(int angle, int speed) {
    // the distance the motor needs to travel in order to reach the desired rotation
    double distance = oneRotationEncoderCount * ((angle - 5) / 360.0);

    // the actual target encoder value for the leftDrive
    double targetDistanceLeft = fLDrive.get_position() + distance;
    double targetDistanceRight = fRDrive.get_position() - distance;

    // set the motors to move to the target positions. (This will move and stop the motors on its own [apparently])
    leftDrive.move_absolute(targetDistanceLeft, speed);
    rightDrive.move_absolute(targetDistanceRight, speed);

    while (abs(abs(targetDistanceLeft) - abs(fLDrive.get_position())) > 50) {
    }

    
    pros::delay(200);
}



// Same goal as the previous method but uses voltage control and a p-controller
// to move the drivebase, instead of the built in position controllers
void rotateToHeadingVoltage(int angle) {
    int kP = 10;

    // the distance the motor needs to travel in order to reach the desired rotation
    int distance = oneRotationEncoderCount * ((angle - 5) / 360);

    // the actual target encoder value
    int targetDistance = fLDrive.get_position() + distance;

    int error = targetDistance - fLDrive.get_position();

    while (abs(error) < 100) {
		int motorVal = error * kP;
		leftDrive.move(motorVal);
		rightDrive.move(-motorVal);
	    int error = targetDistance - fLDrive.get_position();
	}

    leftDrive.move(0);
	rightDrive.move(0);

}

void killSwitch() {
	leftDrive.brake();
	rightDrive.brake();
	leftWingMotor.brake();
	rightWingMotor.brake();
	climb.brake();
}




