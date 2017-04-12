#include "Robot.h"
#include "WPILib.h"
#include "CmndInclude.h"
std::unique_ptr<OI> Robot::oi;
std::unique_ptr<DriveTrain> Robot::DriveTrainsubsystem;
std::unique_ptr<Claw> Robot::Clawsubsystem;
std::unique_ptr<Shooter> Robot::Shootersubsystem;
std::unique_ptr<Arm> Robot::Armsubsystem;
std::unique_ptr<GearDoor> Robot::GearDoorsubsystem;
std::unique_ptr<Light> Robot::Lightsubsystem;
std::unique_ptr<Intake> Robot::Intakesubsystem;
std::unique_ptr<Climb> Robot::Climbsubsystem;
void Robot::RobotInit() {
	DriveTrainsubsystem.reset(new DriveTrain());
	Clawsubsystem.reset(new Claw());
	Armsubsystem.reset(new Arm());
	Shootersubsystem.reset(new Shooter());
	Intakesubsystem.reset(new Intake());
	GearDoorsubsystem.reset(new GearDoor());
	Lightsubsystem.reset(new Light());
	Climbsubsystem.reset(new Climb());
	oi.reset(new OI());

	chooser.AddDefault("Drive Forward", new DriveTime(.25, 0, 3.9));
	chooser.AddObject("Gear: Middle", new VMiddlePeg());
	chooser.AddObject("Gear: Middle (Fast)", new VMiddleFast());
	chooser.AddObject("Gear: Right", new VRightPeg());
	chooser.AddObject("Gear: Left", new VLeftPeg());
	chooser.AddObject("Gear: Left (Shoot)", new LPegShootB());
	chooser.AddObject("Shoot: Blue ", new VBlueShootPlace());
	chooser.AddObject("Shoot: Red", new VRedShootPlace());

//	OLD AUTONS
//	chooser.AddObject("Reset: For Pits", new Reset());
//	chooser.AddObject("Spin Wheel: Cleaning", new ShootSpeedUpTime(2,20));
//	chooser.AddObject("Place Gear: Right (Encoder)", new PlaceREncode());
//	chooser.AddObject("Place Gear: Left", new LeftPeg());
//	chooser.AddObject("Place Gear: Middle", new DriveNPlace());
//	chooser.AddObject("Place Gear: Middle (Encoder)", new PlaceMEncode());
	SmartDashboard::PutData("Auton Selecterion", &chooser);

//	SmartDashboard::PutData(DriveTrainsubsystem.get());
//	SmartDashboard::PutData(Clawsubsystem.get());
//	SmartDashboard::PutData(Armsubsystem.get());
//	SmartDashboard::PutData(Shootersubsystem.get());
//	SmartDashboard::PutData(Intakesubsystem.get());
//	SmartDashboard::PutData(GearDoorsubsystem.get());
//	SmartDashboard::PutData(Lightsubsystem.get());
//	SmartDashboard::PutData(Climbsubsystem.get());
//	frc::SmartDashboard::SetDefaultNumber("Shooter Speed", DefaultShooterSpeed);
}
void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}
void Robot::AutonomousInit() {
	autonomousCommand.reset(chooser.GetSelected());
	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Start();
	}
}
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand != nullptr) {
		autonomousCommand->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot);

