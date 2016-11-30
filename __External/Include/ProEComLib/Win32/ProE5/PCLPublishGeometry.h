//===================================================================================================
// File:
//		PCLPublishGeometry.h
// Summary:
//		�������νӿ���
// Date:
//		2016-08-23
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================
// �������νӿ���
class CPCLPublishGeometry : public CPCLFeature
{
public:
	CPCLPublishGeometry();
	virtual ~CPCLPublishGeometry();

public:

	// �ж������Ƿ��Ƿ�������
	static BOOL IsFeaturePubGeom(
		ProFeature &feature								// ����(in)
		);

	// ��ȡģ�͵ķ�������(ֻ��ȡ��ǰ����ģ�͵���һ��)
	BOOL GetMdlPubGeom(
		ProMdl pMdl,									// ģ��(in)
		vector<ProFeature> &arrPubGeom					// ��������(out)
		);

	// ��ȡ�������εĻ�׼��Ŀ��
	BOOL GetPubDatumItems(
		ProFeature &pubFeature,							// ����(in)
		ProType eDatumType,								// ��׼����(in)
		vector<ProGeomitem> &arrDatumItems				// ��Ŀ��(out)
		);
	
	// ���ݸ��Ƽ������ɷ�������
	BOOL CreatePubGeomByCopyGeom(
		ProSolid pPubGeomMdl,							// ������������ģ��(in)
		ProFeature &copyGeomFeature,					// ���Ƽ��Σ�ֱ���ڷ�����������ģ��(in)
		ProName szPBName,								// ��������������(in)
		ProFeature &newPubFeature						// �µķ�����������(out)
		);

protected:
	// �����������������Ķ�������(ֻ����ģ�͵���һ��)
	static ProError GetPubGeomVisit(ProFeature* pFeature, ProError status, ProAppData pAppData);
	// �����������������Ĺ��˺���
	static ProError GetPubGeomFilter(ProFeature* pFeature, ProAppData pAppData);

};


//===================================================================================================
 