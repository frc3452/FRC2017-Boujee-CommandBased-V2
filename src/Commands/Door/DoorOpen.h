#ifndef DoorOpen_H
#define DoorOpen_H
#include "WPILib.h"
class DoorOpen : public frc::Command {
public:
	DoorOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DoorOpen_H
