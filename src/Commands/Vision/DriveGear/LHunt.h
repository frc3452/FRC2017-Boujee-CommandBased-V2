#ifndef LHunt_H
#define LHunt_H

#include "WPILib.h"

class LHunt: public frc::Command {
private:
	bool m_finish;
	double m_centerx;
public:
	LHunt();
	void Initialize();
	void Execute();bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LHunt_H
