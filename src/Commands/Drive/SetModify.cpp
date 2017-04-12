#include "SetModify.h"
#include <Robot.h>
#include "WPILib.h"
SetModify::SetModify(double modvalue) {
m_modvalue = modvalue;
}
void SetModify::Initialize() {
SetTimeout(.001);
}
void SetModify::Execute() {
Robot::DriveTrainsubsystem->JoyModify(m_modvalue);
}
bool SetModify::IsFinished() {
	return IsTimedOut();
}
void SetModify::End() {

}
void SetModify::Interrupted() {

}
