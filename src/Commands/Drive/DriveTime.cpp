#include "DriveTime.h"
#include <Robot.h>
#include "WPILib.h"
DriveTime::DriveTime(double speed, double rotate, double time) {
	m_speed = speed;
	m_time = time;
	m_rotate = rotate;
	Requires(Robot::DriveTrainsubsystem.get());
}
void DriveTime::Initialize() {
SetTimeout(m_time);
}
void DriveTime::Execute() {
Robot::DriveTrainsubsystem->Arcade(-1*m_speed, m_rotate); //.032
}
bool DriveTime::IsFinished() {
	return IsTimedOut();
}
void DriveTime::End() {
Robot::DriveTrainsubsystem->Arcade(0,0);
}
void DriveTime::Interrupted() {
End();
}
