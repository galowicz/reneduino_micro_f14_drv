/*!
 * \file Uart_Types.h
 * \brief TODO
 * \author awd110
 *
 */
#ifndef USART_TYPES_H
#define USART_TYPES_H
/* Includes */
#include "RingBuffer.h"
#include "Std_Types.h"

/* Macros */
#define USART_FRAME_DATA_5 0
#define USART_FRAME_DATA_6 1
#define USART_FRAME_DATA_7 2
#define USART_FRAME_DATA_8 3
#define USART_FRAME_DATA_9 7

#define USART_PARITY_NONE 0
#define USART_PARITY_EVEN 2
#define USART_PARITY_ODD  3

#define USART_STOPBIT_1 0
#define USART_STOPBIT_2 1

#define USART_POLATIRY_LOW  0
#define USART_POLARITY_HIGH 1

/* Exported Type definitions */
/*!
 * type for storing transmitted data
 */
typedef uint8 Usart_DataType;

/*!
 * type for storing transmitted data
 */
typedef uint32 Usart_BaudrateType;

/*!
 * type for selection of transceiver mode
 */
typedef enum {
	USART_MODE_STOP		      = 0x00,
	USART_MODE_RECEIVE_ONLY	      = 0x01,
	USART_MODE_TRANSMIT_ONLY      = 0x02,
	USART_MODE_TRANSMIT_RECEPTION = 0x03,
} Usart_ModeType;

/*!
 * type for frame data size
 */
typedef uint8 Usart_FrameDataSizeType;

/*!
 * type for frame parity configuration
 */
typedef uint8 Usart_ParityType;

/*!
 * type for frame stop bits configuration
 */
typedef uint8 Usart_StopBitType;
/*!
 * type for frame transmission polarity  configuration
 */
typedef uint8 Usart_PolarityType;

/*!
 * channel identification type
 */
typedef enum {
	USART_CHANNEL_SAU0,
	USART_CHANNEL_SAU1,
	USART_CHANNEL_RLIN3,
	USART_CHANNEL_NUM,
} Usart_ChannelType;

/*!
 * type for internal ring buffer
 */
typedef RingBuffer_uint8_t Usart_BufferType;

/*!
 * channel configuration
 */
typedef struct {
	Usart_ChannelType channelId;

	Usart_BaudrateType	baudrate;
	Usart_FrameDataSizeType frame_size;
	Usart_ParityType	parity;
	Usart_StopBitType	stopbits;
	Usart_PolarityType	polarity;
	Usart_ModeType		mode;
	uint8			echo_enable;

	uint8 cbk_enable;	 /*! Callback after each transmission*/
	uint8 NBytes_cbk_enable; /*! Callback after reception of N bytes */
	uint8 char_cbk_enable;	 /*! Callback after specific character received*/

	char callback_char; /*! Character to call callback after */

	void (*cbk)(void);	 /*! Callback after each byte reception */
	void (*Nbyte_cbk)(void); /*! Callback after number of bytes is received */
	void (*char_cbk)(void);	 /*! Callback after reception of specific character */

	Usart_BufferType* rx_buffer; /*! Buffer for received data */
	Usart_BufferType* tx_buffer; /*! Buffer for transmitted  data */
} Usart_ChannelConfigType;

/*!
 * type for module configuration
 */
typedef struct {
	uint8			 channel_number;
	Usart_ChannelConfigType* channel_config;
} Usart_ConfigType;

/*!
 * module status
 */
typedef enum {
	USART_UNINITIALIZED,
	USART_IDLE,
	USART_SLEEP,			/* sleep mode */
	USART_BUSY,			/* not transmitting data, but buffer not empty */
	USART_TRANSMISSION_IN_PROGRESS, /* data is currently being sent */
} Usart_StatusType;
/* Exported Objects */

/* Exported function prototypes */

#endif /* USART_TYPES_H */
