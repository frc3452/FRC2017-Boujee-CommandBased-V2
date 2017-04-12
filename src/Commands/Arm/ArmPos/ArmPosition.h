#ifndef ArmPosition_H
#define ArmPosition_H

#include <Commands/CommandGroup.h>

class ArmPosition : public CommandGroup {
public:
	ArmPosition(double pos);
};

#endif  // ArmPosition_H
