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
	setArmPosition(-720, 30000);
	pros::delay(500);

	// bring arm up to standing
	holdIntake();
	setArmPosition(-30, 30000);
	pros::delay(500);

	// drop triball into puncher
	spinIntake(-50);
	pros::delay(500);
	holdIntake();
}

void shootTriballs(int shots){
	for(int i = 0; i < shots; i++){
		autoCycleSequence();
	}
}

void skillsJumpBar(){
	shootTriballs(3);
	moveTo(0, 52, 3000, 200.0);
	flipWings();
	moveTo(0, 20, 1500, 50.0);
	moveTo(0, -3, 1500, 50.0);
	moveTo(0, 35, 3000, 200.0);
	moveTo(0, 27.5, 3000, 200.0);
	flipWings();
}

void skillsTrenchRun() {
	// Human Player Cycles
	shootTriballs(1);

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