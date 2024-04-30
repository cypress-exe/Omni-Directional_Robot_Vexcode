#pragma once

class Functions
{
  public:
    static void setup();
    static void setMotorToPosition(motor, float); // might be able to remove
  private:
    static void updateCaptureMotorsAutomaticMode();
    static void initCaptureMotorsManualMode();
    static void resetCaptureMotorCallibration();
};