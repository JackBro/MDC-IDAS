//===================================================================================================
// Summary:
//		�˵��Լ�������Ӧ����
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

// ��Ӳ˵���
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
	AfxMessageBox(L"���1115");
}

BOOL CMenuHandler::Init()
{
	ProFileName Msg = L"Msg_MDCIDAS.txt";

	char szMDCIDASMenuName[] = "MDCIDASMenuName";
	ProMenubarMenuAdd(szMDCIDASMenuName, "MI_MDCIDAS", "Utilities", PRO_B_TRUE, Msg);

	// �û���¼
	AddMenuItem(szMDCIDASMenuName, "MI_UserLogin", Test, MainAccessAvailable, Msg);
	// �½���Ŀ
	AddMenuItem(szMDCIDASMenuName, "MI_NewProject", Test, MainAccessAvailable, Msg);
	// ���붩������ɼ���
	AddMenuItem(szMDCIDASMenuName, "MI_ImportOrderTable", Test, MainAccessAvailable, Msg);
	// ��������ͼ���
	AddMenuItem(szMDCIDASMenuName, "MI_LayoutDesign", Test, MainAccessAvailable, Msg);

	// ��������ͼ���
	char szModelDesignChildMenuName[] = "MIModelDesignChildMenuName";
	ProMenubarmenuMenuAdd(szMDCIDASMenuName, szModelDesignChildMenuName, "MI_ModelDesign", NULL, PRO_B_TRUE, Msg);
	{
		// ģ�黯����ѡ��
		AddMenuItem(szModelDesignChildMenuName, "MI_SelectModelType", Test, MainAccessAvailable, Msg);
		// ������ģ�����
		AddMenuItem(szModelDesignChildMenuName, "MI_ParametricDesign", Test, MainAccessAvailable, Msg);
		// �������ýṹģ������
		AddMenuItem(szModelDesignChildMenuName, "MI_ModelBuild", Test, MainAccessAvailable, Msg);
		// ��װ�������ƽṹ��
		AddMenuItem(szModelDesignChildMenuName, "MI_NewCustomModel", Test, MainAccessAvailable, Msg);
	}
	// �������ܲ���
	char szCableOperatorChildMenuName[] = "MICableOperatorChildMenuName";
	ProMenubarmenuMenuAdd(szMDCIDASMenuName, szCableOperatorChildMenuName, "MI_CableOperator", NULL, PRO_B_TRUE, Msg);
	{
		// ���ѡ�������ܲ���
		AddMenuItem(szCableOperatorChildMenuName, "MI_CableDesign", Test, MainAccessAvailable, Msg);
		// ����λ�õ����ɾ��
		AddMenuItem(szCableOperatorChildMenuName, "MI_DeleteCablePoint", OnDeleteCablePointActFn, MainAccessAvailable, Msg);
		// ����ͳ�ƻ��ܱ�
		AddMenuItem(szCableOperatorChildMenuName, "MI_ExportCableTable", Test, MainAccessAvailable, Msg);
	}
	// ����ͼ��ϸ���
	char szDrawingOperatorChildMenuName[] = "MIDrawingOperatorChildMenuName";
	ProMenubarmenuMenuAdd(szMDCIDASMenuName, szDrawingOperatorChildMenuName, "MI_DrawingOperator", NULL, PRO_B_TRUE, Msg);
	{
		// ��������ͼ���嵥
		AddMenuItem(szDrawingOperatorChildMenuName, "MI_ExportNewModelList", Test, MainAccessAvailable, Msg);
		// ����ͼ�Ų������滻
		AddMenuItem(szDrawingOperatorChildMenuName, "MI_ImportModel", Test, MainAccessAvailable, Msg);
		// ��������ͼ�Զ�����
		AddMenuItem(szDrawingOperatorChildMenuName, "MI_CreateDrawing", Test, MainAccessAvailable, Msg);
		// �����ṹ������ͼ�Զ�����
		AddMenuItem(szDrawingOperatorChildMenuName, "MI_CreateNewDrawing", Test, MainAccessAvailable, Msg);
		// �����嵥����
		AddMenuItem(szDrawingOperatorChildMenuName, "MI_CreateSettingList", Test, MainAccessAvailable, Msg);
		// �����ṹ���嵥����
		AddMenuItem(szDrawingOperatorChildMenuName, "MI_CreateNewList", Test, MainAccessAvailable, Msg);
	}
	// ��������ɼ���ģ�嵼��
	AddMenuItem(szMDCIDASMenuName, "MI_ExportOrderTemplate", Test, MainAccessAvailable, Msg);
	// ������ѯ
	char szOrderQueryChildMenuName[] = "MIOrderQueryChildMenuName";
	ProMenubarmenuMenuAdd(szMDCIDASMenuName, szOrderQueryChildMenuName, "MI_OrderQuery", NULL, PRO_B_TRUE, Msg);
	{
		// ��Ŀ��ѯ
		AddMenuItem(szOrderQueryChildMenuName, "MI_ProjectQuery", Test, MainAccessAvailable, Msg);
		char szStatisticsQueryChildMenuName[] = "MIStatisticsQueryChildMenuName";
		ProMenubarmenuMenuAdd(szOrderQueryChildMenuName, szStatisticsQueryChildMenuName, "MI_StatisticsQuery", NULL, PRO_B_TRUE, Msg);
		{
			// ����Ŀͳ�Ʋ�ѯ
			AddMenuItem(szStatisticsQueryChildMenuName, "MI_SQByProject", Test, MainAccessAvailable, Msg);
			// ���û�ͳ�Ʋ�ѯ
			AddMenuItem(szStatisticsQueryChildMenuName, "MI_SQByUser", Test, MainAccessAvailable, Msg);
			// ������ͳ�Ʋ�ѯ
			AddMenuItem(szStatisticsQueryChildMenuName, "MI_SQByCode", Test, MainAccessAvailable, Msg);
		}
	}
	// ���ļ�����
	char szLibFileMgrChildMenuName[] = "MILibFileMgrChildMenuName";
	ProMenubarmenuMenuAdd(szMDCIDASMenuName, szLibFileMgrChildMenuName, "MI_LibFileMgr", NULL, PRO_B_TRUE, Msg);
	{
		// �û�Ȩ�޹���
		AddMenuItem(szLibFileMgrChildMenuName, "MI_UserPermissionMgr", Test, MainAccessAvailable, Msg);
		// �ṹ���������ݿ��ѯ��ά��
		AddMenuItem(szLibFileMgrChildMenuName, "MI_StructureCodeLibQuery", Test, MainAccessAvailable, Msg);
		// ���´������ݿ��ѯ��ά��
		AddMenuItem(szLibFileMgrChildMenuName, "MI_CableCodeLibQuery", Test, MainAccessAvailable, Msg);
	}

	return TRUE;
}

void CMenuHandler::UnInit()
{
	// ������
}

//===================================================================================================

// ����λ�õ����ɾ��
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
		// ���µ�ǰװ�����ڵ�ģ������������������
		GetIKSSmartCableDataMethodMgr()->UpdateCurAsmMdlTreeHarnessCableData(FALSE);

		int nErrType = IKSUNWRAPCABERRT_OK;
		BOOL bResult = FALSE;
		if (pCable != NULL)
			bResult = GetIKSSmartCableDataMethodMgr()->UnwrapCurAsmCable(pCable, pCabLocStart, pCabLocEnd, &nErrType);
		else
			bResult = GetIKSSmartCableDataMethodMgr()->UnwrapCurAsmCable(pCabLocStart, pCabLocEnd, &nErrType);
		if (bResult)
		{
			// �ػ洰��
			IKS_SMARTCABLINGGLOBAL::RepaintCurrentPreWindow();
		}
		else
		{
			switch (nErrType)
			{
			case IKSUNWRAPCABERRT_SELECTCABLE:
				AfxMessageBox(_T("������ʧ��!ʰȡ�ĵ��²���ȷ!"));
				break;
			case IKSUNWRAPCABERRT_SELECTCABLELOC:
				AfxMessageBox(_T("������ʧ��!ʰȡ�ĵ���λ�ò���ȷ!"));
				break;
			case IKSUNWRAPCABERRT_SELECTCABLELOC_DIFFHARN:
				AfxMessageBox(_T("������ʧ��!ʰȡ�ĵ��������λ�����ڲ�ͬ������!"));
				break;
			case IKSUNWRAPCABERRT_NOTFINDCABLE:
				AfxMessageBox(_T("������ʧ��!δ�ҵ�����!"));
				break;
			case IKSUNWRAPCABERRT_SAMECABLELOC:
				AfxMessageBox(_T("������ʧ��!ʰȡ����������λ����ͬ!"));
				break;
			case IKSUNWRAPCABERRT_NOTFINDCABLELOC:
				AfxMessageBox(_T("������ʧ��!δ�ҵ�����λ��(ѡ�еĵ���λ�ÿ��ܲ�����ѡ�еĵ���)!"));
				break;
			case IKSUNWRAPCABERRT_CABLELOCISNOTFROMNETWORK:
				AfxMessageBox(_T("������ʧ��!�����а��������ڵ��������λ��!"));
				break;
			default:
				AfxMessageBox(_T("������ʧ��!"));
				break;
			}
		}
	}

	SAFE_DELETE_SELECTION(pCable);
	SAFE_DELETE_SELECTION(pCabLocStart);
	SAFE_DELETE_SELECTION(pCabLocEnd);
}

//===================================================================================================
