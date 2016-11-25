//===================================================================================================
// File:
//		TotalUnitBuilder.cpp
// Summary:
//		整机配置结构模型生成器
// Date:
//		2016-11-16
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#include "stdafx.h"
#include "PCLCsys.h"
#include "TotalUnitBuilder.h"

//===================================================================================================

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//===================================================================================================

CTotalUnitBuilder::CTotalUnitBuilder()
{
	;
}

CTotalUnitBuilder::~CTotalUnitBuilder()
{
	;
}

// 生成模型
bool CTotalUnitBuilder::BuildModel(
	const TotalUnitConfiguration &totalUnitConfig					// 整机配置
	)
{
	ProMdl pTopAsm = LoadMdlByPartNo(totalUnitConfig.strAsmName);
	if (NULL == pTopAsm)
		return FALSE;
	for (size_t i=0; i<totalUnitConfig.arrModelConfig.size(); i++)
	{
		AssembleModel((ProAssembly)pTopAsm, totalUnitConfig.arrModelConfig[i]);
	}

	// 显示模型
	ProName szMdlName = {0};
	wcsncpy_s(szMdlName, PRO_NAME_SIZE, (LPCTSTR)totalUnitConfig.strAsmName, _TRUNCATE);
	int nActiveWindowID;
	ProObjectwindowCreate(szMdlName, PRO_ASSEMBLY, &nActiveWindowID);
	ProWindowActivate(nActiveWindowID);
	ProMdlDisplay(pTopAsm);

	return true;
}

// 根据图号获取模型
ProMdl CTotalUnitBuilder::LoadMdlByPartNo(
	const CString &strPartNo										// 图号(in)
	)
{
	ProPath szCurDir;
	ProDirectoryCurrentGet(szCurDir);
	CString strLibPath = CString(szCurDir) + CString(L"\\") + strPartNo + CString(L".asm");
	ProPath szMdlPath = {0};
	wcsncpy_s(szMdlPath, PRO_PATH_SIZE, (LPCTSTR)strLibPath, _TRUNCATE);
	ProMdl pMdl = NULL;
	ProMdlLoad(szMdlPath, PRO_MDL_ASSEMBLY, PRO_B_FALSE, &pMdl);
	if (NULL == pMdl)
	{
		ProName szMdlName = {0};
		wcsncpy_s(szMdlName, PRO_NAME_SIZE, (LPCTSTR)strPartNo, _TRUNCATE);
		ProMdlLoad(szMdlName, PRO_MDL_ASSEMBLY, PRO_B_FALSE, &pMdl);
	}

	// 临时用本地的模型
	if (NULL == pMdl)
	{
		CString strLibPath = CString(L"E:\\ProETest\\MDC-IDAS\\ZTE_LIB\\") + strPartNo + CString(L".asm");
		wcsncpy_s(szMdlPath, PRO_PATH_SIZE, (LPCTSTR)strLibPath, _TRUNCATE);
		ProMdlLoad(szMdlPath, PRO_MDL_ASSEMBLY, PRO_B_FALSE, &pMdl);
	}

	return pMdl;
}

// 装配模型
bool CTotalUnitBuilder::AssembleModel(
	ProAssembly pTopAsm,											// 总组件
	const ModelConfiguration &mdlConfig								// 模型配置
	)
{
	bool bRet = false;
	switch (mdlConfig.nModelType)
	{
	case DMT_IT:						// 服务器机柜
		bRet = AssembleModel_IT(pTopAsm, mdlConfig);
		break;
	case DMT_MJT:						// 管控柜
		break;
	case DMT_CASO4_FLOOR:				// 硫酸钙地板
		break;
	case DMT_STEEL_FLOOR:				// 全钢通风地板
		break;
	case DMT_COLD_FRONT_DOOR:			// 冷通道前门
		break;
	case DMT_COLD_BACK_DOOR:			// 冷通道后门
		break;
	case DMT_LEFT_FRAME:				// 左框架
		break;
	case DMT_RIGHT_FRAME:				// 右框架
		break;
	case DMT_FLIP_WINDOW:				// 翻转顶窗
		break;
	case DMT_FIXED_WINDOW:				// 固定顶窗
		break;
	case DMT_FOOTSTEP:					// 踏步
		break;
	default:
		break;
	}
	return bRet;
}

// 装配模型
bool CTotalUnitBuilder::AssembleModel(
	ProAssembly pTopAsm,											// 总组件(in)
	ProMdl pCompMdl,												// 元件(in)
	const IKSCsysData &asmPosition									// 装配位置(in)
	)
{
	if (NULL == pTopAsm || NULL == pCompMdl)
		return false;

	// 生成装配坐标系
	ProSelection pSelTopAsm = NULL;
	ProModelitem mdlItem;
	ProMdlToModelitem(pTopAsm, &mdlItem);
	ProSelectionAlloc(NULL, &mdlItem, &pSelTopAsm);
	ProCsys pDefaultCsys = NULL;
	CPCLCsys::GetSolidDefaultCsys(pTopAsm, pDefaultCsys);
	if (NULL == pDefaultCsys)
		return false;
	ProModelitem csysItem;
	ProCsysToGeomitem(pTopAsm, pDefaultCsys, &csysItem);
	ProSelection pSelAsmCsysRef = NULL;
	ProSelectionAlloc(NULL, &csysItem, &pSelAsmCsysRef);
	ProName szCompMdlName = {0};
	ProMdlNameGet(pCompMdl, szCompMdlName);
	CString strAsmCsysName = CString(L"CS_") + CString(szCompMdlName);
	ProName szAsmCsysNameExpected = {0}, szAsmCsysName = {0};
	wcsncpy_s(szAsmCsysNameExpected, PRO_NAME_SIZE, strAsmCsysName, _TRUNCATE);
	CPCLFeature::GetNewFeatureName(pTopAsm, szAsmCsysNameExpected, szAsmCsysName, FALSE);
	if (CString(szAsmCsysNameExpected).CompareNoCase(szAsmCsysName) != 0)
	{
		wcsncpy_s(szAsmCsysNameExpected, PRO_NAME_SIZE, strAsmCsysName+L"_", _TRUNCATE);
		CPCLFeature::GetNewFeatureName(pTopAsm, szAsmCsysNameExpected, szAsmCsysName, TRUE);
	}
	ProFeature newCsysFeature;
	CPCLCsys::CreateCSys(asmPosition, pSelTopAsm, pSelAsmCsysRef, szAsmCsysName, newCsysFeature);
	// 获取装配坐标系
	vector<ProGeomitem> arrAsmCsysItem;
	CPCLFeature::GetFeatureGeomItems(newCsysFeature, PRO_CSYS, arrAsmCsysItem);
	if (arrAsmCsysItem.empty())
		return false;
	ProSelection pSelAsmCsys = NULL;
	ProSelectionAlloc(NULL, &arrAsmCsysItem[0], &pSelAsmCsys);

	// 装配模型
	SVMATRIX defaultMatrix;
	ProAsmcomp newAsmcomp;
	ProAsmcompAssemble(pTopAsm, (ProSolid)pCompMdl, defaultMatrix.m, &newAsmcomp);

	// 获取元件装配坐标系
	ProSelection pSelCompCsys = NULL;
	ProGeomitem compCsysItem;
	ProName szCompCsysName = {0};
	wcsncpy_s(szCompCsysName, PRO_NAME_SIZE, g_strCompCsysName, _TRUNCATE);
	if (ProModelitemByNameInit(pCompMdl, PRO_CSYS, szCompCsysName, &compCsysItem) != PRO_TK_NO_ERROR)
	{
		CPCLCsys::GetSolidDefaultCsys((ProSolid)pCompMdl, pDefaultCsys);
		if (NULL == pDefaultCsys)
			return false;
		ProCsysToGeomitem((ProSolid)pCompMdl, pDefaultCsys, &compCsysItem);
	}
	ProSelectionAlloc(NULL, &compCsysItem, &pSelCompCsys);

	// 添加坐标系装配约束
	CPCLAssembly pclAsm;
	pclAsm.AddCsysConstraint(newAsmcomp, pTopAsm, pSelAsmCsys, pSelCompCsys);

	return true;
}

// 装配服务器机柜模型
bool CTotalUnitBuilder::AssembleModel_IT(
	ProAssembly pTopAsm,											// 总组件
	const ModelConfiguration &mdlConfig								// 模型配置
	)
{
	if (NULL == pTopAsm)
		return false;

	// 不需要配置
	if (!mdlConfig.bIsCreate)
		return true;

	if (mdlConfig.strTempPartNo.IsEmpty())
	{
		// 如果正式图号为空，则返回
		if (mdlConfig.strFormalPartNo.IsEmpty())
			return false;

		// 加载模型
		ProMdl pCompMdl = LoadMdlByPartNo(mdlConfig.strFormalPartNo);
		if (NULL == pCompMdl)
			return false;
		// 装配至组件
		for (size_t i=0; i<mdlConfig.arrPosition.size(); i++)
		{
			AssembleModel(pTopAsm, pCompMdl, mdlConfig.arrPosition[i]);
		}

	}
	else
	{
		// 如果临时图号不为空，则利用模板模型，生成参数化的模型
	}

	return true;
}

// 测试生成模型
bool CTotalUnitBuilder::TestBuildModel()
{
	// 整机配置
	TotalUnitConfiguration totalUnitConfig;
	totalUnitConfig.strAsmName = _T("TOTAL_MODEL_00001");
	ModelConfiguration modelConfig;
	modelConfig.nMajorClass = -1;
	modelConfig.nModelType = DMT_IT;
	modelConfig.bIsCreate = true;
	modelConfig.strTempPartNo = _T("");
	modelConfig.strFormalPartNo = _T("JIGUI_300X300X100");
	modelConfig.strPurchaseNo = _T("CG_JIGUI_300X300X100");
	modelConfig.dHieght = 300.0;
	modelConfig.dWidth = 300.0;
	modelConfig.dDepth = 100.0;
	modelConfig.arrPosition.resize(2);
	modelConfig.arrPosition[0].o = SVDOUBLE3(0.0, 200.0, 0.0);
	modelConfig.arrPosition[0].x = SVDOUBLE3(1.0, 0.0, 0.0);
	modelConfig.arrPosition[0].y = SVDOUBLE3(0.0, 1.0, 0.0);
	modelConfig.arrPosition[0].z = SVDOUBLE3(0.0, 0.0, 1.0);
	modelConfig.arrPosition[1].o = SVDOUBLE3(1100.0, 0.0, 0.0);
	modelConfig.arrPosition[1].x = SVDOUBLE3(1.0, 0.0, 0.0);
	modelConfig.arrPosition[1].y = SVDOUBLE3(0.0, 1.0, 0.0);
	modelConfig.arrPosition[1].z = SVDOUBLE3(0.0, 0.0, 1.0);
	modelConfig.strRemark = _T("");
	totalUnitConfig.arrModelConfig.push_back(modelConfig);
	modelConfig.nMajorClass = -1;
	modelConfig.nModelType = DMT_IT;
	modelConfig.bIsCreate = true;
	modelConfig.strTempPartNo = _T("");
	modelConfig.strFormalPartNo = _T("JIGUI_300X200X100");
	modelConfig.strPurchaseNo = _T("CG_JIGUI_300X200X100");
	modelConfig.dHieght = 300.0;
	modelConfig.dWidth = 200.0;
	modelConfig.dDepth = 100.0;
	modelConfig.arrPosition.resize(1);
	modelConfig.arrPosition[0].o = SVDOUBLE3(300.0, 200.0, 0.0);
	modelConfig.arrPosition[0].x = SVDOUBLE3(1.0, 0.0, 0.0);
	modelConfig.arrPosition[0].y = SVDOUBLE3(0.0, 1.0, 0.0);
	modelConfig.arrPosition[0].z = SVDOUBLE3(0.0, 0.0, 1.0);
	modelConfig.strRemark = _T("");
	totalUnitConfig.arrModelConfig.push_back(modelConfig);
	modelConfig.nMajorClass = -1;
	modelConfig.nModelType = DMT_IT;
	modelConfig.bIsCreate = true;
	modelConfig.strTempPartNo = _T("");
	modelConfig.strFormalPartNo = _T("JIGUI_300X100X100");
	modelConfig.strPurchaseNo = _T("CG_JIGUI_300X100X100");
	modelConfig.dHieght = 300.0;
	modelConfig.dWidth = 100.0;
	modelConfig.dDepth = 100.0;
	modelConfig.arrPosition.resize(1);
	modelConfig.arrPosition[0].o = SVDOUBLE3(500.0, 200.0, 0.0);
	modelConfig.arrPosition[0].x = SVDOUBLE3(1.0, 0.0, 0.0);
	modelConfig.arrPosition[0].y = SVDOUBLE3(0.0, 1.0, 0.0);
	modelConfig.arrPosition[0].z = SVDOUBLE3(0.0, 0.0, 1.0);
	modelConfig.strRemark = _T("");
	totalUnitConfig.arrModelConfig.push_back(modelConfig);
	modelConfig.nMajorClass = -1;
	modelConfig.nModelType = DMT_IT;
	modelConfig.bIsCreate = true;
	modelConfig.strTempPartNo = _T("");
	modelConfig.strFormalPartNo = _T("JIGUI_300X400X100");
	modelConfig.strPurchaseNo = _T("CG_JIGUI_300X400X100");
	modelConfig.dHieght = 300.0;
	modelConfig.dWidth = 400.0;
	modelConfig.dDepth = 100.0;
	modelConfig.arrPosition.resize(4);
	modelConfig.arrPosition[0].o = SVDOUBLE3(600.0, 200.0, 0.0);
	modelConfig.arrPosition[0].x = SVDOUBLE3(1.0, 0.0, 0.0);
	modelConfig.arrPosition[0].y = SVDOUBLE3(0.0, 1.0, 0.0);
	modelConfig.arrPosition[0].z = SVDOUBLE3(0.0, 0.0, 1.0);
	modelConfig.arrPosition[1].o = SVDOUBLE3(1000.0, 200.0, 0.0);
	modelConfig.arrPosition[1].x = SVDOUBLE3(1.0, 0.0, 0.0);
	modelConfig.arrPosition[1].y = SVDOUBLE3(0.0, 1.0, 0.0);
	modelConfig.arrPosition[1].z = SVDOUBLE3(0.0, 0.0, 1.0);
	modelConfig.arrPosition[2].o = SVDOUBLE3(0.0, 0.0, 0.0);
	modelConfig.arrPosition[2].x = SVDOUBLE3(1.0, 0.0, 0.0);
	modelConfig.arrPosition[2].y = SVDOUBLE3(0.0, 1.0, 0.0);
	modelConfig.arrPosition[2].z = SVDOUBLE3(0.0, 0.0, 1.0);
	modelConfig.arrPosition[3].o = SVDOUBLE3(700.0, 0.0, 0.0);
	modelConfig.arrPosition[3].x = SVDOUBLE3(1.0, 0.0, 0.0);
	modelConfig.arrPosition[3].y = SVDOUBLE3(0.0, 1.0, 0.0);
	modelConfig.arrPosition[3].z = SVDOUBLE3(0.0, 0.0, 1.0);
	modelConfig.strRemark = _T("");
	totalUnitConfig.arrModelConfig.push_back(modelConfig);

	//LayoutData stuLayoutData;
	//stuLayoutData.dTotalLength = 1400.0;
	//stuLayoutData.dTotalWidth = 300.0;
	//stuLayoutData.strRemark = _T("");
	//LayoutItemData itemData;
	//itemData.nType = LIT_IT;
	//itemData.dWidth = 300.0;
	//itemData.dDepth = 100.0;
	//itemData.o = SVDOUBLE3(0.0, 200.0, 0.0);
	//itemData.x = SVDOUBLE3(1.0, 0.0, 0.0);
	//itemData.y = SVDOUBLE3(0.0, 1.0, 0.0);
	//stuLayoutData.arrItems.push_back(itemData);
	//itemData.nType = LIT_IT;
	//itemData.dWidth = 200.0;
	//itemData.dDepth = 100.0;
	//itemData.o = SVDOUBLE3(300.0, 200.0, 0.0);
	//itemData.x = SVDOUBLE3(1.0, 0.0, 0.0);
	//itemData.y = SVDOUBLE3(0.0, 1.0, 0.0);
	//stuLayoutData.arrItems.push_back(itemData);
	//itemData.nType = LIT_IT;
	//itemData.dWidth = 100.0;
	//itemData.dDepth = 100.0;
	//itemData.o = SVDOUBLE3(500.0, 200.0, 0.0);
	//itemData.x = SVDOUBLE3(1.0, 0.0, 0.0);
	//itemData.y = SVDOUBLE3(0.0, 1.0, 0.0);
	//stuLayoutData.arrItems.push_back(itemData);
	//itemData.nType = LIT_IT;
	//itemData.dWidth = 400.0;
	//itemData.dDepth = 100.0;
	//itemData.o = SVDOUBLE3(600.0, 200.0, 0.0);
	//itemData.x = SVDOUBLE3(1.0, 0.0, 0.0);
	//itemData.y = SVDOUBLE3(0.0, 1.0, 0.0);
	//stuLayoutData.arrItems.push_back(itemData);
	//itemData.nType = LIT_IT;
	//itemData.dWidth = 400.0;
	//itemData.dDepth = 100.0;
	//itemData.o = SVDOUBLE3(1000.0, 200.0, 0.0);
	//itemData.x = SVDOUBLE3(1.0, 0.0, 0.0);
	//itemData.y = SVDOUBLE3(0.0, 1.0, 0.0);
	//stuLayoutData.arrItems.push_back(itemData);
	//itemData.nType = LIT_IT;
	//itemData.dWidth = 400.0;
	//itemData.dDepth = 100.0;
	//itemData.o = SVDOUBLE3(0.0, 0.0, 0.0);
	//itemData.x = SVDOUBLE3(1.0, 0.0, 0.0);
	//itemData.y = SVDOUBLE3(0.0, 1.0, 0.0);
	//stuLayoutData.arrItems.push_back(itemData);
	//itemData.nType = LIT_IT;
	//itemData.dWidth = 400.0;
	//itemData.dDepth = 100.0;
	//itemData.o = SVDOUBLE3(700.0, 0.0, 0.0);
	//itemData.x = SVDOUBLE3(1.0, 0.0, 0.0);
	//itemData.y = SVDOUBLE3(0.0, 1.0, 0.0);
	//stuLayoutData.arrItems.push_back(itemData);
	//itemData.nType = LIT_IT;
	//itemData.dWidth = 300.0;
	//itemData.dDepth = 100.0;
	//itemData.o = SVDOUBLE3(1100.0, 0.0, 0.0);
	//itemData.x = SVDOUBLE3(1.0, 0.0, 0.0);
	//itemData.y = SVDOUBLE3(0.0, 1.0, 0.0);
	//stuLayoutData.arrItems.push_back(itemData);

	BuildModel(totalUnitConfig);
	return true;
}
