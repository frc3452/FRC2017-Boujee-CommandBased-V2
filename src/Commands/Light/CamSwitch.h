#ifndef CamSwitch_H
#define CamSwitch_H

#include "WPILib.h"

class CamSwitch : public frc::Command {
private:
	int cam;
public:
	CamSwitch(int camswitch);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CamSwitch_H
