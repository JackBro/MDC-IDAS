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

// ���²��ֲ���(�ӵ�ǰװ�����ȡ����)
void CIKSMDCCableDataMethodMgr::UpdateLayoutParamFromCurAsm()
{

}

// ���µ��²��ֲ���(�ӵ�ǰװ�����ȡ����)
void CIKSMDCCableDataMethodMgr::UpdateCableLayoutParamFromCurAsm()
{
	m_RoutCabProjDataInf.m_CableLayoutParam;
}

// ���µ��²��ֲ�������ǰװ����
void CIKSMDCCableDataMethodMgr::UpdateCableLayoutParamToCurAsm() const
{
	m_RoutCabProjDataInf.m_CableLayoutParam;
}

// ���µ�����Ʋ���(�ӵ�ǰװ�����ȡ����)
void CIKSMDCCableDataMethodMgr::UpdateCableDesignParamFromCurAsm()
{
	m_RoutCabProjDataInf.m_CableDesignParam;
}

// ���µ�����Ʋ�������ǰװ����
void CIKSMDCCableDataMethodMgr::UpdateCableDesignParamToCurAsm() const
{
	m_RoutCabProjDataInf.m_CableDesignParam;
}

// ���ݲ��ֲ�������������Ʋ���
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

// ���²���װ���壨�ӵ�ǰװ�����л�ȡ����װ���壬��δ�ҵ�����д�����
BOOL CIKSMDCCableDataMethodMgr::UpdateCablingAsm()
{
	m_pCablingAsm = GetCablingAsmInCurAsm(&m_stuCablingAsmCompPath);
	if (m_pCablingAsm == NULL)
		m_pCablingAsm = CreateCablingAsmInCurAsm(&m_stuCablingAsmCompPath);

	return (m_pCablingAsm != NULL);
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

// ����
void CIKSMDCCableDataMethodMgr::Test()
{
	// �����׼Ӧ�ó���

	// ���²���װ���壨�ӵ�ǰװ�����л�ȡ����װ���壬��δ�ҵ�����д�����
	UpdateCablingAsm();

	// ���µ�ǰװ�����ڵ�ģ������������������
	GetIKSSmartCableDataMethodMgr()->UpdateCurAsmMdlTreeHarnessCableData(TRUE);

	m_RoutCabProjDataInf.m_vecConnector.resize(2);
	for (UINT i=0; i<m_RoutCabProjDataInf.m_vecConnector.size(); i++)
		InitConnectorParam(m_RoutCabProjDataInf.m_vecConnector[i].stuConnParam);
	m_RoutCabProjDataInf.m_vecConnector[0].stuConnParam.strRefDes = L"C-01";
	m_RoutCabProjDataInf.m_vecConnector[1].stuConnParam.strRefDes = L"C-02";

	LoadConnTemplateMdl();
	ProAssembly pConnParentAsm = NULL; // GetCablingAsm()
	ProAsmcomppath* pLocateCSysSolidCmpPath = NULL; // GetCablingAsmCompPathPt()
	// ����������ģ�ͺ�����ϵ
	CUnicodeString strPrompt = L"";
	CBPDynamicArray<UINT> arrLostCSysConnIndex;
	CBPDynamicArray<UINT> arrFailedLoadMdlConnIndex;
	CheckConnectorAssembly(GetRoutCabProjDataInfPt()->m_vecConnector, arrLostCSysConnIndex, arrFailedLoadMdlConnIndex, pLocateCSysSolidCmpPath, &strPrompt);
	if (!strPrompt.IsEmpty())
	{
		AfxMessageBox(strPrompt.GetBuffer());
		CopyTextToClipboard(strPrompt);
	}
	// �Զ�װ�䲢ָ����������
	CBPDynamicArray<UINT> arrFailedAsmConnIndex;
	AssemblyAndDesignateConnector(&arrFailedAsmConnIndex, pConnParentAsm, pLocateCSysSolidCmpPath);


	// ע�⣺����Ӧ�ó��򱻼���ʱ���޷��ɹ����ز�װ��ģ��
	// �������Ӧ�ó���
	GetIKSSmartCableDataMethodMgr()->ActiveCableApp();

	// ��������ģ�͡�������������������

	// ���ߵ���

}

//===================================================================================================
