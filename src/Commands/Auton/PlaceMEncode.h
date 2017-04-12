#ifndef PlaceMEncode_H
#define PlaceMEncode_H

#include <Commands/CommandGroup.h>
#include "Commands/Drive/EncoderDrive.h"
#include "Commands/Drive/DriveTime.h"
#include "Commands/Arm/ArmTime.h"
#include "Commands/Claw/OpenClaw.h"
#include "Commands/Claw/CloseClaw.h"
#include "Commands/Door/DoorClose.h"
#include "Commands/Door/DoorOpen.h"
class PlaceMEncode : public CommandGroup {
public:
	PlaceMEncode();
};

#endif  // PlaceMEncode_H
