//===================================================================================================

#pragma once
#include "afxcmn.h"

//===================================================================================================

class CDlgChild2 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild2)

public:
	CDlgChild2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild2();
	enum { IDD = IDD_DlG_Child2 };

	CString m_strName;
	CString m_strPath;
	CListCtrl m_listInfo;

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
