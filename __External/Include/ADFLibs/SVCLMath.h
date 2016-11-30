//===================================================================================================
// File:
//		SVCLMath.h
// Summary:
//		Provides Math method.
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

#include "SVBaseDef.h"

//===================================================================================================
// �궨��

#ifndef max
#define max(a, b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a, b)  (((a) < (b)) ? (a) : (b))
#endif

namespace IKS_MATH
{

//===================================================================================================
// �ṹ��

//===================================================================================================
// �Զ��幦�ܺ���

SVBASEDOUBLE3* BPVec3Normalize(SVBASEDOUBLE3 *pOut,
							  const SVBASEDOUBLE3 *pV);
SVBASEDOUBLE2* BPVec2Normalize(SVBASEDOUBLE2 *pOut,
							   const SVBASEDOUBLE2 *pV);

double BPVec3Dot(const SVBASEDOUBLE3 * pV1,const SVBASEDOUBLE3 * pV2);
double BPVec2Dot(const SVBASEDOUBLE2 * pV1,const SVBASEDOUBLE2 * pV2);

double BPVec3Length( const SVBASEDOUBLE3 *pV );
double BPVec2Length( const SVBASEDOUBLE2 *pV );

SVBASEDOUBLE3* BPVec3Cross(SVBASEDOUBLE3 *pOut,
						  const SVBASEDOUBLE3 *pV1,
						  const SVBASEDOUBLE3 *pV2);
double BPVec2Cross(const SVBASEDOUBLE2 *pV1, const SVBASEDOUBLE2 *pV2);

SVBASEDOUBLE4 * BPVec4Transform(SVBASEDOUBLE4 *pOut, const SVBASEDOUBLE4 *pV, const SVBASEMATRIX *pM);

SVBASEDOUBLE3* BPVec3TransformCoord(SVBASEDOUBLE3 *pOut, const SVBASEDOUBLE3 *pV, const SVBASEMATRIX *pM);

SVBASEDOUBLE3* BPVec3TransformNormal(SVBASEDOUBLE3 *pOut, const SVBASEDOUBLE3 *pV, const SVBASEMATRIX *pM);

// �жϾ����Ƿ�Ϊ��λ����
IKS_BOOL BPMatrixIsIdentity(const SVBASEMATRIX* pM);
// ��λ������
IKS_BOOL BPMatrixIdentity(SVBASEMATRIX* pM);
// �������
SVBASEMATRIX* BPMatrixMultiply(const SVBASEMATRIX *pM1, const SVBASEMATRIX *pM2, SVBASEMATRIX *pMOut);
// ��������(ֻ��Եȱ������š���ת��ƽ�Ƶļ�������)
IKS_BOOL BPSRTMatrixInverse(SVBASEMATRIX* pOut, const SVBASEMATRIX* pM);
// �������ž���
void BPMatrixScaling(SVBASEMATRIX *pMScale, double sx, double sy, double sz);
// ����ƫ�ƾ���
void BPMatrixTranslation(SVBASEMATRIX *pMTran, double x, double y, double z);
// ������ĳ����ת�ľ���
void BPMatrixRotationAxis(SVBASEMATRIX *pOut, const SVBASEDOUBLE3 *pV, double dAngle);
// ������ָ������ת�ľ���
SVBASEMATRIX* BPMatrixRotationAxis(SVBASEMATRIX *pMatrix, const SVBASEDOUBLE3 *pAxisPt, const SVBASEDOUBLE3 *pAxisDir, double dRotValue);

//===================================================================================================
// �Զ��幦�ܺ���

// ������λ�ü��
double CalculateDistance(const SVBASEDOUBLE3 *pPos1, const SVBASEDOUBLE3 *pPos2);
// ������λ�ü���ƽ��
double CalculateDistanceSquare(const SVBASEDOUBLE3 *pPos1, const SVBASEDOUBLE3 *pPos2);

IKS_BOOL IsEqualVector(const SVBASEDOUBLE3 *pV1, const SVBASEDOUBLE3 *pV2);

// ������ֽ�Ϊ������������������������Ȼ�����������;���е�һ������Ϊ���ž���,����������Ϊƽ�ƾ���,�ڶ����������Ϊ��ת����
void DecomposeMatrix(const SVBASEMATRIX &matCombine, SVBASEMATRIX *pScale=NULL, SVBASEMATRIX *pMaybeRot=NULL, SVBASEMATRIX *pTrans=NULL);

// ��ȡ��ԭʼ����ϵ�任Ϊ��������ϵ��ת������
void GetCoordsTransformMatrix(const SVBASEDOUBLE3 &vOrigin, const SVBASEDOUBLE3 &vAxisX, 
							  const SVBASEDOUBLE3 &vAxisY, const SVBASEDOUBLE3 &vAxisZ, SVBASEMATRIX &matrix);
// ��ȡ����������ϵ�任Ϊԭʼ����ϵ��ת������
void GetCoordsTransformMatrixInv(const SVBASEDOUBLE3 &vOrigin, const SVBASEDOUBLE3 &vAxisX, 
							  const SVBASEDOUBLE3 &vAxisY, const SVBASEDOUBLE3 &vAxisZ, SVBASEMATRIX &matrix);
// ��ȡ��Դ����ϵ�任ΪĿ������ϵ��ת������
void GetCoordsTransformMatrix(const SVBASEDOUBLE3 &vSrcOrigin, const SVBASEDOUBLE3 &vSrcAxisX, const SVBASEDOUBLE3 &vSrcAxisY, const SVBASEDOUBLE3 &vSrcAxisZ, 
							  const SVBASEDOUBLE3 &vTgtOrigin, const SVBASEDOUBLE3 &vTgtAxisX, const SVBASEDOUBLE3 &vTgtAxisY, const SVBASEDOUBLE3 &vTgtAxisZ, SVBASEMATRIX &matrix);
// ��ȡ��ԭʼԲ���任ΪĿ��Բ����ת������(ԭʼԲ��:�뾶1,vec1ΪX��,vec2ΪY��,��ʼ����Ϊ0)
void GetArcTransformMatrix(const SVBASEDOUBLE3 &vOrigin, const SVBASEDOUBLE3 &vVector1, const SVBASEDOUBLE3 &vVector2, double dStartAngle, double dEndAngle, double dRadius, SVBASEMATRIX *pScaleMatrix=NULL, SVBASEMATRIX *pRotTransMatrix=NULL);

// ��ȡһ����ֱ����
IKS_BOOL GetVerticalVector(const SVBASEDOUBLE3 &vSrcVector, SVBASEDOUBLE3 &vDstVector);
// ��һ����ͶӰ��һ��ֱ����
void ProjectPtToLine(const SVBASEDOUBLE3 &vLinePt, const SVBASEDOUBLE3 &vLineDir, const SVBASEDOUBLE3 &vSrcPt, SVBASEDOUBLE3 &vPrjPt);
// ��һ����ͶӰ��һ��ֱ����
void ProjectPtToLine(const SVBASEDOUBLE2 &vLinePt, const SVBASEDOUBLE2 &vLineDir, const SVBASEDOUBLE2 &vSrcPt, SVBASEDOUBLE2 &vPrjPt);
// ��һ����ͶӰ��һ��ƽ����
void ProjectPtToPlane(const SVBASEDOUBLE3 &vPlanePt, const SVBASEDOUBLE3 &vPlaneDir, const SVBASEDOUBLE3 &vSrcPt, SVBASEDOUBLE3 &vPrjPt);
// ��һ��ֱ��ͶӰ��һ��ƽ����
IKS_BOOL ProjectLineToPlane(const SVBASEDOUBLE3 &vPlanePt, const SVBASEDOUBLE3 &vPlaneDir, const SVBASEDOUBLE3 &vSrcLinePt, const SVBASEDOUBLE3 &vSrcLineDir, SVBASEDOUBLE3 &vPrjLinePt, SVBASEDOUBLE3 &vPrjLineDir);
// ���Ƿ���ֱ����
IKS_BOOL IsPointOnLine(const SVBASEDOUBLE3 &vLinePt, const SVBASEDOUBLE3 &vLineDir, const SVBASEDOUBLE3 &vPt);
// ���Ƿ���ֱ����
IKS_BOOL IsPointOnLine(const SVBASEDOUBLE2 &vLinePt, const SVBASEDOUBLE2 &vLineDir, const SVBASEDOUBLE2 &vPt);
// ���Ƿ���ƽ����
IKS_BOOL IsPointOnPlane(const SVBASEDOUBLE3 &vPlanePt, const SVBASEDOUBLE3 &vPlaneDir, const SVBASEDOUBLE3 &vPt, double dZero=-1.0);
// ֱ���Ƿ���ƽ����
IKS_BOOL IsLineOnPlane(const SVBASEDOUBLE3 &vLinePt, const SVBASEDOUBLE3 &vLineDir, const SVBASEDOUBLE3 &vPlanePt, const SVBASEDOUBLE3 &vPlaneDir);
// �������Ƿ�ͬ��
IKS_BOOL IsVecSameDir(const SVBASEDOUBLE3 &v1, const SVBASEDOUBLE3 &v2);
// �������Ƿ���
IKS_BOOL IsVecReverseDir(const SVBASEDOUBLE3 &v1, const SVBASEDOUBLE3 &v2);
// �������Ƿ�ֱ
IKS_BOOL IsVecVertical(const SVBASEDOUBLE3 &v1, const SVBASEDOUBLE3 &v2);
// ��ƽ���Ƿ���ͬ(����)
IKS_BOOL IsSamePlane(const SVBASEDOUBLE3 &vPlanePt1, const SVBASEDOUBLE3 &vPlaneDir1, const SVBASEDOUBLE3 &vPlanePt2, const SVBASEDOUBLE3 &vPlaneDir2, double dDisZero=-1.0, double dAngleZero=-1.0);
// ��ָ���Ὣָ��������ת����һָ������,��ȡ��ת�Ƕ�(����ֵ);���޷���ת�ɹ��򷵻�FALSE
IKS_BOOL RotateAxisFromVecToVec(const SVBASEDOUBLE3 &vAxis, const SVBASEDOUBLE3 &v1, const SVBASEDOUBLE3 &v2, double *pRotValue);
// ����ֱ�ߺ�ƽ��Ľ���,�޽����򷵻�FALSE
IKS_BOOL CalcIntersectOfLinePlane(const SVBASEDOUBLE3 &vLinePt, const SVBASEDOUBLE3 &vLineDir, const SVBASEDOUBLE3 &vPlanePt, const SVBASEDOUBLE3 &vPlaneDir, SVBASEDOUBLE3 *pIntersectPt, IKS_BOOL *pIsLineOnPlane=NULL);
// ������ƽ��ĵĽ���,�޽����򷵻�FALSE
IKS_BOOL CalcIntersectOfTwoPlane(const SVBASEDOUBLE3 &vPt1, const SVBASEDOUBLE3 &vDir1, const SVBASEDOUBLE3 &vPt2, const SVBASEDOUBLE3 &vDir2, SVBASEDOUBLE3 *pIntersectPt, SVBASEDOUBLE3 *pIntersectDir, IKS_BOOL *pIsCoPlane=NULL);
// ������ֱ�ߵĽ��㣬�޽����򷵻�FALSE
IKS_BOOL CalcIntersectOfTwoLine(const SVBASEDOUBLE3 &vPt1, const SVBASEDOUBLE3 &vDir1, const SVBASEDOUBLE3 &vPt2, const SVBASEDOUBLE3 &vDir2, SVBASEDOUBLE3 *pIntersectPt, IKS_BOOL *pCollinear=NULL);
// �������߶εĽ��㣬�޽����򷵻�FALSE(�߶α����ཻ�����ӳ����ཻ)
IKS_BOOL CalcIntersectOfTwoLine(const SVBASEDOUBLE2 &vLine1Start, const SVBASEDOUBLE2 &vLine1End, const SVBASEDOUBLE2 &vLine2Start, const SVBASEDOUBLE2 &vLine2End, SVBASEDOUBLE2 *pIntersectPt, IKS_BOOL *pParallel=NULL, IKS_BOOL *pCollinear=NULL);
// ������ֱ�ߵļнǺ;���
void CalcAngleDistOfTwoLine(const SVBASEDOUBLE3 &vPt1, const SVBASEDOUBLE3 &vDir1, const SVBASEDOUBLE3 &vPt2, const SVBASEDOUBLE3 &vDir2, double &dAngle, double &dDist, SVBASEDOUBLE3 *pIntersectPtOnLine1=NULL, SVBASEDOUBLE3 *pIntersectPtOnLine2=NULL);
// �����������������߶��ϵĵ�
void CalcNearestPtOnLine(const SVBASEDOUBLE3 &vLineStart, const SVBASEDOUBLE3 &vLineEnd, const SVBASEDOUBLE3 &vRefPt, SVBASEDOUBLE3 &vOutPt);
// �����������������߶��ϵĵ�
void CalcNearestPtOnLine(const SVBASEDOUBLE2 &vLineStart, const SVBASEDOUBLE2 &vLineEnd, const SVBASEDOUBLE2 &vRefPt, SVBASEDOUBLE2 &vOutPt);

// ��ȡ����������Sin��Cos��ֵ
double GetCorrectSinCosValue(double dCosValue);
// ���㷴����ֵ
double BPCalcArcCos(double dValue);
// ���㷴����ֵ
double BPCalcArcSin(double dValue);
// ��ȡ��׼����ֵ(0~2Pi)
double GetStandardRadian_2Pi(double dRadian);
// ��ȡ��׼����ֵ(-Pi~Pi)
double GetStandardRadian_MinusPlusPi(double dRadian);


//===================================================================================================
// �Զ��幦�ܺ���

// ������ά������YZ����
void BPSwitchVec3YZ(BPBASEFLOAT3 &v);
// ���
float BPVec3Dot(const BPBASEFLOAT3 *pV1, const BPBASEFLOAT3 *pV2);
// ���
float BPVec2Dot(const BPBASEFLOAT2 *pV1, const BPBASEFLOAT2 *pV2);
// ��������
float BPVec3Length( const BPBASEFLOAT3 *pV );
// ���
void BPVec3Cross(BPBASEFLOAT3 *pOut, const BPBASEFLOAT3 *pV1, const BPBASEFLOAT3 *pV2);
// ������λ��
void BPVec3Normalize(BPBASEFLOAT3 *pOut, const BPBASEFLOAT3 *pV);
// ������λ��
void BPVec2Normalize(BPBASEFLOAT2 *pOut, const BPBASEFLOAT2 *pV);
// ��ά�����ľ���任
BPBASEFLOAT4* BPVec4Transform(BPBASEFLOAT4 *pOut, const BPBASEFLOAT4 *pV, const BPBASEMATRIX *pM);
// ��ά�����ľ���任
BPBASEFLOAT3* BPVec3TransformCoord(BPBASEFLOAT3 *pOut, const BPBASEFLOAT3 *pV, const BPBASEMATRIX *pM);
// ��ά��ʸ�ľ���任
BPBASEFLOAT3* BPVec3TransformNormal(BPBASEFLOAT3 *pOut, const BPBASEFLOAT3 *pV, const BPBASEMATRIX *pM);
// �жϾ����Ƿ�Ϊ��λ����
IKS_BOOL BPMatrixIsIdentity(const BPBASEMATRIX* pM);
// ��λ������
IKS_BOOL BPMatrixIdentity(BPBASEMATRIX* pM);
// �������
BPBASEMATRIX* BPMatrixMultiply(const BPBASEMATRIX *pM1, const BPBASEMATRIX *pM2, BPBASEMATRIX *pMOut);
// ��������(ֻ��Եȱ������š���ת��ƽ�Ƶļ�������)
IKS_BOOL BPSRTMatrixInverse(BPBASEMATRIX* pOut, const BPBASEMATRIX* pM);
// �������ž���
void BPMatrixScaling(BPBASEMATRIX *pMScale, float sx, float sy, float sz);
// ����ƫ�ƾ���
void BPMatrixTranslation(BPBASEMATRIX *pMTran, float x, float y, float z);
// ������ĳ����ת�ľ���
void BPMatrixRotationAxis(BPBASEMATRIX *pOut, const BPBASEFLOAT3 *pV, float fAngle);
// ������ָ������ת�ľ���
BPBASEMATRIX* BPMatrixRotationAxis(BPBASEMATRIX *pMatrix, const BPBASEFLOAT3 *pAxisPt, const BPBASEFLOAT3 *pAxisDir, float fRotValue);
// ������X����ת�ľ���
void BPMatrixRotationX(BPBASEMATRIX *pOut, float fAngle);
// ������Y����ת�ľ���
void BPMatrixRotationY(BPBASEMATRIX *pOut, float fAngle);
// ������Z����ת�ľ���
void BPMatrixRotationZ(BPBASEMATRIX *pOut, float fAngle);

//===================================================================================================
// �Զ��幦�ܺ���

// ��ȡ����
float GetSign(float fValue);

// ��ȡ��������
float CalculateVectorLenghth(const BPBASEFLOAT2 *pVec);
// ��ȡ��������
float CalculateVectorLenghth(const BPBASEFLOAT3 *pVec);
// ��ȡ��������
float CalculateVectorLenghth(const BPBASEFLOAT4 *pVec);

// ������λ�ü��
float CalculateDistance(const BPBASEFLOAT3 *pPos1, const BPBASEFLOAT3 *pPos2);
// ������λ�ü��
float CalculateDistance(const BPBASEFLOAT2 *pPos1, const BPBASEFLOAT2 *pPos2);

// ��������жϺ���(���Ǿ���)
IKS_BOOL IsEqualMatrix(const BPBASEMATRIX *pMatrix1, const BPBASEMATRIX *pMatrix2, float fZero=ZERO);
// ������תƽ�ƾ�����ȵ��жϺ���(���Ǿ���)
IKS_BOOL IsEqualScaleRotTransMatrix(const BPBASEMATRIX *pMatrix1, const BPBASEMATRIX *pMatrix2, float fScaleRotZero=ZERO, float fTransZero=EPSILON);

// ��������жϺ���(���Ǿ���)
IKS_BOOL IsEqualVector(const BPBASEFLOAT2 *pV1, const BPBASEFLOAT2 *pV2);
IKS_BOOL IsEqualVector(const BPBASEFLOAT3 *pV1, const BPBASEFLOAT3 *pV2);
IKS_BOOL IsEqualVector(const BPBASEFLOAT4 *pV1, const BPBASEFLOAT4 *pV2);
IKS_BOOL IsEqualVectorEx(const BPBASEFLOAT2 *pV1, const BPBASEFLOAT2 *pV2, float fZero);
IKS_BOOL IsEqualVectorEx(const BPBASEFLOAT3 *pV1, const BPBASEFLOAT3 *pV2, float fZero);
IKS_BOOL IsEqualVectorEx(const BPBASEFLOAT4 *pV1, const BPBASEFLOAT4 *pV2, float fZero);

// ������ֽ�Ϊ������������������������Ȼ�����������;���е�һ������Ϊ���ž���,����������Ϊƽ�ƾ���,�ڶ����������Ϊ��ת����
void DecomposeMatrix(const BPBASEMATRIX &matCombine, BPBASEMATRIX *pScale=NULL, BPBASEMATRIX *pMaybeRot=NULL, BPBASEMATRIX *pTrans=NULL);
// ����ת�������Ϊ(��Z����ת->��X����ת->��Y����ת)�ľ���
IKS_BOOL AnalyseRotMatrix(const BPBASEMATRIX &matRot, float &fRotZ, float &fRotX, float &fRotY, IKS_BOOL bIsHeadDown=FALSE);
// ����ת�������Ϊ(��Z����ת->��X����ת->��Y����ת)�ľ�����X��Y����תʱ,ʹ�õ�����Z��X����ת�������λ�ã�
IKS_BOOL AnalyseRotMatrixForLocalZXY(const BPBASEMATRIX &matRot, float &fRotZ, float &fRotX, float &fRotY, IKS_BOOL bIsHeadDown=FALSE);
// ����ת�������Ϊ��ĳ��(��ԭ��)��ת�ľ���
IKS_BOOL AnalyseRotMatrix(const BPBASEMATRIX &matRot, BPBASEFLOAT3 &vAxis, float &fRotAxisValue);

// ��ȡ��Դ��任ΪĿ�����ת������
void GetAxisTransformMatrix(const BPBASEFLOAT3 &vSrcOrigin, const BPBASEFLOAT3 &vSrcAxis, 
							const BPBASEFLOAT3 &vTgtOrigin, const BPBASEFLOAT3 &vTgtAxis, BPBASEMATRIX &matrix);
// ��ȡ��ԭʼ����ϵ�任Ϊ��������ϵ��ת������
void GetCoordsTransformMatrix(const BPBASEFLOAT3 &vOrigin, const BPBASEFLOAT3 &vAxisX, 
							   const BPBASEFLOAT3 &vAxisY, const BPBASEFLOAT3 &vAxisZ, BPBASEMATRIX &matrix);
// ��ȡ��Դ����ϵ�任ΪĿ������ϵ��ת������
void GetCoordsTransformMatrix(const BPBASEFLOAT3 &vSrcOrigin, const BPBASEFLOAT3 &vSrcAxisX, const BPBASEFLOAT3 &vSrcAxisY, const BPBASEFLOAT3 &vSrcAxisZ, 
							  const BPBASEFLOAT3 &vTgtOrigin, const BPBASEFLOAT3 &vTgtAxisX, const BPBASEFLOAT3 &vTgtAxisY, const BPBASEFLOAT3 &vTgtAxisZ, BPBASEMATRIX &matrix);
// ��ȡ��ԭʼԲ���任ΪĿ��Բ����ת������(ԭʼԲ��:�뾶1,vec1ΪX��,vec2ΪY��,��ʼ����Ϊ0)
void GetArcTransformMatrix(const BPBASEFLOAT3 &vOrigin, const BPBASEFLOAT3 &vVector1, const BPBASEFLOAT3 &vVector2, float fStartAngle, float fEndAngle, float fRadius, BPBASEMATRIX *pScaleMatrix=NULL, BPBASEMATRIX *pRotTransMatrix=NULL);

// ��ȡһ����ֱ����
IKS_BOOL GetVerticalVector(const BPBASEFLOAT3 &vSrcVector, BPBASEFLOAT3 &vDstVector);
// ��һ����ͶӰ��һ��ֱ����
void ProjectPtToLine(const BPBASEFLOAT3 &vLinePt, const BPBASEFLOAT3 &vLineDir, const BPBASEFLOAT3 &vSrcPt, BPBASEFLOAT3 &vPrjPt);
// ��һ����ͶӰ��һ��ֱ����
void ProjectPtToLine(const BPBASEFLOAT2 &vLinePt, const BPBASEFLOAT2 &vLineDir, const BPBASEFLOAT2 &vSrcPt, BPBASEFLOAT2 &vPrjPt);
// ��һ����ͶӰ��һ��ƽ����
void ProjectPtToPlane(const BPBASEFLOAT3 &vPlanePt, const BPBASEFLOAT3 &vPlaneDir, const BPBASEFLOAT3 &vSrcPt, BPBASEFLOAT3 &vPrjPt);
// ��һ��ֱ��ͶӰ��һ��ƽ����
IKS_BOOL ProjectLineToPlane(const BPBASEFLOAT3 &vPlanePt, const BPBASEFLOAT3 &vPlaneDir, const BPBASEFLOAT3 &vSrcLinePt, const BPBASEFLOAT3 &vSrcLineDir, BPBASEFLOAT3 &vPrjLinePt, BPBASEFLOAT3 &vPrjLineDir);
// ���Ƿ���ֱ����
IKS_BOOL IsPointOnLine(const BPBASEFLOAT3 &vLinePt, const BPBASEFLOAT3 &vLineDir, const BPBASEFLOAT3 &vPt);
// ���Ƿ���ƽ����
IKS_BOOL IsPointOnPlane(const BPBASEFLOAT3 &vPlanePt, const BPBASEFLOAT3 &vPlaneDir, const BPBASEFLOAT3 &vPt, float fZero=-1.0f);
// ֱ���Ƿ���ƽ����
IKS_BOOL IsLineOnPlane(const BPBASEFLOAT3 &vLinePt, const BPBASEFLOAT3 &vLineDir, const BPBASEFLOAT3 &vPlanePt, const BPBASEFLOAT3 &vPlaneDir);
// �������Ƿ�ͬ��
IKS_BOOL IsVecSameDir(const BPBASEFLOAT3 &v1, const BPBASEFLOAT3 &v2, float fZero=-1.0f);
// �������Ƿ���
IKS_BOOL IsVecReverseDir(const BPBASEFLOAT3 &v1, const BPBASEFLOAT3 &v2, float fZero=-1.0f);
// �������Ƿ�ֱ
IKS_BOOL IsVecVertical(const BPBASEFLOAT3 &v1, const BPBASEFLOAT3 &v2);
// ��ƽ���Ƿ���ͬ(����)
IKS_BOOL IsSamePlane(const BPBASEFLOAT3 &vPlanePt1, const BPBASEFLOAT3 &vPlaneDir1, const BPBASEFLOAT3 &vPlanePt2, const BPBASEFLOAT3 &vPlaneDir2, float fDisZero=-1.0f, float fAngleZero=-1.0f);
// ��ָ���Ὣָ��������ת����һָ������,��ȡ��ת�Ƕ�(����ֵ);���޷���ת�ɹ��򷵻�FALSE
IKS_BOOL RotateAxisFromVecToVec(const BPBASEFLOAT3 &vAxis, const BPBASEFLOAT3 &v1, const BPBASEFLOAT3 &v2, float *pRotValue);
// ����ֱ�ߺ�ƽ��Ľ���,�޽����򷵻�FALSE
IKS_BOOL CalcIntersectOfLinePlane(const BPBASEFLOAT3 &vLinePt, const BPBASEFLOAT3 &vLineDir, const BPBASEFLOAT3 &vPlanePt, const BPBASEFLOAT3 &vPlaneDir, BPBASEFLOAT3 *pIntersectPt, IKS_BOOL *pIsLineOnPlane=NULL);
// ������ƽ��ĵĽ���,�޽����򷵻�FALSE
IKS_BOOL CalcIntersectOfTwoPlane(const BPBASEFLOAT3 &vPt1, const BPBASEFLOAT3 &vDir1, const BPBASEFLOAT3 &vPt2, const BPBASEFLOAT3 &vDir2, BPBASEFLOAT3 *pIntersectPt, BPBASEFLOAT3 *pIntersectDir, IKS_BOOL *pIsCoPlane=NULL);
// ������ֱ�ߵĽ��㣬�޽����򷵻�FALSE
IKS_BOOL CalcIntersectOfTwoLine(const BPBASEFLOAT3 &vPt1, const BPBASEFLOAT3 &vDir1, const BPBASEFLOAT3 &vPt2, const BPBASEFLOAT3 &vDir2, BPBASEFLOAT3 *pIntersectPt, IKS_BOOL *pCollinear=NULL);
// ������ֱ�ߵļнǺ;���
void CalcAngleDistOfTwoLine(const BPBASEFLOAT3 &vPt1, const BPBASEFLOAT3 &vDir1, const BPBASEFLOAT3 &vPt2, const BPBASEFLOAT3 &vDir2, float &fAngle, float &fDist, BPBASEFLOAT3 *pIntersectPtOnLine1=NULL, BPBASEFLOAT3 *pIntersectPtOnLine2=NULL);

// ��ȡ����������Sin��Cos��ֵ
float GetCorrectSinCosValue(float fCosValue);
// ���㷴����ֵ
float BPCalcArcCos(float fValue);
// ���㷴����ֵ
float BPCalcArcSin(float fValue);
// ��ȡ��׼����ֵ(0~2Pi)
float GetStandardRadian_2Pi(float fRadian);
// ��ȡ��׼����ֵ(-Pi~Pi)
float GetStandardRadian_MinusPlusPi(float fRadian);

}	// namespace IKS_MATH
