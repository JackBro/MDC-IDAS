//===================================================================================================
// Summary:
//		ӳ�����غ�����
// Date:
//		2016-08-22
// Author:
//		HuoPengcheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

//====================================================================================================
// ӳ�����غ�����
class CPCLMapKey
{
public:
	CPCLMapKey();
	virtual ~CPCLMapKey();

public:
	// ����ӳ������ں���������ִ�У�
	static void LoadMapKey(
		const CString &strMacro,										// ӳ�����������(in)
		ProSelection pSel												// ѡ�����(in)
		);
	// ����ӳ������ں���������ִ�У�
	static void LoadMapKey(
		const CString &strMacro,										// ӳ�����������(in)
		ProModelitem *pMdlItem = NULL									// ģ�Ͷ���(in)
		);
	// ִ��ӳ���
	static void ExecuteMapKey(
		const CString &strMacro,										// ӳ�����������(in)
		ProSelection pSel												// ѡ�����(in)
		);
	// ִ��ӳ���
	static void ExecuteMapKey(
		const CString &strMacro,										// ӳ�����������(in)
		ProModelitem *pMdlItem = NULL									// ģ�Ͷ���(in)
		);


};

//===================================================================================================


