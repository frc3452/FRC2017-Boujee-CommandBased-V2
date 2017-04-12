#ifndef LightOff_H
#define LightOff_H
#include "WPILib.h"
class LightOff : public frc::Command {
public:
	LightOff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LightOff_H
