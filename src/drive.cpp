#include <vex.h>

using namespace vex;

//SET ALL CONSTANT VALUES IN "projectID.h"
//IGNORE THIS CONSTRUCTOR
computation Computation(robotID.gearRatio, robotID.wheelCircumference); 
drive::drive(){};

//Create functions to be able to use in other parts of the code

void drive::move(directionType dir, double veloL, double veloR){

    veloL = Computation.percentLimit(veloL); //Limits the velocity to 100% to avoid overloading the motors
    veloR = Computation.percentLimit(veloR);
    
    leftDrive.spin(dir, veloL, velocityUnits::pct);
    rightDrive.spin(dir, veloR, velocityUnits::pct);

}

void drive::brake(brakeType type){

    leftDrive.stop(type);
    rightDrive.stop(type);

}

void drive::moveUntil(double degrees, double motorVelo, bool waitForCompletion){

    leftDrive.spinTo(degrees, rotationUnits::deg, motorVelo, velocityUnits::pct, waitForCompletion);
    rightDrive.spinTo(degrees, rotationUnits::deg, motorVelo, velocityUnits::pct, waitForCompletion);

}

double drive::leftDriveRotation(){

    return fabs(leftDrive.position(rotationUnits::deg)); //Returns the rotation values of the left drive encoders
    
}

double drive::rightDriveRotation(){

    return fabs(rightDrive.position(rotationUnits::deg)); //Returns the rotation values of the right drive encoders

}

double drive::averageDriveRotation(){

    return (leftDriveRotation() + rightDriveRotation())/2; //Returns average rotation values of both side drive encoders

}

void drive::resetDegreePosition(){

    leftDrive.resetPosition();
    rightDrive.resetPosition();

}

void drive::autoDrive(){ //Drive function for arcade drive

    rightAxisPCT = Controller.Axis3.position(percent) - Controller.Axis4.position(percent);
    leftAxisPCT = Controller.Axis3.position(percent) + Controller.Axis4.position(percent);

    if (fabs(rightAxisPCT) > 5 || fabs(leftAxisPCT) > 5){ //Deadzone for joystick, joystick must be moved more then 5% to activate drive

        move(forward, leftAxisPCT, rightAxisPCT);

    }

    else{

        brake(coast);

    }
}






