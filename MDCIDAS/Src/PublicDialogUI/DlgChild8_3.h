//===================================================================================================

#pragma once
#include "afxcmn.h"

//===================================================================================================

class CDlgChild8_3 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild8_3)

public:
	CDlgChild8_3(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild8_3();
	enum { IDD = IDD_DlG_Child8_3 };
	CString m_strName;
	CListCtrl m_listInfo;

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
