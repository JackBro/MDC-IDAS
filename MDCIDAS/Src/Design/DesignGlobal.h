//===================================================================================================
// Summary:
//		整机配置模块使用的公用函数
// Date:
//		2016-12-01
// Author:
//		lgq
//===================================================================================================

#pragma once

//===================================================================================================

// 全局变量定义

// 机柜模板参数_宽
extern CString g_strITParaWidthName;
// 机柜模板参数_深
extern CString g_strITParaDepthName;
// 机柜模板参数_高
extern CString g_strITParaHeightName;

// 服务器机柜装配坐标
extern CString g_strFWQJGCompCsysName;
// 管控柜装配坐标
extern CString g_strGKGCompCsysName;
// 空调柜装配坐标
extern CString g_strKTGCompCsysName;
// 消防柜装配坐标
extern CString g_strXFGCompCsysName;
// 导风柜装配坐标
extern CString g_strDFGCompCsysName;
// 行间空柜装配坐标
extern CString g_strHJKGCompCsysName;
// 走线架装配坐标
extern CString g_strZXJCompCsysName;
// 光纤槽装配坐标
extern CString g_strGXCCompCsysName;
// 固定顶窗装配坐标
extern CString g_strGDDCCompCsysName;
// 翻转顶窗装配坐标
extern CString g_strFZDCCompCsysName;
// 可调顶窗装配坐标
extern CString g_strKTDCCompCsysName;
// 走下架支架装配坐标
extern CString g_strZXJZJCompCsysName;
// 通道平门装配坐标
extern CString g_strTDPMCompCsysName;
// 通道凸门装配坐标
extern CString g_strTDTMCompCsysName;
// 围板装配坐标
extern CString g_strZJWBCompCsysName;
// 走线架转接板装配坐标
extern CString g_strZXJZJBCompCsysName;
// 凸门立柱装配坐标
extern CString g_strTMLZCompCsysName;
// 连接支架装配坐标
extern CString g_strLJZJCompCsysName;
// 踏步装配坐标
extern CString g_strTBZJCompCsysName;
// 机柜侧门装配坐标
extern CString g_strJGCMCompCsysName;
// 边底座装配坐标
extern CString g_strBDZCompCsysName;
// 底座挡板装配坐标
extern CString g_strDZDBCompCsysName;
// 底座托板装配坐标
extern CString g_strDZTBCompCsysName;
// 底座横梁装配坐标
extern CString g_strDZHLCompCsysName;
// 底座装配坐标
extern CString g_strDZCompCsysName;
// 配电柜装配坐标
extern CString g_strPDGCompCsysName;
// 假墙框架装配坐标
extern CString g_strJQKJCompCsysName;
// 假墙底座装配坐标
extern CString g_strJQDZCompCsysName;
// 左框架装配坐标
extern CString g_strZKJCompCsysName;
// 右框架装配坐标
extern CString g_strYKJCompCsysName;
// 框架底座装配坐标
extern CString g_strKJDZCompCsysName;
// 框架装配坐标
extern CString g_strKJCompCsysName;

// 服务器机柜模板组件名称
extern CString g_strFWQJGTemplateAsmName;
// 管控柜模板组件名称
extern CString g_strGKGTemplateAsmName;
// 空调柜模板组件名称
extern CString g_strKTGTemplateAsmName;
// 消防柜模板组件名称
extern CString g_strXFGTemplateAsmName;
// 导风柜模板组件名称
extern CString g_strDFGTemplateAsmName;
// 行间空柜模板组件名称
extern CString g_strHJKGTemplateAsmName;
// 走线架模板组件名称
extern CString g_strZXJTemplateAsmName;
// 光纤槽模板组件名称
extern CString g_strGXCTemplateAsmName;
// 固定顶窗模板组件名称
extern CString g_strGDDCTemplateAsmName;
// 翻转顶窗模板组件名称
extern CString g_strFZDCTemplateAsmName;
// 可调顶窗模板组件名称
extern CString g_strKTDCTemplateAsmName;
// 走下架支架模板组件名称
extern CString g_strZXJZJTemplateAsmName;
// 通道平门模板组件名称
extern CString g_strTDPMTemplateAsmName;
// 通道凸门模板组件名称
extern CString g_strTDTMTemplateAsmName;
// 围板模板组件名称
extern CString g_strZJWBTemplateAsmName;
// 走线架转接板模板组件名称
extern CString g_strZXJZJBTemplateAsmName;
// 凸门立柱模板组件名称
extern CString g_strTMLZTemplateAsmName;
// 连接支架模板组件名称
extern CString g_strLJZJTemplateAsmName;
// 踏步模板组件名称
extern CString g_strTBZJTemplateAsmName;
// 机柜侧门模板组件名称
extern CString g_strJGCMTemplateAsmName;
// 边底座模板组件名称
extern CString g_strBDZTemplateAsmName;
// 底座挡板模板组件名称
extern CString g_strDZDBTemplateAsmName;
// 底座托板模板组件名称
extern CString g_strDZTBTemplateAsmName;
// 底座横梁模板组件名称
extern CString g_strDZHLTemplateAsmName;
// 底座模板组件名称
extern CString g_strDZTemplateAsmName;
// 配电柜模板组件名称
extern CString g_strPDGTemplateAsmName;
// 假墙框架模板组件名称
extern CString g_strJQKJTemplateAsmName;
// 假墙底座模板组件名称
extern CString g_strJQDZTemplateAsmName;
// 左框架模板组件名称
extern CString g_strZKJTemplateAsmName;
// 右框架模板组件名称
extern CString g_strYKJTemplateAsmName;
// 框架底座模板组件名称
extern CString g_strKJDZTemplateAsmName;
// 框架模板组件名称
extern CString g_strKJTemplateAsmName;

//===================================================================================================

// 根据布局图符号类型获取设计用组件类型
int GetDesignModelType(int nSymbolSubtype);
// 初始化全局变量
bool InitDesignGlobalData();

//===================================================================================================

