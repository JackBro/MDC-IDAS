//===================================================================================================
// Summary:
//		MDCIDAS的入口函数
// Date:
//		2015-12-15
// Author:
//		Wangshiping
//===================================================================================================

#include "stdafx.h"
#include "MenuHandler.h"
#include "Global.h"
#include "MDCIDAS.h"
#include "CableGlobal.h"
#include "DesignGlobal.h"
#include "IKSSmartCableDataMethodMgrAPI.h"

//===================================================================================================

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//===================================================================================================

CMDCIDASApp theApp;
CMenuHandler *g_pMenuHandler = NULL;
ULONG_PTR g_gdiplusToken = 0;	

// 发送数据的结构
DWORD g_dwSendSize = 0;
DWORD g_dwSendTotal = 102400;
BYTE *g_pSendBuffer = NULL;


//===================================================================================================

BEGIN_MESSAGE_MAP(CMDCIDASApp, CWinApp)
END_MESSAGE_MAP()

//===================================================================================================

extern "C" int user_initialize()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// 初始化RichEdit
	if (!AfxInitRichEdit())
		return -1;

	//初始化通信端口
	if (!AfxSocketInit())
		return -1;

	CoInitialize(NULL);

	// 设置当前模块路径
	CString strMainPath;
	GetMainModulePath(strMainPath, (HMODULE)theApp.m_hInstance);
	IKS_SMARTCABLINGGLOBAL::SetCurModulePath(strMainPath);


	// 创建线缆数据方法的管理器
	IIKSSmartCableDataMethodMgr *pIKSHT505CableDataMethodMgr = CreateIKSSmartCableDataMethodMgr();
	if (pIKSHT505CableDataMethodMgr != NULL)
	{
		pIKSHT505CableDataMethodMgr->Init();
	}

	// 初始化整机配置相关数据
	InitDesignGlobalData();

	g_pSendBuffer = new BYTE[g_dwSendTotal];

	if (g_pMenuHandler == NULL)
	{
		g_pMenuHandler = new CMenuHandler();
		g_pMenuHandler->Init();
	}
	
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&g_gdiplusToken, &gdiplusStartupInput, NULL);

	return 0;
}

extern "C" void user_terminate()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());	

	if (g_pMenuHandler != NULL)
	{
		g_pMenuHandler->UnInit();
		SAFE_DELETE_POINTER(g_pMenuHandler);
	}

	SAFE_DELETE_ARRAY(g_pSendBuffer);

	IIKSSmartCableDataMethodMgr *pIKSHT505CableDataMethodMgr = GetIKSSmartCableDataMethodMgr();
	if (pIKSHT505CableDataMethodMgr != NULL)
	{
		pIKSHT505CableDataMethodMgr->UnInit();
		DestroyIKSSmartCableDataMethodMgr();
	}

	if (g_gdiplusToken != 0)
	{
		GdiplusShutdown(g_gdiplusToken);
		g_gdiplusToken = 0;
	}

	CoUninitialize();
}

//===================================================================================================

CMDCIDASApp::CMDCIDASApp()
{
}

BOOL CMDCIDASApp::InitInstance()
{
	CWinApp::InitInstance();
	return TRUE;
}

BOOL CMDCIDASApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
