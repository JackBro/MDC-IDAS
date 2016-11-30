//===================================================================================================
// Summary:
//		XML��document�ڵ�
// Usage:
//		�õ�CBpXMLDocumentָ���ɽ���XPath����������XML�����������ڵ��
// Remarks:
//		ע�ⷵ��ָ����ͷ�
//		�ͷ�CBpXMLNodeָ�롢CBpXMLDocumentָ�벢����Ӱ��DOM���Ľṹ
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

// �������Ͷ���
#define XML_OK						0					// �ɹ�
#define XML_ERROR					1					// ʧ��
#define XML_CL_UNEXPECTED			2					// �޷�Ԥ֪��ʧ��
#define XML_INITXMLDOM_ERROR		100					// ��ʼ��XML DOMʧ��
#define XML_FILE_CREATE_ERROR		101					// XML�ļ���������
#define XML_FILE_OPEN_ERROR			102					// XML�ļ��򿪴���
#define XML_FILE_SAVE_ERROR			103					// XML�ļ��������
#define XML_ADDNODE_ERROR			104					// XML�ļ��ӽ�����
#define XML_ADDCHILDNODE_ERROR		105					// XML�ļ����ӽ�����

// ����ַ�����
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
	// XML�ĵ�����ָ��
	MSXML2::IXMLDOMDocumentPtr m_pDOMDocument;	
	int m_nLastError;
	CString m_strFileName;
};

//===================================================================================================

#endif	// #ifndef	__Bp_XMLCodec_ImplXMLDocument__