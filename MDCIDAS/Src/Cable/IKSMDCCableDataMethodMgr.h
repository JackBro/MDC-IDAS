//===================================================================================================
// File:
//		IKSMDCCableDataMethodMgr.h
// Summary:
//		΢ģ��������ݷ����Ĺ�����
// Date:
//		2016-11-21
// Author:
//		WangShiping
//===================================================================================================

#pragma once

#include "IKSMDCCableDataDef.h"

//===================================================================================================


//===================================================================================================

class CIKSMDCCableDataMethodMgr
{
public:
	CIKSMDCCableDataMethodMgr();
	~CIKSMDCCableDataMethodMgr();

public:
	BOOL Init();
	void UnInit();

protected:
	// ����ѡ������
	void LoadConfig();

// ���²��ֲ����͵�����Ʋ���
public:
	// ��ȡ���ֲ���(�ӵ�ǰװ�����ȡ����)
	void GetLayoutParamFromCurAsm();

	// ��ȡ���²��ֲ���(�ӵ�ǰװ�����ȡ����)
	void GetCableLayoutParamFromCurAsm();
// 	// ���µ��²��ֲ�������ǰװ����
// 	void UpdateCableLayoutParamToCurAsm() const;

	// ��ȡ������Ʋ���(�ӵ�ǰ����װ�����ȡ����)
	void GetCableDesignParamFromCurAsm();
	// ��ȡ������Ʋ���(�����벼��װ�����ȡ����)
	void GetCableDesignParamFromCurAsm(IKSMDCCableDesignParam &stuCableDesignParam, ProAssembly pCablingAsm=NULL);
	// ���µ�����Ʋ�������ǰװ����
	void UpdateCableDesignParamToCurAsm() const;

	// ���ݲ��ֲ�������������Ʋ���
	void CorrectCableDesignParamByLayoutParam();

// ����װ����
public:
	// ���²���װ���壨�ӵ�ǰװ�����л�ȡ����װ���壬��δ�ҵ�����д�����
	BOOL UpdateCablingAsm();

	// ��֤��ǰװ�����Ƿ���Ҫ�ؽ�
	BOOL IsCablingAsmNeedToRebuild(const IKSMDCCableDesignParam &stuOriCableDesignParam, const IKSMDCCableDesignParam &stuCurCableDesignParam);

// ����װ����
protected:
	// �ڵ�ǰװ�����д�������װ����
	ProAssembly CreateCablingAsmInCurAsm(ProAsmcomppath *pCablingAsmCompPath=NULL);
	// �ڵ�ǰװ�����л�ȡ����װ����
	ProAssembly GetCablingAsmInCurAsm(ProAsmcomppath *pCablingAsmCompPath=NULL);

	// ͨ��װ��������������Ĺ��˺���
	static ProError GetCablingAsmOfAssemblyFilter(ProFeature* pFeature, ProAppData pAppData);
	// ͨ��װ��������������ķ��ʺ���
	static ProError GetCablingAsmOfAssemblyVisit(ProFeature* pFeature, ProError status, ProAppData pAppData);
	// �������������Ƿ���Ч
	static IKS_BOOL CheckFeatureValid(ProFeature* pFeature);

	// ����ȱʡԼ��
	BOOL SetDefaultConstraint(ProAsmcomp *pAsmComp);

// ��������
public:
	// �ڲ���װ�����д�������������λ����ϵ�����Ѵ�������ɾ�������´���������޸ģ������ݶ���װ�����еĵ���������λ����ϵ���д�����
	BOOL CreateConnLocCSysInCablingAsm();

	// װ�䲢ָ����������
	BOOL AssemblyAndDesignateConnector(CBPDynamicArray<UINT> *parrFailedAsmConnIndex=NULL, ProAssembly pConnParentAsm=NULL, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL);
	// װ�䲢ָ����������
	BOOL AssemblyAndDesignateConnector(std::vector<IKSMDCConnector> &vecMDCConnector, CBPDynamicArray<UINT> &arrFailedAsmConnIndex, ProAssembly pConnParentAsm=NULL, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL);
	// ������������ܷ�װ��
	BOOL CheckConnectorAssembly(CBPDynamicArray<UINT> *parrLostCSysConnIndex=NULL, CBPDynamicArray<UINT> *parrFailedLoadMdlConnIndex=NULL, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL, CUnicodeString *pPrompt=NULL);
	// ������������ܷ�װ��
	BOOL CheckConnectorAssembly(const std::vector<IKSMDCConnector> &vecMDCConnector, CBPDynamicArray<UINT> &arrLostCSysConnIndex, CBPDynamicArray<UINT> &arrFailedLoadMdlConnIndex, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL, CUnicodeString *pPrompt=NULL);
	// ���صĵ�������ģ��ģ��
	void LoadConnTemplateMdl();

	// ��ʼ��������������
	void InitConnectorParam(IKSConnectorParamInfo &stuConnParam);
	// ���������˿�����ϵProSelection����������
	BOOL ConnectorPortCSysProSelectionAlloc(const CIKSMDCRoutCabProjDataInf &stuRoutCabProjDataInf, const CSVWString &strRefDes, ProSelection &pSelection, CSVStringIndexMgr *pmapConnRefDesIndexMgr=NULL);

// ����
public:
	// ͨ��������Ŀ������Ϣ�����������������������������
	BOOL CreateHarnessCableSplData();
	// ͨ��������Ŀ������Ϣ�����������������������������
	BOOL CreateHarnessCableSplData(const CIKSMDCRoutCabProjDataInf &stuRoutCabProjDataInf, ProAssembly pCablingAsm);

	// ���ݵ�ǰProEģ�����ݸ��²�����Ŀ������Ϣ�е���������
	BOOL UpdateRoutCabProjHarnDataByCurAsmData();
	// ���ݵ�ǰProEģ�����ݸ��²�����Ŀ������Ϣ�е���������
	BOOL UpdateRoutCabProjHarnDataByCurAsmData(CIKSMDCRoutCabProjDataInf &stuRoutCabProjDataInf);

	// ͨ��������Ŀ������Ϣ���ߵ���
	BOOL RoutingCable();
	// ͨ��������Ŀ������Ϣ���ߵ���
	BOOL RoutingCable(const CIKSMDCRoutCabProjDataInf &stuRoutCabProjDataInf, ProAssembly pCablingAsm);

// ����
protected:
	// ��������ģ��
	BOOL CreateHarnessMdl(CIKSMDCHarness* pHarness, ProAssembly pCablingAsm);
	// ���������ڵĵ�������
	BOOL CreateCableFeatInHarn(CIKSMDCHarness* pHarness);
	// ������������
	BOOL CreateCableFeat(CIKSMDCHarness* pHarness, CIKSMDCCable* pCable);

// ����
public:
	// ����
	void Test();

public:
	const CIKSMDCRoutCabProjDataInf* GetRoutCabProjDataInfPt() const { return &m_RoutCabProjDataInf; }
	const CIKSMDCRoutCabProjDataInf& GetRoutCabProjDataInf() const { return m_RoutCabProjDataInf; }
	void SetRoutCabProjDataInf(const CIKSMDCRoutCabProjDataInf& RoutCabProjDataInf) { m_RoutCabProjDataInf = RoutCabProjDataInf;}

	const IKSMDCCableLayoutParam& GetCableLayoutParam() const { return m_RoutCabProjDataInf.m_CableLayoutParam; }
	void SetCableLayoutParam(const IKSMDCCableLayoutParam& CableLayoutParam) { m_RoutCabProjDataInf.m_CableLayoutParam = CableLayoutParam;}

	const IKSMDCCableDesignParam& GetCableDesignParam() const { return m_RoutCabProjDataInf.m_CableDesignParam; }
	void SetCableDesignParam(const IKSMDCCableDesignParam& CableDesignParam) { m_RoutCabProjDataInf.m_CableDesignParam = CableDesignParam;}

	ProAssembly GetCablingAsm() const { return m_pCablingAsm; }
	void SetCablingAsm(ProAssembly pCablingAsm) { m_pCablingAsm = pCablingAsm; }

	ProAsmcomppath* GetCablingAsmCompPathPt() { return &m_stuCablingAsmCompPath; }
	ProAsmcomppath GetCablingAsmCompPath() const { return m_stuCablingAsmCompPath; }
	void SetCablingAsmCompPath(const ProAsmcomppath &stuCablingAsmCompPath) { m_stuCablingAsmCompPath = stuCablingAsmCompPath; }

// ˽������
private:
	CIKSMDCRoutCabProjDataInf m_RoutCabProjDataInf;	// ������Ŀ������Ϣ

private:
	ProAssembly m_pCablingAsm;						// ����װ����
	ProAsmcomppath m_stuCablingAsmCompPath;			// ����װ�����װ��·��

// �����ļ�����
private:
	CString m_strConfig_DefaultConnEntryPortCSysName;
	CString m_strConfig_DefaultConnEntryPortType;
	double m_dConfig_DefaultConnEntryPortIntLength;
};

//===================================================================================================
