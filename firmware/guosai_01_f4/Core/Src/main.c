/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "User.h"
#include "Servo.h"
#include "EXTI.h"
#include "Openmv.h"
#include "pid.h"
#include "math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int i,j,z,b=0;
uint8_t usart1_rxbuff;
int a=0,po=0;
extern int aa,bb,cc,dd,ee,ff,gg,hh,ii,jj;
extern int Last_Realizex,Last_Realizey;
float pa,pb,pc,pd,pe,pf,pg,pi,pj;
int xe=0,ye;
void delay_ms(uint32_t nTimer)
{
	uint32_t i=0;
	for(i=0;i<nTimer;i++){
		for(z=0;z<=100;z++){

			for(j=0;j<=84;j++)
		{
		__NOP();
		}
		j=0;
	}
		z=0;
	}
}
 void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin==GPIO_PIN_4)
	{
		delay_ms(100);
		if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4)==GPIO_PIN_SET)
		{
			delay_ms(100);
			if(a%2==0)
			{
							while(1)
						{
						if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4)==GPIO_PIN_RESET)
						{
							break;
						}
						}
					}
			else{}
		a++;
		}
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  uint16_t tem;
  if(huart->Instance==USART1)
  {
    tem=usart1_rxbuff;
    Openmv_Receive_Data(tem);
  }	
  HAL_UART_Receive_IT(&huart1,(void *)&usart1_rxbuff,1);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
	User_PWMInit();
	HAL_UART_Receive_IT(&huart1,(void *)&usart1_rxbuff,1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
	{		
		if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_1)==GPIO_PIN_RESET)
		{
			delay_ms(10);
			point();
		}//back to the initial point
		if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_2)==GPIO_PIN_RESET)
		{
			delay_ms(10);
			square();
		}//run around the white screen
		if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_3)==GPIO_PIN_RESET)
		{		
		delay_ms(10);
			black();
	}	//run around the black square
		if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_4)==GPIO_PIN_RESET)
		{		
		delay_ms(10);
		four_two();
	}	//closed-loop contrl to run around the black square
		if(HAL_GPIO_ReadPin(GPIOF,GPIO_PIN_5)==GPIO_PIN_RESET)
		{		
		delay_ms(10);
		star();
	}	
//		while(1)
//		{
//		a11=(1814-1805)/255;
//		a22=(2105-1850)/255;
//		flag++;
//		b11=1814-flag*a11;
//		b22=2105-flag*a22;
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, b11);
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, b22);
//		if(b22==1850)
//		{
//			break;
//		}
//		delay_ms(10);
//		
//		}
				
//	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1890);
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2117);
//		int r=100,a1=1890,a2=2117;
//		delay_ms(1000);
//		while(1)
//		{
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, a1);
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, a2);
//			a1++;
//			a2++;
//			delay_ms(50);
//			r--;
//			if(r<=0)
//			{
//			break;
//			}
//		
//		}
//		delay_ms(10000);

		
		//中心
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1916);//前后加3
//				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2123);//前后加3	
//		左上角，
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1802);//前后加3
//				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2261);//前后加3

//		右上角
//		HAL_Delay(3000);
//						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1793);//前后加3
//				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1986);//前后加3

////		左下角
//		HAL_Delay(3000);
//						__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 2051);//前后加3
//				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2261);//前后加3

////		右下角
//		HAL_Delay(3000);
//				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 2045);//前后加3
//				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1980);//前后加3
//		break;
//HAL_Delay(3000);				
//		HAL_Delay(2000);
//					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 2300);
//		HAL_Delay(2000);
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2500);
//		HAL_Delay(2000);
		
		
//		    __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1790);//前后加3
//				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2261);//前后加3



//				while(1)
//			{
//				 PID_Realizex(aa,gg);	
//		  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1790-Last_Realizex);
//			PID_Realizey(bb,hh);	
//		  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2261-Last_Realizey);
//			delay_ms(500);
//				dec(gg,hh);
//			if(c<=2&&d<=2)
//			{
//				break;
//			}
//			}
//			while(1)
//			{
//				 PID_Realizex(aa,ee);	
//		  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1790-Last_Realizex);
//			PID_Realizey(bb,ff);	
//		  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2261-Last_Realizey);
//			delay_ms(500);
//				dec(ee,ff);
//			if(c<=2&&d<=2)
//			{
//				break;
//			}
//			}
//			while(1)
//			{
//				 PID_Realizex(aa,cc);	
//		  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1790-Last_Realizex);
//			PID_Realizey(bb,dd);	
//		  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2261-Last_Realizey);
//			delay_ms(500);
//				dec(cc,dd);
//			if(c<=2&&d<=2)
//			{
//				break;
//			}
//			}
//			while(1)
//			{
//			PID_Realizex(aa,ii);	
//		  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1790-Last_Realizex);
//			PID_Realizey(bb,jj);	
//		  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2261-Last_Realizey);
//			delay_ms(500);
//				dec(ii,jj);
//			if(c<=2&&d<=2)
//			{
//				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1916);
//				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2117);
//			}
//			}
//	
//	 }
//		else{
//					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1790);
//					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2261);

//		}
		
//			HAL_Delay(200);
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2000);
//		pe=(264.0/117.0)*(ee-116.0);
//		pf=(256.0/118.0)*(ff-38.0);
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2240-pe);
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,2140-pf);
//		pc=(264.0/117.0)*(cc-116.0);
//		pd=(256.0/118.0)*(dd-38.0);
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2240-pc);
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,2140-pd);
		
		
		
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2240);//下限2240，上限1984
//	  HAL_Delay(3000);
//		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1992);
//					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 2000);
//		HAL_Delay(3000);
//			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2136);//左上2144，左下2136，右下1868，右上1884
//			HAL_Delay(3000);
//			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1500);
//			HAL_Delay(3000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
