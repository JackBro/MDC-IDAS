#include "StdAfx.h"
#include "Tracer.h"
#include "AFXMT.h"

static HANDLE g_hTraceThread = NULL;
static HWND g_hTraceWnd = NULL;
static HWND g_hEditCtrl = NULL;
static CCriticalSection g_csTrace;

static DWORD WINAPI TraceThreadProc(LPVOID lpParam);
static LRESULT CALLBACK TraceWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#define WS_EX_NOACTIVATE        0x08000000L

DWORD WINAPI TraceThreadProc(LPVOID lpParam)
{
	HANDLE hTraceWndCreatedEvent = (HANDLE)lpParam;

	INT cxScreen = GetSystemMetrics(SM_CXSCREEN);
	INT cyScreen = GetSystemMetrics(SM_CYSCREEN);
	INT cxMargin = 20;
	INT cyMargin = 20;
	INT height = 200;
	
	WNDCLASS wcs = { 0 };
	wcs.hInstance = NULL;
	wcs.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcs.hIcon = NULL;
	wcs.hCursor = (HCURSOR)LoadCursor(NULL, IDC_ARROW);
	wcs.lpfnWndProc = TraceWndProc;
	wcs.lpszClassName = _T("Tracer");
	wcs.lpszMenuName = NULL;
	wcs.style = CS_VREDRAW | CS_HREDRAW | CS_NOCLOSE;
	wcs.cbClsExtra = 0;
	wcs.cbWndExtra = 0;
	g_hTraceWnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_NOACTIVATE, (LPCTSTR)RegisterClass(&wcs), _T("Tracer"), WS_OVERLAPPEDWINDOW, cxMargin, cyScreen - cyMargin - height, cxScreen - 2 * cxMargin, height, NULL, NULL, NULL, NULL);
	
	RECT rcClient = { 0 };
	GetClientRect(g_hTraceWnd, &rcClient);
	g_hEditCtrl = CreateWindow(_T("Edit"), _T(""), WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_READONLY, 0, 0, rcClient.right, rcClient.bottom, g_hTraceWnd, NULL, NULL, NULL);
	
	ShowWindow(g_hTraceWnd, SW_SHOWNOACTIVATE);
	SetEvent(hTraceWndCreatedEvent);

	MSG msg = { 0 };
	BOOL bRet = FALSE;
	while ((bRet = GetMessage(&msg, NULL, NULL, NULL)) == TRUE)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK TraceWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return CallWindowProc(DefWindowProc, hWnd, uMsg, wParam, lParam);
}


static void CreateTraceThread()
{
	if (g_hTraceThread == NULL)
	{
		HANDLE hTraceWndCreatedEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
		g_hTraceThread = CreateThread(NULL, 0, TraceThreadProc, (LPVOID)hTraceWndCreatedEvent, 0, NULL);
		WaitForSingleObject(hTraceWndCreatedEvent, INFINITE);
		CloseHandle(hTraceWndCreatedEvent);
	}
}

void CTracer::Trace(LPCTSTR pFormat, ...)
{
	g_csTrace.Lock();
	CreateTraceThread();

	va_list argList;
	va_start(argList, pFormat);

	CString strMessage;
	strMessage.FormatV(pFormat, argList);
	INT nLength = GetWindowTextLength(g_hEditCtrl);
	SendMessage(g_hEditCtrl, EM_SETSEL, nLength, nLength);
	SendMessage(g_hEditCtrl, EM_REPLACESEL, FALSE, (LPARAM)(LPCTSTR)strMessage);

	va_end(argList);
	g_csTrace.Unlock();
}

