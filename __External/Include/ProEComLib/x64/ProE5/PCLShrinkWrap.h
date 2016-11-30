//===================================================================================================
// File:
//		PCLShrinkWrap.h
// Summary:
//		复制几何接口类
// Date:
//		2016-09-11
// Author:
//		HuoPengCheng(Huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================
// 复制几何接口类
class CPCLShrinkWrap : public CPCLFeature
{
public:
	CPCLShrinkWrap();
	virtual ~CPCLShrinkWrap();

public:
	
	// 根据模型生成收缩包络，用坐标系参考方式
	static BOOL CreateShrinkWrapByPubGeomUseCsys(
		ProSolid pExtRefMdl,								// 外部参考总模型(in)
		ProSelection pSelExtCsys,							// 外部参考坐标系，路径相对于外部参考总模型(in)
		vector<ProSelection> &arrIncludeComps,				// 收缩包络包含的元件，路径相对于外部参考总模型(in)
		vector<ProSelection> &arrNotIncludeComps,			// 收缩包络不包含的元件，路径相对于外部参考总模型(in)
		ProSolid pShrinkWrapMdl,							// 收缩包络总模型(in)
		ProSelection pSelLocalCsys,							// 局部参考坐标系，路径相对于收缩包络总模型(in)
		int nQualityLevel,									// 质量等级(in)
		ProName szSWName,									// 收缩包络特征名(in)
		ProFeature &newSWFeature							// 新的收缩包络特征(out)
		);

};


//===================================================================================================
 