#ifndef ClimbSlow_H
#define ClimbSlow_H
#include "WPILib.h"

class ClimbSlow : public frc::Command {
public:
	ClimbSlow();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClimbSlow_H
