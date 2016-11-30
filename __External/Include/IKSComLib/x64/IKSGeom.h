//===================================================================================================
// Summary:
//		��ע���ζ���
// Date:
//		2015-07-31			����
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSGeom_h__
#define __IKSGeom_h__

//===================================================================================================

#include "IKSConst.h"
#include "IKSMath.h"

//===================================================================================================

// ��������
typedef enum __tagIKSCurveType
{
	IKSCURVETYPE_UNKNOWN			= 0,		// δ֪����
	IKSCURVETYPE_LINE				= 1,		// ֱ��
	IKSCURVETYPE_ARC				= 2,		// Բ��
	IKSCURVETYPE_POLYGON			= 3,		// �����
} IKSCurveType;

// ����
typedef enum __tagIKSLineType
{
	IKSLINETYPE_UNKNOWN			= 0,			// δ֪����
	IKSLINETYPE_HEAVYLINE		= 1,			// ��ʵ��
	IKSLINETYPE_FINELINE		= 2,			// ϸʵ��
} IKSLineType;

//===================================================================================================

// ֱ��
typedef struct __tagIKSLine
{
	IKSDouble3 start;							// ���
	IKSDouble3 end;								// �յ�

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

// Բ��
typedef struct __tagIKSArc
{
	IKSDouble3 center;							// Բ��
	IKSDouble3 axisX;							// X�������
	double dRadius;								// �뾶
	double dStartAngle;							// ��ʼ��
	double dEndAngle;							// ��ֹ��

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

// �����
typedef struct __tagIKSPolygon
{
	IKSDouble3 *arrPoints;						// �㼯
	int nSize;									// �����

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

// ��ά����������Ϣ
typedef struct __tagIKSCurve
{
	int nID;									// ��ά����ID
	int nType;									// ��ά��������,�ο�ö����IKSCURVETYPE
	int nLineStyle;								// ����
	union{
		IKSLine *pLine;							// ֱ��
		IKSArc *pArc;							// Բ��
		IKSPolygon *pPolygon;					// �����
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

// ƽ������
void IKSMoveCurve(IKSCurve &curve, IKSDouble3 move);

// ��������
void IKSMirrorCurve(IKSCurve &curve, IKSDouble3 mirrorPt, IKSDouble3 mirrorDir);

// ��ת���ߣ��Ƕ�Ϊ���ȵ�λ��
void IKSRotateCurve(IKSCurve &curve, IKSDouble3 origin, double dAngle);

// ƽ�ư�Χ��
void IKSMoveBox(IKSBox box, IKSDouble3 move);

// �ϲ���Χ��
void IKSMergeBox(IKSBox box1, IKSBox box2, IKSBox newBox);

// ��ȡ�µļ���ID
int GetNewGeomID();

//===================================================================================================

#endif