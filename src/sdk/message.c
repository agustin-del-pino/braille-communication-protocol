#include "./bcpsdk.h"

int encodeCommandConnection(const CommandConnection *cmd, MessageBuffer out)
{
    out[0] = 5;
    out[1] = CMD_CON;
    out[2] = cmd->id;
    out[3] = cmd->version[0];
    out[4] = cmd->version[1];
    out[5] = cmd->version[2];
    return out[0];
}

int encodeCommandDisconnect(const CommandDisconnect *cmd, MessageBuffer out)
{
    out[0] = 2;
    out[1] = CMD_DIS;
    out[2] = cmd->id;
    return out[0];
}

int encodeCommandHardware(const CommandHardware *cmd, MessageBuffer out)
{
    out[0] = 2;
    out[1] = CMD_HWE;
    out[2] = cmd->cells;
    return out[0];
}

int encodeQuerySoftware(const QuerySoftware *qry, MessageBuffer out)
{
    out[0] = 1;
    out[1] = QRY_SWT;
    return out[0];
}

int (*encoders[])(const void *, MessageBuffer) = {
    [CMD_CON] = (int (*)(const void *, MessageBuffer))encodeCommandConnection,
    [CMD_DIS] = (int (*)(const void *, MessageBuffer))encodeCommandDisconnect,
    [CMD_HWE] = (int (*)(const void *, MessageBuffer))encodeCommandHardware,
    [QRY_SWT] = (int (*)(const void *, MessageBuffer))encodeQuerySoftware
};

int encode(const BCPMessage *msg, MessageBuffer out)
{
    return encoders[msg->type]((const void *)&msg->data, out);
}