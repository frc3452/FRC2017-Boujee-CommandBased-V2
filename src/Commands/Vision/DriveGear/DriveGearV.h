#ifndef DriveGearV_H
#define DriveGearV_H

#include "WPILib.h"

class DriveGearV: public frc::Command {
private:
	int m_target;
	int m_centerpos;
	double m_contour1;
	double m_contour2;
	bool m_finish;

	double m_forwardspeed;
	double m_adjustment;
	double m_stopspeed;
public:
	DriveGearV(int target, double forwardspeed, double adjustment, double stopspeed);
	void Initialize();
	void Execute();bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveGearV_H
