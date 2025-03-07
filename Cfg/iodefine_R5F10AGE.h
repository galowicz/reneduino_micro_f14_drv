/************************************************************************/
/* Header file generated from device file:                              */
/*    DR5F10AGE.DVF                                                     */
/*    V1.11b (2022/09/15)                                               */
/*    Copyright(C) 2022 Renesas                                         */
/* Tool Version: 4.0.5                                                  */
/* Date Generated: 2021/03/09                                           */
/************************************************************************/

#ifndef __INTRINSIC_FUNCTIONS
#define __INTRINSIC_FUNCTIONS

#define DI() __builtin_rl78_di()
#define EI() __builtin_rl78_ei()
#define HALT() __halt()
#define NOP() __nop()
#define STOP() __stop()

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

#ifndef IODEFINE_H
#define IODEFINE_H

/*
 IO Registers
 */
union un_p0 {
	unsigned char p0;
	__BITS8 BIT;
};
union un_p1 {
	unsigned char p1;
	__BITS8 BIT;
};
union un_p3 {
	unsigned char p3;
	__BITS8 BIT;
};
union un_p4 {
	unsigned char p4;
	__BITS8 BIT;
};
union un_p6 {
	unsigned char p6;
	__BITS8 BIT;
};
union un_p7 {
	unsigned char p7;
	__BITS8 BIT;
};
union un_p8 {
	unsigned char p8;
	__BITS8 BIT;
};
union un_p9 {
	unsigned char p9;
	__BITS8 BIT;
};
union un_p12 {
	unsigned char p12;
	__BITS8 BIT;
};
union un_p13 {
	unsigned char p13;
	__BITS8 BIT;
};
union un_p14 {
	unsigned char p14;
	__BITS8 BIT;
};
union un_pm0 {
	unsigned char pm0;
	__BITS8 BIT;
};
union un_pm1 {
	unsigned char pm1;
	__BITS8 BIT;
};
union un_pm3 {
	unsigned char pm3;
	__BITS8 BIT;
};
union un_pm4 {
	unsigned char pm4;
	__BITS8 BIT;
};
union un_pm6 {
	unsigned char pm6;
	__BITS8 BIT;
};
union un_pm7 {
	unsigned char pm7;
	__BITS8 BIT;
};
union un_pm8 {
	unsigned char pm8;
	__BITS8 BIT;
};
union un_pm9 {
	unsigned char pm9;
	__BITS8 BIT;
};
union un_pm12 {
	unsigned char pm12;
	__BITS8 BIT;
};
union un_pm14 {
	unsigned char pm14;
	__BITS8 BIT;
};
union un_adm0 {
	unsigned char adm0;
	__BITS8 BIT;
};
union un_ads {
	unsigned char ads;
	__BITS8 BIT;
};
union un_adm1 {
	unsigned char adm1;
	__BITS8 BIT;
};
union un_krm {
	unsigned char krm;
	__BITS8 BIT;
};
union un_egp0 {
	unsigned char egp0;
	__BITS8 BIT;
};
union un_egn0 {
	unsigned char egn0;
	__BITS8 BIT;
};
union un_egp1 {
	unsigned char egp1;
	__BITS8 BIT;
};
union un_egn1 {
	unsigned char egn1;
	__BITS8 BIT;
};
union un_rtcc0 {
	unsigned char rtcc0;
	__BITS8 BIT;
};
union un_rtcc1 {
	unsigned char rtcc1;
	__BITS8 BIT;
};
union un_csc {
	unsigned char csc;
	__BITS8 BIT;
};
union un_ostc {
	unsigned char ostc;
	__BITS8 BIT;
};
union un_ckc {
	unsigned char ckc;
	__BITS8 BIT;
};
union un_cks0 {
	unsigned char cks0;
	__BITS8 BIT;
};
union un_lvim {
	unsigned char lvim;
	__BITS8 BIT;
};
union un_lvis {
	unsigned char lvis;
	__BITS8 BIT;
};
union un_if2 {
	unsigned short if2;
	__BITS16 BIT;
};
union un_if2l {
	unsigned char if2l;
	__BITS8 BIT;
};
union un_if2h {
	unsigned char if2h;
	__BITS8 BIT;
};
union un_mk2 {
	unsigned short mk2;
	__BITS16 BIT;
};
union un_mk2l {
	unsigned char mk2l;
	__BITS8 BIT;
};
union un_mk2h {
	unsigned char mk2h;
	__BITS8 BIT;
};
union un_pr02 {
	unsigned short pr02;
	__BITS16 BIT;
};
union un_pr02l {
	unsigned char pr02l;
	__BITS8 BIT;
};
union un_pr02h {
	unsigned char pr02h;
	__BITS8 BIT;
};
union un_pr12 {
	unsigned short pr12;
	__BITS16 BIT;
};
union un_pr12l {
	unsigned char pr12l;
	__BITS8 BIT;
};
union un_pr12h {
	unsigned char pr12h;
	__BITS8 BIT;
};
union un_if0 {
	unsigned short if0;
	__BITS16 BIT;
};
union un_if0l {
	unsigned char if0l;
	__BITS8 BIT;
};
union un_if0h {
	unsigned char if0h;
	__BITS8 BIT;
};
union un_if1 {
	unsigned short if1;
	__BITS16 BIT;
};
union un_if1l {
	unsigned char if1l;
	__BITS8 BIT;
};
union un_if1h {
	unsigned char if1h;
	__BITS8 BIT;
};
union un_mk0 {
	unsigned short mk0;
	__BITS16 BIT;
};
union un_mk0l {
	unsigned char mk0l;
	__BITS8 BIT;
};
union un_mk0h {
	unsigned char mk0h;
	__BITS8 BIT;
};
union un_mk1 {
	unsigned short mk1;
	__BITS16 BIT;
};
union un_mk1l {
	unsigned char mk1l;
	__BITS8 BIT;
};
union un_mk1h {
	unsigned char mk1h;
	__BITS8 BIT;
};
union un_pr00 {
	unsigned short pr00;
	__BITS16 BIT;
};
union un_pr00l {
	unsigned char pr00l;
	__BITS8 BIT;
};
union un_pr00h {
	unsigned char pr00h;
	__BITS8 BIT;
};
union un_pr01 {
	unsigned short pr01;
	__BITS16 BIT;
};
union un_pr01l {
	unsigned char pr01l;
	__BITS8 BIT;
};
union un_pr01h {
	unsigned char pr01h;
	__BITS8 BIT;
};
union un_pr10 {
	unsigned short pr10;
	__BITS16 BIT;
};
union un_pr10l {
	unsigned char pr10l;
	__BITS8 BIT;
};
union un_pr10h {
	unsigned char pr10h;
	__BITS8 BIT;
};
union un_pr11 {
	unsigned short pr11;
	__BITS16 BIT;
};
union un_pr11l {
	unsigned char pr11l;
	__BITS8 BIT;
};
union un_pr11h {
	unsigned char pr11h;
	__BITS8 BIT;
};
union un_pmc {
	unsigned char pmc;
	__BITS8 BIT;
};

#define P0 (*(volatile union un_p0 *)0xFFF00).p0
#define P0_bit (*(volatile union un_p0 *)0xFFF00).BIT
#define P1 (*(volatile union un_p1 *)0xFFF01).p1
#define P1_bit (*(volatile union un_p1 *)0xFFF01).BIT
#define P3 (*(volatile union un_p3 *)0xFFF03).p3
#define P3_bit (*(volatile union un_p3 *)0xFFF03).BIT
#define P4 (*(volatile union un_p4 *)0xFFF04).p4
#define P4_bit (*(volatile union un_p4 *)0xFFF04).BIT
#define P6 (*(volatile union un_p6 *)0xFFF06).p6
#define P6_bit (*(volatile union un_p6 *)0xFFF06).BIT
#define P7 (*(volatile union un_p7 *)0xFFF07).p7
#define P7_bit (*(volatile union un_p7 *)0xFFF07).BIT
#define P8 (*(volatile union un_p8 *)0xFFF08).p8
#define P8_bit (*(volatile union un_p8 *)0xFFF08).BIT
#define P9 (*(volatile union un_p9 *)0xFFF09).p9
#define P9_bit (*(volatile union un_p9 *)0xFFF09).BIT
#define P12 (*(volatile union un_p12 *)0xFFF0C).p12
#define P12_bit (*(volatile union un_p12 *)0xFFF0C).BIT
#define P13 (*(volatile union un_p13 *)0xFFF0D).p13
#define P13_bit (*(volatile union un_p13 *)0xFFF0D).BIT
#define P14 (*(volatile union un_p14 *)0xFFF0E).p14
#define P14_bit (*(volatile union un_p14 *)0xFFF0E).BIT
#define SDR00 (*(volatile unsigned short *)0xFFF10)
#define SDR00L (*(volatile unsigned char *)0xFFF10)
#define SDR01 (*(volatile unsigned short *)0xFFF12)
#define SDR01L (*(volatile unsigned char *)0xFFF12)
#define TDR00 (*(volatile unsigned short *)0xFFF18)
#define TDR01 (*(volatile unsigned short *)0xFFF1A)
#define TDR01L (*(volatile unsigned char *)0xFFF1A)
#define TDR01H (*(volatile unsigned char *)0xFFF1B)
#define ADCR (*(volatile unsigned short *)0xFFF1E)
#define ADCRH (*(volatile unsigned char *)0xFFF1F)
#define PM0 (*(volatile union un_pm0 *)0xFFF20).pm0
#define PM0_bit (*(volatile union un_pm0 *)0xFFF20).BIT
#define PM1 (*(volatile union un_pm1 *)0xFFF21).pm1
#define PM1_bit (*(volatile union un_pm1 *)0xFFF21).BIT
#define PM3 (*(volatile union un_pm3 *)0xFFF23).pm3
#define PM3_bit (*(volatile union un_pm3 *)0xFFF23).BIT
#define PM4 (*(volatile union un_pm4 *)0xFFF24).pm4
#define PM4_bit (*(volatile union un_pm4 *)0xFFF24).BIT
#define PM6 (*(volatile union un_pm6 *)0xFFF26).pm6
#define PM6_bit (*(volatile union un_pm6 *)0xFFF26).BIT
#define PM7 (*(volatile union un_pm7 *)0xFFF27).pm7
#define PM7_bit (*(volatile union un_pm7 *)0xFFF27).BIT
#define PM8 (*(volatile union un_pm8 *)0xFFF28).pm8
#define PM8_bit (*(volatile union un_pm8 *)0xFFF28).BIT
#define PM9 (*(volatile union un_pm9 *)0xFFF29).pm9
#define PM9_bit (*(volatile union un_pm9 *)0xFFF29).BIT
#define PM12 (*(volatile union un_pm12 *)0xFFF2C).pm12
#define PM12_bit (*(volatile union un_pm12 *)0xFFF2C).BIT
#define PM14 (*(volatile union un_pm14 *)0xFFF2E).pm14
#define PM14_bit (*(volatile union un_pm14 *)0xFFF2E).BIT
#define ADM0 (*(volatile union un_adm0 *)0xFFF30).adm0
#define ADM0_bit (*(volatile union un_adm0 *)0xFFF30).BIT
#define ADS (*(volatile union un_ads *)0xFFF31).ads
#define ADS_bit (*(volatile union un_ads *)0xFFF31).BIT
#define ADM1 (*(volatile union un_adm1 *)0xFFF32).adm1
#define ADM1_bit (*(volatile union un_adm1 *)0xFFF32).BIT
#define KRM (*(volatile union un_krm *)0xFFF37).krm
#define KRM_bit (*(volatile union un_krm *)0xFFF37).BIT
#define EGP0 (*(volatile union un_egp0 *)0xFFF38).egp0
#define EGP0_bit (*(volatile union un_egp0 *)0xFFF38).BIT
#define EGN0 (*(volatile union un_egn0 *)0xFFF39).egn0
#define EGN0_bit (*(volatile union un_egn0 *)0xFFF39).BIT
#define EGP1 (*(volatile union un_egp1 *)0xFFF3A).egp1
#define EGP1_bit (*(volatile union un_egp1 *)0xFFF3A).BIT
#define EGN1 (*(volatile union un_egn1 *)0xFFF3B).egn1
#define EGN1_bit (*(volatile union un_egn1 *)0xFFF3B).BIT
#define SUBCUDW (*(volatile unsigned short *)0xFFF54)
#define TRDGRC0 (*(volatile unsigned short *)0xFFF58)
#define TRDGRD0 (*(volatile unsigned short *)0xFFF5A)
#define TRDGRC1 (*(volatile unsigned short *)0xFFF5C)
#define TRDGRD1 (*(volatile unsigned short *)0xFFF5E)
#define TDR02 (*(volatile unsigned short *)0xFFF64)
#define TDR03 (*(volatile unsigned short *)0xFFF66)
#define TDR03L (*(volatile unsigned char *)0xFFF66)
#define TDR03H (*(volatile unsigned char *)0xFFF67)
#define TDR04 (*(volatile unsigned short *)0xFFF68)
#define TDR05 (*(volatile unsigned short *)0xFFF6A)
#define TDR06 (*(volatile unsigned short *)0xFFF6C)
#define TDR07 (*(volatile unsigned short *)0xFFF6E)
#define SEC (*(volatile unsigned char *)0xFFF92)
#define MIN (*(volatile unsigned char *)0xFFF93)
#define HOUR (*(volatile unsigned char *)0xFFF94)
#define WEEK (*(volatile unsigned char *)0xFFF95)
#define DAY (*(volatile unsigned char *)0xFFF96)
#define MONTH (*(volatile unsigned char *)0xFFF97)
#define YEAR (*(volatile unsigned char *)0xFFF98)
#define SUBCUD (*(volatile unsigned char *)0xFFF99)
#define ALARMWM (*(volatile unsigned char *)0xFFF9A)
#define ALARMWH (*(volatile unsigned char *)0xFFF9B)
#define ALARMWW (*(volatile unsigned char *)0xFFF9C)
#define RTCC0 (*(volatile union un_rtcc0 *)0xFFF9D).rtcc0
#define RTCC0_bit (*(volatile union un_rtcc0 *)0xFFF9D).BIT
#define RTCC1 (*(volatile union un_rtcc1 *)0xFFF9E).rtcc1
#define RTCC1_bit (*(volatile union un_rtcc1 *)0xFFF9E).BIT
#define CMC (*(volatile unsigned char *)0xFFFA0)
#define CSC (*(volatile union un_csc *)0xFFFA1).csc
#define CSC_bit (*(volatile union un_csc *)0xFFFA1).BIT
#define OSTC (*(volatile union un_ostc *)0xFFFA2).ostc
#define OSTC_bit (*(volatile union un_ostc *)0xFFFA2).BIT
#define OSTS (*(volatile unsigned char *)0xFFFA3)
#define CKC (*(volatile union un_ckc *)0xFFFA4).ckc
#define CKC_bit (*(volatile union un_ckc *)0xFFFA4).BIT
#define CKS0 (*(volatile union un_cks0 *)0xFFFA5).cks0
#define CKS0_bit (*(volatile union un_cks0 *)0xFFFA5).BIT
#define RESF (*(volatile unsigned char *)0xFFFA8)
#define LVIM (*(volatile union un_lvim *)0xFFFA9).lvim
#define LVIM_bit (*(volatile union un_lvim *)0xFFFA9).BIT
#define LVIS (*(volatile union un_lvis *)0xFFFAA).lvis
#define LVIS_bit (*(volatile union un_lvis *)0xFFFAA).BIT
#define WDTE (*(volatile unsigned char *)0xFFFAB)
#define CRCIN (*(volatile unsigned char *)0xFFFAC)
#define IF2 (*(volatile union un_if2 *)0xFFFD0).if2
#define IF2_bit (*(volatile union un_if2 *)0xFFFD0).BIT
#define IF2L (*(volatile union un_if2l *)0xFFFD0).if2l
#define IF2L_bit (*(volatile union un_if2l *)0xFFFD0).BIT
#define IF2H (*(volatile union un_if2h *)0xFFFD1).if2h
#define IF2H_bit (*(volatile union un_if2h *)0xFFFD1).BIT
#define MK2 (*(volatile union un_mk2 *)0xFFFD4).mk2
#define MK2_bit (*(volatile union un_mk2 *)0xFFFD4).BIT
#define MK2L (*(volatile union un_mk2l *)0xFFFD4).mk2l
#define MK2L_bit (*(volatile union un_mk2l *)0xFFFD4).BIT
#define MK2H (*(volatile union un_mk2h *)0xFFFD5).mk2h
#define MK2H_bit (*(volatile union un_mk2h *)0xFFFD5).BIT
#define PR02 (*(volatile union un_pr02 *)0xFFFD8).pr02
#define PR02_bit (*(volatile union un_pr02 *)0xFFFD8).BIT
#define PR02L (*(volatile union un_pr02l *)0xFFFD8).pr02l
#define PR02L_bit (*(volatile union un_pr02l *)0xFFFD8).BIT
#define PR02H (*(volatile union un_pr02h *)0xFFFD9).pr02h
#define PR02H_bit (*(volatile union un_pr02h *)0xFFFD9).BIT
#define PR12 (*(volatile union un_pr12 *)0xFFFDC).pr12
#define PR12_bit (*(volatile union un_pr12 *)0xFFFDC).BIT
#define PR12L (*(volatile union un_pr12l *)0xFFFDC).pr12l
#define PR12L_bit (*(volatile union un_pr12l *)0xFFFDC).BIT
#define PR12H (*(volatile union un_pr12h *)0xFFFDD).pr12h
#define PR12H_bit (*(volatile union un_pr12h *)0xFFFDD).BIT
#define IF0 (*(volatile union un_if0 *)0xFFFE0).if0
#define IF0_bit (*(volatile union un_if0 *)0xFFFE0).BIT
#define IF0L (*(volatile union un_if0l *)0xFFFE0).if0l
#define IF0L_bit (*(volatile union un_if0l *)0xFFFE0).BIT
#define IF0H (*(volatile union un_if0h *)0xFFFE1).if0h
#define IF0H_bit (*(volatile union un_if0h *)0xFFFE1).BIT
#define IF1 (*(volatile union un_if1 *)0xFFFE2).if1
#define IF1_bit (*(volatile union un_if1 *)0xFFFE2).BIT
#define IF1L (*(volatile union un_if1l *)0xFFFE2).if1l
#define IF1L_bit (*(volatile union un_if1l *)0xFFFE2).BIT
#define IF1H (*(volatile union un_if1h *)0xFFFE3).if1h
#define IF1H_bit (*(volatile union un_if1h *)0xFFFE3).BIT
#define MK0 (*(volatile union un_mk0 *)0xFFFE4).mk0
#define MK0_bit (*(volatile union un_mk0 *)0xFFFE4).BIT
#define MK0L (*(volatile union un_mk0l *)0xFFFE4).mk0l
#define MK0L_bit (*(volatile union un_mk0l *)0xFFFE4).BIT
#define MK0H (*(volatile union un_mk0h *)0xFFFE5).mk0h
#define MK0H_bit (*(volatile union un_mk0h *)0xFFFE5).BIT
#define MK1 (*(volatile union un_mk1 *)0xFFFE6).mk1
#define MK1_bit (*(volatile union un_mk1 *)0xFFFE6).BIT
#define MK1L (*(volatile union un_mk1l *)0xFFFE6).mk1l
#define MK1L_bit (*(volatile union un_mk1l *)0xFFFE6).BIT
#define MK1H (*(volatile union un_mk1h *)0xFFFE7).mk1h
#define MK1H_bit (*(volatile union un_mk1h *)0xFFFE7).BIT
#define PR00 (*(volatile union un_pr00 *)0xFFFE8).pr00
#define PR00_bit (*(volatile union un_pr00 *)0xFFFE8).BIT
#define PR00L (*(volatile union un_pr00l *)0xFFFE8).pr00l
#define PR00L_bit (*(volatile union un_pr00l *)0xFFFE8).BIT
#define PR00H (*(volatile union un_pr00h *)0xFFFE9).pr00h
#define PR00H_bit (*(volatile union un_pr00h *)0xFFFE9).BIT
#define PR01 (*(volatile union un_pr01 *)0xFFFEA).pr01
#define PR01_bit (*(volatile union un_pr01 *)0xFFFEA).BIT
#define PR01L (*(volatile union un_pr01l *)0xFFFEA).pr01l
#define PR01L_bit (*(volatile union un_pr01l *)0xFFFEA).BIT
#define PR01H (*(volatile union un_pr01h *)0xFFFEB).pr01h
#define PR01H_bit (*(volatile union un_pr01h *)0xFFFEB).BIT
#define PR10 (*(volatile union un_pr10 *)0xFFFEC).pr10
#define PR10_bit (*(volatile union un_pr10 *)0xFFFEC).BIT
#define PR10L (*(volatile union un_pr10l *)0xFFFEC).pr10l
#define PR10L_bit (*(volatile union un_pr10l *)0xFFFEC).BIT
#define PR10H (*(volatile union un_pr10h *)0xFFFED).pr10h
#define PR10H_bit (*(volatile union un_pr10h *)0xFFFED).BIT
#define PR11 (*(volatile union un_pr11 *)0xFFFEE).pr11
#define PR11_bit (*(volatile union un_pr11 *)0xFFFEE).BIT
#define PR11L (*(volatile union un_pr11l *)0xFFFEE).pr11l
#define PR11L_bit (*(volatile union un_pr11l *)0xFFFEE).BIT
#define PR11H (*(volatile union un_pr11h *)0xFFFEF).pr11h
#define PR11H_bit (*(volatile union un_pr11h *)0xFFFEF).BIT
#define MACRL (*(volatile unsigned short *)0xFFFF0)
#define MACRH (*(volatile unsigned short *)0xFFFF2)
#define PMC (*(volatile union un_pmc *)0xFFFFE).pmc
#define PMC_bit (*(volatile union un_pmc *)0xFFFFE).BIT

/*
 Sfr bits
 */
#define ADCE ADM0_bit.no0
#define ADCS ADM0_bit.no7
#define RCLOE1 RTCC0_bit.no5
#define RTCE RTCC0_bit.no7
#define RWAIT RTCC1_bit.no0
#define RWST RTCC1_bit.no1
#define RIFG RTCC1_bit.no3
#define WAFG RTCC1_bit.no4
#define WALIE RTCC1_bit.no6
#define WALE RTCC1_bit.no7
#define HIOSTOP CSC_bit.no0
#define XTSTOP CSC_bit.no6
#define MSTOP CSC_bit.no7
#define MCM0 CKC_bit.no4
#define MCS CKC_bit.no5
#define CSS CKC_bit.no6
#define CLS CKC_bit.no7
#define PCLOE0 CKS0_bit.no7
#define LVIF LVIM_bit.no0
#define LVIOMSK LVIM_bit.no1
#define LVISEN LVIM_bit.no7
#define LVILV LVIS_bit.no0
#define LVIMD LVIS_bit.no7
#define TMIF05 IF2L_bit.no0
#define TMIF06 IF2L_bit.no1
#define TMIF07 IF2L_bit.no2
#define LIN0WUPIF IF2L_bit.no3
#define KRIF IF2L_bit.no4
#define FLIF IF2H_bit.no7
#define TMMK05 MK2L_bit.no0
#define TMMK06 MK2L_bit.no1
#define TMMK07 MK2L_bit.no2
#define LIN0WUPMK MK2L_bit.no3
#define KRMK MK2L_bit.no4
#define FLMK MK2H_bit.no7
#define TMPR005 PR02L_bit.no0
#define TMPR006 PR02L_bit.no1
#define TMPR007 PR02L_bit.no2
#define LIN0WUPPR0 PR02L_bit.no3
#define KRPR0 PR02L_bit.no4
#define FLPR0 PR02H_bit.no7
#define TMPR105 PR12L_bit.no0
#define TMPR106 PR12L_bit.no1
#define TMPR107 PR12L_bit.no2
#define LIN0WUPPR1 PR12L_bit.no3
#define KRPR1 PR12L_bit.no4
#define FLPR1 PR12H_bit.no7
#define WDTIIF IF0L_bit.no0
#define LVIIF IF0L_bit.no1
#define PIF0 IF0L_bit.no2
#define PIF1 IF0L_bit.no3
#define PIF2 IF0L_bit.no4
#define PIF3 IF0L_bit.no5
#define PIF4 IF0L_bit.no6
#define SPMIF IF0L_bit.no6
#define PIF5 IF0L_bit.no7
#define CLMIF IF0H_bit.no0
#define CSIIF00 IF0H_bit.no1
#define IICIF00 IF0H_bit.no1
#define STIF0 IF0H_bit.no1
#define CSIIF01 IF0H_bit.no2
#define IICIF01 IF0H_bit.no2
#define SRIF0 IF0H_bit.no2
#define TRDIF0 IF0H_bit.no3
#define TRDIF1 IF0H_bit.no4
#define TRJIF0 IF0H_bit.no5
#define RAMIF IF0H_bit.no6
#define LIN0TRMIF IF0H_bit.no7
#define LIN0RVCIF IF1L_bit.no0
#define LIN0IF IF1L_bit.no1
#define LIN0STAIF IF1L_bit.no1
#define RTCIF IF1L_bit.no3
#define TMIF00 IF1L_bit.no4
#define TMIF01 IF1L_bit.no5
#define TMIF02 IF1L_bit.no6
#define TMIF03 IF1L_bit.no7
#define ADIF IF1H_bit.no0
#define PIF6 IF1H_bit.no1
#define PIF7 IF1H_bit.no2
#define TMIF01H IF1H_bit.no3
#define TMIF03H IF1H_bit.no4
#define TMIF04 IF1H_bit.no7
#define WDTIMK MK0L_bit.no0
#define LVIMK MK0L_bit.no1
#define PMK0 MK0L_bit.no2
#define PMK1 MK0L_bit.no3
#define PMK2 MK0L_bit.no4
#define PMK3 MK0L_bit.no5
#define PMK4 MK0L_bit.no6
#define SPMMK MK0L_bit.no6
#define PMK5 MK0L_bit.no7
#define CLMMK MK0H_bit.no0
#define CSIMK00 MK0H_bit.no1
#define IICMK00 MK0H_bit.no1
#define STMK0 MK0H_bit.no1
#define CSIMK01 MK0H_bit.no2
#define IICMK01 MK0H_bit.no2
#define SRMK0 MK0H_bit.no2
#define TRDMK0 MK0H_bit.no3
#define TRDMK1 MK0H_bit.no4
#define TRJMK0 MK0H_bit.no5
#define RAMMK MK0H_bit.no6
#define LIN0TRMMK MK0H_bit.no7
#define LIN0RVCMK MK1L_bit.no0
#define LIN0MK MK1L_bit.no1
#define LIN0STAMK MK1L_bit.no1
#define RTCMK MK1L_bit.no3
#define TMMK00 MK1L_bit.no4
#define TMMK01 MK1L_bit.no5
#define TMMK02 MK1L_bit.no6
#define TMMK03 MK1L_bit.no7
#define ADMK MK1H_bit.no0
#define PMK6 MK1H_bit.no1
#define PMK7 MK1H_bit.no2
#define TMMK01H MK1H_bit.no3
#define TMMK03H MK1H_bit.no4
#define TMMK04 MK1H_bit.no7
#define WDTIPR0 PR00L_bit.no0
#define LVIPR0 PR00L_bit.no1
#define PPR00 PR00L_bit.no2
#define PPR01 PR00L_bit.no3
#define PPR02 PR00L_bit.no4
#define PPR03 PR00L_bit.no5
#define PPR04 PR00L_bit.no6
#define SPMPR0 PR00L_bit.no6
#define PPR05 PR00L_bit.no7
#define CLMPR0 PR00H_bit.no0
#define CSIPR000 PR00H_bit.no1
#define IICPR000 PR00H_bit.no1
#define STPR00 PR00H_bit.no1
#define CSIPR001 PR00H_bit.no2
#define IICPR001 PR00H_bit.no2
#define SRPR00 PR00H_bit.no2
#define TRDPR00 PR00H_bit.no3
#define TRDPR01 PR00H_bit.no4
#define TRJPR00 PR00H_bit.no5
#define RAMPR0 PR00H_bit.no6
#define LIN0TRMPR0 PR00H_bit.no7
#define LIN0RVCPR0 PR01L_bit.no0
#define LIN0PR0 PR01L_bit.no1
#define LIN0STAPR0 PR01L_bit.no1
#define RTCPR0 PR01L_bit.no3
#define TMPR000 PR01L_bit.no4
#define TMPR001 PR01L_bit.no5
#define TMPR002 PR01L_bit.no6
#define TMPR003 PR01L_bit.no7
#define ADPR0 PR01H_bit.no0
#define PPR06 PR01H_bit.no1
#define PPR07 PR01H_bit.no2
#define TMPR001H PR01H_bit.no3
#define TMPR003H PR01H_bit.no4
#define TMPR004 PR01H_bit.no7
#define WDTIPR1 PR10L_bit.no0
#define LVIPR1 PR10L_bit.no1
#define PPR10 PR10L_bit.no2
#define PPR11 PR10L_bit.no3
#define PPR12 PR10L_bit.no4
#define PPR13 PR10L_bit.no5
#define PPR14 PR10L_bit.no6
#define SPMPR1 PR10L_bit.no6
#define PPR15 PR10L_bit.no7
#define CLMPR1 PR10H_bit.no0
#define CSIPR100 PR10H_bit.no1
#define IICPR100 PR10H_bit.no1
#define STPR10 PR10H_bit.no1
#define CSIPR101 PR10H_bit.no2
#define IICPR101 PR10H_bit.no2
#define SRPR10 PR10H_bit.no2
#define TRDPR10 PR10H_bit.no3
#define TRDPR11 PR10H_bit.no4
#define TRJPR10 PR10H_bit.no5
#define RAMPR1 PR10H_bit.no6
#define LIN0TRMPR1 PR10H_bit.no7
#define LIN0RVCPR1 PR11L_bit.no0
#define LIN0PR1 PR11L_bit.no1
#define LIN0STAPR1 PR11L_bit.no1
#define RTCPR1 PR11L_bit.no3
#define TMPR100 PR11L_bit.no4
#define TMPR101 PR11L_bit.no5
#define TMPR102 PR11L_bit.no6
#define TMPR103 PR11L_bit.no7
#define ADPR1 PR11H_bit.no0
#define PPR16 PR11H_bit.no1
#define PPR17 PR11H_bit.no2
#define TMPR101H PR11H_bit.no3
#define TMPR103H PR11H_bit.no4
#define TMPR104 PR11H_bit.no7
#define MAA PMC_bit.no0

/*
 Interrupt vector addresses
 */
#define RST_vect 0x0
#define INTDBG_vect 0x2
#define INTSRO_vect 0x4
#define INTWDTI_vect 0x4
#define INTLVI_vect 0x6
#define INTP0_vect 0x8
#define INTP1_vect 0xA
#define INTP2_vect 0xC
#define INTP3_vect 0xE
#define INTP4_vect 0x10
#define INTSPM_vect 0x10
#define INTP5_vect 0x12
#define INTCLM_vect 0x14
#define INTCSI00_vect 0x16
#define INTIIC00_vect 0x16
#define INTST0_vect 0x16
#define INTCSI01_vect 0x18
#define INTIIC01_vect 0x18
#define INTSR0_vect 0x18
#define INTTRD0_vect 0x1A
#define INTTRD1_vect 0x1C
#define INTTRJ0_vect 0x1E
#define INTRAM_vect 0x20
#define INTLIN0TRM_vect 0x22
#define INTLIN0RVC_vect 0x24
#define INTLIN0_vect 0x26
#define INTLIN0STA_vect 0x26
#define INTRTC_vect 0x2A
#define INTTM00_vect 0x2C
#define INTTM01_vect 0x2E
#define INTTM02_vect 0x30
#define INTTM03_vect 0x32
#define INTAD_vect 0x34
#define INTP6_vect 0x36
#define INTP7_vect 0x38
#define INTTM01H_vect 0x3A
#define INTTM03H_vect 0x3C
#define INTTM04_vect 0x42
#define INTTM05_vect 0x44
#define INTTM06_vect 0x46
#define INTTM07_vect 0x48
#define INTLIN0WUP_vect 0x4A
#define INTKR_vect 0x4C
#define INTFL_vect 0x62
#define BRK_I_vect 0x7E
#endif
