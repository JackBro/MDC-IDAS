//===================================================================================================
// Summary:
//		菜单相关函数集
// Date:
//		2015-07-16			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __PCLMenu_h__
#define __PCLMenu_h__

//===================================================================================================

// 引用ProE头文件
#include <ProMenu.h>
#include <ProMenuBar.h>
#include <ProPopupmenu.h>
#include <ProUICmd.h>

//===================================================================================================

namespace PCLMenu
{
	// 菜单响应函数
	typedef void (*MenuActionFunc)();

	// 菜单访问状态函数，判断菜单是否可用
	typedef uiCmdAccessState (*MenuAccessFunc)(uiCmdAccessMode eAccessMode);

	// 默认访问状态函数
	uiCmdAccessState DefaultAccess(uiCmdAccessMode eAccessMode);

	// 菜单访问状态函数：该菜单项仅组件下可用，其他情况下置灰
	uiCmdAccessState AssemblyAccess(uiCmdAccessMode eAccessMode);

	// 菜单访问状态函数：该菜单项仅零件下可用，其他情况下置灰
	uiCmdAccessState PartAccess(uiCmdAccessMode eAccessMode);

	// 菜单访问状态函数：该菜单项仅工程图下可用，其他情况下置灰
	uiCmdAccessState DrawingAccess(uiCmdAccessMode eAccessMode);

	// 添加菜单项
	void AddMenuItem(
		ProMenuItemName szMenuName,				// 菜单名称(in)
		ProMenuItemName szItemName,				// 菜单项名称(in)
		MenuActionFunc menuitemAction,			// 菜单响应函数(in)
		MenuAccessFunc menuitemAccess,			// 菜单访问状态函数(in)
		ProFileName msgFile,					// 菜单文本信息文件(in)
		ProMenuItemIcon szIconName				// 图标名称(in)
		);
}

#endif

