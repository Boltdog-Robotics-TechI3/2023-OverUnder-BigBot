#include "main.h"
#include <iostream>
using namespace std;

void climberInitialize() {
    leftClimbMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
    rightClimbMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void climberPeriodic(bool override) {
    if (driverController.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
        manualRaiseClimber();
    }
    else if (driverController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        manualLowerClimber();
    }
    else {
        stopClimber();
    }

    if (coachController.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        lockClimb();
    }

    else if (coachController.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        unlockClimb();
    }
    
    else {
        stopClimbLock();
    }

    pros::lcd::set_text(3, "Climb Encoder: " + to_string(leftClimbMotor.get_position()));

}

void climberToPosition(int position) {
    climb.move_absolute(position, 600);
}

void manualRaiseClimber() {
    climb.move(75);
}

void manualLowerClimber() {
    climb.move(-75);
}

void stopClimber() {
    climb.move(0);
}

void lockClimb() {
    climbLock.move(50);
}

void unlockClimb() {
    climbLock.move(-50);
}

void stopClimbLock() {
    climbLock.move(0);
}


