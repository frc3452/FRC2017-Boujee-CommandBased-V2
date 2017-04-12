#include "VGear.h"
#include "CmndInclude.h"
VGear::VGear(int target, double forwardspeed, double adjustment, double stopspeed) {
	AddSequential(new VPause());
//	AddSequential(new DriveToStopV(.25));
	AddSequential(new DriveGearV(target, forwardspeed, adjustment, stopspeed));
}
