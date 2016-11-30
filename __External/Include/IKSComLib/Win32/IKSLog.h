//===================================================================================================
// Summary:
//		日志文件
// Date:
//		2015-08-19
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSLOG_H_INCLUDE__
#define __IKSLOG_H_INCLUDE__

//===================================================================================================

#include <string>
#include <fstream>
#include <time.h>
using namespace std;

class CIKSLog
{
public:
	enum EnumLogType
	{
		LOG_TYPE_INFORMATION = 0,
		LOG_TYPE_WARNING = 1,
		LOG_TYPE_ERROR = 2
	};

public:
	static CString GetTypeString(int type)
	{
		CString x = _T("Unknown");
		switch(type)
		{
		case LOG_TYPE_INFORMATION: 
			x = _T("Inf");
			break;
		case LOG_TYPE_WARNING: 
			x = _T("War");
			break;
		case LOG_TYPE_ERROR: 
			x = _T("Err");
			break;
		}

		return x;
	}

public:
	CIKSLog();
	virtual ~CIKSLog();

	void Init(const CString &strLogFileName);
	void UnInit();

	CString GetLogFileName() const { return m_strLogFileName; }
protected:
	void SetLogFileName(CString strLogFileName) { m_strLogFileName = strLogFileName; }
	bool CheckEnvironment();

public:
	bool Log(int nType, LPCTSTR strContent);

protected:
	CString m_strUser;				// user name. 
	CString m_strComputer;			// computer name. 
	CString m_strApplication;		// the application's name.  
	static CString m_strLogFileName;// log file name. 
	static BOOL m_bLogFileOpen;		// log文件是否打开
	static CStdioFile m_ofs;
};

//===================================================================================================

#endif // __IKSLOG_H_INCLUDE__
