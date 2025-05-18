/*!
 * \file Ring_Buffer_Char.c
 * \brief simple ring buffer implementation
 * \author awd110
 */
/* Includes */
#include "RingBuffer.h"
#include "Std_Types.h"
#include <assert.h>

/* Macros */

/* Typedefs */

/* Objects */

/* Function prototypes */

/* Function definitions */

Std_ReturnType RingBuffer_uint8_Init(RingBuffer_uint8_t* ringBuffer, uint8* dataBuffer, RingBuffer_Size_t dataBufferSize) {
	assert(NULL_PTR != ringBuffer);
	assert(NULL_PTR != dataBuffer);
	assert(dataBufferSize > 0);

	if ((NULL_PTR != ringBuffer) && (NULL_PTR != dataBuffer) && (dataBufferSize > 0)) {
		ringBuffer->buffer = dataBuffer;
		ringBuffer->size   = dataBufferSize;
		return RingBuffer_uint8_Clear(ringBuffer);
	}

	return E_NOT_OK;
}

Std_ReturnType RingBuffer_uint8_Clear(RingBuffer_uint8_t* ringBuffer) {
	assert(ringBuffer);

	if (ringBuffer) {
		ringBuffer->head = 0;
		ringBuffer->tail = 0;
		ringBuffer->len	 = 0;
		/*for (int i = 0; i < ringBuffer->size; ++i) {
			ringBuffer->buffer[i] = 0;
		}*/
		return E_OK;
	}
	return E_NOT_OK;
}

Std_ReturnType RingBuffer_uint8_IsEmpty(const RingBuffer_uint8_t* ringBuffer) {
	assert(ringBuffer);
	if (ringBuffer->len == 0)
		return E_OK;
	return E_NOT_OK;
}

RingBuffer_Size_t RingBuffer_uint8_GetLen(const RingBuffer_uint8_t* ringBuffer) {
	assert(ringBuffer);

	if (ringBuffer) {
		return ringBuffer->len;
	}
	return 0;
}

RingBuffer_Size_t RingBuffer_uint8_GetCapacity(const RingBuffer_uint8_t* ringBuffer) {
	assert(ringBuffer);

	if (ringBuffer) {
		return ringBuffer->size;
	}
	return 0;
}

Std_ReturnType RingBuffer_uint8_Put(RingBuffer_uint8_t* ringBuffer, uint8 data) {
	assert(ringBuffer);

	if (ringBuffer) {
		if (ringBuffer->len == ringBuffer->size)
			return E_NOT_OK;
		ringBuffer->buffer[ringBuffer->head++] = data;
		ringBuffer->len++;
		if (ringBuffer->head >= (ringBuffer->size))
			ringBuffer->head = 0;
		return E_OK;
	}
	return E_NOT_OK;
}

Std_ReturnType RingBuffer_uint8_Get(RingBuffer_uint8_t* ringBuffer, uint8* dataPtr) {
	assert(ringBuffer);
	assert(dataPtr);

	if ((ringBuffer) && (dataPtr)) {
		if (ringBuffer->len == 0)
			return E_NOT_OK;
		*dataPtr = ringBuffer->buffer[ringBuffer->tail++];
		ringBuffer->len--;
		if (ringBuffer->tail >= ringBuffer->size)
			ringBuffer->tail = 0;
		return E_OK;
	}
	return E_NOT_OK;
}
