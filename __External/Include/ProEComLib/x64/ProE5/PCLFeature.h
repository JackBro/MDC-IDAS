//===================================================================================================
// File:
//		PCLFeature.h
// Summary:
//		�����ӿ���
// Date:
//		2016-08-19
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once
#include "PCLModelitem.h"

//===================================================================================================
// �����ӿ���
class CPCLFeature : public CPCLModelitem
{
public:
	CPCLFeature();
	virtual ~CPCLFeature();

public:
	// ��ȡ������������
	static BOOL GetNewFeatureName(
		ProSolid pSld,												// ģ��(in)
		ProName szNameExpected,										// ������������������(in)
		ProName szNewFeaName,										// ����������(out)
		BOOL bStartWith1 = FALSE									// ���ֺ�׺�Ƿ��1��ʼ���(in)
		);

	// ��ȡ��������������������ɵ�����
	static BOOL GetFeatureAllPatternFeatures(
		ProFeature &feature,										// ��������(in)
		vector<ProFeature> &arrPatternFeatures						// ����������(out)
		);

	// ������
	static BOOL CreateGroup(
		ProSolid pSld,												// ģ��(in)
		ProName szGroupName,										// ����(in)
		const vector<ProFeature> &arrFeatures,						// ����(in)
		ProGroup &newGroup											// ��(out)
		);

protected:
	// ����һ��Ԫ��
	static ProError AddElement(
		ProElement pParentElement,									// �ϲ�Ԫ��(in)
		ProElemId nElemID,											// Ԫ�ر�ʶ(in)
		ProElement &pNewElement										// ��Ԫ��(out)
		);

	// ����һ��Ԫ��
	static ProError AddElement(
		ProElement pParentElement,									// �ϲ�Ԫ��(in)
		ProElemId nElemID,											// Ԫ�ر�ʶ(in)
		int nValue,													// intԪ��ֵ(in)
		ProElement &pNewElement										// ��Ԫ��(out)
		);

	// ����һ��Ԫ��
	static ProError AddElement(
		ProElement pParentElement,									// �ϲ�Ԫ��(in)
		ProElemId nElemID,											// Ԫ�ر�ʶ(in)
		double dValue,												// doubleԪ��ֵ(in)
		ProElement &pNewElement										// ��Ԫ��(out)
		);

	// ����һ��Ԫ��
	static ProError AddElement(
		ProElement pParentElement,									// �ϲ�Ԫ��(in)
		ProElemId nElemID,											// Ԫ�ر�ʶ(in)
		void *p,													// ָ��(in)
		ProElement &pNewElement										// ��Ԫ��(out)
		);

	// ����һ��Ԫ��
	static ProError AddElement(
		ProElement pParentElement,									// �ϲ�Ԫ��(in)
		ProElemId nElemID,											// Ԫ�ر�ʶ(in)
		char *strValue,												// charԪ��ֵ(in)
		ProElement &pNewElement										// ��Ԫ��(out)
		);

	// ����һ��Ԫ��
	static ProError AddElement(
		ProElement pParentElement,									// �ϲ�Ԫ��(in)
		ProElemId nElemID,											// Ԫ�ر�ʶ(in)
		wchar_t *wstrValue,											// WcharԪ��ֵ(in)
		ProElement &pNewElement										// ��Ԫ��(out)
		);

	// ����һ��Ԫ��
	static ProError AddElement(
		ProElement pParentElement,									// �ϲ�Ԫ��(in)
		ProElemId nElemID,											// Ԫ�ر�ʶ(in)
		ProSelection pSelValue,										// ѡ�����(in)
		ProElement &pNewElement										// ��Ԫ��(out)
		);

	// ����һ��Ԫ��
	static ProError AddElement(
		ProElement pParentElement,									// �ϲ�Ԫ��(in)
		ProElemId nElemID,											// Ԫ�ر�ʶ(in)
		ProBoolean bValue,											// ����ֵ(in)
		ProElement &pNewElement										// ��Ԫ��(out)
		);

	// ��ȡԪ�ص�����
	static ProError GetElementValueData(
		ProElement pElementTree, 
		ProElempathItem pathItems[], 
		int nCount, 
		ProValueData &valueData
		);

	// ����Ԫ�ص�����
	static ProError SetElementValueData(
		ProElement pElementTree,
		ProElempathItem pathItems[],
		int nCount,
		ProValueData &valueData
		);
private:
	// ��ȡ�����ĸ�������
	static BOOL GetFeatureRootPattern(
		ProFeature &feature,										// ����(in)
		ProPattern &rootPattern										// ������������(out)
		);

};

//===================================================================================================
