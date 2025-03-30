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

/* Macros */

/* Typedefs */

/* Objects */
uint8	    Frame_Data[8] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77};
Lin_PduType Frame	  = {
		.Pid	= 0,
		.Cs	= LIN_CLASSIC_CS,
		.Drc	= LIN_FRAMERESPONSE_TX,
		.Dl	= 8,
		.SduPtr = Frame_Data,
};

/* Function prototypes */
int main(void) {
	uint32 max = 0;
	Port_Init(&Port_DefaultConfig);
	Lin_Init(NULL_PTR);

	// PM4 = (uint8) ~(1 << 1);

	Lin_SendFrame(0, &Frame);
	for (;;) {
		Dio_WriteChannel(DIO_CHANNEL_USERLED, STD_HIGH);
		for (uint32 i = max / 2; i != 0; i--) {
			asm("nop");
		}
		Dio_WriteChannel(DIO_CHANNEL_USERLED, STD_LOW);
		for (uint32 i = max; i != 0; i--) {
			asm("nop");
		}
		// max = max + 50;
		max = 40000;
	}
	return 0;
}

/* Function definitions */
