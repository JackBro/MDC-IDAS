//===================================================================================================
// Summary:
//		�ڲ�ʹ�õĹ�������
// Date:
//		2010-12-08
// Author:
//		
//===================================================================================================

#ifndef __Global_h__
#define __Global_h__

//===================================================================================================

#include "BaseMacro.h"
#include "SVCLMath.h"
// #include "SVCLGlobal.h"
#include "SVGlobalTools.h"
#include "SVCLGlobalMFC.h"
#include "SVCLXMLParse.h"
#include "ExcelOperatorAPI.h"
#include "WordControlAPI.h"
#include "ConstantValue.h"

using namespace IKS_MATH;

//===================================================================================================

SVDOUBLE3 Double3ToSVDouble3(double d[3]);

// �õ��б�ؼ���ѡ����Ŀ
void GetListSelectedItems(CListCtrl &listCtrl, vector<int> &arrItems);

// ���ؼ��ְ��ַ������
BOOL CStringToCStringArray(const CString &str, CStringArray &arr, const CString &strKeyword);

// ���ؼ��ְ��ַ������
BOOL CStringArrayToCString(const CStringArray &arr, CString &str, const CString &strKeyword);

//===================================================================================================

#endif