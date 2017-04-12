#include "ShootSpeedUp.h"
#include <Robot.h>
#include "WPILib.h"
ShootSpeedUp::ShootSpeedUp(int setting) {
	Requires(Robot::Shootersubsystem.get());
	m_setting = setting;
}
void ShootSpeedUp::Initialize() {
//	SetTimeout(.01);
}
void ShootSpeedUp::Execute() {
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
bool ShootSpeedUp::IsFinished() {
	return IsTimedOut();
}
void ShootSpeedUp::End() {
	Robot::Shootersubsystem->SetOff();
}
void ShootSpeedUp::Interrupted() {
	End();
}
