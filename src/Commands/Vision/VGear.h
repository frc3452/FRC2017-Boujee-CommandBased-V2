#ifndef VGear_H
#define VGear_H

#include <Commands/CommandGroup.h>

class VGear : public CommandGroup {
public:
	VGear(int target, double forwardspeed, double adjustment, double stopspeed);
};

#endif  // VGear_H
