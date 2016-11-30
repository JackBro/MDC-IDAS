//===================================================================================================
// File:
//		SVBaseDef.h
// Summary:
//		Define Base class/struct, enum, macro and so on.
// Usage:
//		定义最基本的数据；不依赖其他数据结构。用于定义其他数据结构。
// Remarks:
//		Null
// Date:
//		2012-7-19
// Author:
//		Shiping Wang
//===================================================================================================

#pragma once

//===================================================================================================
// 头文件
#include <malloc.h>
#include <memory.h>
#include <wchar.h>

//===================================================================================================
// 数学常量
const float INFINITY = 3.402823466e+38F;
const float EPSILON  = 0.001f;
const float ZERO = float(1e-6);
const double DZERO = 1e-6;
const double DEPSILON = 1e-3;

//===================================================================================================
// 宏定义

#ifndef SAFE_DELETE
#define SAFE_DELETE(p) {if(p) {delete (p);(p)=NULL;}}
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) {if(p) {delete[] (p);(p)=NULL;}}
#endif

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p) {if(p) {(p)->Release();(p)=NULL;}}
#endif

#ifndef SVSAFE_SETPDATA
#define SVSAFE_SETPDATA(pDst, pSrc) {if(pDst&&pSrc) *pDst=*pSrc;}
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef ASSERT
#define ASSERT(exp) ((void) 0)
#endif

#if defined(x64)
typedef __int64 IKS_INT_PTR, *IKS_PINT_PTR;
typedef unsigned __int64 IKS_UINT_PTR, *IKS_PUINT_PTR;
#else
typedef _W64 int IKS_INT_PTR, *IKS_PINT_PTR;
typedef _W64 unsigned int IKS_UINT_PTR, *IKS_PUINT_PTR;
#endif

typedef unsigned long       IKS_DWORD;
typedef int                 IKS_BOOL;
typedef unsigned char       IKS_BYTE;
typedef unsigned short      IKS_WORD;
typedef int                 IKS_INT;
typedef unsigned int        IKS_UINT;
typedef float               IKS_FLOAT;
typedef double				IKS_DOUBLE;
typedef __int64				IKS_LONG64, *IKS_PLONG64;
typedef unsigned __int64	IKS_ULONG64, *IKS_PULONG64;
typedef unsigned __int64	IKS_DWORD64, *IKS_PDWORD64;

typedef IKS_UINT_PTR		BPFXHANDLE;

#define INVALID_ID IKS_UINT(-1)
#define SVTEMPRANDOM_ID IKS_UINT(-2)
#define SVSYSTEMRANDOM_ID IKS_UINT(-3)
#define ISNEEDTONEWID(uID) (uID==INVALID_ID || uID==SVTEMPRANDOM_ID || uID==SVSYSTEMRANDOM_ID)

#define BP_MAX_PATH 256

#define BP_D_PI    (3.14159265358979323846)
#define BP_PI    ((float)  3.141592654f)

#define BPToRadian( degree ) ((degree) * (BP_PI / 180.0f))
#define BPToDegree( radian ) ((radian) * (180.0f / BP_PI))
#define BPToDRadian( degree ) ((degree) * (BP_D_PI / 180.0))
#define BPToDDegree( radian ) ((radian) * (180.0 / BP_D_PI))

#define ISZERO(fValue) ((fValue)<ZERO && (fValue)>-ZERO)
#define ISDZERO(dValue) ((dValue)<DZERO && (dValue)>-DZERO)
#define ISEQUAL(fValue1,fValue2) ((fValue1)-(fValue2)<ZERO && (fValue1)-(fValue2)>-ZERO)
#define ISDEQUAL(dValue1,dValue2) ((dValue1)-(dValue2)<DZERO && (dValue1)-(dValue2)>-DZERO)
#define ISNEAR(fValue1,fValue2) ((fValue1)-(fValue2)<EPSILON && (fValue1)-(fValue2)>-EPSILON)
#define ISDNEAR(fValue1,fValue2) ((fValue1)-(fValue2)<DEPSILON && (fValue1)-(fValue2)>-DEPSILON)
#define ISEQUALEX(fValue1,fValue2,fZero) ((fValue1)-(fValue2)<fZero && (fValue1)-(fValue2)>-fZero)
#define ISDEQUALEX(dValue1,dValue2,dZero) ((dValue1)-(dValue2)<dZero && (dValue1)-(dValue2)>-dZero)
#define ISNEAREX(fValue1,fValue2,fEpsilon) ((fValue1)-(fValue2)<fEpsilon && (fValue1)-(fValue2)>-fEpsilon)
#define ISFLOAT2EQUAL(v1,v2) (ISEQUAL(v1.x, v2.x) && ISEQUAL(v1.y, v2.y))
#define ISFLOAT3EQUAL(v1,v2) (ISEQUAL(v1.x, v2.x) && ISEQUAL(v1.y, v2.y) && ISEQUAL(v1.z, v2.z))
#define ISFLOAT4EQUAL(v1,v2) (ISEQUAL(v1.x, v2.x) && ISEQUAL(v1.y, v2.y) && ISEQUAL(v1.z, v2.z) && ISEQUAL(v1.w, v2.w))
#define ISDOUBLE2EQUAL(v1,v2) (ISDEQUAL(v1.x, v2.x) && ISDEQUAL(v1.y, v2.y))
#define ISDOUBLE3EQUAL(v1,v2) (ISDEQUAL(v1.x, v2.x) && ISDEQUAL(v1.y, v2.y) && ISDEQUAL(v1.z, v2.z))
#define ISDOUBLE4EQUAL(v1,v2) (ISDEQUAL(v1.x, v2.x) && ISDEQUAL(v1.y, v2.y) && ISDEQUAL(v1.z, v2.z) && ISDEQUAL(v1.w, v2.w))
#define ISFLOAT2NEAR(v1,v2) (ISNEAR(v1.x, v2.x) && ISNEAR(v1.y, v2.y))
#define ISFLOAT3NEAR(v1,v2) (ISNEAR(v1.x, v2.x) && ISNEAR(v1.y, v2.y) && ISNEAR(v1.z, v2.z))
#define ISFLOAT4NEAR(v1,v2) (ISNEAR(v1.x, v2.x) && ISNEAR(v1.y, v2.y) && ISNEAR(v1.z, v2.z) && ISNEAR(v1.w, v2.w))
#define ISFLOAT2ZERO(vValue) (ISZERO(vValue.x) && ISZERO(vValue.y))
#define ISFLOAT3ZERO(vValue) (ISZERO(vValue.x) && ISZERO(vValue.y) && ISZERO(vValue.z))
#define ISFLOAT4ZERO(vValue) (ISZERO(vValue.x) && ISZERO(vValue.y) && ISZERO(vValue.z) && ISZERO(vValue.w))
#define ISFLOAT3EQUALEX(v1,v2,fZero) (ISEQUALEX(v1.x, v2.x, fZero) && ISEQUALEX(v1.y, v2.y, fZero) && ISEQUALEX(v1.z, v2.z, fZero))
#define ISDOUBLE3EQUALEX(v1,v2,dZero) (ISDEQUALEX(v1.x, v2.x, dZero) && ISDEQUALEX(v1.y, v2.y, dZero) && ISDEQUALEX(v1.z, v2.z, dZero))
#define ISFLOAT3NEAREX(v1,v2,fEpsilon) (ISNEAREX(v1.x, v2.x, fEpsilon) && ISNEAREX(v1.y, v2.y, fEpsilon) && ISNEAREX(v1.z, v2.z, fEpsilon))

#define BPTOBPFLOAT2( vec2 ) (*((BPFLOAT2*)(&vec2)))
#define BPTOCBPFLOAT2( vec2 ) (*((const BPFLOAT2*)(&vec2)))
#define BPTOBPFLOAT3( vec3 ) (*((BPFLOAT3*)(&vec3)))
#define BPTOCBPFLOAT3( vec3 ) (*((const BPFLOAT3*)(&vec3)))
#define BPTOBPFLOAT4( vec4 ) (*((BPFLOAT4*)(&vec4)))
#define BPTOCBPFLOAT4( vec4 ) (*((const BPFLOAT4*)(&vec4)))
#define BPTOBPDOUBLE2( vec2 ) (*((SVDOUBLE2*)(&vec2)))
#define BPTOCBPDOUBLE2( vec2 ) (*((const SVDOUBLE2*)(&vec2)))
#define BPTOBPDOUBLE3( vec3 ) (*((SVDOUBLE3*)(&vec3)))
#define BPTOCBPDOUBLE3( vec3 ) (*((const SVDOUBLE3*)(&vec3)))
#define BPTOBPMATRIX( matrix ) (*((BPMATRIX*)(&matrix)))
#define BPTOCBPMATRIX( matrix ) (*((const BPMATRIX*)(&matrix)))
#define SVTOCSVMATRIX( matrix ) (*((const SVMATRIX*)(&matrix)))

#define INIT_MATRIX(m) {memset(&(m),0,sizeof(BPBASEMATRIX)); (m)._11=(m)._22=(m)._33=(m)._44=1.0f;}

//===================================================================================================
// 枚举类型定义

// ID类型
typedef enum _BPIDTYPE
{
	BP_ID_SYSTEM			= 0,							// 系统使用的首ID
	BP_ID_USER				= 100000,						// 用户使用的首ID
	BP_ID_TEMP				= BP_ID_SYSTEM - 100000000,		// 临时使用的首ID
} BPIDTYPE;

//===================================================================================================
// 结构体定义

// 二维向量(单精度)
typedef struct _BPBASEUINT2 {
	IKS_UINT x;
	IKS_UINT y;
} BPBASEUINT2;

// 二维向量(单精度)
typedef struct _BPBASEFLOAT2 {
	float x;
	float y;
} BPBASEFLOAT2;

// 三维向量(单精度)
typedef struct _BPBASEFLOAT3 {
	float x;
	float y;
	float z;
} BPBASEFLOAT3;

// 四维向量(单精度)
typedef struct _BPBASEFLOAT4 {
	union {
		struct {
			float x;
			float y;
			float z;
			float w;
		};
		struct {
			float r;
			float g;
			float b;
			float a;
		};
	};
} BPBASEFLOAT4;

// 三角片(单精度)
typedef struct _BPBASETRIANGLE {
	BPBASEFLOAT3 p1;
	BPBASEFLOAT3 p2;
	BPBASEFLOAT3 p3;
} BPBASETRIANGLE;

// 矩阵(单精度)
typedef struct _BPBASEMATRIX {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		};
		float m[4][4];
	};
} BPBASEMATRIX;

// 二维向量(双精度)
typedef struct _SVBASEDOUBLE2 {
	double x;
	double y;
} SVBASEDOUBLE2;

// 三维向量(双精度)
typedef struct _SVBASEDOUBLE3 {
	double x;
	double y;
	double z;
} SVBASEDOUBLE3;

// 四维向量(双精度)
typedef struct _SVBASEDOUBLE4 {
	double x;
	double y;
	double z;
	double w;
} SVBASEDOUBLE4;

// 矩阵(双精度)
typedef struct _SVBASEMATRIX {
	union {
		struct {
			double        _11, _12, _13, _14;
			double        _21, _22, _23, _24;
			double        _31, _32, _33, _34;
			double        _41, _42, _43, _44;

		};
		double m[4][4];
	};
} SVBASEMATRIX;

// 二维向量(单精度)
typedef struct _BPFLOAT2 : public BPBASEFLOAT2
{
	_BPFLOAT2()
	{
		x = y = 0.f;
	}
	_BPFLOAT2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
	_BPFLOAT2(const BPBASEFLOAT2 &v)
	{
		x = v.x;
		y = v.y;
	}
	_BPFLOAT2(const float v[2])
	{
		x = v[0];
		y = v[1];
	}
	_BPFLOAT2(const double v[2])
	{
		x = float(v[0]);
		y = float(v[1]);
	}
	_BPFLOAT2(const SVBASEDOUBLE2 &v)
	{
		x = float(v.x);
		y = float(v.y);
	}
	operator float* ()
	{
		return (float *) &x;
	}
	_BPFLOAT2& operator += ( const _BPFLOAT2& v )
	{
		x += v.x;
		y += v.y;
		return *this;
	}
	_BPFLOAT2& operator -= ( const _BPFLOAT2& v )
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}
	// unary operators
	_BPFLOAT2 _BPFLOAT2::operator + () const
	{
		return *this;
	}

	_BPFLOAT2 _BPFLOAT2::operator - () const
	{
		return _BPFLOAT2(-x, -y);
	}

	// binary operators
	_BPFLOAT2 _BPFLOAT2::operator + ( const _BPFLOAT2& v ) const
	{
		return _BPFLOAT2(x + v.x, y + v.y);
	}

	_BPFLOAT2 _BPFLOAT2::operator - ( const _BPFLOAT2& v ) const
	{
		return _BPFLOAT2(x - v.x, y - v.y);
	}

	_BPFLOAT2 _BPFLOAT2::operator * ( float f ) const
	{
		return _BPFLOAT2(x * f, y * f);
	}

	_BPFLOAT2 _BPFLOAT2::operator / ( float f ) const
	{
		float fInv = 1.0f / f;
		return _BPFLOAT2(x * fInv, y * fInv);
	}
} BPFLOAT2;

// 三维向量(单精度)
typedef struct _BPFLOAT3 : public BPBASEFLOAT3
{
	_BPFLOAT3()
	{
		x = y = z = 0.f;
	}
	_BPFLOAT3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
	_BPFLOAT3(const BPBASEFLOAT3 &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}
	_BPFLOAT3(const float v[3])
	{
		x = v[0];
		y = v[1];
		z = v[2];
	}
	_BPFLOAT3(const double v[3])
	{
		x = float(v[0]);
		y = float(v[1]);
		z = float(v[2]);
	}
	_BPFLOAT3(const SVBASEDOUBLE3 &v)
	{
		x = float(v.x);
		y = float(v.y);
		z = float(v.z);
	}
	operator float* ()
	{
		return (float *) &x;
	}
	_BPFLOAT3& operator += ( const _BPFLOAT3& v )
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	_BPFLOAT3& operator -= ( const _BPFLOAT3& v )
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	// unary operators
	_BPFLOAT3 _BPFLOAT3::operator + () const
	{
		return *this;
	}

	_BPFLOAT3 _BPFLOAT3::operator - () const
	{
		return _BPFLOAT3(-x, -y, -z);
	}

	// binary operators
	_BPFLOAT3 _BPFLOAT3::operator + ( const _BPFLOAT3& v ) const
	{
		return _BPFLOAT3(x + v.x, y + v.y, z + v.z);
	}

	_BPFLOAT3 _BPFLOAT3::operator - ( const _BPFLOAT3& v ) const
	{
		return _BPFLOAT3(x - v.x, y - v.y, z - v.z);
	}

	_BPFLOAT3 _BPFLOAT3::operator * ( float f ) const
	{
		return _BPFLOAT3(x * f, y * f, z * f);
	}

	_BPFLOAT3 _BPFLOAT3::operator / ( float f ) const
	{
		float fInv = 1.0f / f;
		return _BPFLOAT3(x * fInv, y * fInv, z * fInv);
	}
} BPFLOAT3;

// 四维向量(单精度)
typedef struct _BPFLOAT4 : public BPBASEFLOAT4
{
	_BPFLOAT4()
	{
		x = y = z = w = 0.f;
	}
	_BPFLOAT4(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}
	_BPFLOAT4(const BPBASEFLOAT4 &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	}
	_BPFLOAT4(const float v[4])
	{
		x = v[0];
		y = v[1];
		z = v[2];
		w = v[3];
	}
	_BPFLOAT4(const double v[4])
	{
		x = float(v[0]);
		y = float(v[1]);
		z = float(v[2]);
		w = float(v[3]);
	}
	_BPFLOAT4(const SVBASEDOUBLE4 &v)
	{
		x = float(v.x);
		y = float(v.y);
		z = float(v.z);
		w = float(v.w);
	}
	operator float* ()
	{
		return (float *) &x;
	}
	_BPFLOAT4& operator += ( const _BPFLOAT4& v )
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}
	_BPFLOAT4& operator -= ( const _BPFLOAT4& v )
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}

	// unary operators
	_BPFLOAT4 _BPFLOAT4::operator + () const
	{
		return *this;
	}

	_BPFLOAT4 _BPFLOAT4::operator - () const
	{
		return _BPFLOAT4(-x, -y, -z, -w);
	}

	// binary operators
	_BPFLOAT4 _BPFLOAT4::operator + ( const _BPFLOAT4& v ) const
	{
		return _BPFLOAT4(x + v.x, y + v.y, z + v.z, w + v.w);
	}

	_BPFLOAT4 _BPFLOAT4::operator - ( const _BPFLOAT4& v ) const
	{
		return _BPFLOAT4(x - v.x, y - v.y, z - v.z, w - v.w);
	}

	_BPFLOAT4 _BPFLOAT4::operator * ( float f ) const
	{
		return _BPFLOAT4(x * f, y * f, z * f, w * f);
	}

	_BPFLOAT4 _BPFLOAT4::operator / ( float f ) const
	{
		float fInv = 1.0f / f;
		return _BPFLOAT4(x * fInv, y * fInv, z * fInv, w * fInv);
	}
} BPFLOAT4;

// 矩阵(单精度)
typedef struct _BPMATRIX : public BPBASEMATRIX
{
public:
	_BPMATRIX()
	{
		memset(&_11, 0, sizeof(_BPMATRIX));
		_11 = _22 = _33 = _44 = 1.0f;
	}
	_BPMATRIX( const float *pf)
	{
#ifdef _DEBUG
		if(!pf)
			return;
#endif
		memcpy_s(&_11, sizeof(_BPMATRIX), pf, sizeof(_BPMATRIX));
	}
	_BPMATRIX( const BPBASEMATRIX& mat )
	{
		memcpy_s(&_11, sizeof(_BPMATRIX), &mat, sizeof(_BPMATRIX));
	}
	_BPMATRIX( float f11, float f12, float f13, float f14,
		float f21, float f22, float f23, float f24,
		float f31, float f32, float f33, float f34,
		float f41, float f42, float f43, float f44 )
	{
		_11 = f11; _12 = f12; _13 = f13; _14 = f14;
		_21 = f21; _22 = f22; _23 = f23; _24 = f24;
		_31 = f31; _32 = f32; _33 = f33; _34 = f34;
		_41 = f41; _42 = f42; _43 = f43; _44 = f44;
	}
	_BPMATRIX( const float mat[4][4])
	{
		_11 = mat[0][0]; _12 = mat[0][1]; _13 = mat[0][2]; _14 = mat[0][3];
		_21 = mat[1][0]; _22 = mat[1][1]; _23 = mat[1][2]; _24 = mat[1][3];
		_31 = mat[2][0]; _32 = mat[2][1]; _33 = mat[2][2]; _34 = mat[2][3];
		_41 = mat[3][0]; _42 = mat[3][1]; _43 = mat[3][2]; _44 = mat[3][3];
	}
	_BPMATRIX( const double mat[4][4])
	{
		_11 = float(mat[0][0]); _12 = float(mat[0][1]); _13 = float(mat[0][2]); _14 = float(mat[0][3]);
		_21 = float(mat[1][0]); _22 = float(mat[1][1]); _23 = float(mat[1][2]); _24 = float(mat[1][3]);
		_31 = float(mat[2][0]); _32 = float(mat[2][1]); _33 = float(mat[2][2]); _34 = float(mat[2][3]);
		_41 = float(mat[3][0]); _42 = float(mat[3][1]); _43 = float(mat[3][2]); _44 = float(mat[3][3]);
	}
	_BPMATRIX( const SVBASEMATRIX &mat)
	{
		_11 = float(mat._11); _12 = float(mat._12); _13 = float(mat._13); _14 = float(mat._14);
		_21 = float(mat._21); _22 = float(mat._22); _23 = float(mat._23); _24 = float(mat._24);
		_31 = float(mat._31); _32 = float(mat._32); _33 = float(mat._33); _34 = float(mat._34);
		_41 = float(mat._41); _42 = float(mat._42); _43 = float(mat._43); _44 = float(mat._44);
	}

	// access grants
	float& operator () ( IKS_UINT uRow, IKS_UINT uCol )
	{
		return m[uRow][uCol];
	}
	float  operator () ( IKS_UINT uRow, IKS_UINT uCol ) const
	{
		return m[uRow][uCol];
	}

	// casting operators
	operator float* ()
	{
		return (float *) &_11;
	}
	operator const float* () const
	{
		return (const float *) &_11;
	}

	// assignment operators
	_BPMATRIX& operator *= ( const _BPMATRIX& mat )
	{
		_BPMATRIX matSrc = *this;
		for (int i=0; i<4; i++)
		{
			for (int j=0; j<4; j++)
			{
				m[i][j] = 0.0;
				for (int k=0; k<4; k++)
				{
					m[i][j] += matSrc.m[i][k] * mat.m[k][j];
				}
			}
		}
		return *this;
	}
	_BPMATRIX& operator += ( const _BPMATRIX& mat )
	{
		_11 += mat._11; _12 += mat._12; _13 += mat._13; _14 += mat._14;
		_21 += mat._21; _22 += mat._22; _23 += mat._23; _24 += mat._24;
		_31 += mat._31; _32 += mat._32; _33 += mat._33; _34 += mat._34;
		_41 += mat._41; _42 += mat._42; _43 += mat._43; _44 += mat._44;
		return *this;
	}
	_BPMATRIX& operator -= ( const _BPMATRIX& mat )
	{
		_11 -= mat._11; _12 -= mat._12; _13 -= mat._13; _14 -= mat._14;
		_21 -= mat._21; _22 -= mat._22; _23 -= mat._23; _24 -= mat._24;
		_31 -= mat._31; _32 -= mat._32; _33 -= mat._33; _34 -= mat._34;
		_41 -= mat._41; _42 -= mat._42; _43 -= mat._43; _44 -= mat._44;
		return *this;
	}
	_BPMATRIX& operator *= ( float f )
	{
		_11 *= f; _12 *= f; _13 *= f; _14 *= f;
		_21 *= f; _22 *= f; _23 *= f; _24 *= f;
		_31 *= f; _32 *= f; _33 *= f; _34 *= f;
		_41 *= f; _42 *= f; _43 *= f; _44 *= f;
		return *this;
	}
	_BPMATRIX& operator /= ( float f )
	{
		float fInv = 1.0f / f;
		_11 *= fInv; _12 *= fInv; _13 *= fInv; _14 *= fInv;
		_21 *= fInv; _22 *= fInv; _23 *= fInv; _24 *= fInv;
		_31 *= fInv; _32 *= fInv; _33 *= fInv; _34 *= fInv;
		_41 *= fInv; _42 *= fInv; _43 *= fInv; _44 *= fInv;
		return *this;
	}

	// unary operators
	_BPMATRIX operator + () const
	{
		return *this;
	}
	_BPMATRIX operator - () const
	{
		return _BPMATRIX(-_11, -_12, -_13, -_14,
			-_21, -_22, -_23, -_24,
			-_31, -_32, -_33, -_34,
			-_41, -_42, -_43, -_44);
	}

	// binary operators
	_BPMATRIX operator * ( const _BPMATRIX& mat ) const
	{
		_BPMATRIX matT;
		for (int i=0; i<4; i++)
		{
			for (int j=0; j<4; j++)
			{
				matT.m[i][j] = 0.0;
				for (int k=0; k<4; k++)
				{
					matT.m[i][j] += this->m[i][k] * mat.m[k][j];
				}
			}
		}
		return matT;
	}
	_BPMATRIX operator + ( const _BPMATRIX& mat ) const
	{
		return _BPMATRIX(_11 + mat._11, _12 + mat._12, _13 + mat._13, _14 + mat._14,
			_21 + mat._21, _22 + mat._22, _23 + mat._23, _24 + mat._24,
			_31 + mat._31, _32 + mat._32, _33 + mat._33, _34 + mat._34,
			_41 + mat._41, _42 + mat._42, _43 + mat._43, _44 + mat._44);
	}
	_BPMATRIX operator - ( const _BPMATRIX& mat ) const
	{
		return _BPMATRIX(_11 - mat._11, _12 - mat._12, _13 - mat._13, _14 - mat._14,
			_21 - mat._21, _22 - mat._22, _23 - mat._23, _24 - mat._24,
			_31 - mat._31, _32 - mat._32, _33 - mat._33, _34 - mat._34,
			_41 - mat._41, _42 - mat._42, _43 - mat._43, _44 - mat._44);
	}
	_BPMATRIX operator * ( float f ) const
	{
		return _BPMATRIX(_11 * f, _12 * f, _13 * f, _14 * f,
			_21 * f, _22 * f, _23 * f, _24 * f,
			_31 * f, _32 * f, _33 * f, _34 * f,
			_41 * f, _42 * f, _43 * f, _44 * f);
	}
	_BPMATRIX operator / ( float f ) const
	{
		float fInv = 1.0f / f;
		return _BPMATRIX(_11 * fInv, _12 * fInv, _13 * fInv, _14 * fInv,
			_21 * fInv, _22 * fInv, _23 * fInv, _24 * fInv,
			_31 * fInv, _32 * fInv, _33 * fInv, _34 * fInv,
			_41 * fInv, _42 * fInv, _43 * fInv, _44 * fInv);
	}

	IKS_BOOL operator == ( const _BPMATRIX& mat ) const
	{
		return 0 == memcmp(this, &mat, sizeof(_BPMATRIX));
	}
	IKS_BOOL operator != ( const _BPMATRIX& mat ) const
	{
		return 0 != memcmp(this, &mat, sizeof(_BPMATRIX));
	}

} BPMATRIX;

// 二维向量(双精度)
typedef struct _SVDOUBLE2 : public SVBASEDOUBLE2
{
	_SVDOUBLE2()
	{
		x = y = 0.0;
	}
	_SVDOUBLE2(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
	_SVDOUBLE2(const SVBASEDOUBLE2 &v)
	{
		x = v.x;
		y = v.y;
	}
	_SVDOUBLE2(const double v[2])
	{
		x = v[0];
		y = v[1];
	}
	_SVDOUBLE2(const float v[2])
	{
		x = double(v[0]);
		y = double(v[1]);
	}
	_SVDOUBLE2(const BPBASEFLOAT2 &v)
	{
		x = double(v.x);
		y = double(v.y);
	}
	operator double* ()
	{
		return (double *) &x;
	}
	_SVDOUBLE2& operator += ( const _SVDOUBLE2& v )
	{
		x += v.x;
		y += v.y;
		return *this;
	}
	_SVDOUBLE2& operator -= ( const _SVDOUBLE2& v )
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	// unary operators
	_SVDOUBLE2 _SVDOUBLE2::operator + () const
	{
		return *this;
	}

	_SVDOUBLE2 _SVDOUBLE2::operator - () const
	{
		return _SVDOUBLE2(-x, -y);
	}

	// binary operators
	_SVDOUBLE2 _SVDOUBLE2::operator + ( const _SVDOUBLE2& v ) const
	{
		return _SVDOUBLE2(x + v.x, y + v.y);
	}

	_SVDOUBLE2 _SVDOUBLE2::operator - ( const _SVDOUBLE2& v ) const
	{
		return _SVDOUBLE2(x - v.x, y - v.y);
	}

	_SVDOUBLE2 _SVDOUBLE2::operator * ( double d ) const
	{
		return _SVDOUBLE2(x * d, y * d);
	}

	_SVDOUBLE2 _SVDOUBLE2::operator / ( double d ) const
	{
		double fInv = 1.0 / d;
		return _SVDOUBLE2(x * fInv, y * fInv);
	}
} SVDOUBLE2;

// 三维向量(双精度)
typedef struct _SVDOUBLE3 : public SVBASEDOUBLE3
{
	_SVDOUBLE3()
	{
		x = y = z = 0.0;
	}
	_SVDOUBLE3(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
	_SVDOUBLE3(const SVBASEDOUBLE3 &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}
	_SVDOUBLE3(const double v[3])
	{
		x = v[0];
		y = v[1];
		z = v[2];
	}
	_SVDOUBLE3(const float v[3])
	{
		x = double(v[0]);
		y = double(v[1]);
		z = double(v[2]);
	}
	_SVDOUBLE3(const BPBASEFLOAT3 &v)
	{
		x = double(v.x);
		y = double(v.y);
		z = double(v.z);
	}
	operator double* ()
	{
		return (double *) &x;
	}
	_SVDOUBLE3& operator += ( const _SVDOUBLE3& v )
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	_SVDOUBLE3& operator -= ( const _SVDOUBLE3& v )
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	// unary operators
	_SVDOUBLE3 _SVDOUBLE3::operator + () const
	{
		return *this;
	}

	_SVDOUBLE3 _SVDOUBLE3::operator - () const
	{
		return _SVDOUBLE3(-x, -y, -z);
	}

	// binary operators
	_SVDOUBLE3 _SVDOUBLE3::operator + ( const _SVDOUBLE3& v ) const
	{
		return _SVDOUBLE3(x + v.x, y + v.y, z + v.z);
	}

	_SVDOUBLE3 _SVDOUBLE3::operator - ( const _SVDOUBLE3& v ) const
	{
		return _SVDOUBLE3(x - v.x, y - v.y, z - v.z);
	}

	_SVDOUBLE3 _SVDOUBLE3::operator * ( double d ) const
	{
		return _SVDOUBLE3(x * d, y * d, z * d);
	}

	_SVDOUBLE3 _SVDOUBLE3::operator / ( double d ) const
	{
		double fInv = 1.0 / d;
		return _SVDOUBLE3(x * fInv, y * fInv, z * fInv);
	}
} SVDOUBLE3;

// 四维向量(双精度)
typedef struct _SVDOUBLE4 : public SVBASEDOUBLE4
{
	_SVDOUBLE4()
	{
		x = y = z = w = 0.0;
	}
	_SVDOUBLE4(double _x, double _y, double _z, double _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}
	_SVDOUBLE4(const SVBASEDOUBLE4 &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	}
	_SVDOUBLE4(const double v[4])
	{
		x = v[0];
		y = v[1];
		z = v[2];
		w = v[3];
	}
	_SVDOUBLE4(const float v[4])
	{
		x = double(v[0]);
		y = double(v[1]);
		z = double(v[2]);
		w = double(v[3]);
	}
	_SVDOUBLE4(const BPBASEFLOAT4 &v)
	{
		x = double(v.x);
		y = double(v.y);
		z = double(v.z);
		w = double(v.w);
	}
	operator double* ()
	{
		return (double *) &x;
	}
	_SVDOUBLE4& operator += ( const _SVDOUBLE4& v )
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}
	_SVDOUBLE4& operator -= ( const _SVDOUBLE4& v )
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}

	// unary operators
	_SVDOUBLE4 _SVDOUBLE4::operator + () const
	{
		return *this;
	}

	_SVDOUBLE4 _SVDOUBLE4::operator - () const
	{
		return _SVDOUBLE4(-x, -y, -z, -w);
	}

	// binary operators
	_SVDOUBLE4 _SVDOUBLE4::operator + ( const _SVDOUBLE4& v ) const
	{
		return _SVDOUBLE4(x + v.x, y + v.y, z + v.z, w + v.w);
	}

	_SVDOUBLE4 _SVDOUBLE4::operator - ( const _SVDOUBLE4& v ) const
	{
		return _SVDOUBLE4(x - v.x, y - v.y, z - v.z, w - v.w);
	}

	_SVDOUBLE4 _SVDOUBLE4::operator * ( double d ) const
	{
		return _SVDOUBLE4(x * d, y * d, z * d, w * d);
	}

	_SVDOUBLE4 _SVDOUBLE4::operator / ( double d ) const
	{
		double fInv = 1.0 / d;
		return _SVDOUBLE4(x * fInv, y * fInv, z * fInv, w * fInv);
	}
} SVDOUBLE4;

// 矩阵(双精度)
typedef struct _SVMATRIX : public SVBASEMATRIX
{
public:
	_SVMATRIX()
	{
		memset(&_11, 0, sizeof(_SVMATRIX));
		_11 = _22 = _33 = _44 = 1.0;
	}
	_SVMATRIX( const double * pd)
	{
#ifdef _DEBUG
		if(!pd)
			return;
#endif
		memcpy_s(&_11, sizeof(_SVMATRIX), pd, sizeof(_SVMATRIX));
	}
	_SVMATRIX( const SVBASEMATRIX &mat)
	{
		memcpy_s(&_11, sizeof(_SVMATRIX), &mat, sizeof(_SVMATRIX));
	}
	_SVMATRIX(	double d11, double d12, double d13, double d14,
				double d21, double d22, double d23, double d24,
				double d31, double d32, double d33, double d34,
				double d41, double d42, double d43, double d44 )
	{
		_11 = d11; _12 = d12; _13 = d13; _14 = d14;
		_21 = d21; _22 = d22; _23 = d23; _24 = d24;
		_31 = d31; _32 = d32; _33 = d33; _34 = d34;
		_41 = d41; _42 = d42; _43 = d43; _44 = d44;
	}
	_SVMATRIX( const double mat[4][4])
	{
		_11 = mat[0][0]; _12 = mat[0][1]; _13 = mat[0][2]; _14 = mat[0][3];
		_21 = mat[1][0]; _22 = mat[1][1]; _23 = mat[1][2]; _24 = mat[1][3];
		_31 = mat[2][0]; _32 = mat[2][1]; _33 = mat[2][2]; _34 = mat[2][3];
		_41 = mat[3][0]; _42 = mat[3][1]; _43 = mat[3][2]; _44 = mat[3][3];
	}
	_SVMATRIX( const float mat[4][4])
	{
		_11 = double(mat[0][0]); _12 = double(mat[0][1]); _13 = double(mat[0][2]); _14 = double(mat[0][3]);
		_21 = double(mat[1][0]); _22 = double(mat[1][1]); _23 = double(mat[1][2]); _24 = double(mat[1][3]);
		_31 = double(mat[2][0]); _32 = double(mat[2][1]); _33 = double(mat[2][2]); _34 = double(mat[2][3]);
		_41 = double(mat[3][0]); _42 = double(mat[3][1]); _43 = double(mat[3][2]); _44 = double(mat[3][3]);
	}
	_SVMATRIX( const BPBASEMATRIX &mat)
	{
		_11 = double(mat._11); _12 = double(mat._12); _13 = double(mat._13); _14 = double(mat._14);
		_21 = double(mat._21); _22 = double(mat._22); _23 = double(mat._23); _24 = double(mat._24);
		_31 = double(mat._31); _32 = double(mat._32); _33 = double(mat._33); _34 = double(mat._34);
		_41 = double(mat._41); _42 = double(mat._42); _43 = double(mat._43); _44 = double(mat._44);
	}

	// access grants
	double& operator () ( IKS_UINT uRow, IKS_UINT uCol )
	{
		return m[uRow][uCol];
	}
	double  operator () ( IKS_UINT uRow, IKS_UINT uCol ) const
	{
		return m[uRow][uCol];
	}

	// casting operators
	operator double* ()
	{
		return (double *) &_11;
	}
	operator const double* () const
	{
		return (const double *) &_11;
	}

	// assignment operators
	_SVMATRIX& operator *= ( const _SVMATRIX &mat)
	{
		_SVMATRIX matSrc = *this;
		for (int i=0; i<4; i++)
		{
			for (int j=0; j<4; j++)
			{
				m[i][j] = 0.0;
				for (int k=0; k<4; k++)
				{
					m[i][j] += matSrc.m[i][k] * mat.m[k][j];
				}
			}
		}
		return *this;
	}
	_SVMATRIX& operator += ( const _SVMATRIX &mat)
	{
		_11 += mat._11; _12 += mat._12; _13 += mat._13; _14 += mat._14;
		_21 += mat._21; _22 += mat._22; _23 += mat._23; _24 += mat._24;
		_31 += mat._31; _32 += mat._32; _33 += mat._33; _34 += mat._34;
		_41 += mat._41; _42 += mat._42; _43 += mat._43; _44 += mat._44;
		return *this;
	}
	_SVMATRIX& operator -= ( const _SVMATRIX &mat)
	{
		_11 -= mat._11; _12 -= mat._12; _13 -= mat._13; _14 -= mat._14;
		_21 -= mat._21; _22 -= mat._22; _23 -= mat._23; _24 -= mat._24;
		_31 -= mat._31; _32 -= mat._32; _33 -= mat._33; _34 -= mat._34;
		_41 -= mat._41; _42 -= mat._42; _43 -= mat._43; _44 -= mat._44;
		return *this;
	}
	_SVMATRIX& operator *= ( double d)
	{
		_11 *= d; _12 *= d; _13 *= d; _14 *= d;
		_21 *= d; _22 *= d; _23 *= d; _24 *= d;
		_31 *= d; _32 *= d; _33 *= d; _34 *= d;
		_41 *= d; _42 *= d; _43 *= d; _44 *= d;
		return *this;
	}
	_SVMATRIX& operator /= ( double d)
	{
		double dInv = 1.0f / d;
		_11 *= dInv; _12 *= dInv; _13 *= dInv; _14 *= dInv;
		_21 *= dInv; _22 *= dInv; _23 *= dInv; _24 *= dInv;
		_31 *= dInv; _32 *= dInv; _33 *= dInv; _34 *= dInv;
		_41 *= dInv; _42 *= dInv; _43 *= dInv; _44 *= dInv;
		return *this;
	}

	// unary operators
	_SVMATRIX operator + () const
	{
		return *this;
	}
	_SVMATRIX operator - () const
	{
		return _SVMATRIX(-_11, -_12, -_13, -_14,
						-_21, -_22, -_23, -_24,
						-_31, -_32, -_33, -_34,
						-_41, -_42, -_43, -_44);
	}

	// binary operators
	_SVMATRIX operator * ( const _SVMATRIX &mat) const
	{
		_SVMATRIX matT;
		for (int i=0; i<4; i++)
		{
			for (int j=0; j<4; j++)
			{
				matT.m[i][j] = 0.0;
				for (int k=0; k<4; k++)
				{
					matT.m[i][j] += this->m[i][k] * mat.m[k][j];
				}
			}
		}
		return matT;
	}
	_SVMATRIX operator + ( const _SVMATRIX &mat) const
	{
		return _SVMATRIX(_11 + mat._11, _12 + mat._12, _13 + mat._13, _14 + mat._14,
			_21 + mat._21, _22 + mat._22, _23 + mat._23, _24 + mat._24,
			_31 + mat._31, _32 + mat._32, _33 + mat._33, _34 + mat._34,
			_41 + mat._41, _42 + mat._42, _43 + mat._43, _44 + mat._44);
	}
	_SVMATRIX operator - ( const _SVMATRIX &mat) const
	{
		return _SVMATRIX(_11 - mat._11, _12 - mat._12, _13 - mat._13, _14 - mat._14,
						_21 - mat._21, _22 - mat._22, _23 - mat._23, _24 - mat._24,
						_31 - mat._31, _32 - mat._32, _33 - mat._33, _34 - mat._34,
						_41 - mat._41, _42 - mat._42, _43 - mat._43, _44 - mat._44);
	}
	_SVMATRIX operator * ( double d) const
	{
		return _SVMATRIX(_11 * d, _12 * d, _13 * d, _14 * d,
						_21 * d, _22 * d, _23 * d, _24 * d,
						_31 * d, _32 * d, _33 * d, _34 * d,
						_41 * d, _42 * d, _43 * d, _44 * d);
	}
	_SVMATRIX operator / ( double d) const
	{
		double dInv = 1.0 / d;
		return _SVMATRIX(_11 * dInv, _12 * dInv, _13 * dInv, _14 * dInv,
						_21 * dInv, _22 * dInv, _23 * dInv, _24 * dInv,
						_31 * dInv, _32 * dInv, _33 * dInv, _34 * dInv,
						_41 * dInv, _42 * dInv, _43 * dInv, _44 * dInv);
	}

	IKS_BOOL operator == ( const _SVMATRIX &mat) const
	{
		if (!ISDEQUAL(this->_11, mat._11) || !ISDEQUAL(this->_12, mat._12) || !ISDEQUAL(this->_13, mat._13) || !ISDEQUAL(this->_14, mat._14) 
		 || !ISDEQUAL(this->_21, mat._21) || !ISDEQUAL(this->_22, mat._22) || !ISDEQUAL(this->_23, mat._23) || !ISDEQUAL(this->_24, mat._24)
		 || !ISDEQUAL(this->_31, mat._31) || !ISDEQUAL(this->_32, mat._32) || !ISDEQUAL(this->_33, mat._33) || !ISDEQUAL(this->_34, mat._34)
		 || !ISDEQUAL(this->_41, mat._41) || !ISDEQUAL(this->_42, mat._42) || !ISDEQUAL(this->_43, mat._43) || !ISDEQUAL(this->_44, mat._44))
			return FALSE;
		return TRUE;
	}
	IKS_BOOL operator != ( const _SVMATRIX &mat) const
	{
		if (!ISDEQUAL(this->_11, mat._11) || !ISDEQUAL(this->_12, mat._12) || !ISDEQUAL(this->_13, mat._13) || !ISDEQUAL(this->_14, mat._14) 
		 || !ISDEQUAL(this->_21, mat._21) || !ISDEQUAL(this->_22, mat._22) || !ISDEQUAL(this->_23, mat._23) || !ISDEQUAL(this->_24, mat._24)
		 || !ISDEQUAL(this->_31, mat._31) || !ISDEQUAL(this->_32, mat._32) || !ISDEQUAL(this->_33, mat._33) || !ISDEQUAL(this->_34, mat._34)
		 || !ISDEQUAL(this->_41, mat._41) || !ISDEQUAL(this->_42, mat._42) || !ISDEQUAL(this->_43, mat._43) || !ISDEQUAL(this->_44, mat._44))
			return TRUE;
		return FALSE;
	}
} SVMATRIX;

// 可变长字符串
class CSVWString
{
public:
	CSVWString()
	{
		m_szBuffer = NULL;
		Copy(L"");
	}
	CSVWString(const wchar_t* szBuff)
	{
		m_szBuffer = NULL;
		if (szBuff == NULL)
			Copy(L"");
		else if (m_szBuffer != szBuff)
			Copy(szBuff);
	}
	CSVWString(const CSVWString& strString)
	{
		m_szBuffer = NULL;
		Copy(strString.m_szBuffer);
	}
	~CSVWString()
	{
		destroy();
	}

public:
	CSVWString& operator =(const wchar_t* szBuff)
	{
		if (m_szBuffer == szBuff)
			return (*this);
		Copy(szBuff);
		return (*this);
	}
	CSVWString& operator =(const CSVWString& strString)
	{
		if (this == &strString)
			return (*this);
		Copy(strString.m_szBuffer);
		return (*this);
	}
	wchar_t operator[](unsigned int dwPos) const
	{
		if (dwPos >= GetLength())
			return L'\0';
		return m_szBuffer[dwPos];
	}
	operator const wchar_t* () const { return m_szBuffer; }
	IKS_BOOL operator == ( const CSVWString &str) const
	{
		unsigned int nLength = GetLength();
		if (nLength != str.GetLength())
			return FALSE;
		return (0 == memcmp(GetBuffer(), str.GetBuffer(), sizeof(wchar_t)*nLength));
	}
	IKS_BOOL operator != ( const CSVWString &str) const
	{
		return (!((*this) == str));
	}
public:
	wchar_t* GetBuffer() const { return m_szBuffer; }
	unsigned int GetLength() const
	{
		if (m_szBuffer == NULL)
			return 0;
		else
			return wcslen(m_szBuffer);
	}
	void MakeUpper()
	{
		if (m_szBuffer == NULL)
			return;
		_wcsupr_s(m_szBuffer, wcslen(m_szBuffer)+1);

	}
	void MakeLower()
	{
		if (m_szBuffer == NULL)
			return;
		_wcslwr_s(m_szBuffer, wcslen(m_szBuffer)+1);
	}

protected:
	void Copy(const wchar_t* szBuff)
	{
		if (szBuff == m_szBuffer)
			return;
		int nSrcSize = 0;
		if (szBuff != NULL)
			nSrcSize = wcslen(szBuff);
		if (nSrcSize == 0)
		{
			if (m_szBuffer==NULL && szBuff!=NULL)
			{
				m_szBuffer = (wchar_t*)malloc(sizeof(wchar_t));
				memset(m_szBuffer, 0, sizeof(wchar_t));
			}
			else
			{
				int nDstSize = 0;
				if (m_szBuffer != NULL)
					nDstSize = wcslen(m_szBuffer);
				if (nDstSize > 0)
					memset(m_szBuffer, 0, sizeof(wchar_t)*(nDstSize));
			}
		}
		else
		{
			destroy();
			m_szBuffer = (wchar_t*)malloc((nSrcSize + 1) * sizeof(wchar_t));
			wcscpy_s(m_szBuffer, nSrcSize + 1, szBuff);
		}
	}
	void destroy()
	{
		if (m_szBuffer != NULL)
		{
			free(m_szBuffer);
			m_szBuffer = NULL;
		}
	}

private:
	wchar_t *m_szBuffer;
};


// 静态数组（其成员(直属或非直属)不允许出现动态数组或容器）
template<class _Ty>
class CBPStaticArray
{
public:
	enum { ARRAYMAXNUM = 8 };
	CBPStaticArray()
	{
		m_uSize = 0;
	}
	CBPStaticArray(const CBPStaticArray& _Right)
	{
		m_uSize = _Right.size();
		memcpy_s(m_szData, sizeof(_Ty)*ARRAYMAXNUM, _Right.begin(), sizeof(_Ty)*m_uSize);
	}
	~CBPStaticArray()
	{
		m_uSize = 0;
	}

	CBPStaticArray& operator=(const CBPStaticArray& _Right)
	{
		if (this == &_Right)
			return (*this);
		m_uSize = _Right.size();
		memcpy_s(m_szData, sizeof(_Ty)*ARRAYMAXNUM, _Right.begin(), sizeof(_Ty)*m_uSize);
		return (*this);
	}

	const _Ty* begin() const
	{
		return m_szData;
	}
	const _Ty* end() const
	{
		return m_szData + m_uSize;
	}
	void resize(unsigned int _Newsize)
	{
		if (_Newsize > ARRAYMAXNUM)
		{
			ASSERT(FALSE);
			m_uSize = ARRAYMAXNUM;
		}
		else
		{
			m_uSize = _Newsize;
		}
	}
	unsigned int size() const	{ return m_uSize; }
	unsigned int max_size() const	{ return ARRAYMAXNUM; }
	bool empty() const
	{	// test if sequence is empty
		return (m_uSize == 0);
	}
	const _Ty& operator[](unsigned int _Pos) const
	{
#if _DEBUG
		if (m_uSize <= _Pos)
		{
			ASSERT(FALSE);
		}
#endif
		return (*(m_szData + _Pos));
	}
	_Ty& operator[](unsigned int _Pos)
	{
#if _DEBUG
		if (m_uSize <= _Pos)
		{
			ASSERT(FALSE);
		}
#endif
		return (*(m_szData + _Pos));
	}
	_Ty& front()
	{	// return first element of mutable sequence
		return (*m_szData);
	}
	const _Ty& front() const
	{	// return first element of nonmutable sequence
		return (*m_szData);
	}
	_Ty& back()
	{	// return last element of mutable sequence
		return (*(m_szData + m_uSize - 1));
	}
	const _Ty& back() const
	{	// return last element of nonmutable sequence
		return (*(m_szData + m_uSize - 1));
	}
	void push_back(const _Ty& _Val)
	{
		if (m_uSize >= ARRAYMAXNUM)
			ASSERT(FALSE);
		else
		{
			m_szData[m_uSize] = _Val;
			m_uSize++;
		}
	}
	void pop_back()
	{
		if (empty())
			ASSERT(FALSE);
		else
			m_uSize--;
	}
	void clear() { m_uSize = 0; }
private:
	_Ty m_szData[ARRAYMAXNUM];
	unsigned int m_uSize;
};

// 动态数组(用法与std::vector类似)
// 注意:(1)其数据为一片连续内存;(2)其缓存大小(max_size())只会增加不会减少
// Note:适用于频繁改变数组长度的情况,节省频繁申请释放内存所花费的时间
template<class _Ty>
class CBPDynamicArray
{
public:
	CBPDynamicArray()
	{
		m_pData = NULL;
		m_uSize = 0;
		m_uMaxSize = 0;
	}
	CBPDynamicArray(const CBPDynamicArray& _Right)
	{
		m_pData = NULL;
		m_uSize = 0;
		m_uMaxSize = 0;
		resize(_Right.size());
		const _Ty *pSrc = _Right.begin();
		for (unsigned int i=0; i<m_uSize; i++)
			m_pData[i] = pSrc[i];
	}
	~CBPDynamicArray()
	{
		destroy();
	}

	CBPDynamicArray& operator=(const CBPDynamicArray& _Right)
	{
		if (this == &_Right)
			return (*this);
		resize(_Right.size());
		const _Ty *pSrc = _Right.begin();
		for (unsigned int i=0; i<m_uSize; i++)
			m_pData[i] = pSrc[i];
		return (*this);
	}

	const _Ty* begin() const
	{
		return m_pData;
	}
	const _Ty* end() const
	{
		return m_pData + m_uSize;
	}
	void resize(unsigned int _Newsize)
	{
		if (_Newsize > m_uMaxSize)
		{
			m_uMaxSize = _Newsize;
			_Ty* pData = new _Ty[m_uMaxSize];
			for (unsigned int i=0; i<m_uSize; i++)
				pData[i] = m_pData[i];
			SAFE_DELETE_ARRAY(m_pData);
			m_pData = pData;
		}
		m_uSize = _Newsize;
	}
	unsigned int size() const	{ return m_uSize; }
	unsigned int max_size() const	{ return m_uMaxSize; }
	bool empty() const
	{	// test if sequence is empty
		return (m_uSize == 0);
	}
	const _Ty& operator[](unsigned int _Pos) const
	{
#if _DEBUG
		if (m_uSize <= _Pos)
		{
			ASSERT(FALSE);
		}
#endif
		return (*(m_pData + _Pos));
	}
	_Ty& operator[](unsigned int _Pos)
	{
#if _DEBUG
		if (m_uSize <= _Pos)
		{
			ASSERT(FALSE);
		}
#endif
		return (*(m_pData + _Pos));
	}
	_Ty& front()
	{	// return first element of mutable sequence
		return (*m_pData);
	}
	const _Ty& front() const
	{	// return first element of nonmutable sequence
		return (*m_pData);
	}
	_Ty& back()
	{	// return last element of mutable sequence
		return (*(m_pData + m_uSize - 1));
	}
	const _Ty& back() const
	{	// return last element of nonmutable sequence
		return (*(m_pData + m_uSize - 1));
	}
	void push_back(const _Ty& _Val)
	{
		unsigned int uNewIndex = m_uSize;
		if (uNewIndex >= m_uMaxSize)
			resize( (uNewIndex+1)*2 );
		m_pData[uNewIndex] = _Val;
		m_uSize = uNewIndex + 1;
	}
	void pop_back()
	{
		if (empty())
			ASSERT(FALSE);
		else
			m_uSize--;
	}
	void clear() { m_uSize = 0; }
	void destroy()
	{
		SAFE_DELETE_ARRAY(m_pData);
		m_uSize = 0;
		m_uMaxSize = 0;
	}
	void erase(unsigned int uIndex)
	{
		if (uIndex >= m_uSize)
			return;
		for (unsigned int i=uIndex; i<m_uSize-1; i++)
			m_pData[i] = m_pData[i+1];
		m_uSize--;
	}
private:
	_Ty* m_pData;
	unsigned int m_uSize;
	unsigned int m_uMaxSize;
};

// 动态数组Vector(用法与std::vector类似)
// 注意:(1)其数据为一片连续内存;(2)其缓存大小(max_size())会随着vector尺寸(size())而变化
template<class _Ty>
class CSVVector
{
public:
	CSVVector()
	{
		m_pData = NULL;
		m_uSize = 0;
		m_uMaxSize = 0;
	}
	CSVVector(const CSVVector& _Right)
	{
		m_pData = NULL;
		m_uSize = 0;
		m_uMaxSize = 0;
		resize(_Right.size());
		const _Ty *pSrc = _Right.begin();
		for (unsigned int i=0; i<m_uSize; i++)
			m_pData[i] = pSrc[i];
	}
	~CSVVector()
	{
		destroy();
	}

	CSVVector& operator=(const CSVVector& _Right)
	{
		if (this == &_Right)
			return (*this);
		resize(_Right.size());
		const _Ty *pSrc = _Right.begin();
		for (unsigned int i=0; i<m_uSize; i++)
			m_pData[i] = pSrc[i];
		return (*this);
	}

	const _Ty* begin() const
	{
		return m_pData;
	}
	const _Ty* end() const
	{
		return m_pData + m_uSize;
	}
	void resize(unsigned int _Newsize)
	{
		if (_Newsize == 0)
			destroy();
		else
		{
			if (_Newsize != m_uMaxSize)
			{
				m_uMaxSize = _Newsize;
				_Ty* pData = new _Ty[m_uMaxSize];
				if (pData != NULL)
				{
					unsigned int uCopySize = m_uSize;
					if (uCopySize > m_uMaxSize)
						uCopySize = m_uMaxSize;
					for (unsigned int i=0; i<uCopySize; i++)
						pData[i] = m_pData[i];
					SAFE_DELETE_ARRAY(m_pData);
					m_pData = pData;
				}
			}
			m_uSize = _Newsize;
			if (m_pData == NULL)
				destroy();
		}
	}
	unsigned int size() const	{ return m_uSize; }
	unsigned int max_size() const	{ return m_uMaxSize; }
	bool empty() const
	{	// test if sequence is empty
		return (m_uSize == 0);
	}
	const _Ty& operator[](unsigned int _Pos) const
	{
#if _DEBUG
		if (m_uSize <= _Pos)
		{
			ASSERT(FALSE);
		}
#endif
		return (*(m_pData + _Pos));
	}
	_Ty& operator[](unsigned int _Pos)
	{
#if _DEBUG
		if (m_uSize <= _Pos)
		{
			ASSERT(FALSE);
		}
#endif
		return (*(m_pData + _Pos));
	}
	_Ty& front()
	{	// return first element of mutable sequence
		return (*m_pData);
	}
	const _Ty& front() const
	{	// return first element of nonmutable sequence
		return (*m_pData);
	}
	_Ty& back()
	{	// return last element of mutable sequence
		return (*(m_pData + m_uSize - 1));
	}
	const _Ty& back() const
	{	// return last element of nonmutable sequence
		return (*(m_pData + m_uSize - 1));
	}
	void push_back(const _Ty& _Val)
	{
		unsigned int uNewIndex = m_uSize;
		if (uNewIndex >= m_uMaxSize)
			resize( (uNewIndex+1) + (uNewIndex+1)/2 );
		m_pData[uNewIndex] = _Val;
		m_uSize = uNewIndex + 1;
	}
	void pop_back()
	{
		if (empty())
			ASSERT(FALSE);
		else
		{
			m_uSize--;
			if (m_uMaxSize > m_uSize*3/2)
				resize(m_uSize);
		}
	}
	void clear()
	{
		destroy();
	}
	void erase(unsigned int uIndex)
	{
		if (uIndex >= m_uSize)
			return;
		for (unsigned int i=uIndex; i<m_uSize-1; i++)
			m_pData[i] = m_pData[i+1];
		m_uSize--;
		if (m_uMaxSize > m_uSize*3/2)
			resize(m_uSize);
	}
protected:
	void destroy()
	{
		SAFE_DELETE_ARRAY(m_pData);
		m_uSize = 0;
		m_uMaxSize = 0;
	}
private:
	_Ty* m_pData;
	unsigned int m_uSize;
	unsigned int m_uMaxSize;
};

// 动态数组-数据类Vector
// 注意:(1)其数据为一片连续内存;(2)其缓存大小(max_size())会随着vector尺寸(size())而变化;
// Note:只适用于成员是纯数据的情况,即成员无需调用构造函数和析构函数,例如int,float,double等
template<class _Ty>
class CSVDataVector
{
public:
	CSVDataVector()
	{
		m_pData = NULL;
		m_uSize = 0;
		m_uMaxSize = 0;
	}
	CSVDataVector(const CSVDataVector& _Right)
	{
		m_pData = NULL;
		m_uSize = 0;
		m_uMaxSize = 0;
		resize(_Right.size());
		if (m_uSize > 0)
			memcpy_s(m_pData, m_uSize*sizeof(_Ty), _Right.begin(), _Right.size()*sizeof(_Ty));
	}
	~CSVDataVector()
	{
		destroy();
	}

	CSVDataVector& operator=(const CSVDataVector& _Right)
	{
		if (this == &_Right)
			return (*this);
		resize(_Right.size());
		if (m_uSize > 0)
			memcpy_s(m_pData, m_uSize*sizeof(_Ty), _Right.begin(), _Right.size()*sizeof(_Ty));
		return (*this);
	}

	const _Ty* begin() const
	{
		return m_pData;
	}
	const _Ty* end() const
	{
		return m_pData + m_uSize;
	}
	void resize(unsigned int _Newsize)
	{
		if (_Newsize == 0)
			destroy();
		else
		{
			if (_Newsize != m_uMaxSize)
			{
				m_uMaxSize = _Newsize;
				_Ty* pData = (_Ty*)malloc(m_uMaxSize * sizeof(_Ty));
				if (pData != NULL)
				{
					unsigned int uCopySize = m_uSize;
					if (uCopySize > m_uMaxSize)
						uCopySize = m_uMaxSize;
					if (uCopySize > 0)
						memcpy_s(pData, uCopySize*sizeof(_Ty), m_pData, uCopySize*sizeof(_Ty));
					if (m_pData != NULL)
						free(m_pData);
					m_pData = pData;
				}
			}
			m_uSize = _Newsize;
			if (m_pData == NULL)
				destroy();
		}
	}
	unsigned int size() const	{ return m_uSize; }
	unsigned int max_size() const	{ return m_uMaxSize; }
	bool empty() const
	{	// test if sequence is empty
		return (m_uSize == 0);
	}
	const _Ty& operator[](unsigned int _Pos) const
	{
#if _DEBUG
		if (m_uSize <= _Pos)
		{
			ASSERT(FALSE);
		}
#endif
		return (*(m_pData + _Pos));
	}
	_Ty& operator[](unsigned int _Pos)
	{
#if _DEBUG
		if (m_uSize <= _Pos)
		{
			ASSERT(FALSE);
		}
#endif
		return (*(m_pData + _Pos));
	}
	_Ty& front()
	{	// return first element of mutable sequence
		return (*m_pData);
	}
	const _Ty& front() const
	{	// return first element of nonmutable sequence
		return (*m_pData);
	}
	_Ty& back()
	{	// return last element of mutable sequence
		return (*(m_pData + m_uSize - 1));
	}
	const _Ty& back() const
	{	// return last element of nonmutable sequence
		return (*(m_pData + m_uSize - 1));
	}
	void push_back(const _Ty& _Val)
	{
		unsigned int uNewIndex = m_uSize;
		if (uNewIndex >= m_uMaxSize)
			resize( (uNewIndex+1) + (uNewIndex+1)/2 );
		m_pData[uNewIndex] = _Val;
		m_uSize = uNewIndex + 1;
	}
	void pop_back()
	{
		if (empty())
			ASSERT(FALSE);
		else
		{
			m_uSize--;
			if (m_uMaxSize > m_uSize*3/2)
				resize(m_uSize);
		}
	}
	void clear()
	{
		destroy();
	}
	void erase(unsigned int uIndex)
	{
		if (uIndex >= m_uSize)
			return;
		for (unsigned int i=uIndex; i<m_uSize-1; i++)
			memcpy_s(&(m_pData[i]), sizeof(_Ty), &(m_pData[i+1]), sizeof(_Ty));
		m_uSize--;
		if (m_uMaxSize > m_uSize*3/2)
			resize(m_uSize);
	}
protected:
	void destroy()
	{
		if (m_pData != NULL)
		{
			free(m_pData);
			m_pData = NULL;
		}
		m_uSize = 0;
		m_uMaxSize = 0;
	}
private:
	_Ty* m_pData;
	unsigned int m_uSize;
	unsigned int m_uMaxSize;
};

// 动态数组-碎片Vector
// 注意:(1)其数据不是一片连续内存;(因此也不需要缓存;)
// Note:适用于sizeof(_Ty)较大(起码比sizeof(void*)大)的情况,避免申请大片连续内存失败的情况;
template<class _Ty>
class CSVChipVector
{
public:
	CSVChipVector()	{}
	CSVChipVector(const CSVChipVector& _Right)
	{
		resize(_Right.size());
		for (unsigned int i=0; i<m_arrDataPt.size(); i++)
			*(m_arrDataPt[i]) = _Right[i];
	}
	~CSVChipVector()
	{
		destroy();
	}

	CSVChipVector& operator=(const CSVChipVector& _Right)
	{
		if (this == &_Right)
			return (*this);
		resize(_Right.size());
		for (unsigned int i=0; i<m_arrDataPt.size(); i++)
			*(m_arrDataPt[i]) = _Right[i];
		return (*this);
	}

	void resize(unsigned int _Newsize)
	{
		if (_Newsize > m_arrDataPt.size())
		{
			unsigned int uOriSize = m_arrDataPt.size();
			m_arrDataPt.resize(_Newsize);
			for (unsigned int i=uOriSize; i<m_arrDataPt.size(); i++)
				m_arrDataPt[i] = NewElement();
		}
		else if (_Newsize < m_arrDataPt.size())
		{
			for (unsigned int i=_Newsize; i<m_arrDataPt.size(); i++)
				DelElement(i);
			m_arrDataPt.resize(_Newsize);
		}
	}
	unsigned int size() const	{ return m_arrDataPt.size(); }
	bool empty() const
	{	// test if sequence is empty
		return m_arrDataPt.empty();
	}
	const _Ty& operator[](unsigned int _Pos) const
	{
#if _DEBUG
		if (m_arrDataPt.size() <= _Pos)
		{
			ASSERT(FALSE);
		}
#endif
		return (*(m_arrDataPt[_Pos]));
	}
	_Ty& operator[](unsigned int _Pos)
	{
#if _DEBUG
		if (m_arrDataPt.size() <= _Pos)
		{
			ASSERT(FALSE);
		}
#endif
		return (*(m_arrDataPt[_Pos]));
	}
	_Ty& front()
	{	// return first element of mutable sequence
		return (*(m_arrDataPt.front()));
	}
	const _Ty& front() const
	{	// return first element of nonmutable sequence
		return (*(m_arrDataPt.front()));
	}
	_Ty& back()
	{	// return last element of mutable sequence
		return (*(m_arrDataPt.back()));
	}
	const _Ty& back() const
	{	// return last element of nonmutable sequence
		return (*(m_arrDataPt.back()));
	}
	void push_back(const _Ty& _Val)
	{
		_Ty* pNewElem = NewElement();
		(*pNewElem) = _Val;
		m_arrDataPt.push_back(pNewElem);
	}
	void pop_back()
	{
		if (empty())
			ASSERT(FALSE);
		else
		{
			DelElement(m_arrDataPt.size()-1);
			m_arrDataPt.pop_back();
		}
	}
	void clear()
	{
		destroy();
	}
	void erase(unsigned int uIndex)
	{
		if (uIndex >= m_arrDataPt.size())
			return;
		DelElement(uIndex);
		m_arrDataPt.erase(uIndex);
	}
protected:
	void destroy()
	{
		for (unsigned int i=0; i<m_arrDataPt.size(); i++)
			DelElement(i);
		m_arrDataPt.clear();
	}
	_Ty* NewElement()
	{
		return (new _Ty());
	}
	void DelElement(unsigned int uIndex)
	{
		delete m_arrDataPt[uIndex];
		m_arrDataPt[uIndex] = NULL;
	}
private:
	CSVDataVector<_Ty*> m_arrDataPt;
};
