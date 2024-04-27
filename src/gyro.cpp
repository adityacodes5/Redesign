#include <vex.h>

gyro::gyro(){}

void gyro::calibrate(){

    gyroscope.calibrate();

    while (gyroscope.isCalibrating()) {

        this_thread::sleep_for(100);

    }
}

void gyro::resetHeading(bool leftTurn){

    gyroscope.setHeading(0.1, rotationUnits::deg);

    if(leftTurn){

        gyroscope.setHeading(359.9, rotationUnits::deg);
        
    }


}

double gyro::getHeading(){

   return gyroscope.heading();

}