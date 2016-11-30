//===================================================================================================
// File:
//		SVPublicDef.h
// Summary:
//		Define public class/struct, enum, macro and so on.
// Usage:
//		定义公共数据；用于渲染模块、场景模块、存储模块等的数据定义
// Remarks:
//		Null
// Date:
//		2012-7-19
// Author:
//		Shiping Wang
//===================================================================================================

#pragma once

//===================================================================================================
// 头文件
#include <vector>
#include "SVBaseDef.h"


//===================================================================================================
// 数学常量


//===================================================================================================
// 宏定义
#define FLOATNUMPERMDLVERTEX 8
#define POSOFFSETOFMDLVERTEX 0
#define NORMOFFSETOFMDLVERTEX 3
#define TEXOFFSETOFMDLVERTEX 6
#define INDEXNUMPERMDLFACE 3
#define INDEXNUMPERMDLLINE 2

// 用户物件的透明渲染序号（取值范围1000~10000）
#define BP_USEROBJ_ALPHABLENDRENDERSERIALNUM_BEGIN 1000
#define BP_USEROBJ_ALPHABLENDRENDERSERIALNUM_DEFAULT 1003
#define BP_USEROBJ_ALPHABLENDRENDERSERIALNUM_END 10000

//===================================================================================================
// 枚举类型定义

// 文件类型
typedef enum _BPFILETYPE
{
	BP_FILE_UNKOWN			= 0,		// 未知类型
	BP_FILE_MODEL			= 1,		// 模型文件
	BP_FILE_IMAGE			= 3,		// 图像文件
	BP_FILE_AUDIO			= 2,		// 音频文件
	BP_FILE_DOCUMENT		= 4,		// 文档文件
	BP_FILE_VIDEO			= 5,		// 视频文件
} BPFILETYPE;

// 文件的操作类型
typedef enum _BPFILEOPTYPE
{
	BPFILEOP_INVALID			= 0,	// 无效类型
	BPFILEOP_READ				= 1,	// 读取类型
	BPFILEOP_CREATE				= 2,	// 创建(修改)类型
	BPFILEOP_DEL				= 3,	// 删除类型
} BPFILEOPTYPE;

// 权利类型
typedef enum __tagRIGHTTYPE
{
	SECT_NULL				= 0,
	SECT_OPEN				= 1,	// 观看，对于SVF文件的打开
	SECT_PLAY				= 2,	// 播放，对于SVF文件的播放
	SECT_EXPORT				= 3,	// 导出，允许将SVF导出视频或图像
	SECT_ANIMATION			= 4,	// 动画，允许编辑三维模型动画
	SECT_CAMERA				= 5,	// 摄像机，允许编辑摄像机动画
	SECT_MATERIAL			= 6,	// 材质，允许编辑三维模型材质
	SECT_TRANSPARECNCY		= 7,	// 透明度动画，允许编辑三维模型透明度动画
	SECT_ANNOTATE			= 8,	// 注释，允许添加或修改注释
} RIGHTTYPE;

// 坐标系类型
typedef enum _BPCOORDSYSTYPE
{
	BPCST_NULL				= 0,	// 无效类型
	BPCST_LEFTHAND			= 1,	// 左手坐标系
	BPCST_RIGHTHAND			= 2,	// 右手坐标系
} BPCOORDSYSTYPE;

// 渲染实体填充方式
typedef enum _BPFILLMODE {
	BPFILL_INVISIBLE     = 0,	// 不可见
	BPFILL_POINT         = 1,	// 点
	BPFILL_WIREFRAME     = 2,	// 线框
	BPFILL_SOLID         = 3,	// 实体
} BPFILLMODE;

// 渲染剪裁方式
typedef enum _BPCULLMODE {
	BPCULL_NONE          = 1,
	BPCULL_CW            = 2,
	BPCULL_CCW           = 3,
} BPCULLMODE;

// 材质类型
typedef enum _BPMATERIALTYPE {
	BPMTLTYPE_PHYSICS	= 0,	// 自然材质
	BPMTLTYPE_PICTURE	= 1,	// 单纹理图像
	BPMTLTYPE_PURECOLOR	= 2,	// 纯色
} BPMATERIALTYPE;

// 灯光类型
typedef enum _BPLIGHTTYPE {
	BPLT_POINT         = 1,		// 点光源
	BPLT_SPOT          = 2,		// 聚光灯
	BPLT_DIRECTIONAL   = 3,		// 平行光
} BPLIGHTTYPE;

// 渲染背景类型
typedef enum _RENDERBACKGROUNDTYPE {
	BPRBGT_INVALID			 = 0,		// 无效类型
	BPRBGT_PURECOLOR         = 1,		// 纯色
	BPRBGT_PICTURE			 = 2,		// 单一背景图
	BPRBGT_SKYBOX	         = 3,		// 天空盒
} RENDERBACKGROUNDTYPE;

// 摄像机投影类型
typedef enum _BPCAMERAPROJECTTYPE
{
	BPCP_NULL				= 0,	// 无效类型
	BPCP_ORTHO				= 1,	// 平行投影
	BPCP_PERSPECTIVE		= 2,	// 透视投影
} BPCAMERAPROJECTTYPE;

// 摄像机上方向类型
typedef enum _SVCAMERAUPTYPE {
	SVCUT_INVALID			= 0,		// 无效类型
	SVCUT_X					= 1,		// X正向为上方向
	SVCUT_Y					= 2,		// Y正向为上方向
	SVCUT_Z					= 3,		// Z正向为上方向
	SVCUT_NX				= 4,		// X负向为上方向
	SVCUT_NY				= 5,		// Y负向为上方向
	SVCUT_NZ				= 6,		// Z负向为上方向
} SVCAMERAUPTYPE;

// 更改摄像机宽高比模式
typedef enum _SVCHANGECAMERAASPECTMODE {
	SVCCAT_INVALID					= 0,		// 无效类型
	SVCCAT_USESTANDARDASPECT		= 1,		// 使用标准宽高比(当实际屏幕宽高比发生改变时，表现为拉伸缩放效果)
	SVCCAT_CHANGEASPECT				= 2,		// 改变宽高比(当实际屏幕宽高比小于标准宽高比时，表现为剪裁屏幕两端的效果)
	SVCCAT_CHANGEASPECTANDFOVY		= 3,		// 改变宽高比和Y方向的视角(当实际屏幕宽高比发生改变时，表现为显示更多场景的效果)
} SVCHANGECAMERAASPECTMODE;

// 场景元素类型
typedef enum _SVSCENEELEMENTTYPE
{
	SVSCENEELEMT_UNKNOWN			= 0,			// 未知类型
	SVSCENEELEMT_OBJECT				= 1,			// 物件
	SVSCENEELEMT_ANNOTATION			= 2,			// 标注
	SVSCENEELEMT_OBJ_SURFGRP		= 3,			// 物件曲面组
	SVSCENEELEMT_OBJ_CURVEGRP		= 4,			// 物件曲线组
	SVSCENEELEMT_ANNOT_FREE			= 5,			// 自由标注
	SVSCENEELEMT_ANNOT_MDL			= 6,			// 模型标注
	SVSCENEELEMT_OBJ_FEATPOINTGRP	= 7,			// 物件特征点组
	SVSCENEELEMT_OBJ_SURFPOINTGRP	= 8,			// 物件曲面点组

	SVSCENEELEMT_CUSTOM				= 1000,			// 自定义类型(即系统预留1000以前的类型)
} SVSCENEELEMENTTYPE;

// 点类型
typedef enum _BPPOINTTYPE
{
	BPPOINTTYPE_UNKOWN			= 0,	// 未知类型
	BPPOINTTYPE_FREE			= 1,	// 自由点
// 	BPPOINTTYPE_CURVEPOINT		= 10,	// 曲线上一点
	BPPOINTTYPE_CURVESTART		= 11,	// 曲线起始端点
	BPPOINTTYPE_CURVEEND		= 12,	// 曲线终止端点
	BPPOINTTYPE_CURVECENTER		= 13,	// 曲线中心点
// 	BPPOINTTYPE_SURFACEPOINT	= 40,	// 曲面上一点
// 	BPPOINTTYPE_SURFACECENTER	= 41,	// 曲面中心点
} BPPOINTTYPE;

// 模型后续动作关键帧更新类型(当某个动作变更时其后续动作的更新类型)
typedef enum _SVSceneObjSubsequentMovKeyFrmUpdateType
{
	SVSOSMKUPDATETYPE_UNKNOWN			= 0,			// 未知类型
	SVSOSMKUPDATETYPE_KEEPPOSITION		= 1,			// 保持位置不变
	SVSOSMKUPDATETYPE_KEEPLOCALMOV		= 2,			// 保持局部动作不变
	SVSOSMKUPDATETYPE_KEEPGLOBALMOV		= 3,			// 保持局部动作不变
	SVSOSMKUPDATETYPE_KEEPORIGINALMOV	= 4,			// 保持原始动作不变
} SVSceneObjSubsequentMovKeyFrmUpdateType;

// 模型来源类型
typedef enum _BPMODELSRCTYPE
{
	BP_MDLSRC_UNKOWN		= 0,		// 未知类型
	BP_MDLSRC_PROE			= 1,		// ProE模型
	BP_MDLSRC_CATIA			= 2,		// Catia模型
	BP_MDLSRC_UG			= 3,		// UG模型
	BP_MDLSRC_SOLIDWORKS	= 4,		// SolidWorks模型
	BP_MDLSRC_3DSMAX		= 5,		// 3dsMax模型
} BPMODELSRCTYPE;

// 模型子集类型
typedef enum _BPMDLSUBSETTYPE
{
	BP_MDLSUBSET_UNKOWN		= 0,		// 未知类型
	BP_MDLSUBSET_SURFACE	= 1,		// 曲面类型
	BP_MDLSUBSET_CURVE		= 2,		// 曲线类型
} BPMDLSUBSETTYPE;

// 图元类型
typedef enum _BPPRIMITIVETYPE
{
	BPPT_NULL				= 0,
	BPPT_POINTLIST			= 1,
	BPPT_LINELIST			= 2,
	BPPT_LINESTRIP			= 3,
	BPPT_TRIANGLELIST		= 4,
	BPPT_TRIANGLESTRIP		= 5,
	BPPT_TRIANGLEFAN		= 6,
} BPPRIMITIVETYPE;

// 直线类型
typedef enum _BPLINEPATTERN
{
	BPLINEP_UNKOWN							= 0,
	BPLINEP_FULLLINE						= 1,		// 实线
	BPLINEP_DASHLINE						= 2,		// 虚线
	BPLINEP_DASHINTERVALLINE				= 3,		// 间隔画线
	BPLINEP_DASHDOTLINE						= 4,		// 点画线
	BPLINEP_DOUBLEDASHDOTLINE				= 5,		// 双点画线
	BPLINEP_TRIDASHDOTLINE					= 6,		// 三点画线
	BPLINEP_DOTLINE							= 7,		// 点线
	BPLINEP_LONGSHORTDASHLINE				= 8,		// 长画短画线
	BPLINEP_LONGDOUBLESHORTDASHLINE			= 9,		// 长画双短画线
	BPLINEP_DASHDOTLINE2					= 10,		// 画点线
	BPLINEP_DOUBLEDASHDOTLINE2				= 11,		// 双画单点线
	BPLINEP_DASHDOUBLEDOTLINE2				= 12,		// 画双点线
	BPLINEP_DOUBLEDASHDOUBLEDOTLINE2		= 13,		// 双画双点线
	BPLINEP_DASHTRIDOTLINE2					= 14,		// 画三点线
	BPLINEP_DOUBLEDASHTRIDOTLINE2			= 15,		// 双画三点线
} BPLINEPATTERN;

// 鼠标操作类型
typedef enum _BPMOUSEOPERATIONTYPE
{
	BPMOT_NULL								= 0,
	BPMOT_DEFAULT							= 1,
	BPMOT_LBTNDOWN							= 10,
	BPMOT_LBTNDOWN_CTRL						= 11,
	BPMOT_LBTNDOWN_SHIFT					= 12,
	BPMOT_LBTNDOWN_ALT						= 13,
	BPMOT_LBTNDOWN_CTRLSHIFT				= 14,
	BPMOT_LBTNDRAG							= 20,
	BPMOT_LBTNDRAG_CTRL						= 21,
	BPMOT_LBTNDRAG_SHIFT					= 22,
	BPMOT_LBTNDRAG_ALT						= 23,
	BPMOT_LBTNDRAG_CTRLSHIFT				= 24,
	BPMOT_RBTNDOWN							= 30,
	BPMOT_RBTNDOWN_CTRL						= 31,
	BPMOT_RBTNDOWN_SHIFT					= 32,
	BPMOT_RBTNDOWN_ALT						= 33,
	BPMOT_RBTNDOWN_CTRLSHIFT				= 34,
	BPMOT_RBTNDRAG							= 40,
	BPMOT_RBTNDRAG_CTRL						= 41,
	BPMOT_RBTNDRAG_SHIFT					= 42,
	BPMOT_RBTNDRAG_ALT						= 43,
	BPMOT_RBTNDRAG_CTRLSHIFT				= 44,
	BPMOT_MBTNDOWN							= 50,
	BPMOT_MBTNDOWN_CTRL						= 51,
	BPMOT_MBTNDOWN_SHIFT					= 52,
	BPMOT_MBTNDOWN_ALT						= 53,
	BPMOT_MBTNDOWN_CTRLSHIFT				= 54,
	BPMOT_MBTNDRAG							= 60,
	BPMOT_MBTNDRAG_CTRL						= 61,
	BPMOT_MBTNDRAG_SHIFT					= 62,
	BPMOT_MBTNDRAG_ALT						= 63,
	BPMOT_MBTNDRAG_CTRLSHIFT				= 64,
	BPMOT_MOUSEWHEEL						= 70,
	BPMOT_MOUSEWHEEL_CTRL					= 71,
	BPMOT_MOUSEWHEEL_SHIFT					= 72,
	BPMOT_MOUSEWHEEL_ALT					= 73,
	BPMOT_MOUSEWHEEL_CTRLSHIFT				= 74,
} BPMOUSEOPERATIONTYPE;

//===================================================================================================
// 结构体定义

// 文件信息
typedef struct __tagResFileInfo
{
	IKS_UINT		uResID;						// 资源ID
	int			nType;						// 文件类型
	wchar_t		stzFileName[BP_MAX_PATH];	// 文件名称
	CSVWString	strFileDigest;				// 文件摘要

	__tagResFileInfo()
	{
		uResID = INVALID_ID;
		nType = BP_FILE_UNKOWN;
		memset(stzFileName, 0, sizeof(wchar_t)*BP_MAX_PATH);
		strFileDigest = L"";
	}
	__tagResFileInfo(const __tagResFileInfo &data)
	{
		uResID = data.uResID;
		nType = data.nType;
		wcsncpy_s(stzFileName, BP_MAX_PATH, data.stzFileName, _TRUNCATE);
		strFileDigest = data.strFileDigest;
	}
	__tagResFileInfo &operator=(const __tagResFileInfo& data){
		if (&data != this)
		{
			uResID = data.uResID;
			nType = data.nType;
			wcsncpy_s(stzFileName, BP_MAX_PATH, data.stzFileName, _TRUNCATE);
			strFileDigest = data.strFileDigest;
		}
		return *this;
	}
	void Clear()
	{
		uResID = INVALID_ID;
		nType = BP_FILE_UNKOWN;
		memset(stzFileName, 0, sizeof(wchar_t)*BP_MAX_PATH);
		strFileDigest = L"";
	}
} ResFileInfo;

// 权利类表
typedef struct __tagSECURITYINFO
{
	wchar_t szVersion[BP_MAX_PATH];			// 版本号
	wchar_t szID[BP_MAX_PATH];				// 安全性唯一标识
	wchar_t szAdminPassword[BP_MAX_PATH];	// 管理员密码
	wchar_t szUserPassword[BP_MAX_PATH];	// 基本用户密码
	std::vector<RIGHTTYPE> vecRightInfo;	// 权利类型

	bool	bControl;						// 是否有时间控制
	IKS_DWORD dwStartTime;						// 起始时间，格式：20140728
	IKS_DWORD dwEndTime;						// 结束时间，格式：20150728

	__tagSECURITYINFO()
	{
		Clear();
	}
	__tagSECURITYINFO(const __tagSECURITYINFO &data)
	{
		wcsncpy_s(szVersion, BP_MAX_PATH, data.szVersion, _TRUNCATE);
		wcsncpy_s(szID, BP_MAX_PATH, data.szID, _TRUNCATE);
		wcsncpy_s(szAdminPassword, BP_MAX_PATH, data.szAdminPassword, _TRUNCATE);
		wcsncpy_s(szUserPassword, BP_MAX_PATH, data.szUserPassword, _TRUNCATE);
		vecRightInfo.clear();
		for (int i = 0; i < (int)data.vecRightInfo.size(); i++)
			vecRightInfo.push_back(data.vecRightInfo[i]);

		bControl = data.bControl;
		dwStartTime = data.dwStartTime;
		dwEndTime = data.dwEndTime;
	}
	__tagSECURITYINFO &operator=(const __tagSECURITYINFO& data)
	{
		if (&data != this)
		{
			wcsncpy_s(szVersion, BP_MAX_PATH, data.szVersion, _TRUNCATE);
			wcsncpy_s(szID, BP_MAX_PATH, data.szID, _TRUNCATE);
			wcsncpy_s(szAdminPassword, BP_MAX_PATH, data.szAdminPassword, _TRUNCATE);
			wcsncpy_s(szUserPassword, BP_MAX_PATH, data.szUserPassword, _TRUNCATE);
			vecRightInfo.clear();
			for (int i = 0; i < (int)data.vecRightInfo.size(); i++)
				vecRightInfo.push_back(data.vecRightInfo[i]);

			bControl = data.bControl;
			dwStartTime = data.dwStartTime;
			dwEndTime = data.dwEndTime;
		}
		return *this;
	}
	void Clear()
	{
		wcsncpy_s(szVersion, BP_MAX_PATH, L"1.0.0", _TRUNCATE);
		memset(szID, 0, sizeof(wchar_t)*BP_MAX_PATH);
		memset(szAdminPassword, 0, sizeof(wchar_t)*BP_MAX_PATH);
		memset(szUserPassword, 0, sizeof(wchar_t)*BP_MAX_PATH);
		bControl = false;
		dwStartTime = 0;
		dwEndTime = 0;

		vecRightInfo.clear();
	}

} SECURITYINFO;

// 产品信息
typedef struct __tagProductInfo
{
	BPBASEFLOAT3		vCenterOfMass;		// 质心
	double				dMass;				// 质量
	double				dVolume;			// 体积
	double				dSurfaceArea;		// 表面积

	__tagProductInfo()
	{
		vCenterOfMass.x = vCenterOfMass.y = vCenterOfMass.z = 0.0f;
		dMass = 0.0;
		dVolume = 0.0;
		dSurfaceArea = 0.0;
	}
	__tagProductInfo(const __tagProductInfo &data)
	{
		vCenterOfMass = data.vCenterOfMass;
		dMass = data.dMass;
		dVolume = data.dVolume;
		dSurfaceArea = data.dSurfaceArea;
	}
	__tagProductInfo &operator=(const __tagProductInfo& data){
		if (&data != this)
		{
			vCenterOfMass = data.vCenterOfMass;
			dMass = data.dMass;
			dVolume = data.dVolume;
			dSurfaceArea = data.dSurfaceArea;
		}
		return *this;
	}
	void Clear()
	{
		vCenterOfMass.x = vCenterOfMass.y = vCenterOfMass.z = 0.0f;
		dMass = 0.0;
		dVolume = 0.0;
		dSurfaceArea = 0.0;
	}
} ProductInfo;

// 立方体包围盒
typedef struct _BOUNDBOX
{
	BPBASEFLOAT3 _min;
	BPBASEFLOAT3 _max;
} BOUNDBOX;

// 球形包围盒
typedef struct _BOUNDSPHERE
{
	BPBASEFLOAT3 _center;
	float     _radius;
} BOUNDSPHERE;

// 坐标系
typedef struct _SVCOORDSYSTEM
{
	BPBASEFLOAT3 _vOrigin;	// 坐标系原点
	BPBASEFLOAT3 _vAxisX;	// 坐标系X轴向量
	BPBASEFLOAT3 _vAxisY;	// 坐标系Y轴向量(坐标系Z轴向量,由X向量叉乘Y向量获得)
} SVCOORDSYSTEM;

// 坐标系
typedef struct _SVCOORDSYSTEMD
{
	SVBASEDOUBLE3 _vOrigin;	// 坐标系原点
	SVBASEDOUBLE3 _vAxisX;	// 坐标系X轴向量
	SVBASEDOUBLE3 _vAxisY;	// 坐标系Y轴向量(坐标系Z轴向量,由X向量叉乘Y向量获得)
} SVCOORDSYSTEMD;

// 渲染实体组的渲染状态
typedef struct _BPOBJGRPRENDERSTATE {
	IKS_BOOL _bZEnable;					// 是否开启深度缓存ZBuff(不开启则没有遮挡关系效果)
	IKS_BOOL _bZWriteEnable;			// 是否开启深度缓存ZBuff(不开启则没有遮挡关系效果)
	IKS_BOOL _bAlphaBlendEnable;		// 是否开启透明度混合
	BPFILLMODE _eFillMode;			// 渲染实体填充方式
	IKS_BOOL _bUseSceneLight;			// 是否使用场景灯光
	BPCULLMODE _eCullMode;			// 渲染剪裁方式
} BPOBJGRPRENDERSTATE;

// 自然材质
typedef struct _BPMATERIALPHYSICS {
	BPBASEFLOAT4	vDiffuse;        /* Diffuse color RGBA */
	BPBASEFLOAT4	vAmbient;        /* Ambient color RGB */
	BPBASEFLOAT4	vSpecular;       /* Specular 'shininess' */
	BPBASEFLOAT4	vEmissive;       /* Emissive color RGB */
	float	fPower;				/* Sharpness if specular highlight */
} BPMATERIALPHYSICS;

// 材质
typedef struct _BPMATERIAL
{
	BPMATERIALTYPE			_eMtlType;				// 材质类型
	BPMATERIALPHYSICS		_mtlPhysics;			// 自然材质
	std::vector<IKS_UINT>			_arrTexID;			// 纹理材质ID
	std::vector<BPBASEFLOAT4>	_arrData;			// 纹理数据
	_BPMATERIAL()
	{
		_eMtlType = BPMTLTYPE_PHYSICS;
	}
	_BPMATERIAL(const _BPMATERIAL &data)
	{
		_eMtlType = data._eMtlType;
		_mtlPhysics = data._mtlPhysics;
		_arrTexID = data._arrTexID;
		_arrData = data._arrData;
	}
	_BPMATERIAL &operator=(const _BPMATERIAL& data){
		if (&data != this)
		{
			_eMtlType = data._eMtlType;
			_mtlPhysics = data._mtlPhysics;
			_arrTexID = data._arrTexID;
			_arrData = data._arrData;
		}
		return *this;
	}
} BPMATERIAL;

// 渲染背景
typedef struct _BPRENDERBACKGROUND {
	RENDERBACKGROUNDTYPE _eType;		// 背景类型
	BPBASEFLOAT4 _vColor;				// 背景颜色
	IKS_UINT _uTexID;						// 背景纹理的ID
	CSVWString	_strPicPath;			// 图片路径
	_BPRENDERBACKGROUND()
	{
		_eType = BPRBGT_INVALID;
		_vColor.x = _vColor.y = _vColor.z = _vColor.w = 0.0f;
		_uTexID = INVALID_ID;
		_strPicPath = L"";
	}
	_BPRENDERBACKGROUND(const _BPRENDERBACKGROUND& bk)
	{
		_eType = bk._eType;
		_vColor = bk._vColor;
		_uTexID = bk._uTexID;
		_strPicPath = bk._strPicPath;
	}
	_BPRENDERBACKGROUND& operator = (const _BPRENDERBACKGROUND& bk)
	{
		if (this == &bk)
			return *this;
		_eType = bk._eType;
		_vColor = bk._vColor;
		_uTexID = bk._uTexID;
		_strPicPath = bk._strPicPath;
		return *this;
	}
} BPRENDERBACKGROUND;

// 摄像机
typedef struct _BPCAMERA {
	BPBASEFLOAT3 _vEyePos;			// 摄像机位置
	BPBASEFLOAT3 _vFocus;			// 摄像机焦点
	BPBASEFLOAT3 _vUp;				// 摄像机上方向
	float _fFOVY;					// Y方向的视角
	float _fAspect;					// 宽高比
	float _fZNear;					// 近平面
	float _fZFar;					// 远平面
	float _fInterocularDistance;	// 目间距
} BPCAMERA;

// 灯光
typedef struct _BPLIGHT {
	BPLIGHTTYPE _eType;				// 灯光类型
	BPBASEFLOAT4 _vDiffuse;			// 漫反射光颜色
	BPBASEFLOAT4 _vSpecular;		// 平行光颜色
	BPBASEFLOAT4 _vAmbient;			// 环境光颜色
	BPBASEFLOAT3 _vPosition;		// 光源位置
	BPBASEFLOAT3 _vDirection;		// 光线方向
	float _fRange;
	float _fFalloff;
	float _fAttenuation0;
	float _fAttenuation1;
	float _fAttenuation2;
	float _fTheta;
	float _fPhi;
} BPLIGHT;

// 场景元素_物件曲面组
typedef struct _SVSCENEELEMENT_OBJSURFACEGRP
{
	IKS_UINT _uObjectID;						// 曲面所在的物件ID
	std::vector<IKS_UINT> _arrSubsetIndex;		// 曲面对应的子集索引(若曲面未对应一组三角片数据,则取值INVALID_ID)
	std::vector<IKS_UINT> _arrSurfaceIndex;		// 曲面索引(若曲面未对应精确数据,则取值INVALID_ID)
	_SVSCENEELEMENT_OBJSURFACEGRP()
	{
		_uObjectID = INVALID_ID;
	}
	_SVSCENEELEMENT_OBJSURFACEGRP(const _SVSCENEELEMENT_OBJSURFACEGRP &elem)
	{
		_uObjectID = elem._uObjectID;
		_arrSubsetIndex = elem._arrSubsetIndex;
		_arrSurfaceIndex = elem._arrSurfaceIndex;
	}
	_SVSCENEELEMENT_OBJSURFACEGRP &operator=(const _SVSCENEELEMENT_OBJSURFACEGRP& elem){
		if (&elem != this)
		{
			_uObjectID = elem._uObjectID;
			_arrSubsetIndex = elem._arrSubsetIndex;
			_arrSurfaceIndex = elem._arrSurfaceIndex;
		}
		return *this;
	}
	void Clear()
	{
		_uObjectID = INVALID_ID;
		_arrSubsetIndex.clear();
		_arrSurfaceIndex.clear();
	}
} SVSCENEELEMENT_OBJSURFACEGRP;

// 场景元素_物件曲线
typedef struct _SVSCENEELEMENT_OBJCURVEGRP
{
	IKS_UINT _uObjectID;						// 曲线所在的物件ID
// 	std::vector<IKS_UINT> _arrSubsetIndex;		// 曲线对应的子集索引(若曲线未对应一组折线数据,则取值INVALID_ID)
	std::vector<IKS_UINT> _arrCurveIndex;		// 曲线索引(若曲线未对应精确数据,则取值INVALID_ID)
// 	std::vector<IKS_UINT> _arrCurveHLObjID;		// 曲线对应的高亮物件ID(用于高亮显示该曲线)
	_SVSCENEELEMENT_OBJCURVEGRP()
	{
		_uObjectID = INVALID_ID;
	}
	_SVSCENEELEMENT_OBJCURVEGRP(const _SVSCENEELEMENT_OBJCURVEGRP &elem)
	{
		_uObjectID = elem._uObjectID;
// 		_arrSubsetIndex = elem._arrSubsetIndex;
		_arrCurveIndex = elem._arrCurveIndex;
// 		_arrCurveHLObjID = elem._arrCurveHLObjID;
	}
	_SVSCENEELEMENT_OBJCURVEGRP &operator=(const _SVSCENEELEMENT_OBJCURVEGRP& elem){
		if (&elem != this)
		{
			_uObjectID = elem._uObjectID;
// 			_arrSubsetIndex = elem._arrSubsetIndex;
			_arrCurveIndex = elem._arrCurveIndex;
// 			_arrCurveHLObjID = elem._arrCurveHLObjID;
		}
		return *this;
	}
	void Clear()
	{
		_uObjectID = INVALID_ID;
// 		_arrSubsetIndex.clear();
		_arrCurveIndex.clear();
// 		_arrCurveHLObjID.clear();
	}
} SVSCENEELEMENT_OBJCURVEGRP;

// 场景元素_物件特征点
typedef struct _SVSCENEELEMENT_OBJFEATUREPOINT
{
	IKS_UINT _uParentGeomIndex;					// 点所在的几何(曲线、曲面)的索引
	int _nPointType;						// 点类型,参看枚举型BPPOINTTYPE
	IKS_UINT _uPointIndex;						// 点索引
	_SVSCENEELEMENT_OBJFEATUREPOINT()
	{
		_uParentGeomIndex = INVALID_ID;
		_nPointType = BPPOINTTYPE_UNKOWN;
		_uPointIndex = INVALID_ID;
	}
	_SVSCENEELEMENT_OBJFEATUREPOINT(const _SVSCENEELEMENT_OBJFEATUREPOINT &pt)
	{
		_uParentGeomIndex = pt._uParentGeomIndex;
		_nPointType = pt._nPointType;
		_uPointIndex = pt._uPointIndex;
	}
	_SVSCENEELEMENT_OBJFEATUREPOINT &operator=(const _SVSCENEELEMENT_OBJFEATUREPOINT& pt){
		if (&pt != this)
		{
			_uParentGeomIndex = pt._uParentGeomIndex;
			_nPointType = pt._nPointType;
			_uPointIndex = pt._uPointIndex;
		}
		return *this;
	}
	IKS_BOOL operator == ( const _SVSCENEELEMENT_OBJFEATUREPOINT& pt ) const
	{
		if (_uParentGeomIndex != pt._uParentGeomIndex)
			return FALSE;
		if (_nPointType != pt._nPointType)
			return FALSE;
		if (_uPointIndex != pt._uPointIndex)
			return FALSE;
		return TRUE;
	}
	IKS_BOOL operator != ( const _SVSCENEELEMENT_OBJFEATUREPOINT& pt ) const
	{
		return (!(*this == pt));
	}
	void Clear()
	{
		_uParentGeomIndex = INVALID_ID;
		_nPointType = BPPOINTTYPE_UNKOWN;
		_uPointIndex = INVALID_ID;
	}
} SVSCENEELEMENT_OBJFEATUREPOINT;

// 场景元素_物件特征点
typedef struct _SVSCENEELEMENT_OBJFEATUREPOINTGRP
{
	IKS_UINT _uObjectID;											// 特征点所在的物件ID
	std::vector<SVSCENEELEMENT_OBJFEATUREPOINT> _arrPoint;		// 特征点
	_SVSCENEELEMENT_OBJFEATUREPOINTGRP()
	{
		_uObjectID = INVALID_ID;
	}
	_SVSCENEELEMENT_OBJFEATUREPOINTGRP(const _SVSCENEELEMENT_OBJFEATUREPOINTGRP &elem)
	{
		_uObjectID = elem._uObjectID;
		_arrPoint = elem._arrPoint;
	}
	_SVSCENEELEMENT_OBJFEATUREPOINTGRP &operator=(const _SVSCENEELEMENT_OBJFEATUREPOINTGRP& elem){
		if (&elem != this)
		{
			_uObjectID = elem._uObjectID;
			_arrPoint = elem._arrPoint;
		}
		return *this;
	}
	void Clear()
	{
		_uObjectID = INVALID_ID;
		_arrPoint.clear();
	}
} SVSCENEELEMENT_OBJFEATUREPOINTGRP;

// 场景元素_物件曲面点
typedef struct _SVSCENEELEMENT_OBJSURFACEPOINTGRP
{
	IKS_UINT _uObjectID;											// 曲面点所在的物件ID
	std::vector<BPBASEFLOAT3> _arrPoint;						// 曲面点位置(物件的局部空间坐标,乘以世界转换矩阵即可获得世界坐标)
	_SVSCENEELEMENT_OBJSURFACEPOINTGRP()
	{
		_uObjectID = INVALID_ID;
	}
	_SVSCENEELEMENT_OBJSURFACEPOINTGRP(const _SVSCENEELEMENT_OBJSURFACEPOINTGRP &elem)
	{
		_uObjectID = elem._uObjectID;
		_arrPoint = elem._arrPoint;
	}
	_SVSCENEELEMENT_OBJSURFACEPOINTGRP &operator=(const _SVSCENEELEMENT_OBJSURFACEPOINTGRP& elem){
		if (&elem != this)
		{
			_uObjectID = elem._uObjectID;
			_arrPoint = elem._arrPoint;
		}
		return *this;
	}
	void Clear()
	{
		_uObjectID = INVALID_ID;
		_arrPoint.clear();
	}
} SVSCENEELEMENT_OBJSURFACEPOINTGRP;

// 场景元素_综合数据信息
typedef struct _SVSCENEELEMENT_GENERAL
{
	int _nSceneElemType;										// 场景元素的类型,参考枚举型SVSCENEELEMENTTYPE
	IKS_UINT _uSceneElemID;											// 场景元素的ID
	std::vector<IKS_UINT> _arrSubsetGeomIndex;						// 子集或几何的索引
	std::vector<int> _arrSceneElemSubType;						// 场景元素的子类型
	std::vector<IKS_UINT> _arrSceneElemSubIndex;					// 场景元素的子索引
	std::vector<BPBASEFLOAT3> _arrSceneElemPos;					// 场景元素的位置(世界坐标系)
	_SVSCENEELEMENT_GENERAL()
	{
		_nSceneElemType = SVSCENEELEMT_UNKNOWN;
		_uSceneElemID = INVALID_ID;
	}
	_SVSCENEELEMENT_GENERAL(const _SVSCENEELEMENT_GENERAL &elem)
	{
		_nSceneElemType = elem._nSceneElemType;
		_uSceneElemID = elem._uSceneElemID;
		_arrSubsetGeomIndex = elem._arrSubsetGeomIndex;
		_arrSceneElemSubType = elem._arrSceneElemSubType;
		_arrSceneElemSubIndex = elem._arrSceneElemSubIndex;
		_arrSceneElemPos = elem._arrSceneElemPos;
	}
	_SVSCENEELEMENT_GENERAL &operator=(const _SVSCENEELEMENT_GENERAL& elem){
		if (&elem != this)
		{
			_nSceneElemType = elem._nSceneElemType;
			_uSceneElemID = elem._uSceneElemID;
			_arrSubsetGeomIndex = elem._arrSubsetGeomIndex;
			_arrSceneElemSubType = elem._arrSceneElemSubType;
			_arrSceneElemSubIndex = elem._arrSceneElemSubIndex;
			_arrSceneElemPos = elem._arrSceneElemPos;
		}
		return *this;
	}
	void Clear()
	{
		_nSceneElemType = SVSCENEELEMT_UNKNOWN;
		_uSceneElemID = INVALID_ID;
		_arrSubsetGeomIndex.clear();
		_arrSceneElemSubType.clear();
		_arrSceneElemSubIndex.clear();
		_arrSceneElemPos.clear();
	}
} SVSCENEELEMENT_GENERAL;

// 场景元素的信息
typedef struct _SVSCENEELEMINFO
{
	IKS_BOOL _bInfoValid_ObjectID;											// 信息有效性:物件ID
	std::vector<IKS_UINT> _arrObjectID;										// 物件ID
	IKS_BOOL _bInfoValid_AnnotationID;										// 信息有效性:标注ID
	std::vector<IKS_UINT> _arrAnnotationID;									// 标注ID
	IKS_BOOL _bInfoValid_ObjSurfaceGrp;										// 信息有效性:物件曲面组
	std::vector<SVSCENEELEMENT_OBJSURFACEGRP> _arrObjSurfaceGrp;		// 物件曲面组
	IKS_BOOL _bInfoValid_ObjCurveGrp;										// 信息有效性:物件曲线组
	std::vector<SVSCENEELEMENT_OBJCURVEGRP> _arrObjCurveGrp;			// 物件曲线组
	IKS_BOOL _bInfoValid_ObjFeatPtGrp;										// 信息有效性:物件特征点组
	std::vector<SVSCENEELEMENT_OBJFEATUREPOINTGRP> _arrObjFeatPtGrp;	// 物件特征点组
	IKS_BOOL _bInfoValid_ObjSurfPtGrp;										// 信息有效性:物件曲面点组
	std::vector<SVSCENEELEMENT_OBJSURFACEPOINTGRP> _arrObjSurfPtGrp;	// 物件曲面点组
// 	IKS_BOOL _bInfoValid_FreePtGrp;											// 信息有效性:自由点组
// 	std::vector<BPBASEFLOAT3> _arrFreePtGrp;							// 自由点组
	IKS_BOOL _bInfoValid_FreeAnnotID;										// 信息有效性:自由标注ID
	std::vector<IKS_UINT> _arrFreeAnnotID;									// 自由标注ID
	IKS_BOOL _bInfoValid_MdlAnnotID;										// 信息有效性:模型标注ID
	std::vector<IKS_UINT> _arrMdlAnnotID;									// 模型标注ID
	_SVSCENEELEMINFO()
	{
		InvalidAll();
	}
	_SVSCENEELEMINFO(const _SVSCENEELEMINFO &elem)
	{
		_bInfoValid_ObjectID = elem._bInfoValid_ObjectID;
		_arrObjectID = elem._arrObjectID;
		_bInfoValid_AnnotationID = elem._bInfoValid_AnnotationID;
		_arrAnnotationID = elem._arrAnnotationID;
		_bInfoValid_ObjSurfaceGrp = elem._bInfoValid_ObjSurfaceGrp;
		_arrObjSurfaceGrp = elem._arrObjSurfaceGrp;
		_bInfoValid_ObjCurveGrp = elem._bInfoValid_ObjCurveGrp;
		_arrObjCurveGrp = elem._arrObjCurveGrp;
		_bInfoValid_ObjFeatPtGrp = elem._bInfoValid_ObjFeatPtGrp;
		_arrObjFeatPtGrp = elem._arrObjFeatPtGrp;
		_bInfoValid_ObjSurfPtGrp = elem._bInfoValid_ObjSurfPtGrp;
		_arrObjSurfPtGrp = elem._arrObjSurfPtGrp;
		_bInfoValid_FreeAnnotID = elem._bInfoValid_FreeAnnotID;
		_arrFreeAnnotID = elem._arrFreeAnnotID;
		_bInfoValid_MdlAnnotID = elem._bInfoValid_MdlAnnotID;
		_arrMdlAnnotID = elem._arrMdlAnnotID;
	}
	_SVSCENEELEMINFO &operator=(const _SVSCENEELEMINFO& elem){
		if (&elem != this)
		{
			_bInfoValid_ObjectID = elem._bInfoValid_ObjectID;
			_arrObjectID = elem._arrObjectID;
			_bInfoValid_AnnotationID = elem._bInfoValid_AnnotationID;
			_arrAnnotationID = elem._arrAnnotationID;
			_bInfoValid_ObjSurfaceGrp = elem._bInfoValid_ObjSurfaceGrp;
			_arrObjSurfaceGrp = elem._arrObjSurfaceGrp;
			_bInfoValid_ObjCurveGrp = elem._bInfoValid_ObjCurveGrp;
			_arrObjCurveGrp = elem._arrObjCurveGrp;
			_bInfoValid_ObjFeatPtGrp = elem._bInfoValid_ObjFeatPtGrp;
			_arrObjFeatPtGrp = elem._arrObjFeatPtGrp;
			_bInfoValid_ObjSurfPtGrp = elem._bInfoValid_ObjSurfPtGrp;
			_arrObjSurfPtGrp = elem._arrObjSurfPtGrp;
			_bInfoValid_FreeAnnotID = elem._bInfoValid_FreeAnnotID;
			_arrFreeAnnotID = elem._arrFreeAnnotID;
			_bInfoValid_MdlAnnotID = elem._bInfoValid_MdlAnnotID;
			_arrMdlAnnotID = elem._arrMdlAnnotID;
		}
		return *this;
	}
	void Clear()
	{
		_bInfoValid_ObjectID = FALSE;
		_arrObjectID.clear();
		_bInfoValid_AnnotationID = FALSE;
		_arrAnnotationID.clear();
		_bInfoValid_ObjSurfaceGrp = FALSE;
		_arrObjSurfaceGrp.clear();
		_bInfoValid_ObjCurveGrp = FALSE;
		_arrObjCurveGrp.clear();
		_bInfoValid_ObjFeatPtGrp = FALSE;
		_arrObjFeatPtGrp.clear();
		_bInfoValid_ObjSurfPtGrp = FALSE;
		_arrObjSurfPtGrp.clear();
		_bInfoValid_FreeAnnotID = FALSE;
		_arrFreeAnnotID.clear();
		_bInfoValid_MdlAnnotID = FALSE;
		_arrMdlAnnotID.clear();
	}
	void InvalidAll()
	{
		_bInfoValid_ObjectID = FALSE;
		_bInfoValid_AnnotationID = FALSE;
		_bInfoValid_ObjSurfaceGrp = FALSE;
		_bInfoValid_ObjCurveGrp = FALSE;
		_bInfoValid_ObjFeatPtGrp = FALSE;
		_bInfoValid_ObjSurfPtGrp = FALSE;
		_bInfoValid_FreeAnnotID = FALSE;
		_bInfoValid_MdlAnnotID = FALSE;
	}
} SVSCENEELEMINFO;

// 模型子集组
typedef struct _MODELSUBSETGROUP
{
	int _nType;								// 组类型,例如面集、体、电缆等；保留参数,暂未使用
	std::vector<IKS_UINT> _arrSubsetIndex;		// 组内子集的索引
	_MODELSUBSETGROUP()
	{
		_nType = -1;
	}
	_MODELSUBSETGROUP(const _MODELSUBSETGROUP &grp)
	{
		_nType = grp._nType;
		_arrSubsetIndex = grp._arrSubsetIndex;
	}
	_MODELSUBSETGROUP &operator=(const _MODELSUBSETGROUP& grp){
		if (&grp != this)
		{
			_nType = grp._nType;
			_arrSubsetIndex = grp._arrSubsetIndex;
		}
		return *this;
	}
	void Clear()
	{
		_nType = -1;
		_arrSubsetIndex.clear();
	}
} MODELSUBSETGROUP;
