#pragma once

class robotID{
    public:
        robotID();

        const double gearRatio = 0; //speed:torque
        const double wheelCircumference = 0; //in
        const double driveBase = 12; //in
        const int maxVelocity = 100; //pct
        const int maxVoltage = 12000; //mV


};

class processID{
    public:
        processID();

        const int deltaTime = 10; //ms
        const int autonTime = 15000; //ms
        const int gameTime = 105000; //ms

};
