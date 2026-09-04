/*
 * systick.h
 *
 *  Created on: Sep 2, 2026
 *      Author: Mahi
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_


#include <stdint.h>
void systick_init(void);
void systick_delay_ms(uint32_t delay);



#endif /* SYSTICK_H_ */
