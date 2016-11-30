//===================================================================================================
// File:
//		PCLEdge.h
// Summary:
//		�߽ӿ���
// Date:
//		2016-09-09
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================

// ��ӿ���
class CPCLEdge : public CPCLFeature
{
public:
	CPCLEdge();
	virtual ~CPCLEdge();
public:

	// ��ȡ�ߵ������յ�
	static BOOL GetEdgeStartAndEnd(
		ProGeomitem &edgeItem,							// �ߵ���Ŀ(in)
		SVDOUBLE3 &vStart,								// ���(out)
		SVDOUBLE3 &vEnd									// �յ�(out)
		);
	
};

//===================================================================================================
 