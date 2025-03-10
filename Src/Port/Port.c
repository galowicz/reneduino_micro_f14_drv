/*!
 * \file Port.c
 * \brief Port driver source file
 * \author awd110
 *
 */
/* Includes */
#include "Port.h"
#include "Std_Types.h"
#include "iodefine_R5F10AGE.h"
#include "iodefine_ext_R5F10AGE.h"
#include "Port_Types.h"

/* Macros */

/* Typedefs */
/*!
 * module status
 */
typedef enum {
	PORT_UNINIT,
	PORT_INITIALIZED,
} Port_Status_t;

/* Objects */
Port_Status_t	       status;
const Port_ConfigType* Port_CurrentConfig;

const Port_PortRegisters_t Port_PortRegistersPtr = {
	.p_reg	   = (volatile uint8*)0xFFF00,
	.pm_reg	   = (volatile uint8*)0xFFF20,
	.pim_reg   = (volatile uint8*)0xF0040,
	.pom_reg   = (volatile uint8*)0xF0050,
	.pmc_reg   = (volatile uint8*)0xF0050,
	.pithl_reg = (volatile uint8*)0xF0020,
};

/* Function prototypes */

/* Function definitions */
/*!
 * Initializes the Port Driver module.
 *
 * \param ConfigPtr - Pointer to configuration set.
 */
void Port_Init(const Port_ConfigType* ConfigPtr) {
	if (ConfigPtr != NULL_PTR) {
		Port_CurrentConfig = ConfigPtr;
		for (uint8 i = 0; i < ConfigPtr->len; i++) {
			Port_PortReg_t current_port			       = ConfigPtr->port_cfg[i];
			Port_PortRegistersPtr.p_reg[current_port.port_index]   = current_port.p_reg;
			Port_PortRegistersPtr.pu_reg[current_port.port_index]  = current_port.pu_reg;
			Port_PortRegistersPtr.pim_reg[current_port.port_index] = current_port.pim_reg;
			Port_PortRegistersPtr.pom_reg[current_port.port_index] = current_port.pom_reg;
			Port_PortRegistersPtr.pmc_reg[current_port.port_index] = current_port.pmc_reg;
			Port_PortRegistersPtr.pm_reg[current_port.port_index]  = current_port.pm_reg;
		}
	}
}

/*!
 * TODO:
 * Sets the port pin direction
 *
 * \param Pin - Port Pin ID number
 * \param Direction - Port Pin Direction
 */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction) {
	uint8 port   = Pin / 8;
	uint8 offset = Pin % 8;

	if (&Port_PortRegistersPtr.pm_reg[port] != NULL_PTR) {
		Port_PortRegistersPtr.pm_reg[port] &= 1 << offset;
		Port_PortRegistersPtr.pm_reg[port] &= Direction << offset;
	}
}

/*!
 * Refreshes port direction.
 */
void Port_RefreshPortDirection(void) {
	for (uint8 i = 0; i < Port_CurrentConfig->len; i++) {
		Port_PortReg_t current_port			       = Port_CurrentConfig->port_cfg[i];
		Port_PortRegistersPtr.pim_reg[current_port.port_index] = current_port.pim_reg;
		Port_PortRegistersPtr.pom_reg[current_port.port_index] = current_port.pom_reg;
		Port_PortRegistersPtr.pmc_reg[current_port.port_index] = current_port.pmc_reg;
		Port_PortRegistersPtr.pm_reg[current_port.port_index]  = current_port.pm_reg;
	}
}

/*!
 * Returns the version information of this module.
 *
 * \param versioninfo - Pointer to where to store the version information of this module.
 */
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo) {
	versioninfo->sw_major_version = 0;
	versioninfo->sw_minor_version = 0;
	versioninfo->sw_patch_version = 0;
	versioninfo->moduleID	      = 0;
	versioninfo->vendorID	      = 0;
}

/*!
 * TODO:
 * Sets the port pin mode.
 *
 * \param Pin - Port Pin ID number
 * \param Mode - New Port Pin mode to be set on port pin.
 */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode) {
	(void)Pin;
	(void)Mode;
}
