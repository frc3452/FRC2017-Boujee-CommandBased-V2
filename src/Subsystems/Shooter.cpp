#include "Shooter.h"
#include "../RobotMap.h"
#include "CANTalon.h"
#include "WPILib.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
Shooter::Shooter() :
		Subsystem("ExampleSubsystem") {
	InitHardware();
}
void Shooter::InitHardware() {
//	INIT IDS
	SW1.reset(new CANTalon(SHOOTER_WHEEL));
	SElev.reset(new Talon(SHOOTER_ELEVATOR));
	Agitator.reset(new Spark(AGITATOR));

// ENCODERS
	SW1->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	SW1->ConfigPeakOutputVoltage(0, -12);

	SW1->SelectProfileSlot(0);
	SW1->SetP(0.075);
	SW1->SetI(0);
	SW1->SetD(0);
	SW1->SetF(0.025625);
	SW1->SetIzone(0);

	SW1->SelectProfileSlot(1);
	SW1->SetP(.25);
	SW1->SetI(0);
	SW1->SetD(0);
	SW1->SetF(0.0275);
	SW1->SetIzone(0);

// INVERT
	SW1->SetSensorDirection(false);
	SW1->SetInverted(true);
	SElev->SetInverted(false);
	Agitator->SetInverted(true);

//	SET RAMPRATE
	SW1->SetCloseLoopRampRate(3);

//	TEST MODE
	LiveWindow * lw = LiveWindow::GetInstance();
	lw->AddActuator("Shooter", "Main", SW1.get());
	lw->AddActuator("Shooter", "Elevator", SElev.get());
}
void Shooter::InitDefaultCommand() {
}
void Shooter::RunElev() {
	SElev->Set(.9);
	Agitator->Set(.75);
}
void Shooter::ReverseAdj(){
	Agitator->Set(-.75);
}
void Shooter::SetOn(double speed) {
	SW1->SetControlMode(CANSpeedController::kSpeed);
	SW1->Set(speed);
	SmartDashboard::PutNumber("SHOOTER AMP", SW1->GetOutputCurrent());
	SmartDashboard::PutNumber("SHOOTER VOLTAGE", SW1->GetOutputVoltage());
	SmartDashboard::PutNumber("SHOOTER WHEEL RPM", GetSpeed() * -1);
}
void Shooter::SetOff() {
	SW1->SetControlMode(CANSpeedController::kPercentVbus);
	SW1->Set(0);
	Agitator->Set(0);
	SElev->Set(0);
}
double Shooter::GetSpeed() {
	return (SW1->GetSpeed());
}
void Shooter::ProfSelect(int profile) {
	SW1->SelectProfileSlot(profile);
}
Shooter::~Shooter() {
}
