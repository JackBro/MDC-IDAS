//===================================================================================================

#pragma once

//===================================================================================================

class CDlgChild4 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild4)

public:
	CDlgChild4(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild4();
	enum { IDD = IDD_DlG_Child4 };
	CString m_strValue1;
	CString m_strValue2;

	CString m_strFilePath;
	CListBox m_listInfo;

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
