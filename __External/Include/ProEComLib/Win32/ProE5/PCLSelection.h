//===================================================================================================
// File:
//		PCLSelection.h
// Summary:
//		ѡ�����ӿ���
// Date:
//		2016-09-08
// Author:
//		HuoPengcheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

//===================================================================================================
// ѡ�����ӿ���
class CPCLSelection
{
public:
	CPCLSelection();
	virtual ~CPCLSelection();

public:

	// ����ѡ�����
	static BOOL HighlightSelection(
		ProSelection pSel								// ѡ�����(in)
		);

	// ����ѡ�����
	static BOOL HighlightSelection(
		const vector<ProSelection> &arrSel				// ѡ�����(in)
		);

	// ���ѡ����������
	static BOOL GetNameFromProSelection(
		ProSelection pSel,								// ѡ�����(in)
		CString &strSelName								// ������(out)
		);

	// ��ȡѡ������λ��
	static BOOL GetSelectionWorldPos(
		ProSelection pSel,								// ѡ�����(in)
		SVDOUBLE3 &vWorldPos							// λ��(out)
		);

	// ��ȡѡ�����������ʵ��ģ�͵�ѡ�����
	BOOL GetSelectionRelSelection(
		ProSelection pSel,								// ѡ�����(in)
		ProSolid pOwnerMdl,								// ʵ��ģ��(in)
		ProSelection &pSelRel							// ��Ե�ѡ�����(out)
		);

};

//===================================================================================================
