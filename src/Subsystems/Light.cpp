#include "Light.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include <Relay.h>
#include <Robot.h>
Light::Light() :
		Subsystem("ExampleSubsystem") {
	InitHardware();
}
void Light::InitHardware() {
	lightrelay.reset(new Relay(LIGHT, frc::Relay::kForwardOnly));
//	Robot::oi->server.SetSource(Robot::oi->mCamera0);
}
void Light::InitDefaultCommand() {
	// SetDefaultCommand(new MySpecialCommand());
}
//void SCamSwitch(int camswitch) {
//	if (camswitch = 0) {
//		Robot::oi->server.SetSource(Robot::oi->mCamera0);
//	}
//	if (camswitch = 1) {
//		Robot::oi->server.SetSource(Robot::oi->mCamera1);
//	}
//	if (camswitch = 2) {
//		Robot::oi->server.SetSource(Robot::oi->mCamera2);
//	}
//}

void Light::Control(bool on) {
	if (on == true) {
		lightrelay->Set(Relay::kForward);
	}
	if (on == false) {
		lightrelay->Set(Relay::kOff);
	}
}
Light::~Light() {

}
