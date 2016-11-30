//===================================================================================================
// File:
//		ExcelOperatorAPI.h
// Summary:
//		office文档操作接口类（excel）
// Date:
//		2016-02-19
// Author:
//		WangShiping
//===================================================================================================

#pragma once

//===================================================================================================

class IExcelOperator
{
public:
	// 后台启动EXCEL应用程序
	virtual BOOL CreateApp() = 0;

	// 退出程序
	virtual BOOL QuitApp() = 0;

	// 前台显示EXCEL应用程序
	virtual void ShowApp() = 0;

	// 打开文档
	virtual BOOL OpenXls(const CString& strName) = 0;

	// 关闭文档
	virtual BOOL CloseXls() = 0;

	// 创建一个空白文档
	virtual BOOL CreateXls() = 0;

	// 保存文档
	virtual BOOL SaveXls() = 0;

	// 文档另存为
	virtual BOOL SaveAs(const CString &strFname) = 0;
	virtual BOOL SaveAs2003(const CString &strFname) = 0;

	// 向单元格写入值
	virtual BOOL SetCellValue(long nRow, long nCol, const CString& strVal) = 0;

	// 读取单元格的值
	virtual BOOL GetCellValue(long nRow, long nCol, CString& strVal) = 0;

	// 设置单元格水平对齐方式(nType:1代表居中,2代表靠左,3代表靠右)
	virtual BOOL SetCellHorizontalAlignment(long nRow, long nCol, int nType) = 0;

	// 设置单元格水平对齐方式(nType:1代表居中,2代表靠上,3代表靠下)
	virtual BOOL SetCellVerticalAlignment(long nRow, long nCol, int nType) = 0;

	// 查找
	virtual BOOL FindCell(long &nRow, long &nCol, const CString& strVal, BOOL bMatchCell=TRUE) = 0;

	// 合并单元格
	virtual BOOL MergeCell(long nStartRow, long nStartCol, long nRowSize, long nColSize) = 0;
	// 取消合并单元格
	virtual BOOL UnMergeCell(long nRow, long nCol) = 0;
	// 获取单元格的合并信息
	virtual BOOL GetMergeInf(long nRow, long nCol, BOOL *pIsMerged=NULL, long *pStartRow=NULL, long *pStartCol=NULL, long *pRowSize=NULL, long *pColSize=NULL) = 0;

	// 设置冻结首列
	virtual BOOL SetFirstColumnFixed(BOOL bFixed) = 0;

	// 设置冻结首行
	virtual BOOL SetFirstRowFixed(BOOL bFixed) = 0;

	// 设置同时冻结首行及首列
	virtual BOOL SetRowAndColumnFixed(BOOL bFixed) = 0;

	// 获得总行数(0)或总列数(1)
	virtual int GetCount(BOOL bIsColumnOrRow) = 0;

	// 获得已使用单元区域的信息
	virtual BOOL GetUsedRangeInf(long *pFirstRow=NULL, long *pFirstCol=NULL, long *pRowCount=NULL, long *pColCount=NULL) = 0;

	// 设置指定列宽度自适应内容
	virtual BOOL SetColumnAutoFit(long nCol) = 0;

	// 插入一行
	virtual BOOL InsertRow(long nRow) = 0;
	// 插入一列
	virtual BOOL InsertColumn(long nCol) = 0;

	// 删除一行
	virtual BOOL DeleteRow(long nRow) = 0;
	// 删除一列
	virtual BOOL DeleteColumn(long nCol) = 0;

	// 清除行内容
	virtual BOOL ClearRowContents(long nFirstRow, long nRowCount=1) = 0;

	// 设定单元格背景色
	virtual BOOL SetCellBkColor(long nRow, long nCol, COLORREF color) = 0;

	// 设定某一列的背景色
	virtual BOOL SetColumnBkColor(long nCol, COLORREF color) = 0;

	// 设定某一行的背景色
	virtual BOOL SetRowBkColor(long nRow, COLORREF color) = 0;

	// 修改指定sheet名称
	//virtual BOOL SetSheetName(int nIndex) = 0;

	// 增加新的sheet
	virtual BOOL AddNewSheet() = 0;

// 	// 增加新的sheet
// 	virtual BOOL AddNewSheet(const CString& strName) = 0;

	// 修改当前sheet名称
	virtual BOOL SetCurrentSheetName(const CString& strName) = 0;

	// 获取指定sheet名称
	virtual BOOL GetSheetName(int nIndex, CString& strName) = 0;

	// 获取sheet名称集合
	virtual BOOL GetSheetNameArray(CStringArray& arrNames) = 0;

	// 切换到指定sheet
	virtual BOOL ActiveSheet(int nIndex) = 0;

	// 获取sheet数
	virtual int GetSheetsNum() = 0;
};

//===================================================================================================

IExcelOperator *CreateExcelOperator();
void DestroyExcelOperator(IExcelOperator *pExcelOperator);

//===================================================================================================
