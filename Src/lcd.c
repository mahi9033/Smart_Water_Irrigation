#include "lcd.h"
#include "i2c.h"
#include "systick.h"
#include <stdint.h>
#define LCD_I2C_ADDRESS    0x27U

#define LCD_RS             (1U << 0)
#define LCD_RW             (1U << 1)
#define LCD_EN             (1U << 2)
#define LCD_BACKLIGHT      (1U << 3)

static void lcd_send_nibble(uint8_t nibble, uint8_t rs)
{
    uint8_t data;

    data = (uint8_t)((nibble << 4) | LCD_BACKLIGHT);

    if (rs)
    {
        data |= LCD_RS;
    }

    /* EN = 1 */
    i2c_write_byte(LCD_I2C_ADDRESS, data | LCD_EN);

    systick_delay_ms(1);

    /* EN = 0 */
    i2c_write_byte(LCD_I2C_ADDRESS, data);

    systick_delay_ms(1);
}


static void lcd_send_byte(uint8_t data, uint8_t rs)
{
    uint8_t high_nibble;
    uint8_t low_nibble;

    high_nibble = (uint8_t)(data >> 4);
    low_nibble  = (uint8_t)(data & 0x0FU);

    lcd_send_nibble(high_nibble, rs);
    lcd_send_nibble(low_nibble, rs);
}


void lcd_init(void)
{
    systick_delay_ms(20);

    /* 4-bit initialization sequence */
    lcd_send_nibble(0x03U, 0);
    systick_delay_ms(5);

    lcd_send_nibble(0x03U, 0);
    systick_delay_ms(1);

    lcd_send_nibble(0x03U, 0);
    systick_delay_ms(1);

    lcd_send_nibble(0x02U, 0);

    /* 4-bit mode, 2 lines, 5x8 font */
    lcd_send_command(0x28U);

    /* Display ON, cursor OFF, blink OFF */
    lcd_send_command(0x0CU);

    /* Entry mode: increment cursor */
    lcd_send_command(0x06U);

    /* Clear display */
    lcd_send_command(0x01U);

    systick_delay_ms(2);
}


void lcd_send_command(uint8_t command)
{
    lcd_send_byte(command, 0);

    if (command == 0x01U || command == 0x02U)
    {
        systick_delay_ms(2);
    }
}


void lcd_send_data(uint8_t data)
{
    lcd_send_byte(data, 1);
}


void lcd_send_string(char *string)
{
    while (*string != '\0')
    {
        lcd_send_data((uint8_t)*string);
        string++;
    }
}


void lcd_set_cursor(uint8_t row, uint8_t column)
{
    uint8_t address;

    if (row == 0U)
    {
        address = (uint8_t)(0x80U + column);
    }
    else
    {
        address = (uint8_t)(0xC0U + column);
    }

    lcd_send_command(address);
}


void lcd_clear(void)
{
    lcd_send_command(0x01U);
    systick_delay_ms(2);
}
