/*!
 * \file ${file-name}
 * \brief
 * \author awd110
 *
 */
/* Includes */
#include "iodefine_R5F10AGE.h"
#include "iodefine_ext_R5F10AGE.h"
#include "port_types.h"

/* Macros */
// 1 - Input, 0 - Output
// default 1
#define PORT_PM_P0_DEFAULT (0b11111111u)
//                            |||||||+-P00 -
//                            ||||||+--P01 - not present
//                            |||||+---P02 - not present
//                            ||||+----P03 - not present
//                            |||+-----P04 - not present
//                            ||+------P05 - not present
//                            |+-------P06 - not present
//                            +--------P07 - not present
#define PORT_PM_P1_DEFAULT (0b11110011u)
//                            |||||||+-P10 -
//                            ||||||+--P11 -
//                            |||||+---P12 - LIN_EN
//                            ||||+----P13 - LIN_TX
//                            |||+-----P14 - LIN_RX
//                            ||+------P15 -
//                            |+-------P16 -
//                            +--------P17 -
#define PORT_PM_P3_DEFAULT (0b11111111u)
//                            |||||||+-P30 -
//                            ||||||+--P31 -
//                            |||||+---P32 -
//                            ||||+----P33 -
//                            |||+-----P34 -
//                            ||+------P35 - not present
//                            |+-------P36 - not present
//                            +--------P37 - not present
#define PORT_PM_P4_DEFAULT (0b11111101u)
//                            |||||||+-P40 - TOOL0
//                            ||||||+--P41 - USERLED
//                            |||||+---P42 - not present
//                            ||||+----P43 - not present
//                            |||+-----P44 - not present
//                            ||+------P45 - not present
//                            |+-------P46 - not present
//                            +--------P47 - not present
#define PORT_PM_P6_DEFAULT (0b11111111u)
//                            |||||||+-P60 -
//                            ||||||+--P61 -
//                            |||||+---P62 -
//                            ||||+----P63 -
//                            |||+-----P64 - not present
//                            ||+------P65 - not present
//                            |+-------P66 - not present
//                            +--------P67 - not present
#define PORT_PM_P7_DEFAULT (0b11111111u)
//                            |||||||+-P70 -
//                            ||||||+--P71 -
//                            |||||+---P72 -
//                            ||||+----P73 -
//                            |||+-----P74 - not present
//                            ||+------P75 - not present
//                            |+-------P76 - not present
//                            +--------P77 - not present
#define PORT_PM_P8_DEFAULT (0b11111111u)
//                            |||||||+-P80 -
//                            ||||||+--P81 -
//                            |||||+---P82 -
//                            ||||+----P83 -
//                            |||+-----P84 -
//                            ||+------P85 -
//                            |+-------P86 -
//                            +--------P87 -
#define PORT_PM_P9_DEFAULT (0b11111111u)
//                            |||||||+-P90 -
//                            ||||||+--P91 -
//                            |||||+---P92 -
//                            ||||+----P93 - not present
//                            |||+-----P94 - not present
//                            ||+------P95 - not present
//                            |+-------P96 - not present
//                            +--------P97 - not present
#define PORT_PM_P12_DEFAULT (0b11111111u)
//                             |||||||+-P120 -
//                             ||||||+--P121 - X1
//                             |||||+---P122 - X2
//                             ||||+----P123 - UNUSED/XT1
//                             |||+-----P124 - UNUSED/XT2
//                             ||+------P125 -
//                             |+-------P126 - not present
//                             +--------P127 - not present
#define PORT_PM_P13_DEFAULT (0b11111111u)
//                             |||||||+-P130 -
//                             ||||||+--P131 - not present
//                             |||||+---P132 - not present
//                             ||||+----P133 - not present
//                             |||+-----P134 - not present
//                             ||+------P135 - not present
//                             |+-------P136 - not present
//                             +--------P137 -
#define PORT_PM_P14_DEFAULT (0b11111111u)
//                             |||||||+-P140 -
//                             ||||||+--P141 - not present
//                             |||||+---P142 - not present
//                             ||||+----P143 - not present
//                             |||+-----P144 - not present
//                             ||+------P145 - not present
//                             |+-------P146 - not present
//                             +--------P147 - not present

// 1 - High, 0 - Low
// default 0
#define PORT_P_P0_DEFAULT (0b00000000u)
//                           |||||||+-P00 -
//                           ||||||+--P01 -
//                           |||||+---P02 -
//                           ||||+----P03 -
//                           |||+-----P04 -
//                           ||+------P05 -
//                           |+-------P06 -
//                           +--------P07 -
#define PORT_P_P1_DEFAULT (0b00001100u)
//                           |||||||+-P10 -
//                           ||||||+--P11 -
//                           |||||+---P12 - LIN_EN
//                           ||||+----P13 - LIN_TX
//                           |||+-----P14 - LIN_RX
//                           ||+------P15 -
//                           |+-------P16 -
//                           +--------P17 -
#define PORT_P_P3_DEFAULT (0b00000000u)
//                           |||||||+-P30 -
//                           ||||||+--P31 -
//                           |||||+---P32 -
//                           ||||+----P33 -
//                           |||+-----P34 -
//                           ||+------P35 -
//                           |+-------P36 -
//                           +--------P37 -
#define PORT_P_P4_DEFAULT (0b00000000u)
//                           |||||||+-P40 -
//                           ||||||+--P41 -
//                           |||||+---P42 -
//                           ||||+----P43 -
//                           |||+-----P44 -
//                           ||+------P45 -
//                           |+-------P46 -
//                           +--------P47 -
#define PORT_P_P5_DEFAULT (0b00000000u)
//                           |||||||+-P50 -
//                           ||||||+--P51 -
//                           |||||+---P52 -
//                           ||||+----P53 -
//                           |||+-----P54 -
//                           ||+------P55 -
//                           |+-------P56 -
//                           +--------P57 -
#define PORT_P_P6_DEFAULT (0b00000000u)
//                           |||||||+-P60 -
//                           ||||||+--P61 -
//                           |||||+---P62 -
//                           ||||+----P63 -
//                           |||+-----P64 -
//                           ||+------P65 -
//                           |+-------P66 -
//                           +--------P67 -
#define PORT_P_P7_DEFAULT (0b00000000u)
//                           |||||||+-P70 -
//                           ||||||+--P71 -
//                           |||||+---P72 -
//                           ||||+----P73 -
//                           |||+-----P74 -
//                           ||+------P75 -
//                           |+-------P76 -
//                           +--------P77 -
#define PORT_P_P8_DEFAULT (0b00000000u)
//                           |||||||+-P80 -
//                           ||||||+--P81 -
//                           |||||+---P82 -
//                           ||||+----P83 -
//                           |||+-----P84 -
//                           ||+------P85 -
//                           |+-------P86 -
//                           +--------P87 -
#define PORT_P_P12_DEFAULT (0b00000000u)
//                            |||||||+-P120 -
//                            ||||||+--P121 -
//                            |||||+---P122 -
//                            ||||+----P123 -
//                            |||+-----P124 -
//                            ||+------P125 -
//                            |+-------P126 -
//                            +--------P127 -
#define PORT_P_P13_DEFAULT (0b00000000u)
//                            |||||||+-P130 -
//                            ||||||+--P131 -
//                            |||||+---P132 -
//                            ||||+----P133 -
//                            |||+-----P134 -
//                            ||+------P135 -
//                            |+-------P136 -
//                            +--------P137 -
#define PORT_P_P14_DEFAULT (0b00000000u)
//                            |||||||+-P140 -
//                            ||||||+--P141 -
//                            |||||+---P142 -
//                            ||||+----P143 -
//                            |||+-----P144 -
//                            ||+------P145 -
//                            |+-------P146 -
//                            +--------P147 -

// 1 - Pull up enabled, 0 - disabled
#define PORT_PU_P0_DEFAULT (0b00000000u)
//                           |||||||+-P00 -
//                           ||||||+--P01 -
//                           |||||+---P02 -
//                           ||||+----P03 -
//                           |||+-----P04 - not present
//                           ||+------P05 - not present
//                           |+-------P06 - not present
//                           +--------P07 - not present
#define PORT_PU_P1_DEFAULT (0b00101100u)
//                           |||||||+-P10 -
//                           ||||||+--P11 -
//                           |||||+---P12 - LIN_EN
//                           ||||+----P13 - LIN_TX
//                           |||+-----P14 - LIN_RX
//                           ||+------P15 -
//                           |+-------P16 -
//                           +--------P17 -
#define PORT_PU_P3_DEFAULT (0b00000000u)
//                           |||||||+-P30 -
//                           ||||||+--P31 -
//                           |||||+---P32 -
//                           ||||+----P33 - not present
//                           |||+-----P34 - not present
//                           ||+------P35 - not present
//                           |+-------P36 - not present
//                           +--------P37 - not present
#define PORT_PU_P4_DEFAULT (0b00000000u)
//                           |||||||+-P40 -
//                           ||||||+--P41 -
//                           |||||+---P42 -
//                           ||||+----P43 -
//                           |||+-----P44 -
//                           ||+------P45 -
//                           |+-------P46 -
//                           +--------P47 -
#define PORT_PU_P6_DEFAULT (0b00000000u)
//                           |||||||+-P60 -
//                           ||||||+--P61 -
//                           |||||+---P62 -
//                           ||+------P65 -
//                           |+-------P66 -
//                           +--------P67 -
#define PORT_PU_P7_DEFAULT (0b00000000u)
//                           |||||||+-P70 -
//                           ||||||+--P71 -
//                           |||||+---P72 -
//                           ||||+----P73 -
//                           |||+-----P74 -
//                           ||+------P75 -
//                           |+-------P76 -
//                           +--------P77 -
#define PORT_PU_P8_DEFAULT (0b00000000u)
//                           |||||||+-P80 -
//                           ||||||+--P81 -
//                           |||||+---P82 -
//                           ||||+----P83 -
//                           |||+-----P84 -
//                           ||+------P85 -
//                           |+-------P86 -
//                           +--------P87 -
#define PORT_PU_P12_DEFAULT (0b00000000u)
//                            |||||||+-P120 -
//                            ||||||+--P121 - not present
//                            |||||+---P122 - not present
//                            ||||+----P123 - not present
//                            |||+-----P124 - not present
//                            ||+------P125 -
//                            |+-------P126 -
//                            +--------P127 -
#define PORT_PU_P13_DEFAULT (0b00000000u)
//                            |||||||+-P130 -
//                            ||||||+--P131 -
//                            |||||+---P132 -
//                            ||||+----P133 -
//                            |||+-----P134 -
//                            ||+------P135 -
//                            |+-------P136 -
//                            +--------P137 -
#define PORT_PU_P14_DEFAULT (0b00000000u)
//                            |||||||+-P140 -
//                            ||||||+--P141 - not present
//                            |||||+---P142 - not present
//                            ||||+----P143 - not present
//                            |||+-----P144 - not present
//                            ||+------P145 - not present
//                            |+-------P146 - not present
//                            +--------P147 - not present

/* Typedefs */

/* Objects */

const Port_PortReg_t Port_PortDefaultConfig[] = {
	{
		// P0
		.port_index = 0,
		.p_reg	    = PORT_P_P0_DEFAULT,
		.pm_reg	    = PORT_PM_P0_DEFAULT,
		.pim_reg    = PORT_PIM_P0_DEFAULT,
		.pom_reg    = PORT_POM_P0_DEFAULT,
		.pmc_reg    = PORT_PMC_P0_DEFAULT,
		.pu_reg	    = PORT_PU_P0_DEFAULT,
		.pithl_reg  = 0,
	 },
	{
		// P1
		.port_index = 1,
		.p_reg	    = PORT_P_P1_DEFAULT,
		.pm_reg	    = PORT_PM_P1_DEFAULT,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = PORT_PU_P1_DEFAULT,
		.pithl_reg  = 0,
	 },
	{
		// P3
		.port_index = 3,
		.p_reg	    = PORT_P_P3_DEFAULT,
		.pm_reg	    = PORT_PM_P3_DEFAULT,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P4
		.port_index = 4,
		.p_reg	    = PORT_P_P4_DEFAULT,
		.pm_reg	    = PORT_PM_P4_DEFAULT,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P6
		.port_index = 6,
		.p_reg	    = PORT_P_P6_DEFAULT,
		.pm_reg	    = PORT_PM_P6_DEFAULT,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P7
		.port_index = 7,
		.p_reg	    = PORT_P_P7_DEFAULT,
		.pm_reg	    = PORT_PM_P7_DEFAULT,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P8
		.port_index = 8,
		.p_reg	    = PORT_P_P8_DEFAULT,
		.pm_reg	    = PORT_PM_P8_DEFAULT,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P12
		.port_index = 12,
		.p_reg	    = PORT_P_P12_DEFAULT,
		.pm_reg	    = PORT_PM_P12_DEFAULT,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P13
		.port_index = 13,
		.p_reg	    = PORT_P_P13_DEFAULT,
		.pm_reg	    = PORT_PM_P13_DEFAULT,
		.pim_reg    = 0,
		.pom_reg    = 0,
		.pmc_reg    = 0,
		.pu_reg	    = 0,
		.pithl_reg  = 0,
	 },
	{
		// P14
		.port_index = 14,
		.p_reg	    = PORT_P_P14_DEFAULT,
		.pm_reg	    = PORT_PM_P14_DEFAULT,
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
