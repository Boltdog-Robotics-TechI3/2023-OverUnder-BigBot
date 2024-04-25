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

void rotateToHeadingPID(double angle);

void rotateToHeadingPIDAbsolute(double angle);

void killSwitch();

void setHeading(double angle);

void moveTo(double xDist, double yDist, int timeout, float maxSpeed);

void chassisMoveTo(float x, float y, int timeout, float maxSpeed = (200.0F), bool log = false);

void chassisTurnTo(float x, float y, int timeout, bool reversed = false, float maxSpeed = (200.0F), bool log = false);

void setChassisPose(double x, double y, double angle, bool radians = false);
