//===================================================================================================
// Summary:
//		���»������ݶ���
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

// ��������ͼ����
typedef struct __tagIKSCabUndiGraphVertex
{
	UINT uID;									// ����ID
	CBPDynamicArray<UINT> vecAdjVertexID;		// ���ڶ����ID
	SVBASEDOUBLE3 vPos;							// ����λ��
	SVBASEDOUBLE3 vTan;							// ��������߷���

	UINT uAreaID;								// ����ID

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

// ��������ͼ��
typedef struct __tagIKSCabUndiGraphEdge
{
	UINT uVertex1ID;							// ����1��ID
	UINT uVertex2ID;							// ����2��ID

	double dDist;								// ������

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

// ��������ͼ
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
	// ������ж��������ID
	void ClearVertexAreaID();
	// ���¶��������ID
	void UpdateVertexAreaID();
	// ���¶��������ID
	void UpdateVertexAreaID(UINT uNewAreaID, IKSCabUndiGraphVertex* pVertex);
	// ��ȡָ�����򶥵��ID
	void GetVertexIDByAreaID(UINT uAreaID, CBPDynamicArray<UINT> &vecVertexID);

public:
	// ��ȡ·���ֲ��
	BOOL GetPathPortVertex(const IKSCabUndiGraphVertex *pPathMidVer, IKSCabUndiGraphVertex **ppPortVer1, IKSCabUndiGraphVertex **ppPortVer2, const UINT *pBanVerID=NULL, UINT *pVerCount1=NULL, UINT *pVerCount2=NULL)	const;
	// ����·���Ƿ����ͨ��ָ���յ�
	BOOL CheckPathFromStartToEnd(const IKSCabUndiGraphVertex *pStartVer, UINT uPreVerID, UINT uEndVerID, UINT *pNextVerCount=NULL)	const;

private:
	CBPDynamicArray<IKSCabUndiGraphVertex*> m_vecVertex;		// ��������
	CBPIDIndexMgr m_mapVertex;
	CBPDynamicArray<IKSCabUndiGraphEdge*> m_vecEdge;			// ������
	CBPUINT2IndexMgr m_mapEdge;
};

//===================================================================================================

// ���²���·���ڵ�
typedef struct __tagIKSCableRoutingPathNode
{
	UINT uProCabLocIndex;						// ����λ������
	UINT uPreNodeCabLocIndex;					// ǰһ���ڵ�ĵ���λ������
	SVBASEDOUBLE3 vCurNodeTan;					// ��ǰ�ڵ�����߷���
	SVBASEDOUBLE3 vPreNodeTan;					// ǰһ���ڵ�����߷���
	CBPDynamicArray<__tagIKSCableRoutingPathNode> vecNextNode;	// �����ڵ㣨��һ���������к�����֧·����

	BOOL bIsToEnd;								// �Ƿ����ͨ���յ�(��ΪFALSE��˵����������·�����ѱ�����û��ͨ���յ��·��,��ΪTRUE��˵��������һ��·��ͨ���յ�)
	double dCurNodePriceValue;					// ��ǰ�ڵ�Ĵ���ֵ(��һ���ڵ㵽��ǰ�ڵ��·������ֵ)
	double dCurPathPriceValueMin;				// ��ǰ·���Ĵ���ֵ(��һ���ڵ�->��ǰ�ڵ�->�����ڵ�·������С����ֵ)
	UINT uNextNodeIndexForPriceValueMin;		// ��С����ֵ·����Ӧ����һ���ڵ�����

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

// ���²���·��
typedef struct __tagIKSCableRoutingPath
{
	IKSCableRoutingPathNode stuStartNode;			// ·�����ڵ�
	CBPDynamicArray<UINT> vecSelProCabLocIndex;		// ѡ��ĵ���λ������(���Զ�����ʱʹ��)(stuStartNodeΪ��һ����ѡ�ĵ���λ�ýڵ㼰�����·���ڵ�)

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

// ���²��߼����Ϣ
typedef struct __tagIKSCableRoutingCheckInf
{
	BOOL bCheckClosedPath;		// ����ջ�·
	BOOL bCheckBendRadius;		// ���ת��뾶
	BOOL bCheckAvoidFeat;		// ����������
	BOOL bCheckCapacity;		// �������

	double dMinBendRadius;		// ��Сת��뾶

// 	CBPDynamicArray<UINT> vecRequiredCabLocIndex;		// ����ͨ���ĵ���λ������
// 	CBPDynamicArray<UINT> vecDisallowedCabLocIndex;		// ��ֹͨ���ĵ���λ������

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

// ���²��ߵ�����Ϣ
typedef struct __tagIKSCableRoutingCabInf
{
	UINT uHarnessCableIndex;						// �����е��µ�����

	SVBASEDOUBLE3 vStartPos;						// ���λ��
	SVBASEDOUBLE3 vStartAxisZ;						// ������߷���
	SVBASEDOUBLE3 vEndPos;							// �յ�λ��
	SVBASEDOUBLE3 vEndAxisZ;						// �յ����߷���(������)

	UINT uStartProCabLocIndex;						// ��ʼ����λ������
	SVBASEDOUBLE3 vStartLocTan;						// ���λ�õ����߷���
	UINT uEndProCabLocIndex;						// ��ֹ����λ������
	SVBASEDOUBLE3 vEndLocTan;						// �յ�λ�õ����߷���
// 	BOOL bEndOnExistPath;							// ��ֹ����֪·����

	IKSCableRoutingPath stuRoutingPath;				// ����·��

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

// ���²�����Ϣ
typedef struct __tagIKSCableRoutingInf
{
	IKSCable stuNetwork;							// ·������
	CIKSCabUndiGraph stuCabUndiGraph;				// ��������ͼ
	CIKSCabUndiGraph stuExistPathUndiGraph;			// �Ѵ���·��������ͼ

	IKSCableRoutingCheckInf stuCheckInf;			// ���²��߼����Ϣ
	int nCabRoutMode;								// ���²���ģʽ,�ο�ö����CABLEROUTINGMODE
	BOOL bFindAllPath;								// ��������·���ı�ʶ(��ΪTRUE���������·����Ѱ������·��)

	IKSCableRoutingCabInf stuRoutingCabInf;			// ���ߵĵ�����Ϣ

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

// ���ߵ��²��ߵ�����������Ϣ
typedef struct __tagIKSTrunkCableRoutingConnPairInf
{
	UINT uStartConnIndex;				// ��ʼ������������(����Ϊ0��ʾIKSTrunkCabSegmentInfo::stuConnStart,����ΪIKSTrunkCabSegmentInfo::vecConnMid.size()+1��ʾIKSTrunkCabSegmentInfo::stuConnEnd,�м��������ʾ�м��������)
	UINT uEndConnIndex;					// ��ֹ������������(����Ϊ0��ʾIKSTrunkCabSegmentInfo::stuConnStart,����ΪIKSTrunkCabSegmentInfo::vecConnMid.size()+1��ʾIKSTrunkCabSegmentInfo::stuConnEnd,�м��������ʾ�м��������)
	UINT uStartConnEntryPortIndex;		// ��ʼ����������ڶ�����
	UINT uEndConnEntryPortIndex;		// ��ֹ����������ڶ�����

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

// ���ߵ��²�����Ϣ
typedef struct __tagIKSTrunkCableRoutingInf
{
	IKSCableRoutingInf stuCableRoutingInf;			// ���²�����Ϣ
	BOOL bFindAllPath;								// ���������м��������������϶�Ӧ·���ı�ʶ(��ΪTRUE���������·����Ѱ������·��)
	BOOL bUseOriSequence;							// ʹ���������ӹ�ϵ���ԭ��˳��
	IKSTrunkCabSegmentInfo stuTrunkCabSegmentInfo;	// ���ߵ��¶���Ϣ

	CBPDynamicArray<IKSCableRoutingCabInf> arrRoutingCabInf;					// ���ߵĵ�����Ϣ(arrRoutingCabInf.size() == stuTrunkCabSegmentInfo.vecConnMid.size()+1)
	CBPDynamicArray<IKSTrunkCableRoutingConnPairInf> arrRoutingConnPairInf;		// ���ߵ��²��ߵ�����������Ϣ

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

// ProE������������Ӧ��ϵ������
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
	std::map<ProSpool,IKS_UINT,ProSpoolComparator> m_ValueIndexPool;		// Spool��������ϵ��
};

// ProEģ������������Ӧ��ϵ������
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
	std::map<pro_model_item,IKS_UINT,ProModelItemComparator> m_ValueIndexPool;		// ModelItem��������ϵ��
};

// ˫������λ����������Ӧ��ϵ�����ࣨ�������ش�ȱ�ݣ�
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
// 	// ����λ�û�ȡ����(ע��:�ҵ����ǵ�һ�����㾫�ȷ�Χ��Ԫ��,�����Ǿ�������λ�������Ԫ��)
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
// 	std::map<SVBASEDOUBLE3,IKS_UINT,DPositionComparator> m_ValueIndexPool;		// ID��������ϵ��
// };

// ֱ�߶δ��ڹ�ϵ�����ࣨ������ȱ�ݣ�
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
// 	std::map<IKSCABDLineData,BOOL,LineComparator> m_ValueExistPool;		// Line���ڹ�ϵ��
// };

}	// namespace IKS_SMARTCABLING

//===================================================================================================

