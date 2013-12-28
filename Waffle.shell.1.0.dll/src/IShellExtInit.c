#include "../shell.h"

HRESULT STDMETHODCALLTYPE IWaffleShellExtInit_QueryInterface(
    _In_    IWaffleShellExtInit *this,
    _In_    REFIID riid,
    _In_    void **ppvObject
    )
{
    if (!IsEqualIID(riid, &IID_IUnknown) && !IsEqualIID(riid, &IID_IShellExtInit) && !IsEqualIID(riid, &IID_IWaffleShellExtInit))
    {
        *ppvObject = NULL;
        return E_NOINTERFACE;
    }

    *ppvObject = this;
    this->lpVtbl->AddRef(this);
    return S_OK;
}

ULONG STDMETHODCALLTYPE IWaffleShellExtInit_AddRef(
    _In_    IWaffleShellExtInit *this
    )
{
    return ((_IWaffleShellExtInit *)this)->IContextMenu->lpVtbl->AddRef((IWaffleContextMenu *)((_IWaffleShellExtInit *)this)->IContextMenu);
}

ULONG STDMETHODCALLTYPE IWaffleShellExtInit_Release(
    _In_    IWaffleShellExtInit *this
    )
{
    return ((_IWaffleShellExtInit *)this)->IContextMenu->lpVtbl->Release((IWaffleContextMenu *)((_IWaffleShellExtInit *)this)->IContextMenu);
}

HRESULT STDMETHODCALLTYPE IWaffleShellExtInit_Initialize(
    _In_    IWaffleShellExtInit *this,
    _In_    PCIDLIST_ABSOLUTE pidlFolder,
    _In_    IDataObject *pdtobj,
    _In_    HKEY hkeyProgID
    )
{
    HRESULT hr;
    FORMATETC formatetcIn = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
    STGMEDIUM medium;
    HDROP hDrop;
    LPTSTR lpszFileName;

    hr = pdtobj->lpVtbl->GetData(pdtobj, &formatetcIn, &medium);
    if (!SUCCEEDED(hr))
    {
        return hr;
    }

    hDrop = (HDROP)GlobalLock(medium.hGlobal);
    if (!hDrop)
    {
        return E_OUTOFMEMORY;
    }
    
    if (DragQueryFile(hDrop, (UINT)-1, NULL, 0) == 1)
    {
        UINT nSize = 1;
        UINT nFileName;
        lpszFileName = GlobalAlloc(GPTR, nSize * sizeof(lpszFileName[0]));
        do
        {
            nSize *= 2;
            lpszFileName = GlobalReAlloc(lpszFileName, nSize * sizeof(lpszFileName[0]), GHND);
            nFileName = DragQueryFile(hDrop, 0, lpszFileName, nSize);
        } while (nFileName == nSize - 1);
    }
    else
    {
        lpszFileName = NULL;
    }

    lpszFileName = InterlockedExchangePointer(&((_IWaffleShellExtInit *)this)->lpszFileName, lpszFileName);
    if (lpszFileName)
    {
        GlobalFree(lpszFileName);
    }

    GlobalUnlock(medium.hGlobal);

    return S_OK;
}

IWaffleShellExtInitVtbl IWaffleShellExtInit_Vtbl = {
    IWaffleShellExtInit_QueryInterface,
    IWaffleShellExtInit_AddRef,
    IWaffleShellExtInit_Release,
    IWaffleShellExtInit_Initialize,
};

_IWaffleShellExtInit IWaffleShellExtInitObject = { &IWaffleShellExtInit_Vtbl };