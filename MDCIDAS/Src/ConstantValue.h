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
	CString strPassageWidth;						// ͨ�����
	CString strHeightOfITRack;						// IT�����񡪡��߶�
	CString strWidthOfITRack;						// IT�����񡪡����
	CString strDepthOfITRack;						// IT�����񡪡����
	int nFrontDoorTypeOfITRack;						// IT�����ǰ������
	int nBackDoorTypeOfITRack;						// IT����ĺ�������
	int nFrontDoorLockTypeOfITRack;					// IT�����ǰ��������
	int nBackDoorLockTypeOfITRack;					// IT����ĺ���������
	int nSideDoorTypeOfITRack;						// IT����Ĳ���
	int nHeightOfPedestal;							// �����߶�
	int nInsideFloorType;							// ģ���ڲ��ذ�
	int nZouXianJiaType;							// ǿ�������߼���������
	CString strDistanceBetwZXJAndJigui;				// �����߼ܻ������ã������߼ܾ�����񶥲����룻
	CString strNumOf1UPanel;						// 1U����������
	CString strNumOf2UPanel;						// 2U����������
	CString strNumOfLPallet;						// L���а������
	CString strNumOfLightLayer;						// ���ز�������
	CString strNumOfHeavyLayer;						// ���ز�������
	CString strNumOfStringingPanel;					// ������������
	int nHuiLiuPaiType;								// �����ŵ�����
	bool bIsWeiBanExist;							// Χ���Ƿ�����
	bool bIsInsideFloorExist;						// ģ���ڲ��Ƿ����õذ�
	bool bIsTABuExist;								// �Ƿ�����̤��
	int nControlCabinetType;						// �ܿع�����

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
// ����ģ��

//===================================================================================================
// ����ͼģ��



//===================================================================================================

