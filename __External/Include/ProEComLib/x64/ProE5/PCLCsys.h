//===================================================================================================
// File:
//		PCLCsys.h
// Summary:
//		����ϵ�ӿ���
// Date:
//		2016-08-27
// Author:
//		HuoPengCheng(huopc@buaa.edu.cn)
//===================================================================================================

#pragma once

#include "PCLFeature.h"

//===================================================================================================

// ����ϵ����
typedef struct __tagIKSCsysData
{
	SVDOUBLE3 o;									// ԭ��
	SVDOUBLE3 x;									// X��
	SVDOUBLE3 y;									// Y��
	SVDOUBLE3 z;									// Z��

	__tagIKSCsysData()
	{
		memset(this, 0, sizeof(__tagIKSCsysData));
		x.x = y.y = z.z = 1.0;
	}
	__tagIKSCsysData(const __tagIKSCsysData &data)
	{
		o = data.o;
		x = data.x;
		y = data.y;
		z = data.z;
	}
	__tagIKSCsysData operator=(const __tagIKSCsysData &data)
	{
		if (&data == this)
			return *this;
		o = data.o;
		x = data.x;
		y = data.y;
		z = data.z;
		return *this;
	}
}IKSCsysData;

//===================================================================================================

// ���Ƽ��νӿ���
class CPCLCsys : public CPCLFeature
{
public:
	CPCLCsys();
	virtual ~CPCLCsys();

public:

	// ��ȡģ�͵�Ĭ�ϲο�����ϵ
	static BOOL GetSolidDefaultCsys(
		ProSolid pSld,														// �ο�ʵ��(in)
		ProCsys &pDefaultCsys												// Ĭ�ϲο�����ϵ(out)
		);

	// ��ȡ����ϵ�����Ĳο�����ϵ
	static BOOL GetCsysRefCsys(
		ProSelection pSelCsysFeature,										// ����ϵ(in)
		ProSelection &pSelRefCsys											// �ο�����ϵ(out)
		);

	// ��ȡԪ�������Ĳο�����ϵ
	static BOOL GetAsmcompRefCsys(
		ProAsmcomp &asmcomp,												// Ԫ������(in)
		ProGeomitem &refCsysItem											// װ��ο�����ϵ(out)
		);

	// ��ȡ����ϵ�Ĳο�����ϵ
	static BOOL GetCsysRefCsys(
		ProGeomitem &csysItem,												// ����ϵ(in)
		ProGeomitem &refCsysItem											// �ο�����ϵ(out)
		);

	// ��������ϵ��ȡ����ϵ����,(����������ϵ)
	static BOOL GetCsysData(
		ProModelitem &csysItem,												// ����ϵ����Ŀ(in)
		IKSCsysData &csysData												// ����ϵ����(out)
		);

	// ��ȡѡ������ϵ�����ݣ��������������
	static BOOL GetCsysData(
		ProSelection pSelCsys,												// ����ϵ��ѡ�����(in)
		IKSCsysData &csysData												// ����ϵ����(out)
		);

	// ����ȱʡ����ϵ
	static BOOL CreateDefaultCSys(
		ProSolid pSld,														// ����ϵ����ģ��(in)
		const CString &strUDFPath,											// UDF·��(in)
		ProName szCsysName,													// ����ϵ��(in)
		ProFeature &newCsysFeature											// �µ�����ϵ����(out)
		);

	// ��������ϵ
	static BOOL CreatCsysByOffset(
		ProSelection pSelMdl,												// ѡ���ģ��(in)
		ProSelection pSelRefCsys,											// �ο�����ϵ(in)
		const double &dMoveX,const double &dMoveY, const double &dMoveZ,	// x, y, z ��ƫ����(in)
		const double &dRotX, const double &dRotY, const double &dRotZ,		// x, y, z �����ת��(in)
		ProFeature &newCsysFeature											// ���ɵ�����ϵ(out)
		);

	// ��������ϵ��λ�úͻ�׼����ϵ�������µ�����ϵ
	static BOOL CreateCSys(
		const IKSCsysData &newCsysData,										// ������ϵ���ݣ�ԭ��λ�ã�x��y��z�᷽������(in)
		ProSelection pSelSld,												// ����ϵ����ģ��(in)
		ProSelection pSelDatumCsys,											// ѡ��Ĳο�����ϵ(in)
		ProName szCsysName,													// ����ϵ��(in)
		ProFeature &newCsysFeature											// �µ�����ϵ����(out)
		);

	// ��������ϵ��λ�ã�����(*������ϵΪ�ο�������*)����ϵ
	static BOOL ModifyCSys(
		ProSelection pSelCsys,												// ����ϵѡ�����
		IKSCsysData &csysData												// ����ϵ����(in)
		);

	// �õ�Դ����ϵ��Ŀ������ϵת����ƽ��������ת�Ƕ�
	static BOOL GetCsysMoveParam(
		const IKSCsysData &srcCsysData,										// Դ����ϵ����(in)
		const IKSCsysData &destCsysData,									// Ŀ������ϵ����(in)
		double &dXMove, double &dYMove, double &dZMove,						// x,y,zƽ����(out)
		double &dRotX, double &dRotY, double &dRotZ							// x,y,z��ת�Ƕ�(out)
		);

protected:

	// ͨ��x,y,z���ƫ�ƺ���ת�޸�(*������ϵΪ�ο�������*)����ϵ
	static BOOL ModifyCsysByOffset(
		ProSelection pSelCsysFeature,										// ѡ�������ϵ(in)
		const double &dMoveX,const double &dMoveY,const double &dMoveZ,		// x,y,z���ƫ����(in)
		const double &dRotX,const double &dRotY,const double &dRotZ			// ��x,y,z�����ת��(in)
		);

	// ͨ��ƫ�óߴ���������ϵ
	static BOOL ModifyCsysByOffsetByDimension(
		ProSelection pSelCsysFeature,										// ѡ�������ϵ����(in)
		const double &dMoveX,const double &dMoveY, const double &dMoveZ,	// x,y,z���ƫ����(in)
		const double &dRotX, const double &dRotY, const double &dRotZ		// ��x,y,z�����ת��(in)
		);

private:
	// ����ģ������ϵ�Ķ�������
	static ProError GetSolidCsysVisitAction(ProCsys pCsys, ProError status, ProAppData pAppData);

	// ���������ĳߴ綯������
	static ProError ModifyCsysByOffsetByDimensionVisit(ProDimension *dimension, ProError status, ProAppData data);

};

//===================================================================================================
 