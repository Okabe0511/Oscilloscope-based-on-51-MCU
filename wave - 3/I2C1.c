#include <STC89C5xRC.H>
sbit I2CSCL=P2^1;
sbit I2CSDA=P2^0;

void I2CStart()
{
	I2CSDA=1;
	I2CSCL=1;
	I2CSDA=0;
	I2CSCL=0;
}
void I2CStop()
{
	I2CSDA=0;
	I2CSCL=1;
	I2CSDA=1;
}
void I2CSendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++){
	I2CSDA=Byte&(0x80>>i);
	I2CSCL=1;
	I2CSCL=0;
			
	}
}
unsigned char I2CReceiveByte()
{
unsigned char Byte=0x00,i;
	I2CSDA=1;	
for(i=0;i<8;i++)
	{
	I2CSCL=1;
	if(I2CSDA){Byte|=(0x80>>i);}
	I2CSCL=0;
	}
		return Byte;
}
void I2CSendACK(unsigned char ACKbit)
{
	I2CSDA=ACKbit; 
	I2CSCL=1;
	I2CSCL=0;	
}
unsigned char I2CReceiveACK()
{
	unsigned char ACKbit;
	I2CSDA=1;
	I2CSCL=1;
	ACKbit=I2CSDA;
	I2CSCL=0;
		return ACKbit;
}