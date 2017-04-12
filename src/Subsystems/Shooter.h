#ifndef Shooter_H
#define Shooter_H
#include <Commands/Subsystem.h>
#include "CANTalon.h"
#include "WPILib.h"
class Shooter : public Subsystem {
private:
	void InitHardware();
	std::shared_ptr<CANTalon> SW1;
	std::shared_ptr<Talon> SElev;
	std::shared_ptr<Spark> Agitator;

public:
	Shooter();
	virtual ~Shooter();
	void InitDefaultCommand();
	void SetOn(double speed);
	void SetOff();
	void RunElev();
	void ReverseAdj();
	double GetSpeed();
	void ProfSelect(int profile);
};

#endif  // Shooter_H
