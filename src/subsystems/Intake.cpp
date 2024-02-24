#include "main.h"

void intakeInit(){
    intake.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void intakePeriodic(bool override) {
}

void spinIntake(int speed) {
  intake.move(speed);
}