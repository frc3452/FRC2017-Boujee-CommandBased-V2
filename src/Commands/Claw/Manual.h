#ifndef Manual_H
#define Manual_H
#include "WPILib.h"

class Manual : public frc::Command {
private:
	double m_speed;
public:
	Manual(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Manual_H
