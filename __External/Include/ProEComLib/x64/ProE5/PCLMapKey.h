//===================================================================================================
// Summary:
//		映射键相关函数类
// Date:
//		2016-08-22
// Author:
//		HuoPengcheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

//====================================================================================================
// 映射键相关函数类
class CPCLMapKey
{
public:
	CPCLMapKey();
	virtual ~CPCLMapKey();

public:
	// 加载映射键（在函数结束后执行）
	static void LoadMapKey(
		const CString &strMacro,										// 映射键解析参数(in)
		ProSelection pSel												// 选择对象(in)
		);
	// 加载映射键（在函数结束后执行）
	static void LoadMapKey(
		const CString &strMacro,										// 映射键解析参数(in)
		ProModelitem *pMdlItem = NULL									// 模型对象(in)
		);
	// 执行映射键
	static void ExecuteMapKey(
		const CString &strMacro,										// 映射键解析参数(in)
		ProSelection pSel												// 选择对象(in)
		);
	// 执行映射键
	static void ExecuteMapKey(
		const CString &strMacro,										// 映射键解析参数(in)
		ProModelitem *pMdlItem = NULL									// 模型对象(in)
		);


};

//===================================================================================================


