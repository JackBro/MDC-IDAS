//===================================================================================================

#pragma once

//===================================================================================================

class CDlgChild6_3 : public CDialog
{
	DECLARE_DYNAMIC(CDlgChild6_3)

public:
	CDlgChild6_3(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChild6_3();
	enum { IDD = IDD_DlG_Child6_3 };

protected:
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
