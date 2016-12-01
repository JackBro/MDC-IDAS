//===================================================================================================
// Summary:
//		�ڲ�ʹ�ó����ͽṹ��
// Date:
//		2016-11-21
// Author:
//		WangShiping
//===================================================================================================

#pragma once

#include <ProCabling.h>
#include <ProSelection.h>

//===================================================================================================
// ����Ϊ��������

//===================================================================================================
// ����Ϊ�Զ������Ϣ

//===================================================================================================
// ����Ϊö��ֵ����

// ������Ŀ����
typedef enum _IKSMDCROUTCABPROJTYPE
{
	IKSMDCRCPT_INVALID				= 0,		// �Ƿ�ֵ
	IKSMDCRCPT_IT					= 1,		// IT��ǿ�磩
	IKSMDCRCPT_TAC					= 2,		// TAC��ǿ�磩
	IKSMDCRCPT_BAT					= 3,		// BAT��ǿ�磩
	IKSMDCRCPT_HVDC					= 4,		// HVDC��ǿ�磩
	IKSMDCRCPT_UPS					= 5,		// UPS��ǿ�磩
	IKSMDCRCPT_ITPDRH				= 6,		// ITPDRH��ǿ�磩
	IKSMDCRCPT_ITPDRU				= 7,		// ITPDRU��ǿ�磩
	IKSMDCRCPT_FC					= 8,		// ��ת���������磩
	IKSMDCRCPT_ZM					= 9,		// ������ǿ�磩
	IKSMDCRCPT_MJ					= 10,		// �Ž������磩
	IKSMDCRCPT_JJAN					= 11,		// ������ť�����磩
	IKSMDCRCPT_GK					= 12,		// �ܿغ�����ϵ��ǿ�磩
	IKSMDCRCPT_JDX					= 13,		// �ӵ���
	IKSMDCRCPT_WX					= 14,		// ����
} IKSMDCROUTCABPROJTYPE;

//===================================================================================================
// ����Ϊ�ṹ�嶨��

// ������������Ϣ
typedef struct __tagIKSMDCConnector
{
	IKSConnectorParamInfo stuConnParam;		// ������������
	IKSConnector stuConnDataInCurAsm;		// ��ǰװ�����ڵĵ�����������

	__tagIKSMDCConnector()
	{
		Clear();
	}
	__tagIKSMDCConnector(const __tagIKSMDCConnector &info)
	{
		stuConnParam = info.stuConnParam;
		stuConnDataInCurAsm = info.stuConnDataInCurAsm;
	}
	__tagIKSMDCConnector& operator=(const __tagIKSMDCConnector &info)
	{
		if (&info == this)
			return *this;
		stuConnParam = info.stuConnParam;
		stuConnDataInCurAsm = info.stuConnDataInCurAsm;
		return *this;
	}
	void Clear()
	{
		stuConnParam.Clear();
		stuConnDataInCurAsm.Clear();
	}
} IKSMDCConnector;

// ���²��ֲ���
typedef struct __tagIKSMDCCableLayoutParam
{
	SVBASEDOUBLE3 vTestPos;

	__tagIKSMDCCableLayoutParam()
	{
		Clear();
	}
	__tagIKSMDCCableLayoutParam(const __tagIKSMDCCableLayoutParam &info)
	{
		vTestPos = info.vTestPos;
	}
	__tagIKSMDCCableLayoutParam& operator=(const __tagIKSMDCCableLayoutParam &info)
	{
		if (&info == this)
			return *this;
		vTestPos = info.vTestPos;
		return *this;
	}
	void Clear()
	{
		memset(&vTestPos, 0, sizeof(SVBASEDOUBLE3));
	}
} IKSMDCCableLayoutParam;

// ������Ʋ���_IT��ǿ�磩
typedef struct __tagIKSMDCCableDesignParam_IT
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_IT()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_IT(const __tagIKSMDCCableDesignParam_IT &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_IT& operator=(const __tagIKSMDCCableDesignParam_IT &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_IT;

// ������Ʋ���_TAC��ǿ�磩
typedef struct __tagIKSMDCCableDesignParam_TAC
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_TAC()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_TAC(const __tagIKSMDCCableDesignParam_TAC &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_TAC& operator=(const __tagIKSMDCCableDesignParam_TAC &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_TAC;

// ������Ʋ���_BAT��ǿ�磩
typedef struct __tagIKSMDCCableDesignParam_BAT
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_BAT()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_BAT(const __tagIKSMDCCableDesignParam_BAT &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_BAT& operator=(const __tagIKSMDCCableDesignParam_BAT &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_BAT;

// ������Ʋ���_HVDC��ǿ�磩
typedef struct __tagIKSMDCCableDesignParam_HVDC
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_HVDC()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_HVDC(const __tagIKSMDCCableDesignParam_HVDC &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_HVDC& operator=(const __tagIKSMDCCableDesignParam_HVDC &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_HVDC;

// ������Ʋ���_UPS��ǿ�磩
typedef struct __tagIKSMDCCableDesignParam_UPS
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_UPS()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_UPS(const __tagIKSMDCCableDesignParam_UPS &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_UPS& operator=(const __tagIKSMDCCableDesignParam_UPS &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_UPS;

// ������Ʋ���_ITPDRH��ǿ�磩
typedef struct __tagIKSMDCCableDesignParam_ITPDRH
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_ITPDRH()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_ITPDRH(const __tagIKSMDCCableDesignParam_ITPDRH &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_ITPDRH& operator=(const __tagIKSMDCCableDesignParam_ITPDRH &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_ITPDRH;

// ������Ʋ���_ITPDRU��ǿ�磩
typedef struct __tagIKSMDCCableDesignParam_ITPDRU
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_ITPDRU()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_ITPDRU(const __tagIKSMDCCableDesignParam_ITPDRU &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_ITPDRU& operator=(const __tagIKSMDCCableDesignParam_ITPDRU &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_ITPDRU;

// ������Ʋ���_��ת���������磩
typedef struct __tagIKSMDCCableDesignParam_FC
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_FC()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_FC(const __tagIKSMDCCableDesignParam_FC &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_FC& operator=(const __tagIKSMDCCableDesignParam_FC &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_FC;

// ������Ʋ���_������ǿ�磩
typedef struct __tagIKSMDCCableDesignParam_ZM
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_ZM()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_ZM(const __tagIKSMDCCableDesignParam_ZM &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_ZM& operator=(const __tagIKSMDCCableDesignParam_ZM &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_ZM;

// ������Ʋ���_�Ž������磩
typedef struct __tagIKSMDCCableDesignParam_MJ
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_MJ()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_MJ(const __tagIKSMDCCableDesignParam_MJ &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_MJ& operator=(const __tagIKSMDCCableDesignParam_MJ &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_MJ;

// ������Ʋ���_������ť�����磩
typedef struct __tagIKSMDCCableDesignParam_JJAN
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_JJAN()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_JJAN(const __tagIKSMDCCableDesignParam_JJAN &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_JJAN& operator=(const __tagIKSMDCCableDesignParam_JJAN &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_JJAN;

// ������Ʋ���_�ܿغ�����ϵ��ǿ�磩
typedef struct __tagIKSMDCCableDesignParam_GK
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_GK()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_GK(const __tagIKSMDCCableDesignParam_GK &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_GK& operator=(const __tagIKSMDCCableDesignParam_GK &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_GK;

// ������Ʋ���_�ӵ���
typedef struct __tagIKSMDCCableDesignParam_JDX
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_JDX()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_JDX(const __tagIKSMDCCableDesignParam_JDX &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_JDX& operator=(const __tagIKSMDCCableDesignParam_JDX &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_JDX;

// ������Ʋ���_����
typedef struct __tagIKSMDCCableDesignParam_WX
{
	BOOL bValid;

	__tagIKSMDCCableDesignParam_WX()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam_WX(const __tagIKSMDCCableDesignParam_WX &info)
	{
		bValid = info.bValid;
	}
	__tagIKSMDCCableDesignParam_WX& operator=(const __tagIKSMDCCableDesignParam_WX &info)
	{
		if (&info == this)
			return *this;
		bValid = info.bValid;
		return *this;
	}
	void Clear()
	{
		bValid = FALSE;
	}
} IKSMDCCableDesignParam_WX;

// ������Ʋ���
typedef struct __tagIKSMDCCableDesignParam
{
	IKSMDCCableDesignParam_IT		stuIT;
	IKSMDCCableDesignParam_TAC		stuTAC;
	IKSMDCCableDesignParam_BAT		stuBAT;
	IKSMDCCableDesignParam_HVDC		stuHVDC;
	IKSMDCCableDesignParam_UPS		stuUPS;
	IKSMDCCableDesignParam_ITPDRH	stuITPDRH;
	IKSMDCCableDesignParam_ITPDRU	stuITPDRU;
	IKSMDCCableDesignParam_FC		stuFC;
	IKSMDCCableDesignParam_ZM		stuZM;
	IKSMDCCableDesignParam_MJ		stuMJ;
	IKSMDCCableDesignParam_JJAN		stuJJAN;
	IKSMDCCableDesignParam_GK		stuGK;
	IKSMDCCableDesignParam_JDX		stuJDX;
	IKSMDCCableDesignParam_WX		stuWX;

	__tagIKSMDCCableDesignParam()
	{
		Clear();
	}
	__tagIKSMDCCableDesignParam(const __tagIKSMDCCableDesignParam &info)
	{
		stuIT = info.stuIT;
		stuTAC = info.stuTAC;
		stuBAT = info.stuBAT;
		stuHVDC = info.stuHVDC;
		stuUPS = info.stuUPS;
		stuITPDRH = info.stuITPDRH;
		stuITPDRU = info.stuITPDRU;
		stuFC = info.stuFC;
		stuZM = info.stuZM;
		stuMJ = info.stuMJ;
		stuJJAN = info.stuJJAN;
		stuGK = info.stuGK;
		stuJDX = info.stuJDX;
		stuWX = info.stuWX;
	}
	__tagIKSMDCCableDesignParam& operator=(const __tagIKSMDCCableDesignParam &info)
	{
		if (&info == this)
			return *this;
		stuIT = info.stuIT;
		stuTAC = info.stuTAC;
		stuBAT = info.stuBAT;
		stuHVDC = info.stuHVDC;
		stuUPS = info.stuUPS;
		stuITPDRH = info.stuITPDRH;
		stuITPDRU = info.stuITPDRU;
		stuFC = info.stuFC;
		stuZM = info.stuZM;
		stuMJ = info.stuMJ;
		stuJJAN = info.stuJJAN;
		stuGK = info.stuGK;
		stuJDX = info.stuJDX;
		stuWX = info.stuWX;
		return *this;
	}
	void Clear()
	{
		stuIT.Clear();
		stuTAC.Clear();
		stuBAT.Clear();
		stuHVDC.Clear();
		stuUPS.Clear();
		stuITPDRH.Clear();
		stuITPDRU.Clear();
		stuFC.Clear();
		stuZM.Clear();
		stuMJ.Clear();
		stuJJAN.Clear();
		stuGK.Clear();
		stuJDX.Clear();
		stuWX.Clear();
	}
} IKSMDCCableDesignParam;

//===================================================================================================

