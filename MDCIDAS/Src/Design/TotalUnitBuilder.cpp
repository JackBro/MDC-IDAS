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
		ProPath szCurPath;
		ProDirectoryCurrentGet(szCurPath);
		CString strLibPath = szCurPath;
		strLibPath += L"\\ZTE_LIB\\";
		strLibPath += strPartNo + CString(L".asm");
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
	return AssembleModel(pTopAsm, GetTemplateNameByModelType(mdlConfig.nModelType), GetCompCsysNameByModelType(mdlConfig.nModelType), mdlConfig);
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
	if (strTemplateName.IsEmpty() || strCompCsysName.IsEmpty())
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
		CString strNewCompName = strTemplateName;
		int nFindUnderline = strNewCompName.ReverseFind(L'_');
		if (nFindUnderline >= 0)
			strNewCompName = strNewCompName.Left(nFindUnderline);
		strNewCompName = GetTempPartNo(strNewCompName);
		ProName szNewCompName = {0};
		wcsncpy_s(szNewCompName, PRO_NAME_SIZE, strNewCompName, _TRUNCATE);
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
			ProMdlNameGet(pSubMdl, szNewSubMdlName);
			strNewSubMdlName = szNewSubMdlName;
			nFindUnderline = strNewSubMdlName.ReverseFind(L'_');
			if (nFindUnderline >= 0)
				strNewSubMdlName = strNewSubMdlName.Left(nFindUnderline);
			strNewSubMdlName = GetTempPartNo(strNewSubMdlName);
			wcsncpy_s(szNewSubMdlName, PRO_NAME_SIZE, strNewSubMdlName, _TRUNCATE);
			ProMdlRename(pSubMdl, szNewSubMdlName);
		}
		ProModelitem mdlItem;
		ProMdlToModelitem(pCompMdl, &mdlItem);
		CPCLParameter::SetParameter(&mdlItem, g_strITParaHeightName, mdlConfig.dHeight, FALSE);
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

// ��ȡ��ʱͼ��
CString CTotalUnitBuilder::GetTempPartNo(
	const CString &strTemplateName									// ģ���ļ���
	)
{
	static int nIndex = 1;
	CString strTempPartNo;
	if (nIndex >= 1 && nIndex <= 9)
		strTempPartNo.Format(L"%s_00000%d", strTemplateName, nIndex++);
	else if (nIndex >= 10 && nIndex <= 99)
		strTempPartNo.Format(L"%s_0000%d", strTemplateName, nIndex++);
	else if (nIndex >= 100 && nIndex <= 999)
		strTempPartNo.Format(L"%s_000%d", strTemplateName, nIndex++);
	else if (nIndex >= 1000 && nIndex <= 9999)
		strTempPartNo.Format(L"%s_00%d", strTemplateName, nIndex++);
	else if (nIndex >= 10000 && nIndex <= 99999)
		strTempPartNo.Format(L"%s_0%d", strTemplateName, nIndex++);
	else
		strTempPartNo.Format(L"%s_%d", strTemplateName, nIndex++);
	return strTempPartNo;
}

// ��ȡģ���ļ���
CString CTotalUnitBuilder::GetTemplateNameByModelType(
	int nModelType													// �������
	)
{
	CString strTemplateName;
	switch (nModelType)
	{
	case DMT_ITC:						// ����������
		strTemplateName = g_strFWQJGTemplateAsmName;
		break;
	case DMT_MGT:						// �ܿع�
		strTemplateName = g_strGKGTemplateAsmName;
		break;
	case DMT_COL_HAED_MGT:				// ��ͷ�ܿع�
		strTemplateName = g_strGKGTemplateAsmName;
		break;
	case DMT_TAC:						// �յ���
		strTemplateName = g_strKTGTemplateAsmName;
		break;
	case DMT_FHC:						// ������
		strTemplateName = g_strXFGTemplateAsmName;
		break;
	case DMT_COL_HAED_EMPTY:			// ��ͷ�չ�
		strTemplateName = g_strGKGTemplateAsmName;
		break;
	case DMT_PDR:						// ����
		strTemplateName = g_strPDGTemplateAsmName;
		break;
	case DMT_COL_HEAD_PDR:				// ��ͷ����
		strTemplateName = g_strPDGTemplateAsmName;
		break;
	case DMT_ROW_EMPTY:					// �м�չ�
		strTemplateName = g_strHJKGTemplateAsmName;
		break;
	case DMT_DAO_FENG:					// �����
		strTemplateName = g_strDFGTemplateAsmName;
		break;
	case DMT_CASO4_FLOOR:				// ����Ƶذ�
		break;
	case DMT_STEEL_FLOOR:				// ȫ��ͨ��ذ�
		break;
	case DMT_COLD_FRONT_DOOR:			// ͨ��ƽ��
		strTemplateName = g_strTDPMTemplateAsmName;
		break;
	case DMT_COLD_BACK_DOOR:			// ͨ��͹��
		strTemplateName = g_strTDTMTemplateAsmName;
		break;
	case DMT_LEFT_FRAME:				// ����
		break;
	case DMT_RIGHT_FRAME:				// �ҿ��
		break;
	case DMT_FLIP_WINDOW:				// ��ת����
		strTemplateName = g_strFZDCTemplateAsmName;
		break;
	case DMT_FIXED_WINDOW:				// �̶�����
		strTemplateName = g_strGDDCTemplateAsmName;
		break;
	case DMT_ADJUST_WINDOW:				// �ɵ�����
		strTemplateName = g_strKTDCTemplateAsmName;
		break;
	case DMT_FOOTSTEP:					// ̤��
		break;
	case DMT_ZOU_XIAN_JIA:				// ǿ�������߼�
		strTemplateName = g_strZXJTemplateAsmName;
		break;
	case DMT_GUANG_XIAN_ZXJ:			// �������߼�
		strTemplateName = g_strGXCTemplateAsmName;
		break;
	case DMT_WALL_PILLAR:				// ǽ��
		break;
	default:
		break;
	}
	return strTemplateName;
}

// ��ȡװ����������
CString CTotalUnitBuilder::GetCompCsysNameByModelType(
	int nModelType													// �������
	)
{
	CString strCompCsysName;
	switch (nModelType)
	{
	case DMT_ITC:						// ����������
		strCompCsysName = g_strFWQJGCompCsysName;
		break;
	case DMT_MGT:						// �ܿع�
		strCompCsysName = g_strGKGCompCsysName;
		break;
	case DMT_COL_HAED_MGT:				// ��ͷ�ܿع�
		strCompCsysName = g_strGKGCompCsysName;
		break;
	case DMT_TAC:						// �յ���
		strCompCsysName = g_strKTGCompCsysName;
		break;
	case DMT_FHC:						// ������
		strCompCsysName = g_strXFGCompCsysName;
		break;
	case DMT_COL_HAED_EMPTY:			// ��ͷ�չ�
		strCompCsysName = g_strGKGCompCsysName;
		break;
	case DMT_PDR:						// ����
		strCompCsysName = g_strPDGCompCsysName;
		break;
	case DMT_COL_HEAD_PDR:				// ��ͷ����
		strCompCsysName = g_strPDGCompCsysName;
		break;
	case DMT_ROW_EMPTY:					// �м�չ�
		strCompCsysName = g_strHJKGCompCsysName;
		break;
	case DMT_DAO_FENG:					// �����
		strCompCsysName = g_strDFGCompCsysName;
		break;
	case DMT_CASO4_FLOOR:				// ����Ƶذ�
		break;
	case DMT_STEEL_FLOOR:				// ȫ��ͨ��ذ�
		break;
	case DMT_COLD_FRONT_DOOR:			// ͨ��ƽ��
		strCompCsysName = g_strTDPMCompCsysName;
		break;
	case DMT_COLD_BACK_DOOR:			// ͨ��͹��
		strCompCsysName = g_strTDTMCompCsysName;
		break;
	case DMT_LEFT_FRAME:				// ����
		break;
	case DMT_RIGHT_FRAME:				// �ҿ��
		break;
	case DMT_FLIP_WINDOW:				// ��ת����
		strCompCsysName = g_strFZDCCompCsysName;
		break;
	case DMT_FIXED_WINDOW:				// �̶�����
		strCompCsysName = g_strGDDCCompCsysName;
		break;
	case DMT_ADJUST_WINDOW:				// �ɵ�����
		strCompCsysName = g_strKTDCCompCsysName;
		break;
	case DMT_FOOTSTEP:					// ̤��
		break;
	case DMT_ZOU_XIAN_JIA:				// ǿ�������߼�
		strCompCsysName = g_strZXJCompCsysName;
		break;
	case DMT_GUANG_XIAN_ZXJ:			// �������߼�
		strCompCsysName = g_strGXCCompCsysName;
		break;
	case DMT_WALL_PILLAR:				// ǽ��
		break;
	default:
		break;
	}
	return strCompCsysName;
}

// ���ݶ����ɼ���Ͳ���ͼ���ż���ѡ�����������
bool CTotalUnitBuilder::SelectFWQJGConfiguration(
	const RequirementTabData &reqTabData,							// ����ɼ���
	CXmlToObject &xmlData,											// ����ͼXML�������
	vector<CLaySymbolObj*> &arrSymbols,								// ����ͼ���ż�
	ModelConfiguration &modelConfig									// ��������
	)
{
	// ��ȡ������������ż�
	vector<CLaySymbolObj*> arrITCSymbols;
	GetLayoutSymbols(SCT_ITC, arrSymbols, arrITCSymbols);
	if (arrITCSymbols.empty())
		return false;

	modelConfig.strMajorClass = _T("����");
	modelConfig.nModelType = DMT_ITC;

	// ��ȡ���ݿ�ѡ������
	JiGuiDBData FWQJGDBData;
	if (GetFWQJGDBData(reqTabData, FWQJGDBData))
	{
		// ����ʽͼ�ŵ��������д������������
		modelConfig.strTempPartNo = _T("");
		modelConfig.strFormalPartNo = FWQJGDBData.strPartNo;
		modelConfig.strPurchaseNo = FWQJGDBData.strCode;
		modelConfig.dHeight = FWQJGDBData.dHeight;
		modelConfig.dWidth = FWQJGDBData.dWidth;
		modelConfig.dDepth = FWQJGDBData.dDepth;
		modelConfig.strRemark = FWQJGDBData.strRemark;
	}
	else
	{
		// ������ʱͼ��
		modelConfig.strTempPartNo = GetTemplateNameByModelType(modelConfig.nModelType);
		modelConfig.strFormalPartNo = _T("");
		modelConfig.strPurchaseNo = _T("");
		modelConfig.dHeight = reqTabData.dHeightOfITRack;
		modelConfig.dWidth = reqTabData.dWidthOfITRack;
		modelConfig.dDepth = reqTabData.dDepthOfITRack;
		modelConfig.strRemark = _T("");
	}

	// ��ȡװ��λ��
	modelConfig.arrPosition.resize(arrITCSymbols.size());
	for (size_t i=0; i<arrITCSymbols.size(); i++)
		GetModelPosition(xmlData.m_dLeft, xmlData.m_dTop, xmlData.m_dWidth, xmlData.m_dHeight,
		arrITCSymbols[i]->m_dWidth, arrITCSymbols[i]->m_dHeight, arrITCSymbols[i]->m_ptCenter.x,
		arrITCSymbols[i]->m_ptCenter.y, arrITCSymbols[i]->m_dAngle, modelConfig.arrPosition[i]);
	// ȷ��װ��߶�
	double dZ = GetHeightOfPedestal(reqTabData.nHeightOfPedestal);
	if (!ISDEQUAL(dZ, 0.0))
	{
		for (size_t i=0; i<modelConfig.arrPosition.size(); i++)
			modelConfig.arrPosition[i].o.z = dZ;
	}

	return true;
}

// ���ݶ����ɼ���Ͳ���ͼ���ż���ѡ��ܿع�
bool CTotalUnitBuilder::SelectGKGConfiguration(
	const RequirementTabData &reqTabData,							// ����ɼ���
	CXmlToObject &xmlData,											// ����ͼXML�������
	vector<CLaySymbolObj*> &arrSymbols,								// ����ͼ���ż�
	ModelConfiguration &gkgConfig									// ��������
	)
{
	// ��ȡ�ܿع���ż�
	vector<CLaySymbolObj*> arrMCCSymbols;
	GetLayoutSymbols(SCT_MCC, arrSymbols, arrMCCSymbols);
	if (arrMCCSymbols.empty())
		return false;

	gkgConfig.strMajorClass = _T("����");
	gkgConfig.nModelType = DMT_MGT;

	// ��ȡ���ݿ�ѡ������
	JiGuiDBData gkgDBData;
	if (GetGKGDBData(reqTabData, gkgDBData))
	{
		// ����ʽͼ�ŵ��������д������������
		gkgConfig.strTempPartNo = _T("");
		gkgConfig.strFormalPartNo = gkgDBData.strPartNo;
		gkgConfig.strPurchaseNo = gkgDBData.strCode;
		gkgConfig.dHeight = gkgDBData.dHeight;
		gkgConfig.dWidth = gkgDBData.dWidth;
		gkgConfig.dDepth = gkgDBData.dDepth;
		gkgConfig.strRemark = gkgDBData.strRemark;
	}
	else
	{
		// ������ʱͼ��
		gkgConfig.strTempPartNo = GetTemplateNameByModelType(gkgConfig.nModelType);
		gkgConfig.strFormalPartNo = _T("");
		gkgConfig.strPurchaseNo = _T("");
		gkgConfig.dHeight = reqTabData.dHeightOfITRack;
		gkgConfig.dWidth = reqTabData.dWidthOfITRack;
		gkgConfig.dDepth = reqTabData.dDepthOfITRack;
		gkgConfig.strRemark = _T("");
	}

	// ��ȡװ��λ��
	gkgConfig.arrPosition.resize(arrMCCSymbols.size());
	for (size_t i=0; i<arrMCCSymbols.size(); i++)
		GetModelPosition(xmlData.m_dLeft, xmlData.m_dTop, xmlData.m_dWidth, xmlData.m_dHeight,
		arrMCCSymbols[i]->m_dWidth, arrMCCSymbols[i]->m_dHeight, arrMCCSymbols[i]->m_ptCenter.x,
		arrMCCSymbols[i]->m_ptCenter.y, arrMCCSymbols[i]->m_dAngle, gkgConfig.arrPosition[i]);
	// ȷ��װ��߶�
	double dZ = GetHeightOfPedestal(reqTabData.nHeightOfPedestal);
	if (!ISDEQUAL(dZ, 0.0))
	{
		for (size_t i=0; i<gkgConfig.arrPosition.size(); i++)
			gkgConfig.arrPosition[i].o.z = dZ;
	}

	return true;
}

// ���ݶ����ɼ���ͨ�����ݿ��ȡ�����������������Ϣ
bool CTotalUnitBuilder::GetFWQJGDBData(
	const RequirementTabData &reqTabData,							// ����ɼ���
	JiGuiDBData &jiguiData											// ��������
	)
{
	reqTabData;
	jiguiData.strCode = _T("624100324601");					// ����
	jiguiData.strPartNo = _T("624100324600");				// ͼ��
	jiguiData.strName = _T("Z6012-20B����");				// ����
	jiguiData.strEngName = _T("Z6012-20Bcabinet");			// Ӣ����
	jiguiData.strUnit = _T("��");							// ��λ
	jiguiData.strState = _T("ͨ��");						// ״̬
	jiguiData.strClass = _T("����������");					// ���
	jiguiData.dHeight = 2000.0;								// ��
	jiguiData.dWidth = 600;									// ��
	jiguiData.dDepth = 1200;								// ��
	jiguiData.strFrontDoor = _T("�����ܿ���");				// ǰ��
	jiguiData.strFrontDoorLock = _T("ͨ��");				// ǰ������
	jiguiData.strBackDoor = _T("˫���ܿ���");				// ����
	jiguiData.strBackDoorLock = _T("ͨ��");					// ��������
	jiguiData.strJiaMianBan = _T("");						// �����
	jiguiData.strChuanXianMianBan = _T("");					// �������
	jiguiData.strLTuoBan = _T("8");							// L���а�
	// ��ע
	jiguiData.strRemark = _T("��ͨ����ջ���ͨ����գ��޽��ֺ͵ؽţ�8��L�͵��죻1��127032931003�Žӵ��ߣ���һ�����߰壬������PDU��װ��");
	return true;
}

// ���ݶ����ɼ���ͨ�����ݿ��ȡ�ܿع��������Ϣ
bool CTotalUnitBuilder::GetGKGDBData(
	const RequirementTabData &reqTabData,							// ����ɼ���
	JiGuiDBData &gkgData											// ��������
	)
{
	reqTabData;
	gkgData.strCode = _T("624100315501");				// ����
	gkgData.strPartNo = _T("624100315500");				// ͼ��
	gkgData.strName = _T("2000PAD�ܿ��Ż���");			// ����
	gkgData.strEngName = _T("cabinet");					// Ӣ����
	gkgData.strUnit = _T("��");							// ��λ
	gkgData.strState = _T("ͨ��");						// ״̬
	gkgData.strClass = _T("�ܿع�");					// ���
	gkgData.dHeight = 2000.0;							// ��
	gkgData.dWidth = 600;								// ��
	gkgData.dDepth = 1200;								// ��
	gkgData.strFrontDoor = _T("�����ܿ���");			// ǰ��
	gkgData.strFrontDoorLock = _T("ͨ��");				// ǰ������
	gkgData.strBackDoor = _T("����PAD�ܿ���");			// ����
	gkgData.strBackDoorLock = _T("ͨ��");				// ��������
	gkgData.strJiaMianBan = _T("");						// �����
	gkgData.strChuanXianMianBan = _T("1");					// �������
	gkgData.strLTuoBan = _T("5");							// L���а�
	// ��ע
	gkgData.strRemark = _T("��ͨ����ջ���ͨ����գ��޽��ֺ͵ؽţ�1U������壻5��L�͵��죻1��127032931003�Žӵ���");
	return true;
}

// ��ȡָ�����͵Ĳ���ͼ���ż�
bool CTotalUnitBuilder::GetLayoutSymbols(int nSymbolType, const vector<CLaySymbolObj*> &arrAllSymbols, vector<CLaySymbolObj*> &arrOutSymbols)
{
	arrOutSymbols.clear();
	for (size_t i=0; i<arrAllSymbols.size(); i++)
	{
		if (arrAllSymbols[i]->m_nSubType == nSymbolType)
			arrOutSymbols.push_back(arrAllSymbols[i]);
	}

	return (!arrOutSymbols.empty());
}

// ��ȡ�����߶�
double CTotalUnitBuilder::GetHeightOfPedestal(int nHeightOfPedestal)
{
	double dPedestalHeight = 0.0;
	switch (nHeightOfPedestal)
	{
	case HP_250:					// 250mm
		dPedestalHeight = 250.00;
		break;
	case HP_300:					// 300mm
		dPedestalHeight = 300.00;
		break;
	case HP_350:					// 350mm
		dPedestalHeight = 350.00;
		break;
	case HP_400:					// 400mm
		dPedestalHeight = 400.00;
		break;
	case HP_450:					// 450mm
		dPedestalHeight = 450.00;
		break;
	case HP_500:					// 500mm
		dPedestalHeight = 500.00;
		break;
	case HP_550:					// 550mm
		dPedestalHeight = 550.00;
		break;
	case HP_600:					// 600mm
		dPedestalHeight = 600.00;
		break;
	case HP_650:					// 650mm
		dPedestalHeight = 650.00;
		break;
	case HP_700:					// 700mm
		dPedestalHeight = 700.00;
		break;
	case HP_750:					// 750mm
		dPedestalHeight = 750.00;
		break;
	case HP_800:					// 800mm
		dPedestalHeight = 800.00;
		break;
	default:
		break;
	}

	return dPedestalHeight;
}

// ��������ģ��
bool CTotalUnitBuilder::TestBuildModel()
{
	// ��������
	TotalUnitConfiguration totalUnitConfig;
	totalUnitConfig.strAsmName = _T("TOTAL_MODEL_00001");
	ModelConfiguration modelConfig;
	modelConfig.strMajorClass = _T("");
	modelConfig.nModelType = DMT_ITC;
	modelConfig.bIsCreate = true;
	modelConfig.strTempPartNo = _T("");
	modelConfig.strFormalPartNo = _T("JIGUI_300X300X100");
	modelConfig.strPurchaseNo = _T("CG_JIGUI_300X300X100");
	modelConfig.dHeight = 300.0;
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
	modelConfig.strMajorClass = _T("");
	modelConfig.nModelType = DMT_ITC;
	modelConfig.bIsCreate = true;
	modelConfig.strTempPartNo = _T("");
	modelConfig.strFormalPartNo = _T("JIGUI_300X200X100");
	modelConfig.strPurchaseNo = _T("CG_JIGUI_300X200X100");
	modelConfig.dHeight = 300.0;
	modelConfig.dWidth = 200.0;
	modelConfig.dDepth = 100.0;
	modelConfig.arrPosition.resize(1);
	modelConfig.arrPosition[0].o = SVDOUBLE3(300.0, 200.0, 0.0);
	modelConfig.arrPosition[0].x = SVDOUBLE3(1.0, 0.0, 0.0);
	modelConfig.arrPosition[0].y = SVDOUBLE3(0.0, 1.0, 0.0);
	modelConfig.arrPosition[0].z = SVDOUBLE3(0.0, 0.0, 1.0);
	modelConfig.strRemark = _T("");
	totalUnitConfig.arrModelConfig.push_back(modelConfig);
	modelConfig.strMajorClass = _T("");
	modelConfig.nModelType = DMT_ITC;
	modelConfig.bIsCreate = true;
	modelConfig.strTempPartNo = _T("");
	modelConfig.strFormalPartNo = _T("JIGUI_300X100X100");
	modelConfig.strPurchaseNo = _T("CG_JIGUI_300X100X100");
	modelConfig.dHeight = 300.0;
	modelConfig.dWidth = 100.0;
	modelConfig.dDepth = 100.0;
	modelConfig.arrPosition.resize(1);
	modelConfig.arrPosition[0].o = SVDOUBLE3(500.0, 200.0, 0.0);
	modelConfig.arrPosition[0].x = SVDOUBLE3(1.0, 0.0, 0.0);
	modelConfig.arrPosition[0].y = SVDOUBLE3(0.0, 1.0, 0.0);
	modelConfig.arrPosition[0].z = SVDOUBLE3(0.0, 0.0, 1.0);
	modelConfig.strRemark = _T("");
	totalUnitConfig.arrModelConfig.push_back(modelConfig);
	modelConfig.strMajorClass = _T("");
	modelConfig.nModelType = DMT_ITC;
	modelConfig.bIsCreate = true;
	modelConfig.strTempPartNo = _T("JIGUI_000001");
	modelConfig.strFormalPartNo = _T("JIGUI_000001");
	modelConfig.strPurchaseNo = _T("");
	modelConfig.dHeight = 300.0;
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
	for (size_t i=0; i<arrSymbols.size(); i++)
	{
		nModelType = GetDesignModelType(arrSymbols[i]->m_nSubType);
		if (nModelType < 0)
			continue;
		nFindMdlConfig = FindModelConfig(nModelType, arrSymbols[i]->m_dWidth, arrSymbols[i]->m_dHeight, totalUnitConfig.arrModelConfig);
		if (nFindMdlConfig < 0)
		{
			// �����µ�����������
			modelConfig.strMajorClass = _T("");
			modelConfig.nModelType = nModelType;
			modelConfig.bIsCreate = true;
			modelConfig.strTempPartNo = GetTemplateNameByModelType(nModelType);
			modelConfig.strFormalPartNo = _T("");
			modelConfig.strPurchaseNo = _T("");
			modelConfig.dHeight = 2000.0;
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

// ���ݶ�������ɼ������������ͼXML�ļ�������������ģ��
bool CTotalUnitBuilder::TestBuildModelByReqTableAndLayoutFile(const CString &strXMLPath)
{
	// ����ɼ���ĳ�ʼ����������
	RequirementTabData reqTabData;
	reqTabData.nModuleType = MT_LONG_MODULE;						// ��ģ��
	reqTabData.bIsExtFloorExist = true;								// �Ƿ�����ⲿ�ذ�
	reqTabData.nAirstreamPattern = AP_COLD_SEAL;					// ��ͨ�����
	reqTabData.dPassageWidth = 1800.0;								// ͨ�����
	reqTabData.dHeightOfITRack = 2000;								// IT�����񡪡��߶�
	reqTabData.dWidthOfITRack = 600;								// IT�����񡪡����
	reqTabData.dDepthOfITRack = 1200;								// IT�����񡪡����
	reqTabData.nFrontDoorTypeOfITRack = FDT_SINGLE_DENSEHOLE_DOOR;	// IT�����ǰ������
	reqTabData.nBackDoorTypeOfITRack = FDT_DOUBLE_DENSEHOLE_DOOR;	// IT����ĺ�������
	reqTabData.nFrontDoorLockTypeOfITRack = FDLT_UNIVERSIAL_LOCK;	// IT�����ǰ��������
	reqTabData.nBackDoorLockTypeOfITRack = FDLT_UNIVERSIAL_LOCK;	// IT����ĺ���������
	reqTabData.nSideDoorTypeOfITRack = SDT_DEFAULT_TYPE;			// IT����Ĳ���
	reqTabData.nHeightOfPedestal = HP_300;							// �����߶�
	reqTabData.nInsideFloorType = IFT_DEFAULT_FLOOR;				// ģ���ڲ��ذ�
	reqTabData.nZouXianJiaType = ZXJT_MODULE_TYPE;					// ǿ�������߼���������
	reqTabData.dDistanceBetwZXJAndJigui = 0.0;						// (���߼ܻ�������)���߼ܾ�����񶥲����룻
	reqTabData.nNumOf1UPanel = 5;									// 1U����������
	reqTabData.nNumOf2UPanel = 5;									// 2U����������
	reqTabData.nNumOfLPallet = 5;									// L���а������
	reqTabData.nNumOfLightLayer = 5;								// ���ز�������
	reqTabData.nNumOfHeavyLayer = 5;								// ���ز�������
	reqTabData.nNumOfStringingPanel = 5;							// ������������
	reqTabData.nHuiLiuPaiType = HLPT_SHUZHUANG_TYPE;				// �����ŵ�����
	reqTabData.bIsWeiBanExist = true;								// Χ���Ƿ�����
	reqTabData.bIsInsideFloorExist = true;							// ģ���ڲ��Ƿ����õذ�
	reqTabData.bIsTaBuExist = true;									// �Ƿ�����̤��
	reqTabData.nControlCabinetType = CCT_IT_PAD_CAB;				// �ܿع�����

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

	// ѡ�����������
	ModelConfiguration FWQJGConfig;
	if (SelectFWQJGConfiguration(reqTabData, xmlParse, arrSymbols, FWQJGConfig))
		totalUnitConfig.arrModelConfig.push_back(FWQJGConfig);

	// ѡ��ܿع�
	ModelConfiguration GKGConfig;
	if (SelectGKGConfiguration(reqTabData, xmlParse, arrSymbols, GKGConfig))
		totalUnitConfig.arrModelConfig.push_back(GKGConfig);
	xmlParse.UnInit();

	BuildModel(totalUnitConfig);

	return true;
}
