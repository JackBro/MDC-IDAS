//===================================================================================================

#pragma once

//===================================================================================================

class CDlgChild5 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild5)

public:
	CDlgChild5(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild5();
	enum { IDD = IDD_DlG_Child5 };

	CString m_strFilePath;
	CListBox m_listInfo;

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
