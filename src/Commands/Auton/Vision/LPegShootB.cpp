#include "LPegShootB.h"
#include "CmndInclude.h"
LPegShootB::LPegShootB() {
	AddSequential(new LightOn());
	AddSequential(new EncoderFrom(.25,.75, 4, 4));
	AddSequential(new EncoderFrom(3,3,4,4));
	AddSequential(new DriveTime(.25, 0, .25));
	AddSequential(new VGear(160, .27, .1, 5));
	AddSequential(new DriveTime(.25, 0, .9));
	AddParallel(new ArmTime(-.5, .7));
	AddSequential(new OpenClaw(.75));
	AddSequential(new DriveTime(-.75, 0, .5));
	AddSequential(new EncoderFrom(3, -4, 5.5, 5.5));
	AddParallel(new ArmTime(.5,.8));
	AddSequential(new DriveTime(.25, 0, .5));
	AddSequential(new DriveToStop(-.35));
	AddSequential(new EncoderFrom(-.3,0.2,5,5));
	AddSequential(new ShootTime(1,8));
}
