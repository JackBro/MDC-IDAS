//===================================================================================================
// Summary:
//		电缆基础数据定义
// Date:
//		2016-11-13
// Author:
//		
//===================================================================================================

#pragma once
#include "CableConstantValue.h"
#include "SVGlobalTools.h"

//===================================================================================================
namespace IKS_SMARTCABLING
{

// 电缆无向图顶点
typedef struct __tagIKSCabUndiGraphVertex
{
	UINT uID;									// 顶点ID
	CBPDynamicArray<UINT> vecAdjVertexID;		// 相邻顶点的ID
	SVBASEDOUBLE3 vPos;							// 顶点位置
	SVBASEDOUBLE3 vTan;							// 顶点的切线方向

	UINT uAreaID;								// 区域ID

	__tagIKSCabUndiGraphVertex()
	{
		uID = UINT(-1);
		memset(&vPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTan, 0, sizeof(SVBASEDOUBLE3));
		uAreaID = UINT(-1);
	}
	__tagIKSCabUndiGraphVertex(const __tagIKSCabUndiGraphVertex &info)
	{
		uID = info.uID;
		vecAdjVertexID = info.vecAdjVertexID;
		vPos = info.vPos;
		vTan = info.vTan;
		uAreaID = info.uAreaID;
	}
	__tagIKSCabUndiGraphVertex& operator=(const __tagIKSCabUndiGraphVertex &info)
	{
		if (&info == this)
			return *this;
		uID = info.uID;
		vecAdjVertexID = info.vecAdjVertexID;
		vPos = info.vPos;
		vTan = info.vTan;
		uAreaID = info.uAreaID;
		return *this;
	}
	void SetData(const __tagIKSCabUndiGraphVertex &info)
	{
		vPos = info.vPos;
		vTan = info.vTan;
		uAreaID = info.uAreaID;
	}
	void Clear()
	{
		uID = UINT(-1);
		vecAdjVertexID.clear();
		memset(&vPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTan, 0, sizeof(SVBASEDOUBLE3));
		uAreaID = UINT(-1);
	}
	BOOL IsPathMidVertex() const { return (vecAdjVertexID.size() == 2); }
} IKSCabUndiGraphVertex;

// 电缆无向图边
typedef struct __tagIKSCabUndiGraphEdge
{
	UINT uVertex1ID;							// 顶点1的ID
	UINT uVertex2ID;							// 顶点2的ID

	double dDist;								// 顶点间距

	__tagIKSCabUndiGraphEdge()
	{
		uVertex1ID = UINT(-1);
		uVertex2ID = UINT(-1);
		dDist = -1.0;
	}
	__tagIKSCabUndiGraphEdge(const __tagIKSCabUndiGraphEdge &info)
	{
		uVertex1ID = info.uVertex1ID;
		uVertex2ID = info.uVertex2ID;
		dDist = info.dDist;
	}
	__tagIKSCabUndiGraphEdge& operator=(const __tagIKSCabUndiGraphEdge &info)
	{
		if (&info == this)
			return *this;
		uVertex1ID = info.uVertex1ID;
		uVertex2ID = info.uVertex2ID;
		dDist = info.dDist;
		return *this;
	}
	void SetData(const __tagIKSCabUndiGraphEdge &info)
	{
		dDist = info.dDist;
	}
	void Clear()
	{
		uVertex1ID = UINT(-1);
		uVertex2ID = UINT(-1);
		dDist = -1.0;
	}
} IKSCabUndiGraphEdge;

// 电缆无向图
class CIKSCabUndiGraph
{
public:
	CIKSCabUndiGraph()
	{
	}
	CIKSCabUndiGraph& operator=(const CIKSCabUndiGraph &info)
	{
		if (&info == this)
			return *this;
		Clear();
		IKSCabUndiGraphVertex *pVertex = NULL;
		for (UINT i=0; i<info.m_vecVertex.size(); i++)
		{
			pVertex = AddVertex(info.m_vecVertex[i]->uID);
			pVertex->SetData(*(info.m_vecVertex[i]));
		}
		IKSCabUndiGraphEdge *pEdge = NULL;
		for (UINT i=0; i<info.m_vecEdge.size(); i++)
		{
			pEdge = AddEdge(info.m_vecEdge[i]->uVertex1ID, info.m_vecEdge[i]->uVertex2ID);
			pEdge->SetData(*(info.m_vecEdge[i]));
		}
		return *this;
	}
	CIKSCabUndiGraph(const CIKSCabUndiGraph &info)
	{
		(*this) = info;
	}

public:
	IKSCabUndiGraphVertex* GetVertexByIndex(UINT uIndex) const;
	IKSCabUndiGraphVertex* GetVertex(UINT uID) const;
	UINT GetVertexIndex(UINT uID) const;
	IKSCabUndiGraphVertex* AddVertex(UINT uID);
	IKSCabUndiGraphEdge* GetEdgeByIndex(UINT uIndex) const;
	IKSCabUndiGraphEdge* GetEdge(UINT uVer1ID, UINT uVer2ID) const;
	UINT GetEdgeIndex(UINT uVer1ID, UINT uVer2ID) const;
	IKSCabUndiGraphEdge* AddEdge(UINT uVer1ID, UINT uVer2ID);
	UINT GetVertexNum() const;
	UINT GetEdgeNum() const;
	void Clear();

public:
	// 清空所有顶点的区域ID
	void ClearVertexAreaID();
	// 更新顶点的区域ID
	void UpdateVertexAreaID();
	// 更新顶点的区域ID
	void UpdateVertexAreaID(UINT uNewAreaID, IKSCabUndiGraphVertex* pVertex);
	// 获取指定区域顶点的ID
	void GetVertexIDByAreaID(UINT uAreaID, CBPDynamicArray<UINT> &vecVertexID);

public:
	// 获取路径分叉点
	BOOL GetPathPortVertex(const IKSCabUndiGraphVertex *pPathMidVer, IKSCabUndiGraphVertex **ppPortVer1, IKSCabUndiGraphVertex **ppPortVer2, const UINT *pBanVerID=NULL, UINT *pVerCount1=NULL, UINT *pVerCount2=NULL)	const;
	// 检验路径是否可以通向指定终点
	BOOL CheckPathFromStartToEnd(const IKSCabUndiGraphVertex *pStartVer, UINT uPreVerID, UINT uEndVerID, UINT *pNextVerCount=NULL)	const;

private:
	CBPDynamicArray<IKSCabUndiGraphVertex*> m_vecVertex;		// 顶点数据
	CBPIDIndexMgr m_mapVertex;
	CBPDynamicArray<IKSCabUndiGraphEdge*> m_vecEdge;			// 边数据
	CBPUINT2IndexMgr m_mapEdge;
};

//===================================================================================================

// 电缆布线路径节点
typedef struct __tagIKSCableRoutingPathNode
{
	UINT uProCabLocIndex;						// 电缆位置索引
	UINT uPreNodeCabLocIndex;					// 前一个节点的电缆位置索引
	SVBASEDOUBLE3 vCurNodeTan;					// 当前节点的切线方向
	SVBASEDOUBLE3 vPreNodeTan;					// 前一个节点的切线方向
	CBPDynamicArray<__tagIKSCableRoutingPathNode> vecNextNode;	// 后续节点（不一定包含所有后续分支路径）

	BOOL bIsToEnd;								// 是否可以通向终点(若为FALSE则说明后续所有路径均已遍历且没有通向终点的路径,若为TRUE则说明起码有一条路径通向终点)
	double dCurNodePriceValue;					// 当前节点的代价值(上一个节点到当前节点的路径带价值)
	double dCurPathPriceValueMin;				// 当前路径的带价值(上一个节点->当前节点->后续节点路径的最小代价值)
	UINT uNextNodeIndexForPriceValueMin;		// 最小带价值路径对应的下一个节点索引

	__tagIKSCableRoutingPathNode()
	{
		uProCabLocIndex = UINT(-1);
		uPreNodeCabLocIndex = UINT(-1);
		memset(&vCurNodeTan, 0, sizeof(SVBASEDOUBLE3));
		memset(&vPreNodeTan, 0, sizeof(SVBASEDOUBLE3));
		bIsToEnd = FALSE;
		dCurNodePriceValue = -1.0;
		dCurPathPriceValueMin = -1.0;
		uNextNodeIndexForPriceValueMin = UINT(-1);
	}
	__tagIKSCableRoutingPathNode(const __tagIKSCableRoutingPathNode &info)
	{
		uProCabLocIndex = info.uProCabLocIndex;
		uPreNodeCabLocIndex = info.uPreNodeCabLocIndex;
		vCurNodeTan = info.vCurNodeTan;
		vPreNodeTan = info.vPreNodeTan;
		vecNextNode = info.vecNextNode;
		bIsToEnd = info.bIsToEnd;
		dCurNodePriceValue = info.dCurNodePriceValue;
		dCurPathPriceValueMin = info.dCurPathPriceValueMin;
		uNextNodeIndexForPriceValueMin = info.uNextNodeIndexForPriceValueMin;
	}
	__tagIKSCableRoutingPathNode& operator=(const __tagIKSCableRoutingPathNode &info)
	{
		if (&info == this)
			return *this;
		uProCabLocIndex = info.uProCabLocIndex;
		uPreNodeCabLocIndex = info.uPreNodeCabLocIndex;
		vCurNodeTan = info.vCurNodeTan;
		vPreNodeTan = info.vPreNodeTan;
		vecNextNode = info.vecNextNode;
		bIsToEnd = info.bIsToEnd;
		dCurNodePriceValue = info.dCurNodePriceValue;
		dCurPathPriceValueMin = info.dCurPathPriceValueMin;
		uNextNodeIndexForPriceValueMin = info.uNextNodeIndexForPriceValueMin;
		return *this;
	}
	void SetData(const __tagIKSCableRoutingPathNode &info)
	{
		uProCabLocIndex = info.uProCabLocIndex;
		uPreNodeCabLocIndex = info.uPreNodeCabLocIndex;
		vCurNodeTan = info.vCurNodeTan;
		vPreNodeTan = info.vPreNodeTan;
		bIsToEnd = info.bIsToEnd;
		dCurNodePriceValue = info.dCurNodePriceValue;
		dCurPathPriceValueMin = info.dCurPathPriceValueMin;
		uNextNodeIndexForPriceValueMin = info.uNextNodeIndexForPriceValueMin;
	}
	void Clear()
	{
		uProCabLocIndex = UINT(-1);
		uPreNodeCabLocIndex = UINT(-1);
		memset(&vCurNodeTan, 0, sizeof(SVBASEDOUBLE3));
		memset(&vPreNodeTan, 0, sizeof(SVBASEDOUBLE3));
		vecNextNode.clear();
		bIsToEnd = FALSE;
		dCurNodePriceValue = -1.0;
		dCurPathPriceValueMin = -1.0;
		uNextNodeIndexForPriceValueMin = UINT(-1);
	}
	UINT GetEndCabLocIndexOnBestPath() const
	{
		const IKSCableRoutingPathNode *pCurNode = this;
		while (pCurNode->uNextNodeIndexForPriceValueMin < pCurNode->vecNextNode.size())
			pCurNode = &(pCurNode->vecNextNode[pCurNode->uNextNodeIndexForPriceValueMin]);
		return pCurNode->uProCabLocIndex;
	}
} IKSCableRoutingPathNode;

// 电缆布线路径
typedef struct __tagIKSCableRoutingPath
{
	IKSCableRoutingPathNode stuStartNode;			// 路径起点节点
	CBPDynamicArray<UINT> vecSelProCabLocIndex;		// 选择的电缆位置索引(半自动布线时使用)(stuStartNode为下一个待选的电缆位置节点及其后续路径节点)

	__tagIKSCableRoutingPath()
	{
	}
	__tagIKSCableRoutingPath(const __tagIKSCableRoutingPath &info)
	{
		stuStartNode = info.stuStartNode;
		vecSelProCabLocIndex = info.vecSelProCabLocIndex;
	}
	__tagIKSCableRoutingPath& operator=(const __tagIKSCableRoutingPath &info)
	{
		if (&info == this)
			return *this;
		stuStartNode = info.stuStartNode;
		vecSelProCabLocIndex = info.vecSelProCabLocIndex;
		return *this;
	}
	void Clear()
	{
		stuStartNode.Clear();
		vecSelProCabLocIndex.clear();
	}
} IKSCableRoutingPath;

// 电缆布线检查信息
typedef struct __tagIKSCableRoutingCheckInf
{
	BOOL bCheckClosedPath;		// 检查封闭环路
	BOOL bCheckBendRadius;		// 检查转弯半径
	BOOL bCheckAvoidFeat;		// 检查避让特征
	BOOL bCheckCapacity;		// 检查容量

	double dMinBendRadius;		// 最小转弯半径

// 	CBPDynamicArray<UINT> vecRequiredCabLocIndex;		// 必须通过的电缆位置索引
// 	CBPDynamicArray<UINT> vecDisallowedCabLocIndex;		// 禁止通过的电缆位置索引

	__tagIKSCableRoutingCheckInf()
	{
		bCheckClosedPath = TRUE;
		bCheckBendRadius = FALSE;
		bCheckAvoidFeat = FALSE;
		bCheckCapacity = FALSE;
		dMinBendRadius = 0.0;
	}
	__tagIKSCableRoutingCheckInf(const __tagIKSCableRoutingCheckInf &info)
	{
		bCheckClosedPath = info.bCheckClosedPath;
		bCheckBendRadius = info.bCheckBendRadius;
		bCheckAvoidFeat = info.bCheckAvoidFeat;
		bCheckCapacity = info.bCheckCapacity;
		dMinBendRadius = info.dMinBendRadius;
// 		vecRequiredCabLocIndex = info.vecRequiredCabLocIndex;
// 		vecDisallowedCabLocIndex = info.vecDisallowedCabLocIndex;
	}
	__tagIKSCableRoutingCheckInf& operator=(const __tagIKSCableRoutingCheckInf &info)
	{
		if (&info == this)
			return *this;
		bCheckClosedPath = info.bCheckClosedPath;
		bCheckBendRadius = info.bCheckBendRadius;
		bCheckAvoidFeat = info.bCheckAvoidFeat;
		bCheckCapacity = info.bCheckCapacity;
		dMinBendRadius = info.dMinBendRadius;
// 		vecRequiredCabLocIndex = info.vecRequiredCabLocIndex;
// 		vecDisallowedCabLocIndex = info.vecDisallowedCabLocIndex;
		return *this;
	}
	void Clear()
	{
		bCheckClosedPath = TRUE;
		bCheckBendRadius = FALSE;
		bCheckAvoidFeat = FALSE;
		bCheckCapacity = FALSE;
		dMinBendRadius = 0.0;
// 		vecRequiredCabLocIndex.clear();
// 		vecDisallowedCabLocIndex.clear();
	}
} IKSCableRoutingCheckInf;

// 电缆布线电缆信息
typedef struct __tagIKSCableRoutingCabInf
{
	UINT uHarnessCableIndex;						// 线束中电缆的索引

	SVBASEDOUBLE3 vStartPos;						// 起点位置
	SVBASEDOUBLE3 vStartAxisZ;						// 起点切线方向
	SVBASEDOUBLE3 vEndPos;							// 终点位置
	SVBASEDOUBLE3 vEndAxisZ;						// 终点切线方向(反方向)

	UINT uStartProCabLocIndex;						// 起始电缆位置索引
	SVBASEDOUBLE3 vStartLocTan;						// 起点位置的切线方向
	UINT uEndProCabLocIndex;						// 终止电缆位置索引
	SVBASEDOUBLE3 vEndLocTan;						// 终点位置的切线方向
// 	BOOL bEndOnExistPath;							// 终止在已知路径上

	IKSCableRoutingPath stuRoutingPath;				// 布线路径

	__tagIKSCableRoutingCabInf()
	{
		uHarnessCableIndex = UINT(-1);
		memset(&vStartPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vStartAxisZ, 0, sizeof(SVBASEDOUBLE3));
		vStartAxisZ.z = 1.0;
		memset(&vEndPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vEndAxisZ, 0, sizeof(SVBASEDOUBLE3));
		vEndAxisZ.z = 1.0;
		uStartProCabLocIndex = UINT(-1);
		memset(&vStartLocTan, 0, sizeof(SVBASEDOUBLE3));
		uEndProCabLocIndex = UINT(-1);
		memset(&vEndLocTan, 0, sizeof(SVBASEDOUBLE3));
// 		bEndOnExistPath = FALSE;
	}
	__tagIKSCableRoutingCabInf(const __tagIKSCableRoutingCabInf &info)
	{
		uHarnessCableIndex = info.uHarnessCableIndex;
		vStartPos = info.vStartPos;
		vStartAxisZ = info.vStartAxisZ;
		vEndPos = info.vEndPos;
		vEndAxisZ = info.vEndAxisZ;
		uStartProCabLocIndex = info.uStartProCabLocIndex;
		vStartLocTan = info.vStartLocTan;
		uEndProCabLocIndex = info.uEndProCabLocIndex;
		vEndLocTan = info.vEndLocTan;
// 		bEndOnExistPath = info.bEndOnExistPath;
		stuRoutingPath = info.stuRoutingPath;
	}
	__tagIKSCableRoutingCabInf& operator=(const __tagIKSCableRoutingCabInf &info)
	{
		if (&info == this)
			return *this;
		uHarnessCableIndex = info.uHarnessCableIndex;
		vStartPos = info.vStartPos;
		vStartAxisZ = info.vStartAxisZ;
		vEndPos = info.vEndPos;
		vEndAxisZ = info.vEndAxisZ;
		uStartProCabLocIndex = info.uStartProCabLocIndex;
		vStartLocTan = info.vStartLocTan;
		uEndProCabLocIndex = info.uEndProCabLocIndex;
		vEndLocTan = info.vEndLocTan;
// 		bEndOnExistPath = info.bEndOnExistPath;
		stuRoutingPath = info.stuRoutingPath;
		return *this;
	}
	void Clear()
	{
		uHarnessCableIndex = UINT(-1);
		memset(&vStartPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vStartAxisZ, 0, sizeof(SVBASEDOUBLE3));
		vStartAxisZ.z = 1.0;
		memset(&vEndPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vEndAxisZ, 0, sizeof(SVBASEDOUBLE3));
		vEndAxisZ.z = 1.0;
		uStartProCabLocIndex = UINT(-1);
		memset(&vStartLocTan, 0, sizeof(SVBASEDOUBLE3));
		uEndProCabLocIndex = UINT(-1);
		memset(&vEndLocTan, 0, sizeof(SVBASEDOUBLE3));
// 		bEndOnExistPath = FALSE;
		stuRoutingPath.Clear();
	}
} IKSCableRoutingCabInf;

// 电缆布线信息
typedef struct __tagIKSCableRoutingInf
{
	IKSCable stuNetwork;							// 路径网络
	CIKSCabUndiGraph stuCabUndiGraph;				// 电缆无向图
	CIKSCabUndiGraph stuExistPathUndiGraph;			// 已存在路径的无向图

	IKSCableRoutingCheckInf stuCheckInf;			// 电缆布线检查信息
	int nCabRoutMode;								// 电缆布线模式,参看枚举型CABLEROUTINGMODE
	BOOL bFindAllPath;								// 遍历所有路径的标识(若为TRUE则遍历所有路径以寻找最优路径)

	IKSCableRoutingCabInf stuRoutingCabInf;			// 布线的电缆信息

	__tagIKSCableRoutingInf()
	{
		nCabRoutMode = IKSCABROUTM_DIRECTTOEND;
		bFindAllPath = TRUE;
	}
	__tagIKSCableRoutingInf(const __tagIKSCableRoutingInf &info)
	{
		stuNetwork = info.stuNetwork;
		stuCabUndiGraph = info.stuCabUndiGraph;
		stuExistPathUndiGraph = info.stuExistPathUndiGraph;
		stuCheckInf = info.stuCheckInf;
		nCabRoutMode = info.nCabRoutMode;
		bFindAllPath = info.bFindAllPath;
		stuRoutingCabInf = info.stuRoutingCabInf;
	}
	__tagIKSCableRoutingInf& operator=(const __tagIKSCableRoutingInf &info)
	{
		if (&info == this)
			return *this;
		stuNetwork = info.stuNetwork;
		stuCabUndiGraph = info.stuCabUndiGraph;
		stuExistPathUndiGraph = info.stuExistPathUndiGraph;
		stuCheckInf = info.stuCheckInf;
		nCabRoutMode = info.nCabRoutMode;
		bFindAllPath = info.bFindAllPath;
		stuRoutingCabInf = info.stuRoutingCabInf;
		return *this;
	}
	void Clear()
	{
		stuNetwork.Clear();
		stuCabUndiGraph.Clear();
		stuExistPathUndiGraph.Clear();
		stuCheckInf.Clear();
		nCabRoutMode = IKSCABROUTM_DIRECTTOEND;
		bFindAllPath = TRUE;
		stuRoutingCabInf.Clear();
	}
} IKSCableRoutingInf;

// 总线电缆布线电连接器对信息
typedef struct __tagIKSTrunkCableRoutingConnPairInf
{
	UINT uStartConnIndex;				// 起始电连接器索引(索引为0表示IKSTrunkCabSegmentInfo::stuConnStart,索引为IKSTrunkCabSegmentInfo::vecConnMid.size()+1表示IKSTrunkCabSegmentInfo::stuConnEnd,中间的索引表示中间电连接器)
	UINT uEndConnIndex;					// 终止电连接器索引(索引为0表示IKSTrunkCabSegmentInfo::stuConnStart,索引为IKSTrunkCabSegmentInfo::vecConnMid.size()+1表示IKSTrunkCabSegmentInfo::stuConnEnd,中间的索引表示中间电连接器)
	UINT uStartConnEntryPortIndex;		// 起始电连接器入口端索引
	UINT uEndConnEntryPortIndex;		// 终止电连接器入口端索引

	__tagIKSTrunkCableRoutingConnPairInf()
	{
		uStartConnIndex = UINT(-1);
		uEndConnIndex = UINT(-1);
		uStartConnEntryPortIndex = UINT(-1);
		uEndConnEntryPortIndex = UINT(-1);
	}
	__tagIKSTrunkCableRoutingConnPairInf(const __tagIKSTrunkCableRoutingConnPairInf &info)
	{
		uStartConnIndex = info.uStartConnIndex;
		uEndConnIndex = info.uEndConnIndex;
		uStartConnEntryPortIndex = info.uStartConnEntryPortIndex;
		uEndConnEntryPortIndex = info.uEndConnEntryPortIndex;
	}
	__tagIKSTrunkCableRoutingConnPairInf& operator=(const __tagIKSTrunkCableRoutingConnPairInf &info)
	{
		if (&info == this)
			return *this;
		uStartConnIndex = info.uStartConnIndex;
		uEndConnIndex = info.uEndConnIndex;
		uStartConnEntryPortIndex = info.uStartConnEntryPortIndex;
		uEndConnEntryPortIndex = info.uEndConnEntryPortIndex;
		return *this;
	}
	void Clear()
	{
		uStartConnIndex = UINT(-1);
		uEndConnIndex = UINT(-1);
		uStartConnEntryPortIndex = UINT(-1);
		uEndConnEntryPortIndex = UINT(-1);
	}
} IKSTrunkCableRoutingConnPairInf;

// 总线电缆布线信息
typedef struct __tagIKSTrunkCableRoutingInf
{
	IKSCableRoutingInf stuCableRoutingInf;			// 电缆布线信息
	BOOL bFindAllPath;								// 遍历所有中间电连接器排列组合对应路径的标识(若为TRUE则遍历所有路径以寻找最优路径)
	BOOL bUseOriSequence;							// 使用总线连接关系表的原有顺序
	IKSTrunkCabSegmentInfo stuTrunkCabSegmentInfo;	// 总线电缆段信息

	CBPDynamicArray<IKSCableRoutingCabInf> arrRoutingCabInf;					// 布线的电缆信息(arrRoutingCabInf.size() == stuTrunkCabSegmentInfo.vecConnMid.size()+1)
	CBPDynamicArray<IKSTrunkCableRoutingConnPairInf> arrRoutingConnPairInf;		// 总线电缆布线电连接器对信息

	__tagIKSTrunkCableRoutingInf()
	{
		bFindAllPath = TRUE;
		bUseOriSequence = FALSE;
	}
	__tagIKSTrunkCableRoutingInf(const __tagIKSTrunkCableRoutingInf &info)
	{
		stuCableRoutingInf = info.stuCableRoutingInf;
		bFindAllPath = info.bFindAllPath;
		bUseOriSequence = info.bUseOriSequence;
		stuTrunkCabSegmentInfo = info.stuTrunkCabSegmentInfo;
		arrRoutingCabInf = info.arrRoutingCabInf;
		arrRoutingConnPairInf = info.arrRoutingConnPairInf;
	}
	__tagIKSTrunkCableRoutingInf& operator=(const __tagIKSTrunkCableRoutingInf &info)
	{
		if (&info == this)
			return *this;
		stuCableRoutingInf = info.stuCableRoutingInf;
		bFindAllPath = info.bFindAllPath;
		bUseOriSequence = info.bUseOriSequence;
		stuTrunkCabSegmentInfo = info.stuTrunkCabSegmentInfo;
		arrRoutingCabInf = info.arrRoutingCabInf;
		arrRoutingConnPairInf = info.arrRoutingConnPairInf;
		return *this;
	}
	void Clear()
	{
		stuCableRoutingInf.Clear();
		bFindAllPath = TRUE;
		bUseOriSequence = FALSE;
		stuTrunkCabSegmentInfo.Clear();
		arrRoutingCabInf.clear();
		arrRoutingConnPairInf.clear();
	}
} IKSTrunkCableRoutingInf;

//===================================================================================================

// ProE线轴与索引对应关系管理类
class CProSpoolIndexMgr
{
public:
	CProSpoolIndexMgr(){}
	virtual ~CProSpoolIndexMgr(){}

protected:
	class ProSpoolComparator
	{
	public:
		bool operator()(const ProSpool& p1, const ProSpool& p2) const
		{
			int nCmp = wcscmp(p1.name, p2.name);
			if (nCmp < 0)
				return true;
			else if (nCmp > 0)
				return false;
			else
			{
				if (memcmp(p1.owner, p2.owner, sizeof(ProAssembly)) < 0)
					return true;
				else
					return false;
			}
		}
	};

public:
	void AddValueIndex(const ProSpool &vValue, IKS_UINT uIndex)
	{
		ProSpool stuSpoolM = vValue;
		CSVWString strM = vValue.name;
		strM.MakeLower();
		wcscpy_s(stuSpoolM.name, PRO_NAME_SIZE, strM);
		m_ValueIndexPool[stuSpoolM] = uIndex;
	}
	IKS_UINT GetIndexByValue(const ProSpool &vValue)	const
	{
		ProSpool stuSpoolM = vValue;
		CSVWString strM = vValue.name;
		strM.MakeLower();
		wcscpy_s(stuSpoolM.name, PRO_NAME_SIZE, strM);
		std::map<ProSpool,IKS_UINT,ProSpoolComparator>::const_iterator iter = m_ValueIndexPool.find(stuSpoolM);
		if (iter != m_ValueIndexPool.end())
			return iter->second;

		return IKS_UINT(-1);
	}
	void clear()	{ m_ValueIndexPool.clear(); }
	IKS_BOOL DeleteValueIndex(const ProSpool &vValue)
	{
		ProSpool stuSpoolM = vValue;
		CSVWString strM = vValue.name;
		strM.MakeLower();
		wcscpy_s(stuSpoolM.name, PRO_NAME_SIZE, strM);
		std::map<ProSpool,IKS_UINT,ProSpoolComparator>::const_iterator iter = m_ValueIndexPool.find(stuSpoolM);
		if (iter == m_ValueIndexPool.end())
			return FALSE;
		m_ValueIndexPool.erase(iter);
		return TRUE;
	}
	void GetValueData(ProSpool *pValueArray, IKS_UINT *pIndexArray, IKS_UINT *pIDSize) const
	{
		IKS_UINT uSize = m_ValueIndexPool.size();
		if (pIDSize != NULL)
			*pIDSize = uSize;
		if (pValueArray != NULL || pIndexArray != NULL)
		{
			std::map<ProSpool,IKS_UINT,ProSpoolComparator>::const_iterator it;
			for(it=m_ValueIndexPool.begin(); it!= m_ValueIndexPool.end(); it++)
			{
				if (pValueArray != NULL)
					*(pValueArray++) = it->first;
				if (pIndexArray != NULL)
					*(pIndexArray++) = it->second;
			}
		}
	}

private:
	std::map<ProSpool,IKS_UINT,ProSpoolComparator> m_ValueIndexPool;		// Spool与索引关系池
};

// ProE模型项与索引对应关系管理类
class CProModelItemIndexMgr
{
public:
	CProModelItemIndexMgr(){}
	virtual ~CProModelItemIndexMgr(){}

protected:
	class ProModelItemComparator
	{
	public:
		bool operator()(const pro_model_item& m1, const pro_model_item& m2) const
		{
			if (memcmp(&m1, &m2, sizeof(pro_model_item)) < 0)
				return true;
			else
				return false;
		}
	};

public:
	void AddValueIndex(const pro_model_item &mi, IKS_UINT uIndex) {	m_ValueIndexPool[mi] = uIndex; }
	IKS_UINT GetIndexByValue(const pro_model_item &mi)	const
	{
		std::map<pro_model_item,IKS_UINT,ProModelItemComparator>::const_iterator iter = m_ValueIndexPool.find(mi);
		if (iter != m_ValueIndexPool.end())
			return iter->second;

		return IKS_UINT(-1);
	}
	void clear()	{ m_ValueIndexPool.clear(); }
	IKS_BOOL DeleteValueIndex(const pro_model_item &mi)
	{
		std::map<pro_model_item,IKS_UINT,ProModelItemComparator>::const_iterator iter = m_ValueIndexPool.find(mi);
		if (iter == m_ValueIndexPool.end())
			return FALSE;
		m_ValueIndexPool.erase(iter);
		return TRUE;
	}
	void GetValueData(pro_model_item *pValueArray, IKS_UINT *pIndexArray, IKS_UINT *pIDSize) const
	{
		IKS_UINT uSize = m_ValueIndexPool.size();
		if (pIDSize != NULL)
			*pIDSize = uSize;
		if (pValueArray != NULL || pIndexArray != NULL)
		{
			std::map<pro_model_item,IKS_UINT,ProModelItemComparator>::const_iterator it;
			for(it=m_ValueIndexPool.begin(); it!= m_ValueIndexPool.end(); it++)
			{
				if (pValueArray != NULL)
					*(pValueArray++) = it->first;
				if (pIndexArray != NULL)
					*(pIndexArray++) = it->second;
			}
		}
	}

private:
	std::map<pro_model_item,IKS_UINT,ProModelItemComparator> m_ValueIndexPool;		// ModelItem与索引关系池
};

// 双精浮点位置与索引对应关系管理类（该类有重大缺陷）
// class CBPDPositionValueIndexMgr
// {
// public:
// 	CBPDPositionValueIndexMgr(){}
// 	virtual ~CBPDPositionValueIndexMgr(){}
// 
// protected:
// 	class DPositionComparator
// 	{
// 	public:
// 		bool operator()(const SVBASEDOUBLE3& v1, const SVBASEDOUBLE3& v2) const
// 		{
// 			if (ISDEQUAL(v1.x, v2.x))
// 			{
// 				if (ISDEQUAL(v1.y, v2.y))
// 				{
// 					if (ISDEQUAL(v1.z, v2.z))
// 					{
// 						return false;
// 					}
// 					else if (v1.z < v2.z)
// 						return true;
// 					else
// 						return false;
// 				}
// 				else if (v1.y < v2.y)
// 					return true;
// 				else
// 					return false;
// 			}
// 			else if (v1.x < v2.x)
// 				return true;
// 			else
// 				return false;
// 		}
// 	};
// 
// public:
// 	void AddValueIndex(const SVBASEDOUBLE3 &vValue, IKS_UINT uIndex)
// 	{
// 		std::map<SVBASEDOUBLE3,IKS_UINT,DPositionComparator>::iterator iter = m_ValueIndexPool.find(vValue);
// 		if (iter != m_ValueIndexPool.end())
// 			iter->second = uIndex;
// 		else
// 			m_ValueIndexPool[vValue] = uIndex;
// 	}
// 	// 根据位置获取索引(注意:找到的是第一个满足精度范围的元素,而非是距离输入位置最近的元素)
// 	IKS_UINT GetIndexByValue(const SVBASEDOUBLE3 &vValue)	const
// 	{
// 		std::map<SVBASEDOUBLE3,IKS_UINT,DPositionComparator>::const_iterator iter = m_ValueIndexPool.find(vValue);
// 		if (iter != m_ValueIndexPool.end())
// 			return iter->second;
// 
// 		return IKS_UINT(-1);
// 	}
// 	void clear()	{ m_ValueIndexPool.clear(); }
// 	IKS_BOOL DeleteValueIndex(const SVBASEDOUBLE3 &vValue)
// 	{
// 		std::map<SVBASEDOUBLE3,IKS_UINT,DPositionComparator>::const_iterator iter = m_ValueIndexPool.find(vValue);
// 		if (iter == m_ValueIndexPool.end())
// 			return FALSE;
// 		m_ValueIndexPool.erase(iter);
// 		return TRUE;
// 	}
// 	void GetValueData(SVBASEDOUBLE3 *pValueArray, IKS_UINT *pIndexArray, IKS_UINT *pIDSize) const
// 	{
// 		IKS_UINT uSize = m_ValueIndexPool.size();
// 		if (pIDSize != NULL)
// 			*pIDSize = uSize;
// 		if (pValueArray != NULL || pIndexArray != NULL)
// 		{
// 			std::map<SVBASEDOUBLE3,IKS_UINT,DPositionComparator>::const_iterator it;
// 			for(it=m_ValueIndexPool.begin(); it!= m_ValueIndexPool.end(); it++)
// 			{
// 				if (pValueArray != NULL)
// 					*(pValueArray++) = it->first;
// 				if (pIndexArray != NULL)
// 					*(pIndexArray++) = it->second;
// 			}
// 		}
// 	}
// 
// private:
// 	std::map<SVBASEDOUBLE3,IKS_UINT,DPositionComparator> m_ValueIndexPool;		// ID与索引关系池
// };

// 直线段存在关系管理类（该类有缺陷）
// class CLineExistMgr
// {
// public:
// 	CLineExistMgr(){}
// 	virtual ~CLineExistMgr(){}
// 
// protected:
// 	class LineComparator
// 	{
// 	public:
// 		bool operator()(const IKSCABDLineData& l1, const IKSCABDLineData& l2) const
// 		{
// 			if (ISDEQUAL(l1.end1.x, l2.end1.x))
// 			{
// 				if (ISDEQUAL(l1.end1.y, l2.end1.y))
// 				{
// 					if (ISDEQUAL(l1.end1.z, l2.end1.z))
// 					{
// 						if (ISDEQUAL(l1.end2.x, l2.end2.x))
// 						{
// 							if (ISDEQUAL(l1.end2.y, l2.end2.y))
// 							{
// 								if (ISDEQUAL(l1.end2.z, l2.end2.z))
// 								{
// 									return false;
// 								}
// 								else if (l1.end2.z < l2.end2.z)
// 									return true;
// 								else
// 									return false;
// 							}
// 							else if (l1.end2.y < l2.end2.y)
// 								return true;
// 							else
// 								return false;
// 						}
// 						else if (l1.end2.x < l2.end2.x)
// 							return true;
// 						else
// 							return false;
// 					}
// 					else if (l1.end1.z < l2.end1.z)
// 						return true;
// 					else
// 						return false;
// 				}
// 				else if (l1.end1.y < l2.end1.y)
// 					return true;
// 				else
// 					return false;
// 			}
// 			else if (l1.end1.x < l2.end1.x)
// 				return true;
// 			else
// 				return false;
// 		}
// 	};
// 
// public:
// 	void AddValueExist(const IKSCABDLineData &vValue)
// 	{
// 		std::map<IKSCABDLineData,BOOL,LineComparator>::iterator iter = m_ValueExistPool.find(vValue);
// 		if (iter != m_ValueExistPool.end())
// 			iter->second = TRUE;
// 		else
// 			m_ValueExistPool[vValue] = TRUE;
// 	}
// 	BOOL IsValueExist(const IKSCABDLineData &vValue)	const
// 	{
// 		std::map<IKSCABDLineData,BOOL,LineComparator>::const_iterator iter = m_ValueExistPool.find(vValue);
// 		if (iter != m_ValueExistPool.end())
// 			return TRUE;
// 
// 		return FALSE;
// 	}
// 	void clear()	{ m_ValueExistPool.clear(); }
// 	IKS_BOOL DeleteValueIndex(const IKSCABDLineData &vValue)
// 	{
// 		std::map<IKSCABDLineData,BOOL,LineComparator>::const_iterator iter = m_ValueExistPool.find(vValue);
// 		if (iter == m_ValueExistPool.end())
// 			return FALSE;
// 		m_ValueExistPool.erase(iter);
// 		return TRUE;
// 	}
// 
// private:
// 	std::map<IKSCABDLineData,BOOL,LineComparator> m_ValueExistPool;		// Line存在关系池
// };

}	// namespace IKS_SMARTCABLING

//===================================================================================================

