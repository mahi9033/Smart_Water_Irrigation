#include "emergency_stop.h"
#include "stm32_regs.h"

#define GPIOBEN             (1U << 1)
#define STOP_PIN            (1U << 0)

void emergency_stop_init(void)
{
    /* Enable GPIOB clock */
    RCC->AHB1ENR |= GPIOBEN;

    /* PB0 as input */
    GPIOB->MODER &= ~(3U << 0);
}

uint8_t emergency_stop_pressed(void)
{
    if (GPIOB->IDR & STOP_PIN)
    {
        return 1U;
    }

    return 0U;
}
