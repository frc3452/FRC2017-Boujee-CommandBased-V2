#ifndef ArmTele_H
#define ArmTele_H
#include "WPILib.h"
class ArmTele : public frc::Command {
public:
	ArmTele();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmTele_H
