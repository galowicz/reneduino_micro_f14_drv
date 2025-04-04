/*!
 * \file opt_bytes.c
 * \brief Option bytes config for Renesas RL78/F14 F13 mcus
 * \author awd110
 *
 */
/* Includes */
#include "iodefine_R5F10AGE.h"
#include "iodefine_ext_R5F10AGE.h"

/* Macros */

/* Typedefs */
// Macros for 0x000C0/0x020C0
#define C0_WDINT_POS (7)
#define C0_WDINT_ON  (1 << C0_WDINT_POS)
#define C0_WDINT_OFF (0 << C0_WDINT_POS)

#define C0_WINDOW0_POS (5)
#define C0_WINDOW_50   (1 << C0_WINDOW0_POS)
#define C0_WINDOW_75   (2 << C0_WINDOW0_POS)
#define C0_WINDOW_100  (3 << C0_WINDOW0_POS)

#define C0_WDTON_POS (4)
#define C0_WDTON_ON  (1 << C0_WDTON_POS)
#define C0_WDTON_OFF (0 << C0_WDTON_POS)

#define C0_WDCS0_POS (1)
#define C0_WDCS_2_6  (0 << C0_WDCS0_POS)
#define C0_WDCS_2_7  (1 << C0_WDCS0_POS)
#define C0_WDCS_2_8  (2 << C0_WDCS0_POS)
#define C0_WDCS_2_9  (3 << C0_WDCS0_POS)
#define C0_WDCS_2_11 (4 << C0_WDCS0_POS)
#define C0_WDCS_2_13 (5 << C0_WDCS0_POS)
#define C0_WDCS_2_14 (6 << C0_WDCS0_POS)
#define C0_WDCS_2_16 (7 << C0_WDCS0_POS)

#define C0_WDSTBYON_POS (0)
#define C0_WDSTBYON_ON	(1 << C0_WDSTBYON_POS)
#define C0_WDSTBYON_OFF (0 << C0_WDSTBYON_POS)

// macros for 0x000C1/0x020C1
#define C1_VPOC0_POS (5)

#define C1_CLKMB_POS (4)
#define C1_CLKMB_OFF (1 << C1_CLKMB_POS)
#define C1_CLKMB_ON  (0 << C1_CLKMB_POS)

#define C1_LVIS0_POS (2)

#define C1_LVIMDIS0_POS (0)

#define C1_LVD_I432_R275 ((1 << C1_VPOC0_POS) | (0 << C1_LVIS0_POS) | (2 << C1_LVIMDIS0_POS))
#define C1_LVD_I452_R275 ((2 << C1_VPOC0_POS) | (0 << C1_LVIS0_POS) | (2 << C1_LVIMDIS0_POS))
#define C1_LVD_I315_R275 ((3 << C1_VPOC0_POS) | (1 << C1_LVIS0_POS) | (2 << C1_LVIMDIS0_POS))
#define C1_LVD_I464_R275 ((3 << C1_VPOC0_POS) | (0 << C1_LVIS0_POS) | (2 << C1_LVIMDIS0_POS))

#define C1_LVD_R275 ((3 << C1_VPOC0_POS) | (3 << C1_LVIS0_POS) | (3 << C1_LVIMDIS0_POS))
#define C1_LVD_R296 ((0 << C1_VPOC0_POS) | (1 << C1_LVIS0_POS) | (3 << C1_LVIMDIS0_POS))
#define C1_LVD_R315 ((3 << C1_VPOC0_POS) | (1 << C1_LVIS0_POS) | (3 << C1_LVIMDIS0_POS))
#define C1_LVD_R432 ((1 << C1_VPOC0_POS) | (0 << C1_LVIS0_POS) | (3 << C1_LVIMDIS0_POS))
#define C1_LVD_R452 ((2 << C1_VPOC0_POS) | (0 << C1_LVIS0_POS) | (3 << C1_LVIMDIS0_POS))
#define C1_LVD_R464 ((3 << C1_VPOC0_POS) | (0 << C1_LVIS0_POS) | (3 << C1_LVIMDIS0_POS))

#define C1_LVD_I275 ((3 << C1_VPOC0_POS) | (3 << C1_LVIS0_POS) | (1 << C1_LVIMDIS0_POS))
#define C1_LVD_I296 ((0 << C1_VPOC0_POS) | (1 << C1_LVIS0_POS) | (1 << C1_LVIMDIS0_POS))
#define C1_LVD_I315 ((3 << C1_VPOC0_POS) | (1 << C1_LVIS0_POS) | (1 << C1_LVIMDIS0_POS))
#define C1_LVD_I432 ((1 << C1_VPOC0_POS) | (0 << C1_LVIS0_POS) | (1 << C1_LVIMDIS0_POS))
#define C1_LVD_I452 ((2 << C1_VPOC0_POS) | (0 << C1_LVIS0_POS) | (1 << C1_LVIMDIS0_POS))
#define C1_LVD_I464 ((3 << C1_VPOC0_POS) | (0 << C1_LVIS0_POS) | (1 << C1_LVIMDIS0_POS))

#define C1_LVD_OFF ((4 << C1_VPOC0_POS) | (3 << C1_LVIS0_POS) | (1 << C1_LVIMDIS0_POS))

// Macros for 0x000C2/0x020C2
#define C2_UNUSED (0xC0)

#define C2_RESOUTB_POS	     (5)
#define C2_RESOUTB_P130_GPIO (1 << C2_RESOUTB_POS)

#define C2_FREQSEL0_POS (0)
#define C2_FREQSEL_64	(0x18 << C2_FREQSEL0_POS)
#define C2_FREQSEL_48	(0x10 << C2_FREQSEL0_POS)
#define C2_FREQSEL_32	(0x08 << C2_FREQSEL0_POS)
#define C2_FREQSEL_24	(0x00 << C2_FREQSEL0_POS)
#define C2_FREQSEL_16	(0x09 << C2_FREQSEL0_POS)
#define C2_FREQSEL_12	(0x01 << C2_FREQSEL0_POS)
#define C2_FREQSEL_8	(0x0A << C2_FREQSEL0_POS)
#define C2_FREQSEL_4	(0x0B << C2_FREQSEL0_POS)
#define C2_FREQSEL_1	(0x0D << C2_FREQSEL0_POS)

// Macros for 0x000C3/0x020C3
#define C3_UNUSED (0x4)

#define C3_OCDENSET_POS (7)
#define C3_HPIEN_POS	(1)
#define C3_OCDERSD_POS	(0)

#define C3_OCD_DISABLED	      ((0 << C3_OCDENSET_POS) | (0 << C3_HPIEN_POS) | (0 << C3_OCDERSD_POS))
#define C3_OCD_EN_HP_DISABLED ((1 << C3_OCDENSET_POS) | (0 << C3_HPIEN_POS) | (1 << C3_OCDERSD_POS))
#define C3_OCD_EN_HP_EN	      ((1 << C3_OCDENSET_POS) | (1 << C3_HPIEN_POS) | (1 << C3_OCDERSD_POS))

/* Objects */
const unsigned char Option_Bytes[] __attribute__((section(".option_bytes"))) = {
	C0_WDINT_ON | C0_WINDOW_100 | C0_WDTON_OFF | C0_WDCS_2_16 | C0_WDSTBYON_ON, // 0xef,
	C1_CLKMB_ON | C1_LVD_R275,						    // 0xff,
	C2_UNUSED | C2_RESOUTB_P130_GPIO | C2_FREQSEL_32,			    // 0xe8,
	C3_UNUSED | C3_OCD_EN_HP_DISABLED					    // 0x85,
};

const unsigned char Security_Id[] __attribute__((section(".security_id"))) = {
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
};

/* Function prototypes */

/* Function definitions */
