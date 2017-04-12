#ifndef ArmTime_H
#define ArmTime_H
#include "WPILib.h"
class ArmTime : public frc::Command {
private:
	double m_speed;
	double m_time;
public:
	ArmTime(double speed, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmTime_H
