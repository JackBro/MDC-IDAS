//===================================================================================================
//  Description		:   XML格式转换为注释信息
//===================================================================================================

#pragma once

//===================================================================================================

#include "LayObject.h"

//===================================================================================================

#import "c:\\Program Files\\Common Files\\System\\ADO\\msado15.dll" no_namespace rename("EOF","adoEOF") 
#import "msxml3.dll"
using namespace MSXML2;

//===================================================================================================

// XML错误代码定义
const WORD LAY_XML_CL_OK					= 0;					// 成功
const WORD LAY_XML_CL_ERROR					= 1;					// 失败
const WORD LAY_XML_CL_UNEXPECTED			= 2;					// 无法预知的失败
const WORD LAY_XML_INITXMLDOM_ERROR			= 100;					// 初始化XML DOM失败
const WORD LAY_XML_FILE_CREATE_ERROR		= 101;					// XML文件创建错误
const WORD LAY_XML_FILE_OPEN_ERROR			= 102;					// XML文件打开错误
const WORD LAY_XML_FILE_SAVE_ERROR			= 103;					// XML文件保存错误
const WORD LAY_XML_ADDNODE_ERROR			= 104;					// XML文件加结点错误
const WORD LAY_XML_ADDCHILDNODE_ERROR		= 105;					// XML文件加子结点错误

//===================================================================================================

// XML节点定义
const CString IDS_BASE_LAYOUT			= _T("LayoutInfo");			// 根节点
const CString IDS_LAYOUT_VERSION		= _T("Version");			// 版本节点
const CString IDS_LAYOUT_WIDTH			= _T("Width");				// 画布的宽度
const CString IDS_LAYOUT_HEIGHT			= _T("Height");				// 画布的高度
const CString IDS_LAYOUT_LEFT			= _T("Left");				// 画布的左上角点X坐标
const CString IDS_LAYOUT_TOP			= _T("Top");				// 画布的左上角点Y坐标

// 直线的根节点
const CString IDS_BASE_LINE				= _T("Line");	
// 矩形的根节点
const CString IDS_BASE_RECTANGLE		= _T("Rectangle");			
// 椭圆的根节点
const CString IDS_BASE_ELLIPSE			= _T("Ellipse");
// 文字的根节点
const CString IDS_BASE_TEXT				= _T("Text");	
// 图像的根节点
const CString IDS_BASE_IMAGE			= _T("Image");	
// 符号的根节点
const CString IDS_BASE_SYMBOL			= _T("Symbol");	

const CString IDS_ANN_NAME				= _T("Name");				// 注释符号的名字
const CString IDS_ANN_DESC				= _T("Desc");				// 注释符号的描述

const CString IDS_ANN_TYPE				= _T("Type");				// 注释的类型
const CString IDS_ANN_POS				= _T("Pos");				// 注释的位置
const CString IDS_ANN_POS_X				= _T("X");					// 中心点X坐标
const CString IDS_ANN_POS_Y				= _T("Y");					// 中心点Y坐标
const CString IDS_ANN_POS_W				= _T("W");					// 注释的宽度
const CString IDS_ANN_POS_H				= _T("H");					// 注释的深度
const CString IDS_ANN_POS_A				= _T("A");					// 注释的角度

const CString IDS_ANN_COLOR				= _T("LineColor");			// 边框颜色
const CString IDS_ANN_FILL_COLOR		= _T("FillColor");			// 填充色
const CString IDS_ANN_COLOR_A			= _T("A");					// 颜色的透明度
const CString IDS_ANN_COLOR_R			= _T("R");					// 颜色的R值
const CString IDS_ANN_COLOR_G			= _T("G");					// 颜色的G值
const CString IDS_ANN_COLOR_B			= _T("B");					// 颜色的B值

const CString IDS_ANN_LINESTYLE			= _T("LineStyle");			// 边框属性，参考APADASHSTYLE
const CString IDS_ANN_LINEWIDTH			= _T("LineWidth");			// 边框宽度

const CString IDS_LINT_POINTLIST		= _T("PointList");			// 直线点的信息
const CString IDS_LINT_POINT			= _T("Point");				// 点的信息

const CString IDS_DOOR_DIRECTION		= _T("Door");				// 门的方向
const CString IDS_SUBTYPE				= _T("SubType");			// 符号子类型， 参考SYMBOLSUBTYPE

//===================================================================================================

class CXmlToObject
{
public:
	CXmlToObject();
	virtual ~CXmlToObject();
	
public:
	// 初始化Dom
	BOOL Init();							
	// 卸载XML Dom
	void UnInit();	
	
public:
	// 读入XML文件
	BOOL OpenFile(LPCTSTR strFileName);	

public:
	// 读取注释信息
	BOOL ReadObjectFromXml();

protected:
	// 从xml中读取基本信息
	BOOL ReadBaseInfoFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *pAnnObj);
	// 从xml中读取矩形信息
	BOOL ReadAnnRectangleFromXml(MSXML2::IXMLDOMNodePtr pNode,CLayObject *&pAnnObj);
	// 从xml中读取椭圆信息
	BOOL ReadAnnEllipseFromXml(MSXML2::IXMLDOMNodePtr pNode,CLayObject *&pAnnObj);
	// 从xml中读取直线信息
	BOOL ReadAnnLineFromXml(MSXML2::IXMLDOMNodePtr pNode,CLayObject *&pAnnObj);
	// 从xml中读取文字信息
	BOOL ReadAnnTextFromXml(MSXML2::IXMLDOMNodePtr pNode,CLayObject *&pAnnObj);
	// 从xml中读取图像信息
	BOOL ReadAnnImageFromXml(MSXML2::IXMLDOMNodePtr pNode,CLayObject *&pAnnObj);
	// 从xml中读取符号信息
	BOOL ReadAnnSymbolFromXml(MSXML2::IXMLDOMNodePtr pNode,CLayObject *&pAnnObj);

protected:
	// 在结点项下加一个新结点
	MSXML2::IXMLDOMNodePtr AppendChildNode(MSXML2::IXMLDOMNodePtr pParent, LPCTSTR strTagName);
	
	// 获取结点名称
	CString GetNodeName(MSXML2::IXMLDOMNodePtr pNode);

	// 设置结点文本
	int SetNodeText(MSXML2::IXMLDOMNodePtr pNode, const wchar_t *szText);
	// 获取结点文本
	CString GetNodeText(MSXML2::IXMLDOMNodePtr pNode);

	// 设置结点属性
	int SetAttribute(MSXML2::IXMLDOMNodePtr pNode, const wchar_t *szAttrName, const wchar_t *szAttrValue);
	// 获取结点属性
	int GetAttribute(MSXML2::IXMLDOMNodePtr pNode, const wchar_t *szAttributeName, CString &strAttributeValue) const;

protected:
	// 把BSTR类型的数据转换为CString
	CString BSTRToCString(BSTR pBFName);
	// 抛出错误标记
	void ThrowHR(HRESULT _hr) { if FAILED(_hr) throw(_hr); }
	// 根据错误代码获得错误描述信息
	BOOL GetErrorMsg(WORD nErrorCode);

public:
	// 版本号
	WORD m_wVersion;
	// 画布的左上角点X坐标
	double m_dLeft;
	// 画布的左上角点Y坐标
	double m_dTop;
	// 高度
	double m_dHeight;
	// 宽度
	double m_dWidth;
	// 文档名字
	CString m_strName;
	// 文档注解
	CString m_strNote;

	// 所有的注释信息
	CTypedPtrArray<CPtrArray, CLayObject*> m_arrObject;

private:
	MSXML2::IXMLDOMDocumentPtr	m_pDOMDocPtr;	// XML文档对象指针
	MSXML2::IXMLDOMElementPtr	m_pDOMElePtr;	// XML元素指针
	CString						m_strFileName;	// XML文件路径名称, 全路径
	CString						m_strErrorMsg;	// 错误信息描述
	BOOL						m_bInitXMLDOM;	// 是否己成功初始化XMLDOM
};

//===================================================================================================
