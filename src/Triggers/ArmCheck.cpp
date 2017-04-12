#include "ArmCheck.h"
#include <Robot.h>
ArmCheck::ArmCheck() {
}
ArmCheck::~ArmCheck() {
}

bool ArmCheck::Get() {
	if((Robot::Armsubsystem->IsMove() == true) && Robot::GearDoorsubsystem->GetPos() == false){
		return true;
	}
}
