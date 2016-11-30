//===================================================================================================
// Summary:
//		�ڲ�ʹ�ú�Ķ���
// Date:
//		2011-08-09
// Author:
//		WangShiping
//===================================================================================================

#ifndef	__CableBaseMacro_h__
#define __CableBaseMacro_h__

//===================================================================================================

// ɾ��ָ��
#ifndef SAFE_DELETE_POINTER
#define SAFE_DELETE_POINTER(p) \
{ \
	if (NULL != p) \
	delete p; \
	p = NULL; \
}
#endif

// ɾ������
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) \
{ \
	if (NULL != p) \
	delete[] p; \
	p = NULL; \
}
#endif

// ɾ����Դ���
#ifndef SAFE_CLOSE_HANDLE
#define SAFE_CLOSE_HANDLE(handle)	\
{ \
	if (handle)	\
	::CloseHandle(handle); \
	handle = NULL; \
}
#endif

// ɾ��ѡ�����
#ifndef SAFE_DELETE_SELECTION
#define SAFE_DELETE_SELECTION(p) \
{ \
	if (NULL != p) \
	ProSelectionFree(&p); \
	p = NULL; \
}
#endif

// ɾ��ѡ�����
#ifndef SAFE_DELETE_PROARRAY
#define SAFE_DELETE_PROARRAY(p) \
{ \
	if (NULL != p) \
	ProArrayFree((ProArray*)&p); \
	p = NULL; \
}
#endif

//===================================================================================================

#endif