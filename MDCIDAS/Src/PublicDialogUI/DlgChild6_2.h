//===================================================================================================

#pragma once

//===================================================================================================

class CDlgChild6_2 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild6_2)

public:
	CDlgChild6_2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild6_2();
	enum { IDD = IDD_DlG_Child6_2 };

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
