#ifndef ClimbFast_H
#define ClimbFast_H
#include "WPILib.h"
class ClimbFast : public frc::Command {
public:
	ClimbFast();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClimbFast_H
