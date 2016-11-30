//===================================================================================================
// File:
//		PCLDatumPlane.h
// Summary:
//		平面接口类
// Date:
//		2016-08-30
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================

// 平面接口类
class CPCLDatumPlane : public CPCLFeature
{
public:
	CPCLDatumPlane();
	virtual ~CPCLDatumPlane();
public:

	// 通过面的偏移生成基准平面
	BOOL CreateDatumPlaneByOffset(
		ProSelection pSelSld,									// 基准面所在模型(in)
		ProSelection pSelRefPlane,								// 选择的参考平面(in)
		double dOffset,											// 偏移参考平面的距离(in)
		ProName szPlaneName,									// 基准面名称(in)
		ProFeature &newPlaneFeature								// 新的平面特征(out)
		);

};

//===================================================================================================
 