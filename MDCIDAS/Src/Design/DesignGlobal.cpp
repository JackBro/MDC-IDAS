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
	case SCT_MCC:
		return DMT_MGT;
	case SCT_FMCC:
		return DMT_COL_HAED_MGT;
	case SCT_TAC:
		return DMT_TAC;
	case SCT_FHC:
		return DMT_FHC;
	case SCT_FEC:
		return DMT_COL_HAED_EMPTY;
	case SCT_PDC:
		return DMT_PDR;
	case SCT_FPDC:
		return DMT_COL_HEAD_PDR;
	case SCT_IEC:
		return DMT_ROW__EMPTY;
	case SCT_AGC:
		return DMT_DAO_FENG;
	case SCT_CR:
		return DMT_ZOU_XIAN_JIA;
	case SCT_OFG:
		return DMT_GUANG_XIAN_ZXJ;
	case SCT_WCln:
		return DMT_WALL_PILLAR;
	case SCT_Cdoor:
		return DMT_COLD_BACK_DOOR;
	case SCT_Fdoor:
		return DMT_COLD_FRONT_DOOR;
	case SCT_FTW:
		return DMT_FIXED_WINDOW;
	case SCT_RTW:
		return DMT_FLIP_WINDOW;
	case SCT_ATW:
		return DMT_ADJUST_WINDOW;
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
