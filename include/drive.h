#pragma once

class drive{
    public:
        drive();

        double leftAxisPCT = Controller.Axis3.position(percent) + Controller.Axis4.position(percent);
        double rightAxisPCT = Controller.Axis3.position(percent) - Controller.Axis4.position(percent);

        void move(directionType dir, double veloL, double veloR);
        void brake(brakeType type);
        void moveUntil(double degrees, double motorVelo, bool waitForCompletion);
        double leftDriveRotation();
        double rightDriveRotation();
        void resetDegreePosition();
        void autoDrive();

        
};