#ifndef __I2C1_H__
#define __I2C1_H__
void I2CStart();
void I2CStop();
void I2CSendByte(unsigned char Byte);
unsigned char I2CReceiveByte();
void I2CSendACK(unsigned char ACKbit);
unsigned char I2CReceiveACK();
#endif