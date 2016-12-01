//===================================================================================================
// Summary:
//		整机配置模块使用的公用函数
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

// 机柜模板参数_宽
CString g_strITParaWidthName = _T("Width");
// 机柜模板参数_深
CString g_strITParaDepthName = _T("Depth");
// 机柜模板参数_高
CString g_strITParaHeightName = _T("Height");
// 服务器机柜装配坐标
CString g_strFWQJGCompCsysName = _T("CS_安装");

// 机柜模板组件名称
CString g_strFWQJGTemplateAsmName = _T("JIGUI_TEMPLATE");

//===================================================================================================


// 根据布局图符号类型获取设计用组件类型
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

// 初始化全局变量
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
	// 驱动参数
	CString strParaConfig = L"驱动参数名";
	if (GetPrivateProfileString(strParaConfig, L"WidthParaName", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strITParaWidthName = lpValue;
	if (GetPrivateProfileString(strParaConfig, L"DepthParaName", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strITParaDepthName = lpValue;
	if (GetPrivateProfileString(strParaConfig, L"HeightParaName", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strITParaHeightName = lpValue;

	// 装配坐标系
	CString strCompCsysConfig = L"装配坐标系";
	if (GetPrivateProfileString(strCompCsysConfig, L"机柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strFWQJGCompCsysName = lpValue;

	// 模板文件
	CString strTemplateNameConfig = L"模板文件";
	if (GetPrivateProfileString(strTemplateNameConfig, L"机柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strFWQJGTemplateAsmName = lpValue;

	return true;
}

//===================================================================================================
