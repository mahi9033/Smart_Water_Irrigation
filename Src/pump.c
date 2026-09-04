#include "stm32_regs.h"
#include <stdint.h>

#define GPIOAEN        (1 << 0)
#define PUMP_ON        (1 << 6)


void pump_on(void){
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |= (1 << 12);
	GPIOA->MODER &= ~(1 << 13);

	GPIOA->ODR |= PUMP_ON;



}

void pump_off(void){
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |= (1 << 12);
	GPIOA->MODER &= ~(1 << 13);

	GPIOA->ODR &= ~PUMP_ON;



}

