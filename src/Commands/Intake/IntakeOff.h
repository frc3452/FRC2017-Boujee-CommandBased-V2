#ifndef IntakeOff_H
#define IntakeOff_H
#include "WPILib.h"
class IntakeOff : public frc::Command {
public:
	IntakeOff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IntakeOff_H
