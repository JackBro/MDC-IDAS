//===================================================================================================
// File:
//		IKSSmartCableDataMethodMgrAPI.h
// Summary:
//		线缆数据方法的管理接口类
// Date:
//		2016-03-18
// Author:
//		WangShiping
//===================================================================================================

#pragma once
#include "CableBaseDef.h"

//===================================================================================================

class IIKSSmartCableDataMethodMgr
{
public:
	virtual BOOL Init() = 0;
	virtual void UnInit() = 0;

// 更新线束数据的相关方法
public:
	// 更新当前装配体内的模型树和线束电缆数据
	virtual BOOL UpdateCurAsmMdlTreeHarnessCableData(BOOL bForceUpdate=TRUE) = 0;
	// 更新线束的电缆数据信息
	virtual void UpdateHarnessCableInfo(CBPDynamicArray<IKSHarness> *pm_vecCurAsmHarnessInfo=NULL) = 0;
	// 通过线束名称获取线束索引
	virtual UINT GetHarnessIndexByName(const wchar_t* szHarnName) = 0;
	// 通过线束拾取数据获取线束索引
	virtual UINT GetHarnessIndexByProSelection(ProSelection pSelection) = 0;
	// 通过线束索引获取线束指针
	virtual const IKSHarness* GetHarnessPtByIndex(UINT uIndex) = 0;
	// 获取当前被激活的线束模型的索引(当前装配体的线束集合m_vecCurAsmHarnessInfo的索引)
	virtual UINT GetActiveHarnessIndex(ProMdl pActiveMdl = NULL) = 0;
	// 获取当前被激活的线束模型的Proe数据指针
	virtual ProMdl GetActiveHarnessProePt() = 0;

	// 获取线缆数据信息
	virtual BOOL GetCableInfoByProcable(const ProCable &stuProeCable, ProAssembly pAssembly, const ProAsmcomppath &stuHarnessAsmPath, IKSCable &stuIKSCable, const CSVWString *pName=NULL, const IKSCable *pConductorParentCable=NULL) = 0;
	// 获取线缆的段和位置信息
	virtual BOOL GetCableSegmentLocationInfo(IKSCable &stuIKSCable, SVBASEMATRIX *pTransMatrix=NULL, const IKSCable *pNetwork=NULL, const IKSHarness *pHarness=NULL) = 0;

// 映射键的相关方法
public:
	// 激活电缆应用程序
	virtual void ActiveCableApp() = 0;
	// 激活Harness
	virtual void ActiveHarness(const wchar_t *szHarnessName) = 0;
	// 生成网络路径的特征数据
	virtual BOOL CreateCableNetworkFeat(IKSHarness &stuHarness) = 0;
	// 检查并修复电缆的重叠位置
	virtual void CheckAndMendCableOverlapLocation() = 0;
	// 刷新电缆的显示
	virtual void RefreshCableDisplay() = 0;

// 线束的相关函数
public:
	// 获取线束Harn电缆网络段的位置坐标(世界坐标系)
	virtual BOOL GetHarnessNetworkSegmentPos(const CBPDynamicArray<IKSHarness> &vecHarness, CBPDynamicArray<CBPDynamicArray<SVBASEDOUBLE3> > &vecSegmentPos) = 0;
	// 获取线束的参考坐标系
	virtual BOOL GetHarnessRefCsys(const IKSHarness &stuHarness, ProModelitem &miCsys, SVCOORDSYSTEMD *pWldCsys=NULL) = 0;
	// 获取线束的电缆位置信息
	virtual BOOL GetHarnessLocationInfo(const IKSHarness &stuHarness, CBPDynamicArray<ProCablelocation> &vecLocation, CBPDynamicArray<SVBASEDOUBLE3> *pvecLocPos=NULL) = 0;
	// 验证零件是否为Harness线束类型
	virtual BOOL IsPartHarnessType(ProMdl pPart, ProAssembly pParentAsm) = 0;

// 线束的相关函数
public:
	// 计算线束的分支信息
	virtual BOOL CalcHarnessBranchInf(const wchar_t *szHarnessName, std::vector<IKSCableBranchPathCabEnd> &vecCabEnd, std::vector<ProCablelocation> &vecCrossLoc, std::vector<ProCablelocation> &vecOtherLoc, std::vector<IKSCableBranchPath> &vecBranchPath, std::vector<IKSCableBranchPathCabInf> &vecCabBranchInf, const IKSHarness **ppHarnessPt=NULL, ProAsmcomppath *pHarnAsmcomppath=NULL) = 0;

	// 重生线束
	virtual void RegenerateHarness(const CBPDynamicArray<IKSHarness> &vecCurAsmHarnessInfo, BOOL bPrompt=TRUE) = 0;

// 网络路径的相关函数
public:
	// 复制网络路径
	virtual BOOL CopyCableNetwork(const CBPDynamicArray<IKSHarness> &vecHarnessFrom, IKSHarness &stuHarnessTo) = 0;
	// 布线线束网络
	virtual BOOL RoutingHarnessNetwork(const CBPDynamicArray<CBPDynamicArray<SVBASEDOUBLE3> > &vecSegmentWldPos, IKSHarness &stuHarnessTo) = 0;

// 布线的相关函数
public:
	// 计算电缆布线信息
	virtual BOOL CalcCableRoutingInfo(IKSHarness &stuHarness, IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo, CBPDynamicArray<IKS_SMARTCABLING::IKSCableRoutingCabInf> &vecCableRoutingCabInf, CBPDynamicArray<UINT> &vecFailedCableIndex, BOOL bReRoutingAllHarnCables=FALSE) = 0;
	// 计算电缆布线信息
	virtual BOOL CalcCableRoutingInfo(IKSHarness &stuHarness, const CBPDynamicArray<UINT> &vecCableIndex, IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo, CBPDynamicArray<IKS_SMARTCABLING::IKSCableRoutingCabInf> &vecCableRoutingCabInf, CBPDynamicArray<UINT> &vecFailedCableIndex) = 0;
	// 计算电缆布线信息_获取线束Harness中需要布线的电缆
	virtual void CalcCableRoutingInfo_GetCableIndex(IKSHarness &stuHarness, const IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo, CBPDynamicArray<UINT> &vecCableIndex, BOOL bReRoutingAllHarnCables=FALSE) = 0;
	// 布线电缆生成电缆
	virtual BOOL CreateRoutingCable(IKSHarness &stuHarness, const CBPDynamicArray<IKS_SMARTCABLING::IKSCableRoutingCabInf> &vecCableRoutingCabInf, BOOL bUpdateHarnessCableInfo=TRUE) = 0;
	// 布线电缆_生成电缆
	virtual BOOL CreateRoutingCable(IKSHarness &stuHarness, const IKS_SMARTCABLING::IKSCableRoutingCabInf &stuCableRoutingCabInf, BOOL bUpdateHarnessCableInfo=TRUE) = 0;

	// 解绑当前装配内的电缆
	virtual BOOL UnwrapCurAsmCable(ProSelection pCable, ProSelection pCabLocStart, ProSelection pCabLocEnd, int *pErrType=NULL) = 0;
	// 解绑当前装配内的电缆
	virtual BOOL UnwrapCurAsmCable(ProSelection pCabLocStart, ProSelection pCabLocEnd, int *pErrType=NULL) = 0;

	// 布线电缆
	virtual BOOL RoutingCable(IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo) = 0;
	// 布线是否结束
	virtual BOOL IsCableRoutingFinished(const IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo) = 0;
	// 获取电缆布线的后续最佳路径(可达终点)
	virtual BOOL GetCableRoutingNextBestPath(const IKS_SMARTCABLING::IKSCableRoutingPathNode &stuCurNode, std::vector<const IKS_SMARTCABLING::IKSCableRoutingPathNode*> &vecNextBestPath) = 0;

	// 从逻辑参照中创建未生成的电缆至指定线束中
	virtual BOOL CreateCablesFromLogical(IKSHarness &stuHarness, ProAssembly pAssembly=NULL) = 0;
	// 根据电缆网络生成电缆无向图
	virtual BOOL CreateCabUndiGraphByNetwork(const IKSCable &stuNetwork, IKS_SMARTCABLING::CIKSCabUndiGraph &stuCabUndiGraph) = 0;
	// 根据线缆生成电缆已存在路径无向图
	virtual BOOL CreateExistPathUndiGraphByHarness(const IKSHarness &stuHarness, IKS_SMARTCABLING::CIKSCabUndiGraph &stuExistPathUndiGraph, BOOL bUpdateVertexAreaID=TRUE) = 0;
	// 根据电缆生成电缆已存在路径无向图
	virtual BOOL CreateExistPathUndiGraphByCable(const IKSCable &stuNetwork, const IKSCable &stuCable, IKS_SMARTCABLING::CIKSCabUndiGraph &stuExistPathUndiGraph, BOOL bUpdateVertexAreaID=TRUE) = 0;
	// 根据电缆布线信息生成电缆已存在路径无向图
	virtual BOOL CreateExistPathUndiGraphByRoutingCabInf(const IKSCable &stuNetwork, const IKS_SMARTCABLING::IKSCableRoutingCabInf &stuRoutingCabInf, IKS_SMARTCABLING::CIKSCabUndiGraph &stuExistPathUndiGraph, BOOL bUpdateVertexAreaID=TRUE) = 0;
	// 获取电缆布线起始终止电缆位置点索引
	virtual BOOL GetCableRoutingStartEndProCabLocIndex(IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo, const CBPIDIndexMgr* pStartExcluIndex=NULL, const CBPIDIndexMgr* pEndExcluIndex=NULL) = 0;
	// 获取电缆布线逻辑参照起点终点的信息
	virtual BOOL GetCableRoutingLogicalStartEndInfo(const IKSHarness &stuHarness, IKSCable &stuCable, IKS_SMARTCABLING::IKSCableRoutingCabInf &stuRoutingCabInf) = 0;
	// 获取电缆布线逻辑参照起点终点的信息
	virtual BOOL GetCableRoutingLogicalStartEndInfo(const IKSHarness &stuHarness, IKSCable &stuCable, SVBASEDOUBLE3 &vStartPos, SVBASEDOUBLE3 &vStartAxisZ, SVBASEDOUBLE3 &vEndPos, SVBASEDOUBLE3 &vEndAxisZ) = 0;

	// 获取电缆路径的节点索引(网络电缆位置索引)
	virtual BOOL GetCableRoutingPathIndexOfNetworkLoc(const IKS_SMARTCABLING::IKSCableRoutingCabInf &stuRoutingCabInf, CBPDynamicArray<UINT> &vecProCabLocIndex) = 0;
	// 获取电缆布线下一个起始路径节点
	virtual BOOL GetCableRoutingNextStartPathNode(IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo, CBPDynamicArray<IKS_SMARTCABLING::IKSCableRoutingPathNode> &vecNextCableRPathNode) = 0;


// 总线电缆连接关系表(定制开发)
public:
	// 通过Excel文件获取总线电缆连接关系
	virtual BOOL GetTrunkCableConnInfoByExcelFile(const wchar_t *szExcelFilePath, IKSTrunkCableConnectTab &stuCableConnTab, IKSTrunkCabConnectTabConfig *pConfig=NULL) = 0;
	// 通过总线电缆连接关系表获取电连接器的参数信息
	virtual BOOL GetConnectorParamInfoByIKSTrunkCableConnectTab(const IKSTrunkCableConnectTab &stuCableConnTab, const IKSTrunkCabConnectTabConfig &stuConfig, CBPDynamicArray<IKSConnectorParamInfo> &arrConnParam) = 0;

// 总线的相关函数
public:
	// 计算总线电缆布线信息
	virtual BOOL CalcTrunkCableRoutingInfo(const CBPDynamicArray<IKSTrunkCabSegmentInfo> &arrTrunkCabSegElem, const IKS_SMARTCABLING::IKSCableRoutingCheckInf &stuCheckInf, BOOL bFindAllPath, BOOL bUseOriSequence, CBPDynamicArray<IKS_SMARTCABLING::IKSTrunkCableRoutingInf> &arrTrunkCabRoutingInf, CBPDynamicArray<UINT> &vecFailedIndex) = 0;

	// 验证待布线总线主路段是否已经存在
	virtual BOOL CheckTrunkCableTrunkCabExist(const CBPDynamicArray<IKSTrunkCabSegmentInfo> &arrTrunkCabSegElem, CBPDynamicArray<UINT> &arrExistSegIndex, CBPDynamicArray<CBPDynamicArray<UINT> > &arrExistCableIndex, CBPDynamicArray<const IKSHarness*> &arrHarnessPt) = 0;
	// 验证待布线总线支路电缆是否已经存在(返回已存在电缆在线束模型中的索引和已存在电缆对应的总线电连接器索引(索引为0表示IKSTrunkCabSegmentInfo::stuConnStart,索引为IKSTrunkCabSegmentInfo::vecConnMid.size()+1表示IKSTrunkCabSegmentInfo::stuConnEnd,中间的索引表示中间电连接器))
	virtual BOOL CheckTrunkCableBranchCabExist(const CBPDynamicArray<IKSTrunkCabSegmentInfo> &arrTrunkCabSegElem, CBPDynamicArray<UINT> &arrExistSegIndex, CBPDynamicArray<CBPDynamicArray<UINT> > &arrExistCableIndex, CBPDynamicArray<CBPDynamicArray<UINT>> &arrExistEquCabConnIndex, CBPDynamicArray<const IKSHarness*> &arrHarnessPt) = 0;

// 总线的相关函数
public:
	// 生成总线主路电缆
	virtual BOOL CreateTrunkCableTrunkCab(const CBPDynamicArray<IKS_SMARTCABLING::IKSTrunkCableRoutingInf> &arrTrunkCabRoutingInf) = 0;
	// 布线生成总线支路电缆
	virtual BOOL CreateTrunkCableBranchCab(const CBPDynamicArray<IKSTrunkCabSegmentInfo> &arrTrunkCabSegElem, CBPDynamicArray<CSVWString> *parrFailedCable=NULL) = 0;

// 电连接器的相关函数
public:
	// 从配置文件中获取电连接器存储库路径
	virtual void GetConnLibPathFromConfigFile(std::vector<CString> &vecConnLibPath) = 0;
	// 获取线束相关的电连接器信息
	virtual BOOL GetConnectorOfHarness(const IKSHarness &stuHarness, CBPDynamicArray<IKSConnector> &arrConnectorInfo) = 0;
	// 获取电连接器的质量
	virtual double GetConnectorMass(const CBPDynamicArray<IKSConnector> &arrConnectorInfo) = 0;

	// 装配并指定电连接器
	virtual BOOL AssemblyAndDesignateConnector(CBPDynamicArray<ProConnector> &arrProConn, CBPDynamicArray<UINT> &arrFailedAsmConnIndex, const CBPDynamicArray<IKSConnectorParamInfo> &arrConnParam, ProAssembly pConnParentAsm=NULL, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL) = 0;
	// 检验电连接器能否装配
	virtual BOOL CheckConnectorAssembly(CBPDynamicArray<UINT> &arrLostCSysConnIndex, CBPDynamicArray<UINT> &arrFailedLoadMdlConnIndex, const CBPDynamicArray<IKSConnectorParamInfo> &arrConnParam, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL) = 0;

// 更新线轴的相关方法(定制开发)
public:
	// 通过Excel文件获取线轴数据
	virtual BOOL GetSpoolsDataByExcelFile(std::vector<IKSSpool> &vecSpools, const wchar_t *szExcelFilePath, std::vector<CSVWString> *parrInvalidWireConName=NULL) = 0;

	// 修改线缆内的线轴数据
	virtual BOOL ModifySpoolsDataOfHarness(const std::vector<IKSSpool> &vecSpools, CBPDynamicArray<IKSHarness> &vecCurAsmHarnessInfo, vector<CSVWString> *pvecUpdateFailedCableName=NULL) = 0;
	// 输出未更新成功的电线名称
	virtual BOOL OutputUpdateFailedCableName(const wchar_t *szFilePath, const vector<CSVWString> &vecUpdateFailedCableName) = 0;
	// 通过当前组件内的线缆信息获取线轴数据(线轴名称无重复)
	virtual BOOL GetSpoolsDataByCurAsmHarnInfo(std::vector<IKSSpool> &vecSpools, const CBPDynamicArray<IKSHarness> &vecCurAsmHarnessInfo) = 0;

// 电缆连接关系表(定制开发)
public:
	// 通过Excel文件获取电缆连接关系
	virtual BOOL GetCableConnInfoByExcelFile(const wchar_t *szExcelFilePath, IKSCableConnectTab &stuCableConnTab) = 0;

// 电缆连接关系综合表(定制开发)
public:
	// 通过Excel文件获取电缆连接关系综合表
	virtual BOOL GetCableConnectOverallTabByExcelFile(const wchar_t *szExcelFilePath, IKSCableConnectOverallTab &stuCabConOverallTab) = 0;
	// 通过Excel文件获取电缆连接关系综合表_加载选项信息
	virtual BOOL GetCableConnectOverallTabByExcelFile_LoadConfig(IKSCableConnectOverallTabConfig &stuConfig) = 0;

// 电缆连接关系正确性检查
public:
	// 检查电缆连接关系
	virtual BOOL CheckCableConnectInfo(const IKSCableConnectTab &stuCableConnTab, CBPDynamicArray<IKSCheckCableConnectInfResultElem> &arrCheckResult) = 0;

// 电缆连接关系中的电连接器的装配检查
public:
	// 根据电缆连接关系表获取电连接器
	virtual BOOL GetConnectorInfoByCabConnTab(const IKSCableConnectTab &stuCableConnTab, CBPDynamicArray<IKSCheckCableConInfConnector> &arrConnector) = 0;
	// 检查电连接器的装配情况
	virtual BOOL CheckConnectorAssemble(CBPDynamicArray<IKSCheckCableConInfConnector> &arrConnector) = 0;
	// 获取元件特征的参考坐标系对应选择类型
	virtual BOOL GetAsmcompRefCsysSel(ProAsmcomp &asmcomp, ProSelection &pSelRef) = 0;

// 电缆完整性检查
public:
	// 检查当前装配体内电缆完整性
	virtual BOOL CheckCurAsmCableComplete(CBPDynamicArray<IKSCheckCableCompleteResultElem> &arrCheckResult) = 0;
	// 检查电缆的完整性
	virtual BOOL CheckCableComplete(const IKSCable &stuCable) = 0;

// 电连接器的电缆转弯半径检查
public:
	// 获取当前装配体内电连接器的电缆综合直径
	virtual BOOL GetCurAsmConnectorWholeCableDiameter(CBPDynamicArray<IKSCheckConnWhlCabDiaResultElem> &arrCheckResult, double dDiameterCoef=1.0) = 0;

// 线束封闭环路检查
public:
	// 检查当前装配体内线束的封闭环路情况(返回存在封闭环路的线束信息;返回值FALSE表示存在封闭环路)
	virtual BOOL CheckCurAsmHarnessClosePath(CBPDynamicArray<IKSCheckHarnessClosePathResultElem> &arrCheckResult) = 0;
	// 检查线束的封闭环路情况(返回存在封闭环路的线束信息;返回值FALSE表示存在封闭环路)
	virtual BOOL CheckHarnessClosePath(const IKSHarness &stuHarness, IKSCheckHarnessClosePathResultElem &stuCheckResult) = 0;

// 电缆类型检查
public:
	// 根据电缆类型分组当前装配体内的电缆
	virtual BOOL GetCurAsmCabGroupByCableType(CBPDynamicArray<IKSCheckCableTypeCabGroup> &arrCabGroup) = 0;

	// 通过网络位置检查电缆类型(检查不同类型的电缆是否混杂在一起)
	virtual BOOL CheckCableTypeByNetworkLoc(const CBPDynamicArray<IKSCheckCableTypeCabGroup> &arrCabGroup, const CBPDynamicArray<CBPDynamicArray<CSVWString> > &arrCheckType, CBPDynamicArray<IKSCheckCableTypeResultElem> &arrCheckResult, double dZero=1.0e-3, BOOL bNoCheckInSameHarn=TRUE) = 0;
	// 通过网络位置检查电缆类型(检查不同类型的电缆是否混杂在一起)
	virtual BOOL CheckCableTypeByNetworkLoc(const IKSCheckCableTypeCabGroup &stuCabGroup1, const IKSCheckCableTypeCabGroup &stuCabGroup2, CBPDynamicArray<IKSCheckCableTypeResultElem> &arrCheckResult, double dZero=1.0e-3, BOOL bNoCheckInSameHarn=TRUE) = 0;

	// 通过距离和角度检查电缆类型(检查不同类型的电缆是否混杂在一起)
	virtual BOOL CheckCableTypeByDistAngle(const CBPDynamicArray<IKSCheckCableTypeCabGroup> &arrCabGroup, const CBPDynamicArray<CBPDynamicArray<CSVWString> > &arrCheckType, CBPDynamicArray<IKSCheckCableTypeResultElem> &arrCheckResult, double dSimilarPathDistMax=20.0, double dSimPathAngleMaxInDeg=10.0, BOOL bNoCheckInSameHarn=TRUE) = 0;
	// 通过距离和角度检查电缆类型(检查不同类型的电缆是否混杂在一起)
	virtual BOOL CheckCableTypeByDistAngle(const IKSCheckCableTypeCabGroup &stuCabGroup1, const IKSCheckCableTypeCabGroup &stuCabGroup2, CBPDynamicArray<IKSCheckCableTypeResultElem> &arrCheckResult, double dSimilarPathDistMax=20.0, double dSimPathAngleMaxInDeg=10.0, BOOL bNoCheckInSameHarn=TRUE) = 0;

// 孔容量检查的相关方法
public:
	// 通过拾取信息获取曲线数据
	virtual BOOL GetCurveDataBySelection(ProSelection pSel, IKSCABDCurve &curve) = 0;
	// 通过拾取的曲面信息获取拾取点及其法矢数据
	virtual BOOL GetPtNormBySelSurf(ProSelection pSel, SVBASEDOUBLE3 &vPt, SVBASEDOUBLE3 &vNorm) = 0;
	// 更新通过孔的线束数据
	virtual BOOL UpdateHarnessThroughHole(ChkHoleCapHoleHarnessInfo &stuChkHoleCapHoleHarnessInfo, const CBPDynamicArray<IKSHarness> &vecCurAsmHarnessInfo) = 0;
	// 检查孔容量
	virtual BOOL CheckHoleCapacity(const ChkHoleCapHoleHarnessInfo &stuChkHoleCapHoleHarnessInfo, const ChkHoleCapConfig &stuChkHoleCapConfig, ChkHoleCapResult &stuResult) = 0;

// 影响域分析
public:
	// 针对输入的参考网络进行线束的影响域分析
	virtual BOOL CheckInfluenceHarness(const IKSCable &stuRefNetwork, const CBPDynamicArray<IKSHarness> &vecHarnessInfo, CBPDynamicArray<IKSCheckInfluenceHarnessAnalysisResult> &arrCheckResult, double dZero=1.0e-3) = 0;

// 导出BOM表的相关函数(定制开发)
public:
	// 导出电缆配套表(装配体)
	virtual BOOL ExportHarnessBOMTableByAsm(const wchar_t *szExcelFilePath) = 0;
	// 导出电缆配套表(电缆)
	virtual BOOL ExportHarnessBOMTableByHarness(const wchar_t *szExcelFilePath) = 0;
	// 导出电连接器配套表
	virtual BOOL ExportConnectorBOMTable(const wchar_t *szExcelFilePath) = 0;
	// 导出电缆支座配套表
	virtual BOOL ExportCabFastenerBOMTable(const wchar_t *szExcelFilePath) = 0;

// 证书的相关函数
public:
	// 判断证书是否有效
	virtual BOOL GetCableValidLicense() const = 0;

public:
	virtual BOOL IsHarnDataUpdate() const  = 0;
	virtual void SetHarnDataUpdate(BOOL bIsHarnDataUpdate) = 0;

	virtual const CABModelNodeData& GetHarnessTreeTopNode() const = 0;
	virtual const CABModelNodeData* GetHarnessTreeTopNodePt() const = 0;
	virtual const CBPDynamicArray<IKSHarness>& GetCurAsmHarnessInfo() const = 0;
	virtual CBPDynamicArray<IKSHarness>* GetCurAsmHarnessInfoPt() = 0;
	virtual const CBPDynamicArray<IKSConnector>& GetCurAsmConnectorInfo() const = 0;
	virtual CBPDynamicArray<IKSConnector>* GetCurAsmConnectorInfoPt() = 0;
};

//===================================================================================================
// 创建线缆数据方法的管理器
IIKSSmartCableDataMethodMgr* CreateIKSSmartCableDataMethodMgr();
// 销毁线缆数据方法的管理器
void DestroyIKSSmartCableDataMethodMgr();
// 获取线缆数据方法的管理器
IIKSSmartCableDataMethodMgr* GetIKSSmartCableDataMethodMgr();

//===================================================================================================
