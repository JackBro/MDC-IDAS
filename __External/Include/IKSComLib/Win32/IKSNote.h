//===================================================================================================
// Summary:
//		��עע�Ͷ���
// Date:
//		2015-08-01			����
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __IKSNote_h__
#define __IKSNote_h__

//===================================================================================================

#define IKS_TEXT_SIZE      256

//===================================================================================================

// ��άע��������Ϣ
typedef struct __tagIKSNote
{
	int nID;						// ��άע��ID
	wchar_t wText[IKS_TEXT_SIZE];	// ��άע���ı�
	double dpPosition[3];			// ע��λ��
	IKSTextStyle textStyle;			// �ı���ʽ

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

// ��ȡ�µ�ע�͵�ID
int IKSGetNewNoteID();

// ��ȡע�͵Ŀ�Ȼص�����
typedef BOOL (*IKSGetNoteSizeAction)(const IKSNote &note, double &dNoteWidth, double &dNoteHeight);

// ��ȡע��Ĭ�ϵĿ��
BOOL IKSGetNoteSizeDefault(const IKSNote &note, double &dNoteWidth, double &dNoteHeight);

//===================================================================================================

#endif