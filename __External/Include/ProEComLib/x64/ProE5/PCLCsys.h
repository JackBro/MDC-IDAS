//===================================================================================================
// File:
//		PCLCsys.h
// Summary:
//		坐标系接口类
// Date:
//		2016-08-27
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================

// 坐标系数据
typedef struct __tagIKSCsysData
{
	SVDOUBLE3 o;									// 原点
	SVDOUBLE3 x;									// X轴
	SVDOUBLE3 y;									// Y轴
	SVDOUBLE3 z;									// Z轴

	__tagIKSCsysData()
	{
		memset(this, 0, sizeof(__tagIKSCsysData));
		x.x = y.y = z.z = 1.0;
	}
	__tagIKSCsysData(const __tagIKSCsysData &data)
	{
		o = data.o;
		x = data.x;
		y = data.y;
		z = data.z;
	}
	__tagIKSCsysData operator=(const __tagIKSCsysData &data)
	{
		if (&data == this)
			return *this;
		o = data.o;
		x = data.x;
		y = data.y;
		z = data.z;
		return *this;
	}
}IKSCsysData;

//===================================================================================================

// 复制几何接口类
class CPCLCsys : public CPCLFeature
{
public:
	CPCLCsys();
	virtual ~CPCLCsys();

public:

	// 获取模型的默认参考坐标系
	static BOOL GetSolidDefaultCsys(
		ProSolid pSld,														// 参考实体(in)
		ProCsys &pDefaultCsys												// 默认参考坐标系(out)
		);

	// 获取坐标系特征的参考坐标系
	static BOOL GetCsysRefCsys(
		ProSelection pSelCsysFeature,										// 坐标系(in)
		ProSelection &pSelRefCsys											// 参考坐标系(out)
		);

	// 获取元件特征的参考坐标系
	static BOOL GetAsmcompRefCsys(
		ProAsmcomp &asmcomp,												// 元件特征(in)
		ProGeomitem &refCsysItem											// 装配参考坐标系(out)
		);

	// 获取坐标系的参考坐标系
	static BOOL GetCsysRefCsys(
		ProGeomitem &csysItem,												// 坐标系(in)
		ProGeomitem &refCsysItem											// 参考坐标系(out)
		);

	// 根据坐标系获取坐标系数据,(非世界坐标系)
	static BOOL GetCsysData(
		ProModelitem &csysItem,												// 坐标系的项目(in)
		IKSCsysData &csysData												// 坐标系数据(out)
		);

	// 获取选择坐标系的数据，相对于世界坐标
	static BOOL GetCsysData(
		ProSelection pSelCsys,												// 坐标系的选择对象(in)
		IKSCsysData &csysData												// 坐标系数据(out)
		);

	// 生成缺省坐标系
	static BOOL CreateDefaultCSys(
		ProSolid pSld,														// 坐标系所在模型(in)
		const CString &strUDFPath,											// UDF路径(in)
		ProName szCsysName,													// 坐标系名(in)
		ProFeature &newCsysFeature											// 新的坐标系特征(out)
		);

	// 创建坐标系
	static BOOL CreatCsysByOffset(
		ProSelection pSelMdl,												// 选择的模型(in)
		ProSelection pSelRefCsys,											// 参考坐标系(in)
		const double &dMoveX,const double &dMoveY, const double &dMoveZ,	// x, y, z 的偏移量(in)
		const double &dRotX, const double &dRotY, const double &dRotZ,		// x, y, z 轴的旋转角(in)
		ProFeature &newCsysFeature											// 生成的坐标系(out)
		);

	// 根据坐标系的位置和基准坐标系，生成新的坐标系
	static BOOL CreateCSys(
		const IKSCsysData &newCsysData,										// 新坐标系数据，原点位置，x、y、z轴方向向量(in)
		ProSelection pSelSld,												// 坐标系所在模型(in)
		ProSelection pSelDatumCsys,											// 选择的参考坐标系(in)
		ProName szCsysName,													// 坐标系名(in)
		ProFeature &newCsysFeature											// 新的坐标系特征(out)
		);

	// 根据坐标系的位置，修正(*以坐标系为参考建立的*)坐标系
	static BOOL ModifyCSys(
		ProSelection pSelCsys,												// 坐标系选择对象
		IKSCsysData &csysData												// 坐标系数据(in)
		);

	// 得到源坐标系向目标坐标系转换的平移量和旋转角度
	static BOOL GetCsysMoveParam(
		const IKSCsysData &srcCsysData,										// 源坐标系数据(in)
		const IKSCsysData &destCsysData,									// 目标坐标系数据(in)
		double &dXMove, double &dYMove, double &dZMove,						// x,y,z平移量(out)
		double &dRotX, double &dRotY, double &dRotZ							// x,y,z旋转角度(out)
		);

protected:

	// 通过x,y,z轴的偏移和旋转修改(*以坐标系为参考建立的*)坐标系
	static BOOL ModifyCsysByOffset(
		ProSelection pSelCsysFeature,										// 选择的坐标系(in)
		const double &dMoveX,const double &dMoveY,const double &dMoveZ,		// x,y,z轴的偏移量(in)
		const double &dRotX,const double &dRotY,const double &dRotZ			// 沿x,y,z轴的旋转角(in)
		);

	// 通过偏置尺寸修正坐标系
	static BOOL ModifyCsysByOffsetByDimension(
		ProSelection pSelCsysFeature,										// 选择的坐标系特征(in)
		const double &dMoveX,const double &dMoveY, const double &dMoveZ,	// x,y,z轴的偏移量(in)
		const double &dRotX, const double &dRotY, const double &dRotZ		// 沿x,y,z轴的旋转角(in)
		);

private:
	// 遍历模型坐标系的动作函数
	static ProError GetSolidCsysVisitAction(ProCsys pCsys, ProError status, ProAppData pAppData);

	// 遍历特征的尺寸动作函数
	static ProError ModifyCsysByOffsetByDimensionVisit(ProDimension *dimension, ProError status, ProAppData data);

};

//===================================================================================================
 