#include "main.h"
#include <iostream>
using namespace std;

void skillsAuto() {
	// Drive into the diagonal alliance bar
	// Launch Preload
	// Preform "match load sequence" 23 times.
	//	  Prime Puncher
	//    Intake Triball
	//    Launch Triball
	//    repeat
	// Drive back
	// Drive into and through trench. (make sure wings are facing forward)
	// Once out of the trench, release wings and drive into the right side of the goal, pushing triballs in.
	// Drive back out and move to the right side of the front of the goal, again pushing triballs in.
	// Continue moving along, pushing triballs into different parts of the goal until the end of auto
}

void autoCycleSequence() {
	// move arm down to make room for the puncher and to prepare to grab next triball
	setArmPosition(-750, 30000);

	// punch that bitch
	spinPuncher(100);
	pros::delay(700);
	spinPuncher(0);

	// intake triball
	spinIntake(127);
	setArmPosition(-700, 30000);
	pros::delay(300);

	// bring arm up to standing
	holdIntake();
	setArmPosition(-30, 30000);
	pros::delay(500);

	// drop triball into puncher
	spinIntake(-50);
	pros::delay(500);
	holdIntake();
}