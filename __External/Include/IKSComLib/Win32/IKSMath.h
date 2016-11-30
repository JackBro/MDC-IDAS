//===================================================================================================
// Summary:
//		��ѧ������
// Date:
//		2015-07-31			����
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSMath_h__
#define __IKSMath_h__

//===================================================================================================

typedef double IKSDouble3[3];					// ��
typedef IKSDouble3 IKSBox[2];					// ��Χ��

// �㣨����������
double *IKSVectorCopy(double from[3], double to[3]);
// ������ģ����λ����
double *IKSVectorNormalize(double input[3], double output[3]);
// ��������
double IKSVectorLength(double v[3]);
// ��������
double *IKSVectorScale(double vector[3], double scale, double result[3]);
// ������
double *IKSVectorAToB(double a[3], double b[3], double c[3]);
// ������
double *IKSVectorSum(double a[3], double b[3], double sum[3]);
// �������
double IKSVectorDot(double a[3], double b[3]);
// �������
double *IKSVectorCross(double v1[3], double v2[3], double cross[3]);
// �������
double IKSTwoPointsDist(double p1[3], double p2[3]);
// �㵽ֱ�߾���
double IKSPointLineDist(double point[3], double start[3], double end[3]);
// �㵽ƽ�����
double IKSPointPlaneDist(double point[3], double origin[3], double normal[3]);
// ��һ����ͶӰ��һ��ֱ����
void IKSProjectPtToLine(double vLinePt[3], double vLineDir[3], double vSrcPt[3], double vPrjPt[3]);
// ��һ����ͶӰ��һ��ƽ����
void IKSProjectPtToPlane(double vPlanePt[3], double vPlaneDir[3], double vSrcPt[3], double vPrjPt[3]);
// ���Ƿ���ֱ����
BOOL IKSIsPointOnLine(double vLinePt[3], double vLineDir[3], double vPt[3]);
// ���Ƿ���ƽ����
BOOL IKSIsPointOnPlane(double vPlanePt[3], double vPlaneDir[3], double vPt[3]);
// �����
void IKSMirrorPoint(double input[3], double mirrorPt[3], double mirrorDir[3], double output[3]);
// ��ת�㣨�Ƕ�Ϊ���ȵ�λ��
void IKSRotatePoint(double input[3], double origin[3], double dAngle, double output[3]);

#endif

