#include "msgperformance.h"

NSMSGPERFORMANCE_BEGIN

CMsgPerformance::CMsgPerformance()
{
    Init();
}

CMsgPerformance::~CMsgPerformance()
{
}

int CMsgPerformance::Encode(int nMsgID, void *pHost, char *pNet, int nNetSize)
{
    m_oData.Prepare(pNet, nNetSize);

    EnFuncCMsgPerformance pfnEncode = FindEncodeFunc(nMsgID);
    if(NULL == pfnEncode)
        return -1;

    return (this->*pfnEncode)(pHost);
}

int CMsgPerformance::Decode(int nMsgID, char *pNet,int nNetSize, void *pHost)
{
    m_oData.Prepare(pNet, nNetSize);

    DeFuncCMsgPerformance pfnDecode = FindDecodeFunc(nMsgID);
    if(NULL == pfnDecode)
        return -1;

    return (this->*pfnDecode)(pHost);
}

EnFuncCMsgPerformance CMsgPerformance::FindEncodeFunc(int nMsgID)
{
    if(nMsgID < 0 || nMsgID >= 65535)
        return NULL;
    return m_EncodeFuncArray[nMsgID];
}

DeFuncCMsgPerformance CMsgPerformance::FindDecodeFunc(int nMsgID)
{
    if(nMsgID < 0 || nMsgID >= 65535)
        return NULL;
    return m_DecodeFuncArray[nMsgID];
}

int CMsgPerformance::EncodeXMSG(void *pHost)
{
    XMSG *pstIn = (XMSG*)pHost;

    if(-1 == m_oData.AddUint64(pstIn->qwMsgID))
        return -1;

    if(-1 == m_oData.AddString(pstIn->szLastTime, sizeof(pstIn->szLastTime)))
        return -1;

    if(-1 == m_oData.AddUint64(pstIn->qwMaxConsumeTime))
        return -1;

    if(-1 == m_oData.AddUint64(pstIn->qwAvgConsumeTime))
        return -1;

    if(-1 == m_oData.AddUint64(pstIn->qwTotalConsumeTime))
        return -1;

    if(-1 == m_oData.AddUint64(pstIn->qwMsgCount))
        return -1;

    if(-1 == m_oData.AddUint64(pstIn->qwTotalMsgSize))
        return -1;

    return m_oData.GetDataLen();
}

int CMsgPerformance::DecodeXMSG(void *pHost)
{
    XMSG *pstOut = (XMSG*)pHost;

    if(-1 == m_oData.DelUint64(pstOut->qwMsgID))
        return -1;

    if(-1 == m_oData.DelString(pstOut->szLastTime, sizeof(pstOut->szLastTime)))
        return -1;

    if(-1 == m_oData.DelUint64(pstOut->qwMaxConsumeTime))
        return -1;

    if(-1 == m_oData.DelUint64(pstOut->qwAvgConsumeTime))
        return -1;

    if(-1 == m_oData.DelUint64(pstOut->qwTotalConsumeTime))
        return -1;

    if(-1 == m_oData.DelUint64(pstOut->qwMsgCount))
        return -1;

    if(-1 == m_oData.DelUint64(pstOut->qwTotalMsgSize))
        return -1;

    return sizeof(*pstOut);
}

int CMsgPerformance::EncodeXMSGS(void *pHost)
{
    XMSGS *pstIn = (XMSGS*)pHost;

    for(int i = 0; i < MAX_MSG_COUNT; i++)
    {
        if(-1 == EncodeXMSG(&pstIn->astMsg[i]))
            return -1;
    }

    return m_oData.GetDataLen();
}

int CMsgPerformance::DecodeXMSGS(void *pHost)
{
    XMSGS *pstOut = (XMSGS*)pHost;

    for(int i = 0; i < MAX_MSG_COUNT; i++)
    {
        if(-1 == DecodeXMSG(&pstOut->astMsg[i]))
            return -1;
    }

    return sizeof(*pstOut);
}

bool CMsgPerformance::Init()
{
    memset(m_EncodeFuncArray, 0, sizeof(m_EncodeFuncArray));
    memset(m_DecodeFuncArray, 0, sizeof(m_DecodeFuncArray));

    return true;
}

NSMSGPERFORMANCE_END
