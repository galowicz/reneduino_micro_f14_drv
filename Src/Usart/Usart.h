/*!
 * \file Uart.h
 * \brief TODO
 * \author awd110
 *
 */
#ifndef USART_H
#define USART_H
/* Includes */
#include "Std_Types.h"
#include "Usart_Types.h"
#include "Usart_Cfg.h"

/* Macros */

/* Exported Type definitions */

/* Exported Objects */

/* Exported function prototypes */
/*!
 * Initialize USART
 *
 * \param Configuration pointer
 */
void Usart_Init(const Usart_ConfigType* ConfigPtr);

/*!
 * Request data transmission
 *
 * \param channel id
 * \param Pointer to data to send
 * \param number of bytes to send
 * \return E_OK - request accepted, E_NOT_OK otherwise
 *
 * Function copies data to internal buffer and starts transmission.
 */
Std_ReturnType Usart_TransmitData(Usart_ChannelType Channel, const Usart_DataType* DataPtr, uint8 Length);

/*!
 * Copy received data
 *
 * \param channel id
 * \param pointer to buffer for data
 * \param maximum length of data to copy
 * \return number of copied bytes, or 0 if error
 */
uint8 Usart_GetReceivedData(Usart_ChannelType Channel, Usart_DataType* DataPtr, uint8 MaxLength);

/*!
 * get module status
 *
 * \param channel id
 * \param pointer for status
 */
void Usart_GetStatus(Usart_ChannelType Channel, Usart_StatusType* StatusPtr);

/*!
 * get module version
 *
 * \param pointer for status
 */
void Usart_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr);

#endif /* USART_H */
