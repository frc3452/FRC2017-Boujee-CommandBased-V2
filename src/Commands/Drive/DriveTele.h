#ifndef DriveTele_H
#define DriveTele_H
#include "WPILib.h"
class DriveTele : public Command {
public:
	DriveTele();
	virtual ~DriveTele();
	void Execute();
	bool IsFinished();
};
#endif  // DriveTele_H
