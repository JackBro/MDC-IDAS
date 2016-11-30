//===================================================================================================
// File:
//		PCLPoint.h
// Summary:
//		��ӿ���
// Date:
//		2016-09-02
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================

// ��ӿ���
class CPCLPoint : public CPCLFeature
{
public:
	CPCLPoint();
	virtual ~CPCLPoint();

public:

	// ��ȡ����Ŀ��λ�ã��ֲ�����ϵ
	static BOOL GetPointCoords(
		ProModelitem &pointItem,							// �����Ŀ(in)
		ProPoint3d pointPos									// ���λ��(out)
		);

	// ��ȡѡ����λ�ã���������ϵ
	static BOOL GetPointCoords(
		ProSelection pSelPoint,								// �����Ŀ(in)
		SVDOUBLE3 &pointPos									// ���λ��(out)
		);

	// ���ɻ�׼��
	BOOL CreateDatumPoints(
		ProSelection pSelSld,								// ��׼����������ģ��(in)
		ProSelection pSelCsys,								// �ο�����ϵ�����Ϊ��������Ĭ�ϵ�����ϵ(in)
		const vector<SVDOUBLE3> &arrPoints,					// ���λ��(in)
		ProName szDtmPntFeatureName,						// ��׼��������(in)
		ProFeature &newDatumPointsFeature					// ��׼������(out)
		);

	// ���ɻ�׼�㣨��������ϵԭ��λ�ã�
	BOOL CreateDatumPointByCsys(
		ProSelection pSelSld,								// ��׼����������ģ��(in)
		ProSelection pSelCsys,								// �ο�����ϵ(in)
		ProName szDtmPntFeatureName,						// ��׼��������(in)
		ProFeature &newDatumPointFeature					// ��׼������(out)
		);

	// �޸Ļ�׼�㣨��Ӧ��ƫ������ϵ��׼�㣩
	BOOL ModifyDatumPoints(
		ProSelection pSelDatumFeature,						// ��׼������(in)
		const vector<SVDOUBLE3> &arrPoints					// ���λ��(��������)(in)
		);

	// ��ȡѡ�������Ͼ����������ĵ�
	BOOL GetPointOnSurface(
		ProSelection pSelSurf,								// ѡ������(in)
		SVDOUBLE3 &vInputPoint,								// �����(in)
		SVDOUBLE3 &vPointOnSurf								// �����ϵĵ�(out)
		);
};

//===================================================================================================
 