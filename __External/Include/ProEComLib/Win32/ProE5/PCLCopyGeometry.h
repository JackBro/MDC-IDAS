//===================================================================================================
// File:
//		PCLCopyGeometry.h
// Summary:
//		复制几何接口类
// Date:
//		2016-08-19
// Author:
//		HuoPengCheng(Huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================
// 复制几何接口类
class CPCLCopyGeometry : public CPCLFeature
{
public:
	CPCLCopyGeometry();
	virtual ~CPCLCopyGeometry();

public:
	
	// 判断特征是否是复制几何
	static BOOL IsFeatureCopyGeom(
		ProFeature &feature						// 特征(in)
		);

	// 获取模型的复制几何(只获取当前输入模型的下一层)
	BOOL GetMdlCopyGeom(
		ProMdl pMdl,							// 模型(in)
		vector<ProFeature> &arrCopyGeom			// 发布几何(out)
		);

	// 根据复制几何获取复制几何的参考模型
	BOOL GetCopyGeomRefMdl(
		ProFeature &feaCopyGeom, 				// 复制几何(in)
		ProMdl &pRefMdl							// 参考模型(out)
		);

	// 根据发布几何生成复制几何，用缺省参考方式
	BOOL CreateCopyGeomByPubGeom(
		ProSolid pSld,							// 复制几何所在模型(in)
		ProSelection pSelPubGeom,				// 选择的发布几何(in)
		ProName szCGName,						// 复制几何特征名(in)
		ProFeature &newCopyFeature				// 新的复制几何特征(out)
		);

	// 根据发布几何生成局部复制几何
	BOOL CreateLocalCopyGeomByPubGeom(
		ProSelection pSelSld,					// 复制几何所在模型(in)
		ProSelection pSelPubGeom,				// 选择的发布几何(in)
		ProName szCGName,						// 复制几何特征名(in)
		ProFeature &newCopyFeature				// 新的复制几何特征(out)
		);

	// 根据发布几何生成复制几何，用坐标系参考方式
	BOOL CreateCopyGeomByPubGeomUseCsys(
		ProSolid pPubGeomMdl,					// 发布几何总模型(in)
		ProSelection pSelExtCsys,				// 外部参考坐标系，路径相对于发布几何总模型(in)
		ProSelection pSelPubGeom,				// 发布几何选择对象，路径相对于发布几何总模型(in)
		ProSolid pCopyGeomMdl,					// 复制几何总模型(in)
		ProSelection pSelLocalCsys,				// 局部参考坐标系，路径相对于复制几何总模型(in)
		ProName szCGName,						// 复制几何特征名(in)
		ProFeature &newCopyFeature				// 新的复制几何特征(out)
		);

protected:

	// 遍历复制几何特征的动作函数(只遍历模型的下一层)
	static ProError GetCopyGeomVisit(ProFeature* pFeature, ProError status, ProAppData pAppData);
	// 遍历发布几何特征的过滤函数
	static ProError GetCopyGeomFilter(ProFeature* pFeature, ProAppData pAppData);

};


//===================================================================================================
 