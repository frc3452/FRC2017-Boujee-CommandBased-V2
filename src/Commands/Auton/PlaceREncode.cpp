#include "PlaceREncode.h"
#include "Commands/Drive/EncoderDrive.h"
#include "Commands/Drive/DriveTime.h"
PlaceREncode::PlaceREncode() {
	AddSequential(new EncoderDrive(1,1,4,4));
	AddSequential(new EncoderDrive(2,2,3,3));
	AddSequential(new EncoderDrive(3.5,3.5,2.5,2.5));
//	AddSequential(new EncoderDrive(5.7,5.8,2.5,2.5));
//	AddSequential(new EncoderDrive(6.7,6.8,1.25,1.25));
}
