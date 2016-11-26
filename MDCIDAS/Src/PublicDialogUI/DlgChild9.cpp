//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "DlgChild9.h"

//===================================================================================================

IMPLEMENT_DYNAMIC(CDlgChild9, CDialog)

CDlgChild9::CDlgChild9(CWnd* pParent /*=NULL*/)	: CDialog(CDlgChild9::IDD, pParent)
{

}

CDlgChild9::~CDlgChild9()
{
}

void CDlgChild9::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgChild9, CDialog)
END_MESSAGE_MAP()


BOOL CDlgChild9::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;
}