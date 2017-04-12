#ifndef EncoderDrive_H
#define EncoderDrive_H
#include "WPILib.h"

class EncoderDrive : public frc::Command {
private:
	double m_left;
	double m_right;
	double m_lspeed;
	double m_rspeed;
	bool m_done;
public:
	EncoderDrive(double left, double right, double leftspeed, double rightspeed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // EncoderDrive_H
