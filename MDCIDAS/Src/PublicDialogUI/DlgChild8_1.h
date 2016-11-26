//===================================================================================================

#pragma once
#include "afxcmn.h"

//===================================================================================================

class CDlgChild8_1 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild8_1)

public:
	CDlgChild8_1(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild8_1();
	enum { IDD = IDD_DlG_Child8_1 };
	CString m_strName;
	CListCtrl m_listInfo;

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
