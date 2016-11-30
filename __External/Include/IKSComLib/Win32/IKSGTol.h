//===================================================================================================
// Summary:
//		形位公差符号
// Date:
//		2015-11-17			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSGTol_h__
#define __IKSGTol_h__

//===================================================================================================

#include "IKSSymbol.h"

//===================================================================================================

// 设定公差类型
typedef enum __tagSdGtolType
{
	GTOL_UNKNOWN          = 0,
	GTOL_STRAIGHTNESS     = 1,	// 直线度
	GTOL_FLATNESS         = 2,	// 平面度
	GTOL_CIRCULAR         = 3,	// 圆度
	GTOL_CYLINDRICAL      = 4,	// 圆柱度
	GTOL_LINE             = 5,	// 线轮廓度
	GTOL_SURFACE          = 6,	// 曲面轮廓度
	GTOL_PARALLEL         = 7,	// 平行度
	GTOL_PERPENDICULAR    = 8,	// 垂直度
	GTOL_ANGULAR          = 9,	// 倾斜度
	GTOL_POSITION         = 10,	// 位置度
	GTOL_CONCENTRICITY    = 11,	// 同轴度
	GTOL_SYMMETRY         = 12,	// 对称度
	GTOL_CIRCULAR_RUNOUT  = 13,	// 圆跳动
	GTOL_TOTAL_RUNOUT     = 14	// 全跳动
};

// 形位公差放置方式
typedef enum __tagSdGtolPlacementType
{
	GPTYPE_UNKNOWN			= -1,
	GPTYPE_NORMLEADER		= 0,	// 引线垂直于图元
	GPTYPE_TOITEMLEADERS	= 1,	// 引线指向图元
	GPTYPE_FREELEADERS		= 2,	// 引线自由放置
	GPTYPE_DIM				= 3,	// 尺寸放置
	GPTYPE_GTOL				= 4,	// 其它几何公差
	GPTYPE_FREENOTE			= 5,	// 自由放置
} SdGtolPlacementType;

// 几何公差基本信息
typedef struct __tagGtolBaseInfo
{
	int		nSymbolType;						// 基本符号类型
	double	dValue;								// 公差值
	CString	strPrefix;							// 前缀
	CString	strSuffix1;							// 后缀1
	CString	strSuffix2;							// 后缀2
	BOOL	bAllAround;							// 全周符号
	CString	strNoteTop;							// 上方附注
	CString	strNoteBack;						// 后方附注
	CString	strDatumName11;						// 第一基准名称
	CString	strDatumMatCond11;					// 第一基准参照选取材料条件
	CString	strDatumName12;						// 第一复合基准名称
	CString	strDatumMatCond12;					// 第一复合基准参照选取材料条件
	CString	strDatumName21;						// 第二基准名称
	CString	strDatumMatCond21;					// 第二基准参照选取材料条件
	CString	strDatumName22;						// 第二复合基准名称
	CString	strDatumMatCond22;					// 第二复合基准参照选取材料条件
	CString	strDatumName31;						// 第三基准名称
	CString	strDatumMatCond31;					// 第三基准参照选取材料条件
	CString	strDatumName32;						// 第三复合基准名称
	CString	strDatumMatCond32;					// 第三复合基准参照选取材料条件

	__tagGtolBaseInfo()
	{
		nSymbolType = GTOL_UNKNOWN;
		dValue = 0.0;
		strPrefix = L"";
		strSuffix1 = L"";
		strSuffix2 = L"";
		bAllAround = FALSE;
		strNoteTop = L"";
		strNoteBack = L"";
		strDatumName11 = L"";
		strDatumMatCond11 = L"";
		strDatumName12 = L"";
		strDatumMatCond12 = L"";
		strDatumName21 = L"";
		strDatumMatCond21 = L"";
		strDatumName22 = L"";
		strDatumMatCond22 = L"";
		strDatumName31 = L"";
		strDatumMatCond31 = L"";
		strDatumName32 = L"";
		strDatumMatCond32 = L"";
	}
	__tagGtolBaseInfo(const __tagGtolBaseInfo &info)
	{
		nSymbolType = info.nSymbolType;
		dValue = info.dValue;
		strPrefix = info.strPrefix;
		strSuffix1 = info.strSuffix1;
		strSuffix2 = info.strSuffix2;
		bAllAround = info.bAllAround;
		strNoteTop = info.strNoteTop;
		strNoteBack = info.strNoteBack;
		strDatumName11 = info.strDatumName11;
		strDatumMatCond11 = info.strDatumMatCond11;
		strDatumName12 = info.strDatumName12;
		strDatumMatCond12 = info.strDatumMatCond12;
		strDatumName21 = info.strDatumName21;
		strDatumMatCond21 = info.strDatumMatCond21;
		strDatumName22 = info.strDatumName22;
		strDatumMatCond22 = info.strDatumMatCond22;
		strDatumName31 = info.strDatumName31;
		strDatumMatCond31 = info.strDatumMatCond31;
		strDatumName32 = info.strDatumName32;
		strDatumMatCond32 = info.strDatumMatCond32;
	}
	__tagGtolBaseInfo& operator=(const __tagGtolBaseInfo& info){
		if (&info == this)
			return *this;
		nSymbolType = info.nSymbolType;
		dValue = info.dValue;
		strPrefix = info.strPrefix;
		strSuffix1 = info.strSuffix1;
		strSuffix2 = info.strSuffix2;
		bAllAround = info.bAllAround;
		strNoteTop = info.strNoteTop;
		strNoteBack = info.strNoteBack;
		strDatumName11 = info.strDatumName11;
		strDatumMatCond11 = info.strDatumMatCond11;
		strDatumName12 = info.strDatumName12;
		strDatumMatCond12 = info.strDatumMatCond12;
		strDatumName21 = info.strDatumName21;
		strDatumMatCond21 = info.strDatumMatCond21;
		strDatumName22 = info.strDatumName22;
		strDatumMatCond22 = info.strDatumMatCond22;
		strDatumName31 = info.strDatumName31;
		strDatumMatCond31 = info.strDatumMatCond31;
		strDatumName32 = info.strDatumName32;
		strDatumMatCond32 = info.strDatumMatCond32;
		return *this;
	}
} GtolBaseInfo;

// 几何公差信息
typedef struct __tagGtolInfo
{
	std::vector<GtolBaseInfo> arrBaseInfo;		// 基本信息
	int		nPlacementType;						// 放置方式
	int		nLeaderType;						// 引线方式

	__tagGtolInfo()
	{
		nPlacementType = GPTYPE_NORMLEADER;
		nLeaderType = IKSAS_ARROWHEAD;
	}
	__tagGtolInfo(const __tagGtolInfo &info)
	{
		arrBaseInfo = info.arrBaseInfo;
		nPlacementType = info.nPlacementType;
		nLeaderType = info.nLeaderType;
	}
	__tagGtolInfo& operator=(const __tagGtolInfo& info){
		if (&info == this)
			return *this;
		arrBaseInfo = info.arrBaseInfo;
		nPlacementType = info.nPlacementType;
		nLeaderType = info.nLeaderType;
		return *this;
	}
} GtolInfo;

//===================================================================================================

class CIKSGTol : public CIKSSymbol
{
public:
	CIKSGTol();
	virtual ~CIKSGTol();

public:
	// 根据形位公差信息生成曲线集和注释集
	BOOL GetCurvesAndNotes(
		const GtolInfo &gtolInfo,			// 形位公差信息(in)
		double dLineWidth,					// 线宽(in)
		IKSGetNoteSizeAction action,		// 获取注释宽度和高度的回调函数，如果传入为空，则使用默认函数(in)
		IKSCurveArray &arrCurves,			// 几何集(out)
		IKSNoteArray &arrNotes,				// 注释集(out)
		IKSAnnoAttribute &attr				// 标注属性(out)
		);
	// 根据字符串生成注释集
	BOOL GetCStringNotes(
		CString strc,							// 字符串
		BOOL bChangeBracket,					// 是否将()转化为圆
		IKSGetNoteSizeAction action,			// 获取注释宽度和高度的回调函数(in)
		int nHorJust,							// 水平放置注释集左端或右端
		double &dXValueOutline,					// 字符串最终X值(输入为起始X)(in)(out)
		double dStartOrdinate,					// 字符串起始Y值
		double dLineWidth,						// 线宽(in)
		IKSNoteArray &arrNotes,					// 公差值注释集(out)
		IKSCurveArray &arrCurves				// 将()转化为圆曲线集(out)
		);
	// 根据起点终点生成直线
	BOOL GetLineCurve(
		int nLineStyle,							// 线型
		double dstartX,							// 起点X坐标
		double dstartY,							// 起点Y坐标
		double dstartZ,							// 起点Z坐标
		double dendX,							// 终点X坐标
		double dendY,							// 终点Y坐标
		double dendZ,							// 终点Z坐标
		IKSCurveArray &arrCurves				// 直线集(out)
		);
	// 根据圆心等生成圆
	BOOL GetCircleCurve(
		int nLineStyle,							// 线型
		double dcenterX,						// 圆心X坐标
		double dcenterY,						// 圆心Y坐标
		double dcenterZ,						// 圆心Z坐标
		double daxisXX,							// X轴的向量X坐标
		double daxisXY,							// X轴的向量Y坐标
		double daxisXZ,							// X轴的向量Z坐标
		double dRadius,							// 半径
		double dStartAngle,						// 起始角
		double dEndAngle,						// 终止角
		IKSCurveArray &arrCurves				// 圆弧集(out)
		);
private:
	// 获取全周符号
	BOOL GetBAllAroundCurves(
		double dLineWidth,					// 线宽(in)
		IKSCurveArray &arrCurves			// 曲线集(out)
		);
	// 获取公差核心直线
	BOOL GetCoreCurves(
		double dLineWidth,					// 线宽(in)
		IKSCurveArray &arrCurves			// 直线(out)
		);
	// 获取单层公差基本符号曲线
	BOOL GetBaseSymbolCurves(
		int nSymbolType,					// 基本符号类型
		int nSize,							// 包含层数
		int i,								// 所在层级
		double dLineWidth,					// 线宽(in)
		IKSCurveArray &arrCurves,			// 曲线集(out)
		double &dSymbolOutline				// 基本符号最右端X(out)
		);
	// 获取单层公差值注释集
	BOOL GetValueNotes(
		double	dValue,								// 公差值(in)
		CString	strPrefix,							// 前缀(in)
		CString	strSuffix1,							// 后缀1(in)
		CString	strSuffix2,							// 后缀2(in)
		double dSymbolOutline,						// 基本符号长度(in)
		int nSize,									// 包含层数(in)
		int i,										// 所在层级(in)
		double dLineWidth,							// 线宽(in)
		IKSGetNoteSizeAction action,				// 获取注释宽度和高度的回调函数(in)
		IKSNoteArray &arrNotes,						// 公差值注释集(out)
		double &dXValueOutline,						// 公差值的最右端X(out)
		IKSCurveArray &arrCurves				// 将()转化为圆曲线集(out)
		);
	// 获取单层第一基准注释集
	BOOL GetStrDatum1Notes(
		CString	strDatumName11,						// 第一基准名称(in)
		CString	strDatumMatCond11,					// 第一基准参照选取材料条件(in)
		CString	strDatumName12,						// 第一复合基准名称(in)
		CString	strDatumMatCond12,					// 第一复合基准参照选取材料条件(in)
		double dXValueOutline,						// 公差值的最右端X(in)
		int nSize,									// 包含层数(in)
		int i,										// 所在层级(in)
		double dLineWidth,							// 线宽(in)
		IKSGetNoteSizeAction action,				// 获取注释宽度和高度的回调函数(in)
		IKSNoteArray &arrNotes,						// 第一基准注释集(out)
		double &dXStrDatum1Outline,					// 第一基准注释的最右端X(out)
		IKSCurveArray &arrCurves				// 将()转化为圆曲线集(out)
		);

	// 当第j注释为空时，令arrXStrDatum j Outline=arrXStrDatum j-1 Outline

	// 获取单层第二基准注释集
	BOOL GetStrDatum2Notes(
		CString	strDatumName21,						// 第二基准名称(in)
		CString	strDatumMatCond21,					// 第二基准参照选取材料条件(in)
		CString	strDatumName22,						// 第二复合基准名称(in)
		CString	strDatumMatCond22,					// 第二复合基准参照选取材料条件(in)
		double dXStrDatum1Outline,					// 第一基准注释的最右端X(in)
		int nSize,									// 包含层数(in)
		int i,										// 所在层级(in)
		double dLineWidth,							// 线宽(in)
		IKSGetNoteSizeAction action,				// 获取注释宽度和高度的回调函数(in)
		IKSNoteArray &arrNotes,						// 第二基准注释集(out)
		double &dXStrDatum2Outline,					// 第二基准注释的最右端X(out)
		IKSCurveArray &arrCurves						// 将()转化为圆曲线集(out)
		);
	// 获取单层第三基准注释集
	BOOL GetStrDatum3Notes(
		CString	strDatumName31,						// 第三基准名称(in)
		CString	strDatumMatCond31,					// 第三基准参照选取材料条件(in)
		CString	strDatumName32,						// 第三复合基准名称(in)
		CString	strDatumMatCond32,					// 第三复合基准参照选取材料条件(in)
		double dXStrDatum2Outline,					// 第二基准注释的最右端X(in)
		int nSize,									// 包含层数(in)
		int i,										// 所在层级(in)
		double dLineWidth,							// 线宽(in)
		IKSGetNoteSizeAction action,				// 获取注释宽度和高度的回调函数(in)
		IKSNoteArray &arrNotes,						// 第三基准注释集(out)
		double &dXStrDatum3Outline,					// 第三基准注释的最右端X(out)
		IKSCurveArray &arrCurves						// 将()转化为圆曲线集(out)
		);
	// 获取前两列矩形框曲线集
	BOOL GetFrontRectCurves(
		int nSize,									// 包含层数(in)
		double dSymbolOutline,						// 基本符号最右端X(out)
		double dXValueOutline,						// 公差值列的最右端X(in)
		double dLineWidth,							// 线宽(in)
		IKSCurveArray &arrCurves					// 矩形框曲线集(out)
		);
	BOOL GetBackRectCurves(
		int nSize,								// 包含层数(in)
		int i,									// 所在层级(in)
		double dXValueLeftline,					// 该框左侧X值
		double dXValueRightline,					// 该框右侧X值
		double dLineWidth,						// 线宽(in)
		IKSCurveArray &arrCurves					// 矩形框曲线集(out)
		);
	// 获取上方、后方标注集
	BOOL GetStrNotes(
		CString	strNoteTop,						// 上方附注(in)
		CString	strNoteBack,					// 后方附注(in)
		int nSize,								// 包含层数(in)
		double dXStrDatum3Outline,				// 第三基准注释列的最右端X(in) 
		double dLineWidth,						// 线宽(in)
		IKSGetNoteSizeAction action,			// 获取注释宽度和高度的回调函数(in)
		IKSNoteArray &arrNotes,					// 上方、后方标注集(out)
		IKSCurveArray &arrCurves						// 将()转化为圆曲线集(out)
		);
	// 将字符串中()转化为圆
	BOOL ChangeBracketToCircle(
		CString &strName,				// 输入字符串(in)(out)
		double dstrNameLength,			// 字符串长度mm(in)
		double dAbscissa,				// 字符串初始位置横坐标(in)
		double dOrdinate,				// 字符串初始位置纵坐标(in)
		double dLineWidth,				// 线宽(in)
		IKSCurveArray &arrCurves		// 输出圆曲线集(out)
		);

};

//===================================================================================================

#endif