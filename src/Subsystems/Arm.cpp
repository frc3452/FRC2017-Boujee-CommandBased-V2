#include "Arm.h"
#include "../RobotMap.h"
#include "WPILib.h"
Arm::Arm() :
		Subsystem("ExampleSubsystem") {
	InitHardware();
	m_done = false;
	m_tomove = false;
}
Arm::~Arm() {
}
void Arm::InitHardware() {
	ArmRotater.reset(new CANTalon(GEAR_ARM));

	ArmRotater->ConfigLimitMode(
			CANSpeedController::kLimitMode_SrxDisableSwitchInputs);
	ArmRotater->SetFeedbackDevice(CANTalon::AnalogPot);
//	ArmRotater->SetAnalogPosition(0);
	LiveWindow * lw = LiveWindow::GetInstance();
//	lw->AddActuator("Arm", "ArmMotor", ArmRotater.get());

}
int Arm::Pos() {
	return (ArmRotater->GetAnalogIn());
}
void Arm::InitDefaultCommand() {
}
void Arm::Manual(double move) {
	ArmRotater->Set(move);
	SmartDashboard::PutNumber("Arm Pot", ArmRotater->GetPosition());
}
void Arm::Manual(std::shared_ptr<Joystick> JoyStick) {
	if (JoyStick->GetRawAxis(1) > 0) {
		Manual(JoyStick->GetRawAxis(1) * -.75);
	}
	if (JoyStick->GetRawAxis(1) < 0) {
		Manual(JoyStick->GetRawAxis(1) * -1);
	}
}
void Arm::ToPosition(double pos) {
	if ((ArmRotater->GetAnalogIn()) < pos) {
		ArmRotater->Set(-.1);
		SmartDashboard::PutNumber("Arm Pot", ArmRotater->GetPosition());
	}
	if ((ArmRotater->GetAnalogIn()) > pos) {
		ArmRotater->Set(.2);
		SmartDashboard::PutNumber("Arm Pot", ArmRotater->GetPosition());
	}
	if (ArmRotater->GetPosition() == pos) {
		ArmRotater->Set(0);
		m_done = true;
		SmartDashboard::PutNumber("Arm Pot", ArmRotater->GetPosition());
	}
}
void Arm::ToPositionB(double pos) {
	if ((ArmRotater->GetAnalogIn()) < pos) {
		ArmRotater->Set(-.6);
		SmartDashboard::PutNumber("Arm Pot", ArmRotater->GetPosition());
	}
	if ((ArmRotater->GetAnalogIn()) > pos) {
		ArmRotater->Set(.6);
		SmartDashboard::PutNumber("Arm Pot", ArmRotater->GetPosition());
	}
	if (((ArmRotater->GetPosition() < pos + 7)
			&& (ArmRotater->GetPosition() > pos - 7))) {
		ArmRotater->Set(0);
		m_done = true;
		SmartDashboard::PutNumber("Arm Pot", ArmRotater->GetPosition());
	}
}
bool Arm::PosDone() {
	return m_done;
}
void Arm::PosReset() {
	m_done = false;
}

void Arm::ToMove(bool ismove) {
	m_tomove = ismove;
}
bool Arm::IsMove() {
	return m_tomove;
}
