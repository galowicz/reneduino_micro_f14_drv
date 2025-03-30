/*!
 * \file Dio.c
 * \brief Digital Input Output driver
 * \author awd110
 */
/* Includes */
#include "Dio.h"
#include "Dio_Types.h"
#include "Port.h"
#include "Std_Types.h"

/* Macros */

/* Typedefs */

/* Objects */

/* Function prototypes */
static Std_ReturnType Dio_DecodeChannel(Dio_ChannelType Channel, uint8* port, uint8* pin);

/* Function definitions */

/*!
 * Returns the value of the specified DIO channel.
 *
 * \param ChannelId - ID of DIO channel
 * \return Dio_LevelTypeSTD_HIGH The physical level of the corresponding Pin is STD_HIGH
 *	STD_LOW The physical level of the corresponding Pin is STD_LOW
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId) {
	Dio_LevelType retval = 0;
	uint8	      port = 0, pin = 0;

	if (E_OK == Dio_DecodeChannel(ChannelId, &port, &pin)) {
		retval = (Port_PortRegistersPtr.p_reg[port] >> pin) & 1;
	}

	return retval;
}

/*!
 * Service to set a level of a channel.
 *
 * \param ChannelId - ID of DIO channel
 * \param Level - Value to be written
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) {
	uint8 port = 0, pin = 0;

	if (E_OK == Dio_DecodeChannel(ChannelId, &port, &pin)) {
		uint8 val = Port_PortRegistersPtr.p_reg[port];
		val &= ~(1 << pin);
		val |= Level << pin;
		Port_PortRegistersPtr.p_reg[port] = val;
	}
}

/*!
 * Returns the level of all channels of that port.
 *
 * \param PortId - ID of DIO Port
 * \retun Dio_PortLevelType - Level of all channels of that port
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId) {
	Dio_PortLevelType retval = 0;

	retval = Port_PortRegistersPtr.p_reg[PortId];

	return retval;
}

/*!
 * Service to set a value of the port.
 *
 * \param PortId - ID of DIO Port
 * \param Level - Value to be written
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level) {
	Port_PortRegistersPtr.p_reg[PortId] = Level;
}

/*!
 * This Service reads a subset of the adjoining bits of a port.
 *
 * \param ChannelGroupIdPtr - Pointer to ChannelGroup
 * \return Dio_PortLevelType - Level of a subset of the adjoining bits of a port
 */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr) {
	Dio_PortLevelType retval = 0;

	retval = (Port_PortRegistersPtr.p_reg[ChannelGroupIdPtr->port] >> ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask;

	return retval;
}

/*!
 * Service to set a subset of the adjoining bits of a port to a specified level.
 *
 * \param ChannelGroupIdPtr - Pointer to ChannelGroup
 * \param Level - Value to be written
 */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level) {
	uint8 val = 0;

	val = Port_PortRegistersPtr.p_reg[ChannelGroupIdPtr->port] & ~(ChannelGroupIdPtr->mask << ChannelGroupIdPtr->offset);
	val |= Level << ChannelGroupIdPtr->offset;

	Port_PortRegistersPtr.p_reg[ChannelGroupIdPtr->port] = val;
}

/*!
 * Service to get the version information of this module.
 *
 * \param VersionInfo - Pointer to where to store the version information of this module.
 */
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo) {
	if (NULL_PTR != VersionInfo) {
		VersionInfo->moduleID	      = 0;
		VersionInfo->vendorID	      = 0;
		VersionInfo->sw_major_version = 0;
		VersionInfo->sw_minor_version = 1;
		VersionInfo->sw_patch_version = 0;
	}
}

/*!
 * Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.
 *
 * \param ChannelId - ID of DIO channel
 * \return Dio_LevelType - STD_HIGH: The physical level of the corresponding Pin is STD_HIGH
 *	STD_LOW: The physical level of the corresponding Pin is STD_LOW.
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId) {
	Dio_LevelType retval = 0;
	uint8	      port = 0, pin = 0;

	if (E_OK == Dio_DecodeChannel(ChannelId, &port, &pin)) {
		uint8 val = Port_PortRegistersPtr.p_reg[port];
		val ^= (1 << pin);
		Port_PortRegistersPtr.p_reg[port] = val;

		retval = (Port_PortRegistersPtr.p_reg[port] >> pin) & 1;
	}
	return retval;
}

/*!
 * Service to set the value of a given port with required mask.
 *
 * \param PortId - ID of DIO Port
 * \param Level - Value to be written
 * \param Channels to be masked in the port
 */
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask) {
	(void)PortId;
	(void)Level;
	(void)Mask;
}

/*!
 * Decode channel id to port and pin.
 *
 * \param Channel - ID of DIO chAnnel.
 * \param port - pointer to wtrite port offset
 * \param pin - pointer to write pin offset
 * \return Std_ReturnType - E_OK - operation successfull
 *	E_NOT_OK - invelid channel ID
 */
static Std_ReturnType Dio_DecodeChannel(Dio_ChannelType Channel, uint8* port, uint8* pin) {
	Std_ReturnType retval = E_NOT_OK;
	if (DIO_CHANNEL_MAX > Channel) {
		*port  = Channel >> 3;
		*pin   = Channel & 7;
		retval = E_OK;
	}
	return retval;
}
