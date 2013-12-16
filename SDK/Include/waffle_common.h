#ifndef __SDK_WAFFLE_COMMON_H_
#define __SDK_WAFFLE_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef  _BUILD_WAFFLE_COMMON_DLL_
#define WAFFLE_COMMON_DLL_FUNCTION LIBRARY_EXPORT
#else

#if     defined(_MSC_VER)
#define WAFFLE_COMMON_DLL_FUNCTION LIBRARY_IMPORT
#else
#define WAFFLE_COMMON_DLL_FUNCTION
#endif

#endif

    /*
    libraryarray.c
    */
    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WaffleFindLibrary(
        _In_    LPVOID lpMemory
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleCopyLibrary(
        _In_    LPWAFFLE_LIBRARY_ARRAY lpstNewLibrary
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleAddLibrary(
        _In_    HMODULE hModule
        );

    /*
    functionarray.c
    */
    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleAddFunction(
        _In_    LPWAFFLE_FUNCTION_ARRAY lpstNewFunction,
        _In_    HMODULE hDetour
        );

    WAFFLE_COMMON_DLL_FUNCTION LPVOID WINAPI WaffleGetBackupAddress(
        _In_    LPCTSTR lpszLibrary,
        _In_    LPCTSTR lpszFunction
        );

    WAFFLE_COMMON_DLL_FUNCTION SIZE_T WINAPI WaffleFindDetourAddress(
        _In_    PVOID ExceptionAddress,
        _In_    PVOID CallerAddress
        );
    /*
    componentarray.c
    */
    WAFFLE_COMMON_DLL_FUNCTION HMODULE WINAPI WaffleLoadComponent(
        _In_    LPCTSTR lpszComponent
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleAddComponent(
        _In_    LPCTSTR lpszComponent
        );
    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WaffleFindComponent(
        _In_    LPVOID lpMemory
        );
    /*
    cmdarg.c
    */
    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WaffleArgc(VOID);

    typedef int (WINAPI *LPWAFFLEARGC)(VOID);

    WAFFLE_COMMON_DLL_FUNCTION SIZE_T WINAPI WaffleArgv(
        _In_    int intPosition,
        _In_    LPTSTR lpString,
        _In_    int intSize
        );

    typedef SIZE_T(WINAPI *LPWAFFLEARGV)(
        _In_    int intPosition,
        _In_    LPTSTR lpString,
        _In_    int intSize
        );

    WAFFLE_COMMON_DLL_FUNCTION LPCTSTR WINAPI WaffleArgp(
        _In_    int intPosition
        );

    typedef LPCTSTR(WINAPI *LPWAFFLEARGP)(
        _In_    int intPosition
        );
    /*
    detour.c
    */
    WAFFLE_COMMON_DLL_FUNCTION BOOL WINAPI WaffleSetDetour(
        _In_    DWORD dwLibrary,
        _In_    DWORD dwFunction
        );

    WAFFLE_COMMON_DLL_FUNCTION BOOL WINAPI WaffleAddDetour(
        _In_    LPBYTE lpSource,
        _In_    LPCTSTR lpszFunction,
        _In_    HMODULE hDetour
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleLoadDetourOption(VOID);
    /*
    exception.c
    */
    WAFFLE_COMMON_DLL_FUNCTION BOOL WINAPI WaffleInlineDetour(
        _In_    LPBYTE  lpFunction
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WaffleInlineHandler(
        _In_    SIZE_T *lpReserved
        );

    WAFFLE_COMMON_DLL_FUNCTION BOOL WINAPI WaffleExceptionDetour(
        _In_    LPBYTE  lpFunction
        );

    WAFFLE_COMMON_DLL_FUNCTION LONG CALLBACK WaffleExceptionHandler(
        _In_    PEXCEPTION_POINTERS ExceptionInfo
        );
    /*
    filesystem.c
    */
    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleGetModuleDirectory(
        _In_opt_    HMODULE hModule,
        _Out_       LPTSTR lpFilename,
        _In_        DWORD nSize
        );

    typedef VOID(WINAPI *LPWAFFLEGETMODULEDIRECTORY)(
        _In_opt_    HMODULE hModule,
        _Out_       LPTSTR lpFilename,
        _In_        DWORD nSize
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleDisableWow64FsRedirection(
        _Inout_ PVOID *OldValue
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleRevertWow64FsRedirection(
        _In_    PVOID OldValue
        );
    /*
    hash.c
    */
    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleGetFileHash(
        _In_    LPCTSTR lpszFile,
        _Out_   LPTSTR lpszResult
        );

    typedef VOID(WINAPI *LPWAFFLEGETFILEHASH)(
        _In_    LPCTSTR lpszFile,
        _Out_   LPTSTR lpszResult
        );
    /*
    init.c
    */
    WAFFLE_COMMON_DLL_FUNCTION SIZE_T WINAPI WaffleInit(
        _In_    LPVOID lpReserved
        );

    typedef SIZE_T(WINAPI *LPWAFFLEINIT)(
        _In_    LPVOID lpReserved
        );
    /*
    inject.c
    */
    WAFFLE_COMMON_DLL_FUNCTION BOOL WINAPI WaffleCreateProcess(
        _In_opt_    LPCTSTR lpApplicationName,
        _Inout_opt_ LPTSTR lpCommandLine,
        _In_opt_    LPSECURITY_ATTRIBUTES lpProcessAttributes,
        _In_opt_    LPSECURITY_ATTRIBUTES lpThreadAttributes,
        _In_        BOOL bInheritHandles,
        _In_        DWORD dwCreationFlags,
        _In_opt_    LPVOID lpEnvironment,
        _In_opt_    LPCTSTR lpCurrentDirectory,
        _In_opt_    LPSTARTUPINFO lpStartupInfo,
        _Out_opt_   LPPROCESS_INFORMATION lpProcessInformation
        );

    typedef BOOL(WINAPI *LPWAFFLECREATEPROCESS)(
        _In_opt_    LPCTSTR lpApplicationName,
        _Inout_opt_ LPTSTR lpCommandLine,
        _In_opt_    LPSECURITY_ATTRIBUTES lpProcessAttributes,
        _In_opt_    LPSECURITY_ATTRIBUTES lpThreadAttributes,
        _In_        BOOL bInheritHandles,
        _In_        DWORD dwCreationFlags,
        _In_opt_    LPVOID lpEnvironment,
        _In_opt_    LPCTSTR lpCurrentDirectory,
        _In_opt_    LPSTARTUPINFO lpStartupInfo,
        _Out_opt_   LPPROCESS_INFORMATION lpProcessInformation
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleInjectDll(
        _In_    HANDLE hProcess,
        _In_    HANDLE hThread,
        _In_    LPCTSTR lpszDllFull
        );

    typedef VOID(WINAPI *LPWAFFLEINJECTDLL)(
        _In_    HANDLE hProcess,
        _In_    HANDLE hThread,
        _In_    LPCTSTR lpszDllFull
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleExecute(
        _Out_opt_   LPWAFFLE_PROCESS_SETTING lpstProcessSetting,
        _In_opt_    LPCTSTR lpApplicationName,
        _Inout_opt_ LPTSTR lpCommandLine,
        _In_opt_    LPCTSTR lpCurrentDirectory
        );

    typedef VOID(WINAPI *LPWAFFLEEXECUTE)(
        _Out_opt_   LPWAFFLE_PROCESS_SETTING lpstProcessSetting,
        _In_opt_    LPCTSTR lpApplicationName,
        _Inout_opt_ LPTSTR lpCommandLine,
        _In_opt_    LPCTSTR lpCurrentDirectory
        );
    /*
    logfile.c
    */
    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleWriteLogFileA(
        _In_    LPCSTR lpszMessage
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleWriteLogFileW(
        _In_    LPCWSTR lpszMessage
        );
    /*
    option.c
    */
    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleCheckOptionEncoding(
        _In_    LPCTSTR lpFileName
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleGetOptionString(
        _In_        LPCTSTR lpszKeyName,
        _Inout_     LPTSTR lpszValue,
        _In_        DWORD nSize,
        _In_opt_    LPTSTR lpszDefaultValue
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleSetOptionString(
        _In_    LPCTSTR lpszKeyName,
        _In_    LPCTSTR lpszValue,
        _In_    BOOL bGlobal
        );

    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WaffleGetOptionInt(
        _In_        LPCTSTR lpszKeyName,
        _In_opt_    int nDefaultValue
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleSetOptionInt(
        _In_    LPCTSTR lpszKeyName,
        _In_    int nValue,
        _In_    BOOL bGlobal
        );

    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WaffleGetOptionStringNumber(
        _In_    LPCTSTR lpszString
        );

    WAFFLE_COMMON_DLL_FUNCTION LPTSTR WINAPI WaffleGetOptionSectionNames(
        _In_    LPCTSTR lpszOption
        );

    WAFFLE_COMMON_DLL_FUNCTION LPTSTR WINAPI WaffleGetOptionSectionKeys(
        _In_    LPCTSTR lpszOption,
        _In_    LPCTSTR lpszSection
        );
    /*
    pemachine.c
    */
    WAFFLE_COMMON_DLL_FUNCTION WORD WINAPI WaffleGetMachineType(
        _In_    LPCTSTR lpszFile
        );

    typedef WORD(WINAPI *LPWAFFLEGETMACHINETYPE)(
        _In_    LPCTSTR lpszFile
        );
    /*
    rtl.c
    */
    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WafflelstrlenW(
        _In_    LPCWSTR lpString
        );

    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WafflelstrlenA(
        _In_    LPCSTR lpString
        );

    WAFFLE_COMMON_DLL_FUNCTION LPWSTR WINAPI WafflelstrcatW(
        _In_    LPWSTR lpString1,
        _In_    LPCWSTR lpString2
        );

    WAFFLE_COMMON_DLL_FUNCTION LPSTR WINAPI WafflelstrcatA(
        _In_    LPSTR lpString1,
        _In_    LPCSTR lpString2
        );

    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WafflelstrcmpiW(
        _In_    LPCWSTR lpString1,
        _In_    LPCWSTR lpString2
        );

    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WafflelstrcmpiA(
        _In_    LPCSTR lpString1,
        _In_    LPCSTR lpString2
        );

    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WafflelstrcmpW(
        _In_    LPCWSTR lpString1,
        _In_    LPCWSTR lpString2
        );

    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WafflelstrcmpA(
        _In_    LPCSTR lpString1,
        _In_    LPCSTR lpString2
        );

    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WaffleStrToIntW(
        _In_    LPCWSTR lpString,
        _In_    int nDefault
        );

    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WaffleStrToIntA(
        _In_    LPCSTR lpString,
        _In_    int nDefault
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleCreateRWLock(
        LPWAFFLE_RWLOCK lpstRWLock
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleReleaseRWLock(
        LPWAFFLE_RWLOCK lpstRWLock
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleEnterWriterLock(
        LPWAFFLE_RWLOCK lpstRWLock
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleLeaveWriterLock(
        LPWAFFLE_RWLOCK lpstRWLock
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleEnterReaderLock(
        LPWAFFLE_RWLOCK lpstRWLock
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleLeaveReaderLock(
        LPWAFFLE_RWLOCK lpstRWLock
        );

    WAFFLE_COMMON_DLL_FUNCTION LPBYTE WINAPI WaffleGetProcAddressW(
        _In_    HMODULE hDll,
        _In_    LPCWSTR lpszFuncName
        );

    WAFFLE_COMMON_DLL_FUNCTION LPBYTE WINAPI WaffleGetProcAddressA(
        _In_    HMODULE hDll,
        _In_    LPCSTR lpszFuncName
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleIntBox(
        int i
        );

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleHexBox(
        DWORD i
        );

    WAFFLE_COMMON_DLL_FUNCTION DWORD WINAPI WaffleGetImageSize(
        HMODULE hModule
        );

    WAFFLE_COMMON_DLL_FUNCTION LPVOID WINAPI WaffleGetCallersAddress(
        _Out_   LPVOID *CallersCaller
        );

    WAFFLE_COMMON_DLL_FUNCTION LPVOID WINAPI WaffleAlloc(
        _In_    SIZE_T dwBytes
        );

    WAFFLE_COMMON_DLL_FUNCTION LPVOID WINAPI WaffleReAlloc(
        _In_    LPVOID lpMemory,
        _In_    SIZE_T dwBytes
        );

    WAFFLE_COMMON_DLL_FUNCTION LPVOID WINAPI WaffleFree(
        _In_    LPVOID lpMemory
        );
    /*
    setting.c
    */
    WAFFLE_COMMON_DLL_FUNCTION LPWAFFLE_PROCESS_SETTING WINAPI WaffleOpenProcessSetting(VOID);

    typedef LPWAFFLE_PROCESS_SETTING(WINAPI *LPWAFFLEOPENPROCESSSETTING)(VOID);

    WAFFLE_COMMON_DLL_FUNCTION LPWAFFLE_PROCESS_SETTING WINAPI WaffleCreateProcessSetting(VOID);

    typedef LPWAFFLE_PROCESS_SETTING(WINAPI *LPWAFFLECREATEPROCESSSETTING)(VOID);

    WAFFLE_COMMON_DLL_FUNCTION VOID WINAPI WaffleResumeMainThread(VOID);

    typedef VOID(WINAPI *LPWAFFLERESUMEMAINTHREAD)(VOID);

#ifdef __cplusplus
};
#endif

#endif /* __SDK_WAFFLE_COMMON_H_ */