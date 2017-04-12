#ifndef IntakeOn_H
#define IntakeOn_H

#include "WPILib.h"
class IntakeOn : public frc::Command {
public:
	IntakeOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IntakeOn_H
