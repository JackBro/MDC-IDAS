//===================================================================================================
// File:
//		PCLRelation.h
// Summary:
//		关系接口类
// Date:
//		2016-08-18
// Author:
//		HuoPengcheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

//===================================================================================================
// 关系接口类
class CPCLRelation
{
public:
	CPCLRelation();
	virtual ~CPCLRelation();

public:
	// 获取关系
	BOOL GetRelation(
		ProMdl pMdl,								// 获取关系的模型(in)
		CString &strRelation						// 关系字符串(out)
		);
	// 增加关系
	BOOL AddRelation(
		ProMdl pMdl,								// 关系所属模型(in)
		const CString &strRelation					// 关系字符串(in)
		);
};

//===================================================================================================
