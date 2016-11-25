//===================================================================================================
// Summary:
//		通过参数布线电缆对话框
// Date:
//		2016-11-21
// Author:
//		WangShiping	
//===================================================================================================

#pragma once

//===================================================================================================

#include "Resource.h"
#include "IKSMDCCableDataMethodMgr.h"

//===================================================================================================

class CRoutCabEditCtrl : public CEdit
{
public:
	CRoutCabEditCtrl();
	virtual ~CRoutCabEditCtrl();

public:
	// 键盘响应(外部调用)
	void OnMyKeyDown(UINT nChar);

public:
	//{{AFX_VIRTUAL(CRoutCabEditCtrl)
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CRoutCabEditCtrl)
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CDlgRoutingCableByParam;

class CDlgRoutingCableByParamChild : public CDialog
{
public:
	CDlgRoutingCableByParamChild(UINT nIDTemplate, CWnd* pParentWnd = NULL);

public:
	CDlgRoutingCableByParam *m_pParentDlg;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParamChild)	
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_VIRTUAL

public:
	IKSMDCCableDesignParam* GetParentCableDesignParamPt();
};

//===================================================================================================
class CDlgRoutingCableByParam_IT : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_IT(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_IT)
	enum { IDD = IDD_ROUTCAB_IT };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_IT)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_IT)
// 	afx_msg void OnBnClickedTest();
// 	afx_msg void OnSelChangeCmbTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_TAC : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_TAC(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_TAC)
	enum { IDD = IDD_ROUTCAB_TAC };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_TAC)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_TAC)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_BAT : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_BAT(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_BAT)
	enum { IDD = IDD_ROUTCAB_BAT };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_BAT)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_BAT)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_HVDC : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_HVDC(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_HVDC)
	enum { IDD = IDD_ROUTCAB_HVDC };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_HVDC)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_HVDC)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_UPS : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_UPS(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_UPS)
	enum { IDD = IDD_ROUTCAB_UPS };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_UPS)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_UPS)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_ITPDRH : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_ITPDRH(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_ITPDRH)
	enum { IDD = IDD_ROUTCAB_ITPDRH };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_ITPDRH)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_ITPDRH)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_ITPDRU : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_ITPDRU(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_ITPDRU)
	enum { IDD = IDD_ROUTCAB_ITPDRU };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_ITPDRU)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_ITPDRU)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_FC : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_FC(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_FC)
	enum { IDD = IDD_ROUTCAB_FC };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_FC)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_FC)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_ZM : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_ZM(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_ZM)
	enum { IDD = IDD_ROUTCAB_ZM };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_ZM)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_ZM)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_MJ : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_MJ(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_MJ)
	enum { IDD = IDD_ROUTCAB_MJ };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_MJ)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_MJ)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_JJAN : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_JJAN(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_JJAN)
	enum { IDD = IDD_ROUTCAB_JJAN };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_JJAN)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_JJAN)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_GK : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_GK(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_GK)
	enum { IDD = IDD_ROUTCAB_GK };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_GK)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_GK)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_JDX : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_JDX(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_JDX)
	enum { IDD = IDD_ROUTCAB_JDX };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_JDX)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_JDX)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================
class CDlgRoutingCableByParam_WX : public CDlgRoutingCableByParamChild
{
public:
	CDlgRoutingCableByParam_WX(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam_WX)
	enum { IDD = IDD_ROUTCAB_WX };
	//}}AFX_DATA

public:
	CRoutCabEditCtrl	m_editTest;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam_WX)
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam_WX)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();
};

//===================================================================================================

class CDlgRoutingCableByParam : public CDialog
{
public:
	CDlgRoutingCableByParam(CWnd* pParent = NULL); 

	//{{AFX_DATA(CDlgRoutingCableByParam)
	enum { IDD = IDD_ROUTINGCABLEBYPARAM };
	//}}AFX_DATA

	friend CDlgRoutingCableByParamChild;

public:
	IKSMDCCableDesignParam m_stuCableDesignParam;

private:
	CTreeCtrl	m_treeCatalogue;

public:
	// 子对话框
	CDlgRoutingCableByParam_IT			m_dlgIT;
	CDlgRoutingCableByParam_TAC			m_dlgTAC;
	CDlgRoutingCableByParam_BAT			m_dlgBAT;
	CDlgRoutingCableByParam_HVDC		m_dlgHVDC;
	CDlgRoutingCableByParam_UPS			m_dlgUPS;
	CDlgRoutingCableByParam_ITPDRH		m_dlgITPDRH;
	CDlgRoutingCableByParam_ITPDRU		m_dlgITPDRU;
	CDlgRoutingCableByParam_FC			m_dlgFC;
	CDlgRoutingCableByParam_ZM			m_dlgZM;
	CDlgRoutingCableByParam_MJ			m_dlgMJ;
	CDlgRoutingCableByParam_JJAN		m_dlgJJAN;
	CDlgRoutingCableByParam_GK			m_dlgGK;
	CDlgRoutingCableByParam_JDX			m_dlgJDX;
	CDlgRoutingCableByParam_WX			m_dlgWX;

protected:
	//{{AFX_VIRTUAL(CDlgRoutingCableByParam)	
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CDlgRoutingCableByParam)
	afx_msg void OnDestroy();
	afx_msg void OnSelChangedTreeCatalogue(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	// 更新控件的可用性
	void UpdateDlgCtrlEnalbe();

	// 隐藏所有子对话框
	void HideAllSubDlg();
	// 显示子对话框
	void ShowSubDlg(int nSubDlgID);
	// 根据目录树选中状态显示子对话框
	void ShowSubDlgByCatalogueSel();

protected:
	// 初始化布线项目数据信息
	void InitRoutCabProjDataInf();

protected:
	CIKSMDCCableDataMethodMgr m_MDCCableDMMgr;
};

//===================================================================================================


