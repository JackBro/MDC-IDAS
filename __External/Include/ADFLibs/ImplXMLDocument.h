//===================================================================================================
// Summary:
//		XML的document节点
// Usage:
//		得到CBpXMLDocument指针后可进行XPath操作、保存XML操作、创建节点等
// Remarks:
//		注意返回指针的释放
//		释放CBpXMLNode指针、CBpXMLDocument指针并不会影响DOM树的结构
// Date:
//		2008-12-3
// Author:
//		Yang Xuefeng (yang_xuefeng@founder.com.cn)
//===================================================================================================

#ifndef __Bp_XMLCodec_ImplXMLDocument__
#define __Bp_XMLCodec_ImplXMLDocument__

//===================================================================================================

#import "msxml3.dll"
using namespace MSXML2;

//===================================================================================================

// 错误类型定义
#define XML_OK						0					// 成功
#define XML_ERROR					1					// 失败
#define XML_CL_UNEXPECTED			2					// 无法预知的失败
#define XML_INITXMLDOM_ERROR		100					// 初始化XML DOM失败
#define XML_FILE_CREATE_ERROR		101					// XML文件创建错误
#define XML_FILE_OPEN_ERROR			102					// XML文件打开错误
#define XML_FILE_SAVE_ERROR			103					// XML文件保存错误
#define XML_ADDNODE_ERROR			104					// XML文件加结点错误
#define XML_ADDCHILDNODE_ERROR		105					// XML文件加子结点错误

// 最大字符长度
#define BP_MAX_FILELEN		256;

//===================================================================================================

class CBpXMLDocument 
{
public:
	CBpXMLDocument();
	~CBpXMLDocument();

public:
	BOOL Init();
	void UnInit();

public:
	 bool OpenXMLForDocument(const BYTE *pBuffer, int nLen);
	 bool OpenXMLForDocument(const wchar_t *szFilePath);
	 bool CreateDocument(const wchar_t *szRootElementName);	
	 bool SaveXML(const wchar_t *szFilePath) const;
	 bool Release();

public:
	 MSXML2::IXMLDOMNodePtr CreateElementNode(const wchar_t *szElementNodeName);
	 MSXML2::IXMLDOMNodePtr CreateTextNode(const wchar_t *szText);
	 MSXML2::IXMLDOMNodePtr GetRootElement();

public:
	 int GetLastError() const { return m_nLastError; }

private:
	// XML文档对象指针
	MSXML2::IXMLDOMDocumentPtr m_pDOMDocument;	
	int m_nLastError;
	CString m_strFileName;
};

//===================================================================================================

#endif	// #ifndef	__Bp_XMLCodec_ImplXMLDocument__