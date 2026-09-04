#include <iwatchdog.h>
#include "stm32_regs.h"

#define IWDG_KEY_ENABLE     0xCCCCU
#define IWDG_KEY_RELOAD     0xAAAAU
#define IWDG_KEY_UNLOCK     0x5555U

#define IWDG_STATUS_BUSY    (1U << 0)

/*
 * LSI ≈ 32 kHz
 *
 * Prescaler = 32
 * Counter = 1000
 *
 * Timeout ≈ 1 second
 */
#define IWDG_PRESCALER      3U
#define IWDG_RELOAD_VALUE   1000U

void iwdg_init(void)
{
    /* Enable write access to IWDG registers */
    IWDG->KR = IWDG_KEY_UNLOCK;

    /* Prescaler = /32 */
    IWDG->PR = IWDG_PRESCALER;

    /* Reload value */
    IWDG->RLR = IWDG_RELOAD_VALUE;

    /* Wait until registers are updated */
    while (IWDG->SR & IWDG_STATUS_BUSY)
    {
    }

    /* Start watchdog */
    IWDG->KR = IWDG_KEY_ENABLE;
}

void iwdg_refresh(void)
{
    IWDG->KR = IWDG_KEY_RELOAD;
}


