//===================================================================================================
// Summary:
//		粗糙度符号
// Date:
//		2015-08-01			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSSurfaceFinish_h__
#define __IKSSurfaceFinish_h__

//===================================================================================================

#include "IKSSymbol.h"

//===================================================================================================

// 表面粗糙度的基本符号类型
typedef enum __tagSurfFinishSymbolType
{
	SURF_SYMBOL1	= 1,			// 去除材料
	SURF_SYMBOL2	= 2,			// 不去除材料
	SURF_SYMBOL3	= 3				// 允许任何工艺
} SurfFinishSymbolType;

// 表面粗糙度的纹理类型
typedef enum __tagSurfFinishTexturetype
{
	SURF_TEXTURE_PARALLEL	= 1,		// 平行
	SURF_TEXTURE_VERTICAL	= 2,		// 垂直
	SURF_TEXTURE_CROSS		= 3,		// 交叉
	SURF_TEXTURE_MULTI		= 4,		// 多个方向
	SURF_TEXTURE_CIRCLE		= 5,		// 同心
	SURF_TEXTURE_RADIATION	= 6,		// 放射
	SURF_TEXTURE_P			= 7,		// 无方向或成凸起的细粒形
	SURF_TEXTURE_CLEAR		= 8			// 无
} SurfFinishTexturetype;

//===================================================================================================

// 表面粗糙度信息
typedef struct __tagSurfFinishInfo
{
	int nSymbolType;			// 基本符号类型， 参考SurfFinishSymbolType枚举值
	int nTextureType;			// 纹理， 参考SurfFinishTexturetype枚举值
	int nAttachType;			// 放置方式，参考SDSymbolAttachType枚举值
	CString	strSurfText1;		// 右侧尺寸1
	CString	strSurfText2;		// 右侧尺寸2
	CString	strSurfText3;		// 右侧尺寸3
	CString	strOther;			// 其余
	CString	strSurfMin;			// 最小尺寸
	CString	strSurfMax;			// 最大尺寸
	BOOL bSameReq;				// 相同要求
	double dAngle;				// 角度
	double dTextHeight;			// 文本高度
	BOOL bIsFlip;				// 是否反向;（只有在nAttachType为SATYPE_NORM_ITEM时有效）

	__tagSurfFinishInfo()
	{
		nSymbolType = SURF_SYMBOL1;
		nTextureType = SURF_TEXTURE_CLEAR;
		nAttachType = SATYPE_NORM_ITEM;
		strSurfText1 = _T("");
		strSurfText2 = _T("");
		strSurfText3 = _T("");
		strOther = _T("");
		strSurfMin = _T("");
		strSurfMax = _T("");
		bSameReq = FALSE;
		dAngle = 0;
		dTextHeight = 3.5;
		bIsFlip = FALSE;
	}
	void operator=(const __tagSurfFinishInfo& info){
		nSymbolType = info.nSymbolType;	
		nTextureType = info.nTextureType;
		nAttachType = info.nAttachType;
		strSurfText1 = info.strSurfText1;
		strSurfText2 = info.strSurfText2;
		strSurfText3 = info.strSurfText3;
		strOther = info.strOther;
		strSurfMin = info.strSurfMin;
		strSurfMax = info.strSurfMax;
		bSameReq = info.bSameReq;
		dAngle = info.dAngle;
		dTextHeight = info.dTextHeight;
		bIsFlip = info.bIsFlip;
	}
} SurfFinishInfo;

//===================================================================================================

class CIKSSurfaceFinish : public CIKSSymbol
{
public:
	CIKSSurfaceFinish();
	virtual ~CIKSSurfaceFinish();

public:
	// 根据表面粗糙度信息生成曲线集和注释集
	BOOL GetCurvesAndNotes(
		const SurfFinishInfo &surfInfo,		// 表面粗糙度信息(in)
		double dLineWidth,					// 线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数，如果传入为空，则使用默认函数(in)
		IKSCurveArray &arrCurves,			// 几何集(out)
		IKSNoteArray &arrNotes,				// 注释集(out)
		IKSAnnoAttribute &attr				// 标注属性(out)
		);

private:
	// 获取表面粗糙度核心的曲线集
	BOOL GetBaseSymbolCurves(
		int nSymbolType,					// 粗糙度符号类型(in)
		IKSCurveArray &arrCurves			// 曲线集(out)
		);
	// 获取表面粗糙度纹理的曲线集
	BOOL GetTextureCurves(
		int nTextureType,					// 纹理类型(in)
		double dLineWidth,					// 线宽(in)
		IKSCurveArray &arrCurves			// 曲线集(out)
		);
	// 获取相同要求的曲线集
	BOOL GetSameReqCurves(
		double dLineWidth,					// 线宽(in)
		IKSCurveArray &arrCurves			// 曲线集(out)
		);
	// 获取右侧的注释线
	BOOL GetSurfTextCurves(
		const SurfFinishInfo &surfInfo,		// 表面粗糙度信息(in)
		IKSBox dSurfText1Outline,			// 右侧尺寸1的包围盒(in)
		IKSBox dSurfText2Outline,			// 右侧尺寸2的包围盒(in)
		IKSBox dSurfText3Outline,			// 右侧尺寸3的包围盒(in)
		double dLineWidth,					// 线宽(in)
		IKSCurveArray &arrCurves			// 曲线集(out)
		);
	// 获取右侧尺寸1的注释集
	BOOL GetSurfText1Notes(
		const CString &strSurfText1,		// 右侧尺寸1(in)
		double dLineWidth,					// 线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSNoteArray &arrSurfText1Notes,	// 右侧尺寸1的注释集(out)
		IKSBox dSurfText1Outline			// 右侧尺寸1的包围盒(out)
		);
	// 获取右侧尺寸2的注释集
	BOOL GetSurfText2Notes(
		const CString &strSurfText2,		// 右侧尺寸2(in)
		double dLineWidth,					// 线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSNoteArray &arrSurfText2Notes,	// 右侧尺寸2的注释集(out)
		IKSBox dSurfText2Outline			// 右侧尺寸2的包围盒(out)
		);
	// 获取右侧尺寸3的注释集
	BOOL GetSurfText3Notes(
		const CString &strSurfText3,		// 右侧尺寸3(in)
		double dLineWidth,					// 线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSNoteArray &arrSurfText3Notes,	// 右侧尺寸3的注释集(out)
		IKSBox dSurfText3Outline			// 右侧尺寸3的包围盒(out)
		);
	// 获取其余尺寸的注释集
	BOOL GetOtherNotes(
		const CString &strOther,			// 其余尺寸(in)
		double dLineWidth,					// 线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSNoteArray &arrOtherNotes			// 其余尺寸的注释集(out)
		);
	// 获取最小尺寸的注释集
	BOOL GetSurfMinNotes(
		const CString &strSurfMin,			// 最小尺寸(in)
		double dLineWidth,					// 线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSNoteArray &arrSurfMinNotes		// 最小尺寸的注释集(out)
		);
	// 获取最大尺寸的注释集
	BOOL GetSurfMaxNotes(
		const CString &strSurfMax,			// 最大尺寸(in)
		double dLineWidth,					// 线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSNoteArray &arrSurfMaxNotes		// 最大尺寸的注释集(out)
		);

private:
	double m_dh;							// 数字和字母高度h，具体含义见GB/T 131-2006
	double m_dH1;							// 高度H1，具体含义见GB/T 131-2006
	double m_dH2;							// 高度H2，具体含义见GB/T 131-2006
};

//===================================================================================================

#endif