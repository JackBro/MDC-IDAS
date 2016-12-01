//===================================================================================================
// Summary:
//		内部使用常量和结构体
// Date:
//		2016-11-21
// Author:
//		WangShiping
//===================================================================================================

#pragma once

#include <ProCabling.h>
#include <ProSelection.h>

//===================================================================================================
// 以下为常量定义

//===================================================================================================
// 以下为自定义的消息

//===================================================================================================
// 以下为枚举值定义

// 布线项目类型
typedef enum _IKSMDCROUTCABPROJTYPE
{
	IKSMDCRCPT_INVALID				= 0,		// 非法值
	IKSMDCRCPT_IT					= 1,		// IT柜（强电）
	IKSMDCRCPT_TAC					= 2,		// TAC柜（强电）
	IKSMDCRCPT_BAT					= 3,		// BAT柜（强电）
	IKSMDCRCPT_HVDC					= 4,		// HVDC（强电）
	IKSMDCRCPT_UPS					= 5,		// UPS（强电）
	IKSMDCRCPT_ITPDRH				= 6,		// ITPDRH（强电）
	IKSMDCRCPT_ITPDRU				= 7,		// ITPDRU（强电）
	IKSMDCRCPT_FC					= 8,		// 翻转顶窗（弱电）
	IKSMDCRCPT_ZM					= 9,		// 照明（强电）
	IKSMDCRCPT_MJ					= 10,		// 门禁（弱电）
	IKSMDCRCPT_JJAN					= 11,		// 紧急按钮（弱电）
	IKSMDCRCPT_GK					= 12,		// 管控盒坐标系（强电）
	IKSMDCRCPT_JDX					= 13,		// 接地线
	IKSMDCRCPT_WX					= 14,		// 网线
} IKSMDCROUTCABPROJTYPE;

//===================================================================================================
// 以下为结构体定义

// 电连接器的信息
typedef struct __tagIKSMDCConnector
{
	IKSConnectorParamInfo stuConnParam;		// 电连接器参数
	IKSConnector stuConnDataInCurAsm;		// 当前装配体内的电连接器数据

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

// 电缆布局参数
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

// 电缆设计参数_IT柜（强电）
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

// 电缆设计参数_TAC柜（强电）
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

// 电缆设计参数_BAT柜（强电）
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

// 电缆设计参数_HVDC（强电）
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

// 电缆设计参数_UPS（强电）
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

// 电缆设计参数_ITPDRH（强电）
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

// 电缆设计参数_ITPDRU（强电）
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

// 电缆设计参数_翻转顶窗（弱电）
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

// 电缆设计参数_照明（强电）
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

// 电缆设计参数_门禁（弱电）
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

// 电缆设计参数_紧急按钮（弱电）
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

// 电缆设计参数_管控盒坐标系（强电）
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

// 电缆设计参数_接地线
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

// 电缆设计参数_网线
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

// 电缆设计参数
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

