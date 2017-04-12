#ifndef DoorSaftey_H
#define DoorSaftey_H

#include "WPILib.h"

class DoorSaftey : public frc::Command {
public:
	DoorSaftey();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DoorSaftey_H
