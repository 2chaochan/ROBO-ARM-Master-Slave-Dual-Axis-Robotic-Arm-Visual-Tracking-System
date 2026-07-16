#include "pid.h"

float P=0.3,I=0.003,D=0.3;//P=0.3,I=0.03,D=0.15
float Current_Errorx;//当前误差
float Last_Errorx;//上一次误差
float Previous_Errorx;//上上次误差
int Realizex,iErrorx,Last_Realizex;
float Current_Errory;//当前误差
float Last_Errory;//上一次误差
float Previous_Errory;//上上次误差
int Realizey,iErrory,Last_Realizey;
 
/*! 
 *  @brief      位置式PID
 *  @since      v1.0
 *  *sptr ：误差参数
 *  *pid:  PID参数
 *  NowPlacex：当前位置
 *  Pointx：   预期位置  
 */
 void claer()
 {
 Last_Realizex=0;
 Last_Realizey=0;
 }
// 位置式PID控制
int PID_Realizex(int NowPlacex, int Pointx)
{
//		if(NowPlacex>Pointx)
//	  iErrorx = NowPlacex-Pointx;
//		else
	  iErrorx = NowPlacex- Pointx;	//计算当前误差
		Current_Errorx = I*iErrorx;//误差积分
		if(Current_Errorx>=20) Current_Errorx=20;
		if(Current_Errorx<=-20) Current_Errorx=-20;//积分限幅

		Realizex = P * iErrorx       //比例P
							+ Current_Errorx   //积分I
							+ D * (iErrorx - Last_Errorx);  //微分D
		Last_Errorx = iErrorx;		  	// 更新上次误差
		Last_Realizex=Last_Realizex+Realizex;
	if(Last_Realizex<=-400) Last_Realizex=-400;
	if(Last_Realizex>=400) Last_Realizex=400;
		return Last_Realizex;	// 返回实际值
}

int PID_Realizey(int NowPlacey, int Pointy)
{
//		if(NowPlacey>Pointy)
//	  iErrory = NowPlacey-Pointy;
//		else
	  iErrory = NowPlacey -  Pointy;		//计算当前误差
		Current_Errory = I*iErrory;//误差积分
		if(Current_Errory>=20) Current_Errory=20;
		if(Current_Errory<=-20) Current_Errory=-20;//积分限幅

		Realizey = P * iErrory       //比例P
							+ Current_Errory   //积分I
							+ D * (iErrory - Last_Errory);  //微分D
		Last_Errory = iErrory;		  	// 更新上次误差
	Last_Realizey=Last_Realizey+Realizey;
	if(Last_Realizey<=-400) Last_Realizey=-400;
	if(Last_Realizey>=400) Last_Realizey=400;
		return Last_Realizey;	// 返回实际值
}
