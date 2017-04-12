#include "EncoderDrive.h"
#include "WPILib.h"
#include <Robot.h>
EncoderDrive::EncoderDrive(double left, double right, double leftspeed, double rightspeed) {
	m_left = left;
	m_right = right;
	m_lspeed = leftspeed;
	m_rspeed = rightspeed;
	m_done = false;
	Requires(Robot::DriveTrainsubsystem.get());
}
void EncoderDrive::Initialize() {
	SetTimeout(7);
	m_done = false;
}
void EncoderDrive::Execute() {
	Robot::DriveTrainsubsystem->Encoder(m_left, m_right, m_lspeed, m_rspeed);
	m_done = Robot::DriveTrainsubsystem->isMove();
}
bool EncoderDrive::IsFinished() {
	return m_done || IsTimedOut();
}
void EncoderDrive::End() {
	Robot::DriveTrainsubsystem->EncoderDone();
}
void EncoderDrive::Interrupted() {
	End();
}
