//===================================================================================================
// File:
//		PCLFeature.h
// Summary:
//		特征接口类
// Date:
//		2016-08-19
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once
#include "PCLModelitem.h"

//===================================================================================================
// 特征接口类
class CPCLFeature : public CPCLModelitem
{
public:
	CPCLFeature();
	virtual ~CPCLFeature();

public:
	// 获取新特征的名称
	static BOOL GetNewFeatureName(
		ProSolid pSld,												// 模型(in)
		ProName szNameExpected,										// 期望命名特征的名字(in)
		ProName szNewFeaName,										// 新特征名称(out)
		BOOL bStartWith1 = FALSE									// 名字后缀是否从1开始标记(in)
		);

	// 获取特征的所有相关阵列生成的特征
	static BOOL GetFeatureAllPatternFeatures(
		ProFeature &feature,										// 特征对象(in)
		vector<ProFeature> &arrPatternFeatures						// 阵列特征集(out)
		);

	// 创建组
	static BOOL CreateGroup(
		ProSolid pSld,												// 模型(in)
		ProName szGroupName,										// 组名(in)
		const vector<ProFeature> &arrFeatures,						// 特征(in)
		ProGroup &newGroup											// 组(out)
		);

protected:
	// 增加一个元素
	static ProError AddElement(
		ProElement pParentElement,									// 上层元素(in)
		ProElemId nElemID,											// 元素标识(in)
		ProElement &pNewElement										// 新元素(out)
		);

	// 增加一个元素
	static ProError AddElement(
		ProElement pParentElement,									// 上层元素(in)
		ProElemId nElemID,											// 元素标识(in)
		int nValue,													// int元素值(in)
		ProElement &pNewElement										// 新元素(out)
		);

	// 增加一个元素
	static ProError AddElement(
		ProElement pParentElement,									// 上层元素(in)
		ProElemId nElemID,											// 元素标识(in)
		double dValue,												// double元素值(in)
		ProElement &pNewElement										// 新元素(out)
		);

	// 增加一个元素
	static ProError AddElement(
		ProElement pParentElement,									// 上层元素(in)
		ProElemId nElemID,											// 元素标识(in)
		void *p,													// 指针(in)
		ProElement &pNewElement										// 新元素(out)
		);

	// 增加一个元素
	static ProError AddElement(
		ProElement pParentElement,									// 上层元素(in)
		ProElemId nElemID,											// 元素标识(in)
		char *strValue,												// char元素值(in)
		ProElement &pNewElement										// 新元素(out)
		);

	// 增加一个元素
	static ProError AddElement(
		ProElement pParentElement,									// 上层元素(in)
		ProElemId nElemID,											// 元素标识(in)
		wchar_t *wstrValue,											// Wchar元素值(in)
		ProElement &pNewElement										// 新元素(out)
		);

	// 增加一个元素
	static ProError AddElement(
		ProElement pParentElement,									// 上层元素(in)
		ProElemId nElemID,											// 元素标识(in)
		ProSelection pSelValue,										// 选择对象(in)
		ProElement &pNewElement										// 新元素(out)
		);

	// 增加一个元素
	static ProError AddElement(
		ProElement pParentElement,									// 上层元素(in)
		ProElemId nElemID,											// 元素标识(in)
		ProBoolean bValue,											// 布尔值(in)
		ProElement &pNewElement										// 新元素(out)
		);

	// 获取元素的数据
	static ProError GetElementValueData(
		ProElement pElementTree, 
		ProElempathItem pathItems[], 
		int nCount, 
		ProValueData &valueData
		);

	// 设置元素的数据
	static ProError SetElementValueData(
		ProElement pElementTree,
		ProElempathItem pathItems[],
		int nCount,
		ProValueData &valueData
		);
private:
	// 获取特征的根部阵列
	static BOOL GetFeatureRootPattern(
		ProFeature &feature,										// 特征(in)
		ProPattern &rootPattern										// 特征根部阵列(out)
		);

};

//===================================================================================================
