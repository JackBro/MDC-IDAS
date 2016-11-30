//===================================================================================================
// File:
//		SVSceneDef.h
// Summary:
//		Define scene class/struct, enum, macro and so on.
// Usage:
//		定义场景所需的数据；用于场景模块、存储模块等。
// Remarks:
//		Null
// Date:
//		
// Author:
//		Shiping Wang
//===================================================================================================

#pragma once

//===================================================================================================
// 头文件
#include <vector>
#include "SVPublicDef.h"
#include "SVGeomDef.h"
#include "SVAnnotationDef.h"

//===================================================================================================
// 数学常量


//===================================================================================================
// 宏定义


//===================================================================================================
// 枚举类型定义

// 关键帧类型
typedef enum _BPKEYFRAMETYPE
{
	BPKFT_UNKNOWN		= 0,
// 	BPKFT_MATRIX		= 1,			// 矩阵(已废弃)
// 	BPKFT_SCALE			= 2,			// 缩放(已废弃)
// 	BPKFT_ROTATIONX		= 3,			// X轴旋转(已废弃)
// 	BPKFT_ROTATIONY		= 4,			// Y轴旋转(已废弃)
// 	BPKFT_ROTATIONZ		= 5,			// Z轴旋转(已废弃)
	BPKFT_ROTATION		= 6,			// 自由旋转
	BPKFT_TRANSLATION	= 7,			// 平移
} BPKEYFRAMETYPE;

// 时间节点类型
typedef enum _BPSCENETIMENODETYPE
{
	BPSTNT_NULL				= 0,	// 无效类
	BPSTNT_BASE				= 1,	// 基类
	BPSTNT_WORKSTAGE		= 2,	// 工序
	BPSTNT_WORKSTEP			= 3,	// 工步
} BPSCENETIMENODETYPE;

// 参数类型
typedef enum _BPPARAMETERTYPE
{
	BPPARAMTYPE_UNKOWN			= 0,	// 未知类型
	BPPARAMTYPE_INT				= 1,	// 整数类型
	BPPARAMTYPE_FLOAT			= 2,	// 单精度浮点类型
	BPPARAMTYPE_DOUBLE			= 3,	// 双精度浮点类型
	BPPARAMTYPE_STRING			= 4,	// 字符串类型
	BPPARAMTYPE_FLOAT3			= 5,	// 三个单精度浮点类型
	BPPARAMTYPE_DOUBLE3			= 6,	// 三个双精度浮点类型
	BPPARAMTYPE_BOOL			= 7,	// 布尔类型
} BPPARAMETERTYPE;

// 参数过滤器操作类型
typedef enum _SVPARAMFILTEROPERTYPE
{
	SVPFOTYPE_UNKOWN				= 0,	// 未知类型
	SVPFOTYPE_EXIST					= 1,	// 参数存在
	SVPFOTYPE_NOTEXIST				= 2,	// 参数不存在
	SVPFOTYPE_EQUAL_STRING			= 3,	// 参数的字符串数值等于
	SVPFOTYPE_NOTEQUAL_STRING		= 4,	// 参数的字符串数值不等于
	SVPFOTYPE_INCLUDE_STRING		= 5,	// 参数的字符串数值包含
	SVPFOTYPE_NOTINCLUDE_STRING		= 6,	// 参数的字符串数值不包含
	SVPFOTYPE_EQUAL_DOUBLE			= 7,	// 参数的实数数值等于
	SVPFOTYPE_NOTEQUAL_DOUBLE		= 8,	// 参数的实数数值不等于
	SVPFOTYPE_GREATER_DOUBLE		= 9,	// 参数的实数数值大于
	SVPFOTYPE_GREATEREQUAL_DOUBLE	= 10,	// 参数的实数数值大于等于
	SVPFOTYPE_LESS_DOUBLE			= 11,	// 参数的实数数值小于
	SVPFOTYPE_LESSEQUAL_DOUBLE		= 12,	// 参数的实数数值小于等于
	SVPFOTYPE_EQUALSTRINGLENGTH		= 13,	// 参数的字符串数值长度等于
	SVPFOTYPE_FINDSTRINGAT			= 14,	// 参数的字符串数值在第i个位置出现指定字符串;输入格式:XXX,i(i=1,2,...)
} SVPARAMFILTEROPERTYPE;

// 长度单位类型
typedef enum _BPLENGTHUNITTYPE
{
	BPLENUNITTYPE_UNKOWN			= 0,	// 未知类型
	BPLENUNITTYPE_MM				= 1,	// 毫米
	BPLENUNITTYPE_CM				= 2,	// 厘米(1cm=10mm)
	BPLENUNITTYPE_M					= 3,	// 米(1m=1000mm)
	BPLENUNITTYPE_MICRON			= 4,	// 微米(1micron=0.001mm)
	BPLENUNITTYPE_FT				= 5,	// 英尺(1ft=304.8mm)
	BPLENUNITTYPE_IN				= 6,	// 英寸(1in=25.4mm)
	BPLENUNITTYPE_MIL				= 7,	// 千分之一英寸(1mil=0.0254mm)
	BPLENUNITTYPE_ANGSTROM			= 8,	// 埃(1Angstrom=0.0000001mm)
	BPLENUNITTYPE_NANOMETER			= 9,	// 纳米(1Nanometer=0.000001mm)
} BPLENGTHUNITTYPE;

// 质量单位类型
typedef enum _BPMASSUNITTYPE
{
	BPMASSUNITTYPE_UNKOWN			= 0,	// 未知类型
	BPMASSUNITTYPE_KG				= 1,	// 千克
	BPMASSUNITTYPE_G				= 2,	// 克(1g=0.001kg)
	BPMASSUNITTYPE_MG				= 3,	// 毫克(1mg=0.000001kg)
	BPMASSUNITTYPE_LBM				= 4,	// 磅(1lbm=0.4536kg)
	BPMASSUNITTYPE_OUNCE_M			= 5,	// 盎司(1ouncem=0.02835kg)
	BPMASSUNITTYPE_SLUG				= 6,	// 斯勒格(1slug=14.5939kg)
	BPMASSUNITTYPE_TON_M			= 7,	// 短吨(1tonm=907.18474kg)
	BPMASSUNITTYPE_TONNE			= 8,	// 吨(1tonne=1000kg)
} BPMASSUNITTYPE;

// 时间单位类型
typedef enum _BPTIMEUNITTYPE
{
	BPTIMEUNITTYPE_UNKOWN			= 0,	// 未知类型
	BPTIMEUNITTYPE_SEC				= 1,	// 秒
	BPTIMEUNITTYPE_MSEC				= 2,	// 毫秒(1msec=0.001sec)
	BPTIMEUNITTYPE_MICRO_SEC		= 3,	// 微妙(1microsec=0.000001sec)
	BPTIMEUNITTYPE_MIN				= 4,	// 分钟(1min=60sec)
	BPTIMEUNITTYPE_HR				= 5,	// 小时(1hr=3600sec)
	BPTIMEUNITTYPE_DAY				= 6,	// 天(1day=86400sec)
	BPTIMEUNITTYPE_WEEK				= 7,	// 周(1week=604800sec)
	BPTIMEUNITTYPE_NANOSECOND		= 8,	// 纳秒(1Nanosecond=0.000000001sec)
} BPTIMEUNITTYPE;

// 角度单位类型
typedef enum _BPANGLEUNITTYPE
{
	BPANGUNITTYPE_UNKOWN			= 0,	// 未知类型
	BPANGUNITTYPE_DEGREE			= 1,	// 角度
	BPANGUNITTYPE_RADIAN			= 2,	// 弧度
} BPANGLEUNITTYPE;

// 场景物件子类型
typedef enum _BPSCENEOBJECTSUBTYPE
{
	BPSCENEOBJSUBTYPE_UNKOWN		= 0,	// 未知类型
	BPSCENEOBJSUBTYPE_GENERAL		= 1,	// 普通物件
	BPSCENEOBJSUBTYPE_HARNESS		= 2,	// 线束物件
	BPSCENEOBJSUBTYPE_CABLE			= 3,	// 线缆物件
} BPSCENEOBJECTSUBTYPE;

// 场景导入的模型合并模式
typedef enum _BPSCENEIMPORTMODELMERGEMODE
{
// 	BPSIMDLMERGEMODE_UNKOWN						= 0,	// 未知模式
	BPSIMDLMERGEMODE_NOMERGE					= 1,	// 不合并相同模型
	BPSIMDLMERGEMODE_SAMEOBJIDSAMEMDL			= 2,	// 根据模型ID合并相同的模型(相同物件ID和相同模型数据(模型文件名称重名且数据相同)的判定为相同模型)
	BPSIMDLMERGEMODE_SAMEMDLTREENODENAMEPOS		= 3,	// 根据模型树合并相同的模型(相同模型树节点名称和位置的判定为相同模型)
	BPSIMDLMERGEMODE_SAMEORIMDLTREENODEID		= 4,	// 根据模型原始标识合并相同的模型(相同模型树节点原始ID的判定为相同模型)
} BPSCENEIMPORTMODELMERGEMODE;

//===================================================================================================
// 结构体定义

// 关键帧参数数据_自由旋转
typedef struct _KEYFRAMEROTATION {
	BPBASEFLOAT3 _vOrigin;
	BPBASEFLOAT3 _vAxis;
	float _fRotValue;
} KEYFRAMEROTATION;

// // 关键帧元素
// typedef struct _KEYFRAMEELEMENT {
// 	IKS_UINT _uFrameID;									// 帧号
// 
// 	union {
// 		BPBASEMATRIX			_matrix;			// 综合矩阵
// 		BPBASEFLOAT3			_vScale;			// 缩放
// 		float					_fRotX;				// X轴旋转
// 		float					_fRotY;				// Y轴旋转
// 		float					_fRotZ;				// Z轴旋转
// 		KEYFRAMEROTATION		_rotation;			// 自由旋转
// 		BPBASEFLOAT3			_vTranslation;		// 平移
// 	};
// } KEYFRAMEELEMENT;
// 
// // 关键帧数据
// typedef struct _KEYFRAMEDATA {
// 	IKS_UINT _uStartFrameID;						// 起始帧号
// 	BPKEYFRAMETYPE _eType;						// 关键帧类型
// 	std::vector<KEYFRAMEELEMENT> _arrElements;	// 关键帧元素组(每个元素描述了当前种类变换的关键帧数据)
// 
// 	_KEYFRAMEDATA()
// 	{
// 		_uStartFrameID = 0;
// 	}
// } KEYFRAMEDATA;

// 关键帧参数
typedef struct _BPKEYPARAMETER {
	BPKEYFRAMETYPE _eType;							// 类型
	union {
// 		BPBASEFLOAT3			_vScale;			// 缩放
// 		float					_fRotX;				// X轴旋转
// 		float					_fRotY;				// Y轴旋转
// 		float					_fRotZ;				// Z轴旋转
		KEYFRAMEROTATION		_rotation;			// 自由旋转
		BPBASEFLOAT3			_vTranslation;		// 平移
	} _data;
} BPKEYPARAMETER;

// 关键帧
// 模型从起始状态,通过局部和全局变换到指定帧号的状态
typedef struct _BPKEYFRAME {
	IKS_UINT _uFrameID;										// 帧号
	BPBASEMATRIX _matStartStatus;						// 起始状态
	std::vector<BPKEYPARAMETER> _arrLocalTransform;		// 局部变换的关键帧参数(有顺序)
	std::vector<BPKEYPARAMETER> _arrGlobalTransform;	// 全局变换的关键帧参数(有顺序)

	_BPKEYFRAME()
	{
		_uFrameID = 0;
		INIT_MATRIX(_matStartStatus);
	}
	_BPKEYFRAME(const _BPKEYFRAME& keyframe)
	{
		_uFrameID = keyframe._uFrameID;
		_matStartStatus = keyframe._matStartStatus;
		_arrLocalTransform = keyframe._arrLocalTransform;
		_arrGlobalTransform = keyframe._arrGlobalTransform;
	}
	_BPKEYFRAME& operator = (const _BPKEYFRAME& keyframe)
	{
		if (this == &keyframe)
			return *this;
		_uFrameID = keyframe._uFrameID;
		_matStartStatus = keyframe._matStartStatus;
		_arrLocalTransform = keyframe._arrLocalTransform;
		_arrGlobalTransform = keyframe._arrGlobalTransform;
		return *this;
	}
	void clear()
	{
		_uFrameID = 0;
		INIT_MATRIX(_matStartStatus);
		_arrLocalTransform.clear();
		_arrGlobalTransform.clear();
	}
	void ClearMov()
	{
		_arrLocalTransform.clear();
		_arrGlobalTransform.clear();
	}
} BPKEYFRAME;

// 摄像机关键帧
typedef struct _BPCAMERA_KEYFRAME {
	IKS_UINT _uFrameID;				// 帧号
	BPCAMERA _camera;			// 摄像机数据
} BPCAMERA_KEYFRAME;

// 缩放关键帧
typedef struct _BPSCALE_KEYFRAME {
	IKS_UINT _uFrameID;				// 帧号
	BPBASEFLOAT3 _vScale;		// 缩放比例XYZ
} BPSCALE_KEYFRAME;

// 可见性关键帧
typedef struct _BPVISIBLE_KEYFRAME {
	IKS_UINT _uFrameID;				// 帧号
	IKS_BOOL _bVisible;				// 可见性
} BPVISIBLE_KEYFRAME;

// 透明度关键帧
typedef struct _BPTRANSPARENCY_KEYFRAME {
	IKS_UINT _uFrameID;				// 帧号
	float _fNoTransparency;		// 非透明度
} BPTRANSPARENCY_KEYFRAME;

// 参数数值
typedef struct _BP_PARAMETERVALUE {
	int _nType;									// 参数类型，参看BPPARAMETERTYPE枚举

	union {
		int				_nValue;				// 整数数值
		float			_fValue;				// 单精度浮点数值
		double			_dValue;				// 双精度浮点数值
		BPBASEFLOAT3	_vFloat3Value;			// 三个单精度浮点的数值
		SVBASEDOUBLE3	_vDouble3Value;			// 三个双精度浮点的数值
		bool			_bValue;				// 布尔数值
	};
	CSVWString _strValue;

	_BP_PARAMETERVALUE()
	{
		_nType = BPPARAMTYPE_UNKOWN;
		_strValue = L"";
	}
	_BP_PARAMETERVALUE(const _BP_PARAMETERVALUE& data)
	{
		_nType = data._nType;
		switch (_nType)
		{
		case BPPARAMTYPE_INT:
			_nValue = data._nValue;
			break;
		case BPPARAMTYPE_FLOAT:
			_fValue = data._fValue;
			break;
		case BPPARAMTYPE_DOUBLE:
			_dValue = data._dValue;
			break;
		case BPPARAMTYPE_FLOAT3:
			_vFloat3Value = data._vFloat3Value;
			break;
		case BPPARAMTYPE_DOUBLE3:
			_vDouble3Value = data._vDouble3Value;
			break;
		case BPPARAMTYPE_BOOL:
			_bValue = data._bValue;
			break;
		default:
			break;
		}
		_strValue = data._strValue;
	}
	_BP_PARAMETERVALUE& operator = (const _BP_PARAMETERVALUE& data)
	{
		if (this == &data) // 如果自己给自己赋值则直接返回
			return *this;
		_nType = data._nType;
		switch (_nType)
		{
		case BPPARAMTYPE_INT:
			_nValue = data._nValue;
			break;
		case BPPARAMTYPE_FLOAT:
			_fValue = data._fValue;
			break;
		case BPPARAMTYPE_DOUBLE:
			_dValue = data._dValue;
			break;
		case BPPARAMTYPE_FLOAT3:
			_vFloat3Value = data._vFloat3Value;
			break;
		case BPPARAMTYPE_DOUBLE3:
			_vDouble3Value = data._vDouble3Value;
			break;
		case BPPARAMTYPE_BOOL:
			_bValue = data._bValue;
			break;
		default:
			break;
		}
		_strValue = data._strValue;
		return *this;
	}
	IKS_BOOL operator == (const _BP_PARAMETERVALUE &data) const
	{
		if (_nType != data._nType)
			return FALSE;
		IKS_BOOL bEqual = TRUE;
		switch (_nType)
		{
		case BPPARAMTYPE_INT:
			if (_nValue != data._nValue)
				bEqual = FALSE;
			break;
		case BPPARAMTYPE_FLOAT:
			if (!ISEQUAL(_fValue, data._fValue))
				bEqual = FALSE;
			break;
		case BPPARAMTYPE_DOUBLE:
			if (!ISDEQUAL(_dValue, data._dValue))
				bEqual = FALSE;
			break;
		case BPPARAMTYPE_STRING:
			{
				CSVWString str1 = _strValue;
				CSVWString str2 = data._strValue;
				str1.MakeLower();
				str2.MakeLower();
				if (wcscmp(str1.GetBuffer(), str2.GetBuffer()) != 0)
					bEqual = FALSE;
				break;
			}
		case BPPARAMTYPE_FLOAT3:
			if ((!ISEQUAL(_vFloat3Value.x, data._vFloat3Value.x)) || (!ISEQUAL(_vFloat3Value.y, data._vFloat3Value.y)) || (!ISEQUAL(_vFloat3Value.z, data._vFloat3Value.z)))
				bEqual = FALSE;
			break;
		case BPPARAMTYPE_DOUBLE3:
			if ((!ISDEQUAL(_vDouble3Value.x, data._vDouble3Value.x)) || (!ISDEQUAL(_vDouble3Value.y, data._vDouble3Value.y)) || (!ISDEQUAL(_vDouble3Value.z, data._vDouble3Value.z)))
				bEqual = FALSE;
			break;
		case BPPARAMTYPE_BOOL:
			if (_bValue != data._bValue)
				bEqual = FALSE;
			break;
		default:
			break;
		}

		return bEqual;
	}
	IKS_BOOL operator != (const _BP_PARAMETERVALUE &data) const
	{
		return !(*this == data);
	}
} BP_PARAMETERVALUE;

// 参数
typedef struct _BP_PARAMETER {
	CSVWString			_strName;				// 参数名称
	BP_PARAMETERVALUE	_stuValue;				// 参数数值
	_BP_PARAMETER()
	{
		_strName = L"";
	}
	_BP_PARAMETER(const _BP_PARAMETER& data)
	{
		_strName = data._strName;
		_stuValue = data._stuValue;
	}
	_BP_PARAMETER& operator = (const _BP_PARAMETER& data)
	{
		if (this == &data) // 如果自己给自己赋值则直接返回
			return *this;
		_strName = data._strName;
		_stuValue = data._stuValue;
		return *this;
	}
} BP_PARAMETER;

// 参数过滤器元素
typedef struct _SV_PARAMETERFILTER_ELEM {
	int					_nOperType;				// 过滤器操作类型
	BP_PARAMETER		_stuParam;				// 参数
	_SV_PARAMETERFILTER_ELEM()
	{
		_nOperType = SVPFOTYPE_UNKOWN;
	}
	_SV_PARAMETERFILTER_ELEM(const _SV_PARAMETERFILTER_ELEM& elem)
	{
		_nOperType = elem._nOperType;
		_stuParam = elem._stuParam;
	}
	_SV_PARAMETERFILTER_ELEM& operator = (const _SV_PARAMETERFILTER_ELEM& elem)
	{
		if (this == &elem)
			return *this;
		_nOperType = elem._nOperType;
		_stuParam = elem._stuParam;
		return *this;
	}
} SV_PARAMETERFILTER_ELEM;

// 参数过滤器
typedef struct _SV_PARAMETERFILTER {
	std::vector<SV_PARAMETERFILTER_ELEM> _arrFilterElem;	// 过滤器元素
	_SV_PARAMETERFILTER()
	{
	}
	_SV_PARAMETERFILTER(const _SV_PARAMETERFILTER& filter)
	{
		_arrFilterElem = filter._arrFilterElem;
	}
	_SV_PARAMETERFILTER& operator = (const _SV_PARAMETERFILTER& filter)
	{
		if (this == &filter)
			return *this;
		_arrFilterElem = filter._arrFilterElem;
		return *this;
	}
	void Clear()
	{
		_arrFilterElem.clear();
	}
} SV_PARAMETERFILTER;

// 参数存储数据
typedef struct _BP_PARAMETER_SAVEDATA {
	std::vector<BP_PARAMETER> _arrParamSaveData;		// 参数存储数据
	_BP_PARAMETER_SAVEDATA()
	{
	}
	_BP_PARAMETER_SAVEDATA(const _BP_PARAMETER_SAVEDATA& data)
	{
		_arrParamSaveData = data._arrParamSaveData;
	}
	_BP_PARAMETER_SAVEDATA& operator = (const _BP_PARAMETER_SAVEDATA& data)
	{
		if (this == &data)
			return *this;
		_arrParamSaveData = data._arrParamSaveData;
		return *this;
	}
	void Clear()
	{
		_arrParamSaveData.clear();
	}
} BP_PARAMETER_SAVEDATA;

// 工艺规程插件数据
typedef struct _BP_TECHPLUGINDATA {
	CSVWString			_strInspectContent;				// 检测内容
	CSVWString			_strInspectResult;				// 检测结果

	_BP_TECHPLUGINDATA()
	{
		_strInspectContent = L"";
		_strInspectResult = L"";
	}
	_BP_TECHPLUGINDATA(const _BP_TECHPLUGINDATA& data)
	{
		_strInspectContent = data._strInspectContent;
		_strInspectResult = data._strInspectResult;
	}
	_BP_TECHPLUGINDATA& operator = (const _BP_TECHPLUGINDATA& data)
	{
		if (this == &data) // 如果自己给自己赋值则直接返回
			return *this;
		_strInspectContent = data._strInspectContent;
		_strInspectResult = data._strInspectResult;
		return *this;
	}
	void Clear()
	{
		_strInspectContent = L"";
		_strInspectResult = L"";
	}
} BP_TECHPLUGINDATA;

// 工艺规程插件数据节点
typedef struct _BP_TECHPLUGINNODE {
	unsigned int _uTimeNodeID;				// 节点对应的时间节点ID
	BP_TECHPLUGINDATA _data;

	_BP_TECHPLUGINNODE()
	{
		_uTimeNodeID = INVALID_ID;
	}
	_BP_TECHPLUGINNODE(const _BP_TECHPLUGINNODE& node)
	{
		_uTimeNodeID = node._uTimeNodeID;
		_data = node._data;
	}
	_BP_TECHPLUGINNODE& operator = (const _BP_TECHPLUGINNODE& node)
	{
		if (this == &node) // 如果自己给自己赋值则直接返回
			return *this;
		_uTimeNodeID = node._uTimeNodeID;
		_data = node._data;
		return *this;
	}
	void Clear()
	{
		_uTimeNodeID = INVALID_ID;
		_data.Clear();
	}
} BP_TECHPLUGINNODE;

// 工艺规程插件数据存储数据管理
typedef struct _BP_TECHPLUGINNODE_SAVEDATAMGR {
	std::vector<BP_TECHPLUGINNODE> _arrTechPlugInSaveData;	// 工艺规程插件数据存储数据
	_BP_TECHPLUGINNODE_SAVEDATAMGR()
	{
	}
	_BP_TECHPLUGINNODE_SAVEDATAMGR(const _BP_TECHPLUGINNODE_SAVEDATAMGR& data)
	{
		_arrTechPlugInSaveData = data._arrTechPlugInSaveData;
	}
	_BP_TECHPLUGINNODE_SAVEDATAMGR& operator = (const _BP_TECHPLUGINNODE_SAVEDATAMGR& data)
	{
		if (this == &data) // 如果自己给自己赋值则直接返回
			return *this;
		_arrTechPlugInSaveData = data._arrTechPlugInSaveData;
		return *this;
	}
	void Clear()
	{
		_arrTechPlugInSaveData.clear();
	}
} BP_TECHPLUGINNODE_SAVEDATAMGR;

// 时间节点
typedef struct _BP_TIMENODE {
	unsigned int _uTimeNodeID;				// 节点对应的时间节点ID
	unsigned int _uTreeNodeID;				// 树节点ID
	int _nType;								// 类型,参看枚举值BPSCENETIMENODETYPE
	wchar_t _szName[BP_MAX_PATH];			// 名称
	CSVWString _strNote;					// 注释
	wchar_t _szAudioPath[BP_MAX_PATH];		// 音频路径
	wchar_t _szDocPath[BP_MAX_PATH];		// 文档路径
	unsigned int _uVideoFileID;				// 视频文件ID
	std::vector<IKS_UINT> _arrImageFileID;		// 图像文件ID
	CSVWString _strHyperlink;				// 超链接
	unsigned int _uStartFrameID;			// 起始帧号
	unsigned int _uFrameSize;				// 帧长度
	BP_TECHPLUGINDATA _TechPlugInData;		// 工艺规程插件数据
	std::vector<_BP_TIMENODE> _arrSubNode;	// 子节点

	_BP_TIMENODE()
	{
		_uTimeNodeID = INVALID_ID;
		_uTreeNodeID = INVALID_ID;
		_nType = BPSTNT_NULL;
		memset(_szName, 0, sizeof(wchar_t)*BP_MAX_PATH);
		_strNote = L"";
		memset(_szAudioPath, 0, sizeof(wchar_t)*BP_MAX_PATH);
		memset(_szDocPath, 0, sizeof(wchar_t)*BP_MAX_PATH);
		_uVideoFileID = INVALID_ID;
		_strHyperlink = L"";
		_uStartFrameID = 0;
		_uFrameSize = 0;
	}
	_BP_TIMENODE(const _BP_TIMENODE& node)
	{
		_uTimeNodeID = node._uTimeNodeID;
		_uTreeNodeID = node._uTreeNodeID;
		_nType = node._nType;
		wcsncpy_s(_szName, BP_MAX_PATH, node._szName, _TRUNCATE);
		_strNote = node._strNote;
		wcsncpy_s(_szAudioPath, BP_MAX_PATH, node._szAudioPath, _TRUNCATE);
		wcsncpy_s(_szDocPath, BP_MAX_PATH, node._szDocPath, _TRUNCATE);
		_uVideoFileID = node._uVideoFileID;
		_arrImageFileID = node._arrImageFileID;
		_strHyperlink = node._strHyperlink;
		_uStartFrameID = node._uStartFrameID;
		_uFrameSize = node._uFrameSize;
		_TechPlugInData = node._TechPlugInData;
		_arrSubNode = node._arrSubNode;
	}
	_BP_TIMENODE& operator = (const _BP_TIMENODE& node)
	{
		if (this == &node) // 如果自己给自己赋值则直接返回
			return *this;
		_uTimeNodeID = node._uTimeNodeID;
		_uTreeNodeID = node._uTreeNodeID;
		_nType = node._nType;
		wcsncpy_s(_szName, BP_MAX_PATH, node._szName, _TRUNCATE);
		_strNote = node._strNote;
		wcsncpy_s(_szAudioPath, BP_MAX_PATH, node._szAudioPath, _TRUNCATE);
		wcsncpy_s(_szDocPath, BP_MAX_PATH, node._szDocPath, _TRUNCATE);
		_uVideoFileID = node._uVideoFileID;
		_arrImageFileID = node._arrImageFileID;
		_strHyperlink = node._strHyperlink;
		_uStartFrameID = node._uStartFrameID;
		_uFrameSize = node._uFrameSize;
		_TechPlugInData = node._TechPlugInData;
		_arrSubNode = node._arrSubNode;
		return *this;
	}
	void CopyData(_BP_TIMENODE& node)	const
	{
		node._uTimeNodeID = _uTimeNodeID;
		node._uTreeNodeID = _uTreeNodeID;
		node._nType = _nType;
		wcsncpy_s(node._szName, BP_MAX_PATH, _szName, _TRUNCATE);
		node._strNote = _strNote;
		wcsncpy_s(node._szAudioPath, BP_MAX_PATH, _szAudioPath, _TRUNCATE);
		wcsncpy_s(node._szDocPath, BP_MAX_PATH, _szDocPath, _TRUNCATE);
		node._uVideoFileID = _uVideoFileID;
		node._arrImageFileID = _arrImageFileID;
		node._strHyperlink = _strHyperlink;
		node._uStartFrameID = _uStartFrameID;
		node._uFrameSize = _uFrameSize;
		node._TechPlugInData = _TechPlugInData;
	}
	void Clear()
	{
		_uTimeNodeID = INVALID_ID;
		_uTreeNodeID = INVALID_ID;
		_nType = BPSTNT_NULL;
		memset(_szName, 0, sizeof(wchar_t)*BP_MAX_PATH);
		_strNote = L"";
		memset(_szAudioPath, 0, sizeof(wchar_t)*BP_MAX_PATH);
		memset(_szDocPath, 0, sizeof(wchar_t)*BP_MAX_PATH);
		_uVideoFileID = INVALID_ID;
		_arrImageFileID.clear();
		_strHyperlink = L"";
		_uStartFrameID = 0;
		_uFrameSize = 0;
		_TechPlugInData.Clear();
		_arrSubNode.clear();
	}
	IKS_UINT GetEndFrameID() const
	{
		return _uStartFrameID + _uFrameSize - 1;
	}
	IKS_UINT GetFrameLength() const
	{
		return _uFrameSize - 1;
	}
	void SetFrameLength(IKS_UINT uFrameLength)
	{
		_uFrameSize = uFrameLength + 1;
	}
} BP_TIMENODE;

// 工艺规程数据节点(一般用于数据导出生成xml数据文件)
typedef struct _BP_TECHPROCEDURENODE {
	unsigned int _uTimeNodeID;				// 节点对应的时间节点ID
	int _nType;								// 类型,参看枚举值BPSCENETIMENODETYPE
	CSVWString _strName;					// 名称
	CSVWString _strNote;					// 注释
	CSVWString _strImageName;				// 图片名称
	unsigned int _uStartFrameID;			// 起始帧号
	unsigned int _uFrameSize;				// 终止帧号
	BP_TECHPLUGINDATA _TechPlugInData;		// 工艺规程插件数据
	std::vector<_BP_TECHPROCEDURENODE> _arrSubNode;	// 子节点

	_BP_TECHPROCEDURENODE()
	{
		_uTimeNodeID = INVALID_ID;
		_nType = BPSTNT_NULL;
		_strName = L"";
		_strNote = L"";
		_strImageName = L"";
		_uStartFrameID = 0;
		_uFrameSize = 0;
	}
	_BP_TECHPROCEDURENODE(const _BP_TECHPROCEDURENODE& node)
	{
		_uTimeNodeID = node._uTimeNodeID;
		_nType = node._nType;
		_strName = node._strName;
		_strNote = node._strNote;
		_strImageName = node._strImageName;
		_uStartFrameID = node._uStartFrameID;
		_uFrameSize = node._uFrameSize;
		_TechPlugInData = node._TechPlugInData;
		_arrSubNode = node._arrSubNode;
	}
	_BP_TECHPROCEDURENODE(const BP_TIMENODE& stuTimeNode)
	{
		_uTimeNodeID = stuTimeNode._uTimeNodeID;
		_nType = stuTimeNode._nType;
		_strName = stuTimeNode._szName;
		_strNote = stuTimeNode._strNote;
		_strImageName = L"";
		_uStartFrameID = stuTimeNode._uStartFrameID;
		_uFrameSize = stuTimeNode._uFrameSize;
		_TechPlugInData = stuTimeNode._TechPlugInData;
		_arrSubNode.resize(stuTimeNode._arrSubNode.size());
		for (IKS_UINT i=0; i<_arrSubNode.size(); i++)
			_arrSubNode[i] = stuTimeNode._arrSubNode[i];
	}
	_BP_TECHPROCEDURENODE& operator = (const _BP_TECHPROCEDURENODE& node)
	{
		if (this == &node) // 如果自己给自己赋值则直接返回
			return *this;
		_uTimeNodeID = node._uTimeNodeID;
		_nType = node._nType;
		_strName = node._strName;
		_strNote = node._strNote;
		_strImageName = node._strImageName;
		_uStartFrameID = node._uStartFrameID;
		_uFrameSize = node._uFrameSize;
		_TechPlugInData = node._TechPlugInData;
		_arrSubNode = node._arrSubNode;
		return *this;
	}
	_BP_TECHPROCEDURENODE& operator = (const BP_TIMENODE& stuTimeNode)
	{
		_uTimeNodeID = stuTimeNode._uTimeNodeID;
		_nType = stuTimeNode._nType;
		_strName = stuTimeNode._szName;
		_strNote = stuTimeNode._strNote;
		_strImageName = L"";
		_uStartFrameID = stuTimeNode._uStartFrameID;
		_uFrameSize = stuTimeNode._uFrameSize;
		_TechPlugInData = stuTimeNode._TechPlugInData;
		_arrSubNode.resize(stuTimeNode._arrSubNode.size());
		for (IKS_UINT i=0; i<_arrSubNode.size(); i++)
			_arrSubNode[i] = stuTimeNode._arrSubNode[i];
		return *this;
	}
	void CopyData(_BP_TECHPROCEDURENODE& node)	const
	{
		node._uTimeNodeID = _uTimeNodeID;
		node._nType = _nType;
		node._strName = _strName;
		node._strNote = _strNote;
		node._strImageName = _strImageName;
		node._uStartFrameID = _uStartFrameID;
		node._uFrameSize = _uFrameSize;
		node._TechPlugInData = _TechPlugInData;
	}
} BP_TECHPROCEDURENODE;

// 模型树节点
typedef struct __BP_OBJ_TREENODE {
	unsigned int _uObjectID;					// 节点对应的物件ID
	unsigned int _uTreeNodeID;					// 树节点ID
	CSVWString _strOriTreeNodeID;				// 树节点原始ID(从CAD导出时的节点ID,用于原CAD模型树更新当前模型树)
	CSVWString _strName;						// 节点名称
	CSVWString _strOriName;						// 节点的原始名称(生成或从CAD导出时的名称,区分于重命名后的名称)
	BPBASEMATRIX _matTranform;					// 变换矩阵(当前模型(组件/零件)在上一层组件中的世界变换矩阵)
	// 注意:变换矩阵代表未编辑时的装配关系,可用于CAD装配体装配关系变化时更新SVF(物件的初始矩阵(Local缩放变换*RTWorld)与模型树中该节点的世界矩阵之差,即为用户修改的初始位置变换矩阵);
	// 因此只允许在CAD软件导出或更改模型树结构(只修改层级的相对位置关系,模型的全局位置不变)时修改,不允许用户私自修改!
	std::vector<BP_PARAMETER> _arrParamData;	// 参数
	std::vector<IKS_UINT> _arrAnnoBlockID;			// 标注块ID
	std::vector<__BP_OBJ_TREENODE> _arrSubNode;	// 子节点
	__BP_OBJ_TREENODE()
	{
		_uObjectID = INVALID_ID;
		_uTreeNodeID = INVALID_ID;
		_strOriTreeNodeID = L"";
		_strName = L"";
		_strOriName = L"";
		INIT_MATRIX(_matTranform);
	}
	__BP_OBJ_TREENODE(const __BP_OBJ_TREENODE& node)
	{
		_uObjectID = node._uObjectID;
		_uTreeNodeID = node._uTreeNodeID;
		_strOriTreeNodeID = node._strOriTreeNodeID;
		_strName = node._strName;
		_strOriName = node._strOriName;
		_matTranform = node._matTranform;
		_arrParamData = node._arrParamData;
		_arrAnnoBlockID = node._arrAnnoBlockID;
		_arrSubNode = node._arrSubNode;
	}
	__BP_OBJ_TREENODE& operator = (const __BP_OBJ_TREENODE& node)
	{
		if (this == &node) // 如果自己给自己赋值则直接返回
			return *this;
		_uObjectID = node._uObjectID;
		_uTreeNodeID = node._uTreeNodeID;
		_strOriTreeNodeID = node._strOriTreeNodeID;
		_strName = node._strName;
		_strOriName = node._strOriName;
		_matTranform = node._matTranform;
		_arrParamData = node._arrParamData;
		_arrAnnoBlockID = node._arrAnnoBlockID;
		_arrSubNode = node._arrSubNode;
		return *this;
	}
	void CopyData(__BP_OBJ_TREENODE& node)	const
	{
		node._uObjectID = _uObjectID;
		node._uTreeNodeID = _uTreeNodeID;
		node._strOriTreeNodeID = _strOriTreeNodeID;
		node._strName = _strName;
		node._strOriName = _strOriName;
		node._matTranform = _matTranform;
		node._arrParamData = _arrParamData;
		node._arrAnnoBlockID = _arrAnnoBlockID;
	}
} BP_OBJ_TREENODE;

// 场景系统单位
typedef struct _BP_SCENE_UNIT {
	int _nLengthUnit;		// 长度单位,参看枚举型BPLENGTHUNITTYPE
	int _nMassUnit;			// 质量单位,参看枚举型BPMASSUNITTYPE
	int _nTimeUnit;			// 时间单位,参看枚举型BPTIMEUNITTYPE
	_BP_SCENE_UNIT()
	{
		_nLengthUnit = BPLENUNITTYPE_UNKOWN;
		_nMassUnit = BPMASSUNITTYPE_UNKOWN;
		_nTimeUnit = BPTIMEUNITTYPE_UNKOWN;
	}
	_BP_SCENE_UNIT(const _BP_SCENE_UNIT& data)
	{
		_nLengthUnit = data._nLengthUnit;
		_nMassUnit = data._nMassUnit;
		_nTimeUnit = data._nTimeUnit;
	}
	_BP_SCENE_UNIT& operator = (const _BP_SCENE_UNIT& data)
	{
		if (this == &data) // 如果自己给自己赋值则直接返回
			return *this;
		_nLengthUnit = data._nLengthUnit;
		_nMassUnit = data._nMassUnit;
		_nTimeUnit = data._nTimeUnit;
		return *this;
	}
	IKS_BOOL operator == ( const _BP_SCENE_UNIT &unit) const
	{
		if (_nLengthUnit != unit._nLengthUnit)
			return FALSE;
		if (_nMassUnit != unit._nMassUnit)
			return FALSE;
		if (_nTimeUnit != unit._nTimeUnit)
			return FALSE;
		return TRUE;
	}
	IKS_BOOL operator != ( const _BP_SCENE_UNIT &unit) const
	{
		return (!((*this) == unit));
	}
	void Clear()
	{
		_nLengthUnit = BPLENUNITTYPE_UNKOWN;
		_nMassUnit = BPMASSUNITTYPE_UNKOWN;
		_nTimeUnit = BPTIMEUNITTYPE_UNKOWN;
	}
} BP_SCENE_UNIT;

// 模型子集存储数据
typedef struct _BP_MODELSUBSET_SAVEDATA
{
	int				_nPrimitType;			// 图元类型,参看枚举型BPPRIMITIVETYPE
	IKS_UINT			_uStartIndex;			// 首索引偏移值
	IKS_UINT			_uIndexCount;			// 索引数量
	BOUNDBOX		_box;					// 曲面包围盒
	int				_nSubsetType;			// 子集类型,参看枚举型BPMDLSUBSETTYPE
	IKS_UINT			_uGeomIndex;			// 几何(曲面曲线等)索引(注意:若该索引不为-1,则该子集与对应的几何是一一对应关系)
	_BP_MODELSUBSET_SAVEDATA()
	{
		_nPrimitType = BPPT_TRIANGLELIST;
		_uStartIndex = 0;
		_uIndexCount = 0;
		memset(&_box, 0, sizeof(BOUNDBOX));
		_nSubsetType = BP_MDLSUBSET_UNKOWN;
		_uGeomIndex = INVALID_ID;
	}
	_BP_MODELSUBSET_SAVEDATA(const _BP_MODELSUBSET_SAVEDATA &data)
	{
		_nPrimitType = data._nPrimitType;
		_uStartIndex = data._uStartIndex;
		_uIndexCount = data._uIndexCount;
		_box = data._box;
		_nSubsetType = data._nSubsetType;
		_uGeomIndex = data._uGeomIndex;
	}
	_BP_MODELSUBSET_SAVEDATA &operator=(const _BP_MODELSUBSET_SAVEDATA& data){
		if (&data != this)
		{
			_nPrimitType = data._nPrimitType;
			_uStartIndex = data._uStartIndex;
			_uIndexCount = data._uIndexCount;
			_box = data._box;
			_nSubsetType = data._nSubsetType;
			_uGeomIndex = data._uGeomIndex;
		}
		return *this;
	}
	IKS_BOOL operator == (const _BP_MODELSUBSET_SAVEDATA &data) const
	{
		if (_nPrimitType != data._nPrimitType)
			return FALSE;
		if (_uStartIndex != data._uStartIndex)
			return FALSE;
		if (_uIndexCount != data._uIndexCount)
			return FALSE;
		if (!ISFLOAT3EQUAL(_box._min, data._box._min))
			return FALSE;
		if (!ISFLOAT3EQUAL(_box._max, data._box._max))
			return FALSE;
		if (_nSubsetType != data._nSubsetType)
			return FALSE;
		if (_uGeomIndex != data._uGeomIndex)
			return FALSE;
		return TRUE;
	}
	IKS_BOOL operator != (const _BP_MODELSUBSET_SAVEDATA &data) const
	{
		return !(*this == data);
	}
	void Clear()
	{
		_nPrimitType = BPPT_TRIANGLELIST;
		_uStartIndex = 0;
		_uIndexCount = 0;
		memset(&_box, 0, sizeof(BOUNDBOX));
		_nSubsetType = BP_MDLSUBSET_UNKOWN;
		_uGeomIndex = INVALID_ID;
	}
} BP_MODELSUBSET_SAVEDATA;

// 模型存储数据
typedef struct _BP_MODEL_SAVEDATA
{
	int										_nModelSrcType;			// 模型来源类型
	std::vector<float>						_arrVertexData;			// 顶点数据(每个顶点包含8个float(3个位置+3个法矢向量+2纹理坐标))
	std::vector<IKS_DWORD>						_arrIndexData;		// 索引组，组内3个元素为一组(三角片)或2个元素为一组(线段)
	std::vector<BP_MODELSUBSET_SAVEDATA>	_arrSubset;				// 子集数据
	std::vector<MODELSUBSETGROUP>			_arrSubsetGrp;			// 子集组数据
	std::vector<BPSurface>					_arrSurface;			// 曲面数据
	std::vector<BPCurve>					_arrCurve;				// 曲线数据
	BOUNDBOX								_box;					// 模型包围盒
	_BP_MODEL_SAVEDATA()
	{
		_nModelSrcType = BP_MDLSRC_UNKOWN;
		memset(&_box, 0, sizeof(BOUNDBOX));
	}
	_BP_MODEL_SAVEDATA(const _BP_MODEL_SAVEDATA &data)
	{
		_nModelSrcType = data._nModelSrcType;
		_arrVertexData = data._arrVertexData;
		_arrIndexData = data._arrIndexData;
		_arrSubset = data._arrSubset;
		_arrSubsetGrp = data._arrSubsetGrp;
		_arrSurface = data._arrSurface;
		_arrCurve = data._arrCurve;
		_box = data._box;
	}
	_BP_MODEL_SAVEDATA &operator=(const _BP_MODEL_SAVEDATA& data){
		if (&data != this)
		{
			_nModelSrcType = data._nModelSrcType;
			_arrVertexData = data._arrVertexData;
			_arrIndexData = data._arrIndexData;
			_arrSubset = data._arrSubset;
			_arrSubsetGrp = data._arrSubsetGrp;
			_arrSurface = data._arrSurface;
			_arrCurve = data._arrCurve;
			_box = data._box;
		}
		return *this;
	}
	IKS_BOOL operator == (const _BP_MODEL_SAVEDATA &data) const
	{
		if (_nModelSrcType != data._nModelSrcType)
			return FALSE;
		if (_arrVertexData.size() != data._arrVertexData.size())
			return FALSE;
		if (_arrIndexData.size() != data._arrIndexData.size())
			return FALSE;
		if (_arrSubset.size() != data._arrSubset.size())
			return FALSE;
		if (_arrSubsetGrp.size() != data._arrSubsetGrp.size())
			return FALSE;
		if (_arrSurface.size() != data._arrSurface.size())
			return FALSE;
		if (_arrCurve.size() != data._arrCurve.size())
			return FALSE;
		if (!ISFLOAT3EQUAL(_box._min, data._box._min))
			return FALSE;
		if (!ISFLOAT3EQUAL(_box._max, data._box._max))
			return FALSE;
		IKS_UINT i = 0;
		// 比较顶点数据
		for (i=0; i<_arrVertexData.size(); i++)
		{
			if (!ISEQUAL(_arrVertexData[i], data._arrVertexData[i]))
				return FALSE;
		}
		// 比较索引数据
		if (memcmp(&(_arrIndexData[0]), &(data._arrIndexData[0]), sizeof(IKS_DWORD)*_arrIndexData.size()) != 0)
			return FALSE;
		// 比较子集数据
		for (i=0; i<_arrSubset.size(); i++)
		{
			if (_arrSubset[i] != data._arrSubset[i])
				return FALSE;
		}
		// 比较子集组数据
		for (i=0; i<_arrSubsetGrp.size(); i++)
		{
			if (_arrSubsetGrp[i]._nType != data._arrSubsetGrp[i]._nType)
				return FALSE;
			if (_arrSubsetGrp[i]._arrSubsetIndex.size() != data._arrSubsetGrp[i]._arrSubsetIndex.size())
				return FALSE;
			if (memcmp(&(_arrSubsetGrp[i]._arrSubsetIndex[0]), &(data._arrSubsetGrp[i]._arrSubsetIndex[0]), sizeof(IKS_UINT)*_arrSubsetGrp[i]._arrSubsetIndex.size()) != 0)
				return FALSE;
		}
		// 比较面数据
		for (i=0; i<_arrSurface.size(); i++)
		{
			if (_arrSurface[i] != data._arrSurface[i])
				return FALSE;
		}
		// 比较边数据
		for (i=0; i<_arrCurve.size(); i++)
		{
			if (_arrCurve[i] != data._arrCurve[i])
				return FALSE;
		}
		return TRUE;
	}
	IKS_BOOL operator != (const _BP_MODEL_SAVEDATA &data) const
	{
		return !(*this == data);
	}
	void Clear()
	{
		_nModelSrcType = BP_MDLSRC_UNKOWN;
		_arrVertexData.clear();
		_arrIndexData.clear();
		_arrSubset.clear();
		_arrSubsetGrp.clear();
		_arrSurface.clear();
		_arrCurve.clear();
		memset(&_box, 0, sizeof(BOUNDBOX));
	}
} BP_MODEL_SAVEDATA;

// 物件存储数据
typedef struct _BP_OBJ_SAVEDATA {
	unsigned int _uObjectID;					// 物件ID
	int _nObjSubType;							// 物件子类型,参看枚举型BPSCENEOBJECTSUBTYPE
	BPOBJGRPRENDERSTATE _RenderState;			// 渲染状态
	unsigned int _uMeshID;						// 物件对应模型Mesh的ID
	BPBASEMATRIX _matLocal;						// 局部矩阵
	BPBASEMATRIX _matWorld;						// 世界矩阵
	int _nAlphaBlendRenderSerialNum;			// 物件的透明渲染序号
	IKS_BOOL _bAlphaBlendRenderInternalStruct;		// 是否透明渲染内部结构
	ProductInfo _ProductInfo;					// 产品信息
	std::vector<unsigned int > _arrSubsetMtlID;	// 物件子集的材质ID
	std::vector<BP_PARAMETER> _arrParamSaveData;		// 物件参数
	_BP_OBJ_SAVEDATA()
	{
		_uObjectID = INVALID_ID;
		_nObjSubType = BPSCENEOBJSUBTYPE_GENERAL;
		_RenderState._bZEnable = TRUE;
		_RenderState._bZWriteEnable = TRUE;
		_RenderState._bAlphaBlendEnable = FALSE;
		_RenderState._eFillMode = BPFILL_SOLID;
		_RenderState._bUseSceneLight = TRUE;
		_RenderState._eCullMode = BPCULL_CW;
		_uMeshID = INVALID_ID;
		INIT_MATRIX(_matLocal);
		INIT_MATRIX(_matWorld);
		_nAlphaBlendRenderSerialNum = BP_USEROBJ_ALPHABLENDRENDERSERIALNUM_DEFAULT;
		_bAlphaBlendRenderInternalStruct = FALSE;
	}
	_BP_OBJ_SAVEDATA(const _BP_OBJ_SAVEDATA& data)
	{
		_uObjectID = data._uObjectID;
		_nObjSubType = data._nObjSubType;
		_RenderState = data._RenderState;
		_uMeshID = data._uMeshID;
		_matLocal = data._matLocal;
		_matWorld = data._matWorld;
		_nAlphaBlendRenderSerialNum = data._nAlphaBlendRenderSerialNum;
		_bAlphaBlendRenderInternalStruct = data._bAlphaBlendRenderInternalStruct;
		_ProductInfo = data._ProductInfo;
		_arrSubsetMtlID = data._arrSubsetMtlID;
		_arrParamSaveData = data._arrParamSaveData;
	}
	_BP_OBJ_SAVEDATA& operator = (const _BP_OBJ_SAVEDATA& data)
	{
		if (this == &data) // 如果自己给自己赋值则直接返回
			return *this;
		_uObjectID = data._uObjectID;
		_nObjSubType = data._nObjSubType;
		_RenderState = data._RenderState;
		_uMeshID = data._uMeshID;
		_matLocal = data._matLocal;
		_matWorld = data._matWorld;
		_nAlphaBlendRenderSerialNum = data._nAlphaBlendRenderSerialNum;
		_bAlphaBlendRenderInternalStruct = data._bAlphaBlendRenderInternalStruct;
		_ProductInfo = data._ProductInfo;
		_arrSubsetMtlID = data._arrSubsetMtlID;
		_arrParamSaveData = data._arrParamSaveData;
		return *this;
	}
	void Clear()
	{
		_uObjectID = INVALID_ID;
		_nObjSubType = BPSCENEOBJSUBTYPE_GENERAL;
		_RenderState._bZEnable = TRUE;
		_RenderState._bZWriteEnable = TRUE;
		_RenderState._bAlphaBlendEnable = FALSE;
		_RenderState._eFillMode = BPFILL_SOLID;
		_RenderState._bUseSceneLight = TRUE;
		_RenderState._eCullMode = BPCULL_CW;
		_uMeshID = INVALID_ID;
		INIT_MATRIX(_matLocal);
		INIT_MATRIX(_matWorld);
		_nAlphaBlendRenderSerialNum = BP_USEROBJ_ALPHABLENDRENDERSERIALNUM_DEFAULT;
		_bAlphaBlendRenderInternalStruct = FALSE;
		_ProductInfo.Clear();
		_arrSubsetMtlID.clear();
		_arrParamSaveData.clear();
	}
	void CopyData(_BP_OBJ_SAVEDATA& data)	const
	{
		data._uObjectID = _uObjectID;
		data._nObjSubType = _nObjSubType;
		data._RenderState = _RenderState;
		data._uMeshID = _uMeshID;
		data._matLocal = _matLocal;
		data._matWorld = _matWorld;
		data._nAlphaBlendRenderSerialNum = _nAlphaBlendRenderSerialNum;
		data._bAlphaBlendRenderInternalStruct = _bAlphaBlendRenderInternalStruct;
		data._ProductInfo = _ProductInfo;
		data._arrSubsetMtlID = _arrSubsetMtlID;
		data._arrParamSaveData = _arrParamSaveData;
	}
} BP_OBJ_SAVEDATA;

// 物件存储数据管理
typedef struct _BP_OBJ_SAVEDATAMGR {
	std::vector<BP_OBJ_SAVEDATA> _arrObjSaveData;	// 物件存储数据
	_BP_OBJ_SAVEDATAMGR()
	{
	}
	_BP_OBJ_SAVEDATAMGR(const _BP_OBJ_SAVEDATAMGR& data)
	{
		_arrObjSaveData = data._arrObjSaveData;
	}
	_BP_OBJ_SAVEDATAMGR& operator = (const _BP_OBJ_SAVEDATAMGR& data)
	{
		if (this == &data)
			return *this;
		_arrObjSaveData = data._arrObjSaveData;
		return *this;
	}
	void Clear()
	{
		_arrObjSaveData.clear();
	}

} BP_OBJ_SAVEDATAMGR;

// 材质存储数据
typedef struct _BP_MTL_SAVEDATA {
	unsigned int _uMtlID;						// 材质ID
	CSVWString _strName;						// 材质名称
	BPMATERIAL _MtlData;						// 材质数据
	_BP_MTL_SAVEDATA()
	{
		_uMtlID = INVALID_ID;
		_strName = L"";
	}
	_BP_MTL_SAVEDATA(const _BP_MTL_SAVEDATA& data)
	{
		_uMtlID = data._uMtlID;
		_strName = data._strName;
		_MtlData = data._MtlData;
	}
	_BP_MTL_SAVEDATA& operator = (const _BP_MTL_SAVEDATA& data)
	{
		if (this == &data)
			return *this;
		_uMtlID = data._uMtlID;
		_strName = data._strName;
		_MtlData = data._MtlData;
		return *this;
	}
} BP_MTL_SAVEDATA;

// 纹理存储数据
// typedef struct _BP_TEX_SAVEDATA {
// 	unsigned int _uTexID;						// 纹理ID
// 	wchar_t stzTexPath[BP_MAX_PATH];			// 纹理路径文件名称
// } BP_TEX_SAVEDATA;

// 材质存储数据管理
typedef struct _BP_MTL_SAVEDATAMGR {
	std::vector<BP_MTL_SAVEDATA> _arrMtlSaveData;		// 材质存储数据
// 	std::vector<BP_TEX_SAVEDATA>	_arrTexSaveData;	// 纹理存储数据
	_BP_MTL_SAVEDATAMGR()
	{
	}
	_BP_MTL_SAVEDATAMGR(const _BP_MTL_SAVEDATAMGR& data)
	{
		_arrMtlSaveData = data._arrMtlSaveData;
	}
	_BP_MTL_SAVEDATAMGR& operator = (const _BP_MTL_SAVEDATAMGR& data)
	{
		if (this == &data)
			return *this;
		_arrMtlSaveData = data._arrMtlSaveData;
		return *this;
	}
	void Clear()
	{
		_arrMtlSaveData.clear();
	}
} BP_MTL_SAVEDATAMGR;

// 物件动画存储数据
typedef struct _BP_OBJ_ANIM_SAVEDATA {
	unsigned int _uObjectID;							// 物件ID
	std::vector<BPKEYFRAME> _arrKeyFrameData;			// 物件的关键帧(旋转平移变换)
	std::vector<BPSCALE_KEYFRAME> _arrScaleKeyFrm;		// 物件的缩放关键帧
	std::vector<BPVISIBLE_KEYFRAME> _arrVisibleKeyFrm;	// 物件的可见性关键帧
	std::vector<BPTRANSPARENCY_KEYFRAME> _arrTranspKeyFrm;	// 物件的透明度关键帧
	_BP_OBJ_ANIM_SAVEDATA()
	{
		_uObjectID = INVALID_ID;
	}
	_BP_OBJ_ANIM_SAVEDATA(const _BP_OBJ_ANIM_SAVEDATA& data)
	{
		_uObjectID = data._uObjectID;
		_arrKeyFrameData = data._arrKeyFrameData;
		_arrScaleKeyFrm = data._arrScaleKeyFrm;
		_arrVisibleKeyFrm = data._arrVisibleKeyFrm;
		_arrTranspKeyFrm = data._arrTranspKeyFrm;
	}
	_BP_OBJ_ANIM_SAVEDATA& operator = (const _BP_OBJ_ANIM_SAVEDATA& data)
	{
		if (this == &data)
			return *this;
		_uObjectID = data._uObjectID;
		_arrKeyFrameData = data._arrKeyFrameData;
		_arrScaleKeyFrm = data._arrScaleKeyFrm;
		_arrVisibleKeyFrm = data._arrVisibleKeyFrm;
		_arrTranspKeyFrm = data._arrTranspKeyFrm;
		return *this;
	}
	void clear()
	{
		_uObjectID = INVALID_ID;
		_arrKeyFrameData.clear();
		_arrScaleKeyFrm.clear();
		_arrVisibleKeyFrm.clear();
		_arrTranspKeyFrm.clear();
	}
} BP_OBJ_ANIM_SAVEDATA;

// 标注动画存储数据
typedef struct _BP_ANNOT_ANIM_SAVEDATA {
	unsigned int _uAnnotID;									// 标注ID
	std::vector<BPKEYFRAME> _arrKeyFrameData;				// 标注的关键帧(旋转平移变换)
	std::vector<BPTRANSPARENCY_KEYFRAME> _arrTranspKeyFrm;	// 标注的透明度关键帧
	_BP_ANNOT_ANIM_SAVEDATA()
	{
		_uAnnotID = INVALID_ID;
	}
	_BP_ANNOT_ANIM_SAVEDATA(const _BP_ANNOT_ANIM_SAVEDATA& data)
	{
		_uAnnotID = data._uAnnotID;
		_arrKeyFrameData = data._arrKeyFrameData;
		_arrTranspKeyFrm = data._arrTranspKeyFrm;
	}
	_BP_ANNOT_ANIM_SAVEDATA& operator = (const _BP_ANNOT_ANIM_SAVEDATA& data)
	{
		if (this == &data)
			return *this;
		_uAnnotID = data._uAnnotID;
		_arrKeyFrameData = data._arrKeyFrameData;
		_arrTranspKeyFrm = data._arrTranspKeyFrm;
		return *this;
	}
	void clear()
	{
		_uAnnotID = INVALID_ID;
		_arrKeyFrameData.clear();
		_arrTranspKeyFrm.clear();
	}
} BP_ANNOT_ANIM_SAVEDATA;

// 动画存储数据管理
typedef struct _BP_ANIM_SAVEDATAMGR {
	unsigned int _uFrameSize;									// 时间线长度(单位：帧)
	std::vector<BP_OBJ_ANIM_SAVEDATA> _arrObjAnimSaveData;		// 物件动画存储数据
	std::vector<BP_ANNOT_ANIM_SAVEDATA> _arrAnnotAnimSaveData;	// 标注动画存储数据
	_BP_ANIM_SAVEDATAMGR()
	{
		_uFrameSize = 0;
	}
	_BP_ANIM_SAVEDATAMGR(const _BP_ANIM_SAVEDATAMGR& data)
	{
		_uFrameSize = data._uFrameSize;
		_arrObjAnimSaveData = data._arrObjAnimSaveData;
		_arrAnnotAnimSaveData = data._arrAnnotAnimSaveData;
	}
	_BP_ANIM_SAVEDATAMGR& operator = (const _BP_ANIM_SAVEDATAMGR& data)
	{
		if (this == &data)
			return *this;
		_uFrameSize = data._uFrameSize;
		_arrObjAnimSaveData = data._arrObjAnimSaveData;
		_arrAnnotAnimSaveData = data._arrAnnotAnimSaveData;
		return *this;
	}
	void Clear()
	{
		_uFrameSize = 0;
		_arrObjAnimSaveData.clear();
		_arrAnnotAnimSaveData.clear();
	}
} BP_ANIM_SAVEDATAMGR;

// 摄像机存储数据管理
typedef struct _BP_CAMERA_SAVEDATAMGR {
	BPCAMERA _DefaultCamera;								// 默认摄像机数据
	std::vector<BPCAMERA_KEYFRAME> _arrCameraAnimSaveData;	// 摄像机关键帧
	_BP_CAMERA_SAVEDATAMGR()
	{
	}
	_BP_CAMERA_SAVEDATAMGR(const _BP_CAMERA_SAVEDATAMGR& data)
	{
		_DefaultCamera = data._DefaultCamera;
		_arrCameraAnimSaveData = data._arrCameraAnimSaveData;
	}
	_BP_CAMERA_SAVEDATAMGR& operator = (const _BP_CAMERA_SAVEDATAMGR& data)
	{
		if (this == &data)
			return *this;
		_DefaultCamera = data._DefaultCamera;
		_arrCameraAnimSaveData = data._arrCameraAnimSaveData;
		return *this;
	}
	void Clear()
	{
		_arrCameraAnimSaveData.clear();
	}
} BP_CAMERA_SAVEDATAMGR;

// 背景音频存储数据
typedef struct _BP_BACKGROUNDAUDIO_SAVEDATA {
	CSVWString	_strAudioName;				// 音频名称
	IKS_BOOL		_bAlwaysPlay;				// 始终播放
	_BP_BACKGROUNDAUDIO_SAVEDATA()
	{
		clear();
	}
	_BP_BACKGROUNDAUDIO_SAVEDATA(const _BP_BACKGROUNDAUDIO_SAVEDATA& data)
	{
		_strAudioName = data._strAudioName;
		_bAlwaysPlay = data._bAlwaysPlay;
	}
	_BP_BACKGROUNDAUDIO_SAVEDATA& operator = (const _BP_BACKGROUNDAUDIO_SAVEDATA& data)
	{
		if (this == &data)
			return *this;
		_strAudioName = data._strAudioName;
		_bAlwaysPlay = data._bAlwaysPlay;
		return *this;
	}
	void clear()
	{
		_strAudioName = L"";
		_bAlwaysPlay = FALSE;
	}
} BP_BACKGROUNDAUDIO_SAVEDATA;

// 选项配置数据
typedef struct _BP_CONFIG_SAVEDATA {
	unsigned int _uPlaySpeed;				// 播放速度
	float _fTextSize;						// 注释文本尺寸
	int _nTextStyle;						// 注释风格样式
	int _nCameraProjectType;				// 摄像机投影类型
	int _nCoordsType;						// 坐标系类型
	int _nSceneUpType;						// 场景上方向类型
	IKS_BOOL _bLockCameraUp;					// 锁定摄像机的上方向
	IKS_BOOL _bPlayUseCameraAnim;				// 播放时使用摄像机动画
	IKS_BOOL _bAutoCalcObjAlphaBlendRenderSerialNum;	// 自动计算物件的透明渲染序号
	BP_SCENE_UNIT _stuSceneUnit;			// 场景单位
	BPRENDERBACKGROUND _SceneBackGroundData;	// 场景背景
	BP_BACKGROUNDAUDIO_SAVEDATA _SceneBGAudio;	// 场景背景音频
	float _fStandardCameraAspect;			// 标准屏幕宽高比
	_BP_CONFIG_SAVEDATA()
	{
		clear();
	}
	_BP_CONFIG_SAVEDATA(const _BP_CONFIG_SAVEDATA& data)
	{
		_uPlaySpeed = data._uPlaySpeed;
		_fTextSize = data._fTextSize;
		_nTextStyle = data._nTextStyle;
		_nCameraProjectType = data._nCameraProjectType;
		_nCoordsType = data._nCoordsType;
		_nSceneUpType = data._nSceneUpType;
		_bLockCameraUp = data._bLockCameraUp;
		_bPlayUseCameraAnim = data._bPlayUseCameraAnim;
		_bAutoCalcObjAlphaBlendRenderSerialNum = data._bAutoCalcObjAlphaBlendRenderSerialNum;
		_stuSceneUnit = data._stuSceneUnit;
		_SceneBackGroundData = data._SceneBackGroundData;
		_SceneBGAudio = data._SceneBGAudio;
		_fStandardCameraAspect = data._fStandardCameraAspect;
	}
	_BP_CONFIG_SAVEDATA& operator = (const _BP_CONFIG_SAVEDATA& data)
	{
		if (this == &data)
			return *this;
		_uPlaySpeed = data._uPlaySpeed;
		_fTextSize = data._fTextSize;
		_nTextStyle = data._nTextStyle;
		_nCameraProjectType = data._nCameraProjectType;
		_nCoordsType = data._nCoordsType;
		_nSceneUpType = data._nSceneUpType;
		_bLockCameraUp = data._bLockCameraUp;
		_bPlayUseCameraAnim = data._bPlayUseCameraAnim;
		_bAutoCalcObjAlphaBlendRenderSerialNum = data._bAutoCalcObjAlphaBlendRenderSerialNum;
		_stuSceneUnit = data._stuSceneUnit;
		_SceneBackGroundData = data._SceneBackGroundData;
		_SceneBGAudio = data._SceneBGAudio;
		_fStandardCameraAspect = data._fStandardCameraAspect;
		return *this;
	}
	void clear()
	{
		_uPlaySpeed = 1;
		_fTextSize = 18.0f;
		_nTextStyle = 0;
		_nCameraProjectType = BPCP_PERSPECTIVE;
		_nCoordsType = BPCST_RIGHTHAND;
		_nSceneUpType = SVCUT_Y;
		_bLockCameraUp = TRUE;
		_bPlayUseCameraAnim = TRUE;
		_bAutoCalcObjAlphaBlendRenderSerialNum = FALSE;
		_stuSceneUnit.Clear();
		_SceneBackGroundData._eType = BPRBGT_INVALID;
		_SceneBGAudio.clear();
		_fStandardCameraAspect = 1.777778f;
	}
} BP_CONFIG_SAVEDATA;

// 标注存储数据
typedef struct _BP_ANNOTATION_SAVEDATA {
	CSVChipVector<SVAnnotation> _arrAnnotation;
	std::vector<SVAnnotationView> _arrAnnotationView;
	std::vector<SVAnnotationBlock> _arrAnnotationBlock;
	_BP_ANNOTATION_SAVEDATA()
	{
	}
	_BP_ANNOTATION_SAVEDATA(const _BP_ANNOTATION_SAVEDATA& data)
	{
		_arrAnnotation = data._arrAnnotation;
		_arrAnnotationView = data._arrAnnotationView;
		_arrAnnotationBlock = data._arrAnnotationBlock;
	}
	_BP_ANNOTATION_SAVEDATA& operator = (const _BP_ANNOTATION_SAVEDATA& data)
	{
		if (this == &data)
			return *this;
		_arrAnnotation = data._arrAnnotation;
		_arrAnnotationView = data._arrAnnotationView;
		_arrAnnotationBlock = data._arrAnnotationBlock;
		return *this;
	}
	void Clear()
	{
		_arrAnnotation.clear();
		_arrAnnotationView.clear();
		_arrAnnotationBlock.clear();
	}
} BP_ANNOTATION_SAVEDATA;

// 场景的导出设置
typedef struct _SV_SCENEEXPORTCONFIG {
	CSVWString	_strPath;			// 导出的路径
	IKS_UINT	_uStartFrameID;			// 导出的起始帧号
	IKS_UINT	_uFrameSize;			// 导出的帧长

	IKS_BOOL	_bIsExportMtl;			// 是否导出材质数据
	IKS_BOOL	_bIsExportAnnot;		// 是否导出标注数据
	IKS_BOOL	_bIsExportAnim;			// 是否导出动画数据
	IKS_BOOL	_bIsExportCamera;		// 是否导出摄像机数据(包括摄像机动画)
	IKS_BOOL	_bIsExportTimeNode;		// 是否导出时间节点(工艺规程)数据

	_SV_SCENEEXPORTCONFIG()
	{
		_strPath = L"";
		_uStartFrameID = 0;
		_uFrameSize = 100;
		_bIsExportMtl = TRUE;
		_bIsExportAnnot = TRUE;
		_bIsExportAnim = TRUE;
		_bIsExportCamera = TRUE;
		_bIsExportTimeNode = TRUE;
	}
	_SV_SCENEEXPORTCONFIG(const _SV_SCENEEXPORTCONFIG& config)
	{
		_strPath = config._strPath;
		_uStartFrameID = config._uStartFrameID;
		_uFrameSize = config._uFrameSize;
		_bIsExportMtl = config._bIsExportMtl;
		_bIsExportAnnot = config._bIsExportAnnot;
		_bIsExportAnim = config._bIsExportAnim;
		_bIsExportCamera = config._bIsExportCamera;
		_bIsExportTimeNode = config._bIsExportTimeNode;
	}
	_SV_SCENEEXPORTCONFIG& operator = (const _SV_SCENEEXPORTCONFIG& config)
	{
		if (this == &config) // 如果自己给自己赋值则直接返回
			return *this;
		_strPath = config._strPath;
		_uStartFrameID = config._uStartFrameID;
		_uFrameSize = config._uFrameSize;
		_bIsExportMtl = config._bIsExportMtl;
		_bIsExportAnnot = config._bIsExportAnnot;
		_bIsExportAnim = config._bIsExportAnim;
		_bIsExportCamera = config._bIsExportCamera;
		_bIsExportTimeNode = config._bIsExportTimeNode;
		return *this;
	}
	void Clear()
	{
		_strPath = L"";
		_uStartFrameID = 0;
		_uFrameSize = 100;
		_bIsExportMtl = TRUE;
		_bIsExportAnnot = TRUE;
		_bIsExportAnim = TRUE;
		_bIsExportCamera = TRUE;
		_bIsExportTimeNode = TRUE;
	}
} SV_SCENEEXPORTCONFIG;

// 场景的导入设置
typedef struct _SV_SCENEIMPORTCONFIG {
	CSVWString	_strPath;			// 导入的文档路径
	IKS_UINT	_uParentTreeNodeID;		// 导入场景模型所在的模型树父节点ID
	IKS_UINT	_uStartFrameID;			// 导入的起始帧号
	int		_nMergeModelMode;		// 合并模型的模式
	IKS_BOOL	_bIsMergeObjTreeNodeParam;			// 是否合并模型树节点参数
	IKS_BOOL	_bIsReplaceObjTreeNodeAnnotBlock;	// 是否替换模型树节点对应的标注块
	IKS_BOOL	_bIsReplaceOriMdlTreeNodeID;		// 是否替换模型树节点的原始标识
	IKS_BOOL	_bIsImportMtl;			// 是否导入材质数据
	IKS_BOOL	_bIsImportAnnot;		// 是否导入标注数据
	IKS_BOOL	_bIsImportAnim;			// 是否导入动画数据
	IKS_BOOL	_bIsImportCamera;		// 是否导入摄像机数据(包括摄像机动画)
	IKS_BOOL	_bIsImportTimeNode;		// 是否导入时间节点(工艺规程)数据

	_SV_SCENEIMPORTCONFIG()
	{
		_strPath = L"";
		_uParentTreeNodeID = INVALID_ID;
		_uStartFrameID = 0;
		_nMergeModelMode = BPSIMDLMERGEMODE_NOMERGE;
		_bIsMergeObjTreeNodeParam = TRUE;
		_bIsReplaceObjTreeNodeAnnotBlock = TRUE;
		_bIsReplaceOriMdlTreeNodeID = FALSE;
		_bIsImportMtl = TRUE;
		_bIsImportAnnot = TRUE;
		_bIsImportAnim = TRUE;
		_bIsImportCamera = TRUE;
		_bIsImportTimeNode = TRUE;
	}
	_SV_SCENEIMPORTCONFIG(const _SV_SCENEIMPORTCONFIG& config)
	{
		_strPath = config._strPath;
		_uParentTreeNodeID = config._uParentTreeNodeID;
		_uStartFrameID = config._uStartFrameID;
		_nMergeModelMode = config._nMergeModelMode;
		_bIsMergeObjTreeNodeParam = config._bIsMergeObjTreeNodeParam;
		_bIsReplaceObjTreeNodeAnnotBlock = config._bIsReplaceObjTreeNodeAnnotBlock;
		_bIsReplaceOriMdlTreeNodeID = config._bIsReplaceOriMdlTreeNodeID;
		_bIsImportMtl = config._bIsImportMtl;
		_bIsImportAnnot = config._bIsImportAnnot;
		_bIsImportAnim = config._bIsImportAnim;
		_bIsImportCamera = config._bIsImportCamera;
		_bIsImportTimeNode = config._bIsImportTimeNode;
	}
	_SV_SCENEIMPORTCONFIG& operator = (const _SV_SCENEIMPORTCONFIG& config)
	{
		if (this == &config) // 如果自己给自己赋值则直接返回
			return *this;
		_strPath = config._strPath;
		_uParentTreeNodeID = config._uParentTreeNodeID;
		_uStartFrameID = config._uStartFrameID;
		_nMergeModelMode = config._nMergeModelMode;
		_bIsMergeObjTreeNodeParam = config._bIsMergeObjTreeNodeParam;
		_bIsReplaceObjTreeNodeAnnotBlock = config._bIsReplaceObjTreeNodeAnnotBlock;
		_bIsReplaceOriMdlTreeNodeID = config._bIsReplaceOriMdlTreeNodeID;
		_bIsImportMtl = config._bIsImportMtl;
		_bIsImportAnnot = config._bIsImportAnnot;
		_bIsImportAnim = config._bIsImportAnim;
		_bIsImportCamera = config._bIsImportCamera;
		_bIsImportTimeNode = config._bIsImportTimeNode;
		return *this;
	}
	void Clear()
	{
		_strPath = L"";
		_uParentTreeNodeID = INVALID_ID;
		_uStartFrameID = 0;
		_nMergeModelMode = BPSIMDLMERGEMODE_NOMERGE;
		_bIsMergeObjTreeNodeParam = TRUE;
		_bIsReplaceObjTreeNodeAnnotBlock = TRUE;
		_bIsReplaceOriMdlTreeNodeID = FALSE;
		_bIsImportMtl = TRUE;
		_bIsImportAnnot = TRUE;
		_bIsImportAnim = TRUE;
		_bIsImportCamera = TRUE;
		_bIsImportTimeNode = TRUE;
	}
} SV_SCENEIMPORTCONFIG;

// 场景的导入结果
typedef struct _SV_SCENEIMPORTRESULT {
	IKS_BOOL	_bResult;
	IKS_UINT	_uImportTreeRootNodeID;

	_SV_SCENEIMPORTRESULT()
	{
		_bResult = FALSE;
		_uImportTreeRootNodeID = INVALID_ID;
	}
	_SV_SCENEIMPORTRESULT(const _SV_SCENEIMPORTRESULT& config)
	{
		_bResult = config._bResult;
		_uImportTreeRootNodeID = config._uImportTreeRootNodeID;
	}
	_SV_SCENEIMPORTRESULT& operator = (const _SV_SCENEIMPORTRESULT& config)
	{
		if (this == &config) // 如果自己给自己赋值则直接返回
			return *this;
		_bResult = config._bResult;
		_uImportTreeRootNodeID = config._uImportTreeRootNodeID;
		return *this;
	}
	void Clear()
	{
		_bResult = FALSE;
		_uImportTreeRootNodeID = INVALID_ID;
	}
} SV_SCENEIMPORTRESULT;
