//===================================================================================================
// File:
//		IKSCutting.h
// Summary:
//		���з���
// Date:
//		2016-04-27
// Author:
//		Wumingli(wumingli007@163.com)
//===================================================================================================

#pragma once

//===================================================================================================

#include "IKSSymbol.h"

//===================================================================================================

typedef struct _tagCuttingInfo
{
	double RefPosX;				// ���з��ŵڶ������õ�X
	CString strName;			// ���з�������

	_tagCuttingInfo()
	{
		RefPosX = 0.0;
		strName = L"Undefine";
	}

	_tagCuttingInfo &operator=(const _tagCuttingInfo& info){
		if (&info != this)
		{
			RefPosX = info.RefPosX;
			strName = info.strName;
		}
		return *this;
	}
}CuttingInfo;

//===================================================================================================


class CIKSCutting :public CIKSSymbol
{
public:
	CIKSCutting(void);
	virtual ~CIKSCutting(void);

public:
	// �������з�����Ϣ�������߼���ע�ͼ�
	BOOL GetCurvesAndNotes(
		const CuttingInfo& cuttingInfo,		// ���з�����Ϣ(in)
		double dLineWidth,					// �߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص��������������Ϊ�գ���ʹ��Ĭ�Ϻ���(in)
		IKSCurveArray &arrCurves,			// ���μ�(out)
		IKSNoteArray &arrNotes,				// ע�ͼ�(out)
		IKSAnnoAttribute &attr				// ��ע����(out)
		);
	// ��ȡ���з��ŵ����߼�
	BOOL GetCurves(
		double dLineWidth,					// �߿�(in)
		IKSCurveArray &arrCurves			// ���μ�(out)
		);
};
