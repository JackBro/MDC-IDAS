//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild1.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild1, CDialog)

CDlgChild1::CDlgChild1(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild1::IDD, pParent)
{
	m_strPath = L"ZTE_MDC_Data:\\��С��";
	m_strName = L"������ͨ20161103B";
}

CDlgChild1::~CDlgChild1()
{
}

void CDlgChild1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strPath);
	DDX_Text(pDX, IDC_EDIT2, m_strName);
	DDX_Control(pDX, IDC_LIST1, m_listInfo);
}

BEGIN_MESSAGE_MAP(CDlgChild1, CDialog)
END_MESSAGE_MAP()


BOOL CDlgChild1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �б����
	DWORD dwStyle = m_listInfo.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_INFOTIP;

	m_listInfo.SetExtendedStyle(dwStyle);	

	// ������
	m_listInfo.InsertColumn(0, L"��Ŀ���", LVCFMT_LEFT, 140);
	m_listInfo.InsertColumn(1, L"��������", LVCFMT_LEFT, 100);
	m_listInfo.InsertColumn(2, L"����", LVCFMT_LEFT, 60);

	// ��������
	int nColum = m_listInfo.InsertItem(0, L"");
	m_listInfo.SetItemText(nColum, 0, L"�����ƶ�20161030A");
	m_listInfo.SetItemText(nColum, 1, L"20161030 11:30");
	m_listInfo.SetItemText(nColum, 2, L"�ļ���");
	
	nColum = m_listInfo.InsertItem(1, L"");
	m_listInfo.SetItemText(nColum, 0, L"��������20161101A");
	m_listInfo.SetItemText(nColum, 1, L"20161101 9:26");
	m_listInfo.SetItemText(nColum, 2, L"�ļ���");

	nColum = m_listInfo.InsertItem(2, L"");
	m_listInfo.SetItemText(nColum, 0, L"������ͨ20161103A");
	m_listInfo.SetItemText(nColum, 1, L"20161103 10:50");
	m_listInfo.SetItemText(nColum, 2, L"�ļ���");

	return TRUE;
}