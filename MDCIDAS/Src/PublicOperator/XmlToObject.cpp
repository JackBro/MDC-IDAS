//===================================================================================================
//  Description		:   XML格式转换为注释信息
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

// 初始化
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

// 卸载XML Dom
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

	// 清空注释对象
	for (int i = 0; i < m_arrObject.GetSize(); i++)
	{
		if (m_arrObject[i] != NULL)
			delete m_arrObject[i];
	}
	m_arrObject.RemoveAll();
}

// 打开XML文件
BOOL CXmlToObject::OpenFile(LPCTSTR strFileName)
{
	if (!m_bInitXMLDOM)
		return FALSE;

	// 清空注释对象
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

// 读取注释信息
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
	// 版本号
	GetAttribute(pRootNode, IDS_LAYOUT_VERSION, strNodeAttr);
	m_wVersion = (WORD)_ttoi(strNodeAttr);
	// 宽度和高度
	GetAttribute(pRootNode, IDS_LAYOUT_WIDTH, strNodeAttr);
	m_dWidth = _wtof(strNodeAttr);
	GetAttribute(pRootNode, IDS_LAYOUT_HEIGHT, strNodeAttr);
	m_dHeight = _wtof(strNodeAttr);

	GetAttribute(pRootNode, IDS_LAYOUT_LEFT, strNodeAttr);
	m_dLeft = _wtof(strNodeAttr);
	GetAttribute(pRootNode, IDS_LAYOUT_TOP, strNodeAttr);
	m_dTop = _wtof(strNodeAttr);

	// 文档名字
	GetAttribute(pRootNode, IDS_ANN_NAME, m_strName);

	// 文档注解
	GetAttribute(pRootNode, IDS_ANN_DESC, m_strNote);

	pNodeList = pRootNode->GetchildNodes();
	if (pNodeList == NULL)
		return FALSE;
	pNodeList->get_length(&nNodeCount);

	// 读取注释信息
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

// 从xml中读取基本信息
BOOL CXmlToObject::ReadBaseInfoFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *pAnnObj)
{
	if (pAnnObj == NULL)
		return FALSE;

	// 注释的类型
	CString strAttributeValue;
	GetAttribute(pNode, IDS_ANN_TYPE, strAttributeValue);
	pAnnObj->m_nType = _ttoi(strAttributeValue);

	// 线的类型
	GetAttribute(pNode, IDS_ANN_LINESTYLE, strAttributeValue);
	pAnnObj->m_nLineStyle = (UINT)_ttoi(strAttributeValue);

	// 线的宽度
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
		
		// 颜色
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
		else if (strNodeName == IDS_ANN_POS) 	// 位置
		{
			GetAttribute(pChildNode, IDS_ANN_POS_X, strAttributeValue);
			pAnnObj->m_ptCenter.x = _wtof(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_POS_Y, strAttributeValue);
			pAnnObj->m_ptCenter.y = _wtof(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_POS_W, strAttributeValue);
			pAnnObj->m_dWidth= _wtof(strAttributeValue);

			GetAttribute(pChildNode, IDS_ANN_POS_H, strAttributeValue);
			pAnnObj->m_dHeight = _wtof(strAttributeValue);

			// 角度
			GetAttribute(pChildNode, IDS_ANN_POS_A, strAttributeValue);
			pAnnObj->m_dAngle = _wtof(strAttributeValue);
		}		
		else if (strNodeName == IDS_ANN_NAME) // 位置
		{
			pAnnObj->m_strName = GetNodeText(pChildNode);
		}
		else if (strNodeName == IDS_ANN_DESC) // 注释
		{
			pAnnObj->m_strDesc = GetNodeText(pChildNode);
		}
	}

	return TRUE;
}

// 从xml中读取矩形信息
BOOL CXmlToObject::ReadAnnRectangleFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *&pAnnObj)
{
	pAnnObj = new CLayRectangleObj;

	CLayRectangleObj *pRecObj = (CLayRectangleObj *)pAnnObj;

	// 读取基本信息
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

		// 颜色
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

// 从xml中读取符号信息
BOOL CXmlToObject::ReadAnnSymbolFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *&pAnnObj)
{
	pAnnObj = new CLaySymbolObj;

	CLaySymbolObj *pSymbolObj = (CLaySymbolObj *)pAnnObj;

	// 读取基本信息
	ReadBaseInfoFromXml(pNode, pAnnObj);

	CString strAttributeValue;

	// 门的方向
	GetAttribute(pNode, IDS_DOOR_DIRECTION, strAttributeValue);
	pSymbolObj->m_nDoorDirection = _ttoi(strAttributeValue);

	// 子类型
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

		// 颜色
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

// 从xml中读取椭圆信息
BOOL CXmlToObject::ReadAnnEllipseFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *&pAnnObj)
{
	pAnnObj = new CLayEllipseObj;

	CLayEllipseObj *pEllipseObj = (CLayEllipseObj *)pAnnObj;

	// 读取基本信息
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

		// 颜色
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

// 从xml中读取直线信息
BOOL CXmlToObject::ReadAnnLineFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *&pAnnObj)
{
	pAnnObj = new CLayLineObj;

	CLayLineObj *pLineObj = (CLayLineObj *)pAnnObj;

	// 读取基本信息
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

		// 点的坐标
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

// 从xml中读取文字信息
BOOL CXmlToObject::ReadAnnTextFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *&pAnnObj)
{
	pAnnObj = new CLayTextObject;

	CLayTextObject *pTextObj = (CLayTextObject *)pAnnObj;

	// 读取基本信息
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
		// 文字信息
		else if (strNodeName == L"TextInfo")
		{	
			// 版本号
			GetAttribute(pChildNode, L"Version", strAttributeValue);
			pTextObj->m_textInfo.wVersion = (WORD)_ttoi(strAttributeValue);
			
			// 字体名称
			GetAttribute(pChildNode, L"FontName", strAttributeValue);
			wcscpy_s(pTextObj->m_textInfo.szFontName, sizeof(pTextObj->m_textInfo.szFontName)/sizeof(wchar_t), strAttributeValue);

			// 文字的左上点坐标, 采用逻辑坐标。
			GetAttribute(pChildNode, L"X", strAttributeValue);
			pTextObj->m_textInfo.ptLeftTop.x = _ttoi(strAttributeValue);
			GetAttribute(pChildNode, L"Y", strAttributeValue);
			pTextObj->m_textInfo.ptLeftTop.y = _ttoi(strAttributeValue);
		
			// 字体的高度
			GetAttribute(pChildNode, L"Height", strAttributeValue);
			pTextObj->m_textInfo.lfHeight = _ttoi(strAttributeValue);

			// 文字外接矩形左上角点为基点，轴为正方向，从0度到360度
			GetAttribute(pChildNode, L"Height", strAttributeValue);
			pTextObj->m_textInfo.nAngle = _ttoi(strAttributeValue);

			// 字体加粗
			GetAttribute(pChildNode, L"Bold", strAttributeValue);
			pTextObj->m_textInfo.bBold = (BYTE)_ttoi(strAttributeValue);

			// 字体斜体
			GetAttribute(pChildNode, L"Italic", strAttributeValue);
			pTextObj->m_textInfo.bItalic = (BYTE)_ttoi(strAttributeValue);

			// 字体下划线
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

				// 文字的颜色
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

// 从xml中读取图像信息
BOOL CXmlToObject::ReadAnnImageFromXml(MSXML2::IXMLDOMNodePtr pNode, CLayObject *&pAnnObj)
{
	pAnnObj = new CLayImageObject;

	// CLayImageObject *pImageObj = (CLayImageObject *)pAnnObj;

	// 读取基本信息
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

// 清除节点的所有子节点，并将strText作为文本节点添加为本节点的子节点
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

//  取得结点文本
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

// 获取结点名称
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

// 设置属性值
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

// 获取当前结点的指定属性的值			
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

// 把BSTR类型的数据转换为CString
CString CXmlToObject::BSTRToCString(BSTR pBFName)
{
	CString strResult = CString(pBFName);
	return strResult;
}

// 获取错误信息
BOOL CXmlToObject::GetErrorMsg(WORD nErrorCode)
{
	switch(nErrorCode)
	{
	case LAY_XML_CL_OK:
		m_strErrorMsg = _T("");
		break;
	case LAY_XML_CL_ERROR:
		m_strErrorMsg =  L"失败";
		break;
	case XML_CL_UNEXPECTED:
		m_strErrorMsg =  L"无法预知的失败";
		break;
	case XML_INITXMLDOM_ERROR:
		m_strErrorMsg =  L"初始化XML DOM失败";
		break;
	case XML_FILE_CREATE_ERROR:
		m_strErrorMsg =  L"XML文件创建错误";
		break;
	case XML_FILE_OPEN_ERROR:
		m_strErrorMsg =  L"XML文件打开错误";
		break;
	case XML_FILE_SAVE_ERROR:
		m_strErrorMsg =  L"XML文件保存错误";
		break;
	case XML_ADDCHILDNODE_ERROR:
		m_strErrorMsg =  L"XML文件加结点错误";
		break;
	default:
		m_strErrorMsg =  L"无法预知的失败";
		return FALSE;
	}
	
	return TRUE;
}
