#include "vex.h"

#include "utils.h"

void log_brain(char* log) // I was unable to get this to just be a string, so it has to be a char*
{
  Brain.Screen.print(log);
  Brain.Screen.newLine();
}