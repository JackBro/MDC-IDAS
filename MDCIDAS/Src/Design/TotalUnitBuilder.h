//===================================================================================================
// File:
//		TotalUnitBuilder.h
// Summary:
//		整机配置结构模型生成器
// Date:
//		2016-11-16
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#pragma once

//===================================================================================================
// 头文件

//===================================================================================================
// 宏定义

//===================================================================================================
// 枚举定义

//===================================================================================================
// 全局变量定义

//===================================================================================================
// 结构体定义

//===================================================================================================
// 类定义

// 整机配置结构模型生成器类
class CTotalUnitBuilder
{
public:
	CTotalUnitBuilder();
	virtual ~CTotalUnitBuilder();

public:
	// 生成模型
	bool BuildModel(
		const TotalUnitConfiguration &totalUnitConfig					// 整机配置(in)
		);
	// 根据图号获取模型
	ProMdl LoadMdlByPartNo(
		const CString &strPartNo										// 图号(in)
		);
	// 装配模型
	bool AssembleModel(
		ProAssembly pTopAsm,											// 总组件(in)
		const ModelConfiguration &mdlConfig								// 模型配置(in)
		);
	// 装配模型
	bool AssembleModel(
		ProAssembly pTopAsm,											// 总组件(in)
		ProMdl pCompMdl,												// 元件(in)
		const CString &strCompCsysName,									// 元件装配坐标(in)
		const IKSCsysData &asmPosition									// 装配位置(in)
		);
	// 装配模型
	bool AssembleModel(
		ProAssembly pTopAsm,											// 总组件(in)
		const CString &strTemplateName,									// 模型名称(in)
		const CString &strCompCsysName,									// 元件装配坐标(in)
		const ModelConfiguration &mdlConfig								// 模型配置(in)
		);
	// 查找组件配置项
	int FindModelConfig(
		int nModelType,													// 模型类型(in)
		double dSymbolWidth,											// 符号的宽度(in)
		double dSymbolHeight,											// 符号的高度(in)
		const ModelConfigurationArray &arrMdlConfig						// 组件配置集(in)
		);
	// 根据符号中心位置和旋转角度，计算装配位置
	bool GetModelPosition(
		double dLayoutLeft,												// 布局图的左上角X(in)
		double dLayoutTop,												// 布局图的左上角Y(in)
		double dLayoutWidth,											// 布局图的宽度(in)
		double dLayoutHeight,											// 布局图的高度(in)
		double dSymbolWidth,											// 符号的宽度(in)
		double dSymbolHeight,											// 符号的高度(in)
		double dCenterX,												// 符号中心X(in)
		double dCenterY,												// 符号中心Y(in)
		double dAngle,													// 符号顺时针旋转角度(in)
		IKSCsysData &position											// 模型装配位置(out)
		);
	// 获取临时图号
	CString GetTempPartNo(
		const CString &strTemplateName									// 模板文件名
		);
	// 获取模板文件名
	CString GetTemplateNameByModelType(
		int nModelType													// 组件类型
		);
	// 获取装配坐标名名
	CString GetCompCsysNameByModelType(
		int nModelType													// 组件类型
		);

	// 测试生成模型
	bool TestBuildModel();
	// 根据XML文件生成模型
	bool TestBuildModelByXML(const CString &strXMLPath);
	// 根据订单需求采集表和整机布局图XML文件生成整机配置模型
	bool TestBuildModelByReqTableAndLayoutFile(const CString &strXMLPath);
};

//===================================================================================================
