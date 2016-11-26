#pragma once
//===================================================================================================

#include "afxcmn.h"
#include "afxwin.h"

#include "DlgChild1.h"
#include "DlgChild2.h"
#include "DlgChild3.h"
#include "DlgChild4.h"
#include "DlgChild5.h"
#include "DlgChild6_1.h"
#include "DlgChild6_2.h"
#include "DlgChild6_3.h"
#include "DlgChild6_4.h"
#include "DlgChild6_5.h"
#include "DlgChild6_6.h"
#include "DlgChild7.h"
#include "DlgChild8_1.h"
#include "DlgChild8_2.h"
#include "DlgChild8_3.h"
#include "DlgChild9.h"
#include "DlgChild8_1_1.h"

//===================================================================================================

// 子对话框类型
typedef enum __CHILDTYPE
{
	CT_0				= 0,
	CT_1				= 1,
	CT_2				= 2,
	CT_3				= 3,
	CT_4				= 4,
	CT_5				= 5,
	CT_6_1				= 6,
	CT_6_2				= 7,
	CT_6_3				= 8,
	CT_6_4				= 9,
	CT_6_5				= 10,
	CT_6_6				= 11,
	CT_7				= 12,
	CT_8_1				= 13,
	CT_8_2				= 14,
	CT_8_3				= 15,
	CT_9				= 16,
	CT_8_1_1			= 17,
} CHILDTYPE;

//===================================================================================================

class CDlgMain : public CDialog
{
	DECLARE_DYNAMIC(CDlgMain)

public:
	CDlgMain(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMain();
	enum { IDD = IDD_DLG_MAIN };

protected:
	CStatic m_staticChild;
	CTreeCtrl m_treeMain;
	CImageList m_imageNode;			// 树节点图标


protected:
	CRect m_rcChild;
	// 自对话框
	CDlgChild1 m_dlgChild1;
	CDlgChild2 m_dlgChild2;
	CDlgChild3 m_dlgChild3;
	CDlgChild4 m_dlgChild4;
	CDlgChild5 m_dlgChild5;
	CDlgChild6_1 m_dlgChild6_1;
	CDlgChild6_2 m_dlgChild6_2;
	CDlgChild6_3 m_dlgChild6_3;
	CDlgChild6_4 m_dlgChild6_4;
	CDlgChild6_5 m_dlgChild6_5;
	CDlgChild6_6 m_dlgChild6_6;
	CDlgChild7 m_dlgChild7;
	CDlgChild8_1 m_dlgChild8_1;
	CDlgChild8_2 m_dlgChild8_2;
	CDlgChild8_3 m_dlgChild8_3;
	CDlgChild9 m_dlgChild9;
	CDlgChild8_1_1 m_dlgChild8_1_1;

	int m_nCurChild;

protected:
	// 隐藏子对话框
	void HideChildFrame();
	// 显示对话框
	void ShowChildFrame();

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	afx_msg void OnTvnSelchangedTreeMain(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnPath();

	DECLARE_MESSAGE_MAP()
};

//===================================================================================================

