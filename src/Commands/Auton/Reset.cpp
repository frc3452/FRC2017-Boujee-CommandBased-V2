#include "Reset.h"
#include "WPILib.h"
#include "Commands/Drive/DriveTime.h"
#include "Commands/Arm/ArmTime.h"
#include "Commands/Claw/OpenClaw.h"
#include "Commands/Claw/CloseClaw.h"
#include "Commands/Door/DoorClose.h"
#include "Commands/Door/DoorOpen.h"
Reset::Reset() {
	AddSequential(new DoorOpen());
	AddSequential(new ArmTime(.5,.7));
	AddSequential(new OpenClaw(.5));
	AddSequential(new DriveTime(0,0,6));
	AddSequential(new CloseClaw(2));
	AddSequential(new OpenClaw(.2));
}
