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
	setArmPosition(-770, 30000);

	// punch that bitch
	spinPuncher(100);
	pros::delay(700);
	spinPuncher(0);

	// intake triball
	spinIntake(127);
	pros::delay(500);

	// bring arm up to standing
	holdIntake();
	setArmPosition(-30, 30000);
	pros::delay(500);

	// drop triball into puncher
	spinIntake(-80);
	pros::delay(700);
	holdIntake();

	// push a bit against bar
	driveStraightDistance(-20, 50);
}

void shootTriballs(int shots){
	for(int i = 0; i < shots; i++){
		autoCycleSequence();
	}
}

void skillsJumpBar(){
	// Cycle Triballs
	shootTriballs(3);

	setArmPosition(-770, 30000);
	spinPuncher(100);
	pros::delay(700);
	spinPuncher(0);
	setArmPosition(-30, 30000);

	// reset gyro to be the correct angle (plz work)
	setHeading(0);

	// Drive To bar
	moveTo(0, 42, 3000, 200.0);
	pros::delay(300);

	// Move ball out of the way
	flipWings();
	rotateToHeadingPIDAbsolute(70);
	flipWings();

	// Jump bar
	rotateToHeadingPIDAbsolute(315);
	pros::delay(200);
	moveTo(0, 50, 3000, 200.0);
	moveTo(0, -30, 3000, 100.0);

	// First set of Smashing
	flipWings();
	moveTo(0, 25, 3000, 200.0);
	moveTo(0, -15, 3000, 200.0);
	moveTo(0, 20, 3000, 200.0);
	moveTo(0, -20, 3000, 200.0);

	// move to right side of middle goal
	rotateToHeadingPIDAbsolute(45);
	flipLeftWing();
	moveTo(0, 20, 3000, 200.0);
	rotateToHeadingPIDAbsolute(315);

	// Second Set of Smashing
	flipLeftWing();
	moveTo(0, 25, 3000, 200.0);
	moveTo(0, -10, 3000, 200.0);
	moveTo(0, 10, 3000, 200.0);
	moveTo(0, -20, 3000, 200.0);
}	

void skillsTrenchRun() {
	// Human Player Cycles
	shootTriballs(16);

	// Back out and head to trench
	moveTo(0, 5, 1000, 200);
	rotateToHeadingPID(72);
	moveTo(0, 23, 2000, 200);

	// turn towards and drive through trench
	setArmPosition(-720, 30000);
	rotateToHeadingPID(-32);
	moveTo(0, 60, 3000, 200);
	setArmPosition(-30, 30000);

	// Turn and drive along enemy human player pole
	rotateToHeadingPID(-32);
	moveTo(0, 22, 2000, 200);
	rotateToHeadingPID(-48);

	// Smash into right side of goal
	flipLeftWing();
	flipRightWing();
	moveTo(0, 12, 1000, 9999990);
	moveTo(0, -12, 1000, 999990);
	moveTo(0, 12, 1000, 999990);
	moveTo(0, -12, 1000, 999990);
	flipLeftWing();
	flipRightWing();

	// Travel To Mid
	rotateToHeadingPID(-80);
	moveTo(0, 30, 1000, 200);

}