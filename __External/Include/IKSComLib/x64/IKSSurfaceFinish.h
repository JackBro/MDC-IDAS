//===================================================================================================
// Summary:
//		�ֲڶȷ���
// Date:
//		2015-08-01			����
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSSurfaceFinish_h__
#define __IKSSurfaceFinish_h__

//===================================================================================================

#include "IKSSymbol.h"

//===================================================================================================

// ����ֲڶȵĻ�����������
typedef enum __tagSurfFinishSymbolType
{
	SURF_SYMBOL1	= 1,			// ȥ������
	SURF_SYMBOL2	= 2,			// ��ȥ������
	SURF_SYMBOL3	= 3				// �����κι���
} SurfFinishSymbolType;

// ����ֲڶȵ���������
typedef enum __tagSurfFinishTexturetype
{
	SURF_TEXTURE_PARALLEL	= 1,		// ƽ��
	SURF_TEXTURE_VERTICAL	= 2,		// ��ֱ
	SURF_TEXTURE_CROSS		= 3,		// ����
	SURF_TEXTURE_MULTI		= 4,		// �������
	SURF_TEXTURE_CIRCLE		= 5,		// ͬ��
	SURF_TEXTURE_RADIATION	= 6,		// ����
	SURF_TEXTURE_P			= 7,		// �޷�����͹���ϸ����
	SURF_TEXTURE_CLEAR		= 8			// ��
} SurfFinishTexturetype;

//===================================================================================================

// ����ֲڶ���Ϣ
typedef struct __tagSurfFinishInfo
{
	int nSymbolType;			// �����������ͣ� �ο�SurfFinishSymbolTypeö��ֵ
	int nTextureType;			// ���� �ο�SurfFinishTexturetypeö��ֵ
	int nAttachType;			// ���÷�ʽ���ο�SDSymbolAttachTypeö��ֵ
	CString	strSurfText1;		// �Ҳ�ߴ�1
	CString	strSurfText2;		// �Ҳ�ߴ�2
	CString	strSurfText3;		// �Ҳ�ߴ�3
	CString	strOther;			// ����
	CString	strSurfMin;			// ��С�ߴ�
	CString	strSurfMax;			// ���ߴ�
	BOOL bSameReq;				// ��ͬҪ��
	double dAngle;				// �Ƕ�
	double dTextHeight;			// �ı��߶�
	BOOL bIsFlip;				// �Ƿ���;��ֻ����nAttachTypeΪSATYPE_NORM_ITEMʱ��Ч��

	__tagSurfFinishInfo()
	{
		nSymbolType = SURF_SYMBOL1;
		nTextureType = SURF_TEXTURE_CLEAR;
		nAttachType = SATYPE_NORM_ITEM;
		strSurfText1 = _T("");
		strSurfText2 = _T("");
		strSurfText3 = _T("");
		strOther = _T("");
		strSurfMin = _T("");
		strSurfMax = _T("");
		bSameReq = FALSE;
		dAngle = 0;
		dTextHeight = 3.5;
		bIsFlip = FALSE;
	}
	void operator=(const __tagSurfFinishInfo& info){
		nSymbolType = info.nSymbolType;	
		nTextureType = info.nTextureType;
		nAttachType = info.nAttachType;
		strSurfText1 = info.strSurfText1;
		strSurfText2 = info.strSurfText2;
		strSurfText3 = info.strSurfText3;
		strOther = info.strOther;
		strSurfMin = info.strSurfMin;
		strSurfMax = info.strSurfMax;
		bSameReq = info.bSameReq;
		dAngle = info.dAngle;
		dTextHeight = info.dTextHeight;
		bIsFlip = info.bIsFlip;
	}
} SurfFinishInfo;

//===================================================================================================

class CIKSSurfaceFinish : public CIKSSymbol
{
public:
	CIKSSurfaceFinish();
	virtual ~CIKSSurfaceFinish();

public:
	// ���ݱ���ֲڶ���Ϣ�������߼���ע�ͼ�
	BOOL GetCurvesAndNotes(
		const SurfFinishInfo &surfInfo,		// ����ֲڶ���Ϣ(in)
		double dLineWidth,					// �߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص��������������Ϊ�գ���ʹ��Ĭ�Ϻ���(in)
		IKSCurveArray &arrCurves,			// ���μ�(out)
		IKSNoteArray &arrNotes,				// ע�ͼ�(out)
		IKSAnnoAttribute &attr				// ��ע����(out)
		);

private:
	// ��ȡ����ֲڶȺ��ĵ����߼�
	BOOL GetBaseSymbolCurves(
		int nSymbolType,					// �ֲڶȷ�������(in)
		IKSCurveArray &arrCurves			// ���߼�(out)
		);
	// ��ȡ����ֲڶ���������߼�
	BOOL GetTextureCurves(
		int nTextureType,					// ��������(in)
		double dLineWidth,					// �߿�(in)
		IKSCurveArray &arrCurves			// ���߼�(out)
		);
	// ��ȡ��ͬҪ������߼�
	BOOL GetSameReqCurves(
		double dLineWidth,					// �߿�(in)
		IKSCurveArray &arrCurves			// ���߼�(out)
		);
	// ��ȡ�Ҳ��ע����
	BOOL GetSurfTextCurves(
		const SurfFinishInfo &surfInfo,		// ����ֲڶ���Ϣ(in)
		IKSBox dSurfText1Outline,			// �Ҳ�ߴ�1�İ�Χ��(in)
		IKSBox dSurfText2Outline,			// �Ҳ�ߴ�2�İ�Χ��(in)
		IKSBox dSurfText3Outline,			// �Ҳ�ߴ�3�İ�Χ��(in)
		double dLineWidth,					// �߿�(in)
		IKSCurveArray &arrCurves			// ���߼�(out)
		);
	// ��ȡ�Ҳ�ߴ�1��ע�ͼ�
	BOOL GetSurfText1Notes(
		const CString &strSurfText1,		// �Ҳ�ߴ�1(in)
		double dLineWidth,					// �߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSNoteArray &arrSurfText1Notes,	// �Ҳ�ߴ�1��ע�ͼ�(out)
		IKSBox dSurfText1Outline			// �Ҳ�ߴ�1�İ�Χ��(out)
		);
	// ��ȡ�Ҳ�ߴ�2��ע�ͼ�
	BOOL GetSurfText2Notes(
		const CString &strSurfText2,		// �Ҳ�ߴ�2(in)
		double dLineWidth,					// �߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSNoteArray &arrSurfText2Notes,	// �Ҳ�ߴ�2��ע�ͼ�(out)
		IKSBox dSurfText2Outline			// �Ҳ�ߴ�2�İ�Χ��(out)
		);
	// ��ȡ�Ҳ�ߴ�3��ע�ͼ�
	BOOL GetSurfText3Notes(
		const CString &strSurfText3,		// �Ҳ�ߴ�3(in)
		double dLineWidth,					// �߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSNoteArray &arrSurfText3Notes,	// �Ҳ�ߴ�3��ע�ͼ�(out)
		IKSBox dSurfText3Outline			// �Ҳ�ߴ�3�İ�Χ��(out)
		);
	// ��ȡ����ߴ��ע�ͼ�
	BOOL GetOtherNotes(
		const CString &strOther,			// ����ߴ�(in)
		double dLineWidth,					// �߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSNoteArray &arrOtherNotes			// ����ߴ��ע�ͼ�(out)
		);
	// ��ȡ��С�ߴ��ע�ͼ�
	BOOL GetSurfMinNotes(
		const CString &strSurfMin,			// ��С�ߴ�(in)
		double dLineWidth,					// �߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSNoteArray &arrSurfMinNotes		// ��С�ߴ��ע�ͼ�(out)
		);
	// ��ȡ���ߴ��ע�ͼ�
	BOOL GetSurfMaxNotes(
		const CString &strSurfMax,			// ���ߴ�(in)
		double dLineWidth,					// �߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSNoteArray &arrSurfMaxNotes		// ���ߴ��ע�ͼ�(out)
		);

private:
	double m_dh;							// ���ֺ���ĸ�߶�h�����庬���GB/T 131-2006
	double m_dH1;							// �߶�H1�����庬���GB/T 131-2006
	double m_dH2;							// �߶�H2�����庬���GB/T 131-2006
};

//===================================================================================================

#endif