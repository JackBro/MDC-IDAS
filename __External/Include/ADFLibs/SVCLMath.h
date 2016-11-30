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
// 宏定义

#ifndef max
#define max(a, b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a, b)  (((a) < (b)) ? (a) : (b))
#endif

namespace IKS_MATH
{

//===================================================================================================
// 结构体

//===================================================================================================
// 自定义功能函数

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

// 判断矩阵是否为单位向量
IKS_BOOL BPMatrixIsIdentity(const SVBASEMATRIX* pM);
// 单位化矩阵
IKS_BOOL BPMatrixIdentity(SVBASEMATRIX* pM);
// 矩阵相乘
SVBASEMATRIX* BPMatrixMultiply(const SVBASEMATRIX *pM1, const SVBASEMATRIX *pM2, SVBASEMATRIX *pMOut);
// 矩阵求逆(只针对等比例缩放、旋转、平移的级联矩阵)
IKS_BOOL BPSRTMatrixInverse(SVBASEMATRIX* pOut, const SVBASEMATRIX* pM);
// 生成缩放矩阵
void BPMatrixScaling(SVBASEMATRIX *pMScale, double sx, double sy, double sz);
// 生成偏移矩阵
void BPMatrixTranslation(SVBASEMATRIX *pMTran, double x, double y, double z);
// 生成绕某轴旋转的矩阵
void BPMatrixRotationAxis(SVBASEMATRIX *pOut, const SVBASEDOUBLE3 *pV, double dAngle);
// 计算沿指定轴旋转的矩阵
SVBASEMATRIX* BPMatrixRotationAxis(SVBASEMATRIX *pMatrix, const SVBASEDOUBLE3 *pAxisPt, const SVBASEDOUBLE3 *pAxisDir, double dRotValue);

//===================================================================================================
// 自定义功能函数

// 计算两位置间距
double CalculateDistance(const SVBASEDOUBLE3 *pPos1, const SVBASEDOUBLE3 *pPos2);
// 计算两位置间距的平方
double CalculateDistanceSquare(const SVBASEDOUBLE3 *pPos1, const SVBASEDOUBLE3 *pPos2);

IKS_BOOL IsEqualVector(const SVBASEDOUBLE3 *pV1, const SVBASEDOUBLE3 *pV2);

// 将矩阵分解为三个级联矩阵（三个矩阵级联必然等于输入矩阵;其中第一个矩阵为缩放矩阵,第三个矩阵为平移矩阵,第二个矩阵可能为旋转矩阵）
void DecomposeMatrix(const SVBASEMATRIX &matCombine, SVBASEMATRIX *pScale=NULL, SVBASEMATRIX *pMaybeRot=NULL, SVBASEMATRIX *pTrans=NULL);

// 获取将原始坐标系变换为输入坐标系的转换矩阵
void GetCoordsTransformMatrix(const SVBASEDOUBLE3 &vOrigin, const SVBASEDOUBLE3 &vAxisX, 
							  const SVBASEDOUBLE3 &vAxisY, const SVBASEDOUBLE3 &vAxisZ, SVBASEMATRIX &matrix);
// 获取将输入坐标系变换为原始坐标系的转换矩阵
void GetCoordsTransformMatrixInv(const SVBASEDOUBLE3 &vOrigin, const SVBASEDOUBLE3 &vAxisX, 
							  const SVBASEDOUBLE3 &vAxisY, const SVBASEDOUBLE3 &vAxisZ, SVBASEMATRIX &matrix);
// 获取将源坐标系变换为目标坐标系的转换矩阵
void GetCoordsTransformMatrix(const SVBASEDOUBLE3 &vSrcOrigin, const SVBASEDOUBLE3 &vSrcAxisX, const SVBASEDOUBLE3 &vSrcAxisY, const SVBASEDOUBLE3 &vSrcAxisZ, 
							  const SVBASEDOUBLE3 &vTgtOrigin, const SVBASEDOUBLE3 &vTgtAxisX, const SVBASEDOUBLE3 &vTgtAxisY, const SVBASEDOUBLE3 &vTgtAxisZ, SVBASEMATRIX &matrix);
// 获取将原始圆弧变换为目标圆弧的转换矩阵(原始圆弧:半径1,vec1为X轴,vec2为Y轴,起始弧度为0)
void GetArcTransformMatrix(const SVBASEDOUBLE3 &vOrigin, const SVBASEDOUBLE3 &vVector1, const SVBASEDOUBLE3 &vVector2, double dStartAngle, double dEndAngle, double dRadius, SVBASEMATRIX *pScaleMatrix=NULL, SVBASEMATRIX *pRotTransMatrix=NULL);

// 获取一个垂直向量
IKS_BOOL GetVerticalVector(const SVBASEDOUBLE3 &vSrcVector, SVBASEDOUBLE3 &vDstVector);
// 将一个点投影到一条直线上
void ProjectPtToLine(const SVBASEDOUBLE3 &vLinePt, const SVBASEDOUBLE3 &vLineDir, const SVBASEDOUBLE3 &vSrcPt, SVBASEDOUBLE3 &vPrjPt);
// 将一个点投影到一条直线上
void ProjectPtToLine(const SVBASEDOUBLE2 &vLinePt, const SVBASEDOUBLE2 &vLineDir, const SVBASEDOUBLE2 &vSrcPt, SVBASEDOUBLE2 &vPrjPt);
// 将一个点投影到一个平面上
void ProjectPtToPlane(const SVBASEDOUBLE3 &vPlanePt, const SVBASEDOUBLE3 &vPlaneDir, const SVBASEDOUBLE3 &vSrcPt, SVBASEDOUBLE3 &vPrjPt);
// 将一条直线投影到一个平面上
IKS_BOOL ProjectLineToPlane(const SVBASEDOUBLE3 &vPlanePt, const SVBASEDOUBLE3 &vPlaneDir, const SVBASEDOUBLE3 &vSrcLinePt, const SVBASEDOUBLE3 &vSrcLineDir, SVBASEDOUBLE3 &vPrjLinePt, SVBASEDOUBLE3 &vPrjLineDir);
// 点是否在直线上
IKS_BOOL IsPointOnLine(const SVBASEDOUBLE3 &vLinePt, const SVBASEDOUBLE3 &vLineDir, const SVBASEDOUBLE3 &vPt);
// 点是否在直线上
IKS_BOOL IsPointOnLine(const SVBASEDOUBLE2 &vLinePt, const SVBASEDOUBLE2 &vLineDir, const SVBASEDOUBLE2 &vPt);
// 点是否在平面上
IKS_BOOL IsPointOnPlane(const SVBASEDOUBLE3 &vPlanePt, const SVBASEDOUBLE3 &vPlaneDir, const SVBASEDOUBLE3 &vPt, double dZero=-1.0);
// 直线是否在平面上
IKS_BOOL IsLineOnPlane(const SVBASEDOUBLE3 &vLinePt, const SVBASEDOUBLE3 &vLineDir, const SVBASEDOUBLE3 &vPlanePt, const SVBASEDOUBLE3 &vPlaneDir);
// 两向量是否同向
IKS_BOOL IsVecSameDir(const SVBASEDOUBLE3 &v1, const SVBASEDOUBLE3 &v2);
// 两向量是否反向
IKS_BOOL IsVecReverseDir(const SVBASEDOUBLE3 &v1, const SVBASEDOUBLE3 &v2);
// 两向量是否垂直
IKS_BOOL IsVecVertical(const SVBASEDOUBLE3 &v1, const SVBASEDOUBLE3 &v2);
// 两平面是否相同(共面)
IKS_BOOL IsSamePlane(const SVBASEDOUBLE3 &vPlanePt1, const SVBASEDOUBLE3 &vPlaneDir1, const SVBASEDOUBLE3 &vPlanePt2, const SVBASEDOUBLE3 &vPlaneDir2, double dDisZero=-1.0, double dAngleZero=-1.0);
// 绕指定轴将指定向量旋转到另一指定向量,获取旋转角度(弧度值);若无法旋转成功则返回FALSE
IKS_BOOL RotateAxisFromVecToVec(const SVBASEDOUBLE3 &vAxis, const SVBASEDOUBLE3 &v1, const SVBASEDOUBLE3 &v2, double *pRotValue);
// 计算直线和平面的交点,无交点则返回FALSE
IKS_BOOL CalcIntersectOfLinePlane(const SVBASEDOUBLE3 &vLinePt, const SVBASEDOUBLE3 &vLineDir, const SVBASEDOUBLE3 &vPlanePt, const SVBASEDOUBLE3 &vPlaneDir, SVBASEDOUBLE3 *pIntersectPt, IKS_BOOL *pIsLineOnPlane=NULL);
// 计算两平面的的交线,无交线则返回FALSE
IKS_BOOL CalcIntersectOfTwoPlane(const SVBASEDOUBLE3 &vPt1, const SVBASEDOUBLE3 &vDir1, const SVBASEDOUBLE3 &vPt2, const SVBASEDOUBLE3 &vDir2, SVBASEDOUBLE3 *pIntersectPt, SVBASEDOUBLE3 *pIntersectDir, IKS_BOOL *pIsCoPlane=NULL);
// 计算两直线的交点，无交点则返回FALSE
IKS_BOOL CalcIntersectOfTwoLine(const SVBASEDOUBLE3 &vPt1, const SVBASEDOUBLE3 &vDir1, const SVBASEDOUBLE3 &vPt2, const SVBASEDOUBLE3 &vDir2, SVBASEDOUBLE3 *pIntersectPt, IKS_BOOL *pCollinear=NULL);
// 计算两线段的交点，无交点则返回FALSE(线段本身相交而非延长线相交)
IKS_BOOL CalcIntersectOfTwoLine(const SVBASEDOUBLE2 &vLine1Start, const SVBASEDOUBLE2 &vLine1End, const SVBASEDOUBLE2 &vLine2Start, const SVBASEDOUBLE2 &vLine2End, SVBASEDOUBLE2 *pIntersectPt, IKS_BOOL *pParallel=NULL, IKS_BOOL *pCollinear=NULL);
// 计算两直线的夹角和距离
void CalcAngleDistOfTwoLine(const SVBASEDOUBLE3 &vPt1, const SVBASEDOUBLE3 &vDir1, const SVBASEDOUBLE3 &vPt2, const SVBASEDOUBLE3 &vDir2, double &dAngle, double &dDist, SVBASEDOUBLE3 *pIntersectPtOnLine1=NULL, SVBASEDOUBLE3 *pIntersectPtOnLine2=NULL);
// 计算与输入点最近的线段上的点
void CalcNearestPtOnLine(const SVBASEDOUBLE3 &vLineStart, const SVBASEDOUBLE3 &vLineEnd, const SVBASEDOUBLE3 &vRefPt, SVBASEDOUBLE3 &vOutPt);
// 计算与输入点最近的线段上的点
void CalcNearestPtOnLine(const SVBASEDOUBLE2 &vLineStart, const SVBASEDOUBLE2 &vLineEnd, const SVBASEDOUBLE2 &vRefPt, SVBASEDOUBLE2 &vOutPt);

// 获取误差修正后的Sin或Cos数值
double GetCorrectSinCosValue(double dCosValue);
// 计算反余弦值
double BPCalcArcCos(double dValue);
// 计算反正弦值
double BPCalcArcSin(double dValue);
// 获取标准弧度值(0~2Pi)
double GetStandardRadian_2Pi(double dRadian);
// 获取标准弧度值(-Pi~Pi)
double GetStandardRadian_MinusPlusPi(double dRadian);


//===================================================================================================
// 自定义功能函数

// 互换三维向量的YZ分量
void BPSwitchVec3YZ(BPBASEFLOAT3 &v);
// 点乘
float BPVec3Dot(const BPBASEFLOAT3 *pV1, const BPBASEFLOAT3 *pV2);
// 点乘
float BPVec2Dot(const BPBASEFLOAT2 *pV1, const BPBASEFLOAT2 *pV2);
// 向量长度
float BPVec3Length( const BPBASEFLOAT3 *pV );
// 叉乘
void BPVec3Cross(BPBASEFLOAT3 *pOut, const BPBASEFLOAT3 *pV1, const BPBASEFLOAT3 *pV2);
// 向量单位化
void BPVec3Normalize(BPBASEFLOAT3 *pOut, const BPBASEFLOAT3 *pV);
// 向量单位化
void BPVec2Normalize(BPBASEFLOAT2 *pOut, const BPBASEFLOAT2 *pV);
// 四维向量的矩阵变换
BPBASEFLOAT4* BPVec4Transform(BPBASEFLOAT4 *pOut, const BPBASEFLOAT4 *pV, const BPBASEMATRIX *pM);
// 三维向量的矩阵变换
BPBASEFLOAT3* BPVec3TransformCoord(BPBASEFLOAT3 *pOut, const BPBASEFLOAT3 *pV, const BPBASEMATRIX *pM);
// 三维法矢的矩阵变换
BPBASEFLOAT3* BPVec3TransformNormal(BPBASEFLOAT3 *pOut, const BPBASEFLOAT3 *pV, const BPBASEMATRIX *pM);
// 判断矩阵是否为单位向量
IKS_BOOL BPMatrixIsIdentity(const BPBASEMATRIX* pM);
// 单位化矩阵
IKS_BOOL BPMatrixIdentity(BPBASEMATRIX* pM);
// 矩阵相乘
BPBASEMATRIX* BPMatrixMultiply(const BPBASEMATRIX *pM1, const BPBASEMATRIX *pM2, BPBASEMATRIX *pMOut);
// 矩阵求逆(只针对等比例缩放、旋转、平移的级联矩阵)
IKS_BOOL BPSRTMatrixInverse(BPBASEMATRIX* pOut, const BPBASEMATRIX* pM);
// 生成缩放矩阵
void BPMatrixScaling(BPBASEMATRIX *pMScale, float sx, float sy, float sz);
// 生成偏移矩阵
void BPMatrixTranslation(BPBASEMATRIX *pMTran, float x, float y, float z);
// 生成绕某轴旋转的矩阵
void BPMatrixRotationAxis(BPBASEMATRIX *pOut, const BPBASEFLOAT3 *pV, float fAngle);
// 计算沿指定轴旋转的矩阵
BPBASEMATRIX* BPMatrixRotationAxis(BPBASEMATRIX *pMatrix, const BPBASEFLOAT3 *pAxisPt, const BPBASEFLOAT3 *pAxisDir, float fRotValue);
// 生成绕X轴旋转的矩阵
void BPMatrixRotationX(BPBASEMATRIX *pOut, float fAngle);
// 生成绕Y轴旋转的矩阵
void BPMatrixRotationY(BPBASEMATRIX *pOut, float fAngle);
// 生成绕Z轴旋转的矩阵
void BPMatrixRotationZ(BPBASEMATRIX *pOut, float fAngle);

//===================================================================================================
// 自定义功能函数

// 获取符号
float GetSign(float fValue);

// 获取向量长度
float CalculateVectorLenghth(const BPBASEFLOAT2 *pVec);
// 获取向量长度
float CalculateVectorLenghth(const BPBASEFLOAT3 *pVec);
// 获取向量长度
float CalculateVectorLenghth(const BPBASEFLOAT4 *pVec);

// 计算两位置间距
float CalculateDistance(const BPBASEFLOAT3 *pPos1, const BPBASEFLOAT3 *pPos2);
// 计算两位置间距
float CalculateDistance(const BPBASEFLOAT2 *pPos1, const BPBASEFLOAT2 *pPos2);

// 矩阵相等判断函数(考虑精度)
IKS_BOOL IsEqualMatrix(const BPBASEMATRIX *pMatrix1, const BPBASEMATRIX *pMatrix2, float fZero=ZERO);
// 缩放旋转平移矩阵相等的判断函数(考虑精度)
IKS_BOOL IsEqualScaleRotTransMatrix(const BPBASEMATRIX *pMatrix1, const BPBASEMATRIX *pMatrix2, float fScaleRotZero=ZERO, float fTransZero=EPSILON);

// 向量相等判断函数(考虑精度)
IKS_BOOL IsEqualVector(const BPBASEFLOAT2 *pV1, const BPBASEFLOAT2 *pV2);
IKS_BOOL IsEqualVector(const BPBASEFLOAT3 *pV1, const BPBASEFLOAT3 *pV2);
IKS_BOOL IsEqualVector(const BPBASEFLOAT4 *pV1, const BPBASEFLOAT4 *pV2);
IKS_BOOL IsEqualVectorEx(const BPBASEFLOAT2 *pV1, const BPBASEFLOAT2 *pV2, float fZero);
IKS_BOOL IsEqualVectorEx(const BPBASEFLOAT3 *pV1, const BPBASEFLOAT3 *pV2, float fZero);
IKS_BOOL IsEqualVectorEx(const BPBASEFLOAT4 *pV1, const BPBASEFLOAT4 *pV2, float fZero);

// 将矩阵分解为三个级联矩阵（三个矩阵级联必然等于输入矩阵;其中第一个矩阵为缩放矩阵,第三个矩阵为平移矩阵,第二个矩阵可能为旋转矩阵）
void DecomposeMatrix(const BPBASEMATRIX &matCombine, BPBASEMATRIX *pScale=NULL, BPBASEMATRIX *pMaybeRot=NULL, BPBASEMATRIX *pTrans=NULL);
// 将旋转矩阵解析为(绕Z轴旋转->绕X轴旋转->绕Y轴旋转)的矩阵
IKS_BOOL AnalyseRotMatrix(const BPBASEMATRIX &matRot, float &fRotZ, float &fRotX, float &fRotY, IKS_BOOL bIsHeadDown=FALSE);
// 将旋转矩阵解析为(绕Z轴旋转->绕X轴旋转->绕Y轴旋转)的矩阵（绕X轴Y轴旋转时,使用的是绕Z轴X轴旋转后的新轴位置）
IKS_BOOL AnalyseRotMatrixForLocalZXY(const BPBASEMATRIX &matRot, float &fRotZ, float &fRotX, float &fRotY, IKS_BOOL bIsHeadDown=FALSE);
// 将旋转矩阵解析为绕某轴(过原点)旋转的矩阵
IKS_BOOL AnalyseRotMatrix(const BPBASEMATRIX &matRot, BPBASEFLOAT3 &vAxis, float &fRotAxisValue);

// 获取将源轴变换为目标轴的转换矩阵
void GetAxisTransformMatrix(const BPBASEFLOAT3 &vSrcOrigin, const BPBASEFLOAT3 &vSrcAxis, 
							const BPBASEFLOAT3 &vTgtOrigin, const BPBASEFLOAT3 &vTgtAxis, BPBASEMATRIX &matrix);
// 获取将原始坐标系变换为输入坐标系的转换矩阵
void GetCoordsTransformMatrix(const BPBASEFLOAT3 &vOrigin, const BPBASEFLOAT3 &vAxisX, 
							   const BPBASEFLOAT3 &vAxisY, const BPBASEFLOAT3 &vAxisZ, BPBASEMATRIX &matrix);
// 获取将源坐标系变换为目标坐标系的转换矩阵
void GetCoordsTransformMatrix(const BPBASEFLOAT3 &vSrcOrigin, const BPBASEFLOAT3 &vSrcAxisX, const BPBASEFLOAT3 &vSrcAxisY, const BPBASEFLOAT3 &vSrcAxisZ, 
							  const BPBASEFLOAT3 &vTgtOrigin, const BPBASEFLOAT3 &vTgtAxisX, const BPBASEFLOAT3 &vTgtAxisY, const BPBASEFLOAT3 &vTgtAxisZ, BPBASEMATRIX &matrix);
// 获取将原始圆弧变换为目标圆弧的转换矩阵(原始圆弧:半径1,vec1为X轴,vec2为Y轴,起始弧度为0)
void GetArcTransformMatrix(const BPBASEFLOAT3 &vOrigin, const BPBASEFLOAT3 &vVector1, const BPBASEFLOAT3 &vVector2, float fStartAngle, float fEndAngle, float fRadius, BPBASEMATRIX *pScaleMatrix=NULL, BPBASEMATRIX *pRotTransMatrix=NULL);

// 获取一个垂直向量
IKS_BOOL GetVerticalVector(const BPBASEFLOAT3 &vSrcVector, BPBASEFLOAT3 &vDstVector);
// 将一个点投影到一条直线上
void ProjectPtToLine(const BPBASEFLOAT3 &vLinePt, const BPBASEFLOAT3 &vLineDir, const BPBASEFLOAT3 &vSrcPt, BPBASEFLOAT3 &vPrjPt);
// 将一个点投影到一条直线上
void ProjectPtToLine(const BPBASEFLOAT2 &vLinePt, const BPBASEFLOAT2 &vLineDir, const BPBASEFLOAT2 &vSrcPt, BPBASEFLOAT2 &vPrjPt);
// 将一个点投影到一个平面上
void ProjectPtToPlane(const BPBASEFLOAT3 &vPlanePt, const BPBASEFLOAT3 &vPlaneDir, const BPBASEFLOAT3 &vSrcPt, BPBASEFLOAT3 &vPrjPt);
// 将一条直线投影到一个平面上
IKS_BOOL ProjectLineToPlane(const BPBASEFLOAT3 &vPlanePt, const BPBASEFLOAT3 &vPlaneDir, const BPBASEFLOAT3 &vSrcLinePt, const BPBASEFLOAT3 &vSrcLineDir, BPBASEFLOAT3 &vPrjLinePt, BPBASEFLOAT3 &vPrjLineDir);
// 点是否在直线上
IKS_BOOL IsPointOnLine(const BPBASEFLOAT3 &vLinePt, const BPBASEFLOAT3 &vLineDir, const BPBASEFLOAT3 &vPt);
// 点是否在平面上
IKS_BOOL IsPointOnPlane(const BPBASEFLOAT3 &vPlanePt, const BPBASEFLOAT3 &vPlaneDir, const BPBASEFLOAT3 &vPt, float fZero=-1.0f);
// 直线是否在平面上
IKS_BOOL IsLineOnPlane(const BPBASEFLOAT3 &vLinePt, const BPBASEFLOAT3 &vLineDir, const BPBASEFLOAT3 &vPlanePt, const BPBASEFLOAT3 &vPlaneDir);
// 两向量是否同向
IKS_BOOL IsVecSameDir(const BPBASEFLOAT3 &v1, const BPBASEFLOAT3 &v2, float fZero=-1.0f);
// 两向量是否反向
IKS_BOOL IsVecReverseDir(const BPBASEFLOAT3 &v1, const BPBASEFLOAT3 &v2, float fZero=-1.0f);
// 两向量是否垂直
IKS_BOOL IsVecVertical(const BPBASEFLOAT3 &v1, const BPBASEFLOAT3 &v2);
// 两平面是否相同(共面)
IKS_BOOL IsSamePlane(const BPBASEFLOAT3 &vPlanePt1, const BPBASEFLOAT3 &vPlaneDir1, const BPBASEFLOAT3 &vPlanePt2, const BPBASEFLOAT3 &vPlaneDir2, float fDisZero=-1.0f, float fAngleZero=-1.0f);
// 绕指定轴将指定向量旋转到另一指定向量,获取旋转角度(弧度值);若无法旋转成功则返回FALSE
IKS_BOOL RotateAxisFromVecToVec(const BPBASEFLOAT3 &vAxis, const BPBASEFLOAT3 &v1, const BPBASEFLOAT3 &v2, float *pRotValue);
// 计算直线和平面的交点,无交点则返回FALSE
IKS_BOOL CalcIntersectOfLinePlane(const BPBASEFLOAT3 &vLinePt, const BPBASEFLOAT3 &vLineDir, const BPBASEFLOAT3 &vPlanePt, const BPBASEFLOAT3 &vPlaneDir, BPBASEFLOAT3 *pIntersectPt, IKS_BOOL *pIsLineOnPlane=NULL);
// 计算两平面的的交线,无交线则返回FALSE
IKS_BOOL CalcIntersectOfTwoPlane(const BPBASEFLOAT3 &vPt1, const BPBASEFLOAT3 &vDir1, const BPBASEFLOAT3 &vPt2, const BPBASEFLOAT3 &vDir2, BPBASEFLOAT3 *pIntersectPt, BPBASEFLOAT3 *pIntersectDir, IKS_BOOL *pIsCoPlane=NULL);
// 计算两直线的交点，无交点则返回FALSE
IKS_BOOL CalcIntersectOfTwoLine(const BPBASEFLOAT3 &vPt1, const BPBASEFLOAT3 &vDir1, const BPBASEFLOAT3 &vPt2, const BPBASEFLOAT3 &vDir2, BPBASEFLOAT3 *pIntersectPt, IKS_BOOL *pCollinear=NULL);
// 计算两直线的夹角和距离
void CalcAngleDistOfTwoLine(const BPBASEFLOAT3 &vPt1, const BPBASEFLOAT3 &vDir1, const BPBASEFLOAT3 &vPt2, const BPBASEFLOAT3 &vDir2, float &fAngle, float &fDist, BPBASEFLOAT3 *pIntersectPtOnLine1=NULL, BPBASEFLOAT3 *pIntersectPtOnLine2=NULL);

// 获取误差修正后的Sin或Cos数值
float GetCorrectSinCosValue(float fCosValue);
// 计算反余弦值
float BPCalcArcCos(float fValue);
// 计算反正弦值
float BPCalcArcSin(float fValue);
// 获取标准弧度值(0~2Pi)
float GetStandardRadian_2Pi(float fRadian);
// 获取标准弧度值(-Pi~Pi)
float GetStandardRadian_MinusPlusPi(float fRadian);

}	// namespace IKS_MATH
