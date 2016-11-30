//===================================================================================================
// File:
//		SVCLGlobal.h
// Summary:
//		Provides Global method.
// Usage:
//		Null	
// Remarks:
//		Null
// Date:
//		
// Author:
//		Shiping Wang
//===================================================================================================

#pragma once

//===================================================================================================

#include "SVSceneDef.h"
#include "SVRenderEngineDef.h"

//===================================================================================================
// 宏定义

//===================================================================================================
// 结构体

//===================================================================================================
// 自定义功能函数

// 变换矩阵数据_左右手坐标系互换
void ConvertMatrixLHRH(BPBASEMATRIX &matrix);
// 变换矩阵数据_坐标系YZ轴互换
void ConvertMatrixAxisYZ(BPBASEMATRIX &matrix);

// 变换模型数据_左右手坐标系互换
void ConvertMeshLHRH(BP_MESH_DESC &mesh);
// 变换模型数据_左右手坐标系互换
void ConvertModelLHRH(BP_MODEL_SAVEDATA &stuModelData);
// 变换模型数据_坐标系YZ轴互换
void ConvertModelAxisYZ(BP_MODEL_SAVEDATA &stuModelData);
// 变换模型数据_面数据_左右手坐标系互换
void ConvertModelLHRH_SurfaceData(BPSurface &stuSurface);
// 变换模型数据_边数据_左右手坐标系互换
void ConvertModelLHRH_CurveData(BPCurve &stuBPCurve);
// 变换模型数据_面数据_坐标系YZ轴互换
void ConvertModelAxisYZ_SurfaceData(BPSurface &stuSurface);
// 变换模型数据_边数据_坐标系YZ轴互换
void ConvertModelAxisYZ_CurveData(BPCurve &stuBPCurve);

// 计算包围盒(整体包围盒和子集包围盒)
void ComputeBoundBox(BP_MESH_DESC &stuMeshDesc);
// 计算包围盒
void ComputeBoundBox(const BP_MESH_DESC &stuMeshDesc, BOUNDBOX &box);
// 计算包围盒(整体包围盒和子集包围盒)
void ComputeBoundBox(BP_MODEL_SAVEDATA &stuModelDesc);
// 计算包围盒
void ComputeBoundBox(const BP_MODEL_SAVEDATA &stuModelDesc, BOUNDBOX &box);
// 计算包围盒(只对指定顶点计算包围盒)
void ComputeBoundBox(const BP_MESH_DESC &stuMeshDesc, IKS_UINT uVertStartIndex, IKS_UINT uVertCount, BOUNDBOX &box);
// 计算包围盒(只对指定顶点计算包围盒)
void ComputeBoundBox(const BP_MODEL_SAVEDATA &stuModelDesc, IKS_UINT uVertStartIndex, IKS_UINT uVertCount, BOUNDBOX &box);
// 计算包围盒(只对指定顶点计算包围盒)
void ComputeBoundBox(BOUNDBOX &box, const BP_MESH_DESC &stuMeshDesc, IKS_UINT *arrVertStartIndex, IKS_UINT uVertCount);
// 计算包围盒(只对指定顶点计算包围盒)
void ComputeBoundBox(BOUNDBOX &box, const BP_MODEL_SAVEDATA &stuModelDesc, IKS_UINT *arrVertStartIndex, IKS_UINT uVertCount);
// 计算包围盒(整体包围盒和子集包围盒)（子集包围盒内存由调用者子集申请及释放,子集包围盒数组个数与模型子集相同）
void ComputeBoundBox(const BP_MESH_DESC &stuMeshDesc, BOUNDBOX &stuEntireBox, BOUNDBOX *arrSubBox);
// 计算包围盒(整体包围盒和子集包围盒)（子集包围盒内存由调用者子集申请及释放,子集包围盒数组个数与模型子集相同）
void ComputeBoundBox(const BP_MODEL_SAVEDATA &stuModelDesc, BOUNDBOX &stuEntireBox, BOUNDBOX *arrSubBox);
// 计算包围盒
void ComputeBoundBox(const BOUNDBOX &boxIn, const BPBASEFLOAT3 &vPos, BOUNDBOX &boxOut);
// 计算包围盒
void ComputeBoundBox(const BOUNDBOX *arrBox, IKS_UINT uNum, BOUNDBOX &boxOut);
// 通过子集包围盒计算整体包围盒
void ComputeBoundBoxBySubBox(BP_MESH_DESC &stuMeshDesc);
// 通过子集包围盒计算整体包围盒
void ComputeBoundBoxBySubBox(BP_MODEL_SAVEDATA &stuModelDesc);
// 验证点是否在包围盒中
IKS_BOOL CheckPtInBox(const BPBASEFLOAT3 &pt, const BOUNDBOX &stuEntireBox);
// 验证点是否在包围球中
IKS_BOOL CheckPtInBoundShpere(const BPBASEFLOAT3 &pt, const BOUNDSPHERE &stuBSphere, float fZero=-1.0f);
// 计算整体包围盒
IKS_BOOL CalculateEntireBoundBox(const std::vector<BOUNDBOX> &arrBox, const std::vector<BPBASEMATRIX> &arrMatLocalWorld, BOUNDBOX &stuEntireBox);

// 合并模型的顶点索引数据
IKS_BOOL BlendMeshVertexIndexData(const BP_MESH_DESC &mesh1, const BP_MESH_DESC &mesh2, BP_MESH_DESC &meshOut);
// 计算模型无重复位置的顶点(返回的数组是对原顶点的索引,相同位置的顶点索引相同)
IKS_BOOL CalcMeshNoDuplicatePosVertices(const BP_MESH_DESC &mesh, IKS_DWORD *arrVertIndex, std::vector<IKS_UINT> &arrNoDupPosVertIndex, float fZero=-1.0f);

// 修正模型曲面的纹理坐标
IKS_BOOL MendModelTexCoords(BP_MODEL_SAVEDATA &stuModelData, int nCoordsType=BPCST_RIGHTHAND);
// 优化模型
void OptimizeModelData(BP_MODEL_SAVEDATA &stuModelData, BPBASEMATRIX &matModelLocal, BOUNDBOX &box);
// 优化模型_根据中心偏移值修正面边精确数据
void OptimizeModelData_OffsetSurfaceEdgeData(BP_MODEL_SAVEDATA &stuModelData, const BPBASEFLOAT3 &vCenterOffset);
// 优化模型_根据中心偏移值修正面精确数据
void OptimizeModelData_OffsetSurfaceData(BPSurface &stuSurface, const BPBASEFLOAT3 &vCenterOffset);
// 优化模型_根据中心偏移值修正边精确数据
void OptimizeModelData_OffsetEdgeData(BPCurve &stuBPCurve, const BPBASEFLOAT3 &vCenterOffset);
// 优化模型_面精确数据
void OptimizeModelData_SurfaceData(BP_MODEL_SAVEDATA &stuModelData);
// 优化拓扑面坐标原点
void OptimizeModelData_SurfaceDataOrigin(BPSurface *pSurface, const BOUNDBOX &box);
// 优化拓扑面法矢方向
void OptimizeModelData_SurfaceDataAxisZ(BPSurface *pSurface, BPBASEFLOAT3 vTriFaceVec);

// 获取模型子集对应的曲面数据
IKS_BOOL GetMeshSubsetSurfData(const BP_MESH_DESC &mesh, IKS_UINT uSubsetIndex, BPSurface &surf);
// 获取模型子集对应的曲面类型(若子集没有对应的曲面则返回BPSURFTYPE_UNKOWN)
int GetMeshSubsetSurfType(const BP_MESH_DESC &mesh, IKS_UINT uSubsetIndex);
// 获取模型曲面的关键位置(例如原点位置)
BPBASEFLOAT3 GetMeshSurfKeyPos(const BP_MESH_DESC &mesh, IKS_UINT uSurfIndex);
// 获取模型子集对应的曲线数据
IKS_BOOL GetMeshSubsetCurveData(const BP_MESH_DESC &mesh, IKS_UINT uSubsetIndex, BPCurve &curve);
// 获取模型子集对应的曲面类型(若子集没有对应的曲面则返回BPCURVETYPE_UNKOWN)
int GetMeshSubsetCurveType(const BP_MESH_DESC &mesh, IKS_UINT uSubsetIndex);
// 获取模型曲线的关键位置
BPBASEFLOAT3 GetMeshCurveKeyPos(const BP_MESH_DESC &mesh, IKS_UINT uCurveIndex);

// 检验模型数据是否合理
IKS_BOOL CheckMeshDataValid(const BP_MESH_DESC *pMeshDesc);
// 验证模型数据是否正确
IKS_BOOL CheckModelValid(const BP_MODEL_SAVEDATA &stuModelData);
// 检验模型子集数据是否合理
IKS_BOOL CheckMdlSubsetValid(const BP_MODEL_SAVEDATA &stuModelData, IKS_UINT uSubsetIndex);

// 判断两个模型子集是否相同
IKS_BOOL CheckSVMeshSubsetDataEqual(const BP_MESH_DESCSubset *pSubset1, const BP_MESH_DESCSubset *pSubset2);
// 判断两个模型是否相同
IKS_BOOL CheckSVMeshDataEqual(const BP_MESH_DESC *pMesh1, const BP_MESH_DESC *pMesh2);
// 比较两条曲线是否相同
IKS_BOOL CheckCurveEqual(const BPCurve &curve1, const BPCurve &curve2, float fDisZero=ZERO, float fNormZero=ZERO, float fAngleZero=ZERO);
// 比较两个面是否相同
IKS_BOOL CheckSurfaceEqual(const BPSurface &surface1, const BPSurface &surface2, float fDisZero=ZERO, float fNormZero=ZERO, float fAngleZero=ZERO);

// 通过平行投影信息获取摄像机数据
void GetCameraDataByOrthoInfo(BPCAMERA &stuCameraData, const BPBASEFLOAT3 &vEyePos, const BPBASEFLOAT3 &vViewDir, const BPBASEFLOAT3 &vUp, float fWidth, float fHeight);
// 通过摄像机的透视投影数据计算平行投影的宽高
void CalcCameraOrthoWidthHeight(const BPCAMERA &stuCameraData, float *pWidth, float *pHeight);

namespace IKS_MATH
{
// 通过矩阵修改模型描述
IKS_BOOL ModifyMeshDescByMatrix(BP_MESH_DESC &stuMeshDesc, const BPBASEMATRIX &matrix);
// 通过矩阵修改模型描述_曲面精确数据
void ModifyMeshDescByMatrix_Surface(BP_MESH_DESC &stuMeshDesc, const BPBASEMATRIX &matrix);
// 通过矩阵修改模型描述_曲面精确数据
void ModifyMeshDescByMatrix_Surface(BPSurface &surf, const BPBASEMATRIX &matrix, float fScale=-1.0f);
// 通过矩阵修改模型描述_曲线精确数据
void ModifyMeshDescByMatrix_Curve(BP_MESH_DESC &stuMeshDesc, const BPBASEMATRIX &matrix);
// 通过矩阵修改模型描述_曲线精确数据
void ModifyMeshDescByMatrix_Curve(BPCurve &curve, const BPBASEMATRIX &matrix, float fScale=-1.0f);
}
