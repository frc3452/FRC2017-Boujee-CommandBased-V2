#include "VRightPeg.h"
#include "CmndInclude.h"

VRightPeg::VRightPeg() {
//	AddSequential(new LightOn());
//	AddSequential(new EncoderFrom(4.4, 6.6, 2.9, 4.8)); //3.2 5.1
//	AddSequential(new DriveTime(0,0,0.5));
//	AddSequential(new DriveTime(.25,0,.25));
//	AddSequential(new VGear(170, .22, .08, 5));
//	AddSequential(new DriveTime(.25, 0, .9));
//	AddParallel(new ArmTime(-.5, .7));
//	AddSequential(new OpenClaw(.75));
//	AddSequential(new DriveTime(-.75, 0, .5));
	AddSequential(new LightOn());
	AddSequential(new EncoderFrom(4.8, 6.8, 2.9, 5.2)); //5.5 3.2
	AddSequential(new DriveTime(.25, 0, .2));
	AddSequential(new VGear(160, .32, .12, 2));
	AddSequential(new DriveTime(.25, 0, .9));
	AddParallel(new ArmTime(-.5, .7));
	AddSequential(new OpenClaw(.75));
	AddSequential(new DriveTime(-.75, 0, .5));
}
