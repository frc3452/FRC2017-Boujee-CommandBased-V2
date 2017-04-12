#include "Climb.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include <Robot.h>
Climb::Climb() : Subsystem("ExampleSubsystem") {
	InitHardware();
}
Climb::~Climb() {

}
void Climb::InitHardware() {
	ClimbMtr.reset(new Spark(CLIMB));
	ClimbMtr->SetInverted(true);
//	TEST MODE
	LiveWindow * lw = LiveWindow::GetInstance();
	lw->AddActuator("Climber", "ClimbMotor", ClimbMtr.get());

}
void Climb::InitDefaultCommand() {
}
void Climb::Slow() {
	ClimbMtr->Set(.35);
}
void Climb::Fast() {
	ClimbMtr->Set(1);
}
void Climb::Off() {
	ClimbMtr->Set(0);
}
