//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild5.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild5, CDialog)

CDlgChild5::CDlgChild5(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild5::IDD, pParent)
{

}

CDlgChild5::~CDlgChild5()
{
}

void CDlgChild5::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX, IDC_EDIT_PATH, m_strFilePath);
	DDX_Control(pDX, IDC_LIST_INFO, m_listInfo);
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgChild5, CDialog)
	
END_MESSAGE_MAP()


BOOL CDlgChild5::OnInitDialog()
{
	CDialog::OnInitDialog();

	int nCount = m_listInfo.GetCount();
	for (int i = nCount-1; i >= 0; i--)
		m_listInfo.DeleteString(i);

	m_listInfo.AddString(L"北京联通20161103A.xls");
	m_listInfo.AddString(L"北京联通20161103A_01.dvf");
	m_listInfo.AddString(L"北京联通20161103A_02.dvf");
	m_listInfo.AddString(L"北京联通20161103A01_01DL.xls");
	m_listInfo.AddString(L"北京联通20161103A01_02DL.xls");

	return TRUE;
}