#include "OI.h"
#include "RobotMap.h"
#include <Robot.h>
#include "SmartDashboard/SmartDashboard.h"
#include "Triggers/ArmCheck.h"
#include "Commands/Auton/AutonomousCommand.h"
#include "CmndInclude.h"

//			TRIGGERS
OI::OI() {
	m_ArmCheck.reset(new ArmCheck());

	DriverJoy.reset(new Joystick(0));
	DriverJoyA.reset(new JoystickButton(DriverJoy.get(), 1));
	DriverJoyB.reset(new JoystickButton(DriverJoy.get(), 2));
	DriverJoyX.reset(new JoystickButton(DriverJoy.get(), 3));
	DriverJoyY.reset(new JoystickButton(DriverJoy.get(), 4));
	DriverJoyLB.reset(new JoystickButton(DriverJoy.get(), 5));
	DriverJoyRB.reset(new JoystickButton(DriverJoy.get(), 6));
	DriverJoyBack.reset(new JoystickButton(DriverJoy.get(), 7));
	DriverJoyStart.reset(new JoystickButton(DriverJoy.get(), 8));
	DriverJoyLClick.reset(new JoystickButton(DriverJoy.get(), 9));
	DriverJoyRClick.reset(new JoystickButton(DriverJoy.get(), 10));

	OpJoy.reset(new Joystick(1));
	OpJoyA.reset(new JoystickButton(OpJoy.get(), 1));
	OpJoyB.reset(new JoystickButton(OpJoy.get(), 2));
	OpJoyX.reset(new JoystickButton(OpJoy.get(), 3));
	OpJoyY.reset(new JoystickButton(OpJoy.get(), 4));
	OpJoyLB.reset(new JoystickButton(OpJoy.get(), 5));
	OpJoyRB.reset(new JoystickButton(OpJoy.get(), 6));
	OpJoyBack.reset(new JoystickButton(OpJoy.get(), 7));
	OpJoyStart.reset(new JoystickButton(OpJoy.get(), 8));
	OpJoyLClick.reset(new JoystickButton(OpJoy.get(), 9));
	OpJoyRClick.reset(new JoystickButton(OpJoy.get(), 10));

//	DRIVER JOY
	DriverJoyA->WhenPressed(new SetModify(.5));
	DriverJoyA->WhenReleased(new SetModify(1));

	DriverJoyX->WhileHeld(new ClimbSlow());
	DriverJoyB->WhileHeld(new ClimbFast());

	DriverJoyY->WhileHeld(new Shoot(1));

	DriverJoyRB->WhileHeld(new LightOn());
	DriverJoyRB->WhenReleased(new LightOff());

//	OP JOY
	OpJoyX->WhileHeld(new Manual(1));
	OpJoyB->WhileHeld(new Manual(-1));

//	OpJoyBack->WhileHeld(new ReverseAdj());

	OpJoyStart->WhileHeld(new IntakeOn());
	OpJoyStart->WhenReleased(new IntakeOff());

	OpJoyLClick->WhileHeld(new ArmTele());
	OpJoyLClick->WhenReleased(new ArmTime(0, .01));

	OpJoyRClick->WhenPressed(new DoorClose());

// SmartDashboard Buttons
//	SmartDashboard::PutData("Door Close", new DoorClose());
//	SmartDashboard::PutData("Door Open", new DoorOpen());
//
//	SmartDashboard::PutData("ArmUp", new ArmTime(.5,.5));
//	SmartDashboard::PutData("ArmDown", new ArmTime(-.5,.5));
//	SmartDashboard::PutData("ArmStop", new ArmTime(0,100));
//
//	SmartDashboard::PutData("ClawOpen", new Manual(1));
//	SmartDashboard::PutData("ClawClose", new Manual(-1));
//	SmartDashboard::PutData("ClawStop", new Manual(0));
//	SmartDashboard::PutData("Intake: On", new IntakeOn());

	mCamera0 = CameraServer::GetInstance()->StartAutomaticCapture(0);
	mCamera0.SetExposureManual(20); //8 with GRIPV5
	mCamera0.SetFPS(30);
	mCamera1 = CameraServer::GetInstance()->StartAutomaticCapture(1);
//	mCamera1.SetExposureManual(5);
//	mCamera1.SetFPS(30);
//	mCamera2 = CameraServer::GetInstance()->StartAutomaticCapture(2);
//	server = CameraServer::GetInstance()->GetServer();

	//	TRIGGERS
	m_ArmCheck->WhenActive(new DoorSaftey());

}

std::shared_ptr<Joystick> OI::GetDriverJoy() {
	return DriverJoy;
}
std::shared_ptr<Joystick> OI::GetOpJoy() {
	return OpJoy;
}
