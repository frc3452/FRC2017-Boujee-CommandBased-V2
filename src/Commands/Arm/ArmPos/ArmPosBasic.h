#ifndef ArmPosBasic_H
#define ArmPosBasic_H

#include "WPILib.h"

class ArmPosBasic: public frc::Command {
private:
	double m_pos;
	bool m_finish;
public:
	ArmPosBasic(double pos);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmPosBasic_H
