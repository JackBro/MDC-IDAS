//===================================================================================================
// File:
//		PCLPoint.h
// Summary:
//		点接口类
// Date:
//		2016-09-02
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================

// 点接口类
class CPCLPoint : public CPCLFeature
{
public:
	CPCLPoint();
	virtual ~CPCLPoint();

public:

	// 获取点项目的位置，局部坐标系
	static BOOL GetPointCoords(
		ProModelitem &pointItem,							// 点的项目(in)
		ProPoint3d pointPos									// 点的位置(out)
		);

	// 获取选择点的位置，世界坐标系
	static BOOL GetPointCoords(
		ProSelection pSelPoint,								// 点的项目(in)
		SVDOUBLE3 &pointPos									// 点的位置(out)
		);

	// 生成基准点
	BOOL CreateDatumPoints(
		ProSelection pSelSld,								// 基准点特征所在模型(in)
		ProSelection pSelCsys,								// 参考坐标系，如果为空则利用默认的坐标系(in)
		const vector<SVDOUBLE3> &arrPoints,					// 点的位置(in)
		ProName szDtmPntFeatureName,						// 基准点特征名(in)
		ProFeature &newDatumPointsFeature					// 基准点特征(out)
		);

	// 生成基准点（根据坐标系原点位置）
	BOOL CreateDatumPointByCsys(
		ProSelection pSelSld,								// 基准点特征所在模型(in)
		ProSelection pSelCsys,								// 参考坐标系(in)
		ProName szDtmPntFeatureName,						// 基准点特征名(in)
		ProFeature &newDatumPointFeature					// 基准点特征(out)
		);

	// 修改基准点（适应于偏移坐标系基准点）
	BOOL ModifyDatumPoints(
		ProSelection pSelDatumFeature,						// 基准点特征(in)
		const vector<SVDOUBLE3> &arrPoints					// 点的位置(世界坐标)(in)
		);

	// 获取选择曲面上距输入点最近的点
	BOOL GetPointOnSurface(
		ProSelection pSelSurf,								// 选择曲面(in)
		SVDOUBLE3 &vInputPoint,								// 输入点(in)
		SVDOUBLE3 &vPointOnSurf								// 曲面上的点(out)
		);
};

//===================================================================================================
 