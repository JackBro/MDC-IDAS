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

public:
	// ���ݲ��ֲ�������������Ʋ���
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

// ˽������
private:
	CIKSMDCRoutCabProjDataInf m_RoutCabProjDataInf;	// ������Ŀ������Ϣ
};

//===================================================================================================
