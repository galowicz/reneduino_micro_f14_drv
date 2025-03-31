/*!
 * \file shiftout.s
 * \brief debug uart
 * \author awd110
 */
/* Includes */
# .include "iodefine_R5F10AGE.h"

/* Macros */
#define P14 (0xFFF0E)

/* Typedefs */

/* Objects */

/* Function prototypes */
/*!
 * Initialise debug uart
 */
Shiftout_Init:
	ret;

/*!
 * Print byte on debug uart;
 * \param A - byte to send
 */
	.global	_Shiftout_Print  /*! global Start routine */
	.type	_Shiftout_Print,@function
_Shiftout_Print:
	SET1 P14.0;
	MOV H, #8;
	NOP;
	NOP;
	NOP;
	CLR1 !P14.0;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
Loop:
	;data bits
	RORC A, 1;
	MOV1 P14.0 , CY;
	DEC H;
	BNZ $Loop;
	; stopbits
	NOP;
	NOP;
	SET1 P14.0;
	NOP;


	RET;



/* Function definitions */

