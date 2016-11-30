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
	int		m_nType;			// ���ͣ��ο�ANNOBJECTTYPE

	UINT	m_nLineStyle;		// �ߵķ��
	APARGB	m_clrLine;			// �ߵ���ɫ
	UINT	m_nLineWidth; 		// �ߵĿ��
	CString	m_strName;			// ע�Ͷ��������
	CString m_strDesc;			// ע�Ͷ��������

	double	m_dAngle;			// ��ת�ĽǶ�
	double  m_dWidth;			// ����Ŀ��
	double  m_dHeight;			// ����ĸ߶�
	SpPoint m_ptCenter;			// ��������ĵ�
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
	CArray <SpPoint, SpPoint&> m_arrPos;	// ����㣬��һ����Ϊ��ʼ�㣬Ϊ�߼�����
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
	APARGB		m_clrFill;		// ���ɫ
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
	APARGB		m_clrFill;		// ���ɫ
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
	// ������Ϣ
	APATEXTINFO m_textInfo;
	// ��������
	CString m_strContent;
	// ������Ӿ���
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
	APARGB m_clrFill;		// ���ɫ
	int m_nDoorDirection;	// �ŵķ��� �ο�DOORDIRECTION
	int m_nSubType;			// ���������ͣ� �ο�SYMBOLSUBTYPE
};

//===================================================================================================