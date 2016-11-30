//===================================================================================================
// File:
//		IKSKeyFlag.h
// Summary:
//		�ؼ�������
// Date:
//		2016-01-12
// Author:
//		Wumingli(wumingli007@163.com)
//===================================================================================================

#pragma once

//===================================================================================================

#include "IKSSymbol.h"

//===================================================================================================

typedef enum __tagKeyFlagType
{
	KFT_KEYFLAG					= 1,					// �ؼ���
	KFT_KEYIMPORTANCEFLAG		= 2,					// ��Ҫ��
}KeyFlagType;

//===================================================================================================

// ���ؼ����
class CIKSKeyFlag : public CIKSSymbol
{
public:
	CIKSKeyFlag(void);
	virtual ~CIKSKeyFlag(void);

public:
	// ���ݹؼ�����Ϣ�������߼���ע�ͼ�
	BOOL GetCurvesAndNotes(
		const KeyFlagType &eKeyType,		// �ؼ�������(in)
		double dLineWidth,					// �߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSCurveArray &arrCurves,			// ���μ�(out)
		IKSNoteArray &arrNotes,				// ע�ͼ�(out)
		IKSAnnoAttribute &attr				// ��ע����(out)
		);
	
	// �������߼�
	BOOL GetCurves(
		IKSCurveArray &arrCurves			// ���μ�(out)
		);

private:
	double m_dLength;						// ���򳤶�
	double m_dWidth;						// ������
};

// ���������ؼ����
class CIKSTitleKeyFlag : public CIKSSymbol
{
public:
	CIKSTitleKeyFlag(void);
	virtual ~CIKSTitleKeyFlag(void);

public:
	// ���ݹؼ�����Ϣ�������߼���ע�ͼ�
	BOOL GetCurvesAndNotes(
		const KeyFlagType &eKeyType,		// �ؼ�������(in)
		double dLineWidth,					// �߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSCurveArray &arrCurves,			// ���μ�(out)
		IKSNoteArray &arrNotes,				// ע�ͼ�(out)
		IKSAnnoAttribute &attr				// ��ע����(out)
		);

	// �������߼�
	BOOL GetCurves(
		IKSCurveArray &arrCurves			// ���μ�(out)
		);

private:
	double m_dLength;						// ���򳤶�
	double m_dWidth;						// ������
};