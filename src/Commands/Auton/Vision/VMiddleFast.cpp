#include "VMiddleFast.h"
#include "CmndInclude.h"
VMiddleFast::VMiddleFast() {
	AddSequential(new LightOn());
	AddSequential(new DriveTime(.4, 0, .75));
	AddSequential(new VGear(160, .24, .06, 5)); //170 //.06
	AddSequential(new DriveTime(.25, 0, .5));
	AddParallel(new ArmTime(-.5, .7));
	AddSequential(new OpenClaw(.75));
	AddSequential(new DriveTime(-.75, 0, .25));
}
