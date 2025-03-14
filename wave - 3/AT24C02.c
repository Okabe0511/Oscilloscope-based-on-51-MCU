#include <STC89C5xRC.H>
#include "I2C1.h"
#include "Delay.h"
#define AT24C02_Address 0xA0
void AT24C02_WriteByte(unsigned char WordAddress,Data)
{
	I2CStart();
	I2CSendByte(AT24C02_Address);
	I2CReceiveACK();
	I2CSendByte(WordAddress);
	I2CReceiveACK();
	I2CSendByte(Data);
	I2CReceiveACK();
	I2CStop();
	
}
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
	unsigned char Data;
	I2CStart();
	I2CSendByte(AT24C02_Address);
	I2CReceiveACK();
	I2CSendByte(WordAddress);
	I2CReceiveACK();
	I2CStart();
	I2CSendByte(AT24C02_Address|0x01);
	I2CReceiveACK();
	Data=I2CReceiveByte();	
	I2CSendACK(1);	
	I2CStop();		
		return Data;

} 