//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild1.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild1, CDialog)

CDlgChild1::CDlgChild1(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild1::IDD, pParent)
{
	m_strPath = L"ZTE_MDC_Data:\\王小明";
	m_strName = L"北京联通20161103B";
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

	// 列表参数
	DWORD dwStyle = m_listInfo.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_INFOTIP;

	m_listInfo.SetExtendedStyle(dwStyle);	

	// 插入列
	m_listInfo.InsertColumn(0, L"项目编号", LVCFMT_LEFT, 140);
	m_listInfo.InsertColumn(1, L"创建日期", LVCFMT_LEFT, 100);
	m_listInfo.InsertColumn(2, L"类型", LVCFMT_LEFT, 60);

	// 测试数据
	int nColum = m_listInfo.InsertItem(0, L"");
	m_listInfo.SetItemText(nColum, 0, L"北京移动20161030A");
	m_listInfo.SetItemText(nColum, 1, L"20161030 11:30");
	m_listInfo.SetItemText(nColum, 2, L"文件夹");
	
	nColum = m_listInfo.InsertItem(1, L"");
	m_listInfo.SetItemText(nColum, 0, L"北京电信20161101A");
	m_listInfo.SetItemText(nColum, 1, L"20161101 9:26");
	m_listInfo.SetItemText(nColum, 2, L"文件夹");

	nColum = m_listInfo.InsertItem(2, L"");
	m_listInfo.SetItemText(nColum, 0, L"北京联通20161103A");
	m_listInfo.SetItemText(nColum, 1, L"20161103 10:50");
	m_listInfo.SetItemText(nColum, 2, L"文件夹");

	return TRUE;
}