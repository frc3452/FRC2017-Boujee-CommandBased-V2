#include "DoorClose.h"
#include <Robot.h>
#include "WPILib.h"
DoorClose::DoorClose() {
	Requires(Robot::GearDoorsubsystem.get());
}
void DoorClose::Initialize() {
	SetTimeout(.595);
}
void DoorClose::Execute() {
	Robot::GearDoorsubsystem->Close();
}
bool DoorClose::IsFinished() {
	return IsTimedOut();
}
void DoorClose::End() {
	Robot::GearDoorsubsystem->Stop();
}
void DoorClose::Interrupted() {
	End();
}
