/*!
 * \file Spi.h
 * \brief Serial peripheral interface API
 * \author awd110
 */
#ifndef SPI_H
#define SPI_H
/* Includes */
#include "Spi_Types.h"
#include "Std_Types.h"
#include "Spi_Cfg.h"

/* Macros */

/* Exported Type definitions */

/* Exported Objects */

/* Exported function prototypes */
void		  Spi_Init(const Spi_ConfigType* ConfigPtr);
Std_ReturnType	  Spi_DeInit(void);
Std_ReturnType	  Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataBufferType* DataBufferPtr);
Std_ReturnType	  Spi_AsyncTransmit(Spi_SequenceType Sequence);
Std_ReturnType	  Spi_ReadIB(Spi_ChannelType Channel, Spi_DataBufferType* DataBufferPointer);
Std_ReturnType	  Spi_SetupEB(Spi_ChannelType Channel, const Spi_DataBufferType* SrcDataBufferPtr, Spi_DataBufferType* DesDataBufferPtr, Spi_NumberOfDataType Length);
Spi_StatusType	  Spi_GetStatus(void);
Spi_JobResultType Spi_GetJobResult(Spi_JobType Job);
Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence);
void		  Spi_GetVersionInfo(Std_VersionInfoType* versioninfo);
Std_ReturnType	  Spi_SyncTransmit(Spi_SequenceType Sequence);
Spi_StatusType	  Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit);
void		  Spi_Cancel(Spi_SequenceType Sequence);
Std_ReturnType	  Spi_SetAsyncMode(Spi_AsyncModeType Mode);
void		  Spi_MainFunction_Handling(void);

#endif /* SPI_H */
