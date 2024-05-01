#include "robot-settings.h"

// Deadband stops the motors when Axis values are close to zero.
const int drive_deadband = 5;
const int turning_deadband = 5;
const int strafe_deadband = 10;

// Speed of the movement of the robot (not strafing)
const float movement_speed = 1;

// Speed of the turning of the robot
const float turning_speed = 0.5;

// Speed of the strafe movement of the robot
const float strafe_speed = 0.7;

// Speed of the capture motors
const float capture_motors_speed = 100;

// Step speed of the capture motors in manual mode
const float capture_motors_manual_speed = 10;

// Capture Motor Positions
const float capture_motor_open_position = 180;
const float capture_motor_closed_position = 0;

// Corrects the center of mass being not centered (too forward / backward)
// Positive number for it being too far forward, and
// Negative number for it being too far backward
const float center_of_mass_correction = 0; //untested