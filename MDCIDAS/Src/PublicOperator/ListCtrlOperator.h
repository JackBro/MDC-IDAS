//===================================================================================================
// File:
//		ListCtrlOperator.h
// Summary:
//		列表控件操作类
// Date:
//		2016-05-06
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#pragma once
//===================================================================================================
// 头文件
//===================================================================================================
// 宏定义
//===================================================================================================
// 枚举定义
//===================================================================================================
// 结构体定义
//===================================================================================================
// 类定义

// 列表控件操作类
class CListCtrlOperator
{
public:
	CListCtrlOperator();
	virtual ~CListCtrlOperator();

public:
	// 获取列表控件的对象数据集
	static void GetListItemDataArray(
		CListCtrl &listCtrl,										// 列表控件
		vector<int> &arrItemData									// 对象数据集
		);
	// 获取列表控件的选择对象
	static void GetListSelectedItems(
		CListCtrl &listCtrl,										// 列表控件
		vector<int> &arrItems										// 选择对象索引集
		);
	// 获取列表控件的选择对象数据
	static void GetListSelectedItemData(
		CListCtrl &listCtrl,										// 列表控件
		vector<int> &arrItemData									// 选择对象数据集
		);
	// 设置列表控件的内容
	static void SetListContent(
		CListCtrl &listCtrl,										// 列表控件
		const vector<vector<CString>> &arrListContent,				// 列表内容
		const vector<int> &arrListItemData,							// 列表行的标记
		const vector<int> &arrListItemImage							// 列表行的图标
		);
};


//===================================================================================================
