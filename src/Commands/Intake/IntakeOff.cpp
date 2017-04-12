#include "IntakeOff.h"
#include "WPILib.h"
#include <Robot.h>
IntakeOff::IntakeOff() {
	Requires(Robot::Intakesubsystem.get());
}

// Called just before this Command runs the first time
void IntakeOff::Initialize() {
SetTimeout(.01);
}

// Called repeatedly when this Command is scheduled to run
void IntakeOff::Execute() {
Robot::Intakesubsystem->Off();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeOff::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void IntakeOff::End() {
Robot::Intakesubsystem->Off();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeOff::Interrupted() {
End();
}
