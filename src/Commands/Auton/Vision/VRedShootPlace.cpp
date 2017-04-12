#include "VRedShootPlace.h"
#include "Commands/Vision/VGear.h"
#include "Commands/Shooter/ShootTime.h"
#include "Commands/Drive/EncoderFrom.h"
#include "Commands/Drive/ResetEncoder.h"
#include "Commands/Drive/DriveTime.h"
#include "Commands/Arm/ArmTime.h"
#include "Commands/Claw/OpenClaw.h"
#include "Commands/Claw/CloseClaw.h"
#include "Commands/Light/LightOn.h"
#include "Commands/Light/LightOff.h"
VRedShootPlace::VRedShootPlace(){
	AddSequential(new ShootTime(1, 8));
	AddSequential(new LightOn());
	AddSequential(new EncoderFrom(-4.32, -8.7, 3, 4));
//	AddSequential(new EncoderFrom(-4,-4,4,4));
	AddSequential(new DriveTime(-.4,0,5));
	AddSequential(new ResetEncoder());
}
