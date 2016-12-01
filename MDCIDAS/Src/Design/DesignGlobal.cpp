//===================================================================================================
// Summary:
//		��������ģ��ʹ�õĹ��ú���
// Date:
//		2016-12-01
// Author:
//		lgq
//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DesignGlobal.h"

//===================================================================================================

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//===================================================================================================

// ����ģ�����_��
CString g_strITParaWidthName = _T("Width");
// ����ģ�����_��
CString g_strITParaDepthName = _T("Depth");
// ����ģ�����_��
CString g_strITParaHeightName = _T("Height");
// ����������װ������
CString g_strFWQJGCompCsysName = _T("CS_��װ");

// ����ģ���������
CString g_strFWQJGTemplateAsmName = _T("JIGUI_TEMPLATE");

//===================================================================================================


// ���ݲ���ͼ�������ͻ�ȡ������������
int GetDesignModelType(int nSymbolSubtype)
{
	switch (nSymbolSubtype)
	{
	case SCT_ITC:
		return DMT_ITC;
	default:
		break;
	}
	return -1;
}

// ��ʼ��ȫ�ֱ���
bool InitDesignGlobalData()
{
	CString strConfigFile;
	GetMainModulePath(strConfigFile, theApp.m_hInstance);
	if (strConfigFile[strConfigFile.GetLength()-1] != L'\\')
		strConfigFile += L"\\";
	strConfigFile += L"DesignConfig.ini";
	if (!IsFileExist(strConfigFile))
		return false;

	TCHAR lpValue[MAX_PATH] = {0};
	// ��������
	CString strParaConfig = L"����������";
	if (GetPrivateProfileString(strParaConfig, L"WidthParaName", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strITParaWidthName = lpValue;
	if (GetPrivateProfileString(strParaConfig, L"DepthParaName", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strITParaDepthName = lpValue;
	if (GetPrivateProfileString(strParaConfig, L"HeightParaName", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strITParaHeightName = lpValue;

	// װ������ϵ
	CString strCompCsysConfig = L"װ������ϵ";
	if (GetPrivateProfileString(strCompCsysConfig, L"����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strFWQJGCompCsysName = lpValue;

	// ģ���ļ�
	CString strTemplateNameConfig = L"ģ���ļ�";
	if (GetPrivateProfileString(strTemplateNameConfig, L"����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strFWQJGTemplateAsmName = lpValue;

	return true;
}

//===================================================================================================