#include "GPIO.h"

void GPIOInit(void);

void GPIOInit(void)
{
	// Enabling GPIO clocks
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN; // Enabling GPIOA clock
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN; // Enabling GPIOB clock
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN; // Enabling GPIOC clock
	RCC->AHBENR |= RCC_AHBENR_GPIODEN; // Enabling GPIOD clock
	RCC->AHBENR |= RCC_AHBENR_GPIOEEN; // Enabling GPIOE clock
	RCC->AHBENR |= RCC_AHBENR_GPIOFEN; // Enabling GPIOF clock
		// Setting GPIOA PA1 as analog input for ADC
	GPIOA->MODER |= (GPIO_MODER_MODER1_1 | GPIO_MODER_MODER1_0); // Mode of pin A1 is set as Analog mode, bits are 11
//	GPIOA->PUPDR &= ~((1UL << 3) | (1UL << 2)); // Mode of pin A1 is set as not pulll-up or pull-down, bits are 00
	GPIOA->PUPDR &= ~((GPIO_PUPDR_PUPDR1_1) | (GPIO_PUPDR_PUPDR1_0)); // Mode of pin A1 is set as not pulll-up or pull-down, bits are 00
	
	GPIOC->MODER |= GPIO_MODER_MODER13_0; // Mode of pin C13 is set as autput mode, bits are 01
	GPIOC->OTYPER &= ~GPIO_OTYPER_OT_13; // Push pull is set as it enables to set the pin 13 as LOW or HIGH
	GPIOC->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR13_1 | GPIO_OSPEEDER_OSPEEDR13_0); // Speed of pin C13 is set to HIGH
		
//	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPDR13_1);	GPIOC->PUPDR |= (GPIO_PUPDR_PUPDR13_0);  // Mode of pin C13 is set as pull-up, bits are 01
	GPIOC->PUPDR |= (GPIO_PUPDR_PUPDR13_1);	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPDR13_0);  // Mode of pin C13 is set as pull-down, bits are 10

	GPIOA->MODER |= GPIO_MODER_MODER3_0; // Mode of pin A3 is set as autput mode, bits are 01
	GPIOA->OTYPER &= ~GPIO_OTYPER_OT_3; // Push pull of A3 is set as it enables to set the pin as LOW or HIGH
	GPIOA->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR3_1 | GPIO_OSPEEDER_OSPEEDR3_0); // Speed of pin A3 is set to HIGH
//	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR3_1;	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR1ss3_0;  // Mode of pin A3 is set as pull-up, bits are 01
//	GPIOA->PUPDR |= (GPIO_PUPDR_PUPDR3_1);	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR3_0);  // Mode of pin A3 is set as pull-down, bits are 10
	GPIOA->PUPDR |= (GPIO_PUPDR_PUPDR3_1);	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR3_0);  // Mode of pin A3 is set as pull-down, bits are 10

}
