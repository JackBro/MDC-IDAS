//===================================================================================================

#pragma once

//===================================================================================================

class CDlgChild6_6 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild6_6)

public:
	CDlgChild6_6(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild6_6();
	enum { IDD = IDD_DlG_Child6_6 };

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
