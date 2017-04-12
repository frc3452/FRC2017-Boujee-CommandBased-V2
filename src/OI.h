#ifndef OI_H
#define OI_H
#include "WPILib.h"
#include "cscore.h"
#include "Triggers/ArmCheck.h"
class OI {
private:
//	INITIALIZATION FOR DRIVER JOYSTICK & BUTTONS
	std::shared_ptr<Joystick> DriverJoy;
	std::shared_ptr<JoystickButton> DriverJoyA;
	std::shared_ptr<JoystickButton> DriverJoyB;
	std::shared_ptr<JoystickButton> DriverJoyX;
	std::shared_ptr<JoystickButton> DriverJoyY;
	std::shared_ptr<JoystickButton> DriverJoyLB;
	std::shared_ptr<JoystickButton> DriverJoyRB;
	std::shared_ptr<JoystickButton> DriverJoyBack;
	std::shared_ptr<JoystickButton> DriverJoyStart;
	std::shared_ptr<JoystickButton> DriverJoyLClick;
	std::shared_ptr<JoystickButton> DriverJoyRClick;

//	INITIALIZATION FOR OPERATOR JOYSTICK & BUTTONS
	std::shared_ptr<Joystick> OpJoy;
	std::shared_ptr<JoystickButton> OpJoyA;
	std::shared_ptr<JoystickButton> OpJoyB;
	std::shared_ptr<JoystickButton> OpJoyX;
	std::shared_ptr<JoystickButton> OpJoyY;
	std::shared_ptr<JoystickButton> OpJoyLB;
	std::shared_ptr<JoystickButton> OpJoyRB;
	std::shared_ptr<JoystickButton> OpJoyBack;
	std::shared_ptr<JoystickButton> OpJoyStart;
	std::shared_ptr<JoystickButton> OpJoyLClick;
	std::shared_ptr<JoystickButton> OpJoyRClick;

//	INIT TRIGGERS
	std::shared_ptr<ArmCheck> m_ArmCheck;
public:
	OI();
	std::shared_ptr<Joystick> GetDriverJoy();
	std::shared_ptr<Joystick> GetOpJoy();

	cs::UsbCamera mCamera0;
	cs::UsbCamera mCamera1;
	cs::UsbCamera mCamera2;
	cs::VideoSink server;
};

#endif
