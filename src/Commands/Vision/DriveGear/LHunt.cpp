#include "LHunt.h"
#include <Robot.h>
#include "WPILib.h"
LHunt::LHunt() {
	m_finish = false;
	Requires(Robot::DriveTrainsubsystem.get());
	m_centerx = 0;
}
void LHunt::Initialize() {
	Robot::Lightsubsystem->Control(true);
	SetTimeout(5);
	Wait(.5);
	m_finish = false;
}
void LHunt::Execute() {
	m_centerx = Robot::DriveTrainsubsystem->VReport("centerX", 1);
	SmartDashboard::PutNumber("CENTERX", m_centerx);
	if (Robot::DriveTrainsubsystem->VArrSize() < 2) {
		if ((m_centerx > 0) && (m_centerx < 160)) {
			Robot::DriveTrainsubsystem->Arcade(0, -.3);
		} else {
			Robot::Intakesubsystem->On();
		}
	} else {
		m_finish = true;
	}
}
bool LHunt::IsFinished() {
	return IsTimedOut() || m_finish;
}
void LHunt::End() {
	Robot::DriveTrainsubsystem->Arcade(0, 0);
	Robot::Lightsubsystem->Control(false);
	Robot::Intakesubsystem->Off();
}
void LHunt::Interrupted() {
	End();
}
