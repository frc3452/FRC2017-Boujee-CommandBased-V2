#include "WPILib.h"
#ifndef SetModify_H
#define SetModify_H

class SetModify : public frc::Command {
private:
	double m_modvalue;
public:
	SetModify(double modvalue);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetModify_H
