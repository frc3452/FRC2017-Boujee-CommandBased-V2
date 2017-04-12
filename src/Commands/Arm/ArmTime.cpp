#include "ArmTime.h"
#include <Robot.h>
#include "WPILib.h"
ArmTime::ArmTime(double speed, double time) {
	m_speed = speed;
	m_time = time;
}
void ArmTime::Initialize() {
	Robot::Armsubsystem->ToMove(true);
	SetTimeout(m_time);
}
void ArmTime::Execute() {
//	if (Robot::GearDoorsubsystem->GetPos() == false) {
//		Robot::GearDoorsubsystem->Open();
//		Wait(.66);
//	Robot::GearDoorsubsystem->Stop();
//	}
	Robot::Armsubsystem->Manual(m_speed);
}
bool ArmTime::IsFinished() {
	return IsTimedOut();
}
void ArmTime::End() {
	Robot::Armsubsystem->Manual(0);
	Robot::Armsubsystem->ToMove(false);
}
void ArmTime::Interrupted() {
	End();
}
