//===================================================================================================
// Summary:
//		װ����غ�����
// Date:
//		2016-08-31
// Author:
//		HuoPengcheng(huopc@buaa.edu.cn)
//===================================================================================================

// ����ProEͷ�ļ�
#include <ProMdl.h>

//====================================================================================================

#pragma once

//====================================================================================================
// װ����غ�����
class CPCLAssembly
{
public:
	CPCLAssembly();
	virtual ~CPCLAssembly();

public:
	// �������ϵԼ��
	BOOL AddCsysConstraint(
		ProAsmcomp &asmcomp,					// �µ�Ԫ��(in)
		ProAssembly pAsm,						// װ����(in)
		ProSelection pSelCsys,					// ѡ��Ļ�׼����ϵ(in)
		ProSelection pSelCompCsys				// ģ�͵�����ϵ(in)
		);

public:

	// ����ģ����װ���壬������ϵװ��
	BOOL AddModelToAsmWithCsysCons(
		ProAssembly pAsm,						// װ����(in)
		ProSelection pSelCsys,					// ѡ��Ļ�׼����ϵ(in)
		ProSolid pMdlToAdd,						// ��������ģ��(in)
		ProModelitem &csysItem,					// ģ�͵�����ϵ(in)
		ProAsmcomp &newAsmcomp					// �µ�Ԫ��(out)
		);

};

//===================================================================================================


