#include "Intake.h"
#include "../RobotMap.h"
#include "Commands/Intake/IntakeOff.h"
#include "WPILib.h"
Intake::Intake() :
		Subsystem("ExampleSubsystem") {
	InitHardware();
}
Intake::~Intake() {
}
void Intake::InitHardware() {
	IntakeMtr.reset(new Spark(INTAKE));
	IntakeMtr->SetInverted(true);
//	TEST MODE
	LiveWindow * lw = LiveWindow::GetInstance();
	lw->AddActuator("Intake", "Door", IntakeMtr.get());
}
void Intake::InitDefaultCommand() {
	SetDefaultCommand(new IntakeOff());
}
void Intake::On() {
	IntakeMtr->Set(.75);
}
void Intake::Off() {
	IntakeMtr->Set(0);
}
void Intake::Reverse() {
	IntakeMtr->Set(-.75);
}
