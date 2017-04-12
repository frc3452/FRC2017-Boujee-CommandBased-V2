#include "DoorSaftey.h"
#include <Robot.h>
DoorSaftey::DoorSaftey() {
	Requires(Robot::GearDoorsubsystem.get());
}
void DoorSaftey::Initialize() {
	SetTimeout(.66);
}
void DoorSaftey::Execute() {
	Robot::GearDoorsubsystem->Open();
}
bool DoorSaftey::IsFinished() {
	return IsTimedOut();
}
void DoorSaftey::End() {
Robot::GearDoorsubsystem->Stop();
}
void DoorSaftey::Interrupted() {
	End();
}
