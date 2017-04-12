#ifndef ResetEncoder_H
#define ResetEncoder_H

#include "WPILib.h"

class ResetEncoder : public frc::Command {
public:
	ResetEncoder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ResetEncoder_H
