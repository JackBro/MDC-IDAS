//===================================================================================================
// File:
//		IKSMDCCableDataMethodMgr.cpp
// Summary:
//		΢ģ��������ݷ����Ĺ�����
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
// ȫ�ֱ���


//===================================================================================================
// ��������

//===================================================================================================
// �ṹ�嶨��

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

// ���²��ֲ���(�ӵ�ǰװ�����ȡ����)
void CIKSMDCCableDataMethodMgr::UpdateLayoutParamFromCurAsm()
{

}

// ���µ��²��ֲ���(�ӵ�ǰװ�����ȡ����)
void CIKSMDCCableDataMethodMgr::UpdateCableLayoutParamFromCurAsm()
{
	m_RoutCabProjDataInf.m_CableLayoutParam;
}

// ���µ��²��ֲ�������ǰװ����
void CIKSMDCCableDataMethodMgr::UpdateCableLayoutParamToCurAsm() const
{
	m_RoutCabProjDataInf.m_CableLayoutParam;
}

// ���µ�����Ʋ���(�ӵ�ǰװ�����ȡ����)
void CIKSMDCCableDataMethodMgr::UpdateCableDesignParamFromCurAsm()
{
	m_RoutCabProjDataInf.m_CableDesignParam;
}

// ���µ�����Ʋ�������ǰװ����
void CIKSMDCCableDataMethodMgr::UpdateCableDesignParamToCurAsm() const
{
	m_RoutCabProjDataInf.m_CableDesignParam;
}

// ���ݲ��ֲ�������������Ʋ���
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
