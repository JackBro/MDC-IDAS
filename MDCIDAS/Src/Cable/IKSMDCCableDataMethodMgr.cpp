//===================================================================================================
// File:
//		IKSMDCCableDataMethodMgr.cpp
// Summary:
//		微模块电缆数据方法的管理类
// Date:
//		2016-11-21
// Author:
//		WangShiping
//===================================================================================================

#include "stdafx.h"
#include "IKSMDCCableDataMethodMgr.h"
#include "IKSSmartCableDataMethodMgrAPI.h"

//===================================================================================================

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//===================================================================================================
// 全局变量


//===================================================================================================
// 常量定义
const CUnicodeString g_strCabAsmName = L"MDCIDAS_Cabling.asm";
const CUnicodeString g_strCabConnectorMdlName = L"EmptyConn";

//===================================================================================================
// 结构体定义

//===================================================================================================

CIKSMDCCableDataMethodMgr::CIKSMDCCableDataMethodMgr()
{
	m_pCablingAsm = NULL;
	m_stuCablingAsmCompPath.owner = NULL;
	m_stuCablingAsmCompPath.table_num = 0;
	m_stuCablingAsmCompPath.comp_id_table[0] = -1;

	m_strConfig_DefaultConnEntryPortCSysName = _T("CS0");
	m_strConfig_DefaultConnEntryPortType = _T("ROUND");
	m_dConfig_DefaultConnEntryPortIntLength = 0.0;
}

CIKSMDCCableDataMethodMgr::~CIKSMDCCableDataMethodMgr()
{

}

BOOL CIKSMDCCableDataMethodMgr::Init()
{
	// 加载选项数据
	LoadConfig();

	return TRUE;
}

void CIKSMDCCableDataMethodMgr::UnInit()
{
}

// 加载选项数据
void CIKSMDCCableDataMethodMgr::LoadConfig()
{
	CString strIniPath = GetCableConfigPath();
	const IKS_DWORD dwParamNameSize = 1024 * 16;
	wchar_t szParamName[dwParamNameSize];

	IKS_DWORD dwRetSize = GetPrivateProfileStringW(_T("电连接器自动装配"), _T("电连接器入口端坐标系名称默认值"), NULL, szParamName, dwParamNameSize, strIniPath);
	if (dwRetSize>0 && dwRetSize<dwParamNameSize-2)
		m_strConfig_DefaultConnEntryPortCSysName = szParamName;

	dwRetSize = GetPrivateProfileStringW(_T("电连接器自动装配"), _T("电连接器入口端类型默认值"), NULL, szParamName, dwParamNameSize, strIniPath);
	if (dwRetSize>0 && dwRetSize<dwParamNameSize-2)
		m_strConfig_DefaultConnEntryPortType = szParamName;

	dwRetSize = GetPrivateProfileStringW(_T("电连接器自动装配"), _T("电连接器入口端内部长度默认值"), NULL, szParamName, dwParamNameSize, strIniPath);
	if (dwRetSize>0 && dwRetSize<dwParamNameSize-2)
		m_dConfig_DefaultConnEntryPortIntLength = _wtof(szParamName);
}

// 获取布局参数(从当前装配体获取参数)
void CIKSMDCCableDataMethodMgr::GetLayoutParamFromCurAsm()
{
	// 未编写代码
	ASSERT(FALSE);
}

// 获取电缆布局参数(从当前装配体获取参数)
void CIKSMDCCableDataMethodMgr::GetCableLayoutParamFromCurAsm()
{
	// 未编写代码
	ASSERT(FALSE);
	m_RoutCabProjDataInf.m_CableLayoutParam;
}
// 
// // 更新电缆布局参数至当前装配体
// void CIKSMDCCableDataMethodMgr::UpdateCableLayoutParamToCurAsm() const
// {
// 	// 未编写代码
// 	ASSERT(FALSE);
// 	m_RoutCabProjDataInf.m_CableLayoutParam;
// }

// 获取电缆设计参数(从当前布线装配体获取参数)
void CIKSMDCCableDataMethodMgr::GetCableDesignParamFromCurAsm()
{
	GetCableDesignParamFromCurAsm(m_RoutCabProjDataInf.m_CableDesignParam, m_pCablingAsm);
}

// 获取电缆设计参数(从输入布线装配体获取参数)
void CIKSMDCCableDataMethodMgr::GetCableDesignParamFromCurAsm(IKSMDCCableDesignParam &stuCableDesignParam, ProAssembly pCablingAsm/*=NULL*/)
{
	if (pCablingAsm == NULL)
		pCablingAsm = GetCablingAsm();
	stuCableDesignParam.Clear();

	// 未编写代码
	ASSERT(FALSE);
	stuCableDesignParam;
	pCablingAsm;
}

// 更新电缆设计参数至当前装配体
void CIKSMDCCableDataMethodMgr::UpdateCableDesignParamToCurAsm() const
{
	// 未编写代码
	ASSERT(FALSE);
	m_RoutCabProjDataInf.m_CableDesignParam;
}

// 根据布局参数修正电缆设计参数
void CIKSMDCCableDataMethodMgr::CorrectCableDesignParamByLayoutParam()
{
	// 未编写代码
	ASSERT(FALSE);
	m_RoutCabProjDataInf.m_CableDesignParam.stuIT.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuTAC.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuBAT.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuHVDC.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuUPS.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuITPDRH.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuITPDRU.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuFC.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuZM.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuMJ.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuJJAN.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuGK.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuJDX.bValid;
	m_RoutCabProjDataInf.m_CableDesignParam.stuWX.bValid;
}

// 更新布线装配体（从当前装配体中获取布线装配体，若未找到则进行创建）
BOOL CIKSMDCCableDataMethodMgr::UpdateCablingAsm()
{
	m_pCablingAsm = GetCablingAsmInCurAsm(&m_stuCablingAsmCompPath);
	if (m_pCablingAsm == NULL)
		m_pCablingAsm = CreateCablingAsmInCurAsm(&m_stuCablingAsmCompPath);

	return (m_pCablingAsm != NULL);
}

// 验证当前装配体是否需要重建
BOOL CIKSMDCCableDataMethodMgr::IsCablingAsmNeedToRebuild(const IKSMDCCableDesignParam &stuOriCableDesignParam, const IKSMDCCableDesignParam &stuCurCableDesignParam)
{
	// 未编写代码
	ASSERT(FALSE);

	stuOriCableDesignParam;stuCurCableDesignParam;

	return TRUE;
}

// 在当前装配体中创建布线装配体
ProAssembly CIKSMDCCableDataMethodMgr::CreateCablingAsmInCurAsm(ProAsmcomppath *pCablingAsmCompPath/*=NULL*/)
{
	ProAssembly pCablingAsm = NULL;
	ProAssembly pOwnerAsm = GetCurrentAssembly();

	// 将装配体文件复制到临时文件夹
	CUnicodeString strCabAsmTempPath = GetTemplateFolderPath();
	strCabAsmTempPath += L"Cable\\" + g_strCabAsmName;
	CUnicodeString strTempFolderPath = CreateTempDirectory();
	CUnicodeString strCabAsmPath = strTempFolderPath + g_strCabAsmName;
	if (!SVCopyFileAnyway(strCabAsmTempPath, strCabAsmPath))
		return NULL;

	// 加载布线装配体
	ProPath szFullPath;
	wcscpy_s(szFullPath, PRO_PATH_SIZE, strCabAsmPath.GetBuffer());
	if (ProMdlLoad(szFullPath, PRO_MDL_ASSEMBLY, PRO_B_FALSE, (ProMdl*)(&pCablingAsm)) != PRO_TK_NO_ERROR)
		return NULL;
	if (pCablingAsm == NULL)
		return NULL;

	// 装配布线装配体
	ProMatrix trf;
	memset(trf, 0, sizeof(ProMatrix));
	trf[0][0] = trf[1][1] = trf[2][2] = trf[3][3] = 1.0;
	ProFeature featureForAsm;
	if (ProAsmcompAssemble(pOwnerAsm, (ProSolid)pCablingAsm, trf, &featureForAsm) == PRO_TK_NO_ERROR)
		SetDefaultConstraint(&featureForAsm);

	// 删除临时文件夹及其文件
	DeleteDirectoryFiles(strTempFolderPath);

	if (pCablingAsmCompPath != NULL)
	{
		pCablingAsmCompPath->owner = pOwnerAsm;
		pCablingAsmCompPath->table_num = 1;
		pCablingAsmCompPath->comp_id_table[0] = featureForAsm.id;
		pCablingAsmCompPath->comp_id_table[pCablingAsmCompPath->table_num] = -1;
	}

	return pCablingAsm;
}

// 在当前装配体中获取布线装配体
ProAssembly CIKSMDCCableDataMethodMgr::GetCablingAsmInCurAsm(ProAsmcomppath *pCablingAsmCompPath/*=NULL*/)
{
	ProAssembly pCablingAsm = NULL;
	ProAssembly pOwnerAsm = GetCurrentAssembly();

	CABModelNodeData stuNode;
	ProSolidFeatVisit(pOwnerAsm, GetCablingAsmOfAssemblyVisit, GetCablingAsmOfAssemblyFilter, &stuNode);

	pCablingAsm = (ProAssembly)stuNode.handle;
	if (pCablingAsmCompPath != NULL)
	{
		pCablingAsmCompPath->owner = pOwnerAsm;
		pCablingAsmCompPath->table_num = 1;
		pCablingAsmCompPath->comp_id_table[0] = stuNode.nFeatureID;
		pCablingAsmCompPath->comp_id_table[pCablingAsmCompPath->table_num] = -1;
	}

	return pCablingAsm;
}

// 通过装配体遍历子特征的过滤函数
ProError CIKSMDCCableDataMethodMgr::GetCablingAsmOfAssemblyFilter(ProFeature* pFeature, ProAppData pAppData)
{
	pAppData;

	// 过滤掉无效的特征
	IKS_BOOL bIsValid = CheckFeatureValid(pFeature);
	if (!bIsValid)
		return PRO_TK_CONTINUE;

	// 特征类型为元件(零件/组件)
	ProFeattype feaType;
	if (ProFeatureTypeGet(pFeature, &feaType) != PRO_TK_NO_ERROR)
		return PRO_TK_CONTINUE;
	if (feaType != PRO_FEAT_COMPONENT)
		return PRO_TK_CONTINUE;

	return PRO_TK_NO_ERROR;
}

// 通过装配体遍历子特征的访问函数
ProError CIKSMDCCableDataMethodMgr::GetCablingAsmOfAssemblyVisit(ProFeature* pFeature, ProError status, ProAppData pAppData)
{
	status;

	ProMdl pMdl = NULL;
	ProAsmcompMdlGet(pFeature, &pMdl);
	if (pMdl == NULL)
		return PRO_TK_NO_ERROR;

	// 模型类型为装配体
	ProMdlType mdlType;
	if (ProMdlTypeGet(pMdl, &mdlType) != PRO_TK_NO_ERROR)
		return PRO_TK_NO_ERROR;
	if (mdlType != PRO_MDL_ASSEMBLY)
		return PRO_TK_NO_ERROR;

	// 装配体名称为指定的布线装配体名称
	ProName szName;
	if (ProMdlNameGet(pMdl, szName) != PRO_TK_NO_ERROR)
		return PRO_TK_NO_ERROR;
	CString strName1 = g_strCabAsmName.GetBuffer();
	CString strName2 = szName;
	strName1.MakeLower();
	strName2.MakeLower();
	if (strName1.Find(strName2) < 0)
		return PRO_TK_NO_ERROR;

	CABModelNodeData *pNode = (CABModelNodeData*)pAppData;
	if (pNode != NULL)
	{
		pNode->handle = pMdl;
		pNode->nFeatureID = pFeature->id;
	}

	return PRO_TK_USER_ABORT;
}

// 检验输入特征是否有效
IKS_BOOL CIKSMDCCableDataMethodMgr::CheckFeatureValid(ProFeature* pFeature)
{
	// 过滤ProE内部使用的特征(不对用户开放的特征)
	ProBoolean bVisible = PRO_B_FALSE;
	ProFeatureVisibilityGet(pFeature, &bVisible);
	if (bVisible == PRO_B_FALSE)
		return FALSE;

	// 过滤隐含、未激活的特征(隐含特征在模型树中已经不存在)
	ProFeatStatus feaStatus;
	ProFeatureStatusGet(pFeature, &feaStatus);
	if (feaStatus != PRO_FEAT_ACTIVE && feaStatus != PRO_FEAT_UNREGENERATED)
		return FALSE;

	return TRUE;
}

// 设置缺省约束
BOOL CIKSMDCCableDataMethodMgr::SetDefaultConstraint(ProAsmcomp *pAsmComp)
{
	// 初始化约束数组
	ProAsmcompconstraint *arrConstraints = NULL;
	ProAsmcompconstraint pConstraint = NULL;
	ProError status = ProArrayAlloc(0, sizeof(ProAsmcompconstraint), 1,(ProArray*)&arrConstraints);
	status = ProAsmcompconstraintAlloc(&pConstraint);

	// 默认固定约束
	status = ProAsmcompconstraintTypeSet(pConstraint, PRO_ASM_DEF_PLACEMENT);

	status = ProArrayObjectAdd((ProArray*)&arrConstraints, -1, 1, &pConstraint);

	// 设置约束并重生模型
	status = ProAsmcompConstraintsSet(NULL, pAsmComp, arrConstraints);
	ProSolidRegenerate((ProSolid)pAsmComp->owner, PRO_REGEN_CAN_FIX);

	// 释放内存
	ProAsmcompconstraintFree(pConstraint);
	pConstraint = NULL;
	SAFE_DELETE_PROARRAY(arrConstraints);

	return TRUE;
}

// 在布线装配体中创建电连接器定位坐标系（若已存在则将其删除后重新创建或进行修改）（根据顶层装配体中的电连接器定位坐标系进行创建）
BOOL CIKSMDCCableDataMethodMgr::CreateConnLocCSysInCablingAsm()
{
	// 未编写代码
	ASSERT(FALSE);
	return TRUE;
}

// 装配并指定电连接器
BOOL CIKSMDCCableDataMethodMgr::AssemblyAndDesignateConnector(CBPDynamicArray<UINT> *parrFailedAsmConnIndex/*=NULL*/, ProAssembly pConnParentAsm/*=NULL*/, ProAsmcomppath* pLocateCSysSolidCmpPath/*=NULL*/)
{
	CBPDynamicArray<UINT> arrFailedAsmConnIndex;
	if (parrFailedAsmConnIndex == NULL)
		parrFailedAsmConnIndex = &arrFailedAsmConnIndex;

	BOOL bResult = AssemblyAndDesignateConnector(m_RoutCabProjDataInf.m_vecConnector, *parrFailedAsmConnIndex, pConnParentAsm, pLocateCSysSolidCmpPath);
	return bResult;
}

// 装配并指定电连接器
BOOL CIKSMDCCableDataMethodMgr::AssemblyAndDesignateConnector(std::vector<IKSMDCConnector> &vecMDCConnector, CBPDynamicArray<UINT> &arrFailedAsmConnIndex, ProAssembly pConnParentAsm/*=NULL*/, ProAsmcomppath* pLocateCSysSolidCmpPath/*=NULL*/)
{
	CBPDynamicArray<ProConnector> arrProConn;
	CBPDynamicArray<IKSConnectorParamInfo> arrConnParam;
	arrConnParam.resize(UINT(vecMDCConnector.size()));
	for (UINT i=0; i<vecMDCConnector.size(); i++)
		arrConnParam[i] = vecMDCConnector[i].stuConnParam;

	BOOL bResult = GetIKSSmartCableDataMethodMgr()->AssemblyAndDesignateConnector(arrProConn, arrFailedAsmConnIndex, arrConnParam, pConnParentAsm, pLocateCSysSolidCmpPath);
	if (bResult)
	{
		for (UINT i=0; i<vecMDCConnector.size(); i++)
			vecMDCConnector[i].stuConnDataInCurAsm.stuProConnector = arrProConn[i];
	}

	return bResult;
}

// 检验电连接器能否装配
BOOL CIKSMDCCableDataMethodMgr::CheckConnectorAssembly(CBPDynamicArray<UINT> *parrLostCSysConnIndex/*=NULL*/, CBPDynamicArray<UINT> *parrFailedLoadMdlConnIndex/*=NULL*/, ProAsmcomppath* pLocateCSysSolidCmpPath/*=NULL*/, CUnicodeString *pPrompt/*=NULL*/)
{
	CBPDynamicArray<UINT> arrLostCSysConnIndex;
	CBPDynamicArray<UINT> arrFailedLoadMdlConnIndex;
	if (parrLostCSysConnIndex == NULL)
		parrLostCSysConnIndex = &arrLostCSysConnIndex;
	if (parrFailedLoadMdlConnIndex == NULL)
		parrFailedLoadMdlConnIndex = &arrFailedLoadMdlConnIndex;

	BOOL bResult = CheckConnectorAssembly(m_RoutCabProjDataInf.m_vecConnector, *parrLostCSysConnIndex, *parrFailedLoadMdlConnIndex, pLocateCSysSolidCmpPath, pPrompt);
	return bResult;
}

// 检验电连接器能否装配
BOOL CIKSMDCCableDataMethodMgr::CheckConnectorAssembly(const std::vector<IKSMDCConnector> &vecMDCConnector, CBPDynamicArray<UINT> &arrLostCSysConnIndex, CBPDynamicArray<UINT> &arrFailedLoadMdlConnIndex, ProAsmcomppath* pLocateCSysSolidCmpPath/*=NULL*/, CUnicodeString *pPrompt/*=NULL*/)
{
	CBPDynamicArray<IKSConnectorParamInfo> arrConnParam;
	arrConnParam.resize(UINT(vecMDCConnector.size()));
	for (UINT i=0; i<vecMDCConnector.size(); i++)
		arrConnParam[i] = vecMDCConnector[i].stuConnParam;

	BOOL bResult = GetIKSSmartCableDataMethodMgr()->CheckConnectorAssembly(arrLostCSysConnIndex, arrFailedLoadMdlConnIndex, arrConnParam, pLocateCSysSolidCmpPath);
	if (pPrompt != NULL)
	{
		if (arrLostCSysConnIndex.size() > 0)
		{
			(*pPrompt) += L"缺少以下坐标系用于装配定位: ";
			for (UINT i=0; i<arrLostCSysConnIndex.size(); i++)
			{
				(*pPrompt) += arrConnParam[arrLostCSysConnIndex[i]].strRefDes;
				if (i < arrLostCSysConnIndex.size()-1)
					(*pPrompt) += L", ";
			}
			(*pPrompt) += L"\r\n";
		}
		if (arrFailedLoadMdlConnIndex.size() > 0)
		{
			(*pPrompt) += L"未找到以下电连接器模型: ";
			for (UINT i=0; i<arrFailedLoadMdlConnIndex.size(); i++)
			{
				(*pPrompt) += arrConnParam[arrFailedLoadMdlConnIndex[i]].strModelName;
				if (i < arrFailedLoadMdlConnIndex.size()-1)
					(*pPrompt) += L", ";
			}
			(*pPrompt) += L"\r\n";
		}
	}

	return bResult;
}

// 加载的电连接器模板模型
void CIKSMDCCableDataMethodMgr::LoadConnTemplateMdl()
{
	// 将装配体文件复制到临时文件夹
	CUnicodeString strCabConnTempPath = GetTemplateFolderPath();
	strCabConnTempPath += L"Cable\\Conn\\" + g_strCabConnectorMdlName + _T(".prt");
	CUnicodeString strTempFolderPath = CreateTempDirectory();
	CUnicodeString strCabAsmPath = strTempFolderPath + g_strCabConnectorMdlName + _T(".prt");
	if (!SVCopyFileAnyway(strCabConnTempPath, strCabAsmPath))
		return;

	// 加载布线装配体
	ProMdl pConn = NULL;
	ProPath szFullPath;
	wcscpy_s(szFullPath, PRO_PATH_SIZE, strCabAsmPath.GetBuffer());
	ProMdlLoad(szFullPath, PRO_MDL_PART, PRO_B_FALSE, &pConn);

	// 删除临时文件夹及其文件
	DeleteDirectoryFiles(strTempFolderPath);
}

// 初始化电连接器参数
void CIKSMDCCableDataMethodMgr::InitConnectorParam(IKSConnectorParamInfo &stuConnParam)
{
	stuConnParam.Clear();

	stuConnParam.strModelName = g_strCabConnectorMdlName.GetBuffer();
	stuConnParam.bIsMdlAsm = FALSE;

	stuConnParam.vecEntryPortsInfo.resize(1);
	stuConnParam.vecEntryPortsInfo[0].strCSysName = m_strConfig_DefaultConnEntryPortCSysName.GetString();
	stuConnParam.vecEntryPortsInfo[0].strType = m_strConfig_DefaultConnEntryPortType.GetString();
	stuConnParam.vecEntryPortsInfo[0].dIntLength = m_dConfig_DefaultConnEntryPortIntLength;
}

// 电连接器端口坐标系ProSelection的数据申请
BOOL CIKSMDCCableDataMethodMgr::ConnectorPortCSysProSelectionAlloc(const CIKSMDCRoutCabProjDataInf &stuRoutCabProjDataInf, const CSVWString &strRefDes, ProSelection &pSelection, CSVStringIndexMgr *pmapConnRefDesIndexMgr/*=NULL*/)
{
	pSelection = NULL;

	CSVStringIndexMgr mapConnRefDesIndexMgr;
	if (pmapConnRefDesIndexMgr == NULL)
	{
		pmapConnRefDesIndexMgr = &mapConnRefDesIndexMgr;
		for (UINT i=0; i<stuRoutCabProjDataInf.m_vecConnector.size(); i++)
			mapConnRefDesIndexMgr.AddStringIndex(stuRoutCabProjDataInf.m_vecConnector[i].stuConnDataInCurAsm.strRefDes, i);
	}

	UINT uIndex = pmapConnRefDesIndexMgr->GetIndexByString(strRefDes);
	if (uIndex >= stuRoutCabProjDataInf.m_vecConnector.size())
		return FALSE;
	const IKSConnector &stuConnector = stuRoutCabProjDataInf.m_vecConnector[uIndex].stuConnDataInCurAsm;

	if (stuConnector.vecEntryPortsCsys.size() == 0)
		return FALSE;
	
	ProModelitem stuCSysMI = stuConnector.vecEntryPortsCsys[0];
	
	ProAsmcomppath stuConnPath = stuConnector.stuProConnector;
	if (stuConnector.stuProConnector.owner == GetCurrentAssembly())
		stuConnPath = stuConnector.stuProConnector;
	else if (stuConnector.stuProConnector.owner == stuConnector.pParentAsm)
	{
		stuConnPath.owner = stuConnector.stuParentAsmAsmPath.owner;
		stuConnPath.table_num = (stuConnector.stuParentAsmAsmPath.table_num) + stuConnector.stuProConnector.table_num;
		stuConnPath.comp_id_table[stuConnPath.table_num] = -1;
		for (int j=0; j<stuConnector.stuParentAsmAsmPath.table_num; j++)
			stuConnPath.comp_id_table[j] = stuConnector.stuParentAsmAsmPath.comp_id_table[j];
		for (int j=0; j<stuConnector.stuProConnector.table_num; j++)
			stuConnPath.comp_id_table[j + stuConnector.stuParentAsmAsmPath.table_num] = stuConnector.stuProConnector.comp_id_table[j];
	}
	else
		return FALSE;


	if (ProSelectionAlloc(&stuConnPath, &stuCSysMI, &pSelection) != PRO_TK_NO_ERROR)
		return FALSE;
	return TRUE;
}

// 通过布线项目数据信息创建线束及其电缆特征和线轴特征
BOOL CIKSMDCCableDataMethodMgr::CreateHarnessCableSplData()
{
	BOOL bResult = CreateHarnessCableSplData(m_RoutCabProjDataInf, m_pCablingAsm);
	return bResult;
}

// 通过布线项目数据信息创建线束及其电缆特征和线轴特征
BOOL CIKSMDCCableDataMethodMgr::CreateHarnessCableSplData(const CIKSMDCRoutCabProjDataInf &stuRoutCabProjDataInf, ProAssembly pCablingAsm)
{
	std::vector<CIKSMDCHarness*> vecHarnessPt;
	if (!stuRoutCabProjDataInf.GetHarnessPt(vecHarnessPt))
		return FALSE;
	
	for (UINT i=0; i<vecHarnessPt.size(); i++)
	{
		// 创建线束模型
		CreateHarnessMdl(vecHarnessPt[i], pCablingAsm);

		// 创建线轴特征
		GetIKSSmartCableDataMethodMgr()->CreateAndUpdateSpool(vecHarnessPt[i]->GetSpool());

		// 创建线束内的电缆特征
		CreateCableFeatInHarn(vecHarnessPt[i]);
	}

	return TRUE;
}

// 根据当前ProE模型数据更新布线项目数据信息中的线束数据
BOOL CIKSMDCCableDataMethodMgr::UpdateRoutCabProjHarnDataByCurAsmData()
{
	BOOL bResult = UpdateRoutCabProjHarnDataByCurAsmData(m_RoutCabProjDataInf);
	return bResult;
}

// 根据当前ProE模型数据更新布线项目数据信息中的线束数据
BOOL CIKSMDCCableDataMethodMgr::UpdateRoutCabProjHarnDataByCurAsmData(CIKSMDCRoutCabProjDataInf &stuRoutCabProjDataInf)
{
	// 更新当前装配体内的模型树和线束电缆数据
	GetIKSSmartCableDataMethodMgr()->UpdateCurAsmMdlTreeHarnessCableData(TRUE);

	CBPDynamicArray<IKSHarness> &arrCurAsmHarnessInfo = *(GetIKSSmartCableDataMethodMgr()->GetCurAsmHarnessInfoPt());
	CBPDynamicArray<IKSConnector> &arrCurAsmConnectorInfo = *(GetIKSSmartCableDataMethodMgr()->GetCurAsmConnectorInfoPt());

	CSVStringIndexMgr mapHarnNameIndexMgr, mapConnNameIndexMgr;
	for (UINT i=0; i<arrCurAsmHarnessInfo.size(); i++)
		mapHarnNameIndexMgr.AddStringIndex(arrCurAsmHarnessInfo[i].strName, i);
	for (UINT i=0; i<arrCurAsmConnectorInfo.size(); i++)
		mapConnNameIndexMgr.AddStringIndex(arrCurAsmConnectorInfo[i].strRefDes, i);

	UINT uIndex = UINT(-1);
	for (UINT i=0; i<stuRoutCabProjDataInf.m_vecConnector.size(); i++)
	{
		uIndex = mapConnNameIndexMgr.GetIndexByString(stuRoutCabProjDataInf.m_vecConnector[i].stuConnParam.strRefDes);
		if (uIndex >= arrCurAsmConnectorInfo.size())
			continue;
		stuRoutCabProjDataInf.m_vecConnector[i].stuConnDataInCurAsm = arrCurAsmConnectorInfo[uIndex];
	}

	UINT uHarnIndex = UINT(-1), uCabIndex = UINT(-1);
	CSVStringIndexMgr mapCabNameIndexMgr;
	std::vector<CIKSMDCCable*> vecCablePt;
	std::vector<CIKSMDCHarness*> vecHarnessPt;
	stuRoutCabProjDataInf.GetHarnessPt(vecHarnessPt);
	for (UINT i=0; i<vecHarnessPt.size(); i++)
	{
		uHarnIndex = mapHarnNameIndexMgr.GetIndexByString(vecHarnessPt[i]->GetName());
		if (uHarnIndex >= arrCurAsmHarnessInfo.size())
			continue;
		vecHarnessPt[i]->SetHarnDataInCurAsm(arrCurAsmHarnessInfo[uHarnIndex]);

		mapCabNameIndexMgr.clear();
		for (UINT j=0; j<arrCurAsmHarnessInfo[uHarnIndex].vecCables.size(); j++)
			mapCabNameIndexMgr.AddStringIndex(arrCurAsmHarnessInfo[uHarnIndex].vecCables[j].strName, j);

		vecCablePt.clear();
		vecHarnessPt[i]->GetCablePt(vecCablePt);
		for (UINT j=0; j<vecCablePt.size(); j++)
		{
			uCabIndex = mapCabNameIndexMgr.GetIndexByString(vecCablePt[j]->GetName());
			if (uCabIndex >= arrCurAsmHarnessInfo[uHarnIndex].vecCables.size())
				continue;
			vecCablePt[j]->SetCurAsmHarnCableIndex(uCabIndex);
			vecCablePt[j]->SetProeCable(arrCurAsmHarnessInfo[uHarnIndex].vecCables[uCabIndex].stuProeCable);
		}
	}

	return TRUE;
}

// 通过布线项目数据信息布线电缆
BOOL CIKSMDCCableDataMethodMgr::RoutingCable()
{
	BOOL bResult = RoutingCable(m_RoutCabProjDataInf, m_pCablingAsm);
	return bResult;
}

// 通过布线项目数据信息布线电缆
BOOL CIKSMDCCableDataMethodMgr::RoutingCable(const CIKSMDCRoutCabProjDataInf &stuRoutCabProjDataInf, ProAssembly pCablingAsm)
{
	CSVStringIndexMgr mapConnRefDesIndexMgr;
	for (UINT i=0; i<stuRoutCabProjDataInf.m_vecConnector.size(); i++)
		mapConnRefDesIndexMgr.AddStringIndex(stuRoutCabProjDataInf.m_vecConnector[i].stuConnDataInCurAsm.strRefDes, i);

	std::vector<CIKSMDCHarness*> vecHarnessPt;
	if (!stuRoutCabProjDataInf.GetHarnessPt(vecHarnessPt))
		return FALSE;

	CBPDynamicArray<UINT> arrHarnessCableIndex;
	CBPDynamicArray<ProSelection> arrCableStart;
	CBPDynamicArray<ProSelection> arrCableEnd;
	CBPDynamicArray<CBPDynamicArray<SVBASEDOUBLE3> > arrCableMidPos;
	std::vector<SVBASEDOUBLE3> vecCurCableMidPos;
	std::vector<CIKSMDCCable*> vecCablePt;
	for (UINT i=0; i<vecHarnessPt.size(); i++)
	{
		vecCablePt.clear();
		vecHarnessPt[i]->GetCablePt(vecCablePt);

		arrHarnessCableIndex.resize(vecCablePt.size());
		arrCableStart.resize(vecCablePt.size());
		arrCableEnd.resize(vecCablePt.size());
		arrCableMidPos.resize(vecCablePt.size());
		for (UINT j=0; j<vecCablePt.size(); j++)
		{
			arrHarnessCableIndex[j] = UINT(-1);
			arrCableStart[j] = NULL;
			arrCableEnd[j] = NULL;
			arrCableMidPos[j].clear();

			arrHarnessCableIndex[j] = vecCablePt[j]->GetCurAsmHarnCableIndex();
			ConnectorPortCSysProSelectionAlloc(stuRoutCabProjDataInf, vecCablePt[j]->GetCabConnRefDes1(), arrCableStart[j], &mapConnRefDesIndexMgr);
			ConnectorPortCSysProSelectionAlloc(stuRoutCabProjDataInf, vecCablePt[j]->GetCabConnRefDes2(), arrCableEnd[j], &mapConnRefDesIndexMgr);
			vecCurCableMidPos = vecCablePt[j]->GetCabMidPos();
			arrCableMidPos[j].resize(UINT(vecCurCableMidPos.size()));
			if (vecCurCableMidPos.size() > 0)
				memcpy_s(&(arrCableMidPos[j][0]), sizeof(SVBASEDOUBLE3)*vecCurCableMidPos.size(), &(vecCurCableMidPos[0]), sizeof(SVBASEDOUBLE3)*vecCurCableMidPos.size());
		}
		GetIKSSmartCableDataMethodMgr()->CreateRoutingCable(*(vecHarnessPt[i]->GetHarnDataInCurAsmPt()), arrHarnessCableIndex, arrCableStart, arrCableEnd, arrCableMidPos, pCablingAsm, TRUE);
		for (UINT j=0; j<arrCableStart.size(); j++)
			SAFE_DELETE_SELECTION(arrCableStart[j]);
		arrCableStart.clear();
		for (UINT j=0; j<arrCableEnd.size(); j++)
			SAFE_DELETE_SELECTION(arrCableEnd[j]);
		arrCableEnd.clear();
	}
}

// 创建线束模型
BOOL CIKSMDCCableDataMethodMgr::CreateHarnessMdl(CIKSMDCHarness* pHarness, ProAssembly pCablingAsm)
{
	ProHarness pProHarness = NULL;
	ProName name;
	wcscpy_s(name, PRO_NAME_SIZE, pHarness->GetName());
	ProError err = ProHarnessCreate(pCablingAsm, name, &pProHarness);
	if (err == PRO_TK_NO_ERROR)
	{
		pHarness->GetHarnDataInCurAsmPt()->pProePt = pProHarness;
		ProSolidRegenerate(pProHarness, PRO_REGEN_NO_FLAGS);
	}
	else
	{
		pHarness->GetHarnDataInCurAsmPt()->pProePt = NULL;
	}

	return TRUE;
}

// 创建线束内的电缆特征
BOOL CIKSMDCCableDataMethodMgr::CreateCableFeatInHarn(CIKSMDCHarness* pHarness)
{
	std::vector<CIKSMDCCable*> vecCablePt;
	pHarness->GetCablePt(vecCablePt);

	for (UINT i=0; i<vecCablePt.size(); i++)
	{
		CreateCableFeat(pHarness, vecCablePt[i]);
	}

	return TRUE;
}

// 创建电缆特征
BOOL CIKSMDCCableDataMethodMgr::CreateCableFeat(CIKSMDCHarness* pHarness, CIKSMDCCable* pCable)
{
	ProCable stuProCable = pCable->GetProeCable();
	ProName name;
	wcscpy_s(name, PRO_NAME_SIZE, pCable->GetName());
	ProError err = ProCableCreate(pHarness->GetHarnDataInCurAsmPt()->pProePt, &(pHarness->GetSpoolPt()->stuProeSpool), name, &stuProCable);
	if (err == PRO_TK_E_NOT_FOUND)		// Spool does not exist yet.
	{
		// 创建线轴特征
		GetIKSSmartCableDataMethodMgr()->CreateAndUpdateSpool(pHarness->GetSpool());
		err = ProCableCreate(pHarness->GetHarnDataInCurAsmPt()->pProePt, &(pHarness->GetSpoolPt()->stuProeSpool), name, &stuProCable);
	}

	if (err == PRO_TK_NO_ERROR)
	{
	}
	else if (err == PRO_TK_E_FOUND)		// Cable already exists.
	{
	}
	else if (err != PRO_TK_NO_ERROR)
	{
		stuProCable.owner = NULL;
		stuProCable.id = -1;
	}
	pCable->SetProeCable(stuProCable);

	return TRUE;
}

// 试验
void CIKSMDCCableDataMethodMgr::Test()
{
	// 注意：加载模型(ProMdlLoad)前不允许调用执行映射键，否则模型将会加载失败!

	// 更新布线装配体（从当前装配体中获取布线装配体，若未找到则进行创建）
	UpdateCablingAsm();

	// 获取电缆设计参数(从输入布线装配体获取参数)
	IKSMDCCableDesignParam stuOriCableDesignParam;
	GetCableDesignParamFromCurAsm(stuOriCableDesignParam);

	// 更新电缆设计参数至当前装配体
	UpdateCableDesignParamToCurAsm();

	// 验证当前装配体是否需要重建
	BOOL bForceRebuild = FALSE;
	BOOL bRebuild = IsCablingAsmNeedToRebuild(stuOriCableDesignParam, GetCableDesignParam());
	if (!(bRebuild || bForceRebuild))
		return;

	// 更新当前装配体内的模型树和线束电缆数据
	GetIKSSmartCableDataMethodMgr()->UpdateCurAsmMdlTreeHarnessCableData(TRUE);

	// 删除布线装配体中的所有线束数据和电连接器数据

	// 初始化数据
	ProAssembly pConnParentAsm = GetCablingAsm(); // GetCablingAsm() // NULL
	ProAsmcomppath* pLocateCSysSolidCmpPath = GetCablingAsmCompPathPt(); // GetCablingAsmCompPathPt()	// NULL

	// 手动初始化数据
	m_RoutCabProjDataInf.m_vecConnector.resize(3);
	for (UINT i=0; i<m_RoutCabProjDataInf.m_vecConnector.size(); i++)
		InitConnectorParam(m_RoutCabProjDataInf.m_vecConnector[i].stuConnParam);
	m_RoutCabProjDataInf.m_vecConnector[0].stuConnParam.strRefDes = L"C-01";
	m_RoutCabProjDataInf.m_vecConnector[1].stuConnParam.strRefDes = L"C-02";
	m_RoutCabProjDataInf.m_vecConnector[2].stuConnParam.strRefDes = L"M-02";

	IKSSpool spl1, spl2, spl3;
	spl1.stuProeSpool.owner = pConnParentAsm;
	wcscpy_s(spl1.stuProeSpool.name, PRO_NAME_SIZE, L"SplHarnIT1");
	spl1.dDiameter = 1.0;
	spl1.dMinBendRadius = 0.1;
	spl1.strColor = L"red";
	spl2.stuProeSpool.owner = pConnParentAsm;
	wcscpy_s(spl2.stuProeSpool.name, PRO_NAME_SIZE, L"SplHarnIT2");
	spl2.dDiameter = 2.0;
	spl2.dMinBendRadius = 0.1;
	spl2.strColor = L"grn";
	spl3.stuProeSpool.owner = pConnParentAsm;
	wcscpy_s(spl3.stuProeSpool.name, PRO_NAME_SIZE, L"SplHarnTAC1");
	spl3.dDiameter = 5.0;
	spl3.dMinBendRadius = 0.1;
	spl3.strColor = L"blu";

	std::vector<SVBASEDOUBLE3> vecMidPos1, vecMidPos2;
	vecMidPos1.resize(1);
	vecMidPos1[0] = SVDOUBLE3(0.0, 0.0, 0.0);
	vecMidPos2.resize(2);
	vecMidPos2[0] = SVDOUBLE3(0.0, 10.0, 0.0);
	vecMidPos2[1] = SVDOUBLE3(0.0, -10.0, 0.0);

	m_RoutCabProjDataInf.m_HarnIT.ResizeHarness(2);
	CIKSMDCHarnessIT *pHarnIT1 = m_RoutCabProjDataInf.m_HarnIT.GetHarnessByIndex(0);
	CIKSMDCHarnessIT *pHarnIT2 = m_RoutCabProjDataInf.m_HarnIT.GetHarnessByIndex(1);
	pHarnIT1->SetName(L"IT_Harn1");
	pHarnIT1->SetSpool(spl1);
	pHarnIT1->ResizeCable(2);
	CIKSMDCCableIT *pCabIT1_1 = pHarnIT1->GetCableByIndex(0);
	CIKSMDCCableIT *pCabIT1_2 = pHarnIT1->GetCableByIndex(1);
	pCabIT1_1->SetName(L"IT1Cab1");
	pCabIT1_1->SetCabConnRefDes1(L"M-02");
	pCabIT1_1->SetCabConnRefDes2(L"C-01");
	pCabIT1_1->SetCabMidPos(vecMidPos1);
	pCabIT1_2->SetName(L"IT1Cab2");
	pCabIT1_2->SetCabConnRefDes1(L"M-02");
	pCabIT1_2->SetCabConnRefDes2(L"C-02");
	pCabIT1_2->SetCabMidPos(vecMidPos1);

	pHarnIT2->SetName(L"IT_Harn2");
	pHarnIT2->SetSpool(spl2);
	pHarnIT2->ResizeCable(1);
	CIKSMDCCableIT *pCabIT2_1 = pHarnIT2->GetCableByIndex(0);
	pCabIT2_1->SetName(L"IT2Cab1");
	pCabIT2_1->SetCabConnRefDes1(L"C-01");
	pCabIT2_1->SetCabConnRefDes2(L"C-02");
	pCabIT2_1->SetCabMidPos(vecMidPos1);

	m_RoutCabProjDataInf.m_HarnTAC.ResizeHarness(1);
	CIKSMDCHarnessTAC *pHarnTAC1 = m_RoutCabProjDataInf.m_HarnTAC.GetHarnessByIndex(0);
	pHarnTAC1->SetName(L"TAC_Harn1");
	pHarnTAC1->SetSpool(spl3);
	pHarnTAC1->ResizeCable(1);
	CIKSMDCCableTAC *pCabTAC1_1 = pHarnTAC1->GetCableByIndex(0);
	pCabTAC1_1->SetName(L"TAC1Cab1");
	pCabTAC1_1->SetCabConnRefDes1(L"C-01");
	pCabTAC1_1->SetCabConnRefDes2(L"C-02");
	pCabTAC1_1->SetCabMidPos(vecMidPos2);

	// 在布线装配体中创建电连接器定位坐标系（若已存在则将其删除后重新创建或进行修改）
	CreateConnLocCSysInCablingAsm();

	// 加载的电连接器模板模型
	LoadConnTemplateMdl();
	// 检查电连接器模型和坐标系
	CUnicodeString strPrompt = L"";
	if (!CheckConnectorAssembly(NULL, NULL, pLocateCSysSolidCmpPath, &strPrompt))
	{
		AfxMessageBox(strPrompt.GetBuffer());
		CopyTextToClipboard(strPrompt);
		if (IDNO == AfxMessageBox(L"无法正确的装配电连接器,是否继续?", MB_YESNO))
			return;
	}
	// 自动装配并指定电连接器
	CBPDynamicArray<UINT> arrFailedAsmConnIndex;
	AssemblyAndDesignateConnector(&arrFailedAsmConnIndex, pConnParentAsm, pLocateCSysSolidCmpPath);


// 	// 激活电缆应用程序
// 	GetIKSSmartCableDataMethodMgr()->ActiveCableApp();

	// 创建线束模型、电缆特征和线轴特征
	CreateHarnessCableSplData();

	// 根据当前ProE模型数据更新布线项目数据信息中的线束数据
	UpdateRoutCabProjHarnDataByCurAsmData();

	// 布线电缆
	RoutingCable();
}

//===================================================================================================
