/*!
 * \file Lin_Rlin3.c
 * \brief Rlin3 lin driver
 * \author awd110
 */
/* Includes */
#include "Lin_Rlin3.h"
#include "Dio.h"
#include "Lin.h"
#include "Lin_GeneralTypes.h"
#include "Std_Types.h"
#include "interrupt_handlers_R5F10AGE.h"
#include "iodefine_R5F10AGE.h"
#include "iodefine_ext_R5F10AGE.h"
#include "shiftout.h"

/* Macros */
#define RLIN_ISC_ISC0_POS    (0)
#define RLIN_ISC_ISC2_POS    (2)
#define RLIN_ISC_ISC3_POS    (3)
#define RLIN_ISC_ISC3_LRXD1  (1 << RLIN_ISC_ISC3_POS)
#define RLIN_ISC_ISC3_INTP12 (0 << RLIN_ISC_ISC3_POS)
#define RLIN_ISC_ISC2_LRXD0  (1 << RLIN_ISC_ISC2_POS)
#define RLIN_ISC_ISC2_INTP11 (0 << RLIN_ISC_ISC2_POS)
#define RLIN_ISC_ISC0_RXD0   (1 << RLIN_ISC_ISC0_POS)
#define RLIN_ISC_ISC0_INTP0  (0 << RLIN_ISC_ISC0_POS)

#define RLIN_LCHSEL_LSEL0_POS  (0)
#define RLIN_LCHSEL_LSEL0_LIN0 (0 << RLIN_LCHSEL_LSEL0_POS)
#define RLIN_LCHSEL_LSEL0_LIN1 (1 << RLIN_LCHSEL_LSEL0_POS)

#define RLIN_PER_LIN0EN_POS	(2)
#define RLIN_PER_LIN1EN_POS	(3)
#define RLIN_PER_LIN0EN_ENABLED (1 << RLIN_PER_LIN0EN_POS)
#define RLIN_PER_LIN1EN_ENABLED (1 << RLIN_PER_LIN1EN_POS)

#define RLIN_LINCKSEL_LIN0MCK_POS  (0)
#define RLIN_LINCKSEL_LIN1MCK_POS  (1)
#define RLIN_LINCKSEL_LIN0MCKE_POS (4)
#define RLIN_LINCKSEL_LIN1MCKE_POS (5)

#define RLIN_LINCKSEL_LIN0MCK_LIN0_FCLK	 (0 << RLIN_LINCKSEL_LIN0MCK_POS)
#define RLIN_LINCKSEL_LIN0MCK_LIN0_FMX	 (1 << RLIN_LINCKSEL_LIN0MCK_POS)
#define RLIN_LINCKSEL_LIN1MCK_LIN1_FCLK	 (0 << RLIN_LINCKSEL_LIN0MCK_POS)
#define RLIN_LINCKSEL_LIN1MCK_LIN1_FMX	 (1 << RLIN_LINCKSEL_LIN0MCK_POS)
#define RLIN_LINCKSEL_LIN0MCKE_LIN0_STOP (0 << RLIN_LINCKSEL_LIN0MCKE_POS)
#define RLIN_LINCKSEL_LIN0MCKE_LIN0_EN	 (1 << RLIN_LINCKSEL_LIN0MCKE_POS)
#define RLIN_LINCKSEL_LIN1MCKE_LIN1_STOP (0 << RLIN_LINCKSEL_LIN1MCKE_POS)
#define RLIN_LINCKSEL_LIN1MCKE_LIN1_EN	 (1 << RLIN_LINCKSEL_LIN1MCKE_POS)

#define RLIN_LWBRn_LWBR0_POS (0) /*Master only*/
#define RLIN_LWBRn_LPRS_POS  (1)
#define RLIN_LWBRn_LPRS_MASK (0x0e)
#define RLIN_LWBRn_NSPB_POS  (1)
#define RLIN_LWBRn_NSPB_MASK (0xf0)

#define RLIN_LWBRn_LWBR0_1_3 (0 << RLIN_LWBRn_LWBR0_POS)
#define RLIN_LWBRn_LWBR0_2_X (1 << RLIN_LWBRn_LWBR0_POS)

#define RLIN_LWBRn_LPRS_1_1   (0 << RLIN_LWBRn_LPRS_POS)
#define RLIN_LWBRn_LPRS_1_2   (1 << RLIN_LWBRn_LPRS_POS)
#define RLIN_LWBRn_LPRS_1_4   (2 << RLIN_LWBRn_LPRS_POS)
#define RLIN_LWBRn_LPRS_1_8   (3 << RLIN_LWBRn_LPRS_POS)
#define RLIN_LWBRn_LPRS_1_16  (4 << RLIN_LWBRn_LPRS_POS)
#define RLIN_LWBRn_LPRS_1_32  (5 << RLIN_LWBRn_LPRS_POS)
#define RLIN_LWBRn_LPRS_1_64  (6 << RLIN_LWBRn_LPRS_POS)
#define RLIN_LWBRn_LPRS_1_128 (7 << RLIN_LWBRn_LPRS_POS)

#define RLIN_LWBRn_NSPB_16_0 (0 << RLIN_LWBRn_NSPB_POS)
#define RLIN_LWBRn_NSPB_16_1 (0 << RLIN_LWBRn_NSPB_POS)

#define RLIN_LSTCn_LSTM_POS		     (0)
#define RLIN_LSTCn_LSTM_NORMAL		     (0 << RLIN_LSTCn_LSTM_POS)
#define RLIN_LSTCn_LSTM_SELFTEST	     (1 << RLIN_LSTCn_LSTM_POS)
#define RLIN_LSTCn_LSTM_SELFTEST_TRANSITION1 (0xA7)
#define RLIN_LSTCn_LSTM_SELFTEST_TRANSITION2 (0x58)
#define RLIN_LSTCn_LSTM_SELFTEST_TRANSITION3 (0x01)

#define RLIN_LMDn_LMD_POS    (0)
#define RLIN_LMDn_LMD_MASK   (0x03)
#define RLIN_LMDn_LCKS_POS   (2)
#define RLIN_LMDn_LCKS_MASK  (0xC0)
#define RLIN_LMDn_LIOS_POS   (4)
#define RLIN_LMDn_LRDNFS_POS (5)

#define RLIN_LMDn_LMD_LIN_MSTR	     (0 << RLIN_LMDn_LMD_POS)
#define RLIN_LMDn_LCKS_FA	     (0 << RLIN_LMDn_LCKS_POS)
#define RLIN_LMDn_LCKS_FB	     (1 << RLIN_LMDn_LCKS_POS)
#define RLIN_LMDn_LCKS_FC	     (2 << RLIN_LMDn_LCKS_POS)
#define RLIN_LMDn_LCKS_FD	     (3 << RLIN_LMDn_LCKS_POS)
#define RLIN_LMDn_LIOS_LIN_IRQ	     (0 << RLIN_LMDn_LIOS_POS)
#define RLIN_LMDn_LIOS_RX_TX_STA_IRQ (1 << RLIN_LMDn_LIOS_POS)
#define RLIN_LMDn_LRDNFS_EN	     (0 << RLIN_LMDn_LRDNFS_POS)
#define RLIN_LMDn_LRDNFS_DIS	     (1 << RLIN_LMDn_LRDNFS_POS)

#define RLIN_LBFCn_BLT_POS  (0)
#define RLIN_LBFCn_BLT_MASK (0x0f)
#define RLIN_LBFCn_BDT_POS  (4)
#define RLIN_LBFCn_BDT_MASK (0x30)

#define RLIN_LBFCn_BLT_13 (0 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_14 (1 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_15 (2 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_16 (3 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_17 (4 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_18 (5 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_19 (6 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_20 (7 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_21 (8 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_22 (9 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_23 (10 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_24 (11 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_25 (12 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_26 (13 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_27 (14 << RLIN_LBFCn_BLT_POS)
#define RLIN_LBFCn_BLT_28 (15 << RLIN_LBFCn_BLT_POS)

#define RLIN_LBFCn_BDT_1 (0 << RLIN_LBFCn_BDT_POS)
#define RLIN_LBFCn_BDT_2 (1 << RLIN_LBFCn_BDT_POS)
#define RLIN_LBFCn_BDT_3 (2 << RLIN_LBFCn_BDT_POS)
#define RLIN_LBFCn_BDT_4 (3 << RLIN_LBFCn_BDT_POS)

#define RLIN_LSCn_IBSH_POS  (0)
#define RLIN_LSCn_IBSH_MASK (0x07)
#define RLIN_LSCn_IBS_POS   (4)
#define RLIN_LSCn_IBS_MASK  (0x30)
#define RLIN_LSCn_IBSH_0    (0 << RLIN_LSCn_IBSH_POS)
#define RLIN_LSCn_IBSH_1    (1 << RLIN_LSCn_IBSH_POS)
#define RLIN_LSCn_IBSH_2    (2 << RLIN_LSCn_IBSH_POS)
#define RLIN_LSCn_IBSH_3    (3 << RLIN_LSCn_IBSH_POS)
#define RLIN_LSCn_IBSH_4    (4 << RLIN_LSCn_IBSH_POS)
#define RLIN_LSCn_IBSH_5    (5 << RLIN_LSCn_IBSH_POS)
#define RLIN_LSCn_IBSH_6    (6 << RLIN_LSCn_IBSH_POS)
#define RLIN_LSCn_IBSH_7    (7 << RLIN_LSCn_IBSH_POS)

#define RLIN_LSCn_IBS_0 (0 << RLIN_LSCn_IBS_POS)
#define RLIN_LSCn_IBS_1 (1 << RLIN_LSCn_IBS_POS)
#define RLIN_LSCn_IBS_2 (2 << RLIN_LSCn_IBS_POS)
#define RLIN_LSCn_IBS_3 (3 << RLIN_LSCn_IBS_POS)

#define RLIN_LWUPn_WUTL_POS  (4)
#define RLIN_LWUPn_WUTL_MASK (0xf0)
#define RLIN_LWUPn_WUTL_1    (0 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_2    (1 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_3    (2 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_4    (3 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_5    (4 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_6    (5 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_7    (6 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_8    (7 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_9    (8 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_10   (9 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_11   (10 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_12   (11 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_13   (12 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_14   (13 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_15   (14 << RLIN_LWUPn_WUTL_POS)
#define RLIN_LWUPn_WUTL_16   (15 << RLIN_LWUPn_WUTL_POS)

#define RLIN_LIEn_FTCIE_POS (0)
#define RLIN_LIEn_FRCIE_POS (1)
#define RLIN_LIEn_ERRIE_POS (2)
#define RLIN_LIEn_SHIE_POS  (3)
#define RLIN_LIEn_DIS_ALL   (0)
#define RLIN_LIEn_FTCIE_EN  (1 << RLIN_LIEn_FTCIE_POS)
#define RLIN_LIEn_FRCIE_EN  (1 << RLIN_LIEn_FRCIE_POS)
#define RLIN_LIEn_ERRIE_EN  (1 << RLIN_LIEn_ERRIE_POS)
#define RLIN_LIEn_SHIE_EN   (1 << RLIN_LIEn_SHIE_POS)

#define RLIN_LEDEn_BERE_POS  (0)
#define RLIN_LEDEn_PBERE_POS (1)
#define RLIN_LEDEn_FTERE_POS (2)
#define RLIN_LEDEn_FERE_POS  (3)
#define RLIN_LEDEn_LTES_POS  (7)

#define RLIN_LEDEn_DIS_ALL	 (0)
#define RLIN_LEDEn_BERE_EN	 (1 << RLIN_LEDEn_BERE_POS)
#define RLIN_LEDEn_PBERE_EN	 (1 << RLIN_LEDEn_PBERE_POS)
#define RLIN_LEDEn_FTERE_EN	 (1 << RLIN_LEDEn_FTERE_POS)
#define RLIN_LEDEn_FERE_EN	 (1 << RLIN_LEDEn_FERE_POS)
#define RLIN_LEDEn_LTES_FRM_TIM	 (0 << RLIN_LEDEn_LTES_POS)
#define RLIN_LEDEn_LTES_RESP_TIM (1 << RLIN_LEDEn_LTES_POS)

#define RLIN_LCUCn_OM0_POS	 (0)
#define RLIN_LCUCn_OM0_RESET	 (0 << RLIN_LCUCn_OM0_POS)
#define RLIN_LCUCn_OM0_WAKEUP	 (1 << RLIN_LCUCn_OM0_POS)
#define RLIN_LCUCn_OM0_OPERATION (3 << RLIN_LCUCn_OM0_POS)

#define RLIN_LTRCn_FTS_POS (0)
#define RLIN_LTRCn_RTS_POS (1)

#define RLIN_LTRCn_FTS_FRM_START  (1 << RLIN_LTRCn_FTS_POS)
#define RLIN_LTRCn_RTS_RESP_START (1 << RLIN_LTRCn_RTS_POS)

#define RLIN_LMSTn_OMM0_POS	  (0)
#define RLIN_LMSTn_OMM0_RESET	  (0 << RLIN_LCUCn_OM0_POS)
#define RLIN_LMSTn_OMM0_WAKEUP	  (1 << RLIN_LCUCn_OM0_POS)
#define RLIN_LMSTn_OMM0_OPERATION (3 << RLIN_LCUCn_OM0_POS)

#define RLIN_LSTn_FTC_POS  (0)
#define RLIN_LSTn_FRC_POS  (1)
#define RLIN_LSTn_ERR_POS  (3)
#define RLIN_LSTn_D1RC_POS (6)
#define RLIN_LSTn_HTRC_POS (7)

#define RLIN_LSTn_FTC_FRM_TX  (1 << RLIN_LSTn_FTC_POS)
#define RLIN_LSTn_FRC_FRM_RX  (1 << RLIN_LSTn_FRC_POS)
#define RLIN_LSTn_ERR_DET     (1 << RLIN_LSTn_ERR_POS)
#define RLIN_LSTn_D1RC_DATA1  (1 << RLIN_LSTn_D1RC_POS)
#define RLIN_LSTn_HTRC_HDR_TX (1 << RLIN_LSTn_HTRC_POS)

#define RLIN_LESTn_BER_POS  (0)
#define RLIN_LESTn_PBER_POS (1)
#define RLIN_LESTn_FTER_POS (2)
#define RLIN_LESTn_FER_POS  (3)
#define RLIN_LESTn_CSER_POS (5)
#define RLIN_LESTn_RPER_POS (7)

#define RLIN_LESTn_BER	(1 << RLIN_LESTn_BER_POS)
#define RLIN_LESTn_PBER (1 << RLIN_LESTn_PBER_POS)
#define RLIN_LESTn_FTER (1 << RLIN_LESTn_FTER_POS)
#define RLIN_LESTn_FER	(1 << RLIN_LESTn_FER_POS)
#define RLIN_LESTn_CSER (0 << RLIN_LESTn_CSER_POS)
#define RLIN_LESTn_RPER (1 << RLIN_LESTn_RPER_POS)

#define RLIN_LDFCn_RDFL_POS  (0)
#define RLIN_LDFCn_RDFL_MASK (0x0f)
#define RLIN_LDFCn_RFT_POS   (4)
#define RLIN_LDFCn_CSM_POS   (5)
#define RLIN_LDFCn_FSM_POS   (6)
#define RLIN_LDFCn_LSS_POS   (7)

#define RLIN_LDFCn_RDFL_0B	(0 << RLIN_LDFCn_RDFL_POS)
#define RLIN_LDFCn_RDFL_1B	(1 << RLIN_LDFCn_RDFL_POS)
#define RLIN_LDFCn_RDFL_2B	(2 << RLIN_LDFCn_RDFL_POS)
#define RLIN_LDFCn_RDFL_3B	(3 << RLIN_LDFCn_RDFL_POS)
#define RLIN_LDFCn_RDFL_4B	(4 << RLIN_LDFCn_RDFL_POS)
#define RLIN_LDFCn_RDFL_5B	(5 << RLIN_LDFCn_RDFL_POS)
#define RLIN_LDFCn_RDFL_6B	(6 << RLIN_LDFCn_RDFL_POS)
#define RLIN_LDFCn_RDFL_7B	(7 << RLIN_LDFCn_RDFL_POS)
#define RLIN_LDFCn_RDFL_8B	(8 << RLIN_LDFCn_RDFL_POS)
#define RLIN_LDFCn_RFT_RX	(0 << RLIN_LDFCn_RFT_POS)
#define RLIN_LDFCn_RFT_TX	(1 << RLIN_LDFCn_RFT_POS)
#define RLIN_LDFCn_CSM_CLASSIC	(0 << RLIN_LDFCn_CSM_POS)
#define RLIN_LDFCn_CSM_ENHANC	(1 << RLIN_LDFCn_CSM_POS)
#define RLIN_LDFCn_FSM_SEPARATE (1 << RLIN_LDFCn_FSM_POS)
#define RLIN_LDFCn_LSS_LAST	(1 << RLIN_LDFCn_LSS_POS)

/* Typedefs */
typedef enum {
	LIN_RLIN3_MODE_RESET	 = 0,
	LIN_RLIN3_MODE_WAKEUP	 = 1,
	LIN_RLIN3_MODE_OPERATION = 3,
} Lin_Rlin3_Mode_t;

/* Objects */
volatile Lin_Control_t Lin_Rlin3_Control = {
	LIN_NOT_OK,
	LIN_FRAME_IDLE,
	0,
	NULL_PTR,
};

/* Function prototypes */
void Lin_Rlin3_PortInit();
void Lin_Rlin3_InterruptInit();

void Lin_Rlin3_SetMode(Lin_Rlin3_Mode_t mode);

/* Function definitions */

/*!
 * Initialize Rlin3
 * \param Config pointer
 */
void Lin_Rlin3_Init(const Lin_Rlin3_ConfigType* Config) {
	(void)Config; // TODO: add config

	Lin_Rlin3_Control.Status = LIN_NOT_OK;

	// TODO: enable in MCU drv?
	Lin_Rlin3_SetMode(LIN_RLIN3_MODE_RESET);

	LMD0  = RLIN_LMDn_LRDNFS_EN | RLIN_LMDn_LIOS_RX_TX_STA_IRQ | RLIN_LMDn_LCKS_FA | RLIN_LMDn_LMD_LIN_MSTR;
	LWBR0 = RLIN_LWBRn_NSPB_16_0 | RLIN_LWBRn_LPRS_1_1 | RLIN_LWBRn_LWBR0_2_X;
	// baudrate prescaler: clk/prescaler/16
	LBRP01 = 0x5f; // baudrate for fd
	LBRP00 = 0x67; // baudrate for fa, fb, fc

	LBFC0 = RLIN_LBFCn_BDT_1 | RLIN_LBFCn_BLT_13; // 0;
	LSC0  = RLIN_LSCn_IBS_1 | RLIN_LSCn_IBSH_0;   // 0x10;
	LWUP0 = RLIN_LWUPn_WUTL_5;		      // 0x40;
	LSTC0 = RLIN_LSTCn_LSTM_NORMAL;		      // 0;
	LIE0  = RLIN_LIEn_DIS_ALL;		      // 0x00;
	LEDE0 = RLIN_LEDEn_DIS_ALL;		      // 0x00

	Lin_Rlin3_PortInit();
	Lin_Rlin3_InterruptInit();

	LIE0  = RLIN_LIEn_FTCIE_EN | RLIN_LIEn_FRCIE_EN | RLIN_LIEn_ERRIE_EN | RLIN_LIEn_SHIE_EN;
	LEDE0 = 0x8f;

	Lin_Rlin3_SetMode(LIN_RLIN3_MODE_OPERATION);

	Lin_Rlin3_Control.DataCount  = 0;
	Lin_Rlin3_Control.FrameState = LIN_FRAME_IDLE;
	Lin_Rlin3_Control.Pdu	     = NULL_PTR;
	Lin_Rlin3_Control.Status     = LIN_OPERATIONAL;
	// TODO: start ins sleep
}

/*!
 * Deinitialises Rlin3
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
Std_ReturnType Lin_Rlin3_SendFrame(const Lin_PduType* PduInfoPtr) {
	LCHSEL = 0;

	Lin_Rlin3_Control.Pdu = PduInfoPtr;
	uint8 ldfc0_val	      = ((PduInfoPtr->Dl) & 0x0f);
	ldfc0_val |= (LIN_FRAMERESPONSE_TX == PduInfoPtr->Drc) ? 0x10 : 0;
	ldfc0_val |= (LIN_ENHANCED_CS == PduInfoPtr->Cs) ? 0x20 : 0;
	ldfc0_val |= (1 << 6); // separate response

	LDFC0 = ldfc0_val;

	LIDB0 = PduInfoPtr->Pid;

	LST0  = 0;
	LEST0 = 0;

	LIN0TRMIF = 0;
	LIN0RVCIF = 0;
	LIN0STAIF = 0;

	LIN0TRMMK = 0;
	LIN0RVCMK = 0;
	LIN0STAMK = 0;

	LTRC0 = 1;
	return E_OK;
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
void __attribute__((interrupt)) INT_LIN0TRM(void) {
	uint8 status;
	LCHSEL = 0;
	status = LST0;
	LST0   = 0;

	Shiftout_Print('T');
	Shiftout_Print(status);
	Shiftout_Print(LDFC0);

	if (0 != (status & (1 << 3))) {
		// error: will be processed in separate irq
		Shiftout_Print('e');
		return;
	} else {
		if (0 != (status & (1 << 7))) {
			// header transmitted
			// if (1 == (LDFC0 & (1 << 4))) {
			if (LIN_FRAMERESPONSE_TX == Lin_Rlin3_Control.Pdu->Drc) {
				switch (LDFC0 & 0x0f) {
				case 8:
					LDB08 = Lin_Rlin3_Control.Pdu->SduPtr[7];
					// Shiftout_Print(LDB08);
				case 7:
					LDB07 = Lin_Rlin3_Control.Pdu->SduPtr[6];
					// Shiftout_Print(LDB07);
				case 6:
					LDB06 = Lin_Rlin3_Control.Pdu->SduPtr[5];
					// Shiftout_Print(LDB06);
				case 5:
					LDB05 = Lin_Rlin3_Control.Pdu->SduPtr[4];
					// Shiftout_Print(LDB05);
				case 4:
					LDB04 = Lin_Rlin3_Control.Pdu->SduPtr[3];
					// Shiftout_Print(LDB04);
				case 3:
					LDB03 = Lin_Rlin3_Control.Pdu->SduPtr[2];
					// Shiftout_Print(LDB03);
				case 2:
					LDB02 = Lin_Rlin3_Control.Pdu->SduPtr[1];
					// Shiftout_Print(LDB02);
				case 1:
					LDB01 = Lin_Rlin3_Control.Pdu->SduPtr[0];
					// Shiftout_Print(LDB01);
					break;
				default:
					break;
				}
				Shiftout_Print('W');
				LTRC0 = 0x02;
			} else {
				Shiftout_Print('R');
				LTRC0 = 0x02;
			}
			Shiftout_Print(LTRC0);
		} else {
			Shiftout_Print('I');
			if (0 != (status & (1 << 0))) {
				if (3 == LMST0) {
					// response finished
				} else {
					// wake up fimished
				}
			} else {
				// illegal irq
			}
		}
	}
}

/*
 * INT_LIN0RVC (0x24)
 */
void __attribute__((interrupt)) INT_LIN0RVC(void) {
	uint8 status;
	LCHSEL = 0;
	status = LST0;
	LST0   = 0;

	if (0 != (status & (1 << 3))) {
		// error: will be processed in separate irq
		return;
	} else {
		if (0 != (status & (1 << 1))) {
			// response received
			switch (LDFC0 & 0x0f) {
			case 8:
				LDB08 = Lin_Rlin3_Control.Pdu->SduPtr[7];
				// Shiftout_Print(LDB08);
			case 7:
				LDB07 = Lin_Rlin3_Control.Pdu->SduPtr[6];
				// Shiftout_Print(LDB07);
			case 6:
				LDB06 = Lin_Rlin3_Control.Pdu->SduPtr[5];
				// Shiftout_Print(LDB06);
			case 5:
				LDB05 = Lin_Rlin3_Control.Pdu->SduPtr[4];
				// Shiftout_Print(LDB05);
			case 4:
				LDB04 = Lin_Rlin3_Control.Pdu->SduPtr[3];
				// Shiftout_Print(LDB04);
			case 3:
				LDB03 = Lin_Rlin3_Control.Pdu->SduPtr[2];
				// Shiftout_Print(LDB03);
			case 2:
				LDB02 = Lin_Rlin3_Control.Pdu->SduPtr[1];
				// Shiftout_Print(LDB02);
			case 1:
				LDB01 = Lin_Rlin3_Control.Pdu->SduPtr[0];
				// Shiftout_Print(LDB01);
				break;
			default:
				break;
			}
		} else {
			// illegal irq
		}
	}

	// Shiftout_Print('R');
}

/*
 * INT_LIN0/INT_LIN0STA (0x26)
 */
void __attribute__((interrupt)) INT_LIN0STA(void) {
	uint8 status;
	LCHSEL = 0;
	status = LEST0;
	LEST0  = 0;

	Shiftout_Print('E');
}

void Lin_Rlin3_PortInit() {
	// PIOR4 = 1 << 4;

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
	if (mode == LIN_RLIN3_MODE_RESET) {
		PER2_bit.no2 = 0;
		PER2_bit.no2 = 1;

		LINCKSEL = 0x10;
	}

	LCHSEL = 0;

	LCUC0 = (uint8)mode;

	while (LMST0 != mode) {
		asm("nop");
	}
}
