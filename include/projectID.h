#ifndef PROJECTID_H
#define PROJECTID_H

struct{

    const double gearRatio = 1.5; //speed:torque
    const double wheelCircumference = 4*M_PI; //in
    const double driveBase = 12; //in
    const int maxVelocity = 100; //pct
    const int maxVoltage = 12000; //mV

} robotID; 


struct{

    const int deltaTime = 10; //ms
    const int autonTime = 15000; //ms
    const int gameTime = 105000; //m

} processID;

#endif //PROJECTID.H