/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Aditya Makhija                                            */
/*    Created:      2/29/2024, 5:21:09 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
// Import EVERYTHING you need for your code for vex here
#include "vex.h"

using namespace vex;

// Create a global instance (calling constructor) of the class "competition" in order to use it in this file
competition Competition;
drive Drive;
odom Odom;
PID pid;
timer Timer;

bool gyroIsCalibrated = false;

// -- PREAUTONOMOUS FUNCTION --
// This function is run before the game starts and is used to set up the robot. It runs when the code is activated,
// but the game has not begun yet. This is where you can set up the robot's starting position, sensors, etc.
void positionUpdateThread() {
  // Odom.updatePosition(0, 0, 90);
}

void pre_auton(void) {
  gyroscope.calibrate();
  gyroIsCalibrated = true;

  // Brain.Screen.drawImageFromFile("Untitled-1.png", 0, 0);
  // thread positionUpdate(positionUpdateThread);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

int updateControllerScreenTask() {
  vex::timer matchTimer;  // Timer to track the match time
  matchTimer.clear();     // Clear the timer 
  int batteryPercent;
  int remainingTime;

  while (true) {
    Controller.Screen.clearScreen();

    batteryPercent = Brain.Battery.capacity();
    Controller.Screen.setCursor(1, 1);
    Controller.Screen.print("Bat: %d%% Gy: %.2lf", batteryPercent, gyroscope.heading());


    // Calculate the remaining time by subtracting the elapsed time from the match duration (120 seconds)
    remainingTime = 105 - matchTimer.time(vex::timeUnits::sec);
    Controller.Screen.setCursor(2, 1);
    Controller.Screen.print("X %2.lf  Y %2.lf", Odom.x, Odom.y);

    Controller.Screen.setCursor(3, 1);
    Controller.Screen.print("Time: %d sec", remainingTime);

    vex::this_thread::sleep_for(1000); // Wait for 1 second


    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Bearing: %.2lf", Odom.bearing);
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("Center Pos: %.2lf", Odom.centerPos);
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("Delta Center: %.2lf", Odom.deltaCenter);
    Brain.Screen.setCursor(4, 1);
    Brain.Screen.print("YoX: %.2lf, Y: %.2lf", pid.errorX, pid.errorY);
  }
  return 0;
}

int updatePositionTask(){
  Odom.updatePosition(0, 0);
  return 0;
}


void usercontrol(void) {
  if (!gyroIsCalibrated) {
    gyroscope.calibrate();
    gyroIsCalibrated = true;
  }
  vex::this_thread::sleep_for(2000); // 2 second delay

  // Start the asynchronous task for updating the controller screen
  vex::task updateScreen(updateControllerScreenTask);
  vex::task odomUpdate(updatePositionTask);

  // User control code here, inside the loop
  while (true) {
    Drive.autoDrive();

    vex::this_thread::sleep_for(processID.deltaTime); // Delay loop to avoid overload

    if (Controller.ButtonA.pressing()) {
      pid.moveFor(48, 250, 2000);
    }
    if (Controller.ButtonB.pressing()) {
      pid.moveFor(24, 250, 2000);
    }
    if (Controller.ButtonX.pressing()) {
      pid.moveTo(12, 12, 250, 2000);
    }
    if (Controller.ButtonY.pressing()) {
      pid.continuousTurn(90, false, 0, false, 250, 2000);
    }
  }
}

// Main will set up the competition functions and callbacks.
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    vex::this_thread::sleep_for(100);
  }
}
