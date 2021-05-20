#include "RCC.h"

void SysClockInit(void);

void SysClockInit(void)
{
	// Flash register
  FLASH->ACR |=  (FLASH_ACR_LATENCY_1 | FLASH_ACR_PRFTBE | FLASH_ACR_HLFCYA); // Seting latency to 2ws, enabling prefetch buffer, eneabling half cycle access
	// Setting POWER ENABLE CLOCK	val = 2;
	RCC->APB1ENR |= RCC_APB1ENR_PWREN; // Enabling Power interface clock	
	// Enabling HSE, HSI and PLL CR register
	RCC->CR |= RCC_CR_HSEON; // Activate external clock (HSE: 8 MHz)
	while ((RCC->CR & RCC_CR_HSERDY) == 0); // Wait until HSE is ready
	RCC->CR |= RCC_CR_HSION; // Activate internal clock (HSI: 8 MHz)
	while ((RCC->CR & RCC_CR_HSIRDY) == 0); // Wait until HSI is ready
	RCC->CR |= RCC_CR_PLLON; // Activate PLL
	while ((RCC->CR & RCC_CR_PLLRDY) == 0); // Wait until PLL is ready
	// Clock config register CFRG								
	RCC->CFGR |= RCC_CFGR_SW_PLL; //Seting SYSCLK source to PLL
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL); // Wait until PLL is ready
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1; // Setting AHB divisor to /1
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; // Setting APB1 divisor to /2
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; // Setting APB2 divisor to /1
	RCC->CFGR |= RCC_CFGR_PLLSRC_HSE_PREDIV;	// Setting PLL source to HSE
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_HSE_PREDIV_DIV1; // Setting PLL HSE divisor to /1
	RCC->CFGR |= RCC_CFGR_PLLMUL9; // Setting PLL multiplicator to 9
	RCC->CFGR |= RCC_CFGR_USBPRE_DIV1; // Setting USB divisor to /1
	RCC->CFGR |= RCC_CFGR_I2SSRC_SYSCLK; // Setting I2S clock to internal SYSCLK
	RCC->CFGR |= RCC_CFGR_MCO_NOCLOCK; // Setting MCO to no clock
}
