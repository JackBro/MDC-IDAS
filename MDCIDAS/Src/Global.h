//===================================================================================================
// Summary:
//		内部使用的公共函数
// Date:
//		2010-12-08
// Author:
//		
//===================================================================================================

#ifndef __Global_h__
#define __Global_h__

//===================================================================================================


//===================================================================================================

SVDOUBLE3 Double3ToSVDouble3(double d[3]);

// 得到列表控件的选择项目
void GetListSelectedItems(CListCtrl &listCtrl, vector<int> &arrItems);

// 按关键字把字符串拆分
BOOL CStringToCStringArray(const CString &str, CStringArray &arr, const CString &strKeyword);

// 按关键字把字符串组合
BOOL CStringArrayToCString(const CStringArray &arr, CString &str, const CString &strKeyword);

//===================================================================================================

#endif