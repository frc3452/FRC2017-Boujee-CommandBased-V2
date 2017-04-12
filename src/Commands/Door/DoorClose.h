#ifndef DoorClose_H
#define DoorClose_H
#include "WPILib.h"
class DoorClose : public frc::Command {
public:
	DoorClose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DoorClose_H
