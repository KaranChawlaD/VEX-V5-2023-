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
#include <math.h>
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
motor clawMotor = motor(PORT5, ratio36_1, false);
//claw is initially closed
// bool clawOpen = false;


// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

#pragma endregion VEXcode Generated Robot Configuration


void axelSpinForward() {axelMotor.spin(forward, 50, percent);}
// void axelSpinHold() {axelMotor.spin(forward, 5, percent);}
void axelSpinStop() {axelMotor.spin(forward, 0, percent);}
void axelSpinBackward() {axelMotor.spin(forward, -80, percent);}


//claw motor defaults
void clawMotorOpen() {clawMotor.spin(forward, -50, percent);}
void clawMotorClose() {clawMotor.spin(forward, 80, percent);}
void clawMotorStop() {clawMotor.spin(forward, 0, percent);}
// void clawMotorStall() {clawMotor.spin(forward, 0.7, percent);}
//void clawMotorOpen() {clawMotor.spinFor(forward, 0.5, seconds, 50.0, percent);}
//void clawMotorClose() {clawMotor.spinFor(forward, -0.5, seconds, 50.0, percent);}
void turnRobot() {
 LeftDriveSmart.setVelocity(-100, percent);
 RightDriveSmart.setVelocity(100, percent);
 LeftDriveSmart.spin(forward);
 RightDriveSmart.spin(forward);
 wait (0.85, seconds);
 LeftDriveSmart.setVelocity(0, percent);
 RightDriveSmart.setVelocity(0, percent);
}
void turnRobot90() {
 LeftDriveSmart.setVelocity(100, percent);
 RightDriveSmart.setVelocity(-100, percent);
 LeftDriveSmart.spin(forward);
 RightDriveSmart.spin(forward);
 wait (0.5, seconds);
 LeftDriveSmart.setVelocity(0, percent);
 RightDriveSmart.setVelocity(0, percent);
}


void turnWhileMoving() {
  LeftDriveSmart.setVelocity(100, percent);
  RightDriveSmart.setVelocity(35, percent);
  LeftDriveSmart.spin(forward);
  RightDriveSmart.spin(forward);
  wait (0.97, seconds);
  RightDriveSmart.setVelocity(100, percent);
  wait (0.9, seconds);
}

void brakeRobot() {
 axelMotor.stop(brakeType::brake);
 clawMotor.stop(brakeType::hold);
}
/*
void drive(int v) {
 LeftDriveSmart.setVelocity(v, percent);
 RightDriveSmart.setVelocity(v, percent);
}
*/
/*
void fullSpeed() {
  // drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 317.5, 117.475, mm, 1);
  // return Drivetrain;
 LeftDriveSmart.setVelocity(100, percent);
 RightDriveSmart.setVelocity(100, percent);
}
void noForward() {
 LeftDriveSmart.setVelocity(0, percent);
 RightDriveSmart.setVelocity(0, percent);
}
*/

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
 clawMotor.spin(forward, 50, percent);
 Drivetrain.setDriveVelocity(75, percent);
 Drivetrain.driveFor(forward, 110, inches);
 clawMotor.spin(forward, -50, percent);
 wait (0.75, seconds);
 Drivetrain.driveFor(forward, -20, inches);
 turnRobot();
 Drivetrain.setDriveVelocity(120, percent);
 Drivetrain.driveFor(forward, -85, inches);
 turnWhileMoving();
 clawMotor.spin(forward, 50, percent);
 turnRobot90();
 LeftDriveSmart.setVelocity(100, percent);
  RightDriveSmart.setVelocity(100, percent);
  LeftDriveSmart.spin(forward);
  RightDriveSmart.spin(forward);
  wait (1.5, seconds);
  clawMotor.spin(forward, -70, percent);
  wait (0.5, seconds);
  turnRobot();
  LeftDriveSmart.setVelocity(-100, percent);
  RightDriveSmart.setVelocity(-100, percent);
  LeftDriveSmart.spin(forward);
  RightDriveSmart.spin(forward);
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
   
  //  LeftDriveSmart.spin(forward);
  //  RightDriveSmart.spin(forward);
  
   Controller1.ButtonR1.pressed(axelSpinForward);
   Controller1.ButtonR1.released(axelSpinStop);
   // Controller1.ButtonR1.released(axelSpinHold);
   Controller1.ButtonR2.pressed(axelSpinBackward);
   Controller1.ButtonR2.released(axelSpinStop);
   // Controller1.ButtonR2.released(axelSpinHold);
  
  


   //open and close claw
   Controller1.ButtonL1.pressed(clawMotorClose);
   Controller1.ButtonL2.pressed(clawMotorOpen);
   //placeholder
   Controller1.ButtonL1.released(clawMotorStop);
   Controller1.ButtonL2.released(clawMotorStop);
  
   LeftDriveSmart.setVelocity(Controller1.Axis3.position()+Controller1.Axis1.position(), percent);
   RightDriveSmart.setVelocity(Controller1.Axis3.position()-Controller1.Axis1.position(), percent);


   LeftDriveSmart.spin(forward);
   RightDriveSmart.spin(forward);


   Controller1.ButtonUp.pressed(brakeRobot);
 
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
 Competition.autonomous(runOnAutonomous);
 Competition.drivercontrol(runOnDriverControl);


 // Run the pre-autonomous function.
 //pre_auton();


 // Prevent main from exiting with an infinite loop.
 while (true) {
   wait(20, msec);
 }
}
