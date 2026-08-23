#include "stm32_regs.h"
#include "gpio.h"
#include "adc.h"

uint32_t soil_val;

int main(void)
{
	gpio_init();
	adc_init();
	start_conv();
    while (1)
    {
    	soil_val = read_data();
    }
}
