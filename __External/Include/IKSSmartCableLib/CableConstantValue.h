//===================================================================================================
// Summary:
//		内部使用常量和结构体
// Date:
//		2016-03-17
// Author:
//		WangShiping
//===================================================================================================

#pragma once

#include "SVGeomDef.h"

#include <ProCabling.h>
#include <ProSelection.h>

//===================================================================================================
// 以下为常量定义
const CUnicodeString g_strCableConfigFileName = L"\\CableConfig.ini";		// 电缆选项配置文件名称
const CUnicodeString g_strConnLibPathServerAlias = L"&(ServerAlias)";		// 电连接器存储库路径中的服务器别名
const CUnicodeString g_strTrunkCableTrunkCabPrefix = L"ZX_";				// 总线电缆的主路电缆前缀名
const CUnicodeString g_strTrunkCableBranchCabPrefix = L"ZXB_";				// 总线电缆的支路电缆前缀名

//===================================================================================================
// 以下为自定义的消息

// 定制消息:显示隐藏窗口
#define WM_CAB_CUSTOM_SHOWWINDOW		WM_USER + 1001

//===================================================================================================
// 以下为枚举值定义

// 检查模式
typedef enum _IKSCHECKHOLECAPACITYMODE
{
	IKSCHKHOLECAPMODE_INVALID				= 0,		// 非法值
	IKSCHKHOLECAPMODE_SURPLUSAREA			= 1,		// 面积余量
	IKSCHKHOLECAPMODE_COVERAREA				= 2,		// 覆盖盘
	IKSCHKHOLECAPMODE_LAYOUT				= 3,		// 填充
} IKSCHECKHOLECAPACITYMODE;

// 检查电缆类型的模式
typedef enum _IKSCHECKCABLETYPEMODE
{
	IKSCHKCABTYPEMODE_INVALID				= 0,		// 非法值
	IKSCHKCABTYPEMODE_NETWORK				= 1,		// 通过电缆位置检查电缆类型
	IKSCHKCABTYPEMODE_SIMPATH				= 2,		// 通过电缆路径相似度检查电缆类型
} IKSCHECKCABLETYPEMODE;

// 电缆位置类型
typedef enum _IKSCABLELOCATIONTYPE
{
	IKSCABLOCT_INVALID						= 0,		// 非法值
	IKSCABLOCT_PROCABLELOCATION				= 1,		// ProE电缆位置
	IKSCABLOCT_LOCATIONDATA					= 2,		// 电缆位置数据
} IKSCABLELOCATIONTYPE;

// 电缆位置类型
typedef enum _IKSCABLETYPE
{
	IKSCABT_INVALID						= -1,		// 非法值
	IKSCABT_CABLE						= 0,		// 电缆
	IKSCABT_BUNDLE						= 1,		// 缆束
	IKSCABT_WIRE						= 2,		// 电线
	IKSCABT_CONDUCTOR					= 3,		// 导线
	IKSCABT_NETWORK						= 10,		// 网络
} IKSCABLETYPE;

// 模型节点类型
typedef enum __tagCABMODELNODETYPE
{
	CABMNTYPE_UNUSED				= -1,	// 未使用
	CABMNTYPE_PART					= 1,	// 零件
	CABMNTYPE_ASSEMBLY				= 2,	// 组件
	CABMNTYPE_GROUP					= 3,	// 组
	CABMNTYPE_PATTERN				= 4,	// 阵列
	CABMNTYPE_PART_HARNESS			= 5,	// 线束
	CABMNTYPE_PART_CONNECTOR		= 6,	// 电连接器
	CABMNTYPE_PART_SKELETON			= 7,	// 骨架模型
} CABMODELNODETYPE;

// 孔横截面形状类型
typedef enum __tagIKSCABHOLESECSHAPETYPE
{
	IKSCABHSSTYPE_INVALID			= 0,	// 非法值
	IKSCABHSSTYPE_CIRCLE			= 1,	// 圆
	IKSCABHSSTYPE_HALFCIRCLE		= 2,	// 半圆
	IKSCABHSSTYPE_RECTANGLE		= 3,	// 矩形
	IKSCABHSSTYPE_WAIST			= 4,	// 腰形
	IKSCABHSSTYPE_HALFWAIST		= 5,	// 半腰形
} IKSCABHOLESECSHAPETYPE;

// 电缆布线模式
typedef enum _IKSCABLEROUTINGMODE
{
	IKSCABROUTM_INVALID							= 0,		// 非法值
	IKSCABROUTM_DIRECTTOEND						= 1,		// 直通终点
// 	IKSCABROUTM_SHAREEXISTPATH					= 2,		// 共用已知路径
} CABLEROUTINGMODE;

// 电缆连接关系检查结果
typedef enum _IKSCABLECONNINFCHECKRESULT
{
	IKSCABCONNCHKR_OK							= 0x00000000,		// 检查通过
	IKSCABCONNCHKR_ERR_NOTEXIST					= 0x00000001,		// 电缆连接关系不存在
	IKSCABCONNCHKR_ERR_HARNESSNAME				= 0x00000002,		// 电缆代号(HARNESS)错误
	IKSCABCONNCHKR_ERR_CABLENAME				= 0x00000004,		// 分支代号(CABLE)错误
	IKSCABCONNCHKR_ERR_SPOOLNAME				= 0x00000008,		// 线轴名称错误
	IKSCABCONNCHKR_ERR_DUMPEDCABLE				= 0x00000010,		// 冗余电缆(电缆已被删除)

	IKSCABCONNCHKR_ERR_CONN_NOTEXIST			= 0x00000100,		// 电连接器不存在
	IKSCABCONNCHKR_ERR_CONN_MDLNAME				= 0x00000200,		// 电连接器类型(模型名称)错误
	IKSCABCONNCHKR_ERR_CONN_ASM					= 0x00000400,		// 电连接器装配错误
} IKSCABLECONNINFCHECKRESULT;

// 解绑电缆的错误类型
typedef enum _IKSUNWRAPCABLEERRORTYPE
{
	IKSUNWRAPCABERRT_OK							= 0,				// 解绑成功
	IKSUNWRAPCABERRT_SELECTCABLE				= 1,				// 拾取的电缆不正确
	IKSUNWRAPCABERRT_SELECTCABLELOC				= 2,				// 拾取的电缆位置不正确
	IKSUNWRAPCABERRT_SELECTCABLELOC_DIFFHARN	= 3,				// 拾取的电缆与电缆位置属于不同的线束
	IKSUNWRAPCABERRT_NOTFINDCABLE				= 4,				// 未找到电缆
// 	IKSUNWRAPCABERRT_CABLEHAVEMULTISEGMENT		= 5,				// 电缆含有多个段
	IKSUNWRAPCABERRT_SAMECABLELOC				= 6,				// 两个电缆位置相同
	IKSUNWRAPCABERRT_NOTFINDCABLELOC			= 7,				// 未找到电缆位置
	IKSUNWRAPCABERRT_CABLELOCISNOTFROMNETWORK	= 8,				// 电缆位置不属于电缆网络

	IKSUNWRAPCABERRT_UNKNOWN					= 100,				// 未知错误
} IKSUNWRAPCABLEERRORTYPE;

//===================================================================================================
// 以下为结构体定义

typedef struct _IKSCABBASEUINT3 {
	IKS_UINT x;
	IKS_UINT y;
	IKS_UINT z;
} IKSCABBASEUINT3;

// 直线
typedef struct __tagIKSCABDBaseLineData
{
	SVBASEDOUBLE3 end1;		// 起点
	SVBASEDOUBLE3 end2;		// 终点
} IKSCABDBaseLineData;

// 直线
typedef struct __tagIKSCABDLineData
{
	SVBASEDOUBLE3 end1;		// 起点
	SVBASEDOUBLE3 end2;		// 终点
	__tagIKSCABDLineData(const SVBASEDOUBLE3 &e1, const SVBASEDOUBLE3 &e2)
	{
		end1 = e1;
		end2 = e2;
	}
} IKSCABDLineData;

// 圆弧
typedef struct __tagIKSCABDBaseArcData
{
	SVBASEDOUBLE3 vOrigin;	// 原点
	SVBASEDOUBLE3 vVector1;	// First vector that defines the plane of the arc
	SVBASEDOUBLE3 vVector2;	// Second vector that defines the plane of the arc
	double dStartAngle;		// Angular parameter of the starting point
	double dEndAngle;		// Angular parameter of the ending point
	double dRadius;			// 半径
} IKSCABDBaseArcData;

// 曲线的形状数据
typedef union __tagIKSCABDCurveData
{
	IKSCABDBaseLineData		line;			// 直线
	IKSCABDBaseArcData		arc;			// 圆弧
} IKSCABDCurveData;

// 曲线数据信息
typedef struct __tagIKSCABDCurve
{
	int						nType;			// 曲线类型
	IKSCABDCurveData		curvedata;		// 曲线数据
	__tagIKSCABDCurve()
	{
		nType = BPCURVETYPE_UNKOWN;
		memset(&curvedata, 0, sizeof(IKSCABDCurveData));
	}
	__tagIKSCABDCurve(const __tagIKSCABDCurve &data)
	{
		nType = data.nType;
		curvedata = data.curvedata;
	}
	__tagIKSCABDCurve &operator=(const __tagIKSCABDCurve& data){
		if (&data != this)
		{
			nType = data.nType;
			curvedata = data.curvedata;
		}
		return *this;
	}
} IKSCABDCurve;

// 线轴信息
typedef struct __tagIKSSpool
{
	ProSpool stuProeSpool;					// 线轴的ProE数据
// 	int						nType;			// 线轴类型,参看枚举型

	double dDiameter;						// 直径（THICKNESS）
	double dMinBendRadius;					// 最小转弯半径（MIN_BEND_RADIUS）
	double dDensity;						// 密度（DENSITY）
	CSVWString	strColor;					// 颜色名(COLOR)
	CSVWString	strUnits;					// 长度单位(UNITS)
	CSVWString	strMassUnits;				// 质量单位(MASS_UNITS)
	__tagIKSSpool()
	{
		stuProeSpool.owner = NULL;
		memset(stuProeSpool.name, 0, sizeof(wchar_t)*PRO_NAME_SIZE);
		dDiameter = 0.0;
		dMinBendRadius = 0.0;
		dDensity = 0.0;
		strColor = L"";
		strUnits = L"";
		strMassUnits = L"";
	}
	__tagIKSSpool(const __tagIKSSpool &data)
	{
		stuProeSpool = data.stuProeSpool;
		dDiameter = data.dDiameter;
		dMinBendRadius = data.dMinBendRadius;
		dDensity = data.dDensity;
		strColor = data.strColor;
		strUnits = data.strUnits;
		strMassUnits = data.strMassUnits;
	}
	__tagIKSSpool &operator=(const __tagIKSSpool& data){
		if (&data != this)
		{
			stuProeSpool = data.stuProeSpool;
			dDiameter = data.dDiameter;
			dMinBendRadius = data.dMinBendRadius;
			dDensity = data.dDensity;
			strColor = data.strColor;
			strUnits = data.strUnits;
			strMassUnits = data.strMassUnits;
		}
		return *this;
	}
	void Clear()
	{
		stuProeSpool.owner = NULL;
		memset(stuProeSpool.name, 0, sizeof(wchar_t)*PRO_NAME_SIZE);
		dDiameter = 0.0;
		dMinBendRadius = 0.0;
		dDensity = 0.0;
		strColor = L"";
		strUnits = L"";
		strMassUnits = L"";
	}
	void SetLocSpoolData(const __tagIKSSpool &data)
	{
		dDiameter = data.dDiameter;
		dMinBendRadius = data.dMinBendRadius;
		dDensity = data.dDensity;
		strColor = data.strColor;
		strUnits = data.strUnits;
		strMassUnits = data.strMassUnits;
	}
	void UpdateLocCorrectSpoolData(const __tagIKSSpool &data)
	{
		if (data.dDiameter > 0.0)
			dDiameter = data.dDiameter;
		if (data.dMinBendRadius > 0.0)
			dMinBendRadius = data.dMinBendRadius;
		if (data.dDensity > 0.0)
			dDensity = data.dDensity;
		if (data.strColor.GetLength() > 0)
			strColor = data.strColor;
		if (data.strUnits.GetLength() > 0)
			strUnits = data.strUnits;
		if (data.strMassUnits.GetLength() > 0)
			strMassUnits = data.strMassUnits;
	}
} IKSSpool;

// 电线电缆的位置信息
typedef struct __tagIKSCableLocation
{
	SVBASEDOUBLE3 vPos;					// 位置坐标(实际点)
	SVBASEDOUBLE3 vTan;					// 切线方向(实际点)
	int nType;							// 位置类型,参看枚举型IKSCABLELOCATIONTYPE

	ProCablelocation stuProCabLoc;		// ProE电缆位置
	SVBASEDOUBLE3 vProCabLocPos;		// 位置坐标(参照点)
	SVBASEDOUBLE3 vProCabLocTan;		// 切线方向(参照点)
	UINT uProCabLocIndex;				// 所属Cable的Loc索引
	UINT uProNetworkLocIndex;			// 电缆网络的电缆位置索引
	UINT uProHarnessLocIndex;			// 线束的电缆位置索引

	__tagIKSCableLocation()
	{
		memset(&vPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTan, 0, sizeof(SVBASEDOUBLE3));
		nType = IKSCABLOCT_INVALID;
		stuProCabLoc.owner = NULL;
		stuProCabLoc.id = -1;
		memset(&vProCabLocPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vProCabLocTan, 0, sizeof(SVBASEDOUBLE3));
		uProCabLocIndex = UINT(-1);
		uProNetworkLocIndex = UINT(-1);
		uProHarnessLocIndex = UINT(-1);
	}
	__tagIKSCableLocation(const __tagIKSCableLocation &info)
	{
		vPos = info.vPos;
		vTan = info.vTan;
		nType = info.nType;
		stuProCabLoc = info.stuProCabLoc;
		vProCabLocPos = info.vProCabLocPos;
		vProCabLocTan = info.vProCabLocTan;
		uProCabLocIndex = info.uProCabLocIndex;
		uProNetworkLocIndex = info.uProNetworkLocIndex;
		uProHarnessLocIndex = info.uProHarnessLocIndex;
	}
	__tagIKSCableLocation& operator=(const __tagIKSCableLocation &info)
	{
		if (&info == this)
			return *this;
		vPos = info.vPos;
		vTan = info.vTan;
		nType = info.nType;
		stuProCabLoc = info.stuProCabLoc;
		vProCabLocPos = info.vProCabLocPos;
		vProCabLocTan = info.vProCabLocTan;
		uProCabLocIndex = info.uProCabLocIndex;
		uProNetworkLocIndex = info.uProNetworkLocIndex;
		uProHarnessLocIndex = info.uProHarnessLocIndex;
		return *this;
	}
	void Clear()
	{
		memset(&vPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTan, 0, sizeof(SVBASEDOUBLE3));
		nType = IKSCABLOCT_INVALID;
		stuProCabLoc.owner = NULL;
		stuProCabLoc.id = -1;
		memset(&vProCabLocPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vProCabLocTan, 0, sizeof(SVBASEDOUBLE3));
		uProCabLocIndex = UINT(-1);
		uProNetworkLocIndex = UINT(-1);
		uProHarnessLocIndex = UINT(-1);
	}
} IKSCableLocation;

// 电线电缆的段信息
typedef struct __tagIKSCableSegment
{
	std::vector<IKSCableLocation> vecLoc;	// 点位置序列
	ProCablesegment pProePt;				// ProE的数据指针
	BOOL bIsInBundle;						// 是否位于缆束内
	CSVWString strBundleName;				// 关联的缆束名称(bIsInBundle为TRUE时有效)

	__tagIKSCableSegment()
	{
		pProePt = NULL;
		bIsInBundle = FALSE;
		strBundleName = L"";
	}
	__tagIKSCableSegment(const __tagIKSCableSegment &info)
	{
		vecLoc = info.vecLoc;
		pProePt = info.pProePt;
		bIsInBundle = info.bIsInBundle;
		strBundleName = info.strBundleName;
	}
	__tagIKSCableSegment& operator=(const __tagIKSCableSegment &info)
	{
		if (&info == this)
			return *this;
		vecLoc = info.vecLoc;
		pProePt = info.pProePt;
		bIsInBundle = info.bIsInBundle;
		strBundleName = info.strBundleName;
		return *this;
	}
} IKSCableSegment;

// 电线电缆的信息
typedef struct __tagIKSCable
{
	ProCable	stuProeCable;			// ProE的数据
	ProAssembly pProeAssm;				// 电缆的父装配体
	ProAsmcomppath stuHarnessAsmPath;	// 电缆所在线束的装配路径

	CSVWString	strName;				// 电线电缆名称
	int			nType;					// 电线电缆类型,参看枚举型IKSCABLETYPE

	ProModelitem stuProeCabEnd1;	// 电缆端点1(电连接器的入口端坐标系,优先使用逻辑参照指定的入口端)
	ProModelitem stuProeCabEnd2;	// 电缆端点2(电连接器的入口端坐标系,优先使用逻辑参照指定的入口端)
	ProAsmcomppath stuProeCabEnd1Path;	// 电缆端点1所在电连接器的装配路径
	ProAsmcomppath stuProeCabEnd2Path;	// 电缆端点2所在电连接器的装配路径
	CSVWString strCabConnRefDes1;		// 电缆起始电连接器的逻辑名称(指定名称)(第一个电缆位置对应的电连接器)
	CSVWString strCabConnRefDes2;		// 电缆终止电连接器的逻辑名称(指定名称)(最后一个电缆位置对应的电连接器)
	CSVWString strCabConnEntryPortName1;	// 电缆起始电连接器的入口端
	CSVWString strCabConnEntryPortName2;	// 电缆终止电连接器的入口端
	CSVWString strCabConnDirection1;		// 电缆起始电连接器的方向（FROM或TO）
	CSVWString strCabConnDirection2;		// 电缆终止电连接器的方向（FROM或TO）
	UINT uCurAsmConnIndex1;				// 电缆起始电连接器索引
	UINT uCurAsmConnIndex2;				// 电缆终止电连接器索引

	IKSSpool stuSpool;					// 电缆的线轴
	vector<CSVWString> vecConductorName;		// 子导线名称（type值为IKSCABT_CABLE时有效）
	vector<CSVWString> vecConductorSplName;		// 子导线线轴名称（type值为IKSCABT_CABLE时有效）
// 	int nProeFeatID;					// ProE的FeatureID

	std::vector<IKSCableSegment>	vecSegment;	// 电缆对应的段
	std::vector<IKSCableLocation>	vecCabLoc;	// 电缆对应的ProE电缆位置
	BOOL bIsComplete;

	__tagIKSCable()
	{
		stuProeCable.owner = NULL;
		stuProeCable.id = -1;
		pProeAssm = NULL;
		stuHarnessAsmPath.owner = NULL;
		stuHarnessAsmPath.comp_id_table[0] = -1;
		stuHarnessAsmPath.table_num = 0;
		strName = L"";
		nType = IKSCABT_WIRE;
		stuProeCabEnd1.owner = NULL;
		stuProeCabEnd1.id = -1;
		stuProeCabEnd2.owner = NULL;
		stuProeCabEnd2.id = -1;
		stuProeCabEnd1Path.owner = NULL;
		stuProeCabEnd1Path.comp_id_table[0] = -1;
		stuProeCabEnd1Path.table_num = 0;
		stuProeCabEnd2Path.owner = NULL;
		stuProeCabEnd2Path.comp_id_table[0] = -1;
		stuProeCabEnd2Path.table_num = 0;
		strCabConnRefDes1 = L"";
		strCabConnRefDes2 = L"";
		strCabConnEntryPortName1 = L"";
		strCabConnEntryPortName2 = L"";
		strCabConnDirection1 = L"";
		strCabConnDirection2 = L"";
		uCurAsmConnIndex1 = UINT(-1);
		uCurAsmConnIndex2 = UINT(-1);
		bIsComplete = TRUE;
	}
	__tagIKSCable(const __tagIKSCable &info)
	{
		stuProeCable = info.stuProeCable;
		pProeAssm = info.pProeAssm;
		stuHarnessAsmPath = info.stuHarnessAsmPath;
		strName = info.strName;
		nType = info.nType;
		stuProeCabEnd1 = info.stuProeCabEnd1;
		stuProeCabEnd2 = info.stuProeCabEnd2;
		stuProeCabEnd1Path = info.stuProeCabEnd1Path;
		stuProeCabEnd2Path = info.stuProeCabEnd2Path;
		strCabConnRefDes1 = info.strCabConnRefDes1;
		strCabConnRefDes2 = info.strCabConnRefDes2;
		strCabConnEntryPortName1 = info.strCabConnEntryPortName1;
		strCabConnEntryPortName2 = info.strCabConnEntryPortName2;
		strCabConnDirection1 = info.strCabConnDirection1;
		strCabConnDirection2 = info.strCabConnDirection2;
		uCurAsmConnIndex1 = info.uCurAsmConnIndex1;
		uCurAsmConnIndex2 = info.uCurAsmConnIndex2;
		stuSpool = info.stuSpool;
		vecConductorName = info.vecConductorName;
		vecConductorSplName = info.vecConductorSplName;
		vecSegment = info.vecSegment;
		vecCabLoc = info.vecCabLoc;
		bIsComplete = info.bIsComplete;
	}
	__tagIKSCable& operator=(const __tagIKSCable &info)
	{
		if (&info == this)
			return *this;
		stuProeCable = info.stuProeCable;
		pProeAssm = info.pProeAssm;
		stuHarnessAsmPath = info.stuHarnessAsmPath;
		strName = info.strName;
		nType = info.nType;
		stuProeCabEnd1 = info.stuProeCabEnd1;
		stuProeCabEnd2 = info.stuProeCabEnd2;
		stuProeCabEnd1Path = info.stuProeCabEnd1Path;
		stuProeCabEnd2Path = info.stuProeCabEnd2Path;
		strCabConnRefDes1 = info.strCabConnRefDes1;
		strCabConnRefDes2 = info.strCabConnRefDes2;
		strCabConnEntryPortName1 = info.strCabConnEntryPortName1;
		strCabConnEntryPortName2 = info.strCabConnEntryPortName2;
		strCabConnDirection1 = info.strCabConnDirection1;
		strCabConnDirection2 = info.strCabConnDirection2;
		uCurAsmConnIndex1 = info.uCurAsmConnIndex1;
		uCurAsmConnIndex2 = info.uCurAsmConnIndex2;
		stuSpool = info.stuSpool;
		vecConductorName = info.vecConductorName;
		vecConductorSplName = info.vecConductorSplName;
		vecSegment = info.vecSegment;
		vecCabLoc = info.vecCabLoc;
		bIsComplete = info.bIsComplete;
		return *this;
	}
	void Clear()
	{
		stuProeCable.owner = NULL;
		stuProeCable.id = -1;
		pProeAssm = NULL;
		stuHarnessAsmPath.owner = NULL;
		stuHarnessAsmPath.comp_id_table[0] = -1;
		stuHarnessAsmPath.table_num = 0;
		strName = L"";
		nType = IKSCABT_WIRE;
		stuProeCabEnd1.owner = NULL;
		stuProeCabEnd1.id = -1;
		stuProeCabEnd2.owner = NULL;
		stuProeCabEnd2.id = -1;
		stuProeCabEnd1Path.owner = NULL;
		stuProeCabEnd1Path.comp_id_table[0] = -1;
		stuProeCabEnd1Path.table_num = 0;
		stuProeCabEnd2Path.owner = NULL;
		stuProeCabEnd2Path.comp_id_table[0] = -1;
		stuProeCabEnd2Path.table_num = 0;
		strCabConnRefDes1 = L"";
		strCabConnRefDes2 = L"";
		strCabConnEntryPortName1 = L"";
		strCabConnEntryPortName2 = L"";
		strCabConnDirection1 = L"";
		strCabConnDirection2 = L"";
		uCurAsmConnIndex1 = UINT(-1);
		uCurAsmConnIndex2 = UINT(-1);
		stuSpool.Clear();
		vecConductorName.clear();
		vecConductorSplName.clear();
		vecSegment.clear();
		vecCabLoc.clear();
		bIsComplete = TRUE;
	}
} IKSCable;

// 线束的信息
typedef struct __tagIKSHarness
{
	ProHarness	pProePt;				// ProE的数据指针
	ProAssembly pParentProeAssm;		// 线束的父装配体
	ProAsmcomppath stuProeAsmPath;		// ProE的装配路径
	CSVWString	strName;				// 线束名称
	SVBASEMATRIX matWld;				// 线束变换到顶层坐标系位置的转换矩阵

	IKSCable network;					// 网络network对应的ProE数据
	std::vector<IKSCable>	vecCables;	// 线束对应的线缆
	std::vector<IKSCableLocation>	vecHarnessLoc;	// 线束对应的ProE电缆位置

	__tagIKSHarness()
	{
		pProePt = NULL;
		pParentProeAssm = NULL;
		stuProeAsmPath.owner = NULL;
		stuProeAsmPath.table_num = 0;
		strName = L"";
		memset(&matWld, 0, sizeof(SVBASEMATRIX));
		matWld.m[0][0] = matWld.m[1][1] = matWld.m[2][2] = matWld.m[3][3] = 1.0;
	}
	__tagIKSHarness(const __tagIKSHarness &info)
	{
		pProePt = info.pProePt;
		pParentProeAssm = info.pParentProeAssm;
		memcpy_s(&stuProeAsmPath, sizeof(ProAsmcomppath), &info.stuProeAsmPath, sizeof(ProAsmcomppath));
		strName = info.strName;
		network = info.network;
		vecCables = info.vecCables;
		vecHarnessLoc = info.vecHarnessLoc;
		matWld = info.matWld;
	}
	__tagIKSHarness& operator=(const __tagIKSHarness &info)
	{
		if (&info == this)
			return *this;
		pProePt = info.pProePt;
		pParentProeAssm = info.pParentProeAssm;
		memcpy_s(&stuProeAsmPath, sizeof(ProAsmcomppath), &info.stuProeAsmPath, sizeof(ProAsmcomppath));
		strName = info.strName;
		network = info.network;
		vecCables = info.vecCables;
		vecHarnessLoc = info.vecHarnessLoc;
		matWld = info.matWld;
		return *this;
	}
	void Clear()
	{
		pProePt = NULL;
		pParentProeAssm = NULL;
		stuProeAsmPath.owner = NULL;
		stuProeAsmPath.table_num = 0;
		strName = L"";
		memset(&matWld, 0, sizeof(SVBASEMATRIX));
		matWld.m[0][0] = matWld.m[1][1] = matWld.m[2][2] = matWld.m[3][3] = 1.0;
		network.Clear();
		vecCables.clear();
		vecHarnessLoc.clear();
	}
} IKSHarness;

// 电缆的分支路径
typedef struct __tagIKSCableBranchPath
{
	ProCablelocation stuProCabLoc1;		// ProE电缆位置1
	ProCablelocation stuProCabLoc2;		// ProE电缆位置2
	std::vector<ProCable> vecCable;		// 通过该分支路径的电缆

	const IKSCableLocation *pIKSCabLoc1;		// 电缆位置1(临时数据)
	const IKSCableLocation *pIKSCabLoc2;		// 电缆位置2(临时数据)
	std::vector<const IKSCable*> vecIKSCablePt;	// 通过该分支路径的电缆(临时数据)

	double dDiameter;					// 电缆分支路径的直径（通过该分支路径的所有电缆的综合直径）

	__tagIKSCableBranchPath()
	{
		stuProCabLoc1.owner = NULL;
		stuProCabLoc1.id = -1;
		stuProCabLoc2.owner = NULL;
		stuProCabLoc2.id = -1;
		pIKSCabLoc1 = NULL;
		pIKSCabLoc2 = NULL;
		dDiameter = 0.0;
	}
	__tagIKSCableBranchPath(const __tagIKSCableBranchPath &info)
	{
		stuProCabLoc1 = info.stuProCabLoc1;
		stuProCabLoc2 = info.stuProCabLoc2;
		vecCable = info.vecCable;
		pIKSCabLoc1 = info.pIKSCabLoc1;
		pIKSCabLoc2 = info.pIKSCabLoc2;
		vecIKSCablePt = info.vecIKSCablePt;
		dDiameter = info.dDiameter;
	}
	__tagIKSCableBranchPath& operator=(const __tagIKSCableBranchPath &info)
	{
		if (&info == this)
			return *this;
		stuProCabLoc1 = info.stuProCabLoc1;
		stuProCabLoc2 = info.stuProCabLoc2;
		vecCable = info.vecCable;
		pIKSCabLoc1 = info.pIKSCabLoc1;
		pIKSCabLoc2 = info.pIKSCabLoc2;
		vecIKSCablePt = info.vecIKSCablePt;
		dDiameter = info.dDiameter;
		return *this;
	}
	void Clear()
	{
		stuProCabLoc1.owner = NULL;
		stuProCabLoc1.id = -1;
		stuProCabLoc2.owner = NULL;
		stuProCabLoc2.id = -1;
		vecCable.clear();
		pIKSCabLoc1 = NULL;
		pIKSCabLoc2 = NULL;
		vecIKSCablePt.clear();
		dDiameter = 0.0;
	}
} IKSCableBranchPath;

// 电缆分支路径的电缆信息
typedef struct __tagIKSCableBranchPathCabInf
{
	const IKSCable* pIKSCablePt;				// 电缆数据(临时数据)
	std::vector<UINT> vecBranchPathIndex;		// 电缆的分支路径的索引

	__tagIKSCableBranchPathCabInf()
	{
		pIKSCablePt = NULL;
	}
	__tagIKSCableBranchPathCabInf(const __tagIKSCableBranchPathCabInf &info)
	{
		pIKSCablePt = info.pIKSCablePt;
		vecBranchPathIndex = info.vecBranchPathIndex;
	}
	__tagIKSCableBranchPathCabInf& operator=(const __tagIKSCableBranchPathCabInf &info)
	{
		if (&info == this)
			return *this;
		pIKSCablePt = info.pIKSCablePt;
		vecBranchPathIndex = info.vecBranchPathIndex;
		return *this;
	}
	void Clear()
	{
		pIKSCablePt = NULL;
		vecBranchPathIndex.clear();
	}
} IKSCableBranchPathCabInf;

// 电缆分支路径的电缆端点
typedef struct __tagIKSCableBranchPathCabEnd
{
	ProCablelocation stuProCabLoc;		// 端点对应的ProE电缆位置
	ProCable stuCable;					// 端点对应的ProE电缆
	ProAsmcomppath stuHarnessAsmPath;	// 电缆所在线束的装配路径
	CSVWString strCabRefDes;			// 端点对应电连接器的逻辑描述(REF_DES)
	const IKSCable* pIKSCablePt;

	__tagIKSCableBranchPathCabEnd()
	{
		stuProCabLoc.owner = NULL;
		stuProCabLoc.id = -1;
		stuCable.owner = NULL;
		stuCable.id = -1;
		stuHarnessAsmPath.owner = NULL;
		stuHarnessAsmPath.comp_id_table[0] = -1;
		stuHarnessAsmPath.table_num = 0;
		strCabRefDes = L"";
		pIKSCablePt = NULL;
	}
	__tagIKSCableBranchPathCabEnd(const __tagIKSCableBranchPathCabEnd &info)
	{
		stuProCabLoc = info.stuProCabLoc;
		stuCable = info.stuCable;
		stuHarnessAsmPath = info.stuHarnessAsmPath;
		strCabRefDes = info.strCabRefDes;
		pIKSCablePt = info.pIKSCablePt;
	}
	__tagIKSCableBranchPathCabEnd& operator=(const __tagIKSCableBranchPathCabEnd &info)
	{
		if (&info == this)
			return *this;
		stuProCabLoc = info.stuProCabLoc;
		stuCable = info.stuCable;
		stuHarnessAsmPath = info.stuHarnessAsmPath;
		strCabRefDes = info.strCabRefDes;
		pIKSCablePt = info.pIKSCablePt;
		return *this;
	}
	void Clear()
	{
		stuProCabLoc.owner = NULL;
		stuProCabLoc.id = -1;
		stuCable.owner = NULL;
		stuCable.id = -1;
		stuHarnessAsmPath.owner = NULL;
		stuHarnessAsmPath.comp_id_table[0] = -1;
		stuHarnessAsmPath.table_num = 0;
		strCabRefDes = L"";
		pIKSCablePt = NULL;
	}
} IKSCableBranchPathCabEnd;

// 电连接器的入口端参数信息
typedef struct __tagIKSConnectorEntryPortsParamInfo
{
	CSVWString strCSysName;			// 坐标系名称
	CSVWString strType;				// 类型,例如ROUND
	double dIntLength;				// 内部长度

	__tagIKSConnectorEntryPortsParamInfo()
	{
		strCSysName = L"";
		strType = L"";
		dIntLength = 0.0;
	}
	__tagIKSConnectorEntryPortsParamInfo(const __tagIKSConnectorEntryPortsParamInfo &info)
	{
		strCSysName = info.strCSysName;
		strType = info.strType;
		dIntLength = info.dIntLength;
	}
	__tagIKSConnectorEntryPortsParamInfo& operator=(const __tagIKSConnectorEntryPortsParamInfo &info)
	{
		if (&info == this)
			return *this;
		strCSysName = info.strCSysName;
		strType = info.strType;
		dIntLength = info.dIntLength;
		return *this;
	}
	void Clear()
	{
		strCSysName = L"";
		strType = L"";
		dIntLength = 0.0;
	}
} IKSConnectorEntryPortsParamInfo;

// 电连接器的参数信息
typedef struct __tagIKSConnectorParamInfo
{
	CSVWString strRefDes;			// 指定名称-逻辑描述(REF_DES)
	CSVWString strModelName;		// 模型名称
	BOOL bIsMdlAsm;					// 模型是否为装配体(TRUE表示装配体,FALSE表示零件)
	CSVWString strLayer;			// 层
	CSVWString strType;				// 类型,CONNECTOR,SPLICE等
	std::vector<IKSConnectorEntryPortsParamInfo> vecEntryPortsInfo;	// 入口端

	__tagIKSConnectorParamInfo()
	{
		strRefDes = L"";
		strModelName = L"";
		bIsMdlAsm = FALSE;
		strLayer = L"0";
		strType = L"CONNECTOR";
	}
	__tagIKSConnectorParamInfo(const __tagIKSConnectorParamInfo &info)
	{
		strRefDes = info.strRefDes;
		strModelName = info.strModelName;
		bIsMdlAsm = info.bIsMdlAsm;
		strLayer = info.strLayer;
		strType = info.strType;
		vecEntryPortsInfo = info.vecEntryPortsInfo;
	}
	__tagIKSConnectorParamInfo& operator=(const __tagIKSConnectorParamInfo &info)
	{
		if (&info == this)
			return *this;
		strRefDes = info.strRefDes;
		strModelName = info.strModelName;
		bIsMdlAsm = info.bIsMdlAsm;
		strLayer = info.strLayer;
		strType = info.strType;
		vecEntryPortsInfo = info.vecEntryPortsInfo;
		return *this;
	}
	void Clear()
	{
		strRefDes = L"";
		strModelName = L"";
		bIsMdlAsm = FALSE;
		strLayer = L"0";
		strType = L"CONNECTOR";
		vecEntryPortsInfo.clear();
	}
} IKSConnectorParamInfo;

// 电连接器的信息
typedef struct __tagIKSConnector
{
	ProConnector stuProConnector;		// ProE的数据指针
	ProMdl pMdl;						// 电连接器模型指针
	ProAsmcomppath stuParentAsmAsmPath;	// 父装配体的装配路径
	ProMdl pParentAsm;					// 父装配体指针
	CSVWString	strName;				// 电连接器名称
	SVBASEMATRIX matWld;				// 电连接器变换到顶层坐标系位置的转换矩阵

	CSVWString strRefDes;				// 电连接器的逻辑描述(REF_DES)
	std::vector<ProModelitem> vecEntryPortsCsys;	// 入口端坐标系

	__tagIKSConnector()
	{
		stuProConnector.owner = NULL;
		stuProConnector.comp_id_table[0] = -1;
		stuProConnector.table_num = 0;
		pMdl = NULL;
		stuParentAsmAsmPath.owner = NULL;
		stuParentAsmAsmPath.comp_id_table[0] = -1;
		stuParentAsmAsmPath.table_num = 0;
		pParentAsm = NULL;
		strName = L"";
		memset(&matWld, 0, sizeof(SVBASEMATRIX));
		matWld.m[0][0] = matWld.m[1][1] = matWld.m[2][2] = matWld.m[3][3] = 1.0;
		strRefDes = L"";
	}
	__tagIKSConnector(const __tagIKSConnector &info)
	{
		memcpy_s(&stuProConnector, sizeof(ProConnector), &info.stuProConnector, sizeof(ProConnector));
		pMdl = info.pMdl;
		memcpy_s(&stuParentAsmAsmPath, sizeof(ProAsmcomppath), &info.stuParentAsmAsmPath, sizeof(ProAsmcomppath));
		pParentAsm = info.pParentAsm;
		strName = info.strName;
		matWld = info.matWld;
		strRefDes = info.strRefDes;
		vecEntryPortsCsys = info.vecEntryPortsCsys;
	}
	__tagIKSConnector& operator=(const __tagIKSConnector &info)
	{
		if (&info == this)
			return *this;
		memcpy_s(&stuProConnector, sizeof(ProConnector), &info.stuProConnector, sizeof(ProConnector));
		pMdl = info.pMdl;
		memcpy_s(&stuParentAsmAsmPath, sizeof(ProAsmcomppath), &info.stuParentAsmAsmPath, sizeof(ProAsmcomppath));
		pParentAsm = info.pParentAsm;
		strName = info.strName;
		matWld = info.matWld;
		strRefDes = info.strRefDes;
		vecEntryPortsCsys = info.vecEntryPortsCsys;
		return *this;
	}
	void Clear()
	{
		stuProConnector.owner = NULL;
		stuProConnector.comp_id_table[0] = -1;
		stuProConnector.table_num = 0;
		pMdl = NULL;
		stuParentAsmAsmPath.owner = NULL;
		stuParentAsmAsmPath.comp_id_table[0] = -1;
		stuParentAsmAsmPath.table_num = 0;
		pParentAsm = NULL;
		strName = L"";
		memset(&matWld, 0, sizeof(SVBASEMATRIX));
		matWld.m[0][0] = matWld.m[1][1] = matWld.m[2][2] = matWld.m[3][3] = 1.0;
		strRefDes = L"";
		vecEntryPortsCsys.clear();
	}
} IKSConnector;

// 总线电连接器的信息
typedef struct __tagIKSTrunkCabConnector
{
	IKSConnector stuConnData;				// 电连接器数据

	IKSConnector stuEquipmentConnData;		// 对应的设备电连接器数据
	IKSSpool stuBranchSplData;				// 分支电缆线轴数据
	CSVWString	strBranchSplNamePrefix;		// 分支电缆线轴名称前缀(例如:L;最终的线轴名称为:L_设备电连接器逻辑名称)

	CSVWString strTrunkEntryPortName1;		// 总线入口端名称1
	CSVWString strTrunkEntryPortName2;		// 总线入口端名称2
	CSVWString strEquipmentEntryPortName;	// 设备入口端名称

	UINT uTrunkEntryPortIndex1;				// 总线入口端索引1(总线电连接器数据中入口端坐标系中的索引)
	UINT uTrunkEntryPortIndex2;				// 总线入口端索引2(总线电连接器数据中入口端坐标系中的索引)
	UINT uTrunkEquipmentEntryPortIndex;		// 总线设备入口端索引(总线电连接器数据中入口端坐标系中的索引)
	UINT uEquipmentEntryPortIndex;			// 设备入口端索引(设备电连接器数据中入口端坐标系中的索引)

	SVBASEDOUBLE3 vTrunkConnWldPos;			// 电连接器世界位置（根据总线入口端位置计算）
	SVBASEDOUBLE3 vTrunkEntryPortWldPos1;	// 总线入口端的世界位置
	SVBASEDOUBLE3 vTrunkEntryPortWldAxisZ1;	// 总线入口端的世界Z轴方向
	UINT uTrunkEntryPortProCabLocIndex1;		// 总线入口端对应的电缆位置索引
	SVBASEDOUBLE3 vTrunkEntryPortCabLocTan1;	// 总线入口端对应的电缆位置切线方向
	SVBASEDOUBLE3 vTrunkEntryPortWldPos2;	// 总线入口端的世界位置
	SVBASEDOUBLE3 vTrunkEntryPortWldAxisZ2;	// 总线入口端的世界Z轴方向
	UINT uTrunkEntryPortProCabLocIndex2;	// 总线入口端对应的电缆位置索引
	SVBASEDOUBLE3 vTrunkEntryPortCabLocTan2;	// 总线入口端对应的电缆位置切线方向
	SVBASEDOUBLE3 vTrunkEquEntryPortWldPos;		// 总线设备入口端的世界位置
	SVBASEDOUBLE3 vTrunkEquEntryPortWldAxisZ;	// 总线设备入口端的世界Z轴方向
	UINT uTrunkEquEntryPortProCabLocIndex;		// 总线设备入口端对应的电缆位置索引
	SVBASEDOUBLE3 vTrunkEquEntryPortCabLocTan;	// 总线设备入口端对应的电缆位置切线方向

	SVBASEDOUBLE3 vEquipmentEntryPortWldPos;		// 设备入口端的世界位置
	SVBASEDOUBLE3 vEquipmentEntryPortWldAxisZ;		// 设备入口端的世界Z轴方向
	UINT uEquipmentEntryPortProCabLocIndex;			// 设备入口端对应的电缆位置索引
	SVBASEDOUBLE3 vEquipmentEntryPortCabLocTan;	// 设备入口端对应的电缆位置切线方向

	__tagIKSTrunkCabConnector()
	{
		strBranchSplNamePrefix = L"";
		strTrunkEntryPortName1 = L"";
		strTrunkEntryPortName2 = L"";
		strEquipmentEntryPortName = L"";
		uTrunkEntryPortIndex1 = UINT(-1);
		uTrunkEntryPortIndex2 = UINT(-1);
		uTrunkEquipmentEntryPortIndex = UINT(-1);
		uEquipmentEntryPortIndex = UINT(-1);
		memset(&vTrunkConnWldPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTrunkEntryPortWldPos1, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTrunkEntryPortWldAxisZ1, 0, sizeof(SVBASEDOUBLE3));
		uTrunkEntryPortProCabLocIndex1 = UINT(-1);
		memset(&vTrunkEntryPortCabLocTan1, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTrunkEntryPortWldPos2, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTrunkEntryPortWldAxisZ2, 0, sizeof(SVBASEDOUBLE3));
		uTrunkEntryPortProCabLocIndex2 = UINT(-1);
		memset(&vTrunkEntryPortCabLocTan2, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTrunkEquEntryPortWldPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTrunkEquEntryPortWldAxisZ, 0, sizeof(SVBASEDOUBLE3));
		uTrunkEquEntryPortProCabLocIndex = UINT(-1);
		memset(&vTrunkEquEntryPortCabLocTan, 0, sizeof(SVBASEDOUBLE3));
		memset(&vEquipmentEntryPortWldPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vEquipmentEntryPortWldAxisZ, 0, sizeof(SVBASEDOUBLE3));
		uEquipmentEntryPortProCabLocIndex = UINT(-1);
		memset(&vEquipmentEntryPortCabLocTan, 0, sizeof(SVBASEDOUBLE3));
	}
	__tagIKSTrunkCabConnector(const __tagIKSTrunkCabConnector &info)
	{
		stuConnData = info.stuConnData;
		stuEquipmentConnData = info.stuEquipmentConnData;
		stuBranchSplData = info.stuBranchSplData;
		strBranchSplNamePrefix = info.strBranchSplNamePrefix;
		strTrunkEntryPortName1 = info.strTrunkEntryPortName1;
		strTrunkEntryPortName2 = info.strTrunkEntryPortName2;
		strEquipmentEntryPortName = info.strEquipmentEntryPortName;
		uTrunkEntryPortIndex1 = info.uTrunkEntryPortIndex1;
		uTrunkEntryPortIndex2 = info.uTrunkEntryPortIndex2;
		uTrunkEquipmentEntryPortIndex = info.uTrunkEquipmentEntryPortIndex;
		uEquipmentEntryPortIndex = info.uEquipmentEntryPortIndex;
		vTrunkConnWldPos = info.vTrunkConnWldPos;
		vTrunkEntryPortWldPos1 = info.vTrunkEntryPortWldPos1;
		vTrunkEntryPortWldAxisZ1 = info.vTrunkEntryPortWldAxisZ1;
		uTrunkEntryPortProCabLocIndex1 = info.uTrunkEntryPortProCabLocIndex1;
		vTrunkEntryPortCabLocTan1 = info.vTrunkEntryPortCabLocTan1;
		vTrunkEntryPortWldPos2 = info.vTrunkEntryPortWldPos2;
		vTrunkEntryPortWldAxisZ2 = info.vTrunkEntryPortWldAxisZ2;
		uTrunkEntryPortProCabLocIndex2 = info.uTrunkEntryPortProCabLocIndex2;
		vTrunkEntryPortCabLocTan2 = info.vTrunkEntryPortCabLocTan2;
		vTrunkEquEntryPortWldPos = info.vTrunkEquEntryPortWldPos;
		vTrunkEquEntryPortWldAxisZ = info.vTrunkEquEntryPortWldAxisZ;
		uTrunkEquEntryPortProCabLocIndex = info.uTrunkEquEntryPortProCabLocIndex;
		vTrunkEquEntryPortCabLocTan = info.vTrunkEquEntryPortCabLocTan;
		vEquipmentEntryPortWldPos = info.vEquipmentEntryPortWldPos;
		vEquipmentEntryPortWldAxisZ = info.vEquipmentEntryPortWldAxisZ;
		uEquipmentEntryPortProCabLocIndex = info.uEquipmentEntryPortProCabLocIndex;
		vEquipmentEntryPortCabLocTan = info.vEquipmentEntryPortCabLocTan;
	}
	__tagIKSTrunkCabConnector& operator=(const __tagIKSTrunkCabConnector &info)
	{
		if (&info == this)
			return *this;
		stuConnData = info.stuConnData;
		stuEquipmentConnData = info.stuEquipmentConnData;
		stuBranchSplData = info.stuBranchSplData;
		strBranchSplNamePrefix = info.strBranchSplNamePrefix;
		strTrunkEntryPortName1 = info.strTrunkEntryPortName1;
		strTrunkEntryPortName2 = info.strTrunkEntryPortName2;
		strEquipmentEntryPortName = info.strEquipmentEntryPortName;
		uTrunkEntryPortIndex1 = info.uTrunkEntryPortIndex1;
		uTrunkEntryPortIndex2 = info.uTrunkEntryPortIndex2;
		uTrunkEquipmentEntryPortIndex = info.uTrunkEquipmentEntryPortIndex;
		uEquipmentEntryPortIndex = info.uEquipmentEntryPortIndex;
		vTrunkConnWldPos = info.vTrunkConnWldPos;
		vTrunkEntryPortWldPos1 = info.vTrunkEntryPortWldPos1;
		vTrunkEntryPortWldAxisZ1 = info.vTrunkEntryPortWldAxisZ1;
		uTrunkEntryPortProCabLocIndex1 = info.uTrunkEntryPortProCabLocIndex1;
		vTrunkEntryPortCabLocTan1 = info.vTrunkEntryPortCabLocTan1;
		vTrunkEntryPortWldPos2 = info.vTrunkEntryPortWldPos2;
		vTrunkEntryPortWldAxisZ2 = info.vTrunkEntryPortWldAxisZ2;
		uTrunkEntryPortProCabLocIndex2 = info.uTrunkEntryPortProCabLocIndex2;
		vTrunkEntryPortCabLocTan2 = info.vTrunkEntryPortCabLocTan2;
		vTrunkEquEntryPortWldPos = info.vTrunkEquEntryPortWldPos;
		vTrunkEquEntryPortWldAxisZ = info.vTrunkEquEntryPortWldAxisZ;
		uTrunkEquEntryPortProCabLocIndex = info.uTrunkEquEntryPortProCabLocIndex;
		vTrunkEquEntryPortCabLocTan = info.vTrunkEquEntryPortCabLocTan;
		vEquipmentEntryPortWldPos = info.vEquipmentEntryPortWldPos;
		vEquipmentEntryPortWldAxisZ = info.vEquipmentEntryPortWldAxisZ;
		uEquipmentEntryPortProCabLocIndex = info.uEquipmentEntryPortProCabLocIndex;
		vEquipmentEntryPortCabLocTan = info.vEquipmentEntryPortCabLocTan;
		return *this;
	}
	void Clear()
	{
		stuConnData.Clear();
		stuEquipmentConnData.Clear();
		stuBranchSplData.Clear();
		strBranchSplNamePrefix = L"";
		strTrunkEntryPortName1 = L"";
		strTrunkEntryPortName2 = L"";
		strEquipmentEntryPortName = L"";
		uTrunkEntryPortIndex1 = UINT(-1);
		uTrunkEntryPortIndex2 = UINT(-1);
		uTrunkEquipmentEntryPortIndex = UINT(-1);
		uEquipmentEntryPortIndex = UINT(-1);
		memset(&vTrunkConnWldPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTrunkEntryPortWldPos1, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTrunkEntryPortWldAxisZ1, 0, sizeof(SVBASEDOUBLE3));
		uTrunkEntryPortProCabLocIndex1 = UINT(-1);
		memset(&vTrunkEntryPortCabLocTan1, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTrunkEntryPortWldPos2, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTrunkEntryPortWldAxisZ2, 0, sizeof(SVBASEDOUBLE3));
		uTrunkEntryPortProCabLocIndex2 = UINT(-1);
		memset(&vTrunkEntryPortCabLocTan2, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTrunkEquEntryPortWldPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vTrunkEquEntryPortWldAxisZ, 0, sizeof(SVBASEDOUBLE3));
		uTrunkEquEntryPortProCabLocIndex = UINT(-1);
		memset(&vTrunkEquEntryPortCabLocTan, 0, sizeof(SVBASEDOUBLE3));
		memset(&vEquipmentEntryPortWldPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vEquipmentEntryPortWldAxisZ, 0, sizeof(SVBASEDOUBLE3));
		uEquipmentEntryPortProCabLocIndex = UINT(-1);
		memset(&vEquipmentEntryPortCabLocTan, 0, sizeof(SVBASEDOUBLE3));
	}
} IKSTrunkCabConnector;

// 总线电缆段信息
typedef struct __tagIKSTrunkCabSegmentInfo
{
	CSVWString	strHarnessName;							// 线束名称

	IKSTrunkCabConnector stuConnStart;					// 起始电连接器
	IKSTrunkCabConnector stuConnEnd;					// 终止电连接器
	std::vector<IKSTrunkCabConnector> vecConnMid;		// 中间电连接器

	IKSSpool stuSplData;								// 总线电缆段的线轴数据
	CSVWString	strSplNamePrefix;						// 总线电缆段的线轴名称前缀(例如:ZX;最终的线轴名称为:ZX_起始电连接器逻辑名称__终止电连接器逻辑名称)

	__tagIKSTrunkCabSegmentInfo()
	{
		strHarnessName = L"";
		strSplNamePrefix = L"";
	}
	__tagIKSTrunkCabSegmentInfo(const __tagIKSTrunkCabSegmentInfo &info)
	{
		strHarnessName = info.strHarnessName;
		stuConnStart = info.stuConnStart;
		stuConnEnd = info.stuConnEnd;
		vecConnMid = info.vecConnMid;
		stuSplData = info.stuSplData;
		strSplNamePrefix = info.strSplNamePrefix;
	}
	__tagIKSTrunkCabSegmentInfo& operator=(const __tagIKSTrunkCabSegmentInfo &info)
	{
		if (&info == this)
			return *this;
		strHarnessName = info.strHarnessName;
		stuConnStart = info.stuConnStart;
		stuConnEnd = info.stuConnEnd;
		vecConnMid = info.vecConnMid;
		stuSplData = info.stuSplData;
		strSplNamePrefix = info.strSplNamePrefix;
		return *this;
	}
	void Clear()
	{
		strHarnessName = L"";
		stuConnStart.Clear();
		stuConnEnd.Clear();
		vecConnMid.clear();
		stuSplData.Clear();
		strSplNamePrefix = L"";
	}
} IKSTrunkCabSegmentInfo;

// 模型节点数据信息
typedef struct __tagCABModelNodeData
{
	ProMdl		handle;							// 节点句柄(指向ProE模型的指针)
	int			nFeatureID;						// 特征ID(当前节点对应的特征ID)
	ProAssembly pParentProeAssm;				// 父装配体
	ProAsmcomppath stuProeAsmPath;				// ProE的装配路径
	int			nType;							// 参看枚举类型CABMODELNODETYPE
	CUnicodeString		strName;				// 节点名称
	double		matrix[4][4];					// 本节点变换到上一层级坐标系位置的转换矩阵
	double		matWld[4][4];					// 本节点变换到顶层坐标系位置的转换矩阵
	int			nHarnessIndex;					// 线束索引(只有当nType值为CABMNTYPE_PART_HARNESS且通过模型树生成线束数据后才有效)
	int			nConnectorIndex;				// 电连接器索引(只有当nType值为CABMNTYPE_PART_CONNECTOR且通过模型树生成电连接器数据后才有效)
	CBPDynamicArray<__tagCABModelNodeData>	arrSubNode;		// 子节点数据

	__tagCABModelNodeData()
	{
		clear();
	}
	__tagCABModelNodeData(const __tagCABModelNodeData &data)
	{
		CopyLocalData(data);
		arrSubNode = data.arrSubNode;
	}
	__tagCABModelNodeData &operator=(const __tagCABModelNodeData& data){
		if (&data != this)
		{
			CopyLocalData(data);
			arrSubNode = data.arrSubNode;
		}
		return *this;
	}
	// 拷贝本层数据
	void CopyLocalData(const __tagCABModelNodeData &data)
	{
		handle = data.handle;
		nFeatureID = data.nFeatureID;
		pParentProeAssm = data.pParentProeAssm;
		memcpy_s(&stuProeAsmPath, sizeof(ProAsmcomppath), &data.stuProeAsmPath, sizeof(ProAsmcomppath));
		nType = data.nType;
		strName = data.strName;
		memcpy_s(matrix, sizeof(double)*16, data.matrix, sizeof(double)*16);
		memcpy_s(matWld, sizeof(double)*16, data.matWld, sizeof(double)*16);
		nHarnessIndex = data.nHarnessIndex;
		nConnectorIndex = data.nConnectorIndex;
	}
	// 清除数据
	void clear()
	{
		handle = NULL;
		nFeatureID = -1;
		pParentProeAssm = NULL;
		stuProeAsmPath.owner = NULL;
		stuProeAsmPath.table_num = 0;
		nType = CABMNTYPE_UNUSED;
		strName = L"";
		memset(matrix, 0, sizeof(double)*16);
		matrix[0][0] = matrix[1][1] = matrix[2][2] = matrix[3][3] = 1.0;
		memset(matWld, 0, sizeof(double)*16);
		matWld[0][0] = matWld[1][1] = matWld[2][2] = matWld[3][3] = 1.0;
		nHarnessIndex = -1;
		nConnectorIndex = -1;
		arrSubNode.clear();
	}
} CABModelNodeData;

// 电缆连接关系表元素
typedef struct __tagIKSCableConnectTabElem
{
	CString strHarnessName;		// 线束名称(电缆代号)
	CString strCableName;		// 电缆名称(分支代号)
	CString strConnRefDes1;		// 起始电连接器的逻辑描述(起始端口)
	CString strConnMdlName1;	// 起始电连接器的模型名称(起始电连接器类型)
	CString strConnRefDes2;		// 终止电连接器的逻辑描述(终止端口)
	CString strConnMdlName2;	// 终止电连接器的模型名称(起始电连接器类型)
	CString strCabType;			// 电缆分支类型
	CString strCabSpoolName;	// 电缆线轴名称(分支类型 + "_" + 分支代号)

	double dDiameter;			// 导线外径
	double dMinBendRadius;		// 最小转弯半径
	CString strColor;			// 颜色
	double dDensity;			// 线密度

	__tagIKSCableConnectTabElem()
	{
		strHarnessName = L"";
		strCableName = L"";
		strConnRefDes1 = L"";
		strConnMdlName1 = L"";
		strConnRefDes2 = L"";
		strConnMdlName2 = L"";
		strCabType = L"";
		strCabSpoolName = L"";
		dDiameter = 0.0;
		dMinBendRadius = 0.0;
		strColor = L"";
		dDensity = 0.0;
	}
	__tagIKSCableConnectTabElem(const __tagIKSCableConnectTabElem &info)
	{
		strHarnessName = info.strHarnessName;
		strCableName = info.strCableName;
		strConnRefDes1 = info.strConnRefDes1;
		strConnMdlName1 = info.strConnMdlName1;
		strConnRefDes2 = info.strConnRefDes2;
		strConnMdlName2 = info.strConnMdlName2;
		strCabType = info.strCabType;
		strCabSpoolName = info.strCabSpoolName;
		dDiameter = info.dDiameter;
		dMinBendRadius = info.dMinBendRadius;
		strColor = info.strColor;
		dDensity = info.dDensity;
	}
	__tagIKSCableConnectTabElem& operator=(const __tagIKSCableConnectTabElem &info)
	{
		if (&info == this)
			return *this;
		strHarnessName = info.strHarnessName;
		strCableName = info.strCableName;
		strConnRefDes1 = info.strConnRefDes1;
		strConnMdlName1 = info.strConnMdlName1;
		strConnRefDes2 = info.strConnRefDes2;
		strConnMdlName2 = info.strConnMdlName2;
		strCabType = info.strCabType;
		strCabSpoolName = info.strCabSpoolName;
		dDiameter = info.dDiameter;
		dMinBendRadius = info.dMinBendRadius;
		strColor = info.strColor;
		dDensity = info.dDensity;
		return *this;
	}
} IKSCableConnectTabElem;

// 电缆线轴表元素
typedef struct __tagIKSCableSpoolTabElem
{
	CString strSymbol;			// 线轴代号(导线名称/分支类型)
	CString strSpoolType;		// 线轴类型(类型)
	double dDiameter;			// 导线外径
	double dMinBendRadius;		// 最小转弯半径
	CString strUnit;			// 单位
	CString strColor;			// 颜色
	double dDensity;			// 线密度

	__tagIKSCableSpoolTabElem()
	{
		strSymbol = L"";
		strSpoolType = L"";
		dDiameter = 0.0;
		dMinBendRadius = 0.0;
		strUnit = L"";
		strColor = L"";
		dDensity = 0.0;
	}
	__tagIKSCableSpoolTabElem(const __tagIKSCableSpoolTabElem &info)
	{
		strSymbol = info.strSymbol;
		strSpoolType = info.strSpoolType;
		dDiameter = info.dDiameter;
		dMinBendRadius = info.dMinBendRadius;
		strUnit = info.strUnit;
		strColor = info.strColor;
		dDensity = info.dDensity;
	}
	__tagIKSCableSpoolTabElem& operator=(const __tagIKSCableSpoolTabElem &info)
	{
		if (&info == this)
			return *this;
		strSymbol = info.strSymbol;
		strSpoolType = info.strSpoolType;
		dDiameter = info.dDiameter;
		dMinBendRadius = info.dMinBendRadius;
		strUnit = info.strUnit;
		strColor = info.strColor;
		dDensity = info.dDensity;
		return *this;
	}
} IKSCableSpoolTabElem;

// 电缆连接关系表
typedef struct __tagIKSCableConnectTab
{
	CBPDynamicArray<IKSCableConnectTabElem> arrCabConnTabElem;			// 电缆连接关系
	CBPDynamicArray<CBPDynamicArray<UINT> > arrHarnCabElemIndex;		// 线束对应的电缆索引(同一个线束名称对应的arrCabConnTabElem的索引)
	CBPDynamicArray<IKSCableSpoolTabElem> arrCableSpoolTabElem;			// 线轴数据信息

	__tagIKSCableConnectTab()
	{
	}
	__tagIKSCableConnectTab(const __tagIKSCableConnectTab &info)
	{
		arrCabConnTabElem = info.arrCabConnTabElem;
		arrHarnCabElemIndex = info.arrHarnCabElemIndex;
		arrCableSpoolTabElem = info.arrCableSpoolTabElem;
	}
	__tagIKSCableConnectTab& operator=(const __tagIKSCableConnectTab &info)
	{
		if (&info == this)
			return *this;
		arrCabConnTabElem = info.arrCabConnTabElem;
		arrHarnCabElemIndex = info.arrHarnCabElemIndex;
		arrCableSpoolTabElem = info.arrCableSpoolTabElem;
		return *this;
	}
	void Clear()
	{
		arrCabConnTabElem.clear();
		arrHarnCabElemIndex.clear();
		arrCableSpoolTabElem.clear();
	}
} IKSCableConnectTab;

// 电缆线轴表选项
typedef struct __tagIKSCableSpoolTabConfig
{
	int nCabSplStartRow;
	int nCabSplSymCol;
	int nCabSplTypeCol;
	int nCabSplDiaCol;
	int nCabSplMinBendRadiusCol;
	int nCabSplUnitCol;
	int nCabSplColorCol;
	int nCabSplDensityCol;

	__tagIKSCableSpoolTabConfig()
	{
		Clear();
	}
	__tagIKSCableSpoolTabConfig(const __tagIKSCableSpoolTabConfig &info)
	{
		nCabSplStartRow = info.nCabSplStartRow;
		nCabSplSymCol = info.nCabSplSymCol;
		nCabSplTypeCol = info.nCabSplTypeCol;
		nCabSplDiaCol = info.nCabSplDiaCol;
		nCabSplMinBendRadiusCol = info.nCabSplMinBendRadiusCol;
		nCabSplUnitCol = info.nCabSplUnitCol;
		nCabSplColorCol = info.nCabSplColorCol;
		nCabSplDensityCol = info.nCabSplDensityCol;
	}
	__tagIKSCableSpoolTabConfig& operator=(const __tagIKSCableSpoolTabConfig &info)
	{
		if (&info == this)
			return *this;
		nCabSplStartRow = info.nCabSplStartRow;
		nCabSplSymCol = info.nCabSplSymCol;
		nCabSplTypeCol = info.nCabSplTypeCol;
		nCabSplDiaCol = info.nCabSplDiaCol;
		nCabSplMinBendRadiusCol = info.nCabSplMinBendRadiusCol;
		nCabSplUnitCol = info.nCabSplUnitCol;
		nCabSplColorCol = info.nCabSplColorCol;
		nCabSplDensityCol = info.nCabSplDensityCol;
		return *this;
	}
	void Clear()
	{
		nCabSplStartRow = 2;
		nCabSplSymCol = 2;
		nCabSplTypeCol = 3;
		nCabSplDiaCol = 4;
		nCabSplMinBendRadiusCol = 5;
		nCabSplUnitCol = 6;
		nCabSplColorCol = 7;
		nCabSplDensityCol = 8;
	}
} IKSCableSpoolTabConfig;

// 电缆连接关系表选项
typedef struct __tagIKSCableConnectTabConfig
{
	int nConnSheetIndex;
	int nConnStartRow;
	int nConnHarnNameCol;
	int nConnCabNameCol;
	int nConnRefDes1Col;
	int nConnMdlName1Col;
	int nConnRefDes2Col;
	int nConnMdlName2Col;
	int nConnSplTypeNameCol;
	int nConnDiameterCol;
	int nConnMinBendRadiusCol;
	int nConnColorCol;
	int nConnDensityCol;
	std::vector<CString> vecConnReplaceCharSrc;
	std::vector<CString> vecConnReplaceCharDst;

	int nCabSplSheetIndex;
	IKSCableSpoolTabConfig stuCabSplConfig;

	__tagIKSCableConnectTabConfig()
	{
		nConnSheetIndex = 1;
		nConnStartRow = 2;
		nConnHarnNameCol = 2;
		nConnCabNameCol = 3;
		nConnRefDes1Col = 4;
		nConnMdlName1Col = 5;
		nConnRefDes2Col = 6;
		nConnMdlName2Col = 7;
		nConnSplTypeNameCol = 8;
		nConnDiameterCol = 9;
		nConnMinBendRadiusCol = 10;
		nConnColorCol = 11;
		nConnDensityCol = 12;
		nCabSplSheetIndex = 2;
	}
	__tagIKSCableConnectTabConfig(const __tagIKSCableConnectTabConfig &info)
	{
		nConnSheetIndex = info.nConnSheetIndex;
		nConnStartRow = info.nConnStartRow;
		nConnHarnNameCol = info.nConnHarnNameCol;
		nConnCabNameCol = info.nConnCabNameCol;
		nConnRefDes1Col = info.nConnRefDes1Col;
		nConnMdlName1Col = info.nConnMdlName1Col;
		nConnRefDes2Col = info.nConnRefDes2Col;
		nConnMdlName2Col = info.nConnMdlName2Col;
		nConnSplTypeNameCol = info.nConnSplTypeNameCol;
		nConnDiameterCol = info.nConnDiameterCol;
		nConnMinBendRadiusCol = info.nConnMinBendRadiusCol;
		nConnColorCol = info.nConnColorCol;
		nConnDensityCol = info.nConnDensityCol;
		vecConnReplaceCharSrc = info.vecConnReplaceCharSrc;
		vecConnReplaceCharDst = info.vecConnReplaceCharDst;
		nCabSplSheetIndex = info.nCabSplSheetIndex;
		stuCabSplConfig = info.stuCabSplConfig;
	}
	__tagIKSCableConnectTabConfig& operator=(const __tagIKSCableConnectTabConfig &info)
	{
		if (&info == this)
			return *this;
		nConnSheetIndex = info.nConnSheetIndex;
		nConnStartRow = info.nConnStartRow;
		nConnHarnNameCol = info.nConnHarnNameCol;
		nConnCabNameCol = info.nConnCabNameCol;
		nConnRefDes1Col = info.nConnRefDes1Col;
		nConnMdlName1Col = info.nConnMdlName1Col;
		nConnRefDes2Col = info.nConnRefDes2Col;
		nConnMdlName2Col = info.nConnMdlName2Col;
		nConnSplTypeNameCol = info.nConnSplTypeNameCol;
		nConnDiameterCol = info.nConnDiameterCol;
		nConnMinBendRadiusCol = info.nConnMinBendRadiusCol;
		nConnColorCol = info.nConnColorCol;
		nConnDensityCol = info.nConnDensityCol;
		vecConnReplaceCharSrc = info.vecConnReplaceCharSrc;
		vecConnReplaceCharDst = info.vecConnReplaceCharDst;
		nCabSplSheetIndex = info.nCabSplSheetIndex;
		stuCabSplConfig = info.stuCabSplConfig;
		return *this;
	}
} IKSCableConnectTabConfig;

// 总线电缆连接关系表
typedef struct __tagIKSTrunkCableConnectTab
{
	CBPDynamicArray<IKSTrunkCabSegmentInfo> arrTrunkCabSegElem;			// 总线电缆段
	CBPDynamicArray<IKSCableSpoolTabElem> arrCableSpoolTabElem;			// 线轴数据信息

	__tagIKSTrunkCableConnectTab()
	{
	}
	__tagIKSTrunkCableConnectTab(const __tagIKSTrunkCableConnectTab &info)
	{
		arrTrunkCabSegElem = info.arrTrunkCabSegElem;
		arrCableSpoolTabElem = info.arrCableSpoolTabElem;
	}
	__tagIKSTrunkCableConnectTab& operator=(const __tagIKSTrunkCableConnectTab &info)
	{
		if (&info == this)
			return *this;
		arrTrunkCabSegElem = info.arrTrunkCabSegElem;
		arrCableSpoolTabElem = info.arrCableSpoolTabElem;
		return *this;
	}
	void Clear()
	{
		arrTrunkCabSegElem.clear();
		arrCableSpoolTabElem.clear();
	}
} IKSTrunkCableConnectTab;

// 总线电缆连接关系表选项
typedef struct __tagIKSTrunkCabConnectTabConfig
{
	std::vector<CString> vecTrunkEntryPortName;
	CString strEquipmentEntryPortName;
	CString strEntryPortType;
	double dEntryPortIntLength;

	CString strTrunkSplType;
	double dTrunkSplDiameter;
	double dTrunkSplMinBendRadius;
	CString strTrunkSplUnit;
	CString strTrunkSplColor;
	double dTrunkSplDensity;

	CString strEquipmentSplType;
	double dEquipmentSplDiameter;
	double dEquipmentSplMinBendRadius;
	CString strEquipmentSplUnit;
	CString strEquipmentSplColor;
	double dEquipmentSplDensity;

	int nConnSheetIndex;
	int nConnStartRow;
	int nConnHarnNameCol;
	int nConnRefDesCol;
	int nConnMdlNameCol;
	int nConnTrunkEntryPortNameCol;
	int nConnSplTypeNameCol;
	int nConnEquipmentRefDesCol;
	int nConnEquipmentMdlNameCol;
	int nConnEquipmentSplTypeNameCol;
	std::vector<CString> vecConnReplaceCharSrc;
	std::vector<CString> vecConnReplaceCharDst;

	int nCabSplSheetIndex;
	IKSCableSpoolTabConfig stuCabSplConfig;

	__tagIKSTrunkCabConnectTabConfig()
	{
		strEquipmentEntryPortName = _T("CS0");
		strEntryPortType = _T("ROUND");
		dEntryPortIntLength = 0.0;
		strTrunkSplType = _T("ZX");
		dTrunkSplDiameter = 2.0;
		dTrunkSplMinBendRadius = 0.5;
		strTrunkSplUnit = _T("MM");
		strTrunkSplColor = _T("c10");
		dTrunkSplDensity = 0.0001;
		strEquipmentSplType = _T("L");
		dEquipmentSplDiameter = 2.0;
		dEquipmentSplMinBendRadius = 0.5;
		strEquipmentSplUnit = _T("MM");
		strEquipmentSplColor = _T("c10");
		dEquipmentSplDensity = 0.0001;
		nConnSheetIndex = 1;
		nConnStartRow = 2;
		nConnHarnNameCol = 2;
		nConnRefDesCol = 3;
		nConnMdlNameCol = 4;
		nConnTrunkEntryPortNameCol = 5;
		nConnSplTypeNameCol = 6;
		nConnEquipmentRefDesCol = 7;
		nConnEquipmentMdlNameCol = 8;
		nConnEquipmentSplTypeNameCol = 9;
		nCabSplSheetIndex = 2;
	}
	__tagIKSTrunkCabConnectTabConfig(const __tagIKSTrunkCabConnectTabConfig &info)
	{
		vecTrunkEntryPortName = info.vecTrunkEntryPortName;
		strEquipmentEntryPortName = info.strEquipmentEntryPortName;
		strEntryPortType = info.strEntryPortType;
		dEntryPortIntLength = info.dEntryPortIntLength;
		strTrunkSplType = info.strTrunkSplType;
		dTrunkSplDiameter = info.dTrunkSplDiameter;
		dTrunkSplMinBendRadius = info.dTrunkSplMinBendRadius;
		strTrunkSplUnit = info.strTrunkSplUnit;
		strTrunkSplColor = info.strTrunkSplColor;
		dTrunkSplDensity = info.dTrunkSplDensity;
		strEquipmentSplType = info.strEquipmentSplType;
		dEquipmentSplDiameter = info.dEquipmentSplDiameter;
		dEquipmentSplMinBendRadius = info.dEquipmentSplMinBendRadius;
		strEquipmentSplUnit = info.strEquipmentSplUnit;
		strEquipmentSplColor = info.strEquipmentSplColor;
		dEquipmentSplDensity = info.dEquipmentSplDensity;
		nConnSheetIndex = info.nConnSheetIndex;
		nConnStartRow = info.nConnStartRow;
		nConnHarnNameCol = info.nConnHarnNameCol;
		nConnRefDesCol = info.nConnRefDesCol;
		nConnMdlNameCol = info.nConnMdlNameCol;
		nConnTrunkEntryPortNameCol = info.nConnTrunkEntryPortNameCol;
		nConnSplTypeNameCol = info.nConnSplTypeNameCol;
		nConnEquipmentRefDesCol = info.nConnEquipmentRefDesCol;
		nConnEquipmentMdlNameCol = info.nConnEquipmentMdlNameCol;
		nConnEquipmentSplTypeNameCol = info.nConnEquipmentSplTypeNameCol;
		vecConnReplaceCharSrc = info.vecConnReplaceCharSrc;
		vecConnReplaceCharDst = info.vecConnReplaceCharDst;
		nCabSplSheetIndex = info.nCabSplSheetIndex;
		stuCabSplConfig = info.stuCabSplConfig;
	}
	__tagIKSTrunkCabConnectTabConfig& operator=(const __tagIKSTrunkCabConnectTabConfig &info)
	{
		if (&info == this)
			return *this;
		vecTrunkEntryPortName = info.vecTrunkEntryPortName;
		strEquipmentEntryPortName = info.strEquipmentEntryPortName;
		strEntryPortType = info.strEntryPortType;
		dEntryPortIntLength = info.dEntryPortIntLength;
		strTrunkSplType = info.strTrunkSplType;
		dTrunkSplDiameter = info.dTrunkSplDiameter;
		dTrunkSplMinBendRadius = info.dTrunkSplMinBendRadius;
		strTrunkSplUnit = info.strTrunkSplUnit;
		strTrunkSplColor = info.strTrunkSplColor;
		dTrunkSplDensity = info.dTrunkSplDensity;
		strEquipmentSplType = info.strEquipmentSplType;
		dEquipmentSplDiameter = info.dEquipmentSplDiameter;
		dEquipmentSplMinBendRadius = info.dEquipmentSplMinBendRadius;
		strEquipmentSplUnit = info.strEquipmentSplUnit;
		strEquipmentSplColor = info.strEquipmentSplColor;
		dEquipmentSplDensity = info.dEquipmentSplDensity;
		nConnSheetIndex = info.nConnSheetIndex;
		nConnStartRow = info.nConnStartRow;
		nConnHarnNameCol = info.nConnHarnNameCol;
		nConnRefDesCol = info.nConnRefDesCol;
		nConnMdlNameCol = info.nConnMdlNameCol;
		nConnTrunkEntryPortNameCol = info.nConnTrunkEntryPortNameCol;
		nConnSplTypeNameCol = info.nConnSplTypeNameCol;
		nConnEquipmentRefDesCol = info.nConnEquipmentRefDesCol;
		nConnEquipmentMdlNameCol = info.nConnEquipmentMdlNameCol;
		nConnEquipmentSplTypeNameCol = info.nConnEquipmentSplTypeNameCol;
		vecConnReplaceCharSrc = info.vecConnReplaceCharSrc;
		vecConnReplaceCharDst = info.vecConnReplaceCharDst;
		nCabSplSheetIndex = info.nCabSplSheetIndex;
		stuCabSplConfig = info.stuCabSplConfig;
		return *this;
	}
	void Clear()
	{
		vecTrunkEntryPortName.clear();
		strEquipmentEntryPortName = _T("CS0");
		strEntryPortType = _T("ROUND");
		dEntryPortIntLength = 0.0;
		strTrunkSplType = _T("ZX");
		dTrunkSplDiameter = 2.0;
		dTrunkSplMinBendRadius = 0.5;
		strTrunkSplUnit = _T("MM");
		strTrunkSplColor = _T("c10");
		dTrunkSplDensity = 0.0001;
		strEquipmentSplType = _T("L");
		dEquipmentSplDiameter = 2.0;
		dEquipmentSplMinBendRadius = 0.5;
		strEquipmentSplUnit = _T("MM");
		strEquipmentSplColor = _T("c10");
		dEquipmentSplDensity = 0.0001;
		nConnSheetIndex = 1;
		nConnStartRow = 2;
		nConnHarnNameCol = 2;
		nConnRefDesCol = 3;
		nConnMdlNameCol = 4;
		nConnTrunkEntryPortNameCol = 5;
		nConnSplTypeNameCol = 6;
		nConnEquipmentRefDesCol = 7;
		nConnEquipmentMdlNameCol = 8;
		nConnEquipmentSplTypeNameCol = 9;
		vecConnReplaceCharSrc.clear();
		vecConnReplaceCharDst.clear();
		nCabSplSheetIndex = 2;
		stuCabSplConfig.Clear();
	}
} IKSTrunkCabConnectTabConfig;

// 电线线轴表选项
typedef struct __tagIKSWireSpoolTabConfig
{
	int nWireSplStartRow;
	int nWireSplSymCol;
	int nWireSplDiaCol;
	int nWireSplDensityCol;

	int nWireSplSymStdFormatLen;
	CString strWireSplSymStdFormatKey_;
	int nWireSplSymStdFormatKey_Pos;
	CString strWireSplSymStdFormatKeyX;
	int nWireSplSymStdFormatKeyXPos;
	int nWireSplSymStdFormatCoreNumPos;

	double dWireSplDiaCoef;
	double dWireSplDensityCoef;

	__tagIKSWireSpoolTabConfig()
	{
		Clear();
	}
	__tagIKSWireSpoolTabConfig(const __tagIKSWireSpoolTabConfig &info)
	{
		nWireSplStartRow = info.nWireSplStartRow;
		nWireSplSymCol = info.nWireSplSymCol;
		nWireSplDiaCol = info.nWireSplDiaCol;
		nWireSplDensityCol = info.nWireSplDensityCol;
		nWireSplSymStdFormatLen = info.nWireSplSymStdFormatLen;
		strWireSplSymStdFormatKey_ = info.strWireSplSymStdFormatKey_;
		nWireSplSymStdFormatKey_Pos = info.nWireSplSymStdFormatKey_Pos;
		strWireSplSymStdFormatKeyX = info.strWireSplSymStdFormatKeyX;
		nWireSplSymStdFormatKeyXPos = info.nWireSplSymStdFormatKeyXPos;
		nWireSplSymStdFormatCoreNumPos = info.nWireSplSymStdFormatCoreNumPos;
		dWireSplDiaCoef = info.dWireSplDiaCoef;
		dWireSplDensityCoef = info.dWireSplDensityCoef;
	}
	__tagIKSWireSpoolTabConfig& operator=(const __tagIKSWireSpoolTabConfig &info)
	{
		if (&info == this)
			return *this;
		nWireSplStartRow = info.nWireSplStartRow;
		nWireSplSymCol = info.nWireSplSymCol;
		nWireSplDiaCol = info.nWireSplDiaCol;
		nWireSplDensityCol = info.nWireSplDensityCol;
		nWireSplSymStdFormatLen = info.nWireSplSymStdFormatLen;
		strWireSplSymStdFormatKey_ = info.strWireSplSymStdFormatKey_;
		nWireSplSymStdFormatKey_Pos = info.nWireSplSymStdFormatKey_Pos;
		strWireSplSymStdFormatKeyX = info.strWireSplSymStdFormatKeyX;
		nWireSplSymStdFormatKeyXPos = info.nWireSplSymStdFormatKeyXPos;
		nWireSplSymStdFormatCoreNumPos = info.nWireSplSymStdFormatCoreNumPos;
		dWireSplDiaCoef = info.dWireSplDiaCoef;
		dWireSplDensityCoef = info.dWireSplDensityCoef;
		return *this;
	}
	void Clear()
	{
		nWireSplStartRow = 2;
		nWireSplSymCol = 1;
		nWireSplDiaCol = 2;
		nWireSplDensityCol = 3;
		nWireSplSymStdFormatLen = 7;
		strWireSplSymStdFormatKey_ = L"-";
		nWireSplSymStdFormatKey_Pos = 5;
		strWireSplSymStdFormatKeyX = L"X";
		nWireSplSymStdFormatKeyXPos = 4;
		nWireSplSymStdFormatCoreNumPos = 3;
		dWireSplDiaCoef = 1.0;
		dWireSplDensityCoef = 0.000001;
	}
} IKSWireSpoolTabConfig;

// 电线接点表选项
typedef struct __tagIKSCableSpoolConnectTabConfig
{
	CString strConSheetKey;
	CString strSpoolSheetKey;

	int nConCellKeyCol;
	CString strConCellKey;
	BPBASEUINT2 u2ConStartCellOffset;
	BPBASEUINT2 u2ConEndCellOffset;
	std::vector<CString> vecConStartEndCellReplaceCharSrc;
	std::vector<CString> vecConStartEndCellReplaceCharDst;
	BPBASEUINT2 u2ConSpoolCellOffset;

	IKSWireSpoolTabConfig stuWireSplConfig;

	__tagIKSCableSpoolConnectTabConfig()
	{
		strConSheetKey = L"";
		strSpoolSheetKey = L"";
		nConCellKeyCol = 0;
		strConCellKey = L"";
		memset(&u2ConStartCellOffset, 0, sizeof(BPBASEUINT2));
		memset(&u2ConEndCellOffset, 0, sizeof(BPBASEUINT2));
		memset(&u2ConSpoolCellOffset, 0, sizeof(BPBASEUINT2));
	}
	__tagIKSCableSpoolConnectTabConfig(const __tagIKSCableSpoolConnectTabConfig &info)
	{
		strConSheetKey = info.strConSheetKey;
		strSpoolSheetKey = info.strSpoolSheetKey;
		nConCellKeyCol = info.nConCellKeyCol;
		strConCellKey = info.strConCellKey;
		u2ConStartCellOffset = info.u2ConStartCellOffset;
		u2ConEndCellOffset = info.u2ConEndCellOffset;
		vecConStartEndCellReplaceCharSrc = info.vecConStartEndCellReplaceCharSrc;
		vecConStartEndCellReplaceCharDst = info.vecConStartEndCellReplaceCharDst;
		u2ConSpoolCellOffset = info.u2ConSpoolCellOffset;
		stuWireSplConfig = info.stuWireSplConfig;
	}
	__tagIKSCableSpoolConnectTabConfig& operator=(const __tagIKSCableSpoolConnectTabConfig &info)
	{
		if (&info == this)
			return *this;
		strConSheetKey = info.strConSheetKey;
		strSpoolSheetKey = info.strSpoolSheetKey;
		nConCellKeyCol = info.nConCellKeyCol;
		strConCellKey = info.strConCellKey;
		u2ConStartCellOffset = info.u2ConStartCellOffset;
		u2ConEndCellOffset = info.u2ConEndCellOffset;
		vecConStartEndCellReplaceCharSrc = info.vecConStartEndCellReplaceCharSrc;
		vecConStartEndCellReplaceCharDst = info.vecConStartEndCellReplaceCharDst;
		u2ConSpoolCellOffset = info.u2ConSpoolCellOffset;
		stuWireSplConfig = info.stuWireSplConfig;
		return *this;
	}
} IKSCableSpoolConnectTabConfig;

// 电线线轴表(电缆线径表)元素
typedef struct __tagIKSWireSpoolTabElem
{
	CString strSpoolName;
	double dDiameter;
	double dDensity;
	int nCoreNum;

	__tagIKSWireSpoolTabElem()
	{
		strSpoolName = L"";
		dDiameter = 0.0;
		dDensity = 0.0;
		nCoreNum = 1;
	}
	__tagIKSWireSpoolTabElem(const __tagIKSWireSpoolTabElem &info)
	{
		strSpoolName = info.strSpoolName;
		dDiameter = info.dDiameter;
		dDensity = info.dDensity;
		nCoreNum = info.nCoreNum;
	}
	__tagIKSWireSpoolTabElem& operator=(const __tagIKSWireSpoolTabElem &info)
	{
		if (&info == this)
			return *this;
		strSpoolName = info.strSpoolName;
		dDiameter = info.dDiameter;
		dDensity = info.dDensity;
		nCoreNum = info.nCoreNum;
		return *this;
	}
} IKSWireSpoolTabElem;

// 电缆连接关系综合表电缆元素
typedef struct __tagIKSCableConnectOverallTabCableElem
{
	CString strCableName;		// 电缆名称(分支代号)
	CString strConnRefDes1;		// 起始电连接器的逻辑描述(起始端口)
	CString strConnMdlName1;	// 起始电连接器的模型名称(起始电连接器类型)
	CString strConnRefDes2;		// 终止电连接器的逻辑描述(终止端口)
	CString strConnMdlName2;	// 终止电连接器的模型名称(起始电连接器类型)
	CString strCabType;			// 电缆分支类型
	CString strCabSpoolName;	// 电缆线轴名称(分支类型 + "_" + 分支代号)

	CBPDynamicArray<CString> arrWireElem;		// 线径代号
	double dDiameter;			// 电缆直径
	double dDensity;			// 电缆线密度

	__tagIKSCableConnectOverallTabCableElem()
	{
		strCableName = L"";
		strConnRefDes1 = L"";
		strConnMdlName1 = L"";
		strConnRefDes2 = L"";
		strConnMdlName2 = L"";
		strCabType = L"";
		strCabSpoolName = L"";
		dDiameter = 0.0;
		dDensity = 0.0;
	}
	__tagIKSCableConnectOverallTabCableElem(const __tagIKSCableConnectOverallTabCableElem &info)
	{
		strCableName = info.strCableName;
		strConnRefDes1 = info.strConnRefDes1;
		strConnMdlName1 = info.strConnMdlName1;
		strConnRefDes2 = info.strConnRefDes2;
		strConnMdlName2 = info.strConnMdlName2;
		strCabType = info.strCabType;
		strCabSpoolName = info.strCabSpoolName;
		arrWireElem = info.arrWireElem;
		dDiameter = info.dDiameter;
		dDensity = info.dDensity;
	}
	__tagIKSCableConnectOverallTabCableElem& operator=(const __tagIKSCableConnectOverallTabCableElem &info)
	{
		if (&info == this)
			return *this;
		strCableName = info.strCableName;
		strConnRefDes1 = info.strConnRefDes1;
		strConnMdlName1 = info.strConnMdlName1;
		strConnRefDes2 = info.strConnRefDes2;
		strConnMdlName2 = info.strConnMdlName2;
		strCabType = info.strCabType;
		strCabSpoolName = info.strCabSpoolName;
		arrWireElem = info.arrWireElem;
		dDiameter = info.dDiameter;
		dDensity = info.dDensity;
		return *this;
	}
	void Clear()
	{
		strCableName = L"";
		strConnRefDes1 = L"";
		strConnMdlName1 = L"";
		strConnRefDes2 = L"";
		strConnMdlName2 = L"";
		strCabType = L"";
		strCabSpoolName = L"";
		arrWireElem.clear();
		dDiameter = 0.0;
		dDensity = 0.0;
	}
} IKSCableConnectOverallTabCableElem;

// 电缆连接关系综合表线束元素
typedef struct __tagIKSCableConnectOverallTabHarnElem
{
	CString strHarnessName;		// 线束名称(电缆代号)
	CBPDynamicArray<IKSCableConnectOverallTabCableElem> arrCableElem;

	__tagIKSCableConnectOverallTabHarnElem()
	{
		strHarnessName = L"";
	}
	__tagIKSCableConnectOverallTabHarnElem(const __tagIKSCableConnectOverallTabHarnElem &info)
	{
		strHarnessName = info.strHarnessName;
		arrCableElem = info.arrCableElem;
	}
	__tagIKSCableConnectOverallTabHarnElem& operator=(const __tagIKSCableConnectOverallTabHarnElem &info)
	{
		if (&info == this)
			return *this;
		strHarnessName = info.strHarnessName;
		arrCableElem = info.arrCableElem;
		return *this;
	}
	void Clear()
	{
		strHarnessName = L"";
		arrCableElem.clear();
	}
} IKSCableConnectOverallTabHarnElem;

// 电缆连接关系综合表
typedef struct __tagIKSCableConnectOverallTab
{
	CBPDynamicArray<IKSCableConnectOverallTabHarnElem> arrHarnElem;		// 线束数据信息
	CBPDynamicArray<IKSCableSpoolTabElem> arrCableSpoolTabElem;			// 线轴数据信息
	CBPDynamicArray<IKSWireSpoolTabElem> arrWireSpoolTabElem;			// 线径数据信息

	__tagIKSCableConnectOverallTab()
	{
	}
	__tagIKSCableConnectOverallTab(const __tagIKSCableConnectOverallTab &info)
	{
		arrHarnElem = info.arrHarnElem;
		arrCableSpoolTabElem = info.arrCableSpoolTabElem;
		arrWireSpoolTabElem = info.arrWireSpoolTabElem;
	}
	__tagIKSCableConnectOverallTab& operator=(const __tagIKSCableConnectOverallTab &info)
	{
		if (&info == this)
			return *this;
		arrHarnElem = info.arrHarnElem;
		arrCableSpoolTabElem = info.arrCableSpoolTabElem;
		arrWireSpoolTabElem = info.arrWireSpoolTabElem;
		return *this;
	}
	void Clear()
	{
		arrHarnElem.clear();
		arrCableSpoolTabElem.clear();
		arrWireSpoolTabElem.clear();
	}
} IKSCableConnectOverallTab;

// 电缆连接关系表选项
typedef struct __tagIKSCableConnectOverallTabConfig
{
	int nCableSheetIndex;
	int nCabSplSheetIndex;
	int nWireSplSheetIndex;

	int nCableStartRow;
	int nCableHarnNameCol;
	int nCableCabNameCol;
	int nCableRefDes1Col;
	int nCableMdlName1Col;
	int nCableRefDes2Col;
	int nCableMdlName2Col;
	int nCableTypeCol;
	int nCableWireCol;
	std::vector<CString> vecConnReplaceCharSrc;
	std::vector<CString> vecConnReplaceCharDst;

	int nCableBranchLenTabStartCol;
	int nCableBranchLenTabEndCol;
	int nCableBranchLenTabLengthCol;
	int nCableBranchLenTabDiameterCol;
	int nCableDiameterCol;
	int nCableHarnMassCol;

	IKSCableSpoolTabConfig stuCabSplConfig;
	IKSWireSpoolTabConfig stuWireSplConfig;

	__tagIKSCableConnectOverallTabConfig()
	{
		Clear();
	}
	__tagIKSCableConnectOverallTabConfig(const __tagIKSCableConnectOverallTabConfig &info)
	{
		nCableSheetIndex = info.nCableSheetIndex;
		nCabSplSheetIndex = info.nCabSplSheetIndex;
		nWireSplSheetIndex = info.nWireSplSheetIndex;
		nCableStartRow = info.nCableStartRow;
		nCableHarnNameCol = info.nCableHarnNameCol;
		nCableCabNameCol = info.nCableCabNameCol;
		nCableRefDes1Col = info.nCableRefDes1Col;
		nCableMdlName1Col = info.nCableMdlName1Col;
		nCableRefDes2Col = info.nCableRefDes2Col;
		nCableMdlName2Col = info.nCableMdlName2Col;
		nCableTypeCol = info.nCableTypeCol;
		nCableWireCol = info.nCableWireCol;
		vecConnReplaceCharSrc = info.vecConnReplaceCharSrc;
		vecConnReplaceCharDst = info.vecConnReplaceCharDst;
		nCableBranchLenTabStartCol = info.nCableBranchLenTabStartCol;
		nCableBranchLenTabEndCol = info.nCableBranchLenTabEndCol;
		nCableBranchLenTabLengthCol = info.nCableBranchLenTabLengthCol;
		nCableBranchLenTabDiameterCol = info.nCableBranchLenTabDiameterCol;
		nCableDiameterCol = info.nCableDiameterCol;
		nCableHarnMassCol = info.nCableHarnMassCol;
		stuCabSplConfig = info.stuCabSplConfig;
		stuWireSplConfig = info.stuWireSplConfig;
	}
	__tagIKSCableConnectOverallTabConfig& operator=(const __tagIKSCableConnectOverallTabConfig &info)
	{
		if (&info == this)
			return *this;
		nCableSheetIndex = info.nCableSheetIndex;
		nCabSplSheetIndex = info.nCabSplSheetIndex;
		nWireSplSheetIndex = info.nWireSplSheetIndex;
		nCableStartRow = info.nCableStartRow;
		nCableHarnNameCol = info.nCableHarnNameCol;
		nCableCabNameCol = info.nCableCabNameCol;
		nCableRefDes1Col = info.nCableRefDes1Col;
		nCableMdlName1Col = info.nCableMdlName1Col;
		nCableRefDes2Col = info.nCableRefDes2Col;
		nCableMdlName2Col = info.nCableMdlName2Col;
		nCableTypeCol = info.nCableTypeCol;
		nCableWireCol = info.nCableWireCol;
		vecConnReplaceCharSrc = info.vecConnReplaceCharSrc;
		vecConnReplaceCharDst = info.vecConnReplaceCharDst;
		nCableBranchLenTabStartCol = info.nCableBranchLenTabStartCol;
		nCableBranchLenTabEndCol = info.nCableBranchLenTabEndCol;
		nCableBranchLenTabLengthCol = info.nCableBranchLenTabLengthCol;
		nCableBranchLenTabDiameterCol = info.nCableBranchLenTabDiameterCol;
		nCableDiameterCol = info.nCableDiameterCol;
		nCableHarnMassCol = info.nCableHarnMassCol;
		stuCabSplConfig = info.stuCabSplConfig;
		stuWireSplConfig = info.stuWireSplConfig;
		return *this;
	}
	void Clear()
	{
		nCableSheetIndex = 1;
		nCabSplSheetIndex = 2;
		nWireSplSheetIndex = 3;
		nCableStartRow = 3;
		nCableHarnNameCol = 1;
		nCableCabNameCol = 3;
		nCableRefDes1Col = 4;
		nCableMdlName1Col = 5;
		nCableRefDes2Col = 6;
		nCableMdlName2Col = 7;
		nCableTypeCol = 8;
		nCableWireCol = 12;
		vecConnReplaceCharSrc.clear();
		vecConnReplaceCharDst.clear();
		nCableBranchLenTabStartCol = 20;
		nCableBranchLenTabEndCol = 21;
		nCableBranchLenTabLengthCol = 22;
		nCableBranchLenTabDiameterCol = 23;
		nCableDiameterCol = 24;
		nCableHarnMassCol = 25;
		stuCabSplConfig.Clear();
		stuWireSplConfig.Clear();
	}
} IKSCableConnectOverallTabConfig;

// 电缆分支长度表数据元素
typedef struct __tagIKSCableBranchLengthTabDataElem
{
	CSVWString strStart;		// 起点名称(此段电缆分支的起点)
	CSVWString strEnd;			// 终点名称(此段电缆分支的终点)
	double dLength;				// 长度(增加了余量的长度)
	double dCabMdlLength;		// 电缆模型长度(未加余量的长度)
	double dDiameter;			// 直径(此段电缆分支的直径)

	__tagIKSCableBranchLengthTabDataElem()
	{
		strStart = L"";
		strEnd = L"";
		dLength = 0.0;
		dCabMdlLength = 0.0;
		dDiameter = 0.0;
	}
	__tagIKSCableBranchLengthTabDataElem(const __tagIKSCableBranchLengthTabDataElem &info)
	{
		strStart = info.strStart;
		strEnd = info.strEnd;
		dLength = info.dLength;
		dCabMdlLength = info.dCabMdlLength;
		dDiameter = info.dDiameter;
	}
	__tagIKSCableBranchLengthTabDataElem& operator=(const __tagIKSCableBranchLengthTabDataElem &info)
	{
		if (&info == this)
			return *this;
		strStart = info.strStart;
		strEnd = info.strEnd;
		dLength = info.dLength;
		dCabMdlLength = info.dCabMdlLength;
		dDiameter = info.dDiameter;
		return *this;
	}
	void Clear()
	{
		strStart = L"";
		strEnd = L"";
		dLength = 0.0;
		dCabMdlLength = 0.0;
		dDiameter = 0.0;
	}
} IKSCableBranchLengthTabDataElem;

// 线束分支长度表数据元素
typedef struct __tagIKSHarnessBranchLengthTabDataElem
{
	CSVWString strHarnessName;		// 线束名称
	std::vector<IKSCableBranchLengthTabDataElem> vecCabBranchDataElem;	// 分支数据元素

	__tagIKSHarnessBranchLengthTabDataElem()
	{
		strHarnessName = _T("");
	}
	__tagIKSHarnessBranchLengthTabDataElem(const __tagIKSHarnessBranchLengthTabDataElem &info)
	{
		strHarnessName = info.strHarnessName;
		vecCabBranchDataElem = info.vecCabBranchDataElem;
	}
	__tagIKSHarnessBranchLengthTabDataElem& operator=(const __tagIKSHarnessBranchLengthTabDataElem &info)
	{
		if (&info == this)
			return *this;
		strHarnessName = info.strHarnessName;
		vecCabBranchDataElem = info.vecCabBranchDataElem;
		return *this;
	}
	void Clear()
	{
		strHarnessName = _T("");
		vecCabBranchDataElem.clear();
	}
} IKSHarnessBranchLengthTabDataElem;

// 电缆分支长度表
typedef struct __tagIKSHarnessBranchLengthTab
{
	std::vector<IKSHarnessBranchLengthTabDataElem> vecHarnBranchDataElem;	// 分支数据元素

	__tagIKSHarnessBranchLengthTab()
	{
	}
	__tagIKSHarnessBranchLengthTab(const __tagIKSHarnessBranchLengthTab &info)
	{
		vecHarnBranchDataElem = info.vecHarnBranchDataElem;
	}
	__tagIKSHarnessBranchLengthTab& operator=(const __tagIKSHarnessBranchLengthTab &info)
	{
		if (&info == this)
			return *this;
		vecHarnBranchDataElem = info.vecHarnBranchDataElem;
		return *this;
	}
	void Clear()
	{
		vecHarnBranchDataElem.clear();
	}
} IKSHarnessBranchLengthTab;

// 电缆生产长度表数据元素
typedef struct __tagIKSCableProductLengthTabDataElem
{
	CSVWString strCableName;			// 电缆名称(电缆分支名称)
	CSVWString strStartConnRefDes;		// 起始电连接器逻辑名称
	CSVWString strEndConnRefDes;		// 终止电连接器逻辑名称
	double dLength;						// 长度(增加了余量的长度)
	double dCabMdlLength;				// 电缆模型长度(未加余量的长度)
	double dDiameter;					// 直径
	double dMass;						// 质量

	__tagIKSCableProductLengthTabDataElem()
	{
		strCableName = L"";
		strStartConnRefDes = L"";
		strEndConnRefDes = L"";
		dLength = 0.0;
		dCabMdlLength = 0.0;
		dDiameter = 0.0;
		dMass = 0.0;
	}
	__tagIKSCableProductLengthTabDataElem(const __tagIKSCableProductLengthTabDataElem &info)
	{
		strCableName = info.strCableName;
		strStartConnRefDes = info.strStartConnRefDes;
		strEndConnRefDes = info.strEndConnRefDes;
		dLength = info.dLength;
		dCabMdlLength = info.dCabMdlLength;
		dDiameter = info.dDiameter;
		dMass = info.dMass;
	}
	__tagIKSCableProductLengthTabDataElem& operator=(const __tagIKSCableProductLengthTabDataElem &info)
	{
		if (&info == this)
			return *this;
		strCableName = info.strCableName;
		strStartConnRefDes = info.strStartConnRefDes;
		strEndConnRefDes = info.strEndConnRefDes;
		dLength = info.dLength;
		dCabMdlLength = info.dCabMdlLength;
		dDiameter = info.dDiameter;
		dMass = info.dMass;
		return *this;
	}
	void Clear()
	{
		strCableName = L"";
		strStartConnRefDes = L"";
		strEndConnRefDes = L"";
		dLength = 0.0;
		dCabMdlLength = 0.0;
		dDiameter = 0.0;
		dMass = 0.0;
	}
} IKSCableProductLengthTabDataElem;

// 线束生产长度表数据元素
typedef struct __tagIKSHarnessProductLengthTabDataElem
{
	CSVWString strHarnessName;		// 线束名称
	std::vector<IKSCableProductLengthTabDataElem> vecCableDataElem;	// 电缆数据元素

	double dCableMass;				// 电缆质量
	double dHarnessMass;			// 线束质量(电缆质量+相关电连接器质量)

	__tagIKSHarnessProductLengthTabDataElem()
	{
		strHarnessName = _T("");
		dCableMass = 0.0;
		dHarnessMass = 0.0;
	}
	__tagIKSHarnessProductLengthTabDataElem(const __tagIKSHarnessProductLengthTabDataElem &info)
	{
		strHarnessName = info.strHarnessName;
		vecCableDataElem = info.vecCableDataElem;
		dCableMass = info.dCableMass;
		dHarnessMass = info.dHarnessMass;
	}
	__tagIKSHarnessProductLengthTabDataElem& operator=(const __tagIKSHarnessProductLengthTabDataElem &info)
	{
		if (&info == this)
			return *this;
		strHarnessName = info.strHarnessName;
		vecCableDataElem = info.vecCableDataElem;
		dCableMass = info.dCableMass;
		dHarnessMass = info.dHarnessMass;
		return *this;
	}
	void Clear()
	{
		strHarnessName = _T("");
		vecCableDataElem.clear();
		dCableMass = 0.0;
		dHarnessMass = 0.0;
	}
} IKSHarnessProductLengthTabDataElem;

// 线束生产长度表
typedef struct __tagIKSHarnessProductLengthTab
{
	std::vector<IKSHarnessProductLengthTabDataElem> vecHarnDataElem;	// 线束数据元素

	__tagIKSHarnessProductLengthTab()
	{
	}
	__tagIKSHarnessProductLengthTab(const __tagIKSHarnessProductLengthTab &info)
	{
		vecHarnDataElem = info.vecHarnDataElem;
	}
	__tagIKSHarnessProductLengthTab& operator=(const __tagIKSHarnessProductLengthTab &info)
	{
		if (&info == this)
			return *this;
		vecHarnDataElem = info.vecHarnDataElem;
		return *this;
	}
	void Clear()
	{
		vecHarnDataElem.clear();
	}
} IKSHarnessProductLengthTab;

// 检查电缆连接关系结果元素
typedef struct __tagIKSCheckCableConnectInfResultElem
{
	int nResult;					// 检查结果(参看枚举型IKSCABLECONNINFCHECKRESULT)
	const IKSHarness* pHarness;		// 电缆所在Harness数据指针(临时数据)
	const IKSCable* pCable;			// 电缆数据指针(临时数据)

	__tagIKSCheckCableConnectInfResultElem()
	{
		nResult = IKSCABCONNCHKR_OK;
		pHarness = NULL;
		pCable = NULL;
	}
	__tagIKSCheckCableConnectInfResultElem(const __tagIKSCheckCableConnectInfResultElem &info)
	{
		nResult = info.nResult;
		pHarness = info.pHarness;
		pCable = info.pCable;
	}
	__tagIKSCheckCableConnectInfResultElem& operator=(const __tagIKSCheckCableConnectInfResultElem &info)
	{
		if (&info == this)
			return *this;
		nResult = info.nResult;
		pHarness = info.pHarness;
		pCable = info.pCable;
		return *this;
	}
	void Clear()
	{
		nResult = IKSCABCONNCHKR_OK;
		pHarness = NULL;
		pCable = NULL;
	}
} IKSCheckCableConnectInfResultElem;

// 检查电缆连接关系电连接器
typedef struct __tagIKSCheckCableConInfConnector
{
	CUnicodeString strConnRefDes;		// 电连接器的逻辑描述
	CUnicodeString strConnMdlName;		// 电连接器的模型名称
	std::vector<CUnicodeString> vecCableName;	// 电连接器相关的电缆名称(对于起始终止是相同电连接器的电缆,会被记录两遍)

	const IKSConnector* pConnector;		// 电连接器数据指针(临时数据)
	int nResult;						// 检查结果(参看枚举型IKSCABLECONNINFCHECKRESULT)
	ProSelection pConstrainCsys;		// 装配坐标系

	__tagIKSCheckCableConInfConnector()
	{
		strConnRefDes = L"";
		strConnMdlName = L"";
		pConnector = NULL;
		nResult = IKSCABCONNCHKR_OK;
		pConstrainCsys = NULL;
	}
	__tagIKSCheckCableConInfConnector(const __tagIKSCheckCableConInfConnector &info)
	{
		strConnRefDes = info.strConnRefDes;
		strConnMdlName = info.strConnMdlName;
		vecCableName = info.vecCableName;
		pConnector = info.pConnector;
		nResult = info.nResult;
		pConstrainCsys = info.pConstrainCsys;
	}
	__tagIKSCheckCableConInfConnector& operator=(const __tagIKSCheckCableConInfConnector &info)
	{
		if (&info == this)
			return *this;
		strConnRefDes = info.strConnRefDes;
		strConnMdlName = info.strConnMdlName;
		vecCableName = info.vecCableName;
		pConnector = info.pConnector;
		nResult = info.nResult;
		pConstrainCsys = info.pConstrainCsys;
		return *this;
	}
	void Clear()
	{
		strConnRefDes = L"";
		strConnMdlName = L"";
		vecCableName.clear();
		pConnector = NULL;
		nResult = IKSCABCONNCHKR_OK;
		pConstrainCsys = NULL;
	}
} IKSCheckCableConInfConnector;

// 检查电缆完整性结果元素
typedef struct __tagIKSCheckCableCompleteResultElem
{
	const IKSHarness* pHarness;			// 电缆所在Harness数据指针(临时数据)
	const IKSCable* pCable;				// 电缆数据指针(临时数据)

	const CABModelNodeData *pParentAsm;	// 逻辑参照中未创建电缆所在的装配体
	CSVWString strLogicalCableName;		// 未创建的电缆名称

	__tagIKSCheckCableCompleteResultElem()
	{
		pHarness = NULL;
		pCable = NULL;
		pParentAsm = NULL;
		strLogicalCableName = L"";
	}
	__tagIKSCheckCableCompleteResultElem(const __tagIKSCheckCableCompleteResultElem &info)
	{
		pHarness = info.pHarness;
		pCable = info.pCable;
		pParentAsm = info.pParentAsm;
		strLogicalCableName = info.strLogicalCableName;
	}
	__tagIKSCheckCableCompleteResultElem& operator=(const __tagIKSCheckCableCompleteResultElem &info)
	{
		if (&info == this)
			return *this;
		pHarness = info.pHarness;
		pCable = info.pCable;
		pParentAsm = info.pParentAsm;
		strLogicalCableName = info.strLogicalCableName;
		return *this;
	}
	void Clear()
	{
		pHarness = NULL;
		pCable = NULL;
		pParentAsm = NULL;
		strLogicalCableName = L"";
	}
} IKSCheckCableCompleteResultElem;

// 检查电连接器电缆综合直径结果元素
typedef struct __tagIKSCheckConnWhlCabDiaResultElem
{
	const IKSConnector* pConnector;					// 电连接器数据指针(临时数据)
	CBPDynamicArray<const IKSCable*> arrConnCable;	// 电连接器相关的电缆(临时数据)(对于起始终止是相同电连接器的电缆,会被记录两遍)
	double dConnWhlCabDia;							// 电缆综合直径

	__tagIKSCheckConnWhlCabDiaResultElem()
	{
		pConnector = NULL;
		dConnWhlCabDia = 0.0;
	}
	__tagIKSCheckConnWhlCabDiaResultElem(const __tagIKSCheckConnWhlCabDiaResultElem &info)
	{
		pConnector = info.pConnector;
		arrConnCable = info.arrConnCable;
		dConnWhlCabDia = info.dConnWhlCabDia;
	}
	__tagIKSCheckConnWhlCabDiaResultElem& operator=(const __tagIKSCheckConnWhlCabDiaResultElem &info)
	{
		if (&info == this)
			return *this;
		pConnector = info.pConnector;
		arrConnCable = info.arrConnCable;
		dConnWhlCabDia = info.dConnWhlCabDia;
		return *this;
	}
	void Clear()
	{
		pConnector = NULL;
		arrConnCable.clear();
		dConnWhlCabDia = 0.0;
	}
} IKSCheckConnWhlCabDiaResultElem;

// 检查线束封闭环路结果元素
typedef struct __tagIKSCheckHarnessClosePathResultElem
{
	const IKSHarness* pHarness;							// 线束Harness数据指针(临时数据)
	std::vector<const IKSCable*> arrClosePathCable;		// 导致封闭环路的电缆数据指针(临时数据)(修正这些电缆的布线可消除封闭环路)
	std::vector<BPBASEUINT2> arrCableClosePathStartEndLocID;	// 电缆封闭环路的起始终止电缆位置的特征ID
	CBPDynamicArray<CBPDynamicArray<UINT>> arrClosePathCableAllLocFeatID;	// 含有封闭环路的电缆的所有电缆位置的特征ID

	__tagIKSCheckHarnessClosePathResultElem()
	{
		pHarness = NULL;
	}
	__tagIKSCheckHarnessClosePathResultElem(const __tagIKSCheckHarnessClosePathResultElem &info)
	{
		pHarness = info.pHarness;
		arrClosePathCable = info.arrClosePathCable;
		arrCableClosePathStartEndLocID = info.arrCableClosePathStartEndLocID;
		arrClosePathCableAllLocFeatID = info.arrClosePathCableAllLocFeatID;
	}
	__tagIKSCheckHarnessClosePathResultElem& operator=(const __tagIKSCheckHarnessClosePathResultElem &info)
	{
		if (&info == this)
			return *this;
		pHarness = info.pHarness;
		arrClosePathCable = info.arrClosePathCable;
		arrCableClosePathStartEndLocID = info.arrCableClosePathStartEndLocID;
		arrClosePathCableAllLocFeatID = info.arrClosePathCableAllLocFeatID;
		return *this;
	}
	void Clear()
	{
		pHarness = NULL;
		arrClosePathCable.clear();
		arrCableClosePathStartEndLocID.clear();
		arrClosePathCableAllLocFeatID.clear();
	}
} IKSCheckHarnessClosePathResultElem;

// 孔容量检查的孔信息
typedef struct __tagChkHoleCapHoleInfo
{
	int nID;							// ID
	double dRefDiameter;				// 参考直径
	SVBASEDOUBLE3 vCenterPos;			// 孔中心点坐标
	SVBASEDOUBLE3 vCenterAxis;			// 孔中心点轴方向
	int nHoleSecShapeType;					// 孔横截面形状类型,参看枚举型IKSCABHOLESECSHAPETYPE
	std::vector<IKSCABDCurve> vecSecShape;		// 孔横截面形状(轮廓)

	__tagChkHoleCapHoleInfo()
	{
		nID = -1;
		dRefDiameter = 0.0;
		memset(&vCenterPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vCenterAxis, 0, sizeof(SVBASEDOUBLE3));
		vCenterAxis.z = 1.0;
		nHoleSecShapeType = IKSCABHSSTYPE_INVALID;
	}
	__tagChkHoleCapHoleInfo(const __tagChkHoleCapHoleInfo &info)
	{
		nID = info.nID;
		dRefDiameter = info.dRefDiameter;
		vCenterPos = info.vCenterPos;
		vCenterAxis = info.vCenterAxis;
		nHoleSecShapeType = info.nHoleSecShapeType;
		vecSecShape = info.vecSecShape;
	}
	__tagChkHoleCapHoleInfo& operator=(const __tagChkHoleCapHoleInfo &info)
	{
		if (&info == this)
			return *this;
		nID = info.nID;
		dRefDiameter = info.dRefDiameter;
		vCenterPos = info.vCenterPos;
		vCenterAxis = info.vCenterAxis;
		nHoleSecShapeType = info.nHoleSecShapeType;
		vecSecShape = info.vecSecShape;
		return *this;
	}
	void Clear()
	{
		nID = -1;
		dRefDiameter = 0.0;
		memset(&vCenterPos, 0, sizeof(SVBASEDOUBLE3));
		memset(&vCenterAxis, 0, sizeof(SVBASEDOUBLE3));
		vCenterAxis.z = 1.0;
		nHoleSecShapeType = IKSCABHSSTYPE_INVALID;
		vecSecShape.clear();
	}
} ChkHoleCapHoleInfo;

// 批量孔容量检查的孔坐标系信息
typedef struct __tagChkBatchHoleCapHoleCsysInfo
{
	ProModelitem stuHole;				// 孔的ProE数据
	CSVWString strHoleName;				// 孔名称
	double dHoleRefDiameter;			// 孔参考直径
	double dCableDiameterMax;			// 电缆综合直径上限
	double dCableDiameter;				// 电缆综合直径

	__tagChkBatchHoleCapHoleCsysInfo()
	{
		stuHole.owner = NULL;
		stuHole.id = -1;
		strHoleName = L"";
		dHoleRefDiameter = 0.0;
		dCableDiameterMax = 0.0;
		dCableDiameter = 0.0;
	}
	__tagChkBatchHoleCapHoleCsysInfo(const __tagChkBatchHoleCapHoleCsysInfo &info)
	{
		stuHole = info.stuHole;
		strHoleName = info.strHoleName;
		dHoleRefDiameter = info.dHoleRefDiameter;
		dCableDiameterMax = info.dCableDiameterMax;
		dCableDiameter = info.dCableDiameter;
	}
	__tagChkBatchHoleCapHoleCsysInfo& operator=(const __tagChkBatchHoleCapHoleCsysInfo &info)
	{
		if (&info == this)
			return *this;
		stuHole = info.stuHole;
		strHoleName = info.strHoleName;
		dHoleRefDiameter = info.dHoleRefDiameter;
		dCableDiameterMax = info.dCableDiameterMax;
		dCableDiameter = info.dCableDiameter;
		return *this;
	}
	void Clear()
	{
		stuHole.owner = NULL;
		stuHole.id = -1;
		strHoleName = L"";
		dHoleRefDiameter = 0.0;
		dCableDiameterMax = 0.0;
		dCableDiameter = 0.0;
	}
} ChkBatchHoleCapHoleCsysInfo;

// 孔容量检查的孔及线束信息
typedef struct __tagChkHoleCapHoleHarnessInfo
{
	ChkHoleCapHoleInfo hole;					// 孔信息
	ChkBatchHoleCapHoleCsysInfo stuBatchHole;	// 批量孔信息
	std::vector<IKSHarness> vecHarnessThrHole;	// 穿过孔的线束

	__tagChkHoleCapHoleHarnessInfo()
	{
	}
	__tagChkHoleCapHoleHarnessInfo(const __tagChkHoleCapHoleHarnessInfo &info)
	{
		hole = info.hole;
		stuBatchHole = info.stuBatchHole;
		vecHarnessThrHole = info.vecHarnessThrHole;
	}
	__tagChkHoleCapHoleHarnessInfo& operator=(const __tagChkHoleCapHoleHarnessInfo &info)
	{
		if (&info == this)
			return *this;
		hole = info.hole;
		stuBatchHole = info.stuBatchHole;
		vecHarnessThrHole = info.vecHarnessThrHole;
		return *this;
	}
	void Clear()
	{
		hole.Clear();
		stuBatchHole.Clear();
		vecHarnessThrHole.clear();
	}
} ChkHoleCapHoleHarnessInfo;

// 孔容量检查的配置信息
typedef struct __tagChkHoleCapConfig
{
	int nCheckMode;								// 检查模式,参看枚举型IKSCHECKHOLECAPACITYMODE
	double dCheckCableAreaRatio;				// 缆面积系数(百分比)
	double dCheckHoleAreaSurplus;				// 孔余量(百分比)

	__tagChkHoleCapConfig()
	{
		nCheckMode = IKSCHKHOLECAPMODE_INVALID;
		dCheckCableAreaRatio = 1.0;
		dCheckHoleAreaSurplus = 0.0;
	}
	__tagChkHoleCapConfig(const __tagChkHoleCapConfig &info)
	{
		nCheckMode = info.nCheckMode;
		dCheckCableAreaRatio = info.dCheckCableAreaRatio;
		dCheckHoleAreaSurplus = info.dCheckHoleAreaSurplus;
	}
	__tagChkHoleCapConfig& operator=(const __tagChkHoleCapConfig &info)
	{
		if (&info == this)
			return *this;
		nCheckMode = info.nCheckMode;
		dCheckCableAreaRatio = info.dCheckCableAreaRatio;
		dCheckHoleAreaSurplus = info.dCheckHoleAreaSurplus;
		return *this;
	}
} ChkHoleCapConfig;

// 孔容量检查的结果信息
typedef struct __tagChkHoleCapResult
{
	BOOL bIsHoleCapOK;							// 孔容量满足电缆的通过要求

	double dHoleArea;							// 孔的实际面积
	double dHarnessTotalRefArea;				// 线束总参考面积
	double dHoleAreaUseRatio;					// 孔利用率(百分比)

	__tagChkHoleCapResult()
	{
		bIsHoleCapOK = FALSE;
		dHoleArea = 0.0;
		dHarnessTotalRefArea = 0.0;
		dHoleAreaUseRatio = 0.0;
	}
	__tagChkHoleCapResult(const __tagChkHoleCapResult &info)
	{
		bIsHoleCapOK = info.bIsHoleCapOK;
		dHoleArea = info.dHoleArea;
		dHarnessTotalRefArea = info.dHarnessTotalRefArea;
		dHoleAreaUseRatio = info.dHoleAreaUseRatio;
	}
	__tagChkHoleCapResult& operator=(const __tagChkHoleCapResult &info)
	{
		if (&info == this)
			return *this;
		bIsHoleCapOK = info.bIsHoleCapOK;
		dHoleArea = info.dHoleArea;
		dHarnessTotalRefArea = info.dHarnessTotalRefArea;
		dHoleAreaUseRatio = info.dHoleAreaUseRatio;
		return *this;
	}
	void Clear()
	{
		bIsHoleCapOK = FALSE;
		dHoleArea = 0.0;
		dHarnessTotalRefArea = 0.0;
		dHoleAreaUseRatio = 0.0;
	}
} ChkHoleCapResult;

// 影响域检查电缆分析结果
typedef struct __tagIKSCheckInfluenceCableAnalysisResult
{
	const IKSCable* pCable;								// 电缆的数据指针
	double dRefLength;									// 电缆的总参考长度
	double dDiffRefLength;								// 不相同路径的电缆参考长度
	std::vector<UINT> arrDiffCableLocIndexPair;			// 不相同路径的电缆位置索引对(IKSCable::vecCabLoc对应索引,两两成对)

	__tagIKSCheckInfluenceCableAnalysisResult()
	{
		pCable = NULL;
		dRefLength = 0.0;
		dDiffRefLength = 0.0;
	}
	__tagIKSCheckInfluenceCableAnalysisResult(const __tagIKSCheckInfluenceCableAnalysisResult &info)
	{
		pCable = info.pCable;
		dRefLength = info.dRefLength;
		dDiffRefLength = info.dDiffRefLength;
		arrDiffCableLocIndexPair = info.arrDiffCableLocIndexPair;
	}
	__tagIKSCheckInfluenceCableAnalysisResult& operator=(const __tagIKSCheckInfluenceCableAnalysisResult &info)
	{
		if (&info == this)
			return *this;
		pCable = info.pCable;
		dRefLength = info.dRefLength;
		dDiffRefLength = info.dDiffRefLength;
		arrDiffCableLocIndexPair = info.arrDiffCableLocIndexPair;
		return *this;
	}
	void Clear()
	{
		pCable = NULL;
		dRefLength = 0.0;
		dDiffRefLength = 0.0;
		arrDiffCableLocIndexPair.clear();
	}
} IKSCheckInfluenceCableAnalysisResult;

// 影响域检查线束分析结果
typedef struct __tagIKSCheckInfluenceHarnessAnalysisResult
{
	const IKSHarness* pHarness;							// 线束的数据指针
	double dRefLength;									// 线束的总参考长度
	double dDiffRefLength;								// 不相同路径的电缆参考长度
	std::vector<IKSCheckInfluenceCableAnalysisResult> arrCableAnalysisRet;			// 电缆分析结果

	__tagIKSCheckInfluenceHarnessAnalysisResult()
	{
		pHarness = NULL;
		dRefLength = 0.0;
		dDiffRefLength = 0.0;
	}
	__tagIKSCheckInfluenceHarnessAnalysisResult(const __tagIKSCheckInfluenceHarnessAnalysisResult &info)
	{
		pHarness = info.pHarness;
		dRefLength = info.dRefLength;
		dDiffRefLength = info.dDiffRefLength;
		arrCableAnalysisRet = info.arrCableAnalysisRet;
	}
	__tagIKSCheckInfluenceHarnessAnalysisResult& operator=(const __tagIKSCheckInfluenceHarnessAnalysisResult &info)
	{
		if (&info == this)
			return *this;
		pHarness = info.pHarness;
		dRefLength = info.dRefLength;
		dDiffRefLength = info.dDiffRefLength;
		arrCableAnalysisRet = info.arrCableAnalysisRet;
		return *this;
	}
	void Clear()
	{
		pHarness = NULL;
		dRefLength = 0.0;
		dDiffRefLength = 0.0;
		arrCableAnalysisRet.clear();
	}
} IKSCheckInfluenceHarnessAnalysisResult;

// 电缆类型检查电缆元素
typedef struct __tagIKSCheckCableTypeCabElem
{
	CSVWString strCabType;								// 电缆类型
	const IKSCable* pCable;								// 电缆的数据指针
	const IKSHarness* pHarness;							// 线束的数据指针

	__tagIKSCheckCableTypeCabElem()
	{
		strCabType = L"";
		pCable = NULL;
		pHarness = NULL;
	}
	__tagIKSCheckCableTypeCabElem(const __tagIKSCheckCableTypeCabElem &info)
	{
		strCabType = info.strCabType;
		pCable = info.pCable;
		pHarness = info.pHarness;
	}
	__tagIKSCheckCableTypeCabElem& operator=(const __tagIKSCheckCableTypeCabElem &info)
	{
		if (&info == this)
			return *this;
		strCabType = info.strCabType;
		pCable = info.pCable;
		pHarness = info.pHarness;
		return *this;
	}
	void Clear()
	{
		strCabType = L"";
		pCable = NULL;
		pHarness = NULL;
	}
} IKSCheckCableTypeCabElem;

// 电缆类型检查电缆组
typedef struct __tagIKSCheckCableTypeCabGroup
{
	CSVWString strCabType;								// 电缆类型
	std::vector<IKSCheckCableTypeCabElem> arrCable;		// 电缆

	__tagIKSCheckCableTypeCabGroup()
	{
		strCabType = L"";
	}
	__tagIKSCheckCableTypeCabGroup(const __tagIKSCheckCableTypeCabGroup &info)
	{
		strCabType = info.strCabType;
		arrCable = info.arrCable;
	}
	__tagIKSCheckCableTypeCabGroup& operator=(const __tagIKSCheckCableTypeCabGroup &info)
	{
		if (&info == this)
			return *this;
		strCabType = info.strCabType;
		arrCable = info.arrCable;
		return *this;
	}
	void Clear()
	{
		strCabType = L"";
		arrCable.clear();
	}
} IKSCheckCableTypeCabGroup;

// 电缆类型检查结果元素
typedef struct __tagIKSCheckCableTypeResultElem
{
	IKSCheckCableTypeCabElem stuCableElem1;				// 第一根电缆元素
	IKSCheckCableTypeCabElem stuCableElem2;				// 第二根电缆元素
	double dSimilarPercent;								// 相似度百分比

	__tagIKSCheckCableTypeResultElem()
	{
		dSimilarPercent = 0.0;
	}
	__tagIKSCheckCableTypeResultElem(const __tagIKSCheckCableTypeResultElem &info)
	{
		stuCableElem1 = info.stuCableElem1;
		stuCableElem2 = info.stuCableElem2;
		dSimilarPercent = info.dSimilarPercent;
	}
	__tagIKSCheckCableTypeResultElem& operator=(const __tagIKSCheckCableTypeResultElem &info)
	{
		if (&info == this)
			return *this;
		stuCableElem1 = info.stuCableElem1;
		stuCableElem2 = info.stuCableElem2;
		dSimilarPercent = info.dSimilarPercent;
		return *this;
	}
	void Clear()
	{
		stuCableElem1.Clear();
		stuCableElem2.Clear();
		dSimilarPercent = 0.0;
	}
} IKSCheckCableTypeResultElem;

// 电连接器装配的配置信息
typedef struct __tagConnectorAsmConfig
{
	std::vector<CString> vecConnLibPath;	// 电连接器存储库路径
	CString strConnMdlAsmCSysName;			// 电连接器模型装配坐标系

	__tagConnectorAsmConfig()
	{
		strConnMdlAsmCSysName = _T("");
	}
	__tagConnectorAsmConfig(const __tagConnectorAsmConfig &info)
	{
		vecConnLibPath = info.vecConnLibPath;
		strConnMdlAsmCSysName = info.strConnMdlAsmCSysName;
	}
	__tagConnectorAsmConfig& operator=(const __tagConnectorAsmConfig &info)
	{
		if (&info == this)
			return *this;
		vecConnLibPath = info.vecConnLibPath;
		strConnMdlAsmCSysName = info.strConnMdlAsmCSysName;
		return *this;
	}
	void Clear()
	{
		vecConnLibPath.clear();
		strConnMdlAsmCSysName = _T("");
	}
} ConnectorAsmConfig;

//===================================================================================================

