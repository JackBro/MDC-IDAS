//===================================================================================================
// File:
//		PCLUDF.h
// Summary:
//		UDF接口类
// Date:
//		2016-08-18
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#pragma once

//===================================================================================================
// UDF参考定义
typedef struct __tagUDFReference
{
	ProLine szRefName;								// 参考名称
	ProSelection pRefSel;							// 参考选择对象

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

// UDF尺寸定义
typedef struct __tagUDFDimension
{
	ProName szDimName;								// 尺寸名称
	double dDimValue;								// 尺寸值

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

// UDF定义
typedef struct __tagUDFDefinition
{
	CString strUDFPath;								// UDF路径
	vector<UDFReference> arrRefs;					// 参考集
	vector<UDFDimension> arrDims;					// 尺寸集

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
// UDF接口类
class CPCLUDF
{
public:
	CPCLUDF();
	virtual ~CPCLUDF();

public:
	// 创建UDF
	static BOOL CreateUDF(
		ProSolid pSld,								// UDF特征所在模型(in)
		UDFDefinition &udfDef,						// UDF数据定义(in)
		ProGroup &udf								// UDF特征组(out)
		);
};

//===================================================================================================
