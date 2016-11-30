//===================================================================================================
// Summary:
//		�����ڲ�ʹ�õĹ�������
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

// ���ٶԻ���
void DestroyDialog(CDialog *pDlg);

// ��ȡ��ģ̬�Ի�������Ͻ�λ��
CRect GetSceenCenterRect(int nOffsetX, int nOffsetY, const CRect &rcRect);
// ��ȡ��ģ̬�Ի�������Ͻ�λ��
CRect GetSceenLeftTopRect(int nOffsetX, int nOffsetY, const CRect &rcRect);

// ���ݾ����ȡ���ű任�ı���ϵ��
double GetScaleRatioByMatrix(const SVBASEMATRIX &matrix);

// �ж������Ƿ�պ�(�����������Ҫ����˳������)
BOOL CheckCurveClose(const std::vector<IKSCABDCurve> &vecCurves, std::vector<SVBASEDOUBLE3> *pvecPortArr=NULL);
// ��ȡԲ���������յ�����
BOOL GetArcStartEndPos(const IKSCABDCurve &arc, SVBASEDOUBLE3 &vStart, SVBASEDOUBLE3 &vEnd);
// ��ȡԲ���������յ�����
BOOL GetCurveStartEndPos(const IKSCABDCurve &curve, SVBASEDOUBLE3 &vStart, SVBASEDOUBLE3 &vEnd);

// ��ȡ����1�任Ϊ��2��ת������
void GetAxisTransformMatrix(const SVBASEDOUBLE3 &vSrcOrigin, const SVBASEDOUBLE3 &vSrcAxis, 
							const SVBASEDOUBLE3 &vTgtOrigin, const SVBASEDOUBLE3 &vTgtAxis, SVBASEMATRIX &matrix);

// SVF�ļ��������
IKS_BOOL WriteSVFFile_Data(const wchar_t *szData, FILE *pFile);

// ���û������ϵ�򴴽�Ĭ������ϵ
BOOL CreateDefaultCSysIfEmpty(ProSolid pSld, ProFeature *pFeature=NULL);
// ���û������ϵ�򴴽�Ĭ������ϵ
BOOL CreateDefaultCSysIfEmpty(ProSelection pSldSel, ProFeature *pFeature=NULL);

// ͨ��ģ�����ڵ��ȡ������������ϵ����(ProSelection��Ҫʹ���������ͷ��ڴ�)
BOOL GetCSysGeomInModelTreeNode(const CABModelNodeData *pSkeletonTreeNode, std::vector<ProGeomitem> *pvecCSysGeom=NULL, std::vector<ProSelection> *pvecCSysGeomSel=NULL, std::vector<CSVWString> *pvecCSysName=NULL);
// ͨ��ģ�����ڵ��ȡ������������ϵ����(ProSelection��Ҫʹ���������ͷ��ڴ�)
BOOL GetCSysGeomInModelTreeNode(ProAsmcomppath* pSolidCmpPath, std::vector<ProGeomitem> *pvecCSysGeom=NULL, std::vector<ProSelection> *pvecCSysGeomSel=NULL, std::vector<CSVWString> *pvecCSysName=NULL);

// ��ȡ��ǰģ��·��
CString GetCurModulePath();
// ���õ�ǰģ��·��
void SetCurModulePath(const CString &strMainModulePath);
// ��ȡ���������ļ�����·��
void GetCableConfigPath(CString& strPath);

}	// namespace IKS_SMARTCABLINGGLOBAL

//===================================================================================================

#endif