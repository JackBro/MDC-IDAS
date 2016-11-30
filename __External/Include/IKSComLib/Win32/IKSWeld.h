//===================================================================================================
// Summary:
//		���ӷ���
// Date:
//		2015-08-01			����
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSWeld_h__
#define __IKSWeld_h__

//===================================================================================================

#include "IKSSymbol.h"

//===================================================================================================

// ���ӻ�����������
typedef enum __tagWeldingBaseType
{
	WELD_BASE_NULL			= 0,			// �Ƿ�
	WELD_BASE_TYPE1			= 1,			// ��ߺ���
	WELD_BASE_TYPE2			= 2,			// I�κ���
	WELD_BASE_TYPE3			= 3,			// V�κ���
	WELD_BASE_TYPE4			= 4,			// ����V�κ���
	WELD_BASE_TYPE5			= 5,			// ���۱�V�κ���
	WELD_BASE_TYPE6			= 6,			// ���۱ߵ���V�κ���
	WELD_BASE_TYPE7			= 7,			// ���۱�U�κ���
	WELD_BASE_TYPE8			= 8,			// ���۱�J�κ���
	WELD_BASE_TYPE9			= 9,			// ��׺���
	WELD_BASE_TYPE10		= 10,			// �Ǻ���
	WELD_BASE_TYPE11		= 11,			// �������ۺ���
	WELD_BASE_TYPE12		= 12,			// �㺸��
	WELD_BASE_TYPE13		= 13,			// �캸��
	WELD_BASE_TYPE14		= 14,			// ����V�κ���
	WELD_BASE_TYPE15		= 15,			// ���ߵ�V�κ���
	WELD_BASE_TYPE16		= 16,			// �˺���
	WELD_BASE_TYPE17		= 17,			// �Ѻ���
	WELD_BASE_TYPE18		= 18,			// ƽ�����ӣ�ǥ����
	WELD_BASE_TYPE19		= 19,			// б�����ӣ�ǥ����
	WELD_BASE_TYPE20		= 20,			// �۵����ӣ�ǥ����
	WELD_BASE_TYPE21		= 21,			// �����κ���
	WELD_BASE_TYPE22		= 22,			// ���������κ���
	WELD_BASE_TYPE23		= 23,			// ���ߺ���
} WeldingBaseType;

// ���Ӳ����������(ƽ��)
typedef enum __tagWeldingContourType
{
	WELD_CONTOUR_NULL		= 30,
	WELD_CONTOUR_FLAT		= 31,			// ƽ��
	WELD_CONTOUR_CONCAVE	= 32,			// ����
	WELD_CONTOUR_CONVEX		= 33,			// ͹��
	WELD_CONTOUR_SMOOTH		= 34,			// Բ������
	WELD_CONTOUR_FILLET		= 35,			// �Ǻ���
} WeldingContourType;

// ���Ӳ����������(�ĵ�)
typedef enum __tagWeldingStripType
{
	WELD_STRIP_NULL			= 40,
	WELD_STRIP_PERMANENT	= 41,			// ���óĵ�
	WELD_STRIP_REMOVABLE	= 42,			// ��ʱ�ĵ�
} WeldingStripType;

// ���Ӳ���������ͣ����溸�죩
typedef enum __tagWeldingFaceType
{
	WELD_FACE_NULL			= 50,
	WELD_FACE_RIGHT			= 51,
	WELD_FACE_LEFT			= 52,
	WELD_FACE_UP			= 53,
	WELD_FACE_DOWN			= 54,
} WeldingFaceType;

// ���Ӳ���������ͣ�β����
typedef enum __tagWeldingTailType
{
	WELD_TAIL_NULL			= 60,
	WELD_TAIL_TYPE1			= 61,
	WELD_TAIL_TYPE2			= 62	
} WeldingTailType;

// ���ӷ���λ��
typedef enum __tagWeldingLocation
{
	WELD_LOCATION_UP		= 0,
	WELD_LOCATION_CENTER	= 1,
	WELD_LOCATION_DOWN		= 2
} WeldingLocation;

// ��������λ��
typedef enum __tagWeldingDashPosition
{
	WELD_DASH_UP			= 0,
	WELD_DASH_DOWN			= 1,
	WELD_DASH_NONE			= 2
} WeldingDashPosition;

//===================================================================================================

// ���ӷ�����Ϣ
typedef struct __tagWeldingInfo
{
	int nUpBaseType;			// ����λ�����Ϸ�ʱ��������������, �ο�WeldingBaseTypeö��ֵ
	int nDownBaseType;			// ����λ�����·�ʱ��������������, �ο�WeldingBaseTypeö��ֵ
	int nCenterBaseType;		// ����λ�����м�ʱ��������������, �ο�WeldingBaseTypeö��ֵ��WELD_BASE_TYPE12��WELD_BASE_TYPE13����Ч

	int nUpContourType;			// ����λ�����Ϸ�ʱ��ƽ�油��������ͣ��ο�WeldingContourTypeö��ֵ
	int nDownContourType;		// ����λ�����·�ʱ��ƽ�油��������ͣ��ο�WeldingContourTypeö��ֵ
	int nLocation;				// ���ӷ���λ��, �ο�WeldingLocationö��ֵ

	int nUpStripType;			// ����λ�����Ϸ�ʱ�����Ӳ����������(�ĵ�)���ο�WeldingStripTypeö��ֵ
	int nDownStripType;			// ����λ�����·�ʱ�����Ӳ����������(�ĵ�)���ο�WeldingStripTypeö��ֵ

	int nTailType;				// β�����Ӳ���������ͣ��ο�WeldingTailTypeö��ֵ

	CString strUpLeftValue;		// ����λ�����Ϸ�ʱ����ߴ�
	CString strUpRootGap;		// ����λ�����Ϸ�ʱ��������϶
	CString strUpUpperValue;	// ����λ�����Ϸ�ʱ���ϳߴ�
	CString strUpRightValue1;	// ����λ�����Ϸ�ʱ���ҳߴ�1
	CString strUpRightValue2;	// ����λ�����Ϸ�ʱ���ҳߴ�2
	CString strUpRightValue3;	// ����λ�����Ϸ�ʱ���ҳߴ�3
	CString strDownLeftValue;	// ����λ�����·�ʱ����ߴ�
	CString strDownRootGap;		// ����λ�����·�ʱ��������϶
	CString strDownUpperValue;	// ����λ�����·�ʱ���ϳߴ�
	CString strDownRightValue1;	// ����λ�����·�ʱ���ҳߴ�1
	CString strDownRightValue2;	// ����λ�����·�ʱ���ҳߴ�2
	CString strDownRightValue3;	// ����λ�����·�ʱ���ҳߴ�3
	CString strCenterLeftValue;	// ����λ�����·�ʱ����ߴ�
	CString strCenterUpperValue;	// ����λ�����м�ʱ���ϳߴ�
	CString strCenterRightValue1;	// ����λ�����м�ʱ���ҳߴ�1
	CString strCenterRightValue2;	// ����λ�����м�ʱ���ҳߴ�2
	CString strCenterRightValue3;	// ����λ�����м�ʱ���ҳߴ�3


	CString strNote;			// ����˵��
	int nDashPosition;			// ��������λ��
	BOOL bAround;				// �Ƿ�Ϊ��Χ���ӷ���
	BOOL bScene;				// �Ƿ�Ϊ�ֳ�����
	BOOL bStagger;				// �Ƿ�Ϊ����������ӷ���

	int nTriFaceType;			// ���溸�캸�Ӳ���������ͣ��ο�WeldingFaceTypeö��ֵ

	int nAngle;					// ���ýǶ�

	BOOL bLeaderOrientLeft;		// ���ӵ����߷���TUREΪ��FALSEʱΪ��

	__tagWeldingInfo()
	{
		Init();	
	}

	void operator=(const __tagWeldingInfo& info){
		nUpBaseType = info.nUpBaseType;			
		nDownBaseType = info.nDownBaseType;			
		nCenterBaseType = info.nCenterBaseType;
		nUpContourType = info.nUpContourType;
		nDownContourType = info.nDownContourType;
		nUpStripType = info.nUpStripType;
		nDownStripType = info.nDownStripType;
		nLocation = info.nLocation;	
		nTailType = info.nTailType;
		strUpLeftValue = info.strUpLeftValue;	
		strUpRootGap = info.strUpRootGap;
		strUpUpperValue = info.strUpUpperValue;	
		strUpRightValue1 = info.strUpRightValue1;	
		strUpRightValue2 = info.strUpRightValue2;
		strUpRightValue3 = info.strUpRightValue3;
		strDownLeftValue = info.strDownLeftValue;	
		strDownRootGap = info.strDownRootGap;
		strDownUpperValue = info.strDownUpperValue;	
		strDownRightValue1 = info.strDownRightValue1;	
		strDownRightValue2 = info.strDownRightValue2;
		strDownRightValue3 = info.strDownRightValue3;
		strCenterLeftValue = info.strCenterLeftValue;	
		strCenterUpperValue = info.strCenterUpperValue;	
		strCenterRightValue1 = info.strCenterRightValue1;	
		strCenterRightValue2 = info.strCenterRightValue2;
		strCenterRightValue3 = info.strCenterRightValue3;

		strNote = info.strNote;

		nDashPosition = info.nDashPosition;

		bAround = info.bAround;
		bScene = info.bScene;
		bStagger = info.bStagger;
		nTriFaceType = info.nTriFaceType;
		nAngle = info.nAngle;
		bLeaderOrientLeft = info.bLeaderOrientLeft;
	}

	void Init()
	{
		nUpBaseType = WELD_BASE_NULL;			
		nDownBaseType = WELD_BASE_NULL;	
		nCenterBaseType = WELD_BASE_NULL;
		nLocation = WELD_LOCATION_UP;
		nUpContourType = WELD_CONTOUR_NULL;
		nDownContourType = WELD_CONTOUR_NULL;
		nUpStripType = WELD_STRIP_NULL;
		nDownStripType = WELD_STRIP_NULL;
		strUpLeftValue = _T("");	
		strUpRootGap = _T("");	
		strUpUpperValue = _T("");	
		strUpRightValue1 = _T("");	
		strUpRightValue2 = _T("");	
		strDownLeftValue = _T("");	
		strDownRootGap = _T("");	
		strDownUpperValue = _T("");	
		strDownRightValue1 = _T("");	
		strDownRightValue2 = _T("");
		strCenterLeftValue = _T("");
		strCenterUpperValue = _T("");	
		strCenterRightValue1 = _T("");
		strCenterRightValue2 = _T("");	
		strCenterRightValue3 = _T("");	
		strNote = _T("");		
		strUpRightValue3 = _T("");		
		strDownRightValue3 = _T("");	
		nDashPosition = WELD_DASH_DOWN;	
		bAround = FALSE;
		bScene = FALSE;
		nTailType = WELD_TAIL_TYPE1;
		bStagger = FALSE;
		nTriFaceType = WELD_FACE_NULL;
		nAngle = 0;
		bLeaderOrientLeft = TRUE;
	}
} WeldingInfo;

//===================================================================================================

class CIKSWeld : public CIKSSymbol
{
public:
	CIKSWeld();
	virtual ~CIKSWeld();

public:
	// ���ݺ�����Ϣ�������߼���ע�ͼ�
	BOOL GetCurvesAndNotes(
		const WeldingInfo &weldInfo,		// ������Ϣ(in)
		double dLineWidth,					// �߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص��������������Ϊ�գ���ʹ��Ĭ�Ϻ���(in)
		IKSCurveArray &arrCurves,			// ���μ�(out)
		IKSNoteArray &arrNotes,				// ע�ͼ�(out)
		IKSAnnoAttribute &attr				// ��ע����(out)
		);

private:
	// ��ȡ���ӷ��ź��ĵ����߼�
	BOOL GetkernelCurvesAndNotes(
		const WeldingInfo &weldInfo,		// ������Ϣ(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSCurveArray &arrCurves,			// ���߼�(out)
		IKSNoteArray &arrNotes,				// ע�ͼ�(out)
		IKSBox dUpBaseOutline,				// �Ϸ��������ŵİ�Χ��(out)
		IKSBox dDownBaseOutline				// �·��������ŵİ�Χ��(out)
		);

	// ��ȡ���ӻ������ŵ����߼�
	BOOL GetBaseSymbolCurvesAndNotes(
		int nBaseType,						// ������������(in)
		int nStripType,						// �ĵ�����(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSCurveArray &arrCurves,			// ���߼�(out)
		IKSNoteArray &arrNotes,				// ע�ͼ�(out)
		IKSBox dBaseOutline					// �������ŵİ�Χ��(out)
		);

	// ��ȡ������϶��ע�ͼ�
	BOOL GetRootGapNotes(
		const WeldingInfo &weldInfo,		// ������Ϣ(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSBox dUpBaseOutline,				// �Ϸ��������ŵİ�Χ��(out)
		IKSBox dDownBaseOutline,			// �·��������ŵİ�Χ��(out)
		IKSNoteArray &arrRootGapNotes		// ע�ͼ�(out)
		);

	// ��ȡ������ŵ����߼�
	BOOL GetAllContourCurves(
		const WeldingInfo &weldInfo,		// ������Ϣ(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSBox dUpBaseOutline,				// �Ϸ��������ŵİ�Χ��(in)
		IKSBox dDownBaseOutline,			// �·��������ŵİ�Χ��(in)
		IKSCurveArray &arrContourCurves,	// ������ŵ����߼�(out)
		IKSBox dUpContourOutline,			// �Ϸ��������ŵİ�Χ��(out)
		IKSBox dDownContourOutline			// �·��������ŵİ�Χ��(out)
		);

	// ������������Ϊ�Ǻ���ʱ������ŵİ�Χ��
	BOOL VerifyWeldFilletContourOutline(
		int nContourType,					// �����������(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSBox dContourOutline				// ������ŵİ�Χ��(out)
		);

	// ��ȡ������ŵ����߼�
	BOOL GetContourCurves(
		int nContourType,					// �����������(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSCurveArray &arrContourCurves,	// ������ŵ����߼�(out)
		IKSBox dContourOutline				// ������ŵİ�Χ��(out)
		);

	// ��ȡ��ߴ��ע�ͼ�
	BOOL GetLeftValueNotes(
		const CString &strUpLeftValue,		// �Ϸ���ߴ�(in)
		const CString &strDownLeftValue,	// �·���ߴ�(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSBox dUpMainOutline,				// �Ϸ���Ҫ�����Χ��(in)
		IKSBox dDownMainOutline,			// �·���Ҫ�����Χ��(in)
		IKSNoteArray &arrLeftValueNotes,	// ��ߴ��ע�ͼ�(out)
		IKSBox dUpLeftValueOutline,			// �Ϸ���ߴ�İ�Χ��(out)
		IKSBox dDownLeftValueOutline		// �·���ߴ�İ�Χ��(out)
		);

	// ��ȡ�ϳߴ��ע�ͼ�
	BOOL GetUpperValueNotes(
		const CString &strUpUpperValue,		// �Ϸ��ϳߴ�(in)
		const CString &strDownUpperValue,	// �·��ϳߴ�(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSBox dUpMainOutline,				// �Ϸ���Ҫ�����Χ��(in)
		IKSBox dDownMainOutline,			// �·���Ҫ�����Χ��(in)
		IKSNoteArray &arrUpperValueNotes,	// �ϳߴ��ע�ͼ�(out)
		IKSBox dUpUpperValueOutline,		// �Ϸ��ϳߴ�İ�Χ��(out)
		IKSBox dDownUpperValueOutline		// �·��ϳߴ�İ�Χ��(out)
		);

	// ��ȡ�ҳߴ�1��ע�ͼ�
	BOOL GetRightValue1Notes(
		const CString &strUpRightValue1,	// �Ϸ��ҳߴ�1(in)
		const CString &strDownRightValue1,	// �·��ҳߴ�1(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSBox dUpMainOutline,				// �Ϸ���Ҫ�����Χ��(in)
		IKSBox dDownMainOutline,			// �·���Ҫ�����Χ��(in)
		IKSNoteArray &arrRightValue1Notes,	// �ҳߴ�1��ע�ͼ�(out)
		IKSBox dUpRightValue1Outline,		// �Ϸ��ҳߴ�1�İ�Χ��(out)
		IKSBox dDownRightValue1Outline		// �·��ҳߴ�1�İ�Χ��(out)
		);

	// ��ȡ�ҳߴ�2��ע�ͼ�
	BOOL GetRightValue2Notes(
		const CString &strUpRightValue2,	// �Ϸ��ҳߴ�2(in)
		const CString &strDownRightValue2,	// �·��ҳߴ�2(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSBox dUpLeftItemOutline,			// �Ϸ������Ŀ�İ�Χ��(in)
		IKSBox dDownLeftItemOutline,		// �·������Ŀ�İ�Χ��(in)
		IKSNoteArray &arrRightValue2Notes,	// �ҳߴ�2��ע�ͼ�(out)
		IKSBox dUpRightValue2Outline,		// �Ϸ��ҳߴ�2�İ�Χ��(out)
		IKSBox dDownRightValue2Outline		// �·��ҳߴ�2�İ�Χ��(out)
		);

	// ��ȡ��������������߼�
	BOOL GetStaggerCurves(
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSBox dUpItemOutline,				// �Ϸ������Ŀ�İ�Χ��(in)
		IKSBox dDownItemOutline,			// �·������Ŀ�İ�Χ��(in)
		IKSCurveArray &arrStaggerCurves,	// ��������������߼�(out)
		IKSBox dUpStaggerOutline,			// �Ϸ�����������ŵİ�Χ��(out)
		IKSBox dDownStaggerOutline			// �·�����������ŵİ�Χ��(out)
		);

	// ��ȡ�ҳߴ�3��ע�ͼ�
	BOOL GetRightValue3Notes(
		const CString &strUpRightValue3,	// �Ϸ��ҳߴ�3(in)
		const CString &strDownRightValue3,	// �·��ҳߴ�3(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSBox dUpItemOutline,				// �Ϸ������Ŀ�İ�Χ��(in)
		IKSBox dDownItemOutline,			// �·������Ŀ�İ�Χ��(in)
		IKSNoteArray &arrRightValue3Notes,	// �ҳߴ�3��ע�ͼ�(out)
		IKSBox dUpRightValue3Outline,		// �Ϸ��ҳߴ�3�İ�Χ��(in)
		IKSBox dDownRightValue3Outline		// �·��ҳߴ�3�İ�Χ��(in)
		);

	// ��ȡ���溸�����߼�
	BOOL GetTriFaceCurves(
		int nTriFaceType,					// ���溸������(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSBox dUpItemOutline,				// �Ϸ��Ҳ���Ŀ�İ�Χ��(in)
		IKSBox dDownItemOutline,			// �·��Ҳ���Ŀ�İ�Χ��(in)
		IKSCurveArray &arrTriFaceCurves,	// ���溸�����߼�(out)
		IKSBox dTriFaceOutline				// ���溸��İ�Χ��(out)
	);

	// ��ȡ�ֳ��������߼�
	BOOL GetSceneCurves(
		BOOL bLeaderOrientLeft,				// ��������(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		double dScenePos,					// �ֳ�����λ��(in)
		IKSCurveArray &arrSceneCurves		// �ֳ��������߼�(out)
		);

	// ��ȡ��Χ����������߼�
	BOOL GetAroundCurves(
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		double dAroundPos,					// ��Χ�������λ��(in)
		IKSCurveArray &arrAroundCurves		// ��Χ����������߼�(out)
		);

	// ��ȡβ���������߼�
	BOOL GetTailCurves(
		int nTailType,						// β����������(in)
		BOOL bLeaderOrientLeft,				// ��������(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		double dTailPos,					// β������λ��(in)
		IKSCurveArray &arrTailCurves		// β���������߼�(out)
		);

	// ��ȡ����˵����ע�ͼ�
	BOOL GetWeldNoteNotes(
		const CString &strNote,				// ����˵��(in)
		BOOL bLeaderOrientLeft,				// ��������(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		double dTailPos,					// β������λ��(in)
		double dLineWidth,					// ͼ�η��ŵ��߿�(in)
		IKSNoteArray &arrWeldNoteNotes		// ����˵����ע�ͼ�(out)
		);

	// ��ȡʵ�ߺ�����
	BOOL GetBaseLineAndDashLineCurves(
		int nDashPosition,					// ����λ��(in)
		double dLeftLength,					// ԭ�����󳤶�(in)
		double dRightLength,				// ԭ�����ҳ���(in)
		IKSCurveArray &arrCurves			// ���߼�(out)
		);

private:
	double m_dItemMinDist;					// Ԫ��֮�����С���
	double m_dDashLength;					// ���߳���
	double m_dDashDist;						// ������ʵ�߾���
};

//===================================================================================================

#endif