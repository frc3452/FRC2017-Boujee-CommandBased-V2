#include "ClimbSlow.h"
#include <Robot.h>
#include "WPILib.h"
ClimbSlow::ClimbSlow() {
Requires(Robot::Climbsubsystem.get());
}
void ClimbSlow::Initialize() {
}
void ClimbSlow::Execute() {
Robot::Climbsubsystem->Slow();
}
bool ClimbSlow::IsFinished() {
	return IsTimedOut();
}
void ClimbSlow::End() {
Robot::Climbsubsystem->Off();
}
void ClimbSlow::Interrupted() {
End();
}
