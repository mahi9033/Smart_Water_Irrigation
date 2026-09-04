/*
 * lcd.h
 *
 *  Created on: Sep 2, 2026
 *      Author: Mahi
 */


#ifndef LCD_H_
#define LCD_H_
#include <stdint.h>

void lcd_init(void);
void lcd_send_command(uint8_t command);
void lcd_send_data(uint8_t data);
void lcd_send_string(char *string);
void lcd_set_cursor(uint8_t row, uint8_t column);
void lcd_clear(void);


#endif /* LCD_H_ */
