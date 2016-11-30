//===================================================================================================
// Summary:
//		参数相关函数集
// Date:
//		2015-07-02			创建
// Author:
//		Liuguoqing(bjliugq@qq.com)
//===================================================================================================

#ifndef __PCLParameter_h__
#define __PCLParameter_h__

//===================================================================================================

// 引用ProE头文件
#include <ProParameter.h>

//===================================================================================================

typedef struct __tagParameterData
{
	CString strParaName;						// 参数名
	CString strDispName;						// 显示名
	CString strValue;							// 参数值
	CString strRemark;							// 备注
	CString strParaType;						// 参数类型

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

	// 获取模型的主参数
	static BOOL GetMdlMainParameters(
		ProMdl pMdl,											// 模型(in)
		vector<ParameterData> &arrParameters					// 属性参数(out)
		);

	// 得到Pro/E的参数名
	static BOOL GetParaName(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		BOOL bAddID,											// 
		ProName szParaName										// 参数名称
		);

	// 获得模型的参数
	static BOOL GetParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		ProName szParaName,										// 参数名称(in)
		ProParameter &para										// 参数(out)
		);

	// 获得模型的参数
	static BOOL GetParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		ProParameter &para,										// 参数(out)
		BOOL bAddID = FALSE										// (in)
		);

	// 获得模型的参数值
	static BOOL GetParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		ProBoolean &bValue,										// 参数值(out)
		BOOL bAddID = FALSE										// (in)
		);

	// 获得模型的参数值
	static BOOL GetParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		CString &strValue,										// 参数值(out)
		BOOL bAddID = TRUE										// (in)
		);

	// 获得模型的参数值
	static BOOL GetParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		int &nValue,											// 参数值(out)
		BOOL bAddID = FALSE										// (in)
		);
	
	// 获得模型的参数值
	static BOOL GetParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		double &dValue,											// 参数值(out)
		BOOL bAddID = FALSE										// (in)
		);

	// 获得模型的长字符串参数值
	static BOOL GetLongStringParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		CString &strValue,										// 参数值(out)
		BOOL bAddID = FALSE										// (in)
		);
	
	// 设置模型的参数值
	static BOOL SetParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		const ProBoolean &bValue,								// 参数值(in)
		BOOL bAddID = FALSE,									// (in)
		wchar_t *strDescription = NULL,							// (in)
		BOOL bDesignation = FALSE								// (in)
		);

	// 设置模型的参数值
	static BOOL SetParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		const CString &strValue,								// 参数值(in)
		BOOL bAddID = FALSE,									// (in)
		wchar_t *strDescription = NULL,							// (in)
		BOOL bDesignation = FALSE								// (in)
		);

	// 设置模型的参数值
	static BOOL SetParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		int nValue,												// 参数值(in)
		BOOL bAddID = FALSE,									// (in)
		wchar_t *strDescription = NULL,							// (in)
		BOOL bDesignation = FALSE								// (in)
		);

	// 设置模型的参数值
	static BOOL SetParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		double dValue,											// 参数值(in)
		BOOL bAddID = FALSE,									// (in)
		wchar_t *strDescription = NULL,							// (in)
		BOOL bDesignation = FALSE								// (in)
		);

	// 设置模型的长字符串参数值
	static BOOL SetLongStringParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		const CString &strValue,								// 参数值(in)
		BOOL bAddID = FALSE,									// (in)
		wchar_t *strDescription = NULL,							// (in)
		BOOL bDesignation = FALSE								// (in)
		);

	// 删除模型参数
	static BOOL DeleteParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		BOOL bAddID = FALSE										// (in)
		);


	// 删除模型参数
	static BOOL DeleteLongStringParameter(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strName,									// 参数名称(in)
		BOOL bAddID = FALSE										// (in)
		);

	
	// 获得布尔类型参数值
	static BOOL Get(
		ProModelitem *pMdlItem,									// 模型项目(in)
		const CString &strParaName,								// 参数名称(in)
		ProBoolean &bValue										// 布尔值(out)
		);

	// 设置布尔类型参数值
	static BOOL Set(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const ProBoolean &bValue		// 布尔值(in)
		);

	// 创建布尔类型参数
	static BOOL Create(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const ProBoolean &bValue,		// 布尔值(in)
		ProParameter &proPara			// 参数数据(out)
		);

	// 获得字符串类型参数值
	static BOOL Get(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		CString &strValue				// 字符串值(out)
		);

	// 设置字符串类型参数值
	static BOOL Set(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const CString &strValue			// 字符串值(in)
		);

	// 创建字符串类型参数
	static BOOL Create(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const CString &strValue,		// 字符串值(in)
		ProParameter &proPara			// 参数数据(out)
		);

	// 获得整型参数值
	static BOOL Get(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		int &nValue						// 整数值(out)
		);

	// 设置整型参数值
	static BOOL Set(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const int &nValue				// 整数值(in)
		);

	// 创建整型参数
	static BOOL Create(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const int &nValue,				// 整数值(in)
		ProParameter &proPara			// 参数数据(out)
		);

	// 获得实数型参数值
	static BOOL Get(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		double &dValue					// 实数值(out)
		);

	// 设置实数型参数值
	static BOOL Set(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const double &dValue			// 实数值(in)
		);

	// 创建实数型参数
	static BOOL Create(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const double &dValue,			// 实数值(in)
		ProParameter &proPara			// 参数数据(out)
		);

	// 获得布尔类型参数值，参数名增加项目ID
	static BOOL GetWithID(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		ProBoolean &bValue				// 布尔值(out)
		);

	// 设置布尔类型参数值，参数名增加项目ID
	static BOOL SetWithID(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const ProBoolean &bValue		// 布尔值(in)
		);

	// 创建布尔类型参数，参数名增加项目ID
	static BOOL CreateWithID(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const ProBoolean &bValue,		// 布尔值(in)
		ProParameter &proPara			// 参数数据(out)
		);

	// 获得字符串类型参数值，参数名增加项目ID
	static BOOL GetWithID(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		CString &strValue				// 字符串值(out)
		);

	// 设置字符串类型参数值，参数名增加项目ID
	static BOOL SetWithID(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const CString &strValue			// 字符串值(in)
		);

	// 创建字符串类型参数，参数名增加项目ID
	static BOOL CreateWithID(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const CString &strValue,		// 字符串值(in)
		ProParameter &proPara			// 参数数据(out)
		);

	// 获得整型参数值，参数名增加项目ID
	static BOOL GetWithID(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		int &nValue						// 整数值(out)
		);

	// 设置整型参数值，参数名增加项目ID
	static BOOL SetWithID(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const int &nValue				// 整数值(in)
		);

	// 创建整型参数，参数名增加项目ID
	static BOOL CreateWithID(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const int &nValue,				// 整数值(in)
		ProParameter &proPara			// 参数数据(out)
		);

	// 获得实数型参数值，参数名增加项目ID
	static BOOL GetWithID(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		double &dValue					// 实数值(out)
		);

	// 设置实数型参数值，参数名增加项目ID
	static BOOL SetWithID(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const double &dValue			// 实数值(in)
		);

	// 创建实数型参数，参数名增加项目ID
	static BOOL CreateWithID(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const double &dValue,			// 实数值(in)
		ProParameter &proPara			// 参数数据(out)
		);

	// 判断项目的参数名和参数值是否合理，即该项目存在参数且参数值等于输入参数值
	static BOOL IsValid(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		const CString &strParaValue,	// 参数值
		BOOL bAddItemID					// 参数名是否增加项目ID(in)
		);

private:

	// 获取模型主参数数组的遍历函数
	static ProError GetMdlParameterArrayVisit(ProParameter *pPara, ProError status, ProAppData pData);


	// 得到实际参数名
	static CString GetRealParaName(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		BOOL bAddItemID					// 参数名是否增加项目ID(in)
		);

	// 获得参数
	static BOOL GetProParameter(
		ProModelitem *pMdlItem,			// 模型项目(in)
		const CString &strParaName,		// 参数名称(in)
		BOOL bAddItemID,				// 参数名是否增加项目ID(in)
		ProParameter &para				// 参数数据(out)
		);
};

#endif

