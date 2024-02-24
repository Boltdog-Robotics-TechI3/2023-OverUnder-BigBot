#include "main.h"

/*
FUNCTIONS
*/
//min and max //idk why they wouldnt work other wise
double max(double a, double b){
    return (a > b)? a: b;
}

double min(double a, double b){
    return (a < b)? a: b;
}

/*
CONSTANTS
*/
    // Drive
    const int oneRotationEncoderCount = 3333;


/*
CONTROLLER
*/
    pros::Controller driverController(pros::E_CONTROLLER_MASTER);
    pros::Controller coachController(pros::E_CONTROLLER_PARTNER);

/*
MOTORS
*/
        //TODO: figure out gears
//Drivetrain
    pros::Motor fRDrive(6, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor mRDrive(8, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor bRDrive(10, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor fLDrive(5, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor mLDrive(3, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor bLDrive(1, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor_Group leftDrive({fLDrive, mLDrive, bLDrive});
    pros::Motor_Group rightDrive({fRDrive, mRDrive, bRDrive});

    pros::IMU gyro(8);
//Shooter
    pros::Motor kickerMotor(8, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);

//Wings
    pros::Motor rightWingMotor(9, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftWingMotor(10, pros::E_MOTOR_GEAR_600, true, pros::E_MOTOR_ENCODER_COUNTS);

//Climber
    pros::Motor leftClimbMotor(21, pros::E_MOTOR_GEAR_600, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor rightClimbMotor(20, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor_Group climb({leftClimbMotor, rightClimbMotor});

    pros::Motor climbLock(18, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Rotation rotationSensor(9, false);

