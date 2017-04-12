#include "PlaceMEncode.h"

PlaceMEncode::PlaceMEncode() {
	AddSequential(new EncoderDrive(5, 5, 2.5, 2.5));
	AddSequential(new EncoderDrive(6, 6, 2, 2));
	AddSequential(new ArmTime(-.5, .5));
	AddSequential(new OpenClaw(1));
	AddSequential(new DriveTime(-.25, 0, 1));
}
