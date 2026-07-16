#include "EXTI.h"
#include "tim.h"
#include <stdio.h>
#include <string.h>
#include <gpio.h>
#include "Servo.h"


////{
////	while(1)
////	{
////		HAL_Delay(10);
////		if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_0)==GPIO_PIN_SET)
////		{
////			break;
////		}
////	}

////}
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//	if(GPIO_Pin==GPIO_PIN_0)
//	{
//		HAL_Delay(10);
//		if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_0)==GPIO_PIN_SET)
//		{
//			a++;
////			STOP();
//		}
//	}
//	if(GPIO_Pin==GPIO_PIN_1)
//	{
//		HAL_Delay(10);
//		if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_1)==GPIO_PIN_SET)
//		{
//			a++;
////			point();
//		}
//	}
//	if(GPIO_Pin==GPIO_PIN_2)
//	{
//		HAL_Delay(10);
//		if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_2)==GPIO_PIN_SET)
//		{
////			square();
//		}
//	}
//	if(GPIO_Pin==GPIO_PIN_3)
//	{
//		HAL_Delay(10);
//		if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_3)==GPIO_PIN_SET)
//		{
//		}
//	}

//}

