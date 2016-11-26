//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild8_1.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild8_1, CDialog)

CDlgChild8_1::CDlgChild8_1(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild8_1::IDD, pParent)
{
	m_strName = L"ZTE_MDC_Data:\\��С��";
}

CDlgChild8_1::~CDlgChild8_1()
{
}

void CDlgChild8_1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDX_Control(pDX, IDC_LIST1, m_listInfo);
}

BEGIN_MESSAGE_MAP(CDlgChild8_1, CDialog)
END_MESSAGE_MAP()


BOOL CDlgChild8_1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �б����
	DWORD dwStyle = m_listInfo.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_INFOTIP;

	m_listInfo.SetExtendedStyle(dwStyle);	

	// ������
	m_listInfo.InsertColumn(0, L"�������", LVCFMT_LEFT, 160);
	m_listInfo.InsertColumn(1, L"��������", LVCFMT_LEFT, 100);
	m_listInfo.InsertColumn(2, L"����", LVCFMT_LEFT, 60);

	// ��������
	int nColum = m_listInfo.InsertItem(0, L"");
	m_listInfo.SetItemText(nColum, 0, L"������ͨ20161030A01.xls");
	m_listInfo.SetItemText(nColum, 1, L"20161103 10:50");
	m_listInfo.SetItemText(nColum, 2, L"Excel��");

	nColum = m_listInfo.InsertItem(1, L"");
	m_listInfo.SetItemText(nColum, 0, L"������ͨ20161030A01_01.dvf");
	m_listInfo.SetItemText(nColum, 1, L"20161103 11:00");
	m_listInfo.SetItemText(nColum, 2, L"dvf");

	nColum = m_listInfo.InsertItem(2, L"");
	m_listInfo.SetItemText(nColum, 0, L"������ͨ20161030A01_02.dvf");
	m_listInfo.SetItemText(nColum, 1, L"20161103 11:00");
	m_listInfo.SetItemText(nColum, 2, L"dvf");


	return TRUE;
}