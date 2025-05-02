/*!
 * \file Lin_Hw_Rlin3.h
 * \brief Header for low level routines for rlin3
 * \author awd110
 */
#ifndef LIN_RLIN3_H_
#define LIN_RLIN3_H_
/* Includes */
#include "Lin_GeneralTypes.h"
#include "Std_Types.h"

/* Macros */

/* Exported Type definitions */
typedef struct {
	uint8 tbd;
} Lin_Rlin3_ConfigType;

/* Exported Objects */

/* Exported function prototypes */

/*!
 * Initializes the LIN module.
 *
 * \param Config Pointer to LIN driver configuration set.
 */
void Lin_Rlin3_Init(const Lin_Rlin3_ConfigType* Config);

/*!
 * Deinitializes rlin3
 */
void Lin_Rlin3_DeInit(void);
/*!
 * prepare rlin to sleep
 */
void Lin_Rlin3_PreSleep(void);
/*!
 * send wakeup signal
 */
void Lin_Rlin3_TxWUPSig(void);

/*!
 * This function checks if a wakeup has occurred on the addressed LIN channel.
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: API call has been accepted, E_NOT_OK: API call has not been accepted
 */
Std_ReturnType Lin_Rlin3_CheckWakeup(uint8 Channel);

/*!
 * Returns the version information of this module.
 *
 * \param versioninfo Pointer to where is stored the version information of this module.
 */
void Lin_Rlin3_GetVersionInfo(Std_VersionInfoType* versioninfo);

/*!
 * Sends a LIN header and a LIN response, if necessary.
 *
 * The direction of the frame response (master response, slave response, slave-to-slave communication) is provided by the PduInfoPtr.
 * Only used for LIN master nodes.
 * \param Channel LIN channel to be addressed
 * \param Pointer to PDU containing the PID, checksum model, response type, Dl and SDU data pointe
 * \return E_OK: Send command has been accepted. E_NOT_OK: Send command has not been accepted, development or production error occurred.
 */
Std_ReturnType Lin_Rlin3_SendFrame(const Lin_PduType* PduInfoPtr);

/*!
 * The service instructs the driver to transmit a go-to-sleep-command on the addressed LIN channel.
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: Sleep command has been accepted, E_NOT_OK: Sleep command has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_Rlin3_GoToSleep(uint8 Channel);

/*!
 * Sets the channel state to LIN_CH_SLEEP, enables the wake-up detection and optionally sets
 * the LIN hardware unit to reduced power operation mode (if supported by HW).
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: Command has been accepted E_NOT_OK: Command has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_Rlin3_GoToSleepInternal(uint8 Channel);

/*!
 * Generates a wake up pulse and sets the channel state to LIN_CH_OPERATIONAL.
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: Wake-up request has been accepted E_NOT_OK: Wake-up request has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_Rlin3_Wakeup(uint8 Channel);

/*!
 * Sets the channel state to LIN_CH_OPERATIONAL without generating a wake up pulse.
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: Wake-up request has been accepted E_NOT_OK: Wake-up request has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_Rlin3_WakeupInternal(uint8 Channel);

/*!
 * Gets the status of the LIN driver
 *
 * \param Channel LIN channel to be checked
 * \param Lin_SduPtr Pointer to pointer to a shadow buffer or memory mapped LIN Hardware receive buffer where the current SDU is stored.
 * \return Lin_StatusType
 */
Lin_StatusType Lin_Rlin3_GetStatus(uint8 Channel, const uint8** Lin_SduPtr);
#endif /* LIN_RLIN3_H_ */
