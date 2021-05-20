# include "stm32f303xc.h"
#include <string.h>
#include "I2C.h"
#include "RCC.h"
#include "GPIO.h"

uint32_t bit7count_0 = 0;
uint32_t bit7count_1 = 0;
uint8_t initOk = 0;

uint16_t address7bit[128];

void I2CBusScanner(void);
void I2CEcho(uint16_t add, char add10[5]);

int main(void)
{	
	SysClockInit();
	GPIOInit();
	initOk = I2C2MasterInit("NOPULL", "HSI", "ANFON", 0000, 0x2000090E, "TXIE", "RXIE", "ADDRIE", "NACKIE", "STOPIE", "TCIE", "ERRIE");
	
	I2CBusScanner();

	while(1)
	{
	}
}

void I2CBusScanner(void)
{
	uint8_t I2C2InitOk = 0;
	for(uint16_t addPos = 0x00; addPos <(sizeof(address7bit)/sizeof(address7bit[0])); addPos++)
	{
		I2CEcho(addPos, "ADD7BIT");
		I2C2InitOk = I2C2MasterInit("NOPULL", "HSI", "ANFON", 0000, 0x2000090E, "TXIE", "RXIE", "ADDRIE", "NACKIE", "STOPIE", "TCIE", "ERRIE");
	}		
}

void I2CEcho(uint16_t add, char add10[5])
{
	uint8_t CRok = 0;
	if(strcmp(add10, "ADD7BIT") == 0)
	{
		CRok = I2C2SetCR2reg(add, 1, "WRITE", add10, "", "NOAUTOEND", "NOPECBYTE");
		I2C2SetReload("NORELOAD");
		I2C2SetStart();
		if((I2C2->ISR & I2C_ISR_NACKF) == 0)
		{
			address7bit[add] = add;
			bit7count_1++;
		}
		if((I2C2->ISR & I2C_ISR_NACKF) != 0)
		{
			address7bit[add] = 0;	
			bit7count_0++;
		}
	}
}


