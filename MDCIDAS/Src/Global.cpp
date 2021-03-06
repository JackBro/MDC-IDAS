//===================================================================================================
// Summary:
//		内部使用的公共函数
// Date:
//		2010-12-08
// Author:
//		
//===================================================================================================

#include "stdafx.h"
#include "Global.h"
#include "MDCIDAS.h"

//===================================================================================================

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//===================================================================================================

SVDOUBLE3 Double3ToSVDouble3(double d[3])
{
	SVDOUBLE3 sv;
	memcpy_s(&sv.x, sizeof(double)*3, d, sizeof(double)*3);
	return sv;
}

// 得到列表控件的选择项目
void GetListSelectedItems(CListCtrl &listCtrl, vector<int> &arrItems)
{
	arrItems.clear();
	POSITION pos = listCtrl.GetFirstSelectedItemPosition();
	while (pos)
	{
		int nItem = listCtrl.GetNextSelectedItem(pos);
		arrItems.push_back(nItem);
	}
}

// 按关键字把字符串拆分
BOOL CStringToCStringArray(const CString &str, CStringArray &arr, const CString &strKeyword)
{
	if (str.IsEmpty())
		return FALSE;

	CString strSub = str;
	arr.RemoveAll();
	int nFind = -1;
	CString strTemp;
	while (!strSub.IsEmpty())
	{
		nFind = strSub.Find(strKeyword);
		if (nFind >= 0)
		{
			strTemp = strSub.Left(nFind);
			if (!strTemp.IsEmpty())
				arr.Add(strTemp);
			strSub = strSub.Mid(nFind+1);
		}
		else
		{
			arr.Add(strSub);
			break;
		}
	}

	return TRUE;
}

// 按关键字把字符串组合
BOOL CStringArrayToCString(const CStringArray &arr, CString &str, const CString &strKeyword)
{
	str = L"";
	if (arr.IsEmpty())
		return FALSE;
	str += arr[0];
	for (int i=1; i<arr.GetSize(); i++)
	{
		str += strKeyword;
		str += arr[i];
	}

	return TRUE;
}

//===================================================================================================

// 获取UDF文件夹路径
CString GetUDFFolderPath()
{
	CString strPath = _T("");
	GetMainModulePath(strPath, (HMODULE)theApp.m_hInstance);
	strPath += _T("\\UDF\\");

	return strPath;
}

// 获取Template文件夹路径
CString GetTemplateFolderPath()
{
	CString strPath = _T("");
	GetMainModulePath(strPath, (HMODULE)theApp.m_hInstance);
	strPath += _T("\\Template\\");

	return strPath;
}

// 获取电缆配置文件路径
CString GetCableConfigPath()
{
	CString strPath = _T("");
	GetMainModulePath(strPath, (HMODULE)theApp.m_hInstance);
	strPath += _T("\\CableConfig.ini");

	return strPath;
}

//===================================================================================================
