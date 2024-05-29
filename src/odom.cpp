#include <vex.h>
#include <cmath>

gyroData GyroData;
computation comp(robotID.gearRatio, robotID.wheelCircumference);
drive drivingData;

odom::odom(){
    x = 0;
    y = 0;
    heading = 0;
    //bearing = 90;
}

void odom::updatePosition(double initialX, double initialY){
    x = initialX;
    y = initialY;

    while(true){
        bearing = GyroData.getBearing();

        //if (bearing > 360){
        //    bearing -= 360;
        //}
//
        //else if (bearing < 0){
        //    bearing += 360;
        //}

        centerPos = comp.degreesToInches(drivingData.averageDriveRotation());
        deltaCenter = centerPos - prevCenterPos;


        x += cos(bearing * degToRad) * (deltaCenter);
        y += sin(bearing * degToRad) * (deltaCenter);

        prevCenterPos = centerPos;


        //this_thread::sleep_for(processID.deltaTime);
    }
}

