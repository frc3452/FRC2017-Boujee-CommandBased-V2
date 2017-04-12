/*
 * CmndInclude.h
 *
 *  Created on: Apr 5, 2017
 *      Author: Mac
 */
#ifndef SRC_CMNDINCLUDE_H_
#define SRC_CMNDINCLUDE_H_

#include "Commands/Test.h"
//			ARM
#include "Commands/Arm/ArmPos/ArmPosition.h"
#include "Commands/Arm/ArmTele.h"
#include "Commands/Arm/ArmTime.h"

//			INTAKE
#include "Commands/Intake/IntakeOn.h"
#include "Commands/Intake/IntakeOff.h"
#include "Commands/Intake/IntakeRev.h"

//			DRIVE
#include "Commands/Drive/SetModify.h"
#include "Commands/Drive/SetInvert.h"
#include "Commands/Drive/EncoderDrive.h"
#include "Commands/Drive/EncoderFrom.h"
#include "Commands/Drive/ResetEncoder.h"
#include "Commands/Drive/GyroPos.h"
#include "Commands/Drive/DriveTime.h"
#include "Commands/Drive/DrivetoStop.h"
#include "Commands/Drive/VPause.h"

//			VISION
#include "Commands/Vision/VGear.h"
#include "Commands/Vision/DriveGear/LHunt.h"
#include "Commands/Vision/DriveGear/DriveGearV.h"
#include "Commands/Vision/DriveGear/DriveToStopV.h"

//			CLAW
#include "Commands/Claw/ClawChute.h"
#include "Commands/Claw/Manual.h"

//			CLIMB
#include "Commands/Climb/ClimbFast.h"
#include "Commands/Climb/ClimbSlow.h"

//			SHOOTER
#include "Commands/Shooter/Shoot.h"
#include "Commands/Shooter/ShootSpeedUp.h"
#include "Commands/Shooter/ShootSpeedUpTime.h"
#include "Commands/Shooter/ShootTime.h"
#include "Commands/Shooter/ReverseAdj.h"

//			LIGHT
#include "Commands/Light/LightOn.h"
#include "Commands/Light/LightOff.h"
#include "Commands/Light/CamSwitch.h"

//			DOOR
#include "Commands/Door/DoorClose.h"
#include "Commands/Door/DoorOpen.h"
#include "Commands/Door/Chute.h"
#include "Commands/Door/DoorSaftey.h"

//			AUTON
#include "Commands/Auton/Vision/VMiddlePeg.h"
#include "Commands/Auton/Vision/VMiddleFast.h"
#include "Commands/Auton/Vision/VRightPeg.h"
#include "Commands/Auton/Vision/VLeftPeg.h"
#include "Commands/Auton/Vision/VBlueShootPlace.h"
#include "Commands/Auton/Vision/VRedShootPlace.h"
#include "Commands/Auton/Vision/LPegShootB.h"
#include "Commands/Auton/LeftPeg.h"
#include "Commands/Auton/DriveNPlace.h"
#include "Commands/Auton/PlaceMEncode.h"
#include "Commands/Auton/Reset.h"
#include "Commands/Auton/PlaceREncode.h"

#endif /* SRC_CMNDINCLUDE_H_ */
