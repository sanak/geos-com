// geos_com.cpp : Implementation of DLL Exports.

#include <objbase.h>
#include <olectl.h>
#include "stdafx.h"
#include "geos_com.h"
#include "geos_com_i.c"
#include "API.h"

static CAPIClassFactory s_APIClassFactory;
HMODULE g_hModule = NULL;

const char *g_RegTable[][3] = {
	// API
	{ "CLSID\\{1BA3C695-871A-4FAD-8754-066681C23818}", 0, "API Class" },
	{ "CLSID\\{1BA3C695-871A-4FAD-8754-066681C23818}\\InprocServer32", 0, (const char*)-1 },
	{ "CLSID\\{1BA3C695-871A-4FAD-8754-066681C23818}\\ProgID", 0, "Geos.API.1" },
	{ "CLSID\\{1BA3C695-871A-4FAD-8754-066681C23818}\\TypeLib", 0, "{D07BED60-96BC-4C7D-AE4F-114104675ABA}" },
	{ "Geos.API.1", 0, "API Class" },
	{ "Geos.API.1\\CLSID", 0, "{1BA3C695-871A-4FAD-8754-066681C23818}" },
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
	char szFileName[MAX_PATH];
	GetModuleFileName(g_hModule, szFileName, MAX_PATH);
	int nEntries = sizeof(g_RegTable) / sizeof(*g_RegTable);
	for (int i = 0; SUCCEEDED(hr) && i < nEntries; i++) {
		const char *pszKeyName = g_RegTable[i][0];
		const char *pszValueName = g_RegTable[i][1];
		const char *pszValue = g_RegTable[i][2];
		if (pszValue == (const char*)-1)
			pszValue = szFileName;
		HKEY hKey;
		long err = RegCreateKey(HKEY_CLASSES_ROOT, pszKeyName, &hKey);
		if (err == ERROR_SUCCESS) {
			err = RegSetValueEx(hKey, pszValueName, 0, REG_SZ, (const BYTE*)pszValue, (DWORD)(strlen(pszValue) + 1));
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
		const char *pszKeyName = g_RegTable[i][0];
		long err = RegDeleteKey(HKEY_CLASSES_ROOT, pszKeyName);
		if (err != ERROR_SUCCESS)
			hr = S_FALSE;
	}
	return hr;
}
