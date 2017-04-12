#include "ShootSpeedUpTime.h"
#include "WPILib.h"
#include <Robot.h>
ShootSpeedUpTime::ShootSpeedUpTime(int setting, double timeout) {
	Requires(Robot::Shootersubsystem.get());
	m_setting = setting;
	m_timeout = timeout;
}
void ShootSpeedUpTime::Initialize() {
	SetTimeout(m_timeout);
}
void ShootSpeedUpTime::Execute() {
	if (m_setting == 1) {
		m_target = 3870;
		Robot::Shootersubsystem->ProfSelect(0);

	}
	if (m_setting == 2) {
		m_target = 4500;
		Robot::Shootersubsystem->ProfSelect(1);
	}
	Robot::Shootersubsystem->SetOn(m_target);

}
bool ShootSpeedUpTime::IsFinished() {
	return IsTimedOut();
}
void ShootSpeedUpTime::End() {
	Robot::Shootersubsystem->SetOff();
}
void ShootSpeedUpTime::Interrupted() {
	End();
}
