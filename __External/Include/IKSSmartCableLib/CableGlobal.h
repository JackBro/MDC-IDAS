//===================================================================================================
// Summary:
//		电缆内部使用的公共函数
// Date:
//		2016-09-18
// Author:
//		
//===================================================================================================

#ifndef __CableGlobal_h__
#define __CableGlobal_h__

//===================================================================================================

const int g_nHolePreviewID = 1001;
const int g_nAutoRoutingCablePreviewID = 1002;
const int g_nSemiAutoRoutingCablePathSelPreviewID = 1003;
const int g_nSemiAutoRoutingCablePathNextPreviewID = 1004;
const int g_nBatchHolePreviewID = 1005;
const int g_nInfluenceCableSegPreviewID = 1006;
const int g_nClosePathCableSegPreviewID = 1007;

//===================================================================================================

#include "CableBaseMacro.h"
#include "SVCLMath.h"
// #include "SVCLGlobal.h"
#include "SVCLGlobalMFC.h"
// #include "SVCLXMLParse.h"
#include "ExcelOperatorAPI.h"
#include "CableBaseDef.h"
#include "CablePublicFunc.h"

//===================================================================================================
namespace IKS_SMARTCABLINGGLOBAL
{

// 销毁对话框
void DestroyDialog(CDialog *pDlg);

// 获取非模态对话框的左上角位置
CRect GetSceenCenterRect(int nOffsetX, int nOffsetY, const CRect &rcRect);
// 获取非模态对话框的左上角位置
CRect GetSceenLeftTopRect(int nOffsetX, int nOffsetY, const CRect &rcRect);

// 根据矩阵获取缩放变换的比例系数
double GetScaleRatioByMatrix(const SVBASEMATRIX &matrix);

// 判断曲线是否闭合(输入的曲线需要按照顺序排列)
BOOL CheckCurveClose(const std::vector<IKSCABDCurve> &vecCurves, std::vector<SVBASEDOUBLE3> *pvecPortArr=NULL);
// 获取圆弧的起点和终点坐标
BOOL GetArcStartEndPos(const IKSCABDCurve &arc, SVBASEDOUBLE3 &vStart, SVBASEDOUBLE3 &vEnd);
// 获取圆弧的起点和终点坐标
BOOL GetCurveStartEndPos(const IKSCABDCurve &curve, SVBASEDOUBLE3 &vStart, SVBASEDOUBLE3 &vEnd);

// 获取将轴1变换为轴2的转换矩阵
void GetAxisTransformMatrix(const SVBASEDOUBLE3 &vSrcOrigin, const SVBASEDOUBLE3 &vSrcAxis, 
							const SVBASEDOUBLE3 &vTgtOrigin, const SVBASEDOUBLE3 &vTgtAxis, SVBASEMATRIX &matrix);

// SVF文件输出数据
IKS_BOOL WriteSVFFile_Data(const wchar_t *szData, FILE *pFile);

// 如果没有坐标系则创建默认坐标系
BOOL CreateDefaultCSysIfEmpty(ProSolid pSld, ProFeature *pFeature=NULL);
// 如果没有坐标系则创建默认坐标系
BOOL CreateDefaultCSysIfEmpty(ProSelection pSldSel, ProFeature *pFeature=NULL);

// 通过模型树节点获取其内所有坐标系几何(ProSelection需要使用者自行释放内存)
BOOL GetCSysGeomInModelTreeNode(const CABModelNodeData *pSkeletonTreeNode, std::vector<ProGeomitem> *pvecCSysGeom=NULL, std::vector<ProSelection> *pvecCSysGeomSel=NULL, std::vector<CSVWString> *pvecCSysName=NULL);
// 通过模型树节点获取其内所有坐标系几何(ProSelection需要使用者自行释放内存)
BOOL GetCSysGeomInModelTreeNode(ProAsmcomppath* pSolidCmpPath, std::vector<ProGeomitem> *pvecCSysGeom=NULL, std::vector<ProSelection> *pvecCSysGeomSel=NULL, std::vector<CSVWString> *pvecCSysName=NULL);

// 获取当前模块路径
CString GetCurModulePath();
// 设置当前模块路径
void SetCurModulePath(const CString &strMainModulePath);
// 获取电缆配置文件所在路径
void GetCableConfigPath(CString& strPath);

}	// namespace IKS_SMARTCABLINGGLOBAL

//===================================================================================================

#endif