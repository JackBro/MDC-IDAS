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
// 常量定义
const CString g_strCompCsysName = _T("CS_安装");		// 元件安装坐标系名称

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
		const IKSCsysData &asmPosition									// 装配位置(in)
		);
	// 装配服务器机柜模型
	bool AssembleModel_IT(
		ProAssembly pTopAsm,											// 总组件
		const ModelConfiguration &mdlConfig								// 模型配置
		);
	// 测试生成模型
	bool TestBuildModel();
};

//===================================================================================================
