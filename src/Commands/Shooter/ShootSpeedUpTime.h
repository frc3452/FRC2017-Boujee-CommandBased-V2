#ifndef ShootSpeedUpTime_H
#define ShootSpeedUpTime_H

#include "WPILib.h"

class ShootSpeedUpTime: public frc::Command {
	//	LOW SPEED = 1
	//	HIGH SPEED = 2
private:
	int m_setting;
	double m_target;
	double m_timeout;
public:
	ShootSpeedUpTime(int setting, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShootSpeedUpTime_H
