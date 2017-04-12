#ifndef Intake_H
#define Intake_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
class Intake : public Subsystem {
private:
	void InitHardware();
	std::shared_ptr<Spark> IntakeMtr;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Intake();
	virtual ~Intake();
	void InitDefaultCommand();
	void On();
	void Off();
	void Reverse();
};

#endif  // Intake_H
