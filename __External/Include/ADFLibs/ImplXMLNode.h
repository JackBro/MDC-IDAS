//===================================================================================================
// Summary:
//		XML�ڵ����
// Usage:
//		XML�ڵ�����ṩXML�ڵ�����ԡ��ӽڵ�����ݵĲ�����
// Remarks:
//		Ŀǰ��ʾElement�ڵ㣬ע�ⷵ��ָ����ͷ�
//		�ͷ�CBpXMLNodeָ�롢CBpXMLDocumentָ�벢����Ӱ��DOM���Ľṹ
// Date:
//		2008-12-3
// Author:
//		Yang Xuefeng (yang_xuefeng@founder.com.cn)
//===================================================================================================

#ifndef	__Bp_XMLCodec_ImplXMLNode__
#define __Bp_XMLCodec_ImplXMLNode__

//===================================================================================================

#include "ImplXMLDocument.h"
#include "UnicodeString.h"

//===================================================================================================

class CBpXMLNode
{
public:
	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ���ĸ����
	// Parameters:
	// 		[out] nodeParent - ��ǰ���ĸ����
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetParent(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ�ڵ������
	// Parameters:
	// 		[out] szNodeName - �ڵ�����,�����ɵ���������
	//		[in/out] nLen - �ڵ����ֵĳ���,����ֵΪʵ�ʳ���
	//------------------------------------------------------------------------------------------------
	static int GetName(MSXML2::IXMLDOMNodePtr pDOMNode, CUnicodeString &strNodeName);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ�ڵ㼰���ӽڵ������
	// Parameters:
	// 		[out] szNodeText - �ڵ�����,�����ɵ���������
	//		[in/out] nLen - �ڵ����ݵĳ���,����ֵΪʵ�ʳ���
	//------------------------------------------------------------------------------------------------
	static int GetText(MSXML2::IXMLDOMNodePtr pDOMNode, CUnicodeString &strNodeText);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ�ڵ������Element�ӽڵ����
	// Returns:
	//		����Element�ӽڵ������
	//------------------------------------------------------------------------------------------------
	static int GetElementCount(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ�ڵ��ָ��λ�õ�Element�ӽڵ�
	// Parameters:
	// 		[in]nIndex - ָ����λ�ã���1��ʼ��
	// Returns:
	//		����ָ��λ�õ�Element�ӽڵ㣬�������ʹ��DestroyXMLNode�ͷ��ڴ档	
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetElementChildByIndex(MSXML2::IXMLDOMNodePtr pDOMNode, int nIndex);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ�ڵ�ĵ�һ��Element�ӽڵ�
	// Returns:
	//		���ص�һ��Element�ӽڵ㣬�������ʹ��DestroyXMLNode�ͷ��ڴ档	
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetFirstElementChild(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ�ڵ�����һ��Element�ӽڵ�
	// Returns:
	//		�������һ��Element�ӽڵ㣬�������ʹ��DestroyXMLNode�ͷ��ڴ档
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetLastElementChild(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ��㣬ָ�����Ƶĵ�index��Element�ӽ��
	// Parameters:
	// 		[in] strChildNodeName - �ӽڵ������
	//		[in] nIndex - �ӽڵ�������ͬ���ڵ��е�˳��
	// Returns:
	//		���ص�index��Element�ӽ�㣬�������ʹ��DestroyXMLNode�ͷ��ڴ档
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetElementChildByName(MSXML2::IXMLDOMNodePtr pDOMNode, const wchar_t *szChildNodeName, int nIndex = 1);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ����ǰһ��Element�ֵܽ��
	// Returns:
	//		����ǰһ��Element�ֵܽ�㣬�������ʹ��DestroyXMLNode�ͷ��ڴ档
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetPreviousElementSibling(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ������һ��Element�ֵܽ��
	// Returns:
	//		������һ��Element�ֵܽ�㣬�������ʹ��DestroyXMLNode�ͷ��ڴ档
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetNextElementSibling(MSXML2::IXMLDOMNodePtr pDOMNode);	

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ�������Եĸ���
	//------------------------------------------------------------------------------------------------
	static int GetAttributeCount(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ����ָ�����Ե�ֵ			
	// Parameters:
	// 		[in] strAttributeName - ��������
	//		[out] strAttributValue - ���Ե�����
	//------------------------------------------------------------------------------------------------
	static int GetAttributeByName(MSXML2::IXMLDOMNodePtr pDOMNode, const wchar_t *szAttributeName, wchar_t *szAttributeValue, int &nValueLen);
	static int GetAttributeByName(MSXML2::IXMLDOMNodePtr pDOMNode, const CUnicodeString &strAttributeName, CUnicodeString &strAttributeValue);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		��ȡ��ǰ����ָ����ŵ����Ե�����
	// Parameters:
	// 		[in] nIndex - ���Ե�����
	//		[out] strAttributeName - ���Ե�ֵ
	//------------------------------------------------------------------------------------------------
	static int GetAttributeByIndex(MSXML2::IXMLDOMNodePtr pDOMNode, int nIndex, wchar_t *szAttributeValue, int &nValueLen);
	static int GetAttributeByIndex(MSXML2::IXMLDOMNodePtr pDOMNode, int nIndex, CUnicodeString &strAttributeValue);

public:
	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		�жϵ�ǰ�ڵ��Ƿ�����ӽ��
	//------------------------------------------------------------------------------------------------
	static bool HasChildNodes(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		�жϵ�ǰ�ڵ��Ƿ����Element�ӽ��
	//------------------------------------------------------------------------------------------------
	static bool HasElementChildNodes(MSXML2::IXMLDOMNodePtr pDOMNode);

public:
	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		���ݸ��������֣�����Element�ڵ㣬�����丽��Ϊ��ǰ�ڵ���ӽڵ�
	// Parameters:
	// 		[In] strElementName - ������Element�ڵ���
	// Returns:
	//		�����´����Ľڵ㣬�������ʹ��DestroyXMLNode�ͷ��ڴ�
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr AppendNewElementChild(MSXML2::IXMLDOMNodePtr pDOMNode, const wchar_t *szElementName);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		ɾ���ӽ��
	// Parameters:
	// 		[In] nodeChild - ��ɾ���Ľڵ�
	// Remarks:
	//		��nodeChild��m_pDOMNodeָ��ָ���DOMNode������Romove
	//		����m_pDOMNode�ͷţ�release��
	//------------------------------------------------------------------------------------------------
	static int DeleteChild(MSXML2::IXMLDOMNodePtr pDOMNode, MSXML2::IXMLDOMNodePtr pNodeChild);

public:
	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		����ڵ�������ӽڵ㣬����strText��Ϊ�ı��ڵ����Ϊ���ڵ���ӽڵ�
	// Parameters:
	// 		[in] strTextContent - ����ӵ��ı�
	//------------------------------------------------------------------------------------------------
	static int SetText(MSXML2::IXMLDOMNodePtr pDOMNode, const wchar_t *szText);

	//------------------------------------------------------------------------------------------------
	//	Summary:
	//		��������ֵ
	//	Parameters:
	//		[in] strAttrName - ��������
	//		[in] strAttrValue - ����ֵ
	//------------------------------------------------------------------------------------------------
	static int SetAttribute(MSXML2::IXMLDOMNodePtr pDOMNode, const wchar_t *szAttrName, const wchar_t *szAttrValue);
};

//===================================================================================================

#endif // #ifndef__Bp_XMLCodec_ImplXMLNode__

