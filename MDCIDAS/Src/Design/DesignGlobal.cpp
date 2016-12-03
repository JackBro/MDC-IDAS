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
CString g_strFWQJGCompCsysName = _T("");
// 管控柜装配坐标
CString g_strGKGCompCsysName = _T("");
// 空调柜装配坐标
CString g_strKTGCompCsysName = _T("");
// 消防柜装配坐标
CString g_strXFGCompCsysName = _T("");
// 导风柜装配坐标
CString g_strDFGCompCsysName = _T("");
// 行间空柜装配坐标
CString g_strHJKGCompCsysName = _T("");
// 走线架装配坐标
CString g_strZXJCompCsysName = _T("");
// 光纤槽装配坐标
CString g_strGXCCompCsysName = _T("");
// 固定顶窗装配坐标
CString g_strGDDCCompCsysName = _T("");
// 翻转顶窗装配坐标
CString g_strFZDCCompCsysName = _T("");
// 可调顶窗装配坐标
CString g_strKTDCCompCsysName = _T("");
// 走下架支架装配坐标
CString g_strZXJZJCompCsysName = _T("");
// 通道平门装配坐标
CString g_strTDPMCompCsysName = _T("");
// 通道凸门装配坐标
CString g_strTDTMCompCsysName = _T("");
// 围板装配坐标
CString g_strZJWBCompCsysName = _T("");
// 走线架转接板装配坐标
CString g_strZXJZJBCompCsysName = _T("");
// 凸门立柱装配坐标
CString g_strTMLZCompCsysName = _T("");
// 连接支架装配坐标
CString g_strLJZJCompCsysName = _T("");
// 踏步装配坐标
CString g_strTBZJCompCsysName = _T("");
// 机柜侧门装配坐标
CString g_strJGCMCompCsysName = _T("");
// 边底座装配坐标
CString g_strBDZCompCsysName = _T("");
// 底座挡板装配坐标
CString g_strDZDBCompCsysName = _T("");
// 底座托板装配坐标
CString g_strDZTBCompCsysName = _T("");
// 底座横梁装配坐标
CString g_strDZHLCompCsysName = _T("");
// 底座装配坐标
CString g_strDZCompCsysName = _T("");
// 配电柜装配坐标
CString g_strPDGCompCsysName = _T("");
// 假墙框架装配坐标
CString g_strJQKJCompCsysName = _T("");
// 假墙底座装配坐标
CString g_strJQDZCompCsysName = _T("");
// 左框架装配坐标
CString g_strZKJCompCsysName = _T("");
// 右框架装配坐标
CString g_strYKJCompCsysName = _T("");
// 框架底座装配坐标
CString g_strKJDZCompCsysName = _T("");
// 框架装配坐标
CString g_strKJCompCsysName = _T("");

// 服务器机柜模板组件名称
CString g_strFWQJGTemplateAsmName = _T("");
// 管控柜模板组件名称
CString g_strGKGTemplateAsmName = _T("");
// 空调柜模板组件名称
CString g_strKTGTemplateAsmName = _T("");
// 消防柜模板组件名称
CString g_strXFGTemplateAsmName = _T("");
// 导风柜模板组件名称
CString g_strDFGTemplateAsmName = _T("");
// 行间空柜模板组件名称
CString g_strHJKGTemplateAsmName = _T("");
// 走线架模板组件名称
CString g_strZXJTemplateAsmName = _T("");
// 光纤槽模板组件名称
CString g_strGXCTemplateAsmName = _T("");
// 固定顶窗模板组件名称
CString g_strGDDCTemplateAsmName = _T("");
// 翻转顶窗模板组件名称
CString g_strFZDCTemplateAsmName = _T("");
// 可调顶窗模板组件名称
CString g_strKTDCTemplateAsmName = _T("");
// 走下架支架模板组件名称
CString g_strZXJZJTemplateAsmName = _T("");
// 通道平门模板组件名称
CString g_strTDPMTemplateAsmName = _T("");
// 通道凸门模板组件名称
CString g_strTDTMTemplateAsmName = _T("");
// 围板模板组件名称
CString g_strZJWBTemplateAsmName = _T("");
// 走线架转接板模板组件名称
CString g_strZXJZJBTemplateAsmName = _T("");
// 凸门立柱模板组件名称
CString g_strTMLZTemplateAsmName = _T("");
// 连接支架模板组件名称
CString g_strLJZJTemplateAsmName = _T("");
// 踏步模板组件名称
CString g_strTBZJTemplateAsmName = _T("");
// 机柜侧门模板组件名称
CString g_strJGCMTemplateAsmName = _T("");
// 边底座模板组件名称
CString g_strBDZTemplateAsmName = _T("");
// 底座挡板模板组件名称
CString g_strDZDBTemplateAsmName = _T("");
// 底座托板模板组件名称
CString g_strDZTBTemplateAsmName = _T("");
// 底座横梁模板组件名称
CString g_strDZHLTemplateAsmName = _T("");
// 底座模板组件名称
CString g_strDZTemplateAsmName = _T("");
// 配电柜模板组件名称
CString g_strPDGTemplateAsmName = _T("");
// 假墙框架模板组件名称
CString g_strJQKJTemplateAsmName = _T("");
// 假墙底座模板组件名称
CString g_strJQDZTemplateAsmName = _T("");
// 左框架模板组件名称
CString g_strZKJTemplateAsmName = _T("");
// 右框架模板组件名称
CString g_strYKJTemplateAsmName = _T("");
// 框架底座模板组件名称
CString g_strKJDZTemplateAsmName = _T("");
// 框架模板组件名称
CString g_strKJTemplateAsmName = _T("");

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
		return DMT_ROW_EMPTY;
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
	if (GetPrivateProfileString(strCompCsysConfig, L"服务器机柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strFWQJGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"管控柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strGKGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"空调柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKTGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"消防柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strXFGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"导风柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDFGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"行间空柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strHJKGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"走线架", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZXJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"光纤槽", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strGXCCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"固定顶窗", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strGDDCCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"翻转顶窗", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strFZDCCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"可调顶窗", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKTDCCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"走线架支架", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZXJZJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"通道平门", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTDPMCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"通道凸门", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTDTMCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"围板", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZJWBCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"走线架转接板", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZXJZJBCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"凸门立柱", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTMLZCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"凸门立柱底座", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strLJZJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"踏步", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTBZJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"机柜侧门", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strJGCMCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"边底座", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strBDZCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"底座挡板", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZDBCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"底座托板", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZTBCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"底座横梁", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZHLCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"底座", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"配电柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strPDGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"假墙框架", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strJQKJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"假墙底座", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strJQDZCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"左框架", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZKJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"右框架", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strYKJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"框架底座", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKJDZCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"框架", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKJCompCsysName = lpValue;

	// 模板文件
	CString strTemplateNameConfig = L"模板文件";
	if (GetPrivateProfileString(strTemplateNameConfig, L"服务器机柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strFWQJGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"管控柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strGKGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"空调柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKTGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"消防柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strXFGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"导风柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDFGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"行间空柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strHJKGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"走线架", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZXJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"光纤槽", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strGXCTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"固定顶窗", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strGDDCTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"翻转顶窗", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strFZDCTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"可调顶窗", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKTDCTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"走线架支架", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZXJZJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"通道平门", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTDPMTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"通道凸门", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTDTMTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"围板", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZJWBTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"走线架转接板", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZXJZJBTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"凸门立柱", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTMLZTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"凸门立柱底座", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strLJZJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"踏步", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTBZJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"机柜侧门", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strJGCMTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"边底座", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strBDZTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"底座挡板", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZDBTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"底座托板", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZTBTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"底座横梁", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZHLTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"底座", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"配电柜", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strPDGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"假墙框架", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strJQKJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"假墙底座", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strJQDZTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"左框架", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZKJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"右框架", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strYKJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"框架底座", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKJDZTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"框架", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKJTemplateAsmName = lpValue;

	return true;
}

// 根据布局图DVF转换为XML文件
bool TransDVF2XML(const CString &strDVFPath, const CString &strXMLPath)
{
	if (!IsFileExist(strDVFPath))
		return false;

	// 加载动态库
	CString strDVF2XMLDllName;
	GetMainModulePath(strDVF2XMLDllName, theApp.m_hInstance);
#if WIN64
	strDVF2XMLDllName += L"\\DVF2XML_x64.dll";
#else
	strDVF2XMLDllName += L"\\DVF2XML.dll";
#endif

	HMODULE hConvertModule = ::LoadLibrary(strDVF2XMLDllName);
	if (hConvertModule == NULL)
		return false;

	bool bResult = false;
	// 转换函数
	fun_ExportDVF2Xml pExportDVF2Xml = (fun_ExportDVF2Xml)GetProcAddress(hConvertModule, "ExportDVF2Xml");
	if (pExportDVF2Xml != NULL)
		bResult = pExportDVF2Xml((LPCTSTR)strDVFPath, (LPCTSTR)strXMLPath);

	return bResult;
}

//===================================================================================================
