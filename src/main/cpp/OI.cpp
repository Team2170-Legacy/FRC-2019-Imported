// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "frc/smartdashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/ElevatorInnerPos.h"
#include "Commands/ElevatorOuterPos.h"
#include "Commands/ElevatorRearPos.h"
#include "Commands/GotoIntakePosition.h"
#include "Commands/InitRobot.h"
#include "Commands/IntakeDown.h"
#include "Commands/IntakeToggle.h"
#include "Commands/IntakeUp.h"
#include "Commands/PlaceHatch.h"
#include "Commands/TeleopDrive.h"
#include "Commands/TeleopElevator.h"
#include "Commands/TeleopElevatorOverrideUp.h"
#include "Commands/TeleopElevatorOverrideDown.h"
#include "Commands/TeleopIntake.h"
#include "Commands/TeleopOuttake.h"
#include "Commands/VisionDrive.h"
#include "Commands/ToggleCameraExposure.h"
#include "Commands/overrideDriveForward.h"
#include "Commands/overrideDriveBack.h"
#include "Commands/overrideDriveTR.h"
#include "Commands/overrideDriveTL.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/PlaceHatch.h"
#include "Commands/RaiseRobot.h"
#include "Commands/ClimbHighPlatform.h"
#include "Commands/ClimbLowPlatform.h"
#include "Commands/DriveStraightDistance.h"
#include "Commands/ElevatorInnerOuterPos.h"
#include "Commands/HatchL1.h"
#include "Commands/HatchL2.h"
#include "Commands/HatchL3.h"


/**
 * @brief Construct a new OI::OI object
 * 
 * 1. Initialize all push buttons (on push button panel)
 * 2. Initialize buttons for rotate commands
 * 3. Initialize buttons on driver joystick for hatch drop, vision lock, exposure toggle,
 *    intake/outtake, and raising robot
 */
OI::OI() {
    // Process operator interface input here.
//    pushbuttonPanel.reset(new frc::Joystick(2));
    
    if (Robot::IsPracticeBot()) {
      printf("Practice OI\n");
      frc::SmartDashboard::PutData("Hatch L1", new ElevatorInnerPos(Robot::elevator->kHatchL1, false));
      frc::SmartDashboard::PutData("Hatch L2", new ElevatorInnerPos(Robot::elevator->kHatchL2, false));
      frc::SmartDashboard::PutData("Cargo L1", new ElevatorInnerPos(Robot::elevator->kCargoL1, false));
      frc::SmartDashboard::PutData("Cargo L2", new ElevatorInnerPos(Robot::elevator->kCargoL2, false));
    }
    else {
      frc::SmartDashboard::PutData("Hatch L3", new HatchL3());
      frc::SmartDashboard::PutData("Hatch L2", new HatchL2());
      frc::SmartDashboard::PutData("Hatch L1", new HatchL1());
      frc::SmartDashboard::PutData("DEFENSE", new ElevatorInnerOuterPos(0.5, 2.0));

      frc::SmartDashboard::PutData("Climb High", new ClimbHighPlatform());
      frc::SmartDashboard::PutData("Climb Low", new ClimbLowPlatform());
    }

   driverJoystick.reset(new frc::Joystick(0));

   if (Robot::IsTankDrive()) {
       driverJoystickRight.reset(new frc::Joystick(3));
   }

   operatorJoystick.reset(new frc::XboxController(1));

   // driver joystick button setups
   joystickDriverButtonHatchDrop.reset(new frc::JoystickButton(driverJoystick.get(), 1));
   joystickDriverButtonHatchDrop->WhenPressed(new PlaceHatch());
	joystickDriverButtonVisionLock.reset(new frc::JoystickButton(driverJoystick.get(), 2));
   joystickDriverButtonVisionLock->WhileHeld(new VisionDrive());
   joystickDriverButtonExposureToggle.reset(new frc::JoystickButton(driverJoystick.get(), 3));
   joystickDriverButtonExposureToggle->WhenPressed(new ToggleCameraExposure());

// override buttons for when we lose xbox controller mid match. Driver can get full control
// of robot. 2 new commands created for these buttons. 
   driverElevatorOverrideUP.reset(new frc::JoystickButton(driverJoystick.get(), 6)); 
   driverElevatorOverrideUP->WhileHeld(new TeleopElevatorOverrideUp()); // override command 1
   driverElevatorOverrideDOWN.reset(new frc::JoystickButton(driverJoystick.get(), 4));
   driverElevatorOverrideDOWN->WhileHeld(new TeleopElevatorOverrideDown()); // override command 2

//operator xbox controller gets full control of the robot when the driver stick goes out. 
// 4 specific commands calling velocity arcade method in drivetrain. 
   operatorDriverOverrideForward.reset(new frc::JoystickButton(operatorJoystick.get(), 6));
   operatorDriverOverrideForward->WhileHeld(new overrideDriveForward()); //override command 1
   operatorDriverOverrideReverse.reset(new frc::JoystickButton(operatorJoystick.get(), 5));
   operatorDriverOverrideReverse->WhileHeld(new overrideDriveBack()); // override command 2
   operatorDriverOverrideTR.reset(new frc::JoystickButton(operatorJoystick.get(), 8));
   operatorDriverOverrideTR->WhileHeld(new overrideDriveTR()); // override command 3
   operatorDriverOverrideTL.reset(new frc::JoystickButton(operatorJoystick.get(), 7));
   operatorDriverOverrideTL->WhileHeld(new overrideDriveTL()); // override command 4


   if (!Robot::IsPracticeBot()) {
      joystickButtonToggleIntake.reset(new frc::JoystickButton(operatorJoystick.get(), 3));
      joystickButtonToggleIntake->WhenPressed(new HatchL1());
      joystickButtonOuttake.reset(new frc::JoystickButton(operatorJoystick.get(), 2));
      joystickButtonOuttake->WhenPressed(new HatchL2());
      joystickButtonIntake.reset(new frc::JoystickButton(operatorJoystick.get(), 1));
      joystickButtonIntake->WhenPressed(new HatchL3());
   }
   else {
      printf("Intake Buttons Bypassed\n");
   }
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

/**
 * @brief Get the left driver joystick pointer
 * 
 * @return std::shared_ptr<frc::Joystick> 
 */
std::shared_ptr<frc::Joystick> OI::getDriverJoystick() {
   return driverJoystick;
}

/**
 * @brief Get the push button panel pointer
 * 
 * @return std::shared_ptr<frc::Joystick> 
 */
std::shared_ptr<frc::Joystick> OI::getPushbuttonPanel() {
   return pushbuttonPanel;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

/**
 * @brief Get the operator joystick pointer
 * 
 * @return std::shared_ptr<frc::Joystick> 
 */
std::shared_ptr<frc::XboxController> OI::getOperatorJoystick() {
   return operatorJoystick;
}

/**
 * @brief Get the right driver joystick pointer
 * 
 * @return std::shared_ptr<frc::Joystick> 
 */
std::shared_ptr<frc::Joystick> OI::getDriverJoystickRight() {
   return driverJoystickRight;
}