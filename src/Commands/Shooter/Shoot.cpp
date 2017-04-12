#include "Shoot.h"
#include "WPILib.h"
#include <Robot.h>
Shoot::Shoot(int setting) {
	Requires(Robot::Shootersubsystem.get());
	m_setting = setting;
}
void Shoot::Initialize() {
}
void Shoot::Execute() {
	if (m_setting == 1) {
		m_elevrun = -3800; //-3750
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

bool Shoot::IsFinished() {
	return IsTimedOut();
}
void Shoot::End() {
	Robot::Shootersubsystem->SetOff();
}
void Shoot::Interrupted() {
	End();
}
