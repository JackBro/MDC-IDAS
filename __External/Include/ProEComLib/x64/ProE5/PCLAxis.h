//===================================================================================================
// File:
//		PCLAxis.h
// Summary:
//		��ӿ���
// Date:
//		2016-09-06
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================

// ��ӿ���
class CPCLAxis : public CPCLFeature
{
public:
	CPCLAxis();
	virtual ~CPCLAxis();
public:

	// ���ɻ�׼�ᣨ����������׼�㣩
	BOOL CreateDatumAxisByTwoPoints(
		ProSelection pSelSld,						// ��׼����������ģ��(in)
		ProSelection pSelPoint1,					// ��׼��1(in)
		ProSelection pSelPoint2,					// ��׼��2(in)
		ProName szDtmAxisFeatureName,				// ��׼��������(in)
		ProFeature &newDtmAxisFeature				// ��׼������(out)
		);

};

//===================================================================================================
 