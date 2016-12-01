//===================================================================================================
// File:
//		IKSMDCCableDataMethodMgr.h
// Summary:
//		微模块电缆数据方法的管理类
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
	// 加载选项数据
	void LoadConfig();

// 电缆布局参数和电缆设计参数
public:
	// 更新布局参数(从当前装配体获取参数)
	void UpdateLayoutParamFromCurAsm();

	// 更新电缆布局参数(从当前装配体获取参数)
	void UpdateCableLayoutParamFromCurAsm();
	// 更新电缆布局参数至当前装配体
	void UpdateCableLayoutParamToCurAsm() const;

	// 更新电缆设计参数(从当前装配体获取参数)
	void UpdateCableDesignParamFromCurAsm();
	// 更新电缆设计参数至当前装配体
	void UpdateCableDesignParamToCurAsm() const;

	// 根据布局参数修正电缆设计参数
	void CorrectCableDesignParamByLayoutParam();

// 布线装配体
public:
	// 更新布线装配体（从当前装配体中获取布线装配体，若未找到则进行创建）
	BOOL UpdateCablingAsm();

// 布线装配体
protected:
	// 在当前装配体中创建布线装配体
	ProAssembly CreateCablingAsmInCurAsm(ProAsmcomppath *pCablingAsmCompPath=NULL);
	// 在当前装配体中获取布线装配体
	ProAssembly GetCablingAsmInCurAsm(ProAsmcomppath *pCablingAsmCompPath=NULL);

	// 通过装配体遍历子特征的过滤函数
	static ProError GetCablingAsmOfAssemblyFilter(ProFeature* pFeature, ProAppData pAppData);
	// 通过装配体遍历子特征的访问函数
	static ProError GetCablingAsmOfAssemblyVisit(ProFeature* pFeature, ProError status, ProAppData pAppData);
	// 检验输入特征是否有效
	static IKS_BOOL CheckFeatureValid(ProFeature* pFeature);

	// 设置缺省约束
	BOOL SetDefaultConstraint(ProAsmcomp *pAsmComp);

// 电连接器
public:
	// 装配并指定电连接器
	BOOL AssemblyAndDesignateConnector(CBPDynamicArray<UINT> *parrFailedAsmConnIndex=NULL, ProAssembly pConnParentAsm=NULL, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL);
	// 装配并指定电连接器
	BOOL AssemblyAndDesignateConnector(std::vector<IKSMDCConnector> &vecMDCConnector, CBPDynamicArray<UINT> &arrFailedAsmConnIndex, ProAssembly pConnParentAsm=NULL, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL);
	// 检验电连接器能否装配
	BOOL CheckConnectorAssembly(const std::vector<IKSMDCConnector> &vecMDCConnector, CBPDynamicArray<UINT> &arrLostCSysConnIndex, CBPDynamicArray<UINT> &arrFailedLoadMdlConnIndex, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL, CUnicodeString *pPrompt=NULL);
	// 加载的电连接器模板模型
	void LoadConnTemplateMdl();

	// 初始化电连接器参数
	void InitConnectorParam(IKSConnectorParamInfo &stuConnParam);

// 试验
public:
	// 试验
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

// 私有数据
private:
	CIKSMDCRoutCabProjDataInf m_RoutCabProjDataInf;	// 布线项目数据信息

private:
	ProAssembly m_pCablingAsm;						// 布线装配体
	ProAsmcomppath m_stuCablingAsmCompPath;			// 布线装配体的装配路径

// 配置文件数据
private:
	CString m_strConfig_DefaultConnEntryPortCSysName;
	CString m_strConfig_DefaultConnEntryPortType;
	double m_dConfig_DefaultConnEntryPortIntLength;
};

//===================================================================================================
