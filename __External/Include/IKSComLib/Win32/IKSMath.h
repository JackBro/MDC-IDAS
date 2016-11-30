//===================================================================================================
// Summary:
//		数学函数集
// Date:
//		2015-07-31			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSMath_h__
#define __IKSMath_h__

//===================================================================================================

typedef double IKSDouble3[3];					// 点
typedef IKSDouble3 IKSBox[2];					// 包围盒

// 点（向量）拷贝
double *IKSVectorCopy(double from[3], double to[3]);
// 向量求模（单位化）
double *IKSVectorNormalize(double input[3], double output[3]);
// 向量长度
double IKSVectorLength(double v[3]);
// 向量缩放
double *IKSVectorScale(double vector[3], double scale, double result[3]);
// 向量减
double *IKSVectorAToB(double a[3], double b[3], double c[3]);
// 向量加
double *IKSVectorSum(double a[3], double b[3], double sum[3]);
// 向量点积
double IKSVectorDot(double a[3], double b[3]);
// 向量叉积
double *IKSVectorCross(double v1[3], double v2[3], double cross[3]);
// 两点距离
double IKSTwoPointsDist(double p1[3], double p2[3]);
// 点到直线距离
double IKSPointLineDist(double point[3], double start[3], double end[3]);
// 点到平面距离
double IKSPointPlaneDist(double point[3], double origin[3], double normal[3]);
// 将一个点投影到一条直线上
void IKSProjectPtToLine(double vLinePt[3], double vLineDir[3], double vSrcPt[3], double vPrjPt[3]);
// 将一个点投影到一个平面上
void IKSProjectPtToPlane(double vPlanePt[3], double vPlaneDir[3], double vSrcPt[3], double vPrjPt[3]);
// 点是否在直线上
BOOL IKSIsPointOnLine(double vLinePt[3], double vLineDir[3], double vPt[3]);
// 点是否在平面上
BOOL IKSIsPointOnPlane(double vPlanePt[3], double vPlaneDir[3], double vPt[3]);
// 镜像点
void IKSMirrorPoint(double input[3], double mirrorPt[3], double mirrorDir[3], double output[3]);
// 旋转点（角度为弧度单位）
void IKSRotatePoint(double input[3], double origin[3], double dAngle, double output[3]);

#endif

