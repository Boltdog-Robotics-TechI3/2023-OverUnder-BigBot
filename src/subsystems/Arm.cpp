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
    // if(driverController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
    //     if(armHomed){
	// 	    arm.move_absolute(-850, 30000);
    //         armHomed = false;
    //     }else{
    //         arm.move_absolute(0, 30000);
    //         armHomed = true;
    //     }
    // }
    pros::lcd::set_text(1, "Arm Encoder: " + to_string(arm1.get_position()));
}

void moveArm(int speed){
    arm.move(speed);
}