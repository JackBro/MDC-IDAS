//===================================================================================================
// File:
//		TotalUnitBuilder.h
// Summary:
//		�������ýṹģ��������
// Date:
//		2016-11-16
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#pragma once

//===================================================================================================
// ͷ�ļ�
#include "LayObject.h"
#include "XmlToObject.h"

//===================================================================================================
// �궨��

//===================================================================================================
// ö�ٶ���

//===================================================================================================
// ȫ�ֱ�������

//===================================================================================================
// �ṹ�嶨��

//===================================================================================================
// �ඨ��

// �������ýṹģ����������
class CTotalUnitBuilder
{
public:
	CTotalUnitBuilder();
	virtual ~CTotalUnitBuilder();

public:
	// ����ģ��
	bool BuildModel(
		const TotalUnitConfiguration &totalUnitConfig					// ��������(in)
		);
	// ����ͼ�Ż�ȡģ��
	ProMdl LoadMdlByPartNo(
		const CString &strPartNo										// ͼ��(in)
		);
	// װ��ģ��
	bool AssembleModel(
		ProAssembly pTopAsm,											// �����(in)
		const ModelConfiguration &mdlConfig								// ģ������(in)
		);
	// װ��ģ��
	bool AssembleModel(
		ProAssembly pTopAsm,											// �����(in)
		ProMdl pCompMdl,												// Ԫ��(in)
		const CString &strCompCsysName,									// Ԫ��װ������(in)
		const IKSCsysData &asmPosition									// װ��λ��(in)
		);
	// װ��ģ��
	bool AssembleModel(
		ProAssembly pTopAsm,											// �����(in)
		const CString &strTemplateName,									// ģ������(in)
		const CString &strCompCsysName,									// Ԫ��װ������(in)
		const ModelConfiguration &mdlConfig								// ģ������(in)
		);
	// �������������
	int FindModelConfig(
		int nModelType,													// ģ������(in)
		double dSymbolWidth,											// ���ŵĿ��(in)
		double dSymbolHeight,											// ���ŵĸ߶�(in)
		const ModelConfigurationArray &arrMdlConfig						// ������ü�(in)
		);
	// ���ݷ�������λ�ú���ת�Ƕȣ�����װ��λ��
	bool GetModelPosition(
		double dLayoutLeft,												// ����ͼ�����Ͻ�X(in)
		double dLayoutTop,												// ����ͼ�����Ͻ�Y(in)
		double dLayoutWidth,											// ����ͼ�Ŀ��(in)
		double dLayoutHeight,											// ����ͼ�ĸ߶�(in)
		double dSymbolWidth,											// ���ŵĿ��(in)
		double dSymbolHeight,											// ���ŵĸ߶�(in)
		double dCenterX,												// ��������X(in)
		double dCenterY,												// ��������Y(in)
		double dAngle,													// ����˳ʱ����ת�Ƕ�(in)
		IKSCsysData &position											// ģ��װ��λ��(out)
		);
	// ��ȡ��ʱͼ��
	CString GetTempPartNo(
		const CString &strTemplateName									// ģ���ļ���
		);
	// ��ȡģ���ļ���
	CString GetTemplateNameByModelType(
		int nModelType													// �������
		);
	// ��ȡװ����������
	CString GetCompCsysNameByModelType(
		int nModelType													// �������
		);

	// ���ݶ����ɼ���Ͳ���ͼ���ż���ѡ�����������
	bool SelectFWQJGConfiguration(
		const RequirementTabData &reqTabData,							// ����ɼ���
		CXmlToObject &xmlData,											// ����ͼXML�������
		vector<CLaySymbolObj*> &arrSymbols,								// ����ͼ���ż�
		ModelConfiguration &modelConfig									// ��������
		);
	// ���ݶ����ɼ���Ͳ���ͼ���ż���ѡ��ܿع�
	bool SelectGKGConfiguration(
		const RequirementTabData &reqTabData,							// ����ɼ���
		CXmlToObject &xmlData,											// ����ͼXML�������
		vector<CLaySymbolObj*> &arrSymbols,								// ����ͼ���ż�
		ModelConfiguration &gkgConfig									// ��������
		);

	// ���ݶ����ɼ���ͨ�����ݿ��ȡ�����������������Ϣ
	bool GetFWQJGDBData(
		const RequirementTabData &reqTabData,							// ����ɼ���
		JiGuiDBData &jiguiData											// ��������
		);

	// ���ݶ����ɼ���ͨ�����ݿ��ȡ�ܿع��������Ϣ
	bool GetGKGDBData(
		const RequirementTabData &reqTabData,							// ����ɼ���
		JiGuiDBData &gkgData											// ��������
		);

	// ��ȡָ�����͵Ĳ���ͼ���ż�
	bool GetLayoutSymbols(int nSymbolType, const vector<CLaySymbolObj*> &arrAllSymbols, vector<CLaySymbolObj*> &arrOutSymbols);
	// ��ȡ�����߶�
	double GetHeightOfPedestal(int nHeightOfPedestal);

	// ��������ģ��
	bool TestBuildModel();
	// ����XML�ļ�����ģ��
	bool TestBuildModelByXML(const CString &strXMLPath);
	// ���ݶ�������ɼ������������ͼXML�ļ�������������ģ��
	bool TestBuildModelByReqTableAndLayoutFile(const CString &strDVFPath);
	// �����������ɲ�������ģ��
	bool TestAutoBuildModel();
	// �����������ɲ�������ģ��
	bool TestAutoBuildModel(const CString &strAsmPath, const CString &strPartNo, const CString &strName, const CString &strClass, double dHeight, double dWidth, double dDepth, const CString &strCompCsysName);
	// ������������
	bool TestTotalDesign();
	// ��ʼ��Ĭ�϶�������ɼ���
	bool InitDefaultReqTabData(RequirementTabData &reqTabData);
};

//===================================================================================================
