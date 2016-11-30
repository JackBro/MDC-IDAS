//===================================================================================================
// File:
//		IKSCutting.h
// Summary:
//		剖切符号
// Date:
//		2016-04-27
// Author:
//		Wumingli(wumingli007@163.com)
//===================================================================================================

#pragma once

//===================================================================================================

#include "IKSSymbol.h"

//===================================================================================================

typedef struct _tagCuttingInfo
{
	double RefPosX;				// 剖切符号第二个放置点X
	CString strName;			// 剖切符号名称

	_tagCuttingInfo()
	{
		RefPosX = 0.0;
		strName = L"Undefine";
	}

	_tagCuttingInfo &operator=(const _tagCuttingInfo& info){
		if (&info != this)
		{
			RefPosX = info.RefPosX;
			strName = info.strName;
		}
		return *this;
	}
}CuttingInfo;

//===================================================================================================


class CIKSCutting :public CIKSSymbol
{
public:
	CIKSCutting(void);
	virtual ~CIKSCutting(void);

public:
	// 根据剖切符号信息生成曲线集和注释集
	BOOL GetCurvesAndNotes(
		const CuttingInfo& cuttingInfo,		// 剖切符号信息(in)
		double dLineWidth,					// 线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数，如果传入为空，则使用默认函数(in)
		IKSCurveArray &arrCurves,			// 几何集(out)
		IKSNoteArray &arrNotes,				// 注释集(out)
		IKSAnnoAttribute &attr				// 标注属性(out)
		);
	// 获取剖切符号的曲线集
	BOOL GetCurves(
		double dLineWidth,					// 线宽(in)
		IKSCurveArray &arrCurves			// 几何集(out)
		);
};
