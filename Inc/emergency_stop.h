/*
 * emergency_stop.h
 *
 *  Created on: Sep 4, 2026
 *      Author: Mahi
 */

#ifndef EMERGENCY_STOP_H_
#define EMERGENCY_STOP_H_
#include <stdint.h>

void emergency_stop_init(void);
uint8_t emergency_stop_pressed(void);
#endif /* EMERGENCY_STOP_H_ */
