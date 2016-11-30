//===================================================================================================
// Summary:
//		������غ�����
// Date:
//		2015-07-02			����
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __PCLParameter_h__
#define __PCLParameter_h__

//===================================================================================================

// ����ProEͷ�ļ�
#include <ProParameter.h>

//===================================================================================================

typedef struct __tagParameterData
{
	CString strParaName;						// ������
	CString strDispName;						// ��ʾ��
	CString strValue;							// ����ֵ
	CString strRemark;							// ��ע
	CString strParaType;						// ��������

	__tagParameterData()
	{
	}
	__tagParameterData(const __tagParameterData &data)
	{
		strParaName = data.strParaName;
		strDispName = data.strDispName;
		strValue = data.strValue;
		strRemark = data.strRemark;
		strParaType = data.strParaType;
	}
	__tagParameterData &operator=(const __tagParameterData& data){
		if (&data != this)
		{
			strParaName = data.strParaName;
			strDispName = data.strDispName;
			strValue = data.strValue;
			strRemark = data.strRemark;
			strParaType = data.strParaType;
		}
		return *this;
	}
} ParameterData;

//===================================================================================================

class CPCLParameter
{
public:

	// ��ȡģ�͵�������
	static BOOL GetMdlMainParameters(
		ProMdl pMdl,											// ģ��(in)
		vector<ParameterData> &arrParameters					// ���Բ���(out)
		);

	// �õ�Pro/E�Ĳ�����
	static BOOL GetParaName(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		BOOL bAddID,											// 
		ProName szParaName										// ��������
		);

	// ���ģ�͵Ĳ���
	static BOOL GetParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		ProName szParaName,										// ��������(in)
		ProParameter &para										// ����(out)
		);

	// ���ģ�͵Ĳ���
	static BOOL GetParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		ProParameter &para,										// ����(out)
		BOOL bAddID = FALSE										// (in)
		);

	// ���ģ�͵Ĳ���ֵ
	static BOOL GetParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		ProBoolean &bValue,										// ����ֵ(out)
		BOOL bAddID = FALSE										// (in)
		);

	// ���ģ�͵Ĳ���ֵ
	static BOOL GetParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		CString &strValue,										// ����ֵ(out)
		BOOL bAddID = TRUE										// (in)
		);

	// ���ģ�͵Ĳ���ֵ
	static BOOL GetParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		int &nValue,											// ����ֵ(out)
		BOOL bAddID = FALSE										// (in)
		);
	
	// ���ģ�͵Ĳ���ֵ
	static BOOL GetParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		double &dValue,											// ����ֵ(out)
		BOOL bAddID = FALSE										// (in)
		);

	// ���ģ�͵ĳ��ַ�������ֵ
	static BOOL GetLongStringParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		CString &strValue,										// ����ֵ(out)
		BOOL bAddID = FALSE										// (in)
		);
	
	// ����ģ�͵Ĳ���ֵ
	static BOOL SetParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		const ProBoolean &bValue,								// ����ֵ(in)
		BOOL bAddID = FALSE,									// (in)
		wchar_t *strDescription = NULL,							// (in)
		BOOL bDesignation = FALSE								// (in)
		);

	// ����ģ�͵Ĳ���ֵ
	static BOOL SetParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		const CString &strValue,								// ����ֵ(in)
		BOOL bAddID = FALSE,									// (in)
		wchar_t *strDescription = NULL,							// (in)
		BOOL bDesignation = FALSE								// (in)
		);

	// ����ģ�͵Ĳ���ֵ
	static BOOL SetParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		int nValue,												// ����ֵ(in)
		BOOL bAddID = FALSE,									// (in)
		wchar_t *strDescription = NULL,							// (in)
		BOOL bDesignation = FALSE								// (in)
		);

	// ����ģ�͵Ĳ���ֵ
	static BOOL SetParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		double dValue,											// ����ֵ(in)
		BOOL bAddID = FALSE,									// (in)
		wchar_t *strDescription = NULL,							// (in)
		BOOL bDesignation = FALSE								// (in)
		);

	// ����ģ�͵ĳ��ַ�������ֵ
	static BOOL SetLongStringParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		const CString &strValue,								// ����ֵ(in)
		BOOL bAddID = FALSE,									// (in)
		wchar_t *strDescription = NULL,							// (in)
		BOOL bDesignation = FALSE								// (in)
		);

	// ɾ��ģ�Ͳ���
	static BOOL DeleteParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		BOOL bAddID = FALSE										// (in)
		);


	// ɾ��ģ�Ͳ���
	static BOOL DeleteLongStringParameter(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strName,									// ��������(in)
		BOOL bAddID = FALSE										// (in)
		);

	
	// ��ò������Ͳ���ֵ
	static BOOL Get(
		ProModelitem *pMdlItem,									// ģ����Ŀ(in)
		const CString &strParaName,								// ��������(in)
		ProBoolean &bValue										// ����ֵ(out)
		);

	// ���ò������Ͳ���ֵ
	static BOOL Set(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const ProBoolean &bValue		// ����ֵ(in)
		);

	// �����������Ͳ���
	static BOOL Create(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const ProBoolean &bValue,		// ����ֵ(in)
		ProParameter &proPara			// ��������(out)
		);

	// ����ַ������Ͳ���ֵ
	static BOOL Get(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		CString &strValue				// �ַ���ֵ(out)
		);

	// �����ַ������Ͳ���ֵ
	static BOOL Set(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const CString &strValue			// �ַ���ֵ(in)
		);

	// �����ַ������Ͳ���
	static BOOL Create(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const CString &strValue,		// �ַ���ֵ(in)
		ProParameter &proPara			// ��������(out)
		);

	// ������Ͳ���ֵ
	static BOOL Get(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		int &nValue						// ����ֵ(out)
		);

	// �������Ͳ���ֵ
	static BOOL Set(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const int &nValue				// ����ֵ(in)
		);

	// �������Ͳ���
	static BOOL Create(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const int &nValue,				// ����ֵ(in)
		ProParameter &proPara			// ��������(out)
		);

	// ���ʵ���Ͳ���ֵ
	static BOOL Get(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		double &dValue					// ʵ��ֵ(out)
		);

	// ����ʵ���Ͳ���ֵ
	static BOOL Set(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const double &dValue			// ʵ��ֵ(in)
		);

	// ����ʵ���Ͳ���
	static BOOL Create(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const double &dValue,			// ʵ��ֵ(in)
		ProParameter &proPara			// ��������(out)
		);

	// ��ò������Ͳ���ֵ��������������ĿID
	static BOOL GetWithID(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		ProBoolean &bValue				// ����ֵ(out)
		);

	// ���ò������Ͳ���ֵ��������������ĿID
	static BOOL SetWithID(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const ProBoolean &bValue		// ����ֵ(in)
		);

	// �����������Ͳ�����������������ĿID
	static BOOL CreateWithID(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const ProBoolean &bValue,		// ����ֵ(in)
		ProParameter &proPara			// ��������(out)
		);

	// ����ַ������Ͳ���ֵ��������������ĿID
	static BOOL GetWithID(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		CString &strValue				// �ַ���ֵ(out)
		);

	// �����ַ������Ͳ���ֵ��������������ĿID
	static BOOL SetWithID(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const CString &strValue			// �ַ���ֵ(in)
		);

	// �����ַ������Ͳ�����������������ĿID
	static BOOL CreateWithID(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const CString &strValue,		// �ַ���ֵ(in)
		ProParameter &proPara			// ��������(out)
		);

	// ������Ͳ���ֵ��������������ĿID
	static BOOL GetWithID(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		int &nValue						// ����ֵ(out)
		);

	// �������Ͳ���ֵ��������������ĿID
	static BOOL SetWithID(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const int &nValue				// ����ֵ(in)
		);

	// �������Ͳ�����������������ĿID
	static BOOL CreateWithID(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const int &nValue,				// ����ֵ(in)
		ProParameter &proPara			// ��������(out)
		);

	// ���ʵ���Ͳ���ֵ��������������ĿID
	static BOOL GetWithID(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		double &dValue					// ʵ��ֵ(out)
		);

	// ����ʵ���Ͳ���ֵ��������������ĿID
	static BOOL SetWithID(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const double &dValue			// ʵ��ֵ(in)
		);

	// ����ʵ���Ͳ�����������������ĿID
	static BOOL CreateWithID(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const double &dValue,			// ʵ��ֵ(in)
		ProParameter &proPara			// ��������(out)
		);

	// �ж���Ŀ�Ĳ������Ͳ���ֵ�Ƿ����������Ŀ���ڲ����Ҳ���ֵ�����������ֵ
	static BOOL IsValid(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		const CString &strParaValue,	// ����ֵ
		BOOL bAddItemID					// �������Ƿ�������ĿID(in)
		);

private:

	// ��ȡģ������������ı�������
	static ProError GetMdlParameterArrayVisit(ProParameter *pPara, ProError status, ProAppData pData);


	// �õ�ʵ�ʲ�����
	static CString GetRealParaName(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		BOOL bAddItemID					// �������Ƿ�������ĿID(in)
		);

	// ��ò���
	static BOOL GetProParameter(
		ProModelitem *pMdlItem,			// ģ����Ŀ(in)
		const CString &strParaName,		// ��������(in)
		BOOL bAddItemID,				// �������Ƿ�������ĿID(in)
		ProParameter &para				// ��������(out)
		);
};

#endif

