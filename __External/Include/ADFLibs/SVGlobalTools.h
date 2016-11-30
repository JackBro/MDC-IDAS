//===================================================================================================
// File:
//		Global.h
// Summary:
//		Provides the Global Method.
// Usage:
//		Null	
// Remarks:
//		Null
// Date:
//		2011-8-31
// Author:
//		WangShiping
//===================================================================================================

#pragma once

//===================================================================================================

#include <map>
#include "SVPublicDef.h"
#include "SVSceneDef.h"

//===================================================================================================
struct BPClock
{
	BPClock()
	{
		dwTimeStart = dwTimeEnd = dwTimeCur = dwTimeTotal = 0;
		dwCount = 0;
	}

	void Begin()
	{
		GetSystemTimeAsFileTime((LPFILETIME)&dwTimeStart);
	}
	void End()
	{
		GetSystemTimeAsFileTime((LPFILETIME)&dwTimeEnd);
		dwTimeCur = dwTimeEnd - dwTimeStart;
		dwTimeTotal += dwTimeCur;
		dwCount++;
	}
	IKS_DWORD GetCurTime()	{ return IKS_DWORD(dwTimeCur/10000); }
	IKS_DWORD GetTotalTime()	{ return IKS_DWORD(dwTimeTotal/10000); }
	IKS_DWORD GetAverageTime()	{ return IKS_DWORD(double(dwTimeTotal/10000)/double(dwCount)); }
	void TraceTime()
	{
// 		CUnicodeString strTimer;
// 		strTimer.Format(_T("CurTime=%u;TotalTime=%u;AverTime=%u;\n"), IKS_DWORD(dwTimeCur/10000), IKS_DWORD(dwTimeTotal/10000), GetAverageTime());
// 		TRACE(strTimer.GetBuffer());
	}
	void Clear()
	{
		dwTimeStart = dwTimeEnd = dwTimeCur = dwTimeTotal = 0;
		dwCount = 0;
	}

	IKS_DWORD64 dwTimeStart;
	IKS_DWORD64 dwTimeEnd;
	IKS_DWORD64 dwTimeCur;
	IKS_DWORD64 dwTimeTotal;
	IKS_DWORD dwCount;
};

//===================================================================================================

// ID与索引对应关系管理类
class CBPIDIndexMgr
{
public:
	CBPIDIndexMgr(){}
	virtual ~CBPIDIndexMgr(){}
	CBPIDIndexMgr& operator=(const CBPIDIndexMgr &mgr)
	{
		if (&mgr == this)
			return *this;
		m_IDIndexPool.clear();
		std::map<IKS_UINT,IKS_UINT>::const_iterator it;
		for(it=mgr.m_IDIndexPool.begin(); it!= mgr.m_IDIndexPool.end(); it++)
			m_IDIndexPool[it->first] = it->second;
		return *this;
	}
	CBPIDIndexMgr(const CBPIDIndexMgr &mgr)
	{
		(*this) = mgr;
	}

public:
	void AddIDIndex(IKS_UINT uID, IKS_UINT uIndex){m_IDIndexPool[uID] = uIndex;}
	IKS_UINT GetIndexByID(IKS_UINT uID)	const
	{
		std::map<IKS_UINT,IKS_UINT>::const_iterator iter = m_IDIndexPool.find(uID);
		if (iter != m_IDIndexPool.end())
			return iter->second;

		return IKS_UINT(-1);
	}
	void clear()	{ m_IDIndexPool.clear(); }
	IKS_BOOL DeleteIDIndex(IKS_UINT uID)
	{
		std::map<IKS_UINT,IKS_UINT>::const_iterator iter = m_IDIndexPool.find(uID);
		if (iter == m_IDIndexPool.end())
			return FALSE;
		m_IDIndexPool.erase(iter);
		return TRUE;
	}
	void GetIDData(IKS_UINT *pIDArray, IKS_UINT *pIndexArray, IKS_UINT *pIDSize) const
	{
		IKS_UINT uSize = m_IDIndexPool.size();
		if (pIDSize != NULL)
			*pIDSize = uSize;
		if (pIDArray != NULL || pIndexArray != NULL)
		{
			std::map<IKS_UINT,IKS_UINT>::const_iterator it;
			for(it=m_IDIndexPool.begin(); it!= m_IDIndexPool.end(); it++)
			{
				if (pIDArray != NULL)
					*(pIDArray++) = it->first;
				if (pIndexArray != NULL)
					*(pIndexArray++) = it->second;
			}
		}
	}
	IKS_UINT GetSize() const { return m_IDIndexPool.size(); }

private:
	std::map<IKS_UINT,IKS_UINT> m_IDIndexPool;		// ID与索引关系池
};

// UINT2与索引对应关系管理类
class CBPUINT2IndexMgr
{
public:
	CBPUINT2IndexMgr(){}
	virtual ~CBPUINT2IndexMgr(){}

protected:
	class UINT2Comparator
	{
	public:
		bool operator()(const BPBASEUINT2& v1, const BPBASEUINT2& v2) const
		{
			if (memcmp(&v1, &v2, sizeof(BPBASEUINT2)) < 0)
				return true;
			else
				return false;
		}
	};

public:
	void AddIDIndex(BPBASEUINT2 uID, IKS_UINT uIndex){m_IDIndexPool[uID] = uIndex;}
	void AddIDIndex(IKS_UINT uID1, IKS_UINT uID2, IKS_UINT uIndex)
	{
		BPBASEUINT2 uID;
		uID.x = uID1;
		uID.y = uID2;
		m_IDIndexPool[uID] = uIndex;
	}
	IKS_UINT GetIndexByID(BPBASEUINT2 uID)	const
	{
		std::map<BPBASEUINT2,IKS_UINT,UINT2Comparator>::const_iterator iter = m_IDIndexPool.find(uID);
		if (iter != m_IDIndexPool.end())
			return iter->second;

		return IKS_UINT(-1);
	}
	void clear()	{ m_IDIndexPool.clear(); }
	IKS_BOOL DeleteIDIndex(BPBASEUINT2 uID)
	{
		std::map<BPBASEUINT2,IKS_UINT,UINT2Comparator>::const_iterator iter = m_IDIndexPool.find(uID);
		if (iter == m_IDIndexPool.end())
			return FALSE;
		m_IDIndexPool.erase(iter);
		return TRUE;
	}
	void GetIDData(BPBASEUINT2 *pIDArray, IKS_UINT *pIndexArray, IKS_UINT *pIDSize) const
	{
		IKS_UINT uSize = m_IDIndexPool.size();
		if (pIDSize != NULL)
			*pIDSize = uSize;
		if (pIDArray != NULL || pIndexArray != NULL)
		{
			std::map<BPBASEUINT2,IKS_UINT,UINT2Comparator>::const_iterator it;
			for(it=m_IDIndexPool.begin(); it!= m_IDIndexPool.end(); it++)
			{
				if (pIDArray != NULL)
					*(pIDArray++) = it->first;
				if (pIndexArray != NULL)
					*(pIndexArray++) = it->second;
			}
		}
	}

private:
	std::map<BPBASEUINT2,IKS_UINT,UINT2Comparator> m_IDIndexPool;		// ID与索引关系池
};

// IKS_UINT与Float对应关系管理类
class CBPUINTFloatMgr
{
public:
	CBPUINTFloatMgr(){}
	virtual ~CBPUINTFloatMgr(){}

public:
	void AddUINTFloat(IKS_UINT uValue, float fValue){m_UINTFloatPool[uValue] = fValue;}
	float GetFloatByUINT(IKS_UINT uValue)	const
	{
		std::map<IKS_UINT,float>::const_iterator iter = m_UINTFloatPool.find(uValue);
		if (iter != m_UINTFloatPool.end())
			return iter->second;

		return -1.0f;
	}
	void clear()	{ m_UINTFloatPool.clear(); }
	IKS_BOOL DeleteIDIndex(IKS_UINT uValue)
	{
		std::map<IKS_UINT,float>::const_iterator iter = m_UINTFloatPool.find(uValue);
		if (iter == m_UINTFloatPool.end())
			return FALSE;
		m_UINTFloatPool.erase(iter);
		return TRUE;
	}
	void GetUINTFloatData(IKS_UINT *pUINTArray, float *pFloatArray, IKS_UINT *pArraySize) const
	{
		IKS_UINT uSize = m_UINTFloatPool.size();
		if (pArraySize != NULL)
			*pArraySize = uSize;
		if (pUINTArray != NULL || pFloatArray != NULL)
		{
			std::map<IKS_UINT,float>::const_iterator it;
			for(it=m_UINTFloatPool.begin(); it!= m_UINTFloatPool.end(); it++)
			{
				if (pUINTArray != NULL)
					*(pUINTArray++) = it->first;
				if (pFloatArray != NULL)
					*(pFloatArray++) = it->second;
			}
		}
	}

private:
	std::map<IKS_UINT,float> m_UINTFloatPool;
};

// IKS_UINT与Double对应关系管理类
class CBPUINTDoubleMgr
{
public:
	CBPUINTDoubleMgr(){}
	virtual ~CBPUINTDoubleMgr(){}
	CBPUINTDoubleMgr& operator=(const CBPUINTDoubleMgr &mgr)
	{
		if (&mgr == this)
			return *this;
		m_UINTDoublePool.clear();
		std::map<IKS_UINT,double>::const_iterator it;
		for(it=mgr.m_UINTDoublePool.begin(); it!= mgr.m_UINTDoublePool.end(); it++)
			m_UINTDoublePool[it->first] = it->second;
		return *this;
	}
	CBPUINTDoubleMgr(const CBPUINTDoubleMgr &mgr)
	{
		(*this) = mgr;
	}
public:
	void AddUINTDouble(IKS_UINT uValue, double dValue){m_UINTDoublePool[uValue] = dValue;}
	double GetDoubleByUINT(IKS_UINT uValue)	const
	{
		std::map<IKS_UINT,double>::const_iterator iter = m_UINTDoublePool.find(uValue);
		if (iter != m_UINTDoublePool.end())
			return iter->second;

		return -1.0;
	}
	void clear()	{ m_UINTDoublePool.clear(); }
	IKS_BOOL DeleteIDIndex(IKS_UINT uValue)
	{
		std::map<IKS_UINT,double>::const_iterator iter = m_UINTDoublePool.find(uValue);
		if (iter == m_UINTDoublePool.end())
			return FALSE;
		m_UINTDoublePool.erase(iter);
		return TRUE;
	}
	void GetUINTDoubleData(IKS_UINT *pUINTArray, double *pDoubleArray, IKS_UINT *pArraySize) const
	{
		IKS_UINT uSize = m_UINTDoublePool.size();
		if (pArraySize != NULL)
			*pArraySize = uSize;
		if (pUINTArray != NULL || pDoubleArray != NULL)
		{
			std::map<IKS_UINT,double>::const_iterator it;
			for(it=m_UINTDoublePool.begin(); it!= m_UINTDoublePool.end(); it++)
			{
				if (pUINTArray != NULL)
					*(pUINTArray++) = it->first;
				if (pDoubleArray != NULL)
					*(pDoubleArray++) = it->second;
			}
		}
	}

private:
	std::map<IKS_UINT,double> m_UINTDoublePool;
};

// 单精浮点值与索引对应关系管理类
class CBPFloatValueIndexMgr
{
public:
	CBPFloatValueIndexMgr(){}
	virtual ~CBPFloatValueIndexMgr(){}

public:
	void AddValueIndex(float fValue, IKS_UINT uIndex){m_ValueIndexPool[fValue] = uIndex;}
	IKS_UINT GetIndexByValue(float fValue)	const
	{
		std::map<float,IKS_UINT>::const_iterator iter = m_ValueIndexPool.find(fValue);
		if (iter != m_ValueIndexPool.end())
			return iter->second;

		return IKS_UINT(-1);
	}
	void clear()	{ m_ValueIndexPool.clear(); }
	IKS_BOOL DeleteValueIndex(float fValue)
	{
		std::map<float,IKS_UINT>::const_iterator iter = m_ValueIndexPool.find(fValue);
		if (iter == m_ValueIndexPool.end())
			return FALSE;
		m_ValueIndexPool.erase(iter);
		return TRUE;
	}
	void GetValueData(float *pValueArray, IKS_UINT *pIndexArray, IKS_UINT *pIDSize) const
	{
		IKS_UINT uSize = m_ValueIndexPool.size();
		if (pIDSize != NULL)
			*pIDSize = uSize;
		if (pValueArray != NULL || pIndexArray != NULL)
		{
			std::map<float,IKS_UINT>::const_iterator it;
			for(it=m_ValueIndexPool.begin(); it!= m_ValueIndexPool.end(); it++)
			{
				if (pValueArray != NULL)
					*(pValueArray++) = it->first;
				if (pIndexArray != NULL)
					*(pIndexArray++) = it->second;
			}
		}
	}

private:
	std::map<float,IKS_UINT> m_ValueIndexPool;		// ID与索引关系池
};

// 单精浮点值与索引对应关系管理类
class CBPFloat3ValueIndexMgr
{
public:
	CBPFloat3ValueIndexMgr(){}
	virtual ~CBPFloat3ValueIndexMgr(){}

protected:
	class Float3Comparator
	{
	public:
		bool operator()(const BPBASEFLOAT3& v1, const BPBASEFLOAT3& v2) const
		{
			if (memcmp(&v1, &v2, sizeof(BPBASEFLOAT3)) < 0)
				return true;
			else
				return false;
		}
	};

public:
	void AddValueIndex(const BPBASEFLOAT3 &vValue, IKS_UINT uIndex){m_ValueIndexPool[vValue] = uIndex;}
	IKS_UINT GetIndexByValue(const BPBASEFLOAT3 &vValue)	const
	{
		std::map<BPBASEFLOAT3,IKS_UINT,Float3Comparator>::const_iterator iter = m_ValueIndexPool.find(vValue);
		if (iter != m_ValueIndexPool.end())
			return iter->second;

		return IKS_UINT(-1);
	}
	void clear()	{ m_ValueIndexPool.clear(); }
	IKS_BOOL DeleteValueIndex(const BPBASEFLOAT3 &vValue)
	{
		std::map<BPBASEFLOAT3,IKS_UINT,Float3Comparator>::const_iterator iter = m_ValueIndexPool.find(vValue);
		if (iter == m_ValueIndexPool.end())
			return FALSE;
		m_ValueIndexPool.erase(iter);
		return TRUE;
	}
	void GetValueData(BPBASEFLOAT3 *pValueArray, IKS_UINT *pIndexArray, IKS_UINT *pIDSize) const
	{
		IKS_UINT uSize = m_ValueIndexPool.size();
		if (pIDSize != NULL)
			*pIDSize = uSize;
		if (pValueArray != NULL || pIndexArray != NULL)
		{
			std::map<BPBASEFLOAT3,IKS_UINT,Float3Comparator>::const_iterator it;
			for(it=m_ValueIndexPool.begin(); it!= m_ValueIndexPool.end(); it++)
			{
				if (pValueArray != NULL)
					*(pValueArray++) = it->first;
				if (pIndexArray != NULL)
					*(pIndexArray++) = it->second;
			}
		}
	}

private:
	std::map<BPBASEFLOAT3,IKS_UINT,Float3Comparator> m_ValueIndexPool;		// ID与索引关系池
};

// 双精浮点值与索引对应关系管理类
class CBPDoubleValueIndexMgr
{
public:
	CBPDoubleValueIndexMgr(){}
	virtual ~CBPDoubleValueIndexMgr(){}

public:
	void AddValueIndex(double dValue, IKS_UINT uIndex){m_ValueIndexPool[dValue] = uIndex;}
	IKS_UINT GetIndexByValue(double dValue)	const
	{
		std::map<double,IKS_UINT>::const_iterator iter = m_ValueIndexPool.find(dValue);
		if (iter != m_ValueIndexPool.end())
			return iter->second;

		return IKS_UINT(-1);
	}
	void clear()	{ m_ValueIndexPool.clear(); }
	IKS_BOOL DeleteValueIndex(double dValue)
	{
		std::map<double,IKS_UINT>::const_iterator iter = m_ValueIndexPool.find(dValue);
		if (iter == m_ValueIndexPool.end())
			return FALSE;
		m_ValueIndexPool.erase(iter);
		return TRUE;
	}
	void GetValueData(double *pValueArray, IKS_UINT *pIndexArray, IKS_UINT *pIDSize) const
	{
		IKS_UINT uSize = m_ValueIndexPool.size();
		if (pIDSize != NULL)
			*pIDSize = uSize;
		if (pValueArray != NULL || pIndexArray != NULL)
		{
			std::map<double,IKS_UINT>::const_iterator it;
			for(it=m_ValueIndexPool.begin(); it!= m_ValueIndexPool.end(); it++)
			{
				if (pValueArray != NULL)
					*(pValueArray++) = it->first;
				if (pIndexArray != NULL)
					*(pIndexArray++) = it->second;
			}
		}
	}

private:
	std::map<double,IKS_UINT> m_ValueIndexPool;		// ID与索引关系池
};

// 双精浮点值与索引对应关系管理类(考虑精度)
class CBPDoubleValueIndexMgrEx
{
public:
	CBPDoubleValueIndexMgrEx(){ m_dZero = DZERO; }
	CBPDoubleValueIndexMgrEx(double dZero){ m_dZero = dZero; }
	virtual ~CBPDoubleValueIndexMgrEx(){}

public:
	void AddValueIndex(double dValue, IKS_UINT uIndex)
	{
		IKS_UINT uCurArrayIndex = INVALID_ID;
		IKS_UINT uArrayIndex = GetArrayIndexBySameValue(dValue, &uCurArrayIndex);
		if (uArrayIndex != INVALID_ID)
		{
			m_arrValue[uArrayIndex] = dValue;
			m_arrIndex[uArrayIndex] = uIndex;
			return;
		}
		else if (uCurArrayIndex != INVALID_ID)
		{
			m_arrValue.resize(m_arrValue.size() + 1);
			m_arrIndex.resize(m_arrIndex.size() + 1);
			if (m_arrValue[uCurArrayIndex] < dValue)
			{
				if (uCurArrayIndex+1 <= m_arrValue.size()-2)
				{
					if (m_arrValue[uCurArrayIndex+1] < dValue)
						uCurArrayIndex = uCurArrayIndex+1;
				}
				if (int(m_arrValue.size()-2-uCurArrayIndex) > 0)
				{
					memmove_s(&(m_arrValue[uCurArrayIndex+2]), sizeof(double)*(m_arrValue.size()-2-uCurArrayIndex), &(m_arrValue[uCurArrayIndex+1]), sizeof(double)*(m_arrValue.size()-2-uCurArrayIndex));
					memmove_s(&(m_arrIndex[uCurArrayIndex+2]), sizeof(IKS_UINT)*(m_arrIndex.size()-2-uCurArrayIndex), &(m_arrIndex[uCurArrayIndex+1]), sizeof(IKS_UINT)*(m_arrIndex.size()-2-uCurArrayIndex));
				}
				m_arrValue[uCurArrayIndex+1] = dValue;
				m_arrIndex[uCurArrayIndex+1] = uIndex;
			}
			else
			{
				if (int(m_arrValue.size()-1-uCurArrayIndex) > 0)
				{
					memmove_s(&(m_arrValue[uCurArrayIndex+1]), sizeof(double)*(m_arrValue.size()-1-uCurArrayIndex), &(m_arrValue[uCurArrayIndex]), sizeof(double)*(m_arrValue.size()-1-uCurArrayIndex));
					memmove_s(&(m_arrIndex[uCurArrayIndex+1]), sizeof(IKS_UINT)*(m_arrIndex.size()-1-uCurArrayIndex), &(m_arrIndex[uCurArrayIndex]), sizeof(IKS_UINT)*(m_arrIndex.size()-1-uCurArrayIndex));
				}
				m_arrValue[uCurArrayIndex] = dValue;
				m_arrIndex[uCurArrayIndex] = uIndex;
			}
		}
		else
		{
			if (m_arrValue.size() == 0)
			{
				m_arrValue.push_back(dValue);
				m_arrIndex.push_back(uIndex);
			}
			else
				ASSERT(FALSE);
		}
	}
	IKS_UINT GetIndexBySameValue(double dValue)	const
	{
		IKS_UINT uArrayIndex = GetArrayIndexBySameValue(dValue);
		if (uArrayIndex != INVALID_ID)
			return m_arrIndex[uArrayIndex];
		return IKS_UINT(-1);
	}
	IKS_BOOL GetIndexByValue(double dValue, CBPDynamicArray<IKS_UINT> &arrIndex)	const
	{
		arrIndex.clear();
		CBPDynamicArray<IKS_UINT> arrArrayIndex;
		if (GetArrayIndexByValue(dValue, arrArrayIndex))
		{
			arrIndex.resize(arrArrayIndex.size());
			for (IKS_UINT i=0; i<arrArrayIndex.size(); i++)
				arrIndex[i] = m_arrIndex[arrArrayIndex[i]];
		}
		return (arrIndex.size() > 0);
	}
	void clear()
	{
		m_arrValue.clear();
		m_arrIndex.clear();
	}
	IKS_BOOL DeleteValueIndexBySameValue(double dValue)
	{
		IKS_UINT uArrayIndex = GetArrayIndexBySameValue(dValue);
		if (uArrayIndex == INVALID_ID)
			return FALSE;
		m_arrValue.erase(uArrayIndex);
		m_arrIndex.erase(uArrayIndex);
		return TRUE;
	}
	void GetValueData(double *pValueArray, IKS_UINT *pIndexArray, IKS_UINT *pIDSize) const
	{
		IKS_UINT uSize = m_arrValue.size();
		if (pIDSize != NULL)
			*pIDSize = uSize;
		if (pValueArray != NULL || pIndexArray != NULL)
		{
			for(IKS_UINT i=0; i<m_arrValue.size(); i++)
			{
				if (pValueArray != NULL)
					*(pValueArray++) = m_arrValue[i];
				if (pIndexArray != NULL)
					*(pIndexArray++) = m_arrIndex[i];
			}
		}
	}

protected:
	// 通过数值获取索引
	IKS_UINT GetArrayIndexBySameValue(double dValue, IKS_UINT *pArrayIndex=NULL) const
	{
		if (pArrayIndex != NULL)
			*pArrayIndex = INVALID_ID;
		if (m_arrValue.size() == 0)
			return INVALID_ID;
		IKS_UINT uBeginIndex = 0;
		IKS_UINT uEndIndex = m_arrValue.size() - 1;
		IKS_UINT uCurIndex = (uBeginIndex + uEndIndex) / 2;
		while (uCurIndex != uBeginIndex)
		{
			if (memcmp(&(m_arrValue[uCurIndex]), &dValue, sizeof(double)) == 0)
			{
				if (pArrayIndex != NULL)
					*pArrayIndex = uCurIndex;
				return uCurIndex;
			}
			if (m_arrValue[uCurIndex] < dValue)
				uBeginIndex = uCurIndex;
			else
				uEndIndex = uCurIndex;
			uCurIndex = (uBeginIndex + uEndIndex) / 2;
		}
		if (memcmp(&(m_arrValue[uBeginIndex]), &dValue, sizeof(double)) == 0)
		{
			if (pArrayIndex != NULL)
				*pArrayIndex = uBeginIndex;
			return uBeginIndex;
		}
		else if (memcmp(&(m_arrValue[uEndIndex]), &dValue, sizeof(double)) == 0)
		{
			if (pArrayIndex != NULL)
				*pArrayIndex = uEndIndex;
			return uEndIndex;
		}
		if (pArrayIndex != NULL)
			*pArrayIndex = uBeginIndex;
		return INVALID_ID;
	}
	// 通过数值获取索引(考虑精度)
	IKS_BOOL GetArrayIndexByValue(double dValue, CBPDynamicArray<IKS_UINT> &arrArrayIndex) const
	{
		arrArrayIndex.clear();
		IKS_UINT uCurArrayIndex = INVALID_ID;
		GetArrayIndexBySameValue(dValue, &uCurArrayIndex);
		if (uCurArrayIndex == INVALID_ID)
			return FALSE;
		for (int i=int(uCurArrayIndex); i>=0; i--)
		{
			if (ISDEQUALEX(m_arrValue[i], dValue, m_dZero))
				arrArrayIndex.push_back(IKS_UINT(i));
			else
				break;
		}
		for (IKS_UINT i=uCurArrayIndex+1; i<m_arrValue.size(); i++)
		{
			if (ISDEQUALEX(m_arrValue[i], dValue, m_dZero))
				arrArrayIndex.push_back(IKS_UINT(i));
			else
				break;
		}
		return (arrArrayIndex.size() > 0);
	}
public:
	double GetZero() const { return m_dZero; }
	void SetZero(double dZero) { m_dZero = dZero; }
private:
	CBPDynamicArray<double> m_arrValue;
	CBPDynamicArray<IKS_UINT> m_arrIndex;
	double m_dZero;
};

// 双精浮点值与索引对应关系管理类
class CBPDouble3ValueIndexMgr
{
public:
	CBPDouble3ValueIndexMgr(){}
	virtual ~CBPDouble3ValueIndexMgr(){}

protected:
	class Double3Comparator
	{
	public:
		bool operator()(const SVBASEDOUBLE3& v1, const SVBASEDOUBLE3& v2) const
		{
			if (memcmp(&v1, &v2, sizeof(SVBASEDOUBLE3)) < 0)
				return true;
			else
				return false;
		}
	};

public:
	void AddValueIndex(const SVBASEDOUBLE3 &vValue, IKS_UINT uIndex){m_ValueIndexPool[vValue] = uIndex;}
	IKS_UINT GetIndexByValue(const SVBASEDOUBLE3 &vValue)	const
	{
		std::map<SVBASEDOUBLE3,IKS_UINT,Double3Comparator>::const_iterator iter = m_ValueIndexPool.find(vValue);
		if (iter != m_ValueIndexPool.end())
			return iter->second;

		return IKS_UINT(-1);
	}
	void clear()	{ m_ValueIndexPool.clear(); }
	IKS_BOOL DeleteValueIndex(const SVBASEDOUBLE3 &vValue)
	{
		std::map<SVBASEDOUBLE3,IKS_UINT,Double3Comparator>::const_iterator iter = m_ValueIndexPool.find(vValue);
		if (iter == m_ValueIndexPool.end())
			return FALSE;
		m_ValueIndexPool.erase(iter);
		return TRUE;
	}
	void GetValueData(SVBASEDOUBLE3 *pValueArray, IKS_UINT *pIndexArray, IKS_UINT *pIDSize) const
	{
		IKS_UINT uSize = m_ValueIndexPool.size();
		if (pIDSize != NULL)
			*pIDSize = uSize;
		if (pValueArray != NULL || pIndexArray != NULL)
		{
			std::map<SVBASEDOUBLE3,IKS_UINT,Double3Comparator>::const_iterator it;
			for(it=m_ValueIndexPool.begin(); it!= m_ValueIndexPool.end(); it++)
			{
				if (pValueArray != NULL)
					*(pValueArray++) = it->first;
				if (pIndexArray != NULL)
					*(pIndexArray++) = it->second;
			}
		}
	}

private:
	std::map<SVBASEDOUBLE3,IKS_UINT,Double3Comparator> m_ValueIndexPool;		// ID与索引关系池
};

// 双精浮点值位置与索引对应关系管理类
class CBPDouble3PositionIndexMgr
{
public:
	CBPDouble3PositionIndexMgr(){}
	CBPDouble3PositionIndexMgr(double dZero)
	{
		m_dZero = dZero;
		m_mapXIndex.SetZero(m_dZero);
		m_mapYIndex.SetZero(m_dZero);
		m_mapZIndex.SetZero(m_dZero);
	}
	virtual ~CBPDouble3PositionIndexMgr(){}

public:
	// 添加数值与索引关系(只要memcmp(vValue1, vValue2)!=0则必然会创建一个新点与索引的关系)
	void AddValueIndex(const SVBASEDOUBLE3 &vValue, IKS_UINT uValueIndex)
	{
		IKS_UINT uPointIndex = GetPointIndexBySameValue(vValue);
		if (uPointIndex != IKS_UINT(-1))
		{
			m_arrValueIndex[uPointIndex] = uValueIndex;
			return;
		}

		uPointIndex = m_arrPoint.size();
		m_arrPoint.push_back(vValue);
		m_arrValueIndex.push_back(uValueIndex);

		IKS_UINT uIndex = IKS_UINT(-1);
		uIndex = m_mapXIndex.GetIndexBySameValue(vValue.x);
		if (uIndex == IKS_UINT(-1))
		{
			uIndex = m_arrXIndex.size();
			m_arrXIndex.resize(uIndex + 1);
			m_arrXIndex[uIndex].clear();
			m_mapXIndex.AddValueIndex(vValue.x, uIndex);
		}
		m_arrXIndex[uIndex].push_back(uPointIndex);

		uIndex = m_mapYIndex.GetIndexBySameValue(vValue.y);
		if (uIndex == IKS_UINT(-1))
		{
			uIndex = m_arrYIndex.size();
			m_arrYIndex.resize(uIndex + 1);
			m_arrYIndex[uIndex].clear();
			m_mapYIndex.AddValueIndex(vValue.y, uIndex);
		}
		m_arrYIndex[uIndex].push_back(uPointIndex);

		uIndex = m_mapZIndex.GetIndexBySameValue(vValue.z);
		if (uIndex == IKS_UINT(-1))
		{
			uIndex = m_arrZIndex.size();
			m_arrZIndex.resize(uIndex + 1);
			m_arrZIndex[uIndex].clear();
			m_mapZIndex.AddValueIndex(vValue.z, uIndex);
		}
		m_arrZIndex[uIndex].push_back(uPointIndex);
	}

	IKS_UINT GetIndexBySameValue(const SVBASEDOUBLE3 &vValue)	const
	{
		IKS_UINT uPointIndex = GetPointIndexBySameValue(vValue);
		if (uPointIndex < m_arrValueIndex.size())
			return m_arrValueIndex[uPointIndex];
		else
			return IKS_UINT(-1);
	}

	IKS_BOOL GetIndexByValue(const SVBASEDOUBLE3 &vValue, CBPDynamicArray<IKS_UINT> &arrIndex)	const
	{
		arrIndex.clear();

		CBPDynamicArray<IKS_UINT> arrPointIndex;
		if (GetPointIndexByValue(vValue, arrPointIndex))
		{
			arrIndex.resize(arrPointIndex.size());
			for (IKS_UINT i=0; i<arrPointIndex.size(); i++)
				arrIndex[i] = m_arrValueIndex[arrPointIndex[i]];
		}

		return (arrIndex.size() > 0);
	}

	IKS_UINT GetIndexByValue(const SVBASEDOUBLE3 &vValue)	const
	{
		IKS_UINT uPointIndex = GetPointIndexByValue(vValue);
		if (uPointIndex < m_arrValueIndex.size())
			return m_arrValueIndex[uPointIndex];
		else
			return IKS_UINT(-1);
	}

	void clear()
	{
		m_arrPoint.clear();
		m_arrValueIndex.clear();

		m_arrXIndex.clear();
		m_arrYIndex.clear();
		m_arrZIndex.clear();
		m_mapXIndex.clear();
		m_mapYIndex.clear();
		m_mapZIndex.clear();
	}

	IKS_BOOL DeleteValueIndexBySameValue(const SVBASEDOUBLE3 &vValue)
	{
		IKS_UINT uPointIndex = GetPointIndexBySameValue(vValue);
		if (uPointIndex == IKS_UINT(-1))
			return FALSE;

		IKS_UINT uIndexX = m_mapXIndex.GetIndexBySameValue(vValue.x);
		if (uIndexX == IKS_UINT(-1))
			return IKS_UINT(-1);
		IKS_UINT uIndexY = m_mapYIndex.GetIndexBySameValue(vValue.y);
		if (uIndexY == IKS_UINT(-1))
			return IKS_UINT(-1);
		IKS_UINT uIndexZ = m_mapZIndex.GetIndexBySameValue(vValue.z);
		if (uIndexZ == IKS_UINT(-1))
			return IKS_UINT(-1);

		for (int i=int(m_arrXIndex[uIndexX].size())-1; i>=0; i--)
		{
			if (uPointIndex == m_arrXIndex[uIndexX][i])
			{
				m_arrXIndex[uIndexX].erase(i);
				break;
			}
		}
		if (m_arrXIndex[uIndexX].size() == 0)
			m_mapXIndex.AddValueIndex(vValue.x, IKS_UINT(-1));

		for (int i=int(m_arrYIndex[uIndexY].size())-1; i>=0; i--)
		{
			if (uPointIndex == m_arrYIndex[uIndexY][i])
			{
				m_arrYIndex[uIndexY].erase(i);
				break;
			}
		}
		if (m_arrYIndex[uIndexY].size() == 0)
			m_mapYIndex.AddValueIndex(vValue.y, IKS_UINT(-1));

		for (int i=int(m_arrZIndex[uIndexZ].size())-1; i>=0; i--)
		{
			if (uPointIndex == m_arrZIndex[uIndexZ][i])
			{
				m_arrZIndex[uIndexZ].erase(i);
				break;
			}
		}
		if (m_arrZIndex[uIndexZ].size() == 0)
			m_mapZIndex.AddValueIndex(vValue.z, IKS_UINT(-1));

		m_arrValueIndex[uPointIndex] = IKS_UINT(-1);
		IKS_BYTE *pData = (IKS_BYTE*)(&(m_arrPoint[uPointIndex]));
		for (int i=0; i<sizeof(SVBASEDOUBLE3)/sizeof(IKS_BYTE); i++)
			pData[i] = 0xff;	
	}

protected:
	IKS_UINT GetPointIndexBySameValue(const SVBASEDOUBLE3 &vValue)	const
	{
		IKS_UINT uIndexX = m_mapXIndex.GetIndexBySameValue(vValue.x);
		if (uIndexX == IKS_UINT(-1))
			return IKS_UINT(-1);
		IKS_UINT uIndexY = m_mapYIndex.GetIndexBySameValue(vValue.y);
		if (uIndexY == IKS_UINT(-1))
			return IKS_UINT(-1);
		IKS_UINT uIndexZ = m_mapZIndex.GetIndexBySameValue(vValue.z);
		if (uIndexZ == IKS_UINT(-1))
			return IKS_UINT(-1);

		CBPDynamicArray<IKS_UINT> arrSamePointIndex = m_arrXIndex[uIndexX];

		BOOL bIsSame = FALSE;
		for (int i=int(arrSamePointIndex.size())-1; i>=0; i--)
		{
			bIsSame = FALSE;
			for (IKS_UINT j=0; j<m_arrYIndex[uIndexY].size(); j++)
			{
				if (arrSamePointIndex[i] == m_arrYIndex[uIndexY][j])
				{
					bIsSame = TRUE;
					break;
				}
			}
			if (!bIsSame)
				arrSamePointIndex.erase(i);
		}
		if (arrSamePointIndex.size() == 0)
			return IKS_UINT(-1);

		for (int i=int(arrSamePointIndex.size())-1; i>=0; i--)
		{
			bIsSame = FALSE;
			for (IKS_UINT j=0; j<m_arrZIndex[uIndexZ].size(); j++)
			{
				if (arrSamePointIndex[i] == m_arrZIndex[uIndexZ][j])
				{
					bIsSame = TRUE;
					break;
				}
			}
			if (!bIsSame)
				arrSamePointIndex.erase(i);
		}
		if (arrSamePointIndex.size() == 0)
			return IKS_UINT(-1);

		return arrSamePointIndex[0];
	}

	IKS_BOOL GetPointIndexByValue(const SVBASEDOUBLE3 &vValue, CBPDynamicArray<IKS_UINT> &arrPointIndex)	const
	{
		arrPointIndex.clear();

		CBPDynamicArray<IKS_UINT> arrIndexX, arrIndexY, arrIndexZ, arrIndexTemp;
		m_mapXIndex.GetIndexByValue(vValue.x, arrIndexTemp);
		for (IKS_UINT i=0; i<arrIndexTemp.size(); i++)
		{
			for (IKS_UINT j=0; j<m_arrXIndex[arrIndexTemp[i]].size(); j++)
				arrIndexX.push_back(m_arrXIndex[arrIndexTemp[i]][j]);
		}
		m_mapYIndex.GetIndexByValue(vValue.y, arrIndexTemp);
		for (IKS_UINT i=0; i<arrIndexTemp.size(); i++)
		{
			for (IKS_UINT j=0; j<m_arrYIndex[arrIndexTemp[i]].size(); j++)
				arrIndexY.push_back(m_arrYIndex[arrIndexTemp[i]][j]);
		}
		m_mapZIndex.GetIndexByValue(vValue.z, arrIndexTemp);
		for (IKS_UINT i=0; i<arrIndexTemp.size(); i++)
		{
			for (IKS_UINT j=0; j<m_arrZIndex[arrIndexTemp[i]].size(); j++)
				arrIndexZ.push_back(m_arrZIndex[arrIndexTemp[i]][j]);
		}

		CBPIDIndexMgr m_mapTemp;
		for (IKS_UINT i=0; i<arrIndexX.size(); i++)
			m_mapTemp.AddIDIndex(arrIndexX[i], IKS_UINT(-2));
		for (IKS_UINT i=0; i<arrIndexY.size(); i++)
		{
			if (m_mapTemp.GetIndexByID(arrIndexY[i]) == IKS_UINT(-2))
				m_mapTemp.AddIDIndex(arrIndexY[i], IKS_UINT(-3));
		}
		for (IKS_UINT i=0; i<arrIndexZ.size(); i++)
		{
			if (m_mapTemp.GetIndexByID(arrIndexZ[i]) == IKS_UINT(-3))
				m_mapTemp.AddIDIndex(arrIndexZ[i], IKS_UINT(-4));
		}
		for (IKS_UINT i=0; i<arrIndexX.size(); i++)
		{
			if (m_mapTemp.GetIndexByID(arrIndexX[i]) == IKS_UINT(-4))
				arrPointIndex.push_back(arrIndexX[i]);
		}

		return (arrPointIndex.size() > 0);
	}

	IKS_UINT GetPointIndexByValue(const SVBASEDOUBLE3 &vValue)	const
	{
		CBPDynamicArray<IKS_UINT> arrPointIndex;
		if (!GetPointIndexByValue(vValue, arrPointIndex))
			return IKS_UINT(-1);
		if (arrPointIndex.size() == 0)
			return IKS_UINT(-1);

		IKS_UINT uPointIndex = arrPointIndex[0];
		double dDistMin = IKS_MATH::CalculateDistanceSquare(&vValue, &(m_arrPoint[uPointIndex]));
		double dDistCur = 0.0;
		for (IKS_UINT i=1; i<arrPointIndex.size(); i++)
		{
			dDistCur = IKS_MATH::CalculateDistanceSquare(&vValue, &(m_arrPoint[arrPointIndex[i]]));
			if (dDistCur < dDistMin)
			{
				uPointIndex = arrPointIndex[i];
				dDistMin = dDistCur;
			}
		}

		return uPointIndex;
	}

private:
	CBPDynamicArray<SVBASEDOUBLE3> m_arrPoint;
	CBPDynamicArray<IKS_UINT> m_arrValueIndex;

	CBPDynamicArray<CBPDynamicArray<IKS_UINT> > m_arrXIndex;
	CBPDynamicArray<CBPDynamicArray<IKS_UINT> > m_arrYIndex;
	CBPDynamicArray<CBPDynamicArray<IKS_UINT> > m_arrZIndex;
	CBPDoubleValueIndexMgrEx m_mapXIndex;
	CBPDoubleValueIndexMgrEx m_mapYIndex;
	CBPDoubleValueIndexMgrEx m_mapZIndex;

	double m_dZero;
};

// 字符串与索引对应关系管理类
class CSVStringIndexMgr
{
public:
	CSVStringIndexMgr(IKS_BOOL bCompareNoCase=TRUE){ m_bCompareNoCase=bCompareNoCase; }
	virtual ~CSVStringIndexMgr(){}

protected:
	class StringComparator
	{
	public:
		bool operator()(const CSVWString& str1, const CSVWString& str2) const
		{
			int nResut = wcscmp(str1, str2);
			if (nResut < 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	};

public:
	void AddStringIndex(const CSVWString& str, IKS_UINT uIndex)
	{
		if (m_bCompareNoCase)
		{
			CSVWString strM = str;
			strM.MakeLower();
			m_StringIndexPool[strM] = uIndex;
		}
		else
			m_StringIndexPool[str] = uIndex;
	}
	IKS_UINT GetIndexByString(const CSVWString& str)	const
	{
		if (m_bCompareNoCase)
		{
			CSVWString strM = str;
			strM.MakeLower();
			std::map<CSVWString,IKS_UINT,StringComparator>::const_iterator iter = m_StringIndexPool.find(strM);
			if (iter != m_StringIndexPool.end())
				return iter->second;
		}
		else
		{
			std::map<CSVWString,IKS_UINT,StringComparator>::const_iterator iter = m_StringIndexPool.find(str);
			if (iter != m_StringIndexPool.end())
				return iter->second;
		}

		return IKS_UINT(-1);
	}
	void clear()	{ m_StringIndexPool.clear(); }
	IKS_BOOL DeleteStringIndex(const CSVWString& str)
	{
		if (m_bCompareNoCase)
		{
			CSVWString strM = str;
			strM.MakeLower();
			std::map<CSVWString,IKS_UINT,StringComparator>::const_iterator iter = m_StringIndexPool.find(strM);
			if (iter == m_StringIndexPool.end())
				return FALSE;
			m_StringIndexPool.erase(iter);
		}
		else
		{
			std::map<CSVWString,IKS_UINT,StringComparator>::const_iterator iter = m_StringIndexPool.find(str);
			if (iter == m_StringIndexPool.end())
				return FALSE;
			m_StringIndexPool.erase(iter);
		}
		return TRUE;
	}
	IKS_UINT GetSize() { return IKS_UINT(m_StringIndexPool.size()); }

private:
	std::map<CSVWString,IKS_UINT,StringComparator> m_StringIndexPool;		// ID与索引关系池
	IKS_BOOL m_bCompareNoCase;
};

// 指针与索引对应关系管理类
class CBPPtIndexMgr
{
public:
	CBPPtIndexMgr(){}
	virtual ~CBPPtIndexMgr(){}

public:
	void AddPtIndex(void* pt, IKS_UINT uIndex){m_PtIndexPool[pt] = uIndex;}
	IKS_UINT GetIndexByPt(void* pt)	const
	{
		std::map<void*,IKS_UINT>::const_iterator iter = m_PtIndexPool.find(pt);
		if (iter != m_PtIndexPool.end())
			return iter->second;

		return IKS_UINT(-1);
	}
	void clear()	{ m_PtIndexPool.clear(); }

private:
	std::map<void*,IKS_UINT> m_PtIndexPool;		// ID与索引关系池
};
