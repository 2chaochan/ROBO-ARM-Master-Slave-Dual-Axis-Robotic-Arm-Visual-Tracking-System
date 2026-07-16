#include "Openmv.h"     // OpenMV通信相关定义
#include "stdio.h"      // 标准输入输出库
#include "usart.h"      // 串口通信库

// 静态变量声明：用于存储从OpenMV接收的解析数据（坐标、尺寸等）
static uint8_t Cx=0,Cy=0,Cw=0,Ch=0,Cq=0,Ce=0,Cr=0,Ct=0,Cp=0,Cu=0;
// 全局变量：可能用于外部访问解析后的数据
int aa,bb,cc,dd,ee,ff,gg,hh,ii,jj;

/*************************************************
* 函数名称：Openmv_Receive_Data
* 功能描述：OpenMV数据接收解析状态机
* 输入参数：int16_t com_data - 通过串口接收的单个字节数据
* 注    意：基于状态机的协议解析，帧格式：
*           帧头0x2C 0x12 + 数据域 + 结束符0x5B
*************************************************/
void Openmv_Receive_Data(int16_t com_data)
{
    uint8_t i;
    static uint8_t RxCounter1 = 0;   // 接收数据计数器
    static uint16_t RxBuffer1[16] = {0}; // 接收缓冲区（16字节）
    static uint8_t RxState = 0;      // 状态机状态标识
    static uint8_t RxFlag1 = 0;      // 接收完成标志

    /*----------- 状态机处理流程 -----------*/
    if(RxState == 0 && com_data == 0x2C) // 状态0：检测第一帧头
    {
        RxState = 1;                      // 进入状态1
        RxBuffer1[RxCounter1++] = com_data; // 存储帧头
    }
    else if(RxState == 1 && com_data == 0x12) // 状态1：检测第二帧头
    {
        RxState = 2;                      // 进入状态2（数据接收状态）
        RxBuffer1[RxCounter1++] = com_data;
    }
    else if(RxState == 2)                // 状态2：持续接收数据
    {
        RxBuffer1[RxCounter1++] = com_data;
        // 判断是否接收满16字节或检测到结束符0x5B
        if(RxCounter1 >=16 || com_data == 0x5B)
        {
            RxState = 3;                // 进入结束处理状态
            RxFlag1 = 1;                // 置位接收完成标志
            
            // 数据解析：从缓冲区倒数位置提取各字段
            Cx = RxBuffer1[RxCounter1-11];  // 通常表示X坐标
            Cy = RxBuffer1[RxCounter1-10];  // Y坐标
            Cw = RxBuffer1[RxCounter1-9];   // 宽度Width
            Ch = RxBuffer1[RxCounter1-8];   // 高度Height
            Cq = RxBuffer1[RxCounter1-7];   // 可能为质量Quality
            Ce = RxBuffer1[RxCounter1-6];   // 可能为错误码Error
            Cr = RxBuffer1[RxCounter1-5];   // 预留字段1
            Ct = RxBuffer1[RxCounter1-4];   // 预留字段2
            Cp = RxBuffer1[RxCounter1-3];   // 预留字段3
            Cu = RxBuffer1[RxCounter1-2];   // 预留字段4
            
            // 将数据复制到全局变量（可能用于外部访问）
            aa=Cx; bb=Cy; cc=Cw; dd=Ch;
            ee=Cq; ff=Ce; gg=Cr; hh=Ct; ii=Cp; jj=Cu;
        }
    }
    else if(RxState == 3)        // 状态3：结束符验证
    {
        if(RxBuffer1[RxCounter1-1] == 0x5B) // 确认结束符正确
        {
            // 正常接收完成，重置状态
            RxFlag1 = 0;
            RxCounter1 = 0;
            RxState = 0;
        }
        else  // 结束符验证失败
        {
            RxState = 0;
            RxCounter1 = 0;
            // 清空缓冲区
            for(i=0; i<16; i++) RxBuffer1[i] = 0x00;
        }
    } 
    else  // 异常处理：非预期状态
    {
        RxState = 0;
        RxCounter1 = 0;
        for(i=0; i<16; i++) RxBuffer1[i] = 0x00; // 清空缓冲区
    }
}

/*************************************************
* 函数名称：fputc
* 功能描述：重定向printf输出到UART1
* 典型应用：调试时通过串口打印数据
*************************************************/
int fputc(int ch, FILE *f)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
    return ch;
}

/*************************************************
* 函数名称：fgetc
* 功能描述：重定向scanf输入从UART1
* 典型应用：从串口接收输入数据（本代码未直接使用）
*************************************************/
int fgetc(FILE *f)
{
    uint8_t ch = 0;
    HAL_UART_Receive(&huart1, &ch, 1, 0xffff);
    return ch;
}