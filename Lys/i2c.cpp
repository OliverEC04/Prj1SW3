#include <avr/io.h>

// Note: LM75 I2C max clock frequency = 400 kHz
// Note: MMA8652 I2C max clock frequency = 400 kHz
void i2c_init()
{
  // TWI prescaler = 1 (same as default)
  TWSR = 0;
  // LM75 / MMA8652 clock has be to be lower than 400 kHz (according to data sheet)
  // We choose 2-wire clock ~ 50 kHz
  // The TWBR must be at least 10 in master mode (Mega32 data book)
  // SCL frequency = 16 MHz / (16 + 2*TWBR*1), when prescaler = 1
  TWBR = 152;
}

void i2c_start()
{
  TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
  while ((TWCR & (1<<TWINT)) == 0)
  {}
}

void i2c_write(unsigned char data)
{
  TWDR = data;
  TWCR = (1<<TWINT) | (1<<TWEN);
  while ((TWCR & (1<<TWINT)) == 0)
  {}
}

unsigned char i2c_read (unsigned char isLast)
{
  if (isLast == 0) //If we want to read more than 1 byte
    TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
  else             //If we want to read only one byte
    TWCR = (1<<TWINT) | (1<<TWEN);
  while ((TWCR & (1<<TWINT)) == 0)
  {}
  return TWDR;
}

void i2c_stop()
{
  TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}