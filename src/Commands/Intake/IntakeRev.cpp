#include "IntakeRev.h"
#include <Robot.h>
#include "WPILib.h"
IntakeRev::IntakeRev() {
	Requires(Robot::Intakesubsystem.get());
}
void IntakeRev::Initialize() {

}
void IntakeRev::Execute() {
	Robot::Intakesubsystem->Reverse();
}
bool IntakeRev::IsFinished() {
	return IsTimedOut();
}
void IntakeRev::End() {
	Robot::Intakesubsystem->Off();
}
void IntakeRev::Interrupted() {
	End();
}
