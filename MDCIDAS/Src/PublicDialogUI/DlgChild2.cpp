//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild2.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild2, CDialog)

CDlgChild2::CDlgChild2(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild2::IDD, pParent)
{
	m_strName = L"ZTE_MDC_Data:\\王小明\\北京联通20161103A";
	m_strPath  = L"北京联通20161103A.xls";
}

CDlgChild2::~CDlgChild2()
{
}

void CDlgChild2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDX_Text(pDX, IDC_EDIT2, m_strPath);
	DDX_Control(pDX, IDC_LIST1, m_listInfo);
}

BEGIN_MESSAGE_MAP(CDlgChild2, CDialog)
END_MESSAGE_MAP()


BOOL CDlgChild2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 列表参数
	DWORD dwStyle = m_listInfo.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_INFOTIP;

	m_listInfo.SetExtendedStyle(dwStyle);	

	// 插入列
	m_listInfo.InsertColumn(0, L"订单编号", LVCFMT_LEFT, 160);
	m_listInfo.InsertColumn(1, L"创建日期", LVCFMT_LEFT, 100);
	m_listInfo.InsertColumn(2, L"类型", LVCFMT_LEFT, 60);

	// 测试数据
	int nColum = m_listInfo.InsertItem(0, L"");
	m_listInfo.SetItemText(nColum, 0, L"北京联通20161030A01.xls");
	m_listInfo.SetItemText(nColum, 1, L"20161103 10:50");
	m_listInfo.SetItemText(nColum, 2, L"Excel表");

	nColum = m_listInfo.InsertItem(1, L"");
	m_listInfo.SetItemText(nColum, 0, L"北京联通20161030A01_01.dvf");
	m_listInfo.SetItemText(nColum, 1, L"20161103 11:00");
	m_listInfo.SetItemText(nColum, 2, L"dvf");

	nColum = m_listInfo.InsertItem(2, L"");
	m_listInfo.SetItemText(nColum, 0, L"北京联通20161030A01_02.dvf");
	m_listInfo.SetItemText(nColum, 1, L"20161103 11:00");
	m_listInfo.SetItemText(nColum, 2, L"dvf");

	return TRUE;
}