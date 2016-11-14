//===================================================================================================
// Summary:
//		�ڲ�ʹ�ú�Ķ���
// Date:
//		2011-08-09
// Author:
//		Liuguoqing(gliu@bplead.com)
//===================================================================================================

#ifndef	__BaseMacro_h__
#define __BaseMacro_h__

//===================================================================================================

#define WM_FILEDW_PROGRESS			WM_USER + 1500
#define WM_FILEDW_ONEDONE			WM_USER + 1501
#define WM_FILEDW_ALLDONE			WM_USER + 1502
#define WM_FILEDW_ERRREPORT			WM_USER + 1503

#define WM_NETCOMM_DONE				WM_USER + 1600
#define WM_NETCOMM_ERRREPORT		WM_USER + 1601

//===================================================================================================

// ɾ��ָ��
#define SAFE_DELETE_POINTER(p) \
{ \
	if (NULL != p) \
	delete p; \
	p = NULL; \
}

// ɾ������
#define SAFE_DELETE_ARRAY(p) \
{ \
	if (NULL != p) \
	delete[] p; \
	p = NULL; \
}

// ɾ����Դ���
#define SAFE_CLOSE_HANDLE(handle)	\
{ \
	if (handle)	\
	::CloseHandle(handle); \
	handle = NULL; \
}

// ɾ��ѡ�����
#define SAFE_DELETE_SELECTION(p) \
{ \
	if (NULL != p) \
	ProSelectionFree(&p); \
	p = NULL; \
}

// ɾ��ѡ�����
#define SAFE_DELETE_PROARRAY(p) \
{ \
	if (NULL != p) \
	ProArrayFree((ProArray*)&p); \
	p = NULL; \
}

//===================================================================================================

#endif