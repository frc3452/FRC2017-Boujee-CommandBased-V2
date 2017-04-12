#include "ArmTele.h"
#include <Robot.h>
ArmTele::ArmTele() {
	Requires(Robot::Armsubsystem.get());
}
void ArmTele::Initialize() {
	Robot::Armsubsystem->ToMove(true);
}
void ArmTele::Execute() {
	Robot::Armsubsystem->Manual(Robot::oi->GetOpJoy());
}
bool ArmTele::IsFinished() {
	return false;
}
void ArmTele::End() {
	Robot::Armsubsystem->ToMove(false);

}
void ArmTele::Interrupted() {
End();
}
