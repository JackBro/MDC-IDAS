//===================================================================================================
// File:
//		PCLModelitem.h
// Summary:
//		��Ŀ��
// Date:
//		2016-08-30
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

//===================================================================================================

// ��Ŀ��
class CPCLModelitem
{
public:
	CPCLModelitem();
	virtual ~CPCLModelitem();

public:

	// ��ȡ��Ŀ����
	static CString GetModelItemName(
		ProModelitem &item								// ��Ŀ
		);

	// ������Ŀ
	int FindModelItem(
		ProModelitem &mdlItem,							// ָ����Ŀ(in)
		const vector<ProModelitem> &arrItems			//	��Ŀ��(in)
		);

	// ��ȡ�����ļ�����Ŀ
	static BOOL GetFeatureGeomItems(
		ProFeature &feature,							// ����(in)
		ProType eGeomType,								// ��������(in)
		vector<ProGeomitem> &arrGeomItems				// ���μ�(out)
		);

	// ��ȡ�����ļ�����Ŀѡ�����
	static BOOL GetFeatureGeomItemSelections(
		ProSelection pSelFeature,						// ����ѡ�����(in)
		ProType eGeomType,								// ��������(in)
		vector<ProSelection> &arrGeomSels				// ����ѡ�����(out)
		);



private:
	// ��ȡ����������Ŀ�Ķ�������
	static ProError GetFeatureGeomItemsAction(ProGeomitem *pItem, ProError status, ProAppData pAppData);

};

//===================================================================================================
 