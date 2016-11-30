//===================================================================================================
// File:
//		ExcelOperatorAPI.h
// Summary:
//		office�ĵ������ӿ��ࣨexcel��
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
	// ��̨����EXCELӦ�ó���
	virtual BOOL CreateApp() = 0;

	// �˳�����
	virtual BOOL QuitApp() = 0;

	// ǰ̨��ʾEXCELӦ�ó���
	virtual void ShowApp() = 0;

	// ���ĵ�
	virtual BOOL OpenXls(const CString& strName) = 0;

	// �ر��ĵ�
	virtual BOOL CloseXls() = 0;

	// ����һ���հ��ĵ�
	virtual BOOL CreateXls() = 0;

	// �����ĵ�
	virtual BOOL SaveXls() = 0;

	// �ĵ����Ϊ
	virtual BOOL SaveAs(const CString &strFname) = 0;
	virtual BOOL SaveAs2003(const CString &strFname) = 0;

	// ��Ԫ��д��ֵ
	virtual BOOL SetCellValue(long nRow, long nCol, const CString& strVal) = 0;

	// ��ȡ��Ԫ���ֵ
	virtual BOOL GetCellValue(long nRow, long nCol, CString& strVal) = 0;

	// ���õ�Ԫ��ˮƽ���뷽ʽ(nType:1�������,2������,3������)
	virtual BOOL SetCellHorizontalAlignment(long nRow, long nCol, int nType) = 0;

	// ���õ�Ԫ��ˮƽ���뷽ʽ(nType:1�������,2������,3������)
	virtual BOOL SetCellVerticalAlignment(long nRow, long nCol, int nType) = 0;

	// ����
	virtual BOOL FindCell(long &nRow, long &nCol, const CString& strVal, BOOL bMatchCell=TRUE) = 0;

	// �ϲ���Ԫ��
	virtual BOOL MergeCell(long nStartRow, long nStartCol, long nRowSize, long nColSize) = 0;
	// ȡ���ϲ���Ԫ��
	virtual BOOL UnMergeCell(long nRow, long nCol) = 0;
	// ��ȡ��Ԫ��ĺϲ���Ϣ
	virtual BOOL GetMergeInf(long nRow, long nCol, BOOL *pIsMerged=NULL, long *pStartRow=NULL, long *pStartCol=NULL, long *pRowSize=NULL, long *pColSize=NULL) = 0;

	// ���ö�������
	virtual BOOL SetFirstColumnFixed(BOOL bFixed) = 0;

	// ���ö�������
	virtual BOOL SetFirstRowFixed(BOOL bFixed) = 0;

	// ����ͬʱ�������м�����
	virtual BOOL SetRowAndColumnFixed(BOOL bFixed) = 0;

	// ���������(0)��������(1)
	virtual int GetCount(BOOL bIsColumnOrRow) = 0;

	// �����ʹ�õ�Ԫ�������Ϣ
	virtual BOOL GetUsedRangeInf(long *pFirstRow=NULL, long *pFirstCol=NULL, long *pRowCount=NULL, long *pColCount=NULL) = 0;

	// ����ָ���п������Ӧ����
	virtual BOOL SetColumnAutoFit(long nCol) = 0;

	// ����һ��
	virtual BOOL InsertRow(long nRow) = 0;
	// ����һ��
	virtual BOOL InsertColumn(long nCol) = 0;

	// ɾ��һ��
	virtual BOOL DeleteRow(long nRow) = 0;
	// ɾ��һ��
	virtual BOOL DeleteColumn(long nCol) = 0;

	// ���������
	virtual BOOL ClearRowContents(long nFirstRow, long nRowCount=1) = 0;

	// �趨��Ԫ�񱳾�ɫ
	virtual BOOL SetCellBkColor(long nRow, long nCol, COLORREF color) = 0;

	// �趨ĳһ�еı���ɫ
	virtual BOOL SetColumnBkColor(long nCol, COLORREF color) = 0;

	// �趨ĳһ�еı���ɫ
	virtual BOOL SetRowBkColor(long nRow, COLORREF color) = 0;

	// �޸�ָ��sheet����
	//virtual BOOL SetSheetName(int nIndex) = 0;

	// �����µ�sheet
	virtual BOOL AddNewSheet() = 0;

// 	// �����µ�sheet
// 	virtual BOOL AddNewSheet(const CString& strName) = 0;

	// �޸ĵ�ǰsheet����
	virtual BOOL SetCurrentSheetName(const CString& strName) = 0;

	// ��ȡָ��sheet����
	virtual BOOL GetSheetName(int nIndex, CString& strName) = 0;

	// ��ȡsheet���Ƽ���
	virtual BOOL GetSheetNameArray(CStringArray& arrNames) = 0;

	// �л���ָ��sheet
	virtual BOOL ActiveSheet(int nIndex) = 0;

	// ��ȡsheet��
	virtual int GetSheetsNum() = 0;
};

//===================================================================================================

IExcelOperator *CreateExcelOperator();
void DestroyExcelOperator(IExcelOperator *pExcelOperator);

//===================================================================================================
