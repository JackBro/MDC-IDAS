//===================================================================================================
// File:
//		ListCtrlOperator.cpp
// Summary:
//		�б�ؼ�������
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

// ��ȡ�б�ؼ��Ķ������ݼ�
void CListCtrlOperator::GetListItemDataArray(
	CListCtrl &listCtrl,										// �б�ؼ�
	vector<int> &arrItemData									// �������ݼ�
	)
{
	arrItemData.clear();
	int nItemCount = listCtrl.GetItemCount();
	arrItemData.resize(nItemCount);
	for (int i=0; i<nItemCount; i++)
		arrItemData[i] = (int)listCtrl.GetItemData(i);
}

// ��ȡ�б�ؼ���ѡ�����
void CListCtrlOperator::GetListSelectedItems(
	CListCtrl &listCtrl,										// �б�ؼ�
	vector<int> &arrItems										// ѡ�����������
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

// ��ȡ�б�ؼ���ѡ���������
void CListCtrlOperator::GetListSelectedItemData(
	CListCtrl &listCtrl,										// �б�ؼ�
	vector<int> &arrItemData									// ѡ��������ݼ�
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

// �����б�ؼ�������
void CListCtrlOperator::SetListContent(
	CListCtrl &listCtrl,										// �б�ؼ�
	const vector<vector<CString>> &arrListContent,				// �б�����
	const vector<int> &arrListItemData,							// �б��еı��
	const vector<int> &arrListItemImage							// �б��е�ͼ��
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
