#ifndef ClawChute_H
#define ClawChute_H
#include "WPILib.h"
class ClawChute : public frc::Command {
private:
	bool m_finish;
public:
	ClawChute();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClawChute_H
