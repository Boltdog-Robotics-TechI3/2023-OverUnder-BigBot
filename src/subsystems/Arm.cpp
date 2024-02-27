#include "main.h"
#include <iostream> 
using namespace std;

bool armHomed = true;

void armInit(){
    arm1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    arm2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    arm.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
}

void armPeriodic(bool overide){    
    if(driverController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
        if(armHomed){
		    setArmPosition(-750, 30000);
            armHomed = false;
        }else{
            setArmPosition(-120, 30000);
            armHomed = true;
        }

    
    // if(driverController.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
		// 	moveArm(127*.6);
		// }else if(driverController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
		// 	moveArm(-127*.6);
		// }else{
		// 	moveArm(0);
		// }
    }
    pros::lcd::set_text(3, "Arm Encoder: " + to_string(arm1.get_position()));
}

void moveArm(int speed){
    arm.move(speed);
}

void setArmPosition(double position, double speed) {
    arm.move_absolute(position, speed);
}