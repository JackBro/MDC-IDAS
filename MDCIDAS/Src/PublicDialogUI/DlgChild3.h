//===================================================================================================

#pragma once

//===================================================================================================

class CDlgChild3 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild3)

public:
	CDlgChild3(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild3();
	enum { IDD = IDD_DlG_Child2 };

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
