//===================================================================================================
// Summary:
//		通过参数布线电缆对话框
// Date:
//		2016-11-21
// Author:
//		WangShiping	
//===================================================================================================

#include "stdafx.h"
#include "DlgRoutingCableByParam.h"

//===================================================================================================

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//===================================================================================================

CRoutCabEditCtrl::CRoutCabEditCtrl()
:CEdit()
{
}

CRoutCabEditCtrl::~CRoutCabEditCtrl()
{
}

BEGIN_MESSAGE_MAP(CRoutCabEditCtrl, CEdit)
	//{{AFX_MSG_MAP(CRoutCabEditCtrl)
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// 键盘响应(外部调用)
void CRoutCabEditCtrl::OnMyKeyDown(UINT nChar)
{
	CDialog *pParent = (CDialog*)GetParent();
	if (pParent == NULL)
		return;

	if (nChar == VK_ESCAPE)
	{
		// 恢复原文本
		pParent->UpdateData(FALSE);
	}
	else if (nChar == VK_RETURN)
	{
		// 更新文本
		pParent->UpdateData(TRUE);
	}
}

BOOL CRoutCabEditCtrl::PreTranslateMessage(MSG* pMsg)
{
	// 截获处理特定消息,并使消息不再向后传递
	BOOL bProcessed = FALSE;
	if (pMsg->hwnd == GetSafeHwnd())
	{
		switch (pMsg->message)
		{
		case WM_KEYDOWN:
			{
				switch (pMsg->wParam)
				{
				case VK_RETURN:
				case VK_ESCAPE:
					OnMyKeyDown(UINT(pMsg->wParam));
					bProcessed = TRUE;
					break;
				default:
					break;
				}
				break;
			}
		default:
			break;
		}
	}

	if (!bProcessed)
		bProcessed = CEdit::PreTranslateMessage(pMsg);

	return bProcessed;
}

void CRoutCabEditCtrl::OnKillFocus(CWnd* pNewWnd)
{
	CDialog *pParent = (CDialog*)GetParent();
	if (pParent == NULL)
		return;

	// 更新文本
	pParent->UpdateData(TRUE);

	CEdit::OnKillFocus(pNewWnd);
}

//===================================================================================================

CDlgRoutingCableByParamChild::CDlgRoutingCableByParamChild(UINT nIDTemplate, CWnd* pParentWnd /*= NULL*/) : CDialog(nIDTemplate, pParentWnd)
{
}

void CDlgRoutingCableByParamChild::OnOK()
{
	if (m_pParentDlg != NULL)
		m_pParentDlg->OnOK();
}

void CDlgRoutingCableByParamChild::OnCancel()
{
	if (m_pParentDlg != NULL)
		m_pParentDlg->OnCancel();
}

IKSMDCCableDesignParam* CDlgRoutingCableByParamChild::GetParentCableDesignParamPt()
{
	if (m_pParentDlg != NULL)
		return &(m_pParentDlg->m_stuCableDesignParam);
	return NULL;
}

//===================================================================================================

CDlgRoutingCableByParam_IT::CDlgRoutingCableByParam_IT(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_IT::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_IT)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_IT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_IT)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_IT_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_IT_TEST, GetParentCableDesignParamPt()->stuIT.bValid);
// 	DDX_Control(pDX, IDC_CMB_ROUTCAB_IT_TEST, m_cmbChangeMode);
// 	DDX_Check(pDX, IDC_CHECK_ROUTCAB_IT_TEST, GetParentCableDesignParamPt()->stuIT.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_IT, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_IT)
// 	ON_BN_CLICKED(IDC_BTN_ROUTCAB_IT_TEST, OnBnClickedTest)
// 	ON_CBN_SELCHANGE(IDC_CMB_ROUTCAB_IT_TEST, OnSelChangeCmbTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_IT::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_IT::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_TAC::CDlgRoutingCableByParam_TAC(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_TAC::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_TAC)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_TAC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_TAC)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_TAC_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_TAC_TEST, GetParentCableDesignParamPt()->stuTAC.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_TAC, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_TAC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_TAC::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_TAC::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_BAT::CDlgRoutingCableByParam_BAT(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_BAT::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_BAT)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_BAT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_BAT)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_BAT_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_BAT_TEST, GetParentCableDesignParamPt()->stuBAT.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_BAT, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_BAT)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_BAT::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_BAT::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_HVDC::CDlgRoutingCableByParam_HVDC(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_HVDC::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_HVDC)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_HVDC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_HVDC)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_HVDC_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_HVDC_TEST, GetParentCableDesignParamPt()->stuHVDC.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_HVDC, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_HVDC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_HVDC::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_HVDC::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_UPS::CDlgRoutingCableByParam_UPS(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_UPS::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_UPS)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_UPS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_UPS)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_UPS_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_UPS_TEST, GetParentCableDesignParamPt()->stuUPS.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_UPS, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_UPS)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_UPS::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_UPS::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_ITPDRH::CDlgRoutingCableByParam_ITPDRH(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_ITPDRH::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_ITPDRH)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_ITPDRH::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_ITPDRH)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_ITPDRH_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_ITPDRH_TEST, GetParentCableDesignParamPt()->stuITPDRH.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_ITPDRH, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_ITPDRH)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_ITPDRH::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_ITPDRH::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_ITPDRU::CDlgRoutingCableByParam_ITPDRU(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_ITPDRU::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_ITPDRU)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_ITPDRU::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_ITPDRU)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_ITPDRU_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_ITPDRU_TEST, GetParentCableDesignParamPt()->stuITPDRU.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_ITPDRU, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_ITPDRU)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_ITPDRU::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_ITPDRU::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_FC::CDlgRoutingCableByParam_FC(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_FC::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_FC)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_FC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_FC)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_FC_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_FC_TEST, GetParentCableDesignParamPt()->stuFC.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_FC, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_FC)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_FC::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_FC::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_ZM::CDlgRoutingCableByParam_ZM(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_ZM::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_ZM)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_ZM::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_ZM)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_ZM_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_ZM_TEST, GetParentCableDesignParamPt()->stuZM.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_ZM, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_ZM)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_ZM::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_ZM::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_MJ::CDlgRoutingCableByParam_MJ(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_MJ::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_MJ)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_MJ::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_MJ)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_MJ_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_MJ_TEST, GetParentCableDesignParamPt()->stuMJ.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_MJ, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_MJ)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_MJ::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_MJ::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_JJAN::CDlgRoutingCableByParam_JJAN(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_JJAN::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_JJAN)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_JJAN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_JJAN)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_JJAN_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_JJAN_TEST, GetParentCableDesignParamPt()->stuJJAN.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_JJAN, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_JJAN)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_JJAN::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_JJAN::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_GK::CDlgRoutingCableByParam_GK(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_GK::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_GK)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_GK::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_GK)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_GK_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_GK_TEST, GetParentCableDesignParamPt()->stuGK.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_GK, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_GK)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_GK::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_GK::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_JDX::CDlgRoutingCableByParam_JDX(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_JDX::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_JDX)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_JDX::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_JDX)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_JDX_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_JDX_TEST, GetParentCableDesignParamPt()->stuJDX.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_JDX, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_JDX)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_JDX::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_JDX::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam_WX::CDlgRoutingCableByParam_WX(CWnd* pParent /*=NULL*/) : CDlgRoutingCableByParamChild(CDlgRoutingCableByParam_WX::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam_WX)
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam_WX::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam_WX)
	DDX_Control(pDX, IDC_EDIT_ROUTCAB_WX_TEST, m_editTest);
	DDX_Text(pDX, IDC_EDIT_ROUTCAB_WX_TEST, GetParentCableDesignParamPt()->stuWX.bValid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam_WX, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam_WX)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam_WX::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	UpdateData(FALSE);
	return TRUE;
}

// 更新控件的可用性
void CDlgRoutingCableByParam_WX::UpdateDlgCtrlEnalbe()
{
}

//===================================================================================================

CDlgRoutingCableByParam::CDlgRoutingCableByParam(CWnd* pParent /*=NULL*/) : CDialog(CDlgRoutingCableByParam::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRoutingCableByParam)
	m_dlgIT.m_pParentDlg = this;
	m_dlgTAC.m_pParentDlg = this;
	m_dlgBAT.m_pParentDlg = this;
	m_dlgHVDC.m_pParentDlg = this;
	m_dlgUPS.m_pParentDlg = this;
	m_dlgITPDRH.m_pParentDlg = this;
	m_dlgITPDRU.m_pParentDlg = this;
	m_dlgFC.m_pParentDlg = this;
	m_dlgZM.m_pParentDlg = this;
	m_dlgMJ.m_pParentDlg = this;
	m_dlgJJAN.m_pParentDlg = this;
	m_dlgGK.m_pParentDlg = this;
	m_dlgJDX.m_pParentDlg = this;
	m_dlgWX.m_pParentDlg = this;
	//}}AFX_DATA_INIT
}

void CDlgRoutingCableByParam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRoutingCableByParam)
	DDX_Control(pDX, IDC_TREE_ROUTCAB_CATALOGUE, m_treeCatalogue);
	//}}AFX_DATA_MAP	
}

BEGIN_MESSAGE_MAP(CDlgRoutingCableByParam, CDialog)
	//{{AFX_MSG_MAP(CDlgRoutingCableByParam)
	ON_WM_DESTROY()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_ROUTCAB_CATALOGUE, OnSelChangedTreeCatalogue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgRoutingCableByParam::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_MDCCableDMMgr.Init();

	// 初始化布线项目数据信息
	InitRoutCabProjDataInf();
	m_stuCableDesignParam = m_MDCCableDMMgr.GetRoutCabProjDataInfPt()->m_CableDesignParam;

	// 初始化目录
	m_treeCatalogue.SetBkColor(RGB(255, 255, 255));
	m_treeCatalogue.SetItemHeight(SHORT(float(m_treeCatalogue.GetItemHeight())*1.3f));
	m_treeCatalogue.DeleteAllItems();
	HTREEITEM hRootItem = m_treeCatalogue.InsertItem(_T("规格"), 1, 1, TVI_ROOT, TVI_LAST);
	HTREEITEM hITItem = NULL;
	m_treeCatalogue.SetItemData(hRootItem, IDD_ROUTCAB_IT);
	if (hRootItem != NULL)
	{
		HTREEITEM hItem = NULL;
		hItem = m_treeCatalogue.InsertItem(_T("IT柜（强电）"), 1, 1, hRootItem, TVI_LAST);
		hITItem = hItem;
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_IT);
		hItem = m_treeCatalogue.InsertItem(_T("TAC柜（强电）"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_TAC);
		hItem = m_treeCatalogue.InsertItem(_T("BAT柜（强电）"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_BAT);
		hItem = m_treeCatalogue.InsertItem(_T("HVDC（强电）"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_HVDC);
		hItem = m_treeCatalogue.InsertItem(_T("UPS（强电）"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_UPS);
		hItem = m_treeCatalogue.InsertItem(_T("ITPDRH（强电）"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_ITPDRH);
		hItem = m_treeCatalogue.InsertItem(_T("ITPDRU（强电）"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_ITPDRU);
		hItem = m_treeCatalogue.InsertItem(_T("翻转顶窗（弱电）"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_FC);
		hItem = m_treeCatalogue.InsertItem(_T("照明（强电）"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_ZM);
		hItem = m_treeCatalogue.InsertItem(_T("门禁（弱电）"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_MJ);
		hItem = m_treeCatalogue.InsertItem(_T("紧急按钮（弱电）"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_JJAN);
		hItem = m_treeCatalogue.InsertItem(_T("管控盒坐标系（强电）"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_GK);
		hItem = m_treeCatalogue.InsertItem(_T("接地线"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_JDX);
		hItem = m_treeCatalogue.InsertItem(_T("网线"), 1, 1, hRootItem, TVI_LAST);
		m_treeCatalogue.SetItemData(hItem, IDD_ROUTCAB_WX);

		m_treeCatalogue.Expand(hRootItem, TVE_EXPAND);
	}

	// 初始化各子系统对话框
	m_dlgIT.Create(IDD_ROUTCAB_IT, this);
	m_dlgTAC.Create(IDD_ROUTCAB_TAC, this);
	m_dlgBAT.Create(IDD_ROUTCAB_BAT, this);
	m_dlgHVDC.Create(IDD_ROUTCAB_HVDC, this);
	m_dlgUPS.Create(IDD_ROUTCAB_UPS, this);
	m_dlgITPDRH.Create(IDD_ROUTCAB_ITPDRH, this);
	m_dlgITPDRU.Create(IDD_ROUTCAB_ITPDRU, this);
	m_dlgFC.Create(IDD_ROUTCAB_FC, this);
	m_dlgZM.Create(IDD_ROUTCAB_ZM, this);
	m_dlgMJ.Create(IDD_ROUTCAB_MJ, this);
	m_dlgJJAN.Create(IDD_ROUTCAB_JJAN, this);
	m_dlgGK.Create(IDD_ROUTCAB_GK, this);
	m_dlgJDX.Create(IDD_ROUTCAB_JDX, this);
	m_dlgWX.Create(IDD_ROUTCAB_WX, this);

	// 调整各子系统对话框位置
	CRect rect;
	GetDlgItem(IDC_STATIC_ROUTCAB_SUBDLGPOSITION)->GetWindowRect(rect);
	ScreenToClient(rect);
	GetDlgItem(IDC_STATIC_ROUTCAB_SUBDLGPOSITION)->ShowWindow(SW_HIDE);
	m_dlgIT.MoveWindow(rect);
	m_dlgTAC.MoveWindow(rect);
	m_dlgBAT.MoveWindow(rect);
	m_dlgHVDC.MoveWindow(rect);
	m_dlgUPS.MoveWindow(rect);
	m_dlgITPDRH.MoveWindow(rect);
	m_dlgITPDRU.MoveWindow(rect);
	m_dlgFC.MoveWindow(rect);
	m_dlgZM.MoveWindow(rect);
	m_dlgMJ.MoveWindow(rect);
	m_dlgJJAN.MoveWindow(rect);
	m_dlgGK.MoveWindow(rect);
	m_dlgJDX.MoveWindow(rect);
	m_dlgWX.MoveWindow(rect);

	// 更新控件的可用性
	UpdateDlgCtrlEnalbe();

	// 设置目录树的选中状态及子对话框的显示
	m_treeCatalogue.SelectItem(hITItem);
	ShowSubDlgByCatalogueSel();

	UpdateData(FALSE);
	return TRUE;
}

void CDlgRoutingCableByParam::OnOK() 
{
	UpdateData(TRUE);

	m_dlgIT.UpdateData(TRUE);
	m_dlgTAC.UpdateData(TRUE);
	m_dlgBAT.UpdateData(TRUE);
	m_dlgHVDC.UpdateData(TRUE);
	m_dlgUPS.UpdateData(TRUE);
	m_dlgITPDRH.UpdateData(TRUE);
	m_dlgITPDRU.UpdateData(TRUE);
	m_dlgFC.UpdateData(TRUE);
	m_dlgZM.UpdateData(TRUE);
	m_dlgMJ.UpdateData(TRUE);
	m_dlgJJAN.UpdateData(TRUE);
	m_dlgGK.UpdateData(TRUE);
	m_dlgJDX.UpdateData(TRUE);
	m_dlgWX.UpdateData(TRUE);

	CDialog::OnOK();
}

void CDlgRoutingCableByParam::OnCancel() 
{
	CDialog::OnCancel();
}


void CDlgRoutingCableByParam::OnDestroy()
{
	m_MDCCableDMMgr.UnInit();

	CDialog::OnDestroy();
}

void CDlgRoutingCableByParam::OnSelChangedTreeCatalogue(NMHDR* pNMHDR, LRESULT* pResult)
{
	pNMHDR;

	// 根据目录树选中状态显示子对话框
	ShowSubDlgByCatalogueSel();

	*pResult = 0;
}

// 更新控件的可用性
void CDlgRoutingCableByParam::UpdateDlgCtrlEnalbe()
{
	m_dlgIT.UpdateDlgCtrlEnalbe();
	m_dlgTAC.UpdateDlgCtrlEnalbe();
	m_dlgBAT.UpdateDlgCtrlEnalbe();
	m_dlgHVDC.UpdateDlgCtrlEnalbe();
	m_dlgUPS.UpdateDlgCtrlEnalbe();
	m_dlgITPDRH.UpdateDlgCtrlEnalbe();
	m_dlgITPDRU.UpdateDlgCtrlEnalbe();
	m_dlgFC.UpdateDlgCtrlEnalbe();
	m_dlgZM.UpdateDlgCtrlEnalbe();
	m_dlgMJ.UpdateDlgCtrlEnalbe();
	m_dlgJJAN.UpdateDlgCtrlEnalbe();
	m_dlgGK.UpdateDlgCtrlEnalbe();
	m_dlgJDX.UpdateDlgCtrlEnalbe();
	m_dlgWX.UpdateDlgCtrlEnalbe();
}

// 隐藏所有子对话框
void CDlgRoutingCableByParam::HideAllSubDlg()
{
	m_dlgIT.ShowWindow(SW_HIDE);
	m_dlgTAC.ShowWindow(SW_HIDE);
	m_dlgBAT.ShowWindow(SW_HIDE);
	m_dlgHVDC.ShowWindow(SW_HIDE);
	m_dlgUPS.ShowWindow(SW_HIDE);
	m_dlgITPDRH.ShowWindow(SW_HIDE);
	m_dlgITPDRU.ShowWindow(SW_HIDE);
	m_dlgFC.ShowWindow(SW_HIDE);
	m_dlgZM.ShowWindow(SW_HIDE);
	m_dlgMJ.ShowWindow(SW_HIDE);
	m_dlgJJAN.ShowWindow(SW_HIDE);
	m_dlgGK.ShowWindow(SW_HIDE);
	m_dlgJDX.ShowWindow(SW_HIDE);
	m_dlgWX.ShowWindow(SW_HIDE);
}

// 显示子对话框
void CDlgRoutingCableByParam::ShowSubDlg(int nSubDlgID)
{
	HideAllSubDlg();

	switch (nSubDlgID)
	{
	case IDD_ROUTCAB_IT:
		m_dlgIT.ShowWindow(SW_SHOW);
		m_dlgIT.Invalidate();
		break;
	case IDD_ROUTCAB_TAC:
		m_dlgTAC.ShowWindow(SW_SHOW);
		m_dlgTAC.Invalidate();
		break;
	case IDD_ROUTCAB_BAT:
		m_dlgBAT.ShowWindow(SW_SHOW);
		m_dlgBAT.Invalidate();
		break;
	case IDD_ROUTCAB_HVDC:
		m_dlgHVDC.ShowWindow(SW_SHOW);
		m_dlgHVDC.Invalidate();
		break;
	case IDD_ROUTCAB_UPS:
		m_dlgUPS.ShowWindow(SW_SHOW);
		m_dlgUPS.Invalidate();
		break;
	case IDD_ROUTCAB_ITPDRH:
		m_dlgITPDRH.ShowWindow(SW_SHOW);
		m_dlgITPDRH.Invalidate();
		break;
	case IDD_ROUTCAB_ITPDRU:
		m_dlgITPDRU.ShowWindow(SW_SHOW);
		m_dlgITPDRU.Invalidate();
		break;
	case IDD_ROUTCAB_FC:
		m_dlgFC.ShowWindow(SW_SHOW);
		m_dlgFC.Invalidate();
		break;
	case IDD_ROUTCAB_ZM:
		m_dlgZM.ShowWindow(SW_SHOW);
		m_dlgZM.Invalidate();
		break;
	case IDD_ROUTCAB_MJ:
		m_dlgMJ.ShowWindow(SW_SHOW);
		m_dlgMJ.Invalidate();
		break;
	case IDD_ROUTCAB_JJAN:
		m_dlgJJAN.ShowWindow(SW_SHOW);
		m_dlgJJAN.Invalidate();
		break;
	case IDD_ROUTCAB_GK:
		m_dlgGK.ShowWindow(SW_SHOW);
		m_dlgGK.Invalidate();
		break;
	case IDD_ROUTCAB_JDX:
		m_dlgJDX.ShowWindow(SW_SHOW);
		m_dlgJDX.Invalidate();
		break;
	case IDD_ROUTCAB_WX:
		m_dlgWX.ShowWindow(SW_SHOW);
		m_dlgWX.Invalidate();
		break;
	default:
		break;
	}
}

// 根据目录树选中状态显示子对话框
void CDlgRoutingCableByParam::ShowSubDlgByCatalogueSel()
{
	HTREEITEM hSelItem = m_treeCatalogue.GetSelectedItem();
	if (hSelItem == NULL)
		return;
	int nSelDlgID = (int)m_treeCatalogue.GetItemData(hSelItem);

	ShowSubDlg(nSelDlgID);
}

// 初始化布线项目数据信息
void CDlgRoutingCableByParam::InitRoutCabProjDataInf()
{
	// 更新布局参数(从当前装配体获取参数)
	m_MDCCableDMMgr.UpdateLayoutParamFromCurAsm();
	// 更新电缆布局参数(从当前装配体获取参数)
	m_MDCCableDMMgr.UpdateCableLayoutParamFromCurAsm();
	// 更新电缆设计参数(从当前装配体获取参数)
	m_MDCCableDMMgr.UpdateCableDesignParamFromCurAsm();

	// 根据布局参数修正电缆设计参数
	m_MDCCableDMMgr.CorrectCableDesignParamByLayoutParam();
}

//===================================================================================================
