//===================================================================================================
// File:
//		PCLSurface.h
// Summary:
//		曲面接口类
// Date:
//		2016-08-30
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"
#include "PCLCsys.h"

//===================================================================================================

// 平面数据
typedef struct __tagIKSPlaneData
{
	SVDOUBLE3 o;									// 原点
	SVDOUBLE3 x;									// X轴
	SVDOUBLE3 y;									// Y轴
	SVDOUBLE3 z;									// Z轴

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

// 柱面数据
typedef struct __tagIKSCylinderData
{
	SVDOUBLE3 o;									// 原点
	SVDOUBLE3 x;									// X轴
	SVDOUBLE3 y;									// Y轴
	SVDOUBLE3 z;									// Z轴
	double r;										// 半径
	double z_min;									// Z最小
	double z_max;									// Z最大

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

// 锥面数据
typedef struct __tagIKSConeData
{
	SVDOUBLE3 o;									// 原点
	SVDOUBLE3 x;									// X轴
	SVDOUBLE3 y;									// Y轴
	SVDOUBLE3 z;									// Z轴
	double a;										// 锥角
	double z_min;									// Z最小
	double z_max;									// Z最大

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

// 球面数据
typedef struct __tagIKSSphereData
{
	SVDOUBLE3 o;									// 原点
	SVDOUBLE3 x;									// X轴
	SVDOUBLE3 y;									// Y轴
	SVDOUBLE3 z;									// Z轴
	double r;										// 半径

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

// 曲面接口类
class CPCLSurface : public CPCLFeature
{
public:
	CPCLSurface();
	virtual ~CPCLSurface();
public:

	// 根据选择曲面对象计算坐标系的绝对位置
	static BOOL CalcCsysBySelSurface(
		ProSelection pSelSurf,								// 选择曲面
		IKSCsysData &csysData								// 坐标系数据
		);
	
	// 获取平面的数据
	static BOOL GetPlaneData(
		ProGeomitem &surfItem,								// 曲面的项目(in)
		IKSPlaneData &planeData								// 平面的数据,Z轴向量(曲面法向)(out)
		);

	// 获取选择平面的数据，相对于世界坐标
	static BOOL GetPlaneData(
		ProSelection pSelPlane,								// 平面的选择对象(in)
		IKSPlaneData &planeData								// 平面的数据,Z轴向量(曲面法向)(out)
		);

	// 获取曲面选择对象的法向
	static BOOL GetSelectionSurfaceNormal(
		ProSelection pSelSurface,							// 曲面选择对象(in)
		SVDOUBLE3 &vNormal									// 法向量(out)
		);
	
	// 获取点的柱面坐标
	static BOOL GetCoordsBySysCylinder(
		SVDOUBLE3 &vPoint,									// 笛卡尔坐标点(in)
		SVDOUBLE3 &vSysCylPoint								// 柱面坐标(out)
		);
	

	// 获取点的球面坐标
	static BOOL GetCoordsBySysSphere(
		SVDOUBLE3 &vPoint,									// 笛卡尔坐标点(in)
		SVDOUBLE3 &vSysSpherePoint							// 球面坐标点(out)
		);

	// 判断点是否在平面区域内
	static BOOL IsPointInPlaneRegion(
		ProGeomitem &surfItem,								// 平面的项目(in)
		const SVDOUBLE3 &vPt,								// 点(in)
		IKSPlaneData &planeData								// 平面的数据,Z轴向量(曲面法向)(in)
		);
	
	// 判断点是否在曲面范围内
	static BOOL IsPointInSurfaceRegion(
		ProPoint3d dPoint,									// 点位置(in)
		ProGeomitem &surfItem								// 面(in)
		);
	
	// 判断点是否在曲面轮廓范围内
	static BOOL IsPointInContourRegion(
		ProPoint3d dPoint,									// 点位置(in)
		ProSolid pSurfOwner,								// 曲面的所属模型(in)
		ProSurface pSurface,								// 曲面(in)
		ProContour pContour									// 轮廓
		);
	
	// 判断点是否在曲面上
	static BOOL IsPointOnSurface(
		ProPoint3d dPoint,									// 点位置()
		ProSelection pSelSurface,							// 曲面选择对象()
		ProContour pContour									// 曲面的轮廓()
		);

	// 判断点是否在曲面上
	static BOOL IsPointOnSurface(
		ProSelection pSelPoint,								// 点位置()
		ProSelection pSelSurface,							// 曲面选择对象()
		ProContour pContour									// 曲面的轮廓()
		);	

	// 判断坐标系是否位于曲面区域范围内
	static BOOL IsCsysInSurfaceRegion(
		ProSelection pSelCsys,								// 坐标系选择对象(in)
		ProSelection pSelSurface							// 曲面选择对象(in)
		);
	
	// 获取曲面的描述
	static CString GetSurfaceDesc(
		ProGeomitem &surfItem								// 曲面项目(in)
		);

	// 获取曲面选择对象指向的轮廓
	static BOOL GetSurfaceContour(
		ProSelection pSelSurface,							// 曲面选择对象(in)
		ProContour &pContour								// 轮廓(out)
		);
	
	// 获取柱面的数据(局部坐标系)
	static BOOL GetCylinderData(
		ProGeomitem &surfItem,								// 柱面的项目(in)
		IKSCylinderData &cylinderData						// 柱面的数据(out)
		);

	// 获取选择柱面的数据，相对于世界坐标
	static BOOL GetCylinderData(
		ProSelection pSelCylinder,							// 柱面的选择对象(in)
		IKSCylinderData &cylinderData						// 柱面的数据(out)
		);

	// 获取锥面的数据(局部坐标)
	static BOOL GetConeData(
		ProGeomitem &surfItem,								// 锥面的项目(in)
		IKSConeData &coneData								// 锥面的数据(out)
		);

	// 获取选择锥面的数据，相对于世界坐标
	static BOOL GetConeData(
		ProSelection pSelCone,								// 锥面的选择对象(in)
		IKSConeData &coneData								// 锥面的数据(out)
		);

	// 获取圆环面的数据(局部坐标)
	static BOOL GetTorusData(
		ProGeomitem &surfItem,								// 圆环面的项目(in)
		SVDOUBLE3 &origin,									// 原点的位置(out)
		SVDOUBLE3 &x,										// X轴向量(out)
		SVDOUBLE3 &y,										// Y轴向量(out)
		SVDOUBLE3 &z,										// Z轴向量(out)
		double &dRadius1,									// 轨迹半径(out)
		double &dRadius2									// 截面半径(out)
		);

	// 获取选择圆环面的数据，相对于世界坐标
	static BOOL GetTorusData(
		ProSelection pSelTorus,								// 圆环面的选择对象(in)
		SVDOUBLE3 &origin,									// 原点的位置(out)
		SVDOUBLE3 &x,										// X轴向量(out)
		SVDOUBLE3 &y,										// Y轴向量(out)
		SVDOUBLE3 &z,										// Z轴向量(out)
		double &dRadius1,									// 轨迹半径(out)
		double &dRadius2									// 截面半径(out)
		);

	// 获取球面的数据
	static BOOL GetSphereData(
		ProGeomitem &surfItem,								// 球面的项目(in)
		IKSSphereData &sphereData							// 球面的数据(out)
		);

	// 获取选择球面的数据，相对于世界坐标
	static BOOL GetSphereData(
		ProSelection pSelSphere,							// 球面的选择对象(in)
		IKSSphereData &sphereData							// 球面的数据(out)
		);
private:
	// 获取曲面指向轮廓的遍历动作函数
	static ProError GetSurfaceContourVisitAction(ProContour pContour, ProError status, ProAppData pAppData);
};

//===================================================================================================
 