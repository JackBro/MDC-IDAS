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
// �ܿع�װ������
extern CString g_strGKGCompCsysName;
// �յ���װ������
extern CString g_strKTGCompCsysName;
// ������װ������
extern CString g_strXFGCompCsysName;
// �����װ������
extern CString g_strDFGCompCsysName;
// �м�չ�װ������
extern CString g_strHJKGCompCsysName;
// ���߼�װ������
extern CString g_strZXJCompCsysName;
// ���˲�װ������
extern CString g_strGXCCompCsysName;
// �̶�����װ������
extern CString g_strGDDCCompCsysName;
// ��ת����װ������
extern CString g_strFZDCCompCsysName;
// �ɵ�����װ������
extern CString g_strKTDCCompCsysName;
// ���¼�֧��װ������
extern CString g_strZXJZJCompCsysName;
// ͨ��ƽ��װ������
extern CString g_strTDPMCompCsysName;
// ͨ��͹��װ������
extern CString g_strTDTMCompCsysName;
// Χ��װ������
extern CString g_strZJWBCompCsysName;
// ���߼�ת�Ӱ�װ������
extern CString g_strZXJZJBCompCsysName;
// ͹������װ������
extern CString g_strTMLZCompCsysName;
// ����֧��װ������
extern CString g_strLJZJCompCsysName;
// ̤��װ������
extern CString g_strTBZJCompCsysName;
// �������װ������
extern CString g_strJGCMCompCsysName;
// �ߵ���װ������
extern CString g_strBDZCompCsysName;
// ��������װ������
extern CString g_strDZDBCompCsysName;
// �����а�װ������
extern CString g_strDZTBCompCsysName;
// ��������װ������
extern CString g_strDZHLCompCsysName;
// ����װ������
extern CString g_strDZCompCsysName;
// ����װ������
extern CString g_strPDGCompCsysName;
// ��ǽ���װ������
extern CString g_strJQKJCompCsysName;
// ��ǽ����װ������
extern CString g_strJQDZCompCsysName;
// ����װ������
extern CString g_strZKJCompCsysName;
// �ҿ��װ������
extern CString g_strYKJCompCsysName;
// ��ܵ���װ������
extern CString g_strKJDZCompCsysName;
// ���װ������
extern CString g_strKJCompCsysName;

// ����������ģ���������
extern CString g_strFWQJGTemplateAsmName;
// �ܿع�ģ���������
extern CString g_strGKGTemplateAsmName;
// �յ���ģ���������
extern CString g_strKTGTemplateAsmName;
// ������ģ���������
extern CString g_strXFGTemplateAsmName;
// �����ģ���������
extern CString g_strDFGTemplateAsmName;
// �м�չ�ģ���������
extern CString g_strHJKGTemplateAsmName;
// ���߼�ģ���������
extern CString g_strZXJTemplateAsmName;
// ���˲�ģ���������
extern CString g_strGXCTemplateAsmName;
// �̶�����ģ���������
extern CString g_strGDDCTemplateAsmName;
// ��ת����ģ���������
extern CString g_strFZDCTemplateAsmName;
// �ɵ�����ģ���������
extern CString g_strKTDCTemplateAsmName;
// ���¼�֧��ģ���������
extern CString g_strZXJZJTemplateAsmName;
// ͨ��ƽ��ģ���������
extern CString g_strTDPMTemplateAsmName;
// ͨ��͹��ģ���������
extern CString g_strTDTMTemplateAsmName;
// Χ��ģ���������
extern CString g_strZJWBTemplateAsmName;
// ���߼�ת�Ӱ�ģ���������
extern CString g_strZXJZJBTemplateAsmName;
// ͹������ģ���������
extern CString g_strTMLZTemplateAsmName;
// ����֧��ģ���������
extern CString g_strLJZJTemplateAsmName;
// ̤��ģ���������
extern CString g_strTBZJTemplateAsmName;
// �������ģ���������
extern CString g_strJGCMTemplateAsmName;
// �ߵ���ģ���������
extern CString g_strBDZTemplateAsmName;
// ��������ģ���������
extern CString g_strDZDBTemplateAsmName;
// �����а�ģ���������
extern CString g_strDZTBTemplateAsmName;
// ��������ģ���������
extern CString g_strDZHLTemplateAsmName;
// ����ģ���������
extern CString g_strDZTemplateAsmName;
// ����ģ���������
extern CString g_strPDGTemplateAsmName;
// ��ǽ���ģ���������
extern CString g_strJQKJTemplateAsmName;
// ��ǽ����ģ���������
extern CString g_strJQDZTemplateAsmName;
// ����ģ���������
extern CString g_strZKJTemplateAsmName;
// �ҿ��ģ���������
extern CString g_strYKJTemplateAsmName;
// ��ܵ���ģ���������
extern CString g_strKJDZTemplateAsmName;
// ���ģ���������
extern CString g_strKJTemplateAsmName;

//===================================================================================================

// ���ݲ���ͼ�������ͻ�ȡ������������
int GetDesignModelType(int nSymbolSubtype);
// ��ʼ��ȫ�ֱ���
bool InitDesignGlobalData();

//===================================================================================================

