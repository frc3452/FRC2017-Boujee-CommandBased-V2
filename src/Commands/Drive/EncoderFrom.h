#ifndef EncoderFrom_H
#define EncoderFrom_H

#include <Commands/CommandGroup.h>

class EncoderFrom : public CommandGroup {
public:
	EncoderFrom(double left, double right, double leftspeed, double rightspeed);
};

#endif  // EncoderFrom_H
