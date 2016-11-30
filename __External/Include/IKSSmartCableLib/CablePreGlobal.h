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

#include <ProWTUtils.h>

//===================================================================================================

namespace IKS_SMARTCABLINGGLOBAL
{

// ��õ�ǰģ��  
ProMdl GetCurrentMdl();
// �������ƻ��ģ��
ProMdl GetMdlByNameAndType(ProName mdlName, ProMdlType mdlType);
// ����ģ��
ProMdl ReloadMdl(ProMdl pMdl);
// ��õ�ǰ���ģ��  
ProPart GetCurrentPart();
// ��õ�ǰ���ģ��  
ProAssembly GetCurrentAssembly();

// ���ǰ����
ProError ActivateCurrentPreWindow();
// �ػ洰��
void RepaintCurrentPreWindow();
// ˢ�´��ڣ������ʱͼ�Σ����������������ʾ
void RefreshCurrentPreWindow();

// ����ֱ�߶�
void DrawGraphicsLine(const SVBASEDOUBLE3& end1, const SVBASEDOUBLE3& end2);
// ͨ�����߻���Բ��
void DrawGraphicsCircleByPolyline(const SVBASEDOUBLE3& vOrigin, const SVBASEDOUBLE3& vVector1, const SVBASEDOUBLE3& vVector2, double dRadius, int nSlices=32);

// �����任����
void MatrixCopy(ProMatrix input, ProMatrix output);
// �������
IKS_BOOL MatrixInvert(ProMatrix input, ProMatrix output);
// �������
void MatrixMultiply(const ProMatrix matrix1, const ProMatrix matrix2, ProMatrix matrixOut);
// �����š���ת��ƽ�Ƶļ���������зֽ�
void DecomposeSRTMatrix(const ProMatrix &matSRT, ProMatrix matScale=NULL, ProMatrix matRot=NULL, ProMatrix matTrans=NULL);
// ���ݾ����ȡ��Z��ת�ĽǶ�ֵ
IKS_BOOL GetAngleByRotMatrix(const ProMatrix &matRotZ, double &dAngle);
// ��õ�ǰҳ�����
void GetDrawingTrans(ProDrawing pDrawing, ProMatrix trans);
// �߼�����ת��Ϊ��ͼ����
void LogicPtToViewPt(ProMatrix invertViewTrans, ProVector ptLogic, ProVector ptView);
// ��ͼ����ת��Ϊ�߼�����
void ViewPtToLogicPt(ProMatrix viewTrans, ProVector ptView, ProVector ptLogic);

// ��ȡѡ����������ѡ���
BOOL GetSelectionWorldPos(ProSelection pSel, ProPoint3d pos);
// ��ȡѡ���������編����Ҫ���ƽ�棩
BOOL GetSelectionWorldNormal(ProSelection pSel, ProPoint3d vec);
// ��ȡѡ�������������
BOOL GetSelectionWorldMatrix(ProSelection pSel, ProMatrix trf);
// ʰȡһ������
BOOL SelectOneObject(ProSelection &pSelObj, char *pSelOpt, ProSelFunctions *pSelFunc = NULL);
// ʰȡ�������
BOOL SelectMultiObject(std::vector<ProSelection> &vecSelObj, char *pSelOpt, ProSelFunctions *pSelFunc = NULL);

// ��ȡ�ߵ�����
ProEnttype GetEdgeType(ProGeomitem *pEnt);
// ��ȡ���ߵ�����
ProEnttype GetCurveType(ProGeomitem *pEnt);
// ��ȡ�ݻ漸�ε�����
ProEnttype GetDtlEntType(ProDtlentity *pEnt);
// ��ȡ���������
ProSrftype GetSurfaceType(ProSurface pSurf);

// ͨ��װ��·����ȡ��ģ��
ProMdl GetParentMdlByAsmcomppath(const ProAsmcomppath &path);
// �ж������װ��·���Ƿ���ͬ
BOOL IsAsmcomppathSame(const ProAsmcomppath &path1, const ProAsmcomppath &path2);

// ��ȡ������ת�����ַ���
BOOL GetParameterString(ProModelitem *pMdlItem, const CString &strName, CString &strValue);

}	// namespace IKS_SMARTCABLINGGLOBAL

//===================================================================================================
