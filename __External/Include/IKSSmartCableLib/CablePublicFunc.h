//===================================================================================================
// Summary:
//		内部使用的Pro/E公共函数
// Date:
//		2016-03-17
// Author:
//		WangShiping
//===================================================================================================

#pragma once

//===================================================================================================

#include <ProToolkit.h>
#include <ProUtil.h>
#include <ProMessage.h>
#include <ProArray.h>
#include <ProNotify.h>
#include <ProUICmd.h>
#include <ProUIMessage.h>

#include <ProMenu.h>
#include <ProMenuBar.h>
#include <ProPopupmenu.h>

#include <ProMdl.h>
#include <ProModelitem.h>
#include <ProAsmcomp.h>
#include <ProWindows.h>
#include <ProSolid.h>
#include <ProDrawing.h>
#include <ProFeature.h>
#include <ProFeatType.h>
#include <ProSelection.h>
#include <ProSelbuffer.h>
#include <ProQuilt.h>
#include <ProLayer.h>
#include <ProCabling.h>

#include <prodev_light.h>

#include <ProParameter.h>
#include <ProParamval.h>
#include <ProRelSet.h>
#include <ProDimension.h>

#include <ProAxis.h>
#include <ProDtlentity.h>
#include <ProDtlgroup.h>
#include <ProDtlnote.h>
#include <ProDtlsymdef.h>
#include <ProDwgTable.h>
#include <ProAnnotation.h>
#include <ProSkeleton.h>
#include <ProCsys.h>

// 阵列
#include <ProPattern.h>
// 组
#include <ProUdf.h>

// 粗糙度所需头文件
#include <ProSurfFinish.h>
#include <prodtl_str.h>
#include <prodev_types.h>
#include <prodev_error.h>
#include <pd_prototype.h>
#include <UtilString.h>
#include <UtilMenu.h>

#include <ProDisplist.h>

#include <ProPoint.h>

// 绘制中心线
#include <ProPoint.h>
#include <ProCurve.h>
#include <ProColor.h>
#include <ProEdge.h>
#include <UtilMath.h>

#include <ProSurface.h>
#include <ProDrawingView.h>

#include <ProPrint.h>
#include <ProXsec.h>
#include <ProSetDatumTag.h>

#include <ProDataShareFeat.h>
#include <ProDtmCsys.h>
#include <ProDtmPnt.h>

//===================================================================================================

#define GREATER_EQUAL(x, y) (ISDEQUAL((x), (y)) || (x) > (y))
#define LESS_EQUAL(x, y) (ISDEQUAL((x), (y)) || (x) < (y))
#define GREATER_NEAR(x, y) (ISDNEAR((x), (y)) || (x) > (y))
#define LESS_NEAR(x, y) (ISDNEAR((x), (y)) || (x) < (y))

namespace IKS_SMARTCABLINGGLOBAL
{

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


// UDF参考定义
typedef struct __tagUDFReference
{
	ProLine szRefName;								// 参考名称
	ProSelection pRefSel;							// 参考选择对象

	__tagUDFReference()
	{
		memset(szRefName, 0, sizeof(ProLine));
		pRefSel = NULL;
	}
	__tagUDFReference(const __tagUDFReference &data)
	{
		wcsncpy_s(szRefName, PRO_LINE_SIZE, data.szRefName, _TRUNCATE);
		pRefSel = data.pRefSel;
	}
	__tagUDFReference operator=(const __tagUDFReference &data)
	{
		if (&data == this)
			return *this;
		wcsncpy_s(szRefName, PRO_LINE_SIZE, data.szRefName, _TRUNCATE);
		pRefSel = data.pRefSel;
		return *this;
	}
}UDFReference;

// UDF尺寸定义
typedef struct __tagUDFDimension
{
	ProName szDimName;								// 尺寸名称
	double dDimValue;								// 尺寸值

	__tagUDFDimension()
	{
		memset(szDimName, 0, sizeof(ProName));
		dDimValue = 0.0;
	}
	__tagUDFDimension(const __tagUDFDimension &data)
	{
		wcsncpy_s(szDimName, PRO_NAME_SIZE, data.szDimName, _TRUNCATE);
		dDimValue = data.dDimValue;
	}
	__tagUDFDimension operator=(const __tagUDFDimension &data)
	{
		if (&data == this)
			return *this;
		wcsncpy_s(szDimName, PRO_NAME_SIZE, data.szDimName, _TRUNCATE);
		dDimValue = data.dDimValue;
		return *this;
	}
}UDFDimension;

// UDF定义
typedef struct __tagUDFDefinition
{
	CString strUDFPath;								// UDF路径
	vector<UDFReference> arrRefs;					// 参考集
	vector<UDFDimension> arrDims;					// 尺寸集

	__tagUDFDefinition()
	{
	}
	__tagUDFDefinition(const __tagUDFDefinition &data)
	{
		strUDFPath = data.strUDFPath;
		arrRefs = data.arrRefs;
		arrDims = data.arrDims;
	}
	__tagUDFDefinition operator=(const __tagUDFDefinition &data)
	{
		if (&data == this)
			return *this;
		strUDFPath = data.strUDFPath;
		arrRefs = data.arrRefs;
		arrDims = data.arrDims;
		return *this;
	}
}UDFDefinition;

// 获取二维点的旋转角度
double PFGetVec2Angle(double x, double y);

// 在组件中生成带骨架的组件
BOOL CreateAsmWithSkelInAsm(
							ProAssembly pTopAsm,					// 总装配模型
							ProPath szAsmTemplatePath,				// 装配模板文件路径
							ProName szNewAsmName,					// 装配体的名称
							ProName szNewSkelName					// 骨架模型的名称
							);

// 根据装配体模型获取骨架模型
BOOL GetSkelMdlFromAsmMdl(
						  ProAssembly pAsm,						// 装配体
						  ProMdl &pSkelMdl,						// 骨架模型
						  int &nSkelCompID						// 骨架元件特征ID
						  );

// 根据发布几何生成复制几何，用缺省参考方式
BOOL CreateCopyGeomByPubGeom(
							 ProSolid pSld,							// 复制几何所在模型
							 ProSelection pSelPubGeom,				// 选择的发布几何
							 ProName szCGName,						// 复制几何特征名
							 ProFeature &newCopyFeature				// 新的复制几何特征
							 );

// 根据发布几何生成局部复制几何
BOOL CreateLocalCopyGeomByPubGeom(
								  ProSelection pSelSld,					// 复制几何所在模型
								  ProSelection pSelPubGeom,				// 选择的发布几何
								  ProName szCGName,						// 复制几何特征名
								  ProFeature &newCopyFeature			// 新的复制几何特征
								  );

// 根据发布几何生成复制几何，用坐标系参考方式
BOOL CreateCopyGeomByPubGeomUseCsys(
									ProSolid pPubGeomMdl,					// 发布几何总模型
									ProSelection pSelExtCsys,				// 外部参考坐标系，路径相对于发布几何总模型
									ProSelection pSelPubGeom,				// 发布几何选择对象，路径相对于发布几何总模型
									ProSolid pCopyGeomMdl,					// 复制几何总模型
									ProSelection pSelLocalCsys,				// 局部参考坐标系，路径相对于复制几何总模型
									ProName szCGName,						// 复制几何特征名
									ProFeature &newCopyFeature				// 新的复制几何特征
									);

// 根据复制几何生成发布几何
BOOL CreatePubGeomByCopyGeom(
							 ProSolid pPubGeomMdl,							// 发布几何所在模型
							 ProFeature &copyGeomFeature,					// 复制几何，直属于发布几何所在模型
							 ProName szPBName,								// 发布几何特征名
							 ProFeature &newPubFeature						// 新的发布几何特征
							 );

// 根据模型生成收缩包络，用坐标系参考方式
BOOL CreateShrinkWrapByPubGeomUseCsys(
									  ProSolid pExtRefMdl,							// 外部参考总模型
									  ProSelection pSelExtCsys,						// 外部参考坐标系，路径相对于外部参考总模型
									  vector<ProSelection> &arrIncludeComps,		// 收缩包络包含的元件，路径相对于外部参考总模型
									  vector<ProSelection> &arrNotIncludeComps,		// 收缩包络不包含的元件，路径相对于外部参考总模型
									  ProSolid pShrinkWrapMdl,						// 收缩包络总模型
									  ProSelection pSelLocalCsys,					// 局部参考坐标系，路径相对于收缩包络总模型
									  int nQualityLevel,							// 质量等级
									  ProName szSWName,								// 收缩包络特征名
									  ProFeature &newSWFeature						// 新的收缩包络特征
									  );

// 得到源矩阵向目标矩阵转换的旋转角度
BOOL PFGetTrfMoveParam(ProMatrix srcTrf, ProMatrix destTrf, 
					   double &dXMove, double &dYMove, double &dZMove, 
					   double &dRotX, double &dRotY, double &dRotZ);

// 得到源坐标系向目标坐标系转换的平移量和旋转角度
BOOL GetCsysMoveParam(SVDOUBLE3 &vSrcCsysOrigin, SVDOUBLE3 &vSrcCsysX, SVDOUBLE3 &vSrcCsysY, SVDOUBLE3 &vSrcCsysZ,
					  SVDOUBLE3 &vDestCsysOrigin, SVDOUBLE3 &vDestCsysX, SVDOUBLE3 &vDestCsysY, SVDOUBLE3 &vDestCsysZ,
					  double &dXMove, double &dYMove, double &dZMove, double &dRotX, double &dRotY, double &dRotZ);

// 根据坐标变换的分量，获取变换矩阵
BOOL GetTransMatrix(double dXMove, double dYMove, double dZMove, double dRotX, double dRotY, double dRotZ, ProMatrix trans);

// 获取坐标系特征的参考坐标系
BOOL GetCsysRefCsys(
					ProSelection pSelCsysFeature, 
					ProSelection &pSelRefCsys
					);

// 获取坐标系的参考坐标系
BOOL GetCsysRefCsys(
					ProGeomitem &csysItem,							// 坐标系
					ProGeomitem &refCsysItem						// 参考坐标系
					);

// 根据坐标系的位置和基准坐标系，生成新的坐标系
BOOL CreateCSys(
				ProSelection pSelSld,								// 坐标系所在模型
				ProPoint3d origin,									// 坐标系的原点位置
				ProPoint3d x,										// 坐标系的X轴向量
				ProPoint3d y,										// 坐标系的Y轴向量
				ProPoint3d z,										// 坐标系的Z轴向量
				ProSelection pSelDatumCsys,							// 选择的基准坐标系
				ProName szCsysName,									// 坐标系名
				ProFeature &newCsysFeature							// 新的坐标系特征
				);

// 生成缺省坐标系
BOOL CreateDefaultCSys(
					   ProSolid pSld,								// 坐标系所在模型
					   const CString &strUDFPath,					// UDF路径
					   ProName szCsysName,							// 坐标系名
					   ProFeature &newCsysFeature					// 新的坐标系特征
					   );

// 根据坐标系的位置，修正坐标系
BOOL ModifyCSys(
				ProSelection pSelCsys,								// 坐标系选择对象
				ProPoint3d origin,									// 坐标系的原点位置
				ProPoint3d x,										// 坐标系的X轴向量
				ProPoint3d y,										// 坐标系的Y轴向量
				ProPoint3d z										// 坐标系的Z轴向量
				);

// 增加模型至装配体，用坐标系装配
BOOL AddModelToAsmWithCsysCons(
							   ProAssembly pAsm,						// 装配体
							   ProSelection pSelCsys,					// 选择的基准坐标系
							   ProSolid pMdlToAdd,						// 待增加新模型
							   ProModelitem &csysItem,					// 模型的坐标系
							   ProAsmcomp &newAsmcomp					// 新的元件
							   );

// 添加坐标系约束
BOOL AddCsysConstraint(
					   ProAsmcomp &asmcomp,						// 新的元件
					   ProAssembly pAsm,						// 装配体
					   ProSelection pSelCsys,					// 选择的基准坐标系
					   ProSelection pSelCompCsys				// 模型的坐标系
					   );

// 判断特征是否是发布几何
BOOL PFIsFeaturePubGeom(ProFeature &feature);
// 判断特征是否是复制几何
BOOL IsFeatureCopyGeom(ProFeature &feature);

// 获取模型的发布几何
BOOL GetMdlPubGeom(
				   ProMdl pMdl,											// 模型
				   vector<ProFeature> &arrPubGeom						// 发布几何
				   );

// 获取模型的复制几何
BOOL GetMdlCopyGeom(
					ProMdl pMdl,										// 模型
					vector<ProFeature> &arrCopyGeom						// 发布几何
					);

// 根据复制几何获取复制几何的参考模型
BOOL GetCopyGeomRefMdl(
					   ProFeature &feaCopyGeom, 						// 复制几何
					   ProMdl &pRefMdl									// 参考模型
					   );

// 根据点项获取点的位置
BOOL GetPointCoords(
					ProModelitem &pointItem,							// 点的项目
					ProPoint3d pointPos									// 点的位置
					);

// 根据选择点获取点的位置
BOOL GetPointCoords(
					ProSelection pSelPoint,								// 点的项目
					SVDOUBLE3 &pointPos									// 点的位置
					);

// 根据坐标系获取坐标系数据
BOOL GetCsysData(ProModelitem &csysItem,								// 坐标系的项目
				 ProPoint3d origin,										// 原点的位置
				 ProPoint3d x,											// X轴向量
				 ProPoint3d y,											// Y轴向量
				 ProPoint3d z											// Z轴向量
				 );

// 获取选择坐标系的数据，相对于世界坐标
BOOL GetCsysData(
				 ProSelection pSelCsys,									// 坐标系的选择对象
				 SVDOUBLE3 &origin,										// 原点的位置
				 SVDOUBLE3 &x,											// X轴向量
				 SVDOUBLE3 &y,											// Y轴向量
				 SVDOUBLE3 &z											// Z轴向量
				 );

// 获取选择坐标系的数据，相对于世界坐标
BOOL GetCsysData(
				 ProSelection pSelCsys,									// 坐标系的选择对象
				 IKSCsysData &csysData									// 坐标系数据
				 );

// 获取选择对象的父组件
BOOL GetSelectionFatherAsm(ProSelection pSel, ProMdl &pFatherAsm);
// 获取选择对象的祖组件
BOOL GetSelectionGrandAsm(ProSelection pSel, ProMdl &pGrandAsm);
// 获取路径的父组件
BOOL GetAsmcomppathFatherAsm(ProAsmcomppath &comppath, ProMdl &pFatherAsm);
// 获取路径的祖组件
BOOL GetAsmcomppathGrandAsm(ProAsmcomppath &comppath, ProMdl &pGrandAsm);
// 获取路径的父路径
BOOL GetAsmcomppathFatherPath(ProAsmcomppath &comppath, ProAsmcomppath &fatherPath);

// 创建UDF
BOOL PFCreateUDF(ProSolid pSld, UDFDefinition &udfDef, ProGroup &udf);

// 矩阵相乘
void PFMatrixMultiply(const ProMatrix matrix1, const ProMatrix matrix2, ProMatrix matrixOut);
// 3X3矩阵相乘
void Matrix3X3Multiply(const double matrix1[3][3], const double matrix2[3][3], double matrixOut[3][3]);
// 拷贝变换矩阵
void PFMatrixCopy(const ProMatrix input, ProMatrix output);
// 求逆矩阵
BOOL PFMatrixInvert(const ProMatrix input, ProMatrix output);
// 坐标系转换为装配矩阵
ProError PFVectorToMatrix(double x_vector[3],					/* IN - X directional vector   */
						  double y_vector[3],					/* IN - Y directional vector   */
						  double z_vector[3],					/* IN - Z directional vector   */
						  double o_vector[3],					/* IN - Origin                 */
						  double transform[4][4]);				/* OUT - transformation matrix */

//===================================================================================================

// 创建拉伸曲面_圆
BOOL CreateExtrudeFace_Circle(
							  ProSolid pSld,							// 拉伸曲面所在模型
							  ProSelection pSelPlane,					// 草绘放置面
							  ProSelection pSelCsys,					// 参考坐标系
							  const CString &strUDFPath,				// UDF路径
							  double dCircleDiameter,					// 圆直径
							  double dExtrudeHeight						// 拉伸高度
							  );

// 创建拉伸曲面_矩形
BOOL CreateExtrudeFace_Rectangle(
								 ProSolid pSld,							// 拉伸曲面所在模型
								 ProSelection pSelPlane,				// 草绘放置面
								 ProSelection pSelCsys,					// 参考坐标系
								 const CString &strUDFPath,				// UDF路径
								 double dLength,						// 长度
								 double dWidth,							// 宽度
								 double dExtrudeHeight					// 拉伸高度
								 );

// 创建拉伸曲面_门形
BOOL CreateExtrudeFace_Door(
							ProSolid pSld,								// 拉伸曲面所在模型
							ProSelection pSelPlane,						// 草绘放置面
							ProSelection pSelCsys,						// 参考坐标系
							const CString &strUDFPath,					// UDF路径
							double dLength,								// 长度
							double dWidth,								// 宽度
							double dExtrudeHeight						// 拉伸高度
							);

//===================================================================================================

// 创建拉伸曲面_直线
BOOL CreateExtrudeFace_Line(
							const CString &strUDFPath,					// UDF路径
							ProSelection pSelSld,						// 扫描曲面所在模型
							ProPoint3d refCsysOrigin,					// 参考坐标系原点
							ProPoint3d refCsysX,						// 参考坐标系X轴
							ProPoint3d refCsysZ,						// 参考坐标系Z轴
							double dSecLineLength,						// 截面直线长度
							double dExtrudeHeight						// 拉伸高度
							);

// 创建拉伸曲面_圆
BOOL CreateExtrudeFace_Circle(
							  const CString &strUDFPath,				// UDF路径
							  ProSelection pSelSld,						// 扫描曲面所在模型
							  ProPoint3d refCsysOrigin,					// 参考坐标系原点
							  ProPoint3d refCsysX,						// 参考坐标系X轴
							  ProPoint3d refCsysZ,						// 参考坐标系Z轴
							  double dSecCircleDiameter,				// 截面圆直径
							  double dExtrudeHeight						// 拉伸高度
							  );

// 创建拉伸曲面_矩形
BOOL CreateExtrudeFace_Rectangle(
								 const CString &strUDFPath,				// UDF路径
								 ProSelection pSelSld,					// 扫描曲面所在模型
								 ProPoint3d refCsysOrigin,				// 参考坐标系原点
								 ProPoint3d refCsysX,					// 参考坐标系X轴
								 ProPoint3d refCsysZ,					// 参考坐标系Z轴
								 double dSecRectLength,					// 截面矩形长度
								 double dSecRectWidth,					// 截面矩形宽度
								 double dExtrudeHeight					// 拉伸高度
								 );

// 创建拉伸曲面_门形
BOOL CreateExtrudeFace_Door(
							const CString &strUDFPath,					// UDF路径
							ProSelection pSelSld,						// 扫描曲面所在模型
							ProPoint3d refCsysOrigin,					// 参考坐标系原点
							ProPoint3d refCsysX,						// 参考坐标系X轴
							ProPoint3d refCsysZ,						// 参考坐标系Z轴
							double dSecDoorLength,						// 截面矩形长度
							double dSecDoorWidth,						// 截面矩形宽度
							double dExtrudeHeight						// 拉伸高度
							);

// 创建拉伸曲面_U形
BOOL CreateExtrudeFace_UShape(
							  const CString &strUDFPath,				// UDF路径
							  ProSelection pSelSld,						// 扫描曲面所在模型
							  ProPoint3d refCsysOrigin,					// 参考坐标系原点
							  ProPoint3d refCsysX,						// 参考坐标系X轴
							  ProPoint3d refCsysZ,						// 参考坐标系Z轴
							  double dSecULength,						// 截面U形长度
							  double dSecUWidth,						// 截面U形宽度
							  double dExtrudeHeight						// 拉伸高度
							  );

// 获取新特征的名称
BOOL PFGetNewFeatureName(ProSolid pSld, ProName szNameExpected, ProName szNewFeaName, BOOL bStartWith1 = FALSE);

//===================================================================================================

// 创建扫描曲面，轨迹为圆弧，截面为直线
BOOL CreateSweepFace_TrailArc_SecLine(
									  const CString &strUDFPath,					// UDF路径
									  ProSelection pSelSld,							// 扫描曲面所在模型
									  ProPoint3d arcStart,							// 圆弧的起点
									  ProPoint3d arcMid,							// 圆弧的中间点
									  ProPoint3d arcEnd,							// 圆弧的终点
									  double dSecLineLength							// 截面直线长度
									  );

// 创建扫描曲面，轨迹为圆弧，截面为圆
BOOL CreateSweepFace_TrailArc_SecCircle(
										const CString &strUDFPath,					// UDF路径
										ProSelection pSelSld,						// 扫描曲面所在模型
										ProPoint3d arcStart,						// 圆弧的起点
										ProPoint3d arcMid,							// 圆弧的中间点
										ProPoint3d arcEnd,							// 圆弧的终点
										double dSecCircleDiameter					// 截面圆直径
										);

// 创建扫描曲面，轨迹为圆弧，截面为矩形
BOOL CreateSweepFace_TrailArc_SecRectangle(
	const CString &strUDFPath,					// UDF路径
	ProSelection pSelSld,						// 扫描曲面所在模型
	ProPoint3d arcStart,						// 圆弧的起点
	ProPoint3d arcMid,							// 圆弧的中间点
	ProPoint3d arcEnd,							// 圆弧的终点
	double dSecRectLength,						// 截面矩形长度
	double dSecRectWidth						// 截面矩形宽度
	);

// 创建扫描曲面，轨迹为圆弧，截面为门形
BOOL CreateSweepFace_TrailArc_SecDoor(
									  const CString &strUDFPath,					// UDF路径
									  ProSelection pSelSld,							// 扫描曲面所在模型
									  ProPoint3d arcStart,							// 圆弧的起点
									  ProPoint3d arcMid,							// 圆弧的中间点
									  ProPoint3d arcEnd,							// 圆弧的终点
									  double dSecDoorLength,						// 截面矩形长度
									  double dSecDoorWidth							// 截面矩形宽度
									  );

// 创建扫描曲面，轨迹为圆弧，截面为U形
BOOL CreateSweepFace_TrailArc_SecUShape(
	const CString &strUDFPath,					// UDF路径
	ProSelection pSelSld,						// 扫描曲面所在模型
	ProPoint3d arcStart,						// 圆弧的起点
	ProPoint3d arcMid,							// 圆弧的中间点
	ProPoint3d arcEnd,							// 圆弧的终点
	double dSecULength,							// 截面U形长度
	double dSecUWidth							// 截面U形宽度
	);

//===================================================================================================

// 生成基准点
BOOL CreateDatumPoints(
					   ProSelection pSelSld,								// 基准点特征所在模型
					   ProSelection pSelCsys,								// 参考坐标系，如果为空则利用默认的坐标系
					   const vector<SVDOUBLE3> &arrPoints,					// 点的位置
					   ProName szDtmPntFeatureName,							// 基准点特征名
					   ProFeature &newDatumPointsFeature					// 基准点特征
					   );

// 生成基准点（根据坐标系位置）
BOOL CreateDatumPointByCsys(
							ProSelection pSelSld,							// 基准点特征所在模型
							ProSelection pSelCsys,							// 参考坐标系
							ProName szDtmPntFeatureName,					// 基准点特征名
							ProFeature &newDatumPointFeature				// 基准点特征
							);

// 生成基准轴（根据两个点）
BOOL CreateDatumAxisByTwoPoints(
								ProSelection pSelSld,						// 基准轴特征所在模型
								ProSelection pSelPoint1,					// 基准点1
								ProSelection pSelPoint2,					// 基准点2
								ProName szDtmAxisFeatureName,				// 基准轴特征名
								ProFeature &newDtmAxisFeature				// 基准轴特征
								);

// 修改基准点（适应于偏移坐标系基准点）
BOOL ModifyDatumPoints(
					   ProSelection pSelDatumFeature,						// 基准点特征
					   const vector<SVDOUBLE3> &arrPoints					// 点的位置（世界坐标）
					   );

// 根据特征获取参考坐标系
BOOL GetDatumPointRefCsys(
						  ProSelection pSelDatumFeature,					// 基准点特征
						  ProSelection &pSelRefCsys							// 参考坐标系
						  );

// 创建扫描曲面，轨迹为样条，截面为直线
BOOL CreateSweepFace_TrailSpline_SecLine(
	const CString &strUDFPath,					// UDF路径
	ProSelection pSelSld,						// 扫描曲面所在模型
	const vector<SVDOUBLE3> &arrSplinePoints,	// 样条曲线点
	double dSecLineLength						// 截面直线长度
	);

// 创建扫描曲面，轨迹为样条，截面为圆
BOOL CreateSweepFace_TrailSpline_SecCircle(
	const CString &strUDFPath,					// UDF路径
	ProSelection pSelSld,						// 扫描曲面所在模型
	const vector<SVDOUBLE3> &arrSplinePoints,	// 样条曲线点
	double dSecCircleDiameter					// 截面圆直径
	);

// 创建扫描曲面，轨迹为样条，截面为矩形
BOOL CreateSweepFace_TrailSpline_SecRectangle(
	const CString &strUDFPath,					// UDF路径
	ProSelection pSelSld,						// 扫描曲面所在模型
	const vector<SVDOUBLE3> &arrSplinePoints,	// 样条曲线点
	double dSecRectLength,						// 截面矩形长度
	double dSecRectWidth						// 截面矩形宽度
	);

// 创建扫描曲面，轨迹为样条，截面为门形
BOOL CreateSweepFace_TrailSpline_SecDoor(
	const CString &strUDFPath,					// UDF路径
	ProSelection pSelSld,						// 扫描曲面所在模型
	const vector<SVDOUBLE3> &arrSplinePoints,	// 样条曲线点
	double dSecDoorLength,						// 截面矩形长度
	double dSecDoorWidth						// 截面矩形宽度
	);

// 创建扫描曲面，轨迹为样条，截面为U形
BOOL CreateSweepFace_TrailSpline_SecUShape(
	const CString &strUDFPath,					// UDF路径
	ProSelection pSelSld,						// 扫描曲面所在模型
	const vector<SVDOUBLE3> &arrSplinePoints,	// 样条曲线点
	double dSecULength,							// 截面U形长度
	double dSecUWidth							// 截面U形宽度
	);

//===================================================================================================

// 根据选择曲面对象计算坐标系的绝对位置
BOOL CalcCsysBySelSurface(
						  ProSelection pSelSurf,							// 选择曲面
						  SVDOUBLE3 &vCsysOrigin,							// 坐标系原点
						  SVDOUBLE3 &vCsysX,								// 坐标系X
						  SVDOUBLE3 &vCsysY,								// 坐标系Y
						  SVDOUBLE3 &vCsysZ									// 坐标系Z
						  );

//===================================================================================================

typedef struct __tagParameterData
{
	CString strParaName;						// 参数名
	CString strDispName;						// 显示名
	CString strValue;							// 参数值
	CString strRemark;							// 备注
	CString strParaType;						// 参数类型

	__tagParameterData()
	{
	}
	__tagParameterData(const __tagParameterData &data)
	{
		strParaName = data.strParaName;
		strDispName = data.strDispName;
		strValue = data.strValue;
		strRemark = data.strRemark;
		strParaType = data.strParaType;
	}
	__tagParameterData &operator=(const __tagParameterData& data){
		if (&data != this)
		{
			strParaName = data.strParaName;
			strDispName = data.strDispName;
			strValue = data.strValue;
			strRemark = data.strRemark;
			strParaType = data.strParaType;
		}
		return *this;
	}
} ParameterData;

// 获取模型的主参数
BOOL GetMdlMainParameters(ProMdl pMdl, vector<ParameterData> &arrParameters);

//===================================================================================================

// 获取离选择曲面最近的点
BOOL GetPointOnSurface(
					   ProSelection pSelSurf,					// 选择曲面
					   SVDOUBLE3 &vInputPoint,					// 输入点
					   SVDOUBLE3 &vPointOnSurf					// 曲面上的点
					   );

//===================================================================================================

// 获取路径的元件特征
BOOL GetAsmcomppathCompFeature(
							   ProAsmcomppath &comppath,		// 路径
							   ProAsmcomp &asmcomp				// 元件特征
							   );

//===================================================================================================

// 获取模型的默认参考坐标系
BOOL GetSolidDefaultCsys(
						 ProSolid pSld,									// 参考实体
						 ProCsys &pDefaultCsys							// 默认参考坐标系
						 );

// 获取特征的坐标系
BOOL GetCsysItemFromFeature(
							ProFeature &feaCsys,						// 参考实体
							ProGeomitem &geomCsys						// 默认参考坐标系
							);

//===================================================================================================

// 获取项目的名称，支持以下项目：
// PRO_EDGE PRO_SURFACE PRO_FEATURE PRO_CSYS PRO_AXIS PRO_POINT PRO_QUILT PRO_CURVE 
// PRO_LAYER PRO_DIMENSION PRO_REF_DIMENSION PRO_NOTE PRO_GTOL PRO_SURF_FIN 
// PRO_SYMBOL_INSTANCE PRO_SET_DATUM_TAG PRO_SIMP_REP PRO_EXPLD_STATE PRO_ANNOTATION_ELEM 
CString GetModelItemName(
						 ProModelitem &item								// 项目
						 );

//===================================================================================================

// 获取平面的数据
BOOL GetPlaneData(
				  ProGeomitem &surfItem,								// 平面的项目
				  SVDOUBLE3 &origin,									// 原点的位置
				  SVDOUBLE3 &x,											// X轴向量
				  SVDOUBLE3 &y,											// Y轴向量
				  SVDOUBLE3 &z											// Z轴向量（曲面法向）
				  );

// 获取选择平面的数据，相对于世界坐标
BOOL GetPlaneData(
				  ProSelection pSelPlane,								// 平面的选择对象
				  SVDOUBLE3 &origin,									// 原点的位置
				  SVDOUBLE3 &x,											// X轴向量
				  SVDOUBLE3 &y,											// Y轴向量
				  SVDOUBLE3 &z											// Z轴向量（曲面法向）
				  );

// 获取选择平面的数据，相对于世界坐标
BOOL GetPlaneData(
				  ProSelection pSelPlane,								// 平面的选择对象
				  IKSPlaneData &planeData								// 平面数据
				  );

// 获取柱面的数据
BOOL GetCylinderData(
					 ProGeomitem &surfItem,								// 柱面的项目
					 IKSCylinderData &cylinderData						// 柱面的数据
					 );

// 获取选择柱面的数据，相对于世界坐标
BOOL GetCylinderData(
					 ProSelection pSelCylinder,							// 柱面的选择对象
					 IKSCylinderData &cylinderData						// 柱面的数据
					 );

// 获取锥面的数据
BOOL GetConeData(
				 ProGeomitem &surfItem,									// 锥面的项目
				 IKSConeData &coneData									// 锥面的数据
				 );

// 获取选择锥面的数据，相对于世界坐标
BOOL GetConeData(
				 ProSelection pSelCone,									// 锥面的选择对象
				 IKSConeData &coneData									// 锥面的数据
				 );

// 获取圆环面的数据
BOOL GetTorusData(
				  ProGeomitem &surfItem,								// 圆环面的项目
				  SVDOUBLE3 &origin,									// 原点的位置
				  SVDOUBLE3 &x,											// X轴向量
				  SVDOUBLE3 &y,											// Y轴向量
				  SVDOUBLE3 &z,											// Z轴向量
				  double &dRadius1,										// 轨迹半径
				  double &dRadius2										// 截面半径
				  );

// 获取选择圆环面的数据，相对于世界坐标
BOOL GetTorusData(
				  ProSelection pSelTorus,								// 圆环面的选择对象
				  SVDOUBLE3 &origin,									// 原点的位置
				  SVDOUBLE3 &x,											// X轴向量
				  SVDOUBLE3 &y,											// Y轴向量
				  SVDOUBLE3 &z,											// Z轴向量
				  double &dRadius1,										// 轨迹半径
				  double &dRadius2										// 截面半径
				  );

// 获取球面的数据
BOOL GetSphereData(
				   ProGeomitem &surfItem,								// 球面的项目
				   IKSSphereData &sphereData							// 球面的数据
				   );

// 获取选择球面的数据，相对于世界坐标
BOOL GetSphereData(
				   ProSelection pSelSphere,								// 球面的选择对象
				   IKSSphereData &sphereData							// 球面的数据
				   );

// 获取曲面的描述
CString GetSurfaceDesc(
					   ProGeomitem &surfItem							// 曲面项目
					   );

//===================================================================================================

// 获取元件特征的参考坐标系
BOOL GetAsmcompRefCsys(
					   ProAsmcomp &asmcomp,								// 元件特征
					   ProGeomitem &refCsysItem							// 装配参考坐标系
					   );

// 获取元件模型的选择对象，路径相对于元件特征的父组件
BOOL GetAsmcompSelection(
						 ProAsmcomp &asmcomp,							// 元件特征
						 ProSelection &pSelCompMdl						// 装配参考坐标系
						 );

//===================================================================================================

// 高亮选择对象
BOOL HighlightSelection(
						ProSelection pSel								// 选择对象
						);
// 高亮选择对象
BOOL HighlightSelection(
						const vector<ProSelection> &arrSel				// 选择对象
						);

//===================================================================================================

// 重生模型和环境
BOOL RegenerateCurrentMdl();

// 获取选择模型下属特征的选择对象集
BOOL GetSolidFeatureSelection(
							  ProSelection pSelSld,						// 选择模型
							  int nFeatureType,							// 特征类型
							  vector<ProSelection> &arrSelFeature		// 特征选择对象
							  );

// 获取模型的指定特征集
BOOL GetSolidFeature(
					 ProSolid pSld,										// 模型
					 ProFeattype feaType,								// 特征类型
					 vector<ProFeature> &arrFeature						// 特征集
					 );

// 获取模型的指定几何集
BOOL GetSolidGeomitems(
					   ProSolid pSld,									// 模型
					   ProType eGeomType,								// 几何类型
					   vector<ProGeomitem> &arrGeomItems				// 几何集
					   );

// 获得选择对象的名称
BOOL GetNameFromProSelection(
							 ProSelection pSel,							// 选择对象
							 CString &strSelName						// 对象名
							 );

// 获取特征的所有相关阵列生成的特征
BOOL GetFeatureAllPatternFeatures(
								  ProFeature &feature,						// 特征对象(in)
								  vector<ProFeature> &arrPatternFeatures	// 阵列特征集(out)
								  );

// 判断坐标系是否位于曲面区域范围内
BOOL IsCsysInSurfaceRegion(
						   ProSelection pSelCsys,						// 坐标系选择对象(in)
						   ProSelection pSelSurface						// 曲面选择对象(in)
						   );

// 获取选择对象的相对于实体模型的选择对象
BOOL GetSelectionRelSelection(
							  ProSelection pSel,						// 选择对象
							  ProSolid pOwnerMdl,						// 实体模型
							  ProSelection &pSelRel						// 相对的选择对象
							  );

// 获取特征的几何项目
BOOL GetFeatureGeomItems(
						 ProFeature &feature,							// 特征
						 ProType eGeomType,								// 几何类型
						 vector<ProGeomitem> &arrGeomItems				// 几何集
						 );

// 获取特征的几何项目选择对象
BOOL GetFeatureGeomItemSelections(
								  ProSelection pSelFeature,				// 特征选择对象
								  ProType eGeomType,					// 几何类型
								  vector<ProSelection> &arrGeomSels		// 几何选择对象集
								  );

// 判断点是否在曲面上
BOOL IsPointOnSurface(
					  ProPoint3d dPoint,								// 点位置
					  ProSelection pSelSurface,							// 曲面选择对象
					  ProContour pContour								// 曲面的轮廓
					  );

// 判断点是否在曲面上
BOOL IsPointOnSurface(
					  ProSelection pSelPoint,							// 点位置
					  ProSelection pSelSurface,							// 曲面选择对象
					  ProContour pContour								// 曲面的轮廓
					  );

// 判断点是否在曲面范围内
BOOL IsPointInSurfaceRegion(
							ProPoint3d dPoint,							// 点位置
							ProGeomitem &surfItem						// 面
							);

// 判断点是否在曲面轮廓范围内
BOOL IsPointInContourRegion(
							ProPoint3d dPoint,							// 点位置
							ProSolid pSurfOwner,						// 曲面的所属模型
							ProSurface pSurface,						// 曲面
							ProContour pContour							// 轮廓
							);

// 获取曲面选择对象指向的轮廓
BOOL GetSurfaceContour(
					   ProSelection pSelSurface,						// 曲面选择对象
					   ProContour &pContour								// 轮廓
					   );

// 获取点的柱面坐标
BOOL GetCoordsBySysCylinder(SVDOUBLE3 &vPoint, SVDOUBLE3 &vSysCylPoint);
// 获取点的球面坐标
BOOL GetCoordsBySysSphere(SVDOUBLE3 &vPoint, SVDOUBLE3 &vSysSpherePoint);

// 获取发布几何的基准项目集
BOOL GetPubDatumItems(ProFeature &pubFeature, ProType eDatumType, vector<ProGeomitem> &arrDatumItems);

// 查找项目
int FindModelItem(ProModelitem &mdlItem, const vector<ProModelitem> &arrItems);

// 得到Pro/E的参数名
BOOL GetParaName(ProModelitem *pMdlItem, const CString &strName, BOOL bAddID, ProName szParaName);
// 获得模型的参数
BOOL GetParameter(ProModelitem *pMdlItem, ProName szParaName, ProParameter &para);
// 获得模型的参数
BOOL GetParameter(ProModelitem *pMdlItem, const CString &strName, ProParameter &para, BOOL bAddID = FALSE);
// 获得模型的参数值
BOOL GetParameter(ProModelitem *pMdlItem, const CString &strName, ProBoolean &bValue, BOOL bAddID = FALSE);
// 设置模型的参数值
BOOL SetParameter(ProModelitem *pMdlItem, const CString &strName, const ProBoolean &bValue, BOOL bAddID = TRUE, wchar_t *strDescription = NULL, BOOL bDesignation = FALSE);
// 获得模型的参数值
BOOL GetParameter(ProModelitem *pMdlItem, const CString &strName, CString &strValue, BOOL bAddID = FALSE);
// 设置模型的参数值
BOOL SetParameter(ProModelitem *pMdlItem, const CString &strName, const CString &strValue, BOOL bAddID = FALSE, wchar_t *strDescription = NULL, BOOL bDesignation = FALSE);
// 获得模型的参数值
BOOL GetParameter(ProModelitem *pMdlItem, const CString &strName, int &nValue, BOOL bAddID = FALSE);
// 设置模型的参数值
BOOL SetParameter(ProModelitem *pMdlItem, const CString &strName, int nValue, BOOL bAddID = FALSE, wchar_t *strDescription = NULL, BOOL bDesignation = FALSE);
// 获得模型的参数值
BOOL GetParameter(ProModelitem *pMdlItem, const CString &strName, double &dValue, BOOL bAddID = FALSE);
// 设置模型的参数值
BOOL SetParameter(ProModelitem *pMdlItem, const CString &strName, double dValue, BOOL bAddID = FALSE, wchar_t *strDescription = NULL, BOOL bDesignation = FALSE);
// 获得模型的长字符串参数值
BOOL GetLongStringParameter(ProModelitem *pMdlItem, const CString &strName, CString &strValue, BOOL bAddID = FALSE);
// 设置模型的长字符串参数值
BOOL SetLongStringParameter(ProModelitem *pMdlItem, const CString &strName, const CString &strValue, BOOL bAddID = FALSE, wchar_t *strDescription = NULL, BOOL bDesignation = FALSE);
// 删除模型参数
BOOL DeleteParameter(ProModelitem *pMdlItem, const CString &strName, BOOL bAddID = FALSE);
// 删除模型参数
BOOL DeleteLongStringParameter(ProModelitem *pMdlItem, const CString &strName, BOOL bAddID = FALSE);

// 获取关系
BOOL GetRelation(ProMdl pMdl, CString &strRelation);
// 增加关系
BOOL AddRelation(ProMdl pMdl, const CString &strRelation);

// 获取边的起点和终点
BOOL GetEdgeStartAndEnd(ProGeomitem &edgeItem, SVDOUBLE3 &vStart, SVDOUBLE3 &vEnd);

// 获取模型的描述
CString GetMdlDesc(ProMdl pMdl);
// 获取模型的描述
CString GetMdlDesc(ProName mdlName, ProMdlType mdlType);
// 获取类型的描述
CString GetTypeDesc(ProType eType);
// 获取基准的描述
CString GetDatumDesc(ProType eType);

// 获取元件路径对应模型的选择对象
BOOL GetAsmcomppathSelection(ProAsmcomppath &asmcomppath, ProSelection &pSelMdl);
// 重生元件路径对应模型
BOOL RegenerateAsmcomppathMdl(ProAsmcomppath &asmcomppath);

// 获取选择对象的位置
BOOL GetSelectionWorldPos(ProSelection pSel, SVDOUBLE3 &vWorldPos);
// 获取曲面选择对象的法向
BOOL GetSelectionSurfaceNormal(ProSelection pSelSurface, SVDOUBLE3 &vNormal);

// 创建组
BOOL CreateGroup(ProSolid pSld, ProName szGroupName, const vector<ProFeature> &arrFeatures, ProGroup &newGroup);

}	// namespace IKS_SMARTCABLINGGLOBAL
