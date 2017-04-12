#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "CANTalon.h"
class Arm: public Subsystem {
private:
	void InitHardware();
	std::shared_ptr<CANTalon> ArmRotater;
	bool m_done;
	bool m_tomove;
public:
	Arm();
	virtual ~Arm();
	void InitDefaultCommand();
	void Manual(double move);
	void Manual(std::shared_ptr<Joystick> JoyStick);
	void ToPosition(double pos);
	void ToPositionB(double pos);
	bool PosDone();
	void PosReset();

	int Pos();
	void ToMove(bool ismove);
	bool IsMove();

};

#endif  // Arm_H
