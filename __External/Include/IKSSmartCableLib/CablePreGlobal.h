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
#include <ProAssembly.h>
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
#include <ProDimension.h>

#include <ProAxis.h>
#include <ProCsys.h>
#include <ProDtlentity.h>
#include <ProDtlgroup.h>
#include <ProDtlnote.h>
#include <ProDtlsymdef.h>
#include <ProDwgTable.h>
#include <ProAnnotation.h>
#include <ProSkeleton.h>

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

#include <ProWTUtils.h>

//===================================================================================================

namespace IKS_SMARTCABLINGGLOBAL
{

// 获得当前模型  
ProMdl GetCurrentMdl();
// 根据名称获得模型
ProMdl GetMdlByNameAndType(ProName mdlName, ProMdlType mdlType);
// 重载模型
ProMdl ReloadMdl(ProMdl pMdl);
// 获得当前零件模型  
ProPart GetCurrentPart();
// 获得当前组件模型  
ProAssembly GetCurrentAssembly();

// 激活当前窗口
ProError ActivateCurrentPreWindow();
// 重绘窗口
void RepaintCurrentPreWindow();
// 刷新窗口，清除临时图形，但不能清除加亮显示
void RefreshCurrentPreWindow();

// 绘制直线段
void DrawGraphicsLine(const SVBASEDOUBLE3& end1, const SVBASEDOUBLE3& end2);
// 通过折线绘制圆弧
void DrawGraphicsCircleByPolyline(const SVBASEDOUBLE3& vOrigin, const SVBASEDOUBLE3& vVector1, const SVBASEDOUBLE3& vVector2, double dRadius, int nSlices=32);

// 拷贝变换矩阵
void MatrixCopy(ProMatrix input, ProMatrix output);
// 求逆矩阵
IKS_BOOL MatrixInvert(ProMatrix input, ProMatrix output);
// 矩阵相乘
void MatrixMultiply(const ProMatrix matrix1, const ProMatrix matrix2, ProMatrix matrixOut);
// 将缩放、旋转、平移的级联矩阵进行分解
void DecomposeSRTMatrix(const ProMatrix &matSRT, ProMatrix matScale=NULL, ProMatrix matRot=NULL, ProMatrix matTrans=NULL);
// 根据矩阵获取沿Z旋转的角度值
IKS_BOOL GetAngleByRotMatrix(const ProMatrix &matRotZ, double &dAngle);
// 获得当前页面矩阵
void GetDrawingTrans(ProDrawing pDrawing, ProMatrix trans);
// 逻辑坐标转换为视图坐标
void LogicPtToViewPt(ProMatrix invertViewTrans, ProVector ptLogic, ProVector ptView);
// 视图坐标转换为逻辑坐标
void ViewPtToLogicPt(ProMatrix viewTrans, ProVector ptView, ProVector ptLogic);

// 获取选择对象的世界选择点
BOOL GetSelectionWorldPos(ProSelection pSel, ProPoint3d pos);
// 获取选择对象的世界法向（主要针对平面）
BOOL GetSelectionWorldNormal(ProSelection pSel, ProPoint3d vec);
// 获取选择对象的世界矩阵
BOOL GetSelectionWorldMatrix(ProSelection pSel, ProMatrix trf);
// 拾取一个对象
BOOL SelectOneObject(ProSelection &pSelObj, char *pSelOpt, ProSelFunctions *pSelFunc = NULL);
// 拾取多个对象
BOOL SelectMultiObject(std::vector<ProSelection> &vecSelObj, char *pSelOpt, ProSelFunctions *pSelFunc = NULL);

// 获取边的类型
ProEnttype GetEdgeType(ProGeomitem *pEnt);
// 获取曲线的类型
ProEnttype GetCurveType(ProGeomitem *pEnt);
// 获取草绘几何的类型
ProEnttype GetDtlEntType(ProDtlentity *pEnt);
// 获取曲面的类型
ProSrftype GetSurfaceType(ProSurface pSurf);

// 通过装配路径获取父模型
ProMdl GetParentMdlByAsmcomppath(const ProAsmcomppath &path);
// 判断输入的装配路径是否相同
BOOL IsAsmcomppathSame(const ProAsmcomppath &path1, const ProAsmcomppath &path2);

// 获取参数并转换至字符串
BOOL GetParameterString(ProModelitem *pMdlItem, const CString &strName, CString &strValue);

}	// namespace IKS_SMARTCABLINGGLOBAL

//===================================================================================================
