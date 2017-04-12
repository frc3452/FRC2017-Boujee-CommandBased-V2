#include "VLeftPeg.h"
#include "CmndInclude.h"

VLeftPeg::VLeftPeg() {
//	AddSequential(new LightOn());
//	AddSequential(new EncoderFrom(.25, .75, 4, 4));
//	AddSequential(new EncoderFrom(3, 3, 4, 4));
//	AddSequential(new DriveTime(.25, 0, .25));
//	AddSequential(new VGear(160, .27, .1, 5));
//	AddSequential(new DriveTime(.25, 0, .9));
//	AddParallel(new ArmTime(-.5, .7));
//	AddSequential(new OpenClaw(.75));
//	AddSequential(new DriveTime(-.75, 0, .5));
	AddSequential(new LightOn());
	AddSequential(new EncoderFrom(6.8, 4.8, 5.2, 2.9)); //5.5 3.2
	AddSequential(new DriveTime(.25, 0, .2));
	AddSequential(new VGear(160, .32, .12, 2));
	AddSequential(new DriveTime(.25, 0, .9));
	AddParallel(new ArmTime(-.5, .7));
	AddSequential(new OpenClaw(.75));
	AddSequential(new DriveTime(-.75, 0, .5));
}
