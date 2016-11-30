//===================================================================================================
// Summary:
//		�˵���غ�����
// Date:
//		2015-07-16			����
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __PCLMenu_h__
#define __PCLMenu_h__

//===================================================================================================

// ����ProEͷ�ļ�
#include <ProMenu.h>
#include <ProMenuBar.h>
#include <ProPopupmenu.h>
#include <ProUICmd.h>

//===================================================================================================

namespace PCLMenu
{
	// �˵���Ӧ����
	typedef void (*MenuActionFunc)();

	// �˵�����״̬�������жϲ˵��Ƿ����
	typedef uiCmdAccessState (*MenuAccessFunc)(uiCmdAccessMode eAccessMode);

	// Ĭ�Ϸ���״̬����
	uiCmdAccessState DefaultAccess(uiCmdAccessMode eAccessMode);

	// �˵�����״̬�������ò˵��������¿��ã�����������û�
	uiCmdAccessState AssemblyAccess(uiCmdAccessMode eAccessMode);

	// �˵�����״̬�������ò˵��������¿��ã�����������û�
	uiCmdAccessState PartAccess(uiCmdAccessMode eAccessMode);

	// �˵�����״̬�������ò˵��������ͼ�¿��ã�����������û�
	uiCmdAccessState DrawingAccess(uiCmdAccessMode eAccessMode);

	// ��Ӳ˵���
	void AddMenuItem(
		ProMenuItemName szMenuName,				// �˵�����(in)
		ProMenuItemName szItemName,				// �˵�������(in)
		MenuActionFunc menuitemAction,			// �˵���Ӧ����(in)
		MenuAccessFunc menuitemAccess,			// �˵�����״̬����(in)
		ProFileName msgFile,					// �˵��ı���Ϣ�ļ�(in)
		ProMenuItemIcon szIconName				// ͼ������(in)
		);
}

#endif

