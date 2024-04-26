#include "vex.h"
#include "robot-config.h"
#include "robot-settings.h"

#include "functions.h"

void Functions::setup()
{
  // Map the keys to Functions::updateFunctionMotors()
  Controller1.ButtonL1.pressed(updateFunctionMotors);
  Controller1.ButtonL2.pressed(updateFunctionMotors);
  Controller1.ButtonR1.pressed(updateFunctionMotors);
  Controller1.ButtonR2.pressed(updateFunctionMotors);

  Controller1.ButtonA.pressed(updateFunctionMotors);
}

// void Functions::setMotorToPosition(motor _motor, float target_rotation){
//   float actual_rotation = _motor.position(degrees);
//   float rotation_delta = actual_rotation - target_rotation;

//   _motor.spinToPosition()
// }

void Functions::updateFunctionMotors()
{
  // Get the controller values
  bool A_pressed = Controller1.ButtonA.pressing();
  bool B_pressed = Controller1.ButtonB.pressing();
  
  bool L1_pressed = Controller1.ButtonL1.pressing();
  bool R1_pressed = Controller1.ButtonR1.pressing();

  bool L2_pressed = Controller1.ButtonL2.pressing();
  bool R2_pressed = Controller1.ButtonR2.pressing();

  if (A_pressed) // Manual mode.
  {
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
  } else {
    if (B_pressed) // Reset Button
    {
      LeftCaptureMotor.resetPosition();
      RightCaptureMotor.resetPosition();
      Brain.Screen.print("-> Reset Capture Motors Encoders to 0");
      Brain.Screen.newLine();

    } else {
      LeftCaptureMotor.setVelocity(0, percent);
      RightCaptureMotor.setVelocity(0, percent);

      // Automatic Mode
      if (R1_pressed && (!R2_pressed))
      {
        Brain.Screen.print("-> R1");
        Brain.Screen.newLine();
        LeftCaptureMotor.setVelocity(capture_motors_speed, percent);
        RightCaptureMotor.setVelocity(capture_motors_speed, percent);
        // Move the left motor to the negative open value, and the right motor to the positive open value
        LeftCaptureMotor.spinToPosition(-capture_motor_closed_position, degrees, false);
        RightCaptureMotor.spinToPosition(capture_motor_closed_position, degrees, true);
      } else {
        if (R2_pressed) {
          Brain.Screen.print("-> R2");
          Brain.Screen.newLine();
          LeftCaptureMotor.setVelocity(capture_motors_speed, percent);
          RightCaptureMotor.setVelocity(capture_motors_speed, percent);
          LeftCaptureMotor.spinToPosition(0, degrees, false);
          RightCaptureMotor.spinToPosition(0, degrees, true);
        }
      }
    }
  }

  // Re-call ourselves if A was pressed
  if (A_pressed)
  {
    updateFunctionMotors(); // Call ourselves
  }
}