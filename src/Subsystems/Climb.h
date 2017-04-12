#ifndef Climb_H
#define Climb_H
#include "WPILib.h"
#include <Commands/Subsystem.h>

class Climb : public Subsystem {
private:
	void InitHardware();
	std::shared_ptr<Spark> ClimbMtr;
public:
	Climb();
	virtual ~Climb();
	void Slow();
	void Fast();
	void Off();
	void InitDefaultCommand();
};

#endif  // Climb_H
