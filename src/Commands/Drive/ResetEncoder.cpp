#include "ResetEncoder.h"
#include <Robot.h>
ResetEncoder::ResetEncoder() {
}
void ResetEncoder::Initialize() {
SetTimeout(.05);
}
void ResetEncoder::Execute() {
Robot::DriveTrainsubsystem->EncoderReset();
}
bool ResetEncoder::IsFinished() {
	return IsTimedOut();
}
void ResetEncoder::End() {

}
void ResetEncoder::Interrupted() {

}
