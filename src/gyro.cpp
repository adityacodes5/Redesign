#include <vex.h>

gyroData::gyroData(){}

void gyroData::calibrate(){

    gyroscope.calibrate();

    while (gyroscope.isCalibrating()) {

        this_thread::sleep_for(100);

    }
}

void gyroData::resetHeading(bool leftTurn){

    gyroscope.setHeading(0.1, rotationUnits::deg);

    if(leftTurn){

        gyroscope.setHeading(359.9, rotationUnits::deg);
        
    }


}

double gyroData::getHeading(){

   return gyroscope.heading();

}