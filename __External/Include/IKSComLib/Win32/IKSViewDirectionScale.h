//===================================================================================================
// File:
//		IKSViewDirectionScale.h
// Summary:
//		�����������
// Date:
//		2016-11-08
// Author:
//		lgq
//===================================================================================================

#pragma once

//===================================================================================================

#include "IKSSymbol.h"

//===================================================================================================

// ��������������ı�����
typedef enum __tagViewDirectionScaleUpTextType
{
	VDSUTT_A				= 0,		// A
	VDSUTT_A_A				= 1,		// A-A
	VDSUTT_A_DIR			= 2			// A��
} ViewDirectionScaleUpTextType;

// �������������Ϣ
typedef struct __tagViewDirectionScaleInfo
{
	CString strUpText;								// ���ı�
	int nUpTextType;								// ���ı�����
	CString strDownLeftScale;						// ���ı������
	CString strDownRightScale;						// ���ı��ұ���

	__tagViewDirectionScaleInfo()
	{
		strUpText = _T("A");
		nUpTextType = VDSUTT_A_A;
		strDownLeftScale = _T("1");
		strDownRightScale = _T("1");
	}
	__tagViewDirectionScaleInfo(const __tagViewDirectionScaleInfo &data)
	{
		strUpText = data.strUpText;
		nUpTextType = data.nUpTextType;
		strDownLeftScale = data.strDownLeftScale;
		strDownRightScale = data.strDownRightScale;
	}
	__tagViewDirectionScaleInfo operator=(const __tagViewDirectionScaleInfo &data)
	{
		if (&data == this)
			return *this;
		strUpText = data.strUpText;
		nUpTextType = data.nUpTextType;
		strDownLeftScale = data.strDownLeftScale;
		strDownRightScale = data.strDownRightScale;
		return *this;
	}
}ViewDirectionScaleInfo;

//===================================================================================================

// ���ؼ����
class CIKSViewDirectionScale : public CIKSSymbol
{
public:
	CIKSViewDirectionScale(void);
	virtual ~CIKSViewDirectionScale(void);

public:
	// �������������Ϣ�������߼���ע�ͼ�
	BOOL GetCurvesAndNotes(
		const ViewDirectionScaleInfo &info,	// ���������Ϣ(in)
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
	double m_dItemMinDist;					// Ԫ��֮�����С���
	double m_dLength;						// ���򳤶�
	double m_dWidth;						// ������
};
