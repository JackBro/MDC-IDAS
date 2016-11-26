//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild6_2.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild6_2, CDialog)

CDlgChild6_2::CDlgChild6_2(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild6_2::IDD, pParent)
{

}

CDlgChild6_2::~CDlgChild6_2()
{
}

void CDlgChild6_2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgChild6_2, CDialog)
END_MESSAGE_MAP()


BOOL CDlgChild6_2::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}