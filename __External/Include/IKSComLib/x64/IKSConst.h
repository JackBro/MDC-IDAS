//===================================================================================================
// Summary:
//		IKSAnnotationLib�ڲ�ʹ�ó����ͽṹ��
// Date:
//		2015-07-31			����
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSConst_h__
#define __IKSConst_h__

//===================================================================================================
// ����Ϊ�궨��
#define IKS_DELTA 0.001
#define IKS_ZERO 0.000001
#define IKS_ISDEQUAL(x, y) ((x)-(y)<IKS_ZERO && (x)-(y)>-IKS_ZERO)
#define IKS_ISDNEAR(x, y) ((x)-(y)<IKS_DELTA && (x)-(y)>-IKS_DELTA)

// Բ����
#define IKS_PI				3.1415926535897932
// �Ƕ�ת����
#define IKS_ANGLE_TO_RADIAN(angle) (angle) * (0.017453292519943296)
#define IKS_RADIAN_TO_ANGLE(rad) (rad) * (57.295779513082321)
// ��������
#define IKS_1_3				0.33333333333333333				// 1/3
#define IKS_SQRT_2			1.4142135623730950				// ����2
#define IKS_SQRT_1_2		0.70710678118654752				// 1/����2
#define IKS_SQRT_3			1.7320508075688773				// ����3
#define IKS_SQRT_1_3		0.57735026918962576				// 1/����3

// ɾ��ָ��
#define IKS_SAFE_DELETE_POINTER(p) \
{ \
	if (NULL != p) \
	delete p; \
	p = NULL; \
}

// ɾ������
#define IKS_SAFE_DELETE_ARRAY(p) \
{ \
	if (NULL != p) \
	delete[] p; \
	p = NULL; \
}

//===================================================================================================
// ����Ϊ��������


//===================================================================================================
// ����Ϊö��ֵ����

// ��ע�ķ�������
typedef enum __tagIKSAnnoAttachType
{
	IKSANNOATTACHTYPE_FREE,					// ����
	IKSANNOATTACHTYPE_LEFT_LEADER,			// ������
	IKSANNOATTACHTYPE_RIGHT_LEADER,			// ������
	IKSANNOATTACHTYPE_RADIAL_LEADER,		// ��������
	IKSANNOATTACHTYPE_ON_ITEM,				// ͼԪ��
	IKSANNOATTACHTYPE_NORM_ITEM				// ��ֱ��ͼԪ
} IKSAnnoAttachType;

// ��ע�ĸ߶�����
typedef enum __tagIKSAnnoHeightType
{
	IKSANNOHEIGHTTYPE_FIXED,				// �̶�
	IKSANNOHEIGHTTYPE_VARIABLE,				// �ɱ��-��ͼ��λ
	IKSANNOHEIGHTTYPE_TEXTRELATED,			// �ɱ��-����ı�
	IKSANNOHEIGHTTYPE_MODELUNITS			// �ɱ��-ģ�͵�λ
} IKSAnnoHeightType;

// �ı���ʽˮƽ���뷽ʽ
typedef enum __tagIKSHorizontalJustification
{
	IKS_HORZJUST_LEFT,						// ���
	IKS_HORZJUST_CENTER,					// ����
	IKS_HORZJUST_RIGHT						// �ұ�
} IKSHorizontalJustification;

// �ı���ʽ��ֱ���뷽ʽ
typedef enum __tagIKSVerticalJustification
{
	IKS_VERTJUST_TOP,						// ����
	IKS_VERTJUST_MIDDLE,					// �м�
	IKS_VERTJUST_BOTTOM						// �ײ�
} IKSVerticalJustification;

// ���߷�ʽ
typedef enum __tagIKSSdArrowStyle
{
	IKSAS_UNKNOWN		= -1,
	IKSAS_ARROWHEAD		=  1,	// ��ͷ
	IKSAS_DOT			=  2,	// ��
	IKSAS_FILLEDDOT		=  3,	// ʵ�ĵ�
	IKSAS_NOARROW		=  4,	// ��
	IKSAS_CROSS			=  5,	// ����
	IKSAS_SLASH			=  6,	// б��
	IKSAS_INTEGRAL		=  7,	// ����
	IKSAS_BOX			=  8,	// ����
	IKSAS_FILLEDBOX		=  9,	// ʵ�Ŀ�
	IKSAS_DOUBLEARROW	= 10,	// ˫��ͷ
	IKSAS_TARGET		= 14,	// Ŀ��
	IKSAS_LEFTHALF		= 15,	// ����ͷ
	IKSAS_RIGHTHALF		= 16,	// �Ұ��ͷ
	IKSAS_TRIANGLE		= 18,	// ������
	IKSAS_NOCHANGE		= 19	// ��ԭ��
} IKSSdArrowStyle;

//===================================================================================================
// ����Ϊ�ṹ�嶨��
// �ı���ʽ
typedef struct __tagIKSTextStyle
{
	CString strFont;			// ����
	BOOL	bDefaultFont;		// Ĭ������
	double	dHeight;			// �߶�ֵ 
	BOOL	bDefaultHeight;		// Ĭ�ϸ߶�
	double	dWidth;				// ��ȱ�ֵ
	BOOL	bDefaultWidth;		// Ĭ�Ͽ�ȱ�
	double	dThickness;			// �ı����ߺ��
	BOOL	bDefaultThickness;	// Ĭ���ı��ߺ��
	double	dSlant;				// ��б�Ƕȣ���˳ʱ�뷽��
	BOOL	bUnderline;			// ���»���
	int		nHorJust;			// ˮƽ
	int		nVerJust;			// ��ֱ
	BOOL	bMirror;			// ����
	BOOL	bReadonly;			// ֻ������

	__tagIKSTextStyle() 
	{
		strFont = _T("default_font");
		bDefaultFont = TRUE;
		dHeight = 3.5;
		bDefaultHeight = TRUE;
		dWidth = 0.85; 
		bDefaultWidth = TRUE;
		dThickness = 0.0;
		bDefaultThickness = TRUE;
		dSlant = 0.00; 
		bUnderline = FALSE;
		nHorJust = IKS_HORZJUST_CENTER;
		nVerJust = IKS_VERTJUST_MIDDLE;
		bMirror = FALSE;
		bReadonly = FALSE;
	}

	BOOL operator== (const __tagIKSTextStyle &textStyle) 
	{
		if (bDefaultFont == textStyle.bDefaultFont)
		{
			if (!bDefaultFont)
			{
				if (strFont.CompareNoCase(textStyle.strFont) != 0)
					return FALSE;
			}
		}
		else
			return FALSE;

		if (bDefaultHeight == textStyle.bDefaultHeight)
		{
			if (!bDefaultHeight)
			{
				if (!IKS_ISDEQUAL(dHeight, textStyle.dHeight))
					return FALSE;
			}
		}
		else
			return FALSE;

		if (bDefaultWidth == textStyle.bDefaultWidth)
		{
			if (!bDefaultWidth)
			{
				if (!IKS_ISDEQUAL(dWidth, textStyle.dWidth))
					return FALSE;
			}
		}
		else
			return FALSE;

		if (bDefaultThickness == textStyle.bDefaultThickness)
		{
			if (!bDefaultThickness)
			{
				if (!IKS_ISDEQUAL(dThickness, textStyle.dThickness))
					return FALSE;
			}
		}
		else
			return FALSE;

		if (!IKS_ISDEQUAL(dSlant, textStyle.dSlant))
			return FALSE;

		if (bUnderline != textStyle.bUnderline)
			return FALSE;

		if (nHorJust != textStyle.nHorJust)
			return FALSE;

		if (nVerJust != textStyle.nVerJust)
			return FALSE;

		if (bMirror != textStyle.bMirror)
			return FALSE;

		if (bReadonly != textStyle.bReadonly)
			return FALSE;

		return TRUE;
	}

	BOOL operator!= (const __tagIKSTextStyle &textStyle) 
	{
		return !(*this == textStyle);
	}

	__tagIKSTextStyle &operator= (const __tagIKSTextStyle &textStyle) 
	{
		if (&textStyle != this)
		{
			strFont = textStyle.strFont;
			bDefaultFont = textStyle.bDefaultFont;
			dHeight = textStyle.dHeight;
			bDefaultHeight = textStyle.bDefaultHeight;
			dWidth = textStyle.dWidth; 
			bDefaultWidth = textStyle.bDefaultWidth;
			dThickness = textStyle.dThickness; 
			bDefaultThickness = textStyle.bDefaultThickness;
			dSlant = textStyle.dSlant; 
			bUnderline = textStyle.bUnderline;
			nHorJust = textStyle.nHorJust;
			nVerJust = textStyle.nVerJust;
			bMirror = textStyle.bMirror;
			bReadonly = textStyle.bReadonly;
		}
		return *this;
	}
} IKSTextStyle;

// ��ע���÷�ʽ
typedef struct __tagIKSAnnoAttach
{
	int nAttachType;					// ���õ����ͣ��ο�IKSAnnoAttachType
	int nEntityID;						// ���õ�ʵ�弸��ID�������ڷ�������Ϊ��ͼԪ�ϡ�����ֱ��ͼԪ���������ߡ��������ߡ����������ߡ�������
	double dEntityParameter;			// ʵ�弸�ε�λ�ò����������ڷ�������Ϊ��ͼԪ�ϡ�����ֱ��ͼԪ���������ߡ��������ߡ�������
	double dpLocation[3];				// ʵ�弸�ε�λ�ã������ڷ�������Ϊ��ͼԪ�ϡ�����ֱ��ͼԪ���������ߡ��������ߡ�������

	__tagIKSAnnoAttach() 
	{
		nAttachType = IKSANNOATTACHTYPE_FREE;
		nEntityID = -1;
		dEntityParameter = 0.0;
		memset(dpLocation, 0, sizeof(double)*3);
	}

	__tagIKSAnnoAttach &operator= (const __tagIKSAnnoAttach &attach) 
	{
		if (&attach != this)
		{
			nAttachType = attach.nAttachType;
			nEntityID = attach.nEntityID;
			dEntityParameter = attach.dEntityParameter;
			memcpy_s(dpLocation, sizeof(double)*3, attach.dpLocation, sizeof(double)*3);
		}
		return *this;
	}
} IKSAnnoAttach;

typedef vector<IKSAnnoAttach> IKSAnnoAttachArray;

// ���Ŷ�������
typedef struct __tagIKSAnnoAttribute
{
	int nHeightType;						// �߶����ͣ��ο�IKSAnnoHeightType
	int nTextRefID;							// ���߶�����Ϊ���ɱ�����ı���ʱ������ı����ı�ID
	int nTextRefLine;						// ���߶�����Ϊ���ɱ�����ı���ʱ������ı�����������
	int nTextRefText;						// ���߶�����Ϊ���ɱ�����ı���ʱ������ı��������ı�����
	BOOL bTextAngleFixed;					// �ı��Ƕ��Ƿ�̶�
	IKSAnnoAttachArray arrAttaches;			// ���÷�ʽ��

	__tagIKSAnnoAttribute() 
	{
		nHeightType = IKSANNOHEIGHTTYPE_VARIABLE;
		nTextRefID = -1;
		nTextRefLine = -1;
		nTextRefText = -1;
		bTextAngleFixed = FALSE;
	}

	__tagIKSAnnoAttribute &operator= (const __tagIKSAnnoAttribute &att) 
	{
		if (&att != this)
		{
			nHeightType = att.nHeightType;
			nTextRefID = att.nTextRefID;
			nTextRefLine = att.nTextRefLine;
			nTextRefText = att.nTextRefText;
			bTextAngleFixed = att.bTextAngleFixed;
			arrAttaches = att.arrAttaches;
		}
		return *this;
	}
} IKSAnnoAttribute;

//===================================================================================================

#endif