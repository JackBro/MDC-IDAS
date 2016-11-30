//===================================================================================================
// Summary:
//		ģ����غ�����
// Date:
//		2016-08-19
// Author:
//		HuoPengcheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

//====================================================================================================

// ������������Ϣ
typedef struct __tagPCLAsmComppathInfo
{
	ProIdTable idTab;	// ID��
	int nIndex;			// ��ǰ����
	ProSolid pTopAsm;	// ���������

	__tagPCLAsmComppathInfo()
	{
		memset(idTab, -1, sizeof(ProIdTable)); 
		nIndex = -1; 
		pTopAsm = NULL; 
	}
	__tagPCLAsmComppathInfo(const __tagPCLAsmComppathInfo &aci)
	{
		for (int i=0; i<PRO_MAX_ASSEM_LEVEL; i++) 
			idTab[i] = aci.idTab[i];
		nIndex = aci.nIndex;
		pTopAsm = aci.pTopAsm;
	}
	__tagPCLAsmComppathInfo &operator=(const __tagPCLAsmComppathInfo &aci)
	{
		if (&aci != this)
		{
			for (int i=0; i<PRO_MAX_ASSEM_LEVEL; i++) 
				idTab[i] = aci.idTab[i];
			nIndex = aci.nIndex;
			pTopAsm = aci.pTopAsm;
		}
		return *this;
	}
}PCLAsmComppathInfo;

typedef CArray<PCLAsmComppathInfo, PCLAsmComppathInfo&> PCLAsmComppathArray;

// ��ʾ����������Ϣ
typedef struct __tagPCLMdlVisitInfo
{
	PCLAsmComppathInfo partInfo;						// �����Ϣ
	void *pData;

	__tagPCLMdlVisitInfo()
	{
		pData = NULL;
	}

	__tagPCLMdlVisitInfo(const __tagPCLMdlVisitInfo &spi)
	{
		partInfo = spi.partInfo;
		pData = spi.pData;
	}
	__tagPCLMdlVisitInfo &operator=(const __tagPCLMdlVisitInfo &spi)
	{
		if (&spi != this)
		{
			partInfo = spi.partInfo;
			pData = spi.pData;
		}
		return *this;
	}
}PCLMdlVisitInfo;

//====================================================================================================
// ģ����غ�����
class CPCLMdl
{
public:
	CPCLMdl();
	virtual ~CPCLMdl();

public:
	// ��õ�ǰģ��
	static ProMdl GetCurrentMdl();
	// ��ȡ��ǰģ������
	static ProMdlType GetCurrentMdlType();
	// ��õ�ǰ���ģ��
	static ProAssembly GetCurrentAssembly();
	// ��õ�ǰ���ģ��
	static ProPart GetCurrentPart();
	// ��õ�ǰ����ͼģ��
	static ProDrawing GetCurrentDrawing();

public:

	// ��ȡ���͵�����
	static CString GetTypeDesc(
		ProType eType									// ����(in)
		);
	
	// ��ȡģ�͵�����
	static CString GetMdlDesc(
		ProName mdlName,								// ģ�͵�����(in)
		ProMdlType mdlType								// ģ�͵�����(in)
		);

	// ��ȡģ�͵�����
	static CString GetMdlDesc(
		ProMdl pMdl										// ģ��(in)
		);

	// ��ȡ��׼������
	static CString GetDatumDesc(
		ProType eType									// ��׼����(in)
		);

public:

	// ����װ����ģ�ͻ�ȡ�Ǽ�ģ��
	static BOOL GetSkelMdlFromAsmMdl(
		ProAssembly pAsm,								// װ����(in)
		vector<ProAsmcomp> &arrSkelComps				// �Ǽ�ģ��Ԫ������(out)
		);
	
	// ��ȡģ�͵�ָ��������
	static BOOL GetSolidFeature(
		ProSolid pSld,									// ģ��(in)
		ProFeattype feaType,							// ��������(in)
		vector<ProFeature> &arrFeature					// ������(out)
		);

	// ��ȡѡ��ģ������������ѡ�����
	static BOOL GetSolidFeatureSelection(
		ProSelection pSelSld,							// ѡ��ģ��(in)
		int nFeatureType,								// ��������(in)
		vector<ProSelection> &arrSelFeature				// ����ѡ�����(out)
		);
	
public:

	// ��ȡ·���ĸ�·��
	static BOOL GetAsmcomppathFatherPath(
		ProAsmcomppath &comppath,						// ·��(in)
		ProAsmcomppath &fatherPath						// ��·��(out)
		);

	// ��ȡ·���ĸ����
	static BOOL GetAsmcomppathFatherAsm(
		ProAsmcomppath &comppath,						// ·��(in)
		ProMdl &pFatherAsm								// �����(out)
		);

	// ��ȡ·���������
	static BOOL GetAsmcomppathGrandAsm(
		ProAsmcomppath &comppath,						// ·��(in)
		ProMdl &pGrandAsm								// �����(out)
		);

	// ��ȡѡ�����ĸ����
	static BOOL GetSelectionFatherAsm(
		ProSelection pSel,								// ѡ�����(in)
		ProMdl &pFatherAsm								// �����(out)
		);

	// ��ȡѡ�����������
	static BOOL GetSelectionGrandAsm(
		ProSelection pSel,								// ѡ�����(in)
		ProMdl &pGrandAsm								// �����(out)
		);

private:
	// ��ùǼ�ģ�͵Ķ�������
	static ProError GetSkelMdlArrayVisit(ProFeature* pFeature,ProError status,ProAppData pAppData);
	// �Ǽ�ģ�͵Ĺ��˺���
	static ProError GetSkelMdlArrayFilter(ProFeature* pFeature,ProAppData pAppData);
	// ģ���ض����������Ķ�������
	static ProError GetSolidFeatureVisit(ProFeature* pFeature, ProError status, ProAppData pAppData);
	// ģ���ض����������Ĺ��˺���
	static ProError GetSolidFeatureFilter(ProFeature* pFeature, ProAppData pAppData);
	// ��������ģ�͹��˺���
	static ProError GetFeatureSelectionFilterAction(ProFeature* pFeature, ProAppData pAppData);
	// ��������ģ�Ͷ�������
	static ProError GetFeatureSelectionVisitAction(ProFeature* pFeature, ProError status, ProAppData pAppData);
};

//===================================================================================================


