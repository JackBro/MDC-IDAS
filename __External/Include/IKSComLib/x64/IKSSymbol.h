//===================================================================================================
// Summary:
//		������
// Date:
//		2015-09-19			����
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSSymbol_h__
#define __IKSSymbol_h__

//===================================================================================================

#include "IKSGeom.h"
#include "IKSNote.h"

//===================================================================================================

// ���ŵķ��÷�ʽ
typedef enum __tagIKSSymbolAttachType
{
	SATYPE_FREE,
	SATYPE_LEFT_LEADER,
	SATYPE_RIGHT_LEADER,
	SATYPE_RADIAL_LEADER,
	SATYPE_ON_ITEM,
	SATYPE_NORM_ITEM
} IKSSymbolAttachType;

//===================================================================================================

class CIKSSymbol
{
public:
	CIKSSymbol();
	virtual ~CIKSSymbol();

protected:
	// ��ȡ��Χ�е����ߣ���Ϊ�ڲ�����
	void GetBoxCurves(
		IKSBox dOutline,					// ��Χ��
		IKSCurveArray &arrCurves			// ���߼�
		);
};

//===================================================================================================

#endif