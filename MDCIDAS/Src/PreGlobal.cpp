//===================================================================================================
// Summary:
//		内部使用的Pro/E公共函数
// Date:
//		2016-03-17
// Author:
//		WangShiping
//===================================================================================================

#include "stdafx.h"
#include "PreGlobal.h"
#include "MDCIDAS.h"

//===================================================================================================

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//===================================================================================================

// 获得当前模型  
ProMdl GetCurrentMdl()
{
	ProMdl mdl = NULL;
	if (ProMdlCurrentGet(&mdl) == PRO_TK_NO_ERROR)
		return mdl;
	return NULL;
}

// 根据名称获得模型
ProMdl GetMdlByNameAndType(ProName mdlName, ProMdlType mdlType)
{
	ProMdl pMdl = NULL;
	ProMdlInit(mdlName, mdlType, &pMdl);
	if (NULL != pMdl)
		return pMdl;

	ProMdlRetrieve(mdlName, mdlType, &pMdl);
	if (NULL != pMdl)
		return pMdl;

	ProMdl *pMdlArray = NULL;
	int nCount = -1;
	ProSessionMdlList(mdlType, &pMdlArray, &nCount);
	CString strMdlName = CString(mdlName);
	ProName tmpName;
	for (int i=0; i<nCount; i++)
	{
		ProMdlNameGet(pMdlArray[i], tmpName);
		if (strMdlName.CompareNoCase(tmpName) == 0)
		{
			pMdl = pMdlArray[i];
			break;
		}
	}
	SAFE_DELETE_PROARRAY(pMdlArray);
	if (NULL != pMdl)
		return pMdl;

	return pMdl;
}

// 重载模型
ProMdl ReloadMdl(ProMdl pMdl)
{
	if (NULL == pMdl)
		return NULL;
	CString strPath;
	ProMdldata mdlData;
	ProMdlDataGet(pMdl, &mdlData);
	if (CString(mdlData.device).IsEmpty())
		strPath.Format(L"%s%s.%s.%d", mdlData.path, mdlData.name, mdlData.type, mdlData.version);
	else
		strPath.Format(L"%s:%s%s.%s.%d", mdlData.device, mdlData.path, mdlData.name, mdlData.type, mdlData.version);
	ProPath asmPath = {0};
	wcsncpy_s(asmPath, sizeof(ProPath)/sizeof(wchar_t), (LPCTSTR)strPath, _TRUNCATE);
	ProMdl pMdlNew = NULL;
	ProMdlLoad(asmPath, PRO_MDL_ASSEMBLY, PRO_B_TRUE, &pMdlNew);
	return pMdlNew;
}

// 获得当前零件模型  
ProPart GetCurrentPart()
{
	ProMdl pMdl = NULL;
	ProError status = ProMdlCurrentGet(&pMdl);
	if (status == PRO_TK_NO_ERROR)
	{
		ProMdlType mdlType; 
		ProMdlTypeGet(pMdl, &mdlType);
		if (mdlType == PRO_MDL_PART)
			return (ProPart)pMdl;
	}
	return NULL;
}

// 获得当前组件模型  
ProAssembly GetCurrentAssembly()
{
	ProMdl pMdl = NULL;
	ProError status = ProMdlCurrentGet(&pMdl);
	if (status == PRO_TK_NO_ERROR)
	{
		ProMdlType mdlType; 
		ProMdlTypeGet(pMdl, &mdlType);
		if (mdlType == PRO_MDL_ASSEMBLY)
			return (ProAssembly)pMdl;
	}
	return NULL;
}

// 选择单个对象
BOOL SelectOneObject(ProSelection &pSelObj, char *pSelOpt, ProSelFunctions *pSelFunc/* = NULL*/, ProSelectionEnv pSelEnv/* = NULL*/)
{
	pSelObj = NULL;
	ProSelection *pTempSelEntity = NULL;
	ProError status = PRO_TK_GENERAL_ERROR;
	BOOL bRet = FALSE;
	int nSelCount = 0;
	status = ProSelect(pSelOpt, 1, NULL, pSelFunc, pSelEnv, NULL, &pTempSelEntity, &nSelCount);
	if (status == PRO_TK_NO_ERROR && nSelCount > 0)
	{
		// 拷贝选择对象
		SAFE_DELETE_SELECTION(pSelObj);
		status = ProSelectionCopy(pTempSelEntity[0], &pSelObj);
		bRet = TRUE;
	}
	if (pSelObj != NULL)
		ProSelectionHighlight(pSelObj, PRO_COLOR_HIGHLITE);
	return bRet;
}


//===================================================================================================
