// API.h : Declaration of the CAPI

#pragma once
#include "resource.h"       // main symbols

#include "geos_com.h"
#include "_IAPIEvents_CP.h"
#include <geos_c.h>

// CAPI

class ATL_NO_VTABLE CAPI : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAPI, &CLSID_API>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CAPI>,
	public CProxy_IAPIEvents<CAPI>, 
	public IDispatchImpl<IAPI, &IID_IAPI, &LIBID_Geos, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	static CAPI* sm_pThis;
	CAPI()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_API)


BEGIN_COM_MAP(CAPI)
	COM_INTERFACE_ENTRY(IAPI)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CAPI)
	CONNECTION_POINT_ENTRY(__uuidof(_IAPIEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		sm_pThis = this;
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

private:
	static void notice(const char *fmt, ...);
	static void error(const char *fmt, ...);

public:
	STDMETHOD(init)(void);
	STDMETHOD(finish)(void);
	STDMETHOD(version)(BSTR *pstrVersion);
	STDMETHOD(GeomFromWKT)(BSTR strBuf, long* phGeom);
	STDMETHOD(GeomToWKT)(long hGeom, BSTR* pstrBuf);
	STDMETHOD(setWKBOutputDims)(long nNewDims, long *pnOldDims);
	STDMETHOD(GeomFromWKB_buf)(VARIANT vBuf, long* phGeom);
	STDMETHOD(GeomToWKB_buf)(long hGeom, VARIANT* pvBuf);
	STDMETHOD(CoordSeq_create)(long nSize, long nDims, long* phCoordSeq);
	STDMETHOD(CoordSeq_clone)(long hCoordSeq, long* phCoordSeq);
	STDMETHOD(CoordSeq_destroy)(long hCoordSeq);
	STDMETHOD(CoordSeq_setX)(long hCoordSeq, long nIndex, double dVal, long* pnResult);
	STDMETHOD(CoordSeq_setY)(long hCoordSeq, long nIndex, double dVal, long* pnResult);
	STDMETHOD(CoordSeq_setZ)(long hCoordSeq, long nIndex, double dVal, long* pnResult);
	STDMETHOD(CoordSeq_setOrdinate)(long hCoordSeq, long nIndex, long nDims, double dVal, long* pnResult);
	STDMETHOD(CoordSeq_getX)(long hCoordSeq, long nIndex, double* pdVal, long* pnResult);
	STDMETHOD(CoordSeq_getY)(long hCoordSeq, long nIndex, double* pdVal, long* pnResult);
	STDMETHOD(CoordSeq_getZ)(long hCoordSeq, long nIndex, double* pdVal, long* pnResult);
	STDMETHOD(CoordSeq_getOrdinate)(long hCoordSeq, long nIndex, long nDims, double* pdVal, long* pnResult);
	STDMETHOD(CoordSeq_getSize)(long hCoordSeq, long* pnSize, long* pnResult);
	STDMETHOD(CoordSeq_getDimensions)(long hCoordSeq, long* pnDims, long* pnResult);
	STDMETHOD(Geom_createPoint)(long hCoordSeq, long* phGeom);
	STDMETHOD(Geom_createLinearRing)(long hCoordSeq, long* phGeom);
	STDMETHOD(Geom_createLineString)(long hCoordSeq, long* phGeom);
	STDMETHOD(Geom_createPolygon)(long hShell, VARIANT vHoles, long* phGeom);
	STDMETHOD(Geom_createCollection)(long nType, VARIANT vGeoms, long* phGeom);
	STDMETHOD(Geom_clone)(long hGeom, long* phGeom);
	STDMETHOD(Geom_destroy)(long hGeom);
	STDMETHOD(Intersection)(long hGeom1, long hGeom2, long* phGeom);
	STDMETHOD(Buffer)(long hGeom, double dWidth, long nQuadSegs, long* phGeom);
	STDMETHOD(ConvexHull)(long hGeom, long* phGeom);
	STDMETHOD(Difference)(long hGeom1, long hGeom2, long* phGeom);
	STDMETHOD(SymDifference)(long hGeom1, long hGeom2, long* phGeom);
	STDMETHOD(Boundary)(long hGeom, long* phGeom);
	STDMETHOD(Union)(long hGeom1, long hGeom2, long* phGeom);
	STDMETHOD(PointOnSurface)(long hGeom, long* phGeom);
	STDMETHOD(GetCentroid)(long hGeom, long* phGeom);
	STDMETHOD(Relate)(long hGeom1, long hGeom2, BSTR* pstrResult);
	STDMETHOD(Polygonize)(VARIANT vGeoms, long* phGeom);
	STDMETHOD(LineMerge)(long hGeom, long* phGeom);
	STDMETHOD(RelatePattern)(long hGeom1, long hGeom2, BSTR strPattern, short* pnResult);
	STDMETHOD(Disjoint)(long hGeom1, long hGeom2, short* pnResult);
	STDMETHOD(Touches)(long hGeom1, long hGeom2, short* pnResult);
	STDMETHOD(Intersects)(long hGeom1, long hGeom2, short* pnResult);
	STDMETHOD(Crosses)(long hGeom1, long hGeom2, short* pnResult);
	STDMETHOD(Within)(long hGeom1, long hGeom2, short* pnResult);
	STDMETHOD(Contains)(long hGeom1, long hGeom2, short* pnResult);
	STDMETHOD(Overlaps)(long hGeom1, long hGeom2, short* pnResult);
	STDMETHOD(Equals)(long hGeom1, long hGeom2, short* pnResult);
	STDMETHOD(isEmpty)(long hGeom, short* pnResult);
	STDMETHOD(isValid)(long hGeom, short* pnResult);
	STDMETHOD(isSimple)(long hGeom, short* pnResult);
	STDMETHOD(isRing)(long hGeom, short* pnResult);
	STDMETHOD(HasZ)(long hGeom, short* pnResult);
	STDMETHOD(GeomTypeId)(long hGeom, enum geosGeomTypeId* peTypeId);
	STDMETHOD(GetSRID)(long hGeom, long* pnSRID);
	STDMETHOD(SetSRID)(long hGeom, int nSRID);
	STDMETHOD(GetNumGeometries)(long hGeom, long* pnNumGeoms);
	STDMETHOD(GetGeometryN)(long hGeom, long nIndex, long* phGeom);
	STDMETHOD(GetNumInteriorRings)(long hGeom, long* pnResult);
	STDMETHOD(GetInteriorRingN)(long hGeom, long nIndex, long* phGeom);
	STDMETHOD(GetExteriorRing)(long hGeom, long* phGeom);
	STDMETHOD(GetNumCoordinates)(long hGeom, long* pnNumCoords);
	STDMETHOD(Geom_getCoordSeq)(long hGeom, long* phCoordSeq);
	STDMETHOD(Geom_getDimensions)(long hGeom, long* pnDims);
	STDMETHOD(Distance)(long hGeom1, long hGeom2, double* pdDistance, long* pnResult);
	STDMETHOD(Envelope)(long hGeom, long* phGeom);
	STDMETHOD(GeomType)(long hGeom, BSTR* pstrType);
	STDMETHOD(Area)(long hGeom, double* pdArea, long* pnResult);
	STDMETHOD(Length)(long hGeom, double* pdLength, long* pnResult);
};
#if _MSC_VER > 1200
OBJECT_ENTRY_AUTO(__uuidof(API), CAPI)
#endif // _MSC_VER