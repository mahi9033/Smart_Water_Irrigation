#ifndef STM32_REGS_H_
#define STM32_REGS_H_

#include <stdint.h>
#define PERIPH_BASE             (0x40000000UL)
#define AHB1PERIPH_OFFSET       (0x00020000UL)
#define AHB1PERIPH_BASE         (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define APB2PERIPH_OFFSET       (0x00010000UL)
#define APB2PERIPH_BASE         (PERIPH_BASE + APB2PERIPH_OFFSET)

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

/*************ADC_ADDRESS*******************/
#define ADC1_OFFSET              (0x00002000UL)

#define ADC1_BASE                (APB2PERIPH_BASE + ADC1_OFFSET)

/*************I2C_ADDRESS*******************/
#define I2C1_OFFSET              (0x00005400UL)

#define I2C1_BASE                (APB2PERIPH_BASE + I2C1_OFFSET)

/************SYSTICK_BASE ******************/

#define SYSTICK_BASE    0xE000E010UL

/************Watchdog_BASE ******************/


#define IWDG_BASE       0x40003000UL




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
	    volatile uint32_t APB1RSTR;
	    volatile uint32_t APB2RSTR;
	    volatile uint32_t AHB1ENR;
	    volatile uint32_t AHB2ENR;
	    volatile uint32_t APB1ENR;
	    volatile uint32_t APB2ENR;
	    volatile uint32_t AHB1LPENR;
	    volatile uint32_t AHB2LPENR;
	    volatile uint32_t APB1LPENR;
	    volatile uint32_t APB2LPENR;
	    volatile uint32_t BDCR;
	    volatile uint32_t CSR;
	    volatile uint32_t SSCGR;
	    volatile uint32_t PLLI2SCFGR;
	    volatile uint32_t DCKCFGR;;

	}RCC_TypeDef;
#define RCC            ((RCC_TypeDef*)RCC_BASE)

typedef struct{

		volatile uint32_t SR;
		volatile uint32_t CR1;
		volatile uint32_t CR2;
		volatile uint32_t SMPR1;
		volatile uint32_t SMPR2;
		volatile uint32_t JOFR;
		volatile uint32_t HTR;
		volatile uint32_t LTR[4];
		volatile uint32_t SQR1;
		volatile uint32_t SQR2;
		volatile uint32_t SQR3;
		volatile uint32_t JSQR;
		volatile uint32_t JDR[4];
		volatile uint32_t DR;
		volatile uint32_t CCR;


	}ADC_TypeDef;

#define ADC1          ((ADC_TypeDef *)ADC1_BASE)



	typedef struct{

			volatile uint32_t CR1;
			volatile uint32_t CR2;
			volatile uint32_t OAR1;
			volatile uint32_t OAR2;
			volatile uint32_t DR;
			volatile uint32_t SR1;
			volatile uint32_t SR2;
			volatile uint32_t CCR;
			volatile uint32_t TRISE;
			volatile uint32_t FLTR;

		}I2C1_TypeDef;

	#define I2C1          ((I2C1_TypeDef *)I2C1_BASE)

		typedef struct
		{
		    volatile uint32_t CTRL;
		    volatile uint32_t LOAD;
		    volatile uint32_t VAL;
		    volatile uint32_t CALIB;
		} SysTick_TypeDef;

#define SysTick         ((SysTick_TypeDef *)SYSTICK_BASE)


		typedef struct
		{
		    volatile uint32_t KR;
		    volatile uint32_t PR;
		    volatile uint32_t RLR;
		    volatile uint32_t SR;
		} IWDG_TypeDef;

#define IWDG            ((IWDG_TypeDef *)IWDG_BASE)


#endif /* STM32_REGS_H_ */












