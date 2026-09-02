/*
 * i2c.h
 *
 *  Created on: Sep 2, 2026
 *      Author: Mahi
 */

#ifndef I2C_H_
#define I2C_H_

void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_write_byte(char saddr, char data);
#endif /* I2C_H_ */
