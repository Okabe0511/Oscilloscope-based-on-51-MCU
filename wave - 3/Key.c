#include <STC89C5xRC.H>
#include "Timer0.h"
#include "Key.h"
unsigned char Key_KeyNumber,KeyTime=0,KeyCount,keyi=0;
unsigned int times=0;	
unsigned char Key(void)
{
	unsigned char Temp;
	Temp=Key_KeyNumber;
	Key_KeyNumber=0;
	return Temp;
}

unsigned char MatrixKey()
{
	unsigned char KeyNumber=0;
	
	P1=0xFF;
	P13=0;
	if(P17==0){KeyNumber=1;}
	if(P16==0){KeyNumber=5;}
	if(P15==0){KeyNumber=9;}
	if(P14==0){KeyNumber=13;}
	
	P1=0xFF;
	P12=0;
	if(P17==0){KeyNumber=2;}
	if(P16==0){KeyNumber=6;}
	if(P15==0){KeyNumber=10;}
	if(P14==0){KeyNumber=14;}
	
	P1=0xFF;
	P11=0;
	if(P17==0){KeyNumber=3;}
	if(P16==0){KeyNumber=7;}
	if(P15==0){KeyNumber=11;}
	if(P14==0){KeyNumber=15;}
	
	P1=0xFF;
	P10=0;
	if(P17==0){KeyNumber=4;}
	if(P16==0){KeyNumber=8;}
	if(P15==0){KeyNumber=12;}
	if(P14==0){KeyNumber=16;}
	
	return KeyNumber;
}

void Key_Loop()
{
 static unsigned char NowState,LastState;
LastState=NowState;
NowState=MatrixKey();
if(LastState)
{
	{
		keyi++;
		times++;
		if(NowState==0)
		{
			KeyCount=keyi;
			keyi=0;
			if(LastState==1 && KeyCount<=50){Key_KeyNumber=1;KeyCount=0;}
			else if(LastState==2 && KeyCount<=50){Key_KeyNumber=2;KeyCount=0;}
			else if(LastState==3 && KeyCount<=50){Key_KeyNumber=3;KeyCount=0;}
			else if(LastState==4 && KeyCount<=50){Key_KeyNumber=4;KeyCount=0;}
			else if(LastState==5 && KeyCount<=50){Key_KeyNumber=5;KeyCount=0;}
			else if(LastState==6 && KeyCount<=50){Key_KeyNumber=6;KeyCount=0;}
			else if(LastState==7 && KeyCount<=50){Key_KeyNumber=7;KeyCount=0;}
		}
		if(NowState)
		{
			if(times>=50)
			{
			    KeyTime++; 
				if(KeyTime>=10)
				{
				    if(LastState==1 && NowState==1){Key_KeyNumber=17;KeyTime=0;}
					else if(LastState==2 && NowState==2){Key_KeyNumber=18;KeyTime=0;}
					else if(LastState==3 && NowState==3){Key_KeyNumber=19;KeyTime=0;}
					else if(LastState==4 && NowState==4){Key_KeyNumber=20;KeyTime=0;}
					else if(LastState==5 && NowState==5){Key_KeyNumber=21;KeyTime=0;}
					else if(LastState==6 && NowState==6){Key_KeyNumber=22;KeyTime=0;}
					else if(LastState==7 && NowState==7){Key_KeyNumber=23;KeyTime=0;}
				}
			}
		}
		else 
		{
			times=0;
		}
	}
}
}	


