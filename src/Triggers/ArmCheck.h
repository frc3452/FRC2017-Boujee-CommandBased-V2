#ifndef ArmCheck_H
#define ArmCheck_H

#include "WPILib.h"
#include <Buttons/Trigger.h>

class ArmCheck : public frc::Trigger {
public:
	ArmCheck();
	virtual ~ArmCheck();
	bool Get() override;
};
#endif  // ArmCheck_H
