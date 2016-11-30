//===================================================================================================
// Summary:
//		�ڲ�ʹ�õ�Pro/E��������
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

// ����
#include <ProPattern.h>
// ��
#include <ProUdf.h>

// �ֲڶ�����ͷ�ļ�
#include <ProSurfFinish.h>
#include <prodtl_str.h>
#include <prodev_types.h>
#include <prodev_error.h>
#include <pd_prototype.h>
#include <UtilString.h>
#include <UtilMenu.h>

#include <ProDisplist.h>

#include <ProPoint.h>

// ����������
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

// ����ϵ����
typedef struct __tagIKSCsysData
{
	SVDOUBLE3 o;									// ԭ��
	SVDOUBLE3 x;									// X��
	SVDOUBLE3 y;									// Y��
	SVDOUBLE3 z;									// Z��

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

// ƽ������
typedef struct __tagIKSPlaneData
{
	SVDOUBLE3 o;									// ԭ��
	SVDOUBLE3 x;									// X��
	SVDOUBLE3 y;									// Y��
	SVDOUBLE3 z;									// Z��

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

// ��������
typedef struct __tagIKSCylinderData
{
	SVDOUBLE3 o;									// ԭ��
	SVDOUBLE3 x;									// X��
	SVDOUBLE3 y;									// Y��
	SVDOUBLE3 z;									// Z��
	double r;										// �뾶
	double z_min;									// Z��С
	double z_max;									// Z���

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

// ׶������
typedef struct __tagIKSConeData
{
	SVDOUBLE3 o;									// ԭ��
	SVDOUBLE3 x;									// X��
	SVDOUBLE3 y;									// Y��
	SVDOUBLE3 z;									// Z��
	double a;										// ׶��
	double z_min;									// Z��С
	double z_max;									// Z���

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

// ��������
typedef struct __tagIKSSphereData
{
	SVDOUBLE3 o;									// ԭ��
	SVDOUBLE3 x;									// X��
	SVDOUBLE3 y;									// Y��
	SVDOUBLE3 z;									// Z��
	double r;										// �뾶

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


// UDF�ο�����
typedef struct __tagUDFReference
{
	ProLine szRefName;								// �ο�����
	ProSelection pRefSel;							// �ο�ѡ�����

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

// UDF�ߴ綨��
typedef struct __tagUDFDimension
{
	ProName szDimName;								// �ߴ�����
	double dDimValue;								// �ߴ�ֵ

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

// UDF����
typedef struct __tagUDFDefinition
{
	CString strUDFPath;								// UDF·��
	vector<UDFReference> arrRefs;					// �ο���
	vector<UDFDimension> arrDims;					// �ߴ缯

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

// ��ȡ��ά�����ת�Ƕ�
double PFGetVec2Angle(double x, double y);

// ����������ɴ��Ǽܵ����
BOOL CreateAsmWithSkelInAsm(
							ProAssembly pTopAsm,					// ��װ��ģ��
							ProPath szAsmTemplatePath,				// װ��ģ���ļ�·��
							ProName szNewAsmName,					// װ���������
							ProName szNewSkelName					// �Ǽ�ģ�͵�����
							);

// ����װ����ģ�ͻ�ȡ�Ǽ�ģ��
BOOL GetSkelMdlFromAsmMdl(
						  ProAssembly pAsm,						// װ����
						  ProMdl &pSkelMdl,						// �Ǽ�ģ��
						  int &nSkelCompID						// �Ǽ�Ԫ������ID
						  );

// ���ݷ����������ɸ��Ƽ��Σ���ȱʡ�ο���ʽ
BOOL CreateCopyGeomByPubGeom(
							 ProSolid pSld,							// ���Ƽ�������ģ��
							 ProSelection pSelPubGeom,				// ѡ��ķ�������
							 ProName szCGName,						// ���Ƽ���������
							 ProFeature &newCopyFeature				// �µĸ��Ƽ�������
							 );

// ���ݷ����������ɾֲ����Ƽ���
BOOL CreateLocalCopyGeomByPubGeom(
								  ProSelection pSelSld,					// ���Ƽ�������ģ��
								  ProSelection pSelPubGeom,				// ѡ��ķ�������
								  ProName szCGName,						// ���Ƽ���������
								  ProFeature &newCopyFeature			// �µĸ��Ƽ�������
								  );

// ���ݷ����������ɸ��Ƽ��Σ�������ϵ�ο���ʽ
BOOL CreateCopyGeomByPubGeomUseCsys(
									ProSolid pPubGeomMdl,					// ����������ģ��
									ProSelection pSelExtCsys,				// �ⲿ�ο�����ϵ��·������ڷ���������ģ��
									ProSelection pSelPubGeom,				// ��������ѡ�����·������ڷ���������ģ��
									ProSolid pCopyGeomMdl,					// ���Ƽ�����ģ��
									ProSelection pSelLocalCsys,				// �ֲ��ο�����ϵ��·������ڸ��Ƽ�����ģ��
									ProName szCGName,						// ���Ƽ���������
									ProFeature &newCopyFeature				// �µĸ��Ƽ�������
									);

// ���ݸ��Ƽ������ɷ�������
BOOL CreatePubGeomByCopyGeom(
							 ProSolid pPubGeomMdl,							// ������������ģ��
							 ProFeature &copyGeomFeature,					// ���Ƽ��Σ�ֱ���ڷ�����������ģ��
							 ProName szPBName,								// ��������������
							 ProFeature &newPubFeature						// �µķ�����������
							 );

// ����ģ�������������磬������ϵ�ο���ʽ
BOOL CreateShrinkWrapByPubGeomUseCsys(
									  ProSolid pExtRefMdl,							// �ⲿ�ο���ģ��
									  ProSelection pSelExtCsys,						// �ⲿ�ο�����ϵ��·��������ⲿ�ο���ģ��
									  vector<ProSelection> &arrIncludeComps,		// �������������Ԫ����·��������ⲿ�ο���ģ��
									  vector<ProSelection> &arrNotIncludeComps,		// �������粻������Ԫ����·��������ⲿ�ο���ģ��
									  ProSolid pShrinkWrapMdl,						// ����������ģ��
									  ProSelection pSelLocalCsys,					// �ֲ��ο�����ϵ��·�����������������ģ��
									  int nQualityLevel,							// �����ȼ�
									  ProName szSWName,								// ��������������
									  ProFeature &newSWFeature						// �µ�������������
									  );

// �õ�Դ������Ŀ�����ת������ת�Ƕ�
BOOL PFGetTrfMoveParam(ProMatrix srcTrf, ProMatrix destTrf, 
					   double &dXMove, double &dYMove, double &dZMove, 
					   double &dRotX, double &dRotY, double &dRotZ);

// �õ�Դ����ϵ��Ŀ������ϵת����ƽ��������ת�Ƕ�
BOOL GetCsysMoveParam(SVDOUBLE3 &vSrcCsysOrigin, SVDOUBLE3 &vSrcCsysX, SVDOUBLE3 &vSrcCsysY, SVDOUBLE3 &vSrcCsysZ,
					  SVDOUBLE3 &vDestCsysOrigin, SVDOUBLE3 &vDestCsysX, SVDOUBLE3 &vDestCsysY, SVDOUBLE3 &vDestCsysZ,
					  double &dXMove, double &dYMove, double &dZMove, double &dRotX, double &dRotY, double &dRotZ);

// ��������任�ķ�������ȡ�任����
BOOL GetTransMatrix(double dXMove, double dYMove, double dZMove, double dRotX, double dRotY, double dRotZ, ProMatrix trans);

// ��ȡ����ϵ�����Ĳο�����ϵ
BOOL GetCsysRefCsys(
					ProSelection pSelCsysFeature, 
					ProSelection &pSelRefCsys
					);

// ��ȡ����ϵ�Ĳο�����ϵ
BOOL GetCsysRefCsys(
					ProGeomitem &csysItem,							// ����ϵ
					ProGeomitem &refCsysItem						// �ο�����ϵ
					);

// ��������ϵ��λ�úͻ�׼����ϵ�������µ�����ϵ
BOOL CreateCSys(
				ProSelection pSelSld,								// ����ϵ����ģ��
				ProPoint3d origin,									// ����ϵ��ԭ��λ��
				ProPoint3d x,										// ����ϵ��X������
				ProPoint3d y,										// ����ϵ��Y������
				ProPoint3d z,										// ����ϵ��Z������
				ProSelection pSelDatumCsys,							// ѡ��Ļ�׼����ϵ
				ProName szCsysName,									// ����ϵ��
				ProFeature &newCsysFeature							// �µ�����ϵ����
				);

// ����ȱʡ����ϵ
BOOL CreateDefaultCSys(
					   ProSolid pSld,								// ����ϵ����ģ��
					   const CString &strUDFPath,					// UDF·��
					   ProName szCsysName,							// ����ϵ��
					   ProFeature &newCsysFeature					// �µ�����ϵ����
					   );

// ��������ϵ��λ�ã���������ϵ
BOOL ModifyCSys(
				ProSelection pSelCsys,								// ����ϵѡ�����
				ProPoint3d origin,									// ����ϵ��ԭ��λ��
				ProPoint3d x,										// ����ϵ��X������
				ProPoint3d y,										// ����ϵ��Y������
				ProPoint3d z										// ����ϵ��Z������
				);

// ����ģ����װ���壬������ϵװ��
BOOL AddModelToAsmWithCsysCons(
							   ProAssembly pAsm,						// װ����
							   ProSelection pSelCsys,					// ѡ��Ļ�׼����ϵ
							   ProSolid pMdlToAdd,						// ��������ģ��
							   ProModelitem &csysItem,					// ģ�͵�����ϵ
							   ProAsmcomp &newAsmcomp					// �µ�Ԫ��
							   );

// �������ϵԼ��
BOOL AddCsysConstraint(
					   ProAsmcomp &asmcomp,						// �µ�Ԫ��
					   ProAssembly pAsm,						// װ����
					   ProSelection pSelCsys,					// ѡ��Ļ�׼����ϵ
					   ProSelection pSelCompCsys				// ģ�͵�����ϵ
					   );

// �ж������Ƿ��Ƿ�������
BOOL PFIsFeaturePubGeom(ProFeature &feature);
// �ж������Ƿ��Ǹ��Ƽ���
BOOL IsFeatureCopyGeom(ProFeature &feature);

// ��ȡģ�͵ķ�������
BOOL GetMdlPubGeom(
				   ProMdl pMdl,											// ģ��
				   vector<ProFeature> &arrPubGeom						// ��������
				   );

// ��ȡģ�͵ĸ��Ƽ���
BOOL GetMdlCopyGeom(
					ProMdl pMdl,										// ģ��
					vector<ProFeature> &arrCopyGeom						// ��������
					);

// ���ݸ��Ƽ��λ�ȡ���Ƽ��εĲο�ģ��
BOOL GetCopyGeomRefMdl(
					   ProFeature &feaCopyGeom, 						// ���Ƽ���
					   ProMdl &pRefMdl									// �ο�ģ��
					   );

// ���ݵ����ȡ���λ��
BOOL GetPointCoords(
					ProModelitem &pointItem,							// �����Ŀ
					ProPoint3d pointPos									// ���λ��
					);

// ����ѡ����ȡ���λ��
BOOL GetPointCoords(
					ProSelection pSelPoint,								// �����Ŀ
					SVDOUBLE3 &pointPos									// ���λ��
					);

// ��������ϵ��ȡ����ϵ����
BOOL GetCsysData(ProModelitem &csysItem,								// ����ϵ����Ŀ
				 ProPoint3d origin,										// ԭ���λ��
				 ProPoint3d x,											// X������
				 ProPoint3d y,											// Y������
				 ProPoint3d z											// Z������
				 );

// ��ȡѡ������ϵ�����ݣ��������������
BOOL GetCsysData(
				 ProSelection pSelCsys,									// ����ϵ��ѡ�����
				 SVDOUBLE3 &origin,										// ԭ���λ��
				 SVDOUBLE3 &x,											// X������
				 SVDOUBLE3 &y,											// Y������
				 SVDOUBLE3 &z											// Z������
				 );

// ��ȡѡ������ϵ�����ݣ��������������
BOOL GetCsysData(
				 ProSelection pSelCsys,									// ����ϵ��ѡ�����
				 IKSCsysData &csysData									// ����ϵ����
				 );

// ��ȡѡ�����ĸ����
BOOL GetSelectionFatherAsm(ProSelection pSel, ProMdl &pFatherAsm);
// ��ȡѡ�����������
BOOL GetSelectionGrandAsm(ProSelection pSel, ProMdl &pGrandAsm);
// ��ȡ·���ĸ����
BOOL GetAsmcomppathFatherAsm(ProAsmcomppath &comppath, ProMdl &pFatherAsm);
// ��ȡ·���������
BOOL GetAsmcomppathGrandAsm(ProAsmcomppath &comppath, ProMdl &pGrandAsm);
// ��ȡ·���ĸ�·��
BOOL GetAsmcomppathFatherPath(ProAsmcomppath &comppath, ProAsmcomppath &fatherPath);

// ����UDF
BOOL PFCreateUDF(ProSolid pSld, UDFDefinition &udfDef, ProGroup &udf);

// �������
void PFMatrixMultiply(const ProMatrix matrix1, const ProMatrix matrix2, ProMatrix matrixOut);
// 3X3�������
void Matrix3X3Multiply(const double matrix1[3][3], const double matrix2[3][3], double matrixOut[3][3]);
// �����任����
void PFMatrixCopy(const ProMatrix input, ProMatrix output);
// �������
BOOL PFMatrixInvert(const ProMatrix input, ProMatrix output);
// ����ϵת��Ϊװ�����
ProError PFVectorToMatrix(double x_vector[3],					/* IN - X directional vector   */
						  double y_vector[3],					/* IN - Y directional vector   */
						  double z_vector[3],					/* IN - Z directional vector   */
						  double o_vector[3],					/* IN - Origin                 */
						  double transform[4][4]);				/* OUT - transformation matrix */

//===================================================================================================

// ������������_Բ
BOOL CreateExtrudeFace_Circle(
							  ProSolid pSld,							// ������������ģ��
							  ProSelection pSelPlane,					// �ݻ������
							  ProSelection pSelCsys,					// �ο�����ϵ
							  const CString &strUDFPath,				// UDF·��
							  double dCircleDiameter,					// Բֱ��
							  double dExtrudeHeight						// ����߶�
							  );

// ������������_����
BOOL CreateExtrudeFace_Rectangle(
								 ProSolid pSld,							// ������������ģ��
								 ProSelection pSelPlane,				// �ݻ������
								 ProSelection pSelCsys,					// �ο�����ϵ
								 const CString &strUDFPath,				// UDF·��
								 double dLength,						// ����
								 double dWidth,							// ���
								 double dExtrudeHeight					// ����߶�
								 );

// ������������_����
BOOL CreateExtrudeFace_Door(
							ProSolid pSld,								// ������������ģ��
							ProSelection pSelPlane,						// �ݻ������
							ProSelection pSelCsys,						// �ο�����ϵ
							const CString &strUDFPath,					// UDF·��
							double dLength,								// ����
							double dWidth,								// ���
							double dExtrudeHeight						// ����߶�
							);

//===================================================================================================

// ������������_ֱ��
BOOL CreateExtrudeFace_Line(
							const CString &strUDFPath,					// UDF·��
							ProSelection pSelSld,						// ɨ����������ģ��
							ProPoint3d refCsysOrigin,					// �ο�����ϵԭ��
							ProPoint3d refCsysX,						// �ο�����ϵX��
							ProPoint3d refCsysZ,						// �ο�����ϵZ��
							double dSecLineLength,						// ����ֱ�߳���
							double dExtrudeHeight						// ����߶�
							);

// ������������_Բ
BOOL CreateExtrudeFace_Circle(
							  const CString &strUDFPath,				// UDF·��
							  ProSelection pSelSld,						// ɨ����������ģ��
							  ProPoint3d refCsysOrigin,					// �ο�����ϵԭ��
							  ProPoint3d refCsysX,						// �ο�����ϵX��
							  ProPoint3d refCsysZ,						// �ο�����ϵZ��
							  double dSecCircleDiameter,				// ����Բֱ��
							  double dExtrudeHeight						// ����߶�
							  );

// ������������_����
BOOL CreateExtrudeFace_Rectangle(
								 const CString &strUDFPath,				// UDF·��
								 ProSelection pSelSld,					// ɨ����������ģ��
								 ProPoint3d refCsysOrigin,				// �ο�����ϵԭ��
								 ProPoint3d refCsysX,					// �ο�����ϵX��
								 ProPoint3d refCsysZ,					// �ο�����ϵZ��
								 double dSecRectLength,					// ������γ���
								 double dSecRectWidth,					// ������ο��
								 double dExtrudeHeight					// ����߶�
								 );

// ������������_����
BOOL CreateExtrudeFace_Door(
							const CString &strUDFPath,					// UDF·��
							ProSelection pSelSld,						// ɨ����������ģ��
							ProPoint3d refCsysOrigin,					// �ο�����ϵԭ��
							ProPoint3d refCsysX,						// �ο�����ϵX��
							ProPoint3d refCsysZ,						// �ο�����ϵZ��
							double dSecDoorLength,						// ������γ���
							double dSecDoorWidth,						// ������ο��
							double dExtrudeHeight						// ����߶�
							);

// ������������_U��
BOOL CreateExtrudeFace_UShape(
							  const CString &strUDFPath,				// UDF·��
							  ProSelection pSelSld,						// ɨ����������ģ��
							  ProPoint3d refCsysOrigin,					// �ο�����ϵԭ��
							  ProPoint3d refCsysX,						// �ο�����ϵX��
							  ProPoint3d refCsysZ,						// �ο�����ϵZ��
							  double dSecULength,						// ����U�γ���
							  double dSecUWidth,						// ����U�ο��
							  double dExtrudeHeight						// ����߶�
							  );

// ��ȡ������������
BOOL PFGetNewFeatureName(ProSolid pSld, ProName szNameExpected, ProName szNewFeaName, BOOL bStartWith1 = FALSE);

//===================================================================================================

// ����ɨ�����棬�켣ΪԲ��������Ϊֱ��
BOOL CreateSweepFace_TrailArc_SecLine(
									  const CString &strUDFPath,					// UDF·��
									  ProSelection pSelSld,							// ɨ����������ģ��
									  ProPoint3d arcStart,							// Բ�������
									  ProPoint3d arcMid,							// Բ�����м��
									  ProPoint3d arcEnd,							// Բ�����յ�
									  double dSecLineLength							// ����ֱ�߳���
									  );

// ����ɨ�����棬�켣ΪԲ��������ΪԲ
BOOL CreateSweepFace_TrailArc_SecCircle(
										const CString &strUDFPath,					// UDF·��
										ProSelection pSelSld,						// ɨ����������ģ��
										ProPoint3d arcStart,						// Բ�������
										ProPoint3d arcMid,							// Բ�����м��
										ProPoint3d arcEnd,							// Բ�����յ�
										double dSecCircleDiameter					// ����Բֱ��
										);

// ����ɨ�����棬�켣ΪԲ��������Ϊ����
BOOL CreateSweepFace_TrailArc_SecRectangle(
	const CString &strUDFPath,					// UDF·��
	ProSelection pSelSld,						// ɨ����������ģ��
	ProPoint3d arcStart,						// Բ�������
	ProPoint3d arcMid,							// Բ�����м��
	ProPoint3d arcEnd,							// Բ�����յ�
	double dSecRectLength,						// ������γ���
	double dSecRectWidth						// ������ο��
	);

// ����ɨ�����棬�켣ΪԲ��������Ϊ����
BOOL CreateSweepFace_TrailArc_SecDoor(
									  const CString &strUDFPath,					// UDF·��
									  ProSelection pSelSld,							// ɨ����������ģ��
									  ProPoint3d arcStart,							// Բ�������
									  ProPoint3d arcMid,							// Բ�����м��
									  ProPoint3d arcEnd,							// Բ�����յ�
									  double dSecDoorLength,						// ������γ���
									  double dSecDoorWidth							// ������ο��
									  );

// ����ɨ�����棬�켣ΪԲ��������ΪU��
BOOL CreateSweepFace_TrailArc_SecUShape(
	const CString &strUDFPath,					// UDF·��
	ProSelection pSelSld,						// ɨ����������ģ��
	ProPoint3d arcStart,						// Բ�������
	ProPoint3d arcMid,							// Բ�����м��
	ProPoint3d arcEnd,							// Բ�����յ�
	double dSecULength,							// ����U�γ���
	double dSecUWidth							// ����U�ο��
	);

//===================================================================================================

// ���ɻ�׼��
BOOL CreateDatumPoints(
					   ProSelection pSelSld,								// ��׼����������ģ��
					   ProSelection pSelCsys,								// �ο�����ϵ�����Ϊ��������Ĭ�ϵ�����ϵ
					   const vector<SVDOUBLE3> &arrPoints,					// ���λ��
					   ProName szDtmPntFeatureName,							// ��׼��������
					   ProFeature &newDatumPointsFeature					// ��׼������
					   );

// ���ɻ�׼�㣨��������ϵλ�ã�
BOOL CreateDatumPointByCsys(
							ProSelection pSelSld,							// ��׼����������ģ��
							ProSelection pSelCsys,							// �ο�����ϵ
							ProName szDtmPntFeatureName,					// ��׼��������
							ProFeature &newDatumPointFeature				// ��׼������
							);

// ���ɻ�׼�ᣨ���������㣩
BOOL CreateDatumAxisByTwoPoints(
								ProSelection pSelSld,						// ��׼����������ģ��
								ProSelection pSelPoint1,					// ��׼��1
								ProSelection pSelPoint2,					// ��׼��2
								ProName szDtmAxisFeatureName,				// ��׼��������
								ProFeature &newDtmAxisFeature				// ��׼������
								);

// �޸Ļ�׼�㣨��Ӧ��ƫ������ϵ��׼�㣩
BOOL ModifyDatumPoints(
					   ProSelection pSelDatumFeature,						// ��׼������
					   const vector<SVDOUBLE3> &arrPoints					// ���λ�ã��������꣩
					   );

// ����������ȡ�ο�����ϵ
BOOL GetDatumPointRefCsys(
						  ProSelection pSelDatumFeature,					// ��׼������
						  ProSelection &pSelRefCsys							// �ο�����ϵ
						  );

// ����ɨ�����棬�켣Ϊ����������Ϊֱ��
BOOL CreateSweepFace_TrailSpline_SecLine(
	const CString &strUDFPath,					// UDF·��
	ProSelection pSelSld,						// ɨ����������ģ��
	const vector<SVDOUBLE3> &arrSplinePoints,	// �������ߵ�
	double dSecLineLength						// ����ֱ�߳���
	);

// ����ɨ�����棬�켣Ϊ����������ΪԲ
BOOL CreateSweepFace_TrailSpline_SecCircle(
	const CString &strUDFPath,					// UDF·��
	ProSelection pSelSld,						// ɨ����������ģ��
	const vector<SVDOUBLE3> &arrSplinePoints,	// �������ߵ�
	double dSecCircleDiameter					// ����Բֱ��
	);

// ����ɨ�����棬�켣Ϊ����������Ϊ����
BOOL CreateSweepFace_TrailSpline_SecRectangle(
	const CString &strUDFPath,					// UDF·��
	ProSelection pSelSld,						// ɨ����������ģ��
	const vector<SVDOUBLE3> &arrSplinePoints,	// �������ߵ�
	double dSecRectLength,						// ������γ���
	double dSecRectWidth						// ������ο��
	);

// ����ɨ�����棬�켣Ϊ����������Ϊ����
BOOL CreateSweepFace_TrailSpline_SecDoor(
	const CString &strUDFPath,					// UDF·��
	ProSelection pSelSld,						// ɨ����������ģ��
	const vector<SVDOUBLE3> &arrSplinePoints,	// �������ߵ�
	double dSecDoorLength,						// ������γ���
	double dSecDoorWidth						// ������ο��
	);

// ����ɨ�����棬�켣Ϊ����������ΪU��
BOOL CreateSweepFace_TrailSpline_SecUShape(
	const CString &strUDFPath,					// UDF·��
	ProSelection pSelSld,						// ɨ����������ģ��
	const vector<SVDOUBLE3> &arrSplinePoints,	// �������ߵ�
	double dSecULength,							// ����U�γ���
	double dSecUWidth							// ����U�ο��
	);

//===================================================================================================

// ����ѡ����������������ϵ�ľ���λ��
BOOL CalcCsysBySelSurface(
						  ProSelection pSelSurf,							// ѡ������
						  SVDOUBLE3 &vCsysOrigin,							// ����ϵԭ��
						  SVDOUBLE3 &vCsysX,								// ����ϵX
						  SVDOUBLE3 &vCsysY,								// ����ϵY
						  SVDOUBLE3 &vCsysZ									// ����ϵZ
						  );

//===================================================================================================

typedef struct __tagParameterData
{
	CString strParaName;						// ������
	CString strDispName;						// ��ʾ��
	CString strValue;							// ����ֵ
	CString strRemark;							// ��ע
	CString strParaType;						// ��������

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

// ��ȡģ�͵�������
BOOL GetMdlMainParameters(ProMdl pMdl, vector<ParameterData> &arrParameters);

//===================================================================================================

// ��ȡ��ѡ����������ĵ�
BOOL GetPointOnSurface(
					   ProSelection pSelSurf,					// ѡ������
					   SVDOUBLE3 &vInputPoint,					// �����
					   SVDOUBLE3 &vPointOnSurf					// �����ϵĵ�
					   );

//===================================================================================================

// ��ȡ·����Ԫ������
BOOL GetAsmcomppathCompFeature(
							   ProAsmcomppath &comppath,		// ·��
							   ProAsmcomp &asmcomp				// Ԫ������
							   );

//===================================================================================================

// ��ȡģ�͵�Ĭ�ϲο�����ϵ
BOOL GetSolidDefaultCsys(
						 ProSolid pSld,									// �ο�ʵ��
						 ProCsys &pDefaultCsys							// Ĭ�ϲο�����ϵ
						 );

// ��ȡ����������ϵ
BOOL GetCsysItemFromFeature(
							ProFeature &feaCsys,						// �ο�ʵ��
							ProGeomitem &geomCsys						// Ĭ�ϲο�����ϵ
							);

//===================================================================================================

// ��ȡ��Ŀ�����ƣ�֧��������Ŀ��
// PRO_EDGE PRO_SURFACE PRO_FEATURE PRO_CSYS PRO_AXIS PRO_POINT PRO_QUILT PRO_CURVE 
// PRO_LAYER PRO_DIMENSION PRO_REF_DIMENSION PRO_NOTE PRO_GTOL PRO_SURF_FIN 
// PRO_SYMBOL_INSTANCE PRO_SET_DATUM_TAG PRO_SIMP_REP PRO_EXPLD_STATE PRO_ANNOTATION_ELEM 
CString GetModelItemName(
						 ProModelitem &item								// ��Ŀ
						 );

//===================================================================================================

// ��ȡƽ�������
BOOL GetPlaneData(
				  ProGeomitem &surfItem,								// ƽ�����Ŀ
				  SVDOUBLE3 &origin,									// ԭ���λ��
				  SVDOUBLE3 &x,											// X������
				  SVDOUBLE3 &y,											// Y������
				  SVDOUBLE3 &z											// Z�����������淨��
				  );

// ��ȡѡ��ƽ������ݣ��������������
BOOL GetPlaneData(
				  ProSelection pSelPlane,								// ƽ���ѡ�����
				  SVDOUBLE3 &origin,									// ԭ���λ��
				  SVDOUBLE3 &x,											// X������
				  SVDOUBLE3 &y,											// Y������
				  SVDOUBLE3 &z											// Z�����������淨��
				  );

// ��ȡѡ��ƽ������ݣ��������������
BOOL GetPlaneData(
				  ProSelection pSelPlane,								// ƽ���ѡ�����
				  IKSPlaneData &planeData								// ƽ������
				  );

// ��ȡ���������
BOOL GetCylinderData(
					 ProGeomitem &surfItem,								// �������Ŀ
					 IKSCylinderData &cylinderData						// ���������
					 );

// ��ȡѡ����������ݣ��������������
BOOL GetCylinderData(
					 ProSelection pSelCylinder,							// �����ѡ�����
					 IKSCylinderData &cylinderData						// ���������
					 );

// ��ȡ׶�������
BOOL GetConeData(
				 ProGeomitem &surfItem,									// ׶�����Ŀ
				 IKSConeData &coneData									// ׶�������
				 );

// ��ȡѡ��׶������ݣ��������������
BOOL GetConeData(
				 ProSelection pSelCone,									// ׶���ѡ�����
				 IKSConeData &coneData									// ׶�������
				 );

// ��ȡԲ���������
BOOL GetTorusData(
				  ProGeomitem &surfItem,								// Բ�������Ŀ
				  SVDOUBLE3 &origin,									// ԭ���λ��
				  SVDOUBLE3 &x,											// X������
				  SVDOUBLE3 &y,											// Y������
				  SVDOUBLE3 &z,											// Z������
				  double &dRadius1,										// �켣�뾶
				  double &dRadius2										// ����뾶
				  );

// ��ȡѡ��Բ��������ݣ��������������
BOOL GetTorusData(
				  ProSelection pSelTorus,								// Բ�����ѡ�����
				  SVDOUBLE3 &origin,									// ԭ���λ��
				  SVDOUBLE3 &x,											// X������
				  SVDOUBLE3 &y,											// Y������
				  SVDOUBLE3 &z,											// Z������
				  double &dRadius1,										// �켣�뾶
				  double &dRadius2										// ����뾶
				  );

// ��ȡ���������
BOOL GetSphereData(
				   ProGeomitem &surfItem,								// �������Ŀ
				   IKSSphereData &sphereData							// ���������
				   );

// ��ȡѡ����������ݣ��������������
BOOL GetSphereData(
				   ProSelection pSelSphere,								// �����ѡ�����
				   IKSSphereData &sphereData							// ���������
				   );

// ��ȡ���������
CString GetSurfaceDesc(
					   ProGeomitem &surfItem							// ������Ŀ
					   );

//===================================================================================================

// ��ȡԪ�������Ĳο�����ϵ
BOOL GetAsmcompRefCsys(
					   ProAsmcomp &asmcomp,								// Ԫ������
					   ProGeomitem &refCsysItem							// װ��ο�����ϵ
					   );

// ��ȡԪ��ģ�͵�ѡ�����·�������Ԫ�������ĸ����
BOOL GetAsmcompSelection(
						 ProAsmcomp &asmcomp,							// Ԫ������
						 ProSelection &pSelCompMdl						// װ��ο�����ϵ
						 );

//===================================================================================================

// ����ѡ�����
BOOL HighlightSelection(
						ProSelection pSel								// ѡ�����
						);
// ����ѡ�����
BOOL HighlightSelection(
						const vector<ProSelection> &arrSel				// ѡ�����
						);

//===================================================================================================

// ����ģ�ͺͻ���
BOOL RegenerateCurrentMdl();

// ��ȡѡ��ģ������������ѡ�����
BOOL GetSolidFeatureSelection(
							  ProSelection pSelSld,						// ѡ��ģ��
							  int nFeatureType,							// ��������
							  vector<ProSelection> &arrSelFeature		// ����ѡ�����
							  );

// ��ȡģ�͵�ָ��������
BOOL GetSolidFeature(
					 ProSolid pSld,										// ģ��
					 ProFeattype feaType,								// ��������
					 vector<ProFeature> &arrFeature						// ������
					 );

// ��ȡģ�͵�ָ�����μ�
BOOL GetSolidGeomitems(
					   ProSolid pSld,									// ģ��
					   ProType eGeomType,								// ��������
					   vector<ProGeomitem> &arrGeomItems				// ���μ�
					   );

// ���ѡ����������
BOOL GetNameFromProSelection(
							 ProSelection pSel,							// ѡ�����
							 CString &strSelName						// ������
							 );

// ��ȡ��������������������ɵ�����
BOOL GetFeatureAllPatternFeatures(
								  ProFeature &feature,						// ��������(in)
								  vector<ProFeature> &arrPatternFeatures	// ����������(out)
								  );

// �ж�����ϵ�Ƿ�λ����������Χ��
BOOL IsCsysInSurfaceRegion(
						   ProSelection pSelCsys,						// ����ϵѡ�����(in)
						   ProSelection pSelSurface						// ����ѡ�����(in)
						   );

// ��ȡѡ�����������ʵ��ģ�͵�ѡ�����
BOOL GetSelectionRelSelection(
							  ProSelection pSel,						// ѡ�����
							  ProSolid pOwnerMdl,						// ʵ��ģ��
							  ProSelection &pSelRel						// ��Ե�ѡ�����
							  );

// ��ȡ�����ļ�����Ŀ
BOOL GetFeatureGeomItems(
						 ProFeature &feature,							// ����
						 ProType eGeomType,								// ��������
						 vector<ProGeomitem> &arrGeomItems				// ���μ�
						 );

// ��ȡ�����ļ�����Ŀѡ�����
BOOL GetFeatureGeomItemSelections(
								  ProSelection pSelFeature,				// ����ѡ�����
								  ProType eGeomType,					// ��������
								  vector<ProSelection> &arrGeomSels		// ����ѡ�����
								  );

// �жϵ��Ƿ���������
BOOL IsPointOnSurface(
					  ProPoint3d dPoint,								// ��λ��
					  ProSelection pSelSurface,							// ����ѡ�����
					  ProContour pContour								// ���������
					  );

// �жϵ��Ƿ���������
BOOL IsPointOnSurface(
					  ProSelection pSelPoint,							// ��λ��
					  ProSelection pSelSurface,							// ����ѡ�����
					  ProContour pContour								// ���������
					  );

// �жϵ��Ƿ������淶Χ��
BOOL IsPointInSurfaceRegion(
							ProPoint3d dPoint,							// ��λ��
							ProGeomitem &surfItem						// ��
							);

// �жϵ��Ƿ�������������Χ��
BOOL IsPointInContourRegion(
							ProPoint3d dPoint,							// ��λ��
							ProSolid pSurfOwner,						// ���������ģ��
							ProSurface pSurface,						// ����
							ProContour pContour							// ����
							);

// ��ȡ����ѡ�����ָ�������
BOOL GetSurfaceContour(
					   ProSelection pSelSurface,						// ����ѡ�����
					   ProContour &pContour								// ����
					   );

// ��ȡ�����������
BOOL GetCoordsBySysCylinder(SVDOUBLE3 &vPoint, SVDOUBLE3 &vSysCylPoint);
// ��ȡ�����������
BOOL GetCoordsBySysSphere(SVDOUBLE3 &vPoint, SVDOUBLE3 &vSysSpherePoint);

// ��ȡ�������εĻ�׼��Ŀ��
BOOL GetPubDatumItems(ProFeature &pubFeature, ProType eDatumType, vector<ProGeomitem> &arrDatumItems);

// ������Ŀ
int FindModelItem(ProModelitem &mdlItem, const vector<ProModelitem> &arrItems);

// �õ�Pro/E�Ĳ�����
BOOL GetParaName(ProModelitem *pMdlItem, const CString &strName, BOOL bAddID, ProName szParaName);
// ���ģ�͵Ĳ���
BOOL GetParameter(ProModelitem *pMdlItem, ProName szParaName, ProParameter &para);
// ���ģ�͵Ĳ���
BOOL GetParameter(ProModelitem *pMdlItem, const CString &strName, ProParameter &para, BOOL bAddID = FALSE);
// ���ģ�͵Ĳ���ֵ
BOOL GetParameter(ProModelitem *pMdlItem, const CString &strName, ProBoolean &bValue, BOOL bAddID = FALSE);
// ����ģ�͵Ĳ���ֵ
BOOL SetParameter(ProModelitem *pMdlItem, const CString &strName, const ProBoolean &bValue, BOOL bAddID = TRUE, wchar_t *strDescription = NULL, BOOL bDesignation = FALSE);
// ���ģ�͵Ĳ���ֵ
BOOL GetParameter(ProModelitem *pMdlItem, const CString &strName, CString &strValue, BOOL bAddID = FALSE);
// ����ģ�͵Ĳ���ֵ
BOOL SetParameter(ProModelitem *pMdlItem, const CString &strName, const CString &strValue, BOOL bAddID = FALSE, wchar_t *strDescription = NULL, BOOL bDesignation = FALSE);
// ���ģ�͵Ĳ���ֵ
BOOL GetParameter(ProModelitem *pMdlItem, const CString &strName, int &nValue, BOOL bAddID = FALSE);
// ����ģ�͵Ĳ���ֵ
BOOL SetParameter(ProModelitem *pMdlItem, const CString &strName, int nValue, BOOL bAddID = FALSE, wchar_t *strDescription = NULL, BOOL bDesignation = FALSE);
// ���ģ�͵Ĳ���ֵ
BOOL GetParameter(ProModelitem *pMdlItem, const CString &strName, double &dValue, BOOL bAddID = FALSE);
// ����ģ�͵Ĳ���ֵ
BOOL SetParameter(ProModelitem *pMdlItem, const CString &strName, double dValue, BOOL bAddID = FALSE, wchar_t *strDescription = NULL, BOOL bDesignation = FALSE);
// ���ģ�͵ĳ��ַ�������ֵ
BOOL GetLongStringParameter(ProModelitem *pMdlItem, const CString &strName, CString &strValue, BOOL bAddID = FALSE);
// ����ģ�͵ĳ��ַ�������ֵ
BOOL SetLongStringParameter(ProModelitem *pMdlItem, const CString &strName, const CString &strValue, BOOL bAddID = FALSE, wchar_t *strDescription = NULL, BOOL bDesignation = FALSE);
// ɾ��ģ�Ͳ���
BOOL DeleteParameter(ProModelitem *pMdlItem, const CString &strName, BOOL bAddID = FALSE);
// ɾ��ģ�Ͳ���
BOOL DeleteLongStringParameter(ProModelitem *pMdlItem, const CString &strName, BOOL bAddID = FALSE);

// ��ȡ��ϵ
BOOL GetRelation(ProMdl pMdl, CString &strRelation);
// ���ӹ�ϵ
BOOL AddRelation(ProMdl pMdl, const CString &strRelation);

// ��ȡ�ߵ������յ�
BOOL GetEdgeStartAndEnd(ProGeomitem &edgeItem, SVDOUBLE3 &vStart, SVDOUBLE3 &vEnd);

// ��ȡģ�͵�����
CString GetMdlDesc(ProMdl pMdl);
// ��ȡģ�͵�����
CString GetMdlDesc(ProName mdlName, ProMdlType mdlType);
// ��ȡ���͵�����
CString GetTypeDesc(ProType eType);
// ��ȡ��׼������
CString GetDatumDesc(ProType eType);

// ��ȡԪ��·����Ӧģ�͵�ѡ�����
BOOL GetAsmcomppathSelection(ProAsmcomppath &asmcomppath, ProSelection &pSelMdl);
// ����Ԫ��·����Ӧģ��
BOOL RegenerateAsmcomppathMdl(ProAsmcomppath &asmcomppath);

// ��ȡѡ������λ��
BOOL GetSelectionWorldPos(ProSelection pSel, SVDOUBLE3 &vWorldPos);
// ��ȡ����ѡ�����ķ���
BOOL GetSelectionSurfaceNormal(ProSelection pSelSurface, SVDOUBLE3 &vNormal);

// ������
BOOL CreateGroup(ProSolid pSld, ProName szGroupName, const vector<ProFeature> &arrFeatures, ProGroup &newGroup);

}	// namespace IKS_SMARTCABLINGGLOBAL
