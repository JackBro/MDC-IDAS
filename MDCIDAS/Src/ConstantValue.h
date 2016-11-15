//===================================================================================================
// Summary:
//		内部使用常量和结构体
// Date:
//		2016-11-13
// Author:
//		WangShiping
//===================================================================================================

#pragma once

#include "SVBaseDef.h"

//===================================================================================================
//===================================================================================================
// 以下为常量定义

//===================================================================================================
// 数据库模块

//===================================================================================================
// 整机配置模块

//===================================================================================================
// 电缆模块

//===================================================================================================
// 工程图模块




//===================================================================================================
//===================================================================================================
// 以下为自定义的消息

// 定制消息:显示隐藏窗口
#define WM_CUSTOM_SHOWWINDOW			WM_USER + 10001

//===================================================================================================
//===================================================================================================
// 以下为枚举值定义

//===================================================================================================
// 数据库模块

//===================================================================================================
// 整机配置模块

// 模块类型
typedef enum __tagMDCModuleType
{
	MT_LONG_MODULE			= 1,					// 长模块
	MT_MINI_MODULE			= 2,					// 微模块
	MT_TENCENT				= 3,					// 腾讯
	MT_BAIDU_YANGQUAN		= 4,					// 百度阳泉
	MT_BAIDU_HUALONG		= 5,					// 百度化龙
	MT_NEIMENG_ALI			= 6,					// 内蒙阿里
	MT_DIANXIN_MINI_MODULE	= 7,					// 电信微模块
}MDCModuleType;

// 气流模式
typedef enum __tagAirstreamPattern
{
	AP_COLD_SEAL				= 1,				// 冷通道封闭
	AP_HOT_SEAL					= 2,				// 热通道封闭
	AP_COLDANDHOT_DOUBLESEAL	= 3,				// 冷热通道双封闭
}AirstreamPattern;

// IT机柜前门类型
typedef enum __tagFrontDoorTypeOfITRack
{
	FDT_NO_DOOR					= 1,				// 无
	FDT_SINGLE_DENSEHOLE_DOOR	= 2,				// 单开密孔门
	FDT_DOUBLE_DENSEHOLE_DOOR	= 3,				// 双开密孔门
}FrontDoorTypeOfITRack;

// IT机柜后门类型
typedef enum __tagBackDoorTypeOfITRack
{
	BDT_NO_DOOR					= 1,				// 无
	BDT_SINGLE_DENSEHOLE_DOOR	= 2,				// 单开密孔门
	BDT_DOUBLE_DENSEHOLE_DOOR	= 3,				// 双开密孔门
	BDT_SINGLE_SOILD_DOOR		= 4,				// 单开实心门
	BDT_DOUBLE_SOILD_DOOR		= 5,				// 双开实心门
}BackDoorTypeOfITRack;

// IT机柜前门锁类型
typedef enum __tagFrontDoorLockTypeOfITRack
{
	FDLT_UNKNOWN			= -1,					// 未知
	FDLT_UNIVERSIAL_LOCK	= 1,					// 通用锁
	FDLT_HANGING_EAR_LOCK	= 2,					// 挂耳锁
}FrontDoorLockTypeOfITRack;

// IT机柜后门锁类型
typedef enum __tagBackDoorLockTypeOfITRack
{
	BDLT_UNKNOWN			= -1,					// 未知
	BDLT_UNIVERSIAL_LOCK	= 1,					// 通用锁
	BDLT_HANGING_EAR_LOCK	= 2,					// 挂耳锁
}BackDoorLockTypeOfITRack;

// IT机柜侧门类型
typedef enum __tagSideDoorTypeOfITRack
{
	SDT_UNKNOWN				= -1,					// 未知
	SDT_DEFAULT_TYPE		= 1,					// 默认
	SDT_SINGLE_TYPE			= 2,					// 单侧配置
	SDT_DOUBLE_TYPE			= 3,					// 双侧配置
}SideDoorTypeOfITRack;

// 底座高度
typedef enum __tagHeightOfPedestal
{
	HP_UNKNOWN				= -1,					// 未知
	HP_250					= 1,					// 250mm
	HP_300					= 2,					// 300mm
	HP_350					= 3,					// 350mm
	HP_400					= 4,					// 400mm
	HP_450					= 5,					// 450mm
	HP_500					= 6,					// 500mm
	HP_550					= 7,					// 550mm
	HP_600					= 8,					// 600mm
	HP_650					= 9,					// 650mm
	HP_700					= 10,					// 700mm
	HP_750					= 11,					// 750mm
	HP_800					= 12,					// 800mm
	HP_OTHER				= 13,					// 其他
}HeightOfPedestal;

// 模块内部地板
typedef enum __tagInsideFloorType
{
	IFT_UNKNOWN				= -1,					// 未知
	IFT_NO_FLOOR			= 1,					// 无需配置
	IFT_DEFAULT_FLOOR		= 2,					// 默认配置
}InsideFloorType;

// 走线架配置类型
typedef enum __tagZouXianJiaType
{
	ZXJT_UNKNOWN			= -1,					// 未知
	ZXJT_MODULE_TYPE		= 1,					// 模块配置
	ZXJT_MACHINE_ROOM_TYPE	= 2,					// 机房配置
}ZouXianJiaType;

// 汇流排类型
typedef enum __tagHuiLiuPaiType
{
	HLPT_UNKNOWN			= -1,					// 未知
	HLPT_NO_TYPE			= 1,					// 不配置
	HLPT_HENGZHUANG_TYPE	= 2,					// 横装
	HLPT_SHUZHUANG_TYPE		= 3,					// 竖装
}HuiLiuPaiType;

// 管控柜类型
typedef enum __tagControlCabinetType
{
	CCT_UNKNOWN				= -1,					// 未知
	CCT_NO_CAB				= 1,					// 无
	CCT_COL_HEAD_CAB		= 2,					// 列头管控柜
	CCT_IT_CAB				= 3,					// 服务器管控柜
	CCT_COL_HEAD_PAD_CAB	= 4,					// 列头管控柜带PAD
	CCT_IT_PAD_CAB			= 5,					// 服务器管控柜带PAD
}ControlCabinetType;

//===================================================================================================
// 电缆模块

//===================================================================================================
// 工程图模块



//===================================================================================================
//===================================================================================================
// 以下为结构体定义

//===================================================================================================
// 数据库模块

//===================================================================================================
// 整机配置模块

// 需求采集表数据
typedef struct __tagRequirementTabData
{
	int nModuleType;								// 模块类型
	bool bIsExtFloorExist;							// 模块外围有无地板
	int nAirstreamPattern;							// 气流模式
	CString strPassageWidth;						// 通道宽度
	CString strHeightOfITRack;						// IT机柜规格——高度
	CString strWidthOfITRack;						// IT机柜规格——宽度
	CString strDepthOfITRack;						// IT机柜规格——深度
	int nFrontDoorTypeOfITRack;						// IT机柜的前门类型
	int nBackDoorTypeOfITRack;						// IT机柜的后门类型
	int nFrontDoorLockTypeOfITRack;					// IT机柜的前门锁类型
	int nBackDoorLockTypeOfITRack;					// IT机柜的后门锁类型
	int nSideDoorTypeOfITRack;						// IT机柜的侧门
	int nHeightOfPedestal;							// 底座高度
	int nInsideFloorType;							// 模块内部地板
	int nZouXianJiaType;							// 强弱电走线架配置类型
	CString strDistanceBetwZXJAndJigui;				// （走线架机房配置），走线架距离机柜顶部距离；
	CString strNumOf1UPanel;						// 1U假面板的数量
	CString strNumOf2UPanel;						// 2U假面板的数量
	CString strNumOfLPallet;						// L型托板的数量
	CString strNumOfLightLayer;						// 轻载层板的数量
	CString strNumOfHeavyLayer;						// 重载层板的数量
	CString strNumOfStringingPanel;					// 穿线面板的数量
	int nHuiLiuPaiType;								// 汇流排的类型
	bool bIsWeiBanExist;							// 围板是否配置
	bool bIsInsideFloorExist;						// 模块内部是否配置地板
	bool bIsTABuExist;								// 是否配置踏步
	int nControlCabinetType;						// 管控柜类型

	__tagRequirementTabData()
	{
		nModuleType = -1;
		bIsExtFloorExist = false;
		nAirstreamPattern = -1;
		strPassageWidth = _T("");
		strHeightOfITRack = _T("");
		strWidthOfITRack = _T("");
		strDepthOfITRack = _T("");
		nFrontDoorTypeOfITRack = 1;
		nBackDoorTypeOfITRack = -1;
		nFrontDoorLockTypeOfITRack = -1;
		nBackDoorLockTypeOfITRack = -1;
		nSideDoorTypeOfITRack = -1;
		nHeightOfPedestal = -1;
		nInsideFloorType = -1;
		nZouXianJiaType = -1;
		strDistanceBetwZXJAndJigui = _T("");
		strNumOf1UPanel = _T("");
		strNumOf2UPanel = _T("");
		strNumOfLPallet = _T("");
		strNumOfLightLayer = _T("");
		strNumOfHeavyLayer = _T("");
		strNumOfStringingPanel = _T("");
		nHuiLiuPaiType = -1;
		bIsWeiBanExist = false;
		bIsInsideFloorExist = false;
		bIsTABuExist = false;
		nControlCabinetType = -1;
	}
	__tagRequirementTabData(const __tagRequirementTabData &data)
	{
		nModuleType = data.nModuleType;
		bIsExtFloorExist = data.bIsExtFloorExist;
		nAirstreamPattern = data.nAirstreamPattern;
		strPassageWidth = data.strPassageWidth;
		strHeightOfITRack = data.strHeightOfITRack;
		strWidthOfITRack = data.strWidthOfITRack;
		strDepthOfITRack = data.strDepthOfITRack;
		nFrontDoorTypeOfITRack = data.nFrontDoorTypeOfITRack;
		nBackDoorTypeOfITRack = data.nBackDoorTypeOfITRack;
		nFrontDoorLockTypeOfITRack = data.nFrontDoorLockTypeOfITRack;
		nBackDoorLockTypeOfITRack = data.nBackDoorLockTypeOfITRack;
		nSideDoorTypeOfITRack = data.nSideDoorTypeOfITRack;
		nHeightOfPedestal = data.nHeightOfPedestal;
		nInsideFloorType = data.nInsideFloorType;
		nZouXianJiaType = data.nZouXianJiaType;
		strDistanceBetwZXJAndJigui = data.strDistanceBetwZXJAndJigui;
		strNumOf1UPanel = data.strNumOf1UPanel;
		strNumOf2UPanel = data.strNumOf2UPanel;
		strNumOfLPallet = data.strNumOfLPallet;
		strNumOfLightLayer = data.strNumOfLightLayer;
		strNumOfHeavyLayer = data.strNumOfHeavyLayer;
		strNumOfStringingPanel = data.strNumOfStringingPanel;
		nHuiLiuPaiType = data.nHuiLiuPaiType;
		bIsWeiBanExist = data.bIsWeiBanExist;
		bIsInsideFloorExist = data.bIsInsideFloorExist;
		bIsTABuExist = data.bIsTABuExist;
		nControlCabinetType = data.nControlCabinetType;
	}
	__tagRequirementTabData operator=(const __tagRequirementTabData &data)
	{
		if (&data == this)
			return *this;
		nModuleType = data.nModuleType;
		bIsExtFloorExist = data.bIsExtFloorExist;
		nAirstreamPattern = data.nAirstreamPattern;
		strPassageWidth = data.strPassageWidth;
		strHeightOfITRack = data.strHeightOfITRack;
		strWidthOfITRack = data.strWidthOfITRack;
		strDepthOfITRack = data.strDepthOfITRack;
		nFrontDoorTypeOfITRack = data.nFrontDoorTypeOfITRack;
		nBackDoorTypeOfITRack = data.nBackDoorTypeOfITRack;
		nFrontDoorLockTypeOfITRack = data.nFrontDoorLockTypeOfITRack;
		nBackDoorLockTypeOfITRack = data.nBackDoorLockTypeOfITRack;
		nSideDoorTypeOfITRack = data.nSideDoorTypeOfITRack;
		nHeightOfPedestal = data.nHeightOfPedestal;
		nInsideFloorType = data.nInsideFloorType;
		nZouXianJiaType = data.nZouXianJiaType;
		strDistanceBetwZXJAndJigui = data.strDistanceBetwZXJAndJigui;
		strNumOf1UPanel = data.strNumOf1UPanel;
		strNumOf2UPanel = data.strNumOf2UPanel;
		strNumOfLPallet = data.strNumOfLPallet;
		strNumOfLightLayer = data.strNumOfLightLayer;
		strNumOfHeavyLayer = data.strNumOfHeavyLayer;
		strNumOfStringingPanel = data.strNumOfStringingPanel;
		nHuiLiuPaiType = data.nHuiLiuPaiType;
		bIsWeiBanExist = data.bIsWeiBanExist;
		bIsInsideFloorExist = data.bIsInsideFloorExist;
		bIsTABuExist = data.bIsTABuExist;
		nControlCabinetType = data.nControlCabinetType;
		return *this;
	}
}RequirementTabData;

//===================================================================================================
// 电缆模块

//===================================================================================================
// 工程图模块



//===================================================================================================

