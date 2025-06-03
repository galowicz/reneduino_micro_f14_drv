/*!
 * \file spi_dl.c
 * \brief spi_datalink layer
 * \author awd110
 */
/* Includes */
#include "Spi_Ll.h"
#include "Std_Types.h"
#include "iodefine_R5F10AGE.h"
#include "iodefine_ext_R5F10AGE.h"
#include "shiftout.h"

/* Macros */
#define SAU_PER0_SAU0EN_POS (2U)
#define SAU_PER0_SAU1EN_POS (3U)
#define SAU_PER0_SAU0EN	    (1U << SAU_PER0_SAU0EN_POS)
#define SAU_PER1_SAU0EN	    (1U << SAU_PER0_SAU1EN_POS)

#define SAU_SPSmn_PRS000_POS	 (0U)
#define SAU_SPSmn_PRS000_MASK	 (0x000FU)
#define SAU_SPSmn_PRS010_POS	 (4U)
#define SAU_SPSmn_PRS010_MASK	 (0x00F0U)
#define SAU_SPSmn_PRS00_NODIV	 (0U << SAU_SPSmn_PRS000_POS)
#define SAU_SPSmn_PRS00_DIV_2	 (1U << SAU_SPSmn_PRS000_POS)
#define SAU_SPSmn_PRS00_DIV_4	 (2U << SAU_SPSmn_PRS000_POS)
#define SAU_SPSmn_PRS00_DIV_8	 (3U << SAU_SPSmn_PRS000_POS)
#define SAU_SPSmn_PRS00_DIV_16	 (4U << SAU_SPSmn_PRS000_POS)
#define SAU_SPSmn_PRS00_DIV_32	 (5U << SAU_SPSmn_PRS000_POS)
#define SAU_SPSmn_PRS00_DIV_64	 (6U << SAU_SPSmn_PRS000_POS)
#define SAU_SPSmn_PRS00_DIV_128	 (7U << SAU_SPSmn_PRS000_POS)
#define SAU_SPSmn_PRS00_DIV_256	 (8U << SAU_SPSmn_PRS000_POS)
#define SAU_SPSmn_PRS00_DIV_512	 (9U << SAU_SPSmn_PRS000_POS)
#define SAU_SPSmn_PRS00_DIV_1024 (10U << SAU_SPSmn_PRS000_POS)
#define SAU_SPSmn_PRS00_DIV_2048 (11U << SAU_SPSmn_PRS000_POS)
#define SAU_SPSmn_PRS10_NODIV	 (0U << SAU_SPSmn_PRS010_POS)
#define SAU_SPSmn_PRS10_DIV_2	 (1U << SAU_SPSmn_PRS010_POS)
#define SAU_SPSmn_PRS10_DIV_4	 (2U << SAU_SPSmn_PRS010_POS)
#define SAU_SPSmn_PRS10_DIV_8	 (3U << SAU_SPSmn_PRS010_POS)
#define SAU_SPSmn_PRS10_DIV_16	 (4U << SAU_SPSmn_PRS010_POS)
#define SAU_SPSmn_PRS10_DIV_32	 (5U << SAU_SPSmn_PRS010_POS)
#define SAU_SPSmn_PRS10_DIV_64	 (6U << SAU_SPSmn_PRS010_POS)
#define SAU_SPSmn_PRS10_DIV_128	 (7U << SAU_SPSmn_PRS010_POS)
#define SAU_SPSmn_PRS10_DIV_256	 (8U << SAU_SPSmn_PRS010_POS)
#define SAU_SPSmn_PRS10_DIV_512	 (9U << SAU_SPSmn_PRS010_POS)
#define SAU_SPSmn_PRS10_DIV_1024 (10U << SAU_SPSmn_PRS010_POS)
#define SAU_SPSmn_PRS10_DIV_2048 (11U << SAU_SPSmn_PRS010_POS)

#define SAU_SMRmn_CKS_POS	    (15U)
#define SAU_SMRmn_CCS_POS	    (14U)
#define SAU_SMRmn_STS_POS	    (8U)
#define SAU_SMRmn_SIS_POS	    (6U)
#define SAU_SMRmn_MD1_POS	    (1U)
#define SAU_SMRmn_MD0_POS	    (0U)
#define SAU_SMRmn_ALWAYS	    (1U << 5U)
#define SAU_SMRmn_CKS_CK0	    (0U << SAU_SMRmn_CKS_POS)
#define SAU_SMRmn_CKS_CK1	    (1U << SAU_SMRmn_CKS_POS)
#define SAU_SMRmn_CCS_FMCK	    (0U << SAU_SMRmn_CCS_POS)
#define SAU_SMRmn_CCS_SCK	    (1U << SAU_SMRmn_CCS_POS) /* SPI slave */
#define SAU_SMRmn_STS_SW	    (0U << SAU_SMRmn_STS_POS)
#define SAU_SMRmn_STS_RX	    (1U << SAU_SMRmn_STS_POS)
#define SAU_SMRmn_SIS_NON_INVERT    (0U << SAU_SMRmn_SIS_POS)
#define SAU_SMRmn_SIS_INVERT	    (1U << SAU_SMRmn_SIS_POS)
#define SAU_SMRmn_MD12_CSI	    (0U << SAU_SMRmn_MD1_POS)
#define SAU_SMRmn_MD12_UART	    (1U << SAU_SMRmn_MD1_POS)
#define SAU_SMRmn_MD12_I2C	    (2U << SAU_SMRmn_MD1_POS)
#define SAU_SMRmn_MD0_IRQ_TXEND	    (0U << SAU_SMRmn_MD0_POS)
#define SAU_SMRmn_MD0_IRQ_BUF_EMPTY (1U << SAU_SMRmn_MD0_POS)

#define SAU_SCRmn_TXE_POS	   (15U)
#define SAU_SCRmn_RXE_POS	   (14U)
#define SAU_SCRmn_DAP_POS	   (13U)
#define SAU_SCRmn_CKP_POS	   (12U)
#define SAU_SCRmn_PTC_POS	   (8U)
#define SAU_SCRmn_DIR_POS	   (7U)
#define SAU_SCRmn_SLC_POS	   (4U)
#define SAU_SCRmn_DLS_POS	   (0U)
#define SAU_SCRmn_TRXE_DISABLE	   (0U << SAU_SCRmn_RXE_POS)
#define SAU_SCRmn_TRXE_RX_ONLY	   (1U << SAU_SCRmn_RXE_POS)
#define SAU_SCRmn_TRXE_TX_ONLY	   (2U << SAU_SCRmn_RXE_POS)
#define SAU_SCRmn_TRXE_ENABLE	   (3U << SAU_SCRmn_RXE_POS)
#define SAU_SCRmn_DAP_CSI_2EDGE	   (0U << SAU_SCRmn_DAP_POS)
#define SAU_SCRmn_DAP_CSI_1EDGE	   (1U << SAU_SCRmn_DAP_POS)
#define SAU_SCRmn_CKP_CSI_HIGH	   (0U << SAU_SCRmn_CKP_POS)
#define SAU_SCRmn_CKP_CSI_LOW	   (1U << SAU_SCRmn_CKP_POS)
#define SAU_SCRmn_DAP_CKP_UART_I2C (SAU_SCRmn_CKP_CSI_HIGH | SAU_SCRmn_DAP_CSI_2EDGE)
#define SAU_SCRmn_PTC_NONE	   (0U << SAU_SCRmn_PTC_POS)
#define SAU_SCRmn_PTC_0		   (1U << SAU_SCRmn_PTC_POS)
#define SAU_SCRmn_PTC_EVEN	   (2U << SAU_SCRmn_PTC_POS)
#define SAU_SCRmn_PTC_ODD	   (3U << SAU_SCRmn_PTC_POS)
#define SAU_SCRmn_DIR_MSB_FIRST	   (0U << SAU_SCRmn_DIR_POS)
#define SAU_SCRmn_DIR_LSB_FIRST	   (1U << SAU_SCRmn_DIR_POS)
#define SAU_SCRmn_DIR_I2C	   (SAU_SCRmn_DIR_MSB_FIRST)
#define SAU_SCRmn_SLC_CSI_NO_STOP  (0U << SAU_SCRmn_SLC_POS)
#define SAU_SCRmn_SLC_1STOP	   (1U << SAU_SCRmn_SLC_POS)
#define SAU_SCRmn_SLC_2STOP	   (2U << SAU_SCRmn_SLC_POS)
#define SAU_SCRmn_DLS_7BIT	   (6U << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_8BIT	   (7U << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_9BIT	   (8U << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_10BIT	   (9U << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_11BIT	   (10U << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_12BIT	   (11U << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_13BIT	   (12U << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_14BIT	   (13U << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_15BIT	   (14U << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_16BIT	   (15U << SAU_SCRmn_DLS_POS)
#define SAU_SCRmn_DLS_I2C	   (SAU_SCRmn_DLS_8BIT)
#define SAU_SCRmn_DLS_USART_7BIT   (SAU_SCRmn_DLS_7BIT)
#define SAU_SCRmn_DLS_USART_8BIT   (SAU_SCRmn_DLS_8BIT)
#define SAU_SCRmn_DLS_USART_9BIT   (SAU_SCRmn_DLS_9BIT)
#define SAU_SCRmn_DLS_USART_16BIT  (SAU_SCRmn_DLS_16BIT)

#define SAU_SDRmn_BRG_POS	(9U)
#define SAU_SDRmn_BRG_DIV2	(0U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV4	(1U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV6	(2U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV8	(3U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV10	(4U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV12	(5U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV14	(6U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV16	(7U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV18	(8U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV20	(9U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV22	(10U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV24	(11U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV26	(12U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV28	(13U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV30	(14U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV32	(15U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV34	(16U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV36	(17U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV38	(18U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV40	(19U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV42	(20U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV44	(21U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV46	(22U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV48	(23U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV50	(24U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV52	(25U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV54	(26U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV56	(27U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV58	(28U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV60	(29U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV62	(30U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV64	(31U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV66	(32U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV68	(33U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV70	(34U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV72	(35U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV74	(36U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV76	(37U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV78	(38U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV80	(39U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV82	(40U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV84	(41U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV86	(42U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV88	(43U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV90	(44U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV92	(45U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV94	(46U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV96	(47U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV98	(48U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV100	(49U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV102	(50U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV104	(51U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV106	(52U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV108	(53U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV110	(54U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV112	(55U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV114	(56U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV116	(57U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV118	(58U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV120	(59U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV122	(60U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV124	(61U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV126	(62U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV128	(63U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV130	(64U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV132	(65U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV134	(66U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV136	(67U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV138	(68U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV140	(69U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV142	(70U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV144	(71U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV146	(72U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV148	(73U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV150	(74U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV152	(75U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV154	(76U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV156	(77U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV158	(78U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV160	(79U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV162	(80U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV164	(81U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV166	(82U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV168	(83U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV170	(84U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV172	(85U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV174	(86U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV176	(87U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV178	(88U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV180	(89U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV182	(90U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV184	(91U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV186	(92U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV188	(93U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV190	(94U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV192	(95U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV194	(96U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV196	(97U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV198	(98U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV200	(99U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV202	(100U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV204	(101U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV206	(102U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV208	(103U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV210	(104U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV212	(105U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV214	(106U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV216	(107U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV218	(108U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV220	(109U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV222	(110U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV224	(111U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV226	(112U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV228	(113U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV230	(114U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV232	(115U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV234	(116U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV236	(117U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV238	(118U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV240	(119U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV242	(120U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV244	(121U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV246	(122U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV248	(123U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV250	(124U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV252	(125U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV254	(126U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_DIV256	(127U << SAU_SDRmn_BRG_POS)
#define SAU_SDRmn_BRG_USART_MIN (SAU_SDRmn_BRG_DIV6)
#define SAU_SDRmn_BRG_I2C_MIN	(SAU_SDRmn_BRG_DIV4)

#define SAU_SIRmn_FECT_POS   (2U)
#define SAU_SIRmn_PEC_POS    (1U)
#define SAU_SIRmn_OVC_POS    (0U)
#define SAU_SIRmn_CLEAR_FECT (1U << SAU_SIRmn_FECT_POS)
#define SAU_SIRmn_CLEAR_PEC  (1U << SAU_SIRmn_PEC_POS)
#define SAU_SIRmn_CLEAR_OVC  (1U << SAU_SIRmn_OVC_POS)

#define SAU_SSRmn_TSF_POS		(6U)
#define SAU_SSRmn_BFF_POS		(5U)
#define SAU_SSRmn_FEF_POS		(2U)
#define SAU_SSRmn_PEF_POS		(1U)
#define SAU_SSRmn_OVF_POS		(0U)
#define SAU_SSRmn_TSF_COMM_ONGOING(reg) (0U != (reg & (1U << SAU_SSRmn_TSF_POS)))
#define SAU_SSRmn_BFF_HAS_DATA(reg)	(0U != (reg & (1U << SAU_SSRmn_BFF_POS)))
#define SAU_SSRmn_FEF_FRAMING_ERR(reg)	(0U != (reg & (1U << SAU_SSRmn_FEF_POS)))
#define SAU_SSRmn_PEF_PARITY_ERR(reg)	(0U != (reg & (1U << SAU_SSRmn_PEF_POS)))
#define SAU_SSRmn_OVF_OVERRUN_ERR(reg)	(0U != (reg & (1U << SAU_SSRmn_OVF_POS)))

#define SAU_SSm_SSm1_POS   (1U)
#define SAU_SSm_SSm0_POS   (0U)
#define SAU_SSm_SSm1_START (1U << SAU_SSm_SSm1_POS)
#define SAU_SSm_SSm0_START (1U << SAU_SSm_SSm0_POS)

#define SAU_STm_STm1_POS  (1U)
#define SAU_STm_STm0_POS  (0U)
#define SAU_STm_STm1_STOP (1U << SAU_STm_STm1_POS)
#define SAU_STm_STm0_STOP (1U << SAU_STm_STm0_POS)

#define SAU_SEm_SEm1_POS	  (1U)
#define SAU_SEm_SEm0_POS	  (0U)
#define SAU_SEm_SEm1_ENABLED(reg) (0U != (reg & (1 << SAU_SEm_SEm1_POS)))
#define SAU_SEm_SEm0_ENABLED(reg) (0U != (reg & (1 << SAU_SEm_SEm0_POS)))

#define SAU_SOEm_SOEm1_POS	 (1U)
#define SAU_SOEm_SOEm0_POS	 (0U)
#define SAU_SOEm_SOEm1_OUTPUT_EN (1U << SAU_SOEm_SOEm1_POS)
#define SAU_SOEm_SOEm0_OUTPUT_EN (1U << SAU_SOEm_SOEm0_POS)

#define SAU_SOm_CKOm1_POS	 (1U)
#define SAU_SOm_CKOm0_POS	 (0U)
#define SAU_SOm_SOm1_POS	 (1U)
#define SAU_SOm_SOm0_POS	 (0U)
#define SAU_SOm_CKOm1_CLOCK_HIGH (1U << SAU_SOm_CKOm1_POS)
#define SAU_SOm_CKOm0_CLOCK_HIGH (1U << SAU_SOm_CKOm0_POS)
#define SAU_SOm_SOm1_OUTPUT_HIGH (1U << SAU_SOm_SOm1_POS)
#define SAU_SOm_SOm0_OUTPUT_HIGH (1U << SAU_SOm_SOm0_POS)

#define SAU_SOLm_SOLm1_POS		 (1U)
#define SAU_SOLm_SOLm0_POS		 (0U)
#define SAU_SOLm_SOLm1_DATA_INVERTED	 (1U << SAU_SOLm_SOLm1_POS)
#define SAU_SOLm_SOLm1_DATA_NON_INVERTED (0U << SAU_SOLm_SOLm1_POS)
#define SAU_SOLm_SOLm0_DATA_INVERTED	 (1U << SAU_SOLm_SOLm0_POS)
#define SAU_SOLm_SOLm0_DATA_NON_INVERTED (0U << SAU_SOLm_SOLm0_POS)

#define SAU_SSEm_SSEm1_POS	       (1U)
#define SAU_SSEm_SSEm0_POS	       (0U)
#define SAU_SSEm_SSEm1_SS_ENABLED(reg) (0U != (reg & (1U << SAU_SSEm_SSEm1_POS)))
#define SAU_SSEm_SSEm0_SS_ENABLED(reg) (0U != (reg & (1U << SAU_SSEm_SSEm0_POS)))

#define SAU_ISC_ISC0_POS   (0U)
#define SAU_ISC_ISC0_RXD0  (1U << SAU_ISC_ISC0_POS)
#define SAU_ISC_ISC0_INTP0 (0U << SAU_ISC_ISC0_POS)

#define SAU_NFEN0_SNFEN10_POS (2U)
#define SAU_NFEN0_SNFEN00_POS (0U)
#define SAU_NFEN0_SNFEN10_ON  (1U << SAU_NFEN0_SNFEN10_POS)
#define SAU_NFEN0_SNFEN00_ON  (1U << SAU_NFEN0_SNFEN00_POS)

/* Typedefs */

/* Objects */

/* Function prototypes */

/* Function definitions */
void Spi_Ll_Init(Spi_HWUnitType HwUnit, Spi_HWConfigType* HwConfig) {
	switch (HwUnit) {
	case (0): {
		PER0 |= SAU_PER0_SAU0EN;

		SPS0 = (HwConfig->clk_presc << SAU_SPSmn_PRS000_POS) & SAU_SPSmn_PRS000_POS;

		/* Stop channel 0 */
		ST0 = SAU_STm_STm0_STOP;
		/* Mask channel 0 interrupt */
		CSIMK00 = 1U; /* disable INTCSI00 interrupt */
		CSIIF00 = 0U; /* clear INTCSI00 interrupt flag */
		/* Set INTCSI00 low priority */
		CSIPR100 = 1U;
		CSIPR000 = 1U;

		// clear errors
		SIR00 = SAU_SIRmn_CLEAR_FECT | SAU_SIRmn_CLEAR_PEC | SAU_SIRmn_CLEAR_OVC;
		SMR00 = SAU_SMRmn_ALWAYS | SAU_SMRmn_CKS_CK0 | (uint16)(HwConfig->mode << SAU_SMRmn_CCS_POS) | SAU_SMRmn_STS_SW | SAU_SMRmn_SIS_NON_INVERT | SAU_SMRmn_MD12_CSI | SAU_SMRmn_MD0_IRQ_TXEND;
		SCR00 = SAU_SCRmn_TRXE_ENABLE | (uint16)(HwConfig->clkPhase << SAU_SCRmn_DAP_POS) | (uint16)(HwConfig->clkPolarity << SAU_SCRmn_CKP_POS) | (uint16)(HwConfig->dataOrder << SAU_SCRmn_DIR_POS) | SAU_SCRmn_SLC_CSI_NO_STOP | SAU_SCRmn_DLS_8BIT;
		SDR00 = HwConfig->baudrate;
		SO0   = (uint16)(!HwConfig->clkPolarity << SAU_SOm_CKOm0_POS); /* CSI00 clock initial level */
		SOE0 |= SAU_SOEm_SOEm0_OUTPUT_EN;			      /* enable CSI00 output */

		// PIOR4 = 1;

		// CSIIF00 = 0U; /* clear INTCSI00 interrupt flag */
		// CSIMK00 = 0U; /* enable INTCSI00 interrupt */

		SS0 |= SAU_SSm_SSm0_START; /* enable CSI00 */

		for (uint8 i = 255; i != 0; i--) {
			if (SAU_SEm_SEm0_ENABLED(SE0)) {
				break;
			}
		}
		// SDR00L = 0x55;
	}
	case (1): {
		PER0 |= SAU_PER0_SAU0EN;

		SPS0 = HwConfig->clk_presc << SAU_SPSmn_PRS010_POS;

		/* Stop channel 0 */
		ST0 = SAU_STm_STm1_STOP;
		/* Mask channel 0 interrupt */
		CSIMK01 = 1U; /* disable INTCSI00 interrupt */
		CSIIF01 = 0U; /* clear INTCSI00 interrupt flag */
		/* Set INTCSI00 low priority */
		CSIPR101 = 1U;
		CSIPR001 = 1U;

		// clear errors
		SIR01 = SAU_SIRmn_CLEAR_FECT | SAU_SIRmn_CLEAR_PEC | SAU_SIRmn_CLEAR_OVC;
		SMR01 = SAU_SMRmn_ALWAYS | SAU_SMRmn_CKS_CK0 | (uint16)(HwConfig->mode << SAU_SMRmn_CCS_POS) | SAU_SMRmn_STS_SW | SAU_SMRmn_SIS_NON_INVERT | SAU_SMRmn_MD12_CSI | SAU_SMRmn_MD0_IRQ_TXEND;
		SCR01 = SAU_SCRmn_TRXE_ENABLE | (uint16)(HwConfig->clkPhase << SAU_SCRmn_DAP_POS) | (uint16)(HwConfig->clkPolarity << SAU_SCRmn_CKP_POS) | SAU_SCRmn_DIR_MSB_FIRST | SAU_SCRmn_SLC_CSI_NO_STOP | SAU_SCRmn_DLS_8BIT;
		SDR01 = HwConfig->baudrate;
		SO0   = SAU_SOm_CKOm1_CLOCK_HIGH | SAU_SOm_SOm1_OUTPUT_HIGH; /* CSI00 clock initial level */
		SOE0 |= SAU_SOEm_SOEm1_OUTPUT_EN;			     /* enable CSI00 output */

		// CSIIF00 = 0U; /* clear INTCSI00 interrupt flag */
		// CSIMK00 = 0U; /* enable INTCSI00 interrupt */

		SS0 |= SAU_SSm_SSm0_START; /* enable CSI00 */

		for (uint8 i = 255; i != 0; i--) {
			if (SAU_SEm_SEm0_ENABLED(SE0)) {
				break;
			}
		}
		// SDR00L = 0x55;
	}
	}
}
void Spi_Ll_EnableInt(Spi_HWUnitType HwUnit);
void Spi_Ll_StartTransmit(Spi_HWUnitType HwUnit, Spi_ChannelDescType buffer);
