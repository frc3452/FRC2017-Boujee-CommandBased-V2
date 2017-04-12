#include "ArmPosition.h"
#include "Commands/Arm/ArmPos/ArmPos.h"
#include "Commands/Arm/ArmPos/ArmPosBasic.h"
#include "Commands/Door/DoorClose.h"
#include "Commands/Door/DoorOpen.h"
ArmPosition::ArmPosition(double pos) {
	AddSequential(new ArmPosBasic(pos));
	AddSequential(new ArmPos(pos));
}
