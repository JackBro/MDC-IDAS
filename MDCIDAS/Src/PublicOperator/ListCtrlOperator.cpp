//===================================================================================================
// File:
//		ListCtrlOperator.cpp
// Summary:
//		列表控件操作类
// Date:
//		2016-05-06
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#include "stdafx.h"
#include "ListCtrlOperator.h"

//===================================================================================================

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//===================================================================================================

CListCtrlOperator::CListCtrlOperator()
{
}

CListCtrlOperator::~CListCtrlOperator()
{
}

// 获取列表控件的对象数据集
void CListCtrlOperator::GetListItemDataArray(
	CListCtrl &listCtrl,										// 列表控件
	vector<int> &arrItemData									// 对象数据集
	)
{
	arrItemData.clear();
	int nItemCount = listCtrl.GetItemCount();
	arrItemData.resize(nItemCount);
	for (int i=0; i<nItemCount; i++)
		arrItemData[i] = (int)listCtrl.GetItemData(i);
}

// 获取列表控件的选择对象
void CListCtrlOperator::GetListSelectedItems(
	CListCtrl &listCtrl,										// 列表控件
	vector<int> &arrItems										// 选择对象索引集
	)
{
	arrItems.clear();
	POSITION pos = listCtrl.GetFirstSelectedItemPosition();
	while (pos)
	{
		int nItem = listCtrl.GetNextSelectedItem(pos);
		arrItems.push_back(nItem);
	}
}

// 获取列表控件的选择对象数据
void CListCtrlOperator::GetListSelectedItemData(
	CListCtrl &listCtrl,										// 列表控件
	vector<int> &arrItemData									// 选择对象数据集
	)
{
	arrItemData.clear();
	POSITION pos = listCtrl.GetFirstSelectedItemPosition();
	while (pos)
	{
		int nItem = listCtrl.GetNextSelectedItem(pos);
		arrItemData.push_back((int)listCtrl.GetItemData(nItem));
	}
}

// 设置列表控件的内容
void CListCtrlOperator::SetListContent(
	CListCtrl &listCtrl,										// 列表控件
	const vector<vector<CString>> &arrListContent,				// 列表内容
	const vector<int> &arrListItemData,							// 列表行的标记
	const vector<int> &arrListItemImage							// 列表行的图标
	)
{
	LVITEM lvItem;
	lvItem.mask = LVIF_IMAGE;
	if (arrListContent.size() != arrListItemData.size())
		return;

	int nSize = (int)arrListContent.size(), nRow = 0;
	int nItemCount = listCtrl.GetItemCount();
	if (nSize > nItemCount)
	{
		for (nRow=0; nRow<nItemCount; nRow++)
		{
			if (nRow < arrListItemImage.size())
			{
				lvItem.iItem = nRow;
				lvItem.iSubItem = 0;
				listCtrl.GetItem(&lvItem);
				lvItem.iImage = arrListItemImage[nRow];
				listCtrl.SetItem(&lvItem);
			}
			if (arrListItemData[nRow] != (int)listCtrl.GetItemData(nRow))
				listCtrl.SetItemData(nRow, arrListItemData[nRow]);
			for (int nCol=0; nCol<arrListContent[nRow].size(); nCol++)
			{
				if (arrListContent[nRow][nCol].Compare(listCtrl.GetItemText(nRow, nCol)) != 0)
					listCtrl.SetItemText(nRow, nCol, arrListContent[nRow][nCol]);
			}
		}
		for (; nRow<nSize; nRow++)
		{
			if (nRow < arrListItemImage.size())
				listCtrl.InsertItem(nRow, arrListContent[nRow][0], arrListItemImage[nRow]);
			else
				listCtrl.InsertItem(nRow, arrListContent[nRow][0]);
			listCtrl.SetItemData(nRow, arrListItemData[nRow]);
			for (int nCol=1; nCol<arrListContent[nRow].size(); nCol++)
				listCtrl.SetItemText(nRow, nCol, arrListContent[nRow][nCol]);
		}
	}
	else
	{
		for (nRow=0; nRow<nSize; nRow++)
		{
			if (nRow < arrListItemImage.size())
			{
				lvItem.iItem = nRow;
				lvItem.iSubItem = 0;
				listCtrl.GetItem(&lvItem);
				lvItem.iImage = arrListItemImage[nRow];
				listCtrl.SetItem(&lvItem);
			}
			if (arrListItemData[nRow] != (int)listCtrl.GetItemData(nRow))
				listCtrl.SetItemData(nRow, arrListItemData[nRow]);
			for (int nCol=0; nCol<arrListContent[nRow].size(); nCol++)
			{
				if (arrListContent[nRow][nCol].Compare(listCtrl.GetItemText(nRow, nCol)) != 0)
					listCtrl.SetItemText(nRow, nCol, arrListContent[nRow][nCol]);
			}
		}
		for (; nRow<nItemCount; nRow++)
			listCtrl.DeleteItem(nSize);
	}
}
