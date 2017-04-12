#include "CamSwitch.h"
#include <Robot.h>
#include "WPILib.h"
CamSwitch::CamSwitch(int camswitch) {
	cam = camswitch;
}
void CamSwitch::Initialize() {
	SetTimeout(.01);
}
void CamSwitch::Execute() {
//	Robot::Lightsubsystem->SCamSwitch(cam);
}
bool CamSwitch::IsFinished() {
	return IsTimedOut();
}
void CamSwitch::End() {

}
void CamSwitch::Interrupted() {
	End();
}
