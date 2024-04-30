#include "vex.h"
#define no_port PORT22

using namespace vex;


brain Brain;
controller Controller;

/*
    VALUES OF "NULL" ARE PLACEHOLDERS, TO BE REPLACED WITH MOTOR PORTS. CORRECT FORMAT IS
    motor motorName = motor(PORT, GEAR_RATIO, REVERSE?)

    sample:
        motor motorName = motor(PORT1, ratio18_1, false);
*/

//Drive motors (4 motors)
motor frontLeft = motor(no_port, ratio18_1, false);
motor frontRight = motor(no_port, ratio18_1, true);

motor backLeft = motor(no_port, ratio18_1, false);
motor backRight = motor(no_port, ratio18_1, true);

//Drive motors (if 6 motor)
motor middleLeft = motor(no_port, ratio18_1, false);
motor middleRight = motor(no_port, ratio18_1, true);

motor_group leftDrive = motor_group(frontLeft, middleLeft, backLeft);
motor_group rightDrive = motor_group(frontRight, middleRight, backRight);
//Gyroscope

inertial gyroscope = inertial(no_port);




void vexcodeInit(void){
    // Nothing to initialize
}
