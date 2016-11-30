//===================================================================================================
// File:
//		PCLShrinkWrap.h
// Summary:
//		���Ƽ��νӿ���
// Date:
//		2016-09-11
// Author:
//		HuoPengCheng(Huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================
// ���Ƽ��νӿ���
class CPCLShrinkWrap : public CPCLFeature
{
public:
	CPCLShrinkWrap();
	virtual ~CPCLShrinkWrap();

public:
	
	// ����ģ�������������磬������ϵ�ο���ʽ
	static BOOL CreateShrinkWrapByPubGeomUseCsys(
		ProSolid pExtRefMdl,								// �ⲿ�ο���ģ��(in)
		ProSelection pSelExtCsys,							// �ⲿ�ο�����ϵ��·��������ⲿ�ο���ģ��(in)
		vector<ProSelection> &arrIncludeComps,				// �������������Ԫ����·��������ⲿ�ο���ģ��(in)
		vector<ProSelection> &arrNotIncludeComps,			// �������粻������Ԫ����·��������ⲿ�ο���ģ��(in)
		ProSolid pShrinkWrapMdl,							// ����������ģ��(in)
		ProSelection pSelLocalCsys,							// �ֲ��ο�����ϵ��·�����������������ģ��(in)
		int nQualityLevel,									// �����ȼ�(in)
		ProName szSWName,									// ��������������(in)
		ProFeature &newSWFeature							// �µ�������������(out)
		);

};


//===================================================================================================
 