//===================================================================================================
// File:
//		PCLDatumPlane.h
// Summary:
//		ƽ��ӿ���
// Date:
//		2016-08-30
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================

// ƽ��ӿ���
class CPCLDatumPlane : public CPCLFeature
{
public:
	CPCLDatumPlane();
	virtual ~CPCLDatumPlane();
public:

	// ͨ�����ƫ�����ɻ�׼ƽ��
	BOOL CreateDatumPlaneByOffset(
		ProSelection pSelSld,									// ��׼������ģ��(in)
		ProSelection pSelRefPlane,								// ѡ��Ĳο�ƽ��(in)
		double dOffset,											// ƫ�Ʋο�ƽ��ľ���(in)
		ProName szPlaneName,									// ��׼������(in)
		ProFeature &newPlaneFeature								// �µ�ƽ������(out)
		);

};

//===================================================================================================
 