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

// 更新布局参数(从当前装配体获取参数)
void CIKSMDCCableDataMethodMgr::UpdateLayoutParamFromCurAsm()
{

}

// 更新电缆布局参数(从当前装配体获取参数)
void CIKSMDCCableDataMethodMgr::UpdateCableLayoutParamFromCurAsm()
{
	m_RoutCabProjDataInf.m_CableLayoutParam;
}

// 更新电缆布局参数至当前装配体
void CIKSMDCCableDataMethodMgr::UpdateCableLayoutParamToCurAsm() const
{
	m_RoutCabProjDataInf.m_CableLayoutParam;
}

// 更新电缆设计参数(从当前装配体获取参数)
void CIKSMDCCableDataMethodMgr::UpdateCableDesignParamFromCurAsm()
{
	m_RoutCabProjDataInf.m_CableDesignParam;
}

// 更新电缆设计参数至当前装配体
void CIKSMDCCableDataMethodMgr::UpdateCableDesignParamToCurAsm() const
{
	m_RoutCabProjDataInf.m_CableDesignParam;
}

// 根据布局参数修正电缆设计参数
void CIKSMDCCableDataMethodMgr::CorrectCableDesignParamByLayoutParam()
{
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
BOOL CIKSMDCCableDataMethodMgr::CheckConnectorAssembly(const std::vector<IKSMDCConnector> &vecMDCConnector, CBPDynamicArray<UINT> &arrLostCSysConnIndex, CBPDynamicArray<UINT> &arrFailedLoadMdlConnIndex, ProAsmcomppath* pLocateCSysSolidCmpPath/*=NULL*/, CUnicodeString *pPrompt/*=NULL*/)
{
	CBPDynamicArray<IKSConnectorParamInfo> arrConnParam;
	arrConnParam.resize(UINT(vecMDCConnector.size()));
	for (UINT i=0; i<vecMDCConnector.size(); i++)
		arrConnParam[i] = vecMDCConnector[i].stuConnParam;

	BOOL bResult = GetIKSSmartCableDataMethodMgr()->CheckConnectorAssembly(arrLostCSysConnIndex, arrFailedLoadMdlConnIndex, arrConnParam, pLocateCSysSolidCmpPath);
	if (bResult)
	{
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

// 试验
void CIKSMDCCableDataMethodMgr::Test()
{
	// 激活标准应用程序

	// 更新布线装配体（从当前装配体中获取布线装配体，若未找到则进行创建）
	UpdateCablingAsm();

	// 更新当前装配体内的模型树和线束电缆数据
	GetIKSSmartCableDataMethodMgr()->UpdateCurAsmMdlTreeHarnessCableData(TRUE);

	m_RoutCabProjDataInf.m_vecConnector.resize(2);
	for (UINT i=0; i<m_RoutCabProjDataInf.m_vecConnector.size(); i++)
		InitConnectorParam(m_RoutCabProjDataInf.m_vecConnector[i].stuConnParam);
	m_RoutCabProjDataInf.m_vecConnector[0].stuConnParam.strRefDes = L"C-01";
	m_RoutCabProjDataInf.m_vecConnector[1].stuConnParam.strRefDes = L"C-02";

	LoadConnTemplateMdl();
	ProAssembly pConnParentAsm = NULL; // GetCablingAsm()
	ProAsmcomppath* pLocateCSysSolidCmpPath = NULL; // GetCablingAsmCompPathPt()
	// 检查电连接器模型和坐标系
	CUnicodeString strPrompt = L"";
	CBPDynamicArray<UINT> arrLostCSysConnIndex;
	CBPDynamicArray<UINT> arrFailedLoadMdlConnIndex;
	CheckConnectorAssembly(GetRoutCabProjDataInfPt()->m_vecConnector, arrLostCSysConnIndex, arrFailedLoadMdlConnIndex, pLocateCSysSolidCmpPath, &strPrompt);
	if (!strPrompt.IsEmpty())
	{
		AfxMessageBox(strPrompt.GetBuffer());
		CopyTextToClipboard(strPrompt);
	}
	// 自动装配并指定电连接器
	CBPDynamicArray<UINT> arrFailedAsmConnIndex;
	AssemblyAndDesignateConnector(&arrFailedAsmConnIndex, pConnParentAsm, pLocateCSysSolidCmpPath);


	// 注意：电缆应用程序被激活时，无法成功加载并装配模型
	// 激活电缆应用程序
	GetIKSSmartCableDataMethodMgr()->ActiveCableApp();

	// 创建线束模型、电缆特征和线轴特征

	// 布线电缆

}

//===================================================================================================
