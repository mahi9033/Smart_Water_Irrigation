#include "stm32_regs.h"
#include <stdint.h>

#define GPIOBEN              (1U << 1)
#define I2C1EN               (1U << 21)

#define I2CEN                (1U << 0)

#define SR2_BUSY             (1U << 1)

#define CR1_START            (1U << 8)
#define CR1_STOP             (1U << 9)

#define SR1_SB               (1U << 0)
#define SR1_ADDR             (1U << 1)
#define SR1_BTF              (1U << 2)
#define SR1_TXE              (1U << 7)

#define I2C_100KHZ           80U
#define SD_MODE_MAX_RISE_TIME     17


void i2c_init(void){

	// enable clock access for gpiob
		RCC->AHB1ENR |= GPIOBEN;

		// set pb8 and pb9 mode altenate function
		GPIOB->MODER &= ~(1U << 16);
		GPIOB->MODER |=  (1U << 17);

		GPIOB->MODER &= ~(1U << 18);
		GPIOB->MODER |=  (1U << 19);

		// set pb8 and pb9 otype mode open drain
		GPIOB->OTYPER |= (1U << 8);
		GPIOB->OTYPER |= (1U << 9);

		// set pb8 and pb9 pullup
		GPIOB->PUPDR &= ~(1U << 17);
		GPIOB->PUPDR |=  (1U << 16);

		GPIOB->PUPDR &= ~(1U << 19);
		GPIOB->PUPDR |=  (1U << 18);

		GPIOB->AFR[1] &= ~(1U << 0);
		GPIOB->AFR[1] &= ~(1U << 1);
		GPIOB->AFR[1] |=  (1U << 2);
		GPIOB->AFR[1] &= ~(1U << 3);

		GPIOB->AFR[1] &= ~(1U << 4);
		GPIOB->AFR[1] &= ~(1U << 5);
		GPIOB->AFR[1] |=  (1U << 6);
		GPIOB->AFR[1] &= ~(1U << 7);

		// ENABLE CLOCK //
		RCC->APB1ENR |= I2C1EN;

		// ENTER IN RESET MODE //
		I2C1->CR1 |= (1U << 15);

		// ENTER out of  RESET MODE //
		I2C1->CR1 &= ~(1U << 15);

		// SET THE PHEP CLK FRQ

		I2C1->CR2 |= (1U << 4);  // 16MHz     01000  = 16

		// SET I2C IN STANDARD MODE, 100Kz //
		I2C1->CCR |=I2C_100KHZ;

		//  SET RISE TIME //
		I2C1->TRISE |= SD_MODE_MAX_RISE_TIME;

		// EB=NABLE PHERIP //

		I2C1->CR1 |= I2CEN;

}

void i2c_start(void)
{
    I2C1->CR1 |= CR1_START;

    while (!(I2C1->SR1 & SR1_SB))
    {
    }
}


void i2c_stop(void)
{
    I2C1->CR1 |= CR1_STOP;
}


void i2c_write_byte(char saddr, char data)
{
    volatile int tmp;

    /* Wait until bus is free */
    while (I2C1->SR2 & SR2_BUSY)
    {
    }

    /* Generate START */
    I2C1->CR1 |= CR1_START;

    /* Wait for START condition */
    while (!(I2C1->SR1 & SR1_SB))
    {
    }

    /* Send slave address + WRITE */
    I2C1->DR = saddr << 1;

    /* Wait for address acknowledge */
    while (!(I2C1->SR1 & SR1_ADDR))
    {
    }

    /* Clear ADDR flag */
    tmp = I2C1->SR2;
    (void)tmp;

    /* Wait until data register is empty */
    while (!(I2C1->SR1 & SR1_TXE))
    {
    }

    /* Send data */
    I2C1->DR = data;

    /* Wait until byte transfer is finished */
    while (!(I2C1->SR1 & SR1_BTF))
    {
    }

    /* Generate STOP */
    I2C1->CR1 |= CR1_STOP;
}

