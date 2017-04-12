#include "Chute.h"
#include "RobotMap.h"
#include "Commands/Arm/ArmPos/ArmPosition.h"
#include "Commands/Door/DoorClose.h"
#include "Commands/Door/DoorOpen.h"
Chute::Chute() {
	AddSequential(new ArmPosition(UPPER_LIMIT));
	AddSequential(new DoorClose());
}
