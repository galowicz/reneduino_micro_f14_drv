/*!
 * \file Lin_GeneralTypes.h
 * \brief TODO
 * \author awd110
 */
#ifndef LIN_GENERAL_TYPES_H_
#define LIN_GENERAL_TYPES_H_
/* Includes */
#include "Std_Types.h"

/* Macros */

/* Exported Type definitions */
/**
 * Represents all valid protected identifier used by Lin_SendFrame()
 */
typedef uint8 Lin_FramePidType;

/**
 * This type is used to specify the Checksum model to be used for LIN frame
 */
typedef enum {
	LIN_ENHANCED_CS, /** Enhanced checksum model */
	LIN_CLASSIC_CS,	 /** Classic checksum model */
} Lin_FrameCsModelType;

/**
 * This type is used to specify whether the frame processor is required to transmit the response part of the LIN frame
 */
typedef enum {
	LIN_FRAMERESPONSE_TX,
	LIN_FRAMERESPONSE_RX,
	LIN_FRAMERESPONSE_IGNORE,
} Lin_FrameResponseType;

/*!
 * This type is used to specify the number of SDU data bytes to copy
 */
typedef uint8 Lin_FrameDlType;

/*!
 * This type is used to provide PID, checksum model, data length and SDU pointer from the LIN Interface layer to the LIN driver
 */
typedef struct {
	Lin_FramePidType      Pid;
	Lin_FrameCsModelType  Cs;
	Lin_FrameResponseType Drc;
	Lin_FrameDlType	      Dl;
	uint8*		      SduPtr;
} Lin_PduType;

/*!
 * LIN operation states for a LIN channel or frame, as returned by the API service Lin_GetStatus().
 */
typedef enum {
	LIN_NOT_OK,	     /* Development or production error occurred */
	LIN_TX_OK,	     /* Successful transmission */
	LIN_TX_BUSY,	     /* Ongoing transmission */
	LIN_TX_HEADER_ERROR, /* Erroneous header transmission */
	LIN_TX_ERROR,	     /* Erroneous response transmission */
	LIN_RX_OK,	     /* Reception of correct response */
	LIN_RX_BUSY,	     /* Ongoing reception: at least one response byte has been received */
	LIN_RX_ERROR,	     /* Erroneous response reception */
	LIN_RX_NO_RESPONSE,  /*  No response byte has been received so far */
	LIN_OPERATIONAL,     /* Normal operation; the related LIN channel is ready to transmit next header */
	LIN_CH_SLEEP,	     /* Sleep state operation */
} Lin_StatusType;

/*!
 * This type represents the slave error types that are detected during header reception and response transmission/reception.
 */
typedef enum {
	LIN_ERR_HEADER,	       /* Error in header */
	LIN_ERR_RESP_STOPBIT,  /* Framing error in response */
	LIN_ERR_RESP_CHECKSUM, /* Checksum error */
	LIN_ERR_RESP_DATABIT,  /* Monitoring error of transmitted data bit */
	LIN_ERR_NO_RESP,       /* No response */
	LIN_ERR_INC_RESP,      /* Incomplete response */
} Lin_SlaveerrorType;

/* Exported Objects */

/* Exported function prototypes */

#endif /* LIN_GENERAL_TYPES_H_ */
