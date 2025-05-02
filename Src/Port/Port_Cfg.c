/*!
 * \file Port_Cfg.c
 * \brief Port driver configuration
 * \author awd110
 *
 */
/* Includes */
#include "iodefine_R5F10AGE.h"
#include "iodefine_ext_R5F10AGE.h"
#include "Port_Types.h"

/* Macros */

/* Typedefs */

/* Objects */

const Port_PortReg_t Port_PortDefaultConfig[] = {
	{
		// P0
		.port_index = 0,
		.p_reg	    = 0,
		.pm_reg	    = 0,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P1
		.port_index = 1,
		.p_reg	    = 0b00001100u,// P17 - unused, P16 - unused, P15 - unused, P14 - lin rx, P13 - lin tx, P12 - lin en, P11 - unused, P10 - unused
		.pm_reg	    = 0b11110011u,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0b00101100u,
		.pithl_reg  = 0,
	 },
	{
		// P3
		.port_index = 3,
		.p_reg	    = 0,
		.pm_reg	    = 0,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P4
		.port_index = 4,
		.p_reg	    = 0b00000010u, //P41 - USERLED
		.pm_reg	    = 0b11111101u,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P6
		.port_index = 6,
		.p_reg	    = 0,
		.pm_reg	    = 0,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P7
		.port_index = 7,
		.p_reg	    = 0,
		.pm_reg	    = 0,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P8
		.port_index = 8,
		.p_reg	    = 0,
		.pm_reg	    = 0,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P9
		.port_index = 9,
		.p_reg	    = 0,
		.pm_reg	    = 0,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P12
		.port_index = 12,
		.p_reg	    = 0,
		.pm_reg	    = 0,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P13
		.port_index = 13,
		.p_reg	    = 0,
		.pm_reg	    = 0,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P14
		.port_index = 14,
		.p_reg	    = 0,
		.pm_reg	    = 0b00000000,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
};

const Port_ConfigType Port_DefaultConfig = {
	.port_cfg = Port_PortDefaultConfig,
	.len	  = sizeof(Port_PortDefaultConfig) / sizeof(Port_PortReg_t),
};

/* Function prototypes */

/* Function definitions */
