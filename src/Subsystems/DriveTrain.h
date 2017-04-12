#ifndef DriveTrain_H
#define DriveTrain_H
#include "WPILib.h"
#include <Commands/Subsystem.h>
#include "CANTalon.h"
#include "Encoder.h"
#include "AHRS.h"
class DriveTrain : public Subsystem {
private:
	double m_modify;
	double m_invert;
	double l_pos;
	double r_pos;

	bool v_broke;

	bool m_gyrodone;

	std::shared_ptr<NetworkTable> vtable;
	std::unique_ptr<RobotDrive> RoboDrive;
	std::shared_ptr<CANTalon> LF;
	std::shared_ptr<CANTalon> LB;
	std::shared_ptr<CANTalon> RF;
	std::shared_ptr<CANTalon> RB;
	std::shared_ptr<AHRS> Gyro;
	std::shared_ptr<NetworkTable> ntable;

public:
	DriveTrain();
	virtual ~DriveTrain();

	void InitHardware();
	void InitHardwareV2();
	void InitDefaultCommand() override;
	void JoyModify(double modify);
	void Arcade(std::shared_ptr<Joystick> JoyStick);
	void Arcade(double move, double rotate);

//	ENCODERS
	void Encoder(double left, double right, double leftspeed, double rightspeed);
	void EncoderDone();
	bool isMove();
	void EncoderReset();
	double EncoderReport(std::string LorR);
	double EncoderSpeed(std::string LorR);

//	VISION
	double VReport(std::string type, int arraynum);
	int VArrSize();
	bool IsVBad();
	void VBad(bool isgood);

//	JOY INVERSION
	void JoyInvert();
	void JoyInvertOff();

//	GYRO
	double GyroReport();
	void GyroReset();
};

#endif  // DriveTrain_H
