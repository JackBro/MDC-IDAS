//===================================================================================================

#pragma once

//===================================================================================================

// �ж������������Ƿ����
#define DEQUAL(x, y)	(fabs((x) - (y)) <= 0.02)
const double DMZERO = 1e-2;

//===================================================================================================

// ���ŵ�����
enum ANNOBJECTTYPE
{
	AOT_UNKNOWN			=	0,		// δ֪����
	AOT_CAVAS			=	1,		// ��������
	AOT_DIM				=	2,		// �ߴ��ע

	AOT_IMAGE			=	10,		// ͼ������
	AOT_TEXT			=	11,		// ��������
	AOT_PENCIL			=	12,		// ���ɻ���
	AOT_RECTANGLE		=	13,		// ����
	AOT_ELLIPSE			=	14,		// ��Բ
	AOT_LINE			=	15,		// ֱ��
	AOT_NOTE			=	16,		// ע��

	AOT_BALLON			=	30,		// ���	

	AOT_CABINET			=	100,	// ����	
	AOT_CR				=	101,	// ���߼�	
	AOT_WCLN			=	102,	// ǽ��
	AOT_DOOR			=	103,	// ͨ����
	AOT_WINDOW			=	104,	// ����
};

// ����
enum SYMBOLSUBTYPE
{
	SCT_NULL			=	0,	// ������
	SCT_ITC				=	1,	// ����������
	SCT_MCC				=	2,	// �ܿع�
	SCT_FMCC			=	3,	// ��ͷ�ܿع�
	SCT_TAC				=	4,	// �յ���
	SCT_FHC				=	5,	// ������
	SCT_FEC				=	6,	// ��ͷ�չ�
	SCT_PDC				=	7,	// ����
	SCT_FPDC			=	8,	// ��ͷ����
	SCT_IEC				=	9,	// �м�չ�
	SCT_AGC				=	10,	// �����

	SCT_CR				=	20,	// ǿ�������߼�	
	SCT_OFG				=	21,	// ���˲�

	SCT_WCln			=	30,	// ǽ��	

	SCT_Cdoor			=	40,	// ͨ��͹��
	SCT_Fdoor			=	41,	// ͨ��ƽ��

	SCT_FTW				=	50,	// �̶�����
	SCT_RTW				=	51,	// ��ת����
	SCT_ATW				=	51,	// �ɵ�����
};

// ����
typedef enum __APADASHSTYLE
{
	APADT_SOLID			= 0,
	APADT_DASH			= 1,
	APADT_DOT			= 2,
	APADT_DASHDOT		= 3,
	APADT_DASHDOTDOT	= 4,
} APADASHSTYLE;

// �ŵķ���
typedef enum __DOORDIRECTION
{
	DOOR_NULL			= 0,	// ��ʾû����
	DOOR_BOTTOM			= 1,	// ��ʾ����
	DOOR_UP				= 2,	// ��ʾ����
	DOOR_BOTH			= 3,	// ������
} DOORDIRECTION;

//===================================================================================================

typedef struct __tagLineSytleID
{
	int nType;
	TCHAR strName[20];
} LineSytleID;

const LineSytleID g_LineSytleIDList[] = 
{
	{ APADT_SOLID, _T("ʵ����") },
	{ APADT_DASH, _T("����") },
	{ APADT_DOT, _T("����") },
	{ APADT_DASHDOT, _T("�㻮��") },
	{ APADT_DASHDOTDOT, _T("��㻮��") }
};

// �Զ����
typedef struct __tagSpPoint
{
	double x;
	double y;
	__tagSpPoint() 
	{
		x = 0;
		y = 0;
	}
	__tagSpPoint(double dX,	double dY) 
	{
		x = dX;
		y = dY;
	}
	void operator= (const __tagSpPoint info) 
	{
		x = info.x;
		y = info.y;
	}

	BOOL EqualPoint(const __tagSpPoint &pt)
	{
		if (!DEQUAL(x,  pt.x)||
			!DEQUAL(y,  pt.y))
			return FALSE;

		return TRUE;
	}	

} SpPoint, *PSpPoint;

// �Զ������
typedef struct __tagSpRect
{
	double left;
	double top;
	double right;
	double bottom;
	__tagSpRect() 
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}
	__tagSpRect(double dLeft,double dTop, double dRight, double dBottom) 
	{
		left = dLeft;
		top = dTop;
		right = dRight;
		bottom = dBottom;
	}
	__tagSpRect(const SpPoint& ptStart, const SpPoint& ptEnd) 
	{
		left = ptStart.x;
		top = ptStart.y;
		right = ptEnd.x;
		bottom = ptEnd.y;
	}

	void operator= (const __tagSpRect &info) 
	{
		left = info.left;
		top = info.top;
		right = info.right;
		bottom = info.bottom;
	}

	SpPoint TopLeft() const
	{
		return SpPoint(left, top);
	}

	SpPoint BottomRight() const
	{
		return SpPoint(right, bottom);
	}

	void NormalizeRect() 
	{
		double nTemp;
		if (left > right)
		{
			nTemp = left;
			left = right;
			right = nTemp;
		}
		if (top > bottom)
		{
			nTemp = top;
			top = bottom;
			bottom = nTemp;
		}
	}
	double Width() const
	{
		return right - left; 
	}
	double Height() const
	{
		return bottom - top; 
	}

	BOOL IntersectRect(const __tagSpRect rc)
	{
		if ((bottom < rc.top) || (rc.bottom < top)   || (right < rc.left) || (rc.right < left)) 
		{ 
			return FALSE;
		}
		else 
		{  
			return TRUE; 
		}
	}

	BOOL PtInRect(const SpPoint& pt)
	{
		if ((bottom < pt.y) || (top > pt.y)   || (right < pt.x) || (left > pt.x)) 
		{ 
			return FALSE;
		}
		else 
		{  
			return TRUE; 
		}
	}

	void SetRect(const SpPoint& ptStart, const SpPoint& ptEnd)
	{
		left = ptStart.x;
		top = ptStart.y;
		right = ptEnd.x;
		bottom = ptEnd.y;
	}

	void SetRect(double dLeft,double dTop, double dRight, double dBottom)
	{
		left = dLeft;
		top = dTop;
		right = dRight;
		bottom = dBottom;
	}

	BOOL IsRectEmpty()
	{
		if ((bottom == top && top == 0)  || (right == left && left == 0) ) 
		{ 
			return TRUE;
		}
		else 
		{  
			return FALSE; 
		}
	}
	void SetRectEmpty()
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;
	}

	void InflateRect(int dx, int dy)
	{
		left -= dx;
		top -= dy;
		right += dx;
		bottom += dy;
	}
	BOOL EqualRect(const __tagSpRect &rect)
	{
		if (!DEQUAL(left,  rect.left)||
			!DEQUAL(top,  rect.top)||
			!DEQUAL(right,  rect.right)||
			!DEQUAL(bottom,  rect.bottom))
			return FALSE;

		return TRUE;
	}	
} SpRect, *PSpRect;

typedef struct __APARGB
{
	BYTE byAlpha;
	BYTE byRed;
	BYTE byGreen;
	BYTE byBlue;

	/*__APARGB() 
	{
		byAlpha = 255;
		byRed = 0;
		byGreen = 0;
		byBlue = 0;
	}
	__APARGB(BYTE alpha, BYTE red, BYTE green, BYTE blue) 
	{
		byAlpha = alpha;
		byRed = red;
		byGreen = green;
		byBlue = blue;
	}*/

	void operator= (const __APARGB info) 
	{
		byAlpha = info.byAlpha;
		byRed = info.byRed;
		byGreen = info.byGreen;
		byBlue = info.byBlue;
	}

	BOOL IsEqual(const __APARGB info)
	{
		if (byAlpha == info.byAlpha && byRed == info.byRed && byGreen == info.byGreen && byBlue == info.byBlue)
			return TRUE;

		return FALSE;
	}

} APARGB;

typedef struct __APATEXTINFO
{
	WORD wVersion;				// �汾��
	wchar_t szFontName[32];		// ���������
	SpPoint ptLeftTop;			// ���ֵ����ϵ�����, �����߼����ꡣ
	INT lfHeight;				// ����ĸ߶�
	// LONG lfWidth;			// ����Ŀ�ȣ����Ϊ0���и߶Ⱦ���
	INT nAngle;					// ������Ӿ������Ͻǵ�Ϊ���㣬��Ϊ�����򣬴�0�ȵ�360��
	APARGB clrText;				// ���ֵ���ɫ
	BYTE bBold;					// ����Ӵ�
	BYTE bItalic;				// ����б��
	BYTE bUnderline;			// �����»���

	__APATEXTINFO()
	{
		wVersion = 1;
		memset(szFontName, 0,sizeof(szFontName));
		wcscpy_s(szFontName, sizeof(szFontName)/sizeof(wchar_t), L"SimSun");
		ptLeftTop.x = ptLeftTop.y = 0;
		lfHeight = 120;	// С��
		nAngle = 0;

		clrText.byAlpha = 255;// ��͸��
		clrText.byRed = 0;
		clrText.byGreen = 0;
		clrText.byBlue = 0;
		bBold = 0;
		bItalic = 0;
		bUnderline = 0;
	}

	void operator= (const __APATEXTINFO info) 
	{
		wVersion = info.wVersion;

		memcpy(szFontName, info.szFontName, sizeof(szFontName));
		ptLeftTop = info.ptLeftTop;
		lfHeight = info.lfHeight;
		nAngle = info.nAngle;
		clrText = info.clrText;

		bBold = info.bBold;
		bItalic = info.bItalic;
		bUnderline = info.bUnderline;
	}

	BOOL IsEqual(const __APATEXTINFO info)
	{
		if (wcscmp(szFontName, info.szFontName) != 0)
			return FALSE;

		if (!DEQUAL(ptLeftTop.x, info.ptLeftTop.x) || !DEQUAL(ptLeftTop.y, info.ptLeftTop.y))
			return FALSE;

		if (lfHeight != info.lfHeight)
			return FALSE;

		if (nAngle != info.nAngle)
			return FALSE;

		if (clrText.byAlpha != info.clrText.byAlpha ||
			clrText.byRed != info.clrText.byRed ||
			clrText.byGreen != info.clrText.byGreen ||
			clrText.byBlue != info.clrText.byBlue)
			return FALSE;

		if (bBold != info.bBold)
			return FALSE;
		if (bItalic != info.bItalic)
			return FALSE;
		if (bUnderline != info.bUnderline)
			return FALSE;

		return TRUE;
	}

	void Serialize(CArchive& ar)
	{
		if (ar.IsLoading())
		{
			ar >> wVersion;
			ar >> ptLeftTop.x;
			ar >> ptLeftTop.y;
			ar >> lfHeight;
			ar >> nAngle;

			ar >> clrText.byAlpha;
			ar >> clrText.byRed;
			ar >> clrText.byGreen;
			ar >> clrText.byBlue;

			ar.Read(szFontName, sizeof(szFontName));

			ar >> bBold;
			ar >> bItalic;
			ar >> bUnderline;
		}
		else
		{
			ar << wVersion;
			ar << ptLeftTop.x;
			ar << ptLeftTop.y;
			ar << lfHeight;
			ar << nAngle;

			ar << clrText.byAlpha;
			ar << clrText.byRed;
			ar << clrText.byGreen;
			ar << clrText.byBlue;

			ar.Write(szFontName, sizeof(szFontName));

			ar << bBold;
			ar << bItalic;
			ar << bUnderline;
		}
	}

} APATEXTINFO;

//===================================================================================================
