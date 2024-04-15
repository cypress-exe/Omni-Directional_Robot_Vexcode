#include "vex.h"
#include "robot-settings.h"

#include "drivetrain.h"

#include <cmath>


void Drivetrain::enableControllerMovement(){
  // setup drive callbacks
  Controller1.Axis1.changed(updateDriveMotors);
  Controller1.Axis3.changed(updateDriveMotors);
  Controller1.Axis4.changed(updateDriveMotors);
}

void Drivetrain::updateDriveMotors(){
  // Left Up and Down is ROBOT Forward and Back (3)
  // Right Right and Left is ROBOT Turning (1)
  // Left Right and Left is ROBOT Strafe (4)
  
  // Get inputs
  float drive_axis_value = (float)Controller1.Axis3.position();
  float turning_axis_value = (float)Controller1.Axis1.position();
  float strafe_axis_value = (float)Controller1.Axis4.position();

  // Create variables
  float front_left_motor_velocity = 0;
  float front_right_motor_velocity = 0;
  float back_left_motor_velocity = 0;
  float back_right_motor_velocity = 0;

  // Multiply the inputs by the speed in settings
  drive_axis_value *= movement_speed_multiplier;
  turning_axis_value *= turning_speed_multiplier;
  strafe_axis_value *= strafe_speed_multiplier;


  // Set the speed of the motor only if the value is more than the deadband.

  // Movement Logic
  if (std::abs(drive_axis_value) > drive_deadband) { // Forward and Back
    front_left_motor_velocity += drive_axis_value;
    front_right_motor_velocity += drive_axis_value;
    back_left_motor_velocity += drive_axis_value;
    back_right_motor_velocity += drive_axis_value;
  }

  if (std::abs(turning_axis_value) > turning_deadband) { // Turning
    front_left_motor_velocity += turning_axis_value;
    front_right_motor_velocity -= turning_axis_value;
    back_left_motor_velocity += turning_axis_value;
    back_right_motor_velocity -= turning_axis_value;
  }

  if ((std::abs(strafe_axis_value) > strafe_deadband)) { // Left and Right
    front_left_motor_velocity -= strafe_axis_value;
    front_right_motor_velocity += strafe_axis_value;
    back_left_motor_velocity += strafe_axis_value;
    back_right_motor_velocity -= strafe_axis_value;
  }

  // Update the motors to be the computed velocity
  FrontLeftDriveMotor.setVelocity(front_left_motor_velocity, percent);
  FrontRightDriveMotor.setVelocity(front_right_motor_velocity, percent);
  BackLeftDriveMotor.setVelocity(back_left_motor_velocity, percent);
  BackRightDriveMotor.setVelocity(back_right_motor_velocity, percent);


  // Spin the motors in the forward direction.
  FrontLeftDriveMotor.spin(forward);
  FrontRightDriveMotor.spin(forward);
  BackLeftDriveMotor.spin(forward);
  BackRightDriveMotor.spin(forward);
}