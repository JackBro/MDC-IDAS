//===================================================================================================
// File:
//		PCLPreview.h
// Summary:
//		�߽ӿ���
// Date:
//		2016-09-10
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once
#include "PCLCsys.h"

//===================================================================================================

// ��ӿ���
class CPCLPreview
{
public:
	CPCLPreview();
	virtual ~CPCLPreview();
public:

	// ����ϵԤ��
	static BOOL PreviewCsys(
		const IKSCsysData &csysData,								// ����ϵ����(in)
		double dArrowLength											// ��ͷ����(in)
		);

	// ԲԤ��
	static BOOL PreviewCircle(
		const SVDOUBLE3 &vCenter,									// ���ĵ�(in)
		const SVDOUBLE3 &vNormal,									// ����(in)
		double dRadius												// �뾶(in)
		);

	
};

//===================================================================================================
 