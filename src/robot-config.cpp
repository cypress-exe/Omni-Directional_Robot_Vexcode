#include "vex.h"

#include "robot-config.h"

using namespace vex;

// A global instance of the brain
brain Brain;

// VEXcode device constructors

// Controller
controller Controller1 = controller(primary);

// Motors
motor FrontLeftDriveMotor = motor(PORT1, ratio18_1, false);
motor FrontRightDriveMotor = motor(PORT10, ratio18_1, true);
motor BackLeftDriveMotor = motor(PORT11, ratio18_1, false);
motor BackRightDriveMotor = motor(PORT20, ratio18_1, true);