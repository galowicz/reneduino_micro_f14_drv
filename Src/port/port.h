/*!
 * \file  port.h
 * \brief Port driver header file
 * \author awd110
 *
 */
#ifndef PORT_H
#define PORT_H

/* Includes */
#include "Std_Types.h"
#include "port_types.h"

/* Macros */
#define PORT_E_PARAM_PIN	      0x0A
#define PORT_E_DIRECTION_UNCHANGEABLE 0x0B
#define PORT_E_INIT_FAILED	      0x0C
#define PORT_E_PARAM_INVALID_MODE     0x0D
#define PORT_E_MODE_UNCHANGEABLE      0x0E
#define PORT_E_UNINIT		      0x0F
#define PORT_E_PARAM_POINTER	      0x10

/* Exported Type definitions */

/* Exported Objects */
extern const Port_PortRegisters_t Port_PortRegistersPtr[16];
extern const Port_ConfigType	  Port_DefaultConfig;

/* Exported function prototypes */
void Port_Init(const Port_ConfigType* ConfigPtr);
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
void Port_RefreshPortDirection(void);
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);

#endif /* PORT_H */
