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

// 装配模型
bool CTotalUnitBuilder::AssembleModel(
	ProAssembly pTopAsm,											// 总组件
	const ModelConfiguration &mdlConfig								// 模型配置
	)
{
	return AssembleModel(pTopAsm, GetTemplateNameByModelType(mdlConfig.nModelType), GetCompCsysNameByModelType(mdlConfig.nModelType), mdlConfig);
}

// 装配模型
bool CTotalUnitBuilder::AssembleModel(
	ProAssembly pTopAsm,											// 总组件(in)
	ProMdl pCompMdl,												// 元件(in)
	const CString &strCompCsysName,									// 元件装配坐标(in)
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
	wcsncpy_s(szCompCsysName, PRO_NAME_SIZE, strCompCsysName, _TRUNCATE);
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

// 装配模型
bool CTotalUnitBuilder::AssembleModel(
	ProAssembly pTopAsm,											// 总组件(in)
	const CString &strTemplateName,									// 模型名称(in)
	const CString &strCompCsysName,									// 元件装配坐标(in)
	const ModelConfiguration &mdlConfig								// 模型配置(in)
	)
{
	if (NULL == pTopAsm)
		return false;
	if (strTemplateName.IsEmpty() || strCompCsysName.IsEmpty())
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
			AssembleModel(pTopAsm, pCompMdl, strCompCsysName, mdlConfig.arrPosition[i]);
		}

	}
	else
	{
		// 如果临时图号不为空，则利用模板模型，生成参数化的模型
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
		// 装配至组件
		for (size_t i=0; i<mdlConfig.arrPosition.size(); i++)
		{
			AssembleModel(pTopAsm, pCompMdl, strCompCsysName, mdlConfig.arrPosition[i]);
		}
	}

	return true;
}

// 查找组件配置项
int CTotalUnitBuilder::FindModelConfig(
	int nModelType,													// 模型类型(in)
	double dSymbolWidth,											// 符号的宽度(in)
	double dSymbolHeight,											// 符号的高度(in)
	const ModelConfigurationArray &arrMdlConfig						// 组件配置集(in)
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

// 根据符号中心位置和旋转角度，计算装配位置
bool CTotalUnitBuilder::GetModelPosition(
	double dLayoutLeft,												// 布局图的左上角X(in)
	double dLayoutTop,												// 布局图的左上角Y(in)
	double dLayoutWidth,											// 布局图的宽度(in)
	double dLayoutHeight,											// 布局图的高度(in)
	double dSymbolWidth,											// 符号的宽度(in)
	double dSymbolHeight,											// 符号的高度(in)
	double dCenterX,												// 符号中心X(in)
	double dCenterY,												// 符号中心Y(in)
	double dAngle,													// 符号顺时针旋转角度(in)
	IKSCsysData &position											// 模型装配位置(out)
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

// 获取临时图号
CString CTotalUnitBuilder::GetTempPartNo(
	const CString &strTemplateName									// 模板文件名
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

// 获取模板文件名
CString CTotalUnitBuilder::GetTemplateNameByModelType(
	int nModelType													// 组件类型
	)
{
	CString strTemplateName;
	switch (nModelType)
	{
	case DMT_ITC:						// 服务器机柜
		strTemplateName = g_strFWQJGTemplateAsmName;
		break;
	case DMT_MGT:						// 管控柜
		strTemplateName = g_strGKGTemplateAsmName;
		break;
	case DMT_COL_HAED_MGT:				// 列头管控柜
		strTemplateName = g_strGKGTemplateAsmName;
		break;
	case DMT_TAC:						// 空调柜
		strTemplateName = g_strKTGTemplateAsmName;
		break;
	case DMT_FHC:						// 消防柜
		strTemplateName = g_strXFGTemplateAsmName;
		break;
	case DMT_COL_HAED_EMPTY:			// 列头空柜
		strTemplateName = g_strGKGTemplateAsmName;
		break;
	case DMT_PDR:						// 配电柜
		strTemplateName = g_strPDGTemplateAsmName;
		break;
	case DMT_COL_HEAD_PDR:				// 列头配电柜
		strTemplateName = g_strPDGTemplateAsmName;
		break;
	case DMT_ROW_EMPTY:					// 行间空柜
		strTemplateName = g_strHJKGTemplateAsmName;
		break;
	case DMT_DAO_FENG:					// 导风柜
		strTemplateName = g_strDFGTemplateAsmName;
		break;
	case DMT_CASO4_FLOOR:				// 硫酸钙地板
		break;
	case DMT_STEEL_FLOOR:				// 全钢通风地板
		break;
	case DMT_COLD_FRONT_DOOR:			// 通道平门
		strTemplateName = g_strTDPMTemplateAsmName;
		break;
	case DMT_COLD_BACK_DOOR:			// 通道凸门
		strTemplateName = g_strTDTMTemplateAsmName;
		break;
	case DMT_LEFT_FRAME:				// 左框架
		break;
	case DMT_RIGHT_FRAME:				// 右框架
		break;
	case DMT_FLIP_WINDOW:				// 翻转顶窗
		strTemplateName = g_strFZDCTemplateAsmName;
		break;
	case DMT_FIXED_WINDOW:				// 固定顶窗
		strTemplateName = g_strGDDCTemplateAsmName;
		break;
	case DMT_ADJUST_WINDOW:				// 可调顶窗
		strTemplateName = g_strKTDCTemplateAsmName;
		break;
	case DMT_FOOTSTEP:					// 踏步
		break;
	case DMT_ZOU_XIAN_JIA:				// 强弱电走线架
		strTemplateName = g_strZXJTemplateAsmName;
		break;
	case DMT_GUANG_XIAN_ZXJ:			// 光纤走线架
		strTemplateName = g_strGXCTemplateAsmName;
		break;
	case DMT_WALL_PILLAR:				// 墙柱
		break;
	default:
		break;
	}
	return strTemplateName;
}

// 获取装配坐标名名
CString CTotalUnitBuilder::GetCompCsysNameByModelType(
	int nModelType													// 组件类型
	)
{
	CString strCompCsysName;
	switch (nModelType)
	{
	case DMT_ITC:						// 服务器机柜
		strCompCsysName = g_strFWQJGCompCsysName;
		break;
	case DMT_MGT:						// 管控柜
		strCompCsysName = g_strGKGCompCsysName;
		break;
	case DMT_COL_HAED_MGT:				// 列头管控柜
		strCompCsysName = g_strGKGCompCsysName;
		break;
	case DMT_TAC:						// 空调柜
		strCompCsysName = g_strKTGCompCsysName;
		break;
	case DMT_FHC:						// 消防柜
		strCompCsysName = g_strXFGCompCsysName;
		break;
	case DMT_COL_HAED_EMPTY:			// 列头空柜
		strCompCsysName = g_strGKGCompCsysName;
		break;
	case DMT_PDR:						// 配电柜
		strCompCsysName = g_strPDGCompCsysName;
		break;
	case DMT_COL_HEAD_PDR:				// 列头配电柜
		strCompCsysName = g_strPDGCompCsysName;
		break;
	case DMT_ROW_EMPTY:					// 行间空柜
		strCompCsysName = g_strHJKGCompCsysName;
		break;
	case DMT_DAO_FENG:					// 导风柜
		strCompCsysName = g_strDFGCompCsysName;
		break;
	case DMT_CASO4_FLOOR:				// 硫酸钙地板
		break;
	case DMT_STEEL_FLOOR:				// 全钢通风地板
		break;
	case DMT_COLD_FRONT_DOOR:			// 通道平门
		strCompCsysName = g_strTDPMCompCsysName;
		break;
	case DMT_COLD_BACK_DOOR:			// 通道凸门
		strCompCsysName = g_strTDTMCompCsysName;
		break;
	case DMT_LEFT_FRAME:				// 左框架
		break;
	case DMT_RIGHT_FRAME:				// 右框架
		break;
	case DMT_FLIP_WINDOW:				// 翻转顶窗
		strCompCsysName = g_strFZDCCompCsysName;
		break;
	case DMT_FIXED_WINDOW:				// 固定顶窗
		strCompCsysName = g_strGDDCCompCsysName;
		break;
	case DMT_ADJUST_WINDOW:				// 可调顶窗
		strCompCsysName = g_strKTDCCompCsysName;
		break;
	case DMT_FOOTSTEP:					// 踏步
		break;
	case DMT_ZOU_XIAN_JIA:				// 强弱电走线架
		strCompCsysName = g_strZXJCompCsysName;
		break;
	case DMT_GUANG_XIAN_ZXJ:			// 光纤走线架
		strCompCsysName = g_strGXCCompCsysName;
		break;
	case DMT_WALL_PILLAR:				// 墙柱
		break;
	default:
		break;
	}
	return strCompCsysName;
}

// 根据订单采集表和布局图符号集，选配服务器机柜
bool CTotalUnitBuilder::SelectFWQJGConfiguration(
	const RequirementTabData &reqTabData,							// 需求采集表
	CXmlToObject &xmlData,											// 布局图XML相关数据
	vector<CLaySymbolObj*> &arrSymbols,								// 布局图符号集
	ModelConfiguration &modelConfig									// 整机配置
	)
{
	// 获取服务器机柜符号集
	vector<CLaySymbolObj*> arrITCSymbols;
	GetLayoutSymbols(SCT_ITC, arrSymbols, arrITCSymbols);
	if (arrITCSymbols.empty())
		return false;

	modelConfig.strMajorClass = _T("机柜");
	modelConfig.nModelType = DMT_ITC;

	// 获取数据库选配数据
	JiGuiDBData FWQJGDBData;
	if (GetFWQJGDBData(reqTabData, FWQJGDBData))
	{
		// 把正式图号的相关数据写入整机配置中
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
		// 生成临时图号
		modelConfig.strTempPartNo = GetTemplateNameByModelType(modelConfig.nModelType);
		modelConfig.strFormalPartNo = _T("");
		modelConfig.strPurchaseNo = _T("");
		modelConfig.dHeight = reqTabData.dHeightOfITRack;
		modelConfig.dWidth = reqTabData.dWidthOfITRack;
		modelConfig.dDepth = reqTabData.dDepthOfITRack;
		modelConfig.strRemark = _T("");
	}

	// 获取装配位置
	modelConfig.arrPosition.resize(arrITCSymbols.size());
	for (size_t i=0; i<arrITCSymbols.size(); i++)
		GetModelPosition(xmlData.m_dLeft, xmlData.m_dTop, xmlData.m_dWidth, xmlData.m_dHeight,
		arrITCSymbols[i]->m_dWidth, arrITCSymbols[i]->m_dHeight, arrITCSymbols[i]->m_ptCenter.x,
		arrITCSymbols[i]->m_ptCenter.y, arrITCSymbols[i]->m_dAngle, modelConfig.arrPosition[i]);
	// 确定装配高度
	double dZ = GetHeightOfPedestal(reqTabData.nHeightOfPedestal);
	if (!ISDEQUAL(dZ, 0.0))
	{
		for (size_t i=0; i<modelConfig.arrPosition.size(); i++)
			modelConfig.arrPosition[i].o.z = dZ;
	}

	return true;
}

// 根据订单采集表和布局图符号集，选配管控柜
bool CTotalUnitBuilder::SelectGKGConfiguration(
	const RequirementTabData &reqTabData,							// 需求采集表
	CXmlToObject &xmlData,											// 布局图XML相关数据
	vector<CLaySymbolObj*> &arrSymbols,								// 布局图符号集
	ModelConfiguration &gkgConfig									// 整机配置
	)
{
	// 获取管控柜符号集
	vector<CLaySymbolObj*> arrMCCSymbols;
	GetLayoutSymbols(SCT_MCC, arrSymbols, arrMCCSymbols);
	if (arrMCCSymbols.empty())
		return false;

	gkgConfig.strMajorClass = _T("机柜");
	gkgConfig.nModelType = DMT_MGT;

	// 获取数据库选配数据
	JiGuiDBData gkgDBData;
	if (GetGKGDBData(reqTabData, gkgDBData))
	{
		// 把正式图号的相关数据写入整机配置中
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
		// 生成临时图号
		gkgConfig.strTempPartNo = GetTemplateNameByModelType(gkgConfig.nModelType);
		gkgConfig.strFormalPartNo = _T("");
		gkgConfig.strPurchaseNo = _T("");
		gkgConfig.dHeight = reqTabData.dHeightOfITRack;
		gkgConfig.dWidth = reqTabData.dWidthOfITRack;
		gkgConfig.dDepth = reqTabData.dDepthOfITRack;
		gkgConfig.strRemark = _T("");
	}

	// 获取装配位置
	gkgConfig.arrPosition.resize(arrMCCSymbols.size());
	for (size_t i=0; i<arrMCCSymbols.size(); i++)
		GetModelPosition(xmlData.m_dLeft, xmlData.m_dTop, xmlData.m_dWidth, xmlData.m_dHeight,
		arrMCCSymbols[i]->m_dWidth, arrMCCSymbols[i]->m_dHeight, arrMCCSymbols[i]->m_ptCenter.x,
		arrMCCSymbols[i]->m_ptCenter.y, arrMCCSymbols[i]->m_dAngle, gkgConfig.arrPosition[i]);
	// 确定装配高度
	double dZ = GetHeightOfPedestal(reqTabData.nHeightOfPedestal);
	if (!ISDEQUAL(dZ, 0.0))
	{
		for (size_t i=0; i<gkgConfig.arrPosition.size(); i++)
			gkgConfig.arrPosition[i].o.z = dZ;
	}

	return true;
}

// 根据订单采集表，通过数据库获取服务器机柜的配置信息
bool CTotalUnitBuilder::GetFWQJGDBData(
	const RequirementTabData &reqTabData,							// 需求采集表
	JiGuiDBData &jiguiData											// 机柜数据
	)
{
	reqTabData;
	jiguiData.strCode = _T("624100324601");					// 代码
	jiguiData.strPartNo = _T("624100324600");				// 图号
	jiguiData.strName = _T("Z6012-20B机柜");				// 名称
	jiguiData.strEngName = _T("Z6012-20Bcabinet");			// 英文名
	jiguiData.strUnit = _T("个");							// 单位
	jiguiData.strState = _T("通用");						// 状态
	jiguiData.strClass = _T("服务器机柜");					// 类别
	jiguiData.dHeight = 2000.0;								// 高
	jiguiData.dWidth = 600;									// 宽
	jiguiData.dDepth = 1200;								// 深
	jiguiData.strFrontDoor = _T("单开密孔门");				// 前门
	jiguiData.strFrontDoorLock = _T("通用");				// 前门锁型
	jiguiData.strBackDoor = _T("双开密孔门");				// 后门
	jiguiData.strBackDoorLock = _T("通用");					// 后门锁型
	jiguiData.strJiaMianBan = _T("");						// 假面板
	jiguiData.strChuanXianMianBan = _T("");					// 穿线面板
	jiguiData.strLTuoBan = _T("8");							// L型托板
	// 备注
	jiguiData.strRemark = _T("冷通道封闭或热通道封闭，无脚轮和地脚；8对L型导轨；1套127032931003门接地线；左一条扎线板，右两条PDU安装板");
	return true;
}

// 根据订单采集表，通过数据库获取管控柜的配置信息
bool CTotalUnitBuilder::GetGKGDBData(
	const RequirementTabData &reqTabData,							// 需求采集表
	JiGuiDBData &gkgData											// 机柜数据
	)
{
	reqTabData;
	gkgData.strCode = _T("624100315501");				// 代码
	gkgData.strPartNo = _T("624100315500");				// 图号
	gkgData.strName = _T("2000PAD密孔门机柜");			// 名称
	gkgData.strEngName = _T("cabinet");					// 英文名
	gkgData.strUnit = _T("个");							// 单位
	gkgData.strState = _T("通用");						// 状态
	gkgData.strClass = _T("管控柜");					// 类别
	gkgData.dHeight = 2000.0;							// 高
	gkgData.dWidth = 600;								// 宽
	gkgData.dDepth = 1200;								// 深
	gkgData.strFrontDoor = _T("单开密孔门");			// 前门
	gkgData.strFrontDoorLock = _T("通用");				// 前门锁型
	gkgData.strBackDoor = _T("单开PAD密孔门");			// 后门
	gkgData.strBackDoorLock = _T("通用");				// 后门锁型
	gkgData.strJiaMianBan = _T("");						// 假面板
	gkgData.strChuanXianMianBan = _T("1");					// 穿线面板
	gkgData.strLTuoBan = _T("5");							// L型托板
	// 备注
	gkgData.strRemark = _T("冷通道封闭或热通道封闭，无脚轮和地脚；1U穿线面板；5对L型导轨；1套127032931003门接地线");
	return true;
}

// 获取指定类型的布局图符号集
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

// 获取底座高度
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

// 测试生成模型
bool CTotalUnitBuilder::TestBuildModel()
{
	// 整机配置
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

// 根据XML文件生成模型
bool CTotalUnitBuilder::TestBuildModelByXML(const CString &strXMLPath)
{
	CXmlToObject xmlParse;
	xmlParse.Init();
	xmlParse.OpenFile(strXMLPath);

	// 获取符号集
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

	// 生成整机配置信息
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
			// 增加新的整机配置项
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
			// 设置已有整机配置项
			IKSCsysData newPosition;
			GetModelPosition(xmlParse.m_dLeft, xmlParse.m_dTop, xmlParse.m_dWidth, xmlParse.m_dHeight, arrSymbols[i]->m_dWidth, arrSymbols[i]->m_dHeight, arrSymbols[i]->m_ptCenter.x, arrSymbols[i]->m_ptCenter.y, arrSymbols[i]->m_dAngle, newPosition);
			totalUnitConfig.arrModelConfig[nFindMdlConfig].arrPosition.push_back(newPosition);
		}
	}

	xmlParse.UnInit();

	BuildModel(totalUnitConfig);
	return true;
}

// 根据订单需求采集表和整机布局图XML文件生成整机配置模型
bool CTotalUnitBuilder::TestBuildModelByReqTableAndLayoutFile(const CString &strXMLPath)
{
	// 需求采集表的初始化测试数据
	RequirementTabData reqTabData;
	reqTabData.nModuleType = MT_LONG_MODULE;						// 长模块
	reqTabData.bIsExtFloorExist = true;								// 是否存在外部地板
	reqTabData.nAirstreamPattern = AP_COLD_SEAL;					// 冷通道封闭
	reqTabData.dPassageWidth = 1800.0;								// 通道宽度
	reqTabData.dHeightOfITRack = 2000;								// IT机柜规格——高度
	reqTabData.dWidthOfITRack = 600;								// IT机柜规格——宽度
	reqTabData.dDepthOfITRack = 1200;								// IT机柜规格——深度
	reqTabData.nFrontDoorTypeOfITRack = FDT_SINGLE_DENSEHOLE_DOOR;	// IT机柜的前门类型
	reqTabData.nBackDoorTypeOfITRack = FDT_DOUBLE_DENSEHOLE_DOOR;	// IT机柜的后门类型
	reqTabData.nFrontDoorLockTypeOfITRack = FDLT_UNIVERSIAL_LOCK;	// IT机柜的前门锁类型
	reqTabData.nBackDoorLockTypeOfITRack = FDLT_UNIVERSIAL_LOCK;	// IT机柜的后门锁类型
	reqTabData.nSideDoorTypeOfITRack = SDT_DEFAULT_TYPE;			// IT机柜的侧门
	reqTabData.nHeightOfPedestal = HP_300;							// 底座高度
	reqTabData.nInsideFloorType = IFT_DEFAULT_FLOOR;				// 模块内部地板
	reqTabData.nZouXianJiaType = ZXJT_MODULE_TYPE;					// 强弱电走线架配置类型
	reqTabData.dDistanceBetwZXJAndJigui = 0.0;						// (走线架机房配置)走线架距离机柜顶部距离；
	reqTabData.nNumOf1UPanel = 5;									// 1U假面板的数量
	reqTabData.nNumOf2UPanel = 5;									// 2U假面板的数量
	reqTabData.nNumOfLPallet = 5;									// L型托板的数量
	reqTabData.nNumOfLightLayer = 5;								// 轻载层板的数量
	reqTabData.nNumOfHeavyLayer = 5;								// 重载层板的数量
	reqTabData.nNumOfStringingPanel = 5;							// 穿线面板的数量
	reqTabData.nHuiLiuPaiType = HLPT_SHUZHUANG_TYPE;				// 汇流排的类型
	reqTabData.bIsWeiBanExist = true;								// 围板是否配置
	reqTabData.bIsInsideFloorExist = true;							// 模块内部是否配置地板
	reqTabData.bIsTaBuExist = true;									// 是否配置踏步
	reqTabData.nControlCabinetType = CCT_IT_PAD_CAB;				// 管控柜类型

	CXmlToObject xmlParse;
	xmlParse.Init();
	xmlParse.OpenFile(strXMLPath);

	// 获取符号集
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

	// 生成整机配置信息
	TotalUnitConfiguration totalUnitConfig;
	totalUnitConfig.strAsmName = _T("TOTAL_MODEL_00001");

	// 选配服务器机柜
	ModelConfiguration FWQJGConfig;
	if (SelectFWQJGConfiguration(reqTabData, xmlParse, arrSymbols, FWQJGConfig))
		totalUnitConfig.arrModelConfig.push_back(FWQJGConfig);

	// 选配管控柜
	ModelConfiguration GKGConfig;
	if (SelectGKGConfiguration(reqTabData, xmlParse, arrSymbols, GKGConfig))
		totalUnitConfig.arrModelConfig.push_back(GKGConfig);
	xmlParse.UnInit();

	BuildModel(totalUnitConfig);

	return true;
}
