#ifndef VPause_H
#define VPause_H

#include "WPILib.h"

class VPause : public frc::Command {
private:
	bool m_finish;
public:
	VPause();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // VPause_H
