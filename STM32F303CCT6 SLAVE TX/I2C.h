# include "stm32f303xc.h"

uint8_t I2C2Init(char pupdr[10], char i2csw[10]);

uint8_t I2C2SetCR1reg(char anfoff[10], unsigned int dnf, uint32_t time, char txdma[10], char rxdma[10], char sbc[10], char nostrch[10], 
											char wupen[10], char gcen[10], char smbhen[10], char smbden[10], char alerten[10], char pecen[10],			
											char txie[10], char rxie[10], char addrie[10], char nackie[10], char stopie[10], char tcie[10],	
											char errie[10]);
											
uint8_t I2C2SetTIMINGR(uint32_t time);
											
uint8_t I2C2SetCR2reg(uint16_t add, uint8_t size, char rdwr[10], char add10[10], char head10r[10], char autoend[10], char pecbyt[10]);
											
uint8_t I2C2SetOAR1reg(uint16_t sadd1,  char mode[10], char oa1en[10]);
											
uint8_t I2C2SetOAR2reg(uint8_t sadd2, uint8_t mask, char oa2en[10]);
											
void I2C2ClearISR(void);
											
void I2C2SetStart(void);
											
void I2C2SetStop(void);
											
void I2C2SetReload(char reload[10]);	
											
void I2C2SetAckNacks(char nAck[4]);
											
uint8_t I2C2MasterInit(char pupdr[10], char i2csw[10], char anfoff[10], unsigned int dnf, uint32_t time, 
												char txie[10], char rxie[10], char addrie[10], char nackie[10], char stopie[10], 
												char tcie[10],  char errie[10]);
												
uint8_t I2C2MasterWriteSingleByte(uint16_t add, uint8_t data, char addbit[10], char autoend[10]);
												
uint8_t I2C2MasterReadSingleByte(uint16_t add, char addbit[10], char autoend[10]);
												
uint8_t I2C2SlaveInit(char pupdr[10], char i2csw[10], uint16_t sadd1, char  oar1mode[10], char oa1en[10], 
											uint8_t sadd2, uint8_t oar2mask, char oa2en[10], char anfoff[10], unsigned int dnf, 
											char sbc[10], char nostrch[10], char gcen[10], char txie[10], char rxie[10], 
											char addrie[10], char nackie[10], char stopie[10], char tcie[10],  char errie[10]);
												
uint8_t I2C2SlaveReadWriteSingleByte(uint8_t dataTx, uint8_t oadd, char txrx[5]);
											
uint8_t * I2C2SlaveReadWriteMultipleByte(uint8_t dataTx[], uint32_t size, uint8_t oadd, char txrx[5]);

uint8_t * I2C2MasterReadWriteMultiple(uint8_t add, uint8_t data[], uint32_t size, char rw[5], char addbit[10], char autoend[10]);














											