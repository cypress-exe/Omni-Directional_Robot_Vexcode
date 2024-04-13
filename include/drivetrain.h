#pragma once

class Drivetrain
{
  public:
    void enableControllerMovement();

  private:
    static void updateDriveMotors();
};