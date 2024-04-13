#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {

}

void autonomous(void) {
  
}

void usercontrol(void) {
  while (1) {

    wait(20, msec);
  }
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
