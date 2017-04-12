#include "ClimbFast.h"
#include <Robot.h>
#include "WPILib.h"
ClimbFast::ClimbFast() {
	Requires(Robot::Climbsubsystem.get());
}
void ClimbFast::Initialize() {
}
void ClimbFast::Execute() {
	Robot::Climbsubsystem->Fast();
}
bool ClimbFast::IsFinished() {
	return IsTimedOut();
}
void ClimbFast::End() {
	Robot::Climbsubsystem->Off();
}
void ClimbFast::Interrupted() {
	End();
}
