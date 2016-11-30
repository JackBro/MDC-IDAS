//===================================================================================================
// File:
//		SVSceneDef.h
// Summary:
//		Define scene class/struct, enum, macro and so on.
// Usage:
//		���峡����������ݣ����ڳ���ģ�顢�洢ģ��ȡ�
// Remarks:
//		Null
// Date:
//		
// Author:
//		Shiping Wang
//===================================================================================================

#pragma once

//===================================================================================================
// ͷ�ļ�
#include <vector>
#include "SVPublicDef.h"
#include "SVGeomDef.h"
#include "SVAnnotationDef.h"

//===================================================================================================
// ��ѧ����


//===================================================================================================
// �궨��


//===================================================================================================
// ö�����Ͷ���

// �ؼ�֡����
typedef enum _BPKEYFRAMETYPE
{
	BPKFT_UNKNOWN		= 0,
// 	BPKFT_MATRIX		= 1,			// ����(�ѷ���)
// 	BPKFT_SCALE			= 2,			// ����(�ѷ���)
// 	BPKFT_ROTATIONX		= 3,			// X����ת(�ѷ���)
// 	BPKFT_ROTATIONY		= 4,			// Y����ת(�ѷ���)
// 	BPKFT_ROTATIONZ		= 5,			// Z����ת(�ѷ���)
	BPKFT_ROTATION		= 6,			// ������ת
	BPKFT_TRANSLATION	= 7,			// ƽ��
} BPKEYFRAMETYPE;

// ʱ��ڵ�����
typedef enum _BPSCENETIMENODETYPE
{
	BPSTNT_NULL				= 0,	// ��Ч��
	BPSTNT_BASE				= 1,	// ����
	BPSTNT_WORKSTAGE		= 2,	// ����
	BPSTNT_WORKSTEP			= 3,	// ����
} BPSCENETIMENODETYPE;

// ��������
typedef enum _BPPARAMETERTYPE
{
	BPPARAMTYPE_UNKOWN			= 0,	// δ֪����
	BPPARAMTYPE_INT				= 1,	// ��������
	BPPARAMTYPE_FLOAT			= 2,	// �����ȸ�������
	BPPARAMTYPE_DOUBLE			= 3,	// ˫���ȸ�������
	BPPARAMTYPE_STRING			= 4,	// �ַ�������
	BPPARAMTYPE_FLOAT3			= 5,	// ���������ȸ�������
	BPPARAMTYPE_DOUBLE3			= 6,	// ����˫���ȸ�������
	BPPARAMTYPE_BOOL			= 7,	// ��������
} BPPARAMETERTYPE;

// ������������������
typedef enum _SVPARAMFILTEROPERTYPE
{
	SVPFOTYPE_UNKOWN				= 0,	// δ֪����
	SVPFOTYPE_EXIST					= 1,	// ��������
	SVPFOTYPE_NOTEXIST				= 2,	// ����������
	SVPFOTYPE_EQUAL_STRING			= 3,	// �������ַ�����ֵ����
	SVPFOTYPE_NOTEQUAL_STRING		= 4,	// �������ַ�����ֵ������
	SVPFOTYPE_INCLUDE_STRING		= 5,	// �������ַ�����ֵ����
	SVPFOTYPE_NOTINCLUDE_STRING		= 6,	// �������ַ�����ֵ������
	SVPFOTYPE_EQUAL_DOUBLE			= 7,	// ������ʵ����ֵ����
	SVPFOTYPE_NOTEQUAL_DOUBLE		= 8,	// ������ʵ����ֵ������
	SVPFOTYPE_GREATER_DOUBLE		= 9,	// ������ʵ����ֵ����
	SVPFOTYPE_GREATEREQUAL_DOUBLE	= 10,	// ������ʵ����ֵ���ڵ���
	SVPFOTYPE_LESS_DOUBLE			= 11,	// ������ʵ����ֵС��
	SVPFOTYPE_LESSEQUAL_DOUBLE		= 12,	// ������ʵ����ֵС�ڵ���
	SVPFOTYPE_EQUALSTRINGLENGTH		= 13,	// �������ַ�����ֵ���ȵ���
	SVPFOTYPE_FINDSTRINGAT			= 14,	// �������ַ�����ֵ�ڵ�i��λ�ó���ָ���ַ���;�����ʽ:XXX,i(i=1,2,...)
} SVPARAMFILTEROPERTYPE;

// ���ȵ�λ����
typedef enum _BPLENGTHUNITTYPE
{
	BPLENUNITTYPE_UNKOWN			= 0,	// δ֪����
	BPLENUNITTYPE_MM				= 1,	// ����
	BPLENUNITTYPE_CM				= 2,	// ����(1cm=10mm)
	BPLENUNITTYPE_M					= 3,	// ��(1m=1000mm)
	BPLENUNITTYPE_MICRON			= 4,	// ΢��(1micron=0.001mm)
	BPLENUNITTYPE_FT				= 5,	// Ӣ��(1ft=304.8mm)
	BPLENUNITTYPE_IN				= 6,	// Ӣ��(1in=25.4mm)
	BPLENUNITTYPE_MIL				= 7,	// ǧ��֮һӢ��(1mil=0.0254mm)
	BPLENUNITTYPE_ANGSTROM			= 8,	// ��(1Angstrom=0.0000001mm)
	BPLENUNITTYPE_NANOMETER			= 9,	// ����(1Nanometer=0.000001mm)
} BPLENGTHUNITTYPE;

// ������λ����
typedef enum _BPMASSUNITTYPE
{
	BPMASSUNITTYPE_UNKOWN			= 0,	// δ֪����
	BPMASSUNITTYPE_KG				= 1,	// ǧ��
	BPMASSUNITTYPE_G				= 2,	// ��(1g=0.001kg)
	BPMASSUNITTYPE_MG				= 3,	// ����(1mg=0.000001kg)
	BPMASSUNITTYPE_LBM				= 4,	// ��(1lbm=0.4536kg)
	BPMASSUNITTYPE_OUNCE_M			= 5,	// ��˾(1ouncem=0.02835kg)
	BPMASSUNITTYPE_SLUG				= 6,	// ˹�ո�(1slug=14.5939kg)
	BPMASSUNITTYPE_TON_M			= 7,	// �̶�(1tonm=907.18474kg)
	BPMASSUNITTYPE_TONNE			= 8,	// ��(1tonne=1000kg)
} BPMASSUNITTYPE;

// ʱ�䵥λ����
typedef enum _BPTIMEUNITTYPE
{
	BPTIMEUNITTYPE_UNKOWN			= 0,	// δ֪����
	BPTIMEUNITTYPE_SEC				= 1,	// ��
	BPTIMEUNITTYPE_MSEC				= 2,	// ����(1msec=0.001sec)
	BPTIMEUNITTYPE_MICRO_SEC		= 3,	// ΢��(1microsec=0.000001sec)
	BPTIMEUNITTYPE_MIN				= 4,	// ����(1min=60sec)
	BPTIMEUNITTYPE_HR				= 5,	// Сʱ(1hr=3600sec)
	BPTIMEUNITTYPE_DAY				= 6,	// ��(1day=86400sec)
	BPTIMEUNITTYPE_WEEK				= 7,	// ��(1week=604800sec)
	BPTIMEUNITTYPE_NANOSECOND		= 8,	// ����(1Nanosecond=0.000000001sec)
} BPTIMEUNITTYPE;

// �Ƕȵ�λ����
typedef enum _BPANGLEUNITTYPE
{
	BPANGUNITTYPE_UNKOWN			= 0,	// δ֪����
	BPANGUNITTYPE_DEGREE			= 1,	// �Ƕ�
	BPANGUNITTYPE_RADIAN			= 2,	// ����
} BPANGLEUNITTYPE;

// �������������
typedef enum _BPSCENEOBJECTSUBTYPE
{
	BPSCENEOBJSUBTYPE_UNKOWN		= 0,	// δ֪����
	BPSCENEOBJSUBTYPE_GENERAL		= 1,	// ��ͨ���
	BPSCENEOBJSUBTYPE_HARNESS		= 2,	// �������
	BPSCENEOBJSUBTYPE_CABLE			= 3,	// �������
} BPSCENEOBJECTSUBTYPE;

// ���������ģ�ͺϲ�ģʽ
typedef enum _BPSCENEIMPORTMODELMERGEMODE
{
// 	BPSIMDLMERGEMODE_UNKOWN						= 0,	// δ֪ģʽ
	BPSIMDLMERGEMODE_NOMERGE					= 1,	// ���ϲ���ͬģ��
	BPSIMDLMERGEMODE_SAMEOBJIDSAMEMDL			= 2,	// ����ģ��ID�ϲ���ͬ��ģ��(��ͬ���ID����ͬģ������(ģ���ļ�����������������ͬ)���ж�Ϊ��ͬģ��)
	BPSIMDLMERGEMODE_SAMEMDLTREENODENAMEPOS		= 3,	// ����ģ�����ϲ���ͬ��ģ��(��ͬģ�����ڵ����ƺ�λ�õ��ж�Ϊ��ͬģ��)
	BPSIMDLMERGEMODE_SAMEORIMDLTREENODEID		= 4,	// ����ģ��ԭʼ��ʶ�ϲ���ͬ��ģ��(��ͬģ�����ڵ�ԭʼID���ж�Ϊ��ͬģ��)
} BPSCENEIMPORTMODELMERGEMODE;

//===================================================================================================
// �ṹ�嶨��

// �ؼ�֡��������_������ת
typedef struct _KEYFRAMEROTATION {
	BPBASEFLOAT3 _vOrigin;
	BPBASEFLOAT3 _vAxis;
	float _fRotValue;
} KEYFRAMEROTATION;

// // �ؼ�֡Ԫ��
// typedef struct _KEYFRAMEELEMENT {
// 	IKS_UINT _uFrameID;									// ֡��
// 
// 	union {
// 		BPBASEMATRIX			_matrix;			// �ۺϾ���
// 		BPBASEFLOAT3			_vScale;			// ����
// 		float					_fRotX;				// X����ת
// 		float					_fRotY;				// Y����ת
// 		float					_fRotZ;				// Z����ת
// 		KEYFRAMEROTATION		_rotation;			// ������ת
// 		BPBASEFLOAT3			_vTranslation;		// ƽ��
// 	};
// } KEYFRAMEELEMENT;
// 
// // �ؼ�֡����
// typedef struct _KEYFRAMEDATA {
// 	IKS_UINT _uStartFrameID;						// ��ʼ֡��
// 	BPKEYFRAMETYPE _eType;						// �ؼ�֡����
// 	std::vector<KEYFRAMEELEMENT> _arrElements;	// �ؼ�֡Ԫ����(ÿ��Ԫ�������˵�ǰ����任�Ĺؼ�֡����)
// 
// 	_KEYFRAMEDATA()
// 	{
// 		_uStartFrameID = 0;
// 	}
// } KEYFRAMEDATA;

// �ؼ�֡����
typedef struct _BPKEYPARAMETER {
	BPKEYFRAMETYPE _eType;							// ����
	union {
// 		BPBASEFLOAT3			_vScale;			// ����
// 		float					_fRotX;				// X����ת
// 		float					_fRotY;				// Y����ת
// 		float					_fRotZ;				// Z����ת
		KEYFRAMEROTATION		_rotation;			// ������ת
		BPBASEFLOAT3			_vTranslation;		// ƽ��
	} _data;
} BPKEYPARAMETER;

// �ؼ�֡
// ģ�ʹ���ʼ״̬,ͨ���ֲ���ȫ�ֱ任��ָ��֡�ŵ�״̬
typedef struct _BPKEYFRAME {
	IKS_UINT _uFrameID;										// ֡��
	BPBASEMATRIX _matStartStatus;						// ��ʼ״̬
	std::vector<BPKEYPARAMETER> _arrLocalTransform;		// �ֲ��任�Ĺؼ�֡����(��˳��)
	std::vector<BPKEYPARAMETER> _arrGlobalTransform;	// ȫ�ֱ任�Ĺؼ�֡����(��˳��)

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

// ������ؼ�֡
typedef struct _BPCAMERA_KEYFRAME {
	IKS_UINT _uFrameID;				// ֡��
	BPCAMERA _camera;			// ���������
} BPCAMERA_KEYFRAME;

// ���Źؼ�֡
typedef struct _BPSCALE_KEYFRAME {
	IKS_UINT _uFrameID;				// ֡��
	BPBASEFLOAT3 _vScale;		// ���ű���XYZ
} BPSCALE_KEYFRAME;

// �ɼ��Թؼ�֡
typedef struct _BPVISIBLE_KEYFRAME {
	IKS_UINT _uFrameID;				// ֡��
	IKS_BOOL _bVisible;				// �ɼ���
} BPVISIBLE_KEYFRAME;

// ͸���ȹؼ�֡
typedef struct _BPTRANSPARENCY_KEYFRAME {
	IKS_UINT _uFrameID;				// ֡��
	float _fNoTransparency;		// ��͸����
} BPTRANSPARENCY_KEYFRAME;

// ������ֵ
typedef struct _BP_PARAMETERVALUE {
	int _nType;									// �������ͣ��ο�BPPARAMETERTYPEö��

	union {
		int				_nValue;				// ������ֵ
		float			_fValue;				// �����ȸ�����ֵ
		double			_dValue;				// ˫���ȸ�����ֵ
		BPBASEFLOAT3	_vFloat3Value;			// ���������ȸ������ֵ
		SVBASEDOUBLE3	_vDouble3Value;			// ����˫���ȸ������ֵ
		bool			_bValue;				// ������ֵ
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
		if (this == &data) // ����Լ����Լ���ֵ��ֱ�ӷ���
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

// ����
typedef struct _BP_PARAMETER {
	CSVWString			_strName;				// ��������
	BP_PARAMETERVALUE	_stuValue;				// ������ֵ
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
		if (this == &data) // ����Լ����Լ���ֵ��ֱ�ӷ���
			return *this;
		_strName = data._strName;
		_stuValue = data._stuValue;
		return *this;
	}
} BP_PARAMETER;

// ����������Ԫ��
typedef struct _SV_PARAMETERFILTER_ELEM {
	int					_nOperType;				// ��������������
	BP_PARAMETER		_stuParam;				// ����
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

// ����������
typedef struct _SV_PARAMETERFILTER {
	std::vector<SV_PARAMETERFILTER_ELEM> _arrFilterElem;	// ������Ԫ��
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

// �����洢����
typedef struct _BP_PARAMETER_SAVEDATA {
	std::vector<BP_PARAMETER> _arrParamSaveData;		// �����洢����
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

// ���չ�̲������
typedef struct _BP_TECHPLUGINDATA {
	CSVWString			_strInspectContent;				// �������
	CSVWString			_strInspectResult;				// �����

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
		if (this == &data) // ����Լ����Լ���ֵ��ֱ�ӷ���
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

// ���չ�̲�����ݽڵ�
typedef struct _BP_TECHPLUGINNODE {
	unsigned int _uTimeNodeID;				// �ڵ��Ӧ��ʱ��ڵ�ID
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
		if (this == &node) // ����Լ����Լ���ֵ��ֱ�ӷ���
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

// ���չ�̲�����ݴ洢���ݹ���
typedef struct _BP_TECHPLUGINNODE_SAVEDATAMGR {
	std::vector<BP_TECHPLUGINNODE> _arrTechPlugInSaveData;	// ���չ�̲�����ݴ洢����
	_BP_TECHPLUGINNODE_SAVEDATAMGR()
	{
	}
	_BP_TECHPLUGINNODE_SAVEDATAMGR(const _BP_TECHPLUGINNODE_SAVEDATAMGR& data)
	{
		_arrTechPlugInSaveData = data._arrTechPlugInSaveData;
	}
	_BP_TECHPLUGINNODE_SAVEDATAMGR& operator = (const _BP_TECHPLUGINNODE_SAVEDATAMGR& data)
	{
		if (this == &data) // ����Լ����Լ���ֵ��ֱ�ӷ���
			return *this;
		_arrTechPlugInSaveData = data._arrTechPlugInSaveData;
		return *this;
	}
	void Clear()
	{
		_arrTechPlugInSaveData.clear();
	}
} BP_TECHPLUGINNODE_SAVEDATAMGR;

// ʱ��ڵ�
typedef struct _BP_TIMENODE {
	unsigned int _uTimeNodeID;				// �ڵ��Ӧ��ʱ��ڵ�ID
	unsigned int _uTreeNodeID;				// ���ڵ�ID
	int _nType;								// ����,�ο�ö��ֵBPSCENETIMENODETYPE
	wchar_t _szName[BP_MAX_PATH];			// ����
	CSVWString _strNote;					// ע��
	wchar_t _szAudioPath[BP_MAX_PATH];		// ��Ƶ·��
	wchar_t _szDocPath[BP_MAX_PATH];		// �ĵ�·��
	unsigned int _uVideoFileID;				// ��Ƶ�ļ�ID
	std::vector<IKS_UINT> _arrImageFileID;		// ͼ���ļ�ID
	CSVWString _strHyperlink;				// ������
	unsigned int _uStartFrameID;			// ��ʼ֡��
	unsigned int _uFrameSize;				// ֡����
	BP_TECHPLUGINDATA _TechPlugInData;		// ���չ�̲������
	std::vector<_BP_TIMENODE> _arrSubNode;	// �ӽڵ�

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
		if (this == &node) // ����Լ����Լ���ֵ��ֱ�ӷ���
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

// ���չ�����ݽڵ�(һ���������ݵ�������xml�����ļ�)
typedef struct _BP_TECHPROCEDURENODE {
	unsigned int _uTimeNodeID;				// �ڵ��Ӧ��ʱ��ڵ�ID
	int _nType;								// ����,�ο�ö��ֵBPSCENETIMENODETYPE
	CSVWString _strName;					// ����
	CSVWString _strNote;					// ע��
	CSVWString _strImageName;				// ͼƬ����
	unsigned int _uStartFrameID;			// ��ʼ֡��
	unsigned int _uFrameSize;				// ��ֹ֡��
	BP_TECHPLUGINDATA _TechPlugInData;		// ���չ�̲������
	std::vector<_BP_TECHPROCEDURENODE> _arrSubNode;	// �ӽڵ�

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
		if (this == &node) // ����Լ����Լ���ֵ��ֱ�ӷ���
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

// ģ�����ڵ�
typedef struct __BP_OBJ_TREENODE {
	unsigned int _uObjectID;					// �ڵ��Ӧ�����ID
	unsigned int _uTreeNodeID;					// ���ڵ�ID
	CSVWString _strOriTreeNodeID;				// ���ڵ�ԭʼID(��CAD����ʱ�Ľڵ�ID,����ԭCADģ�������µ�ǰģ����)
	CSVWString _strName;						// �ڵ�����
	CSVWString _strOriName;						// �ڵ��ԭʼ����(���ɻ��CAD����ʱ������,�������������������)
	BPBASEMATRIX _matTranform;					// �任����(��ǰģ��(���/���)����һ������е�����任����)
	// ע��:�任�������δ�༭ʱ��װ���ϵ,������CADװ����װ���ϵ�仯ʱ����SVF(����ĳ�ʼ����(Local���ű任*RTWorld)��ģ�����иýڵ���������֮��,��Ϊ�û��޸ĵĳ�ʼλ�ñ任����);
	// ���ֻ������CAD������������ģ�����ṹ(ֻ�޸Ĳ㼶�����λ�ù�ϵ,ģ�͵�ȫ��λ�ò���)ʱ�޸�,�������û�˽���޸�!
	std::vector<BP_PARAMETER> _arrParamData;	// ����
	std::vector<IKS_UINT> _arrAnnoBlockID;			// ��ע��ID
	std::vector<__BP_OBJ_TREENODE> _arrSubNode;	// �ӽڵ�
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
		if (this == &node) // ����Լ����Լ���ֵ��ֱ�ӷ���
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

// ����ϵͳ��λ
typedef struct _BP_SCENE_UNIT {
	int _nLengthUnit;		// ���ȵ�λ,�ο�ö����BPLENGTHUNITTYPE
	int _nMassUnit;			// ������λ,�ο�ö����BPMASSUNITTYPE
	int _nTimeUnit;			// ʱ�䵥λ,�ο�ö����BPTIMEUNITTYPE
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
		if (this == &data) // ����Լ����Լ���ֵ��ֱ�ӷ���
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

// ģ���Ӽ��洢����
typedef struct _BP_MODELSUBSET_SAVEDATA
{
	int				_nPrimitType;			// ͼԪ����,�ο�ö����BPPRIMITIVETYPE
	IKS_UINT			_uStartIndex;			// ������ƫ��ֵ
	IKS_UINT			_uIndexCount;			// ��������
	BOUNDBOX		_box;					// �����Χ��
	int				_nSubsetType;			// �Ӽ�����,�ο�ö����BPMDLSUBSETTYPE
	IKS_UINT			_uGeomIndex;			// ����(�������ߵ�)����(ע��:����������Ϊ-1,����Ӽ����Ӧ�ļ�����һһ��Ӧ��ϵ)
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

// ģ�ʹ洢����
typedef struct _BP_MODEL_SAVEDATA
{
	int										_nModelSrcType;			// ģ����Դ����
	std::vector<float>						_arrVertexData;			// ��������(ÿ���������8��float(3��λ��+3����ʸ����+2��������))
	std::vector<IKS_DWORD>						_arrIndexData;		// �����飬����3��Ԫ��Ϊһ��(����Ƭ)��2��Ԫ��Ϊһ��(�߶�)
	std::vector<BP_MODELSUBSET_SAVEDATA>	_arrSubset;				// �Ӽ�����
	std::vector<MODELSUBSETGROUP>			_arrSubsetGrp;			// �Ӽ�������
	std::vector<BPSurface>					_arrSurface;			// ��������
	std::vector<BPCurve>					_arrCurve;				// ��������
	BOUNDBOX								_box;					// ģ�Ͱ�Χ��
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
		// �Ƚ϶�������
		for (i=0; i<_arrVertexData.size(); i++)
		{
			if (!ISEQUAL(_arrVertexData[i], data._arrVertexData[i]))
				return FALSE;
		}
		// �Ƚ���������
		if (memcmp(&(_arrIndexData[0]), &(data._arrIndexData[0]), sizeof(IKS_DWORD)*_arrIndexData.size()) != 0)
			return FALSE;
		// �Ƚ��Ӽ�����
		for (i=0; i<_arrSubset.size(); i++)
		{
			if (_arrSubset[i] != data._arrSubset[i])
				return FALSE;
		}
		// �Ƚ��Ӽ�������
		for (i=0; i<_arrSubsetGrp.size(); i++)
		{
			if (_arrSubsetGrp[i]._nType != data._arrSubsetGrp[i]._nType)
				return FALSE;
			if (_arrSubsetGrp[i]._arrSubsetIndex.size() != data._arrSubsetGrp[i]._arrSubsetIndex.size())
				return FALSE;
			if (memcmp(&(_arrSubsetGrp[i]._arrSubsetIndex[0]), &(data._arrSubsetGrp[i]._arrSubsetIndex[0]), sizeof(IKS_UINT)*_arrSubsetGrp[i]._arrSubsetIndex.size()) != 0)
				return FALSE;
		}
		// �Ƚ�������
		for (i=0; i<_arrSurface.size(); i++)
		{
			if (_arrSurface[i] != data._arrSurface[i])
				return FALSE;
		}
		// �Ƚϱ�����
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

// ����洢����
typedef struct _BP_OBJ_SAVEDATA {
	unsigned int _uObjectID;					// ���ID
	int _nObjSubType;							// ���������,�ο�ö����BPSCENEOBJECTSUBTYPE
	BPOBJGRPRENDERSTATE _RenderState;			// ��Ⱦ״̬
	unsigned int _uMeshID;						// �����Ӧģ��Mesh��ID
	BPBASEMATRIX _matLocal;						// �ֲ�����
	BPBASEMATRIX _matWorld;						// �������
	int _nAlphaBlendRenderSerialNum;			// �����͸����Ⱦ���
	IKS_BOOL _bAlphaBlendRenderInternalStruct;		// �Ƿ�͸����Ⱦ�ڲ��ṹ
	ProductInfo _ProductInfo;					// ��Ʒ��Ϣ
	std::vector<unsigned int > _arrSubsetMtlID;	// ����Ӽ��Ĳ���ID
	std::vector<BP_PARAMETER> _arrParamSaveData;		// �������
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
		if (this == &data) // ����Լ����Լ���ֵ��ֱ�ӷ���
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

// ����洢���ݹ���
typedef struct _BP_OBJ_SAVEDATAMGR {
	std::vector<BP_OBJ_SAVEDATA> _arrObjSaveData;	// ����洢����
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

// ���ʴ洢����
typedef struct _BP_MTL_SAVEDATA {
	unsigned int _uMtlID;						// ����ID
	CSVWString _strName;						// ��������
	BPMATERIAL _MtlData;						// ��������
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

// ����洢����
// typedef struct _BP_TEX_SAVEDATA {
// 	unsigned int _uTexID;						// ����ID
// 	wchar_t stzTexPath[BP_MAX_PATH];			// ����·���ļ�����
// } BP_TEX_SAVEDATA;

// ���ʴ洢���ݹ���
typedef struct _BP_MTL_SAVEDATAMGR {
	std::vector<BP_MTL_SAVEDATA> _arrMtlSaveData;		// ���ʴ洢����
// 	std::vector<BP_TEX_SAVEDATA>	_arrTexSaveData;	// ����洢����
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

// ��������洢����
typedef struct _BP_OBJ_ANIM_SAVEDATA {
	unsigned int _uObjectID;							// ���ID
	std::vector<BPKEYFRAME> _arrKeyFrameData;			// ����Ĺؼ�֡(��תƽ�Ʊ任)
	std::vector<BPSCALE_KEYFRAME> _arrScaleKeyFrm;		// ��������Źؼ�֡
	std::vector<BPVISIBLE_KEYFRAME> _arrVisibleKeyFrm;	// ����Ŀɼ��Թؼ�֡
	std::vector<BPTRANSPARENCY_KEYFRAME> _arrTranspKeyFrm;	// �����͸���ȹؼ�֡
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

// ��ע�����洢����
typedef struct _BP_ANNOT_ANIM_SAVEDATA {
	unsigned int _uAnnotID;									// ��עID
	std::vector<BPKEYFRAME> _arrKeyFrameData;				// ��ע�Ĺؼ�֡(��תƽ�Ʊ任)
	std::vector<BPTRANSPARENCY_KEYFRAME> _arrTranspKeyFrm;	// ��ע��͸���ȹؼ�֡
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

// �����洢���ݹ���
typedef struct _BP_ANIM_SAVEDATAMGR {
	unsigned int _uFrameSize;									// ʱ���߳���(��λ��֡)
	std::vector<BP_OBJ_ANIM_SAVEDATA> _arrObjAnimSaveData;		// ��������洢����
	std::vector<BP_ANNOT_ANIM_SAVEDATA> _arrAnnotAnimSaveData;	// ��ע�����洢����
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

// ������洢���ݹ���
typedef struct _BP_CAMERA_SAVEDATAMGR {
	BPCAMERA _DefaultCamera;								// Ĭ�����������
	std::vector<BPCAMERA_KEYFRAME> _arrCameraAnimSaveData;	// ������ؼ�֡
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

// ������Ƶ�洢����
typedef struct _BP_BACKGROUNDAUDIO_SAVEDATA {
	CSVWString	_strAudioName;				// ��Ƶ����
	IKS_BOOL		_bAlwaysPlay;				// ʼ�ղ���
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

// ѡ����������
typedef struct _BP_CONFIG_SAVEDATA {
	unsigned int _uPlaySpeed;				// �����ٶ�
	float _fTextSize;						// ע���ı��ߴ�
	int _nTextStyle;						// ע�ͷ����ʽ
	int _nCameraProjectType;				// �����ͶӰ����
	int _nCoordsType;						// ����ϵ����
	int _nSceneUpType;						// �����Ϸ�������
	IKS_BOOL _bLockCameraUp;					// ������������Ϸ���
	IKS_BOOL _bPlayUseCameraAnim;				// ����ʱʹ�����������
	IKS_BOOL _bAutoCalcObjAlphaBlendRenderSerialNum;	// �Զ����������͸����Ⱦ���
	BP_SCENE_UNIT _stuSceneUnit;			// ������λ
	BPRENDERBACKGROUND _SceneBackGroundData;	// ��������
	BP_BACKGROUNDAUDIO_SAVEDATA _SceneBGAudio;	// ����������Ƶ
	float _fStandardCameraAspect;			// ��׼��Ļ��߱�
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

// ��ע�洢����
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

// �����ĵ�������
typedef struct _SV_SCENEEXPORTCONFIG {
	CSVWString	_strPath;			// ������·��
	IKS_UINT	_uStartFrameID;			// ��������ʼ֡��
	IKS_UINT	_uFrameSize;			// ������֡��

	IKS_BOOL	_bIsExportMtl;			// �Ƿ񵼳���������
	IKS_BOOL	_bIsExportAnnot;		// �Ƿ񵼳���ע����
	IKS_BOOL	_bIsExportAnim;			// �Ƿ񵼳���������
	IKS_BOOL	_bIsExportCamera;		// �Ƿ񵼳����������(�������������)
	IKS_BOOL	_bIsExportTimeNode;		// �Ƿ񵼳�ʱ��ڵ�(���չ��)����

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
		if (this == &config) // ����Լ����Լ���ֵ��ֱ�ӷ���
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

// �����ĵ�������
typedef struct _SV_SCENEIMPORTCONFIG {
	CSVWString	_strPath;			// ������ĵ�·��
	IKS_UINT	_uParentTreeNodeID;		// ���볡��ģ�����ڵ�ģ�������ڵ�ID
	IKS_UINT	_uStartFrameID;			// �������ʼ֡��
	int		_nMergeModelMode;		// �ϲ�ģ�͵�ģʽ
	IKS_BOOL	_bIsMergeObjTreeNodeParam;			// �Ƿ�ϲ�ģ�����ڵ����
	IKS_BOOL	_bIsReplaceObjTreeNodeAnnotBlock;	// �Ƿ��滻ģ�����ڵ��Ӧ�ı�ע��
	IKS_BOOL	_bIsReplaceOriMdlTreeNodeID;		// �Ƿ��滻ģ�����ڵ��ԭʼ��ʶ
	IKS_BOOL	_bIsImportMtl;			// �Ƿ����������
	IKS_BOOL	_bIsImportAnnot;		// �Ƿ����ע����
	IKS_BOOL	_bIsImportAnim;			// �Ƿ��붯������
	IKS_BOOL	_bIsImportCamera;		// �Ƿ������������(�������������)
	IKS_BOOL	_bIsImportTimeNode;		// �Ƿ���ʱ��ڵ�(���չ��)����

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
		if (this == &config) // ����Լ����Լ���ֵ��ֱ�ӷ���
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

// �����ĵ�����
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
		if (this == &config) // ����Լ����Լ���ֵ��ֱ�ӷ���
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
