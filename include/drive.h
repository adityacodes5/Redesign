#pragma once

class drive{
    private:

        double leftAxisPCT;
        double rightAxisPCT;

    public:
        drive();
        

        void move(directionType dir, double veloL, double veloR);
        void brake(brakeType type);
        void moveUntil(double degrees, double motorVelo, bool waitForCompletion);
        double leftDriveRotation();
        double rightDriveRotation();
        double averageDriveRotation();
        void resetDegreePosition();
        void autoDrive();

        
};