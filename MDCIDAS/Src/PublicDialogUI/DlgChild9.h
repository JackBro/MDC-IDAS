//===================================================================================================

#pragma once

//===================================================================================================

class CDlgChild9 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild9)

public:
	CDlgChild9(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild9();
	enum { IDD = IDD_DlG_Child9 };

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
