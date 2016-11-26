//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild7.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild7, CDialog)

CDlgChild7::CDlgChild7(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild7::IDD, pParent)
{

}

CDlgChild7::~CDlgChild7()
{
}

void CDlgChild7::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgChild7, CDialog)
END_MESSAGE_MAP()


BOOL CDlgChild7::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}