//===================================================================================================
// Summary:
//		模型相关函数类
// Date:
//		2016-08-19
// Author:
//		HuoPengcheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

//====================================================================================================

// 组件的子零件信息
typedef struct __tagPCLAsmComppathInfo
{
	ProIdTable idTab;	// ID表
	int nIndex;			// 当前索引
	ProSolid pTopAsm;	// 根部的组件

	__tagPCLAsmComppathInfo()
	{
		memset(idTab, -1, sizeof(ProIdTable)); 
		nIndex = -1; 
		pTopAsm = NULL; 
	}
	__tagPCLAsmComppathInfo(const __tagPCLAsmComppathInfo &aci)
	{
		for (int i=0; i<PRO_MAX_ASSEM_LEVEL; i++) 
			idTab[i] = aci.idTab[i];
		nIndex = aci.nIndex;
		pTopAsm = aci.pTopAsm;
	}
	__tagPCLAsmComppathInfo &operator=(const __tagPCLAsmComppathInfo &aci)
	{
		if (&aci != this)
		{
			for (int i=0; i<PRO_MAX_ASSEM_LEVEL; i++) 
				idTab[i] = aci.idTab[i];
			nIndex = aci.nIndex;
			pTopAsm = aci.pTopAsm;
		}
		return *this;
	}
}PCLAsmComppathInfo;

typedef CArray<PCLAsmComppathInfo, PCLAsmComppathInfo&> PCLAsmComppathArray;

// 提示零件所需的信息
typedef struct __tagPCLMdlVisitInfo
{
	PCLAsmComppathInfo partInfo;						// 零件信息
	void *pData;

	__tagPCLMdlVisitInfo()
	{
		pData = NULL;
	}

	__tagPCLMdlVisitInfo(const __tagPCLMdlVisitInfo &spi)
	{
		partInfo = spi.partInfo;
		pData = spi.pData;
	}
	__tagPCLMdlVisitInfo &operator=(const __tagPCLMdlVisitInfo &spi)
	{
		if (&spi != this)
		{
			partInfo = spi.partInfo;
			pData = spi.pData;
		}
		return *this;
	}
}PCLMdlVisitInfo;

//====================================================================================================
// 模型相关函数类
class CPCLMdl
{
public:
	CPCLMdl();
	virtual ~CPCLMdl();

public:
	// 获得当前模型
	static ProMdl GetCurrentMdl();
	// 获取当前模型类型
	static ProMdlType GetCurrentMdlType();
	// 获得当前组件模型
	static ProAssembly GetCurrentAssembly();
	// 获得当前零件模型
	static ProPart GetCurrentPart();
	// 获得当前工程图模型
	static ProDrawing GetCurrentDrawing();

public:

	// 获取类型的描述
	static CString GetTypeDesc(
		ProType eType									// 类型(in)
		);
	
	// 获取模型的描述
	static CString GetMdlDesc(
		ProName mdlName,								// 模型的名称(in)
		ProMdlType mdlType								// 模型的类型(in)
		);

	// 获取模型的描述
	static CString GetMdlDesc(
		ProMdl pMdl										// 模型(in)
		);

	// 获取基准的描述
	static CString GetDatumDesc(
		ProType eType									// 基准类型(in)
		);

public:

	// 根据装配体模型获取骨架模型
	static BOOL GetSkelMdlFromAsmMdl(
		ProAssembly pAsm,								// 装配体(in)
		vector<ProAsmcomp> &arrSkelComps				// 骨架模型元件特征(out)
		);
	
	// 获取模型的指定特征集
	static BOOL GetSolidFeature(
		ProSolid pSld,									// 模型(in)
		ProFeattype feaType,							// 特征类型(in)
		vector<ProFeature> &arrFeature					// 特征集(out)
		);

	// 获取选择模型下属特征的选择对象集
	static BOOL GetSolidFeatureSelection(
		ProSelection pSelSld,							// 选择模型(in)
		int nFeatureType,								// 特征类型(in)
		vector<ProSelection> &arrSelFeature				// 特征选择对象(out)
		);
	
public:

	// 获取路径的父路径
	static BOOL GetAsmcomppathFatherPath(
		ProAsmcomppath &comppath,						// 路径(in)
		ProAsmcomppath &fatherPath						// 父路径(out)
		);

	// 获取路径的父组件
	static BOOL GetAsmcomppathFatherAsm(
		ProAsmcomppath &comppath,						// 路径(in)
		ProMdl &pFatherAsm								// 父组件(out)
		);

	// 获取路径的祖组件
	static BOOL GetAsmcomppathGrandAsm(
		ProAsmcomppath &comppath,						// 路径(in)
		ProMdl &pGrandAsm								// 祖组件(out)
		);

	// 获取选择对象的父组件
	static BOOL GetSelectionFatherAsm(
		ProSelection pSel,								// 选择对象(in)
		ProMdl &pFatherAsm								// 父组件(out)
		);

	// 获取选择对象的祖组件
	static BOOL GetSelectionGrandAsm(
		ProSelection pSel,								// 选择对象(in)
		ProMdl &pGrandAsm								// 祖组件(out)
		);

private:
	// 获得骨架模型的动作函数
	static ProError GetSkelMdlArrayVisit(ProFeature* pFeature,ProError status,ProAppData pAppData);
	// 骨架模型的过滤函数
	static ProError GetSkelMdlArrayFilter(ProFeature* pFeature,ProAppData pAppData);
	// 模型特定特征遍历的动作函数
	static ProError GetSolidFeatureVisit(ProFeature* pFeature, ProError status, ProAppData pAppData);
	// 模型特定特征遍历的过滤函数
	static ProError GetSolidFeatureFilter(ProFeature* pFeature, ProAppData pAppData);
	// 遍历区域模型过滤函数
	static ProError GetFeatureSelectionFilterAction(ProFeature* pFeature, ProAppData pAppData);
	// 遍历区域模型动作函数
	static ProError GetFeatureSelectionVisitAction(ProFeature* pFeature, ProError status, ProAppData pAppData);
};

//===================================================================================================


