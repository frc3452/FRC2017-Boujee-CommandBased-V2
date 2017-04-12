#ifndef LeftPeg_H
#define LeftPeg_H

#include <Commands/CommandGroup.h>
#include "Commands/Drive/DriveTime.h"
#include "Commands/Arm/ArmTime.h"
#include "Commands/Claw/OpenClaw.h"
#include "Commands/Claw/CloseClaw.h"
#include "Commands/Door/DoorClose.h"
#include "Commands/Door/DoorOpen.h"
class LeftPeg : public CommandGroup {
public:
	LeftPeg();
};

#endif  // LeftPeg_H
