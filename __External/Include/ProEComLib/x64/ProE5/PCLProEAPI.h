//===================================================================================================
// Summary:
//		ProE函数集
// Date:
//		2015-08-20			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __PCLProEAPI_h__
#define __PCLProEAPI_h__

//===================================================================================================

// 引用ProE头文件

#include <ProToolkit.h>
#include <ProUtil.h>
#include <ProMessage.h>
#include <ProUIMessage.h>
#include <ProNotify.h>
#include <ProWindows.h>
#include <ProDisplist.h>
#include <ProGraphic.h>
#include <ProColor.h>
#include <ProArray.h>
#include <ProWstring.h>
#include <ProSelection.h>
#include <ProReference.h>
#include <ProSelbuffer.h>
#include <ProAsmcomp.h>
#include <ProAsmcomppath.h>
#include <ProMdl.h>
#include <ProModelitem.h>
#include <ProMdlUnits.h>
#include <ProSolid.h>
#include <ProSkeleton.h>
#include <ProFeature.h>
#include <ProVariantFeat.h>
#include <ProElement.h>
#include <ProElempath.h>
#include <ProValue.h>
#include <ProDrawing.h>
#include <ProView.h>
#include <ProDwgtable.h>
#include <ProMenu.h>
#include <ProMenuBar.h>
#include <ProPopupmenu.h>
#include <ProParameter.h>
#include <ProParamval.h>
#include <ProRelSet.h>
#include <ProDtlnote.h>
#include <ProDtlattach.h>
#include <ProDtlsymdef.h>
#include <ProDtlsyminst.h>
#include <ProDtlgroup.h>
#include <ProDimension.h>
#include <ProGtol.h>
#include <ProAnnotation.h>
#include <ProDtlentity.h>
#include <ProNote.h>

// 几何
#include <ProPoint.h>
#include <ProAxis.h>
#include <ProCsys.h>
#include <ProCurve.h>
#include <ProCurvedata.h>
#include <ProEdge.h>
#include <ProEdgedata.h>
#include <ProContour.h>
#include <ProContourdata.h>
#include <ProQuilt.h>
#include <ProQuiltdata.h>
#include <ProSurface.h>
#include <ProSurfacedata.h>
#include <ProGeomitem.h>
#include <ProGeomitemdata.h>

// 特征相关头文件
#include <ProFeatType.h>
#include <ProAnalysis.h>
#include <ProAsmcomp.h>
#include <ProChamfer.h>
#include <ProDraft.h>
#include <ProDtmAxis.h>
#include <ProDtmCrv.h>
#include <ProDtmCsys.h>
#include <ProDtmPln.h>
#include <ProDtmPnt.h>
#include <ProElemId.h>
#include <ProExtrude.h>
#include <ProFeatIntr.h>
#include <ProFixture.h>
#include <ProFlatSrf.h>
#include <ProForeignCurve.h>
#include <ProHole.h>
#include <ProMfgoper.h>
#include <ProMerge.h>
#include <ProMirror.h>
#include <ProMove.h>
#include <ProNcseq.h>
#include <ProNcseqElem.h>
#include <ProPattern.h>
#include <ProReplace.h>
#include <ProRevolve.h>
#include <ProRib.h>
#include <ProRound.h>
#include <ProShell.h>
#include <ProSmtFlangeWall.h>
#include <ProSmtFlatWall.h>
#include <ProSolidify.h>
#include <ProStdSection.h>
#include <ProSweep.h>
#include <ProThicken.h>
#include <ProTrim.h>
#include <ProToolElem.h>
#include <ProWcell.h>
#include <ProGroup.h>
#include <ProUdf.h>

//===================================================================================================

#define PRO_CALL(X) (ReportError(#X, (X)))

ProError ReportError(char* szFuncName, ProError status);

#define CHECK_STATUS(status) if (status != PRO_TK_NO_ERROR) return status;

//===================================================================================================

#endif	// __PCLProEAPI_h__

