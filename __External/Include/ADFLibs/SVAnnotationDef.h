//===================================================================================================
// Summary:
//		FreeType的接口定义
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

// 以下为宏定义

// 角度转弧度
#define ANGLE_TO_RADIAN(angle) (angle) * (0.017453292519943295769236907684883)
#define RADIAN_TO_ANGLE(rad) (rad) * (57.295779513082320876798154814105)

// 字符串宏定义
// 使用宏区分多语言版本
#define SVSTR_TECHREQ L"技术要求"

// 最大实体要求
#define SVSTR_ANNOTGTOL_MAXMATCOND L"(M)"
// 最小实体要求
#define SVSTR_ANNOTGTOL_LSTMATCOND L"(L)"
// 延伸公差带
#define SVSTR_ANNOTGTOL_PROJTOLZONE L"(P)"
// 自由状态条件
#define SVSTR_ANNOTGTOL_FREESTATE L"(F)"
// 正切平面
#define SVSTR_ANNOTGTOL_TANPLANE L"(T)"
// 包含要求
#define SVSTR_ANNOTGTOL_EMBODY L"(E)"
// 独立原则RFS
#define SVSTR_ANNOTGTOL_RFS L"(S)"

//===================================================================================================

// 以下为枚举值定义

// 标注类型
typedef enum __tagAnnotationType
{
	AT_UNKNOWN			= 0,	// 未知类型
	AT_DIMENSION		= 1,	// 尺寸
	AT_NOTE				= 2,	// 注释
	AT_DATUM			= 3,	// 基准
	AT_GTOL				= 4,	// 形位公差
	AT_SURFFINISH		= 5,	// 粗糙度
	AT_TECHREQU			= 6,	// 技术要求
	AT_SYMBOL			= 7,	// 一般符号
	AT_WELDFILLET		= 8,	// 焊角符号
	AT_WELD				= 9,	// 焊接符号
	AT_SAMEHOLE			= 10,	// 相同孔符号
	AT_SKETCH			= 20,	// 草绘（当作一种特殊符号处理）
	AT_COSMETIC			= 21,	// 修饰特征（当作一种特殊符号处理）

	AT_SECTIONPLANE		= 100	// 剖切平面
} AnnotationType;

// 尺寸公差输入方式
typedef enum __tagDimensionInputType
{
	INTYPE_SYMBOL		= 0,	// 代号
	INTYPE_TOL			= 1,	// 偏差
	INTYPE_FIT			= 2,	// 配合
	INTYPE_SYMMETRY		= 3,	// 对称
} DimInputType;

// 尺寸公差输出方式
typedef enum __tagDimensionOuputType
{
	OUTYPE_SYMBOL		= 0,	// 代号
	OUTYPE_TOL			= 1,	// 偏差
	OUTYPE_BRACKETTOL	= 2,	// (偏差)
	OUTYPE_SYMBOLTOL	= 3,	// 代号(偏差)
	OUTYPE_LIMIT		= 4,	// 极限尺寸
	OUTYPE_FIT			= 5,	// 配合
	OUTYPE_FITGAP		= 6,	// 配合(间隙)
	OUTYPE_NONE			= -1	// 无效
} DimOutputType;

// 表格类型
typedef enum __tagTableType
{
	TABT_HOLE_TOL_SMALL		= 0,		// 孔公差，尺寸小于500
	TABT_HOLE_TOL_BIG		= 1,		// 孔公差，尺寸大于500小于3150
	TABT_HOLE_TOL_NONE		= 2,		// 孔公差，尺寸大于3150
	TABT_AXIS_TOL_SMALL		= 3,		// 轴公差，尺寸小于500
	TABT_AXIS_TOL_BIG		= 4,		// 轴公差，尺寸大于500小于3150
	TABT_AXIS_TOL_NONE		= 5,		// 孔公差，尺寸大于3150
	TABT_HOLE_BASE_NORMAL	= 6,		// 基孔制
	TABT_HOLE_BASE_NONE		= 7,		// 基孔制，尺寸大于3150
	TABT_AXIS_BASE_NORMAL	= 8,		// 基轴制
	TABT_AXIS_BASE_NONE		= 9,		// 基轴制，尺寸大于3150
}TABLE_TYPE;

// 尺寸可选择的几何类型
typedef enum __tagSDGeomType
{
	SDGT_POINT			= 1,		// 点
	SDGT_LINE			,			// 直线
	SDGT_CIRCLE			,			// 圆
	SDGT_ARC			,			// 圆弧
	SDGT_ELLIPSE		,			// 圆弧
	SDGT_POINT_POINT	,			// 点和点
	SDGT_POINT_LINE		,			// 点和直线
	SDGT_POINT_CIRCLE	,			// 点和圆
	SDGT_LINE_POINT		,			// 直线和点
	SDGT_LINE_LINE		,			// 直线和直线
	SDGT_LINE_CIRCLE	,			// 直线和圆
	SDGT_CIRCLE_POINT	,			// 圆和点
	SDGT_CIRCLE_LINE	,			// 圆和直线
	SDGT_CIRCLE_CIRCLE	,			// 圆和圆
	SDGT_OTHER			= -1		// 其他情况
} SDGeomType;

// 尺寸类型
typedef enum __tagDimensionType 
{
	DT_HOR_DIS_PNT_PNT			= 1,		// 点点水平距离
	DT_VER_DIS_PNT_PNT			,			// 点点竖直距离
	DT_VEC_DIS_PNT_PNT			,			// 点点向量距离
	//DT_DIS_PNT_LINE				,			// 点与直线距离
	//DT_DIS_LINE_PNT				,			// 点与直线距离
	//DT_DIS_LINE_LINE			,			// 直线与直线距离
	DT_ANG_LINE_LINE			,			// 直线与直线角度
	DT_DIA_CIRCLE				,			// 圆的直径
	DT_RAD_CIRCLE				,			// 圆的半径
	DT_LENGTH_ARC				,			// 圆的弧长
	DT_TANGENT					,			// 相切尺寸
	DT_OTHER								// 其他情况
} DimensionType;

// 表面粗糙度的基本符号类型
typedef enum __tagSurfFinishSymbolType
{
	SURF_SYMBOL1	= 1,			// 去除材料的方法获得
	SURF_SYMBOL2	= 2,
	SURF_SYMBOL3	= 3				// 任意方法获得
} SurfFinishSymbolType;

// 表面粗糙度的放置方式
typedef enum __tagSDSymbolAttachType
{
	SATYPE_FREE,
	SATYPE_LEFT_LEADER,
	SATYPE_RIGHT_LEADER,
	SATYPE_RADIAL_LEADER,
	SATYPE_ON_ITEM,
	SATYPE_NORM_ITEM
} SDSymbolAttachType;

// 表面粗糙度的纹理类型
typedef enum __tagSurfFinishTexturetype
{
	SURF_TEXTURE_PARALLEL	= 1,		// 平行
	SURF_TEXTURE_VERTICAL	= 2,		// 垂直
	SURF_TEXTURE_CROSS		= 3,		// 交叉
	SURF_TEXTURE_MULTI		= 4,		// 多个方向
	SURF_TEXTURE_CIRCLE		= 5,		// 同心
	SURF_TEXTURE_RADIATION	= 6,		// 放射
	SURF_TEXTURE_P			= 7,		// 无方向或成凸起的细粒形
	SURF_TEXTURE_CLEAR		= 8			// 无
} SurfFinishTexturetype;

// 设定公差类型
typedef enum __tagSdGtolType
{
	GTOL_UNKNOWN          = 0,
	GTOL_STRAIGHTNESS     = 1,	// 直线度
	GTOL_FLATNESS         = 2,	// 平面度
	GTOL_CIRCULAR         = 3,	// 圆度
	GTOL_CYLINDRICAL      = 4,	// 圆柱度
	GTOL_LINE             = 5,	// 线轮廓度
	GTOL_SURFACE          = 6,	// 曲面轮廓度
	GTOL_PARALLEL         = 7,	// 平行度
	GTOL_PERPENDICULAR    = 8,	// 垂直度
	GTOL_ANGULAR          = 9,	// 倾斜度
	GTOL_POSITION         = 10,	// 位置度
	GTOL_CONCENTRICITY    = 11,	// 同轴度
	GTOL_SYMMETRY         = 12,	// 对称度
	GTOL_CIRCULAR_RUNOUT  = 13,	// 圆跳动
	GTOL_TOTAL_RUNOUT     = 14	// 全跳动
};

typedef enum __tagSdGtolMaterialCond
{
	SDGTOLMATCOND_UNKNOWN     = 0,
	SDGTOLMATCOND_LMC         = 1,
	SDGTOLMATCOND_MMC         = 2,
	SDGTOLMATCOND_RFS         = 3,
	SDGTOLMATCOND_DEFAULT_RFS = 4
};

// 形位公差放置方式
typedef enum __tagSdGtolPlacementType
{
	GPTYPE_UNKNOWN			= -1,
	GPTYPE_NORMLEADER		= 0,	// 引线垂直于图元
	GPTYPE_TOITEMLEADERS	= 1,	// 引线指向图元
	GPTYPE_FREELEADERS		= 2,	// 引线自由放置
	GPTYPE_DIM				= 3,	// 尺寸放置
	GPTYPE_GTOL				= 4,	// 其它几何公差
	GPTYPE_FREENOTE			= 5,	// 自由放置
} SdGtolPlacementType;

// 形位公差引线方式
typedef enum __tagSdArrowStyle
{
	AS_UNKNOWN			= -1,
	AS_ARROWHEAD		=  1,	// 箭头
	AS_DOT				=  2,	// 点
	AS_FILLEDDOT		=  3,	// 实心点
	AS_NOARROW			=  4,	// 无
	AS_CROSS			=  5,	// 交叉
	AS_SLASH			=  6,	// 斜杠
	AS_INTEGRAL			=  7,	// 整数
	AS_BOX				=  8,	// 方框
	AS_FILLEDBOX		=  9,	// 实心框
	AS_DOUBLEARROW		= 10,	// 双箭头
	AS_TARGET			= 14,	// 目标
	AS_LEFTHALF			= 15,	// 左半箭头
	AS_RIGHTHALF		= 16,	// 右半箭头
	AS_TRIANGLE			= 18,	// 三角形
	AS_NOCHANGE			= 19	// 照原样
} SdArrowStyle;

// 几何公差的参照几何类型
typedef enum __tagSdGtolReferenceType
{
	GRTYPE_ANY_SURFACE		= 0x0001,	// 任意曲面
	GRTYPE_PLANE_SURFACE	= 0x0004,	// 平面
	GRTYPE_CIRCULAR_SURFACE	= 0x0008,	// 圆柱面和圆锥面
	GRTYPE_ANY_EDGE			= 0x0010,	// 任意边
	GRTYPE_LINE_EDGE		= 0x0040,	// 直线边
	GRTYPE_UNKNOWN			= 0x0000,
} SdGtolReferenceType;

typedef enum __tagSdDimensionValueRegion
{
	DVREG_INVALID			= -1,		// v<0
	DVREG_0_500				= 0,		// 0<v<=500
	DVREG_500_3150			= 1,		// 500<v<=3150
	DVREG_MORETHAN_3150		= 2			// v>3150
} DimValReg;

// 基准的国标类型
typedef enum __tagGBTYPE
{
	GB_CIR  = 0, 		// 圆形
	GB_REC	= 1			// 方形
} GBTYPE;

// 基准的长度类型
typedef enum __tagDATUMLENGTHTYPE
{
	DATUMLT_1	= 1, 		// 长度类型1
	DATUMLT_2	= 2,		// 长度类型2
	DATUMLT_3	= 3, 		// 长度类型3
	DATUMLT_4	= 4,		// 长度类型4
	DATUMLT_5	= 5,		// 长度类型5
} DATUMLENGTHTYPE;

// 焊接基本符号类型
typedef enum __tagWeldingBaseType
{
	WELD_BASE_NULL			= 0,			// 非法
	WELD_BASE_TYPE1			= 1,			// 卷边焊缝
	WELD_BASE_TYPE2			= 2,			// I形焊缝
	WELD_BASE_TYPE3			= 3,			// V形焊缝
	WELD_BASE_TYPE4			= 4,			// 单边V形焊缝
	WELD_BASE_TYPE5			= 5,			// 带钝边V形焊缝
	WELD_BASE_TYPE6			= 6,			// 带钝边单边V形焊缝
	WELD_BASE_TYPE7			= 7,			// 带钝边U形焊缝
	WELD_BASE_TYPE8			= 8,			// 带钝边J形焊缝
	WELD_BASE_TYPE9			= 9,			// 封底焊缝
	WELD_BASE_TYPE10		= 10,			// 角焊缝
	WELD_BASE_TYPE11		= 11,			// 塞焊缝或槽焊缝
	WELD_BASE_TYPE12		= 12,			// 点焊缝
	WELD_BASE_TYPE13		= 13,			// 缝焊缝
	WELD_BASE_TYPE14		= 14,			// 陡边V形焊缝
	WELD_BASE_TYPE15		= 15,			// 陡边单V形焊缝
	WELD_BASE_TYPE16		= 16,			// 端焊缝
	WELD_BASE_TYPE17		= 17,			// 堆焊缝
	WELD_BASE_TYPE18		= 18,			// 平面连接（钎焊）
	WELD_BASE_TYPE19		= 19,			// 斜面连接（钎焊）
	WELD_BASE_TYPE20		= 20,			// 折叠连接（钎焊）
	WELD_BASE_TYPE21		= 21,			// 喇叭形焊缝
	WELD_BASE_TYPE22		= 22,			// 单边喇叭形焊缝
	WELD_BASE_TYPE23		= 23,			// 锁边焊缝
} WeldingBaseType;						

// 焊接补充符号类型(平面)
typedef enum __tagWeldingContourType
{
	WELD_CONTOUR_NULL		= 30,
	WELD_CONTOUR_FLAT		= 31,			// 平面
	WELD_CONTOUR_CONCAVE	= 32,			// 凹面
	WELD_CONTOUR_CONVEX		= 33,			// 凸面
	WELD_CONTOUR_SMOOTH		= 34,			// 圆滑过渡
} WeldingContourType;

// 焊接补充符号类型(衬垫)
typedef enum __tagWeldingStripType
{
	WELD_STRIP_NULL			= 40,
	WELD_STRIP_PERMANENT	= 41,			// 永久衬垫
	WELD_STRIP_REMOVABLE	= 42,			// 临时衬垫
} WeldingStripType;

// 焊接补充符号类型（三面焊缝）
typedef enum __tagWeldingFaceType
{
	WELD_FACE_NULL			= 50,
	WELD_FACE_RIGHT			= 51,
	WELD_FACE_LEFT			= 52,
	WELD_FACE_UP			= 53,
	WELD_FACE_DOWN			= 54,	
} WeldingFaceType;

// 焊接补充符号类型（尾部）
typedef enum __tagWeldingTailType
{
	WELD_TAIL_NULL			= 60,
	WELD_TAIL_TYPE1			= 61,
	WELD_TAIL_TYPE2			= 62	
} WeldingTailType;

// 焊接符号位置
typedef enum __tagWeldingLocation
{
	WELD_LOCATION_UP		= 0,
	WELD_LOCATION_CENTER	= 1,
	WELD_LOCATION_DOWN		= 2
} WeldingLocation;

// 焊接虚线位置
typedef enum __tagWeldingDashPosition
{
	WELD_DASH_UP			= 0,
	WELD_DASH_DOWN			= 1,
	WELD_DASH_NONE			= 2
} WeldingDashPosition;

// 视图符号方向
typedef enum __tagViewDirectionBaseType
{
	VDBTYPE_VIEWDIRECTION	= 0,
	VDBTYPE_ROTANTICLOCK	= 1,
	VDBTYPE_ROTCLOCK		= 2
} ViewDirectionBaseType;

// 视图符号附加文本类型
typedef enum __tagViewDirectionTextType
{
	VDTTYPE_NULL		= 0,	// 无文本
	VDTTYPE_NameOnly	= 1,	// 文本只包含名称
	VDTTYPE_NameDir		= 2		// 文本包含名称和"向"
} tagViewDirectionTextType;

// 视图符号方向
typedef enum __tagViewDirectionType
{
	VDTYPE_UP				= 0,
	VDTYPE_DOWN				= 1,
	VDTYPE_LEFT				= 2,
	VDTYPE_RIGHT			= 3
} ViewDirectionType;

// 焊接符号的类型
// typedef enum __tagWeldSymbolType
// {
// 	WSTYPE_LEFT				= 0,		// 左引线
// 	WSTYPE_RIGHT_LOC1		= 1,		// 右引线位置1
// 	WSTYPE_RIGHT_LOC2		= 2,		// 右引线位置2
// 	WSTYPE_RIGHT_LOC3		= 3			// 右引线位置3
// } WeldSymbolType; 

// 焊角类型
typedef enum __tagWeldFilletType
{
	WFTYPE_LEFTTOP				= 0,	// 左上
	WFTYPE_RIGHTTOP				= 1,	// 右上
	WFTYPE_LEFTBOTTOM			= 2,	// 左下
	WFTYPE_RIGHTBOTTOM			= 3		// 右下
} WeldFilletType;

// 相同孔类型
typedef enum __tagSameHoleType
{
	SHTYPE_QUARTER				= 0,	// 四分之一
	SHTYPE_HALF					= 1,	// 一半
	SHTYPE_CROSS				= 2,	// 交叉
	SHTYPE_THREEQUARTER			= 3,	// 四分之三
	SHTYPE_WHOLE				= 4,	// 全部
	SHTYPE_CONE_30				= 5,	// 30度圆锥
	SHTYPE_CROSS_CONE_30		= 6,	// 交叉30度圆锥
} SameHoleType;

// 线型 / 预设图层ID
typedef enum __tagCurveType
{
	CT_GEOM					= 0,	// 几何
	CT_DATUM				= 1,	// 基准
	CT_ANNOTATION			= 2,	// 标注
} CurveType;

// 选择结果类型
typedef enum __tagSelectResultType
{
	SRT_SUCCEED				= 0,	// 成功(选中几何)
	SRT_QUIT				= 1,	// 退出(按取消按钮)
	SRT_FINISH				= 2,	// 完成(按确定按钮或中键)
	SRT_PICKOTHER			= 3,	// 单击其他(选择其他菜单而中止)
	SRT_UNKNOWN				= 4,	// 未知
} SelResType;

// 斜度锥度的符号类型
typedef enum __tagTaperType
{
	TTTYPE_TAPER_RIGHT				= 1,	// 锥度_朝右
	TTTYPE_TAPER_LEFT				= 2,	// 锥度_朝左
	TTTYPE_SLOPE_LEFTUP				= 3,	// 斜度_朝左上
	TTTYPE_SLOPE_LEFTDOWN			= 4,	// 斜度_朝左下
	TTTYPE_SLOPE_RIGHTUP			= 5,	// 斜度_朝右上
	TTTYPE_SLOPE_RIGHTDOWN			= 6,	// 斜度_朝右下
} TaperType;

// 中心孔的类型
typedef enum __tagCenterHoleType
{
	CHTYPE_REQUIRE				= 1,	// 要求保留中心孔
	CHTYPE_NOTALLOW				= 2,	// 不允许保留中心孔
	CHTYPE_CAN					= 3,	// 可以保留中心孔
} CenterHoleType;

// 标高符号的类型
typedef enum __tagElevationType
{
	ETYPE_GENERAL				= 1,	// 一般
	ETYPE_SPECIAL				= 2,	// 特殊
	ETYPE_OUTSIDE				= 3,	// 室外
} ElevationType;

// 标高符号的方向类型
typedef enum __tagElevationDirectionType
{
	EDTYPE_RIGHT				= 1,	// 数值文本在左
	EDTYPE_LEFT					= 2,	// 数值文本在右
} ElevationDirectionType;

// 视角符号类型
typedef enum __tagViewingAngleType
{
	VATYPE_FIRST				= 1,	// 第一角
	VATYPE_THIRD				= 2,	// 第三角
} ViewingAngleType;

typedef enum __tagSDColorMethod
{
	SD_COLOR_METHOD_DEFAULT,
	SD_COLOR_METHOD_TYPE,
	SD_COLOR_METHOD_RGB
} SDColorMethod;

// 明细表参数位标志
typedef enum __tagDataPlaceFlag
{
	DPF_DECIMAL,			// 小数位
	DPF_VALID,				// 有效位
	DPF_ALLOWED,			// 允许小数位
} DataPlaceFlag;

// 标注树节点类型
typedef enum _BPANNOTTREENODETYPE
{
	BPATNT_NULL				= 0,	// 无效类
	BPATNT_ANNOT			= 1,	// 标注
	BPATNT_ANNOTVIEW		= 2,	// 标注视图
	BPATNT_ANNOTBLOCK		= 3,	// 标注块
} BPANNOTTREENODETYPE;

// 文本样式的水平对齐方式
typedef enum _tagTextHorJustType
{
	THJT_UNKNOWN			= -1,	// 无效类型
	THJT_LEFT				= 0,	// 左边
	THJT_CENTER				= 1,	// 中心
	THJT_RIGHT				= 2,	// 右边
} TextHorJustType;

// 文本样式的竖直对齐方式
typedef enum _tagTextVerJustType
{
	TVJT_TOP				= 0,	// 顶部
	TVJT_MIDDLE				= 1,	// 中间
	TVJT_BOTTOM				= 2,	// 底部
} TextVerJustType;

// 文本样式的竖直对齐方式
typedef enum _tagLeaderStyle
{
	LS_STANDARD				= 0,	// 标准
	LS_ISO					= 1,	// ISO
} LeaderStyle;

// 文本方向
typedef enum _tagTextDirection
{
	TD_LEFT					= 0,	// 向左
	TD_RIGHT				= 1,	// 向右
} TextDirection;

//===================================================================================================
// 以下为结构体定义

// 标注模型拾取三角片
typedef struct _SVANNOTMDL_PICKTRIANGLE {
	std::vector<BPBASETRIANGLE> arrMain;			// 标注主体的拾取三角片
	std::vector<BPBASETRIANGLE> arrLeaderArrow;		// 引线箭头的拾取三角片(每个箭头一个拾取三角片)
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

// RGB颜色
typedef struct __tagSDColorMap
{
	double  red;          /* percentage of red from 0.0 to 1.0     */
	double  green;        /* percentage of green from 0.0 to 1.0   */
	double  blue;         /* percentage of blue from 0.0 to 1.0    */
} SDColorMap;

// 颜色
typedef struct __tagSDColor
{
	SDColorMethod method;
	union {
		int nType;
		SDColorMap map;
	} value;
} SDColor;

// 焊接符号信息
typedef struct __tagWeldingInfo
{
	int nUpBaseType;							// 符号位置在上方时，基本符号类型, 参考WeldingBaseType枚举值
	int nDownBaseType;							// 符号位置在下方时，基本符号类型, 参考WeldingBaseType枚举值
	int nCenterBaseType;						// 符号位置在中间时，基本符号类型, 参考WeldingBaseType枚举值，WELD_BASE_TYPE12和WELD_BASE_TYPE13才有效

	int nUpContourType;							// 符号位置在上方时，平面补充符号类型，参考WeldingContourType枚举值
	int nDownContourType;						// 符号位置在下方时，平面补充符号类型，参考WeldingContourType枚举值
	int nLocation;								// 焊接符号位置, 参考WeldingLocation枚举值

	int nUpStripType;							// 符号位置在上方时，焊接补充符号类型(衬垫)，参考WeldingStripType枚举值
	int nDownStripType;							// 符号位置在下方时，焊接补充符号类型(衬垫)，参考WeldingStripType枚举值

	int nTailType;								// 尾部焊接补充符号类型，参考WeldingTailType枚举值

	CSVWString strUpLeftValue;					// 符号位置在上方时，左尺寸
	CSVWString strUpUpperValue;					// 符号位置在上方时，上尺寸
	CSVWString strUpRightValue1;				// 符号位置在上方时，右尺寸1
	CSVWString strUpRightValue2;				// 符号位置在上方时，右尺寸2
	CSVWString strUpRightValue3;				// 符号位置在上方时，右尺寸3
	CSVWString strDownLeftValue;				// 符号位置在下方时，左尺寸
	CSVWString strDownUpperValue;				// 符号位置在下方时，上尺寸
	CSVWString strDownRightValue1;				// 符号位置在下方时，右尺寸1
	CSVWString strDownRightValue2;				// 符号位置在下方时，右尺寸2
	CSVWString strDownRightValue3;				// 符号位置在下方时，右尺寸3
	CSVWString strCenterLeftValue;				// 符号位置在下方时，左尺寸
	CSVWString strCenterUpperValue;				// 符号位置在中间时，上尺寸
	CSVWString strCenterRightValue1;			// 符号位置在中间时，右尺寸1
	CSVWString strCenterRightValue2;			// 符号位置在中间时，右尺寸2
	CSVWString strCenterRightValue3;			// 符号位置在中间时，右尺寸3
	CSVWString strNote;							// 焊接说明
	int nDashPosition;							// 焊接虚线位置
	IKS_BOOL bAround;								// 是否为周围焊接符号
	IKS_BOOL bScene;								// 是否为现场符号
	IKS_BOOL bStagger;								// 是否为交错断续焊接符号,如果FALSE时,strNote不用显示

	int nTriFaceType;							// 三面焊缝焊接补充符号类型，参考WeldingFaceType枚举值

	int nAngle;									// 放置角度

	IKS_BOOL bLeaderOrientLeft;						// 焊接的引线方向，TURE为左，FALSE时为右

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

// 焊角符号信息
typedef struct __tagWeldFilletInfo
{
	int nType;			// 焊角类型
	double dSize;		// 焊角大小

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

// 视图符号信息
typedef struct __tagViewDirectionInfo
{
	int nType;						// 视图符号类型
	CSVWString strName;				// 视图符号名称，一般为: A B C ...
	int nDirectionType;				// 视图符号方向，一般为：上，下，左，右
	int nAngle;						// 旋转角度
	int nTextType;					// 视图符号附加文本类型
	double dTextHeight;				// 视图符号文字大小

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

// 相同孔符号信息
typedef struct __tagSameHoleInfo
{
	int nType;			// 相同孔类型
	double dAngle;		// 角度

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

// 斜度锥度符号的信息
typedef struct __tagTaperInfo
{
	int nType;						// 符号类型
	CSVWString strDim;				// 斜度锥度尺寸

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

// 数字格式化信息
typedef struct __tagFormatInfo
{
	int nPlaceFlag;					// 位标志
	int nDecimalNum;				// 小数位数
	int nValidNum;					// 有效位数
	int nAllowedNum;				// 允许位数

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

// 注释选项
typedef struct __tagAnnotationOption
{
	float fElbow;				// 引线弯肘长度
	float fArrowLength;			// 箭头长度
	float fArrowWidth;			// 箭头宽度
	float fDimExLen;			// 尺寸界线延伸长度

	// 以下为文本的相关定义
	float fCharSpace;			// 字符间距，默认为2h/14

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

// 文本样式
typedef struct __tagTextStyle
{
	CSVWString strFont;			// 字体
	float	fHeight;			// 高度值 
	float	fWidth;				// 宽度比值
	float	fThickness;			// 文本的线厚度
	float	fSlant;				// 倾斜角度（按顺时针方向）
	IKS_BOOL	bUnderline;			// 加下划线
	int		nHorJust;			// 水平
	int		nVerJust;			// 垂直
	IKS_BOOL	bMirror;			// 镜像
	IKS_BOOL	bReadonly;			// 只读属性
	float	fLineSpace;			// 行间距因子（行间距=行高*行间距因子）

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

// 注释信息
typedef struct __tagNoteInfo
{
	BPBASEFLOAT3 attachPos;					// 放置位置
	std::vector<BPBASEFLOAT3> arrLeaderPos;	// 引线位置
	CSVWString	strText;					// 注释
	CSVWString	strText2;					// 注释2
	TextStyle textStyle;					// 文本样式
	int nArrowStyle;						// 箭头
	int nLeaderStyle;						// 引线方式
	float fElbowLength;						// 引线折弯长度
	int nTextDir;							// 文本方向
	CSVWString strReserve;					// 保留参数

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

// 技术要求信息
typedef struct __tagTechniqueRequirementInfo
{
	NoteInfo titleInfo;			// 标题信息
	NoteInfo contentInfo;		// 正文信息
	IKS_BOOL bTitleLeft;			// 标题左对齐
	CSVWString strReserve;		// 保留参数

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

// 基准基本信息
typedef struct __tagDatumBaseInfo
{
	int nGBType;					// 国标类型
	int nAttachType;				// 放置方式，参考SDSymbolAttachType枚举值
	CSVWString strName;				// 基准符号名称，一般为: A B C ...
	double dAngle;					// 放置角度
	int nLengthType;				// 长度类型，参考DATUMLENGTHTYPE枚举型
	IKS_BOOL bTextAngleFixed;			// 是否固定文本方向
	IKS_BOOL bIsFlip;					// 是否反向;（只有在nAttachType为SATYPE_NORM_ITEM时有效）
	CSVWString strReserve;			// 保留参数

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

// 几何公差基本信息
typedef struct __tagGtolBaseInfo
{
	int		nSymbolType;						// 基本符号类型
	double	dValue;								// 公差值
	CSVWString	strPrefix;						// 前缀
	CSVWString	strSuffix1;						// 后缀1
	CSVWString	strSuffix2;						// 后缀2
	IKS_BOOL	bAllAround;							// 全周符号
	CSVWString	strNoteTop;						// 上方附注
	CSVWString	strNoteBack;					// 后方附注
	CSVWString	strDatumName11;					// 第一基准名称
	CSVWString	strDatumMatCond11;				// 第一基准参照选取材料条件
	CSVWString	strDatumName12;					// 第一复合基准名称
	CSVWString	strDatumMatCond12;				// 第一复合基准参照选取材料条件
	CSVWString	strDatumName21;					// 第二基准名称
	CSVWString	strDatumMatCond21;				// 第二基准参照选取材料条件
	CSVWString	strDatumName22;					// 第二复合基准名称
	CSVWString	strDatumMatCond22;				// 第二复合基准参照选取材料条件
	CSVWString	strDatumName31;					// 第三基准名称
	CSVWString	strDatumMatCond31;				// 第三基准参照选取材料条件
	CSVWString	strDatumName32;					// 第三复合基准名称
	CSVWString	strDatumMatCond32;				// 第三复合基准参照选取材料条件
	CSVWString strReserve;						// 保留参数

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

// 几何公差信息
typedef struct __tagGtolInfo
{
	BPBASEFLOAT3 attachPos;						// 放置位置
	std::vector<BPBASEFLOAT3> arrLeaderPos;		// 引线位置
	std::vector<GtolBaseInfo> arrBaseInfo;		// 基本信息
	std::vector<DatumBaseInfo> arrDatumInfo;	// 基准信息
	int		nPlacementType;						// 放置方式
	int		nLeaderType;						// 引线方式
	TextStyle textStyle;						// 文本样式
	float fElbowLength;							// 引线折弯长度
	int nTextDir;								// 文本方向
	CSVWString strReserve;						// 保留参数

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

// 符号注释信息
typedef struct __tagSymbolNoteInfo
{
	BPBASEFLOAT2 location;						// 位置
	TextStyle textStyle;						// 文本样式
	CSVWString strContent;						// 文本内容

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

// 符号属性信息
typedef struct __tagSymbolProperty
{
	IKS_BOOL bTextFixed;			// 固定文本
	float fAngle;				// 旋转角度
	float fHeight;				// 高度

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

// 符号信息
typedef struct __tagSymbolInfo
{
	int nType;									// 符号类型
	BPBASEFLOAT3 attachPos;						// 放置位置
	std::vector<BPBASEFLOAT3> arrLeaderPos;		// 引线位置
	float fRadialLeaderRadius;					// 径向引线的半径
	std::vector<SymbolNoteInfo> arrText;		// 文本
	std::vector<SVCurve2D> arrGeom;				// 几何
	SymbolProperty prop;						// 符号属性
	CSVWString strReserve;						// 保留参数

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

// 尺寸信息
typedef struct __tagDimensionInfomation
{
	BPBASEFLOAT3 attachPos[10];			// 放置位置
	BPBASEFLOAT3 textPos;				// 尺寸文本位置
// 	IKS_BOOL	bUseTTL;					// 使用模型公差表
	IKS_BOOL	bUseOverrideVal;			// 使用替代尺寸
	int		nDimType;					// 尺寸类型 
	int		nDisplayType;				// 显示方式
	double	dBaseDimValue;				// 基本尺寸
	double	dOverrideValue;				// 替代尺寸
	double	dUpperTol;					// 上偏差
	double	dLowerTol;					// 下偏差
	double	dMaxCl;						// 最大间隙
	double	dMinCl;						// 最小间隙
	CSVWString strTolSymbol;			// 公差代号
	CSVWString strPrefix;				// 前缀
	CSVWString strSurffix;				// 后缀
	CSVWString strNote;					// 附注
	CSVWString strOverride;				// 替代文本
	FormatInfo	format;					// 格式化信息
	TextStyle textStyle;				// 文本样式
	std::vector<GtolBaseInfo> arrGtolInfo;		// 形位公差信息
	std::vector<DatumBaseInfo> arrDatumInfo;	// 基准信息
	CSVWString strReserve;				// 保留参数

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

// 基准信息
typedef struct __tagDatumInfo
{
	BPBASEFLOAT3 attachPos;			// 放置位置
	DatumBaseInfo baseInfo;			// 基本信息
	TextStyle defaultTextStyle;		// 缺省文本样式
	CSVWString strReserve;			// 保留参数

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

// 表面粗糙度信息
typedef struct __tagSurfFinishInfo
{
	int nSymbolType;			// 基本符号类型， 参考SurfFinishSymbolType枚举值
	int nTextureType;			// 纹理， 参考SurfFinishTexturetype枚举值
	int nAttachType;			// 放置方式，参考SDSymbolAttachType枚举值
	CSVWString strSurfText1;
	CSVWString strSurfText2;
	CSVWString strSurfText3;
	CSVWString strOther;
	CSVWString strSurfMin;
	CSVWString strSurfMax;
	IKS_BOOL bSameReq;
	double dAngle;
	double dTextHeight;
	IKS_BOOL bIsFlip;				// 是否反向;（只有在nAttachType为SATYPE_NORM_ITEM时有效）
	TextStyle defaultTextStyle;	// 缺省文本样式

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

// 注释平面
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

// 标注渲染属性
typedef struct __tagSVAnnotRenderProp
{
	IKS_BOOL bVisible;	// 是否可见
	IKS_BOOL bIsFront;	// 是否前端显示
	IKS_BOOL bIsScreenAnnot;	// 是否为屏幕标注（若为屏幕标注,则"是否前端显示"无意义）

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

// 标注
typedef struct __tagSVAnnotation
{
	IKS_UINT uID;						// 标注ID
	CSVWString strOriAnnotID;		// 标注原始ID(从CAD导出时的标注ID,用于原CAD标注更新当前标注)
	int nType;						// 标注类型,参看枚举型AnnotationType
	CSVWString strName;				// 名称
	SVAnnotationPlane annoPlaneLocal;	// 标注的局部注释平面
	SVAnnotRenderProp annoRenderProp;	// 标注的渲染属性
	IKS_UINT uMtlID;					// 材质ID

	union{
		NoteInfo *pNote;				// 注释集
		DimInfo *pDim;					// 尺寸集
		DatumInfo *pDatum;				// 基准集
		GtolInfo *pGTol;				// 形位公差集
		TechRequInfo *pTech;			// 技术要求
		SymbolInfo *pSymbol;			// 符号
		SVSectionPlaneInfo* pSecPlane;	// 剖切平面
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

// 标注视图，包含一系列注释元素
typedef struct __tagSVAnnotationView
{
	IKS_UINT uID;								// 视图ID
	CSVWString strName;						// 名称
	SVAnnotationPlane annoPlane;			// 标注平面
	IKS_BOOL bTranspRenderRefMdlInterStruct;	// 半透明渲染关联模型内部结构
	std::vector<IKS_UINT> arrAnnotationID;		// 标注集
	IKS_BOOL bUseCustomCamera;					// 使用定制摄像机标识
	BPCAMERA stuCustomCamera;				// 定制摄像机(父标注块坐标系空间)

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

// 标注块，包含一系列标注视图
typedef struct __tagSVAnnotationBlock
{
	IKS_UINT uID;								// 标注块ID
	CSVWString strName;						// 名称
	BPBASEMATRIX matWorld;					// 标注块世界矩阵
	IKS_UINT uRefModelTreeNodeID;				// 引用的模型树节点ID
	std::vector<IKS_UINT> arrViewID;			// 视图集

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

// 标注树节点
typedef struct __BP_ANNOT_TREENODE {
	unsigned int _uTreeNodeID;					// 树节点ID(对应标注ID/标注视图ID/标注块ID)
	int _nType;									// 节点类型,参看枚举型BPANNOTTREENODETYPE
	CSVWString _strName;						// 节点名称
	std::vector<__BP_ANNOT_TREENODE> _arrSubNode;	// 子节点
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
		if (this == &node) // 如果自己给自己赋值则直接返回
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