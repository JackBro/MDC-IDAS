//===================================================================================================

#pragma once
#include "afxcmn.h"

//===================================================================================================

class CDlgChild1 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild1)

public:
	CDlgChild1(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild1();
	enum { IDD = IDD_DlG_Child1 };

	CString m_strPath;
	CString m_strName;
	CListCtrl m_listInfo;

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

};
