#include "stm32_regs.h"
#include <stdint.h>
#include "water_level.h"


#define water_l          (1U << 1)

uint8_t water_level(void){

	if(GPIOA->IDR & water_l){
	return 1U;
	}

	else
	{
		return 0U;
	}
}







