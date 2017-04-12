#ifndef Shoot_H
#define Shoot_H
#include "WPILib.h"
class Shoot: public frc::Command {
	//	LOW SPEED = 1
	//	HIGH SPEED = 2
private:
	int m_setting;
	double m_elevrun;
	double m_target;
public:
	Shoot(int setting);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Shoot_H
