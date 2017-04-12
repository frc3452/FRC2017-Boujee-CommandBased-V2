#include "OpenClaw.h"
#include "WPILib.h"
#include <Robot.h>
OpenClaw::OpenClaw(double Timeout) {
	m_Time = Timeout;
}
void OpenClaw::Initialize() {
	SetTimeout(m_Time);
}
void OpenClaw::Execute() {
	Robot::Clawsubsystem->Manual(1);
}
bool OpenClaw::IsFinished() {
	return IsTimedOut();
}
void OpenClaw::End() {
	Robot::Clawsubsystem->Stop();
}
void OpenClaw::Interrupted() {
	End();
}
