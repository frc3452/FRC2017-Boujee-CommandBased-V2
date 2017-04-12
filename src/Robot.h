#ifndef _ROBOT_H
#define _ROBOT_H
#include "WPILib.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "CmndInclude.h"
#include "OI.h"

#include <Subsystems/DriveTrain.h>
#include <Subsystems/Shooter.h>
#include <Subsystems/Intake.h>
#include <Subsystems/Arm.h>
#include <Subsystems/GearDoor.h>
#include <Subsystems/Light.h>
#include <Subsystems/Claw.h>
#include <Subsystems/Climb.h>

class Robot: public IterativeRobot {
public:
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<DriveTrain> DriveTrainsubsystem;
	static std::unique_ptr<Claw> Clawsubsystem;
	static std::unique_ptr<Shooter> Shootersubsystem;
	static std::unique_ptr<Arm> Armsubsystem;
	static std::unique_ptr<Intake> Intakesubsystem;
	static std::unique_ptr<GearDoor> GearDoorsubsystem;
	static std::unique_ptr<Light> Lightsubsystem;
	static std::unique_ptr<Climb> Climbsubsystem;
public:
	virtual void RobotInit();

	virtual void DisabledInit();
	virtual void DisabledPeriodic();

	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();

	virtual void TestPeriodic();
private:
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser<Command*> chooser;
};
#endif

