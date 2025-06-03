/*!
 * \file spi_types.h
 * \brief
 * \author awd110
 */
#ifndef SPI_TYPES_H
#define SPI_TYPES_H

/* Includes */
#include "Std_Types.h"

/* Macros */

/* Exported Type definitions */
typedef enum {
	SPI_UNINIT = 0x00,
	SPI_IDLE   = 0x01,
	SPI_BUSY   = 0x02,
} Spi_StatusType;

typedef enum {
	SPI_JOB_OK	= 0x00,
	SPI_JOB_PENDING = 0x01,
	SPI_JOB_FAILED	= 0x02,
	SPI_JOB_QUEUED	= 0x03,
} Spi_JobResultType;

typedef enum {
	SPI_SEQ_OK	 = 0x00,
	SPI_SEQ_PENDING	 = 0x01,
	SPI_SEQ_FAILED	 = 0x02,
	SPI_SEQ_CANCELED = 0x03,
} Spi_SeqResultType;

typedef uint8  Spi_DataBufferType;
typedef uint16 Spi_NumberOfDataType;

typedef uint8  Spi_ChannelType;
typedef uint16 Spi_JobType;
typedef uint8  Spi_SequenceType;
typedef uint8  Spi_HWUnitType;

typedef enum {
	SPI_POLLING_MODE   = 0x00,
	SPI_INTERRUPT_MODE = 0x01,
} Spi_AsyncModeType;

/* implementation specific types */

typedef struct {
	Spi_DataBufferType*  tx_buffer;
	Spi_DataBufferType*  rx_buffer;
	Spi_NumberOfDataType size;
	Spi_NumberOfDataType current_byte;
	Spi_DataBufferType   default_val;
} Spi_ChannelDescType;
typedef struct {
	uint8 mode;
	uint8 clk_presc;
	uint8 baudrate;
	uint8 clkPolarity;
	uint8 clkPhase;
	uint8 dataOrder;
} Spi_HWConfigType;
/* end implementation specific types */

typedef struct {
	Spi_HWUnitType SpiMaxHwUnit;

} Spi_ConfigType;

/* Exported Objects */

/* Exported function prototypes */

#endif /* SPI_TYPES_H */
/* end of file */
