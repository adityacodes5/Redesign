#ifndef COMPUTATION_H
#define COMPUTATION_H

class computation{
    private:
    
        double gearRatio; // Declare gearRatio as a nonstatic data member
        double wheelCircumference;

    public:
        computation(double gearRatio, double wheelCircumference);

        double computeMin(double a, double b);
        double computeMax(double a, double b);
        double degreesToInches(double degrees);
        double inchesToDegrees(double inches);
        double percentLimit(double percent);
        double voltageLimit(double voltage_mV);
        velocityUnits voltageToPercent(double voltage_mV);
        voltageUnits percentToVoltage(double percent);
        double headingToBearing(double heading);
        double bearingToHeading(double bearing);
};

#endif //COMPUTATION_H