#include "DriveGearV.h"
#include <stdlib.h>
#include <Robot.h>
DriveGearV::DriveGearV(int target, double forwardspeed, double adjustment,
		double stopspeed) {
	Requires(Robot::DriveTrainsubsystem.get());

	m_finish = false;
	m_target = target;
	m_centerpos = 0;

	m_forwardspeed = forwardspeed;
	m_adjustment = adjustment;
	m_stopspeed = stopspeed;
}
void DriveGearV::Initialize() {
	m_finish = false;
	SetTimeout(8);
}
void DriveGearV::Execute() {
	if ((Robot::DriveTrainsubsystem->VArrSize() < 2)) {
		m_finish = true;
	}
	if (Robot::DriveTrainsubsystem->EncoderSpeed("LEFT") < m_stopspeed) {
		m_finish = true;
	}

	m_contour1 = (Robot::DriveTrainsubsystem->VReport("centerX", 0));
	m_contour2 = (Robot::DriveTrainsubsystem->VReport("centerX", 1));

	if (m_contour1 < m_contour2) {
		m_centerpos = ((abs(m_contour2 - m_contour1) / 2) + m_contour1);
	}
	if (m_contour2 < m_contour1) {
		m_centerpos = ((abs(m_contour2 - m_contour1) / 2) + m_contour2);
	}
	SmartDashboard::PutNumber("current position of the vision", m_centerpos);

	if ((m_centerpos > m_target - 1) && (m_centerpos < m_target + 1)) {
		Robot::DriveTrainsubsystem->Arcade(-m_forwardspeed, 0);
	} else if (m_centerpos > m_target - 1) {
		Robot::DriveTrainsubsystem->Arcade(-m_forwardspeed, m_adjustment);
	} else if (m_centerpos < m_target + 1) {
		Robot::DriveTrainsubsystem->Arcade(-m_forwardspeed, -m_adjustment);
	}
}
bool DriveGearV::IsFinished() {
	return m_finish || IsTimedOut();
}
void DriveGearV::End() {
	Robot::DriveTrainsubsystem->Arcade(0, 0);
	Robot::Lightsubsystem->Control(false);
}
void DriveGearV::Interrupted() {
	End();
}
