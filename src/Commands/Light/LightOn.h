#ifndef LightOn_H
#define LightOn_H
#include "WPILib.h"
class LightOn : public frc::Command {
public:
	LightOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LightOn_H
