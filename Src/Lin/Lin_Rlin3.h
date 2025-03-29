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
} Lin_Rlin3_Config_t;

/* Exported Objects */

/* Exported function prototypes */
void Lin_Rlin3_Init(Lin_Rlin3_Config_t* Configptr);
void Lin_Rlin3_DeInit(void);
void Lin_Rlin3_TxHeader(const Lin_PduType * Pdu);
void Lin_Rlin3_PreSleep(void);
void Lin_Rlin3_TxWUPSig(void);

#endif /* LIN_RLIN3_H_ */
