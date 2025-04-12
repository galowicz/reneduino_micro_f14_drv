/*!
 * \file ${file-name}
 * \brief TODO
 * \author awd110
 *
 */
/* Includes */
#include "Dio.h"
#include "Lin.h"
#include "Lin_GeneralTypes.h"
#include "Port.h"
#include "Std_Types.h"
#include "iodefine_R5F10AGE.h"
#include "iodefine_ext_R5F10AGE.h"
#include "shiftout.h"

/* Macros */

/* Typedefs */

/* Objects */
uint8	    Frame_Data[8] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77};
Lin_PduType Frame_Tx	  = {
	     .Pid    = 0x49,
	     .Cs     = LIN_ENHANCED_CS,
	     .Drc    = LIN_FRAMERESPONSE_TX,
	     .Dl     = 8,
	     .SduPtr = Frame_Data,
};
Lin_PduType Frame_Rx = {
	.Pid	= 0xC1,
	.Cs	= LIN_ENHANCED_CS,
	.Drc	= LIN_FRAMERESPONSE_RX,
	.Dl	= 4,
	.SduPtr = Frame_Data,
};

/* Function prototypes */
int main(void) {
	uint32 max = 0;
	Port_Init(&Port_DefaultConfig);
	Shiftout_Print(0x55);
	Lin_Init(NULL_PTR);
	// CKS0 = 0x82;

	// PM4 = (uint8) ~(1 << 1);

	max = 1000000;
	EI();
	for (;;) {
		Shiftout_Print('S');
		if (STD_LOW == Dio_ReadChannel(DIO_CHANNEL_USERLED)) {
			(void)Lin_SendFrame(0, &Frame_Rx);
		} else {
			(void)Lin_SendFrame(0, &Frame_Tx);
		}
		// (void)Dio_FlipChannel(DIO_CHANNEL_P13);
		(void)Dio_FlipChannel(DIO_CHANNEL_USERLED);
		// (void)Dio_WriteChannel(DIO_CHANNEL_USERLED, STD_HIGH);

		for (uint32 i = max; i != 0; i--) {
			asm("nop");
		}
		// max = max + 50;
	}
	return 0;
}

/* Function definitions */
