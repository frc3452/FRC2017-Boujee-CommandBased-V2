#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
class RobotMap {
public:
	static void init();
};
// PWM
constexpr int SHOOTER_ELEVATOR = 1;
constexpr int GEAR_DOOR = 2;
constexpr int CLIMB = 3;
constexpr int AGITATOR = 4;
constexpr int INTAKE = 5;

// CAN IDS
constexpr int DRIVE_LEFT_FRONT = 1;
constexpr int DRIVE_LEFT_BACK = 2;
constexpr int DRIVE_RIGHT_FRONT = 3;
constexpr int DRIVE_RIGHT_BACK = 4;
constexpr int GEAR_CLAW = 5;
constexpr int GEAR_ARM = 6;
constexpr int SHOOTER_WHEEL = 7;
//constexpr int SHOOTER_WHEEL_SLAVE = 8;

// RELAYS
constexpr int LIGHT = 0;

// ARM POSITIONS
constexpr int UPPER_LIMIT = 167;
constexpr int LOWER_LIMIT = 574;

#endif  // ROBOTMAP_H

/** BOUJEE VS BAD
Bad:
	SHOOTER;
		OUTPUT VOLTAGE (0, -12);
		PIDF 0.025625 setting 0
		PIDF 0.0275 setting 1
		SENSOR(FALSE)     MOTOR(TRUE)
		Elev Invert: false
	CLAW;
		INVERTED

Boujee:
	SHOOTER;
		OUTPUT VOLTAGE (12, 0);
		PIDF 0.02623 setting 0
		PIDF 0.0265 setting 1
		SENSOR(TRUE)     MOTOR(FALSE)
		Elev invert: true
	CLAW;
		INVERTED(FALSE)

CHANGE SHOOTER COMMAND
*/
