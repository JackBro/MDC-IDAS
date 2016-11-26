//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild6_6.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild6_6, CDialog)

CDlgChild6_6::CDlgChild6_6(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild6_6::IDD, pParent)
{

}

CDlgChild6_6::~CDlgChild6_6()
{
}

void CDlgChild6_6::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgChild6_6, CDialog)
END_MESSAGE_MAP()


BOOL CDlgChild6_6::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}