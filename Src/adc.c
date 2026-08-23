#include "stm32_regs.h"

#define GPIOAEN         (1U << 0)
#define ADC1EN          (1U << 8)

#define CR2_CONT        (1U << 1)
#define CR2_ADON        (1U << 0)

#define ADC_SEQ_LEN     (0x00)

#define CR2_SWST        (1U << 30)

#define SR_EOC          (1U << 1)


void adc_init(void){

	/* ENABLE CLOCK FOR PORT A*/
	RCC->AHB1ENR |= GPIOAEN;

	/* set port as analog mode*/
	GPIOA->MODER |= (1U << 8);
	GPIOA->MODER |= (1U << 9);


	/*ENABLE CLOCK FOR ADC*/
	RCC->APB2ENR |= ADC1EN;

	/* continuos conversion */
	ADC1->CR2 |=CR2_CONT;

	/* sequence length  */
	ADC1->SQR1 &= ~(ADC_SEQ_LEN);

	/* CHANNEL NO */
	ADC1->SQR3 &= ~(0x1FU << 0);

	ADC1->SQR3 |= (4 << 0);

	/* Enable adc1 */
	ADC1->CR2 |= CR2_ADON;
}

void start_conv(void){
	  ADC1->CR2 |= CR2_SWST;
}

uint32_t read_data(void){
	while (!(ADC1->SR & SR_EOC)){}

	return ADC1->DR;
}





