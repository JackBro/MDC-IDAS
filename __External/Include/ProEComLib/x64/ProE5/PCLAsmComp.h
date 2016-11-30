//===================================================================================================
// File:
//		PCLAsmComp.h
// Summary:
//		元件接口类
// Date:
//		2016-09-08
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================

// 元件接口类
class CPCLAsmComp : public CPCLFeature
{
public:
	CPCLAsmComp();
	virtual ~CPCLAsmComp();

public:

	// 获取元件路径对应模型的选择对象
	static BOOL GetAsmcomppathSelection(
		ProAsmcomppath &asmcomppath,				// 路径(in)
		ProSelection &pSelMdl						// 选择模型(out)
		);

	// 获取元件模型的选择对象，路径相对于元件特征的父组件
	static BOOL GetAsmcompSelection(
		ProAsmcomp &asmcomp,						// 元件特征(in)
		ProSelection &pSelCompMdl					// 装配参考坐标系(out)
		);

	// 获取路径的元件特征
	static BOOL GetAsmcomppathCompFeature(
		ProAsmcomppath &comppath,					// 路径(in)
		ProAsmcomp &asmcomp							// 元件特征(out)
		);

	// 重生元件路径对应模型
	static BOOL RegenerateAsmcomppathMdl(
		ProAsmcomppath &asmcomppath					// 元件路径(in)
		);

};

//===================================================================================================
 