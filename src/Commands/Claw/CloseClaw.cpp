#include "CloseClaw.h"
#include "WPILib.h"
#include <Robot.h>
CloseClaw::CloseClaw(double Timeout) {
	m_Time = Timeout;
}
void CloseClaw::Initialize() {
SetTimeout(m_Time);
}
void CloseClaw::Execute() {
Robot::Clawsubsystem->Manual(-1);
}
bool CloseClaw::IsFinished() {
	return IsTimedOut();
}
void CloseClaw::End() {
Robot::Clawsubsystem->Stop();
}
void CloseClaw::Interrupted() {
End();
}
