﻿#include "..\mojibake.h"

LIBRARY_EXPORT int DetourShellAboutA(
    _In_opt_    HWND hWnd,
    _In_        LPCSTR szApp,
    _In_opt_    LPCSTR szOtherStuff,
    _In_opt_    HICON hIcon
    )
{
    LPWSTR uszApp = AnsiToUnicode(szApp);
    LPWSTR uszOtherStuff = AnsiToUnicode(szOtherStuff);
    int Result = ShellAbout(hWnd, uszApp, uszOtherStuff, hIcon);

    DWORD LastError = GetLastError();
    HeapFree(hHeap, 0, uszApp);
    HeapFree(hHeap, 0, uszOtherStuff);
    SetLastError(LastError);
    return Result;
}