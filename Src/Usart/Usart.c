/*!
 * \file Usart.c
 * \brief TODO
 * \author awd110
 *
 */
/* Includes */
#include "Usart.h"
#include "Std_Types.h"
#include "Usart_Cfg.h"
#include "Usart_Types.h"
#include "iodefine_R5F10AGE.h"
#include "iodefine_ext_R5F10AGE.h"
#include <string.h>

/* Macros */
#define SAU_PER0_SAU0EN_POS (2)
#define SAU_PER0_SAU1EN_POS (3)
#define SAU_PER0_SAU0EN	    (1 << SAU_PER0_SAU0EN_POS)
#define SAU_PER1_SAU0EN	    (1 << SAU_PER0_SAU1EN_POS)

#define SAU_SPSmn_PRS00_POS	 (0)
#define SAU_SPSmn_PRS10_POS	 (4)
#define SAU_SPSmn_PRS00_NODIV	 (0 << SAU_SPSmn_PRS00_POS)
#define SAU_SPSmn_PRS00_DIV_2	 (1 << SAU_SPSmn_PRS00_POS)
#define SAU_SPSmn_PRS00_DIV_4	 (2 << SAU_SPSmn_PRS00_POS)
#define SAU_SPSmn_PRS00_DIV_8	 (3 << SAU_SPSmn_PRS00_POS)
#define SAU_SPSmn_PRS00_DIV_16	 (4 << SAU_SPSmn_PRS00_POS)
#define SAU_SPSmn_PRS00_DIV_32	 (5 << SAU_SPSmn_PRS00_POS)
#define SAU_SPSmn_PRS00_DIV_64	 (6 << SAU_SPSmn_PRS00_POS)
#define SAU_SPSmn_PRS00_DIV_128	 (7 << SAU_SPSmn_PRS00_POS)
#define SAU_SPSmn_PRS00_DIV_256	 (8 << SAU_SPSmn_PRS00_POS)
#define SAU_SPSmn_PRS00_DIV_512	 (9 << SAU_SPSmn_PRS00_POS)
#define SAU_SPSmn_PRS00_DIV_1024 (10 << SAU_SPSmn_PRS00_POS)
#define SAU_SPSmn_PRS00_DIV_2048 (11 << SAU_SPSmn_PRS00_POS)
#define SAU_SPSmn_PRS10_NODIV	 (0 << SAU_SPSmn_PRS10_POS)
#define SAU_SPSmn_PRS10_DIV_2	 (1 << SAU_SPSmn_PRS10_POS)
#define SAU_SPSmn_PRS10_DIV_4	 (2 << SAU_SPSmn_PRS10_POS)
#define SAU_SPSmn_PRS10_DIV_8	 (3 << SAU_SPSmn_PRS10_POS)
#define SAU_SPSmn_PRS10_DIV_16	 (4 << SAU_SPSmn_PRS10_POS)
#define SAU_SPSmn_PRS10_DIV_32	 (5 << SAU_SPSmn_PRS10_POS)
#define SAU_SPSmn_PRS10_DIV_64	 (6 << SAU_SPSmn_PRS10_POS)
#define SAU_SPSmn_PRS10_DIV_128	 (7 << SAU_SPSmn_PRS10_POS)
#define SAU_SPSmn_PRS10_DIV_256	 (8 << SAU_SPSmn_PRS10_POS)
#define SAU_SPSmn_PRS10_DIV_512	 (9 << SAU_SPSmn_PRS10_POS)
#define SAU_SPSmn_PRS10_DIV_1024 (10 << SAU_SPSmn_PRS10_POS)
#define SAU_SPSmn_PRS10_DIV_2048 (11 << SAU_SPSmn_PRS10_POS)

#define SAU_SMRmn_CKS_POS	    (15)
#define SAU_SMRmn_CCS_POS	    (14)
#define SAU_SMRmn_STS_POS	    (8)
#define SAU_SMRmn_SIS_POS	    (6)
#define SAU_SMRmn_MD1_POS	    (1)
#define SAU_SMRmn_MD0_POS	    (0)
#define SAU_SMRmn_ALWAYS	    (1 << 5)
#define SAU_SMRmn_CKS_CK0	    (0 << SAU_SMRmn_CKS_POS)
#define SAU_SMRmn_CKS_CK1	    (1 << SAU_SMRmn_CKS_POS)
#define SAU_SMRmn_CCS_FMCK	    (0 << SAU_SMRmn_CCS_POS)
#define SAU_SMRmn_CCS_SCK	    (1 << SAU_SMRmn_CCS_POS) /* SPI slave */
#define SAU_SMRmn_STS_SW	    (0 << SAU_SMRmn_STS_POS)
#define SAU_SMRmn_STS_RX	    (1 << SAU_SMRmn_STS_POS)
#define SAU_SMRmn_SIS_NON_INVERT    (0 << SAU_SMRmn_SIS_POS)
#define SAU_SMRmn_SIS_INVERT	    (1 << SAU_SMRmn_SIS_POS)
#define SAU_SMRmn_MD12_CSI	    (0 << SAU_SMRmn_MD1_POS)
#define SAU_SMRmn_MD12_UART	    (1 << SAU_SMRmn_MD1_POS)
#define SAU_SMRmn_MD12_I2C	    (2 << SAU_SMRmn_MD1_POS)
#define SAU_SMRmn_MD0_IRQ_TXEND	    (0 << SAU_SMRmn_MD0_POS)
#define SAU_SMRmn_MD0_IRQ_BUF_EMPTY (1 << SAU_SMRmn_MD0_POS)

#define SAU_SCRmn_TXE_POS	   (15)
#define SAU_SCRmn_RXE_POS	   (14)
#define SAU_SCRmn_DAP_POS	   (13)
#define SAU_SCRmn_CKP_POS	   (12)
#define SAU_SCRmn_PTC_POS	   (8)
#define SAU_SCRmn_DIR_POS	   (7)
#define SAU_SCRmn_SLC_POS	   (4)
#define SAU_SCRmn_DLS_POS	   (0)
#define SAU_SCRmn_TRXE_DISABLE	   (0 << SAU_SCRmn_RXE_POS)
#define SAU_SCRmn_TRXE_RX_ONLY	   (1 << SAU_SCRmn_RXE_POS)
#define SAU_SCRmn_TRXE_TX_ONLY	   (2 << SAU_SCRmn_RXE_POS)
#define SAU_SCRmn_TRXE_ENABLE	   (3 << SAU_SCRmn_RXE_POS)
#define SAU_SCRmn_DAP_CSI_2EDGE	   (0 << SAU_SCRmn_DAP_POS)
#define SAU_SCRmn_DAP_CSI_1EDGE	   (1 << SAU_SCRmn_DAP_POS)
#define SAU_SCRmn_CKP_CSI_HIGH	   (0 << SAU_SCRmn_CKP_POS)
#define SAU_SCRmn_CKP_CSI_LOW	   (1 << SAU_SCRmn_CKP_POS)
#define SAU_SCRmn_DAP_CKP_UART_I2C (SAU_SCRmn_CKP_CSI_HIGH | SAU_SCRmn_DAP_CSI_2EDGE)
#define SAU_SCRmn_PTC_NONE	   (0 << SAU_SCRmn_PTC_POS)
#define SAU_SCRmn_PTC_0		   (1 << SAU_SCRmn_PTC_POS)
#define SAU_SCRmn_PTC_EVEN	   (2 << SAU_SCRmn_PTC_POS)
#define SAU_SCRmn_PTC_ODD	   (3 << SAU_SCRmn_PTC_POS)
#define SAU_SCRmn_DIR_MSB_FIRST	   (0 << SAU_SCRmn_DIR_POS)
#define SAU_SCRmn_DIR_LSB_FIRST	   (1 << SAU_SCRmn_DIR_POS)
#define SAU_SCRmn_DIR_I2C	   (SAU_SCRmn_DIR_MSB_FIRST)
#define SAU_SCRmn_SLC_CSI_NO_STOP  (0 << SAU_SCRmn_SLC_POS)
#define SAU_SCRmn_SLC_1STOP	   (1 << SAU_SCRmn_SLC_POS)
#define SAU_SCRmn_SLC_2STOP	   (2 << SAU_SCRmn_SLC_POS)
#define SAU_SCRmn_DLS_7BIT	   (6 << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_8BIT	   (7 << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_9BIT	   (8 << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_10BIT	   (9 << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_11BIT	   (10 << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_12BIT	   (11 << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_13BIT	   (12 << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_14BIT	   (13 << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_15BIT	   (14 << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_16BIT	   (15 << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_I2C	   (SAU_SCRmn_DLS_8BIT)
#define SAU_SCRmn_DLS_USART_7BIT   (SAU_SCRmn_DLS_7BIT)
#define SAU_SCRmn_DLS_USART_8BIT   (SAU_SCRmn_DLS_8BIT)
#define SAU_SCRmn_DLS_USART_9BIT   (SAU_SCRmn_DLS_9BIT)
#define SAU_SCRmn_DLS_USART_16BIT  (SAU_SCRmn_DLS_16BIT)

#define SAU_SDRmn_BRG_POS	(9)
#define SAU_SDRmn_BRG_DIV2	(0 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV4	(1 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV6	(2 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV8	(3 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV10	(4 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV12	(5 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV14	(6 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV16	(7 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV18	(8 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV20	(9 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV22	(10 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV24	(11 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV26	(12 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV28	(13 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV30	(14 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV32	(15 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV34	(16 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV36	(17 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV38	(18 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV40	(19 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV42	(20 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV44	(21 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV46	(22 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV48	(23 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV50	(24 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV52	(25 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV54	(26 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV56	(27 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV58	(28 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV60	(29 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV62	(30 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV64	(31 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV66	(32 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV68	(33 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV70	(34 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV72	(35 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV74	(36 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV76	(37 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV78	(38 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV80	(39 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV82	(40 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV84	(41 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV86	(42 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV88	(43 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV90	(44 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV92	(45 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV94	(46 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV96	(47 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV98	(48 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV100	(49 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV102	(50 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV104	(51 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV106	(52 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV108	(53 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV110	(54 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV112	(55 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV114	(56 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV116	(57 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV118	(58 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV120	(59 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV122	(60 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV124	(61 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV126	(62 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV128	(63 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV130	(64 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV132	(65 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV134	(66 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV136	(67 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV138	(68 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV140	(69 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV142	(70 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV144	(71 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV146	(72 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV148	(73 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV150	(74 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV152	(75 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV154	(76 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV156	(77 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV158	(78 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV160	(79 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV162	(80 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV164	(81 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV166	(82 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV168	(83 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV170	(84 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV172	(85 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV174	(86 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV176	(87 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV178	(88 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV180	(89 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV182	(90 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV184	(91 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV186	(92 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV188	(93 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV190	(94 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV192	(95 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV194	(96 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV196	(97 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV198	(98 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV200	(99 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV202	(100 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV204	(101 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV206	(102 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV208	(103 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV210	(104 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV212	(105 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV214	(106 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV216	(107 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV218	(108 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV220	(109 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV222	(110 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV224	(111 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV226	(112 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV228	(113 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV230	(114 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV232	(115 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV234	(116 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV236	(117 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV238	(118 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV240	(119 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV242	(120 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV244	(121 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV246	(122 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV248	(123 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV250	(124 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV252	(125 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV254	(126 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV256	(127 << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_USART_MIN (SAU_SDRmn_BRG_DIV6)
#define SAU_SDRmn_BRG_I2C_MIN	(SAU_SDRmn_BRG_DIV4)

#define SAU_SIRmn_FECT_POS   (2)
#define SAU_SIRmn_PEC_POS    (1)
#define SAU_SIRmn_OVC_POS    (0)
#define SAU_SIRmn_CLEAR_FECT (1 << SAU_SIRmn_FECT_POS)
#define SAU_SIRmn_CLEAR_PEC  (1 << SAU_SIRmn_PEC_POS)
#define SAU_SIRmn_CLEAR_OVC  (1 << SAU_SIRmn_OVC_POS)

#define SAU_SSRmn_TSF_POS		(6)
#define SAU_SSRmn_BFF_POS		(5)
#define SAU_SSRmn_FEF_POS		(2)
#define SAU_SSRmn_PEF_POS		(1)
#define SAU_SSRmn_OVF_POS		(0)
#define SAU_SSRmn_TSF_COMM_ONGOING(reg) (0 != (reg & (1 << SAU_SSRmn_TSF_POS)))
#define SAU_SSRmn_BFF_HAS_DATA(reg)	(0 != (reg & (1 << SAU_SSRmn_BFF_POS)))
#define SAU_SSRmn_FEF_FRAMING_ERR(reg)	(0 != (reg & (1 << SAU_SSRmn_FEF_POS)))
#define SAU_SSRmn_PEF_PARITY_ERR(reg)	(0 != (reg & (1 << SAU_SSRmn_PEF_POS)))
#define SAU_SSRmn_OVF_OVERRUN_ERR(reg)	(0 != (reg & (1 << SAU_SSRmn_OVF_POS)))

#define SAU_SSm_SSm1_POS   (1)
#define SAU_SSm_SSm0_POS   (0)
#define SAU_SSm_SSm1_START (1 << SAU_SSm_SSm1_POS)
#define SAU_SSm_SSm0_START (1 << SAU_SSm_SSm0_POS)

#define SAU_STm_STm1_POS  (1)
#define SAU_STm_STm0_POS  (0)
#define SAU_STm_STm1_STOP (1 << SAU_STm_STm1_POS)
#define SAU_STm_STm0_STOP (1 << SAU_STm_STm0_POS)

#define SAU_SEm_SEm1_POS	  (1)
#define SAU_SEm_SEm0_POS	  (0)
#define SAU_SEm_SEm1_ENABLED(reg) (0 != (reg & (1 << SAU_SEm_SEm1_POS)))
#define SAU_SEm_SEm0_ENABLED(reg) (0 != (reg & (1 << SAU_SEm_SEm0_POS)))

#define SAU_SOEm_SOEm1_POS	 (1)
#define SAU_SOEm_SOEm0_POS	 (0)
#define SAU_SOEm_SOEm1_OUTPUT_EN (1 << SAU_SOEm_SOEm1_POS)
#define SAU_SOEm_SOEm0_OUTPUT_EN (1 << SAU_SOEm_SOEm0_POS)

#define SAU_SOm_CKOm1_POS	  (1)
#define SAU_SOm_CKOm0_POS	  (0)
#define SAU_SOm_SOm1_POS	  (1)
#define SAU_SOm_SOm0_POS	  (0)
#define SAU_CKOm_CKOm1_CLOCK_HIGH (1 << SAU_SOm_CKOm1_POS)
#define SAU_CKOm_CKOm0_CLOCK_HIGH (1 << SAU_SOm_CKOm0_POS)
#define SAU_SOm_SOm1_OUTPUT_HIGH  (1 << SAU_SOm_SOm1_POS)
#define SAU_SOm_SOm0_OUTPUT_HIGH  (1 << SAU_SOm_SOm0_POS)

#define SAU_SOLm_SOLm1_POS		 (1)
#define SAU_SOLm_SOLm0_POS		 (0)
#define SAU_SOLm_SOLm1_DATA_INVERTED	 (1 << SAU_SOLm_SOLm1_POS)
#define SAU_SOLm_SOLm1_DATA_NON_INVERTED (0 << SAU_SOLm_SOLm1_POS)
#define SAU_SOLm_SOLm0_DATA_INVERTED	 (1 << SAU_SOLm_SOLm0_POS)
#define SAU_SOLm_SOLm0_DATA_NON_INVERTED (0 << SAU_SOLm_SOLm0_POS)

#define SAU_SSEm_SSEm1_POS	       (1)
#define SAU_SSEm_SSEm0_POS	       (0)
#define SAU_SSEm_SSEm1_SS_ENABLED(reg) (0 != (reg & (1 << SAU_SSEm_SSEm1_POS)))
#define SAU_SSEm_SSEm0_SS_ENABLED(reg) (0 != (reg & (1 << SAU_SSEm_SSEm0_POS)))

#define SAU_ISC_ISC0_POS   (0)
#define SAU_ISC_ISC0_RXD0  (1 << SAU_ISC_ISC0_POS)
#define SAU_ISC_ISC0_INTP0 (0 << SAU_ISC_ISC0_POS)

#define SAU_NFEN0_SNFEN10_POS (2)
#define SAU_NFEN0_SNFEN00_POS (0)
#define SAU_NFEN0_SNFEN10_ON  (1 << SAU_NFEN0_SNFEN10_POS)
#define SAU_NFEN0_SNFEN00_ON  (1 << SAU_NFEN0_SNFEN00_POS)

/* Typedefs */
/*!
 * type for module state
 */

/*!
 * main control structure for usart
 */
typedef struct {
	Usart_StatusType state;

	uint8 cbk_enable;	 /*! Callback after each transmission*/
	uint8 NBytes_cbk_enable; /*! Callback after reception of N bytes */
	uint8 char_cbk_enable;	 /*! Callback after specific character received*/

	char callback_char; /*! Character to call callback after */

	void (*cbk)(void);	 /*! Callback after each byte reception */
	void (*Nbyte_cbk)(void); /*! Callback after number of bytes is received */
	void (*char_cbk)(void);	 /*! Callback after reception of specific character */

	volatile Usart_BufferType* rx_buffer; /*! Buffer for received data */
	volatile Usart_BufferType* tx_buffer; /*! Buffer for transmitted  data */

} Usart_Control_t;

/* Objects */
Usart_Control_t Usart_Control[SAU_CHANNELS] = {0};

/* Function prototypes */
static void Usart_InitSAU0(Usart_ChannelConfigType* ConfigPtr);

/* Function definitions */
void Usart_Init(const Usart_ConfigType* ConfigPtr) {
	PER0_bit.no2 = 1;

	for (Usart_ChannelType i = 0; i < ConfigPtr->channel_number; i++) {
		Usart_ChannelType channel = ConfigPtr->channel_config[i].channelId;

		switch (channel) {
		case USART_CHANNEL_SAU0:
			Usart_InitSAU0(&ConfigPtr->channel_config[i]);
			break;
		case USART_CHANNEL_SAU1:
			break;
		case USART_CHANNEL_RLIN3:
			break;
		default:
			break;
		}

		Usart_Control[channel].state = USART_IDLE;
	}
}

Std_ReturnType Usart_TransmitData(Usart_ChannelType Channel, const Usart_DataType* DataPtr, uint8 Length) {
	Std_ReturnType retval = E_NOT_OK;
	return retval;
}

uint8 Usart_GetReceivedData(Usart_ChannelType Channel, Usart_DataType* DataPtr, uint8 MaxLength) {
	uint8 retval = 0;
	return retval;
}

void Usart_GetStatus(Usart_ChannelType Channel, Usart_StatusType* StatusPtr);

void Usart_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr) {
	if (NULL_PTR != VersionInfoPtr) {
		VersionInfoPtr->moduleID	 = 0;
		VersionInfoPtr->vendorID	 = 0;
		VersionInfoPtr->sw_major_version = 0;
		VersionInfoPtr->sw_minor_version = 1;
		VersionInfoPtr->sw_patch_version = 0;
	}
}

// ISR(Usart_RX_vect) {
// 	if (USART_Control.rx_buffer_len < USART_Control.rx_current) {
// 		USART_Control.rx_buffer[USART_Control.rx_current++] = UDR0;
// 	}
// }
//
// ISR(Usart_TX_vect) {
// 	// PINB = 1 << PB5;
// 	if (USART_Control.tx_current < USART_Control.tx_data_length) {
// 		UDR0 = USART_Control.tx_buffer[USART_Control.tx_current++];
// 	}
// }

static void Usart_InitSAU0(Usart_ChannelConfigType* ConfigPtr) {
	Usart_Control[(unsigned int)USART_CHANNEL_SAU0].rx_buffer = ConfigPtr->rx_buffer;
	Usart_Control[(unsigned int)USART_CHANNEL_SAU0].tx_buffer = ConfigPtr->tx_buffer;

	PER0 |= SAU_PER0_SAU0EN;

	STMK0 = 1U; /* disable INTST0 interrupt */
	STIF0 = 0U; /* clear INTST0 interrupt flag */
	SRMK0 = 1U; /* disable INTSR0 interrupt */
	SRIF0 = 0U; /* clear INTSR0 interrupt flag */
	/* Set INTST0 low priority */
	STPR10 = 1U;
	STPR00 = 1U;
	/* Set INTSR0 low priority */
	SRPR10 = 1U;
	SRPR00 = 1U;

	// TX
	if ((ConfigPtr->mode == USART_MODE_TRANSMIT_ONLY) || (ConfigPtr->mode == USART_MODE_TRANSMIT_RECEPTION)) {
		SPS0  = SAU_SPSmn_PRS00_DIV_2;
		ST0   = SAU_STm_STm0_STOP;
		SMR00 = SAU_SMRmn_ALWAYS | SAU_SMRmn_CKS_CK0 | SAU_SMRmn_CCS_FMCK | SAU_SMRmn_STS_SW | SAU_SMRmn_SIS_INVERT | SAU_SMRmn_MD12_UART | SAU_SMRmn_MD0_IRQ_BUF_EMPTY;
		SCR00 = (uint16)(SAU_SCRmn_TRXE_TX_ONLY | SAU_SCRmn_CKP_CSI_HIGH | SAU_SCRmn_DAP_CSI_2EDGE | SAU_SCRmn_PTC_NONE | SAU_SCRmn_DIR_LSB_FIRST | SAU_SCRmn_SLC_1STOP | SAU_SCRmn_DLS_8BIT);
		SDR00 = (uint16)SAU_SDRmn_BRG_DIV138;
		// SOL0  = SAU_SOLm_SOLm0_DATA_NON_INVERTED;
		// SO0   = SAU_CKOm_CKOm0_CLOCK_HIGH | SAU_SOm_SOm0_OUTPUT_HIGH;
		// SOE0  = SAU_SOEm_SOEm0_OUTPUT_EN;
		// SS0 = SAU_SSm_SSm0_START;
		//
		// for (uint8 i = 255; i != 0; i--) {
		// 	if (SAU_SSEm_SSEm0_SS_ENABLED(SSE0))
		// 		break;
		//
		// 	asm("nop");
		// }
		// SPS0 &= 0x00F0;
		// SPS0 |= 0x0001;
		// SMR00 = 0x0020 | 0x0000 | 0x0000 | 0x0002 | 0x0000;
		// SCR00 = SAU_SCRmn_TRXE_TX_ONLY | SAU_SCRmn_CKP_CSI_HIGH | SAU_SCRmn_DAP_CSI_2EDGE | SAU_SCRmn_PTC_NONE | SAU_SCRmn_DIR_LSB_FIRST | SAU_SCRmn_SLC_1STOP | SAU_SCRmn_DLS_8BIT;
		// SDR00 = 0x8800;
	}

	// RX
	if ((ConfigPtr->mode == USART_MODE_RECEIVE_ONLY) || (ConfigPtr->mode == USART_MODE_TRANSMIT_RECEPTION)) {
		NFEN0 |= 0x01;
		SIR01 = 0x0004 | 0x0002 | 0x0001; /* clear error flag */
		SMR01 = 0x0020 | 0x0000 | 0x0100 | 0x0000 | 0x0002 | 0x0000;
		SCR01 = SAU_SCRmn_TRXE_RX_ONLY | 0x0000 | 0x0080 | 0x0010 | 0x0007;
		SDR01 = 0x8800;
		SO0 |= 0x0001;
		SOL0 |= 0x0000; /* output level normal */
		SOE0 |= 0x0001; /* enable UART0 output */

		SO0 |= 0x0001;		  /* output level normal */
		SOE0 |= 0x0001;		  /* enable UART0 output */
		SS0 |= (0x0002 | 0x0001); /* enable UART0 receive and transmit */
		STIF0 = 0U;		  /* clear INTST0 interrupt flag */
		SRIF0 = 0U;		  /* clear INTSR0 interrupt flag */
		STMK0 = 0U;		  /* enable INTST0 interrupt */
		SRMK0 = 0U;		  /* enable INTSR0 interrupt */

		SDR00 = 0x55;
	}
}
