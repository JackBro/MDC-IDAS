//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild6_5.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild6_5, CDialog)

CDlgChild6_5::CDlgChild6_5(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild6_5::IDD, pParent)
{

}

CDlgChild6_5::~CDlgChild6_5()
{
}

void CDlgChild6_5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgChild6_5, CDialog)
END_MESSAGE_MAP()


BOOL CDlgChild6_5::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}