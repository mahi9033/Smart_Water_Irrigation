#include "stm32_regs.h"

#define GPIOAEN    (1 << 0)
#define GPIOCEN    (1 << 2)

void gpio_init(void)
{
	// enable clock for GPIOA
	RCC->AHB1ENR |= GPIOAEN;

	// PA5 output for LED
	GPIOA->MODER |= (1U << 10);
	GPIOA->MODER &= ~(1U << 11);

	// PA6 Output for relay
	GPIOA->MODER |= (1U << 12);
    GPIOA->MODER &= ~(1U << 13);

    // PA1 input for water level sensor
    GPIOA->MODER &= ~(1U << 0);
    GPIOA->MODER &= ~(1U << 1);

    // Enable clock for GPIOC
	RCC->AHB1ENR |= GPIOCEN;

   // set PC13 as input for mannual irrigation
	GPIOC->MODER &= ~(1U << 26);
    GPIOC->MODER &= ~(1U << 27);

}
