#include "robot-settings.h"

// Deadband stops the motors when Axis values are close to zero.
const int drive_deadband = 5;
const int turning_deadband = 5;
const int strafe_deadband = 10;

// Speed of the movement of the robot (not strafing)
const float movement_speed_multiplier = 1;

// Speed of the turning of the robot
const float turning_speed_multiplier = 0.5;

// Speed of the strafe movement of the robot
const float strafe_speed_multiplier = 0.7;