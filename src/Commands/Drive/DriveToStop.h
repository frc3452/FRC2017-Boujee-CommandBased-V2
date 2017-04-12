#ifndef DriveToStop_H
#define DriveToStop_H

#include "WPILib.h"

class DriveToStop : public frc::Command {
private:
	bool m_finish;
	double m_speed;
public:
	DriveToStop(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveToStop_H
