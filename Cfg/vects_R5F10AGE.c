/************************************************************************/
/* Header file generated from device file:                              */
/*    DR5F10AGE.DVF                                                     */
/*    V1.11 (2015/07/09)                                                */
/*    Copyright(C) 2015 Renesas                                         */
/* Tool Version: 4.0.11                                                 */
/* Date Generated: 2022/06/03                                           */
/************************************************************************/
#include "interrupt_handlers_R5F10AGE.h"

extern void PowerON_Reset(void);

const unsigned char Option_Bytes[] __attribute__((section(".option_bytes"))) = {
	0xef, 0xff, 0xe8, 0x85};

const unsigned char Security_Id[] __attribute__((section(".security_id"))) = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

#define VEC __attribute__((section(".vec")))
const void __near* HardwareVectors[] VEC = {
	// Address 0x0
	PowerON_Reset,
	// Secure for Debugging
	(void*)0xFFFF};

#define VECT_SECT __attribute__((section(".vects")))
const void __near* Vectors[] VECT_SECT = {
	// INT_SRO/INT_WDTI (0x4)
	INT_WDTI,
	// INT_LVI (0x6)
	INT_LVI,
	// INT_P0 (0x8)
	INT_P0,
	// INT_P1 (0xA)
	INT_P1,
	// INT_P2 (0xC)
	INT_P2,
	// INT_P3 (0xE)
	INT_P3,
	// INT_P4/INT_SPM (0x10)
	INT_SPM,
	// INT_P5 (0x12)
	INT_P5,
	// INT_CLM (0x14)
	INT_CLM,
	// INT_CSI00/INT_IIC00/INT_ST0 (0x16)
	INT_ST0,
	// INT_CSI01/INT_IIC01/INT_SR0 (0x18)
	INT_SR0,
	// INT_TRD0 (0x1A)
	INT_TRD0,
	// INT_TRD1 (0x1C)
	INT_TRD1,
	// INT_TRJ0 (0x1E)
	INT_TRJ0,
	// INT_RAM (0x20)
	INT_RAM,
	// INT_LIN0TRM (0x22)
	INT_LIN0TRM,
	// INT_LIN0RVC (0x24)
	INT_LIN0RVC,
	// INT_LIN0/INT_LIN0STA (0x26)
	INT_LIN0STA,
	// Padding
	(void*)0xFFFF,
	// INT_RTC (0x2A)
	INT_RTC,
	// INT_TM00 (0x2C)
	INT_TM00,
	// INT_TM01 (0x2E)
	INT_TM01,
	// INT_TM02 (0x30)
	INT_TM02,
	// INT_TM03 (0x32)
	INT_TM03,
	// INT_AD (0x34)
	INT_AD,
	// INT_P6 (0x36)
	INT_P6,
	// INT_P7 (0x38)
	INT_P7,
	// INT_TM01H (0x3A)
	INT_TM01H,
	// INT_TM03H (0x3C)
	INT_TM03H,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// INT_TM04 (0x42)
	INT_TM04,
	// INT_TM05 (0x44)
	INT_TM05,
	// INT_TM06 (0x46)
	INT_TM06,
	// INT_TM07 (0x48)
	INT_TM07,
	// INT_LIN0WUP (0x4A)
	INT_LIN0WUP,
	// INT_KR (0x4C)
	INT_KR,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// INT_FL (0x62)
	INT_FL,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// Padding
	(void*)0xFFFF,
	// INT_BRK_I (0x7E)
	INT_BRK_I,
};
