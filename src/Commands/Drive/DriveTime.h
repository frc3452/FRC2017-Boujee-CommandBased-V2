#ifndef DriveTime_H
#define DriveTime_H
#include "WPILib.h"
class DriveTime : public frc::Command {
private:
	double m_speed;
	double m_time;
	double m_rotate;
public:
	DriveTime(double speed, double rotate, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveTime_H
