//===================================================================================================
// File:
//		PCLSurface.h
// Summary:
//		����ӿ���
// Date:
//		2016-08-30
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"
#include "PCLCsys.h"

//===================================================================================================

// ƽ������
typedef struct __tagIKSPlaneData
{
	SVDOUBLE3 o;									// ԭ��
	SVDOUBLE3 x;									// X��
	SVDOUBLE3 y;									// Y��
	SVDOUBLE3 z;									// Z��

	__tagIKSPlaneData()
	{
	}
	__tagIKSPlaneData(const __tagIKSPlaneData &data)
	{
		o = data.o;
		x = data.x;
		y = data.y;
		z = data.z;
	}
	__tagIKSPlaneData operator=(const __tagIKSPlaneData &data)
	{
		if (&data == this)
			return *this;
		o = data.o;
		x = data.x;
		y = data.y;
		z = data.z;
		return *this;
	}
}IKSPlaneData;

// ��������
typedef struct __tagIKSCylinderData
{
	SVDOUBLE3 o;									// ԭ��
	SVDOUBLE3 x;									// X��
	SVDOUBLE3 y;									// Y��
	SVDOUBLE3 z;									// Z��
	double r;										// �뾶
	double z_min;									// Z��С
	double z_max;									// Z���

	__tagIKSCylinderData()
	{
		r = 0.0;
		z_min = 0.0;
		z_max = 0.0;
	}
	__tagIKSCylinderData(const __tagIKSCylinderData &data)
	{
		o = data.o;
		x = data.x;
		y = data.y;
		z = data.z;
		r = data.r;
		z_min = data.z_min;
		z_max = data.z_max;
	}
	__tagIKSCylinderData operator=(const __tagIKSCylinderData &data)
	{
		if (&data == this)
			return *this;
		o = data.o;
		x = data.x;
		y = data.y;
		z = data.z;
		r = data.r;
		z_min = data.z_min;
		z_max = data.z_max;
		return *this;
	}
}IKSCylinderData;

// ׶������
typedef struct __tagIKSConeData
{
	SVDOUBLE3 o;									// ԭ��
	SVDOUBLE3 x;									// X��
	SVDOUBLE3 y;									// Y��
	SVDOUBLE3 z;									// Z��
	double a;										// ׶��
	double z_min;									// Z��С
	double z_max;									// Z���

	__tagIKSConeData()
	{
		a = 0.0;
		z_min = 0.0;
		z_max = 0.0;
	}
	__tagIKSConeData(const __tagIKSConeData &data)
	{
		o = data.o;
		x = data.x;
		y = data.y;
		z = data.z;
		a = data.a;
		z_min = data.z_min;
		z_max = data.z_max;
	}
	__tagIKSConeData operator=(const __tagIKSConeData &data)
	{
		if (&data == this)
			return *this;
		o = data.o;
		x = data.x;
		y = data.y;
		z = data.z;
		a = data.a;
		z_min = data.z_min;
		z_max = data.z_max;
		return *this;
	}
}IKSConeData;

// ��������
typedef struct __tagIKSSphereData
{
	SVDOUBLE3 o;									// ԭ��
	SVDOUBLE3 x;									// X��
	SVDOUBLE3 y;									// Y��
	SVDOUBLE3 z;									// Z��
	double r;										// �뾶

	__tagIKSSphereData()
	{
		r = 0.0;
	}
	__tagIKSSphereData(const __tagIKSSphereData &data)
	{
		o = data.o;
		x = data.x;
		y = data.y;
		z = data.z;
		r = data.r;
	}
	__tagIKSSphereData operator=(const __tagIKSSphereData &data)
	{
		if (&data == this)
			return *this;
		o = data.o;
		x = data.x;
		y = data.y;
		z = data.z;
		r = data.r;
		return *this;
	}
}IKSSphereData;

//===================================================================================================

// ����ӿ���
class CPCLSurface : public CPCLFeature
{
public:
	CPCLSurface();
	virtual ~CPCLSurface();
public:

	// ����ѡ����������������ϵ�ľ���λ��
	static BOOL CalcCsysBySelSurface(
		ProSelection pSelSurf,								// ѡ������
		IKSCsysData &csysData								// ����ϵ����
		);
	
	// ��ȡƽ�������
	static BOOL GetPlaneData(
		ProGeomitem &surfItem,								// �������Ŀ(in)
		IKSPlaneData &planeData								// ƽ�������,Z������(���淨��)(out)
		);

	// ��ȡѡ��ƽ������ݣ��������������
	static BOOL GetPlaneData(
		ProSelection pSelPlane,								// ƽ���ѡ�����(in)
		IKSPlaneData &planeData								// ƽ�������,Z������(���淨��)(out)
		);

	// ��ȡ����ѡ�����ķ���
	static BOOL GetSelectionSurfaceNormal(
		ProSelection pSelSurface,							// ����ѡ�����(in)
		SVDOUBLE3 &vNormal									// ������(out)
		);
	
	// ��ȡ�����������
	static BOOL GetCoordsBySysCylinder(
		SVDOUBLE3 &vPoint,									// �ѿ��������(in)
		SVDOUBLE3 &vSysCylPoint								// ��������(out)
		);
	

	// ��ȡ�����������
	static BOOL GetCoordsBySysSphere(
		SVDOUBLE3 &vPoint,									// �ѿ��������(in)
		SVDOUBLE3 &vSysSpherePoint							// ���������(out)
		);

	// �жϵ��Ƿ���ƽ��������
	static BOOL IsPointInPlaneRegion(
		ProGeomitem &surfItem,								// ƽ�����Ŀ(in)
		const SVDOUBLE3 &vPt,								// ��(in)
		IKSPlaneData &planeData								// ƽ�������,Z������(���淨��)(in)
		);
	
	// �жϵ��Ƿ������淶Χ��
	static BOOL IsPointInSurfaceRegion(
		ProPoint3d dPoint,									// ��λ��(in)
		ProGeomitem &surfItem								// ��(in)
		);
	
	// �жϵ��Ƿ�������������Χ��
	static BOOL IsPointInContourRegion(
		ProPoint3d dPoint,									// ��λ��(in)
		ProSolid pSurfOwner,								// ���������ģ��(in)
		ProSurface pSurface,								// ����(in)
		ProContour pContour									// ����
		);
	
	// �жϵ��Ƿ���������
	static BOOL IsPointOnSurface(
		ProPoint3d dPoint,									// ��λ��()
		ProSelection pSelSurface,							// ����ѡ�����()
		ProContour pContour									// ���������()
		);

	// �жϵ��Ƿ���������
	static BOOL IsPointOnSurface(
		ProSelection pSelPoint,								// ��λ��()
		ProSelection pSelSurface,							// ����ѡ�����()
		ProContour pContour									// ���������()
		);	

	// �ж�����ϵ�Ƿ�λ����������Χ��
	static BOOL IsCsysInSurfaceRegion(
		ProSelection pSelCsys,								// ����ϵѡ�����(in)
		ProSelection pSelSurface							// ����ѡ�����(in)
		);
	
	// ��ȡ���������
	static CString GetSurfaceDesc(
		ProGeomitem &surfItem								// ������Ŀ(in)
		);

	// ��ȡ����ѡ�����ָ�������
	static BOOL GetSurfaceContour(
		ProSelection pSelSurface,							// ����ѡ�����(in)
		ProContour &pContour								// ����(out)
		);
	
	// ��ȡ���������(�ֲ�����ϵ)
	static BOOL GetCylinderData(
		ProGeomitem &surfItem,								// �������Ŀ(in)
		IKSCylinderData &cylinderData						// ���������(out)
		);

	// ��ȡѡ����������ݣ��������������
	static BOOL GetCylinderData(
		ProSelection pSelCylinder,							// �����ѡ�����(in)
		IKSCylinderData &cylinderData						// ���������(out)
		);

	// ��ȡ׶�������(�ֲ�����)
	static BOOL GetConeData(
		ProGeomitem &surfItem,								// ׶�����Ŀ(in)
		IKSConeData &coneData								// ׶�������(out)
		);

	// ��ȡѡ��׶������ݣ��������������
	static BOOL GetConeData(
		ProSelection pSelCone,								// ׶���ѡ�����(in)
		IKSConeData &coneData								// ׶�������(out)
		);

	// ��ȡԲ���������(�ֲ�����)
	static BOOL GetTorusData(
		ProGeomitem &surfItem,								// Բ�������Ŀ(in)
		SVDOUBLE3 &origin,									// ԭ���λ��(out)
		SVDOUBLE3 &x,										// X������(out)
		SVDOUBLE3 &y,										// Y������(out)
		SVDOUBLE3 &z,										// Z������(out)
		double &dRadius1,									// �켣�뾶(out)
		double &dRadius2									// ����뾶(out)
		);

	// ��ȡѡ��Բ��������ݣ��������������
	static BOOL GetTorusData(
		ProSelection pSelTorus,								// Բ�����ѡ�����(in)
		SVDOUBLE3 &origin,									// ԭ���λ��(out)
		SVDOUBLE3 &x,										// X������(out)
		SVDOUBLE3 &y,										// Y������(out)
		SVDOUBLE3 &z,										// Z������(out)
		double &dRadius1,									// �켣�뾶(out)
		double &dRadius2									// ����뾶(out)
		);

	// ��ȡ���������
	static BOOL GetSphereData(
		ProGeomitem &surfItem,								// �������Ŀ(in)
		IKSSphereData &sphereData							// ���������(out)
		);

	// ��ȡѡ����������ݣ��������������
	static BOOL GetSphereData(
		ProSelection pSelSphere,							// �����ѡ�����(in)
		IKSSphereData &sphereData							// ���������(out)
		);
private:
	// ��ȡ����ָ�������ı�����������
	static ProError GetSurfaceContourVisitAction(ProContour pContour, ProError status, ProAppData pAppData);
};

//===================================================================================================
 