/*!
 * \file Dio_Types.h
 * \brief Type definitions for DIO module
 * \author awd110
 *
 */
#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_
/* Includes */
#include "Std_Types.h"

/* Macros */
// P0
#define DIO_CHANNEL_0 0
#define DIO_CHANNEL_1 1
#define DIO_CHANNEL_2 2
#define DIO_CHANNEL_3 3
#define DIO_CHANNEL_4 4
#define DIO_CHANNEL_5 5
#define DIO_CHANNEL_6 6
#define DIO_CHANNEL_7 7

// P1
#define DIO_CHANNEL_8  8
#define DIO_CHANNEL_9  9
#define DIO_CHANNEL_10 10
#define DIO_CHANNEL_11 11
#define DIO_CHANNEL_12 12
#define DIO_CHANNEL_13 13
#define DIO_CHANNEL_14 14
#define DIO_CHANNEL_15 15

// P2
#define DIO_CHANNEL_16 16
#define DIO_CHANNEL_17 17
#define DIO_CHANNEL_18 18
#define DIO_CHANNEL_19 19
#define DIO_CHANNEL_20 20
#define DIO_CHANNEL_21 21
#define DIO_CHANNEL_22 22
#define DIO_CHANNEL_23 23

// P3
#define DIO_CHANNEL_24 24
#define DIO_CHANNEL_25 25
#define DIO_CHANNEL_26 26
#define DIO_CHANNEL_27 27
#define DIO_CHANNEL_28 28
#define DIO_CHANNEL_29 29
#define DIO_CHANNEL_30 30
#define DIO_CHANNEL_31 31

// P4
#define DIO_CHANNEL_32 32
#define DIO_CHANNEL_33 33
#define DIO_CHANNEL_34 34
#define DIO_CHANNEL_35 35
#define DIO_CHANNEL_36 36
#define DIO_CHANNEL_37 37
#define DIO_CHANNEL_38 38
#define DIO_CHANNEL_39 39

// P5
#define DIO_CHANNEL_40 40
#define DIO_CHANNEL_41 41
#define DIO_CHANNEL_42 42
#define DIO_CHANNEL_43 43
#define DIO_CHANNEL_44 44
#define DIO_CHANNEL_45 45
#define DIO_CHANNEL_46 46
#define DIO_CHANNEL_47 47

// P6
#define DIO_CHANNEL_48 48
#define DIO_CHANNEL_49 49
#define DIO_CHANNEL_50 50
#define DIO_CHANNEL_51 51
#define DIO_CHANNEL_52 52
#define DIO_CHANNEL_53 53
#define DIO_CHANNEL_54 54
#define DIO_CHANNEL_55 55

// P7
#define DIO_CHANNEL_56 56
#define DIO_CHANNEL_57 57
#define DIO_CHANNEL_58 58
#define DIO_CHANNEL_59 59
#define DIO_CHANNEL_60 60
#define DIO_CHANNEL_61 61
#define DIO_CHANNEL_62 62
#define DIO_CHANNEL_63 63

// P8
#define DIO_CHANNEL_64 64
#define DIO_CHANNEL_65 65
#define DIO_CHANNEL_66 66
#define DIO_CHANNEL_67 67
#define DIO_CHANNEL_68 68
#define DIO_CHANNEL_69 69
#define DIO_CHANNEL_70 70
#define DIO_CHANNEL_71 71

// P9
#define DIO_CHANNEL_72 72
#define DIO_CHANNEL_73 73
#define DIO_CHANNEL_74 74
#define DIO_CHANNEL_75 75
#define DIO_CHANNEL_76 76
#define DIO_CHANNEL_77 77
#define DIO_CHANNEL_78 78
#define DIO_CHANNEL_79 79

// P10
#define DIO_CHANNEL_80 80
#define DIO_CHANNEL_81 81
#define DIO_CHANNEL_82 82
#define DIO_CHANNEL_83 83
#define DIO_CHANNEL_84 84
#define DIO_CHANNEL_85 85
#define DIO_CHANNEL_86 86
#define DIO_CHANNEL_87 87

// P11
#define DIO_CHANNEL_88 88
#define DIO_CHANNEL_89 89
#define DIO_CHANNEL_90 90
#define DIO_CHANNEL_91 91
#define DIO_CHANNEL_92 92
#define DIO_CHANNEL_93 93
#define DIO_CHANNEL_94 94
#define DIO_CHANNEL_95 95

// P12
#define DIO_CHANNEL_96	96
#define DIO_CHANNEL_97	97
#define DIO_CHANNEL_98	98
#define DIO_CHANNEL_99	99
#define DIO_CHANNEL_100 100
#define DIO_CHANNEL_101 101
#define DIO_CHANNEL_102 102
#define DIO_CHANNEL_103 103

// P13
#define DIO_CHANNEL_104 104
#define DIO_CHANNEL_105 105
#define DIO_CHANNEL_106 106
#define DIO_CHANNEL_107 107
#define DIO_CHANNEL_108 108
#define DIO_CHANNEL_109 109
#define DIO_CHANNEL_110 110
#define DIO_CHANNEL_111 111

// P14
#define DIO_CHANNEL_112 112
#define DIO_CHANNEL_113 113
#define DIO_CHANNEL_114 114
#define DIO_CHANNEL_115 115
#define DIO_CHANNEL_116 116
#define DIO_CHANNEL_117 117
#define DIO_CHANNEL_118 118
#define DIO_CHANNEL_119 119

// P15
#define DIO_CHANNEL_120 120
#define DIO_CHANNEL_121 121
#define DIO_CHANNEL_122 122
#define DIO_CHANNEL_123 123
#define DIO_CHANNEL_124 124
#define DIO_CHANNEL_125 125
#define DIO_CHANNEL_126 126
#define DIO_CHANNEL_127 127

#define DIO_CHANNEL_MAX 128

#define DIO_PORT_P0  0
#define DIO_PORT_P1  1
#define DIO_PORT_P2  2
#define DIO_PORT_P3  3
#define DIO_PORT_P4  4
#define DIO_PORT_P5  5
#define DIO_PORT_P6  6
#define DIO_PORT_P7  7
#define DIO_PORT_P8  8
#define DIO_PORT_P9  9
#define DIO_PORT_P10 10
#define DIO_PORT_P11 11
#define DIO_PORT_P12 12
#define DIO_PORT_P13 13
#define DIO_PORT_P14 14
#define DIO_PORT_P15 15

#define DIO_PORT_MAX 16
/* Exported Type definitions */
/*!
 * Numeric ID of a DIO channel.
 */
typedef uint8 Dio_ChannelType;

/*!
 * Numeric ID of a DIO port.
 */
typedef uint8 Dio_PortType;

/*!
 * Type for the definition of a channel group, which consists of several adjoining
 * channels within a port.
 */
typedef struct {
	uint8	     mask;   /* This element mask which defines the positions of the channel group. */
	uint8	     offset; /* This element shall be the position of the Channel Group on the port, counted from the LSB. */
	Dio_PortType port;   /* This shall be the port on which the Channel group is defined. */
} Dio_ChannelGroupType;

/*!
 * These are the possible levels a DIO channel can have (input or output)
 */
typedef uint8 Dio_LevelType;

/*!
 * Type for the value of a DIO port.
 */
typedef uint8 Dio_PortLevelType;

/* Exported Objects */

/* Exported function prototypes */

#endif /* DIO_TYPES_H_ */
