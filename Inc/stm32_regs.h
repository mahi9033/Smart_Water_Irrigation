#ifndef STM32_REGS_H_
#define STM32_REGS_H_

#include <stdint.h>
#define PERIPH_BASE             (0x40000000UL)
#define AHB1PERIPH_OFFSET       (0x00020000UL)
#define AHB1PERIPH_BASE         (PERIPH_BASE + AHB1PERIPH_OFFSET)

/*************GPIO_ADDRESS******************/

#define GPIOA_OFFSET            (0x00000000UL)
#define GPIOB_OFFSET            (0x00000400UL)
#define GPIOC_OFFSET            (0x00000800UL)

#define GPIOA_BASE (AHB1PERIPH_BASE + GPIOA_OFFSET)
#define GPIOB_BASE (AHB1PERIPH_BASE + GPIOB_OFFSET)
#define GPIOC_BASE (AHB1PERIPH_BASE + GPIOC_OFFSET)


/*************RCC_ADDRESS*******************/
#define RCC_OFFSET              (0x00003800UL)

#define RCC_BASE                (AHB1PERIPH_BASE + RCC_OFFSET)

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


	}GPIO_TypeDef;

#define GPIOA        ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB        ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC        ((GPIO_TypeDef *)GPIOC_BASE)

	typedef struct
	{
	    volatile uint32_t CR;
	    volatile uint32_t PLLCFGR;
	    volatile uint32_t CFGR;
	    volatile uint32_t CIR;

	    volatile uint32_t AHB1RSTR;
	    volatile uint32_t AHB2RSTR;
	    volatile uint32_t AHB3RSTR;
	    volatile uint32_t RESERVED0;

	    volatile uint32_t APB1RSTR;
	    volatile uint32_t APB2RSTR;
	    volatile uint32_t RESERVED1;
	    volatile uint32_t RESERVED2;

	    volatile uint32_t AHB1ENR;

	} RCC_TypeDef;

	#define RCC ((RCC_TypeDef *)RCC_BASE)


#endif /* STM32_REGS_H_ */
