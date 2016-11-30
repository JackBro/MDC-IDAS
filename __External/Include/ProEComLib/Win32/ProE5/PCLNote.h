//===================================================================================================
// Summary:
//		注释相关函数集
// Date:
//		2015-08-20			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __PCLNote_h__
#define __PCLNote_h__

//===================================================================================================

// 引用ProE头文件
#include <ProDtlnote.h>

// 引用IKS库文件
#include "IKSNote.h"

//===================================================================================================

namespace PCLNote
{
	// 设置文本样式
	BOOL SetTextStyle(
		const IKSTextStyle &textStyle,	// 文本样式(in)
		ProDtlnotetext pNoteText		// 文本(in)
		);

	// 创建文本样式
	BOOL CreateNoteText(
		const IKSTextStyle &textStyle,	// 文本样式(in)
		ProDtlnotetext &pNoteText		// 文本(out)
		);

	// 创建注释文本行
	void CreateNoteLine(
		const IKSNote &noteInfo,		// 注释信息(in)
		ProDtlnoteline *&pLines			// 注释行(out)
		);

	// 获取注释的大小
	BOOL GetNoteSizeInDrawing(
		const IKSNote &note,			// 注释信息(in)
		double &dNoteWidth,				// 注释宽度(out)
		double &dNoteHeight				// 注释高度(out)
		);
}

#endif		// __PCLNote_h__

