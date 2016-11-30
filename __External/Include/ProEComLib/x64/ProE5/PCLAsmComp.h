//===================================================================================================
// File:
//		PCLAsmComp.h
// Summary:
//		Ԫ���ӿ���
// Date:
//		2016-09-08
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================

// Ԫ���ӿ���
class CPCLAsmComp : public CPCLFeature
{
public:
	CPCLAsmComp();
	virtual ~CPCLAsmComp();

public:

	// ��ȡԪ��·����Ӧģ�͵�ѡ�����
	static BOOL GetAsmcomppathSelection(
		ProAsmcomppath &asmcomppath,				// ·��(in)
		ProSelection &pSelMdl						// ѡ��ģ��(out)
		);

	// ��ȡԪ��ģ�͵�ѡ�����·�������Ԫ�������ĸ����
	static BOOL GetAsmcompSelection(
		ProAsmcomp &asmcomp,						// Ԫ������(in)
		ProSelection &pSelCompMdl					// װ��ο�����ϵ(out)
		);

	// ��ȡ·����Ԫ������
	static BOOL GetAsmcomppathCompFeature(
		ProAsmcomppath &comppath,					// ·��(in)
		ProAsmcomp &asmcomp							// Ԫ������(out)
		);

	// ����Ԫ��·����Ӧģ��
	static BOOL RegenerateAsmcomppathMdl(
		ProAsmcomppath &asmcomppath					// Ԫ��·��(in)
		);

};

//===================================================================================================
 