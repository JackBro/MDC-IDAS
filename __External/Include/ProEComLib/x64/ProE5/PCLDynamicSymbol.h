//===================================================================================================
// Summary:
//		动态符号类，用于生成可变的符号
// Date:
//		2015-07-22
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __PCLDynamicSymbol_h__
#define __PCLDynamicSymbol_h__

//===================================================================================================

#include <ProDtlsymdef.h>
#include <ProDtlsyminst.h>
#include <ProDtlnote.h>
#include <ProDtlentity.h>
#include "IKSGeom.h"
#include "IKSNote.h"

//===================================================================================================

// 符号定义放置方式
typedef struct __tagPCLSymdefAttach
{
	ProDtlsymdefattachType eAttachType;	// 放置的类型
	int nEntityID;						// 引用的实体几何ID，仅用于放置类型为【图元上】【垂直于图元】【左引线】【右引线】【径向引线】的情形
	double dEntityParameter;			// 实体几何的位置参数，仅用于放置类型为【图元上】【垂直于图元】【左引线】【右引线】的情形
	ProPoint3d dpLocation;				// 实体几何的位置参数，仅用于放置类型为【图元上】【垂直于图元】【左引线】【右引线】的情形

	__tagPCLSymdefAttach() 
	{
		eAttachType = PROSYMDEFATTACHTYPE_FREE;
		nEntityID = -1;
		dEntityParameter = 0.0;
		memset(dpLocation, 0, sizeof(ProPoint3d));
	}

	__tagPCLSymdefAttach &operator= (const __tagPCLSymdefAttach &attach) 
	{
		if (&attach != this)
		{
			eAttachType = attach.eAttachType;
			nEntityID = attach.nEntityID;
			dEntityParameter = attach.dEntityParameter;
			memcpy_s(dpLocation, sizeof(ProPoint3d), attach.dpLocation, sizeof(ProPoint3d));
		}
		return *this;
	}
} PCLSymdefAttach;

typedef vector<PCLSymdefAttach> PCLSymdefAttachArray;

// 符号定义属性
typedef struct __tagPCLSymdefAttribute
{
	ProDtlsymdefdataHeighttype eHeightType;	// 高度类型，包括【固定】、【可变绘图单位】、【可变相关文本】、【可变模型单位】
	int nTextRefEntity;						// 当高度类型为【可变相关文本】时，相关文本的文本ID
	int nTextRefLine;						// 当高度类型为【可变相关文本】时，相关文本所在行索引
	int nTextRefText;						// 当高度类型为【可变相关文本】时，相关文本的所在文本索引
	BOOL bTextAngleFixed;					// 文本角度是否固定
	PCLSymdefAttachArray arrAttaches;		// 放置方式集

	__tagPCLSymdefAttribute() 
	{
		eHeightType = PRODTLSYMDEFHGHTTYPE_VARIABLE;
		nTextRefEntity = -1;
		nTextRefLine = -1;
		nTextRefText = -1;
		bTextAngleFixed = FALSE;
	}

	__tagPCLSymdefAttribute &operator= (const __tagPCLSymdefAttribute &att) 
	{
		if (&att != this)
		{
			eHeightType = att.eHeightType;
			nTextRefEntity = att.nTextRefEntity;
			nTextRefLine = att.nTextRefLine;
			nTextRefText = att.nTextRefText;
			bTextAngleFixed = att.bTextAngleFixed;
			arrAttaches = att.arrAttaches;
		}
		return *this;
	}
} PCLSymdefAttribute;

namespace PCLDynamicSymbol
{
	// 创建符号定义
	BOOL CreateSymdef(
		ProMdl pMdl,						// 模型指针(in)
		ProName szSymdefName,				// 符号定义的名称(in)
		ProDtlsymdef &symdef				// 符号定义(out)
		);

	// 在符号定义中生成实体几何
	BOOL CreateEntityInSymdef(
		ProDtlsymdef &symdef,				// 符号定义(in)
		ProCurvedata &curveData,			// 曲线数据，包括直线、圆弧等(in)
		ProColortype eColorType,			// 颜色类型，参考枚举定义：ProColortype(in)
		double dWidth,						// 线宽(in)
		ProDtlentity &entity				// 实体几何(out)
		);

	// 在符号定义中生成实体几何
	BOOL CreateEntityInSymdef(
		ProDtlsymdef &symdef,				// 符号定义(in)
		IKSCurve &curveData,				// 曲线数据，包括直线、圆弧等(in)
		double dWidth,						// 线宽(in)
		ProDtlentity &entity				// 实体几何(out)
		);

	// 在符号定义中修改实体几何
	BOOL ModifyEntityInSymdef(
		ProDtlsymdef &symdef,				// 符号定义(in)
		ProDtlentity &entity,				// 实体几何(in)
		ProCurvedata &curveData,			// 曲线数据，包括直线、圆弧等(in)
		ProColortype eColorType,			// 颜色类型，参考枚举定义：ProColortype(in)
		double dWidth						// 线宽(in)
		);

	// 在符号定义中修改实体几何
	BOOL ModifyEntityInSymdef(
		ProDtlsymdef &symdef,				// 符号定义(in)
		ProDtlentity &entity,				// 实体几何(in)
		IKSCurve &curveData,				// 曲线数据，包括直线、圆弧等(in)
		double dWidth						// 线宽(in)
		);

	// 在符号定义中生成注释
	BOOL CreateNoteInSymdef(
		ProDtlsymdef &symdef,				// 符号定义(in)
		const IKSNote &noteInfo,			// 注释的信息
		ProDtlnote &note					// 生成的注释(out)
		);

	// 在符号定义中修改注释
	BOOL ModifyNoteInSymdef(
		ProDtlsymdef &symdef,				// 符号定义(in)
		ProDtlnote &note,					// 生成的注释(out)
		const IKSNote &noteInfo				// 注释的信息
		);

	// 设置符号定义的属性
	BOOL SetSymefAttributes(
		ProDtlsymdef &symdef,				// 符号定义(in)
		const PCLSymdefAttribute &attr		// 符号定义属性(in)
		);

	// 获取符号高度类型
	ProDtlsymdefdataHeighttype GetSymdefHeightType(
		int nAnnoHeightType					// 标注的高度类型(in)
		);

	// 获取符号放置类型
	ProDtlsymdefattachType GetSymdefAttachType(
		int nAnnoAttachType					// 标注的放置类型(in)
		);

	// 获取水平对齐方式
	ProHorizontalJustification GetHorizontalJustification(
		int nHorzJustType					// 水平对齐方式(in)
		);

	// 获取竖直对齐方式
	ProVerticalJustification GetVerticalJustification(
		int nVertJustType					// 竖直对齐方式(in)
		);

	// 在符号定义中生成组
	BOOL CreateGroupInSymdef(
		ProDtlsymdef &symdef,				// 符号定义(in)
		ProName szGroupName,				// 组名称(in)
		int nParentGroupID,					// 父亲的组ID，如果组为根，则该值为-1(in)
		ProDtlsymgroup &proNewGroup			// 生成的组(out)
		);

	// 清除符号定义中所有的组
	BOOL ClearGroupInSymdef(
		ProDtlsymdef &symdef				// 符号定义(in)
		);

	// 获取符号定义的注释缩放因子
	double GetSymdefNoteScale(
		ProDtlsymdef &symdef				// 符号定义(in)
		);
};

//===================================================================================================

#endif