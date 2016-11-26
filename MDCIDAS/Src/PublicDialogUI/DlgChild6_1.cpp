//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild6_1.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild6_1, CDialog)

CDlgChild6_1::CDlgChild6_1(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild6_1::IDD, pParent)
{

}

CDlgChild6_1::~CDlgChild6_1()
{
}

void CDlgChild6_1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgChild6_1, CDialog)
END_MESSAGE_MAP()


BOOL CDlgChild6_1::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}