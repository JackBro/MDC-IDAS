//===================================================================================================
//  Description		:   XML��ʽת��Ϊע����Ϣ
//===================================================================================================

#include "stdafx.h"
#include "XmlToObject.h"

//===================================================================================================

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//===================================================================================================

CXmlToObject::CXmlToObject()
{
	m_bInitXMLDOM = FALSE;
	m_pDOMDocPtr = NULL;
	m_pDOMElePtr  = NULL;
}

CXmlToObject::~CXmlToObject()
{
	if (m_bInitXMLDOM || (m_pDOMDocPtr != NULL) )
		UnInit();
}

// ��ʼ��
BOOL CXmlToObject::Init()
{
	BOOL bResult = TRUE;

	try
	{
		ThrowHR(CoInitialize(NULL));
		ThrowHR(m_pDOMDocPtr.CreateInstance(_T("msxml2.domdocument")));
	}
	catch(...)
	{
		GetErrorMsg(XML_INITXMLDOM_ERROR);
		bResult = FALSE;
	}
	m_bInitXMLDOM = bResult;

	return bResult;
}

// ж��XML Dom
void CXmlToObject::UnInit()
{
	if (m_bInitXMLDOM)
	{
		m_pDOMDocPtr.Detach();
		m_pDOMDocPtr = NULL;
		m_pDOMElePtr = NULL;
		m_bInitXMLDOM = FALSE;
		CoUninitialize();  
	}

	// ���ע�Ͷ���
	for (int i = 0; i < m_arrObject.GetSize(); i++)
	{
		if (m_arrObject[i] != NULL)
			delete m_arrObject[i];
	}
	m_arrObject.RemoveAll();
}

// ��XML�ļ�
BOOL CXmlToObject::OpenFile(LPCTSTR strFileName)
{
	if (!m_bInitXMLDOM)
		return FALSE;

	// ���ע�Ͷ���
	for (int i = 0; i < m_arrObject.GetSize(); i++)
	{
		if (m_arrObject[i] != NULL)
			delete m_arrObject[i];
	}
	m_arrObject.RemoveAll();

	BOOL bResult = FALSE;
	m_pDOMElePtr = NULL;
	m_strFileName = _T("");
	try
	{
		_variant_t varXmlFileName(strFileName);
		_variant_t varOut((bool)TRUE);
		varOut = m_pDOMDocPtr->load(varXmlFileName); 
		if ((bool)varOut == TRUE)
		{
			m_pDOMElePtr = m_pDOMDocPtr->documentElement;
			m_strFileName = strFileName;
			bResult = TRUE;

			ReadObjectFromXml();
		}
	}
	catch(...) 
	{
		GetErrorMsg(XML_FILE_OPEN_ERROR);
	}
	return bResult;
}

// ��ȡע����Ϣ
BOOL CXmlToObject::ReadObjectFromXml()
{
	MSXML2::IXMLDOMNodeListPtr pNodeList = m_pDOMDocPtr->getElementsByTagName(_bstr_t(IDS_BASE_LAYOUT));
	MSXML2::IXMLDOMNodePtr pRootNode = NULL;
	long nNodeCount = 0;
	if (pNodeList != NULL)
		pNodeList->get_length(&nNodeCount);
	else
		return FALSE;
	if (nNodeCount >= 0)
		pNodeList->get_item(0, &pRootNode);
	else
		return FALSE;

	CString strNodeName;
	CString strNodeAttr;
	// �汾��
	GetAttribute(pRootNode, IDS_LAYOUT_VERSION, strNodeAttr);
	m_wVersion = (WORD)_ttoi(strNodeAttr);
	// ��Ⱥ͸߶�
	GetAttribute(pRootNode, IDS_LAYOUT_WIDTH, strNodeAttr);
	m_dWidth = _wtof(strNodeAttr);
	GetAttribute(pRootNode, IDS_LAYOUT_HEIGHT, strNodeAttr);
	m_dHeight = _wtof(strNodeAttr);

	GetAttribute(pRootNode, IDS_LAYOUT_LEFT, strNodeAttr);
	m_dLeft = _wtof(strNodeAttr);
	GetAttribute(pRootNode, IDS_LAYOUT_TOP, strNodeAttr);
	m_dTop = _wtof(strNodeAttr);

	// �ĵ�����
	GetAttribute(pRootNode, IDS_ANN_NAME, m_strName);

	// �ĵ�ע��
	GetAttribute(pRootNode, IDS_ANN_DESC, m_strNote);

	pNodeList = pRootNode->GetchildNodes();
	if (pNodeList == NULL)
		return FALSE;
	pNodeList->get_length(&nNodeCount);

	// ��ȡע����Ϣ
	MSXML2::IXMLDOMNodePtr pNode = NULL;
	
	for(long i=0; i<nNodeCount; i++)
	{
		CLayObject *pNewAnnObject = NULL;

		pNodeList->get_item(i, &pNode);
		strNodeName = GetNodeName(pNode);

		if (strNodeName == IDS_BASE_LINE)
			ReadAnnLineFromXml(pNode, pNewAnnObject);
		else if (strNodeName == IDS_BASE_RECTANGLE)
			ReadAnnRectangleFromXml(pNode, pNewAnnObject);
		else if (strNodeName == IDS_BASE_ELLIPSE)
			ReadAnnEllipseFromXml(pNode, pNewAnnObject);
		else if (strNodeName == IDS_BASE_TEXT)
			ReadAnnTextFromXml(pNode, pNewAnnObject);
		else if (strNodeName == IDS_BASE_IMAGE)
			ReadAnnImageFromXml(pNode, pNewAnnObject);
		else if (strNodeName == IDS_BASE_SYMBOL)
			ReadAnnSymbolFromXml(pNode, pNewAnnObject);

		if (pNewAnnObject != NULL)
			m_arrObject.Add(pNewAnnObject);			
	}
	
	return TRUE;
}

// ��xml�ж�ȡ������Ϣ
BOOL CXmlToObject::ReadBaseInfoFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *pAnnObj)
{
	if (pAnnObj == NULL)
		return FALSE;

	// ע�͵�����
	CString strAttributeValue;
	GetAttribute(pNode, IDS_ANN_TYPE, strAttributeValue);
	pAnnObj->m_nType = _ttoi(strAttributeValue);

	// �ߵ�����
	GetAttribute(pNode, IDS_ANN_LINESTYLE, strAttributeValue);
	pAnnObj->m_nLineStyle = (UINT)_ttoi(strAttributeValue);

	// �ߵĿ��
	GetAttribute(pNode, IDS_ANN_LINEWIDTH, strAttributeValue);
	pAnnObj->m_nLineWidth = (UINT)_ttoi(strAttributeValue);

	MSXML2::IXMLDOMNodeListPtr pNodeList = pNode->GetchildNodes();
	if (pNodeList == NULL)
		return FALSE;

	long nNodeCount = 0;
	MSXML2::IXMLDOMNodePtr pChildNode = NULL;
	CString strNodeName;
	CString strNodeText;
	pNodeList->get_length(&nNodeCount);
	for (long i = 0; i<nNodeCount; i++)
	{
		pNodeList->get_item(i, &pChildNode);
		strNodeName = GetNodeName(pChildNode);
		
		// ��ɫ
		if (strNodeName == IDS_ANN_COLOR)
		{
			GetAttribute(pChildNode, IDS_ANN_COLOR_A, strAttributeValue);
			pAnnObj->m_clrLine.byAlpha = (BYTE)_ttoi(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_COLOR_R, strAttributeValue);
			pAnnObj->m_clrLine.byRed = (BYTE)_ttoi(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_COLOR_G, strAttributeValue);
			pAnnObj->m_clrLine.byGreen = (BYTE)_ttoi(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_COLOR_B, strAttributeValue);
			pAnnObj->m_clrLine.byBlue = (BYTE)_ttoi(strAttributeValue);
		}	
		else if (strNodeName == IDS_ANN_POS) 	// λ��
		{
			GetAttribute(pChildNode, IDS_ANN_POS_X, strAttributeValue);
			pAnnObj->m_ptCenter.x = _wtof(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_POS_Y, strAttributeValue);
			pAnnObj->m_ptCenter.y = _wtof(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_POS_W, strAttributeValue);
			pAnnObj->m_dWidth= _wtof(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_POS_H, strAttributeValue);
			pAnnObj->m_dHeight = _wtof(strAttributeValue);

			// �Ƕ�
			GetAttribute(pChildNode, IDS_ANN_POS_A, strAttributeValue);
			pAnnObj->m_dAngle = _wtof(strAttributeValue);
		}		
		else if (strNodeName == IDS_ANN_NAME) // λ��
		{
			pAnnObj->m_strName = GetNodeText(pChildNode);
		}
		else if (strNodeName == IDS_ANN_DESC) // ע��
		{
			pAnnObj->m_strDesc = GetNodeText(pChildNode);
		}
	}

	return TRUE;
}

// ��xml�ж�ȡ������Ϣ
BOOL CXmlToObject::ReadAnnRectangleFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *&pAnnObj)
{
	pAnnObj = new CLayRectangleObj;

	CLayRectangleObj *pRecObj = (CLayRectangleObj *)pAnnObj;

	// ��ȡ������Ϣ
	ReadBaseInfoFromXml(pNode,pAnnObj);

	MSXML2::IXMLDOMNodeListPtr pNodeList = pNode->GetchildNodes();
	if (pNodeList == NULL)
		return FALSE;

	long nNodeCount = 0;
	MSXML2::IXMLDOMNodePtr pChildNode = NULL;
	CString strNodeName;
	CString strNodeText;
	CString strAttributeValue;
	pNodeList->get_length(&nNodeCount);
	for (long i = 0; i<nNodeCount; i++)
	{
		pNodeList->get_item(i, &pChildNode);
		strNodeName = GetNodeName(pChildNode);

		// ��ɫ
		if (strNodeName == IDS_ANN_FILL_COLOR)
		{
			GetAttribute(pChildNode, IDS_ANN_COLOR_A, strAttributeValue);
			pRecObj->m_clrFill.byAlpha = (BYTE)_ttoi(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_COLOR_R, strAttributeValue);
			pRecObj->m_clrFill.byRed = (BYTE)_ttoi(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_COLOR_G, strAttributeValue);
			pRecObj->m_clrFill.byGreen = (BYTE)_ttoi(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_COLOR_B, strAttributeValue);
			pRecObj->m_clrFill.byBlue = (BYTE)_ttoi(strAttributeValue);
		}
	}

	return TRUE;
}

// ��xml�ж�ȡ������Ϣ
BOOL CXmlToObject::ReadAnnSymbolFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *&pAnnObj)
{
	pAnnObj = new CLaySymbolObj;

	CLaySymbolObj *pSymbolObj = (CLaySymbolObj *)pAnnObj;

	// ��ȡ������Ϣ
	ReadBaseInfoFromXml(pNode, pAnnObj);

	CString strAttributeValue;

	// �ŵķ���
	GetAttribute(pNode, IDS_DOOR_DIRECTION, strAttributeValue);
	pSymbolObj->m_nDoorDirection = _ttoi(strAttributeValue);

	// ������
	GetAttribute(pNode, IDS_SUBTYPE, strAttributeValue);
	pSymbolObj->m_nSubType = _ttoi(strAttributeValue);

	MSXML2::IXMLDOMNodeListPtr pNodeList = pNode->GetchildNodes();
	if (pNodeList == NULL)
		return FALSE;

	long nNodeCount = 0;
	MSXML2::IXMLDOMNodePtr pChildNode = NULL;
	CString strNodeName;
	CString strNodeText;
	pNodeList->get_length(&nNodeCount);
	for (long i = 0; i<nNodeCount; i++)
	{
		pNodeList->get_item(i, &pChildNode);
		strNodeName = GetNodeName(pChildNode);

		// ��ɫ
		if (strNodeName == IDS_ANN_FILL_COLOR)
		{
			GetAttribute(pChildNode, IDS_ANN_COLOR_A, strAttributeValue);
			pSymbolObj->m_clrFill.byAlpha = (BYTE)_ttoi(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_COLOR_R, strAttributeValue);
			pSymbolObj->m_clrFill.byRed = (BYTE)_ttoi(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_COLOR_G, strAttributeValue);
			pSymbolObj->m_clrFill.byGreen = (BYTE)_ttoi(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_COLOR_B, strAttributeValue);
			pSymbolObj->m_clrFill.byBlue = (BYTE)_ttoi(strAttributeValue);
		}
	}

	return TRUE;
}

// ��xml�ж�ȡ��Բ��Ϣ
BOOL CXmlToObject::ReadAnnEllipseFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *&pAnnObj)
{
	pAnnObj = new CLayEllipseObj;

	CLayEllipseObj *pEllipseObj = (CLayEllipseObj *)pAnnObj;

	// ��ȡ������Ϣ
	ReadBaseInfoFromXml(pNode,pAnnObj);

	MSXML2::IXMLDOMNodeListPtr pNodeList = pNode->GetchildNodes();
	if (pNodeList == NULL)
		return FALSE;

	long nNodeCount = 0;
	MSXML2::IXMLDOMNodePtr pChildNode = NULL;
	CString strNodeName;
	CString strNodeText;
	CString strAttributeValue;
	pNodeList->get_length(&nNodeCount);
	for (long i = 0; i<nNodeCount; i++)
	{
		pNodeList->get_item(i, &pChildNode);
		strNodeName = GetNodeName(pChildNode);

		// ��ɫ
		if (strNodeName == IDS_ANN_FILL_COLOR)
		{
			GetAttribute(pChildNode, IDS_ANN_COLOR_A, strAttributeValue);
			pEllipseObj->m_clrFill.byAlpha = (BYTE)_ttoi(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_COLOR_R, strAttributeValue);
			pEllipseObj->m_clrFill.byRed = (BYTE)_ttoi(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_COLOR_G, strAttributeValue);
			pEllipseObj->m_clrFill.byGreen = (BYTE)_ttoi(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_COLOR_B, strAttributeValue);
			pEllipseObj->m_clrFill.byBlue = (BYTE)_ttoi(strAttributeValue);
		}
	}

	return TRUE;
}

// ��xml�ж�ȡֱ����Ϣ
BOOL CXmlToObject::ReadAnnLineFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *&pAnnObj)
{
	pAnnObj = new CLayLineObj;

	CLayLineObj *pLineObj = (CLayLineObj *)pAnnObj;

	// ��ȡ������Ϣ
	ReadBaseInfoFromXml(pNode,pAnnObj);

	MSXML2::IXMLDOMNodeListPtr pNodeList = pNode->GetchildNodes();
	if (pNodeList == NULL)
		return FALSE;

	long nNodeCount = 0;
	MSXML2::IXMLDOMNodePtr pChildNode = NULL;
	CString strNodeName;
	CString strNodeText;
	CString strAttributeValue;
	pNodeList->get_length(&nNodeCount);
	for (long i = 0; i < nNodeCount; i++)
	{
		pNodeList->get_item(i, &pChildNode);
		strNodeName = GetNodeName(pChildNode);

		// �������
		if (strNodeName == IDS_LINT_POINTLIST)
		{
			MSXML2::IXMLDOMNodeListPtr pPosNodeList = pChildNode->GetchildNodes();
			if (pPosNodeList == NULL)
				return FALSE;

			long nPointCount = 0;
			MSXML2::IXMLDOMNodePtr pPointNode = NULL;
			pNodeList->get_length(&nPointCount);
			for (long j = 0; j < nPointCount; j++)
			{
				pPosNodeList->get_item(j, &pPointNode);
				strNodeName = GetNodeName(pPointNode);
				if (!strNodeName.IsEmpty())
				{
					SpPoint pt;
					GetAttribute(pPointNode, IDS_ANN_POS_X, strAttributeValue);
					pt.x = _wtof(strAttributeValue);

					GetAttribute(pPointNode, IDS_ANN_POS_Y, strAttributeValue);
					pt.y = _wtof(strAttributeValue);

					pLineObj->m_arrPos.Add(pt);
				}			
			}
		}
	}

	return TRUE;
}

// ��xml�ж�ȡ������Ϣ
BOOL CXmlToObject::ReadAnnTextFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *&pAnnObj)
{
	pAnnObj = new CLayTextObject;

	CLayTextObject *pTextObj = (CLayTextObject *)pAnnObj;

	// ��ȡ������Ϣ
	ReadBaseInfoFromXml(pNode,pAnnObj);

	MSXML2::IXMLDOMNodeListPtr pNodeList = pNode->GetchildNodes();
	if (pNodeList == NULL)
		return FALSE;

	long nNodeCount = 0;
	MSXML2::IXMLDOMNodePtr pChildNode = NULL;
	CString strNodeName;
	CString strNodeText;
	CString strAttributeValue;
	pNodeList->get_length(&nNodeCount);
	for (long i = 0; i < nNodeCount; i++)
	{
		pNodeList->get_item(i, &pChildNode);
		strNodeName = GetNodeName(pChildNode);

		if (strNodeName == L"Content")
		{
			pTextObj->m_strContent = GetNodeText(pChildNode);
		}
		else if (strNodeName == L"TextBox")
		{
			GetAttribute(pChildNode, IDS_ANN_POS_X, strAttributeValue);
			pTextObj->m_rcTextBox.left = _wtof(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_POS_Y, strAttributeValue);
			pTextObj->m_rcTextBox.top = _wtof(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_POS_W, strAttributeValue);
			pTextObj->m_rcTextBox.right = _wtof(strAttributeValue) + pTextObj->m_rcTextBox.left;

			GetAttribute(pChildNode, IDS_ANN_POS_H, strAttributeValue);
			pTextObj->m_rcTextBox.bottom = _wtof(strAttributeValue) + pTextObj->m_rcTextBox.top;
		}
		// ������Ϣ
		else if (strNodeName == L"TextInfo")
		{	
			// �汾��
			GetAttribute(pChildNode, L"Version", strAttributeValue);
			pTextObj->m_textInfo.wVersion = (WORD)_ttoi(strAttributeValue);
			
			// ��������
			GetAttribute(pChildNode, L"FontName", strAttributeValue);
			wcscpy_s(pTextObj->m_textInfo.szFontName, sizeof(pTextObj->m_textInfo.szFontName)/sizeof(wchar_t), strAttributeValue);

			// ���ֵ����ϵ�����, �����߼����ꡣ
			GetAttribute(pChildNode, L"X", strAttributeValue);
			pTextObj->m_textInfo.ptLeftTop.x = _ttoi(strAttributeValue);
			GetAttribute(pChildNode, L"Y", strAttributeValue);
			pTextObj->m_textInfo.ptLeftTop.y = _ttoi(strAttributeValue);
		
			// ����ĸ߶�
			GetAttribute(pChildNode, L"Height", strAttributeValue);
			pTextObj->m_textInfo.lfHeight = _ttoi(strAttributeValue);

			// ������Ӿ������Ͻǵ�Ϊ���㣬��Ϊ�����򣬴�0�ȵ�360��
			GetAttribute(pChildNode, L"Height", strAttributeValue);
			pTextObj->m_textInfo.nAngle = _ttoi(strAttributeValue);

			// ����Ӵ�
			GetAttribute(pChildNode, L"Bold", strAttributeValue);
			pTextObj->m_textInfo.bBold = (BYTE)_ttoi(strAttributeValue);

			// ����б��
			GetAttribute(pChildNode, L"Italic", strAttributeValue);
			pTextObj->m_textInfo.bItalic = (BYTE)_ttoi(strAttributeValue);

			// �����»���
			GetAttribute(pChildNode, L"Underline", strAttributeValue);
			pTextObj->m_textInfo.bUnderline = (BYTE)_ttoi(strAttributeValue);

			MSXML2::IXMLDOMNodeListPtr pTextNodeList = pChildNode->GetchildNodes();
			if (pTextNodeList == NULL)
				return FALSE;

			long nTextCount = 0;
			MSXML2::IXMLDOMNodePtr pTextNode = NULL;
			pNodeList->get_length(&nTextCount);
			for (long j = 0; j < nTextCount; j++)
			{
				pTextNodeList->get_item(j, &pTextNode);
				strNodeName = GetNodeName(pTextNode);

				// ���ֵ���ɫ
				if (strNodeName == L"Color")
				{
					GetAttribute(pTextNode, IDS_ANN_COLOR_A, strAttributeValue);
					pTextObj->m_textInfo.clrText.byAlpha = (BYTE)_ttoi(strAttributeValue);

					GetAttribute(pTextNode, IDS_ANN_COLOR_R, strAttributeValue);
					pTextObj->m_textInfo.clrText.byRed = (BYTE)_ttoi(strAttributeValue);

					GetAttribute(pTextNode, IDS_ANN_COLOR_G, strAttributeValue);
					pTextObj->m_textInfo.clrText.byGreen = (BYTE)_ttoi(strAttributeValue);

					GetAttribute(pTextNode, IDS_ANN_COLOR_B, strAttributeValue);
					pTextObj->m_textInfo.clrText.byBlue = (BYTE)_ttoi(strAttributeValue);
				}	
				
			}
		}
	}

	return TRUE;
}

// ��xml�ж�ȡͼ����Ϣ
BOOL CXmlToObject::ReadAnnImageFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *&pAnnObj)
{
	pAnnObj = new CLayImageObject;

	// CLayImageObject *pImageObj = (CLayImageObject *)pAnnObj;

	// ��ȡ������Ϣ
	ReadBaseInfoFromXml(pNode,pAnnObj);

	return TRUE;
}

MSXML2::IXMLDOMNodePtr CXmlToObject::AppendChildNode(MSXML2::IXMLDOMNodePtr pParent, LPCTSTR strTagName)
{
	_bstr_t bstrTagName(strTagName);

	VARIANT vtTemp;
	vtTemp.vt = VT_I2;
	vtTemp.iVal = 1;	// NODE_ELEMENT
	MSXML2::IXMLDOMNodePtr pResultNodePtr = NULL;
	try
	{
		pResultNodePtr = m_pDOMDocPtr->createNode(vtTemp, bstrTagName, _T(""));
		if (pParent == NULL)
			m_pDOMElePtr->appendChild(pResultNodePtr);
		else
			pParent->appendChild(pResultNodePtr);

	}
	catch (...) 
	{
		pResultNodePtr = NULL;
	}

	return pResultNodePtr;
}

// ����ڵ�������ӽڵ㣬����strText��Ϊ�ı��ڵ����Ϊ���ڵ���ӽڵ�
int CXmlToObject::SetNodeText(MSXML2::IXMLDOMNodePtr pNode, const wchar_t *szText)
{
	if (pNode == NULL || szText == NULL)
		return LAY_XML_CL_ERROR;

	try
	{
		_bstr_t bstrText(szText);
		pNode->put_text(bstrText);
	}
	catch (...)
	{
		return LAY_XML_CL_ERROR;	
	}
	return LAY_XML_CL_OK;
}

//  ȡ�ý���ı�
CString CXmlToObject::GetNodeText(MSXML2::IXMLDOMNodePtr pNode)
{
	BSTR bstrText = NULL;
	CString strResult;

	if (pNode != NULL)
	{
		pNode->get_text(&bstrText);
		
		strResult = BSTRToCString(bstrText);
		::SysFreeString(bstrText);
	}
	return strResult;
}

// ��ȡ�������
CString CXmlToObject::GetNodeName(MSXML2::IXMLDOMNodePtr pNode)
{
	BSTR bstrName = NULL;
	CString strResult;

	if (pNode != NULL)
	{
		pNode->get_nodeName(&bstrName);
		strResult = BSTRToCString(bstrName);
		::SysFreeString(bstrName);
	}
	return strResult;
}

// ��������ֵ
int CXmlToObject::SetAttribute(MSXML2::IXMLDOMNodePtr pNode, const wchar_t *szAttrName, const wchar_t *szAttrValue)
{
	if (pNode == NULL || szAttrName == NULL || szAttrValue == NULL)
		return LAY_XML_CL_ERROR;

	if (pNode->GetnodeType() != MSXML2::NODE_ELEMENT)
		return LAY_XML_CL_ERROR;

	try
	{
		_bstr_t bstrName(szAttrName);
		MSXML2::IXMLDOMElementPtr pElemt = (MSXML2::IXMLDOMElementPtr)pNode;
		pElemt->setAttribute(_bstr_t(szAttrName),_variant_t(szAttrValue));

	}
	catch (...)
	{
		return LAY_XML_CL_ERROR;
	}
	return LAY_XML_CL_OK;
}

// ��ȡ��ǰ����ָ�����Ե�ֵ			
int CXmlToObject::GetAttribute(MSXML2::IXMLDOMNodePtr pNode, const wchar_t *szAttributeName, CString &strAttributeValue) const
{
	if (pNode == NULL)
		return LAY_XML_CL_ERROR;

	MSXML2::IXMLDOMNamedNodeMap *pAttributeMap = NULL;
	pNode->get_attributes(&pAttributeMap);
	if (pAttributeMap == NULL)
		return LAY_XML_CL_ERROR;

	MSXML2::IXMLDOMNodePtr pAttNode = pAttributeMap->getNamedItem(szAttributeName);
	if (pAttNode == NULL)
		return LAY_XML_CL_ERROR;

	BSTR bstrText = NULL;
	pAttNode->get_text(&bstrText);
	strAttributeValue = bstrText;
	::SysFreeString(bstrText);	

	return LAY_XML_CL_OK;
}

// ��BSTR���͵�����ת��ΪCString
CString CXmlToObject::BSTRToCString(BSTR pBFName)
{
	CString strResult = CString(pBFName);
	return strResult;
}

// ��ȡ������Ϣ
BOOL CXmlToObject::GetErrorMsg(WORD nErrorCode)
{
	switch(nErrorCode)
	{
	case LAY_XML_CL_OK:
		m_strErrorMsg = _T("");
		break;
	case LAY_XML_CL_ERROR:
		m_strErrorMsg =  L"ʧ��";
		break;
	case XML_CL_UNEXPECTED:
		m_strErrorMsg =  L"�޷�Ԥ֪��ʧ��";
		break;
	case XML_INITXMLDOM_ERROR:
		m_strErrorMsg =  L"��ʼ��XML DOMʧ��";
		break;
	case XML_FILE_CREATE_ERROR:
		m_strErrorMsg =  L"XML�ļ���������";
		break;
	case XML_FILE_OPEN_ERROR:
		m_strErrorMsg =  L"XML�ļ��򿪴���";
		break;
	case XML_FILE_SAVE_ERROR:
		m_strErrorMsg =  L"XML�ļ��������";
		break;
	case XML_ADDCHILDNODE_ERROR:
		m_strErrorMsg =  L"XML�ļ��ӽ�����";
		break;
	default:
		m_strErrorMsg =  L"�޷�Ԥ֪��ʧ��";
		return FALSE;
	}
	
	return TRUE;
}
