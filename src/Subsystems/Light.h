#ifndef Light_H
#define Light_H
#include "Relay.h"
#include <Commands/Subsystem.h>

class Light : public Subsystem {
private:
	void InitHardware();
	std::shared_ptr<Relay> lightrelay;
public:
	Light();
	virtual ~Light();
	void InitDefaultCommand();
	void Control(bool on);
	void CamSwitch(int camswitch);
};

#endif  // Light_H
