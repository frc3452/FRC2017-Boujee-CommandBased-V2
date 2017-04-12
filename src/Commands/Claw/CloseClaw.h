#ifndef CloseClaw_H
#define CloseClaw_H
#include "WPILib.h"
class CloseClaw : public frc::Command {
private:
	double m_Time;
public:
	CloseClaw(double Timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CloseClaw_H
