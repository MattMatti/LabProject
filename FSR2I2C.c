//This code takes the data from the FSR and scales it down to a reasonsable number. It then sends it to the I2C
//For data and the I2C sends it to the external circuit to the digital resistor for volume control.
#include "FSR2I2C.h" 


void I2CSendFSR1()
{
	uint32_t FSR1I2C;
	
	I2CMasterSlaveAddrSet(I2C0_BASE, 0x00, false);
	
	I2CMasterDataPut(I2C0_BASE, FSR1I2C );
}
