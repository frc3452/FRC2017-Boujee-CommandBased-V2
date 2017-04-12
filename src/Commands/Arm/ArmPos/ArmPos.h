#ifndef ArmPos_H
#define ArmPos_H
#include "WPILib.h"

class ArmPos: public frc::Command {
private:
	double m_pos;
	bool m_finish;
public:
	ArmPos(double pos);
	void Initialize();
	void Execute();bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmPos_H
