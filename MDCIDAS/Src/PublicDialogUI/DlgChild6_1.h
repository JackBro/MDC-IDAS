//===================================================================================================

#pragma once

//===================================================================================================

class CDlgChild6_1 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild6_1)

public:
	CDlgChild6_1(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild6_1();
	enum { IDD = IDD_DlG_Child6_1 };

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
