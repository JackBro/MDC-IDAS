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
#include "DocModelDef.h"
#include "XmlToObject.h"

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

// 设计用组件类型
typedef enum __tagDesignModelType
{
	DMT_UNKNOWN				= -1,					// 未知
	DMT_ITC					= 1001,					// 服务器机柜
	DMT_MGT					= 1002,					// 管控柜
	DMT_COL_HAED_MGT 		= 1003,					// 列头管控柜
	DMT_TAC					= 1004,					// 空调柜
	DMT_FHC					= 1005,					// 消防柜
	DMT_COL_HAED_EMPTY		= 1006,					// 列头空柜
	DMT_PDR					= 1007,					// 配电柜
	DMT_COL_HEAD_PDR		= 1008,					// 列头配电柜
	DMT_ROW_EMPTY			= 1009,					// 行间空柜
	DMT_DAO_FENG			= 1010,					// 导风柜
	DMT_CASO4_FLOOR			= 1011,					// 硫酸钙地板
	DMT_STEEL_FLOOR			= 1012,					// 全钢通风地板
	DMT_COLD_FRONT_DOOR		= 1013,					// 通道平门
	DMT_COLD_BACK_DOOR		= 1014,					// 通道凸门
	DMT_LEFT_FRAME			= 1015,					// 左框架
	DMT_RIGHT_FRAME			= 1016,					// 右框架
	DMT_FLIP_WINDOW			= 1017,					// 翻转顶窗
	DMT_FIXED_WINDOW		= 1018,					// 固定顶窗
	DMT_ADJUST_WINDOW		= 1019,					// 可调顶窗
	DMT_FOOTSTEP			= 1020,					// 踏步
	DMT_ZOU_XIAN_JIA		= 1021,					// 强弱电走线架
	DMT_GUANG_XIAN_ZXJ		= 1022,					// 光纤走线架
	DMT_WALL_PILLAR			= 1023,					// 墙柱
	DMT_JIA_PANEL			= 1024,					// 假面板
	DMT_CHUAN_XIAN_PANEL	= 1025,					// 穿线面板

}DesignModelType;

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
	double dPassageWidth;							// 通道宽度
	double dHeightOfITRack;							// IT机柜规格——高度
	double dWidthOfITRack;							// IT机柜规格——宽度
	double dDepthOfITRack;							// IT机柜规格——深度
	int nFrontDoorTypeOfITRack;						// IT机柜的前门类型
	int nBackDoorTypeOfITRack;						// IT机柜的后门类型
	int nFrontDoorLockTypeOfITRack;					// IT机柜的前门锁类型
	int nBackDoorLockTypeOfITRack;					// IT机柜的后门锁类型
	int nSideDoorTypeOfITRack;						// IT机柜的侧门
	int nHeightOfPedestal;							// 底座高度
	int nInsideFloorType;							// 模块内部地板
	int nZouXianJiaType;							// 强弱电走线架配置类型
	double dDistanceBetwZXJAndJigui;				// (走线架机房配置)走线架距离机柜顶部距离；
	int nNumOf1UPanel;								// 1U假面板的数量
	int nNumOf2UPanel;								// 2U假面板的数量
	int nNumOfLPallet;								// L型托板的数量
	int nNumOfLightLayer;							// 轻载层板的数量
	int nNumOfHeavyLayer;							// 重载层板的数量
	int nNumOfStringingPanel;						// 穿线面板的数量
	int nHuiLiuPaiType;								// 汇流排的类型
	bool bIsWeiBanExist;							// 围板是否配置
	bool bIsInsideFloorExist;						// 模块内部是否配置地板
	bool bIsTaBuExist;								// 是否配置踏步
	int nControlCabinetType;						// 管控柜类型

	__tagRequirementTabData()
	{
		nModuleType = -1;
		bIsExtFloorExist = false;
		nAirstreamPattern = -1;
		dPassageWidth = 0.0;
		dHeightOfITRack = 0.0;
		dWidthOfITRack = 0.0;
		dDepthOfITRack = 0.0;
		nFrontDoorTypeOfITRack = 1;
		nBackDoorTypeOfITRack = -1;
		nFrontDoorLockTypeOfITRack = -1;
		nBackDoorLockTypeOfITRack = -1;
		nSideDoorTypeOfITRack = -1;
		nHeightOfPedestal = -1;
		nInsideFloorType = -1;
		nZouXianJiaType = -1;
		dDistanceBetwZXJAndJigui = 0.0;
		nNumOf1UPanel = -1;
		nNumOf2UPanel = -1;
		nNumOfLPallet = -1;
		nNumOfLightLayer = -1;
		nNumOfHeavyLayer = -1;
		nNumOfStringingPanel = -1;
		nHuiLiuPaiType = -1;
		bIsWeiBanExist = false;
		bIsInsideFloorExist = false;
		bIsTaBuExist = false;
		nControlCabinetType = -1;
	}
	__tagRequirementTabData(const __tagRequirementTabData &data)
	{
		nModuleType = data.nModuleType;
		bIsExtFloorExist = data.bIsExtFloorExist;
		nAirstreamPattern = data.nAirstreamPattern;
		dPassageWidth = data.dPassageWidth;
		dHeightOfITRack = data.dHeightOfITRack;
		dWidthOfITRack = data.dWidthOfITRack;
		dDepthOfITRack = data.dDepthOfITRack;
		nFrontDoorTypeOfITRack = data.nFrontDoorTypeOfITRack;
		nBackDoorTypeOfITRack = data.nBackDoorTypeOfITRack;
		nFrontDoorLockTypeOfITRack = data.nFrontDoorLockTypeOfITRack;
		nBackDoorLockTypeOfITRack = data.nBackDoorLockTypeOfITRack;
		nSideDoorTypeOfITRack = data.nSideDoorTypeOfITRack;
		nHeightOfPedestal = data.nHeightOfPedestal;
		nInsideFloorType = data.nInsideFloorType;
		nZouXianJiaType = data.nZouXianJiaType;
		dDistanceBetwZXJAndJigui = data.dDistanceBetwZXJAndJigui;
		nNumOf1UPanel = data.nNumOf1UPanel;
		nNumOf2UPanel = data.nNumOf2UPanel;
		nNumOfLPallet = data.nNumOfLPallet;
		nNumOfLightLayer = data.nNumOfLightLayer;
		nNumOfHeavyLayer = data.nNumOfHeavyLayer;
		nNumOfStringingPanel = data.nNumOfStringingPanel;
		nHuiLiuPaiType = data.nHuiLiuPaiType;
		bIsWeiBanExist = data.bIsWeiBanExist;
		bIsInsideFloorExist = data.bIsInsideFloorExist;
		bIsTaBuExist = data.bIsTaBuExist;
		nControlCabinetType = data.nControlCabinetType;
	}
	__tagRequirementTabData operator=(const __tagRequirementTabData &data)
	{
		if (&data == this)
			return *this;
		nModuleType = data.nModuleType;
		bIsExtFloorExist = data.bIsExtFloorExist;
		nAirstreamPattern = data.nAirstreamPattern;
		dPassageWidth = data.dPassageWidth;
		dHeightOfITRack = data.dHeightOfITRack;
		dWidthOfITRack = data.dWidthOfITRack;
		dDepthOfITRack = data.dDepthOfITRack;
		nFrontDoorTypeOfITRack = data.nFrontDoorTypeOfITRack;
		nBackDoorTypeOfITRack = data.nBackDoorTypeOfITRack;
		nFrontDoorLockTypeOfITRack = data.nFrontDoorLockTypeOfITRack;
		nBackDoorLockTypeOfITRack = data.nBackDoorLockTypeOfITRack;
		nSideDoorTypeOfITRack = data.nSideDoorTypeOfITRack;
		nHeightOfPedestal = data.nHeightOfPedestal;
		nInsideFloorType = data.nInsideFloorType;
		nZouXianJiaType = data.nZouXianJiaType;
		dDistanceBetwZXJAndJigui = data.dDistanceBetwZXJAndJigui;
		nNumOf1UPanel = data.nNumOf1UPanel;
		nNumOf2UPanel = data.nNumOf2UPanel;
		nNumOfLPallet = data.nNumOfLPallet;
		nNumOfLightLayer = data.nNumOfLightLayer;
		nNumOfHeavyLayer = data.nNumOfHeavyLayer;
		nNumOfStringingPanel = data.nNumOfStringingPanel;
		nHuiLiuPaiType = data.nHuiLiuPaiType;
		bIsWeiBanExist = data.bIsWeiBanExist;
		bIsInsideFloorExist = data.bIsInsideFloorExist;
		bIsTaBuExist = data.bIsTaBuExist;
		nControlCabinetType = data.nControlCabinetType;
		return *this;
	}
}RequirementTabData;

// 组件配置
typedef struct __tagModelConfiguration
{
	CString strMajorClass;							// 所属类别
	int nModelType;									// 组件类型，参照DesignModelType
	bool bIsCreate;									// 是否配置
	CString strTempPartNo;							// 临时图号
	CString strFormalPartNo;						// 正式图号
	CString strPurchaseNo;							// 采购代码
	double dHeight;									// 高
	double dWidth;									// 宽
	double dDepth;									// 深
	vector<IKSCsysData> arrPosition;				// 组件位置
	CString strRemark;								// 备注

	__tagModelConfiguration()
	{
		strMajorClass = _T("");
		nModelType = -1;
		bIsCreate = true;
		strTempPartNo = _T("");
		strFormalPartNo = _T("");
		strPurchaseNo = _T("");
		dHeight = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagModelConfiguration(const __tagModelConfiguration &data)
	{
		strMajorClass = data.strMajorClass;
		nModelType = data.nModelType;
		bIsCreate = data.bIsCreate;
		strTempPartNo = data.strTempPartNo;
		strFormalPartNo = data.strFormalPartNo;
		strPurchaseNo = data.strPurchaseNo;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		arrPosition = data.arrPosition;
		strRemark = data.strRemark;
	}
	__tagModelConfiguration operator=(const __tagModelConfiguration &data)
	{
		if (&data == this)
			return *this;
		strMajorClass = data.strMajorClass;
		nModelType = data.nModelType;
		bIsCreate = data.bIsCreate;
		strTempPartNo = data.strTempPartNo;
		strFormalPartNo = data.strFormalPartNo;
		strPurchaseNo = data.strPurchaseNo;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		arrPosition = data.arrPosition;
		strRemark = data.strRemark;
		return *this;
	}
}ModelConfiguration;

typedef vector<ModelConfiguration> ModelConfigurationArray;

// 整机配置表
typedef struct __tagTotalUnitConfiguration
{
	CString strAsmName;								// 组件名称
	int nCloseType;									// 封闭方式
	double dCabinetHeight;							// 机柜高度
	int nModulePosition;							// 模块位置
	double dBaseHeight;								// 底座高度
	int nModuleType;								// 模块类型
	int nSameLayoutNumber;							// 相同布局数量
	ModelConfigurationArray arrModelConfig;			// 组件模型配置

	__tagTotalUnitConfiguration()
	{
		strAsmName = _T("");
		nCloseType = -1;
		dCabinetHeight = 0.0;
		nModulePosition = -1;
		dBaseHeight = 0.0;
		nModuleType = -1;
		nSameLayoutNumber = 0;
	}
	__tagTotalUnitConfiguration(const __tagTotalUnitConfiguration &data)
	{
		strAsmName = data.strAsmName;
		nCloseType = data.nCloseType;
		dCabinetHeight = data.dCabinetHeight;
		nModulePosition = data.nModulePosition;
		dBaseHeight = data.dBaseHeight;
		nModuleType = data.nModuleType;
		nSameLayoutNumber = data.nSameLayoutNumber;
		arrModelConfig = data.arrModelConfig;
	}
	__tagTotalUnitConfiguration operator=(const __tagTotalUnitConfiguration &data)
	{
		if (&data == this)
			return *this;
		strAsmName = data.strAsmName;
		nCloseType = data.nCloseType;
		dCabinetHeight = data.dCabinetHeight;
		nModulePosition = data.nModulePosition;
		dBaseHeight = data.dBaseHeight;
		nModuleType = data.nModuleType;
		nSameLayoutNumber = data.nSameLayoutNumber;
		arrModelConfig = data.arrModelConfig;
		return *this;
	}
}TotalUnitConfiguration;

// 布局图数据库结构
typedef struct __tagLayoutDBData
{
	CString strNumber;								// 编号
	CString strDate;								// 创建日期
	CString strXMLPath;								// XML文件路径
	CXmlToObject *pLayoutXML;						// 布局XML文件指针

	__tagLayoutDBData()
	{
		strNumber = _T("");
		strDate = _T("");
		strXMLPath = _T("");
		pLayoutXML = NULL;
	}
	__tagLayoutDBData(const __tagLayoutDBData &data)
	{
		strNumber = data.strNumber;
		strDate = data.strDate;
		strXMLPath = data.strXMLPath;
		pLayoutXML = data.pLayoutXML;
	}
	__tagLayoutDBData operator=(const __tagLayoutDBData &data)
	{
		if (&data == this)
			return *this;
		strNumber = data.strNumber;
		strDate = data.strDate;
		strXMLPath = data.strXMLPath;
		pLayoutXML = data.pLayoutXML;
		return *this;
	}
}LayoutDBData;

// 整机配置数据库结构
typedef struct __tagConfigDBData
{
	CString strNumber;								// 编号
	CString strDate;								// 创建日期
	TotalUnitConfiguration totalConfig;				// 整机配置数据

	__tagConfigDBData()
	{
		strNumber = _T("");
		strDate = _T("");
	}
	__tagConfigDBData(const __tagConfigDBData &data)
	{
		strNumber = data.strNumber;
		strDate = data.strDate;
		totalConfig = data.totalConfig;
	}
	__tagConfigDBData operator=(const __tagConfigDBData &data)
	{
		if (&data == this)
			return *this;
		strNumber = data.strNumber;
		strDate = data.strDate;
		totalConfig = data.totalConfig;
		return *this;
	}
}ConfigDBData;

// 整机数据库结构
typedef struct __tagTotalLayoutConfigDBData
{
	LayoutDBData layout;							// 布局图数据
	ConfigDBData config;							// 整机配置数据

	__tagTotalLayoutConfigDBData()
	{
	}
	__tagTotalLayoutConfigDBData(const __tagTotalLayoutConfigDBData &data)
	{
		layout = data.layout;
		config = data.config;
	}
	__tagTotalLayoutConfigDBData operator=(const __tagTotalLayoutConfigDBData &data)
	{
		if (&data == this)
			return *this;
		layout = data.layout;
		config = data.config;
		return *this;
	}
}TotalLayoutConfigDBData;

typedef vector<TotalLayoutConfigDBData> TotalLayoutConfigDBDataArray;

// 需求采集数据库结构
typedef struct __tagRequirementDBData
{
	CString strNumber;										// 编号
	CString strDate;										// 创建日期
	RequirementTabData tabData;								// 需求采集表数据结构
	TotalLayoutConfigDBDataArray arrTotalData;				// 整机数据集

	__tagRequirementDBData()
	{
		strNumber = _T("");
		strDate = _T("");
	}
	__tagRequirementDBData(const __tagRequirementDBData &data)
	{
		strNumber = data.strNumber;
		strDate = data.strDate;
		tabData = data.tabData;
		arrTotalData = data.arrTotalData;
	}
	__tagRequirementDBData operator=(const __tagRequirementDBData &data)
	{
		if (&data == this)
			return *this;
		strNumber = data.strNumber;
		strDate = data.strDate;
		tabData = data.tabData;
		arrTotalData = data.arrTotalData;
		return *this;
	}
}RequirementDBData;

typedef vector<RequirementDBData> RequirementDBDataArray;

// 项目数据库结构
typedef struct __tagProjectDBData
{
	CString strUser;								// 用户
	CString strNumber;								// 编号
	CString strDate;								// 创建日期
	RequirementDBDataArray arrReqDBData;			// 需求采集数据集

	__tagProjectDBData()
	{
		strUser = _T("");
		strNumber = _T("");
		strDate = _T("");
	}
	__tagProjectDBData(const __tagProjectDBData &data)
	{
		strUser = data.strUser;
		strNumber = data.strNumber;
		strDate = data.strDate;
		arrReqDBData = data.arrReqDBData;
	}
	__tagProjectDBData operator=(const __tagProjectDBData &data)
	{
		if (&data == this)
			return *this;
		strUser = data.strUser;
		strNumber = data.strNumber;
		strDate = data.strDate;
		arrReqDBData = data.arrReqDBData;
		return *this;
	}
}ProjectDBData;

// 机柜的数据
typedef struct __tagJiGuiDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dHeight;									// 高
	double dWidth;									// 宽
	double dDepth;									// 深
	CString strFrontDoor;							// 前门
	CString strFrontDoorLock;						// 前门锁型
	CString strBackDoor;							// 后门
	CString strBackDoorLock;						// 后门锁型
	CString strJiaMianBan;							// 假面板
	CString strChuanXianMianBan;					// 穿线面板
	CString strLTuoBan;								// L型托板
	CString strRemark;								// 备注

	__tagJiGuiDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dHeight = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strFrontDoor = _T("");
		strFrontDoorLock = _T("");
		strBackDoor = _T("");
		strBackDoorLock = _T("");
		strJiaMianBan = _T("");
		strChuanXianMianBan = _T("");
		strLTuoBan = _T("");
		strRemark = _T("");
	}
	__tagJiGuiDBData(const __tagJiGuiDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strFrontDoor = data.strFrontDoor;
		strFrontDoorLock = data.strFrontDoorLock;
		strBackDoor = data.strBackDoor;
		strBackDoorLock = data.strBackDoorLock;
		strJiaMianBan = data.strJiaMianBan;
		strChuanXianMianBan = data.strChuanXianMianBan;
		strLTuoBan = data.strLTuoBan;
		strRemark = data.strRemark;
	}
	__tagJiGuiDBData operator=(const __tagJiGuiDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strFrontDoor = data.strFrontDoor;
		strFrontDoorLock = data.strFrontDoorLock;
		strBackDoor = data.strBackDoor;
		strBackDoorLock = data.strBackDoorLock;
		strJiaMianBan = data.strJiaMianBan;
		strChuanXianMianBan = data.strChuanXianMianBan;
		strLTuoBan = data.strLTuoBan;
		strRemark = data.strRemark;
		return *this;
	}
}JiGuiDBData;

// 面板的数据
typedef struct __tagPanelDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dHeight;									// 高度
	CString strUNum;								// 适配U数
	double dWidth;									// 宽度
	double dDepth;									// 深度
	CString strRemark;								// 备注

	__tagPanelDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dHeight = 0.0;
		strUNum = _T("");
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagPanelDBData(const __tagPanelDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		strUNum = data.strUNum;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
	}
	__tagPanelDBData operator=(const __tagPanelDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		strUNum = data.strUNum;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
		return *this;
	}
}PanelDBData;

// 机柜门的数据
typedef struct __tagJiGuiMenDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dFixedHeight;							// 适配高度
	double dHeight;									// 高度
	double dFixedWidth;								// 适配宽度
	double dWidth;									// 宽度
	double dDepth;									// 深度
	CString strIsPadHole;							// PAD安装孔
	CString strIsHinge;								// 铰链
	CString strRemark;								// 备注

	__tagJiGuiMenDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dFixedHeight = 0.0;
		dHeight = 0.0;
		dFixedWidth = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strIsPadHole = _T("");
		strIsHinge = _T("");
		strRemark = _T("");
	}
	__tagJiGuiMenDBData(const __tagJiGuiMenDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dFixedHeight = data.dFixedHeight;
		dHeight = data.dHeight;
		dFixedWidth = data.dFixedWidth;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strIsPadHole = data.strIsPadHole;
		strIsHinge = data.strIsHinge;
		strRemark = data.strRemark;
	}
	__tagJiGuiMenDBData operator=(const __tagJiGuiMenDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dFixedHeight = data.dFixedHeight;
		dHeight = data.dHeight;
		dFixedWidth = data.dFixedWidth;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strIsPadHole = data.strIsPadHole;
		strIsHinge = data.strIsHinge;
		strRemark = data.strRemark;
		return *this;
	}
}JiGuiMenDBData;

// 机柜侧门的数据
typedef struct __tagJiGuiCeMenDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dFixedHeight;							// 适配高度
	double dHeight;									// 高度
	double dFixedDepth;								// 适配深度
	double dDepth;									// 深度
	double dThickness;								// 厚度
	CString strRemark;								// 备注

	__tagJiGuiCeMenDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dFixedHeight = 0.0;
		dHeight = 0.0;
		dFixedDepth = 0.0;
		dDepth = 0.0;
		dThickness = 0.0;
		strRemark = _T("");
	}
	__tagJiGuiCeMenDBData(const __tagJiGuiCeMenDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dFixedHeight = data.dFixedHeight;
		dHeight = data.dHeight;
		dFixedDepth = data.dFixedDepth;
		dDepth = data.dDepth;
		dThickness = data.dThickness;
		strRemark = data.strRemark;
	}
	__tagJiGuiCeMenDBData operator=(const __tagJiGuiCeMenDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dFixedHeight = data.dFixedHeight;
		dHeight = data.dHeight;
		dFixedDepth = data.dFixedDepth;
		dDepth = data.dDepth;
		dThickness = data.dThickness;
		strRemark = data.strRemark;
		return *this;
	}
}JiGuiCeMenDBData;

// 机柜附件_托板的数据
typedef struct __tagJGFJPlateDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dHeight;									// 高度
	double dWidth;									// 宽度
	double dDepth;									// 深度
	CString strRemark;								// 备注

	__tagJGFJPlateDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dHeight = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagJGFJPlateDBData(const __tagJGFJPlateDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
	}
	__tagJGFJPlateDBData operator=(const __tagJGFJPlateDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
		return *this;
	}
}JGFJPlateDBData;

// 机柜附件_汇流排的数据
typedef struct __tagJGFJHLPDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dHeight;									// 高度
	double dWidth;									// 宽度
	double dDepth;									// 深度
	CString strRemark;								// 备注

	__tagJGFJHLPDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dHeight = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagJGFJHLPDBData(const __tagJGFJHLPDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
	}
	__tagJGFJHLPDBData operator=(const __tagJGFJHLPDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
		return *this;
	}
}JGFJHLPDBData;

// 机柜附件_其他的数据
typedef struct __tagJGFJOtherDBData
{
	CString strXilie;								// 系列
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dHeight;									// 高度
	double dWidth;									// 宽度
	double dDepth;									// 深度
	CString strRemark;								// 备注

	__tagJGFJOtherDBData()
	{
		strXilie = _T("");
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dHeight = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagJGFJOtherDBData(const __tagJGFJOtherDBData &data)
	{
		strXilie = data.strXilie;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
	}
	__tagJGFJOtherDBData operator=(const __tagJGFJOtherDBData &data)
	{
		if (&data == this)
			return *this;
		strXilie = data.strXilie;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
		return *this;
	}
}JGFJOtherDBData;

// 顶部围板的数据
typedef struct __tagTopWeiBanDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dHeight;									// 高度
	double dWidth;									// 宽度
	double dDepth;									// 深度
	CString strRemark;								// 备注

	__tagTopWeiBanDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dHeight = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagTopWeiBanDBData(const __tagTopWeiBanDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
	}
	__tagTopWeiBanDBData operator=(const __tagTopWeiBanDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
		return *this;
	}
}TopWeiBanDBData;

// 顶窗的数据
typedef struct __tagTopWindowDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dHeight;									// 高度
	double dWidth;									// 宽度
	double dDepth;									// 深度
	CString strRemark;								// 备注

	__tagTopWindowDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dHeight = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagTopWindowDBData(const __tagTopWindowDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
	}
	__tagTopWindowDBData operator=(const __tagTopWindowDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
		return *this;
	}
}TopWindowDBData;

// 地板的数据
typedef struct __tagFloorDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dFixedHeight;							// 适配高度
	double dLength;									// 长度
	double dWidth;									// 宽度
	double dThickness;								// 厚度
	CString strRemark;								// 备注

	__tagFloorDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dFixedHeight = 0.0;
		dLength = 0.0;
		dWidth = 0.0;
		dThickness = 0.0;
		strRemark = _T("");
	}
	__tagFloorDBData(const __tagFloorDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dFixedHeight = data.dFixedHeight;
		dLength = data.dLength;
		dWidth = data.dWidth;
		dThickness = data.dThickness;
		strRemark = data.strRemark;
	}
	__tagFloorDBData operator=(const __tagFloorDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dFixedHeight = data.dFixedHeight;
		dLength = data.dLength;
		dWidth = data.dWidth;
		dThickness = data.dThickness;
		strRemark = data.strRemark;
		return *this;
	}
}FloorDBData;

// 通道的数据
typedef struct __tagPassageDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dFixedHeight;							// 适配高度
	double dHeight;									// 高度
	double dWidth;									// 宽度
	double dDepth;									// 深度
	CString strRemark;								// 备注

	__tagPassageDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dFixedHeight = 0.0;
		dHeight = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagPassageDBData(const __tagPassageDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dFixedHeight = data.dFixedHeight;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
	}
	__tagPassageDBData operator=(const __tagPassageDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dFixedHeight = data.dFixedHeight;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
		return *this;
	}
}PassageDBData;

// 布线系统的数据
typedef struct __tagCablingSystemDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dHeight;									// 高度
	double dWidth;									// 宽度
	double dDepth;									// 深度
	CString strRemark;								// 备注

	__tagCablingSystemDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dHeight = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagCablingSystemDBData(const __tagCablingSystemDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
	}
	__tagCablingSystemDBData operator=(const __tagCablingSystemDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
		return *this;
	}
}CablingSystemDBData;

// 底座的数据
typedef struct __tagDiZuoDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dHeight;									// 高度
	double dWidth;									// 宽度
	double dDepth;									// 深度
	CString strRemark;								// 备注

	__tagDiZuoDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dHeight = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagDiZuoDBData(const __tagDiZuoDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
	}
	__tagDiZuoDBData operator=(const __tagDiZuoDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
		return *this;
	}
}DiZuoDBData;

// 底座附件的数据
typedef struct __tagDiZuoFuJianDBData
{
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dHeight;									// 高度
	double dWidth;									// 宽度
	double dDepth;									// 深度
	CString strRemark;								// 备注

	__tagDiZuoFuJianDBData()
	{
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dHeight = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagDiZuoFuJianDBData(const __tagDiZuoFuJianDBData &data)
	{
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
	}
	__tagDiZuoFuJianDBData operator=(const __tagDiZuoFuJianDBData &data)
	{
		if (&data == this)
			return *this;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
		return *this;
	}
}DiZuoFuJianDBData;

// 专用底座的数据
typedef struct __tagSpecialDiZuoDBData
{
	CString strXilie;								// 系列
	CString strCode;								// 代码
	CString strPartNo;								// 图号
	CString strName;								// 名称
	CString strEngName;								// 英文名
	CString strUnit;								// 单位
	CString strState;								// 状态
	CString strClass;								// 类别
	double dHeight;									// 高度
	double dWidth;									// 宽度
	double dDepth;									// 深度
	CString strRemark;								// 备注

	__tagSpecialDiZuoDBData()
	{
		strXilie = _T("");
		strCode = _T("");
		strPartNo = _T("");
		strName = _T("");
		strEngName = _T("");
		strUnit = _T("");
		strState = _T("");
		strClass = _T("");
		dHeight = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagSpecialDiZuoDBData(const __tagSpecialDiZuoDBData &data)
	{
		strXilie = data.strXilie;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
	}
	__tagSpecialDiZuoDBData operator=(const __tagSpecialDiZuoDBData &data)
	{
		if (&data == this)
			return *this;
		strXilie = data.strXilie;
		strCode = data.strCode;
		strPartNo = data.strPartNo;
		strName = data.strName;
		strEngName = data.strEngName;
		strUnit = data.strUnit;
		strState = data.strState;
		strClass = data.strClass;
		dHeight = data.dHeight;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		strRemark = data.strRemark;
		return *this;
	}
}SpecialDiZuoDBData;

//===================================================================================================
// 电缆模块

//===================================================================================================
// 工程图模块



//===================================================================================================

