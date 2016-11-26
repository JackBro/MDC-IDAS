//===================================================================================================

#pragma once

//===================================================================================================

class CDlgChild6_4 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild6_4)

public:
	CDlgChild6_4(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild6_4();
	enum { IDD = IDD_DlG_Child6_4 };

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
