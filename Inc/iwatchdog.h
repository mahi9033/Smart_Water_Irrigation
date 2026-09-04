/*
 * watchdog.h
 *
 *  Created on: Sep 4, 2026
 *      Author: Mahi
 */

#ifndef IWATCHDOG_H_
#define IWATCHDOG_H_

#ifndef IWDG_H_
#define IWDG_H_

#include <stdint.h>

void iwdg_init(void);
void iwdg_refresh(void);

#endif

#endif /* IWATCHDOG_H_ */
