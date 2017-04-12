#include "VPause.h"
#include <Robot.h>
VPause::VPause() {
	Requires(Robot::DriveTrainsubsystem.get());
	m_finish = false;
}
void VPause::Initialize() {
}
void VPause::Execute() {
	if (Robot::DriveTrainsubsystem->VArrSize() < 2) {
		SetTimeout(16);
	} else {
		m_finish = true;
	}
}
bool VPause::IsFinished() {
	return m_finish || IsTimedOut();
}
void VPause::End() {

}
void VPause::Interrupted() {
	End();
}
