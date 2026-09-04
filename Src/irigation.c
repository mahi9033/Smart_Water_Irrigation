#include "irigation.h"
#include "soil_moisture.h"
#include "water_level.h"
#include "pump.h"
#include "emergency_stop.h"
#include "mannual.h"
#include <stdint.h>

#define MOISTURE_THRESHOLD    30U

void irrigation_control(void)
{
    uint8_t moisture;
    uint8_t water_status;
    uint8_t manual_status;
    uint8_t stop_status;

    moisture = soil_moisture();
    water_status = water_level();
    manual_status = mannul_pump_on();
    stop_status = emergency_stop_pressed();

    /* Emergency STOP has highest priority */
    if (stop_status == 1U)
    {
        pump_off();
    }
    /* Do not run pump when water is unavailable */
    else if (water_status == 0U)
    {
        pump_off();
    }
    /* Manual irrigation */
    else if (manual_status == 1U)
    {
        pump_on();
    }
    /* Automatic irrigation */
    else if (moisture < MOISTURE_THRESHOLD)
    {
        pump_on();
    }
    else
    {
        pump_off();
    }
}
