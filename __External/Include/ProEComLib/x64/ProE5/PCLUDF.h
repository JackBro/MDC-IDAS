//===================================================================================================
// File:
//		PCLUDF.h
// Summary:
//		UDF�ӿ���
// Date:
//		2016-08-18
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#pragma once

//===================================================================================================
// UDF�ο�����
typedef struct __tagUDFReference
{
	ProLine szRefName;								// �ο�����
	ProSelection pRefSel;							// �ο�ѡ�����

	__tagUDFReference()
	{
		memset(szRefName, 0, sizeof(ProLine));
		pRefSel = NULL;
	}
	__tagUDFReference(const __tagUDFReference &data)
	{
		wcsncpy_s(szRefName, PRO_LINE_SIZE, data.szRefName, _TRUNCATE);
		pRefSel = data.pRefSel;
	}
	__tagUDFReference operator=(const __tagUDFReference &data)
	{
		if (&data == this)
			return *this;
		wcsncpy_s(szRefName, PRO_LINE_SIZE, data.szRefName, _TRUNCATE);
		pRefSel = data.pRefSel;
		return *this;
	}
}UDFReference;

// UDF�ߴ綨��
typedef struct __tagUDFDimension
{
	ProName szDimName;								// �ߴ�����
	double dDimValue;								// �ߴ�ֵ

	__tagUDFDimension()
	{
		memset(szDimName, 0, sizeof(ProName));
		dDimValue = 0.0;
	}
	__tagUDFDimension(const __tagUDFDimension &data)
	{
		wcsncpy_s(szDimName, PRO_NAME_SIZE, data.szDimName, _TRUNCATE);
		dDimValue = data.dDimValue;
	}
	__tagUDFDimension operator=(const __tagUDFDimension &data)
	{
		if (&data == this)
			return *this;
		wcsncpy_s(szDimName, PRO_NAME_SIZE, data.szDimName, _TRUNCATE);
		dDimValue = data.dDimValue;
		return *this;
	}
}UDFDimension;

// UDF����
typedef struct __tagUDFDefinition
{
	CString strUDFPath;								// UDF·��
	vector<UDFReference> arrRefs;					// �ο���
	vector<UDFDimension> arrDims;					// �ߴ缯

	__tagUDFDefinition()
	{
	}
	__tagUDFDefinition(const __tagUDFDefinition &data)
	{
		strUDFPath = data.strUDFPath;
		arrRefs = data.arrRefs;
		arrDims = data.arrDims;
	}
	__tagUDFDefinition operator=(const __tagUDFDefinition &data)
	{
		if (&data == this)
			return *this;
		strUDFPath = data.strUDFPath;
		arrRefs = data.arrRefs;
		arrDims = data.arrDims;
		return *this;
	}
}UDFDefinition;

//===================================================================================================
// UDF�ӿ���
class CPCLUDF
{
public:
	CPCLUDF();
	virtual ~CPCLUDF();

public:
	// ����UDF
	static BOOL CreateUDF(
		ProSolid pSld,								// UDF��������ģ��(in)
		UDFDefinition &udfDef,						// UDF���ݶ���(in)
		ProGroup &udf								// UDF������(out)
		);
};

//===================================================================================================
