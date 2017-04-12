#ifndef GearDoor_H
#define GearDoor_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
class GearDoor : public Subsystem {
private:
	void InitHardware();
	std::shared_ptr<NetworkTable> table;
	std::shared_ptr<Talon> GearDoorMtr;
	bool m_Pos;
public:
	void NT();
	GearDoor();
	virtual ~GearDoor();
	void InitDefaultCommand();
	void Open();
	void Close();
	void Stop();
	bool GetPos();
	void Manual(double speed);
};

#endif  // GearDoor_H
