/*!
 * \file spi.c
 * \brief spi driver
 * \author awd110
 */
/* Includes */
#include "Spi.h"
#include "Spi_Types.h"
#include "Std_Types.h"

/* Macros */

/* Typedefs */
typedef struct {
	Spi_StatusType	 status;
	Spi_SequenceType current_seq;
	Spi_JobType	 current_job;
	Spi_ChannelType	 curent_channel;
} Spi_Control_t;

/* Objects */
Spi_Control_t Spi_Control = {0};

/* Function prototypes */

/* Function definitions */

void Spi_Init(const Spi_ConfigType* ConfigPtr) {
	Spi_Control.status = SPI_UNINIT;
	for (uint8 i = 0; i < ConfigPtr->SpiMaxHwUnit; i++) {
	}

	Spi_Control.status = SPI_IDLE;
}
Std_ReturnType Spi_DeInit(void) {
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}
Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataBufferType* DataBufferPtr) {
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence) {
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}
Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataBufferType* DataBufferPointer) {
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}
Std_ReturnType Spi_SetupEB(Spi_ChannelType Channel, const Spi_DataBufferType* SrcDataBufferPtr, Spi_DataBufferType* DesDataBufferPtr, Spi_NumberOfDataType Length) {
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}
Spi_StatusType Spi_GetStatus(void) {
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}
Spi_JobResultType Spi_GetJobResult(Spi_JobType Job) {
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}
Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence) {
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}
void Spi_GetVersionInfo(Std_VersionInfoType* versioninfo) {
}
Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence) {
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}
Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit) {
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}
void Spi_Cancel(Spi_SequenceType Sequence) {
}
Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode) {
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}
void Spi_MainFunction_Handling(void) {
}
