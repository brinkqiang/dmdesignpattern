#include "msgperformanceconfig.h"
#include "dmpolicy.h"

NSMSGPERFORMANCE_BEGIN

CMsgPerformanceConfig::CMsgPerformanceConfig()
{
    Init();
}

CMsgPerformanceConfig::~CMsgPerformanceConfig()
{

    m_mapFuncCMsgPerformanceConfig.clear();
}

bool CMsgPerformanceConfig::Init()
{
    m_mapFuncCMsgPerformanceConfig["Msgs"] = &CMsgPerformanceConfig::GetCXMSGS;
    return true;
}

bool CMsgPerformanceConfig::LoadXML(const string& strPath)
{
    stringstream ssp;

    ssp << strPath;
    ssp << CONFIG_PATH_DELIMITER;
    ssp << "msgperformanceconfig.xml";

    ifstream fs;
    stringstream ssf;
    LOCAL_GUARD(fs.open(ssp.str().c_str()));
    if(fs.fail())
    {
        if(CONFIG_FILE_NOTEXIST) return true;
        LastErrorDataEx() << "file: msgperformanceconfig.xml can't load. please check file path & file attribute.\n";
        goto FAIL;
    }

    ssf << fs.rdbuf();

    if(!SetXMLDoc(ssf.str()))
    {
        LastErrorDataEx() << "file: msgperformanceconfig.xml can't parser. please check file info.\n";
        goto FAIL;
    }

    return true;
FAIL:
    OnError(GetLastErrorDataEx());
    return false;
}

bool CMsgPerformanceConfig::SaveXML(const string& strPath)
{
    stringstream ssp;

    ssp << strPath;
    ssp << CONFIG_PATH_DELIMITER;
    ssp << "msgperformanceconfig.xml";

    ofstream fs;
    LOCAL_GUARD(fs.open(ssp.str().c_str()));
    if(fs.fail())
    {
        LastErrorDataEx() << "file: msgperformanceconfig.xml can't load. please check file path & file attribute.\n";
        goto FAIL;
    }

    GetXMLDoc(fs);
    return true;
FAIL:
    OnError(GetLastErrorDataEx());
    return false;
}

bool CMsgPerformanceConfig::SetXMLDoc(const string& strDoc)
{
    xml_document doc;
    if(!doc.load_buffer(strDoc.c_str(), strDoc.size()))
    {
        return false;
    }

    xml_node coder = doc.child("coder");
    if(!coder)
    {
        return false;
    }

    xml_node datas = coder.child("datas");
    if(!datas)
    {
        return false;
    }

    xml_node Msgs = datas.child("Msgs");
    if(Msgs)
    {
        if(-1 == ReadData(&m_oMsgs, "Msgs", Msgs))
        {
            return false;
        }

        if(!m_oMsgs.Init(*this))
        {
            return false;
        }
    }

    return true;
}

ostream& CMsgPerformanceConfig::GetXMLDoc(ostream& os)
{
    xml_document doc;
    xml_node coder = doc.append_child("coder");
    xml_attribute name = coder.append_attribute("name");
    name.set_value("MsgPerformance");
    xml_attribute version = coder.append_attribute("version");
    version.set_value("1_0");
    xml_node datas = coder.append_child("datas");
    xml_node Msgs = datas.append_child("Msgs");
    FormatCXMSGS(&m_oMsgs, Msgs);
    doc.save(os, DM_INDENT , DM_FLAG, DM_ENCODING);
    return os;
}

bool CMsgPerformanceConfig::LoadCSV(const string& strPath)
{
    if(!LoadCSV_Msgs(strPath))
    {
        goto FAIL;
    }

    return true;
FAIL:
    OnError(GetLastErrorDataEx());
    return false;
}

bool CMsgPerformanceConfig::SaveCSV(const string& strPath)
{
    if(!SaveCSV_Msgs(strPath))
    {
        goto FAIL;
    }

    return true;
FAIL:
    OnError(GetLastErrorDataEx());
    return false;
}

template<>
void CMsgPerformanceConfig::ReadCSV_XMSG(CXMSG& oXMSG, csv::CSVRow& row)
{
    oXMSG.GetMsgID() = row["MsgID"].get<unsigned long long>();
    oXMSG.GetLastTime() = row["LastTime"].get<string>();
    oXMSG.GetMaxConsumeTime() = row["MaxConsumeTime"].get<unsigned long long>();
    oXMSG.GetAvgConsumeTime() = row["AvgConsumeTime"].get<unsigned long long>();
    oXMSG.GetTotalConsumeTime() = row["TotalConsumeTime"].get<unsigned long long>();
    oXMSG.GetMsgCount() = row["MsgCount"].get<unsigned long long>();
    oXMSG.GetTotalMsgSize() = row["TotalMsgSize"].get<unsigned long long>();
}

void CMsgPerformanceConfig::WriteCSV_XMSG(ostream& os,CXMSG& oXMSG)
{
    os << oXMSG.GetMsgID();
    os << ",";
    os << oXMSG.GetLastTime();
    os << ",";
    os << oXMSG.GetMaxConsumeTime();
    os << ",";
    os << oXMSG.GetAvgConsumeTime();
    os << ",";
    os << oXMSG.GetTotalConsumeTime();
    os << ",";
    os << oXMSG.GetMsgCount();
    os << ",";
    os << oXMSG.GetTotalMsgSize();
}

bool CMsgPerformanceConfig::LoadCSV_Msgs(const string& strPath)
{
    stringstream ssp;

    ssp << strPath;
    ssp << CONFIG_PATH_DELIMITER;
    ssp << "msgperformanceconfig.msgs.csv";

    try
    {
        csv::CSVReader reader(ssp.str().c_str());
        csv::CSVRow row;
        for(size_t i = 0; reader.read_row(row); i++)
        {
            int j = 0;

            CXMSG oXMSG;
            ReadCSV_XMSG(oXMSG, row);

            m_oMsgs.GetMsg().push_back(oXMSG);
        }
    }
    catch (std::exception& e)
    {
        LastErrorDataEx() << e.what() << "\n";
        return false;
    }

    return m_oMsgs.Init(*this);
}

bool CMsgPerformanceConfig::SaveCSV_Msgs(const string& strPath)
{
    stringstream ssp;

    ssp << strPath;
    ssp << CONFIG_PATH_DELIMITER;
    ssp << "msgperformanceconfig.msgs.csv";

    ofstream fs;
    LOCAL_GUARD(fs.open(ssp.str().c_str()));
    if(fs.fail())
    {
        LastErrorDataEx() << "file: msgperformanceconfig.msgs.csv can't load. please check file path & file attribute.\n";
        goto FAIL;
    }

    GetCSVDoc_Msgs(fs);
    return true;
FAIL:
    OnError(GetLastErrorDataEx());
    return false;
}

ostream& CMsgPerformanceConfig::GetCSVDoc_Msgs(ostream& os)
{
    os << "MsgID";
    os << ",";
    os << "LastTime";
    os << ",";
    os << "MaxConsumeTime";
    os << ",";
    os << "AvgConsumeTime";
    os << ",";
    os << "TotalConsumeTime";
    os << ",";
    os << "MsgCount";
    os << ",";
    os << "TotalMsgSize";
    os << endl;

    for(int i = 0; i < static_cast<int>(m_oMsgs.GetMsg().size()); ++i)
    {
        CXMSG& oXMSG = m_oMsgs.GetMsg()[i];
        WriteCSV_XMSG(os, oXMSG);
        os << endl;
    }

    return os;
}

int CMsgPerformanceConfig::ReadData(void* pHost, const string& strDataName, xml_node& oXml)
{
    MapFuncCMsgPerformanceConfigIt it = m_mapFuncCMsgPerformanceConfig.find(strDataName);
    if(it != m_mapFuncCMsgPerformanceConfig.end() && NULL != it->second)
    {
        return (this->*(it->second))(pHost, strDataName, oXml);
    }
    return -1;
}

int CMsgPerformanceConfig::GetCXMSG(void *pHost, const string& strDataName, xml_node& oXml)
{
    CXMSG *pstOut = (CXMSG*)pHost;
    CXmlData oXmlData;
    oXmlData.Prepare((char*)pstOut, sizeof(XMSG));

    xml_node MsgID = oXml.child("MsgID");
    if(-1 == oXmlData.GetUint64(pstOut->GetMsgID(), "MsgID", MsgID))
        return -1;

    xml_node LastTime = oXml.child("LastTime");
    pstOut->GetLastTime().resize(MAX_MSG_STRING);
    if(-1 == oXmlData.GetString(pstOut->GetLastTime(), MAX_MSG_STRING, "LastTime", LastTime))
        return -1;
    pstOut->GetLastTime().resize(strlen(pstOut->GetLastTime().c_str()));

    xml_node MaxConsumeTime = oXml.child("MaxConsumeTime");
    if(-1 == oXmlData.GetUint64(pstOut->GetMaxConsumeTime(), "MaxConsumeTime", MaxConsumeTime))
        return -1;

    xml_node AvgConsumeTime = oXml.child("AvgConsumeTime");
    if(-1 == oXmlData.GetUint64(pstOut->GetAvgConsumeTime(), "AvgConsumeTime", AvgConsumeTime))
        return -1;

    xml_node TotalConsumeTime = oXml.child("TotalConsumeTime");
    if(-1 == oXmlData.GetUint64(pstOut->GetTotalConsumeTime(), "TotalConsumeTime", TotalConsumeTime))
        return -1;

    xml_node MsgCount = oXml.child("MsgCount");
    if(-1 == oXmlData.GetUint64(pstOut->GetMsgCount(), "MsgCount", MsgCount))
        return -1;

    xml_node TotalMsgSize = oXml.child("TotalMsgSize");
    if(-1 == oXmlData.GetUint64(pstOut->GetTotalMsgSize(), "TotalMsgSize", TotalMsgSize))
        return -1;

    return sizeof(*pstOut);
}

int CMsgPerformanceConfig::GetCXMSGS(void *pHost, const string& strDataName, xml_node& oXml)
{
    CXMSGS *pstOut = (CXMSGS*)pHost;
    CXmlData oXmlData;
    oXmlData.Prepare((char*)pstOut, sizeof(XMSGS));

    {
        xml_object_range<xml_named_node_iterator> Msg = oXml.children("Msg");
        pstOut->GetMsg().resize(Msg.count());
        xml_named_node_iterator It = Msg.begin();
        int i = 0;
        for(i = 0; It != Msg.end(); ++i, ++It)
        {
            int nRet = GetCXMSG(&pstOut->GetMsg()[i], "Msg", *It);
            if(-1 == nRet)
            {
                return -1;
            }
        }
        pstOut->GetMsg().resize(i);
    }

    return sizeof(*pstOut);
}


void CMsgPerformanceConfig::FormatCXMSG(CXMSG* pData, xml_node& oXml)
{
    xml_node MsgID = oXml.append_child("MsgID");
    MsgID.append_child(node_pcdata).set_value((*pData).GetMsgID());
    xml_node LastTime = oXml.append_child("LastTime");
    LastTime.append_child(node_pcdata).set_value((*pData).GetLastTime());
    xml_node MaxConsumeTime = oXml.append_child("MaxConsumeTime");
    MaxConsumeTime.append_child(node_pcdata).set_value((*pData).GetMaxConsumeTime());
    xml_node AvgConsumeTime = oXml.append_child("AvgConsumeTime");
    AvgConsumeTime.append_child(node_pcdata).set_value((*pData).GetAvgConsumeTime());
    xml_node TotalConsumeTime = oXml.append_child("TotalConsumeTime");
    TotalConsumeTime.append_child(node_pcdata).set_value((*pData).GetTotalConsumeTime());
    xml_node MsgCount = oXml.append_child("MsgCount");
    MsgCount.append_child(node_pcdata).set_value((*pData).GetMsgCount());
    xml_node TotalMsgSize = oXml.append_child("TotalMsgSize");
    TotalMsgSize.append_child(node_pcdata).set_value((*pData).GetTotalMsgSize());
}

void CMsgPerformanceConfig::FormatCXMSGS(CXMSGS* pData, xml_node& oXml)
{
    for(int i = 0; i < static_cast<int>((*pData).GetMsg().size()); i++)
    {
        xml_node Msg = oXml.append_child("Msg");
        FormatCXMSG(&(*pData).GetMsg()[i], Msg);
    }
}

NSMSGPERFORMANCE_END
