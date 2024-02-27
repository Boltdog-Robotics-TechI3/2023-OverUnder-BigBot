#include "main.h"
#include <iostream>
using namespace std;
#include "lemlib/api.hpp"
#include "okapi/impl/util/timer.hpp"


lemlib::TrackingWheel horizontalTW(&rotationSensor, 2.75, 0.0, 2);

// lemlib's drivetrain object
lemlib::Drivetrain_t drivetrain {
    &leftDrive, // left drivetrain motors
    &rightDrive, // right drivetrain motors
    15.125, // track width
    4.125, // wheel diameter
    200 // wheel rpm
};

lemlib::OdomSensors_t odometry {
    nullptr,
    nullptr,
    nullptr, //&horizontalTW, 
    nullptr, 
    &gyro // inertial sensor
};

// forward/backward PID
lemlib::ChassisController_t lateralController {
    16, // kP
    0.5, // kD
    1, // smallErrorRange
    4000, // smallErrorTimeout
    3, // largeErrorRange
    5000, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    2, // kP
    0, // kD
    1, // smallErrorRange
    4000, // smallErrorTimeout
    3, // largeErrorRange
    5000, // largeErrorTimeout
    0 // slew rate
};

// create the chassis
lemlib::Chassis chassis(drivetrain, lateralController, angularController, odometry);

lemlib::FAPID turnPID{
    0,//ff
    .05,//aceleration
    2.25,//p
    0,//i
    0.2,//d
    "johnny"//name
};

okapi::Timer timer;


void drivetrainInitialize() {
    fLDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    mLDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    bLDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    fRDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    mRDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    bRDrive.set_brake_mode(MOTOR_BRAKE_BRAKE);
    // gyro.reset();
    chassis.calibrate();
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
            y1 = (coachController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
            x2 = (coachController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
        }
        tankDrive(x2, y1);
    }
    else {
        // if (driverController.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        //     //get joysticks for arcade
        //     y1 = driverController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        //     x2 = driverController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        // }
        // else{
            y1 = (driverController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
            x2 = (driverController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
        // }
        arcadeDrive(y1, x2);

    }

    // pros::lcd::set_text(0, "Drivetrain Left Encoder: " + to_string(fLDrive.get_position()));
    pros::lcd::set_text(6, "Drivetrain Right Encoder: " + to_string(fRDrive.get_position()));

        lemlib::Pose pose = chassis.getPose(); // get the current position of the robot
        pros::lcd::print(0, "x: %f", pose.x); // print the x position
        pros::lcd::print(1, "y: %f", pose.y); // print the y position
        pros::lcd::print(2, "heading: %f", pose.theta); // print the heading
        pros::delay(10);

    pros::lcd::print(4, "time", timer.millis());



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

// Auto Rotate to angle using the gyro and lemlib's FAPID class for output calculation (USE THIS ONE FOR AUTO).
void rotateToHeadingPID(double angle){
    int motorVal = 0;
    double error = angle - gyro.get_heading();
    while (timer.getDtFromMark().getValue() < 1000) {
        motorVal = turnPID.update(angle, gyro.get_heading(), false);
        leftDrive.move(motorVal);
        rightDrive.move(-motorVal);
        // master.set_text(1, 0, to_string(gyro.get_heading()));
        driverController.set_text(0, 0, to_string(turnPID.settled()));
        error = angle - gyro.get_heading();
        if (abs(error) < 2) {
            timer.placeMark();
        }
        else {
            timer.clearMark();
        }
    }  
    turnPID.reset();
    leftDrive.move(0);
    rightDrive.move(0);
}

void killSwitch() {
	leftDrive.brake();
	rightDrive.brake();
	leftWingMotor.brake();
	rightWingMotor.brake();
}

// Move to pose from lemlib but made relative.
void moveTo(double xDist, double yDist, int timeout) {
    chassis.setPose(0, 0, 0);
    double y = chassis.getPose().y + yDist;
    double x = chassis.getPose().x + xDist;
    chassis.moveTo(x, y, timeout);
}



