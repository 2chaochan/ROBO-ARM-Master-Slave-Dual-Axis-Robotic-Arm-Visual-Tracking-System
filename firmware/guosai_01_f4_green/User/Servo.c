#include "main.h"
#include "tim.h"
#include "stdio.h"
#include "Openmv.h"
#include "pid.h"
extern int aa,bb,cc,dd,ee,ff,gg,hh,ii,jj;
extern int Last_Realizex,Last_Realizey;
int c,d,xx,yy;
int pwmx,pwmy;
int aa_,bb_,zz;

void tuozhan1_ZUO()
{
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2000);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1334);
		delay_ms(1000);
		aa_=aa;
		if(dd<=bb)
		{
			bb_=bb-12;
			zz=1;
		}
		
		else
		{	
			bb_=bb+12;
			zz=2;
		}
		
			while(1)
			{	
			 
				if((aa_-2<=cc&&cc<=aa_+2)&&(bb_-2<=dd&&dd<=bb_+2))
				{
					break;
				}
				PID_Realizex(cc,aa_);	
			 PID_Realizey(dd,bb_);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2000-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1334+Last_Realizex);
						delay_ms(100);
			}
				delay_ms(1000);
			if(zz==1)
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2000-Last_Realizey+36);
			if(zz==2)
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1334+Last_Realizey-36);
			delay_ms(1000);

}
void tuozhan2_ZUO()
{
__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2000);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1334);
delay_ms(2000);
while(1)
{
while(1)
{	//cc是绿色光斑的横坐标，dd是绿色光斑的纵坐标,aa是红色光斑的横坐标，bb是绿色光斑的纵坐标
			 PID_Realizex(cc,aa-5);	
			 PID_Realizey(dd,bb-5);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,2000-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1334+Last_Realizex);
						delay_ms(100);
		if((aa-2-5<=cc&&cc<=aa+2-5)&&(bb-2-5<=dd&&dd<=bb+2-5))
				{
					//亮
					break;
				}
		else{
		//灭
		
		}
	}
}

}