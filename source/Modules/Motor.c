#include "../Modules/Motor.h"
#include "stm32f4xx_ll_tim.h"

static tMotor_Angle gTarget_angle = 170;
static tByte gCurrent_angle = MOTOR_ANGLE_170;
static tByte gFiring_angle = 169;
static tMotor_State gMotor_state = SOFT_SWITCHING;

volatile uint32_t currentAngle_DEBUG = 0;			/* Only used for debugging */

void Motor_Init(void)
{
	Motor_SetAngle(MOTOR_ANGLE_90);
}
void Motor_SetAngle(tMotor_Angle angel)
{
	gTarget_angle = angel;
	gMotor_state = SOFT_SWITCHING;
}

void Motor_Update(void)		/* Every 10ms (Triggered with systick) */
{
	currentAngle_DEBUG = gCurrent_angle;
	static tByte soft_i = 0;
	static tByte harm_i = 0;
	static tMotor_harmState harm_prevState = DECREASED;
	static tMotor_harmState harm_curState  = BALANCED;
	switch(gMotor_state)
	{
		case SOFT_SWITCHING:
			if(soft_i == 4)
			{
				soft_i = 1;
				if(gTarget_angle > gCurrent_angle)			/* Still less than required angle */
					gCurrent_angle ++;
				else if(gTarget_angle < gCurrent_angle)	/* Still higher than required angle */
					gCurrent_angle --;
				else /* gTarget_angle == gCurrent_angle */
				{
					gMotor_state = HARMONIC;
					harm_prevState = DECREASED;
					harm_curState  = BALANCED;
				}
			}
			 else soft_i++;
			break;
			
		case HARMONIC:
			if(harm_i == 2)
			{
				if((harm_prevState == INCREASED) && (harm_curState == BALANCED))		/* 85 */
				{
					gCurrent_angle -= DELTA_ANGLE ;
					harm_prevState = BALANCED;
					harm_curState = DECREASED;
				}
				else if((harm_prevState == BALANCED) && (harm_curState == DECREASED))	/* 90 */
				{
					gCurrent_angle += DELTA_ANGLE ;
					harm_prevState = DECREASED;
					harm_curState = BALANCED;
				}
				else if((harm_prevState == DECREASED) && (harm_curState == BALANCED))	/* 95 */
				{
					gCurrent_angle += DELTA_ANGLE ;
					harm_prevState = BALANCED;
					harm_curState = INCREASED;
				}
				else if((harm_prevState == BALANCED) && (harm_curState == INCREASED))	/* 90 */
				{
					gCurrent_angle -= DELTA_ANGLE ;
					harm_prevState = INCREASED;
					harm_curState = BALANCED;
				}
				harm_i = 1;
			}
			else
				harm_i++;
			break;
			
	}
	
}

void TIM1_UP_TIM10_IRQHandler(void)
{
	
}