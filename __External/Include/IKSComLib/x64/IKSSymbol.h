//===================================================================================================
// Summary:
//		符号类
// Date:
//		2015-09-19			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSSymbol_h__
#define __IKSSymbol_h__

//===================================================================================================

#include "IKSGeom.h"
#include "IKSNote.h"

//===================================================================================================

// 符号的放置方式
typedef enum __tagIKSSymbolAttachType
{
	SATYPE_FREE,
	SATYPE_LEFT_LEADER,
	SATYPE_RIGHT_LEADER,
	SATYPE_RADIAL_LEADER,
	SATYPE_ON_ITEM,
	SATYPE_NORM_ITEM
} IKSSymbolAttachType;

//===================================================================================================

class CIKSSymbol
{
public:
	CIKSSymbol();
	virtual ~CIKSSymbol();

protected:
	// 获取包围盒的曲线，作为内部测试
	void GetBoxCurves(
		IKSBox dOutline,					// 包围盒
		IKSCurveArray &arrCurves			// 曲线集
		);
};

//===================================================================================================

#endif