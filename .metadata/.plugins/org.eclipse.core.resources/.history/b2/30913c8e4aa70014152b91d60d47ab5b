#include "WPILib.h"
#include "stdio.h"
#include "math.h"
class Robot: public SampleRobot
{
	RobotDrive myRobot;
	Talon leftDriveMotor;
	Talon rightDriveMotor;
	Joystick leftDriveStick; // right joystick
	Joystick rightDriveStick; // left joystick

public:
	Robot() :
			myRobot(0,1),
			leftDriveMotor(0),
			rightDriveMotor(1),
			leftDriveStick(0),
			rightDriveStick(1)
	{
		myRobot.SetExpiration(0.1);
	}
	float smoothJoyStick(float joyInput)
	{
		return powf(joyInput,3);
	}
	void OperatorControl()
	{
		while (IsOperatorControl() && IsEnabled())
		{
			leftDriveMotor.Set(smoothJoyStick(leftDriveStick.GetY()));
			rightDriveMotor.Set(smoothJoyStick(rightDriveStick.GetY()));
			Wait(0.005);				// wait for a motor update time
		}
	}

};

START_ROBOT_CLASS(Robot);
