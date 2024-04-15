#include "vex.h"

#include "drivetrain.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {
  Brain.Screen.print("----- Omni-Directional Robot Vexcode -----");
  Brain.Screen.newLine();
  Brain.Screen.print("-> Pre-autonomous");
  Brain.Screen.newLine();
}

void autonomous(void) {
  Brain.Screen.print("-> Autonomous");
  Brain.Screen.newLine();
}

void usercontrol(void) {
  Brain.Screen.print("-> Driver Control");
  Brain.Screen.newLine();

  Drivetrain drivetrain;
  drivetrain.enableControllerMovement();
}

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
