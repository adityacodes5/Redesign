/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Aditya Makhija                                            */
/*    Created:      2/29/2024, 5:21:09 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//Import EVERYTHING you need for your code for vex here
#include "vex.h"

using namespace vex;

// Create a global instance (calling constructor) of the class "competition" in order to use it in this file

competition Competition;
drive Drive;
processID Process;
//


// -- PREAUTONOMOUS FUNCTION --

// This function is run before the game starts and is used to set up the robot. It runs when the code is activated,
// but the game has not begun yet. This is where you can set up the robot's starting position, sensors, etc.

void pre_auton(void) {

  //Brain.Screen.drawImageFromFile("Untitled-1.png", 0, 0);

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

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    Drive.autoDrive();

    vexDelay(Process.deltaTime); //Delay loop to avoid overload

  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
