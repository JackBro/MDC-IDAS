//===================================================================================================
// File:
//		PCLModelitem.h
// Summary:
//		项目类
// Date:
//		2016-08-30
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

//===================================================================================================

// 项目类
class CPCLModelitem
{
public:
	CPCLModelitem();
	virtual ~CPCLModelitem();

public:

	// 获取项目名称
	static CString GetModelItemName(
		ProModelitem &item								// 项目
		);

	// 查找项目
	int FindModelItem(
		ProModelitem &mdlItem,							// 指定项目(in)
		const vector<ProModelitem> &arrItems			//	项目集(in)
		);

	// 获取特征的几何项目
	static BOOL GetFeatureGeomItems(
		ProFeature &feature,							// 特征(in)
		ProType eGeomType,								// 几何类型(in)
		vector<ProGeomitem> &arrGeomItems				// 几何集(out)
		);

	// 获取特征的几何项目选择对象
	static BOOL GetFeatureGeomItemSelections(
		ProSelection pSelFeature,						// 特征选择对象(in)
		ProType eGeomType,								// 几何类型(in)
		vector<ProSelection> &arrGeomSels				// 几何选择对象集(out)
		);



private:
	// 获取特征几何项目的动作函数
	static ProError GetFeatureGeomItemsAction(ProGeomitem *pItem, ProError status, ProAppData pAppData);

};

//===================================================================================================
 