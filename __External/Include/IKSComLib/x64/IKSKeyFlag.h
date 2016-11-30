//===================================================================================================
// File:
//		IKSKeyFlag.h
// Summary:
//		关键件符号
// Date:
//		2016-01-12
// Author:
//		Wumingli(wumingli007@163.com)
//===================================================================================================

#pragma once

//===================================================================================================

#include "IKSSymbol.h"

//===================================================================================================

typedef enum __tagKeyFlagType
{
	KFT_KEYFLAG					= 1,					// 关键件
	KFT_KEYIMPORTANCEFLAG		= 2,					// 重要件
}KeyFlagType;

//===================================================================================================

// 关重件标记
class CIKSKeyFlag : public CIKSSymbol
{
public:
	CIKSKeyFlag(void);
	virtual ~CIKSKeyFlag(void);

public:
	// 根据关键件信息生成曲线集和注释集
	BOOL GetCurvesAndNotes(
		const KeyFlagType &eKeyType,		// 关键件类型(in)
		double dLineWidth,					// 线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSCurveArray &arrCurves,			// 几何集(out)
		IKSNoteArray &arrNotes,				// 注释集(out)
		IKSAnnoAttribute &attr				// 标注属性(out)
		);
	
	// 生成曲线集
	BOOL GetCurves(
		IKSCurveArray &arrCurves			// 几何集(out)
		);

private:
	double m_dLength;						// 方框长度
	double m_dWidth;						// 方框宽度
};

// 标题栏关重件标记
class CIKSTitleKeyFlag : public CIKSSymbol
{
public:
	CIKSTitleKeyFlag(void);
	virtual ~CIKSTitleKeyFlag(void);

public:
	// 根据关键件信息生成曲线集和注释集
	BOOL GetCurvesAndNotes(
		const KeyFlagType &eKeyType,		// 关键件类型(in)
		double dLineWidth,					// 线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSCurveArray &arrCurves,			// 几何集(out)
		IKSNoteArray &arrNotes,				// 注释集(out)
		IKSAnnoAttribute &attr				// 标注属性(out)
		);

	// 生成曲线集
	BOOL GetCurves(
		IKSCurveArray &arrCurves			// 几何集(out)
		);

private:
	double m_dLength;						// 方框长度
	double m_dWidth;						// 方框宽度
};