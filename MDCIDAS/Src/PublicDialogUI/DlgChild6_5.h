//===================================================================================================

#pragma once

//===================================================================================================

class CDlgChild6_5 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild6_5)

public:
	CDlgChild6_5(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild6_5();
	enum { IDD = IDD_DlG_Child6_5 };

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
