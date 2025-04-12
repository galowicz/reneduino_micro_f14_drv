/*!
 * \file port_types.h
 * \brief Port driver header with type definitions
 * \author awd110
 *
 */
#ifndef PORT_TYPES_H
#define PORT_TYPES_H
/* Includes */
#include "Std_Types.h"

/* Macros */

/* Exported Type definitions */
/*!
 * Data type for the symbolic name of a port pin
 */
typedef uint8 Port_PinType;

/*!
 * Possible directions of a port pin.
 */
typedef enum {
	PORT_PIN_IN  = 0x00,
	PORT_PIN_OUT = 0x01,
} Port_PinDirectionType;

/*!
 * Different port pin modes.
 */
typedef uint8 Port_PinModeType;

/*!
 * type	for single port configuration.
 */
typedef struct {
	uint8 port_index;
	uint8 p_reg;	 // Data register - 1 high, 0 low
	uint8 pm_reg;	 // Direction - 1 input, 0 output
	uint8 pim_reg;	 // input mode - 1 ttl, 0 normal
	uint8 pom_reg;	 // output mode - 1 open drain, 0 normal
	uint8 pmc_reg;	 // mode control - 1 analog in, 0 digital io
	uint8 pu_reg;	 // Pullup - 1 enabled, 0 disabled
	uint8 pithl_reg; // input threshold - 1 shmitt3, 0 shmitt1
} Port_PortReg_t;

typedef struct {
	volatile uint8* p_reg;
	volatile uint8* pm_reg;
	volatile uint8* pu_reg;
	volatile uint8* pim_reg;
	volatile uint8* pom_reg;
	volatile uint8* pmc_reg;
	volatile uint8* pithl_reg;
} Port_PortRegisters_t;

/*!
 * Type of the external data structure containing the initialization data for this module.
 */
typedef struct {
	const Port_PortReg_t* port_cfg;
	uint8		      len;
} Port_ConfigType;

/* Exported Objects */

/* Exported function prototypes */

#endif /* PORT_TYPES_H */
