#ifndef __OLED_H__
#define __OLED_H__
#include <STC89C5xRC.H>
sbit OLED_SCL=P2^0;//时钟 D0(SCLK)
sbit OLED_SDIN=P2^1;//D1（MOSI） 数据
sbit OLED_RST =P2^2;//复位
sbit OLED_DC =P2^3;//数据/命令控制
sbit OLED_CS=P2^4; //片选
void OLED_WriteCommand(unsigned char Command);
void OLED_WriteData(unsigned char Data);
void OLED_Init();
void OLED_SetCursor(unsigned char X,unsigned char Page);
void OLED_Clear();
void OLED_Clear_Row(int Row);
void OLED_Axis_Y();
void OLED_Axis_X();
void OLED_ShowChar(unsigned char X,unsigned char Page,unsigned char Char,unsigned char FrontSize);
void OLED_ShowString(unsigned char X,unsigned char Page,unsigned char *String,unsigned char FrontSize);
int OLED_Pow(int X, int Y);
void OLED_ShowNum(unsigned char X,unsigned char Page,int Num,unsigned int Length,unsigned char FrontSize);
void Show(int j);
void ClearGraph();
void oled_Draw_szLine2(unsigned char x,unsigned char start,unsigned char end);
#endif