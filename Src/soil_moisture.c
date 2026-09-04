#include "stm32_regs.h"
#include <stdint.h>
#include "irigation.h"

#include "adc.h"

uint32_t dry_value = 3500;
uint32_t wet_value = 1500;

uint32_t soil_moisture(void){
	uint32_t adc_value;
	uint32_t moisture;

	adc_value = read_data();
	if(adc_value >= dry_value)
	{
		return 0U;
	}

	if(adc_value <= wet_value)
		{
			return 100U;
		}

	 moisture = ((uint32_t)(dry_value - adc_value) * 100U)
	               / (dry_value - wet_value);

	    return (uint8_t)moisture;


}

uint8_t soil_sensor_health(void)
{
    uint16_t adc_value;

    adc_value = read_data();

    if (adc_value == 0U || adc_value >= 4095U)
    {
        return 0U;
    }

    return 1U;
}


