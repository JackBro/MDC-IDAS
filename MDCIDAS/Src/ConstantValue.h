//===================================================================================================
// Summary:
//		�ڲ�ʹ�ó����ͽṹ��
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
// ����Ϊ��������

//===================================================================================================
// ���ݿ�ģ��

//===================================================================================================
// ��������ģ��

//===================================================================================================
// ����ģ��

//===================================================================================================
// ����ͼģ��




//===================================================================================================
//===================================================================================================
// ����Ϊ�Զ������Ϣ

// ������Ϣ:��ʾ���ش���
#define WM_CUSTOM_SHOWWINDOW			WM_USER + 10001

//===================================================================================================
//===================================================================================================
// ����Ϊö��ֵ����

//===================================================================================================
// ���ݿ�ģ��

//===================================================================================================
// ��������ģ��

// ������������
typedef enum __tagDesignModelType
{
	DMT_UNKNOWN				= -1,					// δ֪
	DMT_ITC					= 1001,					// ����������
	DMT_MGT					= 1002,					// �ܿع�
	DMT_COL_HAED_MGT 		= 1003,					// ��ͷ�ܿع�
	DMT_TAC					= 1004,					// �յ���
	DMT_FHC					= 1005,					// ������
	DMT_COL_HAED_EMPTY		= 1006,					// ��ͷ�չ�
	DMT_PDR					= 1007,					// ����
	DMT_COL_HEAD_PDR		= 1008,					// ��ͷ����
	DMT_ROW_EMPTY			= 1009,					// �м�չ�
	DMT_DAO_FENG			= 1010,					// �����
	DMT_CASO4_FLOOR			= 1011,					// ����Ƶذ�
	DMT_STEEL_FLOOR			= 1012,					// ȫ��ͨ��ذ�
	DMT_COLD_FRONT_DOOR		= 1013,					// ͨ��ƽ��
	DMT_COLD_BACK_DOOR		= 1014,					// ͨ��͹��
	DMT_LEFT_FRAME			= 1015,					// ����
	DMT_RIGHT_FRAME			= 1016,					// �ҿ��
	DMT_FLIP_WINDOW			= 1017,					// ��ת����
	DMT_FIXED_WINDOW		= 1018,					// �̶�����
	DMT_ADJUST_WINDOW		= 1019,					// �ɵ�����
	DMT_FOOTSTEP			= 1020,					// ̤��
	DMT_ZOU_XIAN_JIA		= 1021,					// ǿ�������߼�
	DMT_GUANG_XIAN_ZXJ		= 1022,					// �������߼�
	DMT_WALL_PILLAR			= 1023,					// ǽ��
}DesignModelType;

// ģ������
typedef enum __tagMDCModuleType
{
	MT_LONG_MODULE			= 1,					// ��ģ��
	MT_MINI_MODULE			= 2,					// ΢ģ��
	MT_TENCENT				= 3,					// ��Ѷ
	MT_BAIDU_YANGQUAN		= 4,					// �ٶ���Ȫ
	MT_BAIDU_HUALONG		= 5,					// �ٶȻ���
	MT_NEIMENG_ALI			= 6,					// ���ɰ���
	MT_DIANXIN_MINI_MODULE	= 7,					// ����΢ģ��
}MDCModuleType;

// ����ģʽ
typedef enum __tagAirstreamPattern
{
	AP_COLD_SEAL				= 1,				// ��ͨ�����
	AP_HOT_SEAL					= 2,				// ��ͨ�����
	AP_COLDANDHOT_DOUBLESEAL	= 3,				// ����ͨ��˫���
}AirstreamPattern;

// IT����ǰ������
typedef enum __tagFrontDoorTypeOfITRack
{
	FDT_NO_DOOR					= 1,				// ��
	FDT_SINGLE_DENSEHOLE_DOOR	= 2,				// �����ܿ���
	FDT_DOUBLE_DENSEHOLE_DOOR	= 3,				// ˫���ܿ���
}FrontDoorTypeOfITRack;

// IT�����������
typedef enum __tagBackDoorTypeOfITRack
{
	BDT_NO_DOOR					= 1,				// ��
	BDT_SINGLE_DENSEHOLE_DOOR	= 2,				// �����ܿ���
	BDT_DOUBLE_DENSEHOLE_DOOR	= 3,				// ˫���ܿ���
	BDT_SINGLE_SOILD_DOOR		= 4,				// ����ʵ����
	BDT_DOUBLE_SOILD_DOOR		= 5,				// ˫��ʵ����
}BackDoorTypeOfITRack;

// IT����ǰ��������
typedef enum __tagFrontDoorLockTypeOfITRack
{
	FDLT_UNKNOWN			= -1,					// δ֪
	FDLT_UNIVERSIAL_LOCK	= 1,					// ͨ����
	FDLT_HANGING_EAR_LOCK	= 2,					// �Ҷ���
}FrontDoorLockTypeOfITRack;

// IT�������������
typedef enum __tagBackDoorLockTypeOfITRack
{
	BDLT_UNKNOWN			= -1,					// δ֪
	BDLT_UNIVERSIAL_LOCK	= 1,					// ͨ����
	BDLT_HANGING_EAR_LOCK	= 2,					// �Ҷ���
}BackDoorLockTypeOfITRack;

// IT�����������
typedef enum __tagSideDoorTypeOfITRack
{
	SDT_UNKNOWN				= -1,					// δ֪
	SDT_DEFAULT_TYPE		= 1,					// Ĭ��
	SDT_SINGLE_TYPE			= 2,					// ��������
	SDT_DOUBLE_TYPE			= 3,					// ˫������
}SideDoorTypeOfITRack;

// �����߶�
typedef enum __tagHeightOfPedestal
{
	HP_UNKNOWN				= -1,					// δ֪
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
	HP_OTHER				= 13,					// ����
}HeightOfPedestal;

// ģ���ڲ��ذ�
typedef enum __tagInsideFloorType
{
	IFT_UNKNOWN				= -1,					// δ֪
	IFT_NO_FLOOR			= 1,					// ��������
	IFT_DEFAULT_FLOOR		= 2,					// Ĭ������
}InsideFloorType;

// ���߼���������
typedef enum __tagZouXianJiaType
{
	ZXJT_UNKNOWN			= -1,					// δ֪
	ZXJT_MODULE_TYPE		= 1,					// ģ������
	ZXJT_MACHINE_ROOM_TYPE	= 2,					// ��������
}ZouXianJiaType;

// ����������
typedef enum __tagHuiLiuPaiType
{
	HLPT_UNKNOWN			= -1,					// δ֪
	HLPT_NO_TYPE			= 1,					// ������
	HLPT_HENGZHUANG_TYPE	= 2,					// ��װ
	HLPT_SHUZHUANG_TYPE		= 3,					// ��װ
}HuiLiuPaiType;

// �ܿع�����
typedef enum __tagControlCabinetType
{
	CCT_UNKNOWN				= -1,					// δ֪
	CCT_NO_CAB				= 1,					// ��
	CCT_COL_HEAD_CAB		= 2,					// ��ͷ�ܿع�
	CCT_IT_CAB				= 3,					// �������ܿع�
	CCT_COL_HEAD_PAD_CAB	= 4,					// ��ͷ�ܿع��PAD
	CCT_IT_PAD_CAB			= 5,					// �������ܿع��PAD
}ControlCabinetType;

//===================================================================================================
// ����ģ��

//===================================================================================================
// ����ͼģ��



//===================================================================================================
//===================================================================================================
// ����Ϊ�ṹ�嶨��

//===================================================================================================
// ���ݿ�ģ��

//===================================================================================================
// ��������ģ��

// ����ɼ�������
typedef struct __tagRequirementTabData
{
	int nModuleType;								// ģ������
	bool bIsExtFloorExist;							// ģ����Χ���޵ذ�
	int nAirstreamPattern;							// ����ģʽ
	double dPassageWidth;							// ͨ�����
	double dHeightOfITRack;							// IT�����񡪡��߶�
	double dWidthOfITRack;							// IT�����񡪡����
	double dDepthOfITRack;							// IT�����񡪡����
	int nFrontDoorTypeOfITRack;						// IT�����ǰ������
	int nBackDoorTypeOfITRack;						// IT����ĺ�������
	int nFrontDoorLockTypeOfITRack;					// IT�����ǰ��������
	int nBackDoorLockTypeOfITRack;					// IT����ĺ���������
	int nSideDoorTypeOfITRack;						// IT����Ĳ���
	int nHeightOfPedestal;							// �����߶�
	int nInsideFloorType;							// ģ���ڲ��ذ�
	int nZouXianJiaType;							// ǿ�������߼���������
	double dDistanceBetwZXJAndJigui;				// (���߼ܻ�������)���߼ܾ�����񶥲����룻
	int nNumOf1UPanel;								// 1U����������
	int nNumOf2UPanel;								// 2U����������
	int nNumOfLPallet;								// L���а������
	int nNumOfLightLayer;							// ���ز�������
	int nNumOfHeavyLayer;							// ���ز�������
	int nNumOfStringingPanel;						// ������������
	int nHuiLiuPaiType;								// �����ŵ�����
	bool bIsWeiBanExist;							// Χ���Ƿ�����
	bool bIsInsideFloorExist;						// ģ���ڲ��Ƿ����õذ�
	bool bIsTaBuExist;								// �Ƿ�����̤��
	int nControlCabinetType;						// �ܿع�����

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

// �������
typedef struct __tagModelConfiguration
{
	CString strMajorClass;							// �������
	int nModelType;									// ������ͣ�����DesignModelType
	bool bIsCreate;									// �Ƿ�����
	CString strTempPartNo;							// ��ʱͼ��
	CString strFormalPartNo;						// ��ʽͼ��
	CString strPurchaseNo;							// �ɹ�����
	double dHeight;									// ��
	double dWidth;									// ��
	double dDepth;									// ��
	vector<IKSCsysData> arrPosition;				// ���λ��
	CString strRemark;								// ��ע

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

// �������ñ�
typedef struct __tagTotalUnitConfiguration
{
	CString strAsmName;								// �������
	int nCloseType;									// ��շ�ʽ
	double dCabinetHeight;							// ����߶�
	int nModulePosition;							// ģ��λ��
	double dBaseHeight;								// �����߶�
	int nModuleType;								// ģ������
	int nSameLayoutNumber;							// ��ͬ��������
	ModelConfigurationArray arrModelConfig;			// ���ģ������

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

// ����ͼ���ݿ�ṹ
typedef struct __tagLayoutDBData
{
	CString strNumber;								// ���
	CString strDate;								// ��������
	CString strXMLPath;								// XML�ļ�·��
	CXmlToObject *pLayoutXML;						// ����XML�ļ�ָ��

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

// �����������ݿ�ṹ
typedef struct __tagConfigDBData
{
	CString strNumber;								// ���
	CString strDate;								// ��������
	TotalUnitConfiguration totalConfig;				// ������������

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

// �������ݿ�ṹ
typedef struct __tagTotalLayoutConfigDBData
{
	LayoutDBData layout;							// ����ͼ����
	ConfigDBData config;							// ������������

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

// ����ɼ����ݿ�ṹ
typedef struct __tagRequirementDBData
{
	CString strNumber;										// ���
	CString strDate;										// ��������
	RequirementTabData tabData;								// ����ɼ������ݽṹ
	TotalLayoutConfigDBDataArray arrTotalData;				// �������ݼ�

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

// ��Ŀ���ݿ�ṹ
typedef struct __tagProjectDBData
{
	CString strUser;								// �û�
	CString strNumber;								// ���
	CString strDate;								// ��������
	RequirementDBDataArray arrReqDBData;			// ����ɼ����ݼ�

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

// ���������
typedef struct __tagJiGuiDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dHeight;									// ��
	double dWidth;									// ��
	double dDepth;									// ��
	CString strFrontDoor;							// ǰ��
	CString strFrontDoorLock;						// ǰ������
	CString strBackDoor;							// ����
	CString strBackDoorLock;						// ��������
	CString strJiaMianBan;							// �����
	CString strChuanXianMianBan;					// �������
	CString strLTuoBan;								// L���а�
	CString strRemark;								// ��ע

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

// ��������
typedef struct __tagPanelDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dHeight;									// �߶�
	CString strUNum;								// ����U��
	double dWidth;									// ���
	double dDepth;									// ���
	CString strRemark;								// ��ע

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

// �����ŵ�����
typedef struct __tagJiGuiMenDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dFixedHeight;							// ����߶�
	double dHeight;									// �߶�
	double dFixedWidth;								// ������
	double dWidth;									// ���
	double dDepth;									// ���
	CString strIsPadHole;							// PAD��װ��
	CString strIsHinge;								// ����
	CString strRemark;								// ��ע

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

// ������ŵ�����
typedef struct __tagJiGuiCeMenDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dFixedHeight;							// ����߶�
	double dHeight;									// �߶�
	double dFixedDepth;								// �������
	double dDepth;									// ���
	double dThickness;								// ���
	CString strRemark;								// ��ע

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

// ���񸽼�_�а������
typedef struct __tagJGFJPlateDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dHeight;									// �߶�
	double dWidth;									// ���
	double dDepth;									// ���
	CString strRemark;								// ��ע

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

// ���񸽼�_�����ŵ�����
typedef struct __tagJGFJHLPDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dHeight;									// �߶�
	double dWidth;									// ���
	double dDepth;									// ���
	CString strRemark;								// ��ע

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

// ���񸽼�_����������
typedef struct __tagJGFJOtherDBData
{
	CString strXilie;								// ϵ��
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dHeight;									// �߶�
	double dWidth;									// ���
	double dDepth;									// ���
	CString strRemark;								// ��ע

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

// ����Χ�������
typedef struct __tagTopWeiBanDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dHeight;									// �߶�
	double dWidth;									// ���
	double dDepth;									// ���
	CString strRemark;								// ��ע

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

// ����������
typedef struct __tagTopWindowDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dHeight;									// �߶�
	double dWidth;									// ���
	double dDepth;									// ���
	CString strRemark;								// ��ע

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

// �ذ������
typedef struct __tagFloorDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dFixedHeight;							// ����߶�
	double dLength;									// ����
	double dWidth;									// ���
	double dThickness;								// ���
	CString strRemark;								// ��ע

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

// ͨ��������
typedef struct __tagPassageDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dFixedHeight;							// ����߶�
	double dHeight;									// �߶�
	double dWidth;									// ���
	double dDepth;									// ���
	CString strRemark;								// ��ע

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

// ����ϵͳ������
typedef struct __tagCablingSystemDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dHeight;									// �߶�
	double dWidth;									// ���
	double dDepth;									// ���
	CString strRemark;								// ��ע

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

// ����������
typedef struct __tagDiZuoDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dHeight;									// �߶�
	double dWidth;									// ���
	double dDepth;									// ���
	CString strRemark;								// ��ע

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

// ��������������
typedef struct __tagDiZuoFuJianDBData
{
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dHeight;									// �߶�
	double dWidth;									// ���
	double dDepth;									// ���
	CString strRemark;								// ��ע

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

// ר�õ���������
typedef struct __tagSpecialDiZuoDBData
{
	CString strXilie;								// ϵ��
	CString strCode;								// ����
	CString strPartNo;								// ͼ��
	CString strName;								// ����
	CString strEngName;								// Ӣ����
	CString strUnit;								// ��λ
	CString strState;								// ״̬
	CString strClass;								// ���
	double dHeight;									// �߶�
	double dWidth;									// ���
	double dDepth;									// ���
	CString strRemark;								// ��ע

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
// ����ģ��

//===================================================================================================
// ����ͼģ��



//===================================================================================================

