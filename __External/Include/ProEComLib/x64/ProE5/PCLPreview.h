//===================================================================================================
// File:
//		PCLPreview.h
// Summary:
//		边接口类
// Date:
//		2016-09-10
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once
#include "PCLCsys.h"

//===================================================================================================

// 轴接口类
class CPCLPreview
{
public:
	CPCLPreview();
	virtual ~CPCLPreview();
public:

	// 坐标系预览
	static BOOL PreviewCsys(
		const IKSCsysData &csysData,								// 坐标系数据(in)
		double dArrowLength											// 箭头长度(in)
		);

	// 圆预览
	static BOOL PreviewCircle(
		const SVDOUBLE3 &vCenter,									// 中心点(in)
		const SVDOUBLE3 &vNormal,									// 法向(in)
		double dRadius												// 半径(in)
		);

	
};

//===================================================================================================
 