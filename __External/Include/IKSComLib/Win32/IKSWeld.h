//===================================================================================================
// Summary:
//		焊接符号
// Date:
//		2015-08-01			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSWeld_h__
#define __IKSWeld_h__

//===================================================================================================

#include "IKSSymbol.h"

//===================================================================================================

// 焊接基本符号类型
typedef enum __tagWeldingBaseType
{
	WELD_BASE_NULL			= 0,			// 非法
	WELD_BASE_TYPE1			= 1,			// 卷边焊缝
	WELD_BASE_TYPE2			= 2,			// I形焊缝
	WELD_BASE_TYPE3			= 3,			// V形焊缝
	WELD_BASE_TYPE4			= 4,			// 单边V形焊缝
	WELD_BASE_TYPE5			= 5,			// 带钝边V形焊缝
	WELD_BASE_TYPE6			= 6,			// 带钝边单边V形焊缝
	WELD_BASE_TYPE7			= 7,			// 带钝边U形焊缝
	WELD_BASE_TYPE8			= 8,			// 带钝边J形焊缝
	WELD_BASE_TYPE9			= 9,			// 封底焊缝
	WELD_BASE_TYPE10		= 10,			// 角焊缝
	WELD_BASE_TYPE11		= 11,			// 塞焊缝或槽焊缝
	WELD_BASE_TYPE12		= 12,			// 点焊缝
	WELD_BASE_TYPE13		= 13,			// 缝焊缝
	WELD_BASE_TYPE14		= 14,			// 陡边V形焊缝
	WELD_BASE_TYPE15		= 15,			// 陡边单V形焊缝
	WELD_BASE_TYPE16		= 16,			// 端焊缝
	WELD_BASE_TYPE17		= 17,			// 堆焊缝
	WELD_BASE_TYPE18		= 18,			// 平面连接（钎焊）
	WELD_BASE_TYPE19		= 19,			// 斜面连接（钎焊）
	WELD_BASE_TYPE20		= 20,			// 折叠连接（钎焊）
	WELD_BASE_TYPE21		= 21,			// 喇叭形焊缝
	WELD_BASE_TYPE22		= 22,			// 单边喇叭形焊缝
	WELD_BASE_TYPE23		= 23,			// 锁边焊缝
} WeldingBaseType;

// 焊接补充符号类型(平面)
typedef enum __tagWeldingContourType
{
	WELD_CONTOUR_NULL		= 30,
	WELD_CONTOUR_FLAT		= 31,			// 平面
	WELD_CONTOUR_CONCAVE	= 32,			// 凹面
	WELD_CONTOUR_CONVEX		= 33,			// 凸面
	WELD_CONTOUR_SMOOTH		= 34,			// 圆滑过渡
	WELD_CONTOUR_FILLET		= 35,			// 角焊缝
} WeldingContourType;

// 焊接补充符号类型(衬垫)
typedef enum __tagWeldingStripType
{
	WELD_STRIP_NULL			= 40,
	WELD_STRIP_PERMANENT	= 41,			// 永久衬垫
	WELD_STRIP_REMOVABLE	= 42,			// 临时衬垫
} WeldingStripType;

// 焊接补充符号类型（三面焊缝）
typedef enum __tagWeldingFaceType
{
	WELD_FACE_NULL			= 50,
	WELD_FACE_RIGHT			= 51,
	WELD_FACE_LEFT			= 52,
	WELD_FACE_UP			= 53,
	WELD_FACE_DOWN			= 54,
} WeldingFaceType;

// 焊接补充符号类型（尾部）
typedef enum __tagWeldingTailType
{
	WELD_TAIL_NULL			= 60,
	WELD_TAIL_TYPE1			= 61,
	WELD_TAIL_TYPE2			= 62	
} WeldingTailType;

// 焊接符号位置
typedef enum __tagWeldingLocation
{
	WELD_LOCATION_UP		= 0,
	WELD_LOCATION_CENTER	= 1,
	WELD_LOCATION_DOWN		= 2
} WeldingLocation;

// 焊接虚线位置
typedef enum __tagWeldingDashPosition
{
	WELD_DASH_UP			= 0,
	WELD_DASH_DOWN			= 1,
	WELD_DASH_NONE			= 2
} WeldingDashPosition;

//===================================================================================================

// 焊接符号信息
typedef struct __tagWeldingInfo
{
	int nUpBaseType;			// 符号位置在上方时，基本符号类型, 参考WeldingBaseType枚举值
	int nDownBaseType;			// 符号位置在下方时，基本符号类型, 参考WeldingBaseType枚举值
	int nCenterBaseType;		// 符号位置在中间时，基本符号类型, 参考WeldingBaseType枚举值，WELD_BASE_TYPE12和WELD_BASE_TYPE13才有效

	int nUpContourType;			// 符号位置在上方时，平面补充符号类型，参考WeldingContourType枚举值
	int nDownContourType;		// 符号位置在下方时，平面补充符号类型，参考WeldingContourType枚举值
	int nLocation;				// 焊接符号位置, 参考WeldingLocation枚举值

	int nUpStripType;			// 符号位置在上方时，焊接补充符号类型(衬垫)，参考WeldingStripType枚举值
	int nDownStripType;			// 符号位置在下方时，焊接补充符号类型(衬垫)，参考WeldingStripType枚举值

	int nTailType;				// 尾部焊接补充符号类型，参考WeldingTailType枚举值

	CString strUpLeftValue;		// 符号位置在上方时，左尺寸
	CString strUpRootGap;		// 符号位置在上方时，根部间隙
	CString strUpUpperValue;	// 符号位置在上方时，上尺寸
	CString strUpRightValue1;	// 符号位置在上方时，右尺寸1
	CString strUpRightValue2;	// 符号位置在上方时，右尺寸2
	CString strUpRightValue3;	// 符号位置在上方时，右尺寸3
	CString strDownLeftValue;	// 符号位置在下方时，左尺寸
	CString strDownRootGap;		// 符号位置在下方时，根部间隙
	CString strDownUpperValue;	// 符号位置在下方时，上尺寸
	CString strDownRightValue1;	// 符号位置在下方时，右尺寸1
	CString strDownRightValue2;	// 符号位置在下方时，右尺寸2
	CString strDownRightValue3;	// 符号位置在下方时，右尺寸3
	CString strCenterLeftValue;	// 符号位置在下方时，左尺寸
	CString strCenterUpperValue;	// 符号位置在中间时，上尺寸
	CString strCenterRightValue1;	// 符号位置在中间时，右尺寸1
	CString strCenterRightValue2;	// 符号位置在中间时，右尺寸2
	CString strCenterRightValue3;	// 符号位置在中间时，右尺寸3


	CString strNote;			// 焊接说明
	int nDashPosition;			// 焊接虚线位置
	BOOL bAround;				// 是否为周围焊接符号
	BOOL bScene;				// 是否为现场符号
	BOOL bStagger;				// 是否为交错断续焊接符号

	int nTriFaceType;			// 三面焊缝焊接补充符号类型，参考WeldingFaceType枚举值

	int nAngle;					// 放置角度

	BOOL bLeaderOrientLeft;		// 焊接的引线方向，TURE为左，FALSE时为右

	__tagWeldingInfo()
	{
		Init();	
	}

	void operator=(const __tagWeldingInfo& info){
		nUpBaseType = info.nUpBaseType;			
		nDownBaseType = info.nDownBaseType;			
		nCenterBaseType = info.nCenterBaseType;
		nUpContourType = info.nUpContourType;
		nDownContourType = info.nDownContourType;
		nUpStripType = info.nUpStripType;
		nDownStripType = info.nDownStripType;
		nLocation = info.nLocation;	
		nTailType = info.nTailType;
		strUpLeftValue = info.strUpLeftValue;	
		strUpRootGap = info.strUpRootGap;
		strUpUpperValue = info.strUpUpperValue;	
		strUpRightValue1 = info.strUpRightValue1;	
		strUpRightValue2 = info.strUpRightValue2;
		strUpRightValue3 = info.strUpRightValue3;
		strDownLeftValue = info.strDownLeftValue;	
		strDownRootGap = info.strDownRootGap;
		strDownUpperValue = info.strDownUpperValue;	
		strDownRightValue1 = info.strDownRightValue1;	
		strDownRightValue2 = info.strDownRightValue2;
		strDownRightValue3 = info.strDownRightValue3;
		strCenterLeftValue = info.strCenterLeftValue;	
		strCenterUpperValue = info.strCenterUpperValue;	
		strCenterRightValue1 = info.strCenterRightValue1;	
		strCenterRightValue2 = info.strCenterRightValue2;
		strCenterRightValue3 = info.strCenterRightValue3;

		strNote = info.strNote;

		nDashPosition = info.nDashPosition;

		bAround = info.bAround;
		bScene = info.bScene;
		bStagger = info.bStagger;
		nTriFaceType = info.nTriFaceType;
		nAngle = info.nAngle;
		bLeaderOrientLeft = info.bLeaderOrientLeft;
	}

	void Init()
	{
		nUpBaseType = WELD_BASE_NULL;			
		nDownBaseType = WELD_BASE_NULL;	
		nCenterBaseType = WELD_BASE_NULL;
		nLocation = WELD_LOCATION_UP;
		nUpContourType = WELD_CONTOUR_NULL;
		nDownContourType = WELD_CONTOUR_NULL;
		nUpStripType = WELD_STRIP_NULL;
		nDownStripType = WELD_STRIP_NULL;
		strUpLeftValue = _T("");	
		strUpRootGap = _T("");	
		strUpUpperValue = _T("");	
		strUpRightValue1 = _T("");	
		strUpRightValue2 = _T("");	
		strDownLeftValue = _T("");	
		strDownRootGap = _T("");	
		strDownUpperValue = _T("");	
		strDownRightValue1 = _T("");	
		strDownRightValue2 = _T("");
		strCenterLeftValue = _T("");
		strCenterUpperValue = _T("");	
		strCenterRightValue1 = _T("");
		strCenterRightValue2 = _T("");	
		strCenterRightValue3 = _T("");	
		strNote = _T("");		
		strUpRightValue3 = _T("");		
		strDownRightValue3 = _T("");	
		nDashPosition = WELD_DASH_DOWN;	
		bAround = FALSE;
		bScene = FALSE;
		nTailType = WELD_TAIL_TYPE1;
		bStagger = FALSE;
		nTriFaceType = WELD_FACE_NULL;
		nAngle = 0;
		bLeaderOrientLeft = TRUE;
	}
} WeldingInfo;

//===================================================================================================

class CIKSWeld : public CIKSSymbol
{
public:
	CIKSWeld();
	virtual ~CIKSWeld();

public:
	// 根据焊接信息生成曲线集和注释集
	BOOL GetCurvesAndNotes(
		const WeldingInfo &weldInfo,		// 焊接信息(in)
		double dLineWidth,					// 线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数，如果传入为空，则使用默认函数(in)
		IKSCurveArray &arrCurves,			// 几何集(out)
		IKSNoteArray &arrNotes,				// 注释集(out)
		IKSAnnoAttribute &attr				// 标注属性(out)
		);

private:
	// 获取焊接符号核心的曲线集
	BOOL GetkernelCurvesAndNotes(
		const WeldingInfo &weldInfo,		// 焊接信息(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSCurveArray &arrCurves,			// 曲线集(out)
		IKSNoteArray &arrNotes,				// 注释集(out)
		IKSBox dUpBaseOutline,				// 上方基本符号的包围盒(out)
		IKSBox dDownBaseOutline				// 下方基本符号的包围盒(out)
		);

	// 获取焊接基本符号的曲线集
	BOOL GetBaseSymbolCurvesAndNotes(
		int nBaseType,						// 基本符号类型(in)
		int nStripType,						// 衬垫类型(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSCurveArray &arrCurves,			// 曲线集(out)
		IKSNoteArray &arrNotes,				// 注释集(out)
		IKSBox dBaseOutline					// 基本符号的包围盒(out)
		);

	// 获取根部间隙的注释集
	BOOL GetRootGapNotes(
		const WeldingInfo &weldInfo,		// 焊接信息(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSBox dUpBaseOutline,				// 上方基本符号的包围盒(out)
		IKSBox dDownBaseOutline,			// 下方基本符号的包围盒(out)
		IKSNoteArray &arrRootGapNotes		// 注释集(out)
		);

	// 获取补充符号的曲线集
	BOOL GetAllContourCurves(
		const WeldingInfo &weldInfo,		// 焊接信息(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSBox dUpBaseOutline,				// 上方基本符号的包围盒(in)
		IKSBox dDownBaseOutline,			// 下方基本符号的包围盒(in)
		IKSCurveArray &arrContourCurves,	// 补充符号的曲线集(out)
		IKSBox dUpContourOutline,			// 上方基本符号的包围盒(out)
		IKSBox dDownContourOutline			// 下方基本符号的包围盒(out)
		);

	// 修正基本符号为角焊缝时补充符号的包围盒
	BOOL VerifyWeldFilletContourOutline(
		int nContourType,					// 补充符号类型(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSBox dContourOutline				// 补充符号的包围盒(out)
		);

	// 获取补充符号的曲线集
	BOOL GetContourCurves(
		int nContourType,					// 补充符号类型(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSCurveArray &arrContourCurves,	// 补充符号的曲线集(out)
		IKSBox dContourOutline				// 补充符号的包围盒(out)
		);

	// 获取左尺寸的注释集
	BOOL GetLeftValueNotes(
		const CString &strUpLeftValue,		// 上方左尺寸(in)
		const CString &strDownLeftValue,	// 下方左尺寸(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSBox dUpMainOutline,				// 上方主要区域包围盒(in)
		IKSBox dDownMainOutline,			// 下方主要区域包围盒(in)
		IKSNoteArray &arrLeftValueNotes,	// 左尺寸的注释集(out)
		IKSBox dUpLeftValueOutline,			// 上方左尺寸的包围盒(out)
		IKSBox dDownLeftValueOutline		// 下方左尺寸的包围盒(out)
		);

	// 获取上尺寸的注释集
	BOOL GetUpperValueNotes(
		const CString &strUpUpperValue,		// 上方上尺寸(in)
		const CString &strDownUpperValue,	// 下方上尺寸(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSBox dUpMainOutline,				// 上方主要区域包围盒(in)
		IKSBox dDownMainOutline,			// 下方主要区域包围盒(in)
		IKSNoteArray &arrUpperValueNotes,	// 上尺寸的注释集(out)
		IKSBox dUpUpperValueOutline,		// 上方上尺寸的包围盒(out)
		IKSBox dDownUpperValueOutline		// 下方上尺寸的包围盒(out)
		);

	// 获取右尺寸1的注释集
	BOOL GetRightValue1Notes(
		const CString &strUpRightValue1,	// 上方右尺寸1(in)
		const CString &strDownRightValue1,	// 下方右尺寸1(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSBox dUpMainOutline,				// 上方主要区域包围盒(in)
		IKSBox dDownMainOutline,			// 下方主要区域包围盒(in)
		IKSNoteArray &arrRightValue1Notes,	// 右尺寸1的注释集(out)
		IKSBox dUpRightValue1Outline,		// 上方右尺寸1的包围盒(out)
		IKSBox dDownRightValue1Outline		// 下方右尺寸1的包围盒(out)
		);

	// 获取右尺寸2的注释集
	BOOL GetRightValue2Notes(
		const CString &strUpRightValue2,	// 上方右尺寸2(in)
		const CString &strDownRightValue2,	// 下方右尺寸2(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSBox dUpLeftItemOutline,			// 上方左侧项目的包围盒(in)
		IKSBox dDownLeftItemOutline,		// 下方左侧项目的包围盒(in)
		IKSNoteArray &arrRightValue2Notes,	// 右尺寸2的注释集(out)
		IKSBox dUpRightValue2Outline,		// 上方右尺寸2的包围盒(out)
		IKSBox dDownRightValue2Outline		// 下方右尺寸2的包围盒(out)
		);

	// 获取交错断续符号曲线集
	BOOL GetStaggerCurves(
		double dLineWidth,					// 图形符号的线宽(in)
		IKSBox dUpItemOutline,				// 上方左侧项目的包围盒(in)
		IKSBox dDownItemOutline,			// 下方左侧项目的包围盒(in)
		IKSCurveArray &arrStaggerCurves,	// 交错断续符号曲线集(out)
		IKSBox dUpStaggerOutline,			// 上方交错断续符号的包围盒(out)
		IKSBox dDownStaggerOutline			// 下方交错断续符号的包围盒(out)
		);

	// 获取右尺寸3的注释集
	BOOL GetRightValue3Notes(
		const CString &strUpRightValue3,	// 上方右尺寸3(in)
		const CString &strDownRightValue3,	// 下方右尺寸3(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		IKSBox dUpItemOutline,				// 上方左侧项目的包围盒(in)
		IKSBox dDownItemOutline,			// 下方左侧项目的包围盒(in)
		IKSNoteArray &arrRightValue3Notes,	// 右尺寸3的注释集(out)
		IKSBox dUpRightValue3Outline,		// 上方右尺寸3的包围盒(in)
		IKSBox dDownRightValue3Outline		// 下方右尺寸3的包围盒(in)
		);

	// 获取三面焊缝曲线集
	BOOL GetTriFaceCurves(
		int nTriFaceType,					// 三面焊缝类型(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSBox dUpItemOutline,				// 上方右侧项目的包围盒(in)
		IKSBox dDownItemOutline,			// 下方右侧项目的包围盒(in)
		IKSCurveArray &arrTriFaceCurves,	// 三面焊缝曲线集(out)
		IKSBox dTriFaceOutline				// 三面焊缝的包围盒(out)
	);

	// 获取现场符号曲线集
	BOOL GetSceneCurves(
		BOOL bLeaderOrientLeft,				// 引线向左(in)
		double dLineWidth,					// 图形符号的线宽(in)
		double dScenePos,					// 现场符号位置(in)
		IKSCurveArray &arrSceneCurves		// 现场符号曲线集(out)
		);

	// 获取周围焊缝符号曲线集
	BOOL GetAroundCurves(
		double dLineWidth,					// 图形符号的线宽(in)
		double dAroundPos,					// 周围焊缝符号位置(in)
		IKSCurveArray &arrAroundCurves		// 周围焊缝符号曲线集(out)
		);

	// 获取尾部符号曲线集
	BOOL GetTailCurves(
		int nTailType,						// 尾部符号类型(in)
		BOOL bLeaderOrientLeft,				// 引线向左(in)
		double dLineWidth,					// 图形符号的线宽(in)
		double dTailPos,					// 尾部符号位置(in)
		IKSCurveArray &arrTailCurves		// 尾部符号曲线集(out)
		);

	// 获取焊接说明的注释集
	BOOL GetWeldNoteNotes(
		const CString &strNote,				// 焊接说明(in)
		BOOL bLeaderOrientLeft,				// 引线向左(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数(in)
		double dTailPos,					// 尾部符号位置(in)
		double dLineWidth,					// 图形符号的线宽(in)
		IKSNoteArray &arrWeldNoteNotes		// 焊接说明的注释集(out)
		);

	// 获取实线和虚线
	BOOL GetBaseLineAndDashLineCurves(
		int nDashPosition,					// 虚线位置(in)
		double dLeftLength,					// 原点向左长度(in)
		double dRightLength,				// 原点向右长度(in)
		IKSCurveArray &arrCurves			// 曲线集(out)
		);

private:
	double m_dItemMinDist;					// 元素之间的最小间距
	double m_dDashLength;					// 虚线长度
	double m_dDashDist;						// 虚线与实线距离
};

//===================================================================================================

#endif