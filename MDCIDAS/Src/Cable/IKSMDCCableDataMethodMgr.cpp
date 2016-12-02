//===================================================================================================
// File:
//		IKSMDCCableDataMethodMgr.cpp
// Summary:
//		΢ģ��������ݷ����Ĺ�����
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
// ȫ�ֱ���


//===================================================================================================
// ��������
const CUnicodeString g_strCabAsmName = L"MDCIDAS_Cabling.asm";
const CUnicodeString g_strCabConnectorMdlName = L"EmptyConn";

//===================================================================================================
// �ṹ�嶨��

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
	// ����ѡ������
	LoadConfig();

	return TRUE;
}

void CIKSMDCCableDataMethodMgr::UnInit()
{
}

// ����ѡ������
void CIKSMDCCableDataMethodMgr::LoadConfig()
{
	CString strIniPath = GetCableConfigPath();
	const IKS_DWORD dwParamNameSize = 1024 * 16;
	wchar_t szParamName[dwParamNameSize];

	IKS_DWORD dwRetSize = GetPrivateProfileStringW(_T("���������Զ�װ��"), _T("����������ڶ�����ϵ����Ĭ��ֵ"), NULL, szParamName, dwParamNameSize, strIniPath);
	if (dwRetSize>0 && dwRetSize<dwParamNameSize-2)
		m_strConfig_DefaultConnEntryPortCSysName = szParamName;

	dwRetSize = GetPrivateProfileStringW(_T("���������Զ�װ��"), _T("����������ڶ�����Ĭ��ֵ"), NULL, szParamName, dwParamNameSize, strIniPath);
	if (dwRetSize>0 && dwRetSize<dwParamNameSize-2)
		m_strConfig_DefaultConnEntryPortType = szParamName;

	dwRetSize = GetPrivateProfileStringW(_T("���������Զ�װ��"), _T("����������ڶ��ڲ�����Ĭ��ֵ"), NULL, szParamName, dwParamNameSize, strIniPath);
	if (dwRetSize>0 && dwRetSize<dwParamNameSize-2)
		m_dConfig_DefaultConnEntryPortIntLength = _wtof(szParamName);
}

// ��ȡ���ֲ���(�ӵ�ǰװ�����ȡ����)
void CIKSMDCCableDataMethodMgr::GetLayoutParamFromCurAsm()
{
	// δ��д����
	ASSERT(FALSE);
}

// ��ȡ���²��ֲ���(�ӵ�ǰװ�����ȡ����)
void CIKSMDCCableDataMethodMgr::GetCableLayoutParamFromCurAsm()
{
	// δ��д����
	ASSERT(FALSE);
	m_RoutCabProjDataInf.m_CableLayoutParam;
}
// 
// // ���µ��²��ֲ�������ǰװ����
// void CIKSMDCCableDataMethodMgr::UpdateCableLayoutParamToCurAsm() const
// {
// 	// δ��д����
// 	ASSERT(FALSE);
// 	m_RoutCabProjDataInf.m_CableLayoutParam;
// }

// ��ȡ������Ʋ���(�ӵ�ǰ����װ�����ȡ����)
void CIKSMDCCableDataMethodMgr::GetCableDesignParamFromCurAsm()
{
	GetCableDesignParamFromCurAsm(m_RoutCabProjDataInf.m_CableDesignParam, m_pCablingAsm);
}

// ��ȡ������Ʋ���(�����벼��װ�����ȡ����)
void CIKSMDCCableDataMethodMgr::GetCableDesignParamFromCurAsm(IKSMDCCableDesignParam &stuCableDesignParam, ProAssembly pCablingAsm/*=NULL*/)
{
	if (pCablingAsm == NULL)
		pCablingAsm = GetCablingAsm();
	stuCableDesignParam.Clear();

	// δ��д����
	ASSERT(FALSE);
	stuCableDesignParam;
	pCablingAsm;
}

// ���µ�����Ʋ�������ǰװ����
void CIKSMDCCableDataMethodMgr::UpdateCableDesignParamToCurAsm() const
{
	// δ��д����
	ASSERT(FALSE);
	m_RoutCabProjDataInf.m_CableDesignParam;
}

// ���ݲ��ֲ�������������Ʋ���
void CIKSMDCCableDataMethodMgr::CorrectCableDesignParamByLayoutParam()
{
	// δ��д����
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

// ���²���װ���壨�ӵ�ǰװ�����л�ȡ����װ���壬��δ�ҵ�����д�����
BOOL CIKSMDCCableDataMethodMgr::UpdateCablingAsm()
{
	m_pCablingAsm = GetCablingAsmInCurAsm(&m_stuCablingAsmCompPath);
	if (m_pCablingAsm == NULL)
		m_pCablingAsm = CreateCablingAsmInCurAsm(&m_stuCablingAsmCompPath);

	return (m_pCablingAsm != NULL);
}

// ��֤��ǰװ�����Ƿ���Ҫ�ؽ�
BOOL CIKSMDCCableDataMethodMgr::IsCablingAsmNeedToRebuild(const IKSMDCCableDesignParam &stuOriCableDesignParam, const IKSMDCCableDesignParam &stuCurCableDesignParam)
{
	// δ��д����
	ASSERT(FALSE);

	stuOriCableDesignParam;stuCurCableDesignParam;

	return TRUE;
}

// �ڵ�ǰװ�����д�������װ����
ProAssembly CIKSMDCCableDataMethodMgr::CreateCablingAsmInCurAsm(ProAsmcomppath *pCablingAsmCompPath/*=NULL*/)
{
	ProAssembly pCablingAsm = NULL;
	ProAssembly pOwnerAsm = GetCurrentAssembly();

	// ��װ�����ļ����Ƶ���ʱ�ļ���
	CUnicodeString strCabAsmTempPath = GetTemplateFolderPath();
	strCabAsmTempPath += L"Cable\\" + g_strCabAsmName;
	CUnicodeString strTempFolderPath = CreateTempDirectory();
	CUnicodeString strCabAsmPath = strTempFolderPath + g_strCabAsmName;
	if (!SVCopyFileAnyway(strCabAsmTempPath, strCabAsmPath))
		return NULL;

	// ���ز���װ����
	ProPath szFullPath;
	wcscpy_s(szFullPath, PRO_PATH_SIZE, strCabAsmPath.GetBuffer());
	if (ProMdlLoad(szFullPath, PRO_MDL_ASSEMBLY, PRO_B_FALSE, (ProMdl*)(&pCablingAsm)) != PRO_TK_NO_ERROR)
		return NULL;
	if (pCablingAsm == NULL)
		return NULL;

	// װ�䲼��װ����
	ProMatrix trf;
	memset(trf, 0, sizeof(ProMatrix));
	trf[0][0] = trf[1][1] = trf[2][2] = trf[3][3] = 1.0;
	ProFeature featureForAsm;
	if (ProAsmcompAssemble(pOwnerAsm, (ProSolid)pCablingAsm, trf, &featureForAsm) == PRO_TK_NO_ERROR)
		SetDefaultConstraint(&featureForAsm);

	// ɾ����ʱ�ļ��м����ļ�
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

// �ڵ�ǰװ�����л�ȡ����װ����
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

// ͨ��װ��������������Ĺ��˺���
ProError CIKSMDCCableDataMethodMgr::GetCablingAsmOfAssemblyFilter(ProFeature* pFeature, ProAppData pAppData)
{
	pAppData;

	// ���˵���Ч������
	IKS_BOOL bIsValid = CheckFeatureValid(pFeature);
	if (!bIsValid)
		return PRO_TK_CONTINUE;

	// ��������ΪԪ��(���/���)
	ProFeattype feaType;
	if (ProFeatureTypeGet(pFeature, &feaType) != PRO_TK_NO_ERROR)
		return PRO_TK_CONTINUE;
	if (feaType != PRO_FEAT_COMPONENT)
		return PRO_TK_CONTINUE;

	return PRO_TK_NO_ERROR;
}

// ͨ��װ��������������ķ��ʺ���
ProError CIKSMDCCableDataMethodMgr::GetCablingAsmOfAssemblyVisit(ProFeature* pFeature, ProError status, ProAppData pAppData)
{
	status;

	ProMdl pMdl = NULL;
	ProAsmcompMdlGet(pFeature, &pMdl);
	if (pMdl == NULL)
		return PRO_TK_NO_ERROR;

	// ģ������Ϊװ����
	ProMdlType mdlType;
	if (ProMdlTypeGet(pMdl, &mdlType) != PRO_TK_NO_ERROR)
		return PRO_TK_NO_ERROR;
	if (mdlType != PRO_MDL_ASSEMBLY)
		return PRO_TK_NO_ERROR;

	// װ��������Ϊָ���Ĳ���װ��������
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

// �������������Ƿ���Ч
IKS_BOOL CIKSMDCCableDataMethodMgr::CheckFeatureValid(ProFeature* pFeature)
{
	// ����ProE�ڲ�ʹ�õ�����(�����û����ŵ�����)
	ProBoolean bVisible = PRO_B_FALSE;
	ProFeatureVisibilityGet(pFeature, &bVisible);
	if (bVisible == PRO_B_FALSE)
		return FALSE;

	// ����������δ���������(����������ģ�������Ѿ�������)
	ProFeatStatus feaStatus;
	ProFeatureStatusGet(pFeature, &feaStatus);
	if (feaStatus != PRO_FEAT_ACTIVE && feaStatus != PRO_FEAT_UNREGENERATED)
		return FALSE;

	return TRUE;
}

// ����ȱʡԼ��
BOOL CIKSMDCCableDataMethodMgr::SetDefaultConstraint(ProAsmcomp *pAsmComp)
{
	// ��ʼ��Լ������
	ProAsmcompconstraint *arrConstraints = NULL;
	ProAsmcompconstraint pConstraint = NULL;
	ProError status = ProArrayAlloc(0, sizeof(ProAsmcompconstraint), 1,(ProArray*)&arrConstraints);
	status = ProAsmcompconstraintAlloc(&pConstraint);

	// Ĭ�Ϲ̶�Լ��
	status = ProAsmcompconstraintTypeSet(pConstraint, PRO_ASM_DEF_PLACEMENT);

	status = ProArrayObjectAdd((ProArray*)&arrConstraints, -1, 1, &pConstraint);

	// ����Լ��������ģ��
	status = ProAsmcompConstraintsSet(NULL, pAsmComp, arrConstraints);
	ProSolidRegenerate((ProSolid)pAsmComp->owner, PRO_REGEN_CAN_FIX);

	// �ͷ��ڴ�
	ProAsmcompconstraintFree(pConstraint);
	pConstraint = NULL;
	SAFE_DELETE_PROARRAY(arrConstraints);

	return TRUE;
}

// �ڲ���װ�����д�������������λ����ϵ�����Ѵ�������ɾ�������´���������޸ģ������ݶ���װ�����еĵ���������λ����ϵ���д�����
BOOL CIKSMDCCableDataMethodMgr::CreateConnLocCSysInCablingAsm()
{
	// δ��д����
	ASSERT(FALSE);
	return TRUE;
}

// װ�䲢ָ����������
BOOL CIKSMDCCableDataMethodMgr::AssemblyAndDesignateConnector(CBPDynamicArray<UINT> *parrFailedAsmConnIndex/*=NULL*/, ProAssembly pConnParentAsm/*=NULL*/, ProAsmcomppath* pLocateCSysSolidCmpPath/*=NULL*/)
{
	CBPDynamicArray<UINT> arrFailedAsmConnIndex;
	if (parrFailedAsmConnIndex == NULL)
		parrFailedAsmConnIndex = &arrFailedAsmConnIndex;

	BOOL bResult = AssemblyAndDesignateConnector(m_RoutCabProjDataInf.m_vecConnector, *parrFailedAsmConnIndex, pConnParentAsm, pLocateCSysSolidCmpPath);
	return bResult;
}

// װ�䲢ָ����������
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

// ������������ܷ�װ��
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

// ������������ܷ�װ��
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
			(*pPrompt) += L"ȱ����������ϵ����װ�䶨λ: ";
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
			(*pPrompt) += L"δ�ҵ����µ�������ģ��: ";
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

// ���صĵ�������ģ��ģ��
void CIKSMDCCableDataMethodMgr::LoadConnTemplateMdl()
{
	// ��װ�����ļ����Ƶ���ʱ�ļ���
	CUnicodeString strCabConnTempPath = GetTemplateFolderPath();
	strCabConnTempPath += L"Cable\\Conn\\" + g_strCabConnectorMdlName + _T(".prt");
	CUnicodeString strTempFolderPath = CreateTempDirectory();
	CUnicodeString strCabAsmPath = strTempFolderPath + g_strCabConnectorMdlName + _T(".prt");
	if (!SVCopyFileAnyway(strCabConnTempPath, strCabAsmPath))
		return;

	// ���ز���װ����
	ProMdl pConn = NULL;
	ProPath szFullPath;
	wcscpy_s(szFullPath, PRO_PATH_SIZE, strCabAsmPath.GetBuffer());
	ProMdlLoad(szFullPath, PRO_MDL_PART, PRO_B_FALSE, &pConn);

	// ɾ����ʱ�ļ��м����ļ�
	DeleteDirectoryFiles(strTempFolderPath);
}

// ��ʼ��������������
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

// ���������˿�����ϵProSelection����������
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

// ͨ��������Ŀ������Ϣ�����������������������������
BOOL CIKSMDCCableDataMethodMgr::CreateHarnessCableSplData()
{
	BOOL bResult = CreateHarnessCableSplData(m_RoutCabProjDataInf, m_pCablingAsm);
	return bResult;
}

// ͨ��������Ŀ������Ϣ�����������������������������
BOOL CIKSMDCCableDataMethodMgr::CreateHarnessCableSplData(const CIKSMDCRoutCabProjDataInf &stuRoutCabProjDataInf, ProAssembly pCablingAsm)
{
	std::vector<CIKSMDCHarness*> vecHarnessPt;
	if (!stuRoutCabProjDataInf.GetHarnessPt(vecHarnessPt))
		return FALSE;
	
	for (UINT i=0; i<vecHarnessPt.size(); i++)
	{
		// ��������ģ��
		CreateHarnessMdl(vecHarnessPt[i], pCablingAsm);

		// ������������
		GetIKSSmartCableDataMethodMgr()->CreateAndUpdateSpool(vecHarnessPt[i]->GetSpool());

		// ���������ڵĵ�������
		CreateCableFeatInHarn(vecHarnessPt[i]);
	}

	return TRUE;
}

// ���ݵ�ǰProEģ�����ݸ��²�����Ŀ������Ϣ�е���������
BOOL CIKSMDCCableDataMethodMgr::UpdateRoutCabProjHarnDataByCurAsmData()
{
	BOOL bResult = UpdateRoutCabProjHarnDataByCurAsmData(m_RoutCabProjDataInf);
	return bResult;
}

// ���ݵ�ǰProEģ�����ݸ��²�����Ŀ������Ϣ�е���������
BOOL CIKSMDCCableDataMethodMgr::UpdateRoutCabProjHarnDataByCurAsmData(CIKSMDCRoutCabProjDataInf &stuRoutCabProjDataInf)
{
	// ���µ�ǰװ�����ڵ�ģ������������������
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

// ͨ��������Ŀ������Ϣ���ߵ���
BOOL CIKSMDCCableDataMethodMgr::RoutingCable()
{
	BOOL bResult = RoutingCable(m_RoutCabProjDataInf, m_pCablingAsm);
	return bResult;
}

// ͨ��������Ŀ������Ϣ���ߵ���
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

// ��������ģ��
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

// ���������ڵĵ�������
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

// ������������
BOOL CIKSMDCCableDataMethodMgr::CreateCableFeat(CIKSMDCHarness* pHarness, CIKSMDCCable* pCable)
{
	ProCable stuProCable = pCable->GetProeCable();
	ProName name;
	wcscpy_s(name, PRO_NAME_SIZE, pCable->GetName());
	ProError err = ProCableCreate(pHarness->GetHarnDataInCurAsmPt()->pProePt, &(pHarness->GetSpoolPt()->stuProeSpool), name, &stuProCable);
	if (err == PRO_TK_E_NOT_FOUND)		// Spool does not exist yet.
	{
		// ������������
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

// ����
void CIKSMDCCableDataMethodMgr::Test()
{
	// ע�⣺����ģ��(ProMdlLoad)ǰ���������ִ��ӳ���������ģ�ͽ������ʧ��!

	// ���²���װ���壨�ӵ�ǰװ�����л�ȡ����װ���壬��δ�ҵ�����д�����
	UpdateCablingAsm();

	// ��ȡ������Ʋ���(�����벼��װ�����ȡ����)
	IKSMDCCableDesignParam stuOriCableDesignParam;
	GetCableDesignParamFromCurAsm(stuOriCableDesignParam);

	// ���µ�����Ʋ�������ǰװ����
	UpdateCableDesignParamToCurAsm();

	// ��֤��ǰװ�����Ƿ���Ҫ�ؽ�
	BOOL bForceRebuild = FALSE;
	BOOL bRebuild = IsCablingAsmNeedToRebuild(stuOriCableDesignParam, GetCableDesignParam());
	if (!(bRebuild || bForceRebuild))
		return;

	// ���µ�ǰװ�����ڵ�ģ������������������
	GetIKSSmartCableDataMethodMgr()->UpdateCurAsmMdlTreeHarnessCableData(TRUE);

	// ɾ������װ�����е������������ݺ͵�����������

	// ��ʼ������
	ProAssembly pConnParentAsm = GetCablingAsm(); // GetCablingAsm() // NULL
	ProAsmcomppath* pLocateCSysSolidCmpPath = GetCablingAsmCompPathPt(); // GetCablingAsmCompPathPt()	// NULL

	// �ֶ���ʼ������
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

	// �ڲ���װ�����д�������������λ����ϵ�����Ѵ�������ɾ�������´���������޸ģ�
	CreateConnLocCSysInCablingAsm();

	// ���صĵ�������ģ��ģ��
	LoadConnTemplateMdl();
	// ����������ģ�ͺ�����ϵ
	CUnicodeString strPrompt = L"";
	if (!CheckConnectorAssembly(NULL, NULL, pLocateCSysSolidCmpPath, &strPrompt))
	{
		AfxMessageBox(strPrompt.GetBuffer());
		CopyTextToClipboard(strPrompt);
		if (IDNO == AfxMessageBox(L"�޷���ȷ��װ���������,�Ƿ����?", MB_YESNO))
			return;
	}
	// �Զ�װ�䲢ָ����������
	CBPDynamicArray<UINT> arrFailedAsmConnIndex;
	AssemblyAndDesignateConnector(&arrFailedAsmConnIndex, pConnParentAsm, pLocateCSysSolidCmpPath);


// 	// �������Ӧ�ó���
// 	GetIKSSmartCableDataMethodMgr()->ActiveCableApp();

	// ��������ģ�͡�������������������
	CreateHarnessCableSplData();

	// ���ݵ�ǰProEģ�����ݸ��²�����Ŀ������Ϣ�е���������
	UpdateRoutCabProjHarnDataByCurAsmData();

	// ���ߵ���
	RoutingCable();
}

//===================================================================================================
