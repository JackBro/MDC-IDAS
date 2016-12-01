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
#include "PCLMdl.h"
#include "DesignGlobal.h"
#include "XmlToObject.h"
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
	case DMT_ITC:						// ����������
		bRet = AssembleModel(pTopAsm, g_strFWQJGTemplateAsmName, g_strFWQJGCompCsysName, mdlConfig);
		break;
	case DMT_MGT:						// �ܿع�
		bRet = AssembleModel(pTopAsm, g_strGKGTemplateAsmName, g_strGKGCompCsysName, mdlConfig);
		break;
	case DMT_COL_HAED_MGT:				// ��ͷ�ܿع�
		bRet = AssembleModel(pTopAsm, g_strGKGTemplateAsmName, g_strGKGCompCsysName, mdlConfig);
		break;
	case DMT_TAC:						// �յ���
		bRet = AssembleModel(pTopAsm, g_strKTGTemplateAsmName, g_strKTGCompCsysName, mdlConfig);
		break;
	case DMT_FHC:						// ������
		bRet = AssembleModel(pTopAsm, g_strXFGTemplateAsmName, g_strXFGCompCsysName, mdlConfig);
		break;
	case DMT_COL_HAED_EMPTY:			// ��ͷ�չ�
		bRet = AssembleModel(pTopAsm, g_strGKGTemplateAsmName, g_strGKGCompCsysName, mdlConfig);
		break;
	case DMT_PDR:						// ����
		bRet = AssembleModel(pTopAsm, g_strPDGTemplateAsmName, g_strPDGCompCsysName, mdlConfig);
		break;
	case DMT_COL_HEAD_PDR:				// ��ͷ����
		bRet = AssembleModel(pTopAsm, g_strPDGTemplateAsmName, g_strPDGCompCsysName, mdlConfig);
		break;
	case DMT_ROW_EMPTY:					// �м�չ�
		bRet = AssembleModel(pTopAsm, g_strHJKGTemplateAsmName, g_strHJKGCompCsysName, mdlConfig);
		break;
	case DMT_DAO_FENG:					// �����
		bRet = AssembleModel(pTopAsm, g_strDFGTemplateAsmName, g_strDFGCompCsysName, mdlConfig);
		break;
	case DMT_CASO4_FLOOR:				// ����Ƶذ�
		break;
	case DMT_STEEL_FLOOR:				// ȫ��ͨ��ذ�
		break;
	case DMT_COLD_FRONT_DOOR:			// ͨ��ƽ��
		bRet = AssembleModel(pTopAsm, g_strTDPMTemplateAsmName, g_strTDPMCompCsysName, mdlConfig);
		break;
	case DMT_COLD_BACK_DOOR:			// ͨ��͹��
		bRet = AssembleModel(pTopAsm, g_strTDTMTemplateAsmName, g_strTDTMCompCsysName, mdlConfig);
		break;
	case DMT_LEFT_FRAME:				// ����
		break;
	case DMT_RIGHT_FRAME:				// �ҿ��
		break;
	case DMT_FLIP_WINDOW:				// ��ת����
		bRet = AssembleModel(pTopAsm, g_strFZDCTemplateAsmName, g_strFZDCCompCsysName, mdlConfig);
		break;
	case DMT_FIXED_WINDOW:				// �̶�����
		bRet = AssembleModel(pTopAsm, g_strGDDCTemplateAsmName, g_strGDDCCompCsysName, mdlConfig);
		break;
	case DMT_ADJUST_WINDOW:				// �ɵ�����
		bRet = AssembleModel(pTopAsm, g_strKTDCTemplateAsmName, g_strKTDCCompCsysName, mdlConfig);
		break;
	case DMT_FOOTSTEP:					// ̤��
		break;
	case DMT_ZOU_XIAN_JIA:				// ǿ�������߼�
		bRet = AssembleModel(pTopAsm, g_strZXJTemplateAsmName, g_strZXJCompCsysName, mdlConfig);
		break;
	case DMT_GUANG_XIAN_ZXJ:			// �������߼�
		bRet = AssembleModel(pTopAsm, g_strGXCTemplateAsmName, g_strGXCCompCsysName, mdlConfig);
		break;
	case DMT_WALL_PILLAR:				// ǽ��
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
	const CString &strCompCsysName,									// Ԫ��װ������(in)
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
	wcsncpy_s(szCompCsysName, PRO_NAME_SIZE, strCompCsysName, _TRUNCATE);
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

// װ��ģ��
bool CTotalUnitBuilder::AssembleModel(
	ProAssembly pTopAsm,											// �����(in)
	const CString &strTemplateName,									// ģ������(in)
	const CString &strCompCsysName,									// Ԫ��װ������(in)
	const ModelConfiguration &mdlConfig								// ģ������(in)
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
			AssembleModel(pTopAsm, pCompMdl, strCompCsysName, mdlConfig.arrPosition[i]);
		}

	}
	else
	{
		// �����ʱͼ�Ų�Ϊ�գ�������ģ��ģ�ͣ����ɲ�������ģ��
		ProMdl pCompMdl = LoadMdlByPartNo(strTemplateName);
		if (NULL == pCompMdl)
			return false;
		ProName szNewCompName = {0};
		wcsncpy_s(szNewCompName, PRO_NAME_SIZE, mdlConfig.strTempPartNo, _TRUNCATE);
		ProMdlRename(pCompMdl, szNewCompName);
		vector<ProAsmcomp> arrComps;
		CPCLMdl::GetSolidFeature((ProSolid)pCompMdl, PRO_FEAT_COMPONENT, arrComps);
		ProMdl pSubMdl = NULL;
		ProName szNewSubMdlName;
		CString strNewSubMdlName;
		for (size_t i=0; i<arrComps.size(); i++)
		{
			ProAsmcompMdlGet(&arrComps[i], &pSubMdl);
			if (NULL == pSubMdl)
				continue;
			strNewSubMdlName.Format(L"%s_P%d", szNewCompName, i+1);
			wcsncpy_s(szNewSubMdlName, PRO_NAME_SIZE, strNewSubMdlName, _TRUNCATE);
			ProMdlRename(pSubMdl, szNewSubMdlName);
		}
		ProModelitem mdlItem;
		ProMdlToModelitem(pCompMdl, &mdlItem);
		CPCLParameter::SetParameter(&mdlItem, g_strITParaHeightName, mdlConfig.dHieght, FALSE);
		CPCLParameter::SetParameter(&mdlItem, g_strITParaWidthName, mdlConfig.dWidth, FALSE);
		CPCLParameter::SetParameter(&mdlItem, g_strITParaDepthName, mdlConfig.dDepth, FALSE);
		ProSolidRegenerate((ProSolid)pCompMdl, PRO_REGEN_NO_FLAGS);
		// װ�������
		for (size_t i=0; i<mdlConfig.arrPosition.size(); i++)
		{
			AssembleModel(pTopAsm, pCompMdl, strCompCsysName, mdlConfig.arrPosition[i]);
		}
	}

	return true;
}

// �������������
int CTotalUnitBuilder::FindModelConfig(
	int nModelType,													// ģ������(in)
	double dSymbolWidth,											// ���ŵĿ��(in)
	double dSymbolHeight,											// ���ŵĸ߶�(in)
	const ModelConfigurationArray &arrMdlConfig						// ������ü�(in)
	)
{
	int nFind = -1;
	for (size_t i=0; i<arrMdlConfig.size(); i++)
	{
		if (arrMdlConfig[i].nModelType == nModelType && 
			ISDEQUAL(arrMdlConfig[i].dWidth, dSymbolWidth) &&
			ISDEQUAL(arrMdlConfig[i].dDepth, dSymbolHeight))
		{
			nFind = (int)i;
			break;
		}
	}

	return nFind;
}

// ���ݷ�������λ�ú���ת�Ƕȣ�����װ��λ��
bool CTotalUnitBuilder::GetModelPosition(
	double dLayoutLeft,												// ����ͼ�����Ͻ�X(in)
	double dLayoutTop,												// ����ͼ�����Ͻ�Y(in)
	double dLayoutWidth,											// ����ͼ�Ŀ��(in)
	double dLayoutHeight,											// ����ͼ�ĸ߶�(in)
	double dSymbolWidth,											// ���ŵĿ��(in)
	double dSymbolHeight,											// ���ŵĸ߶�(in)
	double dCenterX,												// ��������X(in)
	double dCenterY,												// ��������Y(in)
	double dAngle,													// ����˳ʱ����ת�Ƕ�(in)
	IKSCsysData &position											// ģ��װ��λ��(out)
	)
{
	dLayoutWidth;
	SVDOUBLE3 vRealCenter(dCenterX - dLayoutLeft, dLayoutHeight - dCenterY + dLayoutTop, 0.0);
	SVDOUBLE3 vCenterToOrigin(-dSymbolWidth*0.5, -dSymbolHeight*0.5, 0.0);
	double dRadian = BPToDRadian(-dAngle);
	double dCosA = cos(dRadian);
	double dSinA = sin(dRadian);
	SVDOUBLE3 vRealCenterToOrigin(vCenterToOrigin.x*dCosA-vCenterToOrigin.y*dSinA, vCenterToOrigin.x*dSinA+vCenterToOrigin.y*dCosA, 0.0);
	position.o = vRealCenter + vRealCenterToOrigin;
	BPVec3Normalize(&vRealCenterToOrigin, &vRealCenterToOrigin);
	position.x = SVDOUBLE3(dCosA, dSinA, 0.0);
	position.y = SVDOUBLE3(cos(dRadian+BP_D_PI*0.5), sin(dRadian+BP_D_PI*0.5), 0.0);
	position.z = SVDOUBLE3(0.0, 0.0, 1.0);

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
	modelConfig.nModelType = DMT_ITC;
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
	modelConfig.nModelType = DMT_ITC;
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
	modelConfig.nModelType = DMT_ITC;
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
	modelConfig.nModelType = DMT_ITC;
	modelConfig.bIsCreate = true;
	modelConfig.strTempPartNo = _T("JIGUI_000001");
	modelConfig.strFormalPartNo = _T("JIGUI_000001");
	modelConfig.strPurchaseNo = _T("");
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

// ����XML�ļ�����ģ��
bool CTotalUnitBuilder::TestBuildModelByXML(const CString &strXMLPath)
{
	CXmlToObject xmlParse;
	xmlParse.Init();
	xmlParse.OpenFile(strXMLPath);

	// ��ȡ���ż�
	vector<CLaySymbolObj*> arrSymbols;
	for (int i=0; i<(int)xmlParse.m_arrObject.GetSize(); i++)
	{
		if (xmlParse.m_arrObject[i]->m_nType == AOT_CABINET)
			arrSymbols.push_back((CLaySymbolObj*)xmlParse.m_arrObject[i]);
		else if (xmlParse.m_arrObject[i]->m_nType == AOT_CR)
			arrSymbols.push_back((CLaySymbolObj*)xmlParse.m_arrObject[i]);
		else if (xmlParse.m_arrObject[i]->m_nType == AOT_WCLN)
			arrSymbols.push_back((CLaySymbolObj*)xmlParse.m_arrObject[i]);
		else if (xmlParse.m_arrObject[i]->m_nType == AOT_DOOR)
			arrSymbols.push_back((CLaySymbolObj*)xmlParse.m_arrObject[i]);
		else if (xmlParse.m_arrObject[i]->m_nType == AOT_WINDOW)
			arrSymbols.push_back((CLaySymbolObj*)xmlParse.m_arrObject[i]);
	}

	// ��������������Ϣ
	TotalUnitConfiguration totalUnitConfig;
	totalUnitConfig.strAsmName = _T("TOTAL_MODEL_00001");
	ModelConfiguration modelConfig;
	int nModelType = -1, nFindMdlConfig = -1;
	int nIndex = 1;
	for (size_t i=0; i<arrSymbols.size(); i++)
	{
		nModelType = GetDesignModelType(arrSymbols[i]->m_nSubType);
		if (nModelType < 0)
			continue;
		nFindMdlConfig = FindModelConfig(nModelType, arrSymbols[i]->m_dWidth, arrSymbols[i]->m_dHeight, totalUnitConfig.arrModelConfig);
		if (nFindMdlConfig < 0)
		{
			// �����µ�����������
			modelConfig.nMajorClass = -1;
			modelConfig.nModelType = nModelType;
			modelConfig.bIsCreate = true;
			modelConfig.strTempPartNo.Format( _T("JIGUI_%d"), nIndex++);
			modelConfig.strFormalPartNo = _T("");
			modelConfig.strPurchaseNo = _T("");
			modelConfig.dHieght = 500.0;
			modelConfig.dWidth = arrSymbols[i]->m_dWidth;
			modelConfig.dDepth = arrSymbols[i]->m_dHeight;
			modelConfig.arrPosition.resize(1);
			GetModelPosition(xmlParse.m_dLeft, xmlParse.m_dTop, xmlParse.m_dWidth, xmlParse.m_dHeight, arrSymbols[i]->m_dWidth, arrSymbols[i]->m_dHeight, arrSymbols[i]->m_ptCenter.x, arrSymbols[i]->m_ptCenter.y, arrSymbols[i]->m_dAngle, modelConfig.arrPosition[0]);
			modelConfig.strRemark = _T("");
			totalUnitConfig.arrModelConfig.push_back(modelConfig);
		}
		else
		{
			// ������������������
			IKSCsysData newPosition;
			GetModelPosition(xmlParse.m_dLeft, xmlParse.m_dTop, xmlParse.m_dWidth, xmlParse.m_dHeight, arrSymbols[i]->m_dWidth, arrSymbols[i]->m_dHeight, arrSymbols[i]->m_ptCenter.x, arrSymbols[i]->m_ptCenter.y, arrSymbols[i]->m_dAngle, newPosition);
			totalUnitConfig.arrModelConfig[nFindMdlConfig].arrPosition.push_back(newPosition);
		}
	}

	xmlParse.UnInit();

	BuildModel(totalUnitConfig);
	return true;
}
