/*!
 * \file Lin.h
 * \brief Lin Driver Api
 * \author awd110
 */
#ifndef LIN_H_
#define LIN_H_
/* Includes */
#include "Lin_GeneralTypes.h"
#include "Lin_Types.h"
#include "Std_Types.h"

/* Macros */
#define LIN_E_UNINIT	       0x00
#define LIN_E_INVALID_CHANNEL  0x02
#define LIN_E_INVALID_POINTER  0x03
#define LIN_E_STATE_TRANSITION 0x04
#define LIN_E_PARAM_POINTER    0x05

/* Exported Type definitions */

/* Exported Objects */

/* Exported function prototypes */
/*!
 * Initializes the LIN module.
 *
 * \param Config Pointer to LIN driver configuration set.
 */
void Lin_Init(const Lin_ConfigType* Config);

/*!
 * This function checks if a wakeup has occurred on the addressed LIN channel.
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: API call has been accepted, E_NOT_OK: API call has not been accepted
 */
Std_ReturnType Lin_CheckWakeup(uint8 Channel);

/*!
 * Returns the version information of this module.
 *
 * \param versioninfo Pointer to where is stored the version information of this module.
 */
void Lin_GetVersionInfo(Std_VersionInfoType* versioninfo);

/*!
 * Sends a LIN header and a LIN response, if necessary.
 *
 * The direction of the frame response (master response, slave response, slave-to-slave communication) is provided by the PduInfoPtr.
 * Only used for LIN master nodes.
 * \param Channel LIN channel to be addressed
 * \param Pointer to PDU containing the PID, checksum model, response type, Dl and SDU data pointe
 * \return E_OK: Send command has been accepted. E_NOT_OK: Send command has not been accepted, development or production error occurred.
 */
Std_ReturnType Lin_SendFrame(uint8 Channel, const Lin_PduType* PduInfoPtr);

/*!
 * The service instructs the driver to transmit a go-to-sleep-command on the addressed LIN channel.
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: Sleep command has been accepted, E_NOT_OK: Sleep command has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_GoToSleep(uint8 Channel);

/*!
 * Sets the channel state to LIN_CH_SLEEP, enables the wake-up detection and optionally sets
 * the LIN hardware unit to reduced power operation mode (if supported by HW).
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: Command has been accepted E_NOT_OK: Command has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_GoToSleepInternal(uint8 Channel);

/*!
 * Generates a wake up pulse and sets the channel state to LIN_CH_OPERATIONAL.
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: Wake-up request has been accepted E_NOT_OK: Wake-up request has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_Wakeup(uint8 Channel);

/*!
 * Sets the channel state to LIN_CH_OPERATIONAL without generating a wake up pulse.
 *
 * \param Channel LIN channel to be addressed
 * \return E_OK: Wake-up request has been accepted E_NOT_OK: Wake-up request has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_WakeupInternal(uint8 Channel);

/*!
 * Gets the status of the LIN driver
 *
 * \param Channel LIN channel to be checked
 * \param Lin_SduPtr Pointer to pointer to a shadow buffer or memory mapped LIN Hardware receive buffer where the current SDU is stored.
 * \return Lin_StatusType
 */
Lin_StatusType Lin_GetStatus(uint8 Channel, const uint8** Lin_SduPtr);

#endif /* LIN_H_ */
