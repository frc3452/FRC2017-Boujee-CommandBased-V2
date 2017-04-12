#ifndef ShootSpeedUp_H
#define ShootSpeedUp_H
#include "WPILib.h"

class ShootSpeedUp: public frc::Command {
	//	LOW SPEED = 1
	//	HIGH SPEED = 2
private:
	int m_setting;
	double m_target;
public:
	ShootSpeedUp(int setting);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ShootSpeedUp_H
