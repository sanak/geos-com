// API.cpp : Implementation of CAPI

#include "stdafx.h"
#include "API.h"
#include ".\api.h"
#include <stdio.h>

#define MAX_NOTICE	1024
#define MAX_ERROR	1024
// CAPI
CAPI* CAPI::sm_pThis = NULL;
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

void CAPI::notice(const char *fmt, ...)
{
	TCHAR szNotice[MAX_NOTICE];
	va_list ap;
	va_start(ap, fmt);
	_vstprintf(szNotice, fmt, ap);
	va_end(ap);
	CComBSTR sbstrNotice = szNotice;
	sm_pThis->Fire_onNotice(sbstrNotice);
}

void CAPI::error(const char *fmt, ...)
{
	TCHAR szError[MAX_ERROR];
	va_list ap;
	va_start(ap, fmt);
	_vstprintf(szError, fmt, ap);
	va_end(ap);
	CComBSTR sbstrError = szError;
	sm_pThis->Fire_onError(sbstrError);
}

STDMETHODIMP CAPI::init(void)
{
	initGEOS(notice, error);
	return S_OK;
}

STDMETHODIMP CAPI::finish(void)
{
	finishGEOS();
	return S_OK;
}

STDMETHODIMP CAPI::version(BSTR *pstrVersion)
{
	CComBSTR sbstrBuf;
	sbstrBuf = GEOSversion();
	return sbstrBuf.CopyTo(pstrVersion);
}


STDMETHODIMP CAPI::GeomFromWKT(BSTR strBuf, long *phGeom)
{
	USES_CONVERSION;
	*phGeom = PtrToLong(GEOSGeomFromWKT(OLE2T(strBuf)));
	return S_OK;
}

STDMETHODIMP CAPI::GeomToWKT(long hGeom, BSTR *pstrBuf)
{
	USES_CONVERSION;
	char* pszBuf = GEOSGeomToWKT(static_cast<const GEOSGeom>(LongToPtr(hGeom)));
	CComBSTR sbstrBuf;
	sbstrBuf = T2OLE(pszBuf);
//	free(pszBuf);
	return sbstrBuf.CopyTo(pstrBuf);
}

STDMETHODIMP CAPI::setWKBOutputDims(long nNewDims, long *pnOldDims)
{
	*pnOldDims = GEOS_setWKBOutputDims(nNewDims);
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

	*phGeom = PtrToLong(GEOSGeomFromWKB_buf(pbyData, size));
	::SafeArrayUnaccessData(psa);
	return S_OK;
}

STDMETHODIMP CAPI::GeomToWKB_buf(long hGeom, VARIANT *pvBuf)
{
	size_t size;
	BYTE* pbyBuf = GEOSGeomToWKB_buf(static_cast<GEOSGeom>(LongToPtr(hGeom)), &size);

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
	*phCoordSeq = PtrToLong(GEOSCoordSeq_create(nSize, nDims));
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_clone(long hCoordSeq, long *phCoordSeq)
{
	*phCoordSeq = PtrToLong(GEOSCoordSeq_clone(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq))));
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_destroy(long hCoordSeq)
{
	GEOSCoordSeq_destroy(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq)));
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_setX(long hCoordSeq, long nIndex, double dVal, long *pnResult)
{
	*pnResult = GEOSCoordSeq_setX(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, dVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_setY(long hCoordSeq, long nIndex, double dVal, long *pnResult)
{
	*pnResult = GEOSCoordSeq_setY(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, dVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_setZ(long hCoordSeq, long nIndex, double dVal, long *pnResult)
{
	*pnResult = GEOSCoordSeq_setZ(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, dVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_setOrdinate(long hCoordSeq, long nIndex, long nDims, double dVal, long *pnResult)
{
	*pnResult = GEOSCoordSeq_setOrdinate(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, nDims, dVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_getX(long hCoordSeq, long nIndex, double *pdVal, long *pnResult)
{
	*pnResult = GEOSCoordSeq_getX(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, pdVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_getY(long hCoordSeq, long nIndex, double *pdVal, long *pnResult)
{
	*pnResult = GEOSCoordSeq_getY(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, pdVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_getZ(long hCoordSeq, long nIndex, double *pdVal, long *pnResult)
{
	*pnResult = GEOSCoordSeq_getZ(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, pdVal);
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_getOrdinate(long hCoordSeq, long nIndex, long nDims, double *pdVal, long *pnResult)
{
	// ToDo...
//	*pnResult = GEOSCoordSeq_getOrdinate(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq)), nIndex, nDims, pdVal);
	return E_NOTIMPL;
}

STDMETHODIMP CAPI::CoordSeq_getSize(long hCoordSeq, long *pnSize, long *pnResult)
{
	unsigned int nSize;
	*pnResult = GEOSCoordSeq_getSize(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq)), &nSize);
	*pnSize = nSize;
	return S_OK;
}

STDMETHODIMP CAPI::CoordSeq_getDimensions(long hCoordSeq, long *pnDims, long *pnResult)
{
	unsigned int nDims;
	*pnResult = GEOSCoordSeq_getDimensions(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq)), &nDims);
	*pnDims = nDims;
	return S_OK;
}

STDMETHODIMP CAPI::Geom_createPoint(long hCoordSeq, long *phGeom)
{
	*phGeom = PtrToLong(GEOSGeom_createPoint(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq))));
	return S_OK;
}

STDMETHODIMP CAPI::Geom_createLinearRing(long hCoordSeq, long *phGeom)
{
	*phGeom = PtrToLong(GEOSGeom_createLinearRing(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq))));
	return S_OK;
}

STDMETHODIMP CAPI::Geom_createLineString(long hCoordSeq, long *phGeom)
{
	*phGeom = PtrToLong(GEOSGeom_createLineString(static_cast<GEOSCoordSeq>(LongToPtr(hCoordSeq))));
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

	*phGeom = PtrToLong(GEOSGeom_createPolygon(static_cast<GEOSGeom>(LongToPtr(hShell)), reinterpret_cast<GEOSGeom*>(pnHoles), nSize));

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

	*phGeom = PtrToLong(GEOSGeom_createCollection(nType, reinterpret_cast<GEOSGeom*>(pnGeoms), psa->rgsabound->cElements));

	::SafeArrayUnaccessData(psa);
	return S_OK;
}

STDMETHODIMP CAPI::Geom_clone(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(GEOSGeom_clone(static_cast<GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::Geom_destroy(long hGeom)
{
	GEOSGeom_destroy(static_cast<GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}


STDMETHODIMP CAPI::Intersection(long hGeom1, long hGeom2, long *phGeom)
{
	*phGeom = PtrToLong(GEOSIntersection(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2))));
	return S_OK;
}

STDMETHODIMP CAPI::Buffer(long hGeom, double dWidth, long nQuadSegs, long *phGeom)
{
	*phGeom = PtrToLong(GEOSBuffer(static_cast<GEOSGeom>(LongToPtr(hGeom)), dWidth, nQuadSegs));
	return S_OK;
}

STDMETHODIMP CAPI::ConvexHull(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(GEOSConvexHull(static_cast<GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::Difference(long hGeom1, long hGeom2, long *phGeom)
{
	*phGeom = PtrToLong(GEOSDifference(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2))));
	return S_OK;
}

STDMETHODIMP CAPI::SymDifference(long hGeom1, long hGeom2, long *phGeom)
{
	*phGeom = PtrToLong(GEOSSymDifference(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2))));
	return S_OK;
}

STDMETHODIMP CAPI::Boundary(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(GEOSBoundary(static_cast<GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::Union(long hGeom1, long hGeom2, long *phGeom)
{
	*phGeom = PtrToLong(GEOSUnion(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2))));
	return S_OK;
}

STDMETHODIMP CAPI::PointOnSurface(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(GEOSPointOnSurface(static_cast<GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::GetCentroid(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(GEOSGetCentroid(static_cast<GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::Relate(long hGeom1, long hGeom2, BSTR *pstrResult)
{
	USES_CONVERSION;
	char* pszResult = GEOSRelate(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2)));
	CComBSTR sbstrResult;
	sbstrResult = pszResult;
//	free(pszResult);
	return sbstrResult.CopyTo(pstrResult);
}

STDMETHODIMP CAPI::Polygonize(VARIANT vGeoms, long *phGeom)
{
	if (!(vGeoms.vt & VT_ARRAY) || !(vGeoms.vt & VT_I4))
		return E_INVALIDARG;

	SAFEARRAY* psa = vGeoms.parray;
	long* pnGeoms;
	::SafeArrayAccessData(psa, (void**)&pnGeoms);

	*phGeom = PtrToLong(GEOSPolygonize(reinterpret_cast<GEOSGeom*>(pnGeoms), psa->rgsabound->cElements));

	::SafeArrayUnaccessData(psa);
	return S_OK;
}

STDMETHODIMP CAPI::LineMerge(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(GEOSLineMerge(static_cast<GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::RelatePattern(long hGeom1, long hGeom2, BSTR strPattern, short *pnResult)
{
	USES_CONVERSION;
	*pnResult = GEOSRelatePattern(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2)), OLE2T(strPattern));
	return S_OK;
}

STDMETHODIMP CAPI::Disjoint(long hGeom1, long hGeom2, short *pnResult)
{
	*pnResult = GEOSDisjoint(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Touches(long hGeom1, long hGeom2, short *pnResult)
{
	*pnResult = GEOSTouches(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Intersects(long hGeom1, long hGeom2, short *pnResult)
{
	*pnResult = GEOSIntersects(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Crosses(long hGeom1, long hGeom2, short *pnResult)
{
	*pnResult = GEOSCrosses(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Within(long hGeom1, long hGeom2, short *pnResult)
{
	*pnResult = GEOSWithin(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Contains(long hGeom1, long hGeom2, short *pnResult)
{
	*pnResult = GEOSContains(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Overlaps(long hGeom1, long hGeom2, short *pnResult)
{
	*pnResult = GEOSOverlaps(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::Equals(long hGeom1, long hGeom2, short *pnResult)
{
	*pnResult = GEOSEquals(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2)));
	return S_OK;
}

STDMETHODIMP CAPI::isEmpty(long hGeom, short *pnResult)
{
	*pnResult = GEOSisEmpty(static_cast<GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::isValid(long hGeom, short *pnResult)
{
	*pnResult = GEOSisValid(static_cast<GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::isSimple(long hGeom, short *pnResult)
{
	*pnResult = GEOSisSimple(static_cast<GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::isRing(long hGeom, short *pnResult)
{
	*pnResult = GEOSisRing(static_cast<GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::HasZ(long hGeom, short *pnResult)
{
	*pnResult = GEOSHasZ(static_cast<GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::GeomTypeId(long hGeom, enum geosGeomTypeId *peTypeId)
{
	*peTypeId = static_cast<geosGeomTypeId>(GEOSGeomTypeId(static_cast<GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::GetSRID(long hGeom, long *pnSRID)
{
	*pnSRID = GEOSGetSRID(static_cast<GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::SetSRID(long hGeom, int nSRID)
{
	GEOSSetSRID(static_cast<GEOSGeom>(LongToPtr(hGeom)), nSRID);
	return S_OK;
}

STDMETHODIMP CAPI::GetNumGeometries(long hGeom, long *pnNumGeoms)
{
	*pnNumGeoms = GEOSGetNumGeometries(static_cast<GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::GetGeometryN(long hGeom, long nIndex, long *phGeom)
{
	*phGeom = PtrToLong(GEOSGetGeometryN(static_cast<GEOSGeom>(LongToPtr(hGeom)), nIndex));
	return S_OK;
}

STDMETHODIMP CAPI::GetNumInteriorRings(long hGeom, long *pnResult)
{
	*pnResult = GEOSGetNumInteriorRings(static_cast<GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::GetInteriorRingN(long hGeom, long nIndex, long *phGeom)
{
	*phGeom = PtrToLong(GEOSGetInteriorRingN(static_cast<GEOSGeom>(LongToPtr(hGeom)), nIndex));
	return S_OK;
}

STDMETHODIMP CAPI::GetExteriorRing(long hGeom, long *phGeom)
{
	*phGeom = PtrToLong(GEOSGetExteriorRing(static_cast<GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::GetNumCoordinates(long hGeom, long *pnNumCoords)
{
	*pnNumCoords = GEOSGetNumCoordinates(static_cast<GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::Geom_getDimensions(long hGeom, long *pnDims)
{
	*pnDims = GEOSGeom_getDimensions(static_cast<GEOSGeom>(LongToPtr(hGeom)));
	return S_OK;
}

STDMETHODIMP CAPI::Geom_getCoordSeq(long hGeom, long *phCoordSeq)
{
	*phCoordSeq = PtrToLong(GEOSGeom_getCoordSeq(static_cast<GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::Distance(long hGeom1, long hGeom2, double *pdDistance, long *pnResult)
{
	*pnResult = GEOSDistance(static_cast<GEOSGeom>(LongToPtr(hGeom1)), static_cast<GEOSGeom>(LongToPtr(hGeom2)), pdDistance);
	return S_OK;
}

STDMETHODIMP CAPI::Envelope(long hGeom, long* phGeom)
{
	*phGeom = PtrToLong(GEOSEnvelope(static_cast<GEOSGeom>(LongToPtr(hGeom))));
	return S_OK;
}

STDMETHODIMP CAPI::GeomType(long hGeom, BSTR* pstrType)
{
	CComBSTR sbstrType;
	sbstrType = GEOSGeomType(static_cast<GEOSGeom>(LongToPtr(hGeom)));
	return sbstrType.CopyTo(pstrType);
}

STDMETHODIMP CAPI::Area(long hGeom, double* pdArea, long* pnResult)
{
	*pnResult = GEOSArea(static_cast<GEOSGeom>(LongToPtr(hGeom)), pdArea);
	return S_OK;
}

STDMETHODIMP CAPI::Length(long hGeom, double* pdLength, long* pnResult)
{
	*pnResult = GEOSLength(static_cast<GEOSGeom>(LongToPtr(hGeom)), pdLength);
	return S_OK;
}
