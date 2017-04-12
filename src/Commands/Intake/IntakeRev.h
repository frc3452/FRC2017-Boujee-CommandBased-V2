#ifndef IntakeRev_H
#define IntakeRev_H

#include "WPILib.h"

class IntakeRev : public frc::Command {
public:
	IntakeRev();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IntakeRev_H
