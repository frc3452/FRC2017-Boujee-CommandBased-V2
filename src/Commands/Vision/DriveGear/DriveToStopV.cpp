#include "DriveToStopV.h"
#include <Robot.h>
DriveToStopV::DriveToStopV(double speed) {
	Requires(Robot::DriveTrainsubsystem.get());
	m_speed = speed;
	m_finish = false;
}
void DriveToStopV::Initialize() {
	m_finish = false;
}
void DriveToStopV::Execute() {
	if (Robot::DriveTrainsubsystem->VArrSize() > 2) {
		m_finish = true;
	}
	if (Robot::DriveTrainsubsystem->VArrSize() < 2) {
		if (Robot::DriveTrainsubsystem->EncoderSpeed("LEFT") < 5) {
			Robot::DriveTrainsubsystem->Arcade(0, 0);
			SetTimeout(16);
		} else {
			Robot::DriveTrainsubsystem->Arcade(m_speed, 0);
		}
	}
}
bool DriveToStopV::IsFinished() {
	return m_finish || IsTimedOut();
}
void DriveToStopV::End() {
	Robot::DriveTrainsubsystem->Arcade(0, 0);
}
void DriveToStopV::Interrupted() {
	End();
}
