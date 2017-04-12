#ifndef Test_H
#define Test_H

#include "WPILib.h"

class Test : public	frc::Command {
private:
	bool m_finish;
public:
	Test();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Test_H
