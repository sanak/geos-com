/*****************************************************************************
 *
 * FileName: geos_com.cpp
 * Project:  GEOS COM Wrapper - http://sourceforge.jp/projects/geos-com
 * Purpose:  Implementation of DLL Exports.
 * Author:   geosanak, geosanak@gmail.com
 *
 * Copyright (C) 2006-2008 geosanak
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 *****************************************************************************/

#include "stdafx.h"
#include "geos_com.h"
#include "geos_com_i.c"
#include "API.h"

static CAPIClassFactory s_APIClassFactory;
HMODULE g_hModule = NULL;

const TCHAR *g_RegTable[][3] = {
	// API
	{ _T("CLSID\\{1BA3C695-871A-4FAD-8754-066681C23818}"), 0, _T("API Class") },
	{ _T("CLSID\\{1BA3C695-871A-4FAD-8754-066681C23818}\\InprocServer32"), 0, (const TCHAR*)-1 },
	{ _T("CLSID\\{1BA3C695-871A-4FAD-8754-066681C23818}\\ProgID"), 0, _T("Geos.API.1") },
	{ _T("CLSID\\{1BA3C695-871A-4FAD-8754-066681C23818}\\TypeLib"), 0, _T("{D07BED60-96BC-4C7D-AE4F-114104675ABA}") },
	{ _T("Geos.API.1"), 0, _T("API Class") },
	{ _T("Geos.API.1\\CLSID"), 0, _T("{1BA3C695-871A-4FAD-8754-066681C23818}") },
};

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, void *pReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        g_hModule = hModule;
		DisableThreadLibraryCalls(hModule);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
	{
	}
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    return (g_cLocks == 0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
	if (rclsid == CLSID_API)
		return s_APIClassFactory.QueryInterface(riid, ppv);
	*ppv = 0;
	return CLASS_E_CLASSNOTAVAILABLE;
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    HRESULT hr = S_OK;
	// get server file name
	TCHAR szFileName[MAX_PATH];
	GetModuleFileName(g_hModule, szFileName, MAX_PATH);
	int nEntries = sizeof(g_RegTable) / sizeof(*g_RegTable);
	for (int i = 0; SUCCEEDED(hr) && i < nEntries; i++) {
		const TCHAR *pszKeyName = g_RegTable[i][0];
		const TCHAR *pszValueName = g_RegTable[i][1];
		const TCHAR *pszValue = g_RegTable[i][2];
		if (pszValue == (const TCHAR*)-1)
			pszValue = szFileName;
		HKEY hKey;
		long err = RegCreateKey(HKEY_CLASSES_ROOT, pszKeyName, &hKey);
		if (err == ERROR_SUCCESS) {
			err = RegSetValueEx(hKey, pszValueName, 0, REG_SZ, (const BYTE*)pszValue, (DWORD)(_tcslen(pszValue) + 1));
			RegCloseKey(hKey);
		}
		if (err != ERROR_SUCCESS) {
			DllUnregisterServer();
			hr = SELFREG_E_CLASS;
		}
	}
	if (FAILED(hr))
		return hr;

	_bstr_t bstrFileName = szFileName;
	ITypeLib *pTypeLib;
	hr = LoadTypeLib((wchar_t*)bstrFileName, &pTypeLib);
	if (FAILED(hr))
		return hr;

	hr = RegisterTypeLib(pTypeLib, (wchar_t*)bstrFileName, NULL);

	return hr;
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    HRESULT hr = S_OK;
	int nEntries = sizeof(g_RegTable) / sizeof(*g_RegTable);
	for (int i = nEntries - 1; i >= 0; i--) {
		const TCHAR *pszKeyName = g_RegTable[i][0];
		long err = RegDeleteKey(HKEY_CLASSES_ROOT, pszKeyName);
		if (err != ERROR_SUCCESS)
			hr = S_FALSE;
	}
	return hr;
}
