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
motor frontLeft = motor(PORT16, ratio18_1, true);
motor frontRight = motor(PORT10, ratio18_1, false);

motor backLeft = motor(PORT7, ratio18_1, true);
motor backRight = motor(PORT5, ratio18_1, false);

//Drive motors (if 6 motor)
motor middleLeft = motor(PORT15, ratio18_1, false);
motor middleRight = motor(PORT9, ratio18_1, true);

motor_group leftDrive = motor_group(frontLeft, middleLeft, backLeft);
motor_group rightDrive = motor_group(frontRight, middleRight, backRight);
//Gyroscope

inertial gyroscope = inertial(PORT3);




void vexcodeInit(void){
    // Nothing to initialize
}
