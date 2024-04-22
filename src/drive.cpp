#include <vex.h>

using namespace vex;

//FILL OUT CONSTRUCTOR
//SET ALL CONSTANT VALUES IN "projectID.h"
timer myTimer;
processID process;
robotID robot;
computation Computation(robot.gearRatio, robot.wheelCircumference);
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

void drive::resetDegreePosition(){

    leftDrive.resetPosition();
    rightDrive.resetPosition();

}

void drive::autoDrive(){

    if (abs(rightAxisPCT) > 5 || abs(leftAxisPCT) > 5){

        move(forward, leftAxisPCT, rightAxisPCT);

    }

    else{

        brake(coast);

    }
}





