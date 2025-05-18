/*!
 * \file RingBuffer.h
 * \brief simple ring buffer implementation
 * \author awd110
 */
#ifndef RING_BUFFER_H
#define RING_BUFFER_H
/* Includes */
#include "Std_Types.h"
#include <stddef.h>

/* Macros */

/* Exported Type definitions */
typedef size_t RingBuffer_Size_t;

typedef struct {
	uint8*		  buffer;
	RingBuffer_Size_t head;
	RingBuffer_Size_t tail;
	RingBuffer_Size_t size;
	RingBuffer_Size_t len;

} RingBuffer_uint8_t;

typedef struct {
	uint16*		  buffer;
	RingBuffer_Size_t head;
	RingBuffer_Size_t tail;
	RingBuffer_Size_t size;
	RingBuffer_Size_t len;

} RingBuffer_uint16_t;

typedef struct {
	uint32*		  buffer;
	RingBuffer_Size_t head;
	RingBuffer_Size_t tail;
	RingBuffer_Size_t size;
	RingBuffer_Size_t len;

} RingBuffer_uint32_t;

/* Exported Objects */

/* Exported function prototypes */
Std_ReturnType	  RingBuffer_uint8_Init(RingBuffer_uint8_t* ringBuffer, uint8* dataBuffer, RingBuffer_Size_t dataBufferSize);
Std_ReturnType	  RingBuffer_uint8_Clear(RingBuffer_uint8_t* ringBuffer);
Std_ReturnType	  RingBuffer_uint8_IsEmpty(const RingBuffer_uint8_t* ringBuffer);
RingBuffer_Size_t RingBuffer_uint8_GetLen(const RingBuffer_uint8_t* ringBuffer);
RingBuffer_Size_t RingBuffer_uint8_GetCapacity(const RingBuffer_uint8_t* ringBuffer);
Std_ReturnType	  RingBuffer_uint8_Put(RingBuffer_uint8_t* ringBuffer, uint8 data);
Std_ReturnType	  RingBuffer_uint8_Get(RingBuffer_uint8_t* ringBuffer, uint8* dataPtr);

#endif /* RING_BUFFER_H */
