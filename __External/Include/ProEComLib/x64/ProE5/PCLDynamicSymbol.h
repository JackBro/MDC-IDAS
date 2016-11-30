//===================================================================================================
// Summary:
//		��̬�����࣬�������ɿɱ�ķ���
// Date:
//		2015-07-22
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __PCLDynamicSymbol_h__
#define __PCLDynamicSymbol_h__

//===================================================================================================

#include <ProDtlsymdef.h>
#include <ProDtlsyminst.h>
#include <ProDtlnote.h>
#include <ProDtlentity.h>
#include "IKSGeom.h"
#include "IKSNote.h"

//===================================================================================================

// ���Ŷ�����÷�ʽ
typedef struct __tagPCLSymdefAttach
{
	ProDtlsymdefattachType eAttachType;	// ���õ�����
	int nEntityID;						// ���õ�ʵ�弸��ID�������ڷ�������Ϊ��ͼԪ�ϡ�����ֱ��ͼԪ���������ߡ��������ߡ����������ߡ�������
	double dEntityParameter;			// ʵ�弸�ε�λ�ò����������ڷ�������Ϊ��ͼԪ�ϡ�����ֱ��ͼԪ���������ߡ��������ߡ�������
	ProPoint3d dpLocation;				// ʵ�弸�ε�λ�ò����������ڷ�������Ϊ��ͼԪ�ϡ�����ֱ��ͼԪ���������ߡ��������ߡ�������

	__tagPCLSymdefAttach() 
	{
		eAttachType = PROSYMDEFATTACHTYPE_FREE;
		nEntityID = -1;
		dEntityParameter = 0.0;
		memset(dpLocation, 0, sizeof(ProPoint3d));
	}

	__tagPCLSymdefAttach &operator= (const __tagPCLSymdefAttach &attach) 
	{
		if (&attach != this)
		{
			eAttachType = attach.eAttachType;
			nEntityID = attach.nEntityID;
			dEntityParameter = attach.dEntityParameter;
			memcpy_s(dpLocation, sizeof(ProPoint3d), attach.dpLocation, sizeof(ProPoint3d));
		}
		return *this;
	}
} PCLSymdefAttach;

typedef vector<PCLSymdefAttach> PCLSymdefAttachArray;

// ���Ŷ�������
typedef struct __tagPCLSymdefAttribute
{
	ProDtlsymdefdataHeighttype eHeightType;	// �߶����ͣ��������̶��������ɱ��ͼ��λ�������ɱ�����ı��������ɱ�ģ�͵�λ��
	int nTextRefEntity;						// ���߶�����Ϊ���ɱ�����ı���ʱ������ı����ı�ID
	int nTextRefLine;						// ���߶�����Ϊ���ɱ�����ı���ʱ������ı�����������
	int nTextRefText;						// ���߶�����Ϊ���ɱ�����ı���ʱ������ı��������ı�����
	BOOL bTextAngleFixed;					// �ı��Ƕ��Ƿ�̶�
	PCLSymdefAttachArray arrAttaches;		// ���÷�ʽ��

	__tagPCLSymdefAttribute() 
	{
		eHeightType = PRODTLSYMDEFHGHTTYPE_VARIABLE;
		nTextRefEntity = -1;
		nTextRefLine = -1;
		nTextRefText = -1;
		bTextAngleFixed = FALSE;
	}

	__tagPCLSymdefAttribute &operator= (const __tagPCLSymdefAttribute &att) 
	{
		if (&att != this)
		{
			eHeightType = att.eHeightType;
			nTextRefEntity = att.nTextRefEntity;
			nTextRefLine = att.nTextRefLine;
			nTextRefText = att.nTextRefText;
			bTextAngleFixed = att.bTextAngleFixed;
			arrAttaches = att.arrAttaches;
		}
		return *this;
	}
} PCLSymdefAttribute;

namespace PCLDynamicSymbol
{
	// �������Ŷ���
	BOOL CreateSymdef(
		ProMdl pMdl,						// ģ��ָ��(in)
		ProName szSymdefName,				// ���Ŷ��������(in)
		ProDtlsymdef &symdef				// ���Ŷ���(out)
		);

	// �ڷ��Ŷ���������ʵ�弸��
	BOOL CreateEntityInSymdef(
		ProDtlsymdef &symdef,				// ���Ŷ���(in)
		ProCurvedata &curveData,			// �������ݣ�����ֱ�ߡ�Բ����(in)
		ProColortype eColorType,			// ��ɫ���ͣ��ο�ö�ٶ��壺ProColortype(in)
		double dWidth,						// �߿�(in)
		ProDtlentity &entity				// ʵ�弸��(out)
		);

	// �ڷ��Ŷ���������ʵ�弸��
	BOOL CreateEntityInSymdef(
		ProDtlsymdef &symdef,				// ���Ŷ���(in)
		IKSCurve &curveData,				// �������ݣ�����ֱ�ߡ�Բ����(in)
		double dWidth,						// �߿�(in)
		ProDtlentity &entity				// ʵ�弸��(out)
		);

	// �ڷ��Ŷ������޸�ʵ�弸��
	BOOL ModifyEntityInSymdef(
		ProDtlsymdef &symdef,				// ���Ŷ���(in)
		ProDtlentity &entity,				// ʵ�弸��(in)
		ProCurvedata &curveData,			// �������ݣ�����ֱ�ߡ�Բ����(in)
		ProColortype eColorType,			// ��ɫ���ͣ��ο�ö�ٶ��壺ProColortype(in)
		double dWidth						// �߿�(in)
		);

	// �ڷ��Ŷ������޸�ʵ�弸��
	BOOL ModifyEntityInSymdef(
		ProDtlsymdef &symdef,				// ���Ŷ���(in)
		ProDtlentity &entity,				// ʵ�弸��(in)
		IKSCurve &curveData,				// �������ݣ�����ֱ�ߡ�Բ����(in)
		double dWidth						// �߿�(in)
		);

	// �ڷ��Ŷ���������ע��
	BOOL CreateNoteInSymdef(
		ProDtlsymdef &symdef,				// ���Ŷ���(in)
		const IKSNote &noteInfo,			// ע�͵���Ϣ
		ProDtlnote &note					// ���ɵ�ע��(out)
		);

	// �ڷ��Ŷ������޸�ע��
	BOOL ModifyNoteInSymdef(
		ProDtlsymdef &symdef,				// ���Ŷ���(in)
		ProDtlnote &note,					// ���ɵ�ע��(out)
		const IKSNote &noteInfo				// ע�͵���Ϣ
		);

	// ���÷��Ŷ��������
	BOOL SetSymefAttributes(
		ProDtlsymdef &symdef,				// ���Ŷ���(in)
		const PCLSymdefAttribute &attr		// ���Ŷ�������(in)
		);

	// ��ȡ���Ÿ߶�����
	ProDtlsymdefdataHeighttype GetSymdefHeightType(
		int nAnnoHeightType					// ��ע�ĸ߶�����(in)
		);

	// ��ȡ���ŷ�������
	ProDtlsymdefattachType GetSymdefAttachType(
		int nAnnoAttachType					// ��ע�ķ�������(in)
		);

	// ��ȡˮƽ���뷽ʽ
	ProHorizontalJustification GetHorizontalJustification(
		int nHorzJustType					// ˮƽ���뷽ʽ(in)
		);

	// ��ȡ��ֱ���뷽ʽ
	ProVerticalJustification GetVerticalJustification(
		int nVertJustType					// ��ֱ���뷽ʽ(in)
		);

	// �ڷ��Ŷ�����������
	BOOL CreateGroupInSymdef(
		ProDtlsymdef &symdef,				// ���Ŷ���(in)
		ProName szGroupName,				// ������(in)
		int nParentGroupID,					// ���׵���ID�������Ϊ�������ֵΪ-1(in)
		ProDtlsymgroup &proNewGroup			// ���ɵ���(out)
		);

	// ������Ŷ��������е���
	BOOL ClearGroupInSymdef(
		ProDtlsymdef &symdef				// ���Ŷ���(in)
		);

	// ��ȡ���Ŷ����ע����������
	double GetSymdefNoteScale(
		ProDtlsymdef &symdef				// ���Ŷ���(in)
		);
};

//===================================================================================================

#endif