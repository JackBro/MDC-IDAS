//===================================================================================================
// Summary:
//		ע����غ�����
// Date:
//		2015-08-20			����
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __PCLNote_h__
#define __PCLNote_h__

//===================================================================================================

// ����ProEͷ�ļ�
#include <ProDtlnote.h>

// ����IKS���ļ�
#include "IKSNote.h"

//===================================================================================================

namespace PCLNote
{
	// �����ı���ʽ
	BOOL SetTextStyle(
		const IKSTextStyle &textStyle,	// �ı���ʽ(in)
		ProDtlnotetext pNoteText		// �ı�(in)
		);

	// �����ı���ʽ
	BOOL CreateNoteText(
		const IKSTextStyle &textStyle,	// �ı���ʽ(in)
		ProDtlnotetext &pNoteText		// �ı�(out)
		);

	// ����ע���ı���
	void CreateNoteLine(
		const IKSNote &noteInfo,		// ע����Ϣ(in)
		ProDtlnoteline *&pLines			// ע����(out)
		);

	// ��ȡע�͵Ĵ�С
	BOOL GetNoteSizeInDrawing(
		const IKSNote &note,			// ע����Ϣ(in)
		double &dNoteWidth,				// ע�Ϳ��(out)
		double &dNoteHeight				// ע�͸߶�(out)
		);
}

#endif		// __PCLNote_h__

