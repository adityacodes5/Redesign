#include <vex.h>
#define TBD NULL

using namespace std;

computation Compute(robotID.gearRatio, robotID.wheelCircumference);
drive Driving;
gyroData Gyro;
odom Odometry;
PID::PID(){};

//PID::PID(double error, double kP, double kI, double kD, double startIntegral, double settleError, double settleTime, double timeout):
    //error(error), 
    //kP(kP), 
    //kI(kI), 
    //kD(kD), 
    //startIntegral(startIntegral), 
    //settleError(settleError), 
    //settleTime(settleTime), 
    //timeout(timeout)
//{};


double PID::compute(double error){

    if(fabs(error) < startIntegral){ //StartIntegral is used to avoid "integral windup", the unexpected oscillating of speed when using this PID. Error is set to match the next phase of the accumulated error in order to stop this effect. Practically caps the integral
        accumulatedError += error;
    }

    if((error > 0 && previousError < 0)|| (error < 0 && previousError > 0)){ //Checks if error has crossed from negative to positive/positive to negative, if so, accumulatedError is reset and therefore the Integral output is 0
        accumulatedError = 0;
    }

    output = (kP * error) + (kI * accumulatedError) + (kD * (error - previousError)); //PID equation, the final movement output

    previousError = error;

    if(fabs(error) < settleError){
        timeSpentSettled += 10;
    }
    
    else{
        timeSpentSettled = 0;
    }

    timeSpentRunning += 10;

    output = Compute.percentLimit(output); //Limits the output to 100% to avoid overloading the motors

    return (output);
}

void PID::setValues(double error = 0, double kP = 0, double kI = 0, double kD = 0, double startIntegral = 0, double settleError = 0, double settleTime = 0, double timeout = 0){

    //Possibly set values
    this-> error = error;
    this-> kP = kP;
    this-> kI = kI;
    this-> kD = kD;
    this-> startIntegral = startIntegral;
    this-> settleError = settleError;
    this-> settleTime = settleTime;
    this-> timeout = timeout;

    //Reset rest to 0
    this-> degreesError = 0;
    this-> accumulatedError = 0;
    this-> previousError = 0;
    this-> output = 0;
    this-> timeSpentSettled = 0;
    this-> timeSpentRunning = 0;
    this-> motorSpeed = 0;
    this-> leftSpeed = 0;
    this-> rightSpeed = 0;
    this-> targetHeadingError = 0;

    Driving.resetDegreePosition();
}

bool PID::isSettled(){

    if(timeSpentSettled > settleTime){
        return true;
    }

    else if(timeSpentRunning > timeout && timeout != 0){ // If timeout does equal 0, the move will never actually time out. Setting timeout to 0 is the same as setting it to infinity
        return true;
    }

    else{
        return false;
    }

}


void PID::moveFor(double inches, double settleTime = 300, double timeout = 4000){
    setValues(inches, .5, 2, 1.2, 0, 15, settleTime, timeout); //Sets the values for the PID (error, settleTime, timeout

    if(inches >= 36){
        kP = .5;
        kI = 2;
        kD = 1.2;
    }
    if(inches < 36 && inches >= 18){
        kP = .42;
        kI = 2;
        kD = .9;
    }
    if(inches < 18){
        kP = .36;
        kI = 2;
        kD = 1.2;
    }
    degreesError = (inches*360)/(wheelCircumference*gearRatio); //Converts inches to degrees

    resetDegree = Driving.averageDriveRotation(); //Resets the degree position

    while(!isSettled()){

        if(inches >= 0){

            error = degreesError - Driving.averageDriveRotation() - resetDegree;

        }

        if(inches < 0){

            error = degreesError + Driving.averageDriveRotation() - resetDegree;

        }
        
        motorSpeed = compute(error); //Calculates the motor speed

        leftSpeed = motorSpeed;
        rightSpeed = motorSpeed;

        Driving.move(forward, leftSpeed, rightSpeed); //Moves the motors

        vexDelay(deltaTime); //Delay loop to avoid overload
        

    }

    Driving.brake(coast); //Brakes the motors

}

void PID::continuousTurn(double targetHeading, bool leftTurn, double setHeading = 0, bool overwriteHeading = false, double settleTime = TBD, double timeout = TBD) {
    setValues(0, 0.55, 0.001, 0.25, 5, 1, settleTime, timeout); // Set PID values (example values, adjust as needed)
    
    if(overwriteHeading) {
        gyroscope.setHeading(setHeading, rotationUnits::deg);
    }

    const double MIN_SPEED = 5;

    while(!isSettled()) {
        double currentHeading = gyroscope.heading();
        degreesError = targetHeading - currentHeading;

        // Handle wrap-around
        if(degreesError > 180) {
            degreesError -= 360;
        } else if(degreesError < -180) {
            degreesError += 360;
        }

        error = degreesError;
        motorSpeed = compute(error);
    

        if (fabs(motorSpeed) < MIN_SPEED) {
            motorSpeed = (motorSpeed > 0) ? MIN_SPEED : -MIN_SPEED;
        }

        if(leftTurn) {
            Driving.move(fwd, -motorSpeed, motorSpeed);
        } else {
            Driving.move(fwd, motorSpeed, -motorSpeed);
        }

        vexDelay(10);
    }

    Driving.brake(coast);
}


void PID::moveTo(double targetX, double targetY, double settleTime = TBD, double timeout = TBD){
    
    errorX = targetX - Odometry.x;
    errorY = targetY - Odometry.y;

    if (errorX != 0) {
        targetAngle = Odometry.radToDeg * atan(errorY / errorX);
        if (errorX < 0) {
            // Adjust the angle based on the quadrant
            targetAngle += 180.0; // Quadrants 2 and 3
        }
    } else {
        // Handle special cases when errorX is zero
        if (errorY > 0) {
            targetAngle = 90.0; // Quadrant 1
        } else if (errorY < 0) {
            targetAngle = -90.0; // Quadrant 4
        }
    }

    continuousTurn(Compute.bearingToHeading(targetAngle), false);

    targetDist = sqrt(pow(errorX, 2) + pow(errorY, 2));

    moveFor(targetDist);

}