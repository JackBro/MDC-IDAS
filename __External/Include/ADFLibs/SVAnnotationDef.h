//===================================================================================================
// Summary:
//		FreeType�Ľӿڶ���
// Date:
//		2013-03-08
// Author:
//		liuguoqing(gliu@bplead.com)
//===================================================================================================

#ifndef __SVAnnotationDef_h__
#define __SVAnnotationDef_h__

#include <vector>
#include "SVBaseDef.h"
#include "SVGeomDef.h"

//===================================================================================================

// ����Ϊ�궨��

// �Ƕ�ת����
#define ANGLE_TO_RADIAN(angle) (angle) * (0.017453292519943295769236907684883)
#define RADIAN_TO_ANGLE(rad) (rad) * (57.295779513082320876798154814105)

// �ַ����궨��
// ʹ�ú����ֶ����԰汾
#define SVSTR_TECHREQ L"����Ҫ��"

// ���ʵ��Ҫ��
#define SVSTR_ANNOTGTOL_MAXMATCOND L"(M)"
// ��Сʵ��Ҫ��
#define SVSTR_ANNOTGTOL_LSTMATCOND L"(L)"
// ���칫���
#define SVSTR_ANNOTGTOL_PROJTOLZONE L"(P)"
// ����״̬����
#define SVSTR_ANNOTGTOL_FREESTATE L"(F)"
// ����ƽ��
#define SVSTR_ANNOTGTOL_TANPLANE L"(T)"
// ����Ҫ��
#define SVSTR_ANNOTGTOL_EMBODY L"(E)"
// ����ԭ��RFS
#define SVSTR_ANNOTGTOL_RFS L"(S)"

//===================================================================================================

// ����Ϊö��ֵ����

// ��ע����
typedef enum __tagAnnotationType
{
	AT_UNKNOWN			= 0,	// δ֪����
	AT_DIMENSION		= 1,	// �ߴ�
	AT_NOTE				= 2,	// ע��
	AT_DATUM			= 3,	// ��׼
	AT_GTOL				= 4,	// ��λ����
	AT_SURFFINISH		= 5,	// �ֲڶ�
	AT_TECHREQU			= 6,	// ����Ҫ��
	AT_SYMBOL			= 7,	// һ�����
	AT_WELDFILLET		= 8,	// ���Ƿ���
	AT_WELD				= 9,	// ���ӷ���
	AT_SAMEHOLE			= 10,	// ��ͬ�׷���
	AT_SKETCH			= 20,	// �ݻ棨����һ��������Ŵ���
	AT_COSMETIC			= 21,	// ��������������һ��������Ŵ���

	AT_SECTIONPLANE		= 100	// ����ƽ��
} AnnotationType;

// �ߴ繫�����뷽ʽ
typedef enum __tagDimensionInputType
{
	INTYPE_SYMBOL		= 0,	// ����
	INTYPE_TOL			= 1,	// ƫ��
	INTYPE_FIT			= 2,	// ���
	INTYPE_SYMMETRY		= 3,	// �Գ�
} DimInputType;

// �ߴ繫�������ʽ
typedef enum __tagDimensionOuputType
{
	OUTYPE_SYMBOL		= 0,	// ����
	OUTYPE_TOL			= 1,	// ƫ��
	OUTYPE_BRACKETTOL	= 2,	// (ƫ��)
	OUTYPE_SYMBOLTOL	= 3,	// ����(ƫ��)
	OUTYPE_LIMIT		= 4,	// ���޳ߴ�
	OUTYPE_FIT			= 5,	// ���
	OUTYPE_FITGAP		= 6,	// ���(��϶)
	OUTYPE_NONE			= -1	// ��Ч
} DimOutputType;

// �������
typedef enum __tagTableType
{
	TABT_HOLE_TOL_SMALL		= 0,		// �׹���ߴ�С��500
	TABT_HOLE_TOL_BIG		= 1,		// �׹���ߴ����500С��3150
	TABT_HOLE_TOL_NONE		= 2,		// �׹���ߴ����3150
	TABT_AXIS_TOL_SMALL		= 3,		// �ṫ��ߴ�С��500
	TABT_AXIS_TOL_BIG		= 4,		// �ṫ��ߴ����500С��3150
	TABT_AXIS_TOL_NONE		= 5,		// �׹���ߴ����3150
	TABT_HOLE_BASE_NORMAL	= 6,		// ������
	TABT_HOLE_BASE_NONE		= 7,		// �����ƣ��ߴ����3150
	TABT_AXIS_BASE_NORMAL	= 8,		// ������
	TABT_AXIS_BASE_NONE		= 9,		// �����ƣ��ߴ����3150
}TABLE_TYPE;

// �ߴ��ѡ��ļ�������
typedef enum __tagSDGeomType
{
	SDGT_POINT			= 1,		// ��
	SDGT_LINE			,			// ֱ��
	SDGT_CIRCLE			,			// Բ
	SDGT_ARC			,			// Բ��
	SDGT_ELLIPSE		,			// Բ��
	SDGT_POINT_POINT	,			// ��͵�
	SDGT_POINT_LINE		,			// ���ֱ��
	SDGT_POINT_CIRCLE	,			// ���Բ
	SDGT_LINE_POINT		,			// ֱ�ߺ͵�
	SDGT_LINE_LINE		,			// ֱ�ߺ�ֱ��
	SDGT_LINE_CIRCLE	,			// ֱ�ߺ�Բ
	SDGT_CIRCLE_POINT	,			// Բ�͵�
	SDGT_CIRCLE_LINE	,			// Բ��ֱ��
	SDGT_CIRCLE_CIRCLE	,			// Բ��Բ
	SDGT_OTHER			= -1		// �������
} SDGeomType;

// �ߴ�����
typedef enum __tagDimensionType 
{
	DT_HOR_DIS_PNT_PNT			= 1,		// ���ˮƽ����
	DT_VER_DIS_PNT_PNT			,			// �����ֱ����
	DT_VEC_DIS_PNT_PNT			,			// �����������
	//DT_DIS_PNT_LINE				,			// ����ֱ�߾���
	//DT_DIS_LINE_PNT				,			// ����ֱ�߾���
	//DT_DIS_LINE_LINE			,			// ֱ����ֱ�߾���
	DT_ANG_LINE_LINE			,			// ֱ����ֱ�߽Ƕ�
	DT_DIA_CIRCLE				,			// Բ��ֱ��
	DT_RAD_CIRCLE				,			// Բ�İ뾶
	DT_LENGTH_ARC				,			// Բ�Ļ���
	DT_TANGENT					,			// ���гߴ�
	DT_OTHER								// �������
} DimensionType;

// ����ֲڶȵĻ�����������
typedef enum __tagSurfFinishSymbolType
{
	SURF_SYMBOL1	= 1,			// ȥ�����ϵķ������
	SURF_SYMBOL2	= 2,
	SURF_SYMBOL3	= 3				// ���ⷽ�����
} SurfFinishSymbolType;

// ����ֲڶȵķ��÷�ʽ
typedef enum __tagSDSymbolAttachType
{
	SATYPE_FREE,
	SATYPE_LEFT_LEADER,
	SATYPE_RIGHT_LEADER,
	SATYPE_RADIAL_LEADER,
	SATYPE_ON_ITEM,
	SATYPE_NORM_ITEM
} SDSymbolAttachType;

// ����ֲڶȵ���������
typedef enum __tagSurfFinishTexturetype
{
	SURF_TEXTURE_PARALLEL	= 1,		// ƽ��
	SURF_TEXTURE_VERTICAL	= 2,		// ��ֱ
	SURF_TEXTURE_CROSS		= 3,		// ����
	SURF_TEXTURE_MULTI		= 4,		// �������
	SURF_TEXTURE_CIRCLE		= 5,		// ͬ��
	SURF_TEXTURE_RADIATION	= 6,		// ����
	SURF_TEXTURE_P			= 7,		// �޷�����͹���ϸ����
	SURF_TEXTURE_CLEAR		= 8			// ��
} SurfFinishTexturetype;

// �趨��������
typedef enum __tagSdGtolType
{
	GTOL_UNKNOWN          = 0,
	GTOL_STRAIGHTNESS     = 1,	// ֱ�߶�
	GTOL_FLATNESS         = 2,	// ƽ���
	GTOL_CIRCULAR         = 3,	// Բ��
	GTOL_CYLINDRICAL      = 4,	// Բ����
	GTOL_LINE             = 5,	// ��������
	GTOL_SURFACE          = 6,	// ����������
	GTOL_PARALLEL         = 7,	// ƽ�ж�
	GTOL_PERPENDICULAR    = 8,	// ��ֱ��
	GTOL_ANGULAR          = 9,	// ��б��
	GTOL_POSITION         = 10,	// λ�ö�
	GTOL_CONCENTRICITY    = 11,	// ͬ���
	GTOL_SYMMETRY         = 12,	// �Գƶ�
	GTOL_CIRCULAR_RUNOUT  = 13,	// Բ����
	GTOL_TOTAL_RUNOUT     = 14	// ȫ����
};

typedef enum __tagSdGtolMaterialCond
{
	SDGTOLMATCOND_UNKNOWN     = 0,
	SDGTOLMATCOND_LMC         = 1,
	SDGTOLMATCOND_MMC         = 2,
	SDGTOLMATCOND_RFS         = 3,
	SDGTOLMATCOND_DEFAULT_RFS = 4
};

// ��λ������÷�ʽ
typedef enum __tagSdGtolPlacementType
{
	GPTYPE_UNKNOWN			= -1,
	GPTYPE_NORMLEADER		= 0,	// ���ߴ�ֱ��ͼԪ
	GPTYPE_TOITEMLEADERS	= 1,	// ����ָ��ͼԪ
	GPTYPE_FREELEADERS		= 2,	// �������ɷ���
	GPTYPE_DIM				= 3,	// �ߴ����
	GPTYPE_GTOL				= 4,	// �������ι���
	GPTYPE_FREENOTE			= 5,	// ���ɷ���
} SdGtolPlacementType;

// ��λ�������߷�ʽ
typedef enum __tagSdArrowStyle
{
	AS_UNKNOWN			= -1,
	AS_ARROWHEAD		=  1,	// ��ͷ
	AS_DOT				=  2,	// ��
	AS_FILLEDDOT		=  3,	// ʵ�ĵ�
	AS_NOARROW			=  4,	// ��
	AS_CROSS			=  5,	// ����
	AS_SLASH			=  6,	// б��
	AS_INTEGRAL			=  7,	// ����
	AS_BOX				=  8,	// ����
	AS_FILLEDBOX		=  9,	// ʵ�Ŀ�
	AS_DOUBLEARROW		= 10,	// ˫��ͷ
	AS_TARGET			= 14,	// Ŀ��
	AS_LEFTHALF			= 15,	// ����ͷ
	AS_RIGHTHALF		= 16,	// �Ұ��ͷ
	AS_TRIANGLE			= 18,	// ������
	AS_NOCHANGE			= 19	// ��ԭ��
} SdArrowStyle;

// ���ι���Ĳ��ռ�������
typedef enum __tagSdGtolReferenceType
{
	GRTYPE_ANY_SURFACE		= 0x0001,	// ��������
	GRTYPE_PLANE_SURFACE	= 0x0004,	// ƽ��
	GRTYPE_CIRCULAR_SURFACE	= 0x0008,	// Բ�����Բ׶��
	GRTYPE_ANY_EDGE			= 0x0010,	// �����
	GRTYPE_LINE_EDGE		= 0x0040,	// ֱ�߱�
	GRTYPE_UNKNOWN			= 0x0000,
} SdGtolReferenceType;

typedef enum __tagSdDimensionValueRegion
{
	DVREG_INVALID			= -1,		// v<0
	DVREG_0_500				= 0,		// 0<v<=500
	DVREG_500_3150			= 1,		// 500<v<=3150
	DVREG_MORETHAN_3150		= 2			// v>3150
} DimValReg;

// ��׼�Ĺ�������
typedef enum __tagGBTYPE
{
	GB_CIR  = 0, 		// Բ��
	GB_REC	= 1			// ����
} GBTYPE;

// ��׼�ĳ�������
typedef enum __tagDATUMLENGTHTYPE
{
	DATUMLT_1	= 1, 		// ��������1
	DATUMLT_2	= 2,		// ��������2
	DATUMLT_3	= 3, 		// ��������3
	DATUMLT_4	= 4,		// ��������4
	DATUMLT_5	= 5,		// ��������5
} DATUMLENGTHTYPE;

// ���ӻ�����������
typedef enum __tagWeldingBaseType
{
	WELD_BASE_NULL			= 0,			// �Ƿ�
	WELD_BASE_TYPE1			= 1,			// ��ߺ���
	WELD_BASE_TYPE2			= 2,			// I�κ���
	WELD_BASE_TYPE3			= 3,			// V�κ���
	WELD_BASE_TYPE4			= 4,			// ����V�κ���
	WELD_BASE_TYPE5			= 5,			// ���۱�V�κ���
	WELD_BASE_TYPE6			= 6,			// ���۱ߵ���V�κ���
	WELD_BASE_TYPE7			= 7,			// ���۱�U�κ���
	WELD_BASE_TYPE8			= 8,			// ���۱�J�κ���
	WELD_BASE_TYPE9			= 9,			// ��׺���
	WELD_BASE_TYPE10		= 10,			// �Ǻ���
	WELD_BASE_TYPE11		= 11,			// �������ۺ���
	WELD_BASE_TYPE12		= 12,			// �㺸��
	WELD_BASE_TYPE13		= 13,			// �캸��
	WELD_BASE_TYPE14		= 14,			// ����V�κ���
	WELD_BASE_TYPE15		= 15,			// ���ߵ�V�κ���
	WELD_BASE_TYPE16		= 16,			// �˺���
	WELD_BASE_TYPE17		= 17,			// �Ѻ���
	WELD_BASE_TYPE18		= 18,			// ƽ�����ӣ�ǥ����
	WELD_BASE_TYPE19		= 19,			// б�����ӣ�ǥ����
	WELD_BASE_TYPE20		= 20,			// �۵����ӣ�ǥ����
	WELD_BASE_TYPE21		= 21,			// �����κ���
	WELD_BASE_TYPE22		= 22,			// ���������κ���
	WELD_BASE_TYPE23		= 23,			// ���ߺ���
} WeldingBaseType;						

// ���Ӳ����������(ƽ��)
typedef enum __tagWeldingContourType
{
	WELD_CONTOUR_NULL		= 30,
	WELD_CONTOUR_FLAT		= 31,			// ƽ��
	WELD_CONTOUR_CONCAVE	= 32,			// ����
	WELD_CONTOUR_CONVEX		= 33,			// ͹��
	WELD_CONTOUR_SMOOTH		= 34,			// Բ������
} WeldingContourType;

// ���Ӳ����������(�ĵ�)
typedef enum __tagWeldingStripType
{
	WELD_STRIP_NULL			= 40,
	WELD_STRIP_PERMANENT	= 41,			// ���óĵ�
	WELD_STRIP_REMOVABLE	= 42,			// ��ʱ�ĵ�
} WeldingStripType;

// ���Ӳ���������ͣ����溸�죩
typedef enum __tagWeldingFaceType
{
	WELD_FACE_NULL			= 50,
	WELD_FACE_RIGHT			= 51,
	WELD_FACE_LEFT			= 52,
	WELD_FACE_UP			= 53,
	WELD_FACE_DOWN			= 54,	
} WeldingFaceType;

// ���Ӳ���������ͣ�β����
typedef enum __tagWeldingTailType
{
	WELD_TAIL_NULL			= 60,
	WELD_TAIL_TYPE1			= 61,
	WELD_TAIL_TYPE2			= 62	
} WeldingTailType;

// ���ӷ���λ��
typedef enum __tagWeldingLocation
{
	WELD_LOCATION_UP		= 0,
	WELD_LOCATION_CENTER	= 1,
	WELD_LOCATION_DOWN		= 2
} WeldingLocation;

// ��������λ��
typedef enum __tagWeldingDashPosition
{
	WELD_DASH_UP			= 0,
	WELD_DASH_DOWN			= 1,
	WELD_DASH_NONE			= 2
} WeldingDashPosition;

// ��ͼ���ŷ���
typedef enum __tagViewDirectionBaseType
{
	VDBTYPE_VIEWDIRECTION	= 0,
	VDBTYPE_ROTANTICLOCK	= 1,
	VDBTYPE_ROTCLOCK		= 2
} ViewDirectionBaseType;

// ��ͼ���Ÿ����ı�����
typedef enum __tagViewDirectionTextType
{
	VDTTYPE_NULL		= 0,	// ���ı�
	VDTTYPE_NameOnly	= 1,	// �ı�ֻ��������
	VDTTYPE_NameDir		= 2		// �ı��������ƺ�"��"
} tagViewDirectionTextType;

// ��ͼ���ŷ���
typedef enum __tagViewDirectionType
{
	VDTYPE_UP				= 0,
	VDTYPE_DOWN				= 1,
	VDTYPE_LEFT				= 2,
	VDTYPE_RIGHT			= 3
} ViewDirectionType;

// ���ӷ��ŵ�����
// typedef enum __tagWeldSymbolType
// {
// 	WSTYPE_LEFT				= 0,		// ������
// 	WSTYPE_RIGHT_LOC1		= 1,		// ������λ��1
// 	WSTYPE_RIGHT_LOC2		= 2,		// ������λ��2
// 	WSTYPE_RIGHT_LOC3		= 3			// ������λ��3
// } WeldSymbolType; 

// ��������
typedef enum __tagWeldFilletType
{
	WFTYPE_LEFTTOP				= 0,	// ����
	WFTYPE_RIGHTTOP				= 1,	// ����
	WFTYPE_LEFTBOTTOM			= 2,	// ����
	WFTYPE_RIGHTBOTTOM			= 3		// ����
} WeldFilletType;

// ��ͬ������
typedef enum __tagSameHoleType
{
	SHTYPE_QUARTER				= 0,	// �ķ�֮һ
	SHTYPE_HALF					= 1,	// һ��
	SHTYPE_CROSS				= 2,	// ����
	SHTYPE_THREEQUARTER			= 3,	// �ķ�֮��
	SHTYPE_WHOLE				= 4,	// ȫ��
	SHTYPE_CONE_30				= 5,	// 30��Բ׶
	SHTYPE_CROSS_CONE_30		= 6,	// ����30��Բ׶
} SameHoleType;

// ���� / Ԥ��ͼ��ID
typedef enum __tagCurveType
{
	CT_GEOM					= 0,	// ����
	CT_DATUM				= 1,	// ��׼
	CT_ANNOTATION			= 2,	// ��ע
} CurveType;

// ѡ��������
typedef enum __tagSelectResultType
{
	SRT_SUCCEED				= 0,	// �ɹ�(ѡ�м���)
	SRT_QUIT				= 1,	// �˳�(��ȡ����ť)
	SRT_FINISH				= 2,	// ���(��ȷ����ť���м�)
	SRT_PICKOTHER			= 3,	// ��������(ѡ�������˵�����ֹ)
	SRT_UNKNOWN				= 4,	// δ֪
} SelResType;

// б��׶�ȵķ�������
typedef enum __tagTaperType
{
	TTTYPE_TAPER_RIGHT				= 1,	// ׶��_����
	TTTYPE_TAPER_LEFT				= 2,	// ׶��_����
	TTTYPE_SLOPE_LEFTUP				= 3,	// б��_������
	TTTYPE_SLOPE_LEFTDOWN			= 4,	// б��_������
	TTTYPE_SLOPE_RIGHTUP			= 5,	// б��_������
	TTTYPE_SLOPE_RIGHTDOWN			= 6,	// б��_������
} TaperType;

// ���Ŀ׵�����
typedef enum __tagCenterHoleType
{
	CHTYPE_REQUIRE				= 1,	// Ҫ�������Ŀ�
	CHTYPE_NOTALLOW				= 2,	// �����������Ŀ�
	CHTYPE_CAN					= 3,	// ���Ա������Ŀ�
} CenterHoleType;

// ��߷��ŵ�����
typedef enum __tagElevationType
{
	ETYPE_GENERAL				= 1,	// һ��
	ETYPE_SPECIAL				= 2,	// ����
	ETYPE_OUTSIDE				= 3,	// ����
} ElevationType;

// ��߷��ŵķ�������
typedef enum __tagElevationDirectionType
{
	EDTYPE_RIGHT				= 1,	// ��ֵ�ı�����
	EDTYPE_LEFT					= 2,	// ��ֵ�ı�����
} ElevationDirectionType;

// �ӽǷ�������
typedef enum __tagViewingAngleType
{
	VATYPE_FIRST				= 1,	// ��һ��
	VATYPE_THIRD				= 2,	// ������
} ViewingAngleType;

typedef enum __tagSDColorMethod
{
	SD_COLOR_METHOD_DEFAULT,
	SD_COLOR_METHOD_TYPE,
	SD_COLOR_METHOD_RGB
} SDColorMethod;

// ��ϸ�����λ��־
typedef enum __tagDataPlaceFlag
{
	DPF_DECIMAL,			// С��λ
	DPF_VALID,				// ��Чλ
	DPF_ALLOWED,			// ����С��λ
} DataPlaceFlag;

// ��ע���ڵ�����
typedef enum _BPANNOTTREENODETYPE
{
	BPATNT_NULL				= 0,	// ��Ч��
	BPATNT_ANNOT			= 1,	// ��ע
	BPATNT_ANNOTVIEW		= 2,	// ��ע��ͼ
	BPATNT_ANNOTBLOCK		= 3,	// ��ע��
} BPANNOTTREENODETYPE;

// �ı���ʽ��ˮƽ���뷽ʽ
typedef enum _tagTextHorJustType
{
	THJT_UNKNOWN			= -1,	// ��Ч����
	THJT_LEFT				= 0,	// ���
	THJT_CENTER				= 1,	// ����
	THJT_RIGHT				= 2,	// �ұ�
} TextHorJustType;

// �ı���ʽ����ֱ���뷽ʽ
typedef enum _tagTextVerJustType
{
	TVJT_TOP				= 0,	// ����
	TVJT_MIDDLE				= 1,	// �м�
	TVJT_BOTTOM				= 2,	// �ײ�
} TextVerJustType;

// �ı���ʽ����ֱ���뷽ʽ
typedef enum _tagLeaderStyle
{
	LS_STANDARD				= 0,	// ��׼
	LS_ISO					= 1,	// ISO
} LeaderStyle;

// �ı�����
typedef enum _tagTextDirection
{
	TD_LEFT					= 0,	// ����
	TD_RIGHT				= 1,	// ����
} TextDirection;

//===================================================================================================
// ����Ϊ�ṹ�嶨��

// ��עģ��ʰȡ����Ƭ
typedef struct _SVANNOTMDL_PICKTRIANGLE {
	std::vector<BPBASETRIANGLE> arrMain;			// ��ע�����ʰȡ����Ƭ
	std::vector<BPBASETRIANGLE> arrLeaderArrow;		// ���߼�ͷ��ʰȡ����Ƭ(ÿ����ͷһ��ʰȡ����Ƭ)
	_SVANNOTMDL_PICKTRIANGLE()
	{
	}
	_SVANNOTMDL_PICKTRIANGLE(const _SVANNOTMDL_PICKTRIANGLE &tri)
	{
		arrMain = tri.arrMain;
		arrLeaderArrow = tri.arrLeaderArrow;
	}
	_SVANNOTMDL_PICKTRIANGLE &operator=(const _SVANNOTMDL_PICKTRIANGLE& tri){
		if (&tri != this)
		{
			arrMain = tri.arrMain;
			arrLeaderArrow = tri.arrLeaderArrow;
		}
		return *this;
	}
	void Clear()
	{
		arrMain.clear();
		arrLeaderArrow.clear();
	}
} SVANNOTMDL_PICKTRIANGLE;

// RGB��ɫ
typedef struct __tagSDColorMap
{
	double  red;          /* percentage of red from 0.0 to 1.0     */
	double  green;        /* percentage of green from 0.0 to 1.0   */
	double  blue;         /* percentage of blue from 0.0 to 1.0    */
} SDColorMap;

// ��ɫ
typedef struct __tagSDColor
{
	SDColorMethod method;
	union {
		int nType;
		SDColorMap map;
	} value;
} SDColor;

// ���ӷ�����Ϣ
typedef struct __tagWeldingInfo
{
	int nUpBaseType;							// ����λ�����Ϸ�ʱ��������������, �ο�WeldingBaseTypeö��ֵ
	int nDownBaseType;							// ����λ�����·�ʱ��������������, �ο�WeldingBaseTypeö��ֵ
	int nCenterBaseType;						// ����λ�����м�ʱ��������������, �ο�WeldingBaseTypeö��ֵ��WELD_BASE_TYPE12��WELD_BASE_TYPE13����Ч

	int nUpContourType;							// ����λ�����Ϸ�ʱ��ƽ�油��������ͣ��ο�WeldingContourTypeö��ֵ
	int nDownContourType;						// ����λ�����·�ʱ��ƽ�油��������ͣ��ο�WeldingContourTypeö��ֵ
	int nLocation;								// ���ӷ���λ��, �ο�WeldingLocationö��ֵ

	int nUpStripType;							// ����λ�����Ϸ�ʱ�����Ӳ����������(�ĵ�)���ο�WeldingStripTypeö��ֵ
	int nDownStripType;							// ����λ�����·�ʱ�����Ӳ����������(�ĵ�)���ο�WeldingStripTypeö��ֵ

	int nTailType;								// β�����Ӳ���������ͣ��ο�WeldingTailTypeö��ֵ

	CSVWString strUpLeftValue;					// ����λ�����Ϸ�ʱ����ߴ�
	CSVWString strUpUpperValue;					// ����λ�����Ϸ�ʱ���ϳߴ�
	CSVWString strUpRightValue1;				// ����λ�����Ϸ�ʱ���ҳߴ�1
	CSVWString strUpRightValue2;				// ����λ�����Ϸ�ʱ���ҳߴ�2
	CSVWString strUpRightValue3;				// ����λ�����Ϸ�ʱ���ҳߴ�3
	CSVWString strDownLeftValue;				// ����λ�����·�ʱ����ߴ�
	CSVWString strDownUpperValue;				// ����λ�����·�ʱ���ϳߴ�
	CSVWString strDownRightValue1;				// ����λ�����·�ʱ���ҳߴ�1
	CSVWString strDownRightValue2;				// ����λ�����·�ʱ���ҳߴ�2
	CSVWString strDownRightValue3;				// ����λ�����·�ʱ���ҳߴ�3
	CSVWString strCenterLeftValue;				// ����λ�����·�ʱ����ߴ�
	CSVWString strCenterUpperValue;				// ����λ�����м�ʱ���ϳߴ�
	CSVWString strCenterRightValue1;			// ����λ�����м�ʱ���ҳߴ�1
	CSVWString strCenterRightValue2;			// ����λ�����м�ʱ���ҳߴ�2
	CSVWString strCenterRightValue3;			// ����λ�����м�ʱ���ҳߴ�3
	CSVWString strNote;							// ����˵��
	int nDashPosition;							// ��������λ��
	IKS_BOOL bAround;								// �Ƿ�Ϊ��Χ���ӷ���
	IKS_BOOL bScene;								// �Ƿ�Ϊ�ֳ�����
	IKS_BOOL bStagger;								// �Ƿ�Ϊ����������ӷ���,���FALSEʱ,strNote������ʾ

	int nTriFaceType;							// ���溸�캸�Ӳ���������ͣ��ο�WeldingFaceTypeö��ֵ

	int nAngle;									// ���ýǶ�

	IKS_BOOL bLeaderOrientLeft;						// ���ӵ����߷���TUREΪ��FALSEʱΪ��

	__tagWeldingInfo()
	{
		Init();
	}
	__tagWeldingInfo(const __tagWeldingInfo &info)
	{
		nUpBaseType = info.nUpBaseType;
		nDownBaseType = info.nDownBaseType;
		nCenterBaseType = info.nCenterBaseType;
		nUpContourType = info.nUpContourType;
		nDownContourType = info.nDownContourType;
		nUpStripType = info.nUpStripType;
		nDownStripType = info.nDownStripType;
		nLocation = info.nLocation;
		nTailType = info.nTailType;
		strUpLeftValue = info.strUpLeftValue;
		strUpUpperValue = info.strUpUpperValue;
		strUpRightValue1 = info.strUpRightValue1;
		strUpRightValue2 = info.strUpRightValue2;
		strUpRightValue3 = info.strUpRightValue3;
		strDownLeftValue = info.strDownLeftValue;
		strDownUpperValue = info.strDownUpperValue;
		strDownRightValue1 = info.strDownRightValue1;
		strDownRightValue2 = info.strDownRightValue2;
		strDownRightValue3 = info.strDownRightValue3;
		strCenterLeftValue = info.strCenterLeftValue;
		strCenterUpperValue = info.strCenterUpperValue;
		strCenterRightValue1 = info.strCenterRightValue1;
		strCenterRightValue2 = info.strCenterRightValue2;
		strCenterRightValue3 = info.strCenterRightValue3;
		strNote = info.strNote;
		nDashPosition = info.nDashPosition;
		bAround = info.bAround;
		bScene = info.bScene;
		bStagger = info.bStagger;
		nTriFaceType = info.nTriFaceType;
		nAngle = info.nAngle;
		bLeaderOrientLeft = info.bLeaderOrientLeft;
	}
	__tagWeldingInfo& operator=(const __tagWeldingInfo& info){
		if (&info == this)
			return *this;
		nUpBaseType = info.nUpBaseType;
		nDownBaseType = info.nDownBaseType;
		nCenterBaseType = info.nCenterBaseType;
		nUpContourType = info.nUpContourType;
		nDownContourType = info.nDownContourType;
		nUpStripType = info.nUpStripType;
		nDownStripType = info.nDownStripType;
		nLocation = info.nLocation;
		nTailType = info.nTailType;
		strUpLeftValue = info.strUpLeftValue;
		strUpUpperValue = info.strUpUpperValue;
		strUpRightValue1 = info.strUpRightValue1;
		strUpRightValue2 = info.strUpRightValue2;
		strUpRightValue3 = info.strUpRightValue3;
		strDownLeftValue = info.strDownLeftValue;
		strDownUpperValue = info.strDownUpperValue;
		strDownRightValue1 = info.strDownRightValue1;
		strDownRightValue2 = info.strDownRightValue2;
		strDownRightValue3 = info.strDownRightValue3;
		strCenterLeftValue = info.strCenterLeftValue;
		strCenterUpperValue = info.strCenterUpperValue;
		strCenterRightValue1 = info.strCenterRightValue1;
		strCenterRightValue2 = info.strCenterRightValue2;
		strCenterRightValue3 = info.strCenterRightValue3;
		strNote = info.strNote;
		nDashPosition = info.nDashPosition;
		bAround = info.bAround;
		bScene = info.bScene;
		bStagger = info.bStagger;
		nTriFaceType = info.nTriFaceType;
		nAngle = info.nAngle;
		bLeaderOrientLeft = info.bLeaderOrientLeft;
		return *this;
	}

	void Init()
	{
		nUpBaseType = WELD_BASE_NULL;			
		nDownBaseType = WELD_BASE_NULL;	
		nCenterBaseType = WELD_BASE_NULL;
		nLocation = WELD_LOCATION_UP;
		nUpContourType = WELD_CONTOUR_NULL;
		nDownContourType = WELD_CONTOUR_NULL;
		nUpStripType = WELD_STRIP_NULL;
		nDownStripType = WELD_STRIP_NULL;
		strUpLeftValue = L"";
		strUpUpperValue = L"";
		strUpRightValue1 = L"";
		strUpRightValue2 = L"";
		strDownLeftValue = L"";
		strDownUpperValue = L"";
		strDownRightValue1 = L"";
		strDownRightValue2 = L"";
		strCenterLeftValue = L"";
		strCenterUpperValue = L"";
		strCenterRightValue1 = L"";
		strCenterRightValue2 = L"";
		strCenterRightValue3 = L"";
		strNote = L"";
		strUpRightValue3 = L"";
		strDownRightValue3 = L"";
		nDashPosition = WELD_DASH_DOWN;	
		bAround = FALSE;
		bScene = FALSE;
		nTailType = WELD_TAIL_TYPE1;
		bStagger = FALSE;
		nTriFaceType = WELD_FACE_NULL;
		nAngle = 0;
		bLeaderOrientLeft = TRUE;
	}

} WeldingInfo;

// ���Ƿ�����Ϣ
typedef struct __tagWeldFilletInfo
{
	int nType;			// ��������
	double dSize;		// ���Ǵ�С

	__tagWeldFilletInfo()
	{
		nType = WFTYPE_LEFTTOP;	
		dSize = 10.0;
	}
	__tagWeldFilletInfo(const __tagWeldFilletInfo &info)
	{
		nType = info.nType;			
		dSize = info.dSize;			
	}
	__tagWeldFilletInfo &operator=(const __tagWeldFilletInfo& info){
		if (&info == this)
			return *this;
		nType = info.nType;
		dSize = info.dSize;
		return *this;
	}
} WeldFilletInfo;

// ��ͼ������Ϣ
typedef struct __tagViewDirectionInfo
{
	int nType;						// ��ͼ��������
	CSVWString strName;				// ��ͼ�������ƣ�һ��Ϊ: A B C ...
	int nDirectionType;				// ��ͼ���ŷ���һ��Ϊ���ϣ��£�����
	int nAngle;						// ��ת�Ƕ�
	int nTextType;					// ��ͼ���Ÿ����ı�����
	double dTextHeight;				// ��ͼ�������ִ�С

	__tagViewDirectionInfo()
	{
		nType = VDBTYPE_VIEWDIRECTION;
		strName = L"A";
		nDirectionType = VDTYPE_UP;
		nAngle = 0;
		nTextType = VDTTYPE_NULL;
		dTextHeight = 5.0;
	}
	__tagViewDirectionInfo(const __tagViewDirectionInfo &info)
	{
		nType = info.nType;
		strName = info.strName;
		nDirectionType = info.nDirectionType;
		nAngle = info.nAngle;
		nTextType = info.nTextType;
		dTextHeight = info.dTextHeight;
	}
	__tagViewDirectionInfo operator=(const __tagViewDirectionInfo& info){
		if (&info == this)
			return *this;
		nType = info.nType;
		strName = info.strName;
		nDirectionType = info.nDirectionType;
		nAngle = info.nAngle;
		nTextType = info.nTextType;
		dTextHeight = info.dTextHeight;
		return *this;
	}
} ViewDirectionInfo;

// ��ͬ�׷�����Ϣ
typedef struct __tagSameHoleInfo
{
	int nType;			// ��ͬ������
	double dAngle;		// �Ƕ�

	__tagSameHoleInfo()
	{
		nType = SHTYPE_QUARTER;
		dAngle = 0.0;
	}
	__tagSameHoleInfo(const __tagSameHoleInfo &info)
	{
		nType = info.nType;
		dAngle = info.dAngle;
	}
	__tagSameHoleInfo &operator=(const __tagSameHoleInfo& info){
		if (&info == this)
			return *this;
		nType = info.nType;
		dAngle = info.dAngle;
		return *this;
	}
} SameHoleInfo;

// б��׶�ȷ��ŵ���Ϣ
typedef struct __tagTaperInfo
{
	int nType;						// ��������
	CSVWString strDim;				// б��׶�ȳߴ�

	__tagTaperInfo()
	{
		nType = TTTYPE_TAPER_RIGHT;
		strDim = L"";
	}
	__tagTaperInfo(const __tagTaperInfo &ti)
	{
		nType = ti.nType;
		strDim = ti.strDim;
	}
	__tagTaperInfo& operator=(const __tagTaperInfo &ti)
	{
		if (&ti == this)
			return *this;
		nType = ti.nType;
		strDim = ti.strDim;
		return *this;
	}
} TaperInfo;

// ���ָ�ʽ����Ϣ
typedef struct __tagFormatInfo
{
	int nPlaceFlag;					// λ��־
	int nDecimalNum;				// С��λ��
	int nValidNum;					// ��Чλ��
	int nAllowedNum;				// ����λ��

	__tagFormatInfo()
	{
		nPlaceFlag = DPF_ALLOWED;
		nDecimalNum = -1;
		nValidNum = -1;
		nAllowedNum = 3;
	}
	__tagFormatInfo(const __tagFormatInfo &fi)
	{
		nPlaceFlag = fi.nPlaceFlag;
		nDecimalNum = fi.nDecimalNum;
		nValidNum = fi.nValidNum;
		nAllowedNum = fi.nAllowedNum;
	}
	__tagFormatInfo& operator=(const __tagFormatInfo &fi)
	{
		if (&fi == this)
			return *this;
		nPlaceFlag = fi.nPlaceFlag;
		nDecimalNum = fi.nDecimalNum;
		nValidNum = fi.nValidNum;
		nAllowedNum = fi.nAllowedNum;
		return *this;
	}
} FormatInfo;

// ע��ѡ��
typedef struct __tagAnnotationOption
{
	float fElbow;				// �������ⳤ��
	float fArrowLength;			// ��ͷ����
	float fArrowWidth;			// ��ͷ���
	float fDimExLen;			// �ߴ�������쳤��

	// ����Ϊ�ı�����ض���
	float fCharSpace;			// �ַ���࣬Ĭ��Ϊ2h/14

	__tagAnnotationOption() 
	{
		fElbow = 4.f;
		fArrowLength = 4.f;
		fArrowWidth = 1.f;
		fDimExLen = 2.f;
		fCharSpace = 0.142857f;
	}
	__tagAnnotationOption(const __tagAnnotationOption &opt)
	{
		fElbow = opt.fElbow;
		fArrowLength = opt.fArrowLength;
		fArrowWidth = opt.fArrowWidth;
		fDimExLen = opt.fDimExLen;
		fCharSpace = opt.fCharSpace;
	}
	__tagAnnotationOption &operator= (const __tagAnnotationOption &opt) 
	{
		if (&opt == this)
			return *this;
		fElbow = opt.fElbow;
		fArrowLength = opt.fArrowLength;
		fArrowWidth = opt.fArrowWidth;
		fDimExLen = opt.fDimExLen;
		fCharSpace = opt.fCharSpace;
		return *this;
	}
} AnnotationOption;

// �ı���ʽ
typedef struct __tagTextStyle
{
	CSVWString strFont;			// ����
	float	fHeight;			// �߶�ֵ 
	float	fWidth;				// ��ȱ�ֵ
	float	fThickness;			// �ı����ߺ��
	float	fSlant;				// ��б�Ƕȣ���˳ʱ�뷽��
	IKS_BOOL	bUnderline;			// ���»���
	int		nHorJust;			// ˮƽ
	int		nVerJust;			// ��ֱ
	IKS_BOOL	bMirror;			// ����
	IKS_BOOL	bReadonly;			// ֻ������
	float	fLineSpace;			// �м�����ӣ��м��=�и�*�м�����ӣ�

	__tagTextStyle() 
	{
		strFont = L"simfang";
		fHeight = 3.5f;
		fWidth = 0.67f; 
		fThickness = 0.0f;
		fSlant = 0.00f; 
		bUnderline = FALSE;
		nHorJust = THJT_CENTER;
		nVerJust = TVJT_MIDDLE;
		bMirror = FALSE;
		bReadonly = FALSE;
		fLineSpace = 0.2f;
	}
	__tagTextStyle(const __tagTextStyle &textStyle)
	{
		strFont = textStyle.strFont;
		fHeight = textStyle.fHeight;
		fWidth = textStyle.fWidth; 
		fThickness = textStyle.fThickness; 
		fSlant = textStyle.fSlant; 
		bUnderline = textStyle.bUnderline;
		nHorJust = textStyle.nHorJust;
		nVerJust = textStyle.nVerJust;
		bMirror = textStyle.bMirror;
		bReadonly = textStyle.bReadonly;
	}
	IKS_BOOL operator == (const __tagTextStyle &textStyle) const
	{
		if (!ISEQUAL(fHeight, textStyle.fHeight))
			return FALSE;

		if (!ISEQUAL(fWidth, textStyle.fWidth))
			return FALSE;

		return TRUE;
	}

	IKS_BOOL operator != (const __tagTextStyle &textStyle) const
	{
		return !(*this == textStyle);
	}

	__tagTextStyle &operator= (const __tagTextStyle &textStyle) 
	{
		if (&textStyle == this)
			return *this;
		strFont = textStyle.strFont;
		fHeight = textStyle.fHeight;
		fWidth = textStyle.fWidth; 
		fThickness = textStyle.fThickness; 
		fSlant = textStyle.fSlant; 
		bUnderline = textStyle.bUnderline;
		nHorJust = textStyle.nHorJust;
		nVerJust = textStyle.nVerJust;
		bMirror = textStyle.bMirror;
		bReadonly = textStyle.bReadonly;
		return *this;
	}
} TextStyle;

// ע����Ϣ
typedef struct __tagNoteInfo
{
	BPBASEFLOAT3 attachPos;					// ����λ��
	std::vector<BPBASEFLOAT3> arrLeaderPos;	// ����λ��
	CSVWString	strText;					// ע��
	CSVWString	strText2;					// ע��2
	TextStyle textStyle;					// �ı���ʽ
	int nArrowStyle;						// ��ͷ
	int nLeaderStyle;						// ���߷�ʽ
	float fElbowLength;						// �������䳤��
	int nTextDir;							// �ı�����
	CSVWString strReserve;					// ��������

	__tagNoteInfo() 
	{
		attachPos.x = 0.f;
		attachPos.y = 0.f;
		attachPos.z = 0.f;
		strText = L"";
		strText2 = L"";
		textStyle.nHorJust = THJT_LEFT;
		nArrowStyle = AS_ARROWHEAD;
		nLeaderStyle = LS_ISO;
		fElbowLength = 0.f;
		nTextDir = -1;
		strReserve = L"";
	}
	__tagNoteInfo(const __tagNoteInfo &noteInfo)
	{
		attachPos = noteInfo.attachPos;
		arrLeaderPos = noteInfo.arrLeaderPos;
		strText = noteInfo.strText;
		strText2 = noteInfo.strText2;
		textStyle = noteInfo.textStyle;
		nArrowStyle = noteInfo.nArrowStyle;
		nLeaderStyle = noteInfo.nLeaderStyle;
		fElbowLength = noteInfo.fElbowLength;
		nTextDir = noteInfo.nTextDir;
		strReserve = noteInfo.strReserve;
	}
	__tagNoteInfo &operator= (const __tagNoteInfo &noteInfo) 
	{
		if (&noteInfo == this)
			return *this;
		attachPos = noteInfo.attachPos;
		arrLeaderPos = noteInfo.arrLeaderPos;
		strText = noteInfo.strText;
		strText2 = noteInfo.strText2;
		textStyle = noteInfo.textStyle;
		nArrowStyle = noteInfo.nArrowStyle;
		nLeaderStyle = noteInfo.nLeaderStyle;
		fElbowLength = noteInfo.fElbowLength;
		nTextDir = noteInfo.nTextDir;
		strReserve = noteInfo.strReserve;
		return *this;
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		attachPos = BPTOCBPFLOAT3(attachPos) * float(dLenRatio);
		for (IKS_UINT i=0; i<arrLeaderPos.size(); i++)
			arrLeaderPos[i] = BPTOCBPFLOAT3(arrLeaderPos[i]) * float(dLenRatio);
		fElbowLength *= float(dLenRatio);
		textStyle.fHeight *= float(dLenRatio);
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		dLenRatio;
	}
} NoteInfo;

// ����Ҫ����Ϣ
typedef struct __tagTechniqueRequirementInfo
{
	NoteInfo titleInfo;			// ������Ϣ
	NoteInfo contentInfo;		// ������Ϣ
	IKS_BOOL bTitleLeft;			// ���������
	CSVWString strReserve;		// ��������

	__tagTechniqueRequirementInfo()
	{
		titleInfo.strText = SVSTR_TECHREQ;
		titleInfo.textStyle.fHeight = 5.0;
		titleInfo.textStyle.nHorJust = 1;
		titleInfo.textStyle.nVerJust = 1;
		contentInfo.textStyle.nHorJust = 0;
		contentInfo.textStyle.nVerJust = 1;
		bTitleLeft = FALSE;
		strReserve = L"";
	}
	__tagTechniqueRequirementInfo(const __tagTechniqueRequirementInfo &trInfo)
	{
		titleInfo = trInfo.titleInfo;
		contentInfo = trInfo.contentInfo;
		bTitleLeft = trInfo.bTitleLeft;
		strReserve = trInfo.strReserve;
	}
	__tagTechniqueRequirementInfo &operator= (const __tagTechniqueRequirementInfo &trInfo) 
	{
		if (&trInfo == this)
			return *this;
		titleInfo = trInfo.titleInfo;
		contentInfo = trInfo.contentInfo;
		bTitleLeft = trInfo.bTitleLeft;
		strReserve = trInfo.strReserve;
		return *this;
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		titleInfo.UpdatePosForLenUnit(dLenRatio);
		contentInfo.UpdatePosForLenUnit(dLenRatio);
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		titleInfo.UpdateTextForLenUnit(dLenRatio);
		contentInfo.UpdateTextForLenUnit(dLenRatio);
	}
} TechRequInfo; 

// ��׼������Ϣ
typedef struct __tagDatumBaseInfo
{
	int nGBType;					// ��������
	int nAttachType;				// ���÷�ʽ���ο�SDSymbolAttachTypeö��ֵ
	CSVWString strName;				// ��׼�������ƣ�һ��Ϊ: A B C ...
	double dAngle;					// ���ýǶ�
	int nLengthType;				// �������ͣ��ο�DATUMLENGTHTYPEö����
	IKS_BOOL bTextAngleFixed;			// �Ƿ�̶��ı�����
	IKS_BOOL bIsFlip;					// �Ƿ���;��ֻ����nAttachTypeΪSATYPE_NORM_ITEMʱ��Ч��
	CSVWString strReserve;			// ��������

	__tagDatumBaseInfo()
	{
		nGBType = GB_CIR;
		nAttachType = SATYPE_NORM_ITEM;
		strName = L"A";
		dAngle = 0.0;
		nLengthType = DATUMLT_2;
		bTextAngleFixed = TRUE;
		bIsFlip = FALSE;
		strReserve = L"";
	}
	__tagDatumBaseInfo(const __tagDatumBaseInfo &info)
	{
		nGBType = info.nGBType;	
		strName = info.strName;
		nAttachType = info.nAttachType;
		dAngle = info.dAngle;
		nLengthType = info.nLengthType;
		bTextAngleFixed = info.bTextAngleFixed;
		bIsFlip = info.bIsFlip;
		strReserve = info.strReserve;
	}
	__tagDatumBaseInfo& operator=(const __tagDatumBaseInfo& info){
		if (&info == this)
			return *this;
		nGBType = info.nGBType;	
		strName = info.strName;
		nAttachType = info.nAttachType;
		dAngle = info.dAngle;
		nLengthType = info.nLengthType;
		bTextAngleFixed = info.bTextAngleFixed;
		bIsFlip = info.bIsFlip;
		strReserve = info.strReserve;
		return *this;
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		dLenRatio;
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		dLenRatio;
	}
} DatumBaseInfo;

// ���ι��������Ϣ
typedef struct __tagGtolBaseInfo
{
	int		nSymbolType;						// ������������
	double	dValue;								// ����ֵ
	CSVWString	strPrefix;						// ǰ׺
	CSVWString	strSuffix1;						// ��׺1
	CSVWString	strSuffix2;						// ��׺2
	IKS_BOOL	bAllAround;							// ȫ�ܷ���
	CSVWString	strNoteTop;						// �Ϸ���ע
	CSVWString	strNoteBack;					// �󷽸�ע
	CSVWString	strDatumName11;					// ��һ��׼����
	CSVWString	strDatumMatCond11;				// ��һ��׼����ѡȡ��������
	CSVWString	strDatumName12;					// ��һ���ϻ�׼����
	CSVWString	strDatumMatCond12;				// ��һ���ϻ�׼����ѡȡ��������
	CSVWString	strDatumName21;					// �ڶ���׼����
	CSVWString	strDatumMatCond21;				// �ڶ���׼����ѡȡ��������
	CSVWString	strDatumName22;					// �ڶ����ϻ�׼����
	CSVWString	strDatumMatCond22;				// �ڶ����ϻ�׼����ѡȡ��������
	CSVWString	strDatumName31;					// ������׼����
	CSVWString	strDatumMatCond31;				// ������׼����ѡȡ��������
	CSVWString	strDatumName32;					// �������ϻ�׼����
	CSVWString	strDatumMatCond32;				// �������ϻ�׼����ѡȡ��������
	CSVWString strReserve;						// ��������

	__tagGtolBaseInfo()
	{
		nSymbolType = GTOL_UNKNOWN;
		dValue = 0.0;
		strPrefix = L"";
		strSuffix1 = L"";
		strSuffix2 = L"";
		bAllAround = FALSE;
		strNoteTop = L"";
		strNoteBack = L"";
		strDatumName11 = L"";
		strDatumMatCond11 = L"";
		strDatumName12 = L"";
		strDatumMatCond12 = L"";
		strDatumName21 = L"";
		strDatumMatCond21 = L"";
		strDatumName22 = L"";
		strDatumMatCond22 = L"";
		strDatumName31 = L"";
		strDatumMatCond31 = L"";
		strDatumName32 = L"";
		strDatumMatCond32 = L"";
		strReserve = L"";
	}
	__tagGtolBaseInfo(const __tagGtolBaseInfo &info)
	{
		nSymbolType = info.nSymbolType;
		dValue = info.dValue;
		strPrefix = info.strPrefix;
		strSuffix1 = info.strSuffix1;
		strSuffix2 = info.strSuffix2;
		bAllAround = info.bAllAround;
		strNoteTop = info.strNoteTop;
		strNoteBack = info.strNoteBack;
		strDatumName11 = info.strDatumName11;
		strDatumMatCond11 = info.strDatumMatCond11;
		strDatumName12 = info.strDatumName12;
		strDatumMatCond12 = info.strDatumMatCond12;
		strDatumName21 = info.strDatumName21;
		strDatumMatCond21 = info.strDatumMatCond21;
		strDatumName22 = info.strDatumName22;
		strDatumMatCond22 = info.strDatumMatCond22;
		strDatumName31 = info.strDatumName31;
		strDatumMatCond31 = info.strDatumMatCond31;
		strDatumName32 = info.strDatumName32;
		strDatumMatCond32 = info.strDatumMatCond32;
		strReserve = info.strReserve;
	}
	__tagGtolBaseInfo& operator=(const __tagGtolBaseInfo& info){
		if (&info == this)
			return *this;
		nSymbolType = info.nSymbolType;
		dValue = info.dValue;
		strPrefix = info.strPrefix;
		strSuffix1 = info.strSuffix1;
		strSuffix2 = info.strSuffix2;
		bAllAround = info.bAllAround;
		strNoteTop = info.strNoteTop;
		strNoteBack = info.strNoteBack;
		strDatumName11 = info.strDatumName11;
		strDatumMatCond11 = info.strDatumMatCond11;
		strDatumName12 = info.strDatumName12;
		strDatumMatCond12 = info.strDatumMatCond12;
		strDatumName21 = info.strDatumName21;
		strDatumMatCond21 = info.strDatumMatCond21;
		strDatumName22 = info.strDatumName22;
		strDatumMatCond22 = info.strDatumMatCond22;
		strDatumName31 = info.strDatumName31;
		strDatumMatCond31 = info.strDatumMatCond31;
		strDatumName32 = info.strDatumName32;
		strDatumMatCond32 = info.strDatumMatCond32;
		strReserve = info.strReserve;
		return *this;
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		dLenRatio;
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		dValue *= dLenRatio;
	}
} GtolBaseInfo;

// ���ι�����Ϣ
typedef struct __tagGtolInfo
{
	BPBASEFLOAT3 attachPos;						// ����λ��
	std::vector<BPBASEFLOAT3> arrLeaderPos;		// ����λ��
	std::vector<GtolBaseInfo> arrBaseInfo;		// ������Ϣ
	std::vector<DatumBaseInfo> arrDatumInfo;	// ��׼��Ϣ
	int		nPlacementType;						// ���÷�ʽ
	int		nLeaderType;						// ���߷�ʽ
	TextStyle textStyle;						// �ı���ʽ
	float fElbowLength;							// �������䳤��
	int nTextDir;								// �ı�����
	CSVWString strReserve;						// ��������

	__tagGtolInfo()
	{
		nPlacementType = GPTYPE_NORMLEADER;
		nLeaderType = AS_ARROWHEAD;
		fElbowLength = 0.f;
		nTextDir = -1;
		strReserve = L"";
	}
	__tagGtolInfo(const __tagGtolInfo &info)
	{
		attachPos = info.attachPos;
		arrLeaderPos = info.arrLeaderPos;
		arrBaseInfo = info.arrBaseInfo;
		arrDatumInfo = info.arrDatumInfo;
		nPlacementType = info.nPlacementType;
		nLeaderType = info.nLeaderType;
		textStyle = info.textStyle;
		fElbowLength = info.fElbowLength;
		nTextDir = info.nTextDir;
		strReserve = info.strReserve;
	}
	__tagGtolInfo& operator=(const __tagGtolInfo& info){
		if (&info == this)
			return *this;
		attachPos = info.attachPos;
		arrLeaderPos = info.arrLeaderPos;
		arrBaseInfo = info.arrBaseInfo;
		arrDatumInfo = info.arrDatumInfo;
		nPlacementType = info.nPlacementType;
		nLeaderType = info.nLeaderType;
		textStyle = info.textStyle;
		fElbowLength = info.fElbowLength;
		nTextDir = info.nTextDir;
		strReserve = info.strReserve;
		return *this;
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		for (IKS_UINT i=0; i<arrLeaderPos.size(); i++)
			arrLeaderPos[i] = BPTOCBPFLOAT3(arrLeaderPos[i]) * float(dLenRatio);
		attachPos = BPTOCBPFLOAT3(attachPos) * float(dLenRatio);
		fElbowLength *= float(dLenRatio);
		textStyle.fHeight *= float(dLenRatio);
		for (IKS_UINT i=0; i<arrBaseInfo.size(); i++)
			arrBaseInfo[i].UpdatePosForLenUnit(dLenRatio);
		for (IKS_UINT i=0; i<arrDatumInfo.size(); i++)
			arrDatumInfo[i].UpdatePosForLenUnit(dLenRatio);
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		for (IKS_UINT i=0; i<arrBaseInfo.size(); i++)
			arrBaseInfo[i].UpdateTextForLenUnit(dLenRatio);
		for (IKS_UINT i=0; i<arrDatumInfo.size(); i++)
			arrDatumInfo[i].UpdateTextForLenUnit(dLenRatio);
	}
} GtolInfo;

// ����ע����Ϣ
typedef struct __tagSymbolNoteInfo
{
	BPBASEFLOAT2 location;						// λ��
	TextStyle textStyle;						// �ı���ʽ
	CSVWString strContent;						// �ı�����

	__tagSymbolNoteInfo()
	{
		location.x = 0.f;
		location.y = 0.f;
	}
	__tagSymbolNoteInfo(const __tagSymbolNoteInfo &info)
	{
		location = info.location;
		textStyle = info.textStyle;
		strContent = info.strContent;
	}
	__tagSymbolNoteInfo& operator=(const __tagSymbolNoteInfo& info)
	{
		if (&info == this)
			return *this;
		location = info.location;
		textStyle = info.textStyle;
		strContent = info.strContent;
		return *this;
	}
} SymbolNoteInfo;

// ����������Ϣ
typedef struct __tagSymbolProperty
{
	IKS_BOOL bTextFixed;			// �̶��ı�
	float fAngle;				// ��ת�Ƕ�
	float fHeight;				// �߶�

	__tagSymbolProperty()
	{
		bTextFixed = FALSE;
		fAngle = 0.f;
		fHeight = 0.f;
	}
	__tagSymbolProperty(const __tagSymbolProperty &info)
	{
		bTextFixed = info.bTextFixed;
		fAngle = info.fAngle;
		fHeight = info.fHeight;
	}
	__tagSymbolProperty& operator=(const __tagSymbolProperty& info)
	{
		if (&info == this)
			return *this;
		bTextFixed = info.bTextFixed;
		fAngle = info.fAngle;
		fHeight = info.fHeight;
		return *this;
	}
} SymbolProperty;

// ������Ϣ
typedef struct __tagSymbolInfo
{
	int nType;									// ��������
	BPBASEFLOAT3 attachPos;						// ����λ��
	std::vector<BPBASEFLOAT3> arrLeaderPos;		// ����λ��
	float fRadialLeaderRadius;					// �������ߵİ뾶
	std::vector<SymbolNoteInfo> arrText;		// �ı�
	std::vector<SVCurve2D> arrGeom;				// ����
	SymbolProperty prop;						// ��������
	CSVWString strReserve;						// ��������

	__tagSymbolInfo()
	{
		nType = AT_SYMBOL;
		fRadialLeaderRadius = 0.f;
		strReserve = L"";
	}
	__tagSymbolInfo(const __tagSymbolInfo &info)
	{
		nType = info.nType;
		attachPos = info.attachPos;
		arrLeaderPos = info.arrLeaderPos;
		fRadialLeaderRadius = info.fRadialLeaderRadius;
		arrText = info.arrText;
		arrGeom = info.arrGeom;
		prop = info.prop;
		strReserve = info.strReserve;
	}
	__tagSymbolInfo& operator=(const __tagSymbolInfo& info){
		if (&info == this)
			return *this;
		nType = info.nType;
		attachPos = info.attachPos;
		arrLeaderPos = info.arrLeaderPos;
		fRadialLeaderRadius = info.fRadialLeaderRadius;
		arrText = info.arrText;
		arrGeom = info.arrGeom;
		prop = info.prop;
		strReserve = info.strReserve;
		return *this;
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		for (IKS_UINT i=0; i<arrLeaderPos.size(); i++)
			arrLeaderPos[i] = BPTOCBPFLOAT3(arrLeaderPos[i]) * float(dLenRatio);
		attachPos = BPTOCBPFLOAT3(attachPos) * float(dLenRatio);
		for (IKS_UINT i=0; i<arrText.size(); i++)
		{
			arrText[i].location = BPTOCBPFLOAT2(arrText[i].location) * float(dLenRatio);
			arrText[i].textStyle.fHeight = arrText[i].textStyle.fHeight * float(dLenRatio);
		}
		for (IKS_UINT i=0; i<arrGeom.size(); i++)
		{
			switch (arrGeom[i].nType)
			{
			case BP2DCURVETYPE_LINE:
				arrGeom[i].pLine->start = BPTOCBPFLOAT2(arrGeom[i].pLine->start) * float(dLenRatio);
				arrGeom[i].pLine->end = BPTOCBPFLOAT2(arrGeom[i].pLine->end) * float(dLenRatio);
				break;
			case BP2DCURVETYPE_ARC:
				arrGeom[i].pArc->center = BPTOCBPFLOAT2(arrGeom[i].pArc->center) * float(dLenRatio);
				arrGeom[i].pArc->fRadius = arrGeom[i].pArc->fRadius * float(dLenRatio);
				break;
			case BP2DCURVETYPE_POLYGON:
				{
					for (IKS_UINT j=0; j<arrGeom[i].pPolygon->arrPoints.size(); j++)
						arrGeom[i].pPolygon->arrPoints[j] = BPTOCBPFLOAT2(arrGeom[i].pPolygon->arrPoints[j]) * float(dLenRatio);
				}
				break;
			default:
				break;
			}
		}
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		dLenRatio;
	}
} SymbolInfo;

// �ߴ���Ϣ
typedef struct __tagDimensionInfomation
{
	BPBASEFLOAT3 attachPos[10];			// ����λ��
	BPBASEFLOAT3 textPos;				// �ߴ��ı�λ��
// 	IKS_BOOL	bUseTTL;					// ʹ��ģ�͹����
	IKS_BOOL	bUseOverrideVal;			// ʹ������ߴ�
	int		nDimType;					// �ߴ����� 
	int		nDisplayType;				// ��ʾ��ʽ
	double	dBaseDimValue;				// �����ߴ�
	double	dOverrideValue;				// ����ߴ�
	double	dUpperTol;					// ��ƫ��
	double	dLowerTol;					// ��ƫ��
	double	dMaxCl;						// ����϶
	double	dMinCl;						// ��С��϶
	CSVWString strTolSymbol;			// �������
	CSVWString strPrefix;				// ǰ׺
	CSVWString strSurffix;				// ��׺
	CSVWString strNote;					// ��ע
	CSVWString strOverride;				// ����ı�
	FormatInfo	format;					// ��ʽ����Ϣ
	TextStyle textStyle;				// �ı���ʽ
	std::vector<GtolBaseInfo> arrGtolInfo;		// ��λ������Ϣ
	std::vector<DatumBaseInfo> arrDatumInfo;	// ��׼��Ϣ
	CSVWString strReserve;				// ��������

	__tagDimensionInfomation() 
	{
		memset(attachPos, 0, sizeof(BPBASEFLOAT3)*10);
		textPos.x = 0.f;
		textPos.y = 0.f;
		textPos.z = 0.f;
// 		bUseTTL = FALSE;
		bUseOverrideVal = FALSE;
		format.nPlaceFlag = DPF_DECIMAL;
		format.nDecimalNum = -1;
		format.nValidNum = -1;
		format.nAllowedNum = -1;
		nDimType = -1;
		nDisplayType = OUTYPE_SYMBOL; 
		dBaseDimValue = 0.0;
		dOverrideValue = 0.0;
		dUpperTol = 0.0; 
		dLowerTol = 0.0; 
		dMaxCl = 0.0;
		dMinCl = 0.0;
		strTolSymbol = L"";
		strPrefix = L"";
		strSurffix = L"";
		strNote = L"";
		strOverride = L"";
		strReserve = L"";
	}
	__tagDimensionInfomation(const __tagDimensionInfomation &di)
	{
		for (int i=0; i<10; i++)
			attachPos[i] = di.attachPos[i];
		textPos = di.textPos;
// 		bUseTTL = di.bUseTTL;
		bUseOverrideVal = di.bUseOverrideVal;
		nDimType = di.nDimType;
		nDisplayType = di.nDisplayType; 
		dBaseDimValue = di.dBaseDimValue; 
		dOverrideValue = di.dOverrideValue;
		dUpperTol = di.dUpperTol;
		dLowerTol = di.dLowerTol; 
		dMaxCl = di.dMaxCl;
		dMinCl = di.dMinCl;
		strTolSymbol = di.strTolSymbol;
		strPrefix = di.strPrefix;
		strSurffix = di.strSurffix;
		strNote = di.strNote;
		strOverride = di.strOverride;
		format = di.format;
		textStyle = di.textStyle;
		arrGtolInfo = di.arrGtolInfo;
		arrDatumInfo = di.arrDatumInfo;
		strReserve = di.strReserve;
	}

	__tagDimensionInfomation& operator=(const __tagDimensionInfomation &di) 
	{
		if (this == &di)
			return *this;
		for (int i=0; i<10; i++)
			attachPos[i] = di.attachPos[i];
		textPos = di.textPos;
// 		bUseTTL = di.bUseTTL;
		bUseOverrideVal = di.bUseOverrideVal;
		nDimType = di.nDimType;
		nDisplayType = di.nDisplayType; 
		dBaseDimValue = di.dBaseDimValue; 
		dOverrideValue = di.dOverrideValue;
		dUpperTol = di.dUpperTol;
		dLowerTol = di.dLowerTol; 
		dMaxCl = di.dMaxCl;
		dMinCl = di.dMinCl;
		strTolSymbol = di.strTolSymbol;
		strPrefix = di.strPrefix;
		strSurffix = di.strSurffix;
		strNote = di.strNote;
		strOverride = di.strOverride;
		format = di.format;
		textStyle = di.textStyle;
		arrGtolInfo = di.arrGtolInfo;
		arrDatumInfo = di.arrDatumInfo;
		strReserve = di.strReserve;
		return *this;
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		for (IKS_UINT i=0; i<10; i++)
			attachPos[i] = BPTOCBPFLOAT3(attachPos[i]) * float(dLenRatio);
		textPos = BPTOCBPFLOAT3(textPos) * float(dLenRatio);
		textStyle.fHeight *= float(dLenRatio);
		for (IKS_UINT i=0; i<arrGtolInfo.size(); i++)
			arrGtolInfo[i].UpdatePosForLenUnit(dLenRatio);
		for (IKS_UINT i=0; i<arrDatumInfo.size(); i++)
			arrDatumInfo[i].UpdatePosForLenUnit(dLenRatio);
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		dBaseDimValue *= dLenRatio;
		dOverrideValue *= dLenRatio;
		dUpperTol *= dLenRatio;
		dLowerTol *= dLenRatio;
		dMaxCl *= dLenRatio;
		dMinCl *= dLenRatio;
		for (IKS_UINT i=0; i<arrGtolInfo.size(); i++)
			arrGtolInfo[i].UpdateTextForLenUnit(dLenRatio);
		for (IKS_UINT i=0; i<arrDatumInfo.size(); i++)
			arrDatumInfo[i].UpdateTextForLenUnit(dLenRatio);
	}
} DimInfo;

// ��׼��Ϣ
typedef struct __tagDatumInfo
{
	BPBASEFLOAT3 attachPos;			// ����λ��
	DatumBaseInfo baseInfo;			// ������Ϣ
	TextStyle defaultTextStyle;		// ȱʡ�ı���ʽ
	CSVWString strReserve;			// ��������

	__tagDatumInfo()
	{
		memset(&attachPos, 0, sizeof(BPBASEFLOAT3));
		strReserve = L"";
	}
	__tagDatumInfo(const __tagDatumInfo &info)
	{
		attachPos = info.attachPos;
		baseInfo = info.baseInfo;
		strReserve = info.strReserve;
		defaultTextStyle = info.defaultTextStyle;
	}
	__tagDatumInfo& operator=(const __tagDatumInfo& info){
		if (&info == this)
			return *this;
		attachPos = info.attachPos;
		baseInfo = info.baseInfo;
		strReserve = info.strReserve;
		defaultTextStyle = info.defaultTextStyle;
		return *this;
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		attachPos = BPTOCBPFLOAT3(attachPos) * float(dLenRatio);
		defaultTextStyle.fHeight *= float(dLenRatio);
		baseInfo.UpdatePosForLenUnit(dLenRatio);
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		dLenRatio;
		baseInfo.UpdateTextForLenUnit(dLenRatio);
	}
} DatumInfo;

// ����ֲڶ���Ϣ
typedef struct __tagSurfFinishInfo
{
	int nSymbolType;			// �����������ͣ� �ο�SurfFinishSymbolTypeö��ֵ
	int nTextureType;			// ���� �ο�SurfFinishTexturetypeö��ֵ
	int nAttachType;			// ���÷�ʽ���ο�SDSymbolAttachTypeö��ֵ
	CSVWString strSurfText1;
	CSVWString strSurfText2;
	CSVWString strSurfText3;
	CSVWString strOther;
	CSVWString strSurfMin;
	CSVWString strSurfMax;
	IKS_BOOL bSameReq;
	double dAngle;
	double dTextHeight;
	IKS_BOOL bIsFlip;				// �Ƿ���;��ֻ����nAttachTypeΪSATYPE_NORM_ITEMʱ��Ч��
	TextStyle defaultTextStyle;	// ȱʡ�ı���ʽ

	__tagSurfFinishInfo()
	{
		nSymbolType = SURF_SYMBOL1;
		nTextureType = SURF_TEXTURE_CLEAR;
		nAttachType = SATYPE_NORM_ITEM;
		strSurfText1 = L"";
		strSurfText2 = L"";
		strSurfText3 = L"";
		strOther = L"";
		strSurfMin = L"";
		strSurfMax = L"";
		bSameReq = FALSE;
		dAngle = 0;
		dTextHeight = 3.5;
		bIsFlip = FALSE;
	}
	__tagSurfFinishInfo(const __tagSurfFinishInfo &info)
	{
		nSymbolType = info.nSymbolType;	
		nTextureType = info.nTextureType;
		nAttachType = info.nAttachType;
		strSurfText1 = info.strSurfText1;
		strSurfText2 = info.strSurfText2;
		strSurfText3 = info.strSurfText3;
		strOther = info.strOther;
		strSurfMin = info.strSurfMin;
		strSurfMax = info.strSurfMax;
		bSameReq = info.bSameReq;
		dAngle = info.dAngle;
		dTextHeight = info.dTextHeight;
		bIsFlip = info.bIsFlip;
		defaultTextStyle = info.defaultTextStyle;
	}
	__tagSurfFinishInfo& operator=(const __tagSurfFinishInfo& info){
		if (this == &info)
			return *this;
		nSymbolType = info.nSymbolType;	
		nTextureType = info.nTextureType;
		nAttachType = info.nAttachType;
		strSurfText1 = info.strSurfText1;
		strSurfText2 = info.strSurfText2;
		strSurfText3 = info.strSurfText3;
		strOther = info.strOther;
		strSurfMin = info.strSurfMin;
		strSurfMax = info.strSurfMax;
		bSameReq = info.bSameReq;
		dAngle = info.dAngle;
		dTextHeight = info.dTextHeight;
		bIsFlip = info.bIsFlip;
		defaultTextStyle = info.defaultTextStyle;
		return *this;
	}
} SurfFinishInfo;

// ע��ƽ��
typedef struct __tagSVAnnotationPlane
{
	BPBASEFLOAT3 origin;
	BPBASEFLOAT3 x;
	BPBASEFLOAT3 y;
	BPBASEFLOAT3 z;

	__tagSVAnnotationPlane() 
	{
		memset(&origin, 0, sizeof(BPBASEFLOAT3));
		memset(&x, 0, sizeof(BPBASEFLOAT3));
		memset(&y, 0, sizeof(BPBASEFLOAT3));
		memset(&z, 0, sizeof(BPBASEFLOAT3));
		x.x = y.y = z.z = 1.0f;
	}
	__tagSVAnnotationPlane(const __tagSVAnnotationPlane &api)
	{
		origin = api.origin;
		x = api.x;
		y = api.y;
		z = api.z;
	}
	__tagSVAnnotationPlane& operator=(const __tagSVAnnotationPlane &api) 
	{
		if (this == &api)
			return *this;
		origin = api.origin;
		x = api.x;
		y = api.y;
		z = api.z;
		return *this;
	}
	IKS_BOOL operator == ( const __tagSVAnnotationPlane &api) const
	{
		if (!ISEQUAL(origin.x, api.origin.x))
			return FALSE;
		if (!ISEQUAL(origin.y, api.origin.y))
			return FALSE;
		if (!ISEQUAL(origin.z, api.origin.z))
			return FALSE;
		if (!ISEQUAL(x.x, api.x.x))
			return FALSE;
		if (!ISEQUAL(x.y, api.x.y))
			return FALSE;
		if (!ISEQUAL(x.z, api.x.z))
			return FALSE;
		if (!ISEQUAL(y.x, api.y.x))
			return FALSE;
		if (!ISEQUAL(y.y, api.y.y))
			return FALSE;
		if (!ISEQUAL(y.z, api.y.z))
			return FALSE;
		if (!ISEQUAL(z.x, api.z.x))
			return FALSE;
		if (!ISEQUAL(z.y, api.z.y))
			return FALSE;
		if (!ISEQUAL(z.z, api.z.z))
			return FALSE;
		return TRUE;
	}
	IKS_BOOL operator != ( const __tagSVAnnotationPlane &api) const
	{
		return (!((*this) == api));
	}
} SVAnnotationPlane;

// ��ע��Ⱦ����
typedef struct __tagSVAnnotRenderProp
{
	IKS_BOOL bVisible;	// �Ƿ�ɼ�
	IKS_BOOL bIsFront;	// �Ƿ�ǰ����ʾ
	IKS_BOOL bIsScreenAnnot;	// �Ƿ�Ϊ��Ļ��ע����Ϊ��Ļ��ע,��"�Ƿ�ǰ����ʾ"�����壩

	__tagSVAnnotRenderProp()
	{
		bVisible = TRUE;
		bIsFront = FALSE;
		bIsScreenAnnot = FALSE;
	}
	__tagSVAnnotRenderProp(const __tagSVAnnotRenderProp &prop)
	{
		bVisible = prop.bVisible;
		bIsFront = prop.bIsFront;
		bIsScreenAnnot = prop.bIsScreenAnnot;
	}
	__tagSVAnnotRenderProp& operator=(const __tagSVAnnotRenderProp &prop) 
	{
		if (this == &prop)
			return *this;
		bVisible = prop.bVisible;
		bIsFront = prop.bIsFront;
		bIsScreenAnnot = prop.bIsScreenAnnot;
		return *this;
	}
	IKS_BOOL operator == ( const __tagSVAnnotRenderProp &prop) const
	{
		if (bVisible != prop.bVisible)
			return FALSE;
		if (bIsFront != prop.bIsFront)
			return FALSE;
		if (bIsScreenAnnot != prop.bIsScreenAnnot)
			return FALSE;
		return TRUE;
	}
	IKS_BOOL operator != ( const __tagSVAnnotRenderProp &prop) const
	{
		return (!((*this) == prop));
	}
} SVAnnotRenderProp;

// ��ע
typedef struct __tagSVAnnotation
{
	IKS_UINT uID;						// ��עID
	CSVWString strOriAnnotID;		// ��עԭʼID(��CAD����ʱ�ı�עID,����ԭCAD��ע���µ�ǰ��ע)
	int nType;						// ��ע����,�ο�ö����AnnotationType
	CSVWString strName;				// ����
	SVAnnotationPlane annoPlaneLocal;	// ��ע�ľֲ�ע��ƽ��
	SVAnnotRenderProp annoRenderProp;	// ��ע����Ⱦ����
	IKS_UINT uMtlID;					// ����ID

	union{
		NoteInfo *pNote;				// ע�ͼ�
		DimInfo *pDim;					// �ߴ缯
		DatumInfo *pDatum;				// ��׼��
		GtolInfo *pGTol;				// ��λ���
		TechRequInfo *pTech;			// ����Ҫ��
		SymbolInfo *pSymbol;			// ����
		SVSectionPlaneInfo* pSecPlane;	// ����ƽ��
	};

	__tagSVAnnotation() 
	{
		uID = IKS_UINT(-1);
		strOriAnnotID = L"";
		nType = AT_UNKNOWN;
		strName = L"";
		uMtlID = INVALID_ID;
		pNote = NULL;
	}
	__tagSVAnnotation(const __tagSVAnnotation &anno)
	{
		uID = anno.uID;
		strOriAnnotID = anno.strOriAnnotID;
// 		nType = anno.nType;
		strName = anno.strName;
		annoPlaneLocal = anno.annoPlaneLocal;
		annoRenderProp = anno.annoRenderProp;
		uMtlID = anno.uMtlID;
		nType = AT_UNKNOWN;
		pNote = NULL;
		UpdateAnnotData(anno);
	}
	__tagSVAnnotation& operator=(const __tagSVAnnotation &anno) 
	{
		if (this == &anno)
			return *this;
		uID = anno.uID;
		strOriAnnotID = anno.strOriAnnotID;
// 		nType = anno.nType;
		strName = anno.strName;
		annoPlaneLocal = anno.annoPlaneLocal;
		annoRenderProp = anno.annoRenderProp;
		uMtlID = anno.uMtlID;
		UpdateAnnotData(anno);
		return *this;
	}
	~__tagSVAnnotation()
	{
		ClearAllAnnotData();
	}
// 	IKS_BOOL IsEqual(const __tagSVAnnotation &annot) const
// 	{
// 		if (uID != annot.uID)
// 			return FALSE;
// 		if (strOriAnnotID != annot.strOriAnnotID)
// 			return FALSE;
// 		if (nType != annot.nType)
// 			return FALSE;
// 		if (strName != annot.strName)
// 			return FALSE;
// 		if (annoPlaneLocal != annot.annoPlaneLocal)
// 			return FALSE;
// 		if (annoRenderProp != annot.annoRenderProp)
// 			return FALSE;
// 		if (uMtlID != annot.uMtlID)
// 			return FALSE;
// 		return TRUE;
// 	}
	void ClearAllAnnotData()
	{
		switch (nType)
		{
		case AT_NOTE:
			SAFE_DELETE(pNote);
			break;
		case AT_DIMENSION:
			SAFE_DELETE(pDim);
			break;
		case AT_DATUM:
			SAFE_DELETE(pDatum);
			break;
		case AT_GTOL:
			SAFE_DELETE(pGTol);
			break;
		case AT_TECHREQU:
			SAFE_DELETE(pTech);
			break;
		case AT_SYMBOL:
			SAFE_DELETE(pSymbol);
			break;
		case AT_SECTIONPLANE:
			SAFE_DELETE(pSecPlane);
			break;
		default:
			SAFE_DELETE(pNote);
			break;
		}
		nType = AT_UNKNOWN;
	}
	void UpdateAnnotType(int nNewType)
	{
		if (nNewType == nType)
			return;
		ClearAllAnnotData();
		switch (nNewType)
		{
		case AT_NOTE:
			pNote = new NoteInfo;
			break;
		case AT_DIMENSION:
			pDim = new DimInfo;
			break;
		case AT_DATUM:
			pDatum = new DatumInfo;
			break;
		case AT_GTOL:
			pGTol = new GtolInfo;
			break;
		case AT_TECHREQU:
			pTech = new TechRequInfo;
			break;
		case AT_SYMBOL:
			pSymbol = new SymbolInfo;
			break;
		case AT_SECTIONPLANE:
			pSecPlane = new SVSectionPlaneInfo;
			break;
		default:
			break;
		}
		nType = nNewType;
	}
	void UpdateAnnotData(const __tagSVAnnotation &annot)
	{
		UpdateAnnotType(annot.nType);
		switch (nType)
		{
		case AT_NOTE:
			*pNote = *annot.pNote;
			break;
		case AT_DIMENSION:
			*pDim = *annot.pDim;
			break;
		case AT_DATUM:
			*pDatum = *annot.pDatum;
			break;
		case AT_GTOL:
			*pGTol = *annot.pGTol;
			break;
		case AT_TECHREQU:
			*pTech = *annot.pTech;
			break;
		case AT_SYMBOL:
			*pSymbol = *annot.pSymbol;
			break;
		case AT_SECTIONPLANE:
			*pSecPlane = *annot.pSecPlane;
			break;
		default:
			break;
		}
	}
	void UpdatePosForLenUnit(double dLenRatio)
	{
		if (annoRenderProp.bIsScreenAnnot)
			return;
		annoPlaneLocal.origin = BPTOCBPFLOAT3(annoPlaneLocal.origin) * float(dLenRatio);
		switch (nType)
		{
		case AT_NOTE:
			pNote->UpdatePosForLenUnit(dLenRatio);
			break;
		case AT_DIMENSION:
			pDim->UpdatePosForLenUnit(dLenRatio);
			break;
		case AT_DATUM:
			pDatum->UpdatePosForLenUnit(dLenRatio);
			break;
		case AT_GTOL:
			pGTol->UpdatePosForLenUnit(dLenRatio);
			break;
		case AT_TECHREQU:
			pTech->UpdatePosForLenUnit(dLenRatio);
			break;
		case AT_SYMBOL:
			pSymbol->UpdatePosForLenUnit(dLenRatio);
			break;
		case AT_SECTIONPLANE:
			pSecPlane->UpdatePosForLenUnit(dLenRatio);
			break;
		default:
			break;
		}
	}
	void UpdateTextForLenUnit(double dLenRatio)
	{
		switch (nType)
		{
		case AT_NOTE:
			pNote->UpdateTextForLenUnit(dLenRatio);
			break;
		case AT_DIMENSION:
			pDim->UpdateTextForLenUnit(dLenRatio);
			break;
		case AT_DATUM:
			pDatum->UpdateTextForLenUnit(dLenRatio);
			break;
		case AT_GTOL:
			pGTol->UpdateTextForLenUnit(dLenRatio);
			break;
		case AT_TECHREQU:
			pTech->UpdateTextForLenUnit(dLenRatio);
			break;
		case AT_SYMBOL:
			pSymbol->UpdateTextForLenUnit(dLenRatio);
			break;
		case AT_SECTIONPLANE:
			pSecPlane->UpdateTextForLenUnit(dLenRatio);
			break;
		default:
			break;
		}
	}
} SVAnnotation;

// ��ע��ͼ������һϵ��ע��Ԫ��
typedef struct __tagSVAnnotationView
{
	IKS_UINT uID;								// ��ͼID
	CSVWString strName;						// ����
	SVAnnotationPlane annoPlane;			// ��עƽ��
	IKS_BOOL bTranspRenderRefMdlInterStruct;	// ��͸����Ⱦ����ģ���ڲ��ṹ
	std::vector<IKS_UINT> arrAnnotationID;		// ��ע��
	IKS_BOOL bUseCustomCamera;					// ʹ�ö����������ʶ
	BPCAMERA stuCustomCamera;				// ���������(����ע������ϵ�ռ�)

	__tagSVAnnotationView() 
	{
		uID = IKS_UINT(-1);
		strName = L"";
		bTranspRenderRefMdlInterStruct = FALSE;
		bUseCustomCamera = FALSE;
	}
	__tagSVAnnotationView(const __tagSVAnnotationView &avi)
	{
		uID = avi.uID;
		strName = avi.strName;
		annoPlane = avi.annoPlane;
		bTranspRenderRefMdlInterStruct = avi.bTranspRenderRefMdlInterStruct;
		arrAnnotationID = avi.arrAnnotationID;
		bUseCustomCamera = avi.bUseCustomCamera;
		stuCustomCamera = avi.stuCustomCamera;
	}
	__tagSVAnnotationView& operator=(const __tagSVAnnotationView &avi) 
	{
		if (this == &avi)
			return *this;
		uID = avi.uID;
		strName = avi.strName;
		annoPlane = avi.annoPlane;
		bTranspRenderRefMdlInterStruct = avi.bTranspRenderRefMdlInterStruct;
		arrAnnotationID = avi.arrAnnotationID;
		bUseCustomCamera = avi.bUseCustomCamera;
		stuCustomCamera = avi.stuCustomCamera;
		return *this;
	}
} SVAnnotationView;

// ��ע�飬����һϵ�б�ע��ͼ
typedef struct __tagSVAnnotationBlock
{
	IKS_UINT uID;								// ��ע��ID
	CSVWString strName;						// ����
	BPBASEMATRIX matWorld;					// ��ע���������
	IKS_UINT uRefModelTreeNodeID;				// ���õ�ģ�����ڵ�ID
	std::vector<IKS_UINT> arrViewID;			// ��ͼ��

	__tagSVAnnotationBlock() 
	{
		uID = IKS_UINT(-1);
		strName = L"";
		INIT_MATRIX(matWorld);
		uRefModelTreeNodeID = IKS_UINT(-1);
	}
	__tagSVAnnotationBlock(const __tagSVAnnotationBlock &block)
	{
		uID = block.uID;
		strName = block.strName;
		matWorld = block.matWorld;
		uRefModelTreeNodeID = block.uRefModelTreeNodeID;
		arrViewID = block.arrViewID;
	}
	__tagSVAnnotationBlock& operator=(const __tagSVAnnotationBlock &block) 
	{
		if (this == &block)
			return *this;
		uID = block.uID;
		strName = block.strName;
		matWorld = block.matWorld;
		uRefModelTreeNodeID = block.uRefModelTreeNodeID;
		arrViewID = block.arrViewID;
		return *this;
	}
} SVAnnotationBlock;

// ��ע���ڵ�
typedef struct __BP_ANNOT_TREENODE {
	unsigned int _uTreeNodeID;					// ���ڵ�ID(��Ӧ��עID/��ע��ͼID/��ע��ID)
	int _nType;									// �ڵ�����,�ο�ö����BPANNOTTREENODETYPE
	CSVWString _strName;						// �ڵ�����
	std::vector<__BP_ANNOT_TREENODE> _arrSubNode;	// �ӽڵ�
	__BP_ANNOT_TREENODE()
	{
		_uTreeNodeID = INVALID_ID;
		_nType = BPATNT_NULL;
		_strName = L"";
	}
	__BP_ANNOT_TREENODE(const __BP_ANNOT_TREENODE& node)
	{
		_uTreeNodeID = node._uTreeNodeID;
		_nType = node._nType;
		_strName = node._strName;
		_arrSubNode = node._arrSubNode;
	}
	__BP_ANNOT_TREENODE& operator = (const __BP_ANNOT_TREENODE& node)
	{
		if (this == &node) // ����Լ����Լ���ֵ��ֱ�ӷ���
			return *this;
		_uTreeNodeID = node._uTreeNodeID;
		_nType = node._nType;
		_strName = node._strName;
		_arrSubNode = node._arrSubNode;
		return *this;
	}
	void CopyData(__BP_ANNOT_TREENODE& node)	const
	{
		node._uTreeNodeID = _uTreeNodeID;
		node._nType = _nType;
		node._strName = _strName;
	}
} BP_ANNOT_TREENODE;

//===================================================================================================

#endif