//===================================================================================================
// Summary:
//		XML解析
// Date:
//		2012-03-14
// Author:
//		WangShiping(shwang@bplead.com)		
//===================================================================================================

#pragma once

//===================================================================================================

#include "UnicodeString.h"
#include "SVBaseDef.h"

#if defined __ADFXML
// ADFXML Macro
#include "ADFXMLDocument.h"
#include "ADFXMLNode.h"
#else
// XML Macro
#include "ImplXMLDocument.h"
#include "ImplXMLNode.h"
#endif

//===================================================================================================

#if defined __ADFXML
// class CADFXMLDocument;
// ADFXML Macro
#define SVCLXMLNodePtr DOMNode*
#define SVCLXMLNode CADFXMLNode
#define SVCLXMLDocument CADFXMLDocument
#else
// class CBpXMLDocument;
// XML Macro
#define SVCLXMLNodePtr MSXML2::IXMLDOMNodePtr
#define SVCLXMLNode CBpXMLNode
#define SVCLXMLDocument CBpXMLDocument
#endif

//===================================================================================================

// 工序XML解析
class CSVCLXMLParse
{
public:
	CSVCLXMLParse();
	virtual ~CSVCLXMLParse();

public:
	virtual IKS_BOOL Create();
	virtual IKS_BOOL Release();

public:
	virtual IKS_BOOL Init();
	virtual IKS_BOOL Uninit();

public:

protected:
	// 设置下属数值
	IKS_BOOL SetNodeSubValue(SVCLXMLNodePtr pNode, const CUnicodeString &strName, const CUnicodeString &strValue);
	// 获取下属数值
	IKS_BOOL GetNodeSubValue(const SVCLXMLNodePtr pNode, int nChildIndex, CUnicodeString &strValue);
	// 获取下属数值
	IKS_BOOL GetNodeSubValue(const SVCLXMLNodePtr pNode, const CUnicodeString &strName, CUnicodeString &strValue);
	// 设置节点属性数值
	IKS_BOOL SetNodeAttributeValue(SVCLXMLNodePtr pNode, const CUnicodeString &strName, const CUnicodeString &strValue);
	// 获取节点属性数值
	IKS_BOOL GetNodeAttributeValue(const SVCLXMLNodePtr pNode, int nChildIndex, CUnicodeString &strValue);
	// 获取节点属性数值
	IKS_BOOL GetNodeAttributeValue(const SVCLXMLNodePtr pNode, const CUnicodeString &strName, CUnicodeString &strValue);

	// 设置节点的矩阵数值
	IKS_BOOL SetNodeMatrixValue(SVCLXMLNodePtr pNode, const CUnicodeString &strName, const BPBASEMATRIX &matrix);
	// 获取节点的矩阵数值
	IKS_BOOL GetNodeMatrixValue(const SVCLXMLNodePtr pNode, const CUnicodeString &strName, BPBASEMATRIX &matrix);

	// 设置节点的三维向量数值
	IKS_BOOL SetNodeVec3Value(SVCLXMLNodePtr pNode, const CUnicodeString &strName, const BPBASEFLOAT3 &vValue);
	// 设置节点的三维向量数值
	IKS_BOOL SetNodeVec3Value(SVCLXMLNodePtr pNode, const CUnicodeString &strName, const SVBASEDOUBLE3 &vValue);
	// 设置节点的四维向量数值
	IKS_BOOL SetNodeVec4Value(SVCLXMLNodePtr pNode, const CUnicodeString &strName, const BPBASEFLOAT4 &vValue);
	// 设置节点的四维向量数值
	IKS_BOOL SetNodeVec4Value(SVCLXMLNodePtr pNode, const CUnicodeString &strName, const SVBASEDOUBLE4 &vValue);
	// 获取节点的三维向量数值
	IKS_BOOL GetNodeVec3Value(const SVCLXMLNodePtr pNode, const CUnicodeString &strName, BPBASEFLOAT3 &vValue);
	// 获取节点的三维向量数值
	IKS_BOOL GetNodeVec3Value(const SVCLXMLNodePtr pNode, const CUnicodeString &strName, SVBASEDOUBLE3 &vValue);
	// 获取节点的四维向量数值
	IKS_BOOL GetNodeVec4Value(const SVCLXMLNodePtr pNode, const CUnicodeString &strName, BPBASEFLOAT4 &vValue);
	// 获取节点的四维向量数值
	IKS_BOOL GetNodeVec4Value(const SVCLXMLNodePtr pNode, const CUnicodeString &strName, SVBASEDOUBLE4 &vValue);

protected:
	int SVCLXMLNODE_SetText(SVCLXMLNodePtr pDOMNode, const wchar_t *szText);
	int SVCLXMLNODE_GetText(const SVCLXMLNodePtr pDOMNode, CUnicodeString &strNodeText);

	int SVCLXMLNODE_GetName(const SVCLXMLNodePtr pDOMNode, CUnicodeString &strNodeName);

	int SVCLXMLNODE_SetAttribute(SVCLXMLNodePtr pDOMNode, const CUnicodeString &strAttrName, const CUnicodeString &strAttrValue);
	int SVCLXMLNODE_GetAttributeByIndex(const SVCLXMLNodePtr pDOMNode, int nIndex, CUnicodeString &strAttributeValue);
	int SVCLXMLNODE_GetAttributeByName(const SVCLXMLNodePtr pDOMNode, const CUnicodeString &strAttributeName, CUnicodeString &strAttributeValue);
	int SVCLXMLNODE_GetAttributeCount(const SVCLXMLNodePtr pDOMNode);

	SVCLXMLNodePtr SVCLXMLNODE_GetElementChildByIndex(const SVCLXMLNodePtr pDOMNode, int nIndex);
	SVCLXMLNodePtr SVCLXMLNODE_GetElementChildByName(const SVCLXMLNodePtr pDOMNode, const wchar_t *szChildNodeName, int nIndex = 1);
	int SVCLXMLNODE_GetElementCount(const SVCLXMLNodePtr pDOMNode);

	SVCLXMLNodePtr SVCLXMLNODE_AppendNewElementChild(SVCLXMLNodePtr pDOMNode, const wchar_t *szElementName);

protected:
	SVCLXMLDocument *m_pXMLDocument;
	CUnicodeString m_strTextTemp;
};

//===================================================================================================
