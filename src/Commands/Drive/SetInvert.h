#include "WPILib.h"
#ifndef SetInvert_H
#define SetInvert_H

class SetInvert : public frc::Command {
private:
	bool m_invert;
public:
	SetInvert(bool on);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetInvert_H
