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
// �궨��

//===================================================================================================
// �ṹ��

//===================================================================================================
// �Զ��幦�ܺ���

// �任��������_����������ϵ����
void ConvertMatrixLHRH(BPBASEMATRIX &matrix);
// �任��������_����ϵYZ�ụ��
void ConvertMatrixAxisYZ(BPBASEMATRIX &matrix);

// �任ģ������_����������ϵ����
void ConvertMeshLHRH(BP_MESH_DESC &mesh);
// �任ģ������_����������ϵ����
void ConvertModelLHRH(BP_MODEL_SAVEDATA &stuModelData);
// �任ģ������_����ϵYZ�ụ��
void ConvertModelAxisYZ(BP_MODEL_SAVEDATA &stuModelData);
// �任ģ������_������_����������ϵ����
void ConvertModelLHRH_SurfaceData(BPSurface &stuSurface);
// �任ģ������_������_����������ϵ����
void ConvertModelLHRH_CurveData(BPCurve &stuBPCurve);
// �任ģ������_������_����ϵYZ�ụ��
void ConvertModelAxisYZ_SurfaceData(BPSurface &stuSurface);
// �任ģ������_������_����ϵYZ�ụ��
void ConvertModelAxisYZ_CurveData(BPCurve &stuBPCurve);

// �����Χ��(�����Χ�к��Ӽ���Χ��)
void ComputeBoundBox(BP_MESH_DESC &stuMeshDesc);
// �����Χ��
void ComputeBoundBox(const BP_MESH_DESC &stuMeshDesc, BOUNDBOX &box);
// �����Χ��(�����Χ�к��Ӽ���Χ��)
void ComputeBoundBox(BP_MODEL_SAVEDATA &stuModelDesc);
// �����Χ��
void ComputeBoundBox(const BP_MODEL_SAVEDATA &stuModelDesc, BOUNDBOX &box);
// �����Χ��(ֻ��ָ����������Χ��)
void ComputeBoundBox(const BP_MESH_DESC &stuMeshDesc, IKS_UINT uVertStartIndex, IKS_UINT uVertCount, BOUNDBOX &box);
// �����Χ��(ֻ��ָ����������Χ��)
void ComputeBoundBox(const BP_MODEL_SAVEDATA &stuModelDesc, IKS_UINT uVertStartIndex, IKS_UINT uVertCount, BOUNDBOX &box);
// �����Χ��(ֻ��ָ����������Χ��)
void ComputeBoundBox(BOUNDBOX &box, const BP_MESH_DESC &stuMeshDesc, IKS_UINT *arrVertStartIndex, IKS_UINT uVertCount);
// �����Χ��(ֻ��ָ����������Χ��)
void ComputeBoundBox(BOUNDBOX &box, const BP_MODEL_SAVEDATA &stuModelDesc, IKS_UINT *arrVertStartIndex, IKS_UINT uVertCount);
// �����Χ��(�����Χ�к��Ӽ���Χ��)���Ӽ���Χ���ڴ��ɵ������Ӽ����뼰�ͷ�,�Ӽ���Χ�����������ģ���Ӽ���ͬ��
void ComputeBoundBox(const BP_MESH_DESC &stuMeshDesc, BOUNDBOX &stuEntireBox, BOUNDBOX *arrSubBox);
// �����Χ��(�����Χ�к��Ӽ���Χ��)���Ӽ���Χ���ڴ��ɵ������Ӽ����뼰�ͷ�,�Ӽ���Χ�����������ģ���Ӽ���ͬ��
void ComputeBoundBox(const BP_MODEL_SAVEDATA &stuModelDesc, BOUNDBOX &stuEntireBox, BOUNDBOX *arrSubBox);
// �����Χ��
void ComputeBoundBox(const BOUNDBOX &boxIn, const BPBASEFLOAT3 &vPos, BOUNDBOX &boxOut);
// �����Χ��
void ComputeBoundBox(const BOUNDBOX *arrBox, IKS_UINT uNum, BOUNDBOX &boxOut);
// ͨ���Ӽ���Χ�м��������Χ��
void ComputeBoundBoxBySubBox(BP_MESH_DESC &stuMeshDesc);
// ͨ���Ӽ���Χ�м��������Χ��
void ComputeBoundBoxBySubBox(BP_MODEL_SAVEDATA &stuModelDesc);
// ��֤���Ƿ��ڰ�Χ����
IKS_BOOL CheckPtInBox(const BPBASEFLOAT3 &pt, const BOUNDBOX &stuEntireBox);
// ��֤���Ƿ��ڰ�Χ����
IKS_BOOL CheckPtInBoundShpere(const BPBASEFLOAT3 &pt, const BOUNDSPHERE &stuBSphere, float fZero=-1.0f);
// ���������Χ��
IKS_BOOL CalculateEntireBoundBox(const std::vector<BOUNDBOX> &arrBox, const std::vector<BPBASEMATRIX> &arrMatLocalWorld, BOUNDBOX &stuEntireBox);

// �ϲ�ģ�͵Ķ�����������
IKS_BOOL BlendMeshVertexIndexData(const BP_MESH_DESC &mesh1, const BP_MESH_DESC &mesh2, BP_MESH_DESC &meshOut);
// ����ģ�����ظ�λ�õĶ���(���ص������Ƕ�ԭ���������,��ͬλ�õĶ���������ͬ)
IKS_BOOL CalcMeshNoDuplicatePosVertices(const BP_MESH_DESC &mesh, IKS_DWORD *arrVertIndex, std::vector<IKS_UINT> &arrNoDupPosVertIndex, float fZero=-1.0f);

// ����ģ���������������
IKS_BOOL MendModelTexCoords(BP_MODEL_SAVEDATA &stuModelData, int nCoordsType=BPCST_RIGHTHAND);
// �Ż�ģ��
void OptimizeModelData(BP_MODEL_SAVEDATA &stuModelData, BPBASEMATRIX &matModelLocal, BOUNDBOX &box);
// �Ż�ģ��_��������ƫ��ֵ������߾�ȷ����
void OptimizeModelData_OffsetSurfaceEdgeData(BP_MODEL_SAVEDATA &stuModelData, const BPBASEFLOAT3 &vCenterOffset);
// �Ż�ģ��_��������ƫ��ֵ�����澫ȷ����
void OptimizeModelData_OffsetSurfaceData(BPSurface &stuSurface, const BPBASEFLOAT3 &vCenterOffset);
// �Ż�ģ��_��������ƫ��ֵ�����߾�ȷ����
void OptimizeModelData_OffsetEdgeData(BPCurve &stuBPCurve, const BPBASEFLOAT3 &vCenterOffset);
// �Ż�ģ��_�澫ȷ����
void OptimizeModelData_SurfaceData(BP_MODEL_SAVEDATA &stuModelData);
// �Ż�����������ԭ��
void OptimizeModelData_SurfaceDataOrigin(BPSurface *pSurface, const BOUNDBOX &box);
// �Ż������淨ʸ����
void OptimizeModelData_SurfaceDataAxisZ(BPSurface *pSurface, BPBASEFLOAT3 vTriFaceVec);

// ��ȡģ���Ӽ���Ӧ����������
IKS_BOOL GetMeshSubsetSurfData(const BP_MESH_DESC &mesh, IKS_UINT uSubsetIndex, BPSurface &surf);
// ��ȡģ���Ӽ���Ӧ����������(���Ӽ�û�ж�Ӧ�������򷵻�BPSURFTYPE_UNKOWN)
int GetMeshSubsetSurfType(const BP_MESH_DESC &mesh, IKS_UINT uSubsetIndex);
// ��ȡģ������Ĺؼ�λ��(����ԭ��λ��)
BPBASEFLOAT3 GetMeshSurfKeyPos(const BP_MESH_DESC &mesh, IKS_UINT uSurfIndex);
// ��ȡģ���Ӽ���Ӧ����������
IKS_BOOL GetMeshSubsetCurveData(const BP_MESH_DESC &mesh, IKS_UINT uSubsetIndex, BPCurve &curve);
// ��ȡģ���Ӽ���Ӧ����������(���Ӽ�û�ж�Ӧ�������򷵻�BPCURVETYPE_UNKOWN)
int GetMeshSubsetCurveType(const BP_MESH_DESC &mesh, IKS_UINT uSubsetIndex);
// ��ȡģ�����ߵĹؼ�λ��
BPBASEFLOAT3 GetMeshCurveKeyPos(const BP_MESH_DESC &mesh, IKS_UINT uCurveIndex);

// ����ģ�������Ƿ����
IKS_BOOL CheckMeshDataValid(const BP_MESH_DESC *pMeshDesc);
// ��֤ģ�������Ƿ���ȷ
IKS_BOOL CheckModelValid(const BP_MODEL_SAVEDATA &stuModelData);
// ����ģ���Ӽ������Ƿ����
IKS_BOOL CheckMdlSubsetValid(const BP_MODEL_SAVEDATA &stuModelData, IKS_UINT uSubsetIndex);

// �ж�����ģ���Ӽ��Ƿ���ͬ
IKS_BOOL CheckSVMeshSubsetDataEqual(const BP_MESH_DESCSubset *pSubset1, const BP_MESH_DESCSubset *pSubset2);
// �ж�����ģ���Ƿ���ͬ
IKS_BOOL CheckSVMeshDataEqual(const BP_MESH_DESC *pMesh1, const BP_MESH_DESC *pMesh2);
// �Ƚ����������Ƿ���ͬ
IKS_BOOL CheckCurveEqual(const BPCurve &curve1, const BPCurve &curve2, float fDisZero=ZERO, float fNormZero=ZERO, float fAngleZero=ZERO);
// �Ƚ��������Ƿ���ͬ
IKS_BOOL CheckSurfaceEqual(const BPSurface &surface1, const BPSurface &surface2, float fDisZero=ZERO, float fNormZero=ZERO, float fAngleZero=ZERO);

// ͨ��ƽ��ͶӰ��Ϣ��ȡ���������
void GetCameraDataByOrthoInfo(BPCAMERA &stuCameraData, const BPBASEFLOAT3 &vEyePos, const BPBASEFLOAT3 &vViewDir, const BPBASEFLOAT3 &vUp, float fWidth, float fHeight);
// ͨ���������͸��ͶӰ���ݼ���ƽ��ͶӰ�Ŀ��
void CalcCameraOrthoWidthHeight(const BPCAMERA &stuCameraData, float *pWidth, float *pHeight);

namespace IKS_MATH
{
// ͨ�������޸�ģ������
IKS_BOOL ModifyMeshDescByMatrix(BP_MESH_DESC &stuMeshDesc, const BPBASEMATRIX &matrix);
// ͨ�������޸�ģ������_���澫ȷ����
void ModifyMeshDescByMatrix_Surface(BP_MESH_DESC &stuMeshDesc, const BPBASEMATRIX &matrix);
// ͨ�������޸�ģ������_���澫ȷ����
void ModifyMeshDescByMatrix_Surface(BPSurface &surf, const BPBASEMATRIX &matrix, float fScale=-1.0f);
// ͨ�������޸�ģ������_���߾�ȷ����
void ModifyMeshDescByMatrix_Curve(BP_MESH_DESC &stuMeshDesc, const BPBASEMATRIX &matrix);
// ͨ�������޸�ģ������_���߾�ȷ����
void ModifyMeshDescByMatrix_Curve(BPCurve &curve, const BPBASEMATRIX &matrix, float fScale=-1.0f);
}
