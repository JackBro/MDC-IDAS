//===================================================================================================
// File:
//		WordControlAPI.h
// Summary:
//		office文档操作接口类（word）
// Date:
//		2016-02-19
// Author:
//		WangShiping
//===================================================================================================

#pragma once

//===================================================================================================

// 色彩检索表
typedef enum __tagColorIndex
{
	INDEX_BLACK			= 1,	// 黑色
	INDEX_WHITE			= 2,	// 白色
	INDEX_RED			= 3,	// 红色
	INDEX_BRIGHTGREEN	= 4,	// 鲜绿色
	INDEX_BLUE			= 5,	// 蓝色
	INDEX_YELLOW		= 6,	// 黄色
	INDEX_PINK			= 7,	// 粉红色
	INDEX_TURQUOISE		= 8,	// 青绿色
	INDEX_DARKRED		= 9,	// 深红色
	INDEX_GREEN			= 10,	// 绿色
	INDEX_DARKBLUE		= 11,	// 深蓝色
	INDEX_DARKYELLOW	= 12,	// 深黄色
	INDEX_VIOLET		= 13,	// 紫罗兰
	INDEX_TEAL			= 14,	// 青色
	IDNEX_GRAY25		= 15,	// 浅灰
	INDEX_GRAY50		= 16,	// 中灰
	INDEX_PERIWINKLE	= 17,	// 海螺色
	INDEX_PLUMPLUS		= 18,	// 梅红色
	INDEX_LVORY			= 19,	// 象牙色
	INDEX_LITETURQUOISE	= 20,	// 浅青绿
	INDEX_DARKPURPLE	= 21,	// 深紫色
	INDEX_CORAL			= 22,	// 珊瑚红
	INDEX_OCEANBLUE		= 23,	// 海蓝
	INDEX_ICEBLUE		= 24,	// 冰蓝
	INDEX_DARKBLUEPLUS	= 25,	// 深蓝色
	INDEX_PINKPLUS		= 26,	// 粉红色
	INDEX_YELLOWPLUS	= 27,	// 黄色
	INDEX_TURQUOISEPLUS	= 28,	// 青绿色
	INDEX_VIOLETPLUS	= 29,	// 紫罗兰
	INDEX_DARKREDPLUS	= 30,	// 深红色
	INDEX_TEALPLUS		= 31,	// 青色
	INDEX_BLUEPLUS		= 32,	// 蓝色
	INDEX_SKYBLUE		= 33,	// 天蓝色
	INDEX_LIGHTTURQUOIS	= 34,	// 浅青绿
	INDEX_LIGHTGREEN	= 35,	// 浅绿色
	INDEX_LIGHTYELLOW	= 36,	// 浅黄色
	INDEX_PALEBLUE		= 37,	// 淡蓝色
	INDEX_ROSE			= 38,	// 玫瑰红
	INDEX_LAVENDER		= 39,	// 淡紫色
	INDEX_TAN			= 40,	// 茶色
	INDEX_LIGHTBLUE		= 41,	// 浅蓝色
	INDEX_AQUA			= 42,	// 水绿色
	INDEX_LIME			= 43,	// 酸橙色
	INDEX_GOLD			= 44,	// 金色
	INDEX_LIGHTORANGE	= 45,	// 浅橙色
	INDEX_ORANGE		= 46,	// 橙色
	INDEX_BLUEGRAY		= 47,	// 蓝－灰
	INDEX_GRAY40		= 48,	// 灰－40％
	INDEX_DARKTEAL		= 49,	// 深青
	INDEX_SEAGREEN		= 50,	// 海绿
	INDEX_DARKGREEN		= 51,	// 深绿
	INDEX_OLIVEGREEN	= 52,	// 橄榄色
	INDEX_BROWN			= 53,	// 褐色
	INDEX_PLUM			= 54,	// 梅红色
	INDEX_INDIGO		= 55,	// 靛蓝
	INDEX_GRAY80		= 56	// 灰－80％
} ColorIndex;

// 段落对齐方式
typedef enum __tagAlignmentType
{
	ALIGN_LEFT		= 0,	// 左对齐
	ALIGN_RIGHT		= 2,	// 右对齐
	ALIGN_MIDDLE	= 1,	// 居中
	ALIGN_JUSTIFY	= 3		// 自适应
} AlignmentType;

// 行间距类别
typedef enum __tagLineSpace
{
	SPACE_1pt5		= 1,	// 1.5 倍行距。该行距相当于当前字号加6磅.
	SPACE_ATLEAST	= 3,	// 行距至少为一个指定值。该值需要单独指定.
	SPACE_DOUBLE	= 2,	// 双倍行距.
	SPACE_EXACTLY	= 4,	// 行距只能是所需的最大行距。此设置所使用的行距通常小于单倍行距.
	SPACE_MULTIPLE	= 5,	// 由指定的行数确定的行距.
	SPACE_SINGLE	= 0		// 单倍行距，默认值.
} LineSpace;

// 大纲级别
typedef enum __tagOutlineLevel
{
	OUTLINE_LEVEL1	= 1,	// 大纲级别1 
	OUTLINE_LEVEL2	= 2,	// 大纲级别2 
	OUTLINE_LEVEL3	= 3,	// 大纲级别3 
	OUTLINE_LEVEL4	= 4,	// 大纲级别4 
	OUTLINE_LEVEL5	= 5,	// 大纲级别5 
	OUTLINE_LEVEL6	= 6,	// 大纲级别6 
	OUTLINE_LEVEL7	= 7,	// 大纲级别7 
	OUTLINE_LEVEL8	= 8,	// 大纲级别8 
	OUTLINE_LEVEL9	= 9,	// 大纲级别9 
	OUTLINE_NOLEVEL = 10,	//没有大纲级别。 
} OutlienLevel;

typedef struct __tagWordStyleInfo
{
	CString strName;		// 样式名称
	int nAlighment;			// 段落对齐方式
	int nOutlineLevel;		// 段落大纲级别
	int nFirstIndentChar;	// 首行缩进距离
	float fBeforePound;		// 段前间距
	float fAfterPound;		// 段后间距
	int nLineSpaceType;		// 行间距类型
	CString strFontName;	// 字体名称
	float fFontSize;		// 字体大小
	int nFontColor;			// 字体颜色
	BOOL bBold;				// 字体是否加粗
	BOOL bItalic;			// 字体是否倾斜
	BOOL bUnderline;		// 是否带下划线

	__tagWordStyleInfo()
	{
		strName = L"新样式";
		nAlighment = ALIGN_JUSTIFY;
		nOutlineLevel = OUTLINE_NOLEVEL;
		nFirstIndentChar = 2;
		fBeforePound = 0.0;
		fAfterPound = 0.0;
		nLineSpaceType = SPACE_SINGLE;
		strFontName = L"宋体";
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
	// 后台启动WORD应用程序
	virtual BOOL CreateApp() = 0;

	// 前台显示WORD应用程序
	virtual void ShowApp() = 0;

	// 退出程序
	virtual BOOL QuitApp() = 0;

	// 释除内存
	virtual void ReleaseAll() = 0;

	// 打开文档
	virtual BOOL OpenDoc(const CString& strName) = 0;

	// 创建一个空白文档
	virtual BOOL CreateDoc() = 0;

	// 保存文档
	virtual BOOL SaveDoc() = 0;

	// 文档另存为
	virtual BOOL SaveDocAs(const CString &strFname) = 0;

	//===========================================================

	// 向当前光标处插入一句文本
	virtual void WriteLine(const CString& strLine) = 0;

	// 向当前光标处插入段落(最后一个参数必须为"\n")
	virtual BOOL WritePara(const CString &strStyle, CString strText, ...) = 0;

	// 回车换行
	virtual void NewParagraph(int nLine = 1) = 0;

	// 插入图片
	virtual BOOL InsertPicture(CString strPicPath) = 0;

	// 绘制表格
	virtual void CreateTable(int nRow, int nColumn, int nAutoFitType = 0) = 0;
	
	//往表格中写字
	virtual void WriteCellText(int nRow, int nColumne, CString szText) = 0;
	
	// 设置表格中的底纹
	virtual void SetCellShading(int nRow, int nColumne, int nColorIndex) = 0;
	
	// 向下移动光标位置
	virtual void MoveDown(int nRow = 1, int nUnit = 5) = 0;

	//===========================================================

	// 设置字体字号、字体、颜色
	virtual void SetFont(float fSize, CString szFontName = L"宋体", long lFontColor = INDEX_BLACK) = 0;

	// 设置字体状态（加粗、倾斜或者具有下划线）
	virtual void SetFont(BOOL bBold, BOOL bItalic, BOOL bUnderLine) = 0;

	//===========================================================
	
	// 设置段落对齐方式
	virtual void SetParagraphAlignment(int nAlignment = ALIGN_JUSTIFY) = 0;

	// 设置段落首行缩进（字符）
	virtual void SetParagraphIndent(int nCharIndent) = 0;

	// 设置段落首行缩进（厘米）
	virtual void SetParagraphIndent(float fcmIndent) = 0;

	// 设置段间距（按磅值输入）
	virtual void SetParagraphSpace(float fBeforePound, float fAfterPound) = 0;

	// 设置行间距（按行数输入）
	virtual void SetLineSpace(int nRule, float fline = 1.0) = 0;

	// 设置段落大纲级别
	virtual void SetOutlineLevel(int nLevel = OUTLINE_NOLEVEL) = 0;

	// 设置当前光标处段落样式
	virtual void SetParagraphStyle(const CString &strStyle) = 0;

	// 新建样式
	virtual BOOL CreateStyle(WordStyleInfo styleInfo) = 0;

	// 修改已有样式
	virtual BOOL ModifyStyle(WordStyleInfo styleInfo) = 0;
};

//===================================================================================================

IWordControl *CreateWordControl();
void DestroyWordControl(IWordControl *pWordControl);

//===================================================================================================
