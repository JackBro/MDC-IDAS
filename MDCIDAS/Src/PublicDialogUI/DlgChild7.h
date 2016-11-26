//===================================================================================================

#pragma once

//===================================================================================================

class CDlgChild7 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild7)

public:
	CDlgChild7(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild7();
	enum { IDD = IDD_DlG_Child7 };

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
