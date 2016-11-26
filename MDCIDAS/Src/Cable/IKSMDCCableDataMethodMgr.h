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

public:
	// 根据布局参数修正电缆设计参数
	void CorrectCableDesignParamByLayoutParam();

protected:

public:
	const CIKSMDCRoutCabProjDataInf* GetRoutCabProjDataInfPt() const { return &m_RoutCabProjDataInf; }
	const CIKSMDCRoutCabProjDataInf& GetRoutCabProjDataInf() const { return m_RoutCabProjDataInf; }
	void SetRoutCabProjDataInf(const CIKSMDCRoutCabProjDataInf& RoutCabProjDataInf) { m_RoutCabProjDataInf = RoutCabProjDataInf;}

	const IKSMDCCableLayoutParam& GetCableLayoutParam() const { return m_RoutCabProjDataInf.m_CableLayoutParam; }
	void SetCableLayoutParam(const IKSMDCCableLayoutParam& CableLayoutParam) { m_RoutCabProjDataInf.m_CableLayoutParam = CableLayoutParam;}

	const IKSMDCCableDesignParam& GetCableDesignParam() const { return m_RoutCabProjDataInf.m_CableDesignParam; }
	void SetCableDesignParam(const IKSMDCCableDesignParam& CableDesignParam) { m_RoutCabProjDataInf.m_CableDesignParam = CableDesignParam;}

// 私有数据
private:
	CIKSMDCRoutCabProjDataInf m_RoutCabProjDataInf;	// 布线项目数据信息
};

//===================================================================================================
