#include "main.h"

/*
FUNCTIONS
*/
    extern double max(double a, double b);
    extern double min(double a, double b);


/*
CONSTANTS
*/
    // Drive 
    extern const int oneRotationEncoderCount;

/*
CONTROLLER
*/
    extern pros::Controller driverController;
    extern pros::Controller coachController;

/*
MOTORS
*/

    //Drivetrain
        extern pros::Motor fLDrive;
        extern pros::Motor mLDrive;
        extern pros::Motor bLDrive;

        extern pros::Motor fRDrive;
        extern pros::Motor mRDrive;
        extern pros::Motor bRDrive;

        extern pros::Motor_Group leftDrive;
        extern pros::Motor_Group rightDrive;

        extern pros::ADIDigitalIn rightBumpSwitch;
        extern pros::ADIDigitalIn leftBumpSwitch;


    //Shooter
        extern pros::Motor kickerMotor;

    //Wings
        extern pros::Motor leftWingMotor;
        extern pros::Motor rightWingMotor;

    //Climber
        extern pros::Motor leftClimbMotor;
        extern pros::Motor rightClimbMotor;

        extern pros::Motor_Group climb;

        extern pros::Motor climbLock;