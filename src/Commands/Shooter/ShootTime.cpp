#include "ShootTime.h"
#include "WPILib.h"
#include <Robot.h>

ShootTime::ShootTime(int setting, double time) {
	Requires(Robot::Shootersubsystem.get());
	m_setting = setting;
	m_timeout = time;
}
void ShootTime::Initialize() {
	SetTimeout(m_timeout);
}
void ShootTime::Execute() {
	if (m_setting == 1) {
		m_elevrun = -3700;
		m_target = 3870;
		Robot::Shootersubsystem->ProfSelect(0);

	}
	if (m_setting == 2) {
		m_elevrun = -4300;
		m_target = 4500;
		Robot::Shootersubsystem->ProfSelect(1);
	}
	Robot::Shootersubsystem->SetOn(m_target);
	if (Robot::Shootersubsystem->GetSpeed() < m_elevrun) {
		Robot::Shootersubsystem->RunElev();
	}
}
bool ShootTime::IsFinished() {
	return IsTimedOut();
}
void ShootTime::End() {
	Robot::Shootersubsystem->SetOff();
}
void ShootTime::Interrupted() {
	End();
}
