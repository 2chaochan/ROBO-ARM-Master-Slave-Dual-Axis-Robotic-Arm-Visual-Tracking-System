#include "User.h"
#include "tim.h"

#include <stdio.h>
#include <string.h>


void User_PWMInit(void)//¶æ»úPwm·¶Î§£¨500-2500£©
{
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
//	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
//	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 0);
}
