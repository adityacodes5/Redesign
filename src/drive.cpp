#include <vex.h>

using namespace vex;

//FILL OUT CONSTRUCTOR
//SET ALL CONSTANT VALUES IN "projectID.h"

computation Computation(robotID.gearRatio, robotID.wheelCircumference);
drive::drive(){};

void drive::move(directionType dir, double veloL, double veloR){

    veloL = Computation.percentLimit(veloL);
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

    return fabs(leftDrive.position(rotationUnits::deg));
    
}

double drive::rightDriveRotation(){

    return fabs(rightDrive.position(rotationUnits::deg));

}

double drive::averageDriveRotation(){

    return (leftDriveRotation() + rightDriveRotation())/2;

}

void drive::resetDegreePosition(){

    leftDrive.resetPosition();
    rightDrive.resetPosition();

}

void drive::autoDrive(){

    rightAxisPCT = Controller.Axis3.position(percent) + Controller.Axis4.position(percent);
    leftAxisPCT = Controller.Axis3.position(percent) - Controller.Axis4.position(percent);

    if (fabs(rightAxisPCT) > 5 || fabs(leftAxisPCT) > 5){

        move(forward, leftAxisPCT, rightAxisPCT);

    }

    else{

        brake(coast);

    }
}






