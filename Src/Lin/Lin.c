/*!
 * \file Lin.c
 * \brief Lin driver
 * \author awd110
 */
/* Includes */
#include "Lin.h"
#include "Lin_Rlin3.h"
#include "Std_Types.h"
#include "iodefine_R5F10AGE.h"
#include "iodefine_ext_R5F10AGE.h"

/* Macros */

/* Typedefs */
typedef enum {
	LIN_UNINIT,
	LIN_IDLE,
	LIN_SLEEP,
	LIN_WAKEUP,
	LIN_BREAK,
	LIN_SYNC,
	LIN_PID,
	LIN_RESP_DATA,
	LIN_RESP_CHKSUM,
} Lin_state_t;

typedef struct {
	Lin_state_t    state;
	Lin_StatusType Status;
	uint8	       datacount;
	Lin_PduType*   Pdu;
} Lin_Control_t;

/* Objects */
Lin_Control_t Lin_Ctrl = {0};

/* Function prototypes */

/* Function definitions */
/*!
 * Initializes the LIN module.
 *
 * \param Config Pointer to LIN driver configuration set.
 */
void Lin_Init(const Lin_ConfigType* Config) {
	(void)Config; // TODO
	Lin_Ctrl.state = LIN_UNINIT;

	Lin_Rlin3_Init(NULL_PTR);

	Lin_Ctrl.state = LIN_IDLE;
}

/*!
 * This function checks if a wakeup has occurred on the addressed LIN channel.
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: API call has been accepted, E_NOT_OK: API call has not been accepted
 */
Std_ReturnType Lin_CheckWakeup(uint8 Channel) {
	(void)Channel; // TODO
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}

/*!
 * Returns the version information of this module.
 *
 * \param versioninfo Pointer to where is stored the version information of this module.
 */
void Lin_GetVersionInfo(Std_VersionInfoType* versioninfo) {
	if (NULL_PTR != versioninfo) {
		versioninfo->moduleID	      = 0;
		versioninfo->vendorID	      = 0;
		versioninfo->sw_major_version = 0;
		versioninfo->sw_minor_version = 1;
		versioninfo->sw_patch_version = 0;
	}
}

/*!
 * Sends a LIN header and a LIN response, if necessary.
 *
 * The direction of the frame response (master response, slave response, slave-to-slave communication) is provided by the PduInfoPtr.
 * Only used for LIN master nodes.
 * \param Channel LIN channel to be addressed
 * \param Pointer to PDU containing the PID, checksum model, response type, Dl and SDU data pointe
 * \return E_OK: Send command has been accepted. E_NOT_OK: Send command has not been accepted, development or production error occurred.
 */
Std_ReturnType Lin_SendFrame(uint8 Channel, const Lin_PduType* PduInfoPtr) {
	Std_ReturnType retval = E_NOT_OK;
	if (Channel == 0) {
		Lin_Rlin3_TxHeader(PduInfoPtr);
	}
	return retval;
}

/*!
 * The service instructs the driver to transmit a go-to-sleep-command on the addressed LIN channel.
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: Sleep command has been accepted, E_NOT_OK: Sleep command has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_GoToSleep(uint8 Channel) {
	(void)Channel; // TODO
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}

/*!
 * Sets the channel state to LIN_CH_SLEEP, enables the wake-up detection and optionally sets
 * the LIN hardware unit to reduced power operation mode (if supported by HW).
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: Command has been accepted E_NOT_OK: Command has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_GoToSleepInternal(uint8 Channel) {
	(void)Channel; // TODO
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}

/*!
 * Generates a wake up pulse and sets the channel state to LIN_CH_OPERATIONAL.
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: Wake-up request has been accepted E_NOT_OK: Wake-up request has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_Wakeup(uint8 Channel) {
	(void)Channel; // TODO
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}

/*!
 * Sets the channel state to LIN_CH_OPERATIONAL without generating a wake up pulse.
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: Wake-up request has been accepted E_NOT_OK: Wake-up request has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_WakeupInternal(uint8 Channel) {
	(void)Channel; // TODO
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}

/*!
 * Gets the status of the LIN driver
 *
 * \param Channel LIN channel to be checked
 * \param Lin_SduPtr Pointer to pointer to a shadow buffer or memory mapped LIN Hardware receive buffer where the current SDU is stored.
 * \return Lin_StatusType
 */
Lin_StatusType Lin_GetStatus(uint8 Channel, const uint8** Lin_SduPtr) {
	(void)Channel;	  // TODO
	(void)Lin_SduPtr; // TODO;
	Lin_StatusType retval = LIN_NOT_OK;
	return retval;
}
