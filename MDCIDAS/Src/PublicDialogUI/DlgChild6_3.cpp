//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild6_3.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild6_3, CDialog)

CDlgChild6_3::CDlgChild6_3(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild6_3::IDD, pParent)
{

}

CDlgChild6_3::~CDlgChild6_3()
{
}

void CDlgChild6_3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgChild6_3, CDialog)
END_MESSAGE_MAP()


BOOL CDlgChild6_3::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}