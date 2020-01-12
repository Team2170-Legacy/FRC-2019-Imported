// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "frc/WPILib.h"

class OI {
private:
	std::shared_ptr<frc::Joystick> pushbuttonPanel;
	std::shared_ptr<frc::JoystickButton> pushButtonBlue3;
	std::shared_ptr<frc::JoystickButton> pushButtonBlue2;
	std::shared_ptr<frc::JoystickButton> pushButtonBlue1;
	std::shared_ptr<frc::JoystickButton> pushButtonRed3;
	std::shared_ptr<frc::JoystickButton> pushButtonRed2;
	std::shared_ptr<frc::JoystickButton> pushButtonRed1;
	std::shared_ptr<frc::Joystick> driverJoystick;
	std::shared_ptr<frc::JoystickButton> counterClockwiseTurn;
	std::shared_ptr<frc::JoystickButton> clockwiseTurn;


	std::shared_ptr<frc::XboxController> operatorJoystick;
	std::shared_ptr<frc::Joystick> driverJoystickRight;

	std::shared_ptr<frc::JoystickButton> joystickButtonToggleIntake;
	std::shared_ptr<frc::JoystickButton> joystickButtonOuttake;
	std::shared_ptr<frc::JoystickButton> joystickButtonIntake;
	std::shared_ptr<frc::JoystickButton> joystickButtonRaiseRobot;

	std::shared_ptr<frc::JoystickButton> joystickDriverButtonHatchDrop;
	std::shared_ptr<frc::JoystickButton> joystickDriverButtonVisionLock;
	std::shared_ptr<frc::JoystickButton> joystickDriverButtonForward;
	std::shared_ptr<frc::JoystickButton> joystickDriverButtonExposureToggle;

	std::shared_ptr<frc::JoystickButton> driverElevatorOverrideUP;
	std::shared_ptr<frc::JoystickButton> driverElevatorOverrideDOWN;

	std::shared_ptr<frc::JoystickButton> operatorDriverOverrideForward;
	std::shared_ptr<frc::JoystickButton> operatorDriverOverrideReverse;
	std::shared_ptr<frc::JoystickButton> operatorDriverOverrideTR;
	std::shared_ptr<frc::JoystickButton> operatorDriverOverrideTL; 
	//four buttons that move the robot at constant velocity. 

public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<frc::Joystick> getDriverJoystick();
	std::shared_ptr<frc::Joystick> getPushbuttonPanel();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<frc::XboxController> getOperatorJoystick();
	std::shared_ptr<frc::Joystick> getDriverJoystickRight();
};

#endif