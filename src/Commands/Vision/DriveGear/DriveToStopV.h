#ifndef DriveToStopV_H
#define DriveToStopV_H

#include "WPILib.h"

class DriveToStopV: public frc::Command {
private:
	double m_speed;
	bool m_finish;
public:
	DriveToStopV(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveToStopV_H
