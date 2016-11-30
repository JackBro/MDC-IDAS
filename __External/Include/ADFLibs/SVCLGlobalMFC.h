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
// 以下为宏定义


// 删除指针
#ifndef SAFE_DELETE_POINTER
#define SAFE_DELETE_POINTER(p) \
{ \
	if (NULL != p) \
	delete p; \
	p = NULL; \
}
#endif

// 删除数组
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) \
{ \
	if (NULL != p) \
	delete[] p; \
	p = NULL; \
}
#endif

//===================================================================================================

// 通过路径获取文件名(包含文件名和扩展名,不包含所在文件夹的路径;可输入非全路径)
CString GetFileNameByPath(const CString& strFullPath);
CUnicodeString GetFileNameByPathEx(const CUnicodeString& strFullPath);
// 获取文件名,不包含扩展名
CString GetFileNameNoExtByPath(const CString& strFullPath);
CUnicodeString GetFileNameNoExtByPathEx(const CUnicodeString& strFullPath);
// 通过路径获取文件所在目录(包括磁盘分区名drive和目录dir;可输入非全路径)
CString GetDirectoryByPath(const CString& strFullPath);
CUnicodeString GetDirectoryByPathEx(const CUnicodeString& strFullPath);
// 通过路径获取文件扩展名(只包含扩展名,不包含文件名;可输入非全路径)
CString GetFileExtByPath(const CString& strFullPath);
CUnicodeString GetFileExtByPathEx(const CUnicodeString& strFullPath);
// 通过全路径获取父目录
CUnicodeString GetParentDirectoryByPath(const CUnicodeString& strFullPath);
// 规范化路径字符串
void NormalizePathString(const CUnicodeString& strPathIn, CUnicodeString& strPathOut);
// 比较两个路径是否相同
IKS_BOOL IsPathEqual(const CUnicodeString& strPath1, const CUnicodeString& strPath2);
// 判断文件是否存在。
IKS_BOOL IsFileExist(LPCTSTR pszFileName);
// 判断文件是否被打开。
IKS_BOOL IsFileOpened(LPCTSTR pszFileName);
// 安全删除文件。
void SafeDeleteFile(LPCTSTR pszFileName);
// 检查是否存在指定的目录
IKS_BOOL IsFolderExist(LPCTSTR pszFolderName);
// 创建目录
IKS_BOOL RecursiveCreateDirectory(LPCTSTR szPath);
// 删除指定目录下的文件和文件夹
IKS_BOOL DeleteDirectoryFiles(LPCTSTR pszFolderName);
IKS_BOOL DeleteDirectoryFiles(const CUnicodeString &strFolderName);
// 删除指定目录下的文件(不清除文件夹)
IKS_BOOL DeleteFilesOfDirectory(const CUnicodeString &strFolderName);
// 重命名文件或文件夹
IKS_BOOL RenameFileOrDir(CUnicodeString strSrcPath, CUnicodeString strDstPath);
// 获取一个临时文件名。
IKS_BOOL GetTempFile(CString& strTempFileName, const CString &strExt = _T("tmp"));
IKS_BOOL GetTempFileEx(CUnicodeString& strTempFileName, const CUnicodeString &strExt = L"tmp");
// 获取主程序所在路径。
void GetMainModulePath(CString& strPath, void* hModule);
void GetMainModulePathEx(CUnicodeString& strPath, void* hModule);
void GetGlbMainModulePath(CString& strPath, void* hModule);
void GetGlbMainModulePathEx(CUnicodeString& strPath, void* hModule);
// 获取当前日期时间
void GetCurrentDateTime(CUnicodeString &strTime);
// 创建一个空文件
IKS_BOOL CreateEmptyFile(const CUnicodeString &strFile);
// 创建临时文件夹
CUnicodeString CreateTempDirectory();
// 复制一个文件
IKS_BOOL SVCopyFile(const CUnicodeString &strSrcFile, const CUnicodeString &strDstFile);
// 复制一个文件(无论源文件是否已被其他程序打开)
IKS_BOOL SVCopyFileAnyway(const CUnicodeString &strSrcFile, const CUnicodeString &strDstFile);
// 复制一个文件夹及其下所有文件
IKS_BOOL SVCopyDirectoryFiles(const CUnicodeString &strSrcFolderPath, const CUnicodeString &strDstFolderPath);
// 读取一个文件至内存(内存由使用者自行释放)
IKS_BOOL SVReadFileToBuffer(const CUnicodeString &strFilePath, IKS_BYTE **pBuff, int *pSizeInByte);

// 从剪贴板上获得文本内容
IKS_BOOL CopyTextFromClipboard(CUnicodeString &strText);
// 将文本内容复制到剪贴板
IKS_BOOL CopyTextToClipboard(const CUnicodeString &strText);


// 获取屏幕DPI
double GetScreenDPI();

// 分割字符串
void SpanString(const CString strToken, const CString strDelimit, CStringArray &arrText);

// 判断字符是否字母
IKS_BOOL IsLetter(TCHAR ch);
// 判断字符是否数字
IKS_BOOL IsNumber(TCHAR ch);

void CStringToConvertByte(const CString &strSrcText, IKS_BYTE *pDestText, int &nDestLen);
void ConvertByteToCString(const char *pSrcText, CString &strDesText);
void ConvertByteToCString(const IKS_BYTE *pSrcText, CString &strDesText);

void BSTRToCString(BSTR pBFName, wchar_t *szNodeName, int &nLen);
int UTF8ToGB(const char* str, char* pResult);

// 判断是否为虚拟机
bool IsInsideVMWare();

// 获取唯一标识
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
