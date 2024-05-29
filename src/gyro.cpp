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

double gyroData::getBearing(){
    return (450 - gyroscope.heading());
}


void gyroData::errorCalibrate(){

    if(gyroscope.heading() < 1 && gyroscope.heading() >= 0){ //To avoid 360/0 glitch
        gyroscope.setHeading(1, rotationUnits::deg);
    }

    if(gyroscope.heading() > 359 && gyroscope.heading() < 360){ //To avoid 360/0 glitch
        gyroscope.setHeading(359, rotationUnits::deg);
    }   
}
