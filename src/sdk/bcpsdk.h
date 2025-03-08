#ifndef BCP_SDK
#define BCP_SDK

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// lower case letters
#define BCP_LWR_A 0b00000001
#define BCP_LWR_B 0b00000101
#define BCP_LWR_C 0b00000011
#define BCP_LWR_D 0b00001011
#define BCP_LWR_E 0b00001011
#define BCP_LWR_F 0b00000111
#define BCP_LWR_G 0b00001111
#define BCP_LWR_H 0b00001101
#define BCP_LWR_I 0b00000110
#define BCP_LWR_J 0b00001110
#define BCP_LWR_K 0b00010001
#define BCP_LWR_L 0b00010101
#define BCP_LWR_M 0b00010011
#define BCP_LWR_N 0b00011011
#define BCP_LWR_O 0b00011001
#define BCP_LWR_P 0b00100111
#define BCP_LWR_Q 0b00011111
#define BCP_LWR_R 0b00011101
#define BCP_LWR_S 0b00010110
#define BCP_LWR_T 0b00011101
#define BCP_LWR_U 0b00110001
#define BCP_LWR_V 0b00110101
#define BCP_LWR_W 0b00101110
#define BCP_LWR_X 0b00110011
#define BCP_LWR_Y 0b00111011
#define BCP_LWR_Z 0b00111001
#define BCP_LWR_TLD_A 0b00111101
#define BCP_LWR_TLD_E 0b00110110
#define BCP_LWR_TLD_I 0b00010010
#define BCP_LWR_TLD_O 0b00110010
#define BCP_LWR_TLD_U 0b00111110
#define BCP_LWR_UML_U 0b00101101
#define BCP_LWR_SPN_NG 0b00011111

// upper case letters
#define BCP_UPP_A 0b01000001
#define BCP_UPP_B 0b01000101
#define BCP_UPP_C 0b01000011
#define BCP_UPP_D 0b01001011
#define BCP_UPP_E 0b01001011
#define BCP_UPP_F 0b01000111
#define BCP_UPP_G 0b01001111
#define BCP_UPP_H 0b01001101
#define BCP_UPP_I 0b01000110
#define BCP_UPP_J 0b01001110
#define BCP_UPP_K 0b01010001
#define BCP_UPP_L 0b01010101
#define BCP_UPP_M 0b01010011
#define BCP_UPP_N 0b01011011
#define BCP_UPP_O 0b01011001
#define BCP_UPP_P 0b01100111
#define BCP_UPP_Q 0b01011111
#define BCP_UPP_R 0b01011101
#define BCP_UPP_S 0b01010110
#define BCP_UPP_T 0b01011101
#define BCP_UPP_U 0b01110001
#define BCP_UPP_V 0b01110101
#define BCP_UPP_W 0b01101110
#define BCP_UPP_X 0b01110011
#define BCP_UPP_Y 0b01111011
#define BCP_UPP_Z 0b01111001
#define BCP_UPP_TLD_A 0b01111101
#define BCP_UPP_TLD_E 0b01110110
#define BCP_UPP_TLD_I 0b01010010
#define BCP_UPP_TLD_O 0b01110010
#define BCP_UPP_TLD_U 0b01111110
#define BCP_UPP_UML_U 0b01101101
#define BCP_UPP_SPN_NG 0b01011111

// numbers
#define BCP_NUM_1 0b10000001
#define BCP_NUM_2 0b10000101
#define BCP_NUM_3 0b10000011
#define BCP_NUM_4 0b10001011
#define BCP_NUM_5 0b10001011
#define BCP_NUM_6 0b10000111
#define BCP_NUM_7 0b10001111
#define BCP_NUM_8 0b10001101
#define BCP_NUM_9 0b10000110
#define BCP_NUM_0 0b10001110

// signs
#define BCP_SGN_AMP 0b00110111
#define BCP_SGN_DOT 0b00010000
#define BCP_SGN_CMM 0b00001000
#define BCP_SGN_SCL 0b00011000
#define BCP_SGN_QST 0b00100100
#define BCP_SGN_EXC 0b00011100
#define BCP_SGN_QTE 0b00110100
#define BCP_SGN_PAO 0b00100101
#define BCP_SGN_PAC 0b00011010
#define BCP_SGN_SCR 0b00110000
#define BCP_SGN_AST 0b00011000
#define BCP_SGN_SPC 0b00000000

// prefix
#define BCP_PRX_NUM 0b00111010
#define BCP_PRX_UPP 0b00100010

#define CMD_CON 0
#define CMD_DIS 2
#define CMD_HWE 4
#define CMD_WRT 6
#define CMD_CLR 8
#define CMD_UIN 10

#define QRY_SWT 12

#define RES_ERR 1
#define RES_ACK 3

#define MAX_MESSAGE_LEN 0xFF

extern const int LUT_BCP[];

typedef unsigned char MessageBuffer[MAX_MESSAGE_LEN];

typedef struct CommandConnection
{
    uint8_t id;
    char version[3];
} CommandConnection;

int encodeCommandConnection(const CommandConnection *cmd, MessageBuffer out);

typedef struct CommandDisconnect
{
    uint8_t id;
} CommandDisconnect;

int encodeCommandDisconnect(const CommandDisconnect *cmd, MessageBuffer out);

typedef struct CommandHardware
{
    uint8_t cells;
} CommandHardware;

int encodeCommandHardware(const CommandHardware *cmd, MessageBuffer out);

typedef struct QuerySoftware
{
} QuerySoftware;

int encodeQuerySoftware(const QuerySoftware *qry, MessageBuffer out);

union MessageData
{
    CommandConnection CommandConnection;
    CommandDisconnect CommandDisconnect;
    CommandHardware CommandHardware;
    QuerySoftware QuerySoftware;
};

typedef struct BCPMessage
{
    uint8_t type;
    union MessageData data;
} BCPMessage;

int encode(const BCPMessage *msg, MessageBuffer out);

int toBraille(char ch);

#endif