#include "I2C.h"
#include <string.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Setting up the I2C pins ////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t I2C2Init(char pupdr[10], char i2csw[10]);

uint8_t I2C2Init(char pupdr[10], char i2csw[10])
{
// Initiating the GPIO pins A9 SCL and A10 SDA pins
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN; // Enabling GPIOA clock
	GPIOA->MODER |= (( GPIO_MODER_MODER9_1 ) | ( GPIO_MODER_MODER10_1 ));  // Alternate Function for pin SCL A9 and pin SDA A10, 10
	GPIOA->OTYPER |= (( GPIO_OTYPER_OT_9 ) | ( GPIO_OTYPER_OT_10 ));  //  A10 and A9 output open drain
	GPIOA->OSPEEDR |= (( GPIO_OSPEEDER_OSPEEDR9_0 ) | ( GPIO_OSPEEDER_OSPEEDR9_1 ) | ( GPIO_OSPEEDER_OSPEEDR10_0 ) | ( GPIO_OSPEEDER_OSPEEDR10_1 ));  // A10 and A9 set to high speed
	GPIOA->AFR[1] |= (( 0x4U << GPIO_AFRH_AFRH2_Pos ) | ( 0x4U << GPIO_AFRH_AFRH1_Pos ));  //  AF4 for pin A10 and A9
	if(strcmp(pupdr, "PULLUP") == 0)
	{
		GPIOA->PUPDR &= ~( GPIO_PUPDR_PUPDR9_0  | GPIO_PUPDR_PUPDR10_0 );  // Set A10, A9 to pull-up
	}
	else if (strcmp(pupdr, "NOPULL") == 0)
	{
		GPIOA->PUPDR &= ~( GPIO_PUPDR_PUPDR9  | GPIO_PUPDR_PUPDR10 );  // Set A10, A9 to no pull-up or pull-down
	}
// Configuring the I2C clocks
	RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;  // Enable I2C2 CLOCK
	if(strcmp(i2csw, "HSI") == 0)
	{
		RCC->CFGR3 |= RCC_CFGR3_I2C2SW_HSI; // Setting source of I2C2 clock as HSI
	}
	else if(strcmp(i2csw, "SYSCLK") == 0)
	{
		RCC->CFGR3 |= RCC_CFGR3_I2C2SW_SYSCLK; // Setting source of I2C2 clock as SYSCLK
	}
	RCC->APB1RSTR |= ( RCC_APB1RSTR_I2C2RST ); // Reset I2C2
	RCC->APB1RSTR &= ~( RCC_APB1RSTR_I2C2RST ); // Set I2C2 to normal operation
	return 1;
}	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Setting up the CR1, CR2, OAR1, OAR2 registers///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t I2C2SetCR1reg(char anfoff[10], unsigned int dnf, uint32_t time, char txdma[10], char rxdma[10], char sbc[10], char nostrch[10], 
											char wupen[10], char gcen[10], char smbhen[10], char smbden[10], char alerten[10], char pecen[10],			
											char txie[10], char rxie[10], char addrie[10], char nackie[10], char stopie[10], char tcie[10],	
											char errie[10]);
uint8_t I2C2SetTIMINGR(uint32_t time);
uint8_t I2C2SetCR2reg(uint16_t add, uint8_t size, char rdwr[10], char add10[10], char head10r[10], char autoend[10], char pecbyt[10]);
uint8_t I2C2SetOAR1reg(uint16_t sadd1,  char mode[10], char oa1en[10]);
uint8_t I2C2SetOAR2reg(uint8_t sadd2, uint8_t mask, char oa2en[10]);
void I2C2ClearISR(void);
											
uint8_t I2C2SetCR1reg(char anfoff[10], unsigned int dnf, uint32_t time, char txdma[10], char rxdma[10], char sbc[10], char nostrch[10], 
											char wupen[10], char gcen[10], char smbhen[10], char smbden[10], char alerten[10], char pecen[10],			
											char txie[10], char rxie[10], char addrie[10], char nackie[10], char stopie[10], char tcie[10],	
											char errie[10])
{
	//Configuring the CR1 Register
	I2C2->CR1 &= ~I2C_CR1_PE; 
	while((I2C2->CR1 & I2C_CR1_PE));
	I2C2->CR1 |= (dnf << I2C_CR1_DNF_Pos );
	if(strcmp(anfoff, "ANFON") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_ANFOFF; 
	}
	else if (strcmp(anfoff, "ANFOFF") == 0)
	{
		I2C2->CR1 |= I2C_CR1_ANFOFF; 
	}
	if(strcmp(txdma, "TXDMA") == 0)
	{
		I2C2->CR1 |= I2C_CR1_TXDMAEN;
	}
	else if(strcmp(txdma, "NOTXDMA") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_TXDMAEN;
	}
	if(strcmp(rxdma, "RXDMA") == 0)
	{
		I2C2->CR1 |= I2C_CR1_RXDMAEN;
	}
	else if(strcmp(rxdma, "NORXDMA") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_RXDMAEN;
	}
	if(strcmp(sbc, "SBC") == 0)
	{
		I2C2->CR1 |= I2C_CR1_SBC;
	}
	else if(strcmp(sbc, "NOSBC") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_SBC;
	}
	if(strcmp(nostrch, "NOSTRETCH") == 0)
	{
		I2C2->CR1 |= I2C_CR1_NOSTRETCH;
	}
	else if(strcmp(nostrch, "STRETCH") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_NOSTRETCH;
	}
	if(strcmp(wupen, "WUPEN") == 0)
	{
		I2C2->CR1 |= I2C_CR1_WUPEN;
	}
	else if(strcmp(wupen, "NOWUPEN") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_WUPEN;
	}
	if(strcmp(gcen, "GCEN") == 0)
	{
		I2C2->CR1 |= I2C_CR1_GCEN;
	}
	else if(strcmp(gcen, "NOGCEN") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_GCEN;
	}
	if(strcmp(smbhen, "SMBH") == 0)
	{
		I2C2->CR1 |= I2C_CR1_SMBHEN;
	}
	else if(strcmp(smbhen, "NOSMBH") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_SMBHEN;
	}
	if(strcmp(smbden, "SMBD") == 0)
	{
		I2C2->CR1 |= I2C_CR1_SMBDEN;
	}
	else if(strcmp(smbden, "NOSMBD") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_SMBDEN;
	}
	if(strcmp(alerten, "ALERT") == 0)
	{
		I2C2->CR1 |= I2C_CR1_ALERTEN;
	}
	else if(strcmp(alerten, "NOALERT") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_ALERTEN;
	}
	if(strcmp(pecen, "PECEN") == 0)
	{
		I2C2->CR1 |= I2C_CR1_PECEN;
	}
	else if(strcmp(pecen, "NOPECEN") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_PECEN;
	}
	if(strcmp(txie, "TXIE") == 0)
	{
		I2C2->CR1 |= I2C_CR1_TXIE; 
	}
	else if (strcmp(txie, "NOTXIE") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_TXIE; 
	}
	if(strcmp(rxie, "RXIE") == 0)
	{
		I2C2->CR1 |= I2C_CR1_RXIE; 
	}
	else if (strcmp(rxie, "NORXIE") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_RXIE; 
	}
	if(strcmp(addrie, "ADDRIE") == 0)
	{
		I2C2->CR1 |= I2C_CR1_ADDRIE; 
	}
	else if (strcmp(addrie, "NOADDRIE") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_ADDRIE; 
	}
	if(strcmp(nackie, "NACKIE") == 0)
	{
		I2C2->CR1 |= I2C_CR1_NACKIE; 
	}
	else if (strcmp(nackie, "NONACKIE") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_NACKIE; 
	}
	if(strcmp(stopie, "STOPIE") == 0)
	{
		I2C2->CR1 |= I2C_CR1_STOPIE; 
	}
	else if (strcmp(stopie, "NOSTOPIE") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_STOPIE; 
	}
	if(strcmp(tcie, "TCIE") == 0)
	{
		I2C2->CR1 |= I2C_CR1_TCIE; 
	}
	else if (strcmp(tcie, "NOTCIE") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_TCIE; 
	}
	if(strcmp(errie, "ERRIE") == 0)
	{
		I2C2->CR1 |= I2C_CR1_ERRIE; 
	}
	else if (strcmp(errie, "NOERRIE") == 0)
	{
		I2C2->CR1 &= ~I2C_CR1_ERRIE; 
	}
	uint8_t timingrOk = I2C2SetTIMINGR(time);
	I2C2->CR1 |= I2C_CR1_PE; 
	while(!(I2C2->CR1 & I2C_CR1_PE));

	return 1;
}
uint8_t I2C2SetTIMINGR(uint32_t time)
{
// Configuring the timing register with data from the CubeMX software, calculated value is 0x2000090E
	I2C2->TIMINGR = time; // Setting the value of TIMINGR
	return 1;
}
uint8_t I2C2SetCR2reg(uint16_t add, uint8_t size, char rdwr[10], char add10[10], char head10r[10], char autoend[10], char pecbyte[10])
{
	if(strcmp(add10, "ADD7BIT") == 0)
	{
		I2C2->CR2 &= ~I2C_CR2_ADD10; 
		I2C2->CR2 |= ( add << 1 ); 
	}
	else if(strcmp(add10, "ADD10BIT") == 0)
	{
		I2C2->CR2 |= I2C_CR2_ADD10; 
		if(strcmp(head10r, "NOHEAD10R") == 0)
		{
			I2C2->CR2 |= I2C_CR2_HEAD10R; 
		}
		else if (strcmp(head10r, "HEAD10R") == 0)
		{
			I2C2->CR2 &= ~I2C_CR2_HEAD10R; 
		}
		I2C2->CR2 |= ( add << I2C_CR2_SADD_Pos );
	}
	I2C2->CR2 |= ( size << I2C_CR2_NBYTES_Pos ); 	
	if(strcmp(rdwr, "READ") == 0)
	{
		I2C2->CR2 |= I2C_CR2_RD_WRN; 
	}
	else if (strcmp(rdwr, "WRITE") == 0)
	{
		I2C2->CR2 &= ~I2C_CR2_RD_WRN; 
	}
	if(strcmp(autoend, "AUTOEND") == 0)
	{
		I2C2->CR2 |= I2C_CR2_AUTOEND; 
	}
	else if (strcmp(autoend, "NOAUTOEND") == 0)
	{
		I2C2->CR2 &= ~I2C_CR2_AUTOEND; 
	}
	if(strcmp(pecbyte, "PECBYTE") == 0)
	{
		I2C2->CR2 |= I2C_CR2_PECBYTE; 
	}
	else if (strcmp(pecbyte, "NOPECBYTE") == 0)
	{
		I2C2->CR2 &= ~I2C_CR2_PECBYTE; 
	}
	return 1;
}
uint8_t I2C2SetOAR1reg(uint16_t sadd1,  char mode[10], char oa1en[10])
{
	// Configuring the main address register OAR1
	I2C2->OAR1 &= ~I2C_OAR1_OA1EN;
	if(strcmp(mode, "MODE7") == 0)
	{
		I2C2->OAR1 &= ~I2C_OAR1_OA1MODE;
	}
	else if(strcmp(mode, "MODE10") == 0)
	{
		I2C2->OAR1 |= I2C_OAR1_OA1MODE;
	}
	I2C2->OAR1 |= (sadd1 << 1);
	if(strcmp(oa1en, "OA1EN") == 0)
	{
		I2C2->OAR1 |= I2C_OAR1_OA1EN;
	}	
	return 1;
}
uint8_t I2C2SetOAR2reg(uint8_t sadd2, uint8_t mask, char oa2en[10])
{
//Configuring the second slave address register OAR2
	I2C2->OAR2 &= ~I2C_OAR2_OA2EN;
	I2C2->OAR2 |= (sadd2 << 1);
	I2C2->OAR1 |= (mask << 8);
	if(strcmp(oa2en, "OA1EN") == 0)
	{
		I2C2->OAR2 |= I2C_OAR2_OA2EN;
	}	
	return 1;
}
// Resseting different flags in the ISR register
void I2C2ClearISR(void)
{
	I2C2->ICR |= I2C_ICR_STOPCF;
	I2C2->ICR |= I2C_ICR_ADDRCF;
	I2C2->ICR |= I2C_ICR_NACKCF;
	I2C2->ICR |= I2C_ICR_BERRCF;
	I2C2->ICR |= I2C_ICR_ARLOCF;
	I2C2->ICR |= I2C_ICR_OVRCF;
	I2C2->ICR |= I2C_ICR_PECCF;
	I2C2->ICR |= I2C_ICR_TIMOUTCF;
	I2C2->ICR |= I2C_ICR_ALERTCF;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Setting master settings and data sending or recieving //////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t I2C2MasterInit(char pupdr[10], char i2csw[10], char anfoff[10], unsigned int dnf, uint32_t time, 
												char txie[10], char rxie[10], char addrie[10], char nackie[10], char stopie[10], 
												char tcie[10],  char errie[10]);
														
uint8_t I2C2MasterWriteSingleByte(uint16_t add, uint8_t data, char addbit[10], char autoend[10]);
uint8_t I2C2MasterReadSingleByte(uint16_t add, char addbit[10], char autoend[10]);
uint8_t * I2C2MasterReadWriteMultiple(uint8_t add, uint8_t data[], uint32_t size, char rw[5], char addbit[10], char autoend[10]);
												
void I2C2SetStart(void);
void I2C2SetStop(void);
void I2C2SetReload(char reload[10]);
void I2C2SetAckNacks(char nAck[4]);
												
uint8_t I2C2MasterInit(char pupdr[10], char i2csw[10], char anfoff[10], unsigned int dnf, uint32_t time, 
												char txie[10], char rxie[10], char addrie[10], char nackie[10], char stopie[10], 
												char tcie[10],  char errie[10])
{
	uint8_t initOk =	I2C2Init(pupdr, i2csw);

	uint8_t I2CCR1RegOk = I2C2SetCR1reg(anfoff, dnf, time, "", "", "", "STRETCH", "", "", 
																			"", "", "", "", txie, rxie, addrie, nackie, stopie, 
																			tcie, errie);
	return 1;
}

uint8_t I2C2MasterWriteSingleByte(uint16_t add, uint8_t data, char addbit[10], char autoend[10])
{
	uint8_t CRok = 0;
	CRok = I2C2SetCR2reg(add, 1, "WRITE", addbit, "", autoend, "NOPECBYTE");
	I2C2SetReload("NORELOAD");
	I2C2SetStart(); 
	I2C2->TXDR = data; 
	while(!(I2C2->ISR & I2C_ISR_TXE));
	I2C2SetStop(); 
	return 1; 
}
uint8_t I2C2MasterReadSingleByte(uint16_t add, char addbit[10], char autoend[10])
{
	uint8_t data;
	uint8_t CRok = 0;
	CRok = I2C2SetCR2reg(add, 1, "READ", addbit, "", autoend, "NOPECBYTE"); 
	I2C2SetReload("NORELOAD");
	I2C2SetStart(); 
	while(!( I2C2->ISR & I2C_ISR_RXNE )); 
	data = I2C2->RXDR; 
	I2C2SetStop(); 
	return data; 
}
uint8_t * I2C2MasterReadWriteMultiple(uint8_t add, uint8_t data[], uint32_t size, char rw[5], char addbit[10], char autoend[10])
{
	uint32_t arrindex = 0;
	uint8_t nbytes = 0;
	uint8_t CRok = 0;
	uint8_t retPoint[size];
	I2C2ClearISR();
	if(size > 255)
	{
		nbytes = 255;	
		I2C2SetReload("RELOAD");
	}
	else
	{
		nbytes = size;
		I2C2SetReload("NORELOAD");
	}
	CRok = I2C2SetCR2reg(add, nbytes, rw, addbit, "NOHEAD10R", autoend, "NOPECBYTE"); // Calling the function for setting the CR2 register values
	if(strcmp(rw, "WRITE") == 0)
	{
		I2C2SetStart();
		while(size > 0)
		{
			while(!(I2C2->ISR & I2C_ISR_TXIS));
			I2C2->TXDR = data[arrindex];
			arrindex++;
			size--;
			nbytes--;
			if((size != 0) && (nbytes == 0))
			{
				while(!(I2C2->ISR & I2C_ISR_TCR));
				if(size > 255)
				{
					nbytes = 255;	
					I2C2SetReload("RELOAD");
				}
				else
				{
					nbytes = size;
					I2C2SetReload("NORELOAD");
				}
				I2C2->CR2 |= ( nbytes << I2C_CR2_NBYTES_Pos ); 
			}
		}
		I2C2SetStop();
		return 123;
	}
	if(strcmp(rw, "READ") == 0)
	{
		I2C2SetStart();
		while(size > 0)
		{
			while(!(I2C2->ISR & I2C_ISR_RXNE));
			retPoint[arrindex] = I2C2->RXDR;
			arrindex++;
			size--;
			nbytes--;
			if((size != 0) && (nbytes == 0))
			{
				while(!(I2C2->ISR & I2C_ISR_TCR));
				if(size > 255)
				{
					nbytes = 255;	
					I2C2SetReload("RELOAD");
				}
				else
				{
					nbytes = size;
					I2C2SetReload("NORELOAD");
				}
				I2C2->CR2 |= ( nbytes << I2C_CR2_NBYTES_Pos ); 
			}
		}
		I2C2SetStop();
		return 123;
	}
	return 0;
}
// Establishing a start condition
void I2C2SetStart(void)
{
	I2C2->CR2 |= I2C_CR2_START; 
	while(I2C2->CR2 & I2C_CR2_START); // Checking that the start condition was established succesfully
}
 // Establishing a stop condition
void I2C2SetStop(void)
{
	I2C2->CR2 |= I2C_CR2_STOP;
	while(I2C2->CR2 & I2C_CR2_STOP); // Checking that the stop condition was established succesfully
}
 // Setting or resetting the reloead bit
void I2C2SetReload(char reload[10])
{
	if(strcmp(reload, "NORELOAD") == 0)
	{
		I2C2->CR2 &= ~I2C_CR2_RELOAD;
		while(I2C2->CR2 & I2C_CR2_RELOAD); // Checking that the reload bit was established succesfully
	}
	else if(strcmp(reload, "RELOAD") == 0)
	{
		I2C2->CR2 |= I2C_CR2_RELOAD;
		while(!(I2C2->CR2 & I2C_CR2_RELOAD)); // Checking that the reload bit was established succesfully
	}
}
// Setting an ack or nack condition
void I2C2SetAckNacks(char nAck[4])
{
	if(strcmp(nAck, "ACK") == 0)
	{
		I2C2->CR2 &= ~I2C_CR2_NACK; 
		while(!(I2C2->CR2 & I2C_CR2_NACK)); 
	}
	else if(strcmp(nAck, "NACK") == 0)
	{
		I2C2->CR2 |= I2C_CR2_NACK; 
		while(I2C2->CR2 & I2C_CR2_NACK); 
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Setting slave settings and data sending or recieving //////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t I2C2SlaveInit(char pupdr[10], char i2csw[10], uint16_t sadd1, char  oar1mode[10], char oa1en[10], 
											uint8_t sadd2, uint8_t oar2mask, char oa2en[10], char anfoff[10], unsigned int dnf, 
											char sbc[10], char nostrch[10], char gcen[10], char txie[10], char rxie[10], 
											char addrie[10], char nackie[10], char stopie[10], char tcie[10],  char errie[10]);


uint8_t I2C2SlaveReadWriteSingleByte(uint8_t dataTx, uint8_t oadd, char txrx[5]);											
uint8_t * I2C2SlaveReadWriteMultipleByte(uint8_t dataTx[], uint32_t size, uint8_t oadd, char txrx[5]);
											
uint8_t I2C2SlaveInit(char pupdr[10], char i2csw[10], uint16_t sadd1, char  oar1mode[10], char oa1en[10], 
											uint8_t sadd2, uint8_t oar2mask, char oa2en[10], char anfoff[10], unsigned int dnf, 
											char sbc[10], char nostrch[10], char gcen[10], char txie[10], char rxie[10], 
											char addrie[10], char nackie[10], char stopie[10], char tcie[10],  char errie[10])
{
	uint8_t initOk =	I2C2Init(pupdr, i2csw);
	uint8_t CR1Ok = I2C2SetCR1reg(anfoff, dnf, 0, "", "", sbc, nostrch, "", gcen, 
																				"", "", "", "", txie, rxie, addrie, nackie, stopie, 
																				tcie, errie);
	uint8_t OAR1Ok = I2C2SetOAR1reg(sadd1,  oar1mode, oa1en);
	uint8_t OAR2Ok = I2C2SetOAR2reg(sadd2, oar2mask, oa2en);
	return 1;
}

uint8_t I2C2SlaveReadWriteSingleByte(uint8_t dataTx, uint8_t oadd, char txrx[5])
{
	while(!(I2C2->ISR & I2C_ISR_ADDR));
	
	uint32_t maskAddOA1 = 0xFF01;
	uint32_t AddOA1 = 0;
	uint32_t maskAddOA2 = 0xFF01;
	uint32_t AddOA2 = 0;
	uint32_t maskAddcode = 0xFF0001FF;
	uint32_t ISRAddval = 0;
	switch(oadd)
	{
		case 1:
			AddOA1 = ((I2C2->OAR1 & ~maskAddOA1) >> 1);
			ISRAddval = ((I2C2->ISR & ~maskAddcode) >> 17);
			while(AddOA1 != ISRAddval);
			break;
		case 2:
			AddOA2 = ((I2C2->OAR2 & ~maskAddOA2) >> 1);
			ISRAddval = ((I2C2->ISR & ~maskAddcode) >> 17);
			while(AddOA2 != ISRAddval);
			break;
	}	
	if(strcmp(txrx, "READ") == 0)
	{
		while((I2C2->ISR & I2C_ISR_DIR));
		I2C2->ICR |= I2C_ICR_ADDRCF;
		while(!( I2C2->ISR & I2C_ISR_RXNE )); 
		uint8_t data = I2C2->RXDR; 
		return data;
	}		
	else if (strcmp(txrx, "WRITE") == 0)
	{
		while(!(I2C2->ISR & I2C_ISR_DIR));
		I2C2->ISR |= I2C_ISR_TXE;
		I2C2->ICR |= I2C_ICR_ADDRCF;
		while(!(I2C2->ISR & I2C_ISR_TXE)); 
		I2C2->TXDR = dataTx;
		while(!(I2C2->ISR & I2C_ISR_TXE)); 
		return dataTx;
	}
	return 0;
}


uint8_t * I2C2SlaveReadWriteMultipleByte(uint8_t dataTx[], uint32_t size, uint8_t oadd, char txrx[5])
{
	uint8_t data[size];
	uint32_t arrindex = 0;
	while(!(I2C2->ISR & I2C_ISR_ADDR));
	
	uint32_t maskAddOA1 = 0xFF01;
	uint32_t AddOA1 = 0;
	uint32_t maskAddOA2 = 0xFF01;
	uint32_t AddOA2 = 0;
	uint32_t maskAddcode = 0xFF0001FF;
	uint32_t ISRAddval = 0;
	switch(oadd)
	{
		case 1:
			AddOA1 = ((I2C2->OAR1 & ~maskAddOA1) >> 1);
			ISRAddval = ((I2C2->ISR & ~maskAddcode) >> 17);
			while(AddOA1 != ISRAddval);
			break;
		case 2:
			AddOA2 = ((I2C2->OAR2 & ~maskAddOA2) >> 1);
			ISRAddval = ((I2C2->ISR & ~maskAddcode) >> 17);
			while(AddOA2 != ISRAddval);
			break;
	}
	if(strcmp(txrx, "READ") == 0)
	{
		while((I2C2->ISR & I2C_ISR_DIR));
		I2C2->ICR |= I2C_ICR_ADDRCF;
		while(size)
		{
			while(!( I2C2->ISR & I2C_ISR_RXNE )); 
			data[arrindex] = I2C2->RXDR; 
			arrindex++;
			size--;
		}
		return data;
	}		
	else if (strcmp(txrx, "WRITE") == 0)
	{
		while(!(I2C2->ISR & I2C_ISR_DIR));
		I2C2->ISR |= I2C_ISR_TXE;
		I2C2->ICR |= I2C_ICR_ADDRCF;
		while(size)
		{
			while(!(I2C2->ISR & I2C_ISR_TXE)); 
			I2C2->TXDR = dataTx[arrindex]; 
			while(!(I2C2->ISR & I2C_ISR_TXE)); 
			arrindex++;
			size--;
		}
		return dataTx;
	}
	return 0;
}
















