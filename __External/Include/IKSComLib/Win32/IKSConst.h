//===================================================================================================
// Summary:
//		IKSAnnotationLib内部使用常量和结构体
// Date:
//		2015-07-31			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSConst_h__
#define __IKSConst_h__

//===================================================================================================
// 以下为宏定义
#define IKS_DELTA 0.001
#define IKS_ZERO 0.000001
#define IKS_ISDEQUAL(x, y) ((x)-(y)<IKS_ZERO && (x)-(y)>-IKS_ZERO)
#define IKS_ISDNEAR(x, y) ((x)-(y)<IKS_DELTA && (x)-(y)>-IKS_DELTA)

// 圆周率
#define IKS_PI				3.1415926535897932
// 角度转弧度
#define IKS_ANGLE_TO_RADIAN(angle) (angle) * (0.017453292519943296)
#define IKS_RADIAN_TO_ANGLE(rad) (rad) * (57.295779513082321)
// 常用数字
#define IKS_1_3				0.33333333333333333				// 1/3
#define IKS_SQRT_2			1.4142135623730950				// 根号2
#define IKS_SQRT_1_2		0.70710678118654752				// 1/根号2
#define IKS_SQRT_3			1.7320508075688773				// 根号3
#define IKS_SQRT_1_3		0.57735026918962576				// 1/根号3

// 删除指针
#define IKS_SAFE_DELETE_POINTER(p) \
{ \
	if (NULL != p) \
	delete p; \
	p = NULL; \
}

// 删除数组
#define IKS_SAFE_DELETE_ARRAY(p) \
{ \
	if (NULL != p) \
	delete[] p; \
	p = NULL; \
}

//===================================================================================================
// 以下为常量定义


//===================================================================================================
// 以下为枚举值定义

// 标注的放置类型
typedef enum __tagIKSAnnoAttachType
{
	IKSANNOATTACHTYPE_FREE,					// 自由
	IKSANNOATTACHTYPE_LEFT_LEADER,			// 左引线
	IKSANNOATTACHTYPE_RIGHT_LEADER,			// 右引线
	IKSANNOATTACHTYPE_RADIAL_LEADER,		// 径向引线
	IKSANNOATTACHTYPE_ON_ITEM,				// 图元上
	IKSANNOATTACHTYPE_NORM_ITEM				// 垂直于图元
} IKSAnnoAttachType;

// 标注的高度类型
typedef enum __tagIKSAnnoHeightType
{
	IKSANNOHEIGHTTYPE_FIXED,				// 固定
	IKSANNOHEIGHTTYPE_VARIABLE,				// 可变的-绘图单位
	IKSANNOHEIGHTTYPE_TEXTRELATED,			// 可变的-相关文本
	IKSANNOHEIGHTTYPE_MODELUNITS			// 可变的-模型单位
} IKSAnnoHeightType;

// 文本样式水平对齐方式
typedef enum __tagIKSHorizontalJustification
{
	IKS_HORZJUST_LEFT,						// 左边
	IKS_HORZJUST_CENTER,					// 中心
	IKS_HORZJUST_RIGHT						// 右边
} IKSHorizontalJustification;

// 文本样式竖直对齐方式
typedef enum __tagIKSVerticalJustification
{
	IKS_VERTJUST_TOP,						// 顶部
	IKS_VERTJUST_MIDDLE,					// 中间
	IKS_VERTJUST_BOTTOM						// 底部
} IKSVerticalJustification;

// 引线方式
typedef enum __tagIKSSdArrowStyle
{
	IKSAS_UNKNOWN		= -1,
	IKSAS_ARROWHEAD		=  1,	// 箭头
	IKSAS_DOT			=  2,	// 点
	IKSAS_FILLEDDOT		=  3,	// 实心点
	IKSAS_NOARROW		=  4,	// 无
	IKSAS_CROSS			=  5,	// 交叉
	IKSAS_SLASH			=  6,	// 斜杠
	IKSAS_INTEGRAL		=  7,	// 整数
	IKSAS_BOX			=  8,	// 方框
	IKSAS_FILLEDBOX		=  9,	// 实心框
	IKSAS_DOUBLEARROW	= 10,	// 双箭头
	IKSAS_TARGET		= 14,	// 目标
	IKSAS_LEFTHALF		= 15,	// 左半箭头
	IKSAS_RIGHTHALF		= 16,	// 右半箭头
	IKSAS_TRIANGLE		= 18,	// 三角形
	IKSAS_NOCHANGE		= 19	// 照原样
} IKSSdArrowStyle;

//===================================================================================================
// 以下为结构体定义
// 文本样式
typedef struct __tagIKSTextStyle
{
	CString strFont;			// 字体
	BOOL	bDefaultFont;		// 默认字体
	double	dHeight;			// 高度值 
	BOOL	bDefaultHeight;		// 默认高度
	double	dWidth;				// 宽度比值
	BOOL	bDefaultWidth;		// 默认宽度比
	double	dThickness;			// 文本的线厚度
	BOOL	bDefaultThickness;	// 默认文本线厚度
	double	dSlant;				// 倾斜角度（按顺时针方向）
	BOOL	bUnderline;			// 加下划线
	int		nHorJust;			// 水平
	int		nVerJust;			// 垂直
	BOOL	bMirror;			// 镜像
	BOOL	bReadonly;			// 只读属性

	__tagIKSTextStyle() 
	{
		strFont = _T("default_font");
		bDefaultFont = TRUE;
		dHeight = 3.5;
		bDefaultHeight = TRUE;
		dWidth = 0.85; 
		bDefaultWidth = TRUE;
		dThickness = 0.0;
		bDefaultThickness = TRUE;
		dSlant = 0.00; 
		bUnderline = FALSE;
		nHorJust = IKS_HORZJUST_CENTER;
		nVerJust = IKS_VERTJUST_MIDDLE;
		bMirror = FALSE;
		bReadonly = FALSE;
	}

	BOOL operator== (const __tagIKSTextStyle &textStyle) 
	{
		if (bDefaultFont == textStyle.bDefaultFont)
		{
			if (!bDefaultFont)
			{
				if (strFont.CompareNoCase(textStyle.strFont) != 0)
					return FALSE;
			}
		}
		else
			return FALSE;

		if (bDefaultHeight == textStyle.bDefaultHeight)
		{
			if (!bDefaultHeight)
			{
				if (!IKS_ISDEQUAL(dHeight, textStyle.dHeight))
					return FALSE;
			}
		}
		else
			return FALSE;

		if (bDefaultWidth == textStyle.bDefaultWidth)
		{
			if (!bDefaultWidth)
			{
				if (!IKS_ISDEQUAL(dWidth, textStyle.dWidth))
					return FALSE;
			}
		}
		else
			return FALSE;

		if (bDefaultThickness == textStyle.bDefaultThickness)
		{
			if (!bDefaultThickness)
			{
				if (!IKS_ISDEQUAL(dThickness, textStyle.dThickness))
					return FALSE;
			}
		}
		else
			return FALSE;

		if (!IKS_ISDEQUAL(dSlant, textStyle.dSlant))
			return FALSE;

		if (bUnderline != textStyle.bUnderline)
			return FALSE;

		if (nHorJust != textStyle.nHorJust)
			return FALSE;

		if (nVerJust != textStyle.nVerJust)
			return FALSE;

		if (bMirror != textStyle.bMirror)
			return FALSE;

		if (bReadonly != textStyle.bReadonly)
			return FALSE;

		return TRUE;
	}

	BOOL operator!= (const __tagIKSTextStyle &textStyle) 
	{
		return !(*this == textStyle);
	}

	__tagIKSTextStyle &operator= (const __tagIKSTextStyle &textStyle) 
	{
		if (&textStyle != this)
		{
			strFont = textStyle.strFont;
			bDefaultFont = textStyle.bDefaultFont;
			dHeight = textStyle.dHeight;
			bDefaultHeight = textStyle.bDefaultHeight;
			dWidth = textStyle.dWidth; 
			bDefaultWidth = textStyle.bDefaultWidth;
			dThickness = textStyle.dThickness; 
			bDefaultThickness = textStyle.bDefaultThickness;
			dSlant = textStyle.dSlant; 
			bUnderline = textStyle.bUnderline;
			nHorJust = textStyle.nHorJust;
			nVerJust = textStyle.nVerJust;
			bMirror = textStyle.bMirror;
			bReadonly = textStyle.bReadonly;
		}
		return *this;
	}
} IKSTextStyle;

// 标注放置方式
typedef struct __tagIKSAnnoAttach
{
	int nAttachType;					// 放置的类型，参考IKSAnnoAttachType
	int nEntityID;						// 引用的实体几何ID，仅用于放置类型为【图元上】【垂直于图元】【左引线】【右引线】【径向引线】的情形
	double dEntityParameter;			// 实体几何的位置参数，仅用于放置类型为【图元上】【垂直于图元】【左引线】【右引线】的情形
	double dpLocation[3];				// 实体几何的位置，仅用于放置类型为【图元上】【垂直于图元】【左引线】【右引线】的情形

	__tagIKSAnnoAttach() 
	{
		nAttachType = IKSANNOATTACHTYPE_FREE;
		nEntityID = -1;
		dEntityParameter = 0.0;
		memset(dpLocation, 0, sizeof(double)*3);
	}

	__tagIKSAnnoAttach &operator= (const __tagIKSAnnoAttach &attach) 
	{
		if (&attach != this)
		{
			nAttachType = attach.nAttachType;
			nEntityID = attach.nEntityID;
			dEntityParameter = attach.dEntityParameter;
			memcpy_s(dpLocation, sizeof(double)*3, attach.dpLocation, sizeof(double)*3);
		}
		return *this;
	}
} IKSAnnoAttach;

typedef vector<IKSAnnoAttach> IKSAnnoAttachArray;

// 符号定义属性
typedef struct __tagIKSAnnoAttribute
{
	int nHeightType;						// 高度类型，参考IKSAnnoHeightType
	int nTextRefID;							// 当高度类型为【可变相关文本】时，相关文本的文本ID
	int nTextRefLine;						// 当高度类型为【可变相关文本】时，相关文本所在行索引
	int nTextRefText;						// 当高度类型为【可变相关文本】时，相关文本的所在文本索引
	BOOL bTextAngleFixed;					// 文本角度是否固定
	IKSAnnoAttachArray arrAttaches;			// 放置方式集

	__tagIKSAnnoAttribute() 
	{
		nHeightType = IKSANNOHEIGHTTYPE_VARIABLE;
		nTextRefID = -1;
		nTextRefLine = -1;
		nTextRefText = -1;
		bTextAngleFixed = FALSE;
	}

	__tagIKSAnnoAttribute &operator= (const __tagIKSAnnoAttribute &att) 
	{
		if (&att != this)
		{
			nHeightType = att.nHeightType;
			nTextRefID = att.nTextRefID;
			nTextRefLine = att.nTextRefLine;
			nTextRefText = att.nTextRefText;
			bTextAngleFixed = att.bTextAngleFixed;
			arrAttaches = att.arrAttaches;
		}
		return *this;
	}
} IKSAnnoAttribute;

//===================================================================================================

#endif