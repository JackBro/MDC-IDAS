//===================================================================================================
// File:
//		PCLEdge.h
// Summary:
//		边接口类
// Date:
//		2016-09-09
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================

// 轴接口类
class CPCLEdge : public CPCLFeature
{
public:
	CPCLEdge();
	virtual ~CPCLEdge();
public:

	// 获取边的起点和终点
	static BOOL GetEdgeStartAndEnd(
		ProGeomitem &edgeItem,							// 边的项目(in)
		SVDOUBLE3 &vStart,								// 起点(out)
		SVDOUBLE3 &vEnd									// 终点(out)
		);
	
};

//===================================================================================================
 