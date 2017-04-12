#include "VMiddlePeg.h"
#include "CmndInclude.h"
VMiddlePeg::VMiddlePeg() {
	AddSequential(new LightOn());
	AddSequential(new DriveTime(.25, 0, .8));
	AddSequential(new VGear(160, .22, .04, 5)); //170
	AddSequential(new DriveTime(.25, 0, .5));
	AddParallel(new ArmTime(-.5, .7));
	AddSequential(new OpenClaw(.75));
	AddSequential(new DriveTime(-.75, 0, .25));

}
