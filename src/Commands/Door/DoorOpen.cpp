#include "DoorOpen.h"
#include <Robot.h>
#include "WPILib.h"
DoorOpen::DoorOpen() {
	Requires(Robot::GearDoorsubsystem.get());
}
void DoorOpen::Initialize() {
	SetTimeout(.66);
}
void DoorOpen::Execute() {
	Robot::GearDoorsubsystem->Open();
}
bool DoorOpen::IsFinished() {
	return IsTimedOut();
}
void DoorOpen::End() {
	Robot::GearDoorsubsystem->Stop();
}
void DoorOpen::Interrupted() {
	End();
}
