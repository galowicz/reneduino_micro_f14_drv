/*!
 * \file Spi_Ll.h
 * \brief SPI lower layer
 * \author awd110
 */
#ifndef SPI_DL_H
#define SPI_DL_H
/* Includes */
#include "Spi_Cfg.h"
#include "Spi_Types.h"
#include "Std_Types.h"

/* Macros */

/* Exported Type definitions */

/* Exported Objects */

/* Exported function prototypes */
void Spi_Ll_Init(Spi_HWUnitType HwUnit, Spi_HWConfigType* HwConfig);
void Spi_Ll_EnableInt(Spi_HWUnitType HwUnit);
void Spi_Ll_StartTransmit(Spi_HWUnitType HwUnit, Spi_ChannelDescType buffer);

void Spi_TransmissionFinishedCbk(Spi_HWUnitType HwUnit);
#endif /* SPI_DL_H */
