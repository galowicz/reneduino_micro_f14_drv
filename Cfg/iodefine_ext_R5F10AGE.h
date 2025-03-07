/************************************************************************/
/* Header file generated from device file:                              */
/*    DR5F10AGE.DVF                                                     */
/*    V1.11 (2015/07/09)                                                */
/*    Copyright(C) 2015 Renesas                                         */
/* Tool Version: 4.0.0                                                  */
/* Date Generated: 2020/01/17                                           */
/************************************************************************/

#ifndef __INTRINSIC_FUNCTIONS
#define __INTRINSIC_FUNCTIONS

#define DI() asm("di")
#define EI() asm("ei")
#define HALT() asm("halt")
#define NOP() asm("nop")
#define STOP() asm("stop")

#endif

#ifndef __IOREG_BIT_STRUCTURES
#define __IOREG_BIT_STRUCTURES
typedef struct {
	unsigned char no0 :1;
	unsigned char no1 :1;
	unsigned char no2 :1;
	unsigned char no3 :1;
	unsigned char no4 :1;
	unsigned char no5 :1;
	unsigned char no6 :1;
	unsigned char no7 :1;
} __BITS8;

typedef struct {
	unsigned short no0 :1;
	unsigned short no1 :1;
	unsigned short no2 :1;
	unsigned short no3 :1;
	unsigned short no4 :1;
	unsigned short no5 :1;
	unsigned short no6 :1;
	unsigned short no7 :1;
	unsigned short no8 :1;
	unsigned short no9 :1;
	unsigned short no10 :1;
	unsigned short no11 :1;
	unsigned short no12 :1;
	unsigned short no13 :1;
	unsigned short no14 :1;
	unsigned short no15 :1;
} __BITS16;

#endif

#ifndef IODEFINE_EXT_H
#define IODEFINE_EXT_H

/*
 IO Registers
 */
union un_adm2 {
	unsigned char adm2;
	__BITS8 BIT;
};
union un_pithl1 {
	unsigned char pithl1;
	__BITS8 BIT;
};
union un_pithl3 {
	unsigned char pithl3;
	__BITS8 BIT;
};
union un_pithl6 {
	unsigned char pithl6;
	__BITS8 BIT;
};
union un_pithl7 {
	unsigned char pithl7;
	__BITS8 BIT;
};
union un_pithl12 {
	unsigned char pithl12;
	__BITS8 BIT;
};
union un_pu0 {
	unsigned char pu0;
	__BITS8 BIT;
};
union un_pu1 {
	unsigned char pu1;
	__BITS8 BIT;
};
union un_pu3 {
	unsigned char pu3;
	__BITS8 BIT;
};
union un_pu4 {
	unsigned char pu4;
	__BITS8 BIT;
};
union un_pu6 {
	unsigned char pu6;
	__BITS8 BIT;
};
union un_pu7 {
	unsigned char pu7;
	__BITS8 BIT;
};
union un_pu9 {
	unsigned char pu9;
	__BITS8 BIT;
};
union un_pu12 {
	unsigned char pu12;
	__BITS8 BIT;
};
union un_pu14 {
	unsigned char pu14;
	__BITS8 BIT;
};
union un_pim1 {
	unsigned char pim1;
	__BITS8 BIT;
};
union un_pim3 {
	unsigned char pim3;
	__BITS8 BIT;
};
union un_pim12 {
	unsigned char pim12;
	__BITS8 BIT;
};
union un_pom1 {
	unsigned char pom1;
	__BITS8 BIT;
};
union un_pom6 {
	unsigned char pom6;
	__BITS8 BIT;
};
union un_pom12 {
	unsigned char pom12;
	__BITS8 BIT;
};
union un_nfen0 {
	unsigned char nfen0;
	__BITS8 BIT;
};
union un_nfen1 {
	unsigned char nfen1;
	__BITS8 BIT;
};
union un_isc {
	unsigned char isc;
	__BITS8 BIT;
};
union un_pms {
	unsigned char pms;
	__BITS8 BIT;
};
union un_dflctl {
	unsigned char dflctl;
	__BITS8 BIT;
};
union un_per0 {
	unsigned char per0;
	__BITS8 BIT;
};
union un_se0l {
	unsigned char se0l;
	__BITS8 BIT;
};
union un_ss0l {
	unsigned char ss0l;
	__BITS8 BIT;
};
union un_st0l {
	unsigned char st0l;
	__BITS8 BIT;
};
union un_soe0l {
	unsigned char soe0l;
	__BITS8 BIT;
};
union un_te0l {
	unsigned char te0l;
	__BITS8 BIT;
};
union un_ts0l {
	unsigned char ts0l;
	__BITS8 BIT;
};
union un_tt0l {
	unsigned char tt0l;
	__BITS8 BIT;
};
union un_toe0l {
	unsigned char toe0l;
	__BITS8 BIT;
};
union un_psrsel {
	unsigned char psrsel;
	__BITS8 BIT;
};
union un_psnzcnt0 {
	unsigned char psnzcnt0;
	__BITS8 BIT;
};
union un_psnzcnt1 {
	unsigned char psnzcnt1;
	__BITS8 BIT;
};
union un_psnzcnt2 {
	unsigned char psnzcnt2;
	__BITS8 BIT;
};
union un_psnzcnt3 {
	unsigned char psnzcnt3;
	__BITS8 BIT;
};
union un_trjioc0 {
	unsigned char trjioc0;
	__BITS8 BIT;
};
union un_trjmr0 {
	unsigned char trjmr0;
	__BITS8 BIT;
};
union un_trjisr0 {
	unsigned char trjisr0;
	__BITS8 BIT;
};
union un_trdmr {
	unsigned char trdmr;
	__BITS8 BIT;
};
union un_trdpmr {
	unsigned char trdpmr;
	__BITS8 BIT;
};
union un_trdfcr {
	unsigned char trdfcr;
	__BITS8 BIT;
};
union un_trdoer1 {
	unsigned char trdoer1;
	__BITS8 BIT;
};
union un_trdoer2 {
	unsigned char trdoer2;
	__BITS8 BIT;
};
union un_trdocr {
	unsigned char trdocr;
	__BITS8 BIT;
};
union un_trddf0 {
	unsigned char trddf0;
	__BITS8 BIT;
};
union un_trddf1 {
	unsigned char trddf1;
	__BITS8 BIT;
};
union un_trdcr0 {
	unsigned char trdcr0;
	__BITS8 BIT;
};
union un_trdiora0 {
	unsigned char trdiora0;
	__BITS8 BIT;
};
union un_trdiorc0 {
	unsigned char trdiorc0;
	__BITS8 BIT;
};
union un_trdsr0 {
	unsigned char trdsr0;
	__BITS8 BIT;
};
union un_trdier0 {
	unsigned char trdier0;
	__BITS8 BIT;
};
union un_trdpocr0 {
	unsigned char trdpocr0;
	__BITS8 BIT;
};
union un_trdcr1 {
	unsigned char trdcr1;
	__BITS8 BIT;
};
union un_trdiora1 {
	unsigned char trdiora1;
	__BITS8 BIT;
};
union un_trdiorc1 {
	unsigned char trdiorc1;
	__BITS8 BIT;
};
union un_trdsr1 {
	unsigned char trdsr1;
	__BITS8 BIT;
};
union un_trdier1 {
	unsigned char trdier1;
	__BITS8 BIT;
};
union un_trdpocr1 {
	unsigned char trdpocr1;
	__BITS8 BIT;
};
union un_per1 {
	unsigned char per1;
	__BITS8 BIT;
};
union un_per2 {
	unsigned char per2;
	__BITS8 BIT;
};
union un_lincksel {
	unsigned char lincksel;
	__BITS8 BIT;
};
union un_cksel {
	unsigned char cksel;
	__BITS8 BIT;
};
union un_pllctl {
	unsigned char pllctl;
	__BITS8 BIT;
};
union un_pllsts {
	unsigned char pllsts;
	__BITS8 BIT;
};
union un_rtccl {
	unsigned char rtccl;
	__BITS8 BIT;
};
union un_pocres {
	unsigned char pocres;
	__BITS8 BIT;
};
union un_stpstc {
	unsigned char stpstc;
	__BITS8 BIT;
};
union un_hdtccr0 {
	unsigned char hdtccr0;
	__BITS8 BIT;
};
union un_hdtcct0 {
	unsigned char hdtcct0;
	__BITS8 BIT;
};
union un_hdtrld0 {
	unsigned char hdtrld0;
	__BITS8 BIT;
};
union un_hdtccr1 {
	unsigned char hdtccr1;
	__BITS8 BIT;
};
union un_hdtcct1 {
	unsigned char hdtcct1;
	__BITS8 BIT;
};
union un_hdtrld1 {
	unsigned char hdtrld1;
	__BITS8 BIT;
};
union un_selhs0 {
	unsigned char selhs0;
	__BITS8 BIT;
};
union un_selhs1 {
	unsigned char selhs1;
	__BITS8 BIT;
};
union un_dtcen0 {
	unsigned char dtcen0;
	__BITS8 BIT;
};
union un_dtcen1 {
	unsigned char dtcen1;
	__BITS8 BIT;
};
union un_dtcen2 {
	unsigned char dtcen2;
	__BITS8 BIT;
};
union un_dtcen3 {
	unsigned char dtcen3;
	__BITS8 BIT;
};
union un_dtcen4 {
	unsigned char dtcen4;
	__BITS8 BIT;
};
union un_crc0ctl {
	unsigned char crc0ctl;
	__BITS8 BIT;
};
union un_adtrgs0 {
	unsigned char adtrgs0;
	__BITS8 BIT;
};
union un_adtrgs1 {
	unsigned char adtrgs1;
	__BITS8 BIT;
};

#define ADM2 (*(volatile union un_adm2 *)0xF0010).adm2
#define ADM2_bit (*(volatile union un_adm2 *)0xF0010).BIT
#define ADUL (*(volatile unsigned char *)0xF0011)
#define ADLL (*(volatile unsigned char *)0xF0012)
#define ADTES (*(volatile unsigned char *)0xF0013)
#define PIOR0 (*(volatile unsigned char *)0xF0016)
#define PIOR1 (*(volatile unsigned char *)0xF0017)
#define PIOR4 (*(volatile unsigned char *)0xF001A)
#define PIOR5 (*(volatile unsigned char *)0xF001B)
#define PIOR7 (*(volatile unsigned char *)0xF001D)
#define PITHL1 (*(volatile union un_pithl1 *)0xF0021).pithl1
#define PITHL1_bit (*(volatile union un_pithl1 *)0xF0021).BIT
#define PITHL3 (*(volatile union un_pithl3 *)0xF0023).pithl3
#define PITHL3_bit (*(volatile union un_pithl3 *)0xF0023).BIT
#define PITHL6 (*(volatile union un_pithl6 *)0xF0026).pithl6
#define PITHL6_bit (*(volatile union un_pithl6 *)0xF0026).BIT
#define PITHL7 (*(volatile union un_pithl7 *)0xF0027).pithl7
#define PITHL7_bit (*(volatile union un_pithl7 *)0xF0027).BIT
#define PITHL12 (*(volatile union un_pithl12 *)0xF002C).pithl12
#define PITHL12_bit (*(volatile union un_pithl12 *)0xF002C).BIT
#define PU0 (*(volatile union un_pu0 *)0xF0030).pu0
#define PU0_bit (*(volatile union un_pu0 *)0xF0030).BIT
#define PU1 (*(volatile union un_pu1 *)0xF0031).pu1
#define PU1_bit (*(volatile union un_pu1 *)0xF0031).BIT
#define PU3 (*(volatile union un_pu3 *)0xF0033).pu3
#define PU3_bit (*(volatile union un_pu3 *)0xF0033).BIT
#define PU4 (*(volatile union un_pu4 *)0xF0034).pu4
#define PU4_bit (*(volatile union un_pu4 *)0xF0034).BIT
#define PU6 (*(volatile union un_pu6 *)0xF0036).pu6
#define PU6_bit (*(volatile union un_pu6 *)0xF0036).BIT
#define PU7 (*(volatile union un_pu7 *)0xF0037).pu7
#define PU7_bit (*(volatile union un_pu7 *)0xF0037).BIT
#define PU9 (*(volatile union un_pu9 *)0xF0039).pu9
#define PU9_bit (*(volatile union un_pu9 *)0xF0039).BIT
#define PU12 (*(volatile union un_pu12 *)0xF003C).pu12
#define PU12_bit (*(volatile union un_pu12 *)0xF003C).BIT
#define PU14 (*(volatile union un_pu14 *)0xF003E).pu14
#define PU14_bit (*(volatile union un_pu14 *)0xF003E).BIT
#define PIM1 (*(volatile union un_pim1 *)0xF0041).pim1
#define PIM1_bit (*(volatile union un_pim1 *)0xF0041).BIT
#define PIM3 (*(volatile union un_pim3 *)0xF0043).pim3
#define PIM3_bit (*(volatile union un_pim3 *)0xF0043).BIT
#define PIM12 (*(volatile union un_pim12 *)0xF004C).pim12
#define PIM12_bit (*(volatile union un_pim12 *)0xF004C).BIT
#define POM1 (*(volatile union un_pom1 *)0xF0051).pom1
#define POM1_bit (*(volatile union un_pom1 *)0xF0051).BIT
#define POM6 (*(volatile union un_pom6 *)0xF0056).pom6
#define POM6_bit (*(volatile union un_pom6 *)0xF0056).BIT
#define POM12 (*(volatile union un_pom12 *)0xF005C).pom12
#define POM12_bit (*(volatile union un_pom12 *)0xF005C).BIT
#define NFEN0 (*(volatile union un_nfen0 *)0xF0070).nfen0
#define NFEN0_bit (*(volatile union un_nfen0 *)0xF0070).BIT
#define NFEN1 (*(volatile union un_nfen1 *)0xF0071).nfen1
#define NFEN1_bit (*(volatile union un_nfen1 *)0xF0071).BIT
#define ISC (*(volatile union un_isc *)0xF0073).isc
#define ISC_bit (*(volatile union un_isc *)0xF0073).BIT
#define TIS0 (*(volatile unsigned char *)0xF0074)
#define TIS1 (*(volatile unsigned char *)0xF0075)
#define ADPC (*(volatile unsigned char *)0xF0076)
#define PMS (*(volatile union un_pms *)0xF0077).pms
#define PMS_bit (*(volatile union un_pms *)0xF0077).BIT
#define IAWCTL (*(volatile unsigned char *)0xF0078)
#define INTFLG0 (*(volatile unsigned char *)0xF0079)
#define LCHSEL (*(volatile unsigned char *)0xF007B)
#define INTMSK (*(volatile unsigned char *)0xF007C)
#define DFLCTL (*(volatile union un_dflctl *)0xF0090).dflctl
#define DFLCTL_bit (*(volatile union un_dflctl *)0xF0090).BIT
#define HIOTRM (*(volatile unsigned char *)0xF00A0)
#define HOCODIV (*(volatile unsigned char *)0xF00A8)
#define SPMCTRL (*(volatile unsigned char *)0xF00D8)
#define SPOFR (*(volatile unsigned short *)0xF00DA)
#define SPUFR (*(volatile unsigned short *)0xF00DC)
#define PER0 (*(volatile union un_per0 *)0xF00F0).per0
#define PER0_bit (*(volatile union un_per0 *)0xF00F0).BIT
#define OSMC (*(volatile unsigned char *)0xF00F3)
#define BCDADJ (*(volatile unsigned char *)0xF00FE)
#define SSR00 (*(volatile unsigned short *)0xF0100)
#define SSR00L (*(volatile unsigned char *)0xF0100)
#define SSR01 (*(volatile unsigned short *)0xF0102)
#define SSR01L (*(volatile unsigned char *)0xF0102)
#define SIR00 (*(volatile unsigned short *)0xF0104)
#define SIR00L (*(volatile unsigned char *)0xF0104)
#define SIR01 (*(volatile unsigned short *)0xF0106)
#define SIR01L (*(volatile unsigned char *)0xF0106)
#define SMR00 (*(volatile unsigned short *)0xF0108)
#define SMR01 (*(volatile unsigned short *)0xF010A)
#define SCR00 (*(volatile unsigned short *)0xF010C)
#define SCR01 (*(volatile unsigned short *)0xF010E)
#define SE0 (*(volatile unsigned short *)0xF0110)
#define SE0L (*(volatile union un_se0l *)0xF0110).se0l
#define SE0L_bit (*(volatile union un_se0l *)0xF0110).BIT
#define SS0 (*(volatile unsigned short *)0xF0112)
#define SS0L (*(volatile union un_ss0l *)0xF0112).ss0l
#define SS0L_bit (*(volatile union un_ss0l *)0xF0112).BIT
#define ST0 (*(volatile unsigned short *)0xF0114)
#define ST0L (*(volatile union un_st0l *)0xF0114).st0l
#define ST0L_bit (*(volatile union un_st0l *)0xF0114).BIT
#define SPS0 (*(volatile unsigned short *)0xF0116)
#define SPS0L (*(volatile unsigned char *)0xF0116)
#define SO0 (*(volatile unsigned short *)0xF0118)
#define SOE0 (*(volatile unsigned short *)0xF011A)
#define SOE0L (*(volatile union un_soe0l *)0xF011A).soe0l
#define SOE0L_bit (*(volatile union un_soe0l *)0xF011A).BIT
#define SOL0 (*(volatile unsigned short *)0xF0120)
#define SOL0L (*(volatile unsigned char *)0xF0120)
#define SSE0 (*(volatile unsigned short *)0xF0122)
#define SSE0L (*(volatile unsigned char *)0xF0122)
#define TCR00 (*(volatile unsigned short *)0xF0180)
#define TCR01 (*(volatile unsigned short *)0xF0182)
#define TCR02 (*(volatile unsigned short *)0xF0184)
#define TCR03 (*(volatile unsigned short *)0xF0186)
#define TCR04 (*(volatile unsigned short *)0xF0188)
#define TCR05 (*(volatile unsigned short *)0xF018A)
#define TCR06 (*(volatile unsigned short *)0xF018C)
#define TCR07 (*(volatile unsigned short *)0xF018E)
#define TMR00 (*(volatile unsigned short *)0xF0190)
#define TMR01 (*(volatile unsigned short *)0xF0192)
#define TMR02 (*(volatile unsigned short *)0xF0194)
#define TMR03 (*(volatile unsigned short *)0xF0196)
#define TMR04 (*(volatile unsigned short *)0xF0198)
#define TMR05 (*(volatile unsigned short *)0xF019A)
#define TMR06 (*(volatile unsigned short *)0xF019C)
#define TMR07 (*(volatile unsigned short *)0xF019E)
#define TSR00 (*(volatile unsigned short *)0xF01A0)
#define TSR00L (*(volatile unsigned char *)0xF01A0)
#define TSR01 (*(volatile unsigned short *)0xF01A2)
#define TSR01L (*(volatile unsigned char *)0xF01A2)
#define TSR02 (*(volatile unsigned short *)0xF01A4)
#define TSR02L (*(volatile unsigned char *)0xF01A4)
#define TSR03 (*(volatile unsigned short *)0xF01A6)
#define TSR03L (*(volatile unsigned char *)0xF01A6)
#define TSR04 (*(volatile unsigned short *)0xF01A8)
#define TSR04L (*(volatile unsigned char *)0xF01A8)
#define TSR05 (*(volatile unsigned short *)0xF01AA)
#define TSR05L (*(volatile unsigned char *)0xF01AA)
#define TSR06 (*(volatile unsigned short *)0xF01AC)
#define TSR06L (*(volatile unsigned char *)0xF01AC)
#define TSR07 (*(volatile unsigned short *)0xF01AE)
#define TSR07L (*(volatile unsigned char *)0xF01AE)
#define TE0 (*(volatile unsigned short *)0xF01B0)
#define TE0L (*(volatile union un_te0l *)0xF01B0).te0l
#define TE0L_bit (*(volatile union un_te0l *)0xF01B0).BIT
#define TS0 (*(volatile unsigned short *)0xF01B2)
#define TS0L (*(volatile union un_ts0l *)0xF01B2).ts0l
#define TS0L_bit (*(volatile union un_ts0l *)0xF01B2).BIT
#define TT0 (*(volatile unsigned short *)0xF01B4)
#define TT0L (*(volatile union un_tt0l *)0xF01B4).tt0l
#define TT0L_bit (*(volatile union un_tt0l *)0xF01B4).BIT
#define TPS0 (*(volatile unsigned short *)0xF01B6)
#define TO0 (*(volatile unsigned short *)0xF01B8)
#define TO0L (*(volatile unsigned char *)0xF01B8)
#define TOE0 (*(volatile unsigned short *)0xF01BA)
#define TOE0L (*(volatile union un_toe0l *)0xF01BA).toe0l
#define TOE0L_bit (*(volatile union un_toe0l *)0xF01BA).BIT
#define TOL0 (*(volatile unsigned short *)0xF01BC)
#define TOL0L (*(volatile unsigned char *)0xF01BC)
#define TOM0 (*(volatile unsigned short *)0xF01BE)
#define TOM0L (*(volatile unsigned char *)0xF01BE)
#define ERADR (*(volatile unsigned short *)0xF0200)
#define ECCIER (*(volatile unsigned char *)0xF0202)
#define ECCER (*(volatile unsigned char *)0xF0203)
#define ECCTPR (*(volatile unsigned char *)0xF0204)
#define ECCTMDR (*(volatile unsigned char *)0xF0205)
#define ECCDWRVR (*(volatile unsigned short *)0xF0206)
#define PSRSEL (*(volatile union un_psrsel *)0xF0220).psrsel
#define PSRSEL_bit (*(volatile union un_psrsel *)0xF0220).BIT
#define PSNZCNT0 (*(volatile union un_psnzcnt0 *)0xF0222).psnzcnt0
#define PSNZCNT0_bit (*(volatile union un_psnzcnt0 *)0xF0222).BIT
#define PSNZCNT1 (*(volatile union un_psnzcnt1 *)0xF0223).psnzcnt1
#define PSNZCNT1_bit (*(volatile union un_psnzcnt1 *)0xF0223).BIT
#define PSNZCNT2 (*(volatile union un_psnzcnt2 *)0xF0224).psnzcnt2
#define PSNZCNT2_bit (*(volatile union un_psnzcnt2 *)0xF0224).BIT
#define PSNZCNT3 (*(volatile union un_psnzcnt3 *)0xF0225).psnzcnt3
#define PSNZCNT3_bit (*(volatile union un_psnzcnt3 *)0xF0225).BIT
#define PWMDLY0 (*(volatile unsigned short *)0xF0228)
#define PWMDLY1 (*(volatile unsigned short *)0xF022A)
#define TRJCR0 (*(volatile unsigned char *)0xF0240)
#define TRJIOC0 (*(volatile union un_trjioc0 *)0xF0241).trjioc0
#define TRJIOC0_bit (*(volatile union un_trjioc0 *)0xF0241).BIT
#define TRJMR0 (*(volatile union un_trjmr0 *)0xF0242).trjmr0
#define TRJMR0_bit (*(volatile union un_trjmr0 *)0xF0242).BIT
#define TRJISR0 (*(volatile union un_trjisr0 *)0xF0243).trjisr0
#define TRJISR0_bit (*(volatile union un_trjisr0 *)0xF0243).BIT
#define TRDSTR (*(volatile unsigned char *)0xF0263)
#define TRDMR (*(volatile union un_trdmr *)0xF0264).trdmr
#define TRDMR_bit (*(volatile union un_trdmr *)0xF0264).BIT
#define TRDPMR (*(volatile union un_trdpmr *)0xF0265).trdpmr
#define TRDPMR_bit (*(volatile union un_trdpmr *)0xF0265).BIT
#define TRDFCR (*(volatile union un_trdfcr *)0xF0266).trdfcr
#define TRDFCR_bit (*(volatile union un_trdfcr *)0xF0266).BIT
#define TRDOER1 (*(volatile union un_trdoer1 *)0xF0267).trdoer1
#define TRDOER1_bit (*(volatile union un_trdoer1 *)0xF0267).BIT
#define TRDOER2 (*(volatile union un_trdoer2 *)0xF0268).trdoer2
#define TRDOER2_bit (*(volatile union un_trdoer2 *)0xF0268).BIT
#define TRDOCR (*(volatile union un_trdocr *)0xF0269).trdocr
#define TRDOCR_bit (*(volatile union un_trdocr *)0xF0269).BIT
#define TRDDF0 (*(volatile union un_trddf0 *)0xF026A).trddf0
#define TRDDF0_bit (*(volatile union un_trddf0 *)0xF026A).BIT
#define TRDDF1 (*(volatile union un_trddf1 *)0xF026B).trddf1
#define TRDDF1_bit (*(volatile union un_trddf1 *)0xF026B).BIT
#define TRDCR0 (*(volatile union un_trdcr0 *)0xF0270).trdcr0
#define TRDCR0_bit (*(volatile union un_trdcr0 *)0xF0270).BIT
#define TRDIORA0 (*(volatile union un_trdiora0 *)0xF0271).trdiora0
#define TRDIORA0_bit (*(volatile union un_trdiora0 *)0xF0271).BIT
#define TRDIORC0 (*(volatile union un_trdiorc0 *)0xF0272).trdiorc0
#define TRDIORC0_bit (*(volatile union un_trdiorc0 *)0xF0272).BIT
#define TRDSR0 (*(volatile union un_trdsr0 *)0xF0273).trdsr0
#define TRDSR0_bit (*(volatile union un_trdsr0 *)0xF0273).BIT
#define TRDIER0 (*(volatile union un_trdier0 *)0xF0274).trdier0
#define TRDIER0_bit (*(volatile union un_trdier0 *)0xF0274).BIT
#define TRDPOCR0 (*(volatile union un_trdpocr0 *)0xF0275).trdpocr0
#define TRDPOCR0_bit (*(volatile union un_trdpocr0 *)0xF0275).BIT
#define TRD0 (*(volatile unsigned short *)0xF0276)
#define TRDGRA0 (*(volatile unsigned short *)0xF0278)
#define TRDGRB0 (*(volatile unsigned short *)0xF027A)
#define TRDCR1 (*(volatile union un_trdcr1 *)0xF0280).trdcr1
#define TRDCR1_bit (*(volatile union un_trdcr1 *)0xF0280).BIT
#define TRDIORA1 (*(volatile union un_trdiora1 *)0xF0281).trdiora1
#define TRDIORA1_bit (*(volatile union un_trdiora1 *)0xF0281).BIT
#define TRDIORC1 (*(volatile union un_trdiorc1 *)0xF0282).trdiorc1
#define TRDIORC1_bit (*(volatile union un_trdiorc1 *)0xF0282).BIT
#define TRDSR1 (*(volatile union un_trdsr1 *)0xF0283).trdsr1
#define TRDSR1_bit (*(volatile union un_trdsr1 *)0xF0283).BIT
#define TRDIER1 (*(volatile union un_trdier1 *)0xF0284).trdier1
#define TRDIER1_bit (*(volatile union un_trdier1 *)0xF0284).BIT
#define TRDPOCR1 (*(volatile union un_trdpocr1 *)0xF0285).trdpocr1
#define TRDPOCR1_bit (*(volatile union un_trdpocr1 *)0xF0285).BIT
#define TRD1 (*(volatile unsigned short *)0xF0286)
#define TRDGRA1 (*(volatile unsigned short *)0xF0288)
#define TRDGRB1 (*(volatile unsigned short *)0xF028A)
#define PER1 (*(volatile union un_per1 *)0xF02C0).per1
#define PER1_bit (*(volatile union un_per1 *)0xF02C0).BIT
#define PER2 (*(volatile union un_per2 *)0xF02C1).per2
#define PER2_bit (*(volatile union un_per2 *)0xF02C1).BIT
#define LINCKSEL (*(volatile union un_lincksel *)0xF02C3).lincksel
#define LINCKSEL_bit (*(volatile union un_lincksel *)0xF02C3).BIT
#define CKSEL (*(volatile union un_cksel *)0xF02C4).cksel
#define CKSEL_bit (*(volatile union un_cksel *)0xF02C4).BIT
#define PLLCTL (*(volatile union un_pllctl *)0xF02C5).pllctl
#define PLLCTL_bit (*(volatile union un_pllctl *)0xF02C5).BIT
#define PLLSTS (*(volatile union un_pllsts *)0xF02C6).pllsts
#define PLLSTS_bit (*(volatile union un_pllsts *)0xF02C6).BIT
#define MDIV (*(volatile unsigned char *)0xF02C7)
#define RTCCL (*(volatile union un_rtccl *)0xF02C8).rtccl
#define RTCCL_bit (*(volatile union un_rtccl *)0xF02C8).BIT
#define POCRES (*(volatile union un_pocres *)0xF02C9).pocres
#define POCRES_bit (*(volatile union un_pocres *)0xF02C9).BIT
#define STPSTC (*(volatile union un_stpstc *)0xF02CA).stpstc
#define STPSTC_bit (*(volatile union un_stpstc *)0xF02CA).BIT
#define HDTCCR0 (*(volatile union un_hdtccr0 *)0xF02D0).hdtccr0
#define HDTCCR0_bit (*(volatile union un_hdtccr0 *)0xF02D0).BIT
#define HDTCCT0 (*(volatile union un_hdtcct0 *)0xF02D2).hdtcct0
#define HDTCCT0_bit (*(volatile union un_hdtcct0 *)0xF02D2).BIT
#define HDTRLD0 (*(volatile union un_hdtrld0 *)0xF02D3).hdtrld0
#define HDTRLD0_bit (*(volatile union un_hdtrld0 *)0xF02D3).BIT
#define HDTSAR0 (*(volatile unsigned short *)0xF02D4)
#define HDTDAR0 (*(volatile unsigned short *)0xF02D6)
#define HDTCCR1 (*(volatile union un_hdtccr1 *)0xF02D8).hdtccr1
#define HDTCCR1_bit (*(volatile union un_hdtccr1 *)0xF02D8).BIT
#define HDTCCT1 (*(volatile union un_hdtcct1 *)0xF02DA).hdtcct1
#define HDTCCT1_bit (*(volatile union un_hdtcct1 *)0xF02DA).BIT
#define HDTRLD1 (*(volatile union un_hdtrld1 *)0xF02DB).hdtrld1
#define HDTRLD1_bit (*(volatile union un_hdtrld1 *)0xF02DB).BIT
#define HDTSAR1 (*(volatile unsigned short *)0xF02DC)
#define HDTDAR1 (*(volatile unsigned short *)0xF02DE)
#define DTCBAR (*(volatile unsigned char *)0xF02E0)
#define SELHS0 (*(volatile union un_selhs0 *)0xF02E1).selhs0
#define SELHS0_bit (*(volatile union un_selhs0 *)0xF02E1).BIT
#define SELHS1 (*(volatile union un_selhs1 *)0xF02E2).selhs1
#define SELHS1_bit (*(volatile union un_selhs1 *)0xF02E2).BIT
#define DTCEN0 (*(volatile union un_dtcen0 *)0xF02E8).dtcen0
#define DTCEN0_bit (*(volatile union un_dtcen0 *)0xF02E8).BIT
#define DTCEN1 (*(volatile union un_dtcen1 *)0xF02E9).dtcen1
#define DTCEN1_bit (*(volatile union un_dtcen1 *)0xF02E9).BIT
#define DTCEN2 (*(volatile union un_dtcen2 *)0xF02EA).dtcen2
#define DTCEN2_bit (*(volatile union un_dtcen2 *)0xF02EA).BIT
#define DTCEN3 (*(volatile union un_dtcen3 *)0xF02EB).dtcen3
#define DTCEN3_bit (*(volatile union un_dtcen3 *)0xF02EB).BIT
#define DTCEN4 (*(volatile union un_dtcen4 *)0xF02EC).dtcen4
#define DTCEN4_bit (*(volatile union un_dtcen4 *)0xF02EC).BIT
#define CRC0CTL (*(volatile union un_crc0ctl *)0xF02F0).crc0ctl
#define CRC0CTL_bit (*(volatile union un_crc0ctl *)0xF02F0).BIT
#define PGCRCL (*(volatile unsigned short *)0xF02F2)
#define CRCMD (*(volatile unsigned char *)0xF02F9)
#define CRCD (*(volatile unsigned short *)0xF02FA)
#define LWBR0 (*(volatile unsigned char *)0xF06C1)
#define LBRP0 (*(volatile unsigned short *)0xF06C2)
#define LBRP00 (*(volatile unsigned char *)0xF06C2)
#define LBRP01 (*(volatile unsigned char *)0xF06C3)
#define LSTC0 (*(volatile unsigned char *)0xF06C4)
#define LUSC0 (*(volatile unsigned char *)0xF06C5)
#define LMD0 (*(volatile unsigned char *)0xF06C8)
#define LBFC0 (*(volatile unsigned char *)0xF06C9)
#define LSC0 (*(volatile unsigned char *)0xF06CA)
#define LWUP0 (*(volatile unsigned char *)0xF06CB)
#define LIE0 (*(volatile unsigned char *)0xF06CC)
#define LEDE0 (*(volatile unsigned char *)0xF06CD)
#define LCUC0 (*(volatile unsigned char *)0xF06CE)
#define LTRC0 (*(volatile unsigned char *)0xF06D0)
#define LMST0 (*(volatile unsigned char *)0xF06D1)
#define LST0 (*(volatile unsigned char *)0xF06D2)
#define LEST0 (*(volatile unsigned char *)0xF06D3)
#define LDFC0 (*(volatile unsigned char *)0xF06D4)
#define LIDB0 (*(volatile unsigned char *)0xF06D5)
#define LCBR0 (*(volatile unsigned char *)0xF06D6)
#define LUDB00 (*(volatile unsigned char *)0xF06D7)
#define LDB01 (*(volatile unsigned char *)0xF06D8)
#define LDB02 (*(volatile unsigned char *)0xF06D9)
#define LDB03 (*(volatile unsigned char *)0xF06DA)
#define LDB04 (*(volatile unsigned char *)0xF06DB)
#define LDB05 (*(volatile unsigned char *)0xF06DC)
#define LDB06 (*(volatile unsigned char *)0xF06DD)
#define LDB07 (*(volatile unsigned char *)0xF06DE)
#define LDB08 (*(volatile unsigned char *)0xF06DF)
#define LUOER0 (*(volatile unsigned char *)0xF06E0)
#define LUOR01 (*(volatile unsigned char *)0xF06E1)
#define LUTDR0 (*(volatile unsigned short *)0xF06E4)
#define LUTDR0L (*(volatile unsigned char *)0xF06E4)
#define LUTDR0H (*(volatile unsigned char *)0xF06E5)
#define LURDR0 (*(volatile unsigned short *)0xF06E6)
#define LURDR0L (*(volatile unsigned char *)0xF06E6)
#define LURDR0H (*(volatile unsigned char *)0xF06E7)
#define LUWTDR0 (*(volatile unsigned short *)0xF06E8)
#define LUWTDR0L (*(volatile unsigned char *)0xF06E8)
#define LUWTDR0H (*(volatile unsigned char *)0xF06E9)
#define TRJ0 (*(volatile unsigned short *)0xF06F0)
#define ADTRGS0 (*(volatile union un_adtrgs0 *)0xF0789).adtrgs0
#define ADTRGS0_bit (*(volatile union un_adtrgs0 *)0xF0789).BIT
#define ADTRGS1 (*(volatile union un_adtrgs1 *)0xF078D).adtrgs1
#define ADTRGS1_bit (*(volatile union un_adtrgs1 *)0xF078D).BIT

/*
 Sfr bits
 */
#define ADTYP ADM2_bit.no0
#define AWC ADM2_bit.no2
#define ADRCK ADM2_bit.no3
#define DFLEN DFLCTL_bit.no0
#define TAU0EN PER0_bit.no0
#define SAU0EN PER0_bit.no2
#define ADCEN PER0_bit.no5
#define RTCEN PER0_bit.no7
#define TRDSYNC TRDMR_bit.no0
#define TRDBFC0 TRDMR_bit.no4
#define TRDBFD0 TRDMR_bit.no5
#define TRDBFC1 TRDMR_bit.no6
#define TRDBFD1 TRDMR_bit.no7
#define TRDPWMB0 TRDPMR_bit.no0
#define TRDPWMC0 TRDPMR_bit.no1
#define TRDPWMD0 TRDPMR_bit.no2
#define TRDPWMB1 TRDPMR_bit.no4
#define TRDPWMC1 TRDPMR_bit.no5
#define TRDPWMD1 TRDPMR_bit.no6
#define TRDSHUTS TRDOER2_bit.no0
#define TRDPTO TRDOER2_bit.no7
#define TRJ0EN PER1_bit.no0
#define DTCEN PER1_bit.no3
#define TRD0EN PER1_bit.no4
#define LIN0EN PER2_bit.no2
#define LIN0MCK LINCKSEL_bit.no0
#define LIN0MCKE LINCKSEL_bit.no4
#define SELLOSC CKSEL_bit.no0
#define TRD_CKSEL CKSEL_bit.no2
#define PLLON PLLCTL_bit.no0
#define PLLMUL PLLCTL_bit.no1
#define SELPLL PLLCTL_bit.no2
#define PLLDIV0 PLLCTL_bit.no4
#define PLLDIV1 PLLCTL_bit.no5
#define LCKSEL0 PLLCTL_bit.no6
#define LCKSEL1 PLLCTL_bit.no7
#define SELPLLS PLLSTS_bit.no3
#define LOCK PLLSTS_bit.no7
#define POCRES0 POCRES_bit.no0
#define CLKRF POCRES_bit.no4
#define STPLV STPSTC_bit.no4
#define STPOEN STPSTC_bit.no7
#define HMODE0 HDTCCR0_bit.no0
#define HRPTSEL0 HDTCCR0_bit.no1
#define HSAMOD0 HDTCCR0_bit.no2
#define HDAMOD0 HDTCCR0_bit.no3
#define HCHNE0 HDTCCR0_bit.no4
#define HRPTINT0 HDTCCR0_bit.no5
#define HSZ0 HDTCCR0_bit.no6
#define HMODE1 HDTCCR1_bit.no0
#define HRPTSEL1 HDTCCR1_bit.no1
#define HSAMOD1 HDTCCR1_bit.no2
#define HDAMOD1 HDTCCR1_bit.no3
#define HCHNE1 HDTCCR1_bit.no4
#define HRPTINT1 HDTCCR1_bit.no5
#define HSZ1 HDTCCR1_bit.no6
#define DTCEN00 DTCEN0_bit.no0
#define DTCEN01 DTCEN0_bit.no1
#define DTCEN02 DTCEN0_bit.no2
#define DTCEN03 DTCEN0_bit.no3
#define DTCEN04 DTCEN0_bit.no4
#define DTCEN05 DTCEN0_bit.no5
#define DTCEN06 DTCEN0_bit.no6
#define DTCEN10 DTCEN1_bit.no0
#define DTCEN11 DTCEN1_bit.no1
#define DTCEN14 DTCEN1_bit.no4
#define DTCEN15 DTCEN1_bit.no5
#define DTCEN16 DTCEN1_bit.no6
#define DTCEN17 DTCEN1_bit.no7
#define DTCEN20 DTCEN2_bit.no0
#define DTCEN21 DTCEN2_bit.no1
#define DTCEN22 DTCEN2_bit.no2
#define DTCEN23 DTCEN2_bit.no3
#define DTCEN24 DTCEN2_bit.no4
#define DTCEN25 DTCEN2_bit.no5
#define DTCEN30 DTCEN3_bit.no0
#define DTCEN31 DTCEN3_bit.no1
#define DTCEN32 DTCEN3_bit.no2
#define DTCEN33 DTCEN3_bit.no3
#define DTCEN34 DTCEN3_bit.no4
#define DTCEN35 DTCEN3_bit.no5
#define DTCEN36 DTCEN3_bit.no6
#define DTCEN37 DTCEN3_bit.no7
#define DTCEN45 DTCEN4_bit.no5
#define DTCEN46 DTCEN4_bit.no6
#define DTCEN47 DTCEN4_bit.no7
#define CRC0EN CRC0CTL_bit.no7

/*
 Interrupt vector addresses
 */
#endif
