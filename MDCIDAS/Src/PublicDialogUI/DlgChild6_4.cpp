//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild6_4.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild6_4, CDialog)

CDlgChild6_4::CDlgChild6_4(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild6_4::IDD, pParent)
{

}

CDlgChild6_4::~CDlgChild6_4()
{
}

void CDlgChild6_4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgChild6_4, CDialog)
END_MESSAGE_MAP()


BOOL CDlgChild6_4::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}