//===================================================================================================
// Summary:
//		电缆基础数据定义
// Date:
//		2016-11-21
// Author:
//		
//===================================================================================================

#include "stdafx.h"
#include "IKSMDCCableDataDef.h"

//===================================================================================================

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//===================================================================================================
// 电缆数据定义

CIKSMDCCable::CIKSMDCCable()
{
	m_strName = L"";
	m_strCabConnRefDes1 = L"";
	m_strCabConnRefDes2 = L"";

	m_stuProeCable.owner = NULL;
	m_stuProeCable.id = -1;
	m_uCurAsmHarnCableIndex = UINT(-1);
}

CIKSMDCCable::CIKSMDCCable(const CIKSMDCCable &input)
{
	m_strName = input.m_strName;
	m_strCabConnRefDes1 = input.m_strCabConnRefDes1;
	m_strCabConnRefDes2 = input.m_strCabConnRefDes2;
	m_vecCabMidPos = input.m_vecCabMidPos;

	m_stuProeCable = input.m_stuProeCable;
	m_uCurAsmHarnCableIndex = input.m_uCurAsmHarnCableIndex;
}

CIKSMDCCable::~CIKSMDCCable()
{
}

CIKSMDCCable& CIKSMDCCable::operator=(const CIKSMDCCable &input)
{
	if (&input == this)
		return *this;
	m_strName = input.m_strName;
	m_strCabConnRefDes1 = input.m_strCabConnRefDes1;
	m_strCabConnRefDes2 = input.m_strCabConnRefDes2;
	m_vecCabMidPos = input.m_vecCabMidPos;

	m_stuProeCable = input.m_stuProeCable;
	m_uCurAsmHarnCableIndex = input.m_uCurAsmHarnCableIndex;
	return *this;
}

// 清空数据
void CIKSMDCCable::Clear()
{
	m_strName = L"";
	m_strCabConnRefDes1 = L"";
	m_strCabConnRefDes2 = L"";
	m_vecCabMidPos.clear();

	m_stuProeCable.owner = NULL;
	m_stuProeCable.id = -1;
	m_uCurAsmHarnCableIndex = UINT(-1);
}

CIKSMDCCableIT::CIKSMDCCableIT()
{
}

CIKSMDCCableIT::CIKSMDCCableIT(const CIKSMDCCableIT &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableIT::~CIKSMDCCableIT()
{
}

CIKSMDCCableIT& CIKSMDCCableIT::operator=(const CIKSMDCCableIT &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableIT::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableTAC::CIKSMDCCableTAC()
{
}

CIKSMDCCableTAC::CIKSMDCCableTAC(const CIKSMDCCableTAC &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableTAC::~CIKSMDCCableTAC()
{
}

CIKSMDCCableTAC& CIKSMDCCableTAC::operator=(const CIKSMDCCableTAC &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableTAC::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableBAT::CIKSMDCCableBAT()
{
}

CIKSMDCCableBAT::CIKSMDCCableBAT(const CIKSMDCCableBAT &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableBAT::~CIKSMDCCableBAT()
{
}

CIKSMDCCableBAT& CIKSMDCCableBAT::operator=(const CIKSMDCCableBAT &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableBAT::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableHVDC::CIKSMDCCableHVDC()
{
}

CIKSMDCCableHVDC::CIKSMDCCableHVDC(const CIKSMDCCableHVDC &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableHVDC::~CIKSMDCCableHVDC()
{
}

CIKSMDCCableHVDC& CIKSMDCCableHVDC::operator=(const CIKSMDCCableHVDC &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableHVDC::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableUPS::CIKSMDCCableUPS()
{
}

CIKSMDCCableUPS::CIKSMDCCableUPS(const CIKSMDCCableUPS &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableUPS::~CIKSMDCCableUPS()
{
}

CIKSMDCCableUPS& CIKSMDCCableUPS::operator=(const CIKSMDCCableUPS &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableUPS::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableITPDRH::CIKSMDCCableITPDRH()
{
}

CIKSMDCCableITPDRH::CIKSMDCCableITPDRH(const CIKSMDCCableITPDRH &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableITPDRH::~CIKSMDCCableITPDRH()
{
}

CIKSMDCCableITPDRH& CIKSMDCCableITPDRH::operator=(const CIKSMDCCableITPDRH &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableITPDRH::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableITPDRU::CIKSMDCCableITPDRU()
{
}

CIKSMDCCableITPDRU::CIKSMDCCableITPDRU(const CIKSMDCCableITPDRU &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableITPDRU::~CIKSMDCCableITPDRU()
{
}

CIKSMDCCableITPDRU& CIKSMDCCableITPDRU::operator=(const CIKSMDCCableITPDRU &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableITPDRU::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableFC::CIKSMDCCableFC()
{
}

CIKSMDCCableFC::CIKSMDCCableFC(const CIKSMDCCableFC &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableFC::~CIKSMDCCableFC()
{
}

CIKSMDCCableFC& CIKSMDCCableFC::operator=(const CIKSMDCCableFC &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableFC::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableZM::CIKSMDCCableZM()
{
}

CIKSMDCCableZM::CIKSMDCCableZM(const CIKSMDCCableZM &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableZM::~CIKSMDCCableZM()
{
}

CIKSMDCCableZM& CIKSMDCCableZM::operator=(const CIKSMDCCableZM &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableZM::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableMJ::CIKSMDCCableMJ()
{
}

CIKSMDCCableMJ::CIKSMDCCableMJ(const CIKSMDCCableMJ &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableMJ::~CIKSMDCCableMJ()
{
}

CIKSMDCCableMJ& CIKSMDCCableMJ::operator=(const CIKSMDCCableMJ &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableMJ::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableJJAN::CIKSMDCCableJJAN()
{
}

CIKSMDCCableJJAN::CIKSMDCCableJJAN(const CIKSMDCCableJJAN &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableJJAN::~CIKSMDCCableJJAN()
{
}

CIKSMDCCableJJAN& CIKSMDCCableJJAN::operator=(const CIKSMDCCableJJAN &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableJJAN::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableGK::CIKSMDCCableGK()
{
}

CIKSMDCCableGK::CIKSMDCCableGK(const CIKSMDCCableGK &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableGK::~CIKSMDCCableGK()
{
}

CIKSMDCCableGK& CIKSMDCCableGK::operator=(const CIKSMDCCableGK &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableGK::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableJDX::CIKSMDCCableJDX()
{
}

CIKSMDCCableJDX::CIKSMDCCableJDX(const CIKSMDCCableJDX &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableJDX::~CIKSMDCCableJDX()
{
}

CIKSMDCCableJDX& CIKSMDCCableJDX::operator=(const CIKSMDCCableJDX &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableJDX::Clear()
{
	CIKSMDCCable::Clear();
}

CIKSMDCCableWX::CIKSMDCCableWX()
{
}

CIKSMDCCableWX::CIKSMDCCableWX(const CIKSMDCCableWX &input) : CIKSMDCCable(input)
{
}

CIKSMDCCableWX::~CIKSMDCCableWX()
{
}

CIKSMDCCableWX& CIKSMDCCableWX::operator=(const CIKSMDCCableWX &input)
{
	if (&input == this)
		return *this;
	CIKSMDCCable::operator=(input);

	return *this;
}

// 清空数据
void CIKSMDCCableWX::Clear()
{
	CIKSMDCCable::Clear();
}

//===================================================================================================
// 线束数据定义

CIKSMDCHarness::CIKSMDCHarness()
{
	m_strName = L"";
}

CIKSMDCHarness::CIKSMDCHarness(const CIKSMDCHarness &input)
{
	m_strName = input.m_strName;
	m_stuSpool = input.m_stuSpool;
	m_stuHarnDataInCurAsm = input.m_stuHarnDataInCurAsm;
}

CIKSMDCHarness::~CIKSMDCHarness()
{
}

CIKSMDCHarness& CIKSMDCHarness::operator=(const CIKSMDCHarness &input)
{
	if (&input == this)
		return *this;
	m_strName = input.m_strName;
	m_stuSpool = input.m_stuSpool;
	m_stuHarnDataInCurAsm = input.m_stuHarnDataInCurAsm;
	return *this;
}

// 清空数据
void CIKSMDCHarness::Clear()
{
	m_strName = L"";

	m_stuSpool.Clear();
	m_stuHarnDataInCurAsm.Clear();
}

BOOL CIKSMDCHarness::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	if (bClearInputVec)
		vecCablePt.clear();
	return TRUE;
}

CIKSMDCHarnessIT::CIKSMDCHarnessIT()
{
}

CIKSMDCHarnessIT::CIKSMDCHarnessIT(const CIKSMDCHarnessIT &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessIT::~CIKSMDCHarnessIT()
{
}

CIKSMDCHarnessIT& CIKSMDCHarnessIT::operator=(const CIKSMDCHarnessIT &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessIT::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessIT::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessTAC::CIKSMDCHarnessTAC()
{
}

CIKSMDCHarnessTAC::CIKSMDCHarnessTAC(const CIKSMDCHarnessTAC &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessTAC::~CIKSMDCHarnessTAC()
{
}

CIKSMDCHarnessTAC& CIKSMDCHarnessTAC::operator=(const CIKSMDCHarnessTAC &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessTAC::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessTAC::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessBAT::CIKSMDCHarnessBAT()
{
}

CIKSMDCHarnessBAT::CIKSMDCHarnessBAT(const CIKSMDCHarnessBAT &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessBAT::~CIKSMDCHarnessBAT()
{
}

CIKSMDCHarnessBAT& CIKSMDCHarnessBAT::operator=(const CIKSMDCHarnessBAT &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessBAT::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessBAT::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessHVDC::CIKSMDCHarnessHVDC()
{
}

CIKSMDCHarnessHVDC::CIKSMDCHarnessHVDC(const CIKSMDCHarnessHVDC &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessHVDC::~CIKSMDCHarnessHVDC()
{
}

CIKSMDCHarnessHVDC& CIKSMDCHarnessHVDC::operator=(const CIKSMDCHarnessHVDC &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessHVDC::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessHVDC::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessUPS::CIKSMDCHarnessUPS()
{
}

CIKSMDCHarnessUPS::CIKSMDCHarnessUPS(const CIKSMDCHarnessUPS &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessUPS::~CIKSMDCHarnessUPS()
{
}

CIKSMDCHarnessUPS& CIKSMDCHarnessUPS::operator=(const CIKSMDCHarnessUPS &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessUPS::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessUPS::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessITPDRH::CIKSMDCHarnessITPDRH()
{
}

CIKSMDCHarnessITPDRH::CIKSMDCHarnessITPDRH(const CIKSMDCHarnessITPDRH &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessITPDRH::~CIKSMDCHarnessITPDRH()
{
}

CIKSMDCHarnessITPDRH& CIKSMDCHarnessITPDRH::operator=(const CIKSMDCHarnessITPDRH &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessITPDRH::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessITPDRH::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessITPDRU::CIKSMDCHarnessITPDRU()
{
}

CIKSMDCHarnessITPDRU::CIKSMDCHarnessITPDRU(const CIKSMDCHarnessITPDRU &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessITPDRU::~CIKSMDCHarnessITPDRU()
{
}

CIKSMDCHarnessITPDRU& CIKSMDCHarnessITPDRU::operator=(const CIKSMDCHarnessITPDRU &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessITPDRU::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessITPDRU::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessFC::CIKSMDCHarnessFC()
{
}

CIKSMDCHarnessFC::CIKSMDCHarnessFC(const CIKSMDCHarnessFC &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessFC::~CIKSMDCHarnessFC()
{
}

CIKSMDCHarnessFC& CIKSMDCHarnessFC::operator=(const CIKSMDCHarnessFC &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessFC::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessFC::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessZM::CIKSMDCHarnessZM()
{
}

CIKSMDCHarnessZM::CIKSMDCHarnessZM(const CIKSMDCHarnessZM &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessZM::~CIKSMDCHarnessZM()
{
}

CIKSMDCHarnessZM& CIKSMDCHarnessZM::operator=(const CIKSMDCHarnessZM &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessZM::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessZM::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessMJ::CIKSMDCHarnessMJ()
{
}

CIKSMDCHarnessMJ::CIKSMDCHarnessMJ(const CIKSMDCHarnessMJ &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessMJ::~CIKSMDCHarnessMJ()
{
}

CIKSMDCHarnessMJ& CIKSMDCHarnessMJ::operator=(const CIKSMDCHarnessMJ &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessMJ::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessMJ::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessJJAN::CIKSMDCHarnessJJAN()
{
}

CIKSMDCHarnessJJAN::CIKSMDCHarnessJJAN(const CIKSMDCHarnessJJAN &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessJJAN::~CIKSMDCHarnessJJAN()
{
}

CIKSMDCHarnessJJAN& CIKSMDCHarnessJJAN::operator=(const CIKSMDCHarnessJJAN &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessJJAN::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessJJAN::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessGK::CIKSMDCHarnessGK()
{
}

CIKSMDCHarnessGK::CIKSMDCHarnessGK(const CIKSMDCHarnessGK &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessGK::~CIKSMDCHarnessGK()
{
}

CIKSMDCHarnessGK& CIKSMDCHarnessGK::operator=(const CIKSMDCHarnessGK &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessGK::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessGK::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessJDX::CIKSMDCHarnessJDX()
{
}

CIKSMDCHarnessJDX::CIKSMDCHarnessJDX(const CIKSMDCHarnessJDX &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessJDX::~CIKSMDCHarnessJDX()
{
}

CIKSMDCHarnessJDX& CIKSMDCHarnessJDX::operator=(const CIKSMDCHarnessJDX &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessJDX::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessJDX::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

CIKSMDCHarnessWX::CIKSMDCHarnessWX()
{
}

CIKSMDCHarnessWX::CIKSMDCHarnessWX(const CIKSMDCHarnessWX &input) : CIKSMDCHarness(input)
{
	m_vecCable = input.m_vecCable;
}

CIKSMDCHarnessWX::~CIKSMDCHarnessWX()
{
}

CIKSMDCHarnessWX& CIKSMDCHarnessWX::operator=(const CIKSMDCHarnessWX &input)
{
	if (&input == this)
		return *this;
	CIKSMDCHarness::operator=(input);
	m_vecCable = input.m_vecCable;

	return *this;
}

// 清空数据
void CIKSMDCHarnessWX::Clear()
{
	CIKSMDCHarness::Clear();

	m_vecCable.clear();
}

BOOL CIKSMDCHarnessWX::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCHarness::GetCablePt(vecCablePt, bClearInputVec);

	UINT uCurSize = UINT(vecCablePt.size());
	vecCablePt.resize(uCurSize + m_vecCable.size());
	for (UINT i=0; i<m_vecCable.size(); i++)
		vecCablePt[uCurSize + i] = (CIKSMDCCable*)(&(m_vecCable[i]));

	return TRUE;
}

//===================================================================================================
// 布线项目线束数据定义

CIKSMDCRoutCabProjHarnessData::CIKSMDCRoutCabProjHarnessData()
{
}

CIKSMDCRoutCabProjHarnessData::CIKSMDCRoutCabProjHarnessData(const CIKSMDCRoutCabProjHarnessData &input)
{
	input;
}

CIKSMDCRoutCabProjHarnessData::~CIKSMDCRoutCabProjHarnessData()
{
}

CIKSMDCRoutCabProjHarnessData& CIKSMDCRoutCabProjHarnessData::operator=(const CIKSMDCRoutCabProjHarnessData &input)
{
	if (&input == this)
		return *this;
	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessData::Clear()
{

}

// 获取项目内所有线束的基类指针
BOOL CIKSMDCRoutCabProjHarnessData::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	if (bClearInputVec)
		vecHarnessPt.clear();
	return TRUE;
}

BOOL CIKSMDCRoutCabProjHarnessData::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec/*=FALSE*/) const
{
	if (bClearInputVec)
		vecCablePt.clear();

	std::vector<CIKSMDCHarness*> vecHarnessPt;
	GetHarnessPt(vecHarnessPt, FALSE);

	for (UINT i=0; i<vecHarnessPt.size(); i++)
		vecHarnessPt[i]->GetCablePt(vecCablePt, FALSE);
	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataIT::CIKSMDCRoutCabProjHarnessDataIT()
{
}

CIKSMDCRoutCabProjHarnessDataIT::CIKSMDCRoutCabProjHarnessDataIT(const CIKSMDCRoutCabProjHarnessDataIT &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataIT::~CIKSMDCRoutCabProjHarnessDataIT()
{
}

CIKSMDCRoutCabProjHarnessDataIT& CIKSMDCRoutCabProjHarnessDataIT::operator=(const CIKSMDCRoutCabProjHarnessDataIT &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataIT::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataIT::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataTAC::CIKSMDCRoutCabProjHarnessDataTAC()
{
}

CIKSMDCRoutCabProjHarnessDataTAC::CIKSMDCRoutCabProjHarnessDataTAC(const CIKSMDCRoutCabProjHarnessDataTAC &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataTAC::~CIKSMDCRoutCabProjHarnessDataTAC()
{
}

CIKSMDCRoutCabProjHarnessDataTAC& CIKSMDCRoutCabProjHarnessDataTAC::operator=(const CIKSMDCRoutCabProjHarnessDataTAC &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataTAC::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataTAC::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataBAT::CIKSMDCRoutCabProjHarnessDataBAT()
{
}

CIKSMDCRoutCabProjHarnessDataBAT::CIKSMDCRoutCabProjHarnessDataBAT(const CIKSMDCRoutCabProjHarnessDataBAT &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataBAT::~CIKSMDCRoutCabProjHarnessDataBAT()
{
}

CIKSMDCRoutCabProjHarnessDataBAT& CIKSMDCRoutCabProjHarnessDataBAT::operator=(const CIKSMDCRoutCabProjHarnessDataBAT &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataBAT::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataBAT::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataHVDC::CIKSMDCRoutCabProjHarnessDataHVDC()
{
}

CIKSMDCRoutCabProjHarnessDataHVDC::CIKSMDCRoutCabProjHarnessDataHVDC(const CIKSMDCRoutCabProjHarnessDataHVDC &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataHVDC::~CIKSMDCRoutCabProjHarnessDataHVDC()
{
}

CIKSMDCRoutCabProjHarnessDataHVDC& CIKSMDCRoutCabProjHarnessDataHVDC::operator=(const CIKSMDCRoutCabProjHarnessDataHVDC &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataHVDC::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataHVDC::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataUPS::CIKSMDCRoutCabProjHarnessDataUPS()
{
}

CIKSMDCRoutCabProjHarnessDataUPS::CIKSMDCRoutCabProjHarnessDataUPS(const CIKSMDCRoutCabProjHarnessDataUPS &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataUPS::~CIKSMDCRoutCabProjHarnessDataUPS()
{
}

CIKSMDCRoutCabProjHarnessDataUPS& CIKSMDCRoutCabProjHarnessDataUPS::operator=(const CIKSMDCRoutCabProjHarnessDataUPS &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataUPS::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataUPS::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataITPDRH::CIKSMDCRoutCabProjHarnessDataITPDRH()
{
}

CIKSMDCRoutCabProjHarnessDataITPDRH::CIKSMDCRoutCabProjHarnessDataITPDRH(const CIKSMDCRoutCabProjHarnessDataITPDRH &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataITPDRH::~CIKSMDCRoutCabProjHarnessDataITPDRH()
{
}

CIKSMDCRoutCabProjHarnessDataITPDRH& CIKSMDCRoutCabProjHarnessDataITPDRH::operator=(const CIKSMDCRoutCabProjHarnessDataITPDRH &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataITPDRH::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataITPDRH::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataITPDRU::CIKSMDCRoutCabProjHarnessDataITPDRU()
{
}

CIKSMDCRoutCabProjHarnessDataITPDRU::CIKSMDCRoutCabProjHarnessDataITPDRU(const CIKSMDCRoutCabProjHarnessDataITPDRU &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataITPDRU::~CIKSMDCRoutCabProjHarnessDataITPDRU()
{
}

CIKSMDCRoutCabProjHarnessDataITPDRU& CIKSMDCRoutCabProjHarnessDataITPDRU::operator=(const CIKSMDCRoutCabProjHarnessDataITPDRU &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataITPDRU::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataITPDRU::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataFC::CIKSMDCRoutCabProjHarnessDataFC()
{
}

CIKSMDCRoutCabProjHarnessDataFC::CIKSMDCRoutCabProjHarnessDataFC(const CIKSMDCRoutCabProjHarnessDataFC &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataFC::~CIKSMDCRoutCabProjHarnessDataFC()
{
}

CIKSMDCRoutCabProjHarnessDataFC& CIKSMDCRoutCabProjHarnessDataFC::operator=(const CIKSMDCRoutCabProjHarnessDataFC &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataFC::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataFC::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataZM::CIKSMDCRoutCabProjHarnessDataZM()
{
}

CIKSMDCRoutCabProjHarnessDataZM::CIKSMDCRoutCabProjHarnessDataZM(const CIKSMDCRoutCabProjHarnessDataZM &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataZM::~CIKSMDCRoutCabProjHarnessDataZM()
{
}

CIKSMDCRoutCabProjHarnessDataZM& CIKSMDCRoutCabProjHarnessDataZM::operator=(const CIKSMDCRoutCabProjHarnessDataZM &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataZM::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataZM::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataMJ::CIKSMDCRoutCabProjHarnessDataMJ()
{
}

CIKSMDCRoutCabProjHarnessDataMJ::CIKSMDCRoutCabProjHarnessDataMJ(const CIKSMDCRoutCabProjHarnessDataMJ &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataMJ::~CIKSMDCRoutCabProjHarnessDataMJ()
{
}

CIKSMDCRoutCabProjHarnessDataMJ& CIKSMDCRoutCabProjHarnessDataMJ::operator=(const CIKSMDCRoutCabProjHarnessDataMJ &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataMJ::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataMJ::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataJJAN::CIKSMDCRoutCabProjHarnessDataJJAN()
{
}

CIKSMDCRoutCabProjHarnessDataJJAN::CIKSMDCRoutCabProjHarnessDataJJAN(const CIKSMDCRoutCabProjHarnessDataJJAN &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataJJAN::~CIKSMDCRoutCabProjHarnessDataJJAN()
{
}

CIKSMDCRoutCabProjHarnessDataJJAN& CIKSMDCRoutCabProjHarnessDataJJAN::operator=(const CIKSMDCRoutCabProjHarnessDataJJAN &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataJJAN::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataJJAN::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataGK::CIKSMDCRoutCabProjHarnessDataGK()
{
}

CIKSMDCRoutCabProjHarnessDataGK::CIKSMDCRoutCabProjHarnessDataGK(const CIKSMDCRoutCabProjHarnessDataGK &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataGK::~CIKSMDCRoutCabProjHarnessDataGK()
{
}

CIKSMDCRoutCabProjHarnessDataGK& CIKSMDCRoutCabProjHarnessDataGK::operator=(const CIKSMDCRoutCabProjHarnessDataGK &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataGK::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataGK::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataJDX::CIKSMDCRoutCabProjHarnessDataJDX()
{
}

CIKSMDCRoutCabProjHarnessDataJDX::CIKSMDCRoutCabProjHarnessDataJDX(const CIKSMDCRoutCabProjHarnessDataJDX &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataJDX::~CIKSMDCRoutCabProjHarnessDataJDX()
{
}

CIKSMDCRoutCabProjHarnessDataJDX& CIKSMDCRoutCabProjHarnessDataJDX::operator=(const CIKSMDCRoutCabProjHarnessDataJDX &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataJDX::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataJDX::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

CIKSMDCRoutCabProjHarnessDataWX::CIKSMDCRoutCabProjHarnessDataWX()
{
}

CIKSMDCRoutCabProjHarnessDataWX::CIKSMDCRoutCabProjHarnessDataWX(const CIKSMDCRoutCabProjHarnessDataWX &input) : CIKSMDCRoutCabProjHarnessData(input)
{
	m_vecHarness = input.m_vecHarness;
}

CIKSMDCRoutCabProjHarnessDataWX::~CIKSMDCRoutCabProjHarnessDataWX()
{
}

CIKSMDCRoutCabProjHarnessDataWX& CIKSMDCRoutCabProjHarnessDataWX::operator=(const CIKSMDCRoutCabProjHarnessDataWX &input)
{
	if (&input == this)
		return *this;
	CIKSMDCRoutCabProjHarnessData::operator=(input);
	m_vecHarness = input.m_vecHarness;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjHarnessDataWX::Clear()
{
	CIKSMDCRoutCabProjHarnessData::Clear();

	m_vecHarness.clear();
}

BOOL CIKSMDCRoutCabProjHarnessDataWX::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec/*=FALSE*/) const
{
	CIKSMDCRoutCabProjHarnessData::GetHarnessPt(vecHarnessPt, bClearInputVec);

	UINT uCurSize = UINT(vecHarnessPt.size());
	vecHarnessPt.resize(uCurSize + m_vecHarness.size());
	for (UINT i=0; i<m_vecHarness.size(); i++)
		vecHarnessPt[uCurSize + i] = (CIKSMDCHarness*)(&(m_vecHarness[i]));

	return TRUE;
}

//===================================================================================================
// 布线项目数据信息

CIKSMDCRoutCabProjDataInf::CIKSMDCRoutCabProjDataInf()
{
	Clear();
}

CIKSMDCRoutCabProjDataInf::CIKSMDCRoutCabProjDataInf(const CIKSMDCRoutCabProjDataInf &input)
{
	m_CableLayoutParam = input.m_CableLayoutParam;
	m_CableDesignParam = input.m_CableDesignParam;

	m_HarnIT = input.m_HarnIT;
	m_HarnTAC = input.m_HarnTAC;
	m_HarnBAT = input.m_HarnBAT;
	m_HarnHVDC = input.m_HarnHVDC;
	m_HarnUPS = input.m_HarnUPS;
	m_HarnITPDRH = input.m_HarnITPDRH;
	m_HarnITPDRU = input.m_HarnITPDRU;
	m_HarnFC = input.m_HarnFC;
	m_HarnZM = input.m_HarnZM;
	m_HarnMJ = input.m_HarnMJ;
	m_HarnJJAN = input.m_HarnJJAN;
	m_HarnGK = input.m_HarnGK;
	m_HarnJDX = input.m_HarnJDX;
	m_HarnWX = input.m_HarnWX;
}

CIKSMDCRoutCabProjDataInf::~CIKSMDCRoutCabProjDataInf()
{
}

CIKSMDCRoutCabProjDataInf& CIKSMDCRoutCabProjDataInf::operator=(const CIKSMDCRoutCabProjDataInf &input)
{
	if (&input == this)
		return *this;

	m_CableLayoutParam = input.m_CableLayoutParam;
	m_CableDesignParam = input.m_CableDesignParam;

	m_HarnIT = input.m_HarnIT;
	m_HarnTAC = input.m_HarnTAC;
	m_HarnBAT = input.m_HarnBAT;
	m_HarnHVDC = input.m_HarnHVDC;
	m_HarnUPS = input.m_HarnUPS;
	m_HarnITPDRH = input.m_HarnITPDRH;
	m_HarnITPDRU = input.m_HarnITPDRU;
	m_HarnFC = input.m_HarnFC;
	m_HarnZM = input.m_HarnZM;
	m_HarnMJ = input.m_HarnMJ;
	m_HarnJJAN = input.m_HarnJJAN;
	m_HarnGK = input.m_HarnGK;
	m_HarnJDX = input.m_HarnJDX;
	m_HarnWX = input.m_HarnWX;

	return *this;
}

// 清空数据
void CIKSMDCRoutCabProjDataInf::Clear()
{
	m_CableLayoutParam.Clear();
	m_CableLayoutParam.Clear();

	m_HarnIT.Clear();
	m_HarnTAC.Clear();
	m_HarnBAT.Clear();
	m_HarnHVDC.Clear();
	m_HarnUPS.Clear();
	m_HarnITPDRH.Clear();
	m_HarnITPDRU.Clear();
	m_HarnFC.Clear();
	m_HarnZM.Clear();
	m_HarnMJ.Clear();
	m_HarnJJAN.Clear();
	m_HarnGK.Clear();
	m_HarnJDX.Clear();
	m_HarnWX.Clear();
}

// 获取项目内所有线束的基类指针
BOOL CIKSMDCRoutCabProjDataInf::GetRoutCabProjHarnessDataPt(std::vector<CIKSMDCRoutCabProjHarnessData*> &vecRoutCabProjHarnDataPt) const
{
	vecRoutCabProjHarnDataPt.resize(14);

	UINT uIndex = 0;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnIT);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnTAC);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnBAT);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnHVDC);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnUPS);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnITPDRH);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnITPDRU);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnFC);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnZM);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnMJ);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnJJAN);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnGK);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnJDX);
	uIndex++;
	vecRoutCabProjHarnDataPt[uIndex] = (CIKSMDCRoutCabProjHarnessData*)(&m_HarnWX);
	uIndex++;

	return TRUE;
}

// 获取项目内所有线束的基类指针
BOOL CIKSMDCRoutCabProjDataInf::GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt) const
{
	vecHarnessPt.clear();

	std::vector<CIKSMDCRoutCabProjHarnessData*> vecRoutCabProjHarnDataPt;
	if (!GetRoutCabProjHarnessDataPt(vecRoutCabProjHarnDataPt))
		return FALSE;

	for (UINT i=0; i<vecRoutCabProjHarnDataPt.size(); i++)
	{
		vecRoutCabProjHarnDataPt[i]->GetHarnessPt(vecHarnessPt, FALSE);
	}

	return TRUE;
}

// 获取项目内所有电缆的基类指针
BOOL CIKSMDCRoutCabProjDataInf::GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt) const
{
	vecCablePt.clear();

	std::vector<CIKSMDCRoutCabProjHarnessData*> vecRoutCabProjHarnDataPt;
	if (!GetRoutCabProjHarnessDataPt(vecRoutCabProjHarnDataPt))
		return FALSE;

	for (UINT i=0; i<vecRoutCabProjHarnDataPt.size(); i++)
	{
		vecRoutCabProjHarnDataPt[i]->GetCablePt(vecCablePt, FALSE);
	}

	return TRUE;
}

//===================================================================================================
// 其他数据定义
