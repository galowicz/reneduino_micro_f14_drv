/*!
 * \file ${file-name}
 * \brief TODO
 * \author awd110
 *
 */
/* Includes */
#include "Std_Types.h"
#include "iodefine_R5F10AGE.h"
#include "Port.h"

/* Macros */

/* Typedefs */

/* Objects */

/* Function prototypes */
int main(void) {
	uint32 max = 0;
	Port_Init(&Port_DefaultConfig);

	// PM4 = (uint8) ~(1 << 1);

	for (;;) {
		P4 |= (uint8)(1 << 1);
		for (uint32 i = max / 2; i != 0; i--) {
			asm("nop");
		}
		P4 &= (uint8) ~(1 << 1);
		for (uint32 i = max; i != 0; i--) {
			asm("nop");
		}
		max = max + 50;
	}
	return 0;
}

const unsigned char Option_Bytes[] __attribute__((section(".option_bytes"))) = {
	0xef, 0xff, 0xe8, 0x85};

const unsigned char Security_Id[] __attribute__((section(".security_id"))) = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
/* Function definitions */
