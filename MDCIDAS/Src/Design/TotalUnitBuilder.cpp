//===================================================================================================
// File:
//		TotalUnitBuilder.cpp
// Summary:
//		�������ýṹģ��������
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

// ����ģ��
bool CTotalUnitBuilder::BuildModel(
	const TotalUnitConfiguration &totalUnitConfig					// ��������
	)
{
	ProMdl pTopAsm = LoadMdlByPartNo(totalUnitConfig.strAsmName);
	if (NULL == pTopAsm)
		return FALSE;
	for (size_t i=0; i<totalUnitConfig.arrModelConfig.size(); i++)
	{
		AssembleModel((ProAssembly)pTopAsm, totalUnitConfig.arrModelConfig[i]);
	}

	// ��ʾģ��
	ProName szMdlName = {0};
	wcsncpy_s(szMdlName, PRO_NAME_SIZE, (LPCTSTR)totalUnitConfig.strAsmName, _TRUNCATE);
	int nActiveWindowID;
	ProObjectwindowCreate(szMdlName, PRO_ASSEMBLY, &nActiveWindowID);
	ProWindowActivate(nActiveWindowID);
	ProMdlDisplay(pTopAsm);

	return true;
}

// ����ͼ�Ż�ȡģ��
ProMdl CTotalUnitBuilder::LoadMdlByPartNo(
	const CString &strPartNo										// ͼ��(in)
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

	// ��ʱ�ñ��ص�ģ��
	if (NULL == pMdl)
	{
		CString strLibPath = CString(L"E:\\ProETest\\MDC-IDAS\\ZTE_LIB\\") + strPartNo + CString(L".asm");
		wcsncpy_s(szMdlPath, PRO_PATH_SIZE, (LPCTSTR)strLibPath, _TRUNCATE);
		ProMdlLoad(szMdlPath, PRO_MDL_ASSEMBLY, PRO_B_FALSE, &pMdl);
	}

	return pMdl;
}

// װ��ģ��
bool CTotalUnitBuilder::AssembleModel(
	ProAssembly pTopAsm,											// �����
	const ModelConfiguration &mdlConfig								// ģ������
	)
{
	bool bRet = false;
	switch (mdlConfig.nModelType)
	{
	case DMT_IT:						// ����������
		bRet = AssembleModel_IT(pTopAsm, mdlConfig);
		break;
	case DMT_MJT:						// �ܿع�
		break;
	case DMT_CASO4_FLOOR:				// ����Ƶذ�
		break;
	case DMT_STEEL_FLOOR:				// ȫ��ͨ��ذ�
		break;
	case DMT_COLD_FRONT_DOOR:			// ��ͨ��ǰ��
		break;
	case DMT_COLD_BACK_DOOR:			// ��ͨ������
		break;
	case DMT_LEFT_FRAME:				// ����
		break;
	case DMT_RIGHT_FRAME:				// �ҿ��
		break;
	case DMT_FLIP_WINDOW:				// ��ת����
		break;
	case DMT_FIXED_WINDOW:				// �̶�����
		break;
	case DMT_FOOTSTEP:					// ̤��
		break;
	default:
		break;
	}
	return bRet;
}

// װ��ģ��
bool CTotalUnitBuilder::AssembleModel(
	ProAssembly pTopAsm,											// �����(in)
	ProMdl pCompMdl,												// Ԫ��(in)
	const IKSCsysData &asmPosition									// װ��λ��(in)
	)
{
	if (NULL == pTopAsm || NULL == pCompMdl)
		return false;

	// ����װ������ϵ
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
	// ��ȡװ������ϵ
	vector<ProGeomitem> arrAsmCsysItem;
	CPCLFeature::GetFeatureGeomItems(newCsysFeature, PRO_CSYS, arrAsmCsysItem);
	if (arrAsmCsysItem.empty())
		return false;
	ProSelection pSelAsmCsys = NULL;
	ProSelectionAlloc(NULL, &arrAsmCsysItem[0], &pSelAsmCsys);

	// װ��ģ��
	SVMATRIX defaultMatrix;
	ProAsmcomp newAsmcomp;
	ProAsmcompAssemble(pTopAsm, (ProSolid)pCompMdl, defaultMatrix.m, &newAsmcomp);

	// ��ȡԪ��װ������ϵ
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

	// �������ϵװ��Լ��
	CPCLAssembly pclAsm;
	pclAsm.AddCsysConstraint(newAsmcomp, pTopAsm, pSelAsmCsys, pSelCompCsys);

	return true;
}

// װ�����������ģ��
bool CTotalUnitBuilder::AssembleModel_IT(
	ProAssembly pTopAsm,											// �����
	const ModelConfiguration &mdlConfig								// ģ������
	)
{
	if (NULL == pTopAsm)
		return false;

	// ����Ҫ����
	if (!mdlConfig.bIsCreate)
		return true;

	if (mdlConfig.strTempPartNo.IsEmpty())
	{
		// �����ʽͼ��Ϊ�գ��򷵻�
		if (mdlConfig.strFormalPartNo.IsEmpty())
			return false;

		// ����ģ��
		ProMdl pCompMdl = LoadMdlByPartNo(mdlConfig.strFormalPartNo);
		if (NULL == pCompMdl)
			return false;
		// װ�������
		for (size_t i=0; i<mdlConfig.arrPosition.size(); i++)
		{
			AssembleModel(pTopAsm, pCompMdl, mdlConfig.arrPosition[i]);
		}

	}
	else
	{
		// �����ʱͼ�Ų�Ϊ�գ�������ģ��ģ�ͣ����ɲ�������ģ��
	}

	return true;
}

// ��������ģ��
bool CTotalUnitBuilder::TestBuildModel()
{
	// ��������
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
