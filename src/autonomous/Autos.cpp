#include "main.h"
#include <iostream>
using namespace std;

void matchQualsThreeBallAuto() {
    scoreFirstThreeTriballs();
	rotateToHeading(-15, 255);
	flipLeftWing(400, 600);
	flipRightWing(400, 600);
	pros::delay(5000);
	spinKicker();
	driveStraightDistance(2000, 255);
	flipRightWing(150, 600);
	pros::delay(500);
}

void matchQualsFiveBallAuto() {
	scoreFirstThreeTriballs();
	rotateToHeading(75, 255);
	flipLeftWing(233, 600);
	flipRightWing(233, 600);
	driveStraightDistance(900, 255);
	rotateToHeading(-65, 175);
	spinKicker();
	flipLeftWing(140, 100);
	flipRightWing(140, 100);
	driveStraightDistance(800, 255);
	driveStraightDistance(300, 50);
	driveStraightDistance(100, 255);
	stopKicker();
	flipLeftWing(233, 600);
	flipRightWing(233, 600);
	// rotateToHeading(75, 255);
	// driveStraightDistance(400, 255);
	// rotateToHeading(-65, 100);
	// spinKicker();
	// flipLeftWing(140, 100);
	// flipRightWing(140, 100);
	// driveStraightDistance(950, 150);
	// driveStraightDistance(300, 50);
	// driveStraightDistance(100, 255);
	driveStraightDistance(-500, 255);
	rotateToHeading(-90, 175);
	pros::delay(2000);
	flipLeftWing(400, 600);
	flipRightWing(400, 600);
	// spinKicker();
	driveStraightDistance(1500, 255);
	flipLeftWing(150, 200);

	pros::delay(100000);
}


void matchElimsAuto() {
    scoreFirstThreeTriballs();
	rotateToHeading(75, 255);
	flipLeftWing(233, 600);
	flipRightWing(233, 600);
	driveStraightDistance(900, 255);
	rotateToHeading(-65, 175);
	spinKicker();
	flipLeftWing(140, 100);
	flipRightWing(140, 100);
	driveStraightDistance(800, 255);
	driveStraightDistance(300, 50);
	driveStraightDistance(100, 255);
	stopKicker();
	flipLeftWing(233, 600);
	flipRightWing(233, 600);
}

void skillsAuto() {
	// flipRightWing(210, 600);	
	// driveStraightDistance(2800, 255);
	// flipRightWing(160, 600);	
	// spinKicker();
	// driveStraightDistance(600, 100);
	// driveStraightDistance(100, 200);
	// flipRightWing(150, 100);
	// driveStraightDistance(300, 100);
	// driveStraightDistance(100, 200);

	// tankDrive(50, 0);
	// pros::delay(300);
	// tankDrive(0, 0);
	flipLeftWing(150, 600);	
	pros::delay(300);
	flipLeftWing(40, 600);	

	for (int i = 0; i <= 22; i++) {
		flipLeftWing(400, 600);	
		pros::delay(300);
		flipLeftWing(40, 600);	
		pros::delay(1200);
	}

	rotateToHeading(130, 255);
	driveStraightDistance(800, 255);
	rotateToHeading(30, 255);
	driveStraightDistance(3200, 500);
	driveStraightDistance(-1000, 500);
	driveStraightDistance(2000, 500);
	driveStraightDistance(-1000, 500);
	rotateToHeading(-90, 255);
	driveStraightDistance(-1000, 300);
	rotateToHeading(90, 255);

}

void scoreFirstThreeTriballs() {
	pros::delay(10000);
	driveStraightDistance(2800, 255);
	spinKicker();
	driveStraightDistance(600, 100);
	driveStraightDistance(100, 200);
	driveStraightDistance(-1500, 255);
	flipLeftWing(223, 600);
	flipRightWing(223, 600);
	rotateToHeading(70, 1000);
	driveStraightDistance(750, 255);
	rotateToHeading(-70, 200);
	spinKicker();
	flipLeftWing(140, 100);
	flipRightWing(140, 100);
	driveStraightDistance(950, 150);
	driveStraightDistance(300, 50);
	// pros::delay(3000);
	driveStraightDistance(100, 255);
	driveStraightDistance(-900, 255);
	stopKicker();
	flipLeftWing(223, 600);
	flipRightWing(223, 600);
	rotateToHeading(40, 255);
	driveStraightDistance(500, 255);
	rotateToHeading(-40, 255);
	spinKicker();
	flipLeftWing(140, 100);
	flipRightWing(140, 100);
	driveStraightDistance(600, 50);
	driveStraightDistance(100, 255);
	driveStraightDistance(-1700, 255);
	stopKicker();
}