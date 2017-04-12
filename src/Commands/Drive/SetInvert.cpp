#include "SetInvert.h"
#include "WPILib.h"
#include <Robot.h>
SetInvert::SetInvert(bool on) {
	m_invert = on;
}
void SetInvert::Initialize() {
	SetTimeout(.01);
}
void SetInvert::Execute() {
	if (m_invert == true){
	Robot::DriveTrainsubsystem->JoyInvert();
	}
	if (m_invert == false){
	Robot::DriveTrainsubsystem->JoyInvertOff();
	}

}
bool SetInvert::IsFinished() {
	return IsTimedOut();
}
void SetInvert::End() {
}
void SetInvert::Interrupted() {
End();
}
