//===================================================================================================
// Summary:
//		菜单以及命令响应函数
// Date:
//		2015-12-15
// Author:
//		Wangshiping
//===================================================================================================

#include "stdafx.h"
#include "MDCIDAS.h"
#include "MenuHandler.h"
#include "IKSSmartCableDataMethodMgrAPI.h"
#include "CablePreGlobal.h"

//===================================================================================================

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//===================================================================================================

uiCmdAccessState MainAccessAvailable(uiCmdAccessMode access_mode)
{
	access_mode;
	return ACCESS_AVAILABLE;
}

uiCmdAccessState UserAccessDefault(uiCmdAccessMode access_mode)
{
	UNUSED_ALWAYS(access_mode);
	return ACCESS_AVAILABLE;
}

uiCmdAccessState UserAccessPartDefault(uiCmdAccessMode access_mode)
{
	access_mode;
	if (GetCurrentPart() == NULL)
		return ACCESS_UNAVAILABLE;

	return ACCESS_AVAILABLE;
}

uiCmdAccessState UserAccessAsmbDefault(uiCmdAccessMode access_mode)
{
	access_mode;
	if (GetCurrentAssembly() == NULL)
		return ACCESS_UNAVAILABLE;

	return ACCESS_AVAILABLE;
}

uiCmdAccessState UserAccessPartAsmbDefault(uiCmdAccessMode access_mode)
{
	access_mode;
	if (GetCurrentPart()==NULL && GetCurrentAssembly()==NULL)
		return ACCESS_UNAVAILABLE;

	return ACCESS_AVAILABLE;
}

typedef void (*actionFunc)();
typedef uiCmdAccessState (*accessFunc)(uiCmdAccessMode mode);

// 添加菜单项
void AddMenuItem(char *menuName, char *itemName, actionFunc menuitemAction, accessFunc menuitemAccess,  ProFileName msgFile)
{
	string strCmd, strName, strLabel, strHelp, strTip;
	uiCmdCmdId uiMenuBottonId;
	strLabel = string(itemName);
	strCmd = string("cmd") + strLabel;
	ProError status = ProCmdActionAdd((char*)strCmd.c_str(), (uiCmdCmdActFn)menuitemAction, uiProeImmediate, menuitemAccess, PRO_B_TRUE, PRO_B_TRUE, &uiMenuBottonId);
	strName = strLabel + string("Name");
	strHelp = strLabel + string(" Operator");
	strTip = string("Show ") + strHelp;
	status = ProMenubarmenuPushbuttonAdd(menuName, (char*)strName.c_str(), (char*)strLabel.c_str(), (char*)strHelp.c_str(), NULL, PRO_B_TRUE, uiMenuBottonId, msgFile);
	
}

//===================================================================================================

void Test()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	AfxMessageBox(L"你好1115");
}

BOOL CMenuHandler::Init()
{
	ProFileName Msg = L"Msg_MDCIDAS.txt";

	char szMDCIDASMenuName[] = "MDCIDASMenuName";
	ProMenubarMenuAdd(szMDCIDASMenuName, "MI_MDCIDAS", "Utilities", PRO_B_TRUE, Msg);

	// 用户登录
	AddMenuItem(szMDCIDASMenuName, "MI_UserLogin", Test, MainAccessAvailable, Msg);
	// 新建项目
	AddMenuItem(szMDCIDASMenuName, "MI_NewProject", Test, MainAccessAvailable, Msg);
	// 导入订单需求采集表
	AddMenuItem(szMDCIDASMenuName, "MI_ImportOrderTable", Test, MainAccessAvailable, Msg);
	// 整机布局图设计
	AddMenuItem(szMDCIDASMenuName, "MI_LayoutDesign", Test, MainAccessAvailable, Msg);

	// 整机布局图设计
	char szModelDesignChildMenuName[] = "MIModelDesignChildMenuName";
	ProMenubarmenuMenuAdd(szMDCIDASMenuName, szModelDesignChildMenuName, "MI_ModelDesign", NULL, PRO_B_TRUE, Msg);
	{
		// 模块化配置选型
		AddMenuItem(szModelDesignChildMenuName, "MI_SelectModelType", Test, MainAccessAvailable, Msg);
		// 参数化模型设计
		AddMenuItem(szModelDesignChildMenuName, "MI_ParametricDesign", Test, MainAccessAvailable, Msg);
		// 整机配置结构模型生成
		AddMenuItem(szModelDesignChildMenuName, "MI_ModelBuild", Test, MainAccessAvailable, Msg);
		// 总装新增定制结构件
		AddMenuItem(szModelDesignChildMenuName, "MI_NewCustomModel", Test, MainAccessAvailable, Msg);
	}
	// 电缆智能布线
	char szCableOperatorChildMenuName[] = "MICableOperatorChildMenuName";
	ProMenubarmenuMenuAdd(szMDCIDASMenuName, szCableOperatorChildMenuName, "MI_CableOperator", NULL, PRO_B_TRUE, Msg);
	{
		// 规格选型与智能布线
		AddMenuItem(szCableOperatorChildMenuName, "MI_CableDesign", Test, MainAccessAvailable, Msg);
		// 电缆位置点快速删除
		AddMenuItem(szCableOperatorChildMenuName, "MI_DeleteCablePoint", OnDeleteCablePointActFn, MainAccessAvailable, Msg);
		// 电缆统计汇总表
		AddMenuItem(szCableOperatorChildMenuName, "MI_ExportCableTable", Test, MainAccessAvailable, Msg);
	}
	// 工程图详细设计
	char szDrawingOperatorChildMenuName[] = "MIDrawingOperatorChildMenuName";
	ProMenubarmenuMenuAdd(szMDCIDASMenuName, szDrawingOperatorChildMenuName, "MI_DrawingOperator", NULL, PRO_B_TRUE, Msg);
	{
		// 导出新增图号清单
		AddMenuItem(szDrawingOperatorChildMenuName, "MI_ExportNewModelList", Test, MainAccessAvailable, Msg);
		// 导入图号并批量替换
		AddMenuItem(szDrawingOperatorChildMenuName, "MI_ImportModel", Test, MainAccessAvailable, Msg);
		// 整机工程图自动生成
		AddMenuItem(szDrawingOperatorChildMenuName, "MI_CreateDrawing", Test, MainAccessAvailable, Msg);
		// 新增结构件工程图自动生成
		AddMenuItem(szDrawingOperatorChildMenuName, "MI_CreateNewDrawing", Test, MainAccessAvailable, Msg);
		// 配置清单生成
		AddMenuItem(szDrawingOperatorChildMenuName, "MI_CreateSettingList", Test, MainAccessAvailable, Msg);
		// 新增结构件清单生成
		AddMenuItem(szDrawingOperatorChildMenuName, "MI_CreateNewList", Test, MainAccessAvailable, Msg);
	}
	// 订单需求采集表模板导出
	AddMenuItem(szMDCIDASMenuName, "MI_ExportOrderTemplate", Test, MainAccessAvailable, Msg);
	// 订单查询
	char szOrderQueryChildMenuName[] = "MIOrderQueryChildMenuName";
	ProMenubarmenuMenuAdd(szMDCIDASMenuName, szOrderQueryChildMenuName, "MI_OrderQuery", NULL, PRO_B_TRUE, Msg);
	{
		// 项目查询
		AddMenuItem(szOrderQueryChildMenuName, "MI_ProjectQuery", Test, MainAccessAvailable, Msg);
		char szStatisticsQueryChildMenuName[] = "MIStatisticsQueryChildMenuName";
		ProMenubarmenuMenuAdd(szOrderQueryChildMenuName, szStatisticsQueryChildMenuName, "MI_StatisticsQuery", NULL, PRO_B_TRUE, Msg);
		{
			// 按项目统计查询
			AddMenuItem(szStatisticsQueryChildMenuName, "MI_SQByProject", Test, MainAccessAvailable, Msg);
			// 按用户统计查询
			AddMenuItem(szStatisticsQueryChildMenuName, "MI_SQByUser", Test, MainAccessAvailable, Msg);
			// 按代码统计查询
			AddMenuItem(szStatisticsQueryChildMenuName, "MI_SQByCode", Test, MainAccessAvailable, Msg);
		}
	}
	// 库文件管理
	char szLibFileMgrChildMenuName[] = "MILibFileMgrChildMenuName";
	ProMenubarmenuMenuAdd(szMDCIDASMenuName, szLibFileMgrChildMenuName, "MI_LibFileMgr", NULL, PRO_B_TRUE, Msg);
	{
		// 用户权限管理
		AddMenuItem(szLibFileMgrChildMenuName, "MI_UserPermissionMgr", Test, MainAccessAvailable, Msg);
		// 结构件代码数据库查询及维护
		AddMenuItem(szLibFileMgrChildMenuName, "MI_StructureCodeLibQuery", Test, MainAccessAvailable, Msg);
		// 电缆代码数据库查询及维护
		AddMenuItem(szLibFileMgrChildMenuName, "MI_CableCodeLibQuery", Test, MainAccessAvailable, Msg);
	}

	return TRUE;
}

void CMenuHandler::UnInit()
{
	// 测试行
}

//===================================================================================================

// 电缆位置点快速删除
void OnDeleteCablePointActFn()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (!GetIKSSmartCableDataMethodMgr()->GetCableValidLicense())
		return;

	ProSelection pCable = NULL;
	ProSelection pCabLocStart = NULL;
	ProSelection pCabLocEnd = NULL;
	if (IKS_SMARTCABLINGGLOBAL::SelectOneObject(pCable, "location,cable"))
	{
		if (IKS_SMARTCABLINGGLOBAL::SelectOneObject(pCabLocStart, "location"))
		{
			if (pCable->sel_type == SEL_3D_LOCATION)	// location=SEL_3D_LOCATION
			{
				pCabLocEnd = pCabLocStart;
				pCabLocStart = pCable;
				pCable = NULL;
			}
			else
			{
				IKS_SMARTCABLINGGLOBAL::SelectOneObject(pCabLocEnd, "location");
			}
		}
	}

	if (pCabLocStart!=NULL && pCabLocEnd!=NULL)
	{
		// 更新当前装配体内的模型树和线束电缆数据
		GetIKSSmartCableDataMethodMgr()->UpdateCurAsmMdlTreeHarnessCableData(FALSE);

		int nErrType = IKSUNWRAPCABERRT_OK;
		BOOL bResult = FALSE;
		if (pCable != NULL)
			bResult = GetIKSSmartCableDataMethodMgr()->UnwrapCurAsmCable(pCable, pCabLocStart, pCabLocEnd, &nErrType);
		else
			bResult = GetIKSSmartCableDataMethodMgr()->UnwrapCurAsmCable(pCabLocStart, pCabLocEnd, &nErrType);
		if (bResult)
		{
			// 重绘窗口
			IKS_SMARTCABLINGGLOBAL::RepaintCurrentPreWindow();
		}
		else
		{
			switch (nErrType)
			{
			case IKSUNWRAPCABERRT_SELECTCABLE:
				AfxMessageBox(_T("解绑电缆失败!拾取的电缆不正确!"));
				break;
			case IKSUNWRAPCABERRT_SELECTCABLELOC:
				AfxMessageBox(_T("解绑电缆失败!拾取的电缆位置不正确!"));
				break;
			case IKSUNWRAPCABERRT_SELECTCABLELOC_DIFFHARN:
				AfxMessageBox(_T("解绑电缆失败!拾取的电缆与电缆位置属于不同的线束!"));
				break;
			case IKSUNWRAPCABERRT_NOTFINDCABLE:
				AfxMessageBox(_T("解绑电缆失败!未找到电缆!"));
				break;
			case IKSUNWRAPCABERRT_SAMECABLELOC:
				AfxMessageBox(_T("解绑电缆失败!拾取的两个电缆位置相同!"));
				break;
			case IKSUNWRAPCABERRT_NOTFINDCABLELOC:
				AfxMessageBox(_T("解绑电缆失败!未找到电缆位置(选中的电缆位置可能不属于选中的电缆)!"));
				break;
			case IKSUNWRAPCABERRT_CABLELOCISNOTFROMNETWORK:
				AfxMessageBox(_T("解绑电缆失败!电缆中包含不属于电缆网络的位置!"));
				break;
			default:
				AfxMessageBox(_T("解绑电缆失败!"));
				break;
			}
		}
	}

	SAFE_DELETE_SELECTION(pCable);
	SAFE_DELETE_SELECTION(pCabLocStart);
	SAFE_DELETE_SELECTION(pCabLocEnd);
}

//===================================================================================================
