#include "VBlueShootPlace.h"
#include "CmndInclude.h"
VBlueShootPlace::VBlueShootPlace() {
	AddSequential(new ShootTime(1, 8));
	AddSequential(new LightOn());
	AddSequential(new EncoderFrom(-8.7, -4.32, 4.5, 3));
	AddSequential(new EncoderFrom(1.5, 2.3, 4.25, 4.25));
	AddSequential(new EncoderFrom(2, 2, 4, 4));
	AddSequential(new ResetEncoder());
//	AddSequential(new VGear(100, .2, .3, 3, "LEFT"));
//	AddSequential(new VGear(100, .2, .1, 4.9, "LEFT"));
//	AddSequential(new ArmTime(-.5, .7));
//	AddSequential(new OpenClaw(.75));
//	AddSequential(new DriveTime(-.25, 0, 1));
}
