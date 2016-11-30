//===================================================================================================
// Summary:
//		����ͼ��غ�����
// Date:
//		2015-07-24			����
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __PCLDrawing_h__
#define __PCLDrawing_h__

//===================================================================================================

// ����ProEͷ�ļ�
#include <ProDrawing.h>

//===================================================================================================

namespace PCLDrawing
{
	// ��õ�ǰҳ�����
	void GetCurSheetTrans(
		ProDrawing pDrawing,			// ����ͼ(in)
		ProMatrix trans					// ����(out)
		);

	// ��ȡ����ͼ��ģ��
	ProSolid GetDrwSolid(
		ProDrawing pDrawing				// ����ͼ(in)
		);

	// ��ȡ����ͼ�ı�����ͼ
	ProView GetBackgroundView(
		ProDrawing pDrawing				// ����ͼ(in)
		);

	// ��ȡ����ͼĬ������߶�
	double GetDefaultTextHeight(
		ProDrawing pDrawing				// ����ͼ(in)
		);

	// �õ�����ͼ�ı���
	double GetDrawingScale(
		ProDrawing pDrawing				// ����ͼ(in)
		);
}

#endif

