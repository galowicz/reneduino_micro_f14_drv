/*!
 * \file Lin.c
 * \brief Lin driver
 * \author awd110
 */
/* Includes */
#include "Lin.h"
#include "Lin_Rlin3.h"
#include "Lin_Types.h"
#include "Std_Types.h"
#include "iodefine_R5F10AGE.h"
#include "iodefine_ext_R5F10AGE.h"

/* Macros */

/* Typedefs */

/* Objects */
Lin_Control_t Lin_Ctrl = {0};

/* Function prototypes */

/* Function definitions */
void Lin_Init(const Lin_ConfigType* Config) {
	(void)Config; // TODO
	Lin_Ctrl.Status = LIN_NOT_OK;

	Lin_Rlin3_Init(NULL_PTR);

	// TODO: init in sleep
	Lin_Ctrl.Status = LIN_OPERATIONAL;
}

Std_ReturnType Lin_CheckWakeup(uint8 Channel) {
	(void)Channel; // TODO
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}

void Lin_GetVersionInfo(Std_VersionInfoType* versioninfo) {
	if (NULL_PTR != versioninfo) {
		versioninfo->moduleID	      = 0;
		versioninfo->vendorID	      = 0;
		versioninfo->sw_major_version = 0;
		versioninfo->sw_minor_version = 1;
		versioninfo->sw_patch_version = 0;
	}
}

Std_ReturnType Lin_SendFrame(uint8 Channel, const Lin_PduType* PduInfoPtr) {
	Std_ReturnType retval = E_NOT_OK;
	if (Channel == 0) {
		Lin_Rlin3_SendFrame(PduInfoPtr);
		retval = E_OK;
	}
	return retval;
}

Std_ReturnType Lin_GoToSleep(uint8 Channel) {
	(void)Channel; // TODO
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}

Std_ReturnType Lin_GoToSleepInternal(uint8 Channel) {
	(void)Channel; // TODO
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}

Std_ReturnType Lin_Wakeup(uint8 Channel) {
	(void)Channel; // TODO
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}

Std_ReturnType Lin_WakeupInternal(uint8 Channel) {
	(void)Channel; // TODO
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}

Lin_StatusType Lin_GetStatus(uint8 Channel, const uint8** Lin_SduPtr) {
	(void)Channel;	  // TODO
	(void)Lin_SduPtr; // TODO;
	Lin_StatusType retval = LIN_NOT_OK;
	return retval;
}
