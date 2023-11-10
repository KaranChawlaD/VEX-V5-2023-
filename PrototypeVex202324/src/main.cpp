/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       karan                                                     */
/*    Created:      10/27/2023, 3:14:45 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> q
#include <string.h>

#include "vex.h"

using namespace vex;



// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS

brain Brain;
controller Controller1 = controller(primary);
motor axelMotor = motor(PORT4, ratio36_1, false);
motor LeftDriveSmart = motor(PORT2, ratio6_1, false);
motor RightDriveSmart = motor(PORT3, ratio6_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 317.5, 117.475, mm, 1);
motor clawMotor = motor(PORT4, ratio36_1, false);


// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
#pragma endregion VEXcode Generated Robot Configuration

void axelSpinForward() {axelMotor.spin(forward, 50, percent);}
void axelSpinStop() {axelMotor.spin(forward, 0, percent);}

//void clawOpen() {clawMotor.spinFor(forward, 45, degrees, 50, percent, true);}
//void clawCLose() {clawMotor.spinFor(backward, 25, degrees, 50, percent, true);}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
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

void runOnAutonomous(void) {
  Brain.Screen.print("Running auto");
  
  Drivetrain.driveFor(forward, 20, inches);
  Drivetrain.turnFor(right, 180, degrees);
  wait (1, seconds);
  Drivetrain.driveFor(forward, 20, inches);
  Drivetrain.turnFor(right, 180, degrees);
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

void runOnDriverControl(void) {

  Brain.Screen.print("Running teleop");
  axelMotor.setVelocity(0, percent);

  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    //axel spinning for throwing
    Controller1.ButtonR2.pressed(axelSpinForward);
    Controller1.ButtonR2.released(axelSpinStop);
    
    //movemnet of robot
    if (Controller1.Axis3.position() > 0.0) {
      LeftDriveSmart.setVelocity((Controller1.Axis3.position() + Controller1.Axis4.position())/1.5, percent);
      RightDriveSmart.setVelocity((Controller1.Axis3.position() - Controller1.Axis4.position())/1.5, percent);
    }

    else {
      RightDriveSmart.setVelocity((Controller1.Axis3.position() + Controller1.Axis4.position())/1.5, percent);
      LeftDriveSmart.setVelocity((Controller1.Axis3.position() - Controller1.Axis4.position())/1.5, percent);
    }
    
    LeftDriveSmart.spin(forward);
    RightDriveSmart.spin(forward); 
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  //Competition.autonomous(autonomous);
  Competition.drivercontrol(runOnDriverControl);

  // Run the pre-autonomous function.
  //pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(0.05, seconds);
  }
}
