#include "WPILib.h"
#include "stdio.h"
#include "math.h"
class Robot: public SampleRobot
{
	RobotDrive myRobot;
	Talon leftDriveMotor;
	Talon rightDriveMotor;
	//Joystick leftDriveStick; // right joystick
	Joystick DriveStick; // single test joystick
	//Joystick rightDriveStick; // left joystick

public:
	Robot() :
			myRobot(0,1),
			leftDriveMotor(0),
			rightDriveMotor(1),
			DriveStick(0)
			//rightDriveStick(0),
			//leftDriveStick(1)
	{
		myRobot.SetExpiration(0.5);
	}
	float smoothJoyStick(float joyInput)
	{
		return powf(joyInput,3);
	}
	void OperatorControl()
	{
		while (IsOperatorControl() && IsEnabled())
		{
			leftDriveMotor.Set(smoothJoyStick(DriveStick.GetY()));
			rightDriveMotor.Set(smoothJoyStick(DriveStick.GetY()));
			Wait(0.005);				// wait for a motor update time
		}
	}

};

START_ROBOT_CLASS(Robot);
