#ifndef GyroPos_H
#define GyroPos_H

#include "WPILib.h"

class GyroPos : public frc::Command {
private:
	double m_gyro;
	bool m_done;
	double m_target;
	double m_speed;
	double m_precise;
public:
	GyroPos(double targetangle, double speed, double precise);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GyroPos_H
