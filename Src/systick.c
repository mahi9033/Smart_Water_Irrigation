#include "systick.h"
#include "stm32_regs.h"

#define SYSTICK_ENABLE       (1U << 0)
#define SYSTICK_CLKSOURCE    (1U << 2)
#define SYSTICK_COUNTFLAG    (1U << 16)

#define SYSTICK_LOAD_VALUE   15999U

void systick_init(void)
{
    SysTick->LOAD = SYSTICK_LOAD_VALUE;

    SysTick->VAL = 0U;

    SysTick->CTRL = SYSTICK_CLKSOURCE | SYSTICK_ENABLE;
}

void systick_delay_ms(uint32_t delay)
{
    uint32_t i;

    for (i = 0U; i < delay; i++)
    {
        while ((SysTick->CTRL & SYSTICK_COUNTFLAG) == 0U)
        {
        }
    }
}
