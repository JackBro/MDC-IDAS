//===================================================================================================
// Summary:
//		���»������ݶ���
// Date:
//		2016-11-21
// Author:
//		
//===================================================================================================

#pragma once
#include "CableConstantValue.h"
#include "SVGlobalTools.h"

#include "ConstantValue.h"
#include "IKSMDCCableConstantValue.h"

//===================================================================================================
// ��������

class CIKSMDCCable
{
public:
	CIKSMDCCable();
	CIKSMDCCable(const CIKSMDCCable &input);
	~CIKSMDCCable();

	CIKSMDCCable& operator=(const CIKSMDCCable &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_INVALID; }
	// �������
	virtual void Clear();

protected:

public:
	const CSVWString& GetName() const { return m_strName; }
	void SetName(const CSVWString& strName) { m_strName = strName; }

	const CSVWString& GetCabConnRefDes1() const { return m_strCabConnRefDes1; }
	void SetCabConnRefDes1(const CSVWString& strCabConnRefDes1) { m_strCabConnRefDes1 = strCabConnRefDes1; }

	const CSVWString& GetCabConnRefDes2() const { return m_strCabConnRefDes2; }
	void SetCabConnRefDes2(const CSVWString& strCabConnRefDes2) { m_strCabConnRefDes2 = strCabConnRefDes2; }

	const std::vector<SVBASEDOUBLE3>& GetCabMidPos() const { return m_vecCabMidPos; }
	void SetCabMidPos(const std::vector<SVBASEDOUBLE3>& vecCabMidPos) { m_vecCabMidPos = vecCabMidPos; }

	const ProCable& GetProeCable() const { return m_stuProeCable; }
	void SetProeCable(const ProCable& stuProeCable) { m_stuProeCable = stuProeCable; }

	UINT GetCurAsmHarnCableIndex() const { return m_uCurAsmHarnCableIndex; }
	void SetCurAsmHarnCableIndex(UINT uCurAsmHarnCableIndex) { m_uCurAsmHarnCableIndex = uCurAsmHarnCableIndex; }

private:
	CSVWString m_strName;				// ��������
	CSVWString m_strCabConnRefDes1;		// ������ʼ�����������߼�����(ָ������)(��һ������λ�ö�Ӧ�ĵ�������)
	CSVWString m_strCabConnRefDes2;		// ������ֹ�����������߼�����(ָ������)(���һ������λ�ö�Ӧ�ĵ�������)
	std::vector<SVBASEDOUBLE3> m_vecCabMidPos;		// �����м���λ��

	ProCable m_stuProeCable;			// ProE������
	UINT m_uCurAsmHarnCableIndex;		// ��ǰװ���������������еĵ�������
};

class CIKSMDCCableIT : public CIKSMDCCable
{
public:
	CIKSMDCCableIT();
	CIKSMDCCableIT(const CIKSMDCCableIT &input);
	~CIKSMDCCableIT();

	CIKSMDCCableIT& operator=(const CIKSMDCCableIT &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_IT; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableTAC : public CIKSMDCCable
{
public:
	CIKSMDCCableTAC();
	CIKSMDCCableTAC(const CIKSMDCCableTAC &input);
	~CIKSMDCCableTAC();

	CIKSMDCCableTAC& operator=(const CIKSMDCCableTAC &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_TAC; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableBAT : public CIKSMDCCable
{
public:
	CIKSMDCCableBAT();
	CIKSMDCCableBAT(const CIKSMDCCableBAT &input);
	~CIKSMDCCableBAT();

	CIKSMDCCableBAT& operator=(const CIKSMDCCableBAT &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_BAT; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableHVDC : public CIKSMDCCable
{
public:
	CIKSMDCCableHVDC();
	CIKSMDCCableHVDC(const CIKSMDCCableHVDC &input);
	~CIKSMDCCableHVDC();

	CIKSMDCCableHVDC& operator=(const CIKSMDCCableHVDC &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_HVDC; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableUPS : public CIKSMDCCable
{
public:
	CIKSMDCCableUPS();
	CIKSMDCCableUPS(const CIKSMDCCableUPS &input);
	~CIKSMDCCableUPS();

	CIKSMDCCableUPS& operator=(const CIKSMDCCableUPS &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_UPS; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableITPDRH : public CIKSMDCCable
{
public:
	CIKSMDCCableITPDRH();
	CIKSMDCCableITPDRH(const CIKSMDCCableITPDRH &input);
	~CIKSMDCCableITPDRH();

	CIKSMDCCableITPDRH& operator=(const CIKSMDCCableITPDRH &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_ITPDRH; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableITPDRU : public CIKSMDCCable
{
public:
	CIKSMDCCableITPDRU();
	CIKSMDCCableITPDRU(const CIKSMDCCableITPDRU &input);
	~CIKSMDCCableITPDRU();

	CIKSMDCCableITPDRU& operator=(const CIKSMDCCableITPDRU &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_ITPDRU; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableFC : public CIKSMDCCable
{
public:
	CIKSMDCCableFC();
	CIKSMDCCableFC(const CIKSMDCCableFC &input);
	~CIKSMDCCableFC();

	CIKSMDCCableFC& operator=(const CIKSMDCCableFC &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_FC; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableZM : public CIKSMDCCable
{
public:
	CIKSMDCCableZM();
	CIKSMDCCableZM(const CIKSMDCCableZM &input);
	~CIKSMDCCableZM();

	CIKSMDCCableZM& operator=(const CIKSMDCCableZM &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_ZM; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableMJ : public CIKSMDCCable
{
public:
	CIKSMDCCableMJ();
	CIKSMDCCableMJ(const CIKSMDCCableMJ &input);
	~CIKSMDCCableMJ();

	CIKSMDCCableMJ& operator=(const CIKSMDCCableMJ &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_MJ; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableJJAN : public CIKSMDCCable
{
public:
	CIKSMDCCableJJAN();
	CIKSMDCCableJJAN(const CIKSMDCCableJJAN &input);
	~CIKSMDCCableJJAN();

	CIKSMDCCableJJAN& operator=(const CIKSMDCCableJJAN &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_JJAN; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableGK : public CIKSMDCCable
{
public:
	CIKSMDCCableGK();
	CIKSMDCCableGK(const CIKSMDCCableGK &input);
	~CIKSMDCCableGK();

	CIKSMDCCableGK& operator=(const CIKSMDCCableGK &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_GK; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableJDX : public CIKSMDCCable
{
public:
	CIKSMDCCableJDX();
	CIKSMDCCableJDX(const CIKSMDCCableJDX &input);
	~CIKSMDCCableJDX();

	CIKSMDCCableJDX& operator=(const CIKSMDCCableJDX &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_JDX; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

class CIKSMDCCableWX : public CIKSMDCCable
{
public:
	CIKSMDCCableWX();
	CIKSMDCCableWX(const CIKSMDCCableWX &input);
	~CIKSMDCCableWX();

	CIKSMDCCableWX& operator=(const CIKSMDCCableWX &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_WX; }
	// �������
	virtual void Clear();

protected:

public:

private:
};

//===================================================================================================
// ��������

class CIKSMDCHarness
{
public:
	CIKSMDCHarness();
	CIKSMDCHarness(const CIKSMDCHarness &input);
	~CIKSMDCHarness();

	CIKSMDCHarness& operator=(const CIKSMDCHarness &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_INVALID; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const CSVWString& GetName() const { return m_strName; }
	void SetName(const CSVWString& strName) { m_strName = strName; }

	IKSSpool* GetSpoolPt() { return &m_stuSpool; }
	const IKSSpool* GetSpoolPt() const { return &m_stuSpool; }
	const IKSSpool& GetSpool() const { return m_stuSpool; }
	void SetSpool(const IKSSpool& stuSpool) { m_stuSpool = stuSpool; }

	IKSHarness* GetHarnDataInCurAsmPt() { return &m_stuHarnDataInCurAsm; }
	const IKSHarness* GetHarnDataInCurAsmPt() const { return &m_stuHarnDataInCurAsm; }
	const IKSHarness& GetHarnDataInCurAsm() const { return m_stuHarnDataInCurAsm; }
	void SetHarnDataInCurAsm(const IKSHarness& stuHarnDataInCurAsm) { m_stuHarnDataInCurAsm = stuHarnDataInCurAsm; }

private:
	CSVWString m_strName;				// ��������
	IKSSpool m_stuSpool;				// ����������

	IKSHarness m_stuHarnDataInCurAsm;	// ��ǰװ�����ڵ���������
};

class CIKSMDCHarnessIT : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessIT();
	CIKSMDCHarnessIT(const CIKSMDCHarnessIT &input);
	~CIKSMDCHarnessIT();

	CIKSMDCHarnessIT& operator=(const CIKSMDCHarnessIT &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_IT; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableIT>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableIT>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableIT *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableIT> m_vecCable;
};

class CIKSMDCHarnessTAC : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessTAC();
	CIKSMDCHarnessTAC(const CIKSMDCHarnessTAC &input);
	~CIKSMDCHarnessTAC();

	CIKSMDCHarnessTAC& operator=(const CIKSMDCHarnessTAC &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_TAC; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableTAC>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableTAC>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableTAC *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableTAC> m_vecCable;
};

class CIKSMDCHarnessBAT : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessBAT();
	CIKSMDCHarnessBAT(const CIKSMDCHarnessBAT &input);
	~CIKSMDCHarnessBAT();

	CIKSMDCHarnessBAT& operator=(const CIKSMDCHarnessBAT &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_BAT; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableBAT>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableBAT>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableBAT *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableBAT> m_vecCable;
};

class CIKSMDCHarnessHVDC : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessHVDC();
	CIKSMDCHarnessHVDC(const CIKSMDCHarnessHVDC &input);
	~CIKSMDCHarnessHVDC();

	CIKSMDCHarnessHVDC& operator=(const CIKSMDCHarnessHVDC &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_HVDC; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableHVDC>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableHVDC>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableHVDC *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableHVDC> m_vecCable;
};

class CIKSMDCHarnessUPS : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessUPS();
	CIKSMDCHarnessUPS(const CIKSMDCHarnessUPS &input);
	~CIKSMDCHarnessUPS();

	CIKSMDCHarnessUPS& operator=(const CIKSMDCHarnessUPS &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_UPS; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableUPS>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableUPS>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableUPS *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableUPS> m_vecCable;
};

class CIKSMDCHarnessITPDRH : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessITPDRH();
	CIKSMDCHarnessITPDRH(const CIKSMDCHarnessITPDRH &input);
	~CIKSMDCHarnessITPDRH();

	CIKSMDCHarnessITPDRH& operator=(const CIKSMDCHarnessITPDRH &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_ITPDRH; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableITPDRH>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableITPDRH>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableITPDRH *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableITPDRH> m_vecCable;
};

class CIKSMDCHarnessITPDRU : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessITPDRU();
	CIKSMDCHarnessITPDRU(const CIKSMDCHarnessITPDRU &input);
	~CIKSMDCHarnessITPDRU();

	CIKSMDCHarnessITPDRU& operator=(const CIKSMDCHarnessITPDRU &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_ITPDRU; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableITPDRU>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableITPDRU>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableITPDRU *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableITPDRU> m_vecCable;
};

class CIKSMDCHarnessFC : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessFC();
	CIKSMDCHarnessFC(const CIKSMDCHarnessFC &input);
	~CIKSMDCHarnessFC();

	CIKSMDCHarnessFC& operator=(const CIKSMDCHarnessFC &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_FC; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableFC>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableFC>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableFC *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableFC> m_vecCable;
};

class CIKSMDCHarnessZM : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessZM();
	CIKSMDCHarnessZM(const CIKSMDCHarnessZM &input);
	~CIKSMDCHarnessZM();

	CIKSMDCHarnessZM& operator=(const CIKSMDCHarnessZM &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_ZM; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableZM>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableZM>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableZM *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableZM> m_vecCable;
};

class CIKSMDCHarnessMJ : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessMJ();
	CIKSMDCHarnessMJ(const CIKSMDCHarnessMJ &input);
	~CIKSMDCHarnessMJ();

	CIKSMDCHarnessMJ& operator=(const CIKSMDCHarnessMJ &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_MJ; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableMJ>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableMJ>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableMJ *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableMJ> m_vecCable;
};

class CIKSMDCHarnessJJAN : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessJJAN();
	CIKSMDCHarnessJJAN(const CIKSMDCHarnessJJAN &input);
	~CIKSMDCHarnessJJAN();

	CIKSMDCHarnessJJAN& operator=(const CIKSMDCHarnessJJAN &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_JJAN; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableJJAN>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableJJAN>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableJJAN *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableJJAN> m_vecCable;
};

class CIKSMDCHarnessGK : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessGK();
	CIKSMDCHarnessGK(const CIKSMDCHarnessGK &input);
	~CIKSMDCHarnessGK();

	CIKSMDCHarnessGK& operator=(const CIKSMDCHarnessGK &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_GK; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableGK>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableGK>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableGK *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableGK> m_vecCable;
};

class CIKSMDCHarnessJDX : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessJDX();
	CIKSMDCHarnessJDX(const CIKSMDCHarnessJDX &input);
	~CIKSMDCHarnessJDX();

	CIKSMDCHarnessJDX& operator=(const CIKSMDCHarnessJDX &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_JDX; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableJDX>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableJDX>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableJDX *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableJDX> m_vecCable;
};

class CIKSMDCHarnessWX : public CIKSMDCHarness
{
public:
	CIKSMDCHarnessWX();
	CIKSMDCHarnessWX(const CIKSMDCHarnessWX &input);
	~CIKSMDCHarnessWX();

	CIKSMDCHarnessWX& operator=(const CIKSMDCHarnessWX &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_WX; }
	// �������
	virtual void Clear();

public:
	// ��ȡ�����ڵ��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCCableWX>& GetCable() const { return m_vecCable; }
	void SetCable(const std::vector<CIKSMDCCableWX>& vecCable) { m_vecCable = vecCable;}
	void ResizeCable(UINT uSize) { m_vecCable.resize(uSize); }
	UINT GetCableSize() const { return UINT(m_vecCable.size()); }
	CIKSMDCCableWX *GetCableByIndex(UINT uIndex)
	{
		if (uIndex >= GetCableSize())
			return NULL;
		return &(m_vecCable[uIndex]);
	}

private:
	std::vector<CIKSMDCCableWX> m_vecCable;
};

//===================================================================================================
// ������Ŀ��������

class CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessData();
	CIKSMDCRoutCabProjHarnessData(const CIKSMDCRoutCabProjHarnessData &input);
	~CIKSMDCRoutCabProjHarnessData();

	CIKSMDCRoutCabProjHarnessData& operator=(const CIKSMDCRoutCabProjHarnessData &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_INVALID; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;
	// ��ȡ��Ŀ�����е��µĻ���ָ��
	virtual BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt, BOOL bClearInputVec=FALSE) const;

protected:

public:

private:
};

class CIKSMDCRoutCabProjHarnessDataIT : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataIT();
	CIKSMDCRoutCabProjHarnessDataIT(const CIKSMDCRoutCabProjHarnessDataIT &input);
	~CIKSMDCRoutCabProjHarnessDataIT();

	CIKSMDCRoutCabProjHarnessDataIT& operator=(const CIKSMDCRoutCabProjHarnessDataIT &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_IT; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessIT>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessIT>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessIT *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessIT> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataTAC : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataTAC();
	CIKSMDCRoutCabProjHarnessDataTAC(const CIKSMDCRoutCabProjHarnessDataTAC &input);
	~CIKSMDCRoutCabProjHarnessDataTAC();

	CIKSMDCRoutCabProjHarnessDataTAC& operator=(const CIKSMDCRoutCabProjHarnessDataTAC &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_TAC; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessTAC>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessTAC>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessTAC *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessTAC> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataBAT : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataBAT();
	CIKSMDCRoutCabProjHarnessDataBAT(const CIKSMDCRoutCabProjHarnessDataBAT &input);
	~CIKSMDCRoutCabProjHarnessDataBAT();

	CIKSMDCRoutCabProjHarnessDataBAT& operator=(const CIKSMDCRoutCabProjHarnessDataBAT &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_BAT; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessBAT>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessBAT>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessBAT *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessBAT> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataHVDC : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataHVDC();
	CIKSMDCRoutCabProjHarnessDataHVDC(const CIKSMDCRoutCabProjHarnessDataHVDC &input);
	~CIKSMDCRoutCabProjHarnessDataHVDC();

	CIKSMDCRoutCabProjHarnessDataHVDC& operator=(const CIKSMDCRoutCabProjHarnessDataHVDC &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_HVDC; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessHVDC>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessHVDC>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessHVDC *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessHVDC> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataUPS : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataUPS();
	CIKSMDCRoutCabProjHarnessDataUPS(const CIKSMDCRoutCabProjHarnessDataUPS &input);
	~CIKSMDCRoutCabProjHarnessDataUPS();

	CIKSMDCRoutCabProjHarnessDataUPS& operator=(const CIKSMDCRoutCabProjHarnessDataUPS &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_UPS; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessUPS>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessUPS>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessUPS *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessUPS> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataITPDRH : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataITPDRH();
	CIKSMDCRoutCabProjHarnessDataITPDRH(const CIKSMDCRoutCabProjHarnessDataITPDRH &input);
	~CIKSMDCRoutCabProjHarnessDataITPDRH();

	CIKSMDCRoutCabProjHarnessDataITPDRH& operator=(const CIKSMDCRoutCabProjHarnessDataITPDRH &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_ITPDRH; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessITPDRH>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessITPDRH>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessITPDRH *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessITPDRH> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataITPDRU : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataITPDRU();
	CIKSMDCRoutCabProjHarnessDataITPDRU(const CIKSMDCRoutCabProjHarnessDataITPDRU &input);
	~CIKSMDCRoutCabProjHarnessDataITPDRU();

	CIKSMDCRoutCabProjHarnessDataITPDRU& operator=(const CIKSMDCRoutCabProjHarnessDataITPDRU &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_ITPDRU; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessITPDRU>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessITPDRU>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessITPDRU *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessITPDRU> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataFC : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataFC();
	CIKSMDCRoutCabProjHarnessDataFC(const CIKSMDCRoutCabProjHarnessDataFC &input);
	~CIKSMDCRoutCabProjHarnessDataFC();

	CIKSMDCRoutCabProjHarnessDataFC& operator=(const CIKSMDCRoutCabProjHarnessDataFC &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_FC; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessFC>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessFC>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessFC *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessFC> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataZM : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataZM();
	CIKSMDCRoutCabProjHarnessDataZM(const CIKSMDCRoutCabProjHarnessDataZM &input);
	~CIKSMDCRoutCabProjHarnessDataZM();

	CIKSMDCRoutCabProjHarnessDataZM& operator=(const CIKSMDCRoutCabProjHarnessDataZM &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_ZM; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessZM>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessZM>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessZM *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessZM> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataMJ : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataMJ();
	CIKSMDCRoutCabProjHarnessDataMJ(const CIKSMDCRoutCabProjHarnessDataMJ &input);
	~CIKSMDCRoutCabProjHarnessDataMJ();

	CIKSMDCRoutCabProjHarnessDataMJ& operator=(const CIKSMDCRoutCabProjHarnessDataMJ &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_MJ; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessMJ>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessMJ>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessMJ *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessMJ> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataJJAN : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataJJAN();
	CIKSMDCRoutCabProjHarnessDataJJAN(const CIKSMDCRoutCabProjHarnessDataJJAN &input);
	~CIKSMDCRoutCabProjHarnessDataJJAN();

	CIKSMDCRoutCabProjHarnessDataJJAN& operator=(const CIKSMDCRoutCabProjHarnessDataJJAN &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_JJAN; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessJJAN>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessJJAN>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessJJAN *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessJJAN> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataGK : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataGK();
	CIKSMDCRoutCabProjHarnessDataGK(const CIKSMDCRoutCabProjHarnessDataGK &input);
	~CIKSMDCRoutCabProjHarnessDataGK();

	CIKSMDCRoutCabProjHarnessDataGK& operator=(const CIKSMDCRoutCabProjHarnessDataGK &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_GK; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessGK>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessGK>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessGK *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessGK> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataJDX : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataJDX();
	CIKSMDCRoutCabProjHarnessDataJDX(const CIKSMDCRoutCabProjHarnessDataJDX &input);
	~CIKSMDCRoutCabProjHarnessDataJDX();

	CIKSMDCRoutCabProjHarnessDataJDX& operator=(const CIKSMDCRoutCabProjHarnessDataJDX &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_JDX; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessJDX>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessJDX>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessJDX *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessJDX> m_vecHarness;
};

class CIKSMDCRoutCabProjHarnessDataWX : public CIKSMDCRoutCabProjHarnessData
{
public:
	CIKSMDCRoutCabProjHarnessDataWX();
	CIKSMDCRoutCabProjHarnessDataWX(const CIKSMDCRoutCabProjHarnessDataWX &input);
	~CIKSMDCRoutCabProjHarnessDataWX();

	CIKSMDCRoutCabProjHarnessDataWX& operator=(const CIKSMDCRoutCabProjHarnessDataWX &input);

public:
	// ��ȡ������Ŀ����
	virtual int GetRoutCabProjType() const { return IKSMDCRCPT_WX; }
	// �������
	virtual void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	virtual BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt, BOOL bClearInputVec=FALSE) const;

protected:

public:
	const std::vector<CIKSMDCHarnessWX>& GetHarness() const { return m_vecHarness; }
	void SetHarness(const std::vector<CIKSMDCHarnessWX>& vecHarness) { m_vecHarness = vecHarness;}
	void ResizeHarness(UINT uSize) { m_vecHarness.resize(uSize); }
	UINT GetHarnessSize() const { return UINT(m_vecHarness.size()); }
	CIKSMDCHarnessWX *GetHarnessByIndex(UINT uIndex)
	{
		if (uIndex >= GetHarnessSize())
			return NULL;
		return &(m_vecHarness[uIndex]);
	}

private:
	std::vector<CIKSMDCHarnessWX> m_vecHarness;
};

//===================================================================================================
// ������Ŀ������Ϣ

class CIKSMDCRoutCabProjDataInf
{
public:
	CIKSMDCRoutCabProjDataInf();
	CIKSMDCRoutCabProjDataInf(const CIKSMDCRoutCabProjDataInf &input);
	~CIKSMDCRoutCabProjDataInf();

	CIKSMDCRoutCabProjDataInf& operator=(const CIKSMDCRoutCabProjDataInf &input);

public:
	// �������
	void Clear();

public:
	// ��ȡ��Ŀ�����������Ļ���ָ��
	BOOL GetRoutCabProjHarnessDataPt(std::vector<CIKSMDCRoutCabProjHarnessData*> &vecRoutCabProjHarnDataPt) const;
	// ��ȡ��Ŀ�����������Ļ���ָ��
	BOOL GetHarnessPt(std::vector<CIKSMDCHarness*> &vecHarnessPt) const;
	// ��ȡ��Ŀ�����е��µĻ���ָ��
	BOOL GetCablePt(std::vector<CIKSMDCCable*> &vecCablePt) const;


protected:

public:
	IKSMDCCableLayoutParam m_CableLayoutParam;	// ���²��ֲ���
	IKSMDCCableDesignParam m_CableDesignParam;	// ������Ʋ���

// ������Ŀ��������
public:
	CIKSMDCRoutCabProjHarnessDataIT		m_HarnIT;
	CIKSMDCRoutCabProjHarnessDataTAC	m_HarnTAC;
	CIKSMDCRoutCabProjHarnessDataBAT	m_HarnBAT;
	CIKSMDCRoutCabProjHarnessDataHVDC	m_HarnHVDC;
	CIKSMDCRoutCabProjHarnessDataUPS	m_HarnUPS;
	CIKSMDCRoutCabProjHarnessDataITPDRH	m_HarnITPDRH;
	CIKSMDCRoutCabProjHarnessDataITPDRU	m_HarnITPDRU;
	CIKSMDCRoutCabProjHarnessDataFC		m_HarnFC;
	CIKSMDCRoutCabProjHarnessDataZM		m_HarnZM;
	CIKSMDCRoutCabProjHarnessDataMJ		m_HarnMJ;
	CIKSMDCRoutCabProjHarnessDataJJAN	m_HarnJJAN;
	CIKSMDCRoutCabProjHarnessDataGK		m_HarnGK;
	CIKSMDCRoutCabProjHarnessDataJDX	m_HarnJDX;
	CIKSMDCRoutCabProjHarnessDataWX		m_HarnWX;

public:
	std::vector<IKSMDCConnector> m_vecConnector;
};

//===================================================================================================
// �������ݶ���
