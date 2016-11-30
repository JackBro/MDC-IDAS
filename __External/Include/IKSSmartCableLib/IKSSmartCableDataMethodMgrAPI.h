//===================================================================================================
// File:
//		IKSSmartCableDataMethodMgrAPI.h
// Summary:
//		�������ݷ����Ĺ���ӿ���
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

// �����������ݵ���ط���
public:
	// ���µ�ǰװ�����ڵ�ģ������������������
	virtual BOOL UpdateCurAsmMdlTreeHarnessCableData(BOOL bForceUpdate=TRUE) = 0;
	// ���������ĵ���������Ϣ
	virtual void UpdateHarnessCableInfo(CBPDynamicArray<IKSHarness> *pm_vecCurAsmHarnessInfo=NULL) = 0;
	// ͨ���������ƻ�ȡ��������
	virtual UINT GetHarnessIndexByName(const wchar_t* szHarnName) = 0;
	// ͨ������ʰȡ���ݻ�ȡ��������
	virtual UINT GetHarnessIndexByProSelection(ProSelection pSelection) = 0;
	// ͨ������������ȡ����ָ��
	virtual const IKSHarness* GetHarnessPtByIndex(UINT uIndex) = 0;
	// ��ȡ��ǰ�����������ģ�͵�����(��ǰװ�������������m_vecCurAsmHarnessInfo������)
	virtual UINT GetActiveHarnessIndex(ProMdl pActiveMdl = NULL) = 0;
	// ��ȡ��ǰ�����������ģ�͵�Proe����ָ��
	virtual ProMdl GetActiveHarnessProePt() = 0;

	// ��ȡ����������Ϣ
	virtual BOOL GetCableInfoByProcable(const ProCable &stuProeCable, ProAssembly pAssembly, const ProAsmcomppath &stuHarnessAsmPath, IKSCable &stuIKSCable, const CSVWString *pName=NULL, const IKSCable *pConductorParentCable=NULL) = 0;
	// ��ȡ���µĶκ�λ����Ϣ
	virtual BOOL GetCableSegmentLocationInfo(IKSCable &stuIKSCable, SVBASEMATRIX *pTransMatrix=NULL, const IKSCable *pNetwork=NULL, const IKSHarness *pHarness=NULL) = 0;

// ӳ�������ط���
public:
	// �������Ӧ�ó���
	virtual void ActiveCableApp() = 0;
	// ����Harness
	virtual void ActiveHarness(const wchar_t *szHarnessName) = 0;
	// ��������·������������
	virtual BOOL CreateCableNetworkFeat(IKSHarness &stuHarness) = 0;
	// ��鲢�޸����µ��ص�λ��
	virtual void CheckAndMendCableOverlapLocation() = 0;
	// ˢ�µ��µ���ʾ
	virtual void RefreshCableDisplay() = 0;

// ��������غ���
public:
	// ��ȡ����Harn��������ε�λ������(��������ϵ)
	virtual BOOL GetHarnessNetworkSegmentPos(const CBPDynamicArray<IKSHarness> &vecHarness, CBPDynamicArray<CBPDynamicArray<SVBASEDOUBLE3> > &vecSegmentPos) = 0;
	// ��ȡ�����Ĳο�����ϵ
	virtual BOOL GetHarnessRefCsys(const IKSHarness &stuHarness, ProModelitem &miCsys, SVCOORDSYSTEMD *pWldCsys=NULL) = 0;
	// ��ȡ�����ĵ���λ����Ϣ
	virtual BOOL GetHarnessLocationInfo(const IKSHarness &stuHarness, CBPDynamicArray<ProCablelocation> &vecLocation, CBPDynamicArray<SVBASEDOUBLE3> *pvecLocPos=NULL) = 0;
	// ��֤����Ƿ�ΪHarness��������
	virtual BOOL IsPartHarnessType(ProMdl pPart, ProAssembly pParentAsm) = 0;

// ��������غ���
public:
	// ���������ķ�֧��Ϣ
	virtual BOOL CalcHarnessBranchInf(const wchar_t *szHarnessName, std::vector<IKSCableBranchPathCabEnd> &vecCabEnd, std::vector<ProCablelocation> &vecCrossLoc, std::vector<ProCablelocation> &vecOtherLoc, std::vector<IKSCableBranchPath> &vecBranchPath, std::vector<IKSCableBranchPathCabInf> &vecCabBranchInf, const IKSHarness **ppHarnessPt=NULL, ProAsmcomppath *pHarnAsmcomppath=NULL) = 0;

	// ��������
	virtual void RegenerateHarness(const CBPDynamicArray<IKSHarness> &vecCurAsmHarnessInfo, BOOL bPrompt=TRUE) = 0;

// ����·������غ���
public:
	// ��������·��
	virtual BOOL CopyCableNetwork(const CBPDynamicArray<IKSHarness> &vecHarnessFrom, IKSHarness &stuHarnessTo) = 0;
	// ������������
	virtual BOOL RoutingHarnessNetwork(const CBPDynamicArray<CBPDynamicArray<SVBASEDOUBLE3> > &vecSegmentWldPos, IKSHarness &stuHarnessTo) = 0;

// ���ߵ���غ���
public:
	// ������²�����Ϣ
	virtual BOOL CalcCableRoutingInfo(IKSHarness &stuHarness, IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo, CBPDynamicArray<IKS_SMARTCABLING::IKSCableRoutingCabInf> &vecCableRoutingCabInf, CBPDynamicArray<UINT> &vecFailedCableIndex, BOOL bReRoutingAllHarnCables=FALSE) = 0;
	// ������²�����Ϣ
	virtual BOOL CalcCableRoutingInfo(IKSHarness &stuHarness, const CBPDynamicArray<UINT> &vecCableIndex, IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo, CBPDynamicArray<IKS_SMARTCABLING::IKSCableRoutingCabInf> &vecCableRoutingCabInf, CBPDynamicArray<UINT> &vecFailedCableIndex) = 0;
	// ������²�����Ϣ_��ȡ����Harness����Ҫ���ߵĵ���
	virtual void CalcCableRoutingInfo_GetCableIndex(IKSHarness &stuHarness, const IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo, CBPDynamicArray<UINT> &vecCableIndex, BOOL bReRoutingAllHarnCables=FALSE) = 0;
	// ���ߵ������ɵ���
	virtual BOOL CreateRoutingCable(IKSHarness &stuHarness, const CBPDynamicArray<IKS_SMARTCABLING::IKSCableRoutingCabInf> &vecCableRoutingCabInf, BOOL bUpdateHarnessCableInfo=TRUE) = 0;
	// ���ߵ���_���ɵ���
	virtual BOOL CreateRoutingCable(IKSHarness &stuHarness, const IKS_SMARTCABLING::IKSCableRoutingCabInf &stuCableRoutingCabInf, BOOL bUpdateHarnessCableInfo=TRUE) = 0;

	// ���ǰװ���ڵĵ���
	virtual BOOL UnwrapCurAsmCable(ProSelection pCable, ProSelection pCabLocStart, ProSelection pCabLocEnd, int *pErrType=NULL) = 0;
	// ���ǰװ���ڵĵ���
	virtual BOOL UnwrapCurAsmCable(ProSelection pCabLocStart, ProSelection pCabLocEnd, int *pErrType=NULL) = 0;

	// ���ߵ���
	virtual BOOL RoutingCable(IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo) = 0;
	// �����Ƿ����
	virtual BOOL IsCableRoutingFinished(const IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo) = 0;
	// ��ȡ���²��ߵĺ������·��(�ɴ��յ�)
	virtual BOOL GetCableRoutingNextBestPath(const IKS_SMARTCABLING::IKSCableRoutingPathNode &stuCurNode, std::vector<const IKS_SMARTCABLING::IKSCableRoutingPathNode*> &vecNextBestPath) = 0;

	// ���߼������д���δ���ɵĵ�����ָ��������
	virtual BOOL CreateCablesFromLogical(IKSHarness &stuHarness, ProAssembly pAssembly=NULL) = 0;
	// ���ݵ����������ɵ�������ͼ
	virtual BOOL CreateCabUndiGraphByNetwork(const IKSCable &stuNetwork, IKS_SMARTCABLING::CIKSCabUndiGraph &stuCabUndiGraph) = 0;
	// �����������ɵ����Ѵ���·������ͼ
	virtual BOOL CreateExistPathUndiGraphByHarness(const IKSHarness &stuHarness, IKS_SMARTCABLING::CIKSCabUndiGraph &stuExistPathUndiGraph, BOOL bUpdateVertexAreaID=TRUE) = 0;
	// ���ݵ������ɵ����Ѵ���·������ͼ
	virtual BOOL CreateExistPathUndiGraphByCable(const IKSCable &stuNetwork, const IKSCable &stuCable, IKS_SMARTCABLING::CIKSCabUndiGraph &stuExistPathUndiGraph, BOOL bUpdateVertexAreaID=TRUE) = 0;
	// ���ݵ��²�����Ϣ���ɵ����Ѵ���·������ͼ
	virtual BOOL CreateExistPathUndiGraphByRoutingCabInf(const IKSCable &stuNetwork, const IKS_SMARTCABLING::IKSCableRoutingCabInf &stuRoutingCabInf, IKS_SMARTCABLING::CIKSCabUndiGraph &stuExistPathUndiGraph, BOOL bUpdateVertexAreaID=TRUE) = 0;
	// ��ȡ���²�����ʼ��ֹ����λ�õ�����
	virtual BOOL GetCableRoutingStartEndProCabLocIndex(IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo, const CBPIDIndexMgr* pStartExcluIndex=NULL, const CBPIDIndexMgr* pEndExcluIndex=NULL) = 0;
	// ��ȡ���²����߼���������յ����Ϣ
	virtual BOOL GetCableRoutingLogicalStartEndInfo(const IKSHarness &stuHarness, IKSCable &stuCable, IKS_SMARTCABLING::IKSCableRoutingCabInf &stuRoutingCabInf) = 0;
	// ��ȡ���²����߼���������յ����Ϣ
	virtual BOOL GetCableRoutingLogicalStartEndInfo(const IKSHarness &stuHarness, IKSCable &stuCable, SVBASEDOUBLE3 &vStartPos, SVBASEDOUBLE3 &vStartAxisZ, SVBASEDOUBLE3 &vEndPos, SVBASEDOUBLE3 &vEndAxisZ) = 0;

	// ��ȡ����·���Ľڵ�����(�������λ������)
	virtual BOOL GetCableRoutingPathIndexOfNetworkLoc(const IKS_SMARTCABLING::IKSCableRoutingCabInf &stuRoutingCabInf, CBPDynamicArray<UINT> &vecProCabLocIndex) = 0;
	// ��ȡ���²�����һ����ʼ·���ڵ�
	virtual BOOL GetCableRoutingNextStartPathNode(IKS_SMARTCABLING::IKSCableRoutingInf &stuCabRoutInfo, CBPDynamicArray<IKS_SMARTCABLING::IKSCableRoutingPathNode> &vecNextCableRPathNode) = 0;


// ���ߵ������ӹ�ϵ��(���ƿ���)
public:
	// ͨ��Excel�ļ���ȡ���ߵ������ӹ�ϵ
	virtual BOOL GetTrunkCableConnInfoByExcelFile(const wchar_t *szExcelFilePath, IKSTrunkCableConnectTab &stuCableConnTab, IKSTrunkCabConnectTabConfig *pConfig=NULL) = 0;
	// ͨ�����ߵ������ӹ�ϵ���ȡ���������Ĳ�����Ϣ
	virtual BOOL GetConnectorParamInfoByIKSTrunkCableConnectTab(const IKSTrunkCableConnectTab &stuCableConnTab, const IKSTrunkCabConnectTabConfig &stuConfig, CBPDynamicArray<IKSConnectorParamInfo> &arrConnParam) = 0;

// ���ߵ���غ���
public:
	// �������ߵ��²�����Ϣ
	virtual BOOL CalcTrunkCableRoutingInfo(const CBPDynamicArray<IKSTrunkCabSegmentInfo> &arrTrunkCabSegElem, const IKS_SMARTCABLING::IKSCableRoutingCheckInf &stuCheckInf, BOOL bFindAllPath, BOOL bUseOriSequence, CBPDynamicArray<IKS_SMARTCABLING::IKSTrunkCableRoutingInf> &arrTrunkCabRoutingInf, CBPDynamicArray<UINT> &vecFailedIndex) = 0;

	// ��֤������������·���Ƿ��Ѿ�����
	virtual BOOL CheckTrunkCableTrunkCabExist(const CBPDynamicArray<IKSTrunkCabSegmentInfo> &arrTrunkCabSegElem, CBPDynamicArray<UINT> &arrExistSegIndex, CBPDynamicArray<CBPDynamicArray<UINT> > &arrExistCableIndex, CBPDynamicArray<const IKSHarness*> &arrHarnessPt) = 0;
	// ��֤����������֧·�����Ƿ��Ѿ�����(�����Ѵ��ڵ���������ģ���е��������Ѵ��ڵ��¶�Ӧ�����ߵ�����������(����Ϊ0��ʾIKSTrunkCabSegmentInfo::stuConnStart,����ΪIKSTrunkCabSegmentInfo::vecConnMid.size()+1��ʾIKSTrunkCabSegmentInfo::stuConnEnd,�м��������ʾ�м��������))
	virtual BOOL CheckTrunkCableBranchCabExist(const CBPDynamicArray<IKSTrunkCabSegmentInfo> &arrTrunkCabSegElem, CBPDynamicArray<UINT> &arrExistSegIndex, CBPDynamicArray<CBPDynamicArray<UINT> > &arrExistCableIndex, CBPDynamicArray<CBPDynamicArray<UINT>> &arrExistEquCabConnIndex, CBPDynamicArray<const IKSHarness*> &arrHarnessPt) = 0;

// ���ߵ���غ���
public:
	// ����������·����
	virtual BOOL CreateTrunkCableTrunkCab(const CBPDynamicArray<IKS_SMARTCABLING::IKSTrunkCableRoutingInf> &arrTrunkCabRoutingInf) = 0;
	// ������������֧·����
	virtual BOOL CreateTrunkCableBranchCab(const CBPDynamicArray<IKSTrunkCabSegmentInfo> &arrTrunkCabSegElem, CBPDynamicArray<CSVWString> *parrFailedCable=NULL) = 0;

// ������������غ���
public:
	// �������ļ��л�ȡ���������洢��·��
	virtual void GetConnLibPathFromConfigFile(std::vector<CString> &vecConnLibPath) = 0;
	// ��ȡ������صĵ���������Ϣ
	virtual BOOL GetConnectorOfHarness(const IKSHarness &stuHarness, CBPDynamicArray<IKSConnector> &arrConnectorInfo) = 0;
	// ��ȡ��������������
	virtual double GetConnectorMass(const CBPDynamicArray<IKSConnector> &arrConnectorInfo) = 0;

	// װ�䲢ָ����������
	virtual BOOL AssemblyAndDesignateConnector(CBPDynamicArray<ProConnector> &arrProConn, CBPDynamicArray<UINT> &arrFailedAsmConnIndex, const CBPDynamicArray<IKSConnectorParamInfo> &arrConnParam, ProAssembly pConnParentAsm=NULL, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL) = 0;
	// ������������ܷ�װ��
	virtual BOOL CheckConnectorAssembly(CBPDynamicArray<UINT> &arrLostCSysConnIndex, CBPDynamicArray<UINT> &arrFailedLoadMdlConnIndex, const CBPDynamicArray<IKSConnectorParamInfo> &arrConnParam, ProAsmcomppath* pLocateCSysSolidCmpPath=NULL) = 0;

// �����������ط���(���ƿ���)
public:
	// ͨ��Excel�ļ���ȡ��������
	virtual BOOL GetSpoolsDataByExcelFile(std::vector<IKSSpool> &vecSpools, const wchar_t *szExcelFilePath, std::vector<CSVWString> *parrInvalidWireConName=NULL) = 0;

	// �޸������ڵ���������
	virtual BOOL ModifySpoolsDataOfHarness(const std::vector<IKSSpool> &vecSpools, CBPDynamicArray<IKSHarness> &vecCurAsmHarnessInfo, vector<CSVWString> *pvecUpdateFailedCableName=NULL) = 0;
	// ���δ���³ɹ��ĵ�������
	virtual BOOL OutputUpdateFailedCableName(const wchar_t *szFilePath, const vector<CSVWString> &vecUpdateFailedCableName) = 0;
	// ͨ����ǰ����ڵ�������Ϣ��ȡ��������(�����������ظ�)
	virtual BOOL GetSpoolsDataByCurAsmHarnInfo(std::vector<IKSSpool> &vecSpools, const CBPDynamicArray<IKSHarness> &vecCurAsmHarnessInfo) = 0;

// �������ӹ�ϵ��(���ƿ���)
public:
	// ͨ��Excel�ļ���ȡ�������ӹ�ϵ
	virtual BOOL GetCableConnInfoByExcelFile(const wchar_t *szExcelFilePath, IKSCableConnectTab &stuCableConnTab) = 0;

// �������ӹ�ϵ�ۺϱ�(���ƿ���)
public:
	// ͨ��Excel�ļ���ȡ�������ӹ�ϵ�ۺϱ�
	virtual BOOL GetCableConnectOverallTabByExcelFile(const wchar_t *szExcelFilePath, IKSCableConnectOverallTab &stuCabConOverallTab) = 0;
	// ͨ��Excel�ļ���ȡ�������ӹ�ϵ�ۺϱ�_����ѡ����Ϣ
	virtual BOOL GetCableConnectOverallTabByExcelFile_LoadConfig(IKSCableConnectOverallTabConfig &stuConfig) = 0;

// �������ӹ�ϵ��ȷ�Լ��
public:
	// ���������ӹ�ϵ
	virtual BOOL CheckCableConnectInfo(const IKSCableConnectTab &stuCableConnTab, CBPDynamicArray<IKSCheckCableConnectInfResultElem> &arrCheckResult) = 0;

// �������ӹ�ϵ�еĵ���������װ����
public:
	// ���ݵ������ӹ�ϵ���ȡ��������
	virtual BOOL GetConnectorInfoByCabConnTab(const IKSCableConnectTab &stuCableConnTab, CBPDynamicArray<IKSCheckCableConInfConnector> &arrConnector) = 0;
	// ������������װ�����
	virtual BOOL CheckConnectorAssemble(CBPDynamicArray<IKSCheckCableConInfConnector> &arrConnector) = 0;
	// ��ȡԪ�������Ĳο�����ϵ��Ӧѡ������
	virtual BOOL GetAsmcompRefCsysSel(ProAsmcomp &asmcomp, ProSelection &pSelRef) = 0;

// ���������Լ��
public:
	// ��鵱ǰװ�����ڵ���������
	virtual BOOL CheckCurAsmCableComplete(CBPDynamicArray<IKSCheckCableCompleteResultElem> &arrCheckResult) = 0;
	// �����µ�������
	virtual BOOL CheckCableComplete(const IKSCable &stuCable) = 0;

// ���������ĵ���ת��뾶���
public:
	// ��ȡ��ǰװ�����ڵ��������ĵ����ۺ�ֱ��
	virtual BOOL GetCurAsmConnectorWholeCableDiameter(CBPDynamicArray<IKSCheckConnWhlCabDiaResultElem> &arrCheckResult, double dDiameterCoef=1.0) = 0;

// ������ջ�·���
public:
	// ��鵱ǰװ�����������ķ�ջ�·���(���ش��ڷ�ջ�·��������Ϣ;����ֵFALSE��ʾ���ڷ�ջ�·)
	virtual BOOL CheckCurAsmHarnessClosePath(CBPDynamicArray<IKSCheckHarnessClosePathResultElem> &arrCheckResult) = 0;
	// ��������ķ�ջ�·���(���ش��ڷ�ջ�·��������Ϣ;����ֵFALSE��ʾ���ڷ�ջ�·)
	virtual BOOL CheckHarnessClosePath(const IKSHarness &stuHarness, IKSCheckHarnessClosePathResultElem &stuCheckResult) = 0;

// �������ͼ��
public:
	// ���ݵ������ͷ��鵱ǰװ�����ڵĵ���
	virtual BOOL GetCurAsmCabGroupByCableType(CBPDynamicArray<IKSCheckCableTypeCabGroup> &arrCabGroup) = 0;

	// ͨ������λ�ü���������(��鲻ͬ���͵ĵ����Ƿ������һ��)
	virtual BOOL CheckCableTypeByNetworkLoc(const CBPDynamicArray<IKSCheckCableTypeCabGroup> &arrCabGroup, const CBPDynamicArray<CBPDynamicArray<CSVWString> > &arrCheckType, CBPDynamicArray<IKSCheckCableTypeResultElem> &arrCheckResult, double dZero=1.0e-3, BOOL bNoCheckInSameHarn=TRUE) = 0;
	// ͨ������λ�ü���������(��鲻ͬ���͵ĵ����Ƿ������һ��)
	virtual BOOL CheckCableTypeByNetworkLoc(const IKSCheckCableTypeCabGroup &stuCabGroup1, const IKSCheckCableTypeCabGroup &stuCabGroup2, CBPDynamicArray<IKSCheckCableTypeResultElem> &arrCheckResult, double dZero=1.0e-3, BOOL bNoCheckInSameHarn=TRUE) = 0;

	// ͨ������ͽǶȼ���������(��鲻ͬ���͵ĵ����Ƿ������һ��)
	virtual BOOL CheckCableTypeByDistAngle(const CBPDynamicArray<IKSCheckCableTypeCabGroup> &arrCabGroup, const CBPDynamicArray<CBPDynamicArray<CSVWString> > &arrCheckType, CBPDynamicArray<IKSCheckCableTypeResultElem> &arrCheckResult, double dSimilarPathDistMax=20.0, double dSimPathAngleMaxInDeg=10.0, BOOL bNoCheckInSameHarn=TRUE) = 0;
	// ͨ������ͽǶȼ���������(��鲻ͬ���͵ĵ����Ƿ������һ��)
	virtual BOOL CheckCableTypeByDistAngle(const IKSCheckCableTypeCabGroup &stuCabGroup1, const IKSCheckCableTypeCabGroup &stuCabGroup2, CBPDynamicArray<IKSCheckCableTypeResultElem> &arrCheckResult, double dSimilarPathDistMax=20.0, double dSimPathAngleMaxInDeg=10.0, BOOL bNoCheckInSameHarn=TRUE) = 0;

// ������������ط���
public:
	// ͨ��ʰȡ��Ϣ��ȡ��������
	virtual BOOL GetCurveDataBySelection(ProSelection pSel, IKSCABDCurve &curve) = 0;
	// ͨ��ʰȡ��������Ϣ��ȡʰȡ�㼰�䷨ʸ����
	virtual BOOL GetPtNormBySelSurf(ProSelection pSel, SVBASEDOUBLE3 &vPt, SVBASEDOUBLE3 &vNorm) = 0;
	// ����ͨ���׵���������
	virtual BOOL UpdateHarnessThroughHole(ChkHoleCapHoleHarnessInfo &stuChkHoleCapHoleHarnessInfo, const CBPDynamicArray<IKSHarness> &vecCurAsmHarnessInfo) = 0;
	// ��������
	virtual BOOL CheckHoleCapacity(const ChkHoleCapHoleHarnessInfo &stuChkHoleCapHoleHarnessInfo, const ChkHoleCapConfig &stuChkHoleCapConfig, ChkHoleCapResult &stuResult) = 0;

// Ӱ�������
public:
	// �������Ĳο��������������Ӱ�������
	virtual BOOL CheckInfluenceHarness(const IKSCable &stuRefNetwork, const CBPDynamicArray<IKSHarness> &vecHarnessInfo, CBPDynamicArray<IKSCheckInfluenceHarnessAnalysisResult> &arrCheckResult, double dZero=1.0e-3) = 0;

// ����BOM�����غ���(���ƿ���)
public:
	// �����������ױ�(װ����)
	virtual BOOL ExportHarnessBOMTableByAsm(const wchar_t *szExcelFilePath) = 0;
	// �����������ױ�(����)
	virtual BOOL ExportHarnessBOMTableByHarness(const wchar_t *szExcelFilePath) = 0;
	// ���������������ױ�
	virtual BOOL ExportConnectorBOMTable(const wchar_t *szExcelFilePath) = 0;
	// ��������֧�����ױ�
	virtual BOOL ExportCabFastenerBOMTable(const wchar_t *szExcelFilePath) = 0;

// ֤�����غ���
public:
	// �ж�֤���Ƿ���Ч
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
// �����������ݷ����Ĺ�����
IIKSSmartCableDataMethodMgr* CreateIKSSmartCableDataMethodMgr();
// �����������ݷ����Ĺ�����
void DestroyIKSSmartCableDataMethodMgr();
// ��ȡ�������ݷ����Ĺ�����
IIKSSmartCableDataMethodMgr* GetIKSSmartCableDataMethodMgr();

//===================================================================================================
