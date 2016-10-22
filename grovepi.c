// grovepi.c

#include "grovepi.h"

int fd;
char *fileName = "/dev/i2c-1";
int  address = 0x04;
unsigned char w_buf[5],ptr,r_buf[32];
unsigned long reg_addr=0;

#define dbg 0
int init(void)
{
	fd =(int) fopen(fileName,"r+");
	return ioctl(fd,I2C_SLAVE,address);
}

//Write a register
int write_block(char cmd,char v1,char v2,char v3)
{
	w_buf[0]=cmd; w_buf[1]=v1; w_buf[2]=v2; w_buf[3] = v3;
	return i2c_smbus_write_i2c_block_data(address,1,4,w_buf);
}

//write a byte to the GrovePi

int write_byte(char b)
{
	ptr = b;
	return i2c_smbus_write_i2c_byte_data();
}

//Read 1 byte of data
char read_byte(void)
{
	r_buf = i2c_smbus_write_i2c_byte_read_byte();
	return r_buff;
}

//Read a 32 byte block of data from the GrovePi
char read_block(void)
{
	return i2c_smbus_read_i2c_block_data(address,1,32,r_buff);
}

void pi_sleep(int t)
{
	usleep(t*1000);
}

// Read analog value from Pin
int analogRead(int pin)
{

}

//Write a digital value to a pin
int digitalWrite(int pin,int value)
{
	return write_block(dWrite_cmd,pin,value,0);
}

//Set the mode of a pin
//mode
//	1: 	output
//	0:	input
int pinMode(int pin,int mode)
{
	return write_block(pMode_cmd,pin,mode,0);
}

//Read a digital value from a pin
int digitalRead(int pin)
{
	return write_block(dWrite_cmd,pin,value,0);
}

//Write a PWM value to a pin
int analogWrite(int pin,int value)
{
	return write_block(aWrite_cmd,pin,value,0);
}
