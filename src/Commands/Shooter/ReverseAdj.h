#ifndef ReverseAdj_H
#define ReverseAdj_H

#include "WPILib.h"

class ReverseAdj : public frc::Command {
public:
	ReverseAdj();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ReverseAdj_H
