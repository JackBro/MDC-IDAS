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
CString g_strFWQJGCompCsysName = _T("");
// �ܿع�װ������
CString g_strGKGCompCsysName = _T("");
// �յ���װ������
CString g_strKTGCompCsysName = _T("");
// ������װ������
CString g_strXFGCompCsysName = _T("");
// �����װ������
CString g_strDFGCompCsysName = _T("");
// �м�չ�װ������
CString g_strHJKGCompCsysName = _T("");
// ���߼�װ������
CString g_strZXJCompCsysName = _T("");
// ���˲�װ������
CString g_strGXCCompCsysName = _T("");
// �̶�����װ������
CString g_strGDDCCompCsysName = _T("");
// ��ת����װ������
CString g_strFZDCCompCsysName = _T("");
// �ɵ�����װ������
CString g_strKTDCCompCsysName = _T("");
// ���¼�֧��װ������
CString g_strZXJZJCompCsysName = _T("");
// ͨ��ƽ��װ������
CString g_strTDPMCompCsysName = _T("");
// ͨ��͹��װ������
CString g_strTDTMCompCsysName = _T("");
// Χ��װ������
CString g_strZJWBCompCsysName = _T("");
// ���߼�ת�Ӱ�װ������
CString g_strZXJZJBCompCsysName = _T("");
// ͹������װ������
CString g_strTMLZCompCsysName = _T("");
// ����֧��װ������
CString g_strLJZJCompCsysName = _T("");
// ̤��װ������
CString g_strTBZJCompCsysName = _T("");
// �������װ������
CString g_strJGCMCompCsysName = _T("");
// �ߵ���װ������
CString g_strBDZCompCsysName = _T("");
// ��������װ������
CString g_strDZDBCompCsysName = _T("");
// �����а�װ������
CString g_strDZTBCompCsysName = _T("");
// ��������װ������
CString g_strDZHLCompCsysName = _T("");
// ����װ������
CString g_strDZCompCsysName = _T("");
// ����װ������
CString g_strPDGCompCsysName = _T("");
// ��ǽ���װ������
CString g_strJQKJCompCsysName = _T("");
// ��ǽ����װ������
CString g_strJQDZCompCsysName = _T("");
// ����װ������
CString g_strZKJCompCsysName = _T("");
// �ҿ��װ������
CString g_strYKJCompCsysName = _T("");
// ��ܵ���װ������
CString g_strKJDZCompCsysName = _T("");
// ���װ������
CString g_strKJCompCsysName = _T("");

// ����������ģ���������
CString g_strFWQJGTemplateAsmName = _T("");
// �ܿع�ģ���������
CString g_strGKGTemplateAsmName = _T("");
// �յ���ģ���������
CString g_strKTGTemplateAsmName = _T("");
// ������ģ���������
CString g_strXFGTemplateAsmName = _T("");
// �����ģ���������
CString g_strDFGTemplateAsmName = _T("");
// �м�չ�ģ���������
CString g_strHJKGTemplateAsmName = _T("");
// ���߼�ģ���������
CString g_strZXJTemplateAsmName = _T("");
// ���˲�ģ���������
CString g_strGXCTemplateAsmName = _T("");
// �̶�����ģ���������
CString g_strGDDCTemplateAsmName = _T("");
// ��ת����ģ���������
CString g_strFZDCTemplateAsmName = _T("");
// �ɵ�����ģ���������
CString g_strKTDCTemplateAsmName = _T("");
// ���¼�֧��ģ���������
CString g_strZXJZJTemplateAsmName = _T("");
// ͨ��ƽ��ģ���������
CString g_strTDPMTemplateAsmName = _T("");
// ͨ��͹��ģ���������
CString g_strTDTMTemplateAsmName = _T("");
// Χ��ģ���������
CString g_strZJWBTemplateAsmName = _T("");
// ���߼�ת�Ӱ�ģ���������
CString g_strZXJZJBTemplateAsmName = _T("");
// ͹������ģ���������
CString g_strTMLZTemplateAsmName = _T("");
// ����֧��ģ���������
CString g_strLJZJTemplateAsmName = _T("");
// ̤��ģ���������
CString g_strTBZJTemplateAsmName = _T("");
// �������ģ���������
CString g_strJGCMTemplateAsmName = _T("");
// �ߵ���ģ���������
CString g_strBDZTemplateAsmName = _T("");
// ��������ģ���������
CString g_strDZDBTemplateAsmName = _T("");
// �����а�ģ���������
CString g_strDZTBTemplateAsmName = _T("");
// ��������ģ���������
CString g_strDZHLTemplateAsmName = _T("");
// ����ģ���������
CString g_strDZTemplateAsmName = _T("");
// ����ģ���������
CString g_strPDGTemplateAsmName = _T("");
// ��ǽ���ģ���������
CString g_strJQKJTemplateAsmName = _T("");
// ��ǽ����ģ���������
CString g_strJQDZTemplateAsmName = _T("");
// ����ģ���������
CString g_strZKJTemplateAsmName = _T("");
// �ҿ��ģ���������
CString g_strYKJTemplateAsmName = _T("");
// ��ܵ���ģ���������
CString g_strKJDZTemplateAsmName = _T("");
// ���ģ���������
CString g_strKJTemplateAsmName = _T("");

//===================================================================================================

// ���ݲ���ͼ�������ͻ�ȡ������������
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
	if (GetPrivateProfileString(strCompCsysConfig, L"����������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strFWQJGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"�ܿع�", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strGKGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"�յ���", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKTGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strXFGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"�����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDFGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"�м�չ�", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strHJKGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"���߼�", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZXJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"���˲�", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strGXCCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"�̶�����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strGDDCCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"��ת����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strFZDCCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"�ɵ�����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKTDCCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"���߼�֧��", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZXJZJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"ͨ��ƽ��", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTDPMCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"ͨ��͹��", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTDTMCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"Χ��", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZJWBCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"���߼�ת�Ӱ�", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZXJZJBCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"͹������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTMLZCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"͹����������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strLJZJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"̤��", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTBZJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"�������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strJGCMCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"�ߵ���", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strBDZCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"��������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZDBCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"�����а�", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZTBCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"��������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZHLCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strPDGCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"��ǽ���", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strJQKJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"��ǽ����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strJQDZCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZKJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"�ҿ��", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strYKJCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"��ܵ���", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKJDZCompCsysName = lpValue;
	if (GetPrivateProfileString(strCompCsysConfig, L"���", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKJCompCsysName = lpValue;

	// ģ���ļ�
	CString strTemplateNameConfig = L"ģ���ļ�";
	if (GetPrivateProfileString(strTemplateNameConfig, L"����������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strFWQJGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"�ܿع�", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strGKGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"�յ���", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKTGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strXFGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"�����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDFGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"�м�չ�", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strHJKGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"���߼�", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZXJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"���˲�", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strGXCTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"�̶�����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strGDDCTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"��ת����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strFZDCTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"�ɵ�����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKTDCTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"���߼�֧��", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZXJZJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"ͨ��ƽ��", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTDPMTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"ͨ��͹��", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTDTMTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"Χ��", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZJWBTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"���߼�ת�Ӱ�", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZXJZJBTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"͹������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTMLZTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"͹����������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strLJZJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"̤��", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strTBZJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"�������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strJGCMTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"�ߵ���", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strBDZTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"��������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZDBTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"�����а�", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZTBTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"��������", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZHLTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strDZTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strPDGTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"��ǽ���", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strJQKJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"��ǽ����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strJQDZTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"����", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strZKJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"�ҿ��", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strYKJTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"��ܵ���", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKJDZTemplateAsmName = lpValue;
	if (GetPrivateProfileString(strTemplateNameConfig, L"���", L"", lpValue, MAX_PATH, strConfigFile) > 0)
		g_strKJTemplateAsmName = lpValue;

	return true;
}

// ���ݲ���ͼDVFת��ΪXML�ļ�
bool TransDVF2XML(const CString &strDVFPath, const CString &strXMLPath)
{
	if (!IsFileExist(strDVFPath))
		return false;

	// ���ض�̬��
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
	// ת������
	fun_ExportDVF2Xml pExportDVF2Xml = (fun_ExportDVF2Xml)GetProcAddress(hConvertModule, "ExportDVF2Xml");
	if (pExportDVF2Xml != NULL)
		bResult = pExportDVF2Xml((LPCTSTR)strDVFPath, (LPCTSTR)strXMLPath);

	return bResult;
}

//===================================================================================================
