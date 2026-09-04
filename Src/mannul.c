#include "stm32_regs.h"
#include <stdint.h>
#include "mannual.h"


#define PIN13              (1U  << 13)

uint32_t mannul_pump_on(void){

  if(GPIOC->IDR & PIN13)
  {
	  return 1U;
  }
  else
  {
	  return 0U;
  }
}
