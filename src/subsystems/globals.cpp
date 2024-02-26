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
    pros::Motor fRDrive(18, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor mRDrive(19, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor bRDrive(20, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor fLDrive(11, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor mLDrive(12, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor bLDrive(13, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor_Group leftDrive({fLDrive, mLDrive, bLDrive});
    pros::Motor_Group rightDrive({fRDrive, mRDrive, bRDrive});

    pros::IMU gyro(17);

//Shooter
    pros::Motor puncher1(2, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor puncher2(9, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor_Group puncher({puncher1, puncher2});

//Wings
    pros::Motor rightWingMotor(15, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor leftWingMotor(16, pros::E_MOTOR_GEAR_600, true, pros::E_MOTOR_ENCODER_COUNTS);

//Intake

    pros::Motor intake(1, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor arm1(10, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor arm2(8, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor_Group arm({arm1, arm2});

    pros::Rotation rotationSensor(9, false);

