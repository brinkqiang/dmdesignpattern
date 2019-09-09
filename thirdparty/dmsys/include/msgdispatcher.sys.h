
#ifndef __MSGDISPATCHER_SYS_H_INCLUDE__
#define __MSGDISPATCHER_SYS_H_INCLUDE__

#include <assert.h>
#include <stddef.h>

#include <google/protobuf/message.h>

#include "msgperformanceconfig.h"
#include "dmos.h"
#include "dmtypes.h"

template<class T>
int GetMSGID()
{
	static T msg;
	return msg.id();
}

template<class T>
int GetMSGID(T& msg)
{
	return msg.id();
}

template<typename T>
class TMsgDispatcherPB
{
public:
    typedef int (T::*MSG_FUNC)(::google::protobuf::Message& msg, int nLen, const void* pObject);
    enum{ FUN_SIZE_MAX = 20480 };

    static inline uint32_t GetTickCount32()
    {
#ifdef WIN32
        return ::GetTickCount();
#else
        struct timespec ts = {0};
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
#endif
    }

    class MsgGuard
    {
    public:
        MsgGuard(CMsgPerformanceConfig& oConfig, uint16_t wMsgID, ::google::protobuf::Message& msg, int nLen)
        : m_oConfig(oConfig), m_wMsgID(wMsgID), m_msg(msg), m_nLen(nLen), m_dwStart(0), m_poMsg(NULL)
        {
            m_poMsg = m_oConfig.GetMsgs().FindMsg(m_wMsgID);
            if (NULL != m_poMsg)
            {
                m_dwStart = GetTickCount32();
            }
        }
        ~MsgGuard()
        {
            if (NULL != m_poMsg)
            {
                uint32_t dwEnd = GetTickCount32();
                uint32_t dwUse = dwEnd - m_dwStart;

                ++m_poMsg->GetMsgCount();
                m_poMsg->GetTotalMsgSize() += m_nLen;
                m_poMsg->GetTotalConsumeTime() += dwUse;

                if (dwUse > m_poMsg->GetMaxConsumeTime())
                {
                    m_poMsg->GetMaxConsumeTime() = dwUse;
                }

                m_poMsg->GetAvgConsumeTime() = m_poMsg->GetTotalConsumeTime() / m_poMsg->GetMsgCount();
            }
        }
    private:
        CMsgPerformanceConfig& m_oConfig;
        uint16_t m_wMsgID;
        int m_nLen;
        uint32_t m_dwStart;
        CXMSG* m_poMsg;
		::google::protobuf::Message& m_msg;
    };

public:
    TMsgDispatcherPB()
    {
        m_nMsgCount = 0;
        memset(m_arFunctions, 0, sizeof(m_arFunctions));
        memset(m_arMsgSizes, 0, sizeof(m_arMsgSizes));
    }

    virtual ~TMsgDispatcherPB()
    {

    }

    void Register(uint16_t wMsgID, MSG_FUNC fnIn, int nLen)
    {
        MSG_FUNC pFunc = Find(wMsgID);
        if(NULL != pFunc)
        {
            assert(0 && "MsgID Repeat");
            return;
        }

        if (wMsgID >= FUN_SIZE_MAX)
        {
            assert(0 && "MsgID >= FUN_SIZE_MAX");
            return;
        }

        assert(nLen >= 0);
        assert(0 == m_arFunctions[wMsgID]);
        m_arFunctions[wMsgID] = fnIn;
        m_arMsgSizes[wMsgID] = nLen;
        ++m_nMsgCount;

        CXMSG oMsg;
        oMsg.GetMsgID() = wMsgID;

        m_oMsgPerformance.GetMsgs().GetMsg().push_back(oMsg);

        m_oMsgPerformance.GetMsgs().Init(m_oMsgPerformance);
    }

    static inline int GetErrorDefault(){ return -1;}
    static inline int GetErrorNG(){ return -1;}

    MSG_FUNC Find(uint16_t wMsgID)
    {
        if(wMsgID >= FUN_SIZE_MAX) return NULL;
        return m_arFunctions[wMsgID];
    }

    int Call(uint16_t wMsgID, ::google::protobuf::Message& msg, int nLen, const void* pObject = NULL)
    {
        MSG_FUNC pFunc = Find(wMsgID);
        if(NULL == pFunc)
        {
            return GetErrorNG();
        }
        return (static_cast<T*>(this)->*pFunc)(msg, nLen, pObject);
    }

    int MGCall(uint16_t wMsgID, ::google::protobuf::Message& msg, int nLen, const void* pObject = NULL)
    {
        MsgGuard oGuard(m_oMsgPerformance, wMsgID, msg, nLen);
        return Call(wMsgID, msg, nLen, pObject);
    }

    int GetMsgSize(uint16_t wMsgID)
    {
        if(wMsgID >= FUN_SIZE_MAX) return -1;
        return m_arMsgSizes[wMsgID];
    }

    int GetMsgCount(){ return m_nMsgCount;}

private:
    MSG_FUNC m_arFunctions[FUN_SIZE_MAX];
    int  m_arMsgSizes[FUN_SIZE_MAX];
    int  m_nMsgCount;

    CMsgPerformanceConfig m_oMsgPerformance;
};

#endif // __MSGDISPATCHER_SYS_H_INCLUDE__
