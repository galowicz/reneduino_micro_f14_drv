/*!
 * \file ${file-name}
 * \brief TODO
 * \author awd110
 *
 */
/* Includes */
#include "Std_Types.h"
#include "iodefine_R5F10AGE.h"

/* Macros */

/* Typedefs */

/* Objects */

/* Function prototypes */
int main(void) {
	// Port_Init(&Port_DefaultConfig);

	PM4 = ~(1 << 1);
	for (;;) {
		P4 |= (1 << 1);
		for (uint16 i = 10000; i != 0; i--) {
			asm("nop");
		}
		P4 &= ~(1 << 1);
		for (uint32 i = 200000; i != 0; i--) {
			asm("nop");
			asm("nop");
		}
	}
	return 0;
}

/* Function definitions */
