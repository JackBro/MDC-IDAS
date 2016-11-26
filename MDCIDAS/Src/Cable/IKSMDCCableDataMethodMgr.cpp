//===================================================================================================
// File:
//		IKSMDCCableDataMethodMgr.cpp
// Summary:
//		微模块电缆数据方法的管理类
// Date:
//		2016-11-21
// Author:
//		WangShiping
//===================================================================================================

#include "stdafx.h"
#include "IKSMDCCableDataMethodMgr.h"
#include "IKSSmartCableDataMethodMgrAPI.h"

//===================================================================================================

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//===================================================================================================
// 全局变量


//===================================================================================================
// 常量定义

//===================================================================================================
// 结构体定义

//===================================================================================================

CIKSMDCCableDataMethodMgr::CIKSMDCCableDataMethodMgr()
{
}

CIKSMDCCableDataMethodMgr::~CIKSMDCCableDataMethodMgr()
{

}

BOOL CIKSMDCCableDataMethodMgr::Init()
{
	return TRUE;
}

void CIKSMDCCableDataMethodMgr::UnInit()
{
}

// 更新布局参数(从当前装配体获取参数)
void CIKSMDCCableDataMethodMgr::UpdateLayoutParamFromCurAsm()
{

}

// 更新电缆布局参数(从当前装配体获取参数)
void CIKSMDCCableDataMethodMgr::UpdateCableLayoutParamFromCurAsm()
{
	m_RoutCabProjDataInf.m_CableLayoutParam;
}

// 更新电缆布局参数至当前装配体
void CIKSMDCCableDataMethodMgr::UpdateCableLayoutParamToCurAsm() const
{
	m_RoutCabProjDataInf.m_CableLayoutParam;
}

// 更新电缆设计参数(从当前装配体获取参数)
void CIKSMDCCableDataMethodMgr::UpdateCableDesignParamFromCurAsm()
{
	m_RoutCabProjDataInf.m_CableDesignParam;
}

// 更新电缆设计参数至当前装配体
void CIKSMDCCableDataMethodMgr::UpdateCableDesignParamToCurAsm() const
{
	m_RoutCabProjDataInf.m_CableDesignParam;
}

// 根据布局参数修正电缆设计参数
void CIKSMDCCableDataMethodMgr::CorrectCableDesignParamByLayoutParam()
{
	m_RoutCabProjDataInf.m_CableDesignParam.stuIT.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuTAC.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuBAT.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuHVDC.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuUPS.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuITPDRH.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuITPDRU.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuFC.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuZM.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuMJ.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuJJAN.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuGK.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuJDX.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuWX.bValid;
}

//===================================================================================================
