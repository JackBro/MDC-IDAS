//===================================================================================================
// Summary:
//		标注几何定义
// Date:
//		2015-07-31			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSGeom_h__
#define __IKSGeom_h__

//===================================================================================================

#include "IKSConst.h"
#include "IKSMath.h"

//===================================================================================================

// 曲线类型
typedef enum __tagIKSCurveType
{
	IKSCURVETYPE_UNKNOWN			= 0,		// 未知曲线
	IKSCURVETYPE_LINE				= 1,		// 直线
	IKSCURVETYPE_ARC				= 2,		// 圆弧
	IKSCURVETYPE_POLYGON			= 3,		// 多边形
} IKSCurveType;

// 线型
typedef enum __tagIKSLineType
{
	IKSLINETYPE_UNKNOWN			= 0,			// 未知线型
	IKSLINETYPE_HEAVYLINE		= 1,			// 粗实线
	IKSLINETYPE_FINELINE		= 2,			// 细实线
} IKSLineType;

//===================================================================================================

// 直线
typedef struct __tagIKSLine
{
	IKSDouble3 start;							// 起点
	IKSDouble3 end;								// 终点

	__tagIKSLine()
	{
		memset(this, 0, sizeof(__tagIKSLine));
	}
	__tagIKSLine(const __tagIKSLine &line)
	{
		memcpy_s(this, sizeof(__tagIKSLine), &line, sizeof(__tagIKSLine));
	}
	__tagIKSLine& operator=(const __tagIKSLine& line)
	{
		if (&line == this)
			return *this;
		memcpy_s(this, sizeof(__tagIKSLine), &line, sizeof(__tagIKSLine));
		return *this;
	}
} IKSLine;

// 圆弧
typedef struct __tagIKSArc
{
	IKSDouble3 center;							// 圆心
	IKSDouble3 axisX;							// X轴的向量
	double dRadius;								// 半径
	double dStartAngle;							// 起始角
	double dEndAngle;							// 终止角

	__tagIKSArc()
	{
		center[0] = center[1] = center[2] = 0.;
		axisX[0] = 1.0;axisX[1] = axisX[2] = 0.;
		dRadius = 0.;
		dStartAngle = 0.;
		dEndAngle = 0.;
	}
	__tagIKSArc(const __tagIKSArc &arc)
	{
		memcpy_s(this, sizeof(__tagIKSArc), &arc, sizeof(__tagIKSArc));
	}
	__tagIKSArc& operator=(const __tagIKSArc& arc)
	{
		if (&arc == this)
			return *this;
		memcpy_s(this, sizeof(__tagIKSArc), &arc, sizeof(__tagIKSArc));
		return *this;
	}
} IKSArc;

// 多边形
typedef struct __tagIKSPolygon
{
	IKSDouble3 *arrPoints;						// 点集
	int nSize;									// 点个数

	__tagIKSPolygon()
	{
		arrPoints = NULL;
		nSize = -1;
	}
	~__tagIKSPolygon()
	{
		IKS_SAFE_DELETE_ARRAY(arrPoints);
		nSize = -1;
	}
	__tagIKSPolygon(const __tagIKSPolygon &polygon)
	{
		if (polygon.nSize > 0)
		{
			IKS_SAFE_DELETE_ARRAY(arrPoints);
			arrPoints = new IKSDouble3[polygon.nSize];
			nSize = polygon.nSize;
			memcpy_s(arrPoints, sizeof(IKSDouble3)*nSize, polygon.arrPoints, sizeof(IKSDouble3)*nSize);
		}
	}
	__tagIKSPolygon& operator=(const __tagIKSPolygon& polygon)
	{
		if (&polygon == this)
			return *this;
		if (polygon.nSize > 0)
		{
			IKS_SAFE_DELETE_ARRAY(arrPoints);
			arrPoints = new IKSDouble3[polygon.nSize];
			nSize = polygon.nSize;
			memcpy_s(arrPoints, sizeof(IKSDouble3)*nSize, polygon.arrPoints, sizeof(IKSDouble3)*nSize);
		}
		return *this;
	}
} IKSPolygon;

// 二维曲线数据信息
typedef struct __tagIKSCurve
{
	int nID;									// 二维曲线ID
	int nType;									// 二维曲线类型,参看枚举型IKSCURVETYPE
	int nLineStyle;								// 线型
	union{
		IKSLine *pLine;							// 直线
		IKSArc *pArc;							// 圆弧
		IKSPolygon *pPolygon;					// 多边形
	};

	__tagIKSCurve() 
	{
		nID = -1;
		nType = IKSCURVETYPE_UNKNOWN;
		nLineStyle = IKSLINETYPE_UNKNOWN;
		pLine = NULL;
	}
	__tagIKSCurve(const __tagIKSCurve &data)
	{
		nID = data.nID;
		nType = IKSCURVETYPE_UNKNOWN;
		nLineStyle = data.nLineStyle;
		pLine = NULL;
		UpdateCurveData(data);
	}
	__tagIKSCurve& operator=(const __tagIKSCurve &data) 
	{
		if (this == &data)
			return *this;
		nID = data.nID;
		nLineStyle = data.nLineStyle;
		UpdateCurveData(data);
		return *this;
	}
	~__tagIKSCurve()
	{
		ClearCurveData();
	}
	void ClearCurveData()
	{
		switch (nType)
		{
		case IKSCURVETYPE_LINE:
			IKS_SAFE_DELETE_POINTER(pLine);
			break;
		case IKSCURVETYPE_ARC:
			IKS_SAFE_DELETE_POINTER(pArc);
			break;
		case IKSCURVETYPE_POLYGON:
			IKS_SAFE_DELETE_POINTER(pPolygon);
			break;
		default:
			IKS_SAFE_DELETE_POINTER(pLine);
			break;
		}
		nType = IKSCURVETYPE_UNKNOWN;
	}
	void UpdateCurveType(int nNewType)
	{
		if (nNewType == nType)
			return;
		ClearCurveData();
		switch (nNewType)
		{
		case IKSCURVETYPE_LINE:
			pLine = new IKSLine;
			break;
		case IKSCURVETYPE_ARC:
			pArc = new IKSArc;
			break;
		case IKSCURVETYPE_POLYGON:
			pPolygon = new IKSPolygon;
			break;
		default:
			break;
		}
		nType = nNewType;
	}
	void UpdateCurveData(const __tagIKSCurve &data)
	{
		UpdateCurveType(data.nType);
		switch (nType)
		{
		case IKSCURVETYPE_LINE:
			*pLine = *data.pLine;
			break;
		case IKSCURVETYPE_ARC:
			*pArc = *data.pArc;
			break;
		case IKSCURVETYPE_POLYGON:
			*pPolygon = *data.pPolygon;
			break;
		default:
			break;
		}
	}
} IKSCurve;

typedef vector<IKSCurve> IKSCurveArray;

// 平移曲线
void IKSMoveCurve(IKSCurve &curve, IKSDouble3 move);

// 镜像曲线
void IKSMirrorCurve(IKSCurve &curve, IKSDouble3 mirrorPt, IKSDouble3 mirrorDir);

// 旋转曲线（角度为弧度单位）
void IKSRotateCurve(IKSCurve &curve, IKSDouble3 origin, double dAngle);

// 平移包围盒
void IKSMoveBox(IKSBox box, IKSDouble3 move);

// 合并包围盒
void IKSMergeBox(IKSBox box1, IKSBox box2, IKSBox newBox);

// 获取新的几何ID
int GetNewGeomID();

//===================================================================================================

#endif