#include "vex.h"

#include "utils.h"

void log_brain(const char* log)
{
  Brain.Screen.print(log);
  Brain.Screen.newLine();
}