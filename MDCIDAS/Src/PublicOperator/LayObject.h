//===================================================================================================

#pragma once

//===================================================================================================

#include "DocModelDef.h"

//===================================================================================================

class CLayObject
{
public:
	CLayObject()
	{
		m_nType = AOT_UNKNOWN;
		m_strName = L"";
		m_strDesc = L"";
		m_nLineStyle = APADT_SOLID;
		m_nLineWidth = 1;
		m_dAngle = 0;
		m_dWidth = 0;
		m_dHeight = 0;
		m_ptCenter.x = 0;
		m_ptCenter.y = 0;

	}
	virtual ~CLayObject(){}

public:	
	int		m_nType;			// 类型，参考ANNOBJECTTYPE

	UINT	m_nLineStyle;		// 线的风格
	APARGB	m_clrLine;			// 线的颜色
	UINT	m_nLineWidth; 		// 线的宽度
	CString	m_strName;			// 注释对象的名称
	CString m_strDesc;			// 注释对象的描述

	double	m_dAngle;			// 旋转的角度
	double  m_dWidth;			// 对象的宽度
	double  m_dHeight;			// 对象的高度
	SpPoint m_ptCenter;			// 对象的中心点
};

//===================================================================================================

class CLayLineObj : public CLayObject
{
public:
	CLayLineObj()
	{
		m_nType = AOT_LINE;
	}
	virtual ~CLayLineObj(){}

public:	
	CArray <SpPoint, SpPoint&> m_arrPos;	// 坐标点，第一个点为起始点，为逻辑坐标
};

//===================================================================================================

class CLayRectangleObj : public CLayObject
{
public:
	CLayRectangleObj()
	{
		m_nType = AOT_RECTANGLE;
	}
	virtual ~CLayRectangleObj(){}

public:	
	APARGB		m_clrFill;		// 填充色
};

//===================================================================================================

class CLayEllipseObj : public CLayObject
{
public:
	CLayEllipseObj()
	{
		m_nType = AOT_ELLIPSE;
	}
	virtual ~CLayEllipseObj(){}

public:	
	APARGB		m_clrFill;		// 填充色
};

//===================================================================================================

class CLayTextObject : public CLayObject
{
public:
	CLayTextObject()
	{
		m_nType = AOT_TEXT;
	}
	virtual ~CLayTextObject(){ }

public:	
	// 文字信息
	APATEXTINFO m_textInfo;
	// 文字内容
	CString m_strContent;
	// 文字外接矩形
	SpRect m_rcTextBox;
};

//===================================================================================================

class CLayImageObject : public CLayObject
{
public:
	CLayImageObject()
	{
		m_nType = AOT_IMAGE;
	}
	virtual ~CLayImageObject(){}
};

//===================================================================================================

class CLaySymbolObj : public CLayObject
{
public:
	CLaySymbolObj()
	{
		m_nType = AOT_CABINET;
	}
	virtual ~CLaySymbolObj(){}

public:	
	APARGB m_clrFill;		// 填充色
	int m_nDoorDirection;	// 门的方向， 参考DOORDIRECTION
	int m_nSubType;			// 符号子类型， 参考SYMBOLSUBTYPE
};

//===================================================================================================