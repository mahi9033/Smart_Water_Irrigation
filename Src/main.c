#include "stm32_regs.h"
#include "gpio.h"
#include "adc.h"
#include "i2c.h"
#include "lcd.h"
#include "pump.h"
#include "water_level.h"
#include "soil_moisture.h"
#include "emergency_stop.h"
#include "mannual.h"
#include "irigation.h"
#include "systick.h"
uint32_t soil_val;

int main(void)
{
	gpio_init();
	adc_init();
	i2c_init();
	systick_init();
	lcd_init();
	emergency_stop_init();

    while (1)
    {
    	irrigation_control();
    }
}
