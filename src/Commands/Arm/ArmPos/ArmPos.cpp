#include "ArmPos.h"
#include "WPILib.h"
#include <Robot.h>
ArmPos::ArmPos(double pos) {
	Requires(Robot::Armsubsystem.get());
	m_pos = pos;
	m_finish = false;
}
void ArmPos::Initialize() {
	Robot::Armsubsystem->ToMove(true);
}
void ArmPos::Execute() {
	Robot::Armsubsystem->PosReset();
	if (Robot::Armsubsystem->PosDone() == false) {
		Robot::Armsubsystem->ToPosition(m_pos);
	}
	m_finish = Robot::Armsubsystem->PosDone();
}
bool ArmPos::IsFinished() {
	return m_finish;
}
void ArmPos::End() {
	Robot::Armsubsystem->Manual(0);
	Robot::Armsubsystem->PosReset();
	Robot::Armsubsystem->ToMove(false);
}
void ArmPos::Interrupted() {
}
