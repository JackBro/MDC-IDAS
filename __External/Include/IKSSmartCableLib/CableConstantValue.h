//===================================================================================================
// Summary:
//		�ڲ�ʹ�ó����ͽṹ��
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
// ����Ϊ��������
const CUnicodeString g_strCableConfigFileName = L"\\CableConfig.ini";		// ����ѡ�������ļ�����
const CUnicodeString g_strConnLibPathServerAlias = L"&(ServerAlias)";		// ���������洢��·���еķ���������
const CUnicodeString g_strTrunkCableTrunkCabPrefix = L"ZX_";				// ���ߵ��µ���·����ǰ׺��
const CUnicodeString g_strTrunkCableBranchCabPrefix = L"ZXB_";				// ���ߵ��µ�֧·����ǰ׺��

//===================================================================================================
// ����Ϊ�Զ������Ϣ

// ������Ϣ:��ʾ���ش���
#define WM_CAB_CUSTOM_SHOWWINDOW		WM_USER + 1001

//===================================================================================================
// ����Ϊö��ֵ����

// ���ģʽ
typedef enum _IKSCHECKHOLECAPACITYMODE
{
	IKSCHKHOLECAPMODE_INVALID				= 0,		// �Ƿ�ֵ
	IKSCHKHOLECAPMODE_SURPLUSAREA			= 1,		// �������
	IKSCHKHOLECAPMODE_COVERAREA				= 2,		// ������
	IKSCHKHOLECAPMODE_LAYOUT				= 3,		// ���
} IKSCHECKHOLECAPACITYMODE;

// ���������͵�ģʽ
typedef enum _IKSCHECKCABLETYPEMODE
{
	IKSCHKCABTYPEMODE_INVALID				= 0,		// �Ƿ�ֵ
	IKSCHKCABTYPEMODE_NETWORK				= 1,		// ͨ������λ�ü���������
	IKSCHKCABTYPEMODE_SIMPATH				= 2,		// ͨ������·�����ƶȼ���������
} IKSCHECKCABLETYPEMODE;

// ����λ������
typedef enum _IKSCABLELOCATIONTYPE
{
	IKSCABLOCT_INVALID						= 0,		// �Ƿ�ֵ
	IKSCABLOCT_PROCABLELOCATION				= 1,		// ProE����λ��
	IKSCABLOCT_LOCATIONDATA					= 2,		// ����λ������
} IKSCABLELOCATIONTYPE;

// ����λ������
typedef enum _IKSCABLETYPE
{
	IKSCABT_INVALID						= -1,		// �Ƿ�ֵ
	IKSCABT_CABLE						= 0,		// ����
	IKSCABT_BUNDLE						= 1,		// ����
	IKSCABT_WIRE						= 2,		// ����
	IKSCABT_CONDUCTOR					= 3,		// ����
	IKSCABT_NETWORK						= 10,		// ����
} IKSCABLETYPE;

// ģ�ͽڵ�����
typedef enum __tagCABMODELNODETYPE
{
	CABMNTYPE_UNUSED				= -1,	// δʹ��
	CABMNTYPE_PART					= 1,	// ���
	CABMNTYPE_ASSEMBLY				= 2,	// ���
	CABMNTYPE_GROUP					= 3,	// ��
	CABMNTYPE_PATTERN				= 4,	// ����
	CABMNTYPE_PART_HARNESS			= 5,	// ����
	CABMNTYPE_PART_CONNECTOR		= 6,	// ��������
	CABMNTYPE_PART_SKELETON			= 7,	// �Ǽ�ģ��
} CABMODELNODETYPE;

// �׺������״����
typedef enum __tagIKSCABHOLESECSHAPETYPE
{
	IKSCABHSSTYPE_INVALID			= 0,	// �Ƿ�ֵ
	IKSCABHSSTYPE_CIRCLE			= 1,	// Բ
	IKSCABHSSTYPE_HALFCIRCLE		= 2,	// ��Բ
	IKSCABHSSTYPE_RECTANGLE		= 3,	// ����
	IKSCABHSSTYPE_WAIST			= 4,	// ����
	IKSCABHSSTYPE_HALFWAIST		= 5,	// ������
} IKSCABHOLESECSHAPETYPE;

// ���²���ģʽ
typedef enum _IKSCABLEROUTINGMODE
{
	IKSCABROUTM_INVALID							= 0,		// �Ƿ�ֵ
	IKSCABROUTM_DIRECTTOEND						= 1,		// ֱͨ�յ�
// 	IKSCABROUTM_SHAREEXISTPATH					= 2,		// ������֪·��
} CABLEROUTINGMODE;

// �������ӹ�ϵ�����
typedef enum _IKSCABLECONNINFCHECKRESULT
{
	IKSCABCONNCHKR_OK							= 0x00000000,		// ���ͨ��
	IKSCABCONNCHKR_ERR_NOTEXIST					= 0x00000001,		// �������ӹ�ϵ������
	IKSCABCONNCHKR_ERR_HARNESSNAME				= 0x00000002,		// ���´���(HARNESS)����
	IKSCABCONNCHKR_ERR_CABLENAME				= 0x00000004,		// ��֧����(CABLE)����
	IKSCABCONNCHKR_ERR_SPOOLNAME				= 0x00000008,		// �������ƴ���
	IKSCABCONNCHKR_ERR_DUMPEDCABLE				= 0x00000010,		// �������(�����ѱ�ɾ��)

	IKSCABCONNCHKR_ERR_CONN_NOTEXIST			= 0x00000100,		// ��������������
	IKSCABCONNCHKR_ERR_CONN_MDLNAME				= 0x00000200,		// ������������(ģ������)����
	IKSCABCONNCHKR_ERR_CONN_ASM					= 0x00000400,		// ��������װ�����
} IKSCABLECONNINFCHECKRESULT;

// �����µĴ�������
typedef enum _IKSUNWRAPCABLEERRORTYPE
{
	IKSUNWRAPCABERRT_OK							= 0,				// ���ɹ�
	IKSUNWRAPCABERRT_SELECTCABLE				= 1,				// ʰȡ�ĵ��²���ȷ
	IKSUNWRAPCABERRT_SELECTCABLELOC				= 2,				// ʰȡ�ĵ���λ�ò���ȷ
	IKSUNWRAPCABERRT_SELECTCABLELOC_DIFFHARN	= 3,				// ʰȡ�ĵ��������λ�����ڲ�ͬ������
	IKSUNWRAPCABERRT_NOTFINDCABLE				= 4,				// δ�ҵ�����
// 	IKSUNWRAPCABERRT_CABLEHAVEMULTISEGMENT		= 5,				// ���º��ж����
	IKSUNWRAPCABERRT_SAMECABLELOC				= 6,				// ��������λ����ͬ
	IKSUNWRAPCABERRT_NOTFINDCABLELOC			= 7,				// δ�ҵ�����λ��
	IKSUNWRAPCABERRT_CABLELOCISNOTFROMNETWORK	= 8,				// ����λ�ò����ڵ�������

	IKSUNWRAPCABERRT_UNKNOWN					= 100,				// δ֪����
} IKSUNWRAPCABLEERRORTYPE;

//===================================================================================================
// ����Ϊ�ṹ�嶨��

typedef struct _IKSCABBASEUINT3 {
	IKS_UINT x;
	IKS_UINT y;
	IKS_UINT z;
} IKSCABBASEUINT3;

// ֱ��
typedef struct __tagIKSCABDBaseLineData
{
	SVBASEDOUBLE3 end1;		// ���
	SVBASEDOUBLE3 end2;		// �յ�
} IKSCABDBaseLineData;

// ֱ��
typedef struct __tagIKSCABDLineData
{
	SVBASEDOUBLE3 end1;		// ���
	SVBASEDOUBLE3 end2;		// �յ�
	__tagIKSCABDLineData(const SVBASEDOUBLE3 &e1, const SVBASEDOUBLE3 &e2)
	{
		end1 = e1;
		end2 = e2;
	}
} IKSCABDLineData;

// Բ��
typedef struct __tagIKSCABDBaseArcData
{
	SVBASEDOUBLE3 vOrigin;	// ԭ��
	SVBASEDOUBLE3 vVector1;	// First vector that defines the plane of the arc
	SVBASEDOUBLE3 vVector2;	// Second vector that defines the plane of the arc
	double dStartAngle;		// Angular parameter of the starting point
	double dEndAngle;		// Angular parameter of the ending point
	double dRadius;			// �뾶
} IKSCABDBaseArcData;

// ���ߵ���״����
typedef union __tagIKSCABDCurveData
{
	IKSCABDBaseLineData		line;			// ֱ��
	IKSCABDBaseArcData		arc;			// Բ��
} IKSCABDCurveData;

// ����������Ϣ
typedef struct __tagIKSCABDCurve
{
	int						nType;			// ��������
	IKSCABDCurveData		curvedata;		// ��������
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

// ������Ϣ
typedef struct __tagIKSSpool
{
	ProSpool stuProeSpool;					// �����ProE����
// 	int						nType;			// ��������,�ο�ö����

	double dDiameter;						// ֱ����THICKNESS��
	double dMinBendRadius;					// ��Сת��뾶��MIN_BEND_RADIUS��
	double dDensity;						// �ܶȣ�DENSITY��
	CSVWString	strColor;					// ��ɫ��(COLOR)
	CSVWString	strUnits;					// ���ȵ�λ(UNITS)
	CSVWString	strMassUnits;				// ������λ(MASS_UNITS)
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

// ���ߵ��µ�λ����Ϣ
typedef struct __tagIKSCableLocation
{
	SVBASEDOUBLE3 vPos;					// λ������(ʵ�ʵ�)
	SVBASEDOUBLE3 vTan;					// ���߷���(ʵ�ʵ�)
	int nType;							// λ������,�ο�ö����IKSCABLELOCATIONTYPE

	ProCablelocation stuProCabLoc;		// ProE����λ��
	SVBASEDOUBLE3 vProCabLocPos;		// λ������(���յ�)
	SVBASEDOUBLE3 vProCabLocTan;		// ���߷���(���յ�)
	UINT uProCabLocIndex;				// ����Cable��Loc����
	UINT uProNetworkLocIndex;			// ��������ĵ���λ������
	UINT uProHarnessLocIndex;			// �����ĵ���λ������

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

// ���ߵ��µĶ���Ϣ
typedef struct __tagIKSCableSegment
{
	std::vector<IKSCableLocation> vecLoc;	// ��λ������
	ProCablesegment pProePt;				// ProE������ָ��
	BOOL bIsInBundle;						// �Ƿ�λ��������
	CSVWString strBundleName;				// ��������������(bIsInBundleΪTRUEʱ��Ч)

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

// ���ߵ��µ���Ϣ
typedef struct __tagIKSCable
{
	ProCable	stuProeCable;			// ProE������
	ProAssembly pProeAssm;				// ���µĸ�װ����
	ProAsmcomppath stuHarnessAsmPath;	// ��������������װ��·��

	CSVWString	strName;				// ���ߵ�������
	int			nType;					// ���ߵ�������,�ο�ö����IKSCABLETYPE

	ProModelitem stuProeCabEnd1;	// ���¶˵�1(������������ڶ�����ϵ,����ʹ���߼�����ָ������ڶ�)
	ProModelitem stuProeCabEnd2;	// ���¶˵�2(������������ڶ�����ϵ,����ʹ���߼�����ָ������ڶ�)
	ProAsmcomppath stuProeCabEnd1Path;	// ���¶˵�1���ڵ���������װ��·��
	ProAsmcomppath stuProeCabEnd2Path;	// ���¶˵�2���ڵ���������װ��·��
	CSVWString strCabConnRefDes1;		// ������ʼ�����������߼�����(ָ������)(��һ������λ�ö�Ӧ�ĵ�������)
	CSVWString strCabConnRefDes2;		// ������ֹ�����������߼�����(ָ������)(���һ������λ�ö�Ӧ�ĵ�������)
	CSVWString strCabConnEntryPortName1;	// ������ʼ������������ڶ�
	CSVWString strCabConnEntryPortName2;	// ������ֹ������������ڶ�
	CSVWString strCabConnDirection1;		// ������ʼ���������ķ���FROM��TO��
	CSVWString strCabConnDirection2;		// ������ֹ���������ķ���FROM��TO��
	UINT uCurAsmConnIndex1;				// ������ʼ������������
	UINT uCurAsmConnIndex2;				// ������ֹ������������

	IKSSpool stuSpool;					// ���µ�����
	vector<CSVWString> vecConductorName;		// �ӵ������ƣ�typeֵΪIKSCABT_CABLEʱ��Ч��
	vector<CSVWString> vecConductorSplName;		// �ӵ����������ƣ�typeֵΪIKSCABT_CABLEʱ��Ч��
// 	int nProeFeatID;					// ProE��FeatureID

	std::vector<IKSCableSegment>	vecSegment;	// ���¶�Ӧ�Ķ�
	std::vector<IKSCableLocation>	vecCabLoc;	// ���¶�Ӧ��ProE����λ��
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

// ��������Ϣ
typedef struct __tagIKSHarness
{
	ProHarness	pProePt;				// ProE������ָ��
	ProAssembly pParentProeAssm;		// �����ĸ�װ����
	ProAsmcomppath stuProeAsmPath;		// ProE��װ��·��
	CSVWString	strName;				// ��������
	SVBASEMATRIX matWld;				// �����任����������ϵλ�õ�ת������

	IKSCable network;					// ����network��Ӧ��ProE����
	std::vector<IKSCable>	vecCables;	// ������Ӧ������
	std::vector<IKSCableLocation>	vecHarnessLoc;	// ������Ӧ��ProE����λ��

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

// ���µķ�֧·��
typedef struct __tagIKSCableBranchPath
{
	ProCablelocation stuProCabLoc1;		// ProE����λ��1
	ProCablelocation stuProCabLoc2;		// ProE����λ��2
	std::vector<ProCable> vecCable;		// ͨ���÷�֧·���ĵ���

	const IKSCableLocation *pIKSCabLoc1;		// ����λ��1(��ʱ����)
	const IKSCableLocation *pIKSCabLoc2;		// ����λ��2(��ʱ����)
	std::vector<const IKSCable*> vecIKSCablePt;	// ͨ���÷�֧·���ĵ���(��ʱ����)

	double dDiameter;					// ���·�֧·����ֱ����ͨ���÷�֧·�������е��µ��ۺ�ֱ����

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

// ���·�֧·���ĵ�����Ϣ
typedef struct __tagIKSCableBranchPathCabInf
{
	const IKSCable* pIKSCablePt;				// ��������(��ʱ����)
	std::vector<UINT> vecBranchPathIndex;		// ���µķ�֧·��������

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

// ���·�֧·���ĵ��¶˵�
typedef struct __tagIKSCableBranchPathCabEnd
{
	ProCablelocation stuProCabLoc;		// �˵��Ӧ��ProE����λ��
	ProCable stuCable;					// �˵��Ӧ��ProE����
	ProAsmcomppath stuHarnessAsmPath;	// ��������������װ��·��
	CSVWString strCabRefDes;			// �˵��Ӧ�����������߼�����(REF_DES)
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

// ������������ڶ˲�����Ϣ
typedef struct __tagIKSConnectorEntryPortsParamInfo
{
	CSVWString strCSysName;			// ����ϵ����
	CSVWString strType;				// ����,����ROUND
	double dIntLength;				// �ڲ�����

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

// ���������Ĳ�����Ϣ
typedef struct __tagIKSConnectorParamInfo
{
	CSVWString strRefDes;			// ָ������-�߼�����(REF_DES)
	CSVWString strModelName;		// ģ������
	BOOL bIsMdlAsm;					// ģ���Ƿ�Ϊװ����(TRUE��ʾװ����,FALSE��ʾ���)
	CSVWString strLayer;			// ��
	CSVWString strType;				// ����,CONNECTOR,SPLICE��
	std::vector<IKSConnectorEntryPortsParamInfo> vecEntryPortsInfo;	// ��ڶ�

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

// ������������Ϣ
typedef struct __tagIKSConnector
{
	ProConnector stuProConnector;		// ProE������ָ��
	ProMdl pMdl;						// ��������ģ��ָ��
	ProAsmcomppath stuParentAsmAsmPath;	// ��װ�����װ��·��
	ProMdl pParentAsm;					// ��װ����ָ��
	CSVWString	strName;				// ������������
	SVBASEMATRIX matWld;				// ���������任����������ϵλ�õ�ת������

	CSVWString strRefDes;				// �����������߼�����(REF_DES)
	std::vector<ProModelitem> vecEntryPortsCsys;	// ��ڶ�����ϵ

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

// ���ߵ�����������Ϣ
typedef struct __tagIKSTrunkCabConnector
{
	IKSConnector stuConnData;				// ������������

	IKSConnector stuEquipmentConnData;		// ��Ӧ���豸������������
	IKSSpool stuBranchSplData;				// ��֧������������
	CSVWString	strBranchSplNamePrefix;		// ��֧������������ǰ׺(����:L;���յ���������Ϊ:L_�豸���������߼�����)

	CSVWString strTrunkEntryPortName1;		// ������ڶ�����1
	CSVWString strTrunkEntryPortName2;		// ������ڶ�����2
	CSVWString strEquipmentEntryPortName;	// �豸��ڶ�����

	UINT uTrunkEntryPortIndex1;				// ������ڶ�����1(���ߵ���������������ڶ�����ϵ�е�����)
	UINT uTrunkEntryPortIndex2;				// ������ڶ�����2(���ߵ���������������ڶ�����ϵ�е�����)
	UINT uTrunkEquipmentEntryPortIndex;		// �����豸��ڶ�����(���ߵ���������������ڶ�����ϵ�е�����)
	UINT uEquipmentEntryPortIndex;			// �豸��ڶ�����(�豸����������������ڶ�����ϵ�е�����)

	SVBASEDOUBLE3 vTrunkConnWldPos;			// ������������λ�ã�����������ڶ�λ�ü��㣩
	SVBASEDOUBLE3 vTrunkEntryPortWldPos1;	// ������ڶ˵�����λ��
	SVBASEDOUBLE3 vTrunkEntryPortWldAxisZ1;	// ������ڶ˵�����Z�᷽��
	UINT uTrunkEntryPortProCabLocIndex1;		// ������ڶ˶�Ӧ�ĵ���λ������
	SVBASEDOUBLE3 vTrunkEntryPortCabLocTan1;	// ������ڶ˶�Ӧ�ĵ���λ�����߷���
	SVBASEDOUBLE3 vTrunkEntryPortWldPos2;	// ������ڶ˵�����λ��
	SVBASEDOUBLE3 vTrunkEntryPortWldAxisZ2;	// ������ڶ˵�����Z�᷽��
	UINT uTrunkEntryPortProCabLocIndex2;	// ������ڶ˶�Ӧ�ĵ���λ������
	SVBASEDOUBLE3 vTrunkEntryPortCabLocTan2;	// ������ڶ˶�Ӧ�ĵ���λ�����߷���
	SVBASEDOUBLE3 vTrunkEquEntryPortWldPos;		// �����豸��ڶ˵�����λ��
	SVBASEDOUBLE3 vTrunkEquEntryPortWldAxisZ;	// �����豸��ڶ˵�����Z�᷽��
	UINT uTrunkEquEntryPortProCabLocIndex;		// �����豸��ڶ˶�Ӧ�ĵ���λ������
	SVBASEDOUBLE3 vTrunkEquEntryPortCabLocTan;	// �����豸��ڶ˶�Ӧ�ĵ���λ�����߷���

	SVBASEDOUBLE3 vEquipmentEntryPortWldPos;		// �豸��ڶ˵�����λ��
	SVBASEDOUBLE3 vEquipmentEntryPortWldAxisZ;		// �豸��ڶ˵�����Z�᷽��
	UINT uEquipmentEntryPortProCabLocIndex;			// �豸��ڶ˶�Ӧ�ĵ���λ������
	SVBASEDOUBLE3 vEquipmentEntryPortCabLocTan;	// �豸��ڶ˶�Ӧ�ĵ���λ�����߷���

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

// ���ߵ��¶���Ϣ
typedef struct __tagIKSTrunkCabSegmentInfo
{
	CSVWString	strHarnessName;							// ��������

	IKSTrunkCabConnector stuConnStart;					// ��ʼ��������
	IKSTrunkCabConnector stuConnEnd;					// ��ֹ��������
	std::vector<IKSTrunkCabConnector> vecConnMid;		// �м��������

	IKSSpool stuSplData;								// ���ߵ��¶ε���������
	CSVWString	strSplNamePrefix;						// ���ߵ��¶ε���������ǰ׺(����:ZX;���յ���������Ϊ:ZX_��ʼ���������߼�����__��ֹ���������߼�����)

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

// ģ�ͽڵ�������Ϣ
typedef struct __tagCABModelNodeData
{
	ProMdl		handle;							// �ڵ���(ָ��ProEģ�͵�ָ��)
	int			nFeatureID;						// ����ID(��ǰ�ڵ��Ӧ������ID)
	ProAssembly pParentProeAssm;				// ��װ����
	ProAsmcomppath stuProeAsmPath;				// ProE��װ��·��
	int			nType;							// �ο�ö������CABMODELNODETYPE
	CUnicodeString		strName;				// �ڵ�����
	double		matrix[4][4];					// ���ڵ�任����һ�㼶����ϵλ�õ�ת������
	double		matWld[4][4];					// ���ڵ�任����������ϵλ�õ�ת������
	int			nHarnessIndex;					// ��������(ֻ�е�nTypeֵΪCABMNTYPE_PART_HARNESS��ͨ��ģ���������������ݺ����Ч)
	int			nConnectorIndex;				// ������������(ֻ�е�nTypeֵΪCABMNTYPE_PART_CONNECTOR��ͨ��ģ�������ɵ����������ݺ����Ч)
	CBPDynamicArray<__tagCABModelNodeData>	arrSubNode;		// �ӽڵ�����

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
	// ������������
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
	// �������
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

// �������ӹ�ϵ��Ԫ��
typedef struct __tagIKSCableConnectTabElem
{
	CString strHarnessName;		// ��������(���´���)
	CString strCableName;		// ��������(��֧����)
	CString strConnRefDes1;		// ��ʼ�����������߼�����(��ʼ�˿�)
	CString strConnMdlName1;	// ��ʼ����������ģ������(��ʼ������������)
	CString strConnRefDes2;		// ��ֹ�����������߼�����(��ֹ�˿�)
	CString strConnMdlName2;	// ��ֹ����������ģ������(��ʼ������������)
	CString strCabType;			// ���·�֧����
	CString strCabSpoolName;	// ������������(��֧���� + "_" + ��֧����)

	double dDiameter;			// �����⾶
	double dMinBendRadius;		// ��Сת��뾶
	CString strColor;			// ��ɫ
	double dDensity;			// ���ܶ�

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

// ���������Ԫ��
typedef struct __tagIKSCableSpoolTabElem
{
	CString strSymbol;			// �������(��������/��֧����)
	CString strSpoolType;		// ��������(����)
	double dDiameter;			// �����⾶
	double dMinBendRadius;		// ��Сת��뾶
	CString strUnit;			// ��λ
	CString strColor;			// ��ɫ
	double dDensity;			// ���ܶ�

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

// �������ӹ�ϵ��
typedef struct __tagIKSCableConnectTab
{
	CBPDynamicArray<IKSCableConnectTabElem> arrCabConnTabElem;			// �������ӹ�ϵ
	CBPDynamicArray<CBPDynamicArray<UINT> > arrHarnCabElemIndex;		// ������Ӧ�ĵ�������(ͬһ���������ƶ�Ӧ��arrCabConnTabElem������)
	CBPDynamicArray<IKSCableSpoolTabElem> arrCableSpoolTabElem;			// ����������Ϣ

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

// ���������ѡ��
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

// �������ӹ�ϵ��ѡ��
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

// ���ߵ������ӹ�ϵ��
typedef struct __tagIKSTrunkCableConnectTab
{
	CBPDynamicArray<IKSTrunkCabSegmentInfo> arrTrunkCabSegElem;			// ���ߵ��¶�
	CBPDynamicArray<IKSCableSpoolTabElem> arrCableSpoolTabElem;			// ����������Ϣ

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

// ���ߵ������ӹ�ϵ��ѡ��
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

// ���������ѡ��
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

// ���߽ӵ��ѡ��
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

// ���������(�����߾���)Ԫ��
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

// �������ӹ�ϵ�ۺϱ����Ԫ��
typedef struct __tagIKSCableConnectOverallTabCableElem
{
	CString strCableName;		// ��������(��֧����)
	CString strConnRefDes1;		// ��ʼ�����������߼�����(��ʼ�˿�)
	CString strConnMdlName1;	// ��ʼ����������ģ������(��ʼ������������)
	CString strConnRefDes2;		// ��ֹ�����������߼�����(��ֹ�˿�)
	CString strConnMdlName2;	// ��ֹ����������ģ������(��ʼ������������)
	CString strCabType;			// ���·�֧����
	CString strCabSpoolName;	// ������������(��֧���� + "_" + ��֧����)

	CBPDynamicArray<CString> arrWireElem;		// �߾�����
	double dDiameter;			// ����ֱ��
	double dDensity;			// �������ܶ�

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

// �������ӹ�ϵ�ۺϱ�����Ԫ��
typedef struct __tagIKSCableConnectOverallTabHarnElem
{
	CString strHarnessName;		// ��������(���´���)
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

// �������ӹ�ϵ�ۺϱ�
typedef struct __tagIKSCableConnectOverallTab
{
	CBPDynamicArray<IKSCableConnectOverallTabHarnElem> arrHarnElem;		// ����������Ϣ
	CBPDynamicArray<IKSCableSpoolTabElem> arrCableSpoolTabElem;			// ����������Ϣ
	CBPDynamicArray<IKSWireSpoolTabElem> arrWireSpoolTabElem;			// �߾�������Ϣ

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

// �������ӹ�ϵ��ѡ��
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

// ���·�֧���ȱ�����Ԫ��
typedef struct __tagIKSCableBranchLengthTabDataElem
{
	CSVWString strStart;		// �������(�˶ε��·�֧�����)
	CSVWString strEnd;			// �յ�����(�˶ε��·�֧���յ�)
	double dLength;				// ����(�����������ĳ���)
	double dCabMdlLength;		// ����ģ�ͳ���(δ�������ĳ���)
	double dDiameter;			// ֱ��(�˶ε��·�֧��ֱ��)

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

// ������֧���ȱ�����Ԫ��
typedef struct __tagIKSHarnessBranchLengthTabDataElem
{
	CSVWString strHarnessName;		// ��������
	std::vector<IKSCableBranchLengthTabDataElem> vecCabBranchDataElem;	// ��֧����Ԫ��

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

// ���·�֧���ȱ�
typedef struct __tagIKSHarnessBranchLengthTab
{
	std::vector<IKSHarnessBranchLengthTabDataElem> vecHarnBranchDataElem;	// ��֧����Ԫ��

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

// �����������ȱ�����Ԫ��
typedef struct __tagIKSCableProductLengthTabDataElem
{
	CSVWString strCableName;			// ��������(���·�֧����)
	CSVWString strStartConnRefDes;		// ��ʼ���������߼�����
	CSVWString strEndConnRefDes;		// ��ֹ���������߼�����
	double dLength;						// ����(�����������ĳ���)
	double dCabMdlLength;				// ����ģ�ͳ���(δ�������ĳ���)
	double dDiameter;					// ֱ��
	double dMass;						// ����

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

// �����������ȱ�����Ԫ��
typedef struct __tagIKSHarnessProductLengthTabDataElem
{
	CSVWString strHarnessName;		// ��������
	std::vector<IKSCableProductLengthTabDataElem> vecCableDataElem;	// ��������Ԫ��

	double dCableMass;				// ��������
	double dHarnessMass;			// ��������(��������+��ص�����������)

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

// �����������ȱ�
typedef struct __tagIKSHarnessProductLengthTab
{
	std::vector<IKSHarnessProductLengthTabDataElem> vecHarnDataElem;	// ��������Ԫ��

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

// ���������ӹ�ϵ���Ԫ��
typedef struct __tagIKSCheckCableConnectInfResultElem
{
	int nResult;					// �����(�ο�ö����IKSCABLECONNINFCHECKRESULT)
	const IKSHarness* pHarness;		// ��������Harness����ָ��(��ʱ����)
	const IKSCable* pCable;			// ��������ָ��(��ʱ����)

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

// ���������ӹ�ϵ��������
typedef struct __tagIKSCheckCableConInfConnector
{
	CUnicodeString strConnRefDes;		// �����������߼�����
	CUnicodeString strConnMdlName;		// ����������ģ������
	std::vector<CUnicodeString> vecCableName;	// ����������صĵ�������(������ʼ��ֹ����ͬ���������ĵ���,�ᱻ��¼����)

	const IKSConnector* pConnector;		// ������������ָ��(��ʱ����)
	int nResult;						// �����(�ο�ö����IKSCABLECONNINFCHECKRESULT)
	ProSelection pConstrainCsys;		// װ������ϵ

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

// �����������Խ��Ԫ��
typedef struct __tagIKSCheckCableCompleteResultElem
{
	const IKSHarness* pHarness;			// ��������Harness����ָ��(��ʱ����)
	const IKSCable* pCable;				// ��������ָ��(��ʱ����)

	const CABModelNodeData *pParentAsm;	// �߼�������δ�����������ڵ�װ����
	CSVWString strLogicalCableName;		// δ�����ĵ�������

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

// ���������������ۺ�ֱ�����Ԫ��
typedef struct __tagIKSCheckConnWhlCabDiaResultElem
{
	const IKSConnector* pConnector;					// ������������ָ��(��ʱ����)
	CBPDynamicArray<const IKSCable*> arrConnCable;	// ����������صĵ���(��ʱ����)(������ʼ��ֹ����ͬ���������ĵ���,�ᱻ��¼����)
	double dConnWhlCabDia;							// �����ۺ�ֱ��

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

// ���������ջ�·���Ԫ��
typedef struct __tagIKSCheckHarnessClosePathResultElem
{
	const IKSHarness* pHarness;							// ����Harness����ָ��(��ʱ����)
	std::vector<const IKSCable*> arrClosePathCable;		// ���·�ջ�·�ĵ�������ָ��(��ʱ����)(������Щ���µĲ��߿�������ջ�·)
	std::vector<BPBASEUINT2> arrCableClosePathStartEndLocID;	// ���·�ջ�·����ʼ��ֹ����λ�õ�����ID
	CBPDynamicArray<CBPDynamicArray<UINT>> arrClosePathCableAllLocFeatID;	// ���з�ջ�·�ĵ��µ����е���λ�õ�����ID

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

// ���������Ŀ���Ϣ
typedef struct __tagChkHoleCapHoleInfo
{
	int nID;							// ID
	double dRefDiameter;				// �ο�ֱ��
	SVBASEDOUBLE3 vCenterPos;			// �����ĵ�����
	SVBASEDOUBLE3 vCenterAxis;			// �����ĵ��᷽��
	int nHoleSecShapeType;					// �׺������״����,�ο�ö����IKSCABHOLESECSHAPETYPE
	std::vector<IKSCABDCurve> vecSecShape;		// �׺������״(����)

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

// �������������Ŀ�����ϵ��Ϣ
typedef struct __tagChkBatchHoleCapHoleCsysInfo
{
	ProModelitem stuHole;				// �׵�ProE����
	CSVWString strHoleName;				// ������
	double dHoleRefDiameter;			// �ײο�ֱ��
	double dCableDiameterMax;			// �����ۺ�ֱ������
	double dCableDiameter;				// �����ۺ�ֱ��

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

// ���������Ŀ׼�������Ϣ
typedef struct __tagChkHoleCapHoleHarnessInfo
{
	ChkHoleCapHoleInfo hole;					// ����Ϣ
	ChkBatchHoleCapHoleCsysInfo stuBatchHole;	// ��������Ϣ
	std::vector<IKSHarness> vecHarnessThrHole;	// �����׵�����

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

// ����������������Ϣ
typedef struct __tagChkHoleCapConfig
{
	int nCheckMode;								// ���ģʽ,�ο�ö����IKSCHECKHOLECAPACITYMODE
	double dCheckCableAreaRatio;				// �����ϵ��(�ٷֱ�)
	double dCheckHoleAreaSurplus;				// ������(�ٷֱ�)

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

// ���������Ľ����Ϣ
typedef struct __tagChkHoleCapResult
{
	BOOL bIsHoleCapOK;							// ������������µ�ͨ��Ҫ��

	double dHoleArea;							// �׵�ʵ�����
	double dHarnessTotalRefArea;				// �����ܲο����
	double dHoleAreaUseRatio;					// ��������(�ٷֱ�)

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

// Ӱ��������·������
typedef struct __tagIKSCheckInfluenceCableAnalysisResult
{
	const IKSCable* pCable;								// ���µ�����ָ��
	double dRefLength;									// ���µ��ܲο�����
	double dDiffRefLength;								// ����ͬ·���ĵ��²ο�����
	std::vector<UINT> arrDiffCableLocIndexPair;			// ����ͬ·���ĵ���λ��������(IKSCable::vecCabLoc��Ӧ����,�����ɶ�)

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

// Ӱ�����������������
typedef struct __tagIKSCheckInfluenceHarnessAnalysisResult
{
	const IKSHarness* pHarness;							// ����������ָ��
	double dRefLength;									// �������ܲο�����
	double dDiffRefLength;								// ����ͬ·���ĵ��²ο�����
	std::vector<IKSCheckInfluenceCableAnalysisResult> arrCableAnalysisRet;			// ���·������

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

// �������ͼ�����Ԫ��
typedef struct __tagIKSCheckCableTypeCabElem
{
	CSVWString strCabType;								// ��������
	const IKSCable* pCable;								// ���µ�����ָ��
	const IKSHarness* pHarness;							// ����������ָ��

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

// �������ͼ�������
typedef struct __tagIKSCheckCableTypeCabGroup
{
	CSVWString strCabType;								// ��������
	std::vector<IKSCheckCableTypeCabElem> arrCable;		// ����

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

// �������ͼ����Ԫ��
typedef struct __tagIKSCheckCableTypeResultElem
{
	IKSCheckCableTypeCabElem stuCableElem1;				// ��һ������Ԫ��
	IKSCheckCableTypeCabElem stuCableElem2;				// �ڶ�������Ԫ��
	double dSimilarPercent;								// ���ƶȰٷֱ�

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

// ��������װ���������Ϣ
typedef struct __tagConnectorAsmConfig
{
	std::vector<CString> vecConnLibPath;	// ���������洢��·��
	CString strConnMdlAsmCSysName;			// ��������ģ��װ������ϵ

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

