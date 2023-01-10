/*
 * mma8652.c
 *
 * Created: 30-04-2015 11:34:31
 *  Author: hh
 */ 

#include <avr/io.h>
#include "Headers/i2c.h"

#define MMA8652_BASE_ADDRESS 0x1D
#define READ_MASK 0b00000001
#define X_MSB_ADR 0x01
#define Y_MSB_ADR 0x03
#define Z_MSB_ADR 0x05
#define CONTROL1_ADR 0x2A
#define CONTROL2_ADR 0x2B

void initAcc()
{
	// Initialize i2c hardware
	i2c_init();
	i2c_start();
	// Device write
	i2c_write(((MMA8652_BASE_ADDRESS)<<1));
	// Write first register address
	i2c_write(CONTROL1_ADR);
	// Set ACTIVE bit  
	i2c_write(0b00000001);
	i2c_stop();		
}

int AccX()
{
  int x;

    i2c_start();
	// Device write
	i2c_write(((MMA8652_BASE_ADDRESS)<<1));
	// Write first register address
	i2c_write(X_MSB_ADR);
	// Repeated start
	i2c_start();
	// Device read	
	i2c_write(((MMA8652_BASE_ADDRESS)<<1) | READ_MASK);
	// Read X high byte and ACK
	x = i2c_read(0);
	// Shift data to high byte
	x = x << 8 ;
	// Read X low byte and NACK
	// Merge to x variable
	x = x + i2c_read(1);
	i2c_stop();
	// Return right adjusted data (see MMA8652 data sheet)
	return (x>>4);
}

int AccY()
{
	int x;

	i2c_start();
	// Device write
	i2c_write(((MMA8652_BASE_ADDRESS)<<1));
	// Write first register address
	i2c_write(Y_MSB_ADR);
	// Repeated start
	i2c_start();
	// Device read
	i2c_write(((MMA8652_BASE_ADDRESS)<<1) | READ_MASK);
	// Read X high byte and ACK
	x = i2c_read(0);
	// Shift data to high byte
	x = x << 8 ;
	// Read X low byte and NACK
	// Merge to x variable
	x = x + i2c_read(1);
	i2c_stop();
	// Return right adjusted data (see MMA8652 data sheet)
	return (x>>4);
}

int AccZ()
{
	int x;

	i2c_start();
	// Device write
	i2c_write(((MMA8652_BASE_ADDRESS)<<1));
	// Write first register address
	i2c_write(Z_MSB_ADR);
	// Repeated start
	i2c_start();
	// Device read
	i2c_write(((MMA8652_BASE_ADDRESS)<<1) | READ_MASK);
	// Read X high byte and ACK
	x = i2c_read(0);
	// Shift data to high byte
	x = x << 8 ;
	// Read X low byte and NACK
	// Merge to x variable
	x = x + i2c_read(1);
	i2c_stop();
	// Return right adjusted data (see MMA8652 data sheet)
	return (x>>4);
}

