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
	// ���²��ֲ���(�ӵ�ǰװ�����ȡ����)
	void UpdateLayoutParamFromCurAsm();

	// ���µ��²��ֲ���(�ӵ�ǰװ�����ȡ����)
	void UpdateCableLayoutParamFromCurAsm();
	// ���µ��²��ֲ�������ǰװ����
	void UpdateCableLayoutParamToCurAsm() const;

	// ���µ�����Ʋ���(�ӵ�ǰװ�����ȡ����)
	void UpdateCableDesignParamFromCurAsm();
	// ���µ�����Ʋ�������ǰװ����
	void UpdateCableDesignParamToCurAsm() const;

	// ���ݲ��ֲ�������������Ʋ���
	void CorrectCableDesignParamByLayoutParam();

// ����װ����
public:
	// ���²���װ���壨�ӵ�ǰװ�����л�ȡ����װ���壬��δ�ҵ�����д�����
	BOOL UpdateCablingAsm();

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
	// װ�䲢ָ����������
	BOOL AssemblyAndDesignateConnector(CBPDynamicArray<UINT> *parrFailedAsmConnIndex=NULL, ProAssembly pConnParentAsm=NULL, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL);
	// װ�䲢ָ����������
	BOOL AssemblyAndDesignateConnector(std::vector<IKSMDCConnector> &vecMDCConnector, CBPDynamicArray<UINT> &arrFailedAsmConnIndex, ProAssembly pConnParentAsm=NULL, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL);
	// ������������ܷ�װ��
	BOOL CheckConnectorAssembly(const std::vector<IKSMDCConnector> &vecMDCConnector, CBPDynamicArray<UINT> &arrLostCSysConnIndex, CBPDynamicArray<UINT> &arrFailedLoadMdlConnIndex, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL, CUnicodeString *pPrompt=NULL);
	// ���صĵ�������ģ��ģ��
	void LoadConnTemplateMdl();

	// ��ʼ��������������
	void InitConnectorParam(IKSConnectorParamInfo &stuConnParam);

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

	ProAsmcomppath GetCablingAsmCompPath() const { return m_stuCablingAsmCompPath; }
	ProAsmcomppath* GetCablingAsmCompPathPt() { return &m_stuCablingAsmCompPath; }
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
