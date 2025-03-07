/*
 * Std_Types.h
 *
 *  Created on: 29 mar 2024
 *      Author: user
 */

#ifndef STD_TYPES_H
#define STD_TYPES_H
/* Includes */
#include <stdint.h>

/* Macros */
#ifndef STATUSTYPEDEFINED
	#define STATUSTYPEDEFINED
	#define E_OK	 (0x00u)
	#define E_NOT_OK (1u)
typedef unsigned char StatusType; /* OSEK compliance */
#endif

#define STD_HIGH (0x01u) /* Physical state 5V or 3.3V */
#define STD_LOW	 (0x00u) /* Physical state 0V */

#define STD_ACTIVE (0x01u) /* Logical state active */
#define STD_IDLE   (0x00u) /* Logical state idle */

#define STD_ON	(0x01u)
#define STD_OFF (0x00u)

#define NULL_PTR ((void*)0)

#define STD_TRANSFORMER_UNSPECIFIED (0x00u)
#define STD_TRANSFORMER_SERIALIZER  (0x01u)
#define STD_TRANSFORMER_SAFETY	    (0x02u)
#define STD_TRANSFORMER_SECURITY    (0x03u)
#define STD_TRANSFORMER_CUSTOM	    (0xFFu)

#define STD_MESSAGETYPE_REQUEST	 (0u)
#define STD_MESSAGETYPE_RESPONSE (1u)

#define STD_MESSAGERESULT_OK	(0x00u)
#define STD_MESSAGERESULT_ERROR (0x01u)

/* Exported Type definitions */

typedef uint8_t	 uint8;
typedef int8_t	 int8;
typedef uint16_t uint16;
typedef int16_t	 int16;
typedef uint32_t uint32;
typedef int32_t	 int32;

typedef uint8_t Std_ReturnType;

typedef struct {
	uint16 vendorID;
	uint16 moduleID;
	uint8  sw_major_version;
	uint8  sw_minor_version;
	uint8  sw_patch_version;
} Std_VersionInfoType;

typedef uint8 Std_TransformerErrorCode;
typedef uint8 Std_TransformerClass;
typedef struct {
	Std_TransformerErrorCode errorCode;
	Std_TransformerClass	 transformerClass;
} Std_TransformerError;

typedef uint8 Std_MessageTypeType;
typedef uint8 Std_MessageResultType;

typedef Std_ReturnType (*Std_ExtractProtocolHeaderFieldsType)(const uint8* buffer, uint32 bufferLength, Std_MessageTypeType* messageType, Std_MessageResultType* messageResult);
/* Exported Objects */

/* Exported function prototypes */

#endif /* STD_TYPES_H */
