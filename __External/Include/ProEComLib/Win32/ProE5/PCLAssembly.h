//===================================================================================================
// Summary:
//		装配相关函数类
// Date:
//		2016-08-31
// Author:
//		HuoPengcheng(huopc@buaa.edu.cn)
//===================================================================================================

// 引用ProE头文件
#include <ProMdl.h>

//====================================================================================================

#pragma once

//====================================================================================================
// 装配相关函数类
class CPCLAssembly
{
public:
	CPCLAssembly();
	virtual ~CPCLAssembly();

public:
	// 添加坐标系约束
	BOOL AddCsysConstraint(
		ProAsmcomp &asmcomp,					// 新的元件(in)
		ProAssembly pAsm,						// 装配体(in)
		ProSelection pSelCsys,					// 选择的基准坐标系(in)
		ProSelection pSelCompCsys				// 模型的坐标系(in)
		);

public:

	// 增加模型至装配体，用坐标系装配
	BOOL AddModelToAsmWithCsysCons(
		ProAssembly pAsm,						// 装配体(in)
		ProSelection pSelCsys,					// 选择的基准坐标系(in)
		ProSolid pMdlToAdd,						// 待增加新模型(in)
		ProModelitem &csysItem,					// 模型的坐标系(in)
		ProAsmcomp &newAsmcomp					// 新的元件(out)
		);

};

//===================================================================================================


