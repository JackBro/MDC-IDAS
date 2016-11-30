//===================================================================================================
// File:
//		PCLCopyGeometry.h
// Summary:
//		���Ƽ��νӿ���
// Date:
//		2016-08-19
// Author:
//		HuoPengCheng(Huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================
// ���Ƽ��νӿ���
class CPCLCopyGeometry : public CPCLFeature
{
public:
	CPCLCopyGeometry();
	virtual ~CPCLCopyGeometry();

public:
	
	// �ж������Ƿ��Ǹ��Ƽ���
	static BOOL IsFeatureCopyGeom(
		ProFeature &feature						// ����(in)
		);

	// ��ȡģ�͵ĸ��Ƽ���(ֻ��ȡ��ǰ����ģ�͵���һ��)
	BOOL GetMdlCopyGeom(
		ProMdl pMdl,							// ģ��(in)
		vector<ProFeature> &arrCopyGeom			// ��������(out)
		);

	// ���ݸ��Ƽ��λ�ȡ���Ƽ��εĲο�ģ��
	BOOL GetCopyGeomRefMdl(
		ProFeature &feaCopyGeom, 				// ���Ƽ���(in)
		ProMdl &pRefMdl							// �ο�ģ��(out)
		);

	// ���ݷ����������ɸ��Ƽ��Σ���ȱʡ�ο���ʽ
	BOOL CreateCopyGeomByPubGeom(
		ProSolid pSld,							// ���Ƽ�������ģ��(in)
		ProSelection pSelPubGeom,				// ѡ��ķ�������(in)
		ProName szCGName,						// ���Ƽ���������(in)
		ProFeature &newCopyFeature				// �µĸ��Ƽ�������(out)
		);

	// ���ݷ����������ɾֲ����Ƽ���
	BOOL CreateLocalCopyGeomByPubGeom(
		ProSelection pSelSld,					// ���Ƽ�������ģ��(in)
		ProSelection pSelPubGeom,				// ѡ��ķ�������(in)
		ProName szCGName,						// ���Ƽ���������(in)
		ProFeature &newCopyFeature				// �µĸ��Ƽ�������(out)
		);

	// ���ݷ����������ɸ��Ƽ��Σ�������ϵ�ο���ʽ
	BOOL CreateCopyGeomByPubGeomUseCsys(
		ProSolid pPubGeomMdl,					// ����������ģ��(in)
		ProSelection pSelExtCsys,				// �ⲿ�ο�����ϵ��·������ڷ���������ģ��(in)
		ProSelection pSelPubGeom,				// ��������ѡ�����·������ڷ���������ģ��(in)
		ProSolid pCopyGeomMdl,					// ���Ƽ�����ģ��(in)
		ProSelection pSelLocalCsys,				// �ֲ��ο�����ϵ��·������ڸ��Ƽ�����ģ��(in)
		ProName szCGName,						// ���Ƽ���������(in)
		ProFeature &newCopyFeature				// �µĸ��Ƽ�������(out)
		);

protected:

	// �������Ƽ��������Ķ�������(ֻ����ģ�͵���һ��)
	static ProError GetCopyGeomVisit(ProFeature* pFeature, ProError status, ProAppData pAppData);
	// �����������������Ĺ��˺���
	static ProError GetCopyGeomFilter(ProFeature* pFeature, ProAppData pAppData);

};


//===================================================================================================
 