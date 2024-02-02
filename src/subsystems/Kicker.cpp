#include "main.h"
#include <iostream>
using namespace std;

void kickerPeriodic(bool override) {
  if (driverController.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        spinKicker();
  }
  else {
    stopKicker();
  }
}

void stopKicker() {
  kickerMotor.brake();
}

void spinKicker() {
  kickerMotor.move(127);
}
