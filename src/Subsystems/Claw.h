#ifndef Claw_H
#define Claw_H

#include <Commands/Subsystem.h>
#include "CANTalon.h"
#include "WPILib.h"
class Claw: public Subsystem {
private:
	bool m_ClawDone;
	void InitHardware();
	std::shared_ptr<CANTalon> ClawMtr;
public:
	Claw();
	void InitDefaultCommand();
	void OpenChute();
	void OpenFloor();
	void Close();
	void Manual(double speed);
	bool PosDone();
	virtual ~Claw();
	void Stop();
};

#endif  // Claw_H
