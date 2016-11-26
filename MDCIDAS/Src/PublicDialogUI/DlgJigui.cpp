//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgJigui.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgJigui, CDialog)

CDlgJigui::CDlgJigui(CWnd* pParent /*=NULL*/)	: CDialog(CDlgJigui::IDD, pParent)

{
	 m_strName = _T("����������");
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

	HTREEITEM hParent = m_tree.InsertItem(L"����ߴ�", -1, -1, TVI_ROOT);
	hParent = m_tree.InsertItem(L"���񸽼�", -1, -1, TVI_ROOT);
	HTREEITEM hCurItem = m_tree.InsertItem(L"ǰ��", -1, -1, hParent);
	hCurItem = m_tree.InsertItem(L"����", -1, -1, hParent);
	hCurItem = m_tree.InsertItem(L"L���а�", -1, -1, hParent);
	hCurItem = m_tree.InsertItem(L"���", -1, -1, hParent);
	hCurItem = m_tree.InsertItem(L"ä��", -1, -1, hParent);
	hCurItem = m_tree.InsertItem(L"�������", -1, -1, hParent);
	hCurItem = m_tree.InsertItem(L"������", -1, -1, hParent);

	m_tree.Expand(hParent, TVE_EXPAND);


	return TRUE;
}