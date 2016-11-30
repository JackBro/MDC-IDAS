//===================================================================================================
// File:
//		SVCLGlobalMFC.h
// Summary:
//		Provides the Global Method.
// Date:
//		2016-1-18
// Author:
//		WangShiping
//===================================================================================================

#pragma once

#include "UnicodeString.h"
#include "SVBaseDef.h"

//===================================================================================================
// ����Ϊ�궨��


// ɾ��ָ��
#ifndef SAFE_DELETE_POINTER
#define SAFE_DELETE_POINTER(p) \
{ \
	if (NULL != p) \
	delete p; \
	p = NULL; \
}
#endif

// ɾ������
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) \
{ \
	if (NULL != p) \
	delete[] p; \
	p = NULL; \
}
#endif

//===================================================================================================

// ͨ��·����ȡ�ļ���(�����ļ�������չ��,�����������ļ��е�·��;�������ȫ·��)
CString GetFileNameByPath(const CString& strFullPath);
CUnicodeString GetFileNameByPathEx(const CUnicodeString& strFullPath);
// ��ȡ�ļ���,��������չ��
CString GetFileNameNoExtByPath(const CString& strFullPath);
CUnicodeString GetFileNameNoExtByPathEx(const CUnicodeString& strFullPath);
// ͨ��·����ȡ�ļ�����Ŀ¼(�������̷�����drive��Ŀ¼dir;�������ȫ·��)
CString GetDirectoryByPath(const CString& strFullPath);
CUnicodeString GetDirectoryByPathEx(const CUnicodeString& strFullPath);
// ͨ��·����ȡ�ļ���չ��(ֻ������չ��,�������ļ���;�������ȫ·��)
CString GetFileExtByPath(const CString& strFullPath);
CUnicodeString GetFileExtByPathEx(const CUnicodeString& strFullPath);
// ͨ��ȫ·����ȡ��Ŀ¼
CUnicodeString GetParentDirectoryByPath(const CUnicodeString& strFullPath);
// �淶��·���ַ���
void NormalizePathString(const CUnicodeString& strPathIn, CUnicodeString& strPathOut);
// �Ƚ�����·���Ƿ���ͬ
IKS_BOOL IsPathEqual(const CUnicodeString& strPath1, const CUnicodeString& strPath2);
// �ж��ļ��Ƿ���ڡ�
IKS_BOOL IsFileExist(LPCTSTR pszFileName);
// �ж��ļ��Ƿ񱻴򿪡�
IKS_BOOL IsFileOpened(LPCTSTR pszFileName);
// ��ȫɾ���ļ���
void SafeDeleteFile(LPCTSTR pszFileName);
// ����Ƿ����ָ����Ŀ¼
IKS_BOOL IsFolderExist(LPCTSTR pszFolderName);
// ����Ŀ¼
IKS_BOOL RecursiveCreateDirectory(LPCTSTR szPath);
// ɾ��ָ��Ŀ¼�µ��ļ����ļ���
IKS_BOOL DeleteDirectoryFiles(LPCTSTR pszFolderName);
IKS_BOOL DeleteDirectoryFiles(const CUnicodeString &strFolderName);
// ɾ��ָ��Ŀ¼�µ��ļ�(������ļ���)
IKS_BOOL DeleteFilesOfDirectory(const CUnicodeString &strFolderName);
// �������ļ����ļ���
IKS_BOOL RenameFileOrDir(CUnicodeString strSrcPath, CUnicodeString strDstPath);
// ��ȡһ����ʱ�ļ�����
IKS_BOOL GetTempFile(CString& strTempFileName, const CString &strExt = _T("tmp"));
IKS_BOOL GetTempFileEx(CUnicodeString& strTempFileName, const CUnicodeString &strExt = L"tmp");
// ��ȡ����������·����
void GetMainModulePath(CString& strPath, void* hModule);
void GetMainModulePathEx(CUnicodeString& strPath, void* hModule);
void GetGlbMainModulePath(CString& strPath, void* hModule);
void GetGlbMainModulePathEx(CUnicodeString& strPath, void* hModule);
// ��ȡ��ǰ����ʱ��
void GetCurrentDateTime(CUnicodeString &strTime);
// ����һ�����ļ�
IKS_BOOL CreateEmptyFile(const CUnicodeString &strFile);
// ������ʱ�ļ���
CUnicodeString CreateTempDirectory();
// ����һ���ļ�
IKS_BOOL SVCopyFile(const CUnicodeString &strSrcFile, const CUnicodeString &strDstFile);
// ����һ���ļ�(����Դ�ļ��Ƿ��ѱ����������)
IKS_BOOL SVCopyFileAnyway(const CUnicodeString &strSrcFile, const CUnicodeString &strDstFile);
// ����һ���ļ��м����������ļ�
IKS_BOOL SVCopyDirectoryFiles(const CUnicodeString &strSrcFolderPath, const CUnicodeString &strDstFolderPath);
// ��ȡһ���ļ����ڴ�(�ڴ���ʹ���������ͷ�)
IKS_BOOL SVReadFileToBuffer(const CUnicodeString &strFilePath, IKS_BYTE **pBuff, int *pSizeInByte);

// �Ӽ������ϻ���ı�����
IKS_BOOL CopyTextFromClipboard(CUnicodeString &strText);
// ���ı����ݸ��Ƶ�������
IKS_BOOL CopyTextToClipboard(const CUnicodeString &strText);


// ��ȡ��ĻDPI
double GetScreenDPI();

// �ָ��ַ���
void SpanString(const CString strToken, const CString strDelimit, CStringArray &arrText);

// �ж��ַ��Ƿ���ĸ
IKS_BOOL IsLetter(TCHAR ch);
// �ж��ַ��Ƿ�����
IKS_BOOL IsNumber(TCHAR ch);

void CStringToConvertByte(const CString &strSrcText, IKS_BYTE *pDestText, int &nDestLen);
void ConvertByteToCString(const char *pSrcText, CString &strDesText);
void ConvertByteToCString(const IKS_BYTE *pSrcText, CString &strDesText);

void BSTRToCString(BSTR pBFName, wchar_t *szNodeName, int &nLen);
int UTF8ToGB(const char* str, char* pResult);

// �ж��Ƿ�Ϊ�����
bool IsInsideVMWare();

// ��ȡΨһ��ʶ
IKS_BOOL GetUniqueID(CString& strUUID);

//===================================================================================================

class CBpRegKey
{
public:
	CBpRegKey();
	virtual ~CBpRegKey();

protected:
	HKEY m_hKey;

public:
	LONG Open(HKEY hKeyRoot, LPCTSTR pszPath);
	LONG Close();
	LONG DeleteValue(LPCTSTR lpszValue );
	LONG Write(LPCTSTR pszKey, int nVal);
	LONG Write(LPCTSTR pszKey, IKS_DWORD dwVal);
	LONG Write(LPCTSTR pszKey, LPCTSTR pszVal);
	LONG Write(LPCTSTR pszKey, const IKS_BYTE* pData, IKS_DWORD dwLength);
	LONG Read(LPCTSTR pszKey, int& nVal);
	LONG Read(LPCTSTR pszKey, IKS_DWORD& dwVal);
	LONG Read(LPCTSTR pszKey, LPCTSTR strVal);
	LONG Read(LPCTSTR pszKey, CString& strVal);
	LONG Read(LPCTSTR pszKey, CUnicodeString& strVal);
	LONG Read(LPCTSTR pszKey, IKS_BYTE* pData, IKS_DWORD& dwLength);
	LONG Create(HKEY hKeyParent, LPCTSTR lpszKeyName,
		LPTSTR lpszClass = REG_NONE, IKS_DWORD dwOptions = REG_OPTION_NON_VOLATILE,
		REGSAM samDesired = KEY_ALL_ACCESS,
		LPSECURITY_ATTRIBUTES lpSecAttr = NULL,
		LPDWORD lpdwDisposition = NULL);	
	LONG DeleteSubKey(LPCTSTR lpszSubKey);
	LONG SetValue(IKS_DWORD dwValue, LPCTSTR lpszValueName);
	LONG SetValue(LPCTSTR lpszValue, LPCTSTR lpszValueName = NULL);	
};

class CDirDialog
{
public:
	CDirDialog(CWnd* pParentWnd);
	virtual ~CDirDialog() { }

public:
	IKS_BOOL DoBrowse();
	CString GetPath() { return m_strPath; }

private:
	CWnd *m_pParentWnd;
	CString m_strPath;
	CString m_strTitle;
};

//===================================================================================================
