#include "ReverseAdj.h"
#include <Robot.h>

ReverseAdj::ReverseAdj() {
	Requires(Robot::Shootersubsystem.get());
}
void ReverseAdj::Initialize() {

}
void ReverseAdj::Execute() {
	Robot::Shootersubsystem->ReverseAdj();
}
bool ReverseAdj::IsFinished() {
	return false;
}
void ReverseAdj::End() {
	Robot::Shootersubsystem->SetOff();
}
void ReverseAdj::Interrupted() {
	End();
}
