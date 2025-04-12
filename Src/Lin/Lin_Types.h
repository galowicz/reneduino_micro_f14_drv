/*!
 * \file Lin_Types.h
 * \brief Lin Driver Type definitions
 * \author awd110
 */
#ifndef LIN_TYPES_H_
#define LIN_TYPES_H_
/* Includes */
#include "Lin_GeneralTypes.h"
#include "Std_Types.h"

/* Macros */

/* Exported Type definitions */
/*
 * States of frame processor
 */
typedef enum {
	LIN_FRAME_IDLE,
	LIN_FRAME_BREAK_SYNC,
	LIN_FRAME_PID,
	LIN_FRAME_TX_DATA,
	LIN_FRAME_RX_DATA,
	LIN_FRAME_TX_CKSUM,
	LIN_FRAME_RX_CKSUM,
	LIN_FRAME_MAX,
} Lin_FrameState_t;

/*!
 * control structure for lin driver
 */
typedef struct {
	Lin_StatusType	   Status;     // module status
	Lin_FrameState_t   FrameState; // frame status
	uint8		   DataCount;  // current data counter, mainly for driver using UART
	const Lin_PduType* Pdu;	       // current Pdu pointer
} Lin_Control_t;
/*
 * This is the type of the external data structure containing the overall initialization data for the LIN
 * driver and the SFR settings affecting the LIN channels
 */
typedef struct {
	uint32 baudrate;

} Lin_ConfigType;

/* Exported Objects */

/* Exported function prototypes */

#endif /* LIN_TYPES_H_ */
