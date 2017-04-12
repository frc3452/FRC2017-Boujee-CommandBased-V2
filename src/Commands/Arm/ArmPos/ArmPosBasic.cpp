#include "ArmPosBasic.h"
#include <Robot.h>
ArmPosBasic::ArmPosBasic(double pos) {
	Requires(Robot::Armsubsystem.get());
	m_pos = pos;
	m_finish = false;
}
void ArmPosBasic::Initialize() {
Robot::Armsubsystem->ToMove(true);
}
void ArmPosBasic::Execute() {
	Robot::Armsubsystem->PosReset();
	if (Robot::Armsubsystem->PosDone() == false) {
		Robot::Armsubsystem->ToPositionB(m_pos);
	}
	m_finish = Robot::Armsubsystem->PosDone();
}
bool ArmPosBasic::IsFinished() {
	return m_finish;
}
void ArmPosBasic::End() {
	Robot::Armsubsystem->Manual(0);
	Robot::Armsubsystem->PosReset();
	Robot::Armsubsystem->ToMove(false);
}
void ArmPosBasic::Interrupted() {

}
