#ifndef PID_H
#define PID_H


class PID{
    public:

        const double wheelCircumference = robotID.wheelCircumference;
        const double gearRatio = robotID.gearRatio;
        const double deltaTime = processID.deltaTime;
        const double maxVelocity = robotID.maxVelocity;
        const double driveBase = robotID.driveBase;

        bool leftTurn;

        double error;
        double kP;
        double kI;
        double kD;
        double startIntegral;
        double settleError;
        double settleTime;
        double timeout;
        double degreesError;
        
        double resetDegree;
        double accumulatedError;
        double previousError;
        double output;
        double timeSpentRunning;
        double timeSpentSettled;
        double motorSpeed;
        double leftSpeed;
        double rightSpeed;
        double targetHeadingError;

        //odom PID variables
        double currentX;
        double currentY;
        double errorX;
        double errorY;
        double targetAngle;
        double targetDist;
        //TODO RESET THESE VALUES
        
        PID();
        //PID(double error, double kP, double kI, double kD, double startIntegral, double settleError, double settleTime, double timeout);

        double compute(double error);

        void setValues(double error, double kP, double kI, double kD, double startIntegral, double settleError, double settleTime, double timeout);

        bool isSettled();

        void moveFor(double inches, double settleTime, double timeout);

        void continuousTurn(double targetHeading, bool leftTurn, double setHeading, bool overwriteHeading, double settleTime, double timeout);

        void moveTo(double targetX, double targetY, double settleTime, double timeout);




};



#endif //PID_H