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

#include "Global.h"

//===================================================================================================

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
// ѡ�񵥸�����
BOOL SelectOneObject(ProSelection &pSelObj, char *pSelOpt, ProSelFunctions *pSelFunc = NULL, ProSelectionEnv pSelEnv = NULL);


//===================================================================================================
