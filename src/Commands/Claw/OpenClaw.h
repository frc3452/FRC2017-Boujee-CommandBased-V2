#ifndef OpenClaw_H
#define OpenClaw_H
#include "WPILib.h"
class OpenClaw : public frc::Command {
private:
	double m_Time;
public:
	OpenClaw(double Timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OpenClaw_H
