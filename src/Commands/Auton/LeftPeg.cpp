#include "LeftPeg.h"

LeftPeg::LeftPeg() {
	AddSequential(new DriveTime(.25,0,3.45)); //drive forward
	AddSequential(new DriveTime(0,0,.5));
	AddSequential(new DriveTime(0,.5,.33)); //turn
	AddSequential(new DriveTime(.25,0,1.5));
	AddSequential(new DriveTime(-.25,0, 1));
	AddSequential(new ArmTime(-.5, .5));
	AddSequential(new OpenClaw(1));
	AddSequential(new DriveTime(-.25,0, 1));
}
