#include "DriveToStop.h"
#include <Robot.h>
DriveToStop::DriveToStop(double speed) {
	Requires(Robot::DriveTrainsubsystem.get());
	m_finish = false;
	m_speed = speed;
}
void DriveToStop::Initialize() {
	m_finish = false;
	SetTimeout(10);
}
void DriveToStop::Execute() {
	if (Robot::DriveTrainsubsystem->EncoderSpeed("LEFT") < 5) {
		m_finish = true;
	} else {
	Robot::DriveTrainsubsystem->Arcade(m_speed, 0);
	}
}
bool DriveToStop::IsFinished() {
	return m_finish;
}
void DriveToStop::End() {
	Robot::DriveTrainsubsystem->Arcade(0, 0);
}
void DriveToStop::Interrupted() {
	End();
}
