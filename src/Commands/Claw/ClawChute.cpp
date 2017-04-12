#include "ClawChute.h"
#include <Robot.h>
#include "WPILib.h"
ClawChute::ClawChute() {
	Requires(Robot::Clawsubsystem.get());
	m_finish = false;
}

// Called just before this Command runs the first time
void ClawChute::Initialize() {
SetTimeout(10);
}

// Called repeatedly when this Command is scheduled to run
void ClawChute::Execute() {
	Robot::Clawsubsystem->OpenChute();
	m_finish = Robot::Clawsubsystem->PosDone();
}

// Make this return true when this Command no longer needs to run execute()
bool ClawChute::IsFinished() {
	return m_finish || IsTimedOut();
}

// Called once after isFinished returns true
void ClawChute::End() {
Robot::Clawsubsystem->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawChute::Interrupted() {
End();
}
