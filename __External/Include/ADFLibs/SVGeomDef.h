//===================================================================================================
// File:
//		SVGeomDef.h
// Summary:
//		Define Geometry class/struct, enum, macro and so on.
// Usage:
//		���弸�ε����ݣ����ڶ����������ݽṹ��
// Remarks:
//		Null
// Date:
//		2012-7-19
// Author:
//		Shiping Wang
//===================================================================================================

#pragma once

//===================================================================================================

// ͷ�ļ�
#include <vector>
#include "SVBaseDef.h"


//===================================================================================================
// ��ѧ����


//===================================================================================================
// �궨��


//===================================================================================================
// ö�����Ͷ���

// ������
typedef enum _BPSURFACETYPE
{
	BPSURFTYPE_UNKOWN			= 0,	// δ֪��
	BPSURFTYPE_PLANE			= 1,	// ƽ��
	BPSURFTYPE_CYLINDER			= 2,	// Բ����
	BPSURFTYPE_CONE				= 3,	// Բ׶��
	BPSURFTYPE_TORUS			= 4,	// Բ����
	BPSURFTYPE_REVOLVE			= 5,	// ��ת��
	BPSURFTYPE_TABCYL			= 6,	// �б�����
} BPSURFACETYPE;

// ��������
typedef enum _BPCURVETYPE
{
	BPCURVETYPE_UNKOWN			= 0,	// δ֪����
	BPCURVETYPE_LINE			= 1,	// ֱ��
	BPCURVETYPE_ARC				= 2,	// Բ��
} BPCURVETYPE;

// ��ά��������
typedef enum _BPCURVE2DTYPE
{
	BP2DCURVETYPE_UNKNOWN			= 0,	// δ֪����
	BP2DCURVETYPE_LINE				= 1,	// ֱ��
	BP2DCURVETYPE_ARC				= 2,	// Բ��
	BP2DCURVETYPE_POLYGON			= 3,	// �����
} BPCURVE2DTYPE;

//===================================================================================================
// �ṹ�嶨��

// ƽ��
typedef struct __tagBPPlaneData
{
	BPBASEFLOAT3 vAxisX;
	BPBASEFLOAT3 vAxisY;
	BPBASEFLOAT3 vAxisZ;	// ��ֱ����ķ�ʸ����
	BPBASEFLOAT3 vOrigin;	// ԭ��
} BPPlaneData;

// Բ����
typedef struct __tagBPCylinderData
{
	BPBASEFLOAT3 vAxisX;
	BPBASEFLOAT3 vAxisY;
	BPBASEFLOAT3 vAxisZ;	// ��ֱ����ķ�ʸ����
	BPBASEFLOAT3 vOrigin;	// ԭ��
	float radius;			// ��Բ�뾶
} BPCylinderData;

// Բ׶��
typedef struct __tagBPConeData
{
	BPBASEFLOAT3 vAxisX;
	BPBASEFLOAT3 vAxisY;
	BPBASEFLOAT3 vAxisZ;	// ��ֱ����ķ�ʸ����
	BPBASEFLOAT3 vOrigin;	// ԭ��
	float alpha;			// Angle between the axis of the cone and the generating line
} BPConeData;

// Բ����
typedef struct __tagBPTorusData
{
	BPBASEFLOAT3 vAxisX;
	BPBASEFLOAT3 vAxisY;
	BPBASEFLOAT3 vAxisZ;	// ��ֱ����ķ�ʸ����
	BPBASEFLOAT3 vOrigin;	// ԭ��
	float radius1;			// Distance from the center of the generating arc to the axis of revolution
	float radius2;			// Radius of the generating arc
} BPTorusData;

// ��ת��
typedef struct __tagBPRevolveData
{
	BPBASEFLOAT3 vAxisX;
	BPBASEFLOAT3 vAxisY;
	BPBASEFLOAT3 vAxisZ;	// ��ֱ����ķ�ʸ����
	BPBASEFLOAT3 vOrigin;	// ԭ��
	// �˴�������������spline�ķ�������
} BPRevolveData;

// �б�����
typedef struct __tagBPTabCylData
{
	BPBASEFLOAT3 vAxisX;
	BPBASEFLOAT3 vAxisY;
	BPBASEFLOAT3 vAxisZ;	// ��ֱ����ķ�ʸ����
	BPBASEFLOAT3 vOrigin;	// ԭ��
	// �˴��������ߵķ�������
} BPTabCylData;

// �����״����
typedef union __tagBPSurfaceShapeData
{
	BPPlaneData				plane;			// ƽ��
	BPCylinderData			cylinder;		// Բ����
	BPConeData				cone;			// Բ׶��
	BPTorusData				torus;			// Բ����
	BPRevolveData			revolve;		// ��ת��
	BPTabCylData			tabcyl;			// �б�����
} BPSurfaceShapeData;

// ����������Ϣ
typedef struct __tagBPSurface
{
	int						nID;			// ����ID
	int						nType;			// ��������
	BPSurfaceShapeData		Surfacedata;	// ��������
	IKS_BOOL					bIsTopological;	// �Ƿ���������
	__tagBPSurface()
	{
		nID = -1;
		nType = BPSURFTYPE_UNKOWN;
		memset(&Surfacedata, 0, sizeof(BPSurfaceShapeData));
		bIsTopological = FALSE;
	}
	__tagBPSurface(const __tagBPSurface &data)
	{
		nID = data.nID;
		nType = data.nType;
		Surfacedata = data.Surfacedata;
		bIsTopological = data.bIsTopological;
	}
	__tagBPSurface &operator=(const __tagBPSurface& data){
		if (&data != this)
		{
			nID = data.nID;
			nType = data.nType;
			Surfacedata = data.Surfacedata;
			bIsTopological = data.bIsTopological;
		}
		return *this;
	}
	IKS_BOOL operator == (const __tagBPSurface &data) const
	{
		if (nID != data.nID)
			return FALSE;
		if (nType != data.nType)
			return FALSE;
		if (bIsTopological != data.bIsTopological)
			return FALSE;
		switch (nType)
		{
		case BPSURFTYPE_PLANE:
			if (!ISFLOAT3EQUAL(Surfacedata.plane.vAxisX, data.Surfacedata.plane.vAxisX))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.plane.vAxisY, data.Surfacedata.plane.vAxisY))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.plane.vAxisZ, data.Surfacedata.plane.vAxisZ))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.plane.vOrigin, data.Surfacedata.plane.vOrigin))
				return FALSE;
			break;
		case BPSURFTYPE_CYLINDER:
			if (!ISFLOAT3EQUAL(Surfacedata.cylinder.vAxisX, data.Surfacedata.cylinder.vAxisX))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.cylinder.vAxisY, data.Surfacedata.cylinder.vAxisY))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.cylinder.vAxisZ, data.Surfacedata.cylinder.vAxisZ))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.cylinder.vOrigin, data.Surfacedata.cylinder.vOrigin))
				return FALSE;
			if (!ISEQUAL(Surfacedata.cylinder.radius, data.Surfacedata.cylinder.radius))
				return FALSE;
			break;
		case BPSURFTYPE_CONE:
			if (!ISFLOAT3EQUAL(Surfacedata.cone.vAxisX, data.Surfacedata.cone.vAxisX))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.cone.vAxisY, data.Surfacedata.cone.vAxisY))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.cone.vAxisZ, data.Surfacedata.cone.vAxisZ))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.cone.vOrigin, data.Surfacedata.cone.vOrigin))
				return FALSE;
			if (!ISEQUAL(Surfacedata.cone.alpha, data.Surfacedata.cone.alpha))
				return FALSE;
			break;
		case BPSURFTYPE_TORUS:
			if (!ISFLOAT3EQUAL(Surfacedata.torus.vAxisX, data.Surfacedata.torus.vAxisX))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.torus.vAxisY, data.Surfacedata.torus.vAxisY))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.torus.vAxisZ, data.Surfacedata.torus.vAxisZ))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.torus.vOrigin, data.Surfacedata.torus.vOrigin))
				return FALSE;
			if (!ISEQUAL(Surfacedata.torus.radius1, data.Surfacedata.torus.radius1))
				return FALSE;
			if (!ISEQUAL(Surfacedata.torus.radius2, data.Surfacedata.torus.radius2))
				return FALSE;
			break;
		case BPSURFTYPE_REVOLVE:
			if (!ISFLOAT3EQUAL(Surfacedata.revolve.vAxisX, data.Surfacedata.revolve.vAxisX))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.revolve.vAxisY, data.Surfacedata.revolve.vAxisY))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.revolve.vAxisZ, data.Surfacedata.revolve.vAxisZ))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.revolve.vOrigin, data.Surfacedata.revolve.vOrigin))
				return FALSE;
			break;
		case BPSURFTYPE_TABCYL:
			if (!ISFLOAT3EQUAL(Surfacedata.tabcyl.vAxisX, data.Surfacedata.tabcyl.vAxisX))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.tabcyl.vAxisY, data.Surfacedata.tabcyl.vAxisY))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.tabcyl.vAxisZ, data.Surfacedata.tabcyl.vAxisZ))
				return FALSE;
			if (!ISFLOAT3EQUAL(Surfacedata.tabcyl.vOrigin, data.Surfacedata.tabcyl.vOrigin))
				return FALSE;
		case BPSURFTYPE_UNKOWN:
			break;
		default:
			ASSERT(FALSE);
			break;
		}
		return TRUE;
	}
	IKS_BOOL operator != (const __tagBPSurface &data) const
	{
		return !(*this == data);
	}
	void Clear()
	{
		nID = -1;
		nType = BPSURFTYPE_UNKOWN;
		memset(&Surfacedata, 0, sizeof(BPSurfaceShapeData));
		bIsTopological = FALSE;
	}
} BPSurface;

//===================================================================================================
// �ṹ�嶨��

// ֱ��
typedef struct __tagBPLineData
{
	BPBASEFLOAT3 end1;		// ���
	BPBASEFLOAT3 end2;		// �յ�
} BPLineData;

// Բ��
typedef struct __tagBPArcData
{
	BPBASEFLOAT3 vOrigin;	// ԭ��
	BPBASEFLOAT3 vVector1;	// First vector that defines the plane of the arc
	BPBASEFLOAT3 vVector2;	// Second vector that defines the plane of the arc
	float fStartAngle;		// Angular parameter of the starting point
	float fEndAngle;		// Angular parameter of the ending point
	float fRadius;			// �뾶
} BPArcData;

// ���ߵ���״����
typedef union __tagBPCurveData
{
	BPLineData				line;			// ֱ��
	BPArcData				arc;			// Բ��
} BPCurveData;

// ����������Ϣ
typedef struct __tagBPCurve
{
	int						nID;			// ����ID
	int						nType;			// ��������
	BPCurveData				curvedata;		// ��������
	IKS_BOOL					bIsTopological;	// �Ƿ���������
	__tagBPCurve()
	{
		nID = -1;
		nType = BPCURVETYPE_UNKOWN;
		memset(&curvedata, 0, sizeof(BPCurveData));
		bIsTopological = FALSE;
	}
	__tagBPCurve(const __tagBPCurve &data)
	{
		nID = data.nID;
		nType = data.nType;
		curvedata = data.curvedata;
		bIsTopological = data.bIsTopological;
	}
	__tagBPCurve &operator=(const __tagBPCurve& data){
		if (&data != this)
		{
			nID = data.nID;
			nType = data.nType;
			curvedata = data.curvedata;
			bIsTopological = data.bIsTopological;
		}
		return *this;
	}
	IKS_BOOL operator == (const __tagBPCurve &data) const
	{
		if (nID != data.nID)
			return FALSE;
		if (nType != data.nType)
			return FALSE;
		if (bIsTopological != data.bIsTopological)
			return FALSE;
		switch (nType)
		{
		case BPCURVETYPE_LINE:
			if (!ISFLOAT3EQUAL(curvedata.line.end1, data.curvedata.line.end1))
				return FALSE;
			if (!ISFLOAT3EQUAL(curvedata.line.end2, data.curvedata.line.end2))
				return FALSE;
			break;
		case BPCURVETYPE_ARC:
			if (!ISFLOAT3EQUAL(curvedata.arc.vOrigin, data.curvedata.arc.vOrigin))
				return FALSE;
			if (!ISFLOAT3EQUAL(curvedata.arc.vVector1, data.curvedata.arc.vVector1))
				return FALSE;
			if (!ISFLOAT3EQUAL(curvedata.arc.vVector2, data.curvedata.arc.vVector2))
				return FALSE;
			if (!ISEQUAL(curvedata.arc.fStartAngle, data.curvedata.arc.fStartAngle))
				return FALSE;
			if (!ISEQUAL(curvedata.arc.fEndAngle, data.curvedata.arc.fEndAngle))
				return FALSE;
			if (!ISEQUAL(curvedata.arc.fRadius, data.curvedata.arc.fRadius))
				return FALSE;
			break;
		case BPCURVETYPE_UNKOWN:
			break;
		default:
			break;
		}
		return TRUE;
	}
	IKS_BOOL operator != (const __tagBPCurve &data) const
	{
		return !(*this == data);
	}
} BPCurve;

//===================================================================================================
// �ṹ�嶨��

// ��άֱ��
typedef struct __tagSVLine2D
{
	BPBASEFLOAT2 start;							// ���
	BPBASEFLOAT2 end;							// �յ�

	__tagSVLine2D()
	{
		start.x = 0.f;
		start.y = 0.f;
		end.x = 0.f;
		end.y = 0.f;
	}
	__tagSVLine2D(const __tagSVLine2D &info)
	{
		start = info.start;
		end = info.end;
	}
	__tagSVLine2D& operator=(const __tagSVLine2D& info)
	{
		if (&info == this)
			return *this;
		start = info.start;
		end = info.end;
		return *this;
	}
} SVLine2D;

// ��άԲ��
typedef struct __tagSVArc2D
{
	BPBASEFLOAT2 center;						// Բ��
	BPBASEFLOAT2 axisX;							// X�������
	float fRadius;								// �뾶
	float fStartAngle;							// ��ʼ��
	float fEndAngle;							// ��ֹ��

	__tagSVArc2D()
	{
		center.x = 0.f;
		center.y = 0.f;
		axisX.x = 1.f;
		axisX.y = 0.f;
		fRadius = 0.f;
		fStartAngle = 0.f;
		fEndAngle = 0.f;
	}
	__tagSVArc2D(const __tagSVArc2D &info)
	{
		center = info.center;
		axisX = info.axisX;
		fRadius = info.fRadius;
		fStartAngle = info.fStartAngle;
		fEndAngle = info.fEndAngle;
	}
	__tagSVArc2D& operator=(const __tagSVArc2D& info)
	{
		if (&info == this)
			return *this;
		center = info.center;
		axisX = info.axisX;
		fRadius = info.fRadius;
		fStartAngle = info.fStartAngle;
		fEndAngle = info.fEndAngle;
		return *this;
	}
} SVArc2D;

// ��ά��������
typedef struct __tagSVPolygon2D
{
	std::vector<BPBASEFLOAT2> arrPoints;		// �㼯

	__tagSVPolygon2D()
	{
	}
	__tagSVPolygon2D(const __tagSVPolygon2D &info)
	{
		arrPoints = info.arrPoints;
	}
	__tagSVPolygon2D& operator=(const __tagSVPolygon2D& info)
	{
		if (&info == this)
			return *this;
		arrPoints = info.arrPoints;
		return *this;
	}
} SVPolygon2D;

// ��ά����������Ϣ
typedef struct __tagSVCurve2D
{
	int nID;						// ��ά����ID
	int nType;						// ��ά��������,�ο�ö����BPCURVE2DTYPE
	union{
		SVLine2D *pLine;			// ֱ��
		SVArc2D *pArc;				// Բ��
		SVPolygon2D *pPolygon;		// �����
	};

	__tagSVCurve2D() 
	{
		nID = -1;
		nType = BP2DCURVETYPE_UNKNOWN;
		pLine = NULL;
	}
	__tagSVCurve2D(const __tagSVCurve2D &data)
	{
		nID = data.nID;
		nType = BP2DCURVETYPE_UNKNOWN;
		pLine = NULL;
		UpdateCurveData(data);
	}
	__tagSVCurve2D& operator=(const __tagSVCurve2D &data) 
	{
		if (this == &data)
			return *this;
		nID = data.nID;
// 		nType = data.nType;
		UpdateCurveData(data);
		return *this;
	}
	~__tagSVCurve2D()
	{
		ClearCurveData();
	}
	void ClearCurveData()
	{
		switch (nType)
		{
		case BP2DCURVETYPE_LINE:
			SAFE_DELETE(pLine);
			break;
		case BP2DCURVETYPE_ARC:
			SAFE_DELETE(pArc);
			break;
		case BP2DCURVETYPE_POLYGON:
			SAFE_DELETE(pPolygon);
			break;
		default:
			SAFE_DELETE(pLine);
			break;
		}
		nType = BP2DCURVETYPE_UNKNOWN;
	}
	void UpdateCurveType(int nNewType)
	{
		if (nNewType == nType)
			return;
		ClearCurveData();
		switch (nNewType)
		{
		case BP2DCURVETYPE_LINE:
			pLine = new SVLine2D;
			break;
		case BP2DCURVETYPE_ARC:
			pArc = new SVArc2D;
			break;
		case BP2DCURVETYPE_POLYGON:
			pPolygon = new SVPolygon2D;
			break;
		default:
			break;
		}
		nType = nNewType;
	}
	void UpdateCurveData(const __tagSVCurve2D &data)
	{
		UpdateCurveType(data.nType);
		switch (nType)
		{
		case BP2DCURVETYPE_LINE:
			*pLine = *data.pLine;
			break;
		case BP2DCURVETYPE_ARC:
			*pArc = *data.pArc;
			break;
		case BP2DCURVETYPE_POLYGON:
			*pPolygon = *data.pPolygon;
			break;
		default:
			break;
		}
	}
} SVCurve2D;

//===================================================================================================
// �ṹ�嶨��

// ����ƽ��ģ����Ϣ
typedef struct __tagSVSecPlaneMdlInfo
{
	std::vector<BPBASEFLOAT3>				_arrVertexData;			// ��������(����λ��)
	std::vector<IKS_DWORD>						_arrIndexData;			// �����飬����3��Ԫ��Ϊһ��(����Ƭ)��2��Ԫ��Ϊһ��(�߶�)

	__tagSVSecPlaneMdlInfo()
	{
	}
	__tagSVSecPlaneMdlInfo(const __tagSVSecPlaneMdlInfo &info)
	{
		_arrVertexData = info._arrVertexData;
		_arrIndexData = info._arrIndexData;
	}
	__tagSVSecPlaneMdlInfo& operator=(const __tagSVSecPlaneMdlInfo& info){
		if (&info == this)
			return *this;
		_arrVertexData = info._arrVertexData;
		_arrIndexData = info._arrIndexData;
		return *this;
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		for (IKS_UINT i=0; i<_arrVertexData.size(); i++)
			_arrVertexData[i] = BPTOCBPFLOAT3(_arrVertexData[i]) * float(dLenRatio);
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		dLenRatio;
	}
} SVSecPlaneMdlInfo;

// ����ƽ����������Ϣ
typedef struct __tagSVSecPlaneContourInfo
{
	std::vector<BPBASEFLOAT3>			_arrVertexData;		// ��������(����λ��)
	std::vector<std::vector<IKS_DWORD >>	_arrIndexData;	// ������(����)������,��������2��Ԫ��Ϊһ���ʾһ���߶�(�����ϱ�Ȼ������������β�����ıպ�����),���ڼ�¼��������������

	__tagSVSecPlaneContourInfo()
	{
	}
	__tagSVSecPlaneContourInfo(const __tagSVSecPlaneContourInfo &info)
	{
		_arrVertexData = info._arrVertexData;
		_arrIndexData = info._arrIndexData;
	}
	__tagSVSecPlaneContourInfo& operator=(const __tagSVSecPlaneContourInfo& info){
		if (&info == this)
			return *this;
		_arrVertexData = info._arrVertexData;
		_arrIndexData = info._arrIndexData;
		return *this;
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		for (IKS_UINT i=0; i<_arrVertexData.size(); i++)
			_arrVertexData[i] = BPTOCBPFLOAT3(_arrVertexData[i]) * float(dLenRatio);
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		dLenRatio;
	}
} SVSecPlaneContourInfo;

// ���н���(ƽ��)Ԫ��������Ϣ
typedef struct __tagSVSecPlaneElemDataInfo
{
	SVSecPlaneContourInfo infoContour;			// ��������Ϣ
	SVSecPlaneMdlInfo mdlSection;				// �����ģ������(����Ƭ)
	SVSecPlaneMdlInfo mdlSectionLine;			// �����ߵ�ģ������(�߶�)
	IKS_UINT uRefObjIndex;							// Ӱ����������
	IKS_UINT uSectionMtlID;							// �������ID
	IKS_UINT uContourMtlID;							// �����߲���ID
	IKS_UINT uSectionLineMtlID;						// �����߲���ID
	// �����ߵ���Ϣ(�����߽Ƕ�,����,��ϸ��)--δʵ��
	__tagSVSecPlaneElemDataInfo()
	{
		uRefObjIndex = INVALID_ID;
		uSectionMtlID = INVALID_ID;
		uContourMtlID = INVALID_ID;
		uSectionLineMtlID = INVALID_ID;
	}
	__tagSVSecPlaneElemDataInfo(const __tagSVSecPlaneElemDataInfo &data)
	{
		infoContour = data.infoContour;
		mdlSection = data.mdlSection;
		mdlSectionLine = data.mdlSectionLine;
		uRefObjIndex = data.uRefObjIndex;
		uSectionMtlID = data.uSectionMtlID;
		uContourMtlID = data.uContourMtlID;
		uSectionLineMtlID = data.uSectionLineMtlID;
	}
	__tagSVSecPlaneElemDataInfo &operator=(const __tagSVSecPlaneElemDataInfo& data){
		if (&data != this)
		{
			infoContour = data.infoContour;
			mdlSection = data.mdlSection;
			mdlSectionLine = data.mdlSectionLine;
			uRefObjIndex = data.uRefObjIndex;
			uSectionMtlID = data.uSectionMtlID;
			uContourMtlID = data.uContourMtlID;
			uSectionLineMtlID = data.uSectionLineMtlID;
		}
		return *this;
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		infoContour.UpdatePosForLenUnit(dLenRatio);
		mdlSection.UpdatePosForLenUnit(dLenRatio);
		mdlSectionLine.UpdatePosForLenUnit(dLenRatio);
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		infoContour.UpdateTextForLenUnit(dLenRatio);
		mdlSection.UpdateTextForLenUnit(dLenRatio);
		mdlSectionLine.UpdateTextForLenUnit(dLenRatio);
	}
} SVSecPlaneElemDataInfo;

// ����ƽ����Ϣ
typedef struct __tagSVSectionPlaneInfo
{
	BPBASEFLOAT3 vOrigin;			// ƽ��ԭ��λ��
	BPBASEFLOAT3 vAxisY;			// ƽ���Y����
	BPBASEFLOAT3 vAxisZ;			// ��ֱ��ƽ��ķ�ʸ����
	IKS_BOOL bShowPlaneMdl;				// ��ʾ����ƽ��ģ��
	float fPlaneMdlRefSize;			// ����ƽ��ģ�Ͳο��ߴ�(�Ǵ洢����)
	std::vector<SVSecPlaneElemDataInfo> arrSecPlaneElemDataInfo;	// ��������(ÿһ�������е�ģ�;���Ӧһ��Ԫ��)
	std::vector<IKS_UINT> arrRefObjID;	// Ӱ������ID

	__tagSVSectionPlaneInfo()
	{
		memset(&vOrigin, 0, sizeof(BPBASEFLOAT3));
		memset(&vAxisY, 0, sizeof(BPBASEFLOAT3));
		memset(&vAxisZ, 0, sizeof(BPBASEFLOAT3));
		bShowPlaneMdl = FALSE;
		fPlaneMdlRefSize = -1.0f;
	}
	__tagSVSectionPlaneInfo(const __tagSVSectionPlaneInfo &info)
	{
		vOrigin = info.vOrigin;
		vAxisY = info.vAxisY;
		vAxisZ = info.vAxisZ;
		bShowPlaneMdl = info.bShowPlaneMdl;
		fPlaneMdlRefSize = info.fPlaneMdlRefSize;
		arrSecPlaneElemDataInfo = info.arrSecPlaneElemDataInfo;
		arrRefObjID = info.arrRefObjID;
	}
	__tagSVSectionPlaneInfo& operator=(const __tagSVSectionPlaneInfo& info){
		if (&info == this)
			return *this;
		vOrigin = info.vOrigin;
		vAxisY = info.vAxisY;
		vAxisZ = info.vAxisZ;
		bShowPlaneMdl = info.bShowPlaneMdl;
		fPlaneMdlRefSize = info.fPlaneMdlRefSize;
		arrSecPlaneElemDataInfo = info.arrSecPlaneElemDataInfo;
		arrRefObjID = info.arrRefObjID;
		return *this;
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		vOrigin = BPTOCBPFLOAT3(vOrigin) * float(dLenRatio);
		fPlaneMdlRefSize *= float(dLenRatio);
		for (IKS_UINT i=0; i<arrSecPlaneElemDataInfo.size(); i++)
			arrSecPlaneElemDataInfo[i].UpdatePosForLenUnit(dLenRatio);
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		for (IKS_UINT i=0; i<arrSecPlaneElemDataInfo.size(); i++)
			arrSecPlaneElemDataInfo[i].UpdateTextForLenUnit(dLenRatio);
	}
} SVSectionPlaneInfo;
