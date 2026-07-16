#include "main.h"
#include "tim.h"
#include "stdio.h"
#include "Openmv.h"
#include "pid.h"
extern int aa,bb,cc,dd,ee,ff,gg,hh,ii,jj;
extern int Last_Realizex,Last_Realizey;
int c,d,xx,yy,efgh,ghij;
int pwmx,pwmy;

void dec(int x,int y)//求差值，让差值为正
{
	if(aa>=x)
		c=aa-x;
	else
		c=x-aa;
	if(bb>=y)
		d=bb-y;
	else 
		d=y-bb;

}

//分2份，传入次数，目标坐标值，取中点，进行细分,x1，y1为当前值，x2，y2为目标值
void sub2(int num,int x1,int y1,int x2,int y2)
{ 
		xx=x1+(x2-x1)/2*num;//中点值
		yy=y1+(y2-y1)/2*num;//中点值
	if(num==2)
	{
	xx=x2;
	yy=y2;
	}
}
void sub3(int num,int x1,int y1,int x2,int y2)
{ 
		xx=x1+(x2-x1)/3*num;
		yy=y1+(y2-y1)/3*num;
	if(num==3)
	{
	xx=x2;
	yy=y2;
	}
}

void point()
{
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1928);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1962);
		 delay_ms(2000);
	 }

void square()
{
				//zuoshang
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1802);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2105);
		delay_ms(2000);

		//youshang
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1796);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1843);
		delay_ms(2000);
		//youxia
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 2045);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1843);
		delay_ms(2000);
		//zuoxia
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 2048);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2105);
		delay_ms(2000);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1802);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2105);
		delay_ms(2000);
	}
		
	
	
	
//由于摆放位置任意，所以我们不得知黑框的位置，分成横向摆放和纵向摆放，摆放的判断通过勾股定理判断斜边的长度，PID的修正量输出给的很小，确保精度
void four_two()
{
		//先让舵机回到中点预备待命
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1928);//前后加3，舵机的精确度，即舵机只有在PWM数值输出>3时才会产生比较明显的运动
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1962);//前后加3
			delay_ms(2000);
	
			while(1)
			{	
				//使红色光斑回到起始点左上角准备开始移动
			 PID_Realizex(aa,ee);	
			PID_Realizey(bb,ff);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(ee,ff);//计算误差值
			if(c<=2&&d<=2)//如果误差值较小，则跳出
			{
			break;
			}
		}
			
		
			efgh=(ee-gg)*(ee-gg)+(ff-hh)*(ff-hh);
			ghij=(gg-ii)*(gg-ii)+(hh-jj)*(hh-jj);//勾股定理判断长边
		
		
		if(efgh>=ghij)//此时黑色方框处于横向放置
		{
					//ee,ff-gg,hh
			delay_ms(1000);
			
			
			//第一段长边，第一分段
			sub3(1,ee,ff,gg,hh);
			while(1)
			{	
			 PID_Realizex(aa,xx-2);	
			PID_Realizey(bb,yy);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				
				dec(xx-2,yy);//如果红点接近第一个目标点，则跳出该循环，开始进行第二分段的移动
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			delay_ms(1000);
			
			
			//第一段长边，第二分段
			sub3(2,ee,ff,gg,hh);
			while(1)
			{	
			 PID_Realizex(aa,xx-2);	
			PID_Realizey(bb,yy);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx-2,yy);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			delay_ms(1000);
			
			
			//第一段长边，第三分段
			sub3(3,ee,ff,gg,hh);
			while(1)
			{	
			 PID_Realizex(aa,xx-2);	
			PID_Realizey(bb,yy);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx-2,yy);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			
			//gg,hh-ii,jj
			delay_ms(1000);
			
			
			//第二段短边，第一分段
			sub2(1,gg,hh,ii,jj);
			while(1)
			{	
			 PID_Realizex(aa,xx);	
			PID_Realizey(bb,yy-2);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx,yy-2);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			delay_ms(1000);
			
			
			//第二段短边，第二分段
			sub2(2,gg,hh,ii,jj);
			while(1)
			{	
			 PID_Realizex(aa,xx);	
			PID_Realizey(bb,yy-2);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx,yy-2);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			
			//ii,jj-cc,dd
		delay_ms(1000);
			
			
			//第三段长边，第一分段
			sub3(1,ii,jj,cc,dd);
			while(1)
			{	
			 PID_Realizex(aa,xx+2);	
			PID_Realizey(bb,yy);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx+2,yy);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			delay_ms(1000);
			
			
			//第三段长边，第二分段
			sub3(2,ii,jj,cc,dd);
			while(1)
			{	
			 PID_Realizex(aa,xx+2);	
			PID_Realizey(bb,yy);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx+2,yy);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			delay_ms(1000);
			
			
			//第三段长边，第三分段
			sub3(3,ii,jj,cc,dd);
			while(1)
			{	
			 PID_Realizex(aa,xx+2);	
			PID_Realizey(bb,yy);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx+2,yy);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			//cc,dd-ee,ff
			
			
			//第四段短边，第一分段
			sub2(1,cc,dd,ee,ff);
			while(1)
			{	
			 PID_Realizex(aa,xx);	
			PID_Realizey(bb,yy+2);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx,yy+2);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			
			
			//第四段短边，第二分段
			sub2(2,cc,dd,ee,ff);
			while(1)
			{	
			 PID_Realizex(aa,xx);	
			PID_Realizey(bb,yy+2);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx,yy+2);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
		}
		
		
		else{
			//ee,ff-gg,hh
			delay_ms(1000);
			
			sub2(1,ee,ff,gg,hh);
			while(1)
			{	
			 PID_Realizex(aa,xx-2);	
			PID_Realizey(bb,yy);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx-2,yy);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			delay_ms(1000);
			
			sub2(2,ee,ff,gg,hh);
			while(1)
			{	
			 PID_Realizex(aa,xx);	
			PID_Realizey(bb,yy);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx,yy);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			
			//gg,hh-ii,jj
			delay_ms(1000);
			
			sub3(1,gg,hh,ii,jj);
			while(1)
			{	
			 PID_Realizex(aa,xx);	
			PID_Realizey(bb,yy-2);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx,yy-2);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			delay_ms(1000);
			sub3(2,gg,hh,ii,jj);
			
			while(1)
			{	
			 PID_Realizex(aa,xx);	
			PID_Realizey(bb,yy-2);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx,yy-2);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			delay_ms(1000);
			
			sub3(3,gg,hh,ii,jj);
			while(1)
			{	
			 PID_Realizex(aa,xx);	
			PID_Realizey(bb,yy);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx,yy);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			//ii,jj-cc,dd
			delay_ms(1000);
			
			sub2(1,ii,jj,cc,dd);
			while(1)
			{	
			 PID_Realizex(aa,xx+2);	
			PID_Realizey(bb,yy);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx+2,yy);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			delay_ms(1000);
			
			sub2(2,ii,jj,cc,dd);
			while(1)
			{	
			 PID_Realizex(aa,xx);	
			PID_Realizey(bb,yy);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx,yy);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			delay_ms(1000);
			//cc,dd-ee,ff
			
			sub3(1,cc,dd,ee,ff);
			while(1)
			{	
			 PID_Realizex(aa,xx);	
			PID_Realizey(bb,yy+2);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx,yy+2);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			delay_ms(1000);
			
			sub3(2,cc,dd,ee,ff);
			while(1)
			{	
			 PID_Realizex(aa,xx);	
			PID_Realizey(bb,yy+2);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx,yy+2);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
			delay_ms(1000);
			
			sub3(3,cc,dd,ee,ff);
			while(1)
			{	
			 PID_Realizex(aa,xx);	
			PID_Realizey(bb,yy);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1928-Last_Realizey);
			  __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2,1962+Last_Realizex);
						delay_ms(300);
				dec(xx,yy);
			if(c<=3&&d<=3)
			{
			break;
			}
			}
	}
}


void black()//直接写死，固定黑色边框竖向放置白色屏幕左上角
{
	//zuoshang
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1802);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2105);
		delay_ms(2000);

		//youshang
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1799);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1988);
		delay_ms(2000);
		//youxia
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1949);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1988);
		delay_ms(2000);
		//zuoxia
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1949);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2099);
		delay_ms(2000);
			
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1802);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2105);
		delay_ms(2000);

}
void star()
{
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1928);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1962);
		delay_ms(1000);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1928);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2060);
		delay_ms(1000);
	  for(int p=0;p<=100;p++)
		{
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1928-p);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 2060-2*p);
			delay_ms(100);
		}
		delay_ms(1000);
		for(int p=0;p<=100;p++)
		{
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1828+2*p);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1860+p);
			delay_ms(100);
		}
		delay_ms(1000);
		for(int p=0;p<=100;p++)
		{
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 2028-2*p);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1960);
			delay_ms(100);
		}
		delay_ms(1000);
		for(int p=0;p<=100;p++)
		{
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 1828+2*p);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1960-p);
			delay_ms(100);
		}
			delay_ms(1000);
		for(int p=0;p<=100;p++)
		{
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 2028-p);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 1860+2*p);
			delay_ms(100);
		}

}
