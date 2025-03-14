#include <STC89C5xRC.H>
#include "OLED.h"
#include "AT24C02.h"
#include "Delay.h"
#include "TEST_MainPage.h"
#include "XPT2046.h"
#include "Key.h"
#include "math.h"
unsigned char k,p,i,j,fg=0,max,min,Dv=0,Dw,flag=0,wmax,wmin,turn=0,mv=0,xp,xxp=1;
float cnt;
int Dd;
unsigned char D[8]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char KeyNum;
float s=1,m=1,n=0;
int ADValue1,chr;
unsigned int DataValue[256]={0};
void main()
{
	Timer0_Init();
	OLED_Init();
	while(1)
	{
	turn=0;
	KeyNum=MatrixKey();
	if(KeyNum==1){flag=1;}
	if(KeyNum==2){flag=0;}
	if(KeyNum==3){s=s*2;}
	if(KeyNum==4){s=s/2;}
	if(KeyNum==5){turn=1;KeyNum=0;}
	if(KeyNum==6){turn=2;KeyNum=0;}
	if(KeyNum==7){flag=2;}
	if(KeyNum==8){mv++;}
	if(KeyNum==9){if(mv>0){mv--;}}
	if(KeyNum==10){xxp++;}
	if(KeyNum==11){xxp--;}
	if(flag==1){OLED_WriteCommand(0x2E);
	}
	if(flag==2){
	OLED_Clear();
	for(k=1;k<128;k++)
		{
		Dd=DataValue[k+mv]-DataValue[k-1+mv];
		if(Dd>0){oled_Draw_szLine2(k,DataValue[k+mv],DataValue[k+mv]+Dd);}
		if(Dd<=0){oled_Draw_szLine2(k,DataValue[k+mv]+Dd,DataValue[k+mv]);}
	}
		OLED_WriteCommand(0x2E);
		flag=1;
	}
	if(flag==0){
	OLED_WriteCommand(0x2E);
	OLED_WriteCommand(0x26);
	OLED_WriteCommand(0x00);
	OLED_WriteCommand(0x02);
	OLED_WriteCommand(0x07);
	OLED_WriteCommand(0x07);
	OLED_WriteCommand(0x00);
	OLED_WriteCommand(0xFF);
	}
		if(fg==0){
		for(k=128+mv;k>mv;k--)
	{
		for(i=0;i<8;i++){
	OLED_SetCursor(k,i);
	OLED_WriteData(0x00);
		}
		p=7;
		ADValue1=XPT2046_ReadAD(XPT2046_XP);
		m=s;
		DataValue[k]=ADValue1*s;
		Dd=DataValue[k]-DataValue[k-1];
		if(DataValue[k]>16){
		if(Dd>0){oled_Draw_szLine2(0,DataValue[k],DataValue[k]+Dd);}
		if(Dd<=0){oled_Draw_szLine2(0,DataValue[k]+Dd,DataValue[k]);}
	}
}
	if(flag==0){
		OLED_WriteCommand(0x2F);
	}

	fg=1;
	}
		if(fg==1){
		k=0;
		for(i=0;i<8;i++){
	OLED_SetCursor(k,i);
	OLED_WriteData(0x00);
		}
		p=7;
		if(xp>=xxp){
		ADValue1=XPT2046_ReadAD(XPT2046_XP);
			xp=0;
		}
		DataValue[k]=ADValue1*s;
		
			min=255;
			max=0;
		if(flag==0){
		for(k=127;k>0;k--){
			Dd=DataValue[1]-DataValue[0];
			DataValue[k+127]=DataValue[k+126];
			DataValue[k]=DataValue[k-1];
		if(DataValue[k]>max){max=DataValue[k];}
		if(DataValue[k]<min){min=DataValue[k];}
		if(DataValue[0]==max&&(DataValue[0]!=DataValue[1])){cnt=0;}
		}
				Dv=max-min;
		if(Dd>0){oled_Draw_szLine2(0,DataValue[1],DataValue[1]+Dd);}
		if(Dd<=0){oled_Draw_szLine2(0,DataValue[1]+Dd,DataValue[1]);}
if(turn==1){
			for(i=0;i<3;i++){
	OLED_SetCursor(0,i);
	for(j=0;j<19;j++){
	OLED_WriteData(0x00);}
	}
		OLED_ShowNum(0,0,(int)1/(cnt/100),3,6);
	turn==0;
}
if(turn==2){
				for(i=0;i<3;i++){
	OLED_SetCursor(40,i);
	for(j=40;j<59;j++){
	OLED_WriteData(0x00);}
		OLED_ShowNum(40,0,Dv,3,6);
	turn==0;
	}		
	}
}
	}
		if(flag==0){
		OLED_WriteCommand(0x2F);
		}
		Delay(10);
	}
}
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;		
	TH0 = 0xFC;
	T0Count++; 
	if(T0Count>10){
		T0Count=0;
		cnt++;
		xp++;
}

}


