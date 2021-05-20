//#include "I2C.h"
//#include <string.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Setting up the I2C pins ////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//uint8_t I2C1Init(char pupdr[7], char i2csw[6]);
//uint8_t I2C2Init(char pupdr[7], char i2csw[6]);


//uint8_t I2C1Init(char pupdr[7], char i2csw[6])
//{
//// Initiating the GPIO pins B6 SCL and B7 SDA pins
//	RCC->AHBENR |= RCC_AHBENR_GPIOBEN; // Enabling GPIOB clock
//	GPIOB->MODER |= (( GPIO_MODER_MODER6_1 ) | ( GPIO_MODER_MODER7_1 ));  // Alternate Function for pin SCL B6 and pin SDA B7, 10
//	GPIOB->OTYPER |= (( GPIO_OTYPER_OT_6 ) | ( GPIO_OTYPER_OT_7 ));  //  B6 and B7 output open drain
//	GPIOB->OSPEEDR |= (( GPIO_OSPEEDER_OSPEEDR6_0 ) | ( GPIO_OSPEEDER_OSPEEDR6_1 ) | ( GPIO_OSPEEDER_OSPEEDR7_0 ) | ( GPIO_OSPEEDER_OSPEEDR7_1 ));  // B7 and B6 set to high speed
//	GPIOB->AFR[0] |= (( 0x4U << GPIO_AFRL_AFRL6_Pos ) | ( 0x4U << GPIO_AFRL_AFRL7_Pos ));  //  AF4 for pin B7 and B6
//	if(strcmp(pupdr, "PULLUP") == 0)
//	{
//		GPIOB->PUPDR &= ~( GPIO_PUPDR_PUPDR6_0  | GPIO_PUPDR_PUPDR7_0 );  // Set B7, B6 to pull-up
//	}
//	else if (strcmp(pupdr, "NOPULL") == 0)
//	{
//		GPIOB->PUPDR &= ~( GPIO_PUPDR_PUPDR9  | GPIO_PUPDR_PUPDR10 );  // Set B6, B7 to no pull-up or pull-down
//	}
//// Configuring the I2C clocks
//	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;  // enable I2C1 CLOCK
//	if(strcmp(i2csw, "HSI") == 0)
//	{
//		RCC->CFGR3 |= RCC_CFGR3_I2C1SW_HSI; // Setting source of I2C2 clock as HSI
//	}
//	else if(strcmp(i2csw, "SYSCLK") == 0)
//	{
//		RCC->CFGR3 |= RCC_CFGR3_I2C1SW_SYSCLK; // Setting source of I2C2 clock as SYSCLK
//	}
//	RCC->APB1RSTR |= ( RCC_APB1RSTR_I2C1RST ); // Reset I2C2
//	RCC->APB1RSTR &= ~( RCC_APB1RSTR_I2C1RST ); // Set I2C2 to normal operation
//	return 1;
//}	
//	
//uint8_t I2C2Init(char pupdr[7], char i2csw[6])
//{
//// Initiating the GPIO pins A9 SCL and A10 SDA pins
//	RCC->AHBENR |= RCC_AHBENR_GPIOAEN; // Enabling GPIOA clock
//	GPIOA->MODER |= (( GPIO_MODER_MODER9_1 ) | ( GPIO_MODER_MODER10_1 ));  // Alternate Function for pin SCL A9 and pin SDA A10, 10
//	GPIOA->OTYPER |= (( GPIO_OTYPER_OT_9 ) | ( GPIO_OTYPER_OT_10 ));  //  A10 and A9 output open drain
//	GPIOA->OSPEEDR |= (( GPIO_OSPEEDER_OSPEEDR9_0 ) | ( GPIO_OSPEEDER_OSPEEDR9_1 ) | ( GPIO_OSPEEDER_OSPEEDR10_0 ) | ( GPIO_OSPEEDER_OSPEEDR10_1 ));  // A10 and A9 set to high speed
//	GPIOA->AFR[1] |= (( 0x4U << GPIO_AFRH_AFRH2_Pos ) | ( 0x4U << GPIO_AFRH_AFRH1_Pos ));  //  AF4 for pin A10 and A9
//	if(strcmp(pupdr, "PULLUP") == 0)
//	{
//		GPIOA->PUPDR &= ~( GPIO_PUPDR_PUPDR9_0  | GPIO_PUPDR_PUPDR10_0 );  // Set A10, A9 to pull-up
//	}
//	else if (strcmp(pupdr, "NOPULL") == 0)
//	{
//		GPIOA->PUPDR &= ~( GPIO_PUPDR_PUPDR9  | GPIO_PUPDR_PUPDR10 );  // Set A10, A9 to no pull-up or pull-down
//	}
//// Configuring the I2C clocks
//	RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;  // Enable I2C2 CLOCK
//	if(strcmp(i2csw, "HSI") == 0)
//	{
//		RCC->CFGR3 |= RCC_CFGR3_I2C2SW_HSI; // Setting source of I2C2 clock as HSI
//	}
//	else if(strcmp(i2csw, "SYSCLK") == 0)
//	{
//		RCC->CFGR3 |= RCC_CFGR3_I2C2SW_SYSCLK; // Setting source of I2C2 clock as SYSCLK
//	}
//	RCC->APB1RSTR |= ( RCC_APB1RSTR_I2C2RST ); // Reset I2C2
//	RCC->APB1RSTR &= ~( RCC_APB1RSTR_I2C2RST ); // Set I2C2 to normal operation
//	return 1;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Setting up the master///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//uint8_t I2C1MasterSetCR1reg(char anfoff[6], unsigned int dnf, char stretch[9], uint32_t timingreg, char txie[6], char rxie[6], char addrie[8], char nackie[8], char stopie[8], char tcie[6],  char errie[7]);
//uint8_t I2C2MasterSetCR1reg(char anfoff[6], unsigned int dnf, char stretch[9], uint32_t timingreg, char txie[6], char rxie[6], char addrie[8], char nackie[8], char stopie[8], char tcie[6],  char errie[7]);


//uint8_t I2C1MasterSetCR2reg(uint16_t add, char addbit[5], char rw[2], char autoend[9], char reload[8], char pecb[7], uint8_t size);
//uint8_t I2C2MasterSetCR2reg(uint16_t add, char addbit[5], char rw[2], char autoend[9], char reload[8], char pecb[7], uint8_t size);


//uint8_t I2C1MasterWriteSingleByte(uint16_t add, uint8_t data, char addbit[5], char autoend[9]);
//uint8_t I2C1MasterReadSingleByte(uint16_t add, char addbit[5], char autoend[9]);
//uint8_t I2C2MasterWriteSingleByte(uint16_t add, uint8_t data, char addbit[5], char autoend[9]);
//uint8_t I2C2MasterReadSingleByte(uint16_t add, char addbit[5], char autoend[9]);


//void I2C1SetStart(void);
//void I2C1SetStop(void);
//void I2C1SetReload(void);
//void I2C2SetStart(void);
//void I2C2SetStop(void);
//void I2C2SetReload(void);

//uint8_t I2C1MasterSetCR1reg(char anfoff[6], unsigned int dnf, char stretch[9], uint32_t timingreg, char txie[6], char rxie[6], char addrie[8], char nackie[8], char stopie[8], char tcie[6],  char errie[7])
//{	
//	// Configuring the I2C control registers
//	I2C1->CR1 &= ~I2C_CR1_PE; // Disable PE bit to configure the I2C registers
//	while((I2C1->CR1 & I2C_CR1_PE)); // Checking if the PE bit is reset
//	I2C1->CR1 |= (dnf << I2C_CR1_DNF_Pos ); // seting the DNF field
//	if(strcmp(anfoff, "ANFOFF") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_ANFOFF; // Disable ANFOFF bit to turn analog filter on
//	}
//	else if (strcmp(anfoff, "ANFON") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_ANFOFF; // Enable ANFOFF bit to turn analog filter on
//	}
//	if(strcmp(stretch, "STRETCH") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_NOSTRETCH; // NOSTRETCH must be dissabled in master mode
//	}
//	else if (strcmp(stretch, "NOSTRETCH") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_NOSTRETCH; // NOSTRETCH must be dissabled in master mode
//	}
//	if(strcmp(txie, "TXIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_TXIE; // The TX interupt is enabled
//	}
//	else if (strcmp(txie, "NOTXIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_TXIE; // The TX interupt is dissabeled
//	}
//	if(strcmp(rxie, "RXIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_RXIE; // The RX interupt is enabled
//	}
//	else if (strcmp(rxie, "NORXIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_RXIE; // The RX interupt is dissabeled
//	}
//	if(strcmp(addrie, "ADDRIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_ADDRIE; // The address match interupt is enabled
//	}
//	else if (strcmp(addrie, "NOADDRIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_ADDRIE; // The address match interupt is dissabeled
//	}
//	if(strcmp(nackie, "NACKIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_NACKIE; // The not acknowledge recieved interupt is enabled
//	}
//	else if (strcmp(nackie, "NONACKIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_NACKIE; // The not acknowledge recieved interupt is dissabeled
//	}
//	if(strcmp(stopie, "STOPIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_STOPIE; // The stop detection interupt is enabled
//	}
//	else if (strcmp(stopie, "NOSTOPIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_STOPIE; // The stop detection interupt is dissabeled
//	}
//	if(strcmp(tcie, "TCIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_TCIE; // The transfer complete interupt is enabled
//	}
//	else if (strcmp(tcie, "NOTCIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_TCIE; // The transfer complete interupt is dissabeled
//	}
//	if(strcmp(errie, "ERRIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_ERRIE; // The error interupt is enabled
//	}
//	else if (strcmp(errie, "NOERRIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_ERRIE; // The error interupt is dissabeled
//	}
//// Configuring the timing register with data from the CubeMX software, calculated value is 0x2000090E
//	I2C1->TIMINGR = timingreg; // Setting the value of TIMINGR
//	I2C1->CR1 |= I2C_CR1_PE; // After initial configuration the PE bit is activated
//	while(!(I2C1->CR1 & I2C_CR1_PE));
//	return 1;
//}

//uint8_t I2C2MasterSetCR1reg(char anfoff[6], unsigned int dnf, char stretch[9], uint32_t timingreg, char txie[6], char rxie[6], char addrie[8], char nackie[8], char stopie[8], char tcie[6],  char errie[7])
//{
//	// Configuring the I2C control registers
//	I2C2->CR1 &= ~I2C_CR1_PE; // Disable PE bit to configure the I2C registers
//	while((I2C2->CR1 & I2C_CR1_PE));
//	I2C2->CR1 |= (dnf << I2C_CR1_DNF_Pos ); // seting the DNF field
//	if(strcmp(anfoff, "ANFOFF") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_ANFOFF; // Disable ANFOFF bit to turn analog filter on
//	}
//	else if (strcmp(anfoff, "ANFON") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_ANFOFF; // Enable ANFOFF bit to turn analog filter on
//	}
//	if(strcmp(stretch, "STRETCH") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_NOSTRETCH; // NOSTRETCH must be dissabled in master mode
//	}
//	else if (strcmp(stretch, "NOSTRETCH") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_NOSTRETCH; // NOSTRETCH must be dissabled in master mode
//	}
//	if(strcmp(txie, "TXIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_TXIE; // The TX interupt is enabled
//	}
//	else if (strcmp(txie, "NOTXIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_TXIE; // The TX interupt is dissabeled
//	}
//	if(strcmp(rxie, "RXIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_RXIE; // The RX interupt is enabled
//	}
//	else if (strcmp(rxie, "NORXIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_RXIE; // The RX interupt is dissabeled
//	}
//	if(strcmp(addrie, "ADDRIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_ADDRIE; // The address match interupt is enabled
//	}
//	else if (strcmp(addrie, "NOADDRIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_ADDRIE; // The address match interupt is dissabeled
//	}
//	if(strcmp(nackie, "NACKIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_NACKIE; // The not acknowledge recieved interupt is enabled
//	}
//	else if (strcmp(nackie, "NONACKIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_NACKIE; // The not acknowledge recieved interupt is dissabeled
//	}
//	if(strcmp(stopie, "STOPIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_STOPIE; // The stop detection interupt is enabled
//	}
//	else if (strcmp(stopie, "NOSTOPIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_STOPIE; // The stop detection interupt is dissabeled
//	}
//	if(strcmp(tcie, "TCIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_TCIE; // The transfer complete interupt is enabled
//	}
//	else if (strcmp(tcie, "NOTCIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_TCIE; // The transfer complete interupt is dissabeled
//	}
//	if(strcmp(errie, "ERRIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_ERRIE; // The error interupt is enabled
//	}
//	else if (strcmp(errie, "NOERRIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_ERRIE; // The error interupt is dissabeled
//	}
//// Configuring the timing register with data from the CubeMX software, calculated value is 0x2000090E
//	I2C2->TIMINGR = timingreg; // Setting the value of TIMINGR
//	I2C2->CR1 |= I2C_CR1_PE; // After initial configuration the PE bit is activated
//	while(!(I2C2->CR1 & I2C_CR1_PE)); // Checking if the PE bit is set
//	return 1;
//}

//uint8_t I2C1MasterSetCR2reg(uint16_t add,  char addbit[5], char rw[2], char autoend[9], char reload[8], char pecb[7], uint8_t size)
//{
//	if(strcmp(addbit, "7BIT") == 0)
//	{
//		I2C1->CR2 &= ~I2C_CR2_ADD10; // Seting the address mode to a 7 bit address
//		I2C1->CR2 |= ( add << 1 ); // Write the address in the CR2 register and leftshift the address for 1 bit
//	}
//	else if(strcmp(addbit, "10BIT") == 0)
//	{
//		I2C1->CR2 |= I2C_CR2_ADD10; // Seting the address mode to a 10 bit address
////		I2C2->CR2 &= ~I2C_CR2_HEAD10R; // Sending the entire 10 bit address
//		I2C1->CR2 |= ( add << I2C_CR2_SADD_Pos ); // Write the address in the CR2 register and leftshift the address for 1 bit
//	}
//	if(strcmp(rw, "RE") == 0)
//	{
//		I2C1->CR2 |= I2C_CR2_RD_WRN; // Transmiting (0) to the slave or recieving (1)
//	}
//	else if(strcmp(rw, "WR") == 0)
//	{
//		I2C1->CR2 &= ~I2C_CR2_RD_WRN; // Transmiting (0) to the slave or recieving (1)
//	}
//	if(strcmp(reload, "RELOAD") == 0)
//	{
//		I2C1->CR2 |= I2C_CR2_RELOAD ; // Set the RELOAD value to 1
//	}
//	else if(strcmp(reload, "NORELOAD") == 0)
//	{
//		I2C1->CR2 &= ~I2C_CR2_RELOAD ; // Set the RELOAD value to 0
//	}
//	if(strcmp(autoend, "AUTOEND") == 0)
//	{
//		I2C1->CR2 |= I2C_CR2_AUTOEND; // AUTOEND when is set (1) it sets the STOP condition automaticaly if NBYTES are transmited
//	}
//	else if(strcmp(autoend, "NOAUTOEND") == 0)
//	{
//		I2C1->CR2 &= ~I2C_CR2_AUTOEND; // AUTOEND when is set (1) it sets the STOP condition automaticaly if NBYTES are transmited
//	}
//	if(strcmp(pecb, "PECBY") == 0)
//	{
//		I2C1->CR2 |= I2C_CR2_PECBYTE; // Turning the packet error control byte on 
//	}
//	else if(strcmp(pecb, "NOPECBY") == 0)
//	{
//		I2C1->CR2 &= ~I2C_CR2_PECBYTE; // Turning the packet error control byte off
//	}
//	I2C1->CR2 |= ( size << I2C_CR2_NBYTES_Pos ); // Set the NBYTES value to the byte size of the transmited packet
//	return 1;
//}

//uint8_t I2C2MasterSetCR2reg(uint16_t add,  char addbit[5], char rw[2], char autoend[9], char reload[8], char pecb[7], uint8_t size)
//{
//	if(strcmp(addbit, "7BIT") == 0)
//	{
//		I2C2->CR2 &= ~I2C_CR2_ADD10; // Seting the address mode to a 7 bit address
//		I2C2->CR2 |= ( add << 1 ); // Write the address in the CR2 register and leftshift the address for 1 bit
//	}
//	else if(strcmp(addbit, "10BIT") == 0)
//	{
//		I2C2->CR2 |= I2C_CR2_ADD10; // Seting the address mode to a 10 bit address
////		I2C2->CR2 &= ~I2C_CR2_HEAD10R; // Sending the entire 10 bit address
//		I2C2->CR2 |= ( add << I2C_CR2_SADD_Pos ); // Write the address in the CR2 register and leftshift the address for 1 bit
//	}
//	if(strcmp(rw, "RE") == 0)
//	{
//		I2C2->CR2 |= I2C_CR2_RD_WRN; // Transmiting (0) to the slave or recieving (1)
//	}
//	else if(strcmp(rw, "WR") == 0)
//	{
//		I2C2->CR2 &= ~I2C_CR2_RD_WRN; // Transmiting (0) to the slave or recieving (1)
//	}
//	if(strcmp(reload, "RELOAD") == 0)
//	{
//		I2C2->CR2 |= I2C_CR2_RELOAD ; // Set the RELOAD value to 1
//	}
//	else if(strcmp(reload, "NORELOAD") == 0)
//	{
//		I2C2->CR2 &= ~I2C_CR2_RELOAD ; // Set the RELOAD value to 0
//	}
//	if(strcmp(autoend, "AUTOEND") == 0)
//	{
//		I2C2->CR2 |= I2C_CR2_AUTOEND; // AUTOEND when is set (1) it sets the STOP condition automaticaly if NBYTES are transmited
//	}
//	else if(strcmp(autoend, "NOAUTOEND") == 0)
//	{
//		I2C2->CR2 &= ~I2C_CR2_AUTOEND; // AUTOEND when is set (1) it sets the STOP condition automaticaly if NBYTES are transmited
//	}
//	if(strcmp(pecb, "PECBY") == 0)
//	{
//		I2C2->CR2 |= I2C_CR2_PECBYTE; // Turning the packet error control byte on 
//	}
//	else if(strcmp(pecb, "NOPECBY") == 0)
//	{
//		I2C2->CR2 &= ~I2C_CR2_PECBYTE; // Turning the packet error control byte off
//	}
//	I2C2->CR2 |= ( size << I2C_CR2_NBYTES_Pos ); // Set the NBYTES value to the byte size of the transmited packet
//	return 1;
//}

//uint8_t I2C1MasterWriteSingleByte(uint16_t add, uint8_t data, char addbit[5], char autoend[9])
//{
//	uint8_t CRok = 0; 
//	CRok = I2C1MasterSetCR2reg(add, addbit, "WR", autoend, "NORELOAD", "NOPECBY", 1); // Calling the function for setting the CR2 register values
//	I2C1SetStart(); // Setting the start condition
//	I2C1->TXDR = data; // Write data to the data transmmit register
//	while(!(I2C1->ISR & I2C_ISR_TXE)); // Check if data was sent from TXDR register by AND-ing the value of the ISR register and the TXE bit if value is 1 its then NOT-ed by the ! to give a 0 and the while loop is exited
//	I2C1SetStop(); // Setting the stop condition
//	return 1; // Return for successful writing
//}

//uint8_t I2C1MasterReadSingleByte(uint16_t add, char addbit[5], char autoend[9])
//{
//	uint8_t data;
//	uint8_t CRok = 0;
//	CRok = I2C1MasterSetCR2reg(add,  addbit, "RE", autoend, "NORELOAD", "NOPECBY", 1); // Calling the function for setting the CR2 register values
//	I2C1SetStart(); // Setting the start condition
//	while(!( I2C1->ISR & I2C_ISR_RXNE )); // Checking if data to be read is recieved in the RXDR register
//	data = I2C1->RXDR; // Reading data that is in the RXDR register
//	I2C1SetStop(); // Setting the stop condition
//	return data; // Return read data
//}
//uint8_t I2C2MasterWriteSingleByte(uint16_t add, uint8_t data, char addbit[5], char autoend[9])
//{
//	uint8_t CRok = 0;
//	CRok = I2C2MasterSetCR2reg(add, addbit, "WR", autoend, "NORELOAD", "NOPECBY", 1); // Calling the function for setting the CR2 register values
//	I2C2SetStart(); // Setting the start condition
//	I2C2->TXDR = data; // Write data to the data transmmit register
//	while(!(I2C2->ISR & I2C_ISR_TXE)); // Check if data was sent from TXDR register by AND-ing the value of the ISR register and the TXE bit if value is 1 its then NOT-ed by the ! to give a 0 and the while loop is exited
//	I2C2SetStop(); // Setting the stop condition
//	return 1; // Return for successful writing
//}
//uint8_t I2C2MasterReadSingleByte(uint16_t add, char addbit[5], char autoend[9])
//{
//	uint8_t data;
//	uint8_t CRok = 0;
//	CRok = I2C2MasterSetCR2reg(add,  addbit, "RE", autoend, "NORELOAD", "NOPECBY", 1); // Calling the function for setting the CR2 register values
//	I2C2SetStart(); // Setting the start condition
//	while(!( I2C2->ISR & I2C_ISR_RXNE )); // Checking if data to be read is recieved in the RXDR register
//	data = I2C2->RXDR; // Reading data that is in the RXDR register
//	I2C2SetStop(); // Setting the stop condition
//	return data; // Return read data
//}

//void I2C1SetStart(void)
//{
//	I2C1->CR2 |= I2C_CR2_START; // Establishing start condition
//	while(I2C1->CR2 & I2C_CR2_START); // Checking that start condition was established succesfully
//}

//void I2C1SetStop(void)
//{
//	I2C1->CR2 |= I2C_CR2_STOP; // Establishing stop condition
//	while(I2C1->CR2 & I2C_CR2_STOP); // Checking that the stop condition was established succesfully
//}

//void I2C1SetReload(void)
//{
//	I2C1->CR2 |= I2C_CR2_RELOAD; // Seting the reload bit
//	while(I2C1->CR2 & I2C_CR2_RELOAD); // Checking that the reload bit was established succesfully
//}

//void I2C2SetStart(void)
//{
//	I2C2->CR2 |= I2C_CR2_START; // Establishing start condition
//	while(I2C2->CR2 & I2C_CR2_START); // Checking that the start condition was established succesfully
//}

//void I2C2SetStop(void)
//{
//	I2C2->CR2 |= I2C_CR2_STOP; // Establishing stop condition
//	while(I2C2->CR2 & I2C_CR2_STOP); // Checking that the stop condition was established succesfully
//}
//void I2C2SetReload(void)
//{
//	I2C2->CR2 |= I2C_CR2_RELOAD; // Seting the reload bit
//	while(I2C2->CR2 & I2C_CR2_RELOAD); // Checking that the reload bit was established succesfully
//}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Setting up the slave////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//uint8_t I2C1SlaveSetCR1reg(uint8_t add1, char mode[6], char oa1en[7], uint8_t add2, uint8_t add2mask, char oa2en[7],
//														char anfoff[6], unsigned int dnf, char gcen[6], char strch[9], char sbc[5], char wupen[5],
//														char txie[6], char rxie[6], char addrie[8], char nackie[8], char stopie[8], char tcie[6],  
//														char errie[7]);
//uint8_t I2C2SlaveSetCR1reg(uint8_t add1, char mode[6], char oa1en[7], uint8_t add2, uint8_t add2mask, char oa2en[7],
//														char anfoff[6], unsigned int dnf, char gcen[6], char strch[9], char sbc[5], char wupen[5],
//														char txie[6], char rxie[6], char addrie[8], char nackie[8], char stopie[8], char tcie[6],  
//														char errie[7]);


//void I2C1SetAckNacks(char nAck[4]);
//void I2C2SetAckNacks(char nAck[4]);


//uint8_t I2C1SlaveSetCR1reg(uint8_t add1, char mode[6], char oa1en[7], uint8_t add2, uint8_t add2mask, char oa2en[7],
//														char anfoff[6], unsigned int dnf, char gcen[6], char strch[9], char sbc[5], char wupen[5],
//														char txie[6], char rxie[6], char addrie[8], char nackie[8], char stopie[8], char tcie[6],  
//														char errie[7])
//{
//// Configuring the main address register OAR1
//	I2C1->OAR1 &= ~I2C_OAR1_OA1EN;
//	if(strcmp(mode, "MODE7") == 0)
//	{
//		I2C1->OAR1 &= ~I2C_OAR1_OA1MODE;
//	}
//	else if(strcmp(mode, "MODE10") == 0)
//	{
//		I2C1->OAR1 |= I2C_OAR1_OA1MODE;
//	}
//	I2C1->OAR1 |= (add1 << 1);
//	if(strcmp(oa1en, "OA1EN") == 0)
//	{
//		I2C1->OAR1 |= I2C_OAR1_OA1EN;
//	}	
////Configuring the second slave address register OAR2
//	I2C1->OAR2 &= ~I2C_OAR2_OA2EN;
//	I2C1->OAR2 |= (add2 << 1);
//	I2C1->OAR1 |= (add2mask << 8);
//	if(strcmp(oa2en, "OA1EN") == 0)
//	{
//		I2C1->OAR2 |= I2C_OAR2_OA2EN;
//	}	
////Configuring the CR1 Register
//	I2C1->CR1 &= ~I2C_CR1_PE; // Disable PE bit to configure the I2C registers
//	while((I2C1->CR1 & I2C_CR1_PE));
//	I2C1->CR1 |= (dnf << I2C_CR1_DNF_Pos ); // seting the DNF field
//	if(strcmp(anfoff, "ANFOFF") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_ANFOFF; // Disable ANFOFF bit to turn analog filter on
//	}
//	else if (strcmp(anfoff, "ANFON") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_ANFOFF; // Enable ANFOFF bit to turn analog filter on
//	}
//	if(strcmp(gcen, "GCEN") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_GCEN;
//	}
//	else if(strcmp(gcen, "NOGCEN") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_GCEN;
//	}
//	if(strcmp(strch, "NOSTRETCH") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_NOSTRETCH;
//	}
//	else if(strcmp(strch, "STRETCH") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_NOSTRETCH;
//	}
//	if(strcmp(sbc, "SBC") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_SBC;
//	}
//	else if(strcmp(sbc, "NOSBC") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_SBC;
//	}
//	if(strcmp(wupen, "WUPEN") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_WUPEN;
//	}
//	else if(strcmp(wupen, "NOWUPEN") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_WUPEN;
//	}
//	if(strcmp(txie, "TXIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_TXIE; // The TX interupt is enabled
//	}
//	else if (strcmp(txie, "NOTXIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_TXIE; // The TX interupt is dissabeled
//	}
//	if(strcmp(rxie, "RXIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_RXIE; // The RX interupt is enabled
//	}
//	else if (strcmp(rxie, "NORXIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_RXIE; // The RX interupt is dissabeled
//	}
//	if(strcmp(addrie, "ADDRIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_ADDRIE; // The address match interupt is enabled
//	}
//	else if (strcmp(addrie, "NOADDRIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_ADDRIE; // The address match interupt is dissabeled
//	}
//	if(strcmp(nackie, "NACKIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_NACKIE; // The not acknowledge recieved interupt is enabled
//	}
//	else if (strcmp(nackie, "NONACKIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_NACKIE; // The not acknowledge recieved interupt is dissabeled
//	}
//	if(strcmp(stopie, "STOPIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_STOPIE; // The stop detection interupt is enabled
//	}
//	else if (strcmp(stopie, "NOSTOPIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_STOPIE; // The stop detection interupt is dissabeled
//	}
//	if(strcmp(tcie, "TCIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_TCIE; // The transfer complete interupt is enabled
//	}
//	else if (strcmp(tcie, "NOTCIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_TCIE; // The transfer complete interupt is dissabeled
//	}
//	if(strcmp(errie, "ERRIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_ERRIE; // The error interupt is enabled
//	}
//	else if (strcmp(errie, "NOERRIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_ERRIE; // The error interupt is dissabeled
//	}
//	I2C1->CR1 |= I2C_CR1_PE; // After initial configuration the PE bit is activated
//	while(!(I2C1->CR1 & I2C_CR1_PE));
//	return 1;
//}

//uint8_t I2C2SlaveSetCR1reg(uint8_t add1, char mode[6], char oa1en[7], uint8_t add2, uint8_t add2mask, char oa2en[7],
//														char anfoff[6], unsigned int dnf, char gcen[6], char strch[9], char sbc[5], char wupen[5],
//														char txie[6], char rxie[6], char addrie[8], char nackie[8], char stopie[8], char tcie[6],  
//														char errie[7])
//{
//// Configuring the main address register OAR1
//	I2C2->OAR1 &= ~I2C_OAR1_OA1EN;
//	if(strcmp(mode, "MODE7") == 0)
//	{
//		I2C2->OAR1 &= ~I2C_OAR1_OA1MODE;
//	}
//	else if(strcmp(mode, "MODE10") == 0)
//	{
//		I2C2->OAR1 |= I2C_OAR1_OA1MODE;
//	}
//	I2C2->OAR1 |= (add1 << 1);
//	if(strcmp(oa1en, "OA1EN") == 0)
//	{
//		I2C2->OAR1 |= I2C_OAR1_OA1EN;
//	}	
////Configuring the second slave address register OAR2
//	I2C2->OAR2 &= ~I2C_OAR2_OA2EN;
//	I2C2->OAR2 |= (add2 << 1);
//	I2C2->OAR1 |= (add2mask << 8);
//	if(strcmp(oa2en, "OA1EN") == 0)
//	{
//		I2C2->OAR2 |= I2C_OAR2_OA2EN;
//	}	
////Configuring the CR1 Register
//	I2C2->CR1 &= ~I2C_CR1_PE; // Disable PE bit to configure the I2C registers
//	while((I2C2->CR1 & I2C_CR1_PE));
//	I2C2->CR1 |= (dnf << I2C_CR1_DNF_Pos ); // seting the DNF field
//	if(strcmp(anfoff, "ANFOFF") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_ANFOFF; // Disable ANFOFF bit to turn analog filter on
//	}
//	else if (strcmp(anfoff, "ANFON") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_ANFOFF; // Enable ANFOFF bit to turn analog filter on
//	}
//	if(strcmp(gcen, "GCEN") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_GCEN;
//	}
//	else if(strcmp(gcen, "NOGCEN") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_GCEN;
//	}
//	if(strcmp(strch, "NOSTRETCH") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_NOSTRETCH;
//	}
//	else if(strcmp(strch, "STRETCH") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_NOSTRETCH;
//	}
//	if(strcmp(sbc, "SBC") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_SBC;
//	}
//	else if(strcmp(sbc, "NOSBC") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_SBC;
//	}
//	if(strcmp(wupen, "WUPEN") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_WUPEN;
//	}
//	else if(strcmp(wupen, "NOWUPEN") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_WUPEN;
//	}
//	if(strcmp(txie, "TXIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_TXIE; // The TX interupt is enabled
//	}
//	else if (strcmp(txie, "NOTXIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_TXIE; // The TX interupt is dissabeled
//	}
//	if(strcmp(rxie, "RXIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_RXIE; // The RX interupt is enabled
//	}
//	else if (strcmp(rxie, "NORXIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_RXIE; // The RX interupt is dissabeled
//	}
//	if(strcmp(addrie, "ADDRIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_ADDRIE; // The address match interupt is enabled
//	}
//	else if (strcmp(addrie, "NOADDRIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_ADDRIE; // The address match interupt is dissabeled
//	}
//	if(strcmp(nackie, "NACKIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_NACKIE; // The not acknowledge recieved interupt is enabled
//	}
//	else if (strcmp(nackie, "NONACKIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_NACKIE; // The not acknowledge recieved interupt is dissabeled
//	}
//	if(strcmp(stopie, "STOPIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_STOPIE; // The stop detection interupt is enabled
//	}
//	else if (strcmp(stopie, "NOSTOPIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_STOPIE; // The stop detection interupt is dissabeled
//	}
//	if(strcmp(tcie, "TCIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_TCIE; // The transfer complete interupt is enabled
//	}
//	else if (strcmp(tcie, "NOTCIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_TCIE; // The transfer complete interupt is dissabeled
//	}
//	if(strcmp(errie, "ERRIE") == 0)
//	{
//		I2C2->CR1 |= I2C_CR1_ERRIE; // The error interupt is enabled
//	}
//	else if (strcmp(errie, "NOERRIE") == 0)
//	{
//		I2C2->CR1 &= ~I2C_CR1_ERRIE; // The error interupt is dissabeled
//	}
//	I2C2->CR1 |= I2C_CR1_PE; // After initial configuration the PE bit is activated
//	while(!(I2C2->CR1 & I2C_CR1_PE));
//	return 1;
//}


















//void I2C2SetAckNacks(char nAck[4])
//{
//	if(strcmp(nAck, "ACK") == 0)
//	{
//		I2C2->CR2 &= ~I2C_CR2_NACK; // Establishing ACK condition
//		while(!(I2C2->CR2 & I2C_CR2_NACK)); // Checking that the ACK condition was established succesfully
//	}
//	else if(strcmp(nAck, "NACK") == 0)
//	{
//		I2C2->CR2 |= I2C_CR2_NACK; // Establishing NACK condition
//		while(I2C2->CR2 & I2C_CR2_NACK); // Checking that the NACK condition was established succesfully
//	}
//}

//void I2C1SetAckNacks(char nAck[4])
//{
//	if(strcmp(nAck, "ACK") == 0)
//	{
//		I2C1->CR2 &= ~I2C_CR2_NACK; // Establishing ACK condition
//		while(!(I2C1->CR2 & I2C_CR2_NACK)); // Checking that the ACK condition was established succesfully
//	}
//	else if(strcmp(nAck, "NACK") == 0)
//	{
//		I2C1->CR2 |= I2C_CR2_NACK; // Establishing NACK condition
//		while(I2C1->CR2 & I2C_CR2_NACK); // Checking that the NACK condition was established succesfully
//	}
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Setting up the CR1, CR2, OAR1, OAR2 registers///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//uint8_t I2C1SetCR1reg(char anfoff[10], unsigned int dnf, uint32_t time, char txdma[10], char rxdma[10], char sbc[10], char nostrch[10], 
//											char wupen[10], char gcen[10], char smbhen[10], char smbden[10], char alerten[10], char pecen[10],			
//											char txie[10], char rxie[10], char addrie[10], char nackie[10], char stopie[10], char tcie[10],	
//											char errie[10]);
//uint8_t I2C1SetTIMINGR(uint32_t time);
//uint8_t I2C1SetCR2reg(uint16_t add, uint8_t size, char rdwr[10], char add10[10], char head10r[10], char autoend[10], char pecbyt[10]);
//uint8_t I2C1SetOAR1reg(uint16_t sadd1,  char mode[10], char oa1en[10]);
//uint8_t I2C1SetOAR2reg(uint8_t sadd2, uint8_t mask, char oa2en[10]);


//uint8_t I2C1SetCR1reg(char anfoff[10], unsigned int dnf, uint32_t time, char txdma[10], char rxdma[10], char sbc[10], char nostrch[10], 
//											char wupen[10], char gcen[10], char smbhen[10], char smbden[10], char alerten[10], char pecen[10],			
//											char txie[10], char rxie[10], char addrie[10], char nackie[10], char stopie[10], char tcie[10],	
//											char errie[10])
//{
//	//Configuring the CR1 Register
//	I2C1->CR1 &= ~I2C_CR1_PE; // Disable PE bit to configure the I2C registers
//	while((I2C1->CR1 & I2C_CR1_PE));
//	I2C1->CR1 |= (dnf << I2C_CR1_DNF_Pos ); // seting the DNF field
//	if(strcmp(anfoff, "ANFOFF") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_ANFOFF; // Disable ANFOFF bit to turn analog filter on
//	}
//	else if (strcmp(anfoff, "ANFON") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_ANFOFF; // Enable ANFOFF bit to turn analog filter on
//	}
//	if(strcmp(txdma, "TXDMA") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_TXDMAEN;
//	}
//	else if(strcmp(txdma, "NOTXDMA") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_TXDMAEN;
//	}
//	if(strcmp(rxdma, "RXDMA") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_RXDMAEN;
//	}
//	else if(strcmp(rxdma, "NORXDMA") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_RXDMAEN;
//	}
//	if(strcmp(sbc, "SBC") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_SBC;
//	}
//	else if(strcmp(sbc, "NOSBC") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_SBC;
//	}
//	if(strcmp(nostrch, "NOSTRETCH") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_NOSTRETCH;
//	}
//	else if(strcmp(nostrch, "STRETCH") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_NOSTRETCH;
//	}
//	if(strcmp(wupen, "WUPEN") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_WUPEN;
//	}
//	else if(strcmp(wupen, "NOWUPEN") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_WUPEN;
//	}
//	if(strcmp(gcen, "GCEN") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_GCEN;
//	}
//	else if(strcmp(gcen, "NOGCEN") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_GCEN;
//	}
//	if(strcmp(smbhen, "SMBH") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_SMBHEN;
//	}
//	else if(strcmp(smbhen, "NOSMBH") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_SMBHEN;
//	}
//	if(strcmp(smbden, "SMBD") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_SMBDEN;
//	}
//	else if(strcmp(smbden, "NOSMBD") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_SMBDEN;
//	}
//	if(strcmp(alerten, "ALERT") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_ALERTEN;
//	}
//	else if(strcmp(alerten, "NOALERT") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_ALERTEN;
//	}
//	if(strcmp(pecen, "PECEN") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_PECEN;
//	}
//	else if(strcmp(pecen, "NOPECEN") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_PECEN;
//	}
//	if(strcmp(txie, "TXIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_TXIE; // The TX interupt is enabled
//	}
//	else if (strcmp(txie, "NOTXIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_TXIE; // The TX interupt is dissabeled
//	}
//	if(strcmp(rxie, "RXIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_RXIE; // The RX interupt is enabled
//	}
//	else if (strcmp(rxie, "NORXIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_RXIE; // The RX interupt is dissabeled
//	}
//	if(strcmp(addrie, "ADDRIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_ADDRIE; // The address match interupt is enabled
//	}
//	else if (strcmp(addrie, "NOADDRIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_ADDRIE; // The address match interupt is dissabeled
//	}
//	if(strcmp(nackie, "NACKIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_NACKIE; // The not acknowledge recieved interupt is enabled
//	}
//	else if (strcmp(nackie, "NONACKIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_NACKIE; // The not acknowledge recieved interupt is dissabeled
//	}
//	if(strcmp(stopie, "STOPIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_STOPIE; // The stop detection interupt is enabled
//	}
//	else if (strcmp(stopie, "NOSTOPIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_STOPIE; // The stop detection interupt is dissabeled
//	}
//	if(strcmp(tcie, "TCIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_TCIE; // The transfer complete interupt is enabled
//	}
//	else if (strcmp(tcie, "NOTCIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_TCIE; // The transfer complete interupt is dissabeled
//	}
//	if(strcmp(errie, "ERRIE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR1_ERRIE; // The error interupt is enabled
//	}
//	else if (strcmp(errie, "NOERRIE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR1_ERRIE; // The error interupt is dissabeled
//	}
//	uint8_t timingrOk = I2C1SetTIMINGR(time);
//	I2C1->CR1 |= I2C_CR1_PE; // After initial configuration the PE bit is activated
//	while(!(I2C1->CR1 & I2C_CR1_PE));

//	return 1;
//}
//uint8_t I2C1SetTIMINGR(uint32_t time)
//{
//// Configuring the timing register with data from the CubeMX software, calculated value is 0x2000090E
//	I2C1->TIMINGR = time; // Setting the value of TIMINGR
//	return 1;
//}
//uint8_t I2C1SetCR2reg(uint16_t add, uint8_t size, char rdwr[10], char add10[10], char head10r[10], char autoend[10], char pecbyt[10])
//{
//	if(strcmp(add10, "ADD7BIT") == 0)
//	{
//		I2C1->CR2 &= ~I2C_CR2_ADD10; // Seting the address mode to a 7 bit address
//		I2C1->CR2 |= ( add << 1 ); // Write the address in the CR2 register and leftshift the address for 1 bit
//	}
//	else if(strcmp(add10, "ADD10BIT") == 0)
//	{
//		I2C1->CR2 |= I2C_CR2_ADD10; // Seting the address mode to a 10 bit address
//		if(strcmp(head10r, "NOHEAD10R") == 0)
//		{
//			I2C1->CR1 |= I2C_CR2_HEAD10R; // The stop detection interupt is enabled
//		}
//		else if (strcmp(head10r, "HEAD10R") == 0)
//		{
//			I2C1->CR1 &= ~I2C_CR2_HEAD10R; // The stop detection interupt is dissabeled
//		}
//		I2C1->CR2 |= ( add << I2C_CR2_SADD_Pos ); // Write the address in the CR2 register and leftshift the address for 1 bit
//	}
//	I2C1->CR2 |= ( size << I2C_CR2_NBYTES_Pos ); // Set the NBYTES value to the byte size of the transmited packet	
//	if(strcmp(rdwr, "READ") == 0)
//	{
//		I2C1->CR1 |= I2C_CR2_RD_WRN; 
//	}
//	else if (strcmp(rdwr, "WRITE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR2_RD_WRN; 
//	}
//	if(strcmp(autoend, "AUTOEND") == 0)
//	{
//		I2C1->CR1 |= I2C_CR2_AUTOEND; 
//	}
//	else if (strcmp(autoend, "NOAUTOEND") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR2_AUTOEND; 
//	}
//	if(strcmp(pecbyt, "PECBYTE") == 0)
//	{
//		I2C1->CR1 |= I2C_CR2_PECBYTE; 
//	}
//	else if (strcmp(pecbyt, "NOPECBYTE") == 0)
//	{
//		I2C1->CR1 &= ~I2C_CR2_PECBYTE; 
//	}
//	return 1;
//}
//uint8_t I2C1SetOAR1reg(uint16_t sadd1,  char mode[10], char oa1en[10])
//{
//	// Configuring the main address register OAR1
//	I2C2->OAR1 &= ~I2C_OAR1_OA1EN;
//	if(strcmp(mode, "MODE7") == 0)
//	{
//		I2C2->OAR1 &= ~I2C_OAR1_OA1MODE;
//	}
//	else if(strcmp(mode, "MODE10") == 0)
//	{
//		I2C2->OAR1 |= I2C_OAR1_OA1MODE;
//	}
//	I2C2->OAR1 |= (sadd1 << 1);
//	if(strcmp(oa1en, "OA1EN") == 0)
//	{
//		I2C2->OAR1 |= I2C_OAR1_OA1EN;
//	}	
//	return 1;
//}
//uint8_t I2C1SetOAR2reg(uint8_t sadd2, uint8_t mask, char oa2en[10])
//{
////Configuring the second slave address register OAR2
//	I2C2->OAR2 &= ~I2C_OAR2_OA2EN;
//	I2C2->OAR2 |= (sadd2 << 1);
//	I2C2->OAR1 |= (mask << 8);
//	if(strcmp(oa2en, "OA1EN") == 0)
//	{
//		I2C2->OAR2 |= I2C_OAR2_OA2EN;
//	}	
//	return 1;
//}
//	