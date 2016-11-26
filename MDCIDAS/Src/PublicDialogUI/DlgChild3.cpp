//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild3.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild3, CDialog)

CDlgChild3::CDlgChild3(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild3::IDD, pParent)
{

}

CDlgChild3::~CDlgChild3()
{
}

void CDlgChild3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgChild3, CDialog)
END_MESSAGE_MAP()


BOOL CDlgChild3::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}