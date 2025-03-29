/*!
 * \file Lin_Rlin3.c
 * \brief Rlin3 lin driver
 * \author awd110
 */
/* Includes */
#include "Lin_Rlin3.h"
#include "Lin.h"
#include "Std_Types.h"
#include "interrupt_handlers_R5F10AGE.h"
#include "iodefine_R5F10AGE.h"
#include "iodefine_ext_R5F10AGE.h"

/* Macros */

/* Typedefs */
typedef enum {
	LIN_RLIN3_MODE_RESET	 = 0,
	LIN_RLIN3_MODE_WAKEUP	 = 1,
	LIN_RLIN3_MODE_OPERATION = 3,
} Lin_Rlin3_Mode_t;

/* Objects */

/* Function prototypes */
void Lin_Rlin3_PortInit();
void Lin_Rlin3_InterruptInit();

void Lin_Rlin3_SetMode(Lin_Rlin3_Mode_t mode);

/* Function definitions */

/*!
 * Initialize Rlin3
 * \param Config pointer
 */
void Lin_Rlin3_Init(Lin_Rlin3_Config_t* Configptr) {
	(void)Configptr; // TODO: add config

	Lin_Rlin3_SetMode(LIN_RLIN3_MODE_RESET);

	LMD0   = 0x10;
	LWBR0  = 1;
	LBRP00 = 0x67;
	LBRP01 = 0x5f;
	LBFC0  = 0;
	LSC0   = 0x10;
	LWUP0  = 0x40;
	LSTC0  = 0;
	LIE0   = 0x00;
	LEDE0  = 0x00;

	PER2	 = 1 << 2;
	ISC	 = 1 << 2;
	LINCKSEL = 0x10;

	Lin_Rlin3_PortInit();
	Lin_Rlin3_InterruptInit();

	LIE0  = 0x0f;
	LEDE0 = 0x8f;

	Lin_Rlin3_SetMode(LIN_RLIN3_MODE_OPERATION);
}

/*!
 * Deinitialise Rlin3
 */
void Lin_Rlin3_DeInit(void) {
	LIN0TRMMK = 1;
	LIN0RVCMK = 1;
	LIN0STAMK = 1;
	LIN0WUPMK = 1;

	LIN0EN = 0;
}

/*!
 * Send Header to bus
 */
void Lin_Rlin3_TxHeader(const Lin_PduType* Pdu) {
	LCHSEL = 0;

	uint8 ldfc0_val = ((Pdu->Dl) & 0x0f);
	ldfc0_val |= (LIN_FRAMERESPONSE_TX == Pdu->Drc) ? 0x10 : 0;
	ldfc0_val |= (LIN_ENHANCED_CS == Pdu->Cs) ? 0x20 : 0;
	ldfc0_val |= (1 << 6); // separate response

	LDFC0 = ldfc0_val;

	LIDB0 = Pdu->Pid;

	LST0  = 0;
	LEST0 = 0;

	LIN0TRMIF = 0;
	LIN0RVCIF = 0;
	LIN0STAIF = 0;

	LIN0TRMMK = 0;
	LIN0RVCMK = 0;
	LIN0STAMK = 0;

	LTRC0 = 1;
}

void Lin_Rlin3_PreSleep(void) {
	Lin_Rlin3_DeInit();
	LIN0WUPIF = 0;
	LIN0WUPMK = 0;
}

void Lin_Rlin3_TxWUPSig(void) {
	LIN0WUPMK = 1;
	LIN0TRMMK = 1;
	LIN0RVCMK = 1;
	LIN0STAMK = 1;

	Lin_Rlin3_SetMode(LIN_RLIN3_MODE_RESET);

	LMD0  = 0x10;
	LWBR0 = 0x01;
	LBRP0 = 0x5f67;
	LSC0  = 0x10;

	LWUP0 = 0x40;
	LIE0  = 0x05;
	LEDE0 = 0x03;

	Lin_Rlin3_SetMode(LIN_RLIN3_MODE_WAKEUP);

	LIN0TRMIF = 0;
	LIN0STAIF = 0;
	LIN0TRMMK = 0;
	LIN0STAMK = 0;

	LDFC0 = 0x10;

	LTRC0 = 0x01;
}

/*
 * INT_LIN0TRM (0x22)
 */
void INT_LIN0TRM(void) {
	LCHSEL = 0;
}

/*
 * INT_LIN0RVC (0x24)
 */
void INT_LIN0RVC(void) {
	LCHSEL = 0;
}

/*
 * INT_LIN0/INT_LIN0STA (0x26)
 */
void INT_LIN0STA(void) {
	LCHSEL = 0;
}

void Lin_Rlin3_PortInit() {
	PIOR4 = 1 << 4;

	P1_bit.no3   = 1;
	PM1_bit.no3  = 0;
	POM1_bit.no3 = 0;

	PM1_bit.no4    = 1;
	PIM1_bit.no4   = 0;
	PITHL1_bit.no4 = 0;
	PU1_bit.no4    = 0;

	ISC_bit.no2 = 1;
}
void Lin_Rlin3_InterruptInit() {
	EGP1_bit.no1 = 0;
	EGN1_bit.no1 = 1;

	LIN0WUPMK = 1;
	LIN0TRMMK = 1;
	LIN0RVCMK = 1;
	LIN0STAMK = 1;

	LIN0TRMPR1 = 0;
	LIN0TRMPR0 = 1;
	LIN0RVCPR1 = 0;
	LIN0RVCPR0 = 1;
	LIN0STAPR1 = 0;
	LIN0STAPR0 = 1;
	LIN0WUPPR1 = 0;
	LIN0WUPPR0 = 1;

	LIN0WUPIF = 0;
	LIN0TRMIF = 0;
	LIN0RVCIF = 0;
	LIN0STAIF = 0;
}

void Lin_Rlin3_SetMode(Lin_Rlin3_Mode_t mode) {
	LCHSEL = 0;

	LCUC0 = (uint8)mode;

	while (LMST0 != mode) {
		asm("nop");
	}
}
