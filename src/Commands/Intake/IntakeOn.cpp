#include "IntakeOn.h"
#include <Robot.h>
#include "WPILib.h"
IntakeOn::IntakeOn() {
	Requires(Robot::Intakesubsystem.get());
}
void IntakeOn::Initialize() {
}
void IntakeOn::Execute() {
	Robot::Intakesubsystem->On();
}
bool IntakeOn::IsFinished() {
	return IsTimedOut();
}
void IntakeOn::End() {
	Robot::Intakesubsystem->Off();
}
void IntakeOn::Interrupted() {
	End();
}
