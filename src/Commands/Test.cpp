#include "Test.h"
#include <Robot.h>
#include <iostream>
#include "WPILib.h"
Test::Test() {
	Requires(Robot::DriveTrainsubsystem.get());
	m_finish = false;
}
void Test::Initialize() {
	SetTimeout(5);
}
void Test::Execute() {
std::cout << Robot::DriveTrainsubsystem->VArrSize() << std::endl;
}
bool Test::IsFinished() {
	return IsTimedOut() || m_finish;
}
void Test::End() {
	Robot::DriveTrainsubsystem->Arcade(0,0);
}
void Test::Interrupted() {
	End();
}
