#include "./bcpsdk.h"

const int LUT_BCP[] = {
    // index 0-32
    BCP_LWR_A,
    BCP_LWR_B,
    BCP_LWR_C,
    BCP_LWR_D,
    BCP_LWR_E,
    BCP_LWR_F,
    BCP_LWR_G,
    BCP_LWR_H,
    BCP_LWR_I,
    BCP_LWR_J,
    BCP_LWR_K,
    BCP_LWR_L,
    BCP_LWR_M,
    BCP_LWR_N,
    BCP_LWR_O,
    BCP_LWR_P,
    BCP_LWR_Q,
    BCP_LWR_R,
    BCP_LWR_S,
    BCP_LWR_T,
    BCP_LWR_U,
    BCP_LWR_V,
    BCP_LWR_W,
    BCP_LWR_X,
    BCP_LWR_Y,
    BCP_LWR_Z,
    BCP_LWR_TLD_A,
    BCP_LWR_TLD_E,
    BCP_LWR_TLD_I,
    BCP_LWR_TLD_O,
    BCP_LWR_TLD_U,
    BCP_LWR_UML_U,
    BCP_LWR_SPN_NG,

    // index 33-65
    BCP_UPP_A,
    BCP_UPP_B,
    BCP_UPP_C,
    BCP_UPP_D,
    BCP_UPP_E,
    BCP_UPP_F,
    BCP_UPP_G,
    BCP_UPP_H,
    BCP_UPP_I,
    BCP_UPP_J,
    BCP_UPP_K,
    BCP_UPP_L,
    BCP_UPP_M,
    BCP_UPP_N,
    BCP_UPP_O,
    BCP_UPP_P,
    BCP_UPP_Q,
    BCP_UPP_R,
    BCP_UPP_S,
    BCP_UPP_T,
    BCP_UPP_U,
    BCP_UPP_V,
    BCP_UPP_W,
    BCP_UPP_X,
    BCP_UPP_Y,
    BCP_UPP_Z,
    BCP_UPP_TLD_A,
    BCP_UPP_TLD_E,
    BCP_UPP_TLD_I,
    BCP_UPP_TLD_O,
    BCP_UPP_TLD_U,
    BCP_UPP_UML_U,
    BCP_UPP_SPN_NG,

    // index 66-75
    BCP_NUM_0,
    BCP_NUM_1,
    BCP_NUM_2,
    BCP_NUM_3,
    BCP_NUM_4,
    BCP_NUM_5,
    BCP_NUM_6,
    BCP_NUM_7,
    BCP_NUM_8,
    BCP_NUM_9,

    // index 76-86
    BCP_SGN_AMP,
    BCP_SGN_DOT,
    BCP_SGN_CMM,
    BCP_SGN_SCL,
    BCP_SGN_QST,
    BCP_SGN_EXC,
    BCP_SGN_QTE,
    BCP_SGN_PAO,
    BCP_SGN_PAC,
    BCP_SGN_SCR,
    BCP_SGN_AST,

    // index 87-88
    BCP_PRX_NUM,
    BCP_PRX_UPP,

    BCP_SGN_SPC
};


int toBraille(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return LUT_BCP[ch - 'a'];
    }

    if (ch >= 'A' && ch <= 'Z')
    {
        return LUT_BCP[(ch - 'A') + 33];
    }

    if (ch >= '0' && ch <= '9')
    {
        return LUT_BCP[(ch - '0') + 66];
    }

    switch (ch)
    {
    case '&':
        return LUT_BCP[76];
    case '.':
        return LUT_BCP[77];
    case ',':
        return LUT_BCP[78];
    case ';':
        return LUT_BCP[79];
    case '?':
        return LUT_BCP[80];
    case '!':
        return LUT_BCP[81];
    case '"':
        return LUT_BCP[82];
    case '(':
        return LUT_BCP[83];
    case ')':
        return LUT_BCP[84];
    case '_':
        return LUT_BCP[85];
    case '*':
        return LUT_BCP[86];
    }

    return LUT_BCP[89];
}