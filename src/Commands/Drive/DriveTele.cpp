#include "DriveTele.h"
#include <Robot.h>
DriveTele::DriveTele() : Command("DriveTele"){
	Requires(Robot::DriveTrainsubsystem.get());
}
DriveTele::~DriveTele()
{

}
void DriveTele::Execute() {
Robot::DriveTrainsubsystem->Arcade(Robot::oi->GetDriverJoy());
}
bool DriveTele::IsFinished() {
	return false;
}
