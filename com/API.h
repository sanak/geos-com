/*****************************************************************************
 *
 * FileName: API.h
 * Project:  GEOS COM Wrapper - http://sourceforge.jp/projects/geos-com
 * Purpose:  Declaration of the CAPI class.
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

#pragma once

#include "stdafx.h"
#include "geos_com.h"

class CAPIClassFactory : public IClassFactory
{
public:
	// IUnknown
	STDMETHOD(QueryInterface)(REFIID riid, void **ppv);
	STDMETHOD_(ULONG, AddRef)(void);
	STDMETHOD_(ULONG, Release)(void);
	// IClassFactory
	STDMETHOD(CreateInstance)(IUnknown *pUnkOuter, REFIID riid, void **ppv);
	STDMETHOD(LockServer)(BOOL bLock);
};

// CAPI
class CAPI : public IAPI,
	public ISupportErrorInfo,
	public _IAPIEvents,
	public IConnectionPointContainer,
	public IProvideClassInfo2
{
	LONG m_cRef;
	ITypeInfo *m_pTypeInfo;
	_IAPIEvents *m_pAPIEvents;
public:
	class XCPAPIEvents : public IConnectionPoint
	{
	public:
		CAPI *This(void);
		// IUnknown
		STDMETHOD(QueryInterface)(REFIID riid, void **ppv);
		STDMETHOD_(ULONG, AddRef)(void);
		STDMETHOD_(ULONG, Release)(void);
		// IConnectionPoint
		STDMETHOD(GetConnectionInterface)(IID *piid);
		STDMETHOD(GetConnectionPointContainer)(IConnectionPointContainer **ppcps);
		STDMETHOD(Advise)(IUnknown *pUnk, DWORD *pdwCookie);
		STDMETHOD(Unadvise)(DWORD dwCookie);
		STDMETHOD(EnumConnections)(IEnumConnections **ppEnum);
	} m_xcpAPIEvents;
	friend class XCPAPIEvents;
public:
	static CAPI* sm_pThis;
	CAPI(void);
	virtual ~CAPI(void);
	HRESULT FinalConstruct();
	
private:
	static void notice(const char *fmt, ...);
	static void error(const char *fmt, ...);
	// _IAPIEvents
	HRESULT Fire_onNotice(BSTR strNotice);
	HRESULT Fire_onError(BSTR strError);

public:
	// IUnknown
	STDMETHOD(QueryInterface)(REFIID riid, void **ppv);
	STDMETHOD_(ULONG, AddRef)(void);
	STDMETHOD_(ULONG, Release)(void);
	// IDispatch
	STDMETHOD(GetTypeInfoCount)(UINT *pit);
	STDMETHOD(GetTypeInfo)(UINT it, LCID lcid, ITypeInfo **ppti);
	STDMETHOD(GetIDsOfNames)(REFIID riid, LPOLESTR *pNames, UINT cNames, LCID lcid, DISPID *pdispids);
	STDMETHOD(Invoke)(DISPID id, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pd, VARIANT *pVarResult, EXCEPINFO *pe, UINT *pu);
	// ISupportErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
	// IConnectionPointContainer
	STDMETHOD(EnumConnectionPoints)(IEnumConnectionPoints **ppEnum);
	STDMETHOD(FindConnectionPoint)(REFIID riid, IConnectionPoint **ppcp);
	// IProvideClassInfo
	STDMETHOD(GetClassInfo)(ITypeInfo **ppti);
	// IProvideClassInfo2
	STDMETHOD(GetGUID)(DWORD dwgKind, GUID *pguid);
	// IAPI
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
	STDMETHOD(RelatePattern)(long hGeom1, long hGeom2, BSTR strPattern, unsigned char* pbyResult);
	STDMETHOD(Disjoint)(long hGeom1, long hGeom2, unsigned char* pbyResult);
	STDMETHOD(Touches)(long hGeom1, long hGeom2, unsigned char* pbyResult);
	STDMETHOD(Intersects)(long hGeom1, long hGeom2, unsigned char* pbyResult);
	STDMETHOD(Crosses)(long hGeom1, long hGeom2, unsigned char* pbyResult);
	STDMETHOD(Within)(long hGeom1, long hGeom2, unsigned char* pbyResult);
	STDMETHOD(Contains)(long hGeom1, long hGeom2, unsigned char* pbyResult);
	STDMETHOD(Overlaps)(long hGeom1, long hGeom2, unsigned char* pbyResult);
	STDMETHOD(Equals)(long hGeom1, long hGeom2, unsigned char* pbyResult);
	STDMETHOD(isEmpty)(long hGeom, unsigned char* pbyResult);
	STDMETHOD(isValid)(long hGeom, unsigned char* pbyResult);
	STDMETHOD(isSimple)(long hGeom, unsigned char* pbyResult);
	STDMETHOD(isRing)(long hGeom, unsigned char* pbyResult);
	STDMETHOD(HasZ)(long hGeom, unsigned char* pbyResult);
	STDMETHOD(GeomTypeId)(long hGeom, enum GEOSGeomTypes* peTypes);
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
	STDMETHOD(getWKBOutputDims)(long* pnResult);
	STDMETHOD(getWKBByteOrder)(GEOSByteOrders* peResult);
	STDMETHOD(setWKBByteOrder)(GEOSByteOrders eByteOrder, GEOSByteOrders* peResult);
	STDMETHOD(GeomFromHEX_buf)(VARIANT vHex, long* phGeom);
	STDMETHOD(GeomToHEX_buf)(long hGeom, VARIANT* pvHex);
	STDMETHOD(Simplify)(long hGeom, double dTolerance, long* phGeom);
	STDMETHOD(TopologyPreserveSimplify)(long hGeom, double dTolerance, long* phGeom);
	STDMETHOD(EqualsExact)(long hGeom1, long hGeom2, double dTolerance, unsigned char* pbyResult);
	STDMETHOD(Normalize)(long hGeom, long* pnResult);
};
