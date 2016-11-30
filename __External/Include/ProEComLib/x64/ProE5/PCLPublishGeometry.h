//===================================================================================================
// File:
//		PCLPublishGeometry.h
// Summary:
//		发布几何接口类
// Date:
//		2016-08-23
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================
// 发布几何接口类
class CPCLPublishGeometry : public CPCLFeature
{
public:
	CPCLPublishGeometry();
	virtual ~CPCLPublishGeometry();

public:

	// 判断特征是否是发布几何
	static BOOL IsFeaturePubGeom(
		ProFeature &feature								// 特征(in)
		);

	// 获取模型的发布几何(只获取当前输入模型的下一层)
	BOOL GetMdlPubGeom(
		ProMdl pMdl,									// 模型(in)
		vector<ProFeature> &arrPubGeom					// 发布几何(out)
		);

	// 获取发布几何的基准项目集
	BOOL GetPubDatumItems(
		ProFeature &pubFeature,							// 特征(in)
		ProType eDatumType,								// 基准类型(in)
		vector<ProGeomitem> &arrDatumItems				// 项目集(out)
		);
	
	// 根据复制几何生成发布几何
	BOOL CreatePubGeomByCopyGeom(
		ProSolid pPubGeomMdl,							// 发布几何所在模型(in)
		ProFeature &copyGeomFeature,					// 复制几何，直属于发布几何所在模型(in)
		ProName szPBName,								// 发布几何特征名(in)
		ProFeature &newPubFeature						// 新的发布几何特征(out)
		);

protected:
	// 遍历发布几何特征的动作函数(只遍历模型的下一层)
	static ProError GetPubGeomVisit(ProFeature* pFeature, ProError status, ProAppData pAppData);
	// 遍历发布几何特征的过滤函数
	static ProError GetPubGeomFilter(ProFeature* pFeature, ProAppData pAppData);

};


//===================================================================================================
 