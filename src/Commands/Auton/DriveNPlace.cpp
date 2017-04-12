#include "WPILib.h"
#include "DriveNPlace.h"
#include "Commands/Drive/DriveTime.h"
#include "Commands/Arm/ArmTime.h"
#include "Commands/Claw/OpenClaw.h"
#include "Commands/Claw/CloseClaw.h"
#include "Commands/Door/DoorClose.h"
#include "Commands/Door/DoorOpen.h"
DriveNPlace::DriveNPlace() {
	AddSequential(new DriveTime(.25,0,3.9));
	AddSequential(new ArmTime(-.5, .5));
	AddSequential(new OpenClaw(1));
	AddSequential(new DriveTime(-.25,0, 1));
}
