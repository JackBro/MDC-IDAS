//===================================================================================================
// File:
//		PCLAxis.h
// Summary:
//		轴接口类
// Date:
//		2016-09-06
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================

// 轴接口类
class CPCLAxis : public CPCLFeature
{
public:
	CPCLAxis();
	virtual ~CPCLAxis();
public:

	// 生成基准轴（根据两个基准点）
	BOOL CreateDatumAxisByTwoPoints(
		ProSelection pSelSld,						// 基准轴特征所在模型(in)
		ProSelection pSelPoint1,					// 基准点1(in)
		ProSelection pSelPoint2,					// 基准点2(in)
		ProName szDtmAxisFeatureName,				// 基准轴特征名(in)
		ProFeature &newDtmAxisFeature				// 基准轴特征(out)
		);

};

//===================================================================================================
 