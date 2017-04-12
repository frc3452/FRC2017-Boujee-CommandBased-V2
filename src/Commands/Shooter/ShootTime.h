#ifndef ShootTime_H
#define ShootTime_H
#include "WPILib.h"
class ShootTime: public frc::Command {
	//	LOW SPEED = 1
	//	HIGH SPEED = 2
private:
	int m_setting;
	double m_elevrun;
	double m_target;
	double m_timeout;
public:
	ShootTime(int setting, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShootTime_H
