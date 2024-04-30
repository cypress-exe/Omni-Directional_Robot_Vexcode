#include "vex.h"
#include "robot-config.h"
#include "robot-settings.h"

#include "functions.h"

void Functions::setup()
{
  // Map the keys to Functions::updateCaptureMotorsAutomaticMode()
  Controller1.ButtonR1.pressed(updateCaptureMotorsAutomaticMode);
  Controller1.ButtonR2.pressed(updateCaptureMotorsAutomaticMode);

  Controller1.ButtonA.pressed(initCaptureMotorsManualMode);
  Controller1.ButtonB.pressed(resetCaptureMotorCallibration);

  // Zero the motors
  resetCaptureMotorCallibration();
}

void Functions::updateCaptureMotorsAutomaticMode()
{
  // Get the controller values
  bool A_pressed = Controller1.ButtonA.pressing();

  bool R1_pressed = Controller1.ButtonR1.pressing();
  bool R2_pressed = Controller1.ButtonR2.pressing();

  // If A is pressed, then manual mode is active. Thus, stop here
  if (A_pressed) return;

  // If both R1 and R2 are pressed, stop
  if (R1_pressed && R2_pressed) return;

  // Automatic Mode
  if (R2_pressed)
  {
    log_brain("-> Open");

    LeftCaptureMotor.setVelocity(capture_motors_speed, percent);
    RightCaptureMotor.setVelocity(capture_motors_speed, percent);

    // Move the left motor to the negative open value, and the right motor to the positive open value
    LeftCaptureMotor.spinToPosition(-capture_motor_open_position, degrees, false);
    RightCaptureMotor.spinToPosition(-capture_motor_open_position, degrees, true);
  }
  if (R1_pressed)
  {
    log_brain("-> Closed");

    LeftCaptureMotor.setVelocity(capture_motors_speed, percent);
    RightCaptureMotor.setVelocity(capture_motors_speed, percent);
    LeftCaptureMotor.spinToPosition(-capture_motor_closed_position, degrees, false);
    RightCaptureMotor.spinToPosition(-capture_motor_closed_position, degrees, true);
  }
}

void Functions::initCaptureMotorsManualMode(){
  // Get the controller values
  bool L1_pressed = Controller1.ButtonL1.pressing();
  bool R1_pressed = Controller1.ButtonR1.pressing();

  bool L2_pressed = Controller1.ButtonL2.pressing();
  bool R2_pressed = Controller1.ButtonR2.pressing();

  int left_motor_speed = 0;
  int right_motor_speed = 0;

  if (L1_pressed) left_motor_speed += 1;
  if (L2_pressed) left_motor_speed -= 1;
  if (R1_pressed) right_motor_speed += 1;
  if (R2_pressed) right_motor_speed -= 1;

  // Set the velocity of the motors
  LeftCaptureMotor.setVelocity(left_motor_speed * capture_motors_manual_speed, percent);
  RightCaptureMotor.setVelocity(right_motor_speed * capture_motors_manual_speed, percent);

  // Set the motors to spin forward
  LeftCaptureMotor.spin(forward);
  RightCaptureMotor.spin(forward);

  
  // Re-call this function because the user should be able to just hold down the buttons
  // And be able to control the motors smoothly
  if (Controller1.ButtonA.pressing()) initCaptureMotorsManualMode();
}

void Functions::resetCaptureMotorCallibration(){
  // Reset the digital position of the motors
  LeftCaptureMotor.resetPosition();
  RightCaptureMotor.resetPosition();

  // Log this action
  log_brain("-> Reset Capture Motor Encoders to 0");
}