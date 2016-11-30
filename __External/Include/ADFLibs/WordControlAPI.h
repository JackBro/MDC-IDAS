//===================================================================================================
// File:
//		WordControlAPI.h
// Summary:
//		office�ĵ������ӿ��ࣨword��
// Date:
//		2016-02-19
// Author:
//		WangShiping
//===================================================================================================

#pragma once

//===================================================================================================

// ɫ�ʼ�����
typedef enum __tagColorIndex
{
	INDEX_BLACK			= 1,	// ��ɫ
	INDEX_WHITE			= 2,	// ��ɫ
	INDEX_RED			= 3,	// ��ɫ
	INDEX_BRIGHTGREEN	= 4,	// ����ɫ
	INDEX_BLUE			= 5,	// ��ɫ
	INDEX_YELLOW		= 6,	// ��ɫ
	INDEX_PINK			= 7,	// �ۺ�ɫ
	INDEX_TURQUOISE		= 8,	// ����ɫ
	INDEX_DARKRED		= 9,	// ���ɫ
	INDEX_GREEN			= 10,	// ��ɫ
	INDEX_DARKBLUE		= 11,	// ����ɫ
	INDEX_DARKYELLOW	= 12,	// ���ɫ
	INDEX_VIOLET		= 13,	// ������
	INDEX_TEAL			= 14,	// ��ɫ
	IDNEX_GRAY25		= 15,	// ǳ��
	INDEX_GRAY50		= 16,	// �л�
	INDEX_PERIWINKLE	= 17,	// ����ɫ
	INDEX_PLUMPLUS		= 18,	// ÷��ɫ
	INDEX_LVORY			= 19,	// ����ɫ
	INDEX_LITETURQUOISE	= 20,	// ǳ����
	INDEX_DARKPURPLE	= 21,	// ����ɫ
	INDEX_CORAL			= 22,	// ɺ����
	INDEX_OCEANBLUE		= 23,	// ����
	INDEX_ICEBLUE		= 24,	// ����
	INDEX_DARKBLUEPLUS	= 25,	// ����ɫ
	INDEX_PINKPLUS		= 26,	// �ۺ�ɫ
	INDEX_YELLOWPLUS	= 27,	// ��ɫ
	INDEX_TURQUOISEPLUS	= 28,	// ����ɫ
	INDEX_VIOLETPLUS	= 29,	// ������
	INDEX_DARKREDPLUS	= 30,	// ���ɫ
	INDEX_TEALPLUS		= 31,	// ��ɫ
	INDEX_BLUEPLUS		= 32,	// ��ɫ
	INDEX_SKYBLUE		= 33,	// ����ɫ
	INDEX_LIGHTTURQUOIS	= 34,	// ǳ����
	INDEX_LIGHTGREEN	= 35,	// ǳ��ɫ
	INDEX_LIGHTYELLOW	= 36,	// ǳ��ɫ
	INDEX_PALEBLUE		= 37,	// ����ɫ
	INDEX_ROSE			= 38,	// õ���
	INDEX_LAVENDER		= 39,	// ����ɫ
	INDEX_TAN			= 40,	// ��ɫ
	INDEX_LIGHTBLUE		= 41,	// ǳ��ɫ
	INDEX_AQUA			= 42,	// ˮ��ɫ
	INDEX_LIME			= 43,	// ���ɫ
	INDEX_GOLD			= 44,	// ��ɫ
	INDEX_LIGHTORANGE	= 45,	// ǳ��ɫ
	INDEX_ORANGE		= 46,	// ��ɫ
	INDEX_BLUEGRAY		= 47,	// ������
	INDEX_GRAY40		= 48,	// �ң�40��
	INDEX_DARKTEAL		= 49,	// ����
	INDEX_SEAGREEN		= 50,	// ����
	INDEX_DARKGREEN		= 51,	// ����
	INDEX_OLIVEGREEN	= 52,	// ���ɫ
	INDEX_BROWN			= 53,	// ��ɫ
	INDEX_PLUM			= 54,	// ÷��ɫ
	INDEX_INDIGO		= 55,	// ����
	INDEX_GRAY80		= 56	// �ң�80��
} ColorIndex;

// ������뷽ʽ
typedef enum __tagAlignmentType
{
	ALIGN_LEFT		= 0,	// �����
	ALIGN_RIGHT		= 2,	// �Ҷ���
	ALIGN_MIDDLE	= 1,	// ����
	ALIGN_JUSTIFY	= 3		// ����Ӧ
} AlignmentType;

// �м�����
typedef enum __tagLineSpace
{
	SPACE_1pt5		= 1,	// 1.5 ���оࡣ���о��൱�ڵ�ǰ�ֺż�6��.
	SPACE_ATLEAST	= 3,	// �о�����Ϊһ��ָ��ֵ����ֵ��Ҫ����ָ��.
	SPACE_DOUBLE	= 2,	// ˫���о�.
	SPACE_EXACTLY	= 4,	// �о�ֻ�������������оࡣ��������ʹ�õ��о�ͨ��С�ڵ����о�.
	SPACE_MULTIPLE	= 5,	// ��ָ��������ȷ�����о�.
	SPACE_SINGLE	= 0		// �����о࣬Ĭ��ֵ.
} LineSpace;

// ��ټ���
typedef enum __tagOutlineLevel
{
	OUTLINE_LEVEL1	= 1,	// ��ټ���1 
	OUTLINE_LEVEL2	= 2,	// ��ټ���2 
	OUTLINE_LEVEL3	= 3,	// ��ټ���3 
	OUTLINE_LEVEL4	= 4,	// ��ټ���4 
	OUTLINE_LEVEL5	= 5,	// ��ټ���5 
	OUTLINE_LEVEL6	= 6,	// ��ټ���6 
	OUTLINE_LEVEL7	= 7,	// ��ټ���7 
	OUTLINE_LEVEL8	= 8,	// ��ټ���8 
	OUTLINE_LEVEL9	= 9,	// ��ټ���9 
	OUTLINE_NOLEVEL = 10,	//û�д�ټ��� 
} OutlienLevel;

typedef struct __tagWordStyleInfo
{
	CString strName;		// ��ʽ����
	int nAlighment;			// ������뷽ʽ
	int nOutlineLevel;		// �����ټ���
	int nFirstIndentChar;	// ������������
	float fBeforePound;		// ��ǰ���
	float fAfterPound;		// �κ���
	int nLineSpaceType;		// �м������
	CString strFontName;	// ��������
	float fFontSize;		// �����С
	int nFontColor;			// ������ɫ
	BOOL bBold;				// �����Ƿ�Ӵ�
	BOOL bItalic;			// �����Ƿ���б
	BOOL bUnderline;		// �Ƿ���»���

	__tagWordStyleInfo()
	{
		strName = L"����ʽ";
		nAlighment = ALIGN_JUSTIFY;
		nOutlineLevel = OUTLINE_NOLEVEL;
		nFirstIndentChar = 2;
		fBeforePound = 0.0;
		fAfterPound = 0.0;
		nLineSpaceType = SPACE_SINGLE;
		strFontName = L"����";
		fFontSize = 12;
		nFontColor = INDEX_BLACK;
		bBold = FALSE;
		bItalic = FALSE;
		bUnderline = FALSE;
	}

	__tagWordStyleInfo(CString strN, int nA, int nO, int nFI, float fB, float fA, int nL, CString strF, float fFS, int nFC, BOOL bB, BOOL bI, BOOL bU)
	{
		strName =strN;
		nAlighment = nA;
		nOutlineLevel = nO;
		nFirstIndentChar = nFI;
		fBeforePound = fB;
		fAfterPound = fA;
		nLineSpaceType = nL;
		strFontName = strF;
		fFontSize = fFS;
		nFontColor = nFC;
		bBold = bB;
		bItalic = bI;
		bUnderline = bU;
	}

	__tagWordStyleInfo& operator=(const __tagWordStyleInfo &wsi)
	{
		if (&wsi == this)
			return *this;
		strName = wsi.strName;
		nAlighment = wsi.nAlighment;
		nOutlineLevel = wsi.nOutlineLevel;
		nFirstIndentChar = wsi.nFirstIndentChar;
		fBeforePound = wsi.fBeforePound;
		fAfterPound = wsi.fAfterPound;
		nLineSpaceType = wsi.nLineSpaceType;
		strFontName = wsi.strFontName;
		fFontSize = wsi.fFontSize;
		nFontColor = wsi.nFontColor;
		bBold = wsi.bBold;
		bItalic = wsi.bItalic;
		bUnderline = wsi.bUnderline;
		return *this;
	}
} WordStyleInfo;

//===================================================================================================

class IWordControl
{
public:
	// ��̨����WORDӦ�ó���
	virtual BOOL CreateApp() = 0;

	// ǰ̨��ʾWORDӦ�ó���
	virtual void ShowApp() = 0;

	// �˳�����
	virtual BOOL QuitApp() = 0;

	// �ͳ��ڴ�
	virtual void ReleaseAll() = 0;

	// ���ĵ�
	virtual BOOL OpenDoc(const CString& strName) = 0;

	// ����һ���հ��ĵ�
	virtual BOOL CreateDoc() = 0;

	// �����ĵ�
	virtual BOOL SaveDoc() = 0;

	// �ĵ����Ϊ
	virtual BOOL SaveDocAs(const CString &strFname) = 0;

	//===========================================================

	// ��ǰ��괦����һ���ı�
	virtual void WriteLine(const CString& strLine) = 0;

	// ��ǰ��괦�������(���һ����������Ϊ"\n")
	virtual BOOL WritePara(const CString &strStyle, CString strText, ...) = 0;

	// �س�����
	virtual void NewParagraph(int nLine = 1) = 0;

	// ����ͼƬ
	virtual BOOL InsertPicture(CString strPicPath) = 0;

	// ���Ʊ��
	virtual void CreateTable(int nRow, int nColumn, int nAutoFitType = 0) = 0;
	
	//�������д��
	virtual void WriteCellText(int nRow, int nColumne, CString szText) = 0;
	
	// ���ñ���еĵ���
	virtual void SetCellShading(int nRow, int nColumne, int nColorIndex) = 0;
	
	// �����ƶ����λ��
	virtual void MoveDown(int nRow = 1, int nUnit = 5) = 0;

	//===========================================================

	// ���������ֺš����塢��ɫ
	virtual void SetFont(float fSize, CString szFontName = L"����", long lFontColor = INDEX_BLACK) = 0;

	// ��������״̬���Ӵ֡���б���߾����»��ߣ�
	virtual void SetFont(BOOL bBold, BOOL bItalic, BOOL bUnderLine) = 0;

	//===========================================================
	
	// ���ö�����뷽ʽ
	virtual void SetParagraphAlignment(int nAlignment = ALIGN_JUSTIFY) = 0;

	// ���ö��������������ַ���
	virtual void SetParagraphIndent(int nCharIndent) = 0;

	// ���ö����������������ף�
	virtual void SetParagraphIndent(float fcmIndent) = 0;

	// ���öμ�ࣨ����ֵ���룩
	virtual void SetParagraphSpace(float fBeforePound, float fAfterPound) = 0;

	// �����м�ࣨ���������룩
	virtual void SetLineSpace(int nRule, float fline = 1.0) = 0;

	// ���ö����ټ���
	virtual void SetOutlineLevel(int nLevel = OUTLINE_NOLEVEL) = 0;

	// ���õ�ǰ��괦������ʽ
	virtual void SetParagraphStyle(const CString &strStyle) = 0;

	// �½���ʽ
	virtual BOOL CreateStyle(WordStyleInfo styleInfo) = 0;

	// �޸�������ʽ
	virtual BOOL ModifyStyle(WordStyleInfo styleInfo) = 0;
};

//===================================================================================================

IWordControl *CreateWordControl();
void DestroyWordControl(IWordControl *pWordControl);

//===================================================================================================
