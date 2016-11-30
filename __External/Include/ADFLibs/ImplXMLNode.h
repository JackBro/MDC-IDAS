//===================================================================================================
// Summary:
//		XML节点对象
// Usage:
//		XML节点对象，提供XML节点的属性、子节点等内容的操作。
// Remarks:
//		目前表示Element节点，注意返回指针的释放
//		释放CBpXMLNode指针、CBpXMLDocument指针并不会影响DOM树的结构
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
	// 		获取当前结点的父结点
	// Parameters:
	// 		[out] nodeParent - 当前结点的父结点
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetParent(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		获取当前节点的名字
	// Parameters:
	// 		[out] szNodeName - 节点名字,内容由调用者申请
	//		[in/out] nLen - 节点名字的长度,返回值为实际长度
	//------------------------------------------------------------------------------------------------
	static int GetName(MSXML2::IXMLDOMNodePtr pDOMNode, CUnicodeString &strNodeName);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		获取当前节点及其子节点的内容
	// Parameters:
	// 		[out] szNodeText - 节点内容,内容由调用者申请
	//		[in/out] nLen - 节点内容的长度,返回值为实际长度
	//------------------------------------------------------------------------------------------------
	static int GetText(MSXML2::IXMLDOMNodePtr pDOMNode, CUnicodeString &strNodeText);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		获取当前节点的所有Element子节点个数
	// Returns:
	//		所有Element子节点个数。
	//------------------------------------------------------------------------------------------------
	static int GetElementCount(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		获取当前节点的指定位置的Element子节点
	// Parameters:
	// 		[in]nIndex - 指定的位置，从1开始。
	// Returns:
	//		返回指定位置的Element子节点，需调研者使用DestroyXMLNode释放内存。	
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetElementChildByIndex(MSXML2::IXMLDOMNodePtr pDOMNode, int nIndex);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		获取当前节点的第一个Element子节点
	// Returns:
	//		返回第一个Element子节点，需调研者使用DestroyXMLNode释放内存。	
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetFirstElementChild(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		获取当前节点的最后一个Element子节点
	// Returns:
	//		返回最后一个Element子节点，需调研者使用DestroyXMLNode释放内存。
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetLastElementChild(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		获取当前结点，指定名称的第index个Element子结点
	// Parameters:
	// 		[in] strChildNodeName - 子节点的名字
	//		[in] nIndex - 子节点在所有同名节点中的顺序
	// Returns:
	//		返回第index个Element子结点，需调研者使用DestroyXMLNode释放内存。
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetElementChildByName(MSXML2::IXMLDOMNodePtr pDOMNode, const wchar_t *szChildNodeName, int nIndex = 1);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		获取当前结点的前一个Element兄弟结点
	// Returns:
	//		返回前一个Element兄弟结点，需调研者使用DestroyXMLNode释放内存。
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetPreviousElementSibling(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		获取当前结点的下一个Element兄弟结点
	// Returns:
	//		返回下一个Element兄弟结点，需调研者使用DestroyXMLNode释放内存。
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr GetNextElementSibling(MSXML2::IXMLDOMNodePtr pDOMNode);	

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		获取当前结点的属性的个数
	//------------------------------------------------------------------------------------------------
	static int GetAttributeCount(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		获取当前结点的指定属性的值			
	// Parameters:
	// 		[in] strAttributeName - 属性名字
	//		[out] strAttributValue - 属性的内容
	//------------------------------------------------------------------------------------------------
	static int GetAttributeByName(MSXML2::IXMLDOMNodePtr pDOMNode, const wchar_t *szAttributeName, wchar_t *szAttributeValue, int &nValueLen);
	static int GetAttributeByName(MSXML2::IXMLDOMNodePtr pDOMNode, const CUnicodeString &strAttributeName, CUnicodeString &strAttributeValue);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		获取当前结点的指定序号的属性的名称
	// Parameters:
	// 		[in] nIndex - 属性的序列
	//		[out] strAttributeName - 属性的值
	//------------------------------------------------------------------------------------------------
	static int GetAttributeByIndex(MSXML2::IXMLDOMNodePtr pDOMNode, int nIndex, wchar_t *szAttributeValue, int &nValueLen);
	static int GetAttributeByIndex(MSXML2::IXMLDOMNodePtr pDOMNode, int nIndex, CUnicodeString &strAttributeValue);

public:
	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		判断当前节点是否存在子结点
	//------------------------------------------------------------------------------------------------
	static bool HasChildNodes(MSXML2::IXMLDOMNodePtr pDOMNode);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		判断当前节点是否存在Element子结点
	//------------------------------------------------------------------------------------------------
	static bool HasElementChildNodes(MSXML2::IXMLDOMNodePtr pDOMNode);

public:
	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		根据给定的名字，创建Element节点，并将其附加为当前节点的子节点
	// Parameters:
	// 		[In] strElementName - 新增的Element节点名
	// Returns:
	//		返回新创建的节点，需调研者使用DestroyXMLNode释放内存
	//------------------------------------------------------------------------------------------------
	static MSXML2::IXMLDOMNodePtr AppendNewElementChild(MSXML2::IXMLDOMNodePtr pDOMNode, const wchar_t *szElementName);

	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		删除子结点
	// Parameters:
	// 		[In] nodeChild - 被删除的节点
	// Remarks:
	//		将nodeChild的m_pDOMNode指针指向的DOMNode从树上Romove
	//		并将m_pDOMNode释放（release）
	//------------------------------------------------------------------------------------------------
	static int DeleteChild(MSXML2::IXMLDOMNodePtr pDOMNode, MSXML2::IXMLDOMNodePtr pNodeChild);

public:
	//------------------------------------------------------------------------------------------------
	// Summary:
	// 		清除节点的所有子节点，并将strText作为文本节点添加为本节点的子节点
	// Parameters:
	// 		[in] strTextContent - 待添加的文本
	//------------------------------------------------------------------------------------------------
	static int SetText(MSXML2::IXMLDOMNodePtr pDOMNode, const wchar_t *szText);

	//------------------------------------------------------------------------------------------------
	//	Summary:
	//		设置属性值
	//	Parameters:
	//		[in] strAttrName - 属性名称
	//		[in] strAttrValue - 属性值
	//------------------------------------------------------------------------------------------------
	static int SetAttribute(MSXML2::IXMLDOMNodePtr pDOMNode, const wchar_t *szAttrName, const wchar_t *szAttrValue);
};

//===================================================================================================

#endif // #ifndef__Bp_XMLCodec_ImplXMLNode__

