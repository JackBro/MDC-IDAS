//===================================================================================================
// File:
//		SVPublicDef.h
// Summary:
//		Define public class/struct, enum, macro and so on.
// Usage:
//		���幫�����ݣ�������Ⱦģ�顢����ģ�顢�洢ģ��ȵ����ݶ���
// Remarks:
//		Null
// Date:
//		2012-7-19
// Author:
//		Shiping Wang
//===================================================================================================

#pragma once

//===================================================================================================
// ͷ�ļ�
#include <vector>
#include "SVBaseDef.h"


//===================================================================================================
// ��ѧ����


//===================================================================================================
// �궨��
#define FLOATNUMPERMDLVERTEX 8
#define POSOFFSETOFMDLVERTEX 0
#define NORMOFFSETOFMDLVERTEX 3
#define TEXOFFSETOFMDLVERTEX 6
#define INDEXNUMPERMDLFACE 3
#define INDEXNUMPERMDLLINE 2

// �û������͸����Ⱦ��ţ�ȡֵ��Χ1000~10000��
#define BP_USEROBJ_ALPHABLENDRENDERSERIALNUM_BEGIN 1000
#define BP_USEROBJ_ALPHABLENDRENDERSERIALNUM_DEFAULT 1003
#define BP_USEROBJ_ALPHABLENDRENDERSERIALNUM_END 10000

//===================================================================================================
// ö�����Ͷ���

// �ļ�����
typedef enum _BPFILETYPE
{
	BP_FILE_UNKOWN			= 0,		// δ֪����
	BP_FILE_MODEL			= 1,		// ģ���ļ�
	BP_FILE_IMAGE			= 3,		// ͼ���ļ�
	BP_FILE_AUDIO			= 2,		// ��Ƶ�ļ�
	BP_FILE_DOCUMENT		= 4,		// �ĵ��ļ�
	BP_FILE_VIDEO			= 5,		// ��Ƶ�ļ�
} BPFILETYPE;

// �ļ��Ĳ�������
typedef enum _BPFILEOPTYPE
{
	BPFILEOP_INVALID			= 0,	// ��Ч����
	BPFILEOP_READ				= 1,	// ��ȡ����
	BPFILEOP_CREATE				= 2,	// ����(�޸�)����
	BPFILEOP_DEL				= 3,	// ɾ������
} BPFILEOPTYPE;

// Ȩ������
typedef enum __tagRIGHTTYPE
{
	SECT_NULL				= 0,
	SECT_OPEN				= 1,	// �ۿ�������SVF�ļ��Ĵ�
	SECT_PLAY				= 2,	// ���ţ�����SVF�ļ��Ĳ���
	SECT_EXPORT				= 3,	// ����������SVF������Ƶ��ͼ��
	SECT_ANIMATION			= 4,	// ����������༭��άģ�Ͷ���
	SECT_CAMERA				= 5,	// �����������༭���������
	SECT_MATERIAL			= 6,	// ���ʣ�����༭��άģ�Ͳ���
	SECT_TRANSPARECNCY		= 7,	// ͸���ȶ���������༭��άģ��͸���ȶ���
	SECT_ANNOTATE			= 8,	// ע�ͣ�������ӻ��޸�ע��
} RIGHTTYPE;

// ����ϵ����
typedef enum _BPCOORDSYSTYPE
{
	BPCST_NULL				= 0,	// ��Ч����
	BPCST_LEFTHAND			= 1,	// ��������ϵ
	BPCST_RIGHTHAND			= 2,	// ��������ϵ
} BPCOORDSYSTYPE;

// ��Ⱦʵ����䷽ʽ
typedef enum _BPFILLMODE {
	BPFILL_INVISIBLE     = 0,	// ���ɼ�
	BPFILL_POINT         = 1,	// ��
	BPFILL_WIREFRAME     = 2,	// �߿�
	BPFILL_SOLID         = 3,	// ʵ��
} BPFILLMODE;

// ��Ⱦ���÷�ʽ
typedef enum _BPCULLMODE {
	BPCULL_NONE          = 1,
	BPCULL_CW            = 2,
	BPCULL_CCW           = 3,
} BPCULLMODE;

// ��������
typedef enum _BPMATERIALTYPE {
	BPMTLTYPE_PHYSICS	= 0,	// ��Ȼ����
	BPMTLTYPE_PICTURE	= 1,	// ������ͼ��
	BPMTLTYPE_PURECOLOR	= 2,	// ��ɫ
} BPMATERIALTYPE;

// �ƹ�����
typedef enum _BPLIGHTTYPE {
	BPLT_POINT         = 1,		// ���Դ
	BPLT_SPOT          = 2,		// �۹��
	BPLT_DIRECTIONAL   = 3,		// ƽ�й�
} BPLIGHTTYPE;

// ��Ⱦ��������
typedef enum _RENDERBACKGROUNDTYPE {
	BPRBGT_INVALID			 = 0,		// ��Ч����
	BPRBGT_PURECOLOR         = 1,		// ��ɫ
	BPRBGT_PICTURE			 = 2,		// ��һ����ͼ
	BPRBGT_SKYBOX	         = 3,		// ��պ�
} RENDERBACKGROUNDTYPE;

// �����ͶӰ����
typedef enum _BPCAMERAPROJECTTYPE
{
	BPCP_NULL				= 0,	// ��Ч����
	BPCP_ORTHO				= 1,	// ƽ��ͶӰ
	BPCP_PERSPECTIVE		= 2,	// ͸��ͶӰ
} BPCAMERAPROJECTTYPE;

// ������Ϸ�������
typedef enum _SVCAMERAUPTYPE {
	SVCUT_INVALID			= 0,		// ��Ч����
	SVCUT_X					= 1,		// X����Ϊ�Ϸ���
	SVCUT_Y					= 2,		// Y����Ϊ�Ϸ���
	SVCUT_Z					= 3,		// Z����Ϊ�Ϸ���
	SVCUT_NX				= 4,		// X����Ϊ�Ϸ���
	SVCUT_NY				= 5,		// Y����Ϊ�Ϸ���
	SVCUT_NZ				= 6,		// Z����Ϊ�Ϸ���
} SVCAMERAUPTYPE;

// �����������߱�ģʽ
typedef enum _SVCHANGECAMERAASPECTMODE {
	SVCCAT_INVALID					= 0,		// ��Ч����
	SVCCAT_USESTANDARDASPECT		= 1,		// ʹ�ñ�׼��߱�(��ʵ����Ļ��߱ȷ����ı�ʱ������Ϊ��������Ч��)
	SVCCAT_CHANGEASPECT				= 2,		// �ı��߱�(��ʵ����Ļ��߱�С�ڱ�׼��߱�ʱ������Ϊ������Ļ���˵�Ч��)
	SVCCAT_CHANGEASPECTANDFOVY		= 3,		// �ı��߱Ⱥ�Y������ӽ�(��ʵ����Ļ��߱ȷ����ı�ʱ������Ϊ��ʾ���ೡ����Ч��)
} SVCHANGECAMERAASPECTMODE;

// ����Ԫ������
typedef enum _SVSCENEELEMENTTYPE
{
	SVSCENEELEMT_UNKNOWN			= 0,			// δ֪����
	SVSCENEELEMT_OBJECT				= 1,			// ���
	SVSCENEELEMT_ANNOTATION			= 2,			// ��ע
	SVSCENEELEMT_OBJ_SURFGRP		= 3,			// ���������
	SVSCENEELEMT_OBJ_CURVEGRP		= 4,			// ���������
	SVSCENEELEMT_ANNOT_FREE			= 5,			// ���ɱ�ע
	SVSCENEELEMT_ANNOT_MDL			= 6,			// ģ�ͱ�ע
	SVSCENEELEMT_OBJ_FEATPOINTGRP	= 7,			// �����������
	SVSCENEELEMT_OBJ_SURFPOINTGRP	= 8,			// ����������

	SVSCENEELEMT_CUSTOM				= 1000,			// �Զ�������(��ϵͳԤ��1000��ǰ������)
} SVSCENEELEMENTTYPE;

// ������
typedef enum _BPPOINTTYPE
{
	BPPOINTTYPE_UNKOWN			= 0,	// δ֪����
	BPPOINTTYPE_FREE			= 1,	// ���ɵ�
// 	BPPOINTTYPE_CURVEPOINT		= 10,	// ������һ��
	BPPOINTTYPE_CURVESTART		= 11,	// ������ʼ�˵�
	BPPOINTTYPE_CURVEEND		= 12,	// ������ֹ�˵�
	BPPOINTTYPE_CURVECENTER		= 13,	// �������ĵ�
// 	BPPOINTTYPE_SURFACEPOINT	= 40,	// ������һ��
// 	BPPOINTTYPE_SURFACECENTER	= 41,	// �������ĵ�
} BPPOINTTYPE;

// ģ�ͺ��������ؼ�֡��������(��ĳ���������ʱ����������ĸ�������)
typedef enum _SVSceneObjSubsequentMovKeyFrmUpdateType
{
	SVSOSMKUPDATETYPE_UNKNOWN			= 0,			// δ֪����
	SVSOSMKUPDATETYPE_KEEPPOSITION		= 1,			// ����λ�ò���
	SVSOSMKUPDATETYPE_KEEPLOCALMOV		= 2,			// ���־ֲ���������
	SVSOSMKUPDATETYPE_KEEPGLOBALMOV		= 3,			// ���־ֲ���������
	SVSOSMKUPDATETYPE_KEEPORIGINALMOV	= 4,			// ����ԭʼ��������
} SVSceneObjSubsequentMovKeyFrmUpdateType;

// ģ����Դ����
typedef enum _BPMODELSRCTYPE
{
	BP_MDLSRC_UNKOWN		= 0,		// δ֪����
	BP_MDLSRC_PROE			= 1,		// ProEģ��
	BP_MDLSRC_CATIA			= 2,		// Catiaģ��
	BP_MDLSRC_UG			= 3,		// UGģ��
	BP_MDLSRC_SOLIDWORKS	= 4,		// SolidWorksģ��
	BP_MDLSRC_3DSMAX		= 5,		// 3dsMaxģ��
} BPMODELSRCTYPE;

// ģ���Ӽ�����
typedef enum _BPMDLSUBSETTYPE
{
	BP_MDLSUBSET_UNKOWN		= 0,		// δ֪����
	BP_MDLSUBSET_SURFACE	= 1,		// ��������
	BP_MDLSUBSET_CURVE		= 2,		// ��������
} BPMDLSUBSETTYPE;

// ͼԪ����
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

// ֱ������
typedef enum _BPLINEPATTERN
{
	BPLINEP_UNKOWN							= 0,
	BPLINEP_FULLLINE						= 1,		// ʵ��
	BPLINEP_DASHLINE						= 2,		// ����
	BPLINEP_DASHINTERVALLINE				= 3,		// �������
	BPLINEP_DASHDOTLINE						= 4,		// �㻭��
	BPLINEP_DOUBLEDASHDOTLINE				= 5,		// ˫�㻭��
	BPLINEP_TRIDASHDOTLINE					= 6,		// ���㻭��
	BPLINEP_DOTLINE							= 7,		// ����
	BPLINEP_LONGSHORTDASHLINE				= 8,		// �����̻���
	BPLINEP_LONGDOUBLESHORTDASHLINE			= 9,		// ����˫�̻���
	BPLINEP_DASHDOTLINE2					= 10,		// ������
	BPLINEP_DOUBLEDASHDOTLINE2				= 11,		// ˫��������
	BPLINEP_DASHDOUBLEDOTLINE2				= 12,		// ��˫����
	BPLINEP_DOUBLEDASHDOUBLEDOTLINE2		= 13,		// ˫��˫����
	BPLINEP_DASHTRIDOTLINE2					= 14,		// ��������
	BPLINEP_DOUBLEDASHTRIDOTLINE2			= 15,		// ˫��������
} BPLINEPATTERN;

// ����������
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
// �ṹ�嶨��

// �ļ���Ϣ
typedef struct __tagResFileInfo
{
	IKS_UINT		uResID;						// ��ԴID
	int			nType;						// �ļ�����
	wchar_t		stzFileName[BP_MAX_PATH];	// �ļ�����
	CSVWString	strFileDigest;				// �ļ�ժҪ

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

// Ȩ�����
typedef struct __tagSECURITYINFO
{
	wchar_t szVersion[BP_MAX_PATH];			// �汾��
	wchar_t szID[BP_MAX_PATH];				// ��ȫ��Ψһ��ʶ
	wchar_t szAdminPassword[BP_MAX_PATH];	// ����Ա����
	wchar_t szUserPassword[BP_MAX_PATH];	// �����û�����
	std::vector<RIGHTTYPE> vecRightInfo;	// Ȩ������

	bool	bControl;						// �Ƿ���ʱ�����
	IKS_DWORD dwStartTime;						// ��ʼʱ�䣬��ʽ��20140728
	IKS_DWORD dwEndTime;						// ����ʱ�䣬��ʽ��20150728

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

// ��Ʒ��Ϣ
typedef struct __tagProductInfo
{
	BPBASEFLOAT3		vCenterOfMass;		// ����
	double				dMass;				// ����
	double				dVolume;			// ���
	double				dSurfaceArea;		// �����

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

// �������Χ��
typedef struct _BOUNDBOX
{
	BPBASEFLOAT3 _min;
	BPBASEFLOAT3 _max;
} BOUNDBOX;

// ���ΰ�Χ��
typedef struct _BOUNDSPHERE
{
	BPBASEFLOAT3 _center;
	float     _radius;
} BOUNDSPHERE;

// ����ϵ
typedef struct _SVCOORDSYSTEM
{
	BPBASEFLOAT3 _vOrigin;	// ����ϵԭ��
	BPBASEFLOAT3 _vAxisX;	// ����ϵX������
	BPBASEFLOAT3 _vAxisY;	// ����ϵY������(����ϵZ������,��X�������Y�������)
} SVCOORDSYSTEM;

// ����ϵ
typedef struct _SVCOORDSYSTEMD
{
	SVBASEDOUBLE3 _vOrigin;	// ����ϵԭ��
	SVBASEDOUBLE3 _vAxisX;	// ����ϵX������
	SVBASEDOUBLE3 _vAxisY;	// ����ϵY������(����ϵZ������,��X�������Y�������)
} SVCOORDSYSTEMD;

// ��Ⱦʵ�������Ⱦ״̬
typedef struct _BPOBJGRPRENDERSTATE {
	IKS_BOOL _bZEnable;					// �Ƿ�����Ȼ���ZBuff(��������û���ڵ���ϵЧ��)
	IKS_BOOL _bZWriteEnable;			// �Ƿ�����Ȼ���ZBuff(��������û���ڵ���ϵЧ��)
	IKS_BOOL _bAlphaBlendEnable;		// �Ƿ���͸���Ȼ��
	BPFILLMODE _eFillMode;			// ��Ⱦʵ����䷽ʽ
	IKS_BOOL _bUseSceneLight;			// �Ƿ�ʹ�ó����ƹ�
	BPCULLMODE _eCullMode;			// ��Ⱦ���÷�ʽ
} BPOBJGRPRENDERSTATE;

// ��Ȼ����
typedef struct _BPMATERIALPHYSICS {
	BPBASEFLOAT4	vDiffuse;        /* Diffuse color RGBA */
	BPBASEFLOAT4	vAmbient;        /* Ambient color RGB */
	BPBASEFLOAT4	vSpecular;       /* Specular 'shininess' */
	BPBASEFLOAT4	vEmissive;       /* Emissive color RGB */
	float	fPower;				/* Sharpness if specular highlight */
} BPMATERIALPHYSICS;

// ����
typedef struct _BPMATERIAL
{
	BPMATERIALTYPE			_eMtlType;				// ��������
	BPMATERIALPHYSICS		_mtlPhysics;			// ��Ȼ����
	std::vector<IKS_UINT>			_arrTexID;			// �������ID
	std::vector<BPBASEFLOAT4>	_arrData;			// ��������
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

// ��Ⱦ����
typedef struct _BPRENDERBACKGROUND {
	RENDERBACKGROUNDTYPE _eType;		// ��������
	BPBASEFLOAT4 _vColor;				// ������ɫ
	IKS_UINT _uTexID;						// ���������ID
	CSVWString	_strPicPath;			// ͼƬ·��
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

// �����
typedef struct _BPCAMERA {
	BPBASEFLOAT3 _vEyePos;			// �����λ��
	BPBASEFLOAT3 _vFocus;			// ���������
	BPBASEFLOAT3 _vUp;				// ������Ϸ���
	float _fFOVY;					// Y������ӽ�
	float _fAspect;					// ��߱�
	float _fZNear;					// ��ƽ��
	float _fZFar;					// Զƽ��
	float _fInterocularDistance;	// Ŀ���
} BPCAMERA;

// �ƹ�
typedef struct _BPLIGHT {
	BPLIGHTTYPE _eType;				// �ƹ�����
	BPBASEFLOAT4 _vDiffuse;			// ���������ɫ
	BPBASEFLOAT4 _vSpecular;		// ƽ�й���ɫ
	BPBASEFLOAT4 _vAmbient;			// ��������ɫ
	BPBASEFLOAT3 _vPosition;		// ��Դλ��
	BPBASEFLOAT3 _vDirection;		// ���߷���
	float _fRange;
	float _fFalloff;
	float _fAttenuation0;
	float _fAttenuation1;
	float _fAttenuation2;
	float _fTheta;
	float _fPhi;
} BPLIGHT;

// ����Ԫ��_���������
typedef struct _SVSCENEELEMENT_OBJSURFACEGRP
{
	IKS_UINT _uObjectID;						// �������ڵ����ID
	std::vector<IKS_UINT> _arrSubsetIndex;		// �����Ӧ���Ӽ�����(������δ��Ӧһ������Ƭ����,��ȡֵINVALID_ID)
	std::vector<IKS_UINT> _arrSurfaceIndex;		// ��������(������δ��Ӧ��ȷ����,��ȡֵINVALID_ID)
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

// ����Ԫ��_�������
typedef struct _SVSCENEELEMENT_OBJCURVEGRP
{
	IKS_UINT _uObjectID;						// �������ڵ����ID
// 	std::vector<IKS_UINT> _arrSubsetIndex;		// ���߶�Ӧ���Ӽ�����(������δ��Ӧһ����������,��ȡֵINVALID_ID)
	std::vector<IKS_UINT> _arrCurveIndex;		// ��������(������δ��Ӧ��ȷ����,��ȡֵINVALID_ID)
// 	std::vector<IKS_UINT> _arrCurveHLObjID;		// ���߶�Ӧ�ĸ������ID(���ڸ�����ʾ������)
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

// ����Ԫ��_���������
typedef struct _SVSCENEELEMENT_OBJFEATUREPOINT
{
	IKS_UINT _uParentGeomIndex;					// �����ڵļ���(���ߡ�����)������
	int _nPointType;						// ������,�ο�ö����BPPOINTTYPE
	IKS_UINT _uPointIndex;						// ������
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

// ����Ԫ��_���������
typedef struct _SVSCENEELEMENT_OBJFEATUREPOINTGRP
{
	IKS_UINT _uObjectID;											// ���������ڵ����ID
	std::vector<SVSCENEELEMENT_OBJFEATUREPOINT> _arrPoint;		// ������
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

// ����Ԫ��_��������
typedef struct _SVSCENEELEMENT_OBJSURFACEPOINTGRP
{
	IKS_UINT _uObjectID;											// ��������ڵ����ID
	std::vector<BPBASEFLOAT3> _arrPoint;						// �����λ��(����ľֲ��ռ�����,��������ת�����󼴿ɻ����������)
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

// ����Ԫ��_�ۺ�������Ϣ
typedef struct _SVSCENEELEMENT_GENERAL
{
	int _nSceneElemType;										// ����Ԫ�ص�����,�ο�ö����SVSCENEELEMENTTYPE
	IKS_UINT _uSceneElemID;											// ����Ԫ�ص�ID
	std::vector<IKS_UINT> _arrSubsetGeomIndex;						// �Ӽ��򼸺ε�����
	std::vector<int> _arrSceneElemSubType;						// ����Ԫ�ص�������
	std::vector<IKS_UINT> _arrSceneElemSubIndex;					// ����Ԫ�ص�������
	std::vector<BPBASEFLOAT3> _arrSceneElemPos;					// ����Ԫ�ص�λ��(��������ϵ)
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

// ����Ԫ�ص���Ϣ
typedef struct _SVSCENEELEMINFO
{
	IKS_BOOL _bInfoValid_ObjectID;											// ��Ϣ��Ч��:���ID
	std::vector<IKS_UINT> _arrObjectID;										// ���ID
	IKS_BOOL _bInfoValid_AnnotationID;										// ��Ϣ��Ч��:��עID
	std::vector<IKS_UINT> _arrAnnotationID;									// ��עID
	IKS_BOOL _bInfoValid_ObjSurfaceGrp;										// ��Ϣ��Ч��:���������
	std::vector<SVSCENEELEMENT_OBJSURFACEGRP> _arrObjSurfaceGrp;		// ���������
	IKS_BOOL _bInfoValid_ObjCurveGrp;										// ��Ϣ��Ч��:���������
	std::vector<SVSCENEELEMENT_OBJCURVEGRP> _arrObjCurveGrp;			// ���������
	IKS_BOOL _bInfoValid_ObjFeatPtGrp;										// ��Ϣ��Ч��:�����������
	std::vector<SVSCENEELEMENT_OBJFEATUREPOINTGRP> _arrObjFeatPtGrp;	// �����������
	IKS_BOOL _bInfoValid_ObjSurfPtGrp;										// ��Ϣ��Ч��:����������
	std::vector<SVSCENEELEMENT_OBJSURFACEPOINTGRP> _arrObjSurfPtGrp;	// ����������
// 	IKS_BOOL _bInfoValid_FreePtGrp;											// ��Ϣ��Ч��:���ɵ���
// 	std::vector<BPBASEFLOAT3> _arrFreePtGrp;							// ���ɵ���
	IKS_BOOL _bInfoValid_FreeAnnotID;										// ��Ϣ��Ч��:���ɱ�עID
	std::vector<IKS_UINT> _arrFreeAnnotID;									// ���ɱ�עID
	IKS_BOOL _bInfoValid_MdlAnnotID;										// ��Ϣ��Ч��:ģ�ͱ�עID
	std::vector<IKS_UINT> _arrMdlAnnotID;									// ģ�ͱ�עID
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

// ģ���Ӽ���
typedef struct _MODELSUBSETGROUP
{
	int _nType;								// ������,�����漯���塢���µȣ���������,��δʹ��
	std::vector<IKS_UINT> _arrSubsetIndex;		// �����Ӽ�������
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
