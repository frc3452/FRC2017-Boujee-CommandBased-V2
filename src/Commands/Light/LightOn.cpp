#include "LightOn.h"
#include <Robot.h>
#include "WPILib.h"
LightOn::LightOn() {
	Requires(Robot::Lightsubsystem.get());
}
void LightOn::Initialize() {
SetTimeout(.01);
}
void LightOn::Execute() {
Robot::Lightsubsystem->Control(true);
}
bool LightOn::IsFinished() {
	return IsTimedOut();
}
void LightOn::End() {

}
void LightOn::Interrupted() {

}
