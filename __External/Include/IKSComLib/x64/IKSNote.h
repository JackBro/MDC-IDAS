//===================================================================================================
// Summary:
//		标注注释定义
// Date:
//		2015-08-01			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSNote_h__
#define __IKSNote_h__

//===================================================================================================

#define IKS_TEXT_SIZE      256

//===================================================================================================

// 二维注释数据信息
typedef struct __tagIKSNote
{
	int nID;						// 二维注释ID
	wchar_t wText[IKS_TEXT_SIZE];	// 二维注释文本
	double dpPosition[3];			// 注释位置
	IKSTextStyle textStyle;			// 文本样式

	__tagIKSNote() 
	{
		nID = -1;
		memset(wText, 0, sizeof(wchar_t)*IKS_TEXT_SIZE);
		memset(dpPosition, 0, sizeof(double)*3);
	}
	__tagIKSNote(const __tagIKSNote &data)
	{
		nID = data.nID;
		wcsncpy_s(wText, IKS_TEXT_SIZE, data.wText, IKS_TEXT_SIZE);
		memcpy_s(dpPosition, sizeof(double)*3, data.dpPosition, sizeof(double)*3);
		textStyle = data.textStyle;
	}
	__tagIKSNote& operator=(const __tagIKSNote &data) 
	{
		if (this == &data)
			return *this;
		nID = data.nID;
		wcsncpy_s(wText, IKS_TEXT_SIZE, data.wText, IKS_TEXT_SIZE);
		memcpy_s(dpPosition, sizeof(double)*3, data.dpPosition, sizeof(double)*3);
		textStyle = data.textStyle;
		return *this;
	}
} IKSNote;

typedef vector<IKSNote> IKSNoteArray;

// 获取新的注释的ID
int IKSGetNewNoteID();

// 获取注释的宽度回调函数
typedef BOOL (*IKSGetNoteSizeAction)(const IKSNote &note, double &dNoteWidth, double &dNoteHeight);

// 获取注释默认的宽度
BOOL IKSGetNoteSizeDefault(const IKSNote &note, double &dNoteWidth, double &dNoteHeight);

//===================================================================================================

#endif