//===================================================================================================
// Summary:
//		��������ģ��ʹ�õĹ��ú���
// Date:
//		2016-12-01
// Author:
//		lgq
//===================================================================================================

#pragma once

//===================================================================================================

// ȫ�ֱ�������

// ����ģ�����_��
extern CString g_strITParaWidthName;
// ����ģ�����_��
extern CString g_strITParaDepthName;
// ����ģ�����_��
extern CString g_strITParaHeightName;
// ����������װ������
extern CString g_strFWQJGCompCsysName;

// ����ģ���������
extern CString g_strFWQJGTemplateAsmName;

//===================================================================================================

// ���ݲ���ͼ�������ͻ�ȡ������������
int GetDesignModelType(int nSymbolSubtype);
// ��ʼ��ȫ�ֱ���
bool InitDesignGlobalData();

//===================================================================================================
