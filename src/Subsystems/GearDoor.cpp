#include "GearDoor.h"
#include "../RobotMap.h"
#include "WPILib.h"
GearDoor::GearDoor() :
		Subsystem("ExampleSubsystem") {
	InitHardware();
}
void GearDoor::InitHardware() {
	GearDoorMtr.reset(new Talon(GEAR_DOOR));
	m_Pos = true;
//	TEST MODE
	LiveWindow * lw = LiveWindow::GetInstance();
	lw->AddActuator("GearDoor", "Door", GearDoorMtr.get());

}
void GearDoor::InitDefaultCommand() {
}
bool GearDoor::GetPos() {
	return m_Pos;
}
void GearDoor::Open() {
	GearDoorMtr->Set(-.6);
	m_Pos = true;
	SmartDashboard::PutBoolean("Door Pos:", m_Pos);
}
void GearDoor::Close() {
	GearDoorMtr->Set(.6);
	m_Pos = false;
	SmartDashboard::PutBoolean("Door Pos:", m_Pos);
}
void GearDoor::Stop() {
	GearDoorMtr->Set(0);
}
void GearDoor::Manual(double speed) {
	GearDoorMtr->Set(speed);
}
GearDoor::~GearDoor() {

}
void GearDoor::NT() {
//table = NetworkTable::GetTable("GRIP/myCountoursReport");
}
