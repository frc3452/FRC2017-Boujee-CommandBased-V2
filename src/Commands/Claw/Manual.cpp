#include "Manual.h"
#include <Robot.h>
#include "WPILib.h"
Manual::Manual(double speed) {
	m_speed = speed;
	Requires(Robot::Clawsubsystem.get());
}
void Manual::Initialize() {
}
void Manual::Execute() {
	if (m_speed == 0) {
		Robot::oi->GetDriverJoy()->SetRumble(frc::GenericHID::kLeftRumble, 0);
		Robot::oi->GetDriverJoy()->SetRumble(frc::GenericHID::kRightRumble, 0);
	}
	Robot::Clawsubsystem->Manual(m_speed);
	Robot::oi->GetDriverJoy()->SetRumble(frc::GenericHID::kLeftRumble, 1);
	Robot::oi->GetDriverJoy()->SetRumble(frc::GenericHID::kRightRumble, 1);
}
bool Manual::IsFinished() {
	return false;
}
void Manual::End() {
	Robot::oi->GetDriverJoy()->SetRumble(frc::GenericHID::kLeftRumble, 0);
	Robot::oi->GetDriverJoy()->SetRumble(frc::GenericHID::kRightRumble, 0);
	Robot::Clawsubsystem->Manual(0);
}
void Manual::Interrupted() {
	End();
}
