//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild4.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild4, CDialog)

CDlgChild4::CDlgChild4(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild4::IDD, pParent)
{
	m_strFilePath = _T("北京联通20161103A");

	m_strValue1 = _T("北京联通201611030A01.xls");
	m_strValue2 = _T("北京联通201611030A01_01.dvf");
}

CDlgChild4::~CDlgChild4()
{
}

void CDlgChild4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strValue1);
	DDX_Text(pDX, IDC_EDIT2, m_strValue2);
	DDX_Text(pDX, IDC_EDIT_PATH, m_strFilePath);
	DDX_Control(pDX, IDC_LIST_INFO, m_listInfo);
}

BEGIN_MESSAGE_MAP(CDlgChild4, CDialog)
END_MESSAGE_MAP()

BOOL CDlgChild4::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_listInfo.AddString(L"北京联通20161103A.xls");
	m_listInfo.AddString(L"北京联通20161103A_01.dvf");
	m_listInfo.AddString(L"北京联通20161103A_02.dvf");

	return TRUE;
}