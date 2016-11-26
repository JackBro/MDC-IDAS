//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgJigui.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgJigui, CDialog)

CDlgJigui::CDlgJigui(CWnd* pParent /*=NULL*/)	: CDialog(CDlgJigui::IDD, pParent)

{
	 m_strName = _T("服务器机柜");
}

CDlgJigui::~CDlgJigui()
{
}

void CDlgJigui::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDX_Control(pDX, IDC_TREE_MAIN, m_tree);
}

BEGIN_MESSAGE_MAP(CDlgJigui, CDialog)
END_MESSAGE_MAP()

BOOL CDlgJigui::OnInitDialog()
{
	CDialog::OnInitDialog();

	HTREEITEM hParent = m_tree.InsertItem(L"总体尺寸", -1, -1, TVI_ROOT);
	hParent = m_tree.InsertItem(L"机柜附件", -1, -1, TVI_ROOT);
	HTREEITEM hCurItem = m_tree.InsertItem(L"前门", -1, -1, hParent);
	hCurItem = m_tree.InsertItem(L"后门", -1, -1, hParent);
	hCurItem = m_tree.InsertItem(L"L形托板", -1, -1, hParent);
	hCurItem = m_tree.InsertItem(L"层板", -1, -1, hParent);
	hCurItem = m_tree.InsertItem(L"盲板", -1, -1, hParent);
	hCurItem = m_tree.InsertItem(L"穿线面板", -1, -1, hParent);
	hCurItem = m_tree.InsertItem(L"汇流排", -1, -1, hParent);

	m_tree.Expand(hParent, TVE_EXPAND);


	return TRUE;
}