#include "EncoderFrom.h"
#include "CmndInclude.h"
//#include "Commands/Drive/EncoderDrive.h"

EncoderFrom::EncoderFrom(double left, double right, double leftspeed, double rightspeed) {
	AddSequential(new ResetEncoder());
	AddSequential(new EncoderDrive(left, right, leftspeed, rightspeed));
}
