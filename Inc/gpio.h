/*
 * gpio.h
 *
 *  Created on: Aug 23, 2026
 *      Author: Mahi
 */

#ifndef GPIO_H_
#define GPIO_H_
typedef struct
{
        volatile uint32_t MODER;
		volatile uint32_t OTYPER;
		volatile uint32_t OSPEEDR;
		volatile uint32_t PUPDR;
		volatile uint32_t IDR;
		volatile uint32_t ODR;
		volatile uint32_t BSRR;
		volatile uint32_t LCKR;
		volatile uint32_t AFR[2];


	}GPIO_TypeDef



#endif /* GPIO_H_ */
