#pragma once

//===================================================================================================

#include "afxcmn.h"

//===================================================================================================

class CDlgJigui : public CDialog
{
	DECLARE_DYNAMIC(CDlgJigui)

public:
	CDlgJigui(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgJigui();

// Dialog Data
	enum { IDD = IDD_DLG_JIGUI };
	CString m_strName;
	CTreeCtrl m_tree;

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
