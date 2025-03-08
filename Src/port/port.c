/*!
 * \file port.c
 * \brief Port driver source file
 * \author awd110
 *
 */
/* Includes */
#include "port.h"
#include "Std_Types.h"
#include "iodefine_R5F10AGE.h"
#include "iodefine_ext_R5F10AGE.h"
#include "port_types.h"

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

const Port_PortRegisters_t Port_PortRegistersPtr[16] = {
	{
// P0
#ifdef P0
		.p_reg = &P0,
	#ifdef PM0
		.pm_reg = &PM0,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM0*/
	#ifdef PU0
		.pu_reg = &PU0,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU0*/
	#ifdef PIM0
		.pim_reg = &PIM0,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM0*/
	#ifdef POM0
		.pom_reg = &POM0,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM0*/
	#ifdef PMC0
		.pmc_reg = &PMC0,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC1*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,

#endif /*P0*/
	 },
	{
// P1
#ifdef P1
		.p_reg = &P1,
	#ifdef PM1
		.pm_reg = &PM1,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM1*/
	#ifdef PU1
		.pu_reg = &PU1,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU1*/
	#ifdef PIM1
		.pim_reg = &PIM1,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM1*/
	#ifdef POM1
		.pom_reg = &POM1,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM1*/
	#ifdef PMC1
		.pmc_reg = &PMC1,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC1*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P1*/
	 },
	{
// P2 Not present for 48pin package
#ifdef P2
		.p_reg = &P2,
	#ifdef PM2
		.pm_reg = &PM2,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM2*/
	#ifdef PU2
		.pu_reg = &PU2,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU2*/
	#ifdef PIM2
		.pim_reg = &PIM2,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM2*/
	#ifdef POM2
		.pom_reg = &POM2,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM2*/
	#ifdef PMC2
		.pmc_reg = &PMC2,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC2*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P2*/
	 },
	{
// P3
#ifdef P3
		.p_reg = &P3,
	#ifdef PM3
		.pm_reg = &PM3,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM3*/
	#ifdef PU3
		.pu_reg = &PU3,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU3*/
	#ifdef PIM3
		.pim_reg = &PIM3,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM3*/
	#ifdef POM3
		.pom_reg = &POM3,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM3*/
	#ifdef PMC3
		.pmc_reg = &PMC3,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC3*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P3*/
	 },
	{
// P4
#ifdef P4
		.p_reg = &P4,
	#ifdef PM4
		.pm_reg = &PM4,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM4*/
	#ifdef PU4
		.pu_reg = &PU4,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU4*/
	#ifdef PIM4
		.pim_reg = &PIM4,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM4*/
	#ifdef POM4
		.pom_reg = &POM4,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM4*/
	#ifdef PMC4
		.pmc_reg = &PMC4,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC4*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P4*/
	 },
	{
// P5
#ifdef P5
		.p_reg = &P5,
	#ifdef PM5
		.pm_reg = &PM5,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM5*/
	#ifdef PU5
		.pu_reg = &PU5,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU5*/
	#ifdef PIM5
		.pim_reg = &PIM5,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM5*/
	#ifdef POM5
		.pom_reg = &POM5,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM5*/
	#ifdef PMC5
		.pmc_reg = &PMC5,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC5*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P5*/
	 },
	{
// P6
#ifdef P6
		.p_reg = &P6,
	#ifdef PM6
		.pm_reg = &PM6,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM6*/
	#ifdef PU6
		.pu_reg = &PU6,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU6*/
	#ifdef PIM6
		.pim_reg = &PIM6,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM6*/
	#ifdef POM6
		.pom_reg = &POM6,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM6*/
	#ifdef PMC6
		.pmc_reg = &PMC6,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC6*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P6*/
	 },
	{
// P7
#ifdef P7
		.p_reg = &P7,
	#ifdef PM7
		.pm_reg = &PM7,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM7*/
	#ifdef PU7
		.pu_reg = &PU7,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU7*/
	#ifdef PIM7
		.pim_reg = &PIM7,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM7*/
	#ifdef POM7
		.pom_reg = &POM7,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM7*/
	#ifdef PMC7
		.pmc_reg = &PMC7,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC7*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P7*/
	 },
	{
// P8
#ifdef P8
		.p_reg = &P8,
	#ifdef PM8
		.pm_reg = &PM8,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM8*/
	#ifdef PU8
		.pu_reg = &PU8,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU8*/
	#ifdef PIM8
		.pim_reg = &PIM8,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM8*/
	#ifdef POM8
		.pom_reg = &POM8,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM8*/
	#ifdef PMC8
		.pmc_reg = &PMC8,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC8*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P8*/
	 },
	{
// P9 Not present for 48pin package
#ifdef P9
		.p_reg = &P9,
	#ifdef PM9
		.pm_reg = &PM9,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM9*/
	#ifdef PU9
		.pu_reg = &PU9,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU9*/
	#ifdef PIM9
		.pim_reg = &PIM9,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM9*/
	#ifdef POM9
		.pom_reg = &POM9,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM9*/
	#ifdef PMC9
		.pmc_reg = &PMC9,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC9*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P9*/
	 },
	{
// P10
#ifdef P10
		.p_reg = &P10,
	#ifdef PM10
		.pm_reg = &PM10,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM10*/
	#ifdef PU10
		.pu_reg = &PU10,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU10*/
	#ifdef PIM10
		.pim_reg = &PIM10,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM10*/
	#ifdef POM10
		.pom_reg = &POM10,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM10*/
	#ifdef PMC10
		.pmc_reg = &PMC10,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC10*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P10*/
	 },
	{
// P11
#ifdef P11
		.p_reg = &P11,
	#ifdef PM11
		.pm_reg = &PM11,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM11*/
	#ifdef PU11
		.pu_reg = &PU11,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU11*/
	#ifdef PIM11
		.pim_reg = &PIM11,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM11*/
	#ifdef POM11
		.pom_reg = &POM11,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM11*/
	#ifdef PMC11
		.pmc_reg = &PMC11,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC11*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P11*/
	 },
	{
// P12
#ifdef P12
		.p_reg = &P12,
	#ifdef PM12
		.pm_reg = &PM12,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM12*/
	#ifdef PU12
		.pu_reg = &PU12,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU12*/
	#ifdef PIM12
		.pim_reg = &PIM12,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM12*/
	#ifdef POM12
		.pom_reg = &POM12,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM12*/
	#ifdef PMC12
		.pmc_reg = &PMC12,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC12*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P12*/
	 },
	{
// P13
#ifdef P13
		.p_reg = &P13,
	#ifdef PM13
		.pm_reg = &PM13,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM13*/
	#ifdef PU13
		.pu_reg = &PU13,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU13*/
	#ifdef PIM13
		.pim_reg = &PIM13,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM13*/
	#ifdef POM13
		.pom_reg = &POM13,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM13*/
	#ifdef PMC13
		.pmc_reg = &PMC13,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC13*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P13*/
	 },
	{
// P14
#ifdef P14
		.p_reg = &P14,
	#ifdef PM14
		.pm_reg = &PM14,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM14*/
	#ifdef PU14
		.pu_reg = &PU14,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU14*/
	#ifdef PIM14
		.pim_reg = &PIM14,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM14*/
	#ifdef POM14
		.pom_reg = &POM14,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM14*/
	#ifdef PMC14
		.pmc_reg = &PMC14,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC14*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P14*/
	 },
	{
// P15
#ifdef P15
		.p_reg = &P15,
	#ifdef PM15
		.pm_reg = &PM15,
	#else
		.pm_reg = NULL_PTR,
	#endif /*PM15*/
	#ifdef PU15
		.pu_reg = &PU15,
	#else
		.pu_reg = NULL_PTR,
	#endif /*PU15*/
	#ifdef PIM15
		.pim_reg = &PIM15,
	#else
		.pim_reg = NULL_PTR,
	#endif /*PIM15*/
	#ifdef POM15
		.pom_reg = &POM15,
	#else
		.pom_reg = NULL_PTR,
	#endif /*POM15*/
	#ifdef PMC15
		.pmc_reg = &PMC15,
	#else
		.pmc_reg = NULL_PTR,
	#endif /*PMC15*/
#else
		.p_reg	 = NULL_PTR,
		.pm_reg	 = NULL_PTR,
		.pu_reg	 = NULL_PTR,
		.pim_reg = NULL_PTR,
		.pom_reg = NULL_PTR,
		.pmc_reg = NULL_PTR,
#endif /*P15*/
	 },
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
			Port_PortReg_t current_port = ConfigPtr->port_cfg[i];
			if (Port_PortRegistersPtr[current_port.port_index].p_reg != NULL_PTR) {
				*Port_PortRegistersPtr[current_port.port_index].p_reg = current_port.p_reg;
			}
			if (Port_PortRegistersPtr[current_port.port_index].pu_reg != NULL_PTR) {
				*Port_PortRegistersPtr[current_port.port_index].pu_reg = current_port.pu_reg;
			}
			if (Port_PortRegistersPtr[current_port.port_index].pim_reg != NULL_PTR) {
				*Port_PortRegistersPtr[current_port.port_index].pim_reg = current_port.pim_reg;
			}
			if (Port_PortRegistersPtr[current_port.port_index].pom_reg != NULL_PTR) {
				*Port_PortRegistersPtr[current_port.port_index].pom_reg = current_port.pom_reg;
			}
			if (Port_PortRegistersPtr[current_port.port_index].pmc_reg != NULL_PTR) {
				*Port_PortRegistersPtr[current_port.port_index].pmc_reg = current_port.pmc_reg;
			}
			if (Port_PortRegistersPtr[current_port.port_index].pm_reg != NULL_PTR) {
				*Port_PortRegistersPtr[current_port.port_index].pm_reg = current_port.pm_reg;
			}
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

	if (Port_PortRegistersPtr[port].pm_reg != NULL_PTR) {
		*Port_PortRegistersPtr[port].pm_reg &= 1 << offset;
		*Port_PortRegistersPtr[port].pm_reg &= Direction << offset;
	}
}

/*!
 * Refreshes port direction.
 */
void Port_RefreshPortDirection(void) {
	for (uint8 i = 0; i < Port_CurrentConfig->len; i++) {
		Port_PortReg_t current_port = Port_CurrentConfig->port_cfg[i];
		if (Port_PortRegistersPtr[current_port.port_index].pim_reg != NULL_PTR) {
			*Port_PortRegistersPtr[current_port.port_index].pim_reg = current_port.pim_reg;
		}
		if (Port_PortRegistersPtr[current_port.port_index].pom_reg != NULL_PTR) {
			*Port_PortRegistersPtr[current_port.port_index].pom_reg = current_port.pom_reg;
		}
		if (Port_PortRegistersPtr[current_port.port_index].pmc_reg != NULL_PTR) {
			*Port_PortRegistersPtr[current_port.port_index].pmc_reg = current_port.pmc_reg;
		}
		if (Port_PortRegistersPtr[current_port.port_index].pm_reg != NULL_PTR) {
			*Port_PortRegistersPtr[current_port.port_index].pm_reg = current_port.pm_reg;
		}
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
