//===================================================================================================
// File:
//		TotalUnitBuilder.cpp
// Summary:
//		整机配置结构模型生成器
// Date:
//		2016-11-16
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#include "stdafx.h"
#include "TotalUnitBuilder.h"

//===================================================================================================

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//===================================================================================================

CTotalUnitBuilder::CTotalUnitBuilder()
{
	;
}

CTotalUnitBuilder::~CTotalUnitBuilder()
{
	;
}

// 生成模型
BOOL CTotalUnitBuilder::BuildModel(
	const TotalUnitConfiguration &totalUnitConfig,					// 整机配置
	const LayoutData &layoutData									// 布局数据
	)
{
	return TRUE;
}
