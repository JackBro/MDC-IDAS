//===================================================================================================
// Summary:
//		工程图相关函数集
// Date:
//		2015-07-24			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __PCLDrawing_h__
#define __PCLDrawing_h__

//===================================================================================================

// 引用ProE头文件
#include <ProDrawing.h>

//===================================================================================================

namespace PCLDrawing
{
	// 获得当前页面矩阵
	void GetCurSheetTrans(
		ProDrawing pDrawing,			// 工程图(in)
		ProMatrix trans					// 矩阵(out)
		);

	// 获取工程图的模型
	ProSolid GetDrwSolid(
		ProDrawing pDrawing				// 工程图(in)
		);

	// 获取工程图的背景视图
	ProView GetBackgroundView(
		ProDrawing pDrawing				// 工程图(in)
		);

	// 获取工程图默认字体高度
	double GetDefaultTextHeight(
		ProDrawing pDrawing				// 工程图(in)
		);

	// 得到工程图的比例
	double GetDrawingScale(
		ProDrawing pDrawing				// 工程图(in)
		);
}

#endif

