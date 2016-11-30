//===================================================================================================
// File:
//		SVGeomDef.h
// Summary:
//		Define Geometry class/struct, enum, macro and so on.
// Usage:
//		定义几何的数据；用于定义其他数据结构。
// Remarks:
//		Null
// Date:
//		2012-7-19
// Author:
//		Shiping Wang
//===================================================================================================

#pragma once

//===================================================================================================

// 头文件
#include <vector>
#include "SVBaseDef.h"


//===================================================================================================
// 数学常量


//===================================================================================================
// 宏定义


//===================================================================================================
// 枚举类型定义

// 面类型
typedef enum _BPSURFACETYPE
{
	BPSURFTYPE_UNKOWN			= 0,	// 未知面
	BPSURFTYPE_PLANE			= 1,	// 平面
	BPSURFTYPE_CYLINDER			= 2,	// 圆柱面
	BPSURFTYPE_CONE				= 3,	// 圆锥面
	BPSURFTYPE_TORUS			= 4,	// 圆环面
	BPSURFTYPE_REVOLVE			= 5,	// 旋转面
	BPSURFTYPE_TABCYL			= 6,	// 列表柱面
} BPSURFACETYPE;

// 曲线类型
typedef enum _BPCURVETYPE
{
	BPCURVETYPE_UNKOWN			= 0,	// 未知曲线
	BPCURVETYPE_LINE			= 1,	// 直线
	BPCURVETYPE_ARC				= 2,	// 圆弧
} BPCURVETYPE;

// 二维曲线类型
typedef enum _BPCURVE2DTYPE
{
	BP2DCURVETYPE_UNKNOWN			= 0,	// 未知曲线
	BP2DCURVETYPE_LINE				= 1,	// 直线
	BP2DCURVETYPE_ARC				= 2,	// 圆弧
	BP2DCURVETYPE_POLYGON			= 3,	// 多边形
} BPCURVE2DTYPE;

//===================================================================================================
// 结构体定义

// 平面
typedef struct __tagBPPlaneData
{
	BPBASEFLOAT3 vAxisX;
	BPBASEFLOAT3 vAxisY;
	BPBASEFLOAT3 vAxisZ;	// 垂直于面的法矢方向
	BPBASEFLOAT3 vOrigin;	// 原点
} BPPlaneData;

// 圆柱面
typedef struct __tagBPCylinderData
{
	BPBASEFLOAT3 vAxisX;
	BPBASEFLOAT3 vAxisY;
	BPBASEFLOAT3 vAxisZ;	// 垂直于面的法矢方向
	BPBASEFLOAT3 vOrigin;	// 原点
	float radius;			// 底圆半径
} BPCylinderData;

// 圆锥面
typedef struct __tagBPConeData
{
	BPBASEFLOAT3 vAxisX;
	BPBASEFLOAT3 vAxisY;
	BPBASEFLOAT3 vAxisZ;	// 垂直于面的法矢方向
	BPBASEFLOAT3 vOrigin;	// 原点
	float alpha;			// Angle between the axis of the cone and the generating line
} BPConeData;

// 圆环面
typedef struct __tagBPTorusData
{
	BPBASEFLOAT3 vAxisX;
	BPBASEFLOAT3 vAxisY;
	BPBASEFLOAT3 vAxisZ;	// 垂直于面的法矢方向
	BPBASEFLOAT3 vOrigin;	// 原点
	float radius1;			// Distance from the center of the generating arc to the axis of revolution
	float radius2;			// Radius of the generating arc
} BPTorusData;

// 旋转面
typedef struct __tagBPRevolveData
{
	BPBASEFLOAT3 vAxisX;
	BPBASEFLOAT3 vAxisY;
	BPBASEFLOAT3 vAxisZ;	// 垂直于面的法矢方向
	BPBASEFLOAT3 vOrigin;	// 原点
	// 此处忽略样条曲线spline的方程数据
} BPRevolveData;

// 列表柱面
typedef struct __tagBPTabCylData
{
	BPBASEFLOAT3 vAxisX;
	BPBASEFLOAT3 vAxisY;
	BPBASEFLOAT3 vAxisZ;	// 垂直于面的法矢方向
	BPBASEFLOAT3 vOrigin;	// 原点
	// 此处忽略曲线的方程数据
} BPTabCylData;

// 面的形状数据
typedef union __tagBPSurfaceShapeData
{
	BPPlaneData				plane;			// 平面
	BPCylinderData			cylinder;		// 圆柱面
	BPConeData				cone;			// 圆锥面
	BPTorusData				torus;			// 圆环面
	BPRevolveData			revolve;		// 旋转面
	BPTabCylData			tabcyl;			// 列表柱面
} BPSurfaceShapeData;

// 曲面数据信息
typedef struct __tagBPSurface
{
	int						nID;			// 曲面ID
	int						nType;			// 曲面类型
	BPSurfaceShapeData		Surfacedata;	// 曲面数据
	IKS_BOOL					bIsTopological;	// 是否拓扑曲面
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
// 结构体定义

// 直线
typedef struct __tagBPLineData
{
	BPBASEFLOAT3 end1;		// 起点
	BPBASEFLOAT3 end2;		// 终点
} BPLineData;

// 圆弧
typedef struct __tagBPArcData
{
	BPBASEFLOAT3 vOrigin;	// 原点
	BPBASEFLOAT3 vVector1;	// First vector that defines the plane of the arc
	BPBASEFLOAT3 vVector2;	// Second vector that defines the plane of the arc
	float fStartAngle;		// Angular parameter of the starting point
	float fEndAngle;		// Angular parameter of the ending point
	float fRadius;			// 半径
} BPArcData;

// 曲线的形状数据
typedef union __tagBPCurveData
{
	BPLineData				line;			// 直线
	BPArcData				arc;			// 圆弧
} BPCurveData;

// 曲线数据信息
typedef struct __tagBPCurve
{
	int						nID;			// 曲线ID
	int						nType;			// 曲线类型
	BPCurveData				curvedata;		// 曲线数据
	IKS_BOOL					bIsTopological;	// 是否拓扑曲线
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
// 结构体定义

// 二维直线
typedef struct __tagSVLine2D
{
	BPBASEFLOAT2 start;							// 起点
	BPBASEFLOAT2 end;							// 终点

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

// 二维圆弧
typedef struct __tagSVArc2D
{
	BPBASEFLOAT2 center;						// 圆心
	BPBASEFLOAT2 axisX;							// X轴的向量
	float fRadius;								// 半径
	float fStartAngle;							// 起始角
	float fEndAngle;							// 终止角

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

// 二维多边形填充
typedef struct __tagSVPolygon2D
{
	std::vector<BPBASEFLOAT2> arrPoints;		// 点集

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

// 二维曲线数据信息
typedef struct __tagSVCurve2D
{
	int nID;						// 二维曲线ID
	int nType;						// 二维曲线类型,参看枚举型BPCURVE2DTYPE
	union{
		SVLine2D *pLine;			// 直线
		SVArc2D *pArc;				// 圆弧
		SVPolygon2D *pPolygon;		// 多边形
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
// 结构体定义

// 剖切平面模型信息
typedef struct __tagSVSecPlaneMdlInfo
{
	std::vector<BPBASEFLOAT3>				_arrVertexData;			// 顶点数据(顶点位置)
	std::vector<IKS_DWORD>						_arrIndexData;			// 索引组，组内3个元素为一组(三角片)或2个元素为一组(线段)

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

// 剖切平面轮廓线信息
typedef struct __tagSVSecPlaneContourInfo
{
	std::vector<BPBASEFLOAT3>			_arrVertexData;		// 顶点数据(顶点位置)
	std::vector<std::vector<IKS_DWORD >>	_arrIndexData;	// 轮廓线(折线)索引组,组内相邻2个元素为一组表示一条线段(理论上必然是首索引等于尾索引的闭合曲线),组内记录多条内外轮廓线

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

// 剖切截面(平面)元素数据信息
typedef struct __tagSVSecPlaneElemDataInfo
{
	SVSecPlaneContourInfo infoContour;			// 轮廓线信息
	SVSecPlaneMdlInfo mdlSection;				// 截面的模型数据(三角片)
	SVSecPlaneMdlInfo mdlSectionLine;			// 剖面线的模型数据(线段)
	IKS_UINT uRefObjIndex;							// 影响的物件索引
	IKS_UINT uSectionMtlID;							// 截面材质ID
	IKS_UINT uContourMtlID;							// 轮廓线材质ID
	IKS_UINT uSectionLineMtlID;						// 剖面线材质ID
	// 剖面线的信息(剖面线角度,疏密,粗细等)--未实现
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

// 剖切平面信息
typedef struct __tagSVSectionPlaneInfo
{
	BPBASEFLOAT3 vOrigin;			// 平面原点位置
	BPBASEFLOAT3 vAxisY;			// 平面的Y方向
	BPBASEFLOAT3 vAxisZ;			// 垂直于平面的法矢方向
	IKS_BOOL bShowPlaneMdl;				// 显示剖切平面模型
	float fPlaneMdlRefSize;			// 剖切平面模型参考尺寸(非存储数据)
	std::vector<SVSecPlaneElemDataInfo> arrSecPlaneElemDataInfo;	// 截面数据(每一个被剖切的模型均对应一个元素)
	std::vector<IKS_UINT> arrRefObjID;	// 影响的物件ID

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
