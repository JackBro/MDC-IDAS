//===========================================================================
// Summary:
//		对UnicodeString的跨平台修改
//===========================================================================

#ifndef	__UNICODESTRING_HEADERFILE__
#define __UNICODESTRING_HEADERFILE__

///////////////////////////////////////////////////////////////////////////////

// 多字节字符串的编码方式
enum  DK_MULTIBYTE_TYPE
{
	DK_MULTIBYTE_SYSDEFAULT = 0,	// 采用系统设置

	DK_MULTIBYTE_UTF8 = 1,			// UTF-8

	DK_MULTIBYTE_ZH_CN,				// 简体中文(GBK/GB2312)
	DK_MULTIBYTE_ZH_TW,				// 繁体中文(BIG5)
};

///////////////////////////////////////////////////////////////////////////////

bool IsValidString(const char* lpsz, int nLength = -1);
bool IsValidString(const wchar_t* lpsz, int nLength = -1);

///////////////////////////////////////////////////////////////////////////////

class CUnicodeString  
{
public:
	CUnicodeString();
	CUnicodeString(const wchar_t* pstrString);
	CUnicodeString(const char* pstrString, DK_MULTIBYTE_TYPE type = DK_MULTIBYTE_SYSDEFAULT);
	CUnicodeString(const CUnicodeString& strString);
	~CUnicodeString();

public:
	int FindOneOf(const char* lpszCharSet) const;
	int FindOneOf(const wchar_t* lpszCharSet) const;
	int ReverseFind(char ch) const;
	int ReverseFind(wchar_t ch) const;
	int Find(char ch, unsigned int nStart = 0) const;
	int Find(wchar_t ch, unsigned int nStart = 0) const;
	int Find(const char* lpszSub, unsigned int nStart = 0) const;
	int Find(const wchar_t* lpszSub, unsigned int nStart = 0) const;
	void TrimRight(const char* lpszTargets);
	void TrimRight(const wchar_t* lpszTargets);
	void TrimRight(char chTarget);
	void TrimRight(wchar_t chTarget);
	void TrimRight();
	void TrimLeft(const char* lpszTargets);
	void TrimLeft(const wchar_t* lpszTargets);
	void TrimLeft(char chTarget);
	void TrimLeft(wchar_t chTarget);
	void TrimLeft();
	unsigned int Delete(unsigned int nIndex, unsigned int nCount = 1);
	unsigned int Insert(unsigned int nIndex, const char* pstr);
	unsigned int Insert(unsigned int nIndex, const wchar_t* pstr);
	unsigned int Insert(unsigned int nIndex, char ch);
	unsigned int Insert(unsigned int nIndex, wchar_t ch);
	unsigned int Remove(char ch);
	unsigned int Remove(wchar_t ch);
	void MakeReverse();
	void MakeLower();
	void MakeUpper();
	CUnicodeString SpanExcluding(const char* lpszCharSet);
	CUnicodeString SpanExcluding(const wchar_t* lpszCharSet);
	CUnicodeString SpanIncluding(const char* lpszCharSet);
	CUnicodeString SpanIncluding(const wchar_t* lpszCharSet);
	int CollateNoCase(const char* lpsz) const;
	int CollateNoCase(const wchar_t* lpsz) const;
	int Collate(const char* lpsz) const;
	int Collate(const wchar_t* lpsz) const;
	int CompareNoCase(const char* lpsz) const;
	int CompareNoCase(const wchar_t* lpsz) const;
	int Compare(const char* lpsz) const;
	int Compare(const wchar_t* lpsz) const;
	void SetAt(unsigned long dwPos, char ch);
	void SetAt(unsigned long dwPos, wchar_t ch);
	void Empty();
	bool IsEmpty() const;
	wchar_t* GetBuffer() const;
	// 复制字符串并返回字符数组，内存由调用者负责释放
	wchar_t* DuplicateBuffer() const;
	void SetSize(unsigned int dwSize);
	CUnicodeString Mid(unsigned int dwStart, unsigned int dwCount) const;
	CUnicodeString Right(unsigned int dwCount) const;
	CUnicodeString Left(unsigned int dwCount) const;
	int GetSubStringBy(const char* lpsz, int nCount, CUnicodeString& strSub);
	int GetSubStringBy(const wchar_t* lpsz, int nCount, CUnicodeString& strSub);
	void Format(const wchar_t* pstrFormat, ...);
	void Format(const char* pstrFormat, ...);
	unsigned int GetLength() const { return m_Length; }
	CUnicodeString& operator =(const CUnicodeString& strString);
	CUnicodeString& operator =(const wchar_t* pstrString);
	CUnicodeString& operator =(const char* pstrString);
	CUnicodeString& operator =(wchar_t ch);
	CUnicodeString& operator =(char ch);
	void operator += (const CUnicodeString& usString);
	void operator += (const wchar_t* pstrString);
	void operator += (const char* pstrString);
	void operator += (wchar_t wch);
	void operator += (char ch);

	friend CUnicodeString operator+(const CUnicodeString& s1, const CUnicodeString& s2);
	friend CUnicodeString operator+(const CUnicodeString& s, const char* pstrString);
	friend CUnicodeString operator+(const char* pstrString, const CUnicodeString& s);
	friend CUnicodeString operator+(const CUnicodeString& s, const char ch);
	friend CUnicodeString operator+(const char ch, const CUnicodeString& s);
	friend CUnicodeString operator+(const CUnicodeString& s, const wchar_t* pstrString);
	friend CUnicodeString operator+(const wchar_t* pstrString, const CUnicodeString& s);
	friend CUnicodeString operator+(const CUnicodeString& s, const wchar_t ch);
	friend CUnicodeString operator+(const wchar_t ch, const CUnicodeString& s);
	friend bool operator ==(const CUnicodeString& s1, const CUnicodeString& s2);
	friend bool operator ==(const CUnicodeString& s1, const wchar_t* s2);
	friend bool operator ==(const CUnicodeString& s1, const char* s2);
	friend bool operator ==(const wchar_t* s1, const CUnicodeString& s2);
	friend bool operator ==(const char* s1, const CUnicodeString& s2);
	friend bool operator !=(const CUnicodeString& s1, const CUnicodeString& s2);
	friend bool operator !=(const CUnicodeString& s1, const wchar_t* s2);
	friend bool operator !=(const CUnicodeString& s1, const char* s2);
	friend bool operator !=(const wchar_t* s1, const CUnicodeString& s2);
	friend bool operator !=(const char* s1, const CUnicodeString& s2);

	wchar_t operator[](unsigned int dwPos) const;
	wchar_t GetAt(unsigned int dwPos) const;

	operator const wchar_t* () const { return m_Buffer; }
	operator const char* () { return ToMultiByte(DK_MULTIBYTE_SYSDEFAULT); }

	// 从UTF8字符串赋值
	CUnicodeString& AssignUTF8(const char* pstrString);
	// 转为UTF8字符串
	const char* AsUTF8() { return ToMultiByte(DK_MULTIBYTE_UTF8); }
	// 转换为单字节字符
	const char* ToMultiByte(DK_MULTIBYTE_TYPE type = DK_MULTIBYTE_SYSDEFAULT);

	// 从UTF16字节数组赋值
	CUnicodeString& AssignUTF16(const unsigned char* pDataBuffer, long lLen);

protected:
	bool InitializeFromWideString(const wchar_t* pstrString);
	bool InitializeFromString(const char* pstrString, DK_MULTIBYTE_TYPE type);
	void Init() { m_Buffer = &m_chNil; }

protected:
	inline void ReleaseBuffer() 
	{ 
		if (m_Buffer != &m_chNil)
		{
			free(m_Buffer); 
			m_Buffer = &m_chNil;
		}		
	}

protected:
	unsigned int			m_Length;
	wchar_t*		m_Buffer;
	char*			m_TempBuff;
	
public:
	static wchar_t	m_chNil;
};

// CUnicodeString排序
bool UnicodeStringComp(const CUnicodeString& strCmp1, const CUnicodeString& strCmp2);

///////////////////////////////////////////////////////////////////////////////

#endif // #ifndef __UNICODESTRING_HEADERFILE__

