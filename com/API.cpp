/*****************************************************************************
 *
 * FileName: API.cpp
 * Project:  GEOS COM Wrapper - http://sourceforge.jp/projects/geos-com
 * Purpose:  Implementation of CAPI class.
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
#include "API.h"

namespace geos {
	#include <geos_c.h>
};

STDMETHODIMP CAPIClassFactory::QueryInterface(REFIID riid, void **ppv)
{
	if (riid == IID_IUnknown || riid == IID_IClassFactory)
		*ppv = static_cast<IClassFactory*>(this);
	else
		return (*ppv = 0), E_NOINTERFACE;

	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

STDMETHODIMP_(ULONG) CAPIClassFactory::AddRef(void)
{
	LockModule();
	return 2;
}

STDMETHODIMP_(ULONG) CAPIClassFactory::Release(void) {
	UnlockModule();
	return 1;
}

STDMETHODIMP CAPIClassFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppv)
{
	*ppv = 0;
	if (pUnkOuter != 0)
		return CLASS_E_NOAGGREGATION;

	CAPI *p = new CAPI();
	if (p == 0)
		return E_OUTOFMEMORY;

	HRESULT hr = p->FinalConstruct();

	p->AddRef();
	hr = p->QueryInterface(riid, ppv);
	p->Release();
	return hr;
}

STDMETHODIMP CAPIClassFactory::LockServer(BOOL bLock)
{
	if (bLock)
		LockModule();
	else
		UnlockModule();
	return S_OK;
}

// CAPI
#define MAX_NOTICE	1024
#define MAX_ERROR	1024

CAPI* CAPI::sm_pThis = NULL;

CAPI::CAPI(void)
: m_cRef(0), m_pAPIEvents(NULL)
{
	ITypeLib *ptl = 0;
	HRESULT hr = LoadRegTypeLib(LIBID_Geos, 1, 0, 0, &ptl);
	hr = ptl->GetTypeInfoOfGuid(IID_IAPI, &m_pTypeInfo);
	ptl->Release();
}

CAPI::~CAPI(void)
{
	m_pTypeInfo->Release();
}

HRESULT CAPI::FinalConstruct()
{
	sm_pThis = this;
	return S_OK;
}


HRESULT CAPI::Fire_onNotice(BSTR strNotice)
{
	HRESULT hr = S_OK;
	if (m_pAPIEvents)
	{
		IDispatch *pdispAPIEvents = static_cast<IDispatch*>(m_pAPIEvents);
		if (pdispAPIEvents)
		{
			_variant_t avarParams[1];
			avarParams[0].bstrVal = strNotice;	avarParams[0].vt = VT_BSTR;
			_variant_t varResult;

			DISPPARAMS params = { avarParams, NULL, 1, 0 };
			hr = pdispAPIEvents->Invoke(1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
		}
	}
	return hr;
}

HRESULT CAPI::Fire_onError(BSTR strError)
{
	HRESULT hr = S_OK;

	if (m_pAPIEvents)
	{
		IDispatch *pdispAPIEvents = static_cast<IDispatch*>(m_pAPIEvents);
		if (pdispAPIEvents)
		{
			_variant_t avarParams[1];
			avarParams[0].bstrVal = strError;	avarParams[0].vt = VT_BSTR;
			_variant_t varResult;

			DISPPARAMS params = { avarParams, NULL, 1, 0 };
			hr = pdispAPIEvents->Invoke(2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
		}
	}
	return hr;
}

STDMETHODIMP CAPI::QueryInterface(REFIID riid, void **ppv)
{
	if (riid == IID_IUnknown || riid == IID_IAPI)
		*ppv = static_cast<IAPI*>(this);
	else if (riid == IID_IDispatch)
		*ppv = static_cast<IAPI*>(this);
	else if (riid == IID_ISupportErrorInfo)
		*ppv = static_cast<ISupportErrorInfo*>(this);
	else if (riid == DIID__IAPIEvents)
		*ppv = static_cast<_IAPIEvents*>(this);
	else if (riid == IID_IConnectionPointContainer)
		*ppv = static_cast<IConnectionPointContainer*>(this);
	else if (riid == IID_IProvideClassInfo)
		*ppv = static_cast<IProvideClassInfo*>(this);
	else if (riid == IID_IProvideClassInfo2)
		*ppv = static_cast<IProvideClassInfo2*>(this);
	else
		return (*ppv = 0), E_NOINTERFACE;

	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

STDMETHODIMP_(ULONG) CAPI::AddRef(void)
{
	if (m_cRef == 0)
		LockModule();
	return InterlockedIncrement(&m_cRef);
}

STDMETHODIMP_(ULONG) CAPI::Release(void) {
	LONG res = InterlockedDecrement(&m_cRef);
	if (res == 0) {
		delete this;
		UnlockModule();
	}
	return res;
}

STDMETHODIMP CAPI::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IAPI
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

CAPI* CAPI::XCPAPIEvents::This(void)
{
	return (CAPI*)((BYTE*)this - offsetof(CAPI, m_xcpAPIEvents));
}

// IUnknown
STDMETHODIMP CAPI::XCPAPIEvents::QueryInterface(REFIID riid, void **ppv)
{
	if (riid == IID_IUnknown || riid == IID_IConnectionPoint)
		*ppv = static_cast<IConnectionPoint*>(this);
	else
		return (*ppv = 0), E_NOINTERFACE;
	((IUnknown*)*ppv)->AddRef();
	return S_OK;
}

STDMETHODIMP_(ULONG) CAPI::XCPAPIEvents::AddRef(void)
{
	return This()->AddRef();
}

STDMETHODIMP_(ULONG) CAPI::XCPAPIEvents::Release(void)
{
	return This()->Release();
}

// IConnectionPoint
STDMETHODIMP CAPI::XCPAPIEvents::GetConnectionInterface(IID *piid)
{
	*piid = DIID__IAPIEvents;
	return S_OK;
}

STDMETHODIMP CAPI::XCPAPIEvents::GetConnectionPointContainer(IConnectionPointContainer **ppcpc)
{
	((IUnknown*)(*ppcpc = This()))->AddRef();
	return S_OK;
}

STDMETHODIMP CAPI::XCPAPIEvents::Advise(IUnknown *pUnk, DWORD *pdwCookie)
{
	*pdwCookie = 0;
	if (This()->m_pAPIEvents)
		return CONNECT_E_ADVISELIMIT;

	HRESULT hr = pUnk->QueryInterface(DIID__IAPIEvents, (void**)&(This()->m_pAPIEvents));
	if (hr == E_NOINTERFACE)
		hr = CONNECT_E_NOCONNECTION;
	if (SUCCEEDED(hr))
		*pdwCookie = static_cast<DWORD>(PtrToUlong(This()->m_pAPIEvents));
	return hr;
}

STDMETHODIMP CAPI::XCPAPIEvents::Unadvise(DWORD dwCookie)
{
	if (static_cast<DWORD>(PtrToUlong(This()->m_pAPIEvents)) != dwCookie)
		return CONNECT_E_NOCONNECTION;
	This()->m_pAPIEvents->Release();
	This()->m_pAPIEvents = 0;
	return S_OK;
}

STDMETHODIMP CAPI::XCPAPIEvents::EnumConnections(IEnumConnections **ppEnum)
{
	return E_NOTIMPL;
}

STDMETHODIMP CAPI::EnumConnectionPoints(IEnumConnectionPoints **ppEnum)
{
	return S_FALSE; // TODO:
}

STDMETHODIMP CAPI::FindConnectionPoint(REFIID riid, IConnectionPoint **ppcp)
{
	if (riid == DIID__IAPIEvents)
		*ppcp = &m_xcpAPIEvents;
	else
		return (*ppcp = 0), CONNECT_E_NOCONNECTION;

	((IUnknown*)*ppcp)->AddRef();
	return S_OK;
}

STDMETHODIMP CAPI::GetClassInfo(ITypeInfo **ppti)
{
	ITypeLib *ptl = 0;
	HRESULT hr = LoadRegTypeLib(LIBID_Geos, 1, 0, 0, &ptl);
	if (SUCCEEDED(hr)) {
		hr = ptl->GetTypeInfoOfGuid(CLSID_API, ppti);
		ptl->Release();
	}
	return hr;
}

STDMETHODIMP CAPI::GetGUID(DWORD dwKind, GUID *pguid)
{
	if (dwKind != GUIDKIND_DEFAULT_SOURCE_DISP_IID || !pguid)
		return E_INVALIDARG;
	*pguid = DIID__IAPIEvents;
	return S_OK;
}


void CAPI::notice(const char *fmt, ...)
{
	char szNotice[MAX_NOTICE];
	va_list ap;
	va_start(ap, fmt);
	vsprintf(szNotice, fmt, ap);
	va_end(ap);
	_bstr_t bstrNotice = szNotice;
	sm_pThis->Fire_onNotice(bstrNotice);
}

void CAPI::error(const char *fmt, ...)
{
	char szError[MAX_ERROR];
	va_list ap;
	va_start(ap, fmt);
	vsprintf(szError, fmt, ap);
	va_end(ap);
	_bstr_t bstrError = szError;
	sm_pThis->Fire_onError(bstrError);
}

STDMETHODIMP CAPI::GetTypeInfoCount(UINT *pit)
{
	*pit = 1;
	return S_OK;
}

STDMETHODIMP CAPI::GetTypeInfo(UINT it, LCID lcid, ITypeInfo **ppti)
{
	(*ppti = m_pTypeInfo)->AddRef();
	return S_OK;
}

STDMETHODIMP CAPI::GetIDsOfNames(REFIID riid, LPOLESTR *pNames, UINT cNames, LCID lcid, DISPID *pdispids)
{
	return m_pTypeInfo->GetIDsOfNames(pNames, cNames, pdispids);
}

STDMETHODIMP CAPI::Invoke(DISPID id, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pd, VARIANT *pVarResult, EXCEPINFO *pe, UINT *pu)
{
	void *pvThis = static_cast<IAPI*>(this);
	return m_pTypeInfo->Invoke(pvThis, id, wFlags, pd, pVarResult, pe, pu);
}

STDMETHODIMP CAPI::init(void)
{
	geos::initGEOS(notice, error);
	return S_OK;
}

STDMETHODIMP CAPI::finish(void)
{
	geos::finishGEOS();
	return S_OK;
}

STDMETHODIMP CAPI::version(BSTR *pstrVersion)
{
	_bstr_t bstrVersion = geos::GEOSversion();
	*pstrVersion = bstrVersion.copy();
	return S_OK;
}

STDMETHODIMP CAPI::GeomFromWKT(BSTR strBuf, long *phGeom)
{
	_bstr_t bstrBuf = strBuf;
	*phGeom = PtrToLong(geos::GEOSGeomFromWKT((char*)bstrBuf));
	return S_OK;
}

STDMETHODIMP CAPI::GeomToWKT(long hGeom, BSTR *pstrBuf)
{
	char* pszBuf = geos::GEOSGeomToWKT(static_cast<const geos::GEOSGeom>(LongToPtr(hGeom)));
	_bstr_t bstrBuf = pszBuf;
//	free(pszBuf);
	*pstrBuf = bstrBuf.copy();
	return S_OK;
}

STDMETHODIMP CAPI::setWKBOutputDims(long nNewDims, long *pnOldDims)
{
	*pnOldDims = geos::GEOS_setWKBOutputDims(nNewDims);
	return S_OK;
}

STDMETHODIMP CAPI::GeomFromWKB_buf(VARIANT vBuf, long *phGeom)
{
	if (!(vBuf.vt & VT_ARRAY) || !(vBuf.vt & VT_UI1))
		return E_INVALIDARG;
	
	SAFEARRAY* psa = vBuf.parray;
	BYTE* pbyData;
	::SafeArrayAccessData(psa, (void**)&pbyData);

	size_t size = psa->rgsabound->cElements;

	*phGeom = PtrToLong(geos::GEOSGeomFromWKB_buf(pbyData, size));
	::SafeArrayUnaccessData(psa);
	return S_OK;
}

STDMETHODIMP CAPI::GeomToWKB_buf(long hGeom, VARIANT *pvBuf)
{
	size_t size;
	BYTE* pbyBuf = geos::GEOSGeomToWKB_buf(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)), &size);

	::VariantInit(pvBuf);
	pvBuf->vt = VT_ARRAY | VT_BSTR;
	SAFEARRAY* psa;
	ULONG nSize = static_cast<ULONG>(size);
	SAFEARRAYBOUND bounds = {nSize, 0};
	psa = ::SafeArrayCreate(VT_UI1, 1, &bounds);
	BYTE* pbyData;
	::SafeArrayAccessData(psa, (void**)&pbyData);
	for (size_t i = 0; i < size; i++)
	{
		pbyData[i] = pbyBuf[i];
	}
	::SafeArrayUnaccessData(psa);
	pvBuf->parray = psa;
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_create(long nSize, long nDims, long *phCoordSeq)
{
	*phCoordSeq = PtrToLong(geos::GEOSCoordSeq_create(nSize, nDims));
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_clone(long hCoordSeq, long *phCoordSeq)
{
	*phCoordSeq = PtrToLong(geos::GEOSCoordSeq_clone(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq))));
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_destroy(long hCoordSeq)
{
	geos::GEOSCoordSeq_destroy(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq)));
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_setX(long hCoordSeq, long nIndex, double dVal, long *pnResult)
{
	*pnResult = geos::GEOSCoordSeq_setX(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, dVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_setY(long hCoordSeq, long nIndex, double dVal, long *pnResult)
{
	*pnResult = geos::GEOSCoordSeq_setY(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, dVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_setZ(long hCoordSeq, long nIndex, double dVal, long *pnResult)
{
	*pnResult = geos::GEOSCoordSeq_setZ(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, dVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_setOrdinate(long hCoordSeq, long nIndex, long nDims, double dVal, long *pnResult)
{
	*pnResult = geos::GEOSCoordSeq_setOrdinate(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, nDims, dVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_getX(long hCoordSeq, long nIndex, double *pdVal, long *pnResult)
{
	*pnResult = geos::GEOSCoordSeq_getX(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, pdVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_getY(long hCoordSeq, long nIndex, double *pdVal, long *pnResult)
{
	*pnResult = geos::GEOSCoordSeq_getY(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, pdVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_getZ(long hCoordSeq, long nIndex, double *pdVal, long *pnResult)
{
	*pnResult = geos::GEOSCoordSeq_getZ(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, pdVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_getOrdinate(long hCoordSeq, long nIndex, long nDims, double *pdVal, long *pnResult)
{
	*pnResult = geos::GEOSCoordSeq_getOrdinate(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, nDims, pdVal);
	return E_NOTIMPL;
}

STDMETHODIMP CAPI::CoordSeq_getSize(long hCoordSeq, long *pnSize, long *pnResult)
{
	unsigned int nSize;
	*pnResult = geos::GEOSCoordSeq_getSize(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq)), &nSize);
	*pnSize = nSize;
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_getDimensions(long hCoordSeq, long *pnDims, long *pnResult)
{
	unsigned int nDims;
	*pnResult = geos::GEOSCoordSeq_getDimensions(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq)), &nDims);
	*pnDims = nDims;
	return S_OK;
}

STDMETHODIMP CAPI::Geom_createPoint(long hCoordSeq, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSGeom_createPoint(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq))));
	return S_OK;
}

STDMETHODIMP CAPI::Geom_createLinearRing(long hCoordSeq, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSGeom_createLinearRing(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq))));
	return S_OK;
}

STDMETHODIMP CAPI::Geom_createLineString(long hCoordSeq, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSGeom_createLineString(static_cast<geos::GEOSCoordSeq>(LongToPtr(hCoordSeq))));
	return S_OK;
}

STDMETHODIMP CAPI::Geom_createPolygon(long hShell, VARIANT vHoles, long *phGeom)
{
	long* pnHoles = NULL;
	ULONG nSize = 0;
	SAFEARRAY* psa = NULL;
	if ((vHoles.vt & VT_ARRAY) && (vHoles.vt & VT_I4))
	{
		psa = vHoles.parray;
		::SafeArrayAccessData(psa, (void**)&pnHoles);
		nSize = psa->rgsabound->cElements;
	}

	*phGeom = PtrToLong(geos::GEOSGeom_createPolygon(static_cast<geos::GEOSGeom>(LongToPtr(hShell)), reinterpret_cast<geos::GEOSGeom*>(pnHoles), nSize));

	if (psa)
		::SafeArrayUnaccessData(psa);
	return S_OK;
}

STDMETHODIMP CAPI::Geom_createCollection(long nType, VARIANT vGeoms, long *phGeom)
{
	if (!(vGeoms.vt & VT_ARRAY) || !(vGeoms.vt & VT_I4))
		return E_INVALIDARG;

	SAFEARRAY* psa = vGeoms.parray;
	long* pnGeoms;
	::SafeArrayAccessData(psa, (void**)&pnGeoms);

	*phGeom = PtrToLong(geos::GEOSGeom_createCollection(nType, reinterpret_cast<geos::GEOSGeom*>(pnGeoms), psa->rgsabound->cElements));

	::SafeArrayUnaccessData(psa);
	return S_OK;
}

STDMETHODIMP CAPI::Geom_clone(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSGeom_clone(static_cast<geos::GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::Geom_destroy(long hGeom)
{
	geos::GEOSGeom_destroy(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}


STDMETHODIMP CAPI::Intersection(long hGeom1, long hGeom2, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSIntersection(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2))));
	return S_OK;
}

STDMETHODIMP CAPI::Buffer(long hGeom, double dWidth, long nQuadSegs, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSBuffer(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)), dWidth, nQuadSegs));
	return S_OK;
}

STDMETHODIMP CAPI::ConvexHull(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSConvexHull(static_cast<geos::GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::Difference(long hGeom1, long hGeom2, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSDifference(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2))));
	return S_OK;
}

STDMETHODIMP CAPI::SymDifference(long hGeom1, long hGeom2, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSSymDifference(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2))));
	return S_OK;
}

STDMETHODIMP CAPI::Boundary(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSBoundary(static_cast<geos::GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::Union(long hGeom1, long hGeom2, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSUnion(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2))));
	return S_OK;
}

STDMETHODIMP CAPI::PointOnSurface(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSPointOnSurface(static_cast<geos::GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::GetCentroid(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSGetCentroid(static_cast<geos::GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::Relate(long hGeom1, long hGeom2, BSTR *pstrResult)
{
	char* pszResult = geos::GEOSRelate(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2)));
	_bstr_t bstrResult = pszResult;
//	free(pszResult);
	*pstrResult = bstrResult.copy();
	return S_OK;
}

STDMETHODIMP CAPI::Polygonize(VARIANT vGeoms, long *phGeom)
{
	if (!(vGeoms.vt & VT_ARRAY) || !(vGeoms.vt & VT_I4))
		return E_INVALIDARG;

	SAFEARRAY* psa = vGeoms.parray;
	long* pnGeoms;
	::SafeArrayAccessData(psa, (void**)&pnGeoms);

	*phGeom = PtrToLong(geos::GEOSPolygonize(reinterpret_cast<geos::GEOSGeom*>(pnGeoms), psa->rgsabound->cElements));

	::SafeArrayUnaccessData(psa);
	return S_OK;
}

STDMETHODIMP CAPI::LineMerge(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSLineMerge(static_cast<geos::GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::RelatePattern(long hGeom1, long hGeom2, BSTR strPattern, unsigned char *pbyResult)
{
	_bstr_t bstrPattern = strPattern;
	*pbyResult = geos::GEOSRelatePattern(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2)), (char*)bstrPattern);
	return S_OK;
}

STDMETHODIMP CAPI::Disjoint(long hGeom1, long hGeom2, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSDisjoint(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Touches(long hGeom1, long hGeom2, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSTouches(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Intersects(long hGeom1, long hGeom2, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSIntersects(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Crosses(long hGeom1, long hGeom2, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSCrosses(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Within(long hGeom1, long hGeom2, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSWithin(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Contains(long hGeom1, long hGeom2, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSContains(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Overlaps(long hGeom1, long hGeom2, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSOverlaps(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Equals(long hGeom1, long hGeom2, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSEquals(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::isEmpty(long hGeom, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSisEmpty(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::isValid(long hGeom, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSisValid(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::isSimple(long hGeom, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSisSimple(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::isRing(long hGeom, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSisRing(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::HasZ(long hGeom, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSHasZ(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::GeomTypeId(long hGeom, GEOSGeomTypes *peTypes)
{
	*peTypes = static_cast<GEOSGeomTypes>(geos::GEOSGeomTypeId(static_cast<geos::GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::GetSRID(long hGeom, long *pnSRID)
{
	*pnSRID = geos::GEOSGetSRID(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::SetSRID(long hGeom, int nSRID)
{
	geos::GEOSSetSRID(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)), nSRID);
	return S_OK;
}

STDMETHODIMP CAPI::GetNumGeometries(long hGeom, long *pnNumGeoms)
{
	*pnNumGeoms = geos::GEOSGetNumGeometries(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::GetGeometryN(long hGeom, long nIndex, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSGetGeometryN(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)), nIndex));
	return S_OK;
}

STDMETHODIMP CAPI::GetNumInteriorRings(long hGeom, long *pnResult)
{
	*pnResult = geos::GEOSGetNumInteriorRings(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::GetInteriorRingN(long hGeom, long nIndex, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSGetInteriorRingN(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)), nIndex));
	return S_OK;
}

STDMETHODIMP CAPI::GetExteriorRing(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSGetExteriorRing(static_cast<geos::GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::GetNumCoordinates(long hGeom, long *pnNumCoords)
{
	*pnNumCoords = geos::GEOSGetNumCoordinates(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::Geom_getDimensions(long hGeom, long *pnDims)
{
	*pnDims = geos::GEOSGeom_getDimensions(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::Geom_getCoordSeq(long hGeom, long *phCoordSeq)
{
	*phCoordSeq = PtrToLong(geos::GEOSGeom_getCoordSeq(static_cast<geos::GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::Distance(long hGeom1, long hGeom2, double *pdDistance, long *pnResult)
{
	*pnResult = geos::GEOSDistance(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2)), pdDistance);
	return S_OK;
}

STDMETHODIMP CAPI::Envelope(long hGeom, long* phGeom)
{
	*phGeom = PtrToLong(geos::GEOSEnvelope(static_cast<geos::GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::GeomType(long hGeom, BSTR* pstrType)
{
	_bstr_t bstrType;
	bstrType = geos::GEOSGeomType(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	*pstrType = bstrType.copy();
	return S_OK;
}

STDMETHODIMP CAPI::Area(long hGeom, double* pdArea, long* pnResult)
{
	*pnResult = geos::GEOSArea(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)), pdArea);
	return S_OK;
}

STDMETHODIMP CAPI::Length(long hGeom, double* pdLength, long* pnResult)
{
	*pnResult = geos::GEOSLength(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)), pdLength);
	return S_OK;
}

STDMETHODIMP CAPI::getWKBOutputDims(long* pnResult)
{
	*pnResult = geos::GEOS_getWKBOutputDims();
	return S_OK;
}

STDMETHODIMP CAPI::getWKBByteOrder(GEOSByteOrders* peResult)
{
	*peResult = static_cast<GEOSByteOrders>(geos::GEOS_getWKBByteOrder());
	return S_OK;
}

STDMETHODIMP CAPI::setWKBByteOrder(GEOSByteOrders eByteOrder, GEOSByteOrders* peResult)
{
	*peResult = static_cast<GEOSByteOrders>(geos::GEOS_setWKBByteOrder(static_cast<int>(eByteOrder)));
	return S_OK;
}

STDMETHODIMP CAPI::GeomFromHEX_buf(VARIANT vHex, long* phGeom)
{
	if (!(vHex.vt & VT_ARRAY) || !(vHex.vt & VT_UI1))
		return E_INVALIDARG;

	SAFEARRAY* psa = vHex.parray;
	unsigned char* pszHex;
	::SafeArrayAccessData(psa, (void**)&pszHex);

	*phGeom = PtrToLong(geos::GEOSGeomFromHEX_buf(const_cast<const unsigned char*>(pszHex), psa->rgsabound->cElements));

	::SafeArrayUnaccessData(psa);
	return S_OK;
}

STDMETHODIMP CAPI::GeomToHEX_buf(long hGeom, VARIANT *pvHex)
{
	size_t size;
	BYTE* pbyBuf = geos::GEOSGeomToHEX_buf(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)), &size);

	::VariantInit(pvHex);
	pvHex->vt = VT_ARRAY | VT_UI1;
	SAFEARRAY* psa;
	ULONG nSize = static_cast<ULONG>(size);
	SAFEARRAYBOUND bounds = {nSize, 0};
	psa = ::SafeArrayCreate(VT_UI1, 1, &bounds);
	BYTE* pbyData;
	::SafeArrayAccessData(psa, (void**)&pbyData);
	for (size_t i = 0; i < size; i++)
	{
		pbyData[i] = pbyBuf[i];
	}
	::SafeArrayUnaccessData(psa);
	pvHex->parray = psa;
	return S_OK;
}

STDMETHODIMP CAPI::Simplify(long hGeom, double dTolerance, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSSimplify(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)), dTolerance));
	return S_OK;
}

STDMETHODIMP CAPI::TopologyPreserveSimplify(long hGeom, double dTolerance, long *phGeom)
{
	*phGeom = PtrToLong(geos::GEOSTopologyPreserveSimplify(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)), dTolerance));
	return S_OK;
}

STDMETHODIMP CAPI::EqualsExact(long hGeom1, long hGeom2, double dTolerance, unsigned char *pbyResult)
{
	*pbyResult = geos::GEOSEqualsExact(static_cast<geos::GEOSGeom>(LongToPtr(hGeom1)), static_cast<geos::GEOSGeom>(LongToPtr(hGeom2)), dTolerance);
	return S_OK;
}

STDMETHODIMP CAPI::Normalize(long hGeom, long *pnResult)
{
	*pnResult = geos::GEOSNormalize(static_cast<geos::GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}
