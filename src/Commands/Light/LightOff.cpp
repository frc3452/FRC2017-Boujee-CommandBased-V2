#include "LightOff.h"
#include <Robot.h>
#include "WPILib.h"
LightOff::LightOff() {
	Requires(Robot::Lightsubsystem.get());
}
void LightOff::Initialize() {
	SetTimeout(.01);
}
void LightOff::Execute() {
	Robot::Lightsubsystem->Control(false);
}
bool LightOff::IsFinished() {
	return IsTimedOut();
}
void LightOff::End() {

}
void LightOff::Interrupted() {

}
