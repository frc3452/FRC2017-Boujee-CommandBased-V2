#include "GyroPos.h"
#include <Robot.h>
GyroPos::GyroPos(double targetangle, double speed, double precise) {
	Requires(Robot::DriveTrainsubsystem.get());
	m_target = targetangle;
	m_speed = speed;
	m_precise = precise;
	m_done = false;
}
void GyroPos::Initialize() {
	SetTimeout(8);
	m_done = false;
	m_gyro = Robot::DriveTrainsubsystem->GyroReport();
	Robot::DriveTrainsubsystem->GyroReset();
}
void GyroPos::Execute() {
	m_gyro = Robot::DriveTrainsubsystem->GyroReport();
	SmartDashboard::PutNumber("NAVX ANGLE", m_gyro);

	if (m_gyro < 360 && m_gyro > 180) {
		if ((m_gyro < (m_target + 180)) && (m_gyro > m_target)) {
			Robot::DriveTrainsubsystem->Arcade(0, -m_speed);
		} else {
			Robot::DriveTrainsubsystem->Arcade(0, m_speed);
		}
	}

	if (m_gyro > 0 && m_gyro < 180) {
		if ((m_gyro > (m_target - 180)) && (m_gyro < m_target)) {
			Robot::DriveTrainsubsystem->Arcade(0, m_speed);
		} else {
			Robot::DriveTrainsubsystem->Arcade(0, -m_speed);
		}
	}

	if ((m_gyro < (m_target + m_precise)) && (m_gyro > (m_target - m_precise))) {
		Robot::DriveTrainsubsystem->Arcade(0, 0);
		m_done = true;
	}

}
bool GyroPos::IsFinished() {
	return m_done || IsTimedOut();
}
void GyroPos::End() {
	Robot::DriveTrainsubsystem->Arcade(0, 0);
}
void GyroPos::Interrupted() {
	End();
}
