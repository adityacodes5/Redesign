#include "vex.h"

using namespace std;
computation::computation(double gearRatio, double wheelCircumference):
    gearRatio(gearRatio),
    wheelCircumference(wheelCircumference)
{};

double computation::computeMin(double a, double b){
    return fabs(a) < fabs(b) ? a:b;
}

double computation::computeMax(double a, double b){
    return fabs(a) > fabs(b) ? a:b;
}

double computation::degreesToInches(double degrees){
    return degrees*gearRatio*wheelCircumference/360;
}

double computation::inchesToDegrees(double inches){
    return (inches/wheelCircumference) * (360/gearRatio);
}

double computation::percentLimit(double percent){
    if(percent > 100){
        return 100;
    }
    else if(percent < -100){
        return -100;
    }
    else{
        return percent;
    }

}

double computation::voltageLimit(double voltage_mV){
    if(voltage_mV > 12000){
        return 12000;
    }
    else if(voltage_mV < -12000){
        return -12000;
    }
    else{
        return voltage_mV;
    }
}

velocityUnits computation::voltageToPercent(double voltage_mV){
    return velocityUnits((voltage_mV/12000)*100);
}

voltageUnits computation::percentToVoltage(double percent){
    return voltageUnits((percent/100)*12000);
}

double computation::headingToBearing(double heading){
    return 360 - heading + 90;
}