#pragma once

class Functions
{
  public:
    static void setup();
    static void setMotorToPosition(motor, float);
  private:
    static void updateFunctionMotors();
};