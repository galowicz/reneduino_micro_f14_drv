/************************************************************************/
/* Header file generated from device file:                              */
/*    DR5F10AGE.DVF                                                     */
/*    V1.11 (2015/07/09)                                                */
/*    Copyright(C) 2015 Renesas                                         */
/* Tool Version: 4.0.0                                                  */
/* Date Generated: 2020/01/17                                           */
/************************************************************************/
#ifndef INTERRUPT_HANDLERS_H
#define INTERRUPT_HANDLERS_H

/*
 * INT_SRO/INT_WDTI (0x4)
 */
void INT_WDTI(void) __attribute__((interrupt));
// void INT_SRO(void) __attribute__ ((interrupt));

/*
 * INT_LVI (0x6)
 */
void INT_LVI(void) __attribute__((interrupt));

/*
 * INT_P0 (0x8)
 */
void INT_P0(void) __attribute__((interrupt));

/*
 * INT_P1 (0xA)
 */
void INT_P1(void) __attribute__((interrupt));

/*
 * INT_P2 (0xC)
 */
void INT_P2(void) __attribute__((interrupt));

/*
 * INT_P3 (0xE)
 */
void INT_P3(void) __attribute__((interrupt));

/*
 * INT_P4/INT_SPM (0x10)
 */
void INT_SPM(void) __attribute__((interrupt));
// void INT_P4(void) __attribute__ ((interrupt));

/*
 * INT_P5 (0x12)
 */
void INT_P5(void) __attribute__((interrupt));

/*
 * INT_CLM (0x14)
 */
void INT_CLM(void) __attribute__((interrupt));

/*
 * INT_CSI00/INT_IIC00/INT_ST0 (0x16)
 */
void INT_ST0(void) __attribute__((interrupt));
// void INT_CSI00(void) __attribute__ ((interrupt));
// void INT_IIC00(void) __attribute__ ((interrupt));

/*
 * INT_CSI01/INT_IIC01/INT_SR0 (0x18)
 */
void INT_SR0(void) __attribute__((interrupt));
// void INT_CSI01(void) __attribute__ ((interrupt));
// void INT_IIC01(void) __attribute__ ((interrupt));

/*
 * INT_TRD0 (0x1A)
 */
void INT_TRD0(void) __attribute__((interrupt));

/*
 * INT_TRD1 (0x1C)
 */
void INT_TRD1(void) __attribute__((interrupt));

/*
 * INT_TRJ0 (0x1E)
 */
void INT_TRJ0(void) __attribute__((interrupt));

/*
 * INT_RAM (0x20)
 */
void INT_RAM(void) __attribute__((interrupt));

/*
 * INT_LIN0TRM (0x22)
 */
void INT_LIN0TRM(void) __attribute__((interrupt));

/*
 * INT_LIN0RVC (0x24)
 */
void INT_LIN0RVC(void) __attribute__((interrupt));

/*
 * INT_LIN0/INT_LIN0STA (0x26)
 */
void INT_LIN0STA(void) __attribute__((interrupt));
// void INT_LIN0(void) __attribute__ ((interrupt));

/*
 * INT_RTC (0x2A)
 */
void INT_RTC(void) __attribute__((interrupt));

/*
 * INT_TM00 (0x2C)
 */
void INT_TM00(void) __attribute__((interrupt));

/*
 * INT_TM01 (0x2E)
 */
void INT_TM01(void) __attribute__((interrupt));

/*
 * INT_TM02 (0x30)
 */
void INT_TM02(void) __attribute__((interrupt));

/*
 * INT_TM03 (0x32)
 */
void INT_TM03(void) __attribute__((interrupt));

/*
 * INT_AD (0x34)
 */
void INT_AD(void) __attribute__((interrupt));

/*
 * INT_P6 (0x36)
 */
void INT_P6(void) __attribute__((interrupt));

/*
 * INT_P7 (0x38)
 */
void INT_P7(void) __attribute__((interrupt));

/*
 * INT_TM01H (0x3A)
 */
void INT_TM01H(void) __attribute__((interrupt));

/*
 * INT_TM03H (0x3C)
 */
void INT_TM03H(void) __attribute__((interrupt));

/*
 * INT_TM04 (0x42)
 */
void INT_TM04(void) __attribute__((interrupt));

/*
 * INT_TM05 (0x44)
 */
void INT_TM05(void) __attribute__((interrupt));

/*
 * INT_TM06 (0x46)
 */
void INT_TM06(void) __attribute__((interrupt));

/*
 * INT_TM07 (0x48)
 */
void INT_TM07(void) __attribute__((interrupt));

/*
 * INT_LIN0WUP (0x4A)
 */
void INT_LIN0WUP(void) __attribute__((interrupt));

/*
 * INT_KR (0x4C)
 */
void INT_KR(void) __attribute__((interrupt));

/*
 * INT_FL (0x62)
 */
void INT_FL(void) __attribute__((interrupt));

/*
 * INT_BRK_I (0x7E)
 */
void INT_BRK_I(void) __attribute__((interrupt));

// Hardware Vectors
// PowerON_Reset (0x0)
void PowerON_Reset(void) __attribute__((interrupt));

#endif
