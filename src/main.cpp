#include "vex.h"

#include "drivetrain.h"
#include "functions.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {
  log_brain("----- Omni-Directional Robot Vexcode -----");
  log_brain("-> Pre Autonomous");
}

void autonomous(void) {
  log_brain("-> Autonomous");
}

void usercontrol(void) {
  log_brain("-> Driver Control");

  Drivetrain::setup();
  Functions::setup();
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
