//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgMain.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgMain, CDialog)

CDlgMain::CDlgMain(CWnd* pParent /*=NULL*/)	: CDialog(CDlgMain::IDD, pParent)
{
	m_nCurChild = CT_1;
}

CDlgMain::~CDlgMain()
{
}

void CDlgMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_MAIN, m_treeMain);
	DDX_Control(pDX, IDC_CHILD_FRAME, m_staticChild);
}


BEGIN_MESSAGE_MAP(CDlgMain, CDialog)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_MAIN, &CDlgMain::OnTvnSelchangedTreeMain)
	ON_BN_CLICKED(IDC_BTN_PATH, &CDlgMain::OnBnClickedBtnPath)
END_MESSAGE_MAP()

BOOL CDlgMain::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_imageNode.Create(IDB_BMP_TREENODE, 16, 5, RGB(0, 255, 0));
//	m_treeMain.SetImageList(&m_imageNode, TVSIL_NORMAL);

	HTREEITEM hParent = m_treeMain.InsertItem(L"�½���Ŀ", -1, -1, TVI_ROOT);
	m_treeMain.SetItemData(hParent, CT_1);
	hParent = m_treeMain.InsertItem(L"���붩������ɼ���", -1, -1, TVI_ROOT);
	m_treeMain.SetItemData(hParent, CT_2);
	hParent = m_treeMain.InsertItem(L"��������ͼ���", -1, -1, TVI_ROOT);
	m_treeMain.SetItemData(hParent, CT_3);

	hParent = m_treeMain.InsertItem(L"�����������", -1, -11, TVI_ROOT);
	HTREEITEM hCurItem = m_treeMain.InsertItem(L"ģ�黯����ѡ��", -1, -1, hParent);
	m_treeMain.SetItemData(hCurItem, CT_4);
	hCurItem = m_treeMain.InsertItem(L"������ģ�����", -1, -1, hParent);
	hCurItem = m_treeMain.InsertItem(L"����������װģ������", -1, -1, hParent);
	hCurItem = m_treeMain.InsertItem(L"��װ�������ƽṹ��", -1, -1, hParent);

	hParent = m_treeMain.InsertItem(L"�������ܲ���", -1, -1, TVI_ROOT);
	hCurItem = m_treeMain.InsertItem(L"���ѡ�������ܲ���", -1, -1, hParent);
	hCurItem = m_treeMain.InsertItem(L"����λ�õ����ɾ��", -1, -1, hParent);
	hCurItem = m_treeMain.InsertItem(L"����ͳ�ƻ��ܱ�", -1, -1, hParent);
	m_treeMain.SetItemData(hCurItem, CT_5);

	hParent = m_treeMain.InsertItem(L"����ͼ��ϸ���", -1, -1, TVI_ROOT);
	m_treeMain.SetItemData(hParent, CT_6_1);
	hCurItem = m_treeMain.InsertItem(L"��������ͼ���嵥", -1, -1, hParent);
	m_treeMain.SetItemData(hCurItem, CT_6_1);

	hCurItem = m_treeMain.InsertItem(L"����ͼ�Ų������滻", -1, -1, hParent);
	m_treeMain.SetItemData(hCurItem, CT_6_2);

	hCurItem = m_treeMain.InsertItem(L"��������ͼ�Զ�����", -1, -1, hParent);
	m_treeMain.SetItemData(hCurItem, CT_6_3);

	hCurItem = m_treeMain.InsertItem(L"�����ṹ������ͼ�Զ�����", -1, -1, hParent);
	m_treeMain.SetItemData(hCurItem, CT_6_4);

	hCurItem = m_treeMain.InsertItem(L"�����嵥����", -1, -1, hParent);
	m_treeMain.SetItemData(hCurItem, CT_6_5);

	hCurItem = m_treeMain.InsertItem(L"�����ṹ���嵥����", -1, -1, hParent);
	m_treeMain.SetItemData(hCurItem, CT_6_6);


	hParent = m_treeMain.InsertItem(L"��������ɼ���ģ�嵼��", -1, -1, TVI_ROOT);
	m_treeMain.SetItemData(hParent, CT_7);

	hParent = m_treeMain.InsertItem(L"������ѯ", -1, -1, TVI_ROOT);

	hCurItem = m_treeMain.InsertItem(L"��Ŀ��ѯ", -1, -1, hParent);
	m_treeMain.SetItemData(hCurItem, CT_8_1_1);

	HTREEITEM hSecond = m_treeMain.InsertItem(L"ͳ�Ʋ�ѯ", -1, -1, hParent);
	{
		hCurItem = m_treeMain.InsertItem(L"��Ŀͳ�Ʋ�ѯ", -1, -1, hSecond);
		m_treeMain.SetItemData(hCurItem, CT_8_1);
		hCurItem = m_treeMain.InsertItem(L"�û�ҵ��ͳ�Ʋ�ѯ", -1, -1, hSecond);
		m_treeMain.SetItemData(hCurItem, CT_8_2);
		hCurItem = m_treeMain.InsertItem(L"����ͳ�Ʋ�ѯ", -1, -1, hSecond);
		m_treeMain.SetItemData(hCurItem, CT_8_3);
	}

	hParent = m_treeMain.InsertItem(L"���ļ�����", -1, -1, TVI_ROOT);
	m_treeMain.SetItemData(hParent, CT_9);
	hCurItem = m_treeMain.InsertItem(L"ϵͳ����Ա��½", -1, -1, hParent);
	m_treeMain.SetItemData(hCurItem, CT_9);
	hCurItem = m_treeMain.InsertItem(L"�ṹ���������ݿ��ѯ��ά��", -1, -1, hParent);
	hCurItem = m_treeMain.InsertItem(L"���´������ݿ��ѯ��ά��", -1, -1, hParent);

	// �ӶԻ����λ��
	m_staticChild.GetWindowRect(m_rcChild);
	ScreenToClient(m_rcChild);

/*	m_rcChild.left += 3;
	m_rcChild.top += 8;
	m_rcChild.right -= 3;
	m_rcChild.bottom -= 6;*/

	m_dlgChild1.Create(IDD_DlG_Child1, this);
	m_dlgChild2.Create(IDD_DlG_Child2, this);
	m_dlgChild3.Create(IDD_DlG_Child3, this);
	m_dlgChild4.Create(IDD_DlG_Child4, this);
	m_dlgChild5.Create(IDD_DlG_Child5, this);
	m_dlgChild6_1.Create(IDD_DlG_Child6_1, this);
	m_dlgChild6_2.Create(IDD_DlG_Child6_2, this);
	m_dlgChild6_3.Create(IDD_DlG_Child6_3, this);
	m_dlgChild6_4.Create(IDD_DlG_Child6_4, this);
	m_dlgChild6_5.Create(IDD_DlG_Child6_5, this);
	m_dlgChild6_6.Create(IDD_DlG_Child6_6, this);
	m_dlgChild7.Create(IDD_DlG_Child7, this);
	m_dlgChild8_1.Create(IDD_DlG_Child8_1, this);
	m_dlgChild8_2.Create(IDD_DlG_Child8_2, this);
	m_dlgChild8_3.Create(IDD_DlG_Child8_3, this);
	m_dlgChild9.Create(IDD_DlG_Child9, this);
	m_dlgChild8_1_1.Create(IDD_DlG_Child8_1_1, this);

	ShowChildFrame();
	return TRUE;
}

void CDlgMain::OnTvnSelchangedTreeMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	TVITEM item = pNMTreeView->itemNew;
	int nChildType = (int)m_treeMain.GetItemData(item.hItem);
	if (m_nCurChild != nChildType)
	{
		HideChildFrame();

		m_nCurChild = nChildType;
		ShowChildFrame();
	}

	*pResult = 0;
}

void CDlgMain::OnBnClickedBtnPath()
{
}


// �����ӶԻ���
void CDlgMain::HideChildFrame()
{
	m_dlgChild1.ShowWindow(FALSE);
	m_dlgChild1.MoveWindow(0, 0, 0, 0);

	m_dlgChild2.ShowWindow(FALSE);
	m_dlgChild2.MoveWindow(0, 0, 0, 0);
	
	m_dlgChild3.ShowWindow(FALSE);
	m_dlgChild3.MoveWindow(0, 0, 0, 0);

	m_dlgChild4.ShowWindow(FALSE);
	m_dlgChild4.MoveWindow(0, 0, 0, 0);

	m_dlgChild5.ShowWindow(FALSE);
	m_dlgChild5.MoveWindow(0, 0, 0, 0);

	m_dlgChild6_1.ShowWindow(FALSE);
	m_dlgChild6_1.MoveWindow(0, 0, 0, 0);
	m_dlgChild6_2.ShowWindow(FALSE);
	m_dlgChild6_2.MoveWindow(0, 0, 0, 0);
	m_dlgChild6_3.ShowWindow(FALSE);
	m_dlgChild6_3.MoveWindow(0, 0, 0, 0);
	m_dlgChild6_4.ShowWindow(FALSE);
	m_dlgChild6_4.MoveWindow(0, 0, 0, 0);
	m_dlgChild6_5.ShowWindow(FALSE);
	m_dlgChild6_5.MoveWindow(0, 0, 0, 0);
	m_dlgChild6_6.ShowWindow(FALSE);
	m_dlgChild6_6.MoveWindow(0, 0, 0, 0);

	m_dlgChild7.ShowWindow(FALSE);
	m_dlgChild7.MoveWindow(0, 0, 0, 0);

	m_dlgChild8_1.ShowWindow(FALSE);
	m_dlgChild8_1.MoveWindow(0, 0, 0, 0);
	m_dlgChild8_2.ShowWindow(FALSE);
	m_dlgChild8_2.MoveWindow(0, 0, 0, 0);
	m_dlgChild8_3.ShowWindow(FALSE);
	m_dlgChild8_3.MoveWindow(0, 0, 0, 0);

	m_dlgChild8_1_1.ShowWindow(FALSE);
	m_dlgChild8_1_1.MoveWindow(0, 0, 0, 0);

	m_dlgChild9.ShowWindow(FALSE);
	m_dlgChild9.MoveWindow(0, 0, 0, 0);
}

// ��ʾ�Ի���
void CDlgMain::ShowChildFrame()
{
	switch (m_nCurChild)
	{
	case CT_1:
		if (m_dlgChild1.m_hWnd != NULL)
		{
			m_dlgChild1.MoveWindow(m_rcChild);
			m_dlgChild1.ShowWindow(TRUE);
		}
		break;	
	case CT_2:
		if (m_dlgChild2.m_hWnd != NULL)
		{
			m_dlgChild2.MoveWindow(m_rcChild);
			m_dlgChild2.ShowWindow(TRUE);
		}
		break;	
	case CT_3:
		if (m_dlgChild3.m_hWnd != NULL)
		{
			m_dlgChild3.MoveWindow(m_rcChild);
			m_dlgChild3.ShowWindow(TRUE);
		}
		break;	
	case CT_4:
		if (m_dlgChild4.m_hWnd != NULL)
		{	
			m_dlgChild4.MoveWindow(m_rcChild);
			m_dlgChild4.ShowWindow(TRUE);
		}
		break;	
	case CT_5:
		if (m_dlgChild5.m_hWnd != NULL)
		{		
			m_dlgChild5.MoveWindow(m_rcChild);
			m_dlgChild5.ShowWindow(TRUE);
		}
		break;	
	case CT_6_1:
		if (m_dlgChild6_1.m_hWnd != NULL)
		{
			m_dlgChild6_1.MoveWindow(m_rcChild);
			m_dlgChild6_1.ShowWindow(TRUE);
		}
		break;	
	case CT_6_2:
		if (m_dlgChild6_2.m_hWnd != NULL)
		{
			m_dlgChild6_2.MoveWindow(m_rcChild);
			m_dlgChild6_2.ShowWindow(TRUE);
		}
		break;	
	case CT_6_3:
		if (m_dlgChild6_3.m_hWnd != NULL)
		{
			m_dlgChild6_3.MoveWindow(m_rcChild);
			m_dlgChild6_3.ShowWindow(TRUE);
		}
		break;	
	case CT_6_4:
		if (m_dlgChild6_4.m_hWnd != NULL)
		{
			m_dlgChild6_4.MoveWindow(m_rcChild);
			m_dlgChild6_4.ShowWindow(TRUE);
		}
		break;	
	case CT_6_5:
		if (m_dlgChild6_5.m_hWnd != NULL)
		{
			m_dlgChild6_5.MoveWindow(m_rcChild);
			m_dlgChild6_5.ShowWindow(TRUE);
		}
		break;	
	case CT_6_6:
		if (m_dlgChild6_6.m_hWnd != NULL)
		{
			m_dlgChild6_6.MoveWindow(m_rcChild);
			m_dlgChild6_6.ShowWindow(TRUE);
		}
		break;	
	case CT_7:
		if (m_dlgChild7.m_hWnd != NULL)
		{
			m_dlgChild7.MoveWindow(m_rcChild);
			m_dlgChild7.ShowWindow(TRUE);
		}
		break;	
	case CT_8_1:
		if (m_dlgChild8_1.m_hWnd != NULL)
		{
			m_dlgChild8_1.MoveWindow(m_rcChild);
			m_dlgChild8_1.ShowWindow(TRUE);
		}
		break;	
	case CT_8_2:
		if (m_dlgChild8_2.m_hWnd != NULL)
		{
			m_dlgChild8_2.MoveWindow(m_rcChild);
			m_dlgChild8_2.ShowWindow(TRUE);
		}
		break;
	case CT_8_3:
		if (m_dlgChild8_3.m_hWnd != NULL)
		{
			m_dlgChild8_3.MoveWindow(m_rcChild);
			m_dlgChild8_3.ShowWindow(TRUE);
		}
		break;
	case CT_9:
		if (m_dlgChild9.m_hWnd != NULL)
		{
			m_dlgChild9.MoveWindow(m_rcChild);
			m_dlgChild9.ShowWindow(TRUE);
		}
		break;	
	case CT_8_1_1:
		if (m_dlgChild8_1_1.m_hWnd != NULL)
		{
			m_dlgChild8_1_1.MoveWindow(m_rcChild);
			m_dlgChild8_1_1.ShowWindow(TRUE);
		}
		break;	
	default:
		break;
	}
}