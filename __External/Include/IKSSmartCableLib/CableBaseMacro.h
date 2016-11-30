//===================================================================================================
// Summary:
//		内部使用宏的定义
// Date:
//		2011-08-09
// Author:
//		WangShiping
//===================================================================================================

#ifndef	__CableBaseMacro_h__
#define __CableBaseMacro_h__

//===================================================================================================

// 删除指针
#ifndef SAFE_DELETE_POINTER
#define SAFE_DELETE_POINTER(p) \
{ \
	if (NULL != p) \
	delete p; \
	p = NULL; \
}
#endif

// 删除数组
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) \
{ \
	if (NULL != p) \
	delete[] p; \
	p = NULL; \
}
#endif

// 删除资源句柄
#ifndef SAFE_CLOSE_HANDLE
#define SAFE_CLOSE_HANDLE(handle)	\
{ \
	if (handle)	\
	::CloseHandle(handle); \
	handle = NULL; \
}
#endif

// 删除选择对象
#ifndef SAFE_DELETE_SELECTION
#define SAFE_DELETE_SELECTION(p) \
{ \
	if (NULL != p) \
	ProSelectionFree(&p); \
	p = NULL; \
}
#endif

// 删除选择对象
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