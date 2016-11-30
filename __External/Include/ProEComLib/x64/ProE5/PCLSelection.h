//===================================================================================================
// File:
//		PCLSelection.h
// Summary:
//		选择对象接口类
// Date:
//		2016-09-08
// Author:
//		HuoPengcheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

//===================================================================================================
// 选择对象接口类
class CPCLSelection
{
public:
	CPCLSelection();
	virtual ~CPCLSelection();

public:

	// 高亮选择对象
	static BOOL HighlightSelection(
		ProSelection pSel								// 选择对象(in)
		);

	// 高亮选择对象
	static BOOL HighlightSelection(
		const vector<ProSelection> &arrSel				// 选择对象(in)
		);

	// 获得选择对象的名称
	static BOOL GetNameFromProSelection(
		ProSelection pSel,								// 选择对象(in)
		CString &strSelName								// 对象名(out)
		);

	// 获取选择对象的位置
	static BOOL GetSelectionWorldPos(
		ProSelection pSel,								// 选择对象(in)
		SVDOUBLE3 &vWorldPos							// 位置(out)
		);

	// 获取选择对象的相对于实体模型的选择对象
	BOOL GetSelectionRelSelection(
		ProSelection pSel,								// 选择对象(in)
		ProSolid pOwnerMdl,								// 实体模型(in)
		ProSelection &pSelRel							// 相对的选择对象(out)
		);

};

//===================================================================================================
