//===================================================================================================

#pragma once
#include "afxcmn.h"

//===================================================================================================

class CDlgChild8_2 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild8_2)

public:
	CDlgChild8_2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild8_2();
	enum { IDD = IDD_DlG_Child8_2 };
	CString m_strName;
	CListCtrl m_listInfo;

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
