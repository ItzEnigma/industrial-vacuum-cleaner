#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "../Main/main.h"

#define DELTA_ANGLE 5

typedef enum
{
	MOTOR_ANGLE_10 = 10,
	MOTOR_ANGLE_90 = 90,
	MOTOR_ANGLE_140 = 140,
	MOTOR_ANGLE_170 = 170
}tMotor_Angle;

typedef enum
{
	SOFT_SWITCHING = 5,
	HARMONIC
}tMotor_State;

typedef enum
{
	INCREASED = 0,
	BALANCED ,
	DECREASED
}tMotor_harmState;

void Motor_Init(void);
void Motor_SetAngle(tMotor_Angle);
void Motor_Update(void);

#endif // __MOTOR_H__
