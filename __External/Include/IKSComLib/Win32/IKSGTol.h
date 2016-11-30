//===================================================================================================
// Summary:
//		��λ�������
// Date:
//		2015-11-17			����
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSGTol_h__
#define __IKSGTol_h__

//===================================================================================================

#include "IKSSymbol.h"

//===================================================================================================

// �趨��������
typedef enum __tagSdGtolType
{
	GTOL_UNKNOWN          = 0,
	GTOL_STRAIGHTNESS     = 1,	// ֱ�߶�
	GTOL_FLATNESS         = 2,	// ƽ���
	GTOL_CIRCULAR         = 3,	// Բ��
	GTOL_CYLINDRICAL      = 4,	// Բ����
	GTOL_LINE             = 5,	// ��������
	GTOL_SURFACE          = 6,	// ����������
	GTOL_PARALLEL         = 7,	// ƽ�ж�
	GTOL_PERPENDICULAR    = 8,	// ��ֱ��
	GTOL_ANGULAR          = 9,	// ��б��
	GTOL_POSITION         = 10,	// λ�ö�
	GTOL_CONCENTRICITY    = 11,	// ͬ���
	GTOL_SYMMETRY         = 12,	// �Գƶ�
	GTOL_CIRCULAR_RUNOUT  = 13,	// Բ����
	GTOL_TOTAL_RUNOUT     = 14	// ȫ����
};

// ��λ������÷�ʽ
typedef enum __tagSdGtolPlacementType
{
	GPTYPE_UNKNOWN			= -1,
	GPTYPE_NORMLEADER		= 0,	// ���ߴ�ֱ��ͼԪ
	GPTYPE_TOITEMLEADERS	= 1,	// ����ָ��ͼԪ
	GPTYPE_FREELEADERS		= 2,	// �������ɷ���
	GPTYPE_DIM				= 3,	// �ߴ����
	GPTYPE_GTOL				= 4,	// �������ι���
	GPTYPE_FREENOTE			= 5,	// ���ɷ���
} SdGtolPlacementType;

// ���ι��������Ϣ
typedef struct __tagGtolBaseInfo
{
	int		nSymbolType;						// ������������
	double	dValue;								// ����ֵ
	CString	strPrefix;							// ǰ׺
	CString	strSuffix1;							// ��׺1
	CString	strSuffix2;							// ��׺2
	BOOL	bAllAround;							// ȫ�ܷ���
	CString	strNoteTop;							// �Ϸ���ע
	CString	strNoteBack;						// �󷽸�ע
	CString	strDatumName11;						// ��һ��׼����
	CString	strDatumMatCond11;					// ��һ��׼����ѡȡ��������
	CString	strDatumName12;						// ��һ���ϻ�׼����
	CString	strDatumMatCond12;					// ��һ���ϻ�׼����ѡȡ��������
	CString	strDatumName21;						// �ڶ���׼����
	CString	strDatumMatCond21;					// �ڶ���׼����ѡȡ��������
	CString	strDatumName22;						// �ڶ����ϻ�׼����
	CString	strDatumMatCond22;					// �ڶ����ϻ�׼����ѡȡ��������
	CString	strDatumName31;						// ������׼����
	CString	strDatumMatCond31;					// ������׼����ѡȡ��������
	CString	strDatumName32;						// �������ϻ�׼����
	CString	strDatumMatCond32;					// �������ϻ�׼����ѡȡ��������

	__tagGtolBaseInfo()
	{
		nSymbolType = GTOL_UNKNOWN;
		dValue = 0.0;
		strPrefix = L"";
		strSuffix1 = L"";
		strSuffix2 = L"";
		bAllAround = FALSE;
		strNoteTop = L"";
		strNoteBack = L"";
		strDatumName11 = L"";
		strDatumMatCond11 = L"";
		strDatumName12 = L"";
		strDatumMatCond12 = L"";
		strDatumName21 = L"";
		strDatumMatCond21 = L"";
		strDatumName22 = L"";
		strDatumMatCond22 = L"";
		strDatumName31 = L"";
		strDatumMatCond31 = L"";
		strDatumName32 = L"";
		strDatumMatCond32 = L"";
	}
	__tagGtolBaseInfo(const __tagGtolBaseInfo &info)
	{
		nSymbolType = info.nSymbolType;
		dValue = info.dValue;
		strPrefix = info.strPrefix;
		strSuffix1 = info.strSuffix1;
		strSuffix2 = info.strSuffix2;
		bAllAround = info.bAllAround;
		strNoteTop = info.strNoteTop;
		strNoteBack = info.strNoteBack;
		strDatumName11 = info.strDatumName11;
		strDatumMatCond11 = info.strDatumMatCond11;
		strDatumName12 = info.strDatumName12;
		strDatumMatCond12 = info.strDatumMatCond12;
		strDatumName21 = info.strDatumName21;
		strDatumMatCond21 = info.strDatumMatCond21;
		strDatumName22 = info.strDatumName22;
		strDatumMatCond22 = info.strDatumMatCond22;
		strDatumName31 = info.strDatumName31;
		strDatumMatCond31 = info.strDatumMatCond31;
		strDatumName32 = info.strDatumName32;
		strDatumMatCond32 = info.strDatumMatCond32;
	}
	__tagGtolBaseInfo& operator=(const __tagGtolBaseInfo& info){
		if (&info == this)
			return *this;
		nSymbolType = info.nSymbolType;
		dValue = info.dValue;
		strPrefix = info.strPrefix;
		strSuffix1 = info.strSuffix1;
		strSuffix2 = info.strSuffix2;
		bAllAround = info.bAllAround;
		strNoteTop = info.strNoteTop;
		strNoteBack = info.strNoteBack;
		strDatumName11 = info.strDatumName11;
		strDatumMatCond11 = info.strDatumMatCond11;
		strDatumName12 = info.strDatumName12;
		strDatumMatCond12 = info.strDatumMatCond12;
		strDatumName21 = info.strDatumName21;
		strDatumMatCond21 = info.strDatumMatCond21;
		strDatumName22 = info.strDatumName22;
		strDatumMatCond22 = info.strDatumMatCond22;
		strDatumName31 = info.strDatumName31;
		strDatumMatCond31 = info.strDatumMatCond31;
		strDatumName32 = info.strDatumName32;
		strDatumMatCond32 = info.strDatumMatCond32;
		return *this;
	}
} GtolBaseInfo;

// ���ι�����Ϣ
typedef struct __tagGtolInfo
{
	std::vector<GtolBaseInfo> arrBaseInfo;		// ������Ϣ
	int		nPlacementType;						// ���÷�ʽ
	int		nLeaderType;						// ���߷�ʽ

	__tagGtolInfo()
	{
		nPlacementType = GPTYPE_NORMLEADER;
		nLeaderType = IKSAS_ARROWHEAD;
	}
	__tagGtolInfo(const __tagGtolInfo &info)
	{
		arrBaseInfo = info.arrBaseInfo;
		nPlacementType = info.nPlacementType;
		nLeaderType = info.nLeaderType;
	}
	__tagGtolInfo& operator=(const __tagGtolInfo& info){
		if (&info == this)
			return *this;
		arrBaseInfo = info.arrBaseInfo;
		nPlacementType = info.nPlacementType;
		nLeaderType = info.nLeaderType;
		return *this;
	}
} GtolInfo;

//===================================================================================================

class CIKSGTol : public CIKSSymbol
{
public:
	CIKSGTol();
	virtual ~CIKSGTol();

public:
	// ������λ������Ϣ�������߼���ע�ͼ�
	BOOL GetCurvesAndNotes(
		const GtolInfo &gtolInfo,			// ��λ������Ϣ(in)
		double dLineWidth,					// �߿�(in)
		IKSGetNoteSizeAction action,		// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص��������������Ϊ�գ���ʹ��Ĭ�Ϻ���(in)
		IKSCurveArray &arrCurves,			// ���μ�(out)
		IKSNoteArray &arrNotes,				// ע�ͼ�(out)
		IKSAnnoAttribute &attr				// ��ע����(out)
		);
	// �����ַ�������ע�ͼ�
	BOOL GetCStringNotes(
		CString strc,							// �ַ���
		BOOL bChangeBracket,					// �Ƿ�()ת��ΪԲ
		IKSGetNoteSizeAction action,			// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		int nHorJust,							// ˮƽ����ע�ͼ���˻��Ҷ�
		double &dXValueOutline,					// �ַ�������Xֵ(����Ϊ��ʼX)(in)(out)
		double dStartOrdinate,					// �ַ�����ʼYֵ
		double dLineWidth,						// �߿�(in)
		IKSNoteArray &arrNotes,					// ����ֵע�ͼ�(out)
		IKSCurveArray &arrCurves				// ��()ת��ΪԲ���߼�(out)
		);
	// ��������յ�����ֱ��
	BOOL GetLineCurve(
		int nLineStyle,							// ����
		double dstartX,							// ���X����
		double dstartY,							// ���Y����
		double dstartZ,							// ���Z����
		double dendX,							// �յ�X����
		double dendY,							// �յ�Y����
		double dendZ,							// �յ�Z����
		IKSCurveArray &arrCurves				// ֱ�߼�(out)
		);
	// ����Բ�ĵ�����Բ
	BOOL GetCircleCurve(
		int nLineStyle,							// ����
		double dcenterX,						// Բ��X����
		double dcenterY,						// Բ��Y����
		double dcenterZ,						// Բ��Z����
		double daxisXX,							// X�������X����
		double daxisXY,							// X�������Y����
		double daxisXZ,							// X�������Z����
		double dRadius,							// �뾶
		double dStartAngle,						// ��ʼ��
		double dEndAngle,						// ��ֹ��
		IKSCurveArray &arrCurves				// Բ����(out)
		);
private:
	// ��ȡȫ�ܷ���
	BOOL GetBAllAroundCurves(
		double dLineWidth,					// �߿�(in)
		IKSCurveArray &arrCurves			// ���߼�(out)
		);
	// ��ȡ�������ֱ��
	BOOL GetCoreCurves(
		double dLineWidth,					// �߿�(in)
		IKSCurveArray &arrCurves			// ֱ��(out)
		);
	// ��ȡ���㹫�������������
	BOOL GetBaseSymbolCurves(
		int nSymbolType,					// ������������
		int nSize,							// ��������
		int i,								// ���ڲ㼶
		double dLineWidth,					// �߿�(in)
		IKSCurveArray &arrCurves,			// ���߼�(out)
		double &dSymbolOutline				// �����������Ҷ�X(out)
		);
	// ��ȡ���㹫��ֵע�ͼ�
	BOOL GetValueNotes(
		double	dValue,								// ����ֵ(in)
		CString	strPrefix,							// ǰ׺(in)
		CString	strSuffix1,							// ��׺1(in)
		CString	strSuffix2,							// ��׺2(in)
		double dSymbolOutline,						// �������ų���(in)
		int nSize,									// ��������(in)
		int i,										// ���ڲ㼶(in)
		double dLineWidth,							// �߿�(in)
		IKSGetNoteSizeAction action,				// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSNoteArray &arrNotes,						// ����ֵע�ͼ�(out)
		double &dXValueOutline,						// ����ֵ�����Ҷ�X(out)
		IKSCurveArray &arrCurves				// ��()ת��ΪԲ���߼�(out)
		);
	// ��ȡ�����һ��׼ע�ͼ�
	BOOL GetStrDatum1Notes(
		CString	strDatumName11,						// ��һ��׼����(in)
		CString	strDatumMatCond11,					// ��һ��׼����ѡȡ��������(in)
		CString	strDatumName12,						// ��һ���ϻ�׼����(in)
		CString	strDatumMatCond12,					// ��һ���ϻ�׼����ѡȡ��������(in)
		double dXValueOutline,						// ����ֵ�����Ҷ�X(in)
		int nSize,									// ��������(in)
		int i,										// ���ڲ㼶(in)
		double dLineWidth,							// �߿�(in)
		IKSGetNoteSizeAction action,				// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSNoteArray &arrNotes,						// ��һ��׼ע�ͼ�(out)
		double &dXStrDatum1Outline,					// ��һ��׼ע�͵����Ҷ�X(out)
		IKSCurveArray &arrCurves				// ��()ת��ΪԲ���߼�(out)
		);

	// ����jע��Ϊ��ʱ����arrXStrDatum j Outline=arrXStrDatum j-1 Outline

	// ��ȡ����ڶ���׼ע�ͼ�
	BOOL GetStrDatum2Notes(
		CString	strDatumName21,						// �ڶ���׼����(in)
		CString	strDatumMatCond21,					// �ڶ���׼����ѡȡ��������(in)
		CString	strDatumName22,						// �ڶ����ϻ�׼����(in)
		CString	strDatumMatCond22,					// �ڶ����ϻ�׼����ѡȡ��������(in)
		double dXStrDatum1Outline,					// ��һ��׼ע�͵����Ҷ�X(in)
		int nSize,									// ��������(in)
		int i,										// ���ڲ㼶(in)
		double dLineWidth,							// �߿�(in)
		IKSGetNoteSizeAction action,				// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSNoteArray &arrNotes,						// �ڶ���׼ע�ͼ�(out)
		double &dXStrDatum2Outline,					// �ڶ���׼ע�͵����Ҷ�X(out)
		IKSCurveArray &arrCurves						// ��()ת��ΪԲ���߼�(out)
		);
	// ��ȡ���������׼ע�ͼ�
	BOOL GetStrDatum3Notes(
		CString	strDatumName31,						// ������׼����(in)
		CString	strDatumMatCond31,					// ������׼����ѡȡ��������(in)
		CString	strDatumName32,						// �������ϻ�׼����(in)
		CString	strDatumMatCond32,					// �������ϻ�׼����ѡȡ��������(in)
		double dXStrDatum2Outline,					// �ڶ���׼ע�͵����Ҷ�X(in)
		int nSize,									// ��������(in)
		int i,										// ���ڲ㼶(in)
		double dLineWidth,							// �߿�(in)
		IKSGetNoteSizeAction action,				// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSNoteArray &arrNotes,						// ������׼ע�ͼ�(out)
		double &dXStrDatum3Outline,					// ������׼ע�͵����Ҷ�X(out)
		IKSCurveArray &arrCurves						// ��()ת��ΪԲ���߼�(out)
		);
	// ��ȡǰ���о��ο����߼�
	BOOL GetFrontRectCurves(
		int nSize,									// ��������(in)
		double dSymbolOutline,						// �����������Ҷ�X(out)
		double dXValueOutline,						// ����ֵ�е����Ҷ�X(in)
		double dLineWidth,							// �߿�(in)
		IKSCurveArray &arrCurves					// ���ο����߼�(out)
		);
	BOOL GetBackRectCurves(
		int nSize,								// ��������(in)
		int i,									// ���ڲ㼶(in)
		double dXValueLeftline,					// �ÿ����Xֵ
		double dXValueRightline,					// �ÿ��Ҳ�Xֵ
		double dLineWidth,						// �߿�(in)
		IKSCurveArray &arrCurves					// ���ο����߼�(out)
		);
	// ��ȡ�Ϸ����󷽱�ע��
	BOOL GetStrNotes(
		CString	strNoteTop,						// �Ϸ���ע(in)
		CString	strNoteBack,					// �󷽸�ע(in)
		int nSize,								// ��������(in)
		double dXStrDatum3Outline,				// ������׼ע���е����Ҷ�X(in) 
		double dLineWidth,						// �߿�(in)
		IKSGetNoteSizeAction action,			// ��ȡע�Ϳ�Ⱥ͸߶ȵĻص�����(in)
		IKSNoteArray &arrNotes,					// �Ϸ����󷽱�ע��(out)
		IKSCurveArray &arrCurves						// ��()ת��ΪԲ���߼�(out)
		);
	// ���ַ�����()ת��ΪԲ
	BOOL ChangeBracketToCircle(
		CString &strName,				// �����ַ���(in)(out)
		double dstrNameLength,			// �ַ�������mm(in)
		double dAbscissa,				// �ַ�����ʼλ�ú�����(in)
		double dOrdinate,				// �ַ�����ʼλ��������(in)
		double dLineWidth,				// �߿�(in)
		IKSCurveArray &arrCurves		// ���Բ���߼�(out)
		);

};

//===================================================================================================

#endif