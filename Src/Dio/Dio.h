/*!
 * \file Dio.h
 * \brief Digital Input Output driver
 * \author awd110
 *
 */
#ifndef DIO_H_
#define DIO_H_
/* Includes */
#include "Dio_Cfg.h"
#include "Dio_Types.h"

/* Macros */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (0x0A)
#define DIO_E_PARAM_INVALID_PORT_ID    (0x14)
#define DIO_E_PARAM_INVALID_GROUP      (0x1F)
#define DIO_E_PARAM_POINTER	       (0x20)

/* Exported Type definitions */

/* Exported Objects */

/* Exported function prototypes */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void	      Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void		  Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);
void		  Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);

void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo);

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
void	      Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);

#endif /* DIO_H_ */
