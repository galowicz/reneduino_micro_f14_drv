/*!
 * \file Uart_Cfg.c
 * \brief TODO
 * \author awd110
 *
 */
/* Includes */
#include "Usart_Cfg.h"
#include "Usart_Types.h"

/* Macros */
#define USART_BAUDRATE(baudrate) (32000000UL / (16 * (baudrate)) - 1)
#define RX_BUFFER_LENGTH	 32
#define TX_BUFFER_LENGTH	 32

/* Typedefs */

/* Objects */
/*transmission buffers*/
uint8		 rx_buffer[RX_BUFFER_LENGTH] = {0};
Usart_BufferType usart_rx_buffer	     = {
		    .buffer = rx_buffer,
		    .head   = 0,
		    .tail   = 0,
		    .size   = RX_BUFFER_LENGTH,
		    .len    = 0,
};

uint8		 tx_buffer[TX_BUFFER_LENGTH] = {0};
Usart_BufferType usart_tx_buffer	     = {
		    .buffer = tx_buffer,
		    .head   = 0,
		    .tail   = 0,
		    .size   = TX_BUFFER_LENGTH,
		    .len    = 0,
};

Usart_ChannelConfigType Usart_SAU0Config = {
	.mode	     = USART_MODE_TRANSMIT_ONLY,
	.baudrate    = USART_BAUDRATE(115200),
	.parity	     = USART_PARITY_NONE,
	.frame_size  = USART_FRAME_DATA_8,
	.stopbits    = USART_STOPBIT_1,
	.polarity    = USART_POLATIRY_LOW,
	.echo_enable = 1,

	.cbk_enable	   = 0,
	.NBytes_cbk_enable = 0,
	.char_cbk_enable   = 0,
	.callback_char	   = 0,

	.cbk	   = NULL_PTR,
	.Nbyte_cbk = NULL_PTR,
	.char_cbk  = NULL_PTR,

	.rx_buffer = &usart_rx_buffer,
	.tx_buffer = &usart_tx_buffer,
};
Usart_ConfigType Usart_DefaultConfig = {
	.channel_number = 1,
	.channel_config = &Usart_SAU0Config,

};

/* Function prototypes */

/* Function definitions */
