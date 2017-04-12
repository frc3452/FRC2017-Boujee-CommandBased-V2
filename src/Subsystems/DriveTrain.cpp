#include "DriveTrain.h"
#include "Commands/Drive/DriveTele.h"
#include "CANTalon.h"
#include <Subsystems/DriveTrain.h>
#include "RobotMap.h"
#include <Robot.h>
#include <ntcore.h>
#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
DriveTrain::DriveTrain() :
		Subsystem("ExampleSubsystem") {
	InitHardware();
	m_modify = 1;
	m_invert = 1;
	v_broke = false;
	m_gyrodone = false;
}
DriveTrain::~DriveTrain() {
}
void DriveTrain::InitHardware() {
	vtable = NetworkTable::GetTable("GRIP/vision");

//	DRIVE INIT
	LF.reset(new CANTalon(DRIVE_LEFT_FRONT));
	LB.reset(new CANTalon(DRIVE_LEFT_BACK));
	RF.reset(new CANTalon(DRIVE_RIGHT_FRONT));
	RB.reset(new CANTalon(DRIVE_RIGHT_BACK));
	RoboDrive.reset(new RobotDrive(LF, RF));

//	GYRO
	Gyro.reset(new AHRS(SerialPort::kMXP));
	Gyro->Reset();

//	SLAVE
	LB->SetControlMode(CANSpeedController::kFollower);
	LB->Set(DRIVE_LEFT_FRONT);
	RB->SetControlMode(CANSpeedController::kFollower);
	RB->Set(DRIVE_RIGHT_FRONT);

//	ENCODERS
	LF->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	RF->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	LF->SetEncPosition(0);
	RF->SetEncPosition(0);
	LF->SetSensorDirection(true);
	RF->SetSensorDirection(false);
	LF->SelectProfileSlot(0);
	RF->SelectProfileSlot(0);

	LF->SetF(0);
	LF->SetP(.4);
	LF->SetI(0);
	LF->SetD(6);

	RF->SetF(0);
	RF->SetP(.4);
	RF->SetI(0);
	RF->SetD(6);

//P = .2
//I = .002
//	DRIVE INVERSION
	RoboDrive->SetInvertedMotor(frc::RobotDrive::kRearLeftMotor, true);
	RoboDrive->SetInvertedMotor(frc::RobotDrive::kRearRightMotor, true);

	//	TEST MODE
	LiveWindow * lw = LiveWindow::GetInstance();
	lw->AddActuator("DriveTrain", "Left 1", LF.get());
	lw->AddActuator("DriveTrain", "Left 2", LB.get());
	lw->AddActuator("DriveTrain", "Right 1", RF.get());
	lw->AddActuator("DriveTrain", "Right 2", RB.get());
}
void DriveTrain::Arcade(double move, double rotate) {
	RoboDrive->ArcadeDrive(move, rotate, false);
}
void DriveTrain::Arcade(std::shared_ptr<Joystick> JoyStick) {
	Arcade((JoyStick->GetRawAxis(1) * m_modify * m_invert),
			((JoyStick->GetRawAxis(3) - JoyStick->GetRawAxis(2)) * m_modify));
	SmartDashboard::PutNumber("LF POS", LF->GetPosition());
	SmartDashboard::PutNumber("RF POS", RF->GetPosition());
	SmartDashboard::PutNumber("LEFT ENCVEL", LF->GetSpeed() /* * .011363636*/);
	SmartDashboard::PutNumber("RIGHT ENCVEL", RF->GetSpeed() /* * .011363636*/);
	SmartDashboard::PutNumber("NAVX ANGLE", Gyro->GetFusedHeading());
}
void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveTele());
}
void DriveTrain::JoyModify(double modify) {
	m_modify = modify;
}
void DriveTrain::Encoder(double left, double right, double leftspeed,
		double rightspeed) {
	LF->ConfigMaxOutputVoltage(leftspeed);
	RF->ConfigMaxOutputVoltage(rightspeed);
	LF->SetControlMode(CANSpeedController::kPosition);
	LF->Set(left);
	RF->SetControlMode(CANSpeedController::kPosition);
	RF->Set(right);
	RF->SetClosedLoopOutputDirection(true);
	l_pos = left;
	r_pos = right;

	SmartDashboard::PutNumber("LF POS", LF->GetPosition());
	SmartDashboard::PutNumber("RF POS", RF->GetPosition());
}
bool DriveTrain::isMove() {
	if ((LF->GetPosition() < (l_pos + .1) && LF->GetPosition() > (l_pos - .1))
			&& RF->GetPosition() < (r_pos + .1)
			&& RF->GetPosition() > (r_pos - .1)) {
		return true;
	} else {
		return false;
	}
}
void DriveTrain::EncoderDone() {
	RF->ConfigMaxOutputVoltage(12);
	LF->ConfigMaxOutputVoltage(12);
	LF->SetControlMode(CANSpeedController::kPercentVbus);
	LF->Set(0);
	RF->SetControlMode(CANSpeedController::kPercentVbus);
	RF->Set(0);
	l_pos = 0;
	r_pos = 0;
}
void DriveTrain::EncoderReset() {
	LF->SetEncPosition(0);
	RF->SetEncPosition(0);
}
double DriveTrain::EncoderReport(std::string LorR) {
//	"LEFT" OR "RIGHT"
	if (LorR == "LEFT") {
		return LF->GetPosition();
	}
	if (LorR == "RIGHT") {
		return RF->GetPosition();
	}
}
double DriveTrain::EncoderSpeed(std::string LorR) {
	//	"LEFT" OR "RIGHT"
	if (LorR == "LEFT") {
		return LF->GetSpeed();
	}
	if (LorR == "RIGHT") {
		return RF->GetSpeed();
	}
}
void DriveTrain::JoyInvert() {
	m_invert = -1;
}
void DriveTrain::JoyInvertOff() {
	m_invert = 1;
}
double DriveTrain::VReport(std::string type, int arraynum) {
	std::vector<double> arr = vtable->GetNumberArray(type,
			llvm::ArrayRef<double>());
	return arr[arraynum];
}
int DriveTrain::VArrSize() {
	std::vector<double> arr = vtable->GetNumberArray("width", llvm::ArrayRef<double>());
	return (arr.size());
}
bool DriveTrain::IsVBad() {
	return v_broke;
}
void DriveTrain::VBad(bool isgood) {
	if (isgood == true) {
		v_broke = true;
	}
	if (isgood == false) {
		v_broke = false;
	}
}

double DriveTrain::GyroReport() {
	return (Gyro->GetFusedHeading());
}

void DriveTrain::GyroReset() {
	Gyro->Reset();
}
