#include "Claw.h"
#include "../RobotMap.h"
#include "CANTalon.h"
Claw::Claw() : Subsystem("ExampleSubsystem") {
	InitHardware();
	bool m_ClawDone = false;
}
void Claw::InitHardware() {
	ClawMtr.reset(new CANTalon(GEAR_CLAW));
	ClawMtr->SetEncPosition(0);
	ClawMtr->SetInverted(true);
}
void Claw::InitDefaultCommand() {
}
void Claw::Close() {
}
void Claw::Manual(double speed) {
	ClawMtr->Set(speed);
}
void Claw::OpenChute() {
	if (ClawMtr->GetEncPosition() < 2 /*ACCEPTABLE POSITION*/) {
		ClawMtr->Set(-1);
	}
	if (ClawMtr->GetEncPosition() > 1 /*ACCEPTABLE POSITION*/) {
		ClawMtr->Set(1);
	}
	if (ClawMtr->GetEncPosition() > 2 && ClawMtr->GetEncPosition() < 1) {
		ClawMtr->Set(0);
	}
	m_ClawDone = true;
}
void Claw::OpenFloor() {
	if (ClawMtr->GetEncPosition() < 0) {
		ClawMtr->Set(-1);
	} else {
		ClawMtr->Set(0);
	}
	m_ClawDone = true;
}
bool Claw::PosDone() {
	return m_ClawDone;
	m_ClawDone = false;
}
Claw::~Claw() {
}
void Claw::Stop() {
	ClawMtr->Set(0);
}
