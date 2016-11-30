//===================================================================================================
// File:
//		IKSViewDirectionScale.h
// Summary:
//		视向比例符号
// Date:
//		2016-11-08
// Author:
//		lgq
//===================================================================================================

#pragma once

//===================================================================================================

#include "IKSSymbol.h"

//===================================================================================================

// 视向比例符号上文本类型
typedef enum __tagViewDirectionScaleUpTextType
{
	VDSUTT_A				= 0,		// A
	VDSUTT_A_A				= 1,		// A-A
	VDSUTT_A_DIR			= 2			// A向
} ViewDirectionScaleUpTextType;

// 视向比例符号信息
typedef struct __tagViewDirectionScaleInfo
{
	CString strUpText;								// 上文本
	int nUpTextType;								// 上文本类型
	CString strDownLeftScale;						// 下文本左比例
	CString strDownRightScale;						// 下文本右比例

	__tagViewDirectionScaleInfo()
	{
		strUpText = _T("A");
		nUpTextType = VDSUTT_A_A;
		strDownLeftScale = _T("1");
		strDownRightScale = _T("1");
	}
	__tagViewDirectionScaleInfo(const __tagViewDirectionScaleInfo &data)
	{
		strUpText = data.strUpText;
		nUpTextType = data.nUpTextType;
		strDownLeftScale = data.strDownLeftScale;
		strDownRightScale = data.strDownRightScale;
	}
	__tagViewDirectionScaleInfo operator=(const __tagViewDirectionScaleInfo &data)
	{
		if (&data == this)
			return *this;
		strUpText = data.strUpText;
		nUpTextType = data.nUpTextType;
		strDownLeftScale = data.strDownLeftScale;
		strDownRightScale = data.strDownRightScale;
		return *this;
	}
}ViewDirectionScaleInfo;

//===================================================================================================

// 关重件标记
class CIKSViewDirectionScale : public CIKSSymbol
{
public:
	CIKSViewDirectionScale(void);
	virtual ~CIKSViewDirectionScale(void);

public:
	// 根据视向比例信息生成曲线集和注释集
	BOOL GetCurvesAndNotes(
		const ViewDirectionScaleInfo &info,	// 视向比例信息(in)
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
	double m_dItemMinDist;					// 元素之间的最小间距
	double m_dLength;						// 方框长度
	double m_dWidth;						// 方框宽度
};
