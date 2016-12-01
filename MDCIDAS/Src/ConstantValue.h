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

// ����ͼԪ������
typedef struct __tagLayoutItemData
{
	int nType;										// Ԫ�ط������ͣ�����LayoutItemType
	double dWidth;									// ���
	double dDepth;									// ���
	SVDOUBLE3 o;									// ԭ��
	SVDOUBLE3 x;									// X��
	SVDOUBLE3 y;									// Y��

	__tagLayoutItemData()
	{
		nType = SCT_NULL;
		dWidth = 0.0;
		dDepth = 0.0;
	}
	__tagLayoutItemData(const __tagLayoutItemData &data)
	{
		nType = data.nType;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		o = data.o;
		x = data.x;
		y = data.y;
	}
	__tagLayoutItemData operator=(const __tagLayoutItemData &data)
	{
		if (&data == this)
			return *this;
		nType = data.nType;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		o = data.o;
		x = data.x;
		y = data.y;
		return *this;
	}
}LayoutItemData;

typedef vector<LayoutItemData> LayoutItemDataArray;

// ����ͼ����
typedef struct __tagLayoutData
{
	double dTotalLength;							// �ܳ���
	double dTotalWidth;								// �ܿ��
	CString strRemark;								// ��ע��Ϣ
	LayoutItemDataArray arrItems;					// ���ż�

	__tagLayoutData()
	{
		dTotalLength = 0.0;
		dTotalWidth = 0.0;
		strRemark = _T("");
	}
	__tagLayoutData(const __tagLayoutData &data)
	{
		dTotalLength = data.dTotalLength;
		dTotalWidth = data.dTotalWidth;
		strRemark = data.strRemark;
		arrItems = data.arrItems;
	}
	__tagLayoutData operator=(const __tagLayoutData &data)
	{
		if (&data == this)
			return *this;
		dTotalLength = data.dTotalLength;
		dTotalWidth = data.dTotalWidth;
		strRemark = data.strRemark;
		arrItems = data.arrItems;
		return *this;
	}
}LayoutData;

// �������
typedef struct __tagModelConfiguration
{
	int nMajorClass;								// ���
	int nModelType;									// ������ͣ�����DesignModelType
	bool bIsCreate;									// �Ƿ�����
	CString strTempPartNo;							// ��ʱͼ��
	CString strFormalPartNo;						// ��ʽͼ��
	CString strPurchaseNo;							// �ɹ�����
	double dHieght;									// ��
	double dWidth;									// ��
	double dDepth;									// ��
	vector<IKSCsysData> arrPosition;				// ���λ��
	CString strRemark;								// ��ע

	__tagModelConfiguration()
	{
		nMajorClass = -1;
		nModelType = -1;
		bIsCreate = true;
		strTempPartNo = _T("");
		strFormalPartNo = _T("");
		strPurchaseNo = _T("");
		dHieght = 0.0;
		dWidth = 0.0;
		dDepth = 0.0;
		strRemark = _T("");
	}
	__tagModelConfiguration(const __tagModelConfiguration &data)
	{
		nMajorClass = data.nMajorClass;
		nModelType = data.nModelType;
		bIsCreate = data.bIsCreate;
		strTempPartNo = data.strTempPartNo;
		strFormalPartNo = data.strFormalPartNo;
		strPurchaseNo = data.strPurchaseNo;
		dHieght = data.dHieght;
		dWidth = data.dWidth;
		dDepth = data.dDepth;
		arrPosition = data.arrPosition;
		strRemark = data.strRemark;
	}
	__tagModelConfiguration operator=(const __tagModelConfiguration &data)
	{
		if (&data == this)
			return *this;
		nMajorClass = data.nMajorClass;
		nModelType = data.nModelType;
		bIsCreate = data.bIsCreate;
		strTempPartNo = data.strTempPartNo;
		strFormalPartNo = data.strFormalPartNo;
		strPurchaseNo = data.strPurchaseNo;
		dHieght = data.dHieght;
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

//===================================================================================================
// ����ģ��

//===================================================================================================
// ����ͼģ��



//===================================================================================================

