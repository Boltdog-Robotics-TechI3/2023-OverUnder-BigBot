#include "main.h"

void drivetrainInitialize();

void drivetrainPeriodic(bool override);

void tankDrive(int left, int right);

void arcadeDrive(int moveValue, int rotateValue);

void evenBotWithBeam();

void driveStraightDistance(int distance, int speed);

void driveStraightDistanceVoltage(int distance);

void rotateToHeading(int angle, int speed);
 
void rotateToHeadingVoltage(int angle);

void killSwitch();

void moveTo(double xDist, double yDist, int timeout);