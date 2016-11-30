//===================================================================================================
//  Description		:   XML��ʽת��Ϊע����Ϣ
//===================================================================================================

#pragma once

//===================================================================================================

#include "LayObject.h"

//===================================================================================================

#import "c:\\Program Files\\Common Files\\System\\ADO\\msado15.dll" no_namespace rename("EOF","adoEOF") 
#import "msxml3.dll"
using namespace MSXML2;

//===================================================================================================

// XML������붨��
const WORD LAY_XML_CL_OK					= 0;					// �ɹ�
const WORD LAY_XML_CL_ERROR					= 1;					// ʧ��
const WORD LAY_XML_CL_UNEXPECTED			= 2;					// �޷�Ԥ֪��ʧ��
const WORD LAY_XML_INITXMLDOM_ERROR			= 100;					// ��ʼ��XML DOMʧ��
const WORD LAY_XML_FILE_CREATE_ERROR		= 101;					// XML�ļ���������
const WORD LAY_XML_FILE_OPEN_ERROR			= 102;					// XML�ļ��򿪴���
const WORD LAY_XML_FILE_SAVE_ERROR			= 103;					// XML�ļ��������
const WORD LAY_XML_ADDNODE_ERROR			= 104;					// XML�ļ��ӽ�����
const WORD LAY_XML_ADDCHILDNODE_ERROR		= 105;					// XML�ļ����ӽ�����

//===================================================================================================

// XML�ڵ㶨��
const CString IDS_BASE_LAYOUT			= _T("LayoutInfo");			// ���ڵ�
const CString IDS_LAYOUT_VERSION		= _T("Version");			// �汾�ڵ�
const CString IDS_LAYOUT_WIDTH			= _T("Width");				// �����Ŀ��
const CString IDS_LAYOUT_HEIGHT			= _T("Height");				// �����ĸ߶�
const CString IDS_LAYOUT_LEFT			= _T("Left");				// ���������Ͻǵ�X����
const CString IDS_LAYOUT_TOP			= _T("Top");				// ���������Ͻǵ�Y����

// ֱ�ߵĸ��ڵ�
const CString IDS_BASE_LINE				= _T("Line");	
// ���εĸ��ڵ�
const CString IDS_BASE_RECTANGLE		= _T("Rectangle");			
// ��Բ�ĸ��ڵ�
const CString IDS_BASE_ELLIPSE			= _T("Ellipse");
// ���ֵĸ��ڵ�
const CString IDS_BASE_TEXT				= _T("Text");	
// ͼ��ĸ��ڵ�
const CString IDS_BASE_IMAGE			= _T("Image");	
// ���ŵĸ��ڵ�
const CString IDS_BASE_SYMBOL			= _T("Symbol");	

const CString IDS_ANN_NAME				= _T("Name");				// ע�ͷ��ŵ�����
const CString IDS_ANN_DESC				= _T("Desc");				// ע�ͷ��ŵ�����

const CString IDS_ANN_TYPE				= _T("Type");				// ע�͵�����
const CString IDS_ANN_POS				= _T("Pos");				// ע�͵�λ��
const CString IDS_ANN_POS_X				= _T("X");					// ���ĵ�X����
const CString IDS_ANN_POS_Y				= _T("Y");					// ���ĵ�Y����
const CString IDS_ANN_POS_W				= _T("W");					// ע�͵Ŀ��
const CString IDS_ANN_POS_H				= _T("H");					// ע�͵����
const CString IDS_ANN_POS_A				= _T("A");					// ע�͵ĽǶ�

const CString IDS_ANN_COLOR				= _T("LineColor");			// �߿���ɫ
const CString IDS_ANN_FILL_COLOR		= _T("FillColor");			// ���ɫ
const CString IDS_ANN_COLOR_A			= _T("A");					// ��ɫ��͸����
const CString IDS_ANN_COLOR_R			= _T("R");					// ��ɫ��Rֵ
const CString IDS_ANN_COLOR_G			= _T("G");					// ��ɫ��Gֵ
const CString IDS_ANN_COLOR_B			= _T("B");					// ��ɫ��Bֵ

const CString IDS_ANN_LINESTYLE			= _T("LineStyle");			// �߿����ԣ��ο�APADASHSTYLE
const CString IDS_ANN_LINEWIDTH			= _T("LineWidth");			// �߿���

const CString IDS_LINT_POINTLIST		= _T("PointList");			// ֱ�ߵ����Ϣ
const CString IDS_LINT_POINT			= _T("Point");				// �����Ϣ

const CString IDS_DOOR_DIRECTION		= _T("Door");				// �ŵķ���
const CString IDS_SUBTYPE				= _T("SubType");			// ���������ͣ� �ο�SYMBOLSUBTYPE

//===================================================================================================

class CXmlToObject
{
public:
	CXmlToObject();
	virtual ~CXmlToObject();
	
public:
	// ��ʼ��Dom
	BOOL Init();							
	// ж��XML Dom
	void UnInit();	
	
public:
	// ����XML�ļ�
	BOOL OpenFile(LPCTSTR strFileName);	

public:
	// ��ȡע����Ϣ
	BOOL ReadObjectFromXml();

protected:
	// ��xml�ж�ȡ������Ϣ
	BOOL ReadBaseInfoFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *pAnnObj);
	// ��xml�ж�ȡ������Ϣ
	BOOL ReadAnnRectangleFromXml(MSXML2::IXMLDOMNodePtr pNode,CLayObject *&pAnnObj);
	// ��xml�ж�ȡ��Բ��Ϣ
	BOOL ReadAnnEllipseFromXml(MSXML2::IXMLDOMNodePtr pNode,CLayObject *&pAnnObj);
	// ��xml�ж�ȡֱ����Ϣ
	BOOL ReadAnnLineFromXml(MSXML2::IXMLDOMNodePtr pNode,CLayObject *&pAnnObj);
	// ��xml�ж�ȡ������Ϣ
	BOOL ReadAnnTextFromXml(MSXML2::IXMLDOMNodePtr pNode,CLayObject *&pAnnObj);
	// ��xml�ж�ȡͼ����Ϣ
	BOOL ReadAnnImageFromXml(MSXML2::IXMLDOMNodePtr pNode,CLayObject *&pAnnObj);
	// ��xml�ж�ȡ������Ϣ
	BOOL ReadAnnSymbolFromXml(MSXML2::IXMLDOMNodePtr pNode,CLayObject *&pAnnObj);

protected:
	// �ڽ�����¼�һ���½��
	MSXML2::IXMLDOMNodePtr AppendChildNode(MSXML2::IXMLDOMNodePtr pParent, LPCTSTR strTagName);
	
	// ��ȡ�������
	CString GetNodeName(MSXML2::IXMLDOMNodePtr pNode);

	// ���ý���ı�
	int SetNodeText(MSXML2::IXMLDOMNodePtr pNode, const wchar_t *szText);
	// ��ȡ����ı�
	CString GetNodeText(MSXML2::IXMLDOMNodePtr pNode);

	// ���ý������
	int SetAttribute(MSXML2::IXMLDOMNodePtr pNode, const wchar_t *szAttrName, const wchar_t *szAttrValue);
	// ��ȡ�������
	int GetAttribute(MSXML2::IXMLDOMNodePtr pNode, const wchar_t *szAttributeName, CString &strAttributeValue) const;

protected:
	// ��BSTR���͵�����ת��ΪCString
	CString BSTRToCString(BSTR pBFName);
	// �׳�������
	void ThrowHR(HRESULT _hr) { if FAILED(_hr) throw(_hr); }
	// ���ݴ�������ô���������Ϣ
	BOOL GetErrorMsg(WORD nErrorCode);

public:
	// �汾��
	WORD m_wVersion;
	// ���������Ͻǵ�X����
	double m_dLeft;
	// ���������Ͻǵ�Y����
	double m_dTop;
	// �߶�
	double m_dHeight;
	// ���
	double m_dWidth;
	// �ĵ�����
	CString m_strName;
	// �ĵ�ע��
	CString m_strNote;

	// ���е�ע����Ϣ
	CTypedPtrArray<CPtrArray, CLayObject*> m_arrObject;

private:
	MSXML2::IXMLDOMDocumentPtr	m_pDOMDocPtr;	// XML�ĵ�����ָ��
	MSXML2::IXMLDOMElementPtr	m_pDOMElePtr;	// XMLԪ��ָ��
	CString						m_strFileName;	// XML�ļ�·������, ȫ·��
	CString						m_strErrorMsg;	// ������Ϣ����
	BOOL						m_bInitXMLDOM;	// �Ƿ񼺳ɹ���ʼ��XMLDOM
};

//===================================================================================================
