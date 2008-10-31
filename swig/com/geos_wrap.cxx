
#ifdef __cplusplus
template<typename T> class SwigValueWrapper {
    T *tt;
public:
    SwigValueWrapper() : tt(0) { }
    SwigValueWrapper(const SwigValueWrapper<T>& rhs) : tt(new T(*rhs.tt)) { }
    SwigValueWrapper(const T& t) : tt(new T(t)) { }
    ~SwigValueWrapper() { delete tt; } 
    SwigValueWrapper& operator=(const T& t) { delete tt; tt = new T(t); return *this; }
    operator T&() const { return *tt; }
    T *operator&() { return tt; }
private:
    SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__)) 
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__)) 
# else
#   define SWIGUNUSED 
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif 
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif




#include <windows.h>
#include <olectl.h>
#include <tchar.h>
#include <comutil.h>

#include <string.h>
#include <memory.h>

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) { return nullreturn; } else

typedef void (SWIGSTDCALL *SWIG_funcptr)(void);

typedef struct {
  SWIG_funcptr *vtable;
  SWIG_funcptr newInstance;
  LONG refCount;
  int aggregatable;
} SWIGClassFactory;

/* For consistent manipulation regardless of C or C++ mode */
typedef struct {
  SWIG_funcptr *vtable;
} SWIGIUnknown;

typedef struct {
  SWIG_funcptr *vtable; /* vtable for the methods of the wrapped object */
  SWIG_funcptr *SWIGWrappedObject_vtable; /* vtable for helper methods */
  SWIG_funcptr *aggregated_vtable; /* vtable to present to the outer object */
  SWIG_funcptr *ISupportErrorInfo_vtable;
  void *cPtr; /* pointer to the wrapped object */
  int cMemOwn; /* memory owned by the proxy? */
  LONG refCount; /* reference count */
  void (*deleteInstance)(void *); /* destructor */
  ITypeInfo *typeInfo; /* ITypeInfo object for IDispatch */
  SWIGIUnknown *outer; /* outer type in COM aggregation */
  GUID *additionalIID; /* IID supported by object (apart from IUnknown and IDispatch) */
} SWIGWrappedObject;

GUID IID_ISWIGWrappedObject = { 0x1a3a5cc8, 0x9a61, 0x4681, { 0xae, 0x9c, 0xd0, 0x42, 0x93, 0xf3, 0x57, 0x34 }};
static LONG globalRefCount = 0;

static int SWIGIsEqual(const GUID *a, const GUID *b) {
  return memcmp(a, b, sizeof(GUID)) == 0;
}

void SWIG_SetErrorInfo(const char *msg, const char *source, const GUID *guid) {
  SWIGIUnknown *icei;
  IErrorInfo *iei;
  int msglen = MultiByteToWideChar(CP_ACP, 0, msg, -1, 0, 0);
  wchar_t *wmsg = new wchar_t[msglen + 1];
  int sourcelen = MultiByteToWideChar(CP_ACP, 0, source, -1, 0, 0);
  wchar_t *wsource = new wchar_t[sourcelen + 1];
  MultiByteToWideChar(CP_ACP, 0, msg, -1, wmsg, msglen);
  MultiByteToWideChar(CP_ACP, 0, source, -1, wsource, sourcelen);
  CreateErrorInfo((ICreateErrorInfo **) &icei);

  /* SetGUID */
  ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, const GUID *)) icei->vtable[3])(icei, guid);

  /* SetSource */
  ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, LPCOLESTR)) icei->vtable[4])(icei, wsource);

  /* SetDescription */
  ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, LPCOLESTR)) icei->vtable[5])(icei, wmsg);

  if (wmsg)
    delete wmsg;
  if (wsource)
    delete wsource;

  /* Use QueryInterface to convert ICreateErrorInfo to IErrorInfo */
  ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, const GUID *, LPVOID *)) icei->vtable[0])(icei, &IID_IErrorInfo, (void **) &iei);

  SetErrorInfo(0, iei);

  /* Release both object references */
  ((LONG (SWIGSTDCALL *)(SWIGIUnknown *)) icei->vtable[2])(icei);
  ((LONG (SWIGSTDCALL *)(SWIGIUnknown *)) ((SWIGIUnknown *) iei)->vtable[2])((SWIGIUnknown *) iei);
}

long SWIGSTDCALL SWIGAddRef1(void *iunk) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) iunk;

  if (obj->outer != NULL) {
    return ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (obj->outer->vtable[1]))(obj->outer);
  } else {
    InterlockedIncrement(&globalRefCount);
    return InterlockedIncrement(&obj->refCount);
  }
}

long SWIGSTDCALL SWIGAddRef2(void *iunk) {
  return SWIGAddRef1((void **)iunk - 1);
}

long SWIGSTDCALL SWIGAddRef3(void *iunk) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)iunk - 2);

  InterlockedIncrement(&globalRefCount);
  return InterlockedIncrement(&obj->refCount);
}

long SWIGSTDCALL SWIGAddRef4(void *iunk) {
  return SWIGAddRef1((void **)iunk - 3);
}

long SWIGSTDCALL SWIGRelease1(void *iunk) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) iunk;

  if (obj->outer != NULL) {
    return ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (obj->outer->vtable[2]))(obj->outer);
  } else {
    LONG res = InterlockedDecrement(&obj->refCount);

    if (res == 0) {
      if (obj->cMemOwn && obj->deleteInstance != 0) {
        obj->deleteInstance(obj->cPtr);
      }

#ifdef __cplusplus
      delete obj;
#else
      free(obj);
#endif    
    }

    InterlockedDecrement(&globalRefCount);
    return res;
  }
}

long SWIGSTDCALL SWIGRelease2(void *iunk) {
  return SWIGRelease1((void **)iunk - 1);
}

long SWIGSTDCALL SWIGRelease3(void *iunk) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)iunk - 2);

  LONG res = InterlockedDecrement(&obj->refCount);

  if (res == 0) {
    if (obj->cMemOwn && obj->deleteInstance != 0) {
      obj->deleteInstance((SWIGIUnknown *) obj);
    }

#ifdef __cplusplus
    delete obj;
#else
    free(obj);
#endif    
  }

  InterlockedDecrement(&globalRefCount);
  return res;
}

long SWIGSTDCALL SWIGRelease4(void *iunk) {
  return SWIGRelease1((void **)iunk - 3);
}

HRESULT SWIGSTDCALL SWIGQueryInterface4(void *iunk, GUID *iid, void **ppvObject) {
  /*
   * Forwards the call to the main vtable. This is not optimal as the call cannot
   * be inlined. However generating a separate function for each class is
   * rather inconvenient.
   */

  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **) iunk - 3);

  return ((HRESULT (SWIGSTDCALL *)(void *, GUID *, void **)) obj->vtable[0]) ((void *) obj, iid, ppvObject);
}

void * SWIGSTDCALL SWIGGetCPtr(void *iunk) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)iunk - 1);

  return obj->cPtr;
}

HRESULT SWIGSTDCALL SWIGGetTypeInfoCount(SWIGWrappedObject *obj, unsigned int * pctinfo) {
  *pctinfo = 1;

  return S_OK;
}

HRESULT SWIGSTDCALL SWIGGetTypeInfo(SWIGWrappedObject *obj, unsigned int iTInfo, LCID  lcid, ITypeInfo **  ppTInfo) {
  *ppTInfo = obj->typeInfo;

  return S_OK;
}

HRESULT SWIGSTDCALL SWIGGetIDsOfNames(SWIGWrappedObject *obj, REFIID riid, OLECHAR FAR* FAR* rgszNames,  
    unsigned int cNames, LCID lcid, DISPID FAR* rgDispId) {
  HRESULT hres = DispGetIDsOfNames(obj->typeInfo, rgszNames, cNames, rgDispId);

  return hres;
}

HRESULT SWIGSTDCALL SWIGInvoke(SWIGWrappedObject *obj, DISPID dispIdMember, REFIID riid, LCID lcid,                
    WORD wFlags, DISPPARAMS FAR* pDispParams, VARIANT FAR*  pVarResult,  
    EXCEPINFO FAR*  pExcepInfo, unsigned int FAR*  puArgErr) {
  HRESULT hres = DispInvoke(
      (void *) obj, obj->typeInfo,
      dispIdMember, wFlags, pDispParams,
      pVarResult, pExcepInfo, puArgErr); 

  return hres;
}

HRESULT SWIGSTDCALL SWIGInterfaceSupportsErrorInfo(void *ignored, GUID *riid) {
  return S_OK;
}

SWIG_funcptr ISupportErrorInfo_vtable[] = {
  (SWIG_funcptr) SWIGQueryInterface4,
  (SWIG_funcptr) SWIGAddRef4,
  (SWIG_funcptr) SWIGRelease4,
  (SWIG_funcptr) SWIGInterfaceSupportsErrorInfo
};

static OLECHAR SWIG_typelib_path[MAX_PATH + 1];
static ITypeLib *SWIG_typelib = NULL;

long SWIGSTDCALL SWIGClassFactoryAddRef(SWIGClassFactory *factory) {
  InterlockedIncrement(&globalRefCount);
  return InterlockedIncrement(&factory->refCount);
}

long SWIGSTDCALL SWIGClassFactoryRelease(SWIGClassFactory *factory) {
  LONG res = InterlockedDecrement(&factory->refCount);

  if (res == 0) {
#ifdef __cplusplus
    delete factory;
#else
    free(factory);
#endif    
  }

  InterlockedDecrement(&globalRefCount);
  return res;
}

HRESULT SWIGSTDCALL SWIGClassFactoryQueryInterface(SWIGClassFactory *factory, GUID *iid, void **ppvObject) {
  if (SWIGIsEqual(iid, &IID_IUnknown) || SWIGIsEqual(iid, &IID_IClassFactory)) {
    SWIGClassFactoryAddRef(factory);
    *ppvObject = factory;

    return S_OK;
  } else {
    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL SWIGClassFactoryCreateInstance(SWIGClassFactory *factory, SWIGIUnknown *punkOuter, GUID *riid, void **ppvObject)
{
  HRESULT hr;
  SWIGWrappedObject *obj;

  if (ppvObject == NULL)
     return E_INVALIDARG;

  if (punkOuter && (!factory->aggregatable || !SWIGIsEqual(riid, &IID_IUnknown)))
     return CLASS_E_NOAGGREGATION;

  /* Create the instance */
  obj = (SWIGWrappedObject *) ((void* (SWIGSTDCALL *)()) factory->newInstance)();

  if (obj == NULL) {
    return E_OUTOFMEMORY;
  }

  if (!punkOuter) {
    hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **)) obj->vtable[0])
        ((SWIGIUnknown *) obj, riid, ppvObject);

    /* Release reference */
    ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (obj->vtable[2]))((SWIGIUnknown *) obj);
  } else {
    obj->outer = punkOuter;

    /* We need to return the address of aggregate_vtable */
    *ppvObject = &obj->aggregated_vtable;

    hr = S_OK;
  }

  return hr;
}

HRESULT SWIGSTDCALL SWIGClassFactoryLockServer(SWIGClassFactory *factory, BOOL fLock) {
  CoLockObjectExternal((IUnknown *) (void *) factory, fLock, TRUE);

  return S_OK;
}

SWIG_funcptr SWIGClassFactory_vtable[] = {
  (SWIG_funcptr) SWIGClassFactoryQueryInterface,
  (SWIG_funcptr) SWIGClassFactoryAddRef,
  (SWIG_funcptr) SWIGClassFactoryRelease,
  (SWIG_funcptr) SWIGClassFactoryCreateInstance,
  (SWIG_funcptr) SWIGClassFactoryLockServer
};

typedef struct {
  SWIG_funcptr newInstance;
  GUID *guid;
  TCHAR *guid_string;
  TCHAR *oleaut_string;
  int aggregatable;
} SWIGClassDescription_t;

void _wrap_delete_staticclass(void *arg) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) arg;
#ifdef __cplusplus
  delete obj;
#else
  free(obj);
#endif
}

void *_wrap_new_staticclass(SWIG_funcptr *vtable, GUID *iid) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = vtable;
  res->SWIGWrappedObject_vtable = NULL;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  /* cPtr and cMemOwn make no sense for static classes */
  res->cPtr = NULL;
  res->cMemOwn = 0;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = _wrap_delete_staticclass;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, iid, &res->typeInfo);
  res->outer = NULL;
  res->additionalIID = iid;
  return (void *) res;
}

HRESULT SWIGSTDCALL _wrap_staticclass_QueryInterface(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (SWIGIsEqual(iid, &IID_IUnknown) ||
      SWIGIsEqual(iid, &IID_IDispatch) ||
      (obj->additionalIID != NULL && SWIGIsEqual(iid, obj->additionalIID))) {
    SWIGAddRef1(that);
    *ppvObject = that;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  return E_NOINTERFACE;
}

HRESULT SWIGSTDCALL _wrap_opaque_QueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;
  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef1(that); 
    *ppvObject = (void *) ((void **)that + 1);
    return S_OK;
  }
  
  if (SWIGIsEqual(iid, &IID_IUnknown) ||
      (obj->additionalIID != NULL && SWIGIsEqual(iid, obj->additionalIID))) {
    /* FIXME: This could be more elegant */
    SWIGAddRef1(that);
    *ppvObject = that;
    return S_OK;
  }
  
  return E_NOINTERFACE;
}

HRESULT SWIGSTDCALL _wrap_opaque_QueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrap_opaque_QueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

SWIG_funcptr _wrap_opaque_SWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrap_opaque_QueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrap_opaque_vtable[] = {
  (SWIG_funcptr) _wrap_opaque_QueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
};

void * SWIGSTDCALL SWIG_wrap_opaque(void *arg, int cMemOwn, GUID *iid) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrap_opaque_vtable;
  res->SWIGWrappedObject_vtable = _wrap_opaque_SWIGWrappedObject_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = NULL;
  res->outer = NULL;
  res->additionalIID = iid;
  return (void *) res;
}


/*  Errors in SWIG */ // TODO: error mapping (E_OUTOFMEMORY .etc)
#define  SWIG_UnknownError    	   -1 
#define  SWIG_IOError        	   -2 
#define  SWIG_RuntimeError   	   -3 
#define  SWIG_IndexError     	   -4 
#define  SWIG_TypeError      	   -5 
#define  SWIG_DivisionByZero 	   -6 
#define  SWIG_OverflowError  	   -7 
#define  SWIG_SyntaxError    	   -8 
#define  SWIG_ValueError     	   -9 
#define  SWIG_SystemError    	   -10
#define  SWIG_AttributeError 	   -11
#define  SWIG_MemoryError    	   -12 
#define  SWIG_NullReferenceError   -13

// <-- add #geosanak 2008.10.29
#define SWIG_as_voidptr(a) const_cast< void * >(static_cast< const void * >(a)) 
#define SWIG_as_voidptrptr(a) ((void)SWIG_as_voidptr(*a),reinterpret_cast< void** >(a)) 

#define SWIGTYPE_p_GeosCoordinateSequence SWIG_wrapCoordinateSequence
#define SWIGTYPE_p_GeosGeometry SWIG_wrapGeometry
#define SWIGTYPE_p_GeosGeometryCollection SWIG_wrapGeometryCollection
#define SWIGTYPE_p_GeosLineString SWIG_wrapLineString
#define SWIGTYPE_p_GeosLinearRing SWIG_wrapLinearRing
#define SWIGTYPE_p_GeosMultiLineString SWIG_wrapMultiLineString
#define SWIGTYPE_p_GeosMultiLinearRing SWIG_wrapMultiLinearRing
#define SWIGTYPE_p_GeosMultiPoint SWIG_wrapMultiPoint
#define SWIGTYPE_p_GeosMultiPolygon SWIG_wrapMultiPolygon
#define SWIGTYPE_p_GeosPoint SWIG_wrapPoint
#define SWIGTYPE_p_GeosPolygon SWIG_wrapPolygon

#define SWIG_NewPointerObj(ptr, fnc, flags) ((!ptr) ? NULL : (SWIGIUnknown *) fnc(ptr, flags))
// add #geosanak 2008.10.29 -->

#include <stdio.h>


#include <stdexcept>


#include <string>


#include <stdexcept>


#include <vector>
#include <stdexcept>

 
#include "geos_c.h"
/* Needed for va_start, etc. */
#include <stdarg.h>


    static const int DEFAULT_QUADRANT_SEGMENTS=8;



/* This is not thread safe ! */
static const int MESSAGE_SIZE = 1000;
static char message[MESSAGE_SIZE];

void noticeHandler(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vsnprintf(message, sizeof(message) - 1, fmt, args);
    va_end(args);
}

void errorHandler(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vsnprintf(message, sizeof(message) - 1, fmt, args);
    va_end(args);
}


typedef void GeosCoordinateSequence;

void checkCoordSeqBounds(const GEOSCoordSeq coordSeq, const size_t index)
{
    unsigned int size = 0;
    GEOSCoordSeq_getSize(coordSeq, &size);

    if (index < 0 || index >= size)
        throw std::runtime_error("Index out of bounds");
}

SWIGINTERN GeosCoordinateSequence *new_GeosCoordinateSequence(size_t size,size_t dims){
        return (GeosCoordinateSequence*) GEOSCoordSeq_create(size, dims);
    }
SWIGINTERN void delete_GeosCoordinateSequence(GeosCoordinateSequence *self){
        GEOSCoordSeq coords = (GEOSCoordSeq) self;
        return GEOSCoordSeq_destroy(coords);
    }
SWIGINTERN GeosCoordinateSequence *GeosCoordinateSequence_clone(GeosCoordinateSequence *self){
        GEOSCoordSeq coords = (GEOSCoordSeq) self;
        return (GeosCoordinateSequence*) GEOSCoordSeq_clone(coords);
    }
SWIGINTERN int GeosCoordinateSequence_setX(GeosCoordinateSequence *self,size_t idx,double val){
        GEOSCoordSeq coords = (GEOSCoordSeq) self;
        checkCoordSeqBounds(coords, idx);
        return GEOSCoordSeq_setX(coords, idx, val);
    }
SWIGINTERN int GeosCoordinateSequence_setY(GeosCoordinateSequence *self,size_t idx,double val){
        GEOSCoordSeq coords = (GEOSCoordSeq) self;
        checkCoordSeqBounds(coords, idx);
        return GEOSCoordSeq_setY(coords, idx, val);
    }
SWIGINTERN int GeosCoordinateSequence_setZ(GeosCoordinateSequence *self,size_t idx,double val){
        GEOSCoordSeq coords = (GEOSCoordSeq) self;
        checkCoordSeqBounds(coords, idx);
        return GEOSCoordSeq_setZ(coords, idx, val);
    }
SWIGINTERN int GeosCoordinateSequence_setOrdinate(GeosCoordinateSequence *self,size_t idx,size_t dim,double val){
        GEOSCoordSeq coords = (GEOSCoordSeq) self;
        checkCoordSeqBounds(coords, idx);
        return GEOSCoordSeq_setOrdinate(coords, idx, dim, val);
    }
SWIGINTERN double GeosCoordinateSequence_getX(GeosCoordinateSequence *self,size_t idx){
        double result;
        GEOSCoordSeq coords = (GEOSCoordSeq) self;
        checkCoordSeqBounds(coords, idx);
        GEOSCoordSeq_getX(coords, idx, &result);
        return result;
    }
SWIGINTERN double GeosCoordinateSequence_getY(GeosCoordinateSequence *self,size_t idx){
        double result;
        GEOSCoordSeq coords = (GEOSCoordSeq) self;
        checkCoordSeqBounds(coords, idx);
        GEOSCoordSeq_getY(coords, idx, &result);
        return result;
    }
SWIGINTERN double GeosCoordinateSequence_getZ(GeosCoordinateSequence *self,size_t idx){
        double result;
        GEOSCoordSeq coords = (GEOSCoordSeq) self;
        checkCoordSeqBounds(coords, idx);
        GEOSCoordSeq_getZ(coords, idx, &result);
        return result;
    }
SWIGINTERN double GeosCoordinateSequence_getOrdinate(GeosCoordinateSequence *self,size_t idx,size_t dim){
        double result;
        GEOSCoordSeq coords = (GEOSCoordSeq) self;
        checkCoordSeqBounds(coords, idx);
        GEOSCoordSeq_getOrdinate(coords, idx, dim, &result);
        return result;
    }
SWIGINTERN unsigned int GeosCoordinateSequence_getSize(GeosCoordinateSequence *self){
        unsigned int result;
        GEOSCoordSeq coords = (GEOSCoordSeq) self;
        GEOSCoordSeq_getSize(coords, &result);
        return result;
    }
SWIGINTERN unsigned int GeosCoordinateSequence_getDimensions(GeosCoordinateSequence *self){
        unsigned int result;
        GEOSCoordSeq coords = (GEOSCoordSeq) self;
        GEOSCoordSeq_getDimensions(coords, &result);
        return result;
    }

typedef void GeosGeometry;
typedef void GeosPoint;
typedef void GeosLineString;
typedef void GeosLinearRing;
typedef void GeosPolygon;
typedef void GeosGeometryCollection;
typedef void GeosMultiPoint;
typedef void GeosMultiLineString;
typedef void GeosMultiLinearRing;
typedef void GeosMultiPolygon;

typedef void GeosWktReader;
typedef void GeosWktWriter;
typedef void GeosWkbReader;
typedef void GeosWkbWriter;


bool checkBoolResult(char result)
{
    int intResult = (int) result;

    if (intResult == 1)
        return true;
    else if (intResult == 0)
        return false;
    else
        throw std::runtime_error(message);
}

SWIGINTERN void delete_GeosGeometry(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom_destroy(geom);
    }
SWIGINTERN GeosGeometry *GeosGeometry_clone(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return GEOSGeom_clone(geom);
    }
SWIGINTERN char *GeosGeometry_geomType(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return GEOSGeomType(geom);
    }
SWIGINTERN int GeosGeometry_typeId(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return GEOSGeomTypeId(geom);
    }
SWIGINTERN void GeosGeometry_normalize(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        int result = GEOSNormalize(geom);

        if (result == -1)
            throw std::runtime_error(message);
    }
SWIGINTERN int GeosGeometry_getSRID(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return GEOSGetSRID(geom);
    }
SWIGINTERN void GeosGeometry_setSRID(GeosGeometry *self,int SRID){
        GEOSGeom geom = (GEOSGeom) self;
        return GEOSSetSRID(geom, SRID);
    }
SWIGINTERN size_t GeosGeometry_getDimensions(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return GEOSGeom_getDimensions(geom);
    }
SWIGINTERN size_t GeosGeometry_getNumGeometries(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        size_t result = GEOSGetNumGeometries(geom);
        
        if ((int)result == -1)
            throw std::runtime_error(message);

        return result;
    }
SWIGINTERN GeosGeometry *GeosGeometry_intersection(GeosGeometry *self,GeosGeometry *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return (GeosGeometry*) GEOSIntersection(geom, otherGeom);
    }
SWIGINTERN GeosGeometry *GeosGeometry_buffer(GeosGeometry *self,double width,int quadsegs){
        GEOSGeom geom = (GEOSGeom) self;
        return (GeosGeometry*) GEOSBuffer(geom, width, quadsegs);
    }
SWIGINTERN GeosGeometry *GeosGeometry_convexHull(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return (GeosGeometry*) GEOSConvexHull(geom);
    }
SWIGINTERN GeosGeometry *GeosGeometry_difference(GeosGeometry *self,GeosGeometry *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return (GeosGeometry*) GEOSDifference(geom, otherGeom);
    }
SWIGINTERN GeosGeometry *GeosGeometry_symDifference(GeosGeometry *self,GeosGeometry *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return (GeosGeometry*) GEOSSymDifference(geom, otherGeom);
    }
SWIGINTERN GeosGeometry *GeosGeometry_boundary(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return (GeosGeometry*) GEOSBoundary(geom);
    }
SWIGINTERN GeosGeometry *GeosGeometry_geomUnion(GeosGeometry *self,GeosGeometry *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return (GeosGeometry*) GEOSUnion(geom, otherGeom);
    }
SWIGINTERN GeosGeometry *GeosGeometry_pointOnSurface(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return (GeosGeometry*) GEOSPointOnSurface(geom);
    }
SWIGINTERN GeosGeometry *GeosGeometry_getCentroid(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return (GeosGeometry*) GEOSGetCentroid(geom);
    }
SWIGINTERN GeosGeometry *GeosGeometry_getEnvelope(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return (GeosGeometry*) GEOSEnvelope(geom);
    }
SWIGINTERN char *GeosGeometry_relate(GeosGeometry *self,GeosGeometry *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return GEOSRelate(geom, otherGeom);
    }
SWIGINTERN GeosGeometry *GeosGeometry_lineMerge(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return GEOSLineMerge(geom);
    }
SWIGINTERN GeosGeometry *GeosGeometry_simplify(GeosGeometry *self,double tolerance){
        GEOSGeom geom = (GEOSGeom) self;
        return (GeosGeometry*) GEOSSimplify(geom, tolerance);
    }
SWIGINTERN GeosGeometry *GeosGeometry_topologyPreserveSimplify(GeosGeometry *self,double tolerance){
        GEOSGeom geom = (GEOSGeom) self;
        return (GeosGeometry*) GEOSTopologyPreserveSimplify(geom, tolerance);
    }
SWIGINTERN bool GeosGeometry_relatePattern(GeosGeometry *self,GeosGeometry const *other,char const *pat){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return checkBoolResult(GEOSRelatePattern(geom, otherGeom, pat));
    }
SWIGINTERN bool GeosGeometry_disjoint(GeosGeometry *self,GeosGeometry const *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return checkBoolResult(GEOSDisjoint(geom, otherGeom));
    }
SWIGINTERN bool GeosGeometry_touches(GeosGeometry *self,GeosGeometry const *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return checkBoolResult(GEOSTouches(geom, otherGeom));
    }
SWIGINTERN bool GeosGeometry_intersects(GeosGeometry *self,GeosGeometry const *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return checkBoolResult(GEOSIntersects(geom, otherGeom));
    }
SWIGINTERN bool GeosGeometry_crosses(GeosGeometry *self,GeosGeometry const *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return checkBoolResult(GEOSCrosses(geom, otherGeom));
    }
SWIGINTERN bool GeosGeometry_within(GeosGeometry *self,GeosGeometry const *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return checkBoolResult(GEOSWithin(geom, otherGeom));
    }
SWIGINTERN bool GeosGeometry_contains(GeosGeometry *self,GeosGeometry const *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return checkBoolResult(GEOSContains(geom, otherGeom));
    }
SWIGINTERN bool GeosGeometry_overlaps(GeosGeometry *self,GeosGeometry const *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return checkBoolResult(GEOSOverlaps(geom, otherGeom));
    }
SWIGINTERN bool GeosGeometry_equals(GeosGeometry *self,GeosGeometry const *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return checkBoolResult(GEOSEquals(geom, otherGeom));
    }
SWIGINTERN bool GeosGeometry_equalsExact(GeosGeometry *self,GeosGeometry const *other,double tolerance){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        return checkBoolResult(GEOSEqualsExact(geom, otherGeom, tolerance));
    }
SWIGINTERN bool GeosGeometry_isEmpty(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return checkBoolResult(GEOSisEmpty(geom));
    }
SWIGINTERN bool GeosGeometry_isValid(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return checkBoolResult(GEOSisValid(geom));
    }
SWIGINTERN bool GeosGeometry_isSimple(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return checkBoolResult(GEOSisSimple(geom));
    }
SWIGINTERN bool GeosGeometry_isRing(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return checkBoolResult(GEOSisRing(geom));
    }
SWIGINTERN bool GeosGeometry_hasZ(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        return checkBoolResult(GEOSHasZ(geom));
    }
SWIGINTERN double GeosGeometry_area(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        double result;

        int code = GEOSArea(geom, &result);

        if (code == 0)
            throw std::runtime_error(message);

        return result;
    }
SWIGINTERN double GeosGeometry_length(GeosGeometry *self){
        GEOSGeom geom = (GEOSGeom) self;
        double result;

        int code = GEOSLength(geom, &result);

        if (code == 0)
            throw std::runtime_error(message);

        return result;
    }
SWIGINTERN double GeosGeometry_distance(GeosGeometry *self,GeosGeometry const *other){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom otherGeom = (GEOSGeom) other;
        double result;

        int code = GEOSDistance(geom, otherGeom, &result);

        if (code == 0)
            throw std::runtime_error(message);

        return result;
    }
SWIGINTERN void delete_GeosPoint(GeosPoint *self){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom_destroy(geom);
    }
SWIGINTERN GeosCoordinateSequence const *GeosPoint_getCoordSeq(GeosPoint *self){
        GEOSGeom geom = (GEOSGeom) self;
        const GEOSCoordSeq result = (const GEOSCoordSeq) GEOSGeom_getCoordSeq(geom);

        if (result == NULL)
            throw std::runtime_error(message);

        return (const GeosCoordinateSequence*) result;
    }
SWIGINTERN void delete_GeosLineString(GeosLineString *self){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom_destroy(geom);
    }
SWIGINTERN GeosCoordinateSequence const *GeosLineString_getCoordSeq(GeosLineString *self){
        GEOSGeom geom = (GEOSGeom) self;
        const GEOSCoordSeq result = (const GEOSCoordSeq) GEOSGeom_getCoordSeq(geom);

        if (result == NULL)
            throw std::runtime_error(message);

        return (const GeosCoordinateSequence*) result;
    }
SWIGINTERN void delete_GeosLinearRing(GeosLinearRing *self){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom_destroy(geom);
    }
SWIGINTERN GeosCoordinateSequence const *GeosLinearRing_getCoordSeq(GeosLinearRing *self){
        GEOSGeom geom = (GEOSGeom) self;
        const GEOSCoordSeq result = (const GEOSCoordSeq) GEOSGeom_getCoordSeq(geom);

        if (result == NULL)
            throw std::runtime_error(message);

        return (const GeosCoordinateSequence*) result;
    }
SWIGINTERN void delete_GeosPolygon(GeosPolygon *self){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom_destroy(geom);
    }
SWIGINTERN GeosGeometry const *GeosPolygon_getExteriorRing(GeosPolygon *self){
        GEOSGeom geom = (GEOSGeom) self;
        const GEOSGeom result = (const GEOSGeom) GEOSGetExteriorRing(geom);

        if (result == NULL)
            throw std::runtime_error(message);

        return (const GeosGeometry*) result;
    }
SWIGINTERN size_t GeosPolygon_getNumInteriorRings(GeosPolygon *self){
        GEOSGeom geom = (GEOSGeom) self;
        size_t result = GEOSGetNumInteriorRings(geom);

        if ((int)result == -1)
            throw std::runtime_error(message);

        return result;
    }
SWIGINTERN GeosGeometry const *GeosPolygon_getInteriorRingN(GeosPolygon *self,size_t n){
        GEOSGeom geom = (GEOSGeom) self;

        size_t size = GEOSGetNumInteriorRings(geom);

        if (n < 0 || n >= size)
            throw std::runtime_error("Index out of bounds");

        const GEOSGeom result = (const GEOSGeom) GEOSGetInteriorRingN(geom, n);

        if (result == NULL)
            throw std::runtime_error(message);

        return (const GeosGeometry*) result;
    }
SWIGINTERN void delete_GeosGeometryCollection(GeosGeometryCollection *self){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom_destroy(geom);
    }
SWIGINTERN GeosGeometry const *GeosGeometryCollection_getGeometryN(GeosGeometryCollection *self,size_t n){
        GEOSGeom geom = (GEOSGeom) self;
        const GEOSGeom result = (const GEOSGeom) GEOSGetGeometryN(geom, n);

        if (result == NULL)
            throw std::runtime_error(message);

        return (const GeosGeometry*) result;
    }
SWIGINTERN void delete_GeosMultiPoint(GeosMultiPoint *self){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom_destroy(geom);
    }
SWIGINTERN void delete_GeosMultiLineString(GeosMultiLineString *self){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom_destroy(geom);
    }
SWIGINTERN void delete_GeosMultiLinearRing(GeosMultiLinearRing *self){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom_destroy(geom);
    }
SWIGINTERN void delete_GeosMultiPolygon(GeosMultiPolygon *self){
        GEOSGeom geom = (GEOSGeom) self;
        GEOSGeom_destroy(geom);
    }

GeosGeometry *createPoint(GeosCoordinateSequence *s)
{
    GEOSCoordSeq coords = (GEOSCoordSeq) s;
    GEOSGeom geom = GEOSGeom_createPoint(GEOSCoordSeq_clone(coords)); // TODO:

    if(geom == NULL)
        throw std::runtime_error(message);

    return (GeosGeometry*) geom;
}

GeosGeometry *createLineString(GeosCoordinateSequence *s)
{
    GEOSCoordSeq coords = (GEOSCoordSeq) s;
    GEOSGeom geom = GEOSGeom_createLineString(GEOSCoordSeq_clone(coords)); // TODO:

    if(geom == NULL)
        throw std::runtime_error(message);

    return (GeosGeometry*) geom;
}

GeosGeometry *createLinearRing(GeosCoordinateSequence *s)
{
    GEOSCoordSeq coords = (GEOSCoordSeq) s;
    GEOSGeom geom = GEOSGeom_createLinearRing(GEOSCoordSeq_clone(coords)); // TODO:

    if(geom == NULL)
        throw std::runtime_error(message);

    return (GeosGeometry*) geom;
}

GeosGeometry *createPolygon(GeosLinearRing *shell, GeosLinearRing **holes, size_t nholes)
{
    GEOSGeom shellGeom = (GEOSGeom) shell;
    GEOSGeom* holeGeoms = new GEOSGeom[nholes];
    if(holeGeoms == NULL)
        throw std::runtime_error("TODO:");

    for (size_t i = 0; i < nholes; i++) {
        holeGeoms[i] = GEOSGeom_clone((GEOSGeom)holes[i]);
    }
    GEOSGeom geom = GEOSGeom_createPolygon(GEOSGeom_clone(shellGeom), holeGeoms, nholes); // TODO:

    if(holeGeoms)
        delete holeGeoms;

    if(geom == NULL)
        throw std::runtime_error(message);

    return (GeosGeometry*) geom;
}


SWIGINTERN GeosWktReader *new_GeosWktReader(){
        return GEOSWKTReader_create();
    }
SWIGINTERN void delete_GeosWktReader(GeosWktReader *self){
        GEOSWKTReader *reader = (GEOSWKTReader*) self;
        GEOSWKTReader_destroy(reader);
    }
SWIGINTERN GeosGeometry *GeosWktReader_read(GeosWktReader *self,char const *wkt){
        if(wkt == NULL)
            throw std::runtime_error("Trying to create geometry from a NULL string");
            
        GEOSWKTReader *reader = (GEOSWKTReader*) self;
        GEOSGeometry *geom = GEOSWKTReader_read(reader, wkt);

        if(geom == NULL)
            throw std::runtime_error(message);

        return (GeosGeometry*) geom;
    }
SWIGINTERN GeosWktWriter *new_GeosWktWriter(){
        return GEOSWKTWriter_create();
    }
SWIGINTERN void delete_GeosWktWriter(GeosWktWriter *self){
        GEOSWKTWriter *writer = (GEOSWKTWriter*) self;
        GEOSWKTWriter_destroy(writer);
    }
SWIGINTERN char *GeosWktWriter_write(GeosWktWriter *self,GeosGeometry const *g){
        GEOSWKTWriter *writer = (GEOSWKTWriter*) self;
        GEOSGeom geom = (GEOSGeom) g;
        return GEOSWKTWriter_write(writer, geom);
    }
SWIGINTERN GeosWkbReader *new_GeosWkbReader(){
        return GEOSWKBReader_create();
    }
SWIGINTERN void delete_GeosWkbReader(GeosWkbReader *self){
        GEOSWKBReader *reader = (GEOSWKBReader*) self;
        GEOSWKBReader_destroy(reader);
    }
SWIGINTERN GeosGeometry *GeosWkbReader_read(GeosWkbReader *self,unsigned char const *wkb,size_t size){
        if(wkb == NULL)
          throw std::runtime_error("Trying to create geometry from a NULL string");
         
        GEOSWKBReader *reader = (GEOSWKBReader*) self;
        GEOSGeometry *geom = GEOSWKBReader_read(reader, wkb, size);
       
        if(geom == NULL)
          throw std::runtime_error(message);

        return (GeosGeometry*) geom;
    }
SWIGINTERN GeosGeometry *GeosWkbReader_readHEX(GeosWkbReader *self,unsigned char const *wkb,size_t size){
        if(wkb == NULL)
          throw std::runtime_error("Trying to create geometry from a NULL string");
         
        GEOSWKBReader *reader = (GEOSWKBReader*) self;
        GEOSGeometry *geom = GEOSWKBReader_readHEX(reader, wkb, size);
       
        if(geom == NULL)
          throw std::runtime_error(message);

        return (GeosGeometry*) geom;
    }
SWIGINTERN GeosWkbWriter *new_GeosWkbWriter(){
        return GEOSWKBWriter_create();
    }
SWIGINTERN void delete_GeosWkbWriter(GeosWkbWriter *self){
        GEOSWKBWriter *writer = (GEOSWKBWriter*) self;
        GEOSWKBWriter_destroy(writer);
    }
SWIGINTERN int GeosWkbWriter_getOutputDimension(GeosWkbWriter *self){
        GEOSWKBWriter *writer = (GEOSWKBWriter*) self;
        return GEOSWKBWriter_getOutputDimension(writer);
    }
SWIGINTERN void GeosWkbWriter_setOutputDimension(GeosWkbWriter *self,int newDimension){
        GEOSWKBWriter *writer = (GEOSWKBWriter*) self;
        GEOSWKBWriter_setOutputDimension(writer, newDimension);
    }
SWIGINTERN int GeosWkbWriter_getByteOrder(GeosWkbWriter *self){
        GEOSWKBWriter *writer = (GEOSWKBWriter*) self;
        return GEOSWKBWriter_getByteOrder(writer);
    }
SWIGINTERN void GeosWkbWriter_setByteOrder(GeosWkbWriter *self,int newByteOrder){
        GEOSWKBWriter *writer = (GEOSWKBWriter*) self;
        return GEOSWKBWriter_setByteOrder(writer, newByteOrder);
    }
SWIGINTERN bool GeosWkbWriter_getIncludeSRID(GeosWkbWriter *self){
        GEOSWKBWriter *writer = (GEOSWKBWriter*) self;
        return GEOSWKBWriter_getIncludeSRID(writer);
    }
SWIGINTERN void GeosWkbWriter_setIncludeSRID(GeosWkbWriter *self,bool newIncludeSRID){
        GEOSWKBWriter *writer = (GEOSWKBWriter*) self;
        return GEOSWKBWriter_setIncludeSRID(writer, newIncludeSRID);
    }
SWIGINTERN unsigned char *GeosWkbWriter_write(GeosWkbWriter *self,GeosGeometry const *g,size_t *size){
        GEOSWKBWriter *writer = (GEOSWKBWriter*) self;
        GEOSGeom geom = (GEOSGeom) g;
        return GEOSWKBWriter_write(writer, geom, size);
    }
SWIGINTERN unsigned char *GeosWkbWriter_writeHEX(GeosWkbWriter *self,GeosGeometry const *g,size_t *size){
        GEOSWKBWriter *writer = (GEOSWKBWriter*) self;
        GEOSGeom geom = (GEOSGeom) g;
        return GEOSWKBWriter_writeHEX(writer, geom, size);
    }
void * SWIGSTDCALL SWIG_wrapCoordinateSequence(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapGeometry(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapPoint(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapLineString(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapLinearRing(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapPolygon(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapGeometryCollection(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapMultiPoint(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapMultiLineString(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapMultiLinearRing(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapMultiPolygon(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapWktReader(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapWktWriter(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapWkbReader(void *arg, int cMemOwn);
void * SWIGSTDCALL SWIG_wrapWkbWriter(void *arg, int cMemOwn);
//GUID IID_ISWIGTYPE_p_unsigned_char = { 0x0211390a, 0x7a8f, 0x5e7d, { 0xac, 0xaa, 0x11, 0x06, 0xf0, 0xf1, 0x08, 0x4e}};
//
//void * SWIGSTDCALL SWIG_wrapSWIGTYPE_p_unsigned_char(void *ptr, int cMemOwn) {
//  return SWIG_wrap_opaque(ptr, cMemOwn, &IID_ISWIGTYPE_p_unsigned_char);
//};
//
//GUID IID_ISWIGTYPE_p_p_GeosLinearRing = { 0xbbf7519b, 0x84a5, 0x536c, { 0xa9, 0x39, 0x9d, 0x7b, 0x75, 0xce, 0x6e, 0x9f}};
//
//void * SWIGSTDCALL SWIG_wrapSWIGTYPE_p_p_GeosLinearRing(void *ptr, int cMemOwn) {
//  return SWIG_wrap_opaque(ptr, cMemOwn, &IID_ISWIGTYPE_p_p_GeosLinearRing);
//};

extern GUID IID_Igeos;
extern GUID IID_ICoordinateSequenceStatic;
extern GUID IID_ICoordinateSequence;
extern GUID IID_IGeometry;
extern GUID IID_IPoint;
extern GUID IID_ILineString;
extern GUID IID_ILinearRing;
extern GUID IID_IPolygon;
extern GUID IID_IGeometryCollection;
extern GUID IID_IMultiPoint;
extern GUID IID_IMultiLineString;
extern GUID IID_IMultiLinearRing;
extern GUID IID_IMultiPolygon;
extern GUID IID_IWktReaderStatic;
extern GUID IID_IWktReader;
extern GUID IID_IWktWriterStatic;
extern GUID IID_IWktWriter;
extern GUID IID_IWkbReaderStatic;
extern GUID IID_IWkbReader;
extern GUID IID_IWkbWriterStatic;
extern GUID IID_IWkbWriter;

HRESULT SWIGSTDCALL _wrap_GEOS_VERSION_MAJOR_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int) 3;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_VERSION_MINOR_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int) 0;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_VERSION_PATCH_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int) 1;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_VERSION_get(void *SWIG_ignored, WCHAR **SWIG_result_ptr) {
  WCHAR * jresult ;
  HRESULT hres ;
  char *result = 0 ;
  
  result = (char *) "3.0.1";
  
  if (result) {
    int SWIG_len = MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, 0, 0);
    WCHAR *SWIG_res = (WCHAR *) CoTaskMemAlloc((SWIG_len + 2) * sizeof(WCHAR));
    /* First 4 bytes contain length in bytes */
    *((unsigned int *) SWIG_res) = (unsigned int) (SWIG_len - 1) * sizeof(WCHAR);
    MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, SWIG_res + 2, SWIG_len);
    *SWIG_result_ptr = SWIG_res + 2;
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_JTS_PORT_get(void *SWIG_ignored, WCHAR **SWIG_result_ptr) {
  WCHAR * jresult ;
  HRESULT hres ;
  char *result = 0 ;
  
  result = (char *) "1.7.1";
  
  if (result) {
    int SWIG_len = MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, 0, 0);
    WCHAR *SWIG_res = (WCHAR *) CoTaskMemAlloc((SWIG_len + 2) * sizeof(WCHAR));
    /* First 4 bytes contain length in bytes */
    *((unsigned int *) SWIG_res) = (unsigned int) (SWIG_len - 1) * sizeof(WCHAR);
    MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, SWIG_res + 2, SWIG_len);
    *SWIG_result_ptr = SWIG_res + 2;
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_CAPI_VERSION_MAJOR_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int) 1;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_CAPI_VERSION_MINOR_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int) 4;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_CAPI_VERSION_PATCH_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int) 1;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_CAPI_FIRST_INTERFACE_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int) 1;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_CAPI_LAST_INTERFACE_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int) (1+4);
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_CAPI_VERSION_get(void *SWIG_ignored, WCHAR **SWIG_result_ptr) {
  WCHAR * jresult ;
  HRESULT hres ;
  char *result = 0 ;
  
  result = (char *) "3.0.1-CAPI-1.4.1";
  
  if (result) {
    int SWIG_len = MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, 0, 0);
    WCHAR *SWIG_res = (WCHAR *) CoTaskMemAlloc((SWIG_len + 2) * sizeof(WCHAR));
    /* First 4 bytes contain length in bytes */
    *((unsigned int *) SWIG_res) = (unsigned int) (SWIG_len - 1) * sizeof(WCHAR);
    MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, SWIG_res + 2, SWIG_len);
    *SWIG_result_ptr = SWIG_res + 2;
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_POINT_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int)GEOS_POINT;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_LINESTRING_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int)GEOS_LINESTRING;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_LINEARRING_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int)GEOS_LINEARRING;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_POLYGON_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int)GEOS_POLYGON;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_MULTIPOINT_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int)GEOS_MULTIPOINT;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_MULTILINESTRING_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int)GEOS_MULTILINESTRING;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_MULTIPOLYGON_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int)GEOS_MULTIPOLYGON;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_GEOMETRYCOLLECTION_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int)GEOS_GEOMETRYCOLLECTION;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_WKB_XDR_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int)GEOS_WKB_XDR;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GEOS_WKB_NDR_get(void *SWIG_ignored, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  int result;
  
  result = (int)GEOS_WKB_NDR;
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_version(void *SWIG_ignored, WCHAR **SWIG_result_ptr) {
  WCHAR * jresult ;
  HRESULT hres ;
  char *result = 0 ;
  
  result = (char *)GEOSversion();
  
  if (result) {
    int SWIG_len = MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, 0, 0);
    WCHAR *SWIG_res = (WCHAR *) CoTaskMemAlloc((SWIG_len + 2) * sizeof(WCHAR));
    /* First 4 bytes contain length in bytes */
    *((unsigned int *) SWIG_res) = (unsigned int) (SWIG_len - 1) * sizeof(WCHAR);
    MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, SWIG_res + 2, SWIG_len);
    *SWIG_result_ptr = SWIG_res + 2;
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_new_CoordinateSequence(void *SWIG_ignored, unsigned long jarg1, unsigned long jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  size_t arg1 ;
  size_t arg2 ;
  GeosCoordinateSequence *result = 0 ;
  
  arg1 = (size_t)jarg1; 
  arg2 = (size_t)jarg2; 
  {
    try
    {
      result = (GeosCoordinateSequence *)new_GeosCoordinateSequence(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequenceStatic", &IID_ICoordinateSequenceStatic);
        return E_ABORT; 
      };
    }
  }
  
  if (result) {
    *SWIG_result_ptr = (SWIGIUnknown *) SWIG_wrapCoordinateSequence(*(void **) &result, 1);
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_CoordinateSequence(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosCoordinateSequence(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequenceStatic", &IID_ICoordinateSequenceStatic);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_CoordinateSequence_clone(SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  GeosCoordinateSequence *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosCoordinateSequence *)GeosCoordinateSequence_clone(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequence", &IID_ICoordinateSequence);
        return E_ABORT; 
      };
    }
  }
  
  if (result) {
    *SWIG_result_ptr = (SWIGIUnknown *) SWIG_wrapCoordinateSequence(*(void **) &result, 1);
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_CoordinateSequence_setX(SWIGIUnknown * jarg1, unsigned long jarg2, double jarg3, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  size_t arg2 ;
  double arg3 ;
  int result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (size_t)jarg2; 
  arg3 = (double)jarg3; 
  {
    try
    {
      result = (int)GeosCoordinateSequence_setX(arg1,arg2,arg3);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequence", &IID_ICoordinateSequence);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_CoordinateSequence_setY(SWIGIUnknown * jarg1, unsigned long jarg2, double jarg3, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  size_t arg2 ;
  double arg3 ;
  int result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (size_t)jarg2; 
  arg3 = (double)jarg3; 
  {
    try
    {
      result = (int)GeosCoordinateSequence_setY(arg1,arg2,arg3);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequence", &IID_ICoordinateSequence);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_CoordinateSequence_setZ(SWIGIUnknown * jarg1, unsigned long jarg2, double jarg3, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  size_t arg2 ;
  double arg3 ;
  int result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (size_t)jarg2; 
  arg3 = (double)jarg3; 
  {
    try
    {
      result = (int)GeosCoordinateSequence_setZ(arg1,arg2,arg3);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequence", &IID_ICoordinateSequence);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_CoordinateSequence_setOrdinate(SWIGIUnknown * jarg1, unsigned long jarg2, unsigned long jarg3, double jarg4, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  size_t arg2 ;
  size_t arg3 ;
  double arg4 ;
  int result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (size_t)jarg2; 
  arg3 = (size_t)jarg3; 
  arg4 = (double)jarg4; 
  {
    try
    {
      result = (int)GeosCoordinateSequence_setOrdinate(arg1,arg2,arg3,arg4);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequence", &IID_ICoordinateSequence);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_CoordinateSequence_getX(SWIGIUnknown * jarg1, unsigned long jarg2, double*SWIG_result_ptr) {
  double jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  size_t arg2 ;
  double result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (size_t)jarg2; 
  {
    try
    {
      result = (double)GeosCoordinateSequence_getX(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequence", &IID_ICoordinateSequence);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_CoordinateSequence_getY(SWIGIUnknown * jarg1, unsigned long jarg2, double*SWIG_result_ptr) {
  double jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  size_t arg2 ;
  double result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (size_t)jarg2; 
  {
    try
    {
      result = (double)GeosCoordinateSequence_getY(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequence", &IID_ICoordinateSequence);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_CoordinateSequence_getZ(SWIGIUnknown * jarg1, unsigned long jarg2, double*SWIG_result_ptr) {
  double jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  size_t arg2 ;
  double result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (size_t)jarg2; 
  {
    try
    {
      result = (double)GeosCoordinateSequence_getZ(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequence", &IID_ICoordinateSequence);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_CoordinateSequence_getOrdinate(SWIGIUnknown * jarg1, unsigned long jarg2, unsigned long jarg3, double*SWIG_result_ptr) {
  double jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  size_t arg2 ;
  size_t arg3 ;
  double result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (size_t)jarg2; 
  arg3 = (size_t)jarg3; 
  {
    try
    {
      result = (double)GeosCoordinateSequence_getOrdinate(arg1,arg2,arg3);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequence", &IID_ICoordinateSequence);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_CoordinateSequence_getSize(SWIGIUnknown * jarg1, unsigned int*SWIG_result_ptr) {
  unsigned int jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  unsigned int result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (unsigned int)GeosCoordinateSequence_getSize(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequence", &IID_ICoordinateSequence);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_CoordinateSequence_getDimensions(SWIGIUnknown * jarg1, unsigned int*SWIG_result_ptr) {
  unsigned int jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  unsigned int result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (unsigned int)GeosCoordinateSequence_getDimensions(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "CoordinateSequence", &IID_ICoordinateSequence);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


extern GUID IID_ICoordinateSequenceStatic;

extern SWIG_funcptr _wrapCoordinateSequenceStatic_vtable[];

HRESULT SWIGSTDCALL _wrap_CoordinateSequenceStatic(void *SWIG_ignored, SWIGIUnknown **SWIG_result) {
  *SWIG_result = (SWIGIUnknown *) _wrap_new_staticclass(_wrapCoordinateSequenceStatic_vtable, &IID_ICoordinateSequenceStatic);

  return S_OK;
}

HRESULT SWIGSTDCALL _wrap_delete_Geometry(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosGeometry(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_clone(SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_clone(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_geomType(SWIGIUnknown * jarg1, WCHAR **SWIG_result_ptr) {
  WCHAR * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  char *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (char *)GeosGeometry_geomType(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  
  if (result) {
    int SWIG_len = MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, 0, 0);
    WCHAR *SWIG_res = (WCHAR *) CoTaskMemAlloc((SWIG_len + 2) * sizeof(WCHAR));
    /* First 4 bytes contain length in bytes */
    *((unsigned int *) SWIG_res) = (unsigned int) (SWIG_len - 1) * sizeof(WCHAR);
    MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, SWIG_res + 2, SWIG_len);
    *SWIG_result_ptr = SWIG_res + 2;
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_typeId(SWIGIUnknown * jarg1, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  int result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (int)GeosGeometry_typeId(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_normalize(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      GeosGeometry_normalize(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_getSRID(SWIGIUnknown * jarg1, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  int result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (int)GeosGeometry_getSRID(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_setSRID(SWIGIUnknown * jarg1, int jarg2) {
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  int arg2 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (int)jarg2; 
  {
    try
    {
      GeosGeometry_setSRID(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_getDimensions(SWIGIUnknown * jarg1, unsigned long*SWIG_result_ptr) {
  unsigned long jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  size_t result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = GeosGeometry_getDimensions(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_getNumGeometries(SWIGIUnknown * jarg1, unsigned long*SWIG_result_ptr) {
  unsigned long jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  size_t result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = GeosGeometry_getNumGeometries(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_intersection(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_intersection(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_buffer(SWIGIUnknown * jarg1, double jarg2, int jarg3, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  double arg2 ;
  int arg3 ;
  GeosGeometry *result = 0 ;
  
  {
    arg3 = DEFAULT_QUADRANT_SEGMENTS;
  }
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (double)jarg2; 
  arg3 = (int)jarg3; 
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_buffer(arg1,arg2,arg3);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_convexHull(SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_convexHull(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_difference(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_difference(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_symDifference(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_symDifference(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_boundary(SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_boundary(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_Union(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_geomUnion(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_pointOnSurface(SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_pointOnSurface(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_getCentroid(SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_getCentroid(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_getEnvelope(SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_getEnvelope(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 0);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 0);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 0);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 0);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 0);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 0);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 0);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 0);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_relate(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, WCHAR **SWIG_result_ptr) {
  WCHAR * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  char *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (char *)GeosGeometry_relate(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  
  if (result) {
    int SWIG_len = MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, 0, 0);
    WCHAR *SWIG_res = (WCHAR *) CoTaskMemAlloc((SWIG_len + 2) * sizeof(WCHAR));
    /* First 4 bytes contain length in bytes */
    *((unsigned int *) SWIG_res) = (unsigned int) (SWIG_len - 1) * sizeof(WCHAR);
    MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, SWIG_res + 2, SWIG_len);
    *SWIG_result_ptr = SWIG_res + 2;
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_lineMerge(SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_lineMerge(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_simplify(SWIGIUnknown * jarg1, double jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  double arg2 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (double)jarg2; 
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_simplify(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_topologyPreserveSimplify(SWIGIUnknown * jarg1, double jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  double arg2 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (double)jarg2; 
  {
    try
    {
      result = (GeosGeometry *)GeosGeometry_topologyPreserveSimplify(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_relatePattern(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, WCHAR * jarg3, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  char *arg3 = (char *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    if (jarg3) {
      int SWIG_len = WideCharToMultiByte(CP_ACP, 0, jarg3, -1, 0, 0, 0, 0);
      arg3 = (char *) malloc(SWIG_len);
      WideCharToMultiByte(CP_ACP, 0, jarg3, -1, (char *) arg3, SWIG_len, 0, 0);
    }
  }
  {
    try
    {
      result = (bool)GeosGeometry_relatePattern(arg1,(GeosGeometry const *)arg2,(char const *)arg3);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  {
    if (jarg3) {
      free(arg3);
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_disjoint(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_disjoint(arg1,(GeosGeometry const *)arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_touches(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_touches(arg1,(GeosGeometry const *)arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_intersects(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_intersects(arg1,(GeosGeometry const *)arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_crosses(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_crosses(arg1,(GeosGeometry const *)arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_within(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_within(arg1,(GeosGeometry const *)arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_contains(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_contains(arg1,(GeosGeometry const *)arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_overlaps(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_overlaps(arg1,(GeosGeometry const *)arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_equals(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_equals(arg1,(GeosGeometry const *)arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_equalsExact(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, double jarg3, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  double arg3 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg3 = (double)jarg3; 
  {
    try
    {
      result = (bool)GeosGeometry_equalsExact(arg1,(GeosGeometry const *)arg2,arg3);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_isEmpty(SWIGIUnknown * jarg1, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_isEmpty(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_isValid(SWIGIUnknown * jarg1, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_isValid(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_isSimple(SWIGIUnknown * jarg1, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_isSimple(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_isRing(SWIGIUnknown * jarg1, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_isRing(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_hasZ(SWIGIUnknown * jarg1, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosGeometry_hasZ(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_area(SWIGIUnknown * jarg1, double*SWIG_result_ptr) {
  double jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  double result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (double)GeosGeometry_area(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_length(SWIGIUnknown * jarg1, double*SWIG_result_ptr) {
  double jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  double result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (double)GeosGeometry_length(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Geometry_distance(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, double*SWIG_result_ptr) {
  double jresult ;
  HRESULT hres ;
  GeosGeometry *arg1 = (GeosGeometry *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  double result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (double)GeosGeometry_distance(arg1,(GeosGeometry const *)arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Geometry", &IID_IGeometry);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_Point(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosPoint *arg1 = (GeosPoint *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosPoint **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosPoint(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Point", &IID_IPoint);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Point_getCoordSeq(SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosPoint *arg1 = (GeosPoint *) 0 ;
  GeosCoordinateSequence *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosPoint **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosCoordinateSequence *)GeosPoint_getCoordSeq(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Point", &IID_IPoint);
        return E_ABORT; 
      };
    }
  }
  
  if (result) {
    *SWIG_result_ptr = (SWIGIUnknown *) SWIG_wrapCoordinateSequence(*(void **) &result, 0);
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_LineString(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosLineString *arg1 = (GeosLineString *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosLineString **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosLineString(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "LineString", &IID_ILineString);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_LineString_getCoordSeq(SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosLineString *arg1 = (GeosLineString *) 0 ;
  GeosCoordinateSequence *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosLineString **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosCoordinateSequence *)GeosLineString_getCoordSeq(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "LineString", &IID_ILineString);
        return E_ABORT; 
      };
    }
  }
  
  if (result) {
    *SWIG_result_ptr = (SWIGIUnknown *) SWIG_wrapCoordinateSequence(*(void **) &result, 0);
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_LinearRing(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosLinearRing *arg1 = (GeosLinearRing *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosLinearRing **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosLinearRing(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "LinearRing", &IID_ILinearRing);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_LinearRing_getCoordSeq(SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosLinearRing *arg1 = (GeosLinearRing *) 0 ;
  GeosCoordinateSequence *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosLinearRing **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosCoordinateSequence *)GeosLinearRing_getCoordSeq(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "LinearRing", &IID_ILinearRing);
        return E_ABORT; 
      };
    }
  }
  
  if (result) {
    *SWIG_result_ptr = (SWIGIUnknown *) SWIG_wrapCoordinateSequence(*(void **) &result, 0);
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_Polygon(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosPolygon *arg1 = (GeosPolygon *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosPolygon **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosPolygon(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Polygon", &IID_IPolygon);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Polygon_getExteriorRing(SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosPolygon *arg1 = (GeosPolygon *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosPolygon **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)GeosPolygon_getExteriorRing(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Polygon", &IID_IPolygon);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 0);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 0);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 0);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 0);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 0);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 0);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 0);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 0);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Polygon_getNumInteriorRings(SWIGIUnknown * jarg1, unsigned long*SWIG_result_ptr) {
  unsigned long jresult ;
  HRESULT hres ;
  GeosPolygon *arg1 = (GeosPolygon *) 0 ;
  size_t result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosPolygon **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = GeosPolygon_getNumInteriorRings(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Polygon", &IID_IPolygon);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_Polygon_getInteriorRingN(SWIGIUnknown * jarg1, unsigned long jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosPolygon *arg1 = (GeosPolygon *) 0 ;
  size_t arg2 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosPolygon **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (size_t)jarg2; 
  {
    try
    {
      result = (GeosGeometry *)GeosPolygon_getInteriorRingN(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "Polygon", &IID_IPolygon);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 0);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 0);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 0);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 0);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 0);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 0);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 0);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 0);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_GeometryCollection(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosGeometryCollection *arg1 = (GeosGeometryCollection *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometryCollection **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosGeometryCollection(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "GeometryCollection", &IID_IGeometryCollection);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_GeometryCollection_getGeometryN(SWIGIUnknown * jarg1, unsigned long jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosGeometryCollection *arg1 = (GeosGeometryCollection *) 0 ;
  size_t arg2 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosGeometryCollection **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (size_t)jarg2; 
  {
    try
    {
      result = (GeosGeometry *)GeosGeometryCollection_getGeometryN(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "GeometryCollection", &IID_IGeometryCollection);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 0);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 0);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 0);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 0);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 0);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 0);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 0);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 0);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_MultiPoint(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosMultiPoint *arg1 = (GeosMultiPoint *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosMultiPoint **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosMultiPoint(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "MultiPoint", &IID_IMultiPoint);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_MultiLineString(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosMultiLineString *arg1 = (GeosMultiLineString *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosMultiLineString **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosMultiLineString(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "MultiLineString", &IID_IMultiLineString);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_MultiLinearRing(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosMultiLinearRing *arg1 = (GeosMultiLinearRing *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosMultiLinearRing **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosMultiLinearRing(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "MultiLinearRing", &IID_IMultiLinearRing);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_MultiPolygon(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosMultiPolygon *arg1 = (GeosMultiPolygon *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosMultiPolygon **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosMultiPolygon(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "MultiPolygon", &IID_IMultiPolygon);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_createPoint(void *SWIG_ignored, SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)createPoint(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "geos", &IID_Igeos);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_createLineString(void *SWIG_ignored, SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)createLineString(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "geos", &IID_Igeos);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_createLinearRing(void *SWIG_ignored, SWIGIUnknown * jarg1, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosCoordinateSequence *arg1 = (GeosCoordinateSequence *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosCoordinateSequence **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (GeosGeometry *)createLinearRing(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "geos", &IID_Igeos);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


//HRESULT SWIGSTDCALL _wrap_createPolygon(void *SWIG_ignored, SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, unsigned long jarg3, SWIGIUnknown **SWIG_result_ptr) {
HRESULT SWIGSTDCALL _wrap_createPolygon(void *SWIG_ignored, SWIGIUnknown * jarg1, VARIANT jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosLinearRing *arg1 = (GeosLinearRing *) 0 ;
  GeosLinearRing **arg2 = (GeosLinearRing **) 0 ;
  GeosGeometry *result = 0 ;
  
  {
    arg2 = NULL;
  }
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosLinearRing **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  VARIANT* pvars = NULL;
  ULONG nSize = 0;
  SAFEARRAY* psa = NULL;
  if ((jarg2.vt & VT_ARRAY) && (jarg2.vt & VT_VARIANT)) {
    psa = jarg2.parray;
	::SafeArrayAccessData(psa, (void**)&pvars);
	nSize = psa->rgsabound->cElements;

	arg2 = (GeosLinearRing**)malloc(sizeof(void*) * nSize);
	for (int i = 0; i < nSize; i++) {
      if (pvars[i].vt == VT_DISPATCH) {
        SWIGIUnknown *wrapper;
   
        /* Call to QueryInterface */
        HRESULT hr = pvars[i].pdispVal->QueryInterface(IID_ISWIGWrappedObject, (void **) &wrapper);
        if (hr != S_OK) {
          /* Argument was not wrapped by SWIG - directors will be needed */
        } else {
          /* GetCPtr */
          void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
          arg2[i] = *(GeosLinearRing **) &c_ptr;
        
          /* Release */
          ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
        }
      }
	}
  }
  
  try
  {
    result = (GeosGeometry *)createPolygon(arg1,arg2,nSize);
    if (psa) {
      ::SafeArrayUnaccessData(psa);
    }
    if (arg2) {
      free(arg2);
    }
  }
  catch (const std::exception& e)
  {
    {
      if (psa) {
        ::SafeArrayUnaccessData(psa);
      }
      if (arg2) {
        free(arg2);
      }
      SWIG_SetErrorInfo(e.what(), "geos", &IID_Igeos);
      return E_ABORT; 
    };
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_new_WktReader(void *SWIG_ignored, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosWktReader *result = 0 ;
  
  {
    try
    {
      result = (GeosWktReader *)new_GeosWktReader();
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WktReaderStatic", &IID_IWktReaderStatic);
        return E_ABORT; 
      };
    }
  }
  
  if (result) {
    *SWIG_result_ptr = (SWIGIUnknown *) SWIG_wrapWktReader(*(void **) &result, 1);
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_WktReader(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosWktReader *arg1 = (GeosWktReader *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWktReader **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosWktReader(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WktReader", &IID_IWktReader);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_WktReader_read(SWIGIUnknown * jarg1, WCHAR * jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosWktReader *arg1 = (GeosWktReader *) 0 ;
  char *arg2 = (char *) 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWktReader **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    if (jarg2) {
      int SWIG_len = WideCharToMultiByte(CP_ACP, 0, jarg2, -1, 0, 0, 0, 0);
      arg2 = (char *) malloc(SWIG_len);
      WideCharToMultiByte(CP_ACP, 0, jarg2, -1, (char *) arg2, SWIG_len, 0, 0);
    }
  }
  {
    try
    {
      result = (GeosGeometry *)GeosWktReader_read(arg1,(char const *)arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WktReader", &IID_IWktReader);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  {
    if (jarg2) {
      free(arg2);
    }
  }
  return S_OK;
}


extern GUID IID_IWktReaderStatic;

extern SWIG_funcptr _wrapWktReaderStatic_vtable[];

HRESULT SWIGSTDCALL _wrap_WktReaderStatic(void *SWIG_ignored, SWIGIUnknown **SWIG_result) {
  *SWIG_result = (SWIGIUnknown *) _wrap_new_staticclass(_wrapWktReaderStatic_vtable, &IID_IWktReaderStatic);

  return S_OK;
}

HRESULT SWIGSTDCALL _wrap_new_WktWriter(void *SWIG_ignored, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosWktWriter *result = 0 ;
  
  {
    try
    {
      result = (GeosWktWriter *)new_GeosWktWriter();
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WktWriterStatic", &IID_IWktWriterStatic);
        return E_ABORT; 
      };
    }
  }
  
  if (result) {
    *SWIG_result_ptr = (SWIGIUnknown *) SWIG_wrapWktWriter(*(void **) &result, 1);
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_WktWriter(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosWktWriter *arg1 = (GeosWktWriter *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWktWriter **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosWktWriter(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WktWriter", &IID_IWktWriter);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_WktWriter_write(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, WCHAR **SWIG_result_ptr) {
  WCHAR * jresult ;
  HRESULT hres ;
  GeosWktWriter *arg1 = (GeosWktWriter *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  char *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWktWriter **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (char *)GeosWktWriter_write(arg1,(GeosGeometry const *)arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WktWriter", &IID_IWktWriter);
        return E_ABORT; 
      };
    }
  }
  
  if (result) {
    int SWIG_len = MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, 0, 0);
    WCHAR *SWIG_res = (WCHAR *) CoTaskMemAlloc((SWIG_len + 2) * sizeof(WCHAR));
    /* First 4 bytes contain length in bytes */
    *((unsigned int *) SWIG_res) = (unsigned int) (SWIG_len - 1) * sizeof(WCHAR);
    MultiByteToWideChar(CP_ACP, 0, (char *) result, -1, SWIG_res + 2, SWIG_len);
    *SWIG_result_ptr = SWIG_res + 2;
  }
  
  return S_OK;
}


extern GUID IID_IWktWriterStatic;

extern SWIG_funcptr _wrapWktWriterStatic_vtable[];

HRESULT SWIGSTDCALL _wrap_WktWriterStatic(void *SWIG_ignored, SWIGIUnknown **SWIG_result) {
  *SWIG_result = (SWIGIUnknown *) _wrap_new_staticclass(_wrapWktWriterStatic_vtable, &IID_IWktWriterStatic);

  return S_OK;
}

HRESULT SWIGSTDCALL _wrap_new_WkbReader(void *SWIG_ignored, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosWkbReader *result = 0 ;
  
  {
    try
    {
      result = (GeosWkbReader *)new_GeosWkbReader();
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbReaderStatic", &IID_IWkbReaderStatic);
        return E_ABORT; 
      };
    }
  }
  
  if (result) {
    *SWIG_result_ptr = (SWIGIUnknown *) SWIG_wrapWkbReader(*(void **) &result, 1);
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_WkbReader(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosWkbReader *arg1 = (GeosWkbReader *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWkbReader **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosWkbReader(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbReader", &IID_IWkbReader);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_WkbReader_read(SWIGIUnknown * jarg1, VARIANT jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosWkbReader *arg1 = (GeosWkbReader *) 0 ;
  unsigned char *arg2 = (unsigned char *) 0 ;
  size_t arg3 ;
  int alloc2 = 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWkbReader **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  VARIANT* pvars = NULL;
  ULONG nSize = 0;
  SAFEARRAY* psa = NULL;
  if ((jarg2.vt & VT_ARRAY) && (jarg2.vt & VT_VARIANT)) {
    psa = jarg2.parray;
	::SafeArrayAccessData(psa, (void**)&pvars);
	nSize = psa->rgsabound->cElements;

	arg2 = new unsigned char[nSize];
	for (int i = 0; i < nSize; i++) {
		switch (pvars[i].vt) {
			case VT_UI1:
				arg2[i] = (unsigned char)pvars[i].bVal;
				break;
			case VT_I2:
				arg2[i] = (unsigned char)pvars[i].iVal;
				break;
			case VT_I4:
				arg2[i] = (unsigned char)pvars[i].lVal;
				break;
			default:
				break;
		}
	}
	if (psa) {
		::SafeArrayUnaccessData(psa);
	}
  }

  {
    try
    {
      result = (GeosGeometry *)GeosWkbReader_read(arg1,(unsigned char const *)arg2,arg3);
	  if (arg2) {
		  delete arg2;
	  }
    }
    catch (const std::exception& e)
    {
      {
        if (arg2) {
          delete arg2;
		}
        SWIG_SetErrorInfo(e.what(), "WkbReader", &IID_IWkbReader);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_WkbReader_readHEX(SWIGIUnknown * jarg1, BSTR jarg2, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosWkbReader *arg1 = (GeosWkbReader *) 0 ;
  unsigned char *arg2 = (unsigned char *) 0 ;
  size_t arg3 ;
  int alloc2 = 0 ;
  GeosGeometry *result = 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWkbReader **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  _bstr_t barg2 = jarg2;
  arg2 = (unsigned char *)((char*)barg2);
  arg3 = strlen((const char*)barg2);
  {
    try
    {
      result = (GeosGeometry *)GeosWkbReader_readHEX(arg1,(unsigned char const *)arg2,arg3);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbReader", &IID_IWkbReader);
        return E_ABORT; 
      };
    }
  }
  {
    /* %typemap(out) GeosGeometry */
    
    if (result == NULL)
    {
      return E_ABORT; 
    };
    
    GeosGeometry *geom = result;
    GEOSGeomTypes geomId = (GEOSGeomTypes)GEOSGeomTypeId((GEOSGeom) geom);
    
    switch (geomId)
    {
    case GEOS_POINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPoint, 0 | 1);
      break;
    case GEOS_LINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLineString, 0 | 1);
      break;
    case GEOS_LINEARRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosLinearRing, 0 | 1);
      break;
    case GEOS_POLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosPolygon, 0 | 1);
      break;
    case GEOS_MULTIPOINT:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPoint, 0 | 1);
      break;
    case GEOS_MULTILINESTRING:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiLineString, 0 | 1);
      break;
    case GEOS_MULTIPOLYGON:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosMultiPolygon, 0 | 1);
      break;
    case GEOS_GEOMETRYCOLLECTION:
      *SWIG_result_ptr = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_GeosGeometryCollection, 0 | 1);
      break;
    }
  }
  return S_OK;
}


extern GUID IID_IWkbReaderStatic;

extern SWIG_funcptr _wrapWkbReaderStatic_vtable[];

HRESULT SWIGSTDCALL _wrap_WkbReaderStatic(void *SWIG_ignored, SWIGIUnknown **SWIG_result) {
  *SWIG_result = (SWIGIUnknown *) _wrap_new_staticclass(_wrapWkbReaderStatic_vtable, &IID_IWkbReaderStatic);

  return S_OK;
}

HRESULT SWIGSTDCALL _wrap_new_WkbWriter(void *SWIG_ignored, SWIGIUnknown **SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosWkbWriter *result = 0 ;
  
  {
    try
    {
      result = (GeosWkbWriter *)new_GeosWkbWriter();
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbWriterStatic", &IID_IWkbWriterStatic);
        return E_ABORT; 
      };
    }
  }
  
  if (result) {
    *SWIG_result_ptr = (SWIGIUnknown *) SWIG_wrapWkbWriter(*(void **) &result, 1);
  }
  
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_delete_WkbWriter(SWIGIUnknown * jarg1) {
  HRESULT hres ;
  GeosWkbWriter *arg1 = (GeosWkbWriter *) 0 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWkbWriter **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      delete_GeosWkbWriter(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbWriter", &IID_IWkbWriter);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_WkbWriter_getOutputDimension(SWIGIUnknown * jarg1, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  GeosWkbWriter *arg1 = (GeosWkbWriter *) 0 ;
  int result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWkbWriter **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (int)GeosWkbWriter_getOutputDimension(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbWriter", &IID_IWkbWriter);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_WkbWriter_setOutputDimension(SWIGIUnknown * jarg1, int jarg2) {
  HRESULT hres ;
  GeosWkbWriter *arg1 = (GeosWkbWriter *) 0 ;
  int arg2 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWkbWriter **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (int)jarg2; 
  {
    try
    {
      GeosWkbWriter_setOutputDimension(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbWriter", &IID_IWkbWriter);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_WkbWriter_getByteOrder(SWIGIUnknown * jarg1, int*SWIG_result_ptr) {
  int jresult ;
  HRESULT hres ;
  GeosWkbWriter *arg1 = (GeosWkbWriter *) 0 ;
  int result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWkbWriter **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (int)GeosWkbWriter_getByteOrder(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbWriter", &IID_IWkbWriter);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_WkbWriter_setByteOrder(SWIGIUnknown * jarg1, int jarg2) {
  HRESULT hres ;
  GeosWkbWriter *arg1 = (GeosWkbWriter *) 0 ;
  int arg2 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWkbWriter **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = (int)jarg2; 
  {
    try
    {
      GeosWkbWriter_setByteOrder(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbWriter", &IID_IWkbWriter);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_WkbWriter_getIncludeSRID(SWIGIUnknown * jarg1, VARIANT_BOOL*SWIG_result_ptr) {
  VARIANT_BOOL jresult ;
  HRESULT hres ;
  GeosWkbWriter *arg1 = (GeosWkbWriter *) 0 ;
  bool result;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWkbWriter **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (bool)GeosWkbWriter_getIncludeSRID(arg1);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbWriter", &IID_IWkbWriter);
        return E_ABORT; 
      };
    }
  }
  *SWIG_result_ptr = result ? VARIANT_TRUE : VARIANT_FALSE; 
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_WkbWriter_setIncludeSRID(SWIGIUnknown * jarg1, VARIANT_BOOL jarg2) {
  HRESULT hres ;
  GeosWkbWriter *arg1 = (GeosWkbWriter *) 0 ;
  bool arg2 ;
  
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWkbWriter **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  arg2 = jarg2 ? true : false; 
  {
    try
    {
      GeosWkbWriter_setIncludeSRID(arg1,arg2);
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbWriter", &IID_IWkbWriter);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_WkbWriter_write(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, VARIANT *SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosWkbWriter *arg1 = (GeosWkbWriter *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  size_t *arg3 = (size_t *) 0 ;
  size_t temp3 = 0 ;
  unsigned char *result = 0 ;
  
  {
    /* %typemap(in, numinputs=0) size_t *size (size_t temp3 = 0) */
    arg3 = &temp3;
  }
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWkbWriter **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (unsigned char *)GeosWkbWriter_write(arg1,(GeosGeometry const *)arg2,arg3);
	  VARIANT vitem;
	  ::VariantInit(&vitem);
	  vitem.vt = VT_UI1;
	  ::VariantInit(SWIG_result_ptr);
	  SWIG_result_ptr->vt = VT_ARRAY | VT_VARIANT;
	  SAFEARRAY *psa;
	  SAFEARRAYBOUND bounds = {*arg3, 0};
	  psa = ::SafeArrayCreate(VT_VARIANT, 1, &bounds);
	  VARIANT *pvdata;
	  ::SafeArrayAccessData(psa, (void**)&pvdata);
	  for (int i = 0; i < *arg3; i++) {
	    vitem.bVal = result[i];
		pvdata[i] = vitem;
	  }
	  ::SafeArrayUnaccessData(psa);
	  SWIG_result_ptr->parray = psa;
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbWriter", &IID_IWkbWriter);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


HRESULT SWIGSTDCALL _wrap_WkbWriter_writeHEX(SWIGIUnknown * jarg1, SWIGIUnknown * jarg2, BSTR *SWIG_result_ptr) {
  SWIGIUnknown * jresult ;
  HRESULT hres ;
  GeosWkbWriter *arg1 = (GeosWkbWriter *) 0 ;
  GeosGeometry *arg2 = (GeosGeometry *) 0 ;
  size_t *arg3 = (size_t *) 0 ;
  size_t temp3 = 0 ;
  unsigned char *result = 0 ;
  
  {
    /* %typemap(in, numinputs=0) size_t *size (size_t temp3 = 0) */
    arg3 = &temp3;
  }
  
  if (jarg1) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg1->vtable[0])(jarg1, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg1 = *(GeosWkbWriter **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  
  if (jarg2) {
    SWIGIUnknown *wrapper;
    
    /* Call to QueryInterface */
    HRESULT hr = ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
      jarg2->vtable[0])(jarg2, &IID_ISWIGWrappedObject, (void **) &wrapper); 
    
    if (hr != S_OK) {
      /* Argument was not wrapped by SWIG - directors will be needed */
    } else {
      /* GetCPtr */
      void *c_ptr = ((void * (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[3]))(wrapper);
      arg2 = *(GeosGeometry **) &c_ptr;
      
      /* Release */
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (wrapper->vtable[2]))(wrapper);
    }
  }
  
  {
    try
    {
      result = (unsigned char *)GeosWkbWriter_writeHEX(arg1,(GeosGeometry const *)arg2,arg3);
      unsigned char *strbuf = 0;
      strbuf = (unsigned char *)malloc(*arg3 + 1);
      if (strbuf) {
        memcpy(strbuf, result, *arg3);
        strbuf[*arg3] = 0;
        _bstr_t bresult((const char*)strbuf);
        *SWIG_result_ptr = bresult.copy();
		free(strbuf);
      }
    }
    catch (const std::exception& e)
    {
      {
        SWIG_SetErrorInfo(e.what(), "WkbWriter", &IID_IWkbWriter);
        return E_ABORT; 
      };
    }
  }
  return S_OK;
}


extern GUID IID_IWkbWriterStatic;

extern SWIG_funcptr _wrapWkbWriterStatic_vtable[];

HRESULT SWIGSTDCALL _wrap_WkbWriterStatic(void *SWIG_ignored, SWIGIUnknown **SWIG_result) {
  *SWIG_result = (SWIGIUnknown *) _wrap_new_staticclass(_wrapWkbWriterStatic_vtable, &IID_IWkbWriterStatic);

  return S_OK;
}

GUID IID_Igeos = { 0x1e2792f9, 0xb414, 0x5d84, { 0xbc, 0xa5, 0x6a, 0xd6, 0x7e, 0xec, 0x8a, 0xd3}};

GUID CLSID_geos = { 0x37091295, 0xe126, 0x5e8f, { 0xb2, 0x93, 0xea, 0xb4, 0x78, 0x3b, 0x60, 0x33}};

extern SWIG_funcptr _wrapgeos_vtable[];

void * SWIGSTDCALL _wrap_new_geos() {
  initGEOS(noticeHandler, errorHandler);
  return _wrap_new_staticclass(_wrapgeos_vtable, &IID_Igeos);
};

SWIG_funcptr _wrapgeos_vtable[] = {
  (SWIG_funcptr) _wrap_staticclass_QueryInterface,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_GEOS_VERSION_MAJOR_get,
  (SWIG_funcptr) _wrap_GEOS_VERSION_MINOR_get,
  (SWIG_funcptr) _wrap_GEOS_VERSION_PATCH_get,
  (SWIG_funcptr) _wrap_GEOS_VERSION_get,
  (SWIG_funcptr) _wrap_GEOS_JTS_PORT_get,
  (SWIG_funcptr) _wrap_GEOS_CAPI_VERSION_MAJOR_get,
  (SWIG_funcptr) _wrap_GEOS_CAPI_VERSION_MINOR_get,
  (SWIG_funcptr) _wrap_GEOS_CAPI_VERSION_PATCH_get,
  (SWIG_funcptr) _wrap_GEOS_CAPI_FIRST_INTERFACE_get,
  (SWIG_funcptr) _wrap_GEOS_CAPI_LAST_INTERFACE_get,
  (SWIG_funcptr) _wrap_GEOS_CAPI_VERSION_get,
  (SWIG_funcptr) _wrap_GEOS_POINT_get,
  (SWIG_funcptr) _wrap_GEOS_LINESTRING_get,
  (SWIG_funcptr) _wrap_GEOS_LINEARRING_get,
  (SWIG_funcptr) _wrap_GEOS_POLYGON_get,
  (SWIG_funcptr) _wrap_GEOS_MULTIPOINT_get,
  (SWIG_funcptr) _wrap_GEOS_MULTILINESTRING_get,
  (SWIG_funcptr) _wrap_GEOS_MULTIPOLYGON_get,
  (SWIG_funcptr) _wrap_GEOS_GEOMETRYCOLLECTION_get,
  (SWIG_funcptr) _wrap_GEOS_WKB_XDR_get,
  (SWIG_funcptr) _wrap_GEOS_WKB_NDR_get,
  (SWIG_funcptr) _wrap_version,
  (SWIG_funcptr) _wrap_CoordinateSequenceStatic,
  (SWIG_funcptr) _wrap_createPoint,
  (SWIG_funcptr) _wrap_createLineString,
  (SWIG_funcptr) _wrap_createLinearRing,
  (SWIG_funcptr) _wrap_createPolygon,
  (SWIG_funcptr) _wrap_WktReaderStatic,
  (SWIG_funcptr) _wrap_WktWriterStatic,
  (SWIG_funcptr) _wrap_WkbReaderStatic,
  (SWIG_funcptr) _wrap_WkbWriterStatic
};

GUID IID_ICoordinateSequence = { 0xade7da6d, 0x5ebb, 0x5ed0, { 0x9d, 0x7b, 0x24, 0xd0, 0xf1, 0xbd, 0xb9, 0xb3}};

HRESULT SWIGSTDCALL _wrapCoordinateSequenceQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_ICoordinateSequence)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapCoordinateSequenceQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapCoordinateSequenceQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapCoordinateSequenceQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_ICoordinateSequence)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapCoordinateSequenceSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapCoordinateSequenceQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapCoordinateSequenceaggregated_vtable[] = {
  (SWIG_funcptr) _wrapCoordinateSequenceQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapCoordinateSequencevtable[] = {
  (SWIG_funcptr) _wrapCoordinateSequenceQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_CoordinateSequence_clone,
  (SWIG_funcptr) _wrap_CoordinateSequence_setX,
  (SWIG_funcptr) _wrap_CoordinateSequence_setY,
  (SWIG_funcptr) _wrap_CoordinateSequence_setZ,
  (SWIG_funcptr) _wrap_CoordinateSequence_setOrdinate,
  (SWIG_funcptr) _wrap_CoordinateSequence_getX,
  (SWIG_funcptr) _wrap_CoordinateSequence_getY,
  (SWIG_funcptr) _wrap_CoordinateSequence_getZ,
  (SWIG_funcptr) _wrap_CoordinateSequence_getOrdinate,
  (SWIG_funcptr) _wrap_CoordinateSequence_getSize,
  (SWIG_funcptr) _wrap_CoordinateSequence_getDimensions
};

void SWIG_delete_CoordinateSequence(GeosCoordinateSequence *arg) {
  delete_GeosCoordinateSequence(arg);
}

void * SWIGSTDCALL SWIG_wrapCoordinateSequence(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapCoordinateSequencevtable;
  res->SWIGWrappedObject_vtable = _wrapCoordinateSequenceSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapCoordinateSequenceaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_CoordinateSequence;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_ICoordinateSequence, &res->typeInfo);
  return (void *) res;
}

GUID IID_ICoordinateSequenceStatic = { 0xc3206b4f, 0x14c9, 0x5199, { 0x8f, 0xd8, 0x07, 0x8d, 0xa5, 0xd9, 0xa6, 0x65}};

extern SWIG_funcptr _wrapCoordinateSequenceStatic_vtable[];

SWIG_funcptr _wrapCoordinateSequenceStatic_vtable[] = {
  (SWIG_funcptr) _wrap_staticclass_QueryInterface,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_new_CoordinateSequence
};

GUID IID_IGeometry = { 0x1dbce943, 0x7d17, 0x548e, { 0xa5, 0x22, 0x6f, 0x7d, 0x9c, 0xff, 0x7d, 0xe4}};

HRESULT SWIGSTDCALL _wrapGeometryQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapGeometryQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapGeometryQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapGeometryQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_IGeometry)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapGeometrySWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapGeometryQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapGeometryaggregated_vtable[] = {
  (SWIG_funcptr) _wrapGeometryQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapGeometryvtable[] = {
  (SWIG_funcptr) _wrapGeometryQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_Geometry_clone,
  (SWIG_funcptr) _wrap_Geometry_geomType,
  (SWIG_funcptr) _wrap_Geometry_typeId,
  (SWIG_funcptr) _wrap_Geometry_normalize,
  (SWIG_funcptr) _wrap_Geometry_getSRID,
  (SWIG_funcptr) _wrap_Geometry_setSRID,
  (SWIG_funcptr) _wrap_Geometry_getDimensions,
  (SWIG_funcptr) _wrap_Geometry_getNumGeometries,
  (SWIG_funcptr) _wrap_Geometry_intersection,
  (SWIG_funcptr) _wrap_Geometry_buffer,
  (SWIG_funcptr) _wrap_Geometry_convexHull,
  (SWIG_funcptr) _wrap_Geometry_difference,
  (SWIG_funcptr) _wrap_Geometry_symDifference,
  (SWIG_funcptr) _wrap_Geometry_boundary,
  (SWIG_funcptr) _wrap_Geometry_Union,
  (SWIG_funcptr) _wrap_Geometry_pointOnSurface,
  (SWIG_funcptr) _wrap_Geometry_getCentroid,
  (SWIG_funcptr) _wrap_Geometry_getEnvelope,
  (SWIG_funcptr) _wrap_Geometry_relate,
  (SWIG_funcptr) _wrap_Geometry_lineMerge,
  (SWIG_funcptr) _wrap_Geometry_simplify,
  (SWIG_funcptr) _wrap_Geometry_topologyPreserveSimplify,
  (SWIG_funcptr) _wrap_Geometry_relatePattern,
  (SWIG_funcptr) _wrap_Geometry_disjoint,
  (SWIG_funcptr) _wrap_Geometry_touches,
  (SWIG_funcptr) _wrap_Geometry_intersects,
  (SWIG_funcptr) _wrap_Geometry_crosses,
  (SWIG_funcptr) _wrap_Geometry_within,
  (SWIG_funcptr) _wrap_Geometry_contains,
  (SWIG_funcptr) _wrap_Geometry_overlaps,
  (SWIG_funcptr) _wrap_Geometry_equals,
  (SWIG_funcptr) _wrap_Geometry_equalsExact,
  (SWIG_funcptr) _wrap_Geometry_isEmpty,
  (SWIG_funcptr) _wrap_Geometry_isValid,
  (SWIG_funcptr) _wrap_Geometry_isSimple,
  (SWIG_funcptr) _wrap_Geometry_isRing,
  (SWIG_funcptr) _wrap_Geometry_hasZ,
  (SWIG_funcptr) _wrap_Geometry_area,
  (SWIG_funcptr) _wrap_Geometry_length,
  (SWIG_funcptr) _wrap_Geometry_distance
};

void SWIG_delete_Geometry(GeosGeometry *arg) {
  delete_GeosGeometry(arg);
}

void * SWIGSTDCALL SWIG_wrapGeometry(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapGeometryvtable;
  res->SWIGWrappedObject_vtable = _wrapGeometrySWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapGeometryaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_Geometry;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_IGeometry, &res->typeInfo);
  return (void *) res;
}

GUID IID_IPoint = { 0x9172157d, 0xc90f, 0x5565, { 0xad, 0xd0, 0xd5, 0x09, 0xc5, 0xa6, 0x05, 0x49}};

HRESULT SWIGSTDCALL _wrapPointQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_IPoint) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapPointQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapPointQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapPointQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_IPoint) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapPointSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapPointQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapPointaggregated_vtable[] = {
  (SWIG_funcptr) _wrapPointQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapPointvtable[] = {
  (SWIG_funcptr) _wrapPointQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_Geometry_clone,
  (SWIG_funcptr) _wrap_Geometry_geomType,
  (SWIG_funcptr) _wrap_Geometry_typeId,
  (SWIG_funcptr) _wrap_Geometry_normalize,
  (SWIG_funcptr) _wrap_Geometry_getSRID,
  (SWIG_funcptr) _wrap_Geometry_setSRID,
  (SWIG_funcptr) _wrap_Geometry_getDimensions,
  (SWIG_funcptr) _wrap_Geometry_getNumGeometries,
  (SWIG_funcptr) _wrap_Geometry_intersection,
  (SWIG_funcptr) _wrap_Geometry_buffer,
  (SWIG_funcptr) _wrap_Geometry_convexHull,
  (SWIG_funcptr) _wrap_Geometry_difference,
  (SWIG_funcptr) _wrap_Geometry_symDifference,
  (SWIG_funcptr) _wrap_Geometry_boundary,
  (SWIG_funcptr) _wrap_Geometry_Union,
  (SWIG_funcptr) _wrap_Geometry_pointOnSurface,
  (SWIG_funcptr) _wrap_Geometry_getCentroid,
  (SWIG_funcptr) _wrap_Geometry_getEnvelope,
  (SWIG_funcptr) _wrap_Geometry_relate,
  (SWIG_funcptr) _wrap_Geometry_lineMerge,
  (SWIG_funcptr) _wrap_Geometry_simplify,
  (SWIG_funcptr) _wrap_Geometry_topologyPreserveSimplify,
  (SWIG_funcptr) _wrap_Geometry_relatePattern,
  (SWIG_funcptr) _wrap_Geometry_disjoint,
  (SWIG_funcptr) _wrap_Geometry_touches,
  (SWIG_funcptr) _wrap_Geometry_intersects,
  (SWIG_funcptr) _wrap_Geometry_crosses,
  (SWIG_funcptr) _wrap_Geometry_within,
  (SWIG_funcptr) _wrap_Geometry_contains,
  (SWIG_funcptr) _wrap_Geometry_overlaps,
  (SWIG_funcptr) _wrap_Geometry_equals,
  (SWIG_funcptr) _wrap_Geometry_equalsExact,
  (SWIG_funcptr) _wrap_Geometry_isEmpty,
  (SWIG_funcptr) _wrap_Geometry_isValid,
  (SWIG_funcptr) _wrap_Geometry_isSimple,
  (SWIG_funcptr) _wrap_Geometry_isRing,
  (SWIG_funcptr) _wrap_Geometry_hasZ,
  (SWIG_funcptr) _wrap_Geometry_area,
  (SWIG_funcptr) _wrap_Geometry_length,
  (SWIG_funcptr) _wrap_Geometry_distance,
  (SWIG_funcptr) _wrap_Point_getCoordSeq
};

void SWIG_delete_Point(GeosPoint *arg) {
  delete_GeosPoint(arg);
}

void * SWIGSTDCALL SWIG_wrapPoint(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapPointvtable;
  res->SWIGWrappedObject_vtable = _wrapPointSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapPointaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_Point;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_IPoint, &res->typeInfo);
  return (void *) res;
}

GUID IID_ILineString = { 0x98752de3, 0x4684, 0x5906, { 0x84, 0x88, 0x2b, 0x9d, 0xfb, 0x0c, 0x91, 0xdd}};

HRESULT SWIGSTDCALL _wrapLineStringQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_ILineString) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapLineStringQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapLineStringQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapLineStringQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_ILineString) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapLineStringSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapLineStringQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapLineStringaggregated_vtable[] = {
  (SWIG_funcptr) _wrapLineStringQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapLineStringvtable[] = {
  (SWIG_funcptr) _wrapLineStringQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_Geometry_clone,
  (SWIG_funcptr) _wrap_Geometry_geomType,
  (SWIG_funcptr) _wrap_Geometry_typeId,
  (SWIG_funcptr) _wrap_Geometry_normalize,
  (SWIG_funcptr) _wrap_Geometry_getSRID,
  (SWIG_funcptr) _wrap_Geometry_setSRID,
  (SWIG_funcptr) _wrap_Geometry_getDimensions,
  (SWIG_funcptr) _wrap_Geometry_getNumGeometries,
  (SWIG_funcptr) _wrap_Geometry_intersection,
  (SWIG_funcptr) _wrap_Geometry_buffer,
  (SWIG_funcptr) _wrap_Geometry_convexHull,
  (SWIG_funcptr) _wrap_Geometry_difference,
  (SWIG_funcptr) _wrap_Geometry_symDifference,
  (SWIG_funcptr) _wrap_Geometry_boundary,
  (SWIG_funcptr) _wrap_Geometry_Union,
  (SWIG_funcptr) _wrap_Geometry_pointOnSurface,
  (SWIG_funcptr) _wrap_Geometry_getCentroid,
  (SWIG_funcptr) _wrap_Geometry_getEnvelope,
  (SWIG_funcptr) _wrap_Geometry_relate,
  (SWIG_funcptr) _wrap_Geometry_lineMerge,
  (SWIG_funcptr) _wrap_Geometry_simplify,
  (SWIG_funcptr) _wrap_Geometry_topologyPreserveSimplify,
  (SWIG_funcptr) _wrap_Geometry_relatePattern,
  (SWIG_funcptr) _wrap_Geometry_disjoint,
  (SWIG_funcptr) _wrap_Geometry_touches,
  (SWIG_funcptr) _wrap_Geometry_intersects,
  (SWIG_funcptr) _wrap_Geometry_crosses,
  (SWIG_funcptr) _wrap_Geometry_within,
  (SWIG_funcptr) _wrap_Geometry_contains,
  (SWIG_funcptr) _wrap_Geometry_overlaps,
  (SWIG_funcptr) _wrap_Geometry_equals,
  (SWIG_funcptr) _wrap_Geometry_equalsExact,
  (SWIG_funcptr) _wrap_Geometry_isEmpty,
  (SWIG_funcptr) _wrap_Geometry_isValid,
  (SWIG_funcptr) _wrap_Geometry_isSimple,
  (SWIG_funcptr) _wrap_Geometry_isRing,
  (SWIG_funcptr) _wrap_Geometry_hasZ,
  (SWIG_funcptr) _wrap_Geometry_area,
  (SWIG_funcptr) _wrap_Geometry_length,
  (SWIG_funcptr) _wrap_Geometry_distance,
  (SWIG_funcptr) _wrap_LineString_getCoordSeq
};

void SWIG_delete_LineString(GeosLineString *arg) {
  delete_GeosLineString(arg);
}

void * SWIGSTDCALL SWIG_wrapLineString(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapLineStringvtable;
  res->SWIGWrappedObject_vtable = _wrapLineStringSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapLineStringaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_LineString;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_ILineString, &res->typeInfo);
  return (void *) res;
}

GUID IID_ILinearRing = { 0xb64cf891, 0xa616, 0x57ac, { 0xa2, 0x5c, 0xe9, 0xea, 0x10, 0xc1, 0xe2, 0x7c}};

HRESULT SWIGSTDCALL _wrapLinearRingQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_ILinearRing) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapLinearRingQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapLinearRingQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapLinearRingQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_ILinearRing) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapLinearRingSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapLinearRingQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapLinearRingaggregated_vtable[] = {
  (SWIG_funcptr) _wrapLinearRingQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapLinearRingvtable[] = {
  (SWIG_funcptr) _wrapLinearRingQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_Geometry_clone,
  (SWIG_funcptr) _wrap_Geometry_geomType,
  (SWIG_funcptr) _wrap_Geometry_typeId,
  (SWIG_funcptr) _wrap_Geometry_normalize,
  (SWIG_funcptr) _wrap_Geometry_getSRID,
  (SWIG_funcptr) _wrap_Geometry_setSRID,
  (SWIG_funcptr) _wrap_Geometry_getDimensions,
  (SWIG_funcptr) _wrap_Geometry_getNumGeometries,
  (SWIG_funcptr) _wrap_Geometry_intersection,
  (SWIG_funcptr) _wrap_Geometry_buffer,
  (SWIG_funcptr) _wrap_Geometry_convexHull,
  (SWIG_funcptr) _wrap_Geometry_difference,
  (SWIG_funcptr) _wrap_Geometry_symDifference,
  (SWIG_funcptr) _wrap_Geometry_boundary,
  (SWIG_funcptr) _wrap_Geometry_Union,
  (SWIG_funcptr) _wrap_Geometry_pointOnSurface,
  (SWIG_funcptr) _wrap_Geometry_getCentroid,
  (SWIG_funcptr) _wrap_Geometry_getEnvelope,
  (SWIG_funcptr) _wrap_Geometry_relate,
  (SWIG_funcptr) _wrap_Geometry_lineMerge,
  (SWIG_funcptr) _wrap_Geometry_simplify,
  (SWIG_funcptr) _wrap_Geometry_topologyPreserveSimplify,
  (SWIG_funcptr) _wrap_Geometry_relatePattern,
  (SWIG_funcptr) _wrap_Geometry_disjoint,
  (SWIG_funcptr) _wrap_Geometry_touches,
  (SWIG_funcptr) _wrap_Geometry_intersects,
  (SWIG_funcptr) _wrap_Geometry_crosses,
  (SWIG_funcptr) _wrap_Geometry_within,
  (SWIG_funcptr) _wrap_Geometry_contains,
  (SWIG_funcptr) _wrap_Geometry_overlaps,
  (SWIG_funcptr) _wrap_Geometry_equals,
  (SWIG_funcptr) _wrap_Geometry_equalsExact,
  (SWIG_funcptr) _wrap_Geometry_isEmpty,
  (SWIG_funcptr) _wrap_Geometry_isValid,
  (SWIG_funcptr) _wrap_Geometry_isSimple,
  (SWIG_funcptr) _wrap_Geometry_isRing,
  (SWIG_funcptr) _wrap_Geometry_hasZ,
  (SWIG_funcptr) _wrap_Geometry_area,
  (SWIG_funcptr) _wrap_Geometry_length,
  (SWIG_funcptr) _wrap_Geometry_distance,
  (SWIG_funcptr) _wrap_LinearRing_getCoordSeq
};

void SWIG_delete_LinearRing(GeosLinearRing *arg) {
  delete_GeosLinearRing(arg);
}

void * SWIGSTDCALL SWIG_wrapLinearRing(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapLinearRingvtable;
  res->SWIGWrappedObject_vtable = _wrapLinearRingSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapLinearRingaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_LinearRing;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_ILinearRing, &res->typeInfo);
  return (void *) res;
}

GUID IID_IPolygon = { 0xd21be932, 0x9692, 0x5899, { 0xb3, 0x4c, 0x23, 0x59, 0x94, 0x42, 0xa2, 0x9b}};

HRESULT SWIGSTDCALL _wrapPolygonQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_IPolygon) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapPolygonQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapPolygonQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapPolygonQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_IPolygon) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapPolygonSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapPolygonQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapPolygonaggregated_vtable[] = {
  (SWIG_funcptr) _wrapPolygonQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapPolygonvtable[] = {
  (SWIG_funcptr) _wrapPolygonQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_Geometry_clone,
  (SWIG_funcptr) _wrap_Geometry_geomType,
  (SWIG_funcptr) _wrap_Geometry_typeId,
  (SWIG_funcptr) _wrap_Geometry_normalize,
  (SWIG_funcptr) _wrap_Geometry_getSRID,
  (SWIG_funcptr) _wrap_Geometry_setSRID,
  (SWIG_funcptr) _wrap_Geometry_getDimensions,
  (SWIG_funcptr) _wrap_Geometry_getNumGeometries,
  (SWIG_funcptr) _wrap_Geometry_intersection,
  (SWIG_funcptr) _wrap_Geometry_buffer,
  (SWIG_funcptr) _wrap_Geometry_convexHull,
  (SWIG_funcptr) _wrap_Geometry_difference,
  (SWIG_funcptr) _wrap_Geometry_symDifference,
  (SWIG_funcptr) _wrap_Geometry_boundary,
  (SWIG_funcptr) _wrap_Geometry_Union,
  (SWIG_funcptr) _wrap_Geometry_pointOnSurface,
  (SWIG_funcptr) _wrap_Geometry_getCentroid,
  (SWIG_funcptr) _wrap_Geometry_getEnvelope,
  (SWIG_funcptr) _wrap_Geometry_relate,
  (SWIG_funcptr) _wrap_Geometry_lineMerge,
  (SWIG_funcptr) _wrap_Geometry_simplify,
  (SWIG_funcptr) _wrap_Geometry_topologyPreserveSimplify,
  (SWIG_funcptr) _wrap_Geometry_relatePattern,
  (SWIG_funcptr) _wrap_Geometry_disjoint,
  (SWIG_funcptr) _wrap_Geometry_touches,
  (SWIG_funcptr) _wrap_Geometry_intersects,
  (SWIG_funcptr) _wrap_Geometry_crosses,
  (SWIG_funcptr) _wrap_Geometry_within,
  (SWIG_funcptr) _wrap_Geometry_contains,
  (SWIG_funcptr) _wrap_Geometry_overlaps,
  (SWIG_funcptr) _wrap_Geometry_equals,
  (SWIG_funcptr) _wrap_Geometry_equalsExact,
  (SWIG_funcptr) _wrap_Geometry_isEmpty,
  (SWIG_funcptr) _wrap_Geometry_isValid,
  (SWIG_funcptr) _wrap_Geometry_isSimple,
  (SWIG_funcptr) _wrap_Geometry_isRing,
  (SWIG_funcptr) _wrap_Geometry_hasZ,
  (SWIG_funcptr) _wrap_Geometry_area,
  (SWIG_funcptr) _wrap_Geometry_length,
  (SWIG_funcptr) _wrap_Geometry_distance,
  (SWIG_funcptr) _wrap_Polygon_getExteriorRing,
  (SWIG_funcptr) _wrap_Polygon_getNumInteriorRings,
  (SWIG_funcptr) _wrap_Polygon_getInteriorRingN
};

void SWIG_delete_Polygon(GeosPolygon *arg) {
  delete_GeosPolygon(arg);
}

void * SWIGSTDCALL SWIG_wrapPolygon(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapPolygonvtable;
  res->SWIGWrappedObject_vtable = _wrapPolygonSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapPolygonaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_Polygon;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_IPolygon, &res->typeInfo);
  return (void *) res;
}

GUID IID_IGeometryCollection = { 0x89b326e7, 0xd823, 0x5a4e, { 0x92, 0x01, 0x46, 0xd8, 0xc4, 0x82, 0x81, 0x81}};

HRESULT SWIGSTDCALL _wrapGeometryCollectionQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_IGeometryCollection) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapGeometryCollectionQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapGeometryCollectionQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapGeometryCollectionQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_IGeometryCollection) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapGeometryCollectionSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapGeometryCollectionQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapGeometryCollectionaggregated_vtable[] = {
  (SWIG_funcptr) _wrapGeometryCollectionQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapGeometryCollectionvtable[] = {
  (SWIG_funcptr) _wrapGeometryCollectionQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_Geometry_clone,
  (SWIG_funcptr) _wrap_Geometry_geomType,
  (SWIG_funcptr) _wrap_Geometry_typeId,
  (SWIG_funcptr) _wrap_Geometry_normalize,
  (SWIG_funcptr) _wrap_Geometry_getSRID,
  (SWIG_funcptr) _wrap_Geometry_setSRID,
  (SWIG_funcptr) _wrap_Geometry_getDimensions,
  (SWIG_funcptr) _wrap_Geometry_getNumGeometries,
  (SWIG_funcptr) _wrap_Geometry_intersection,
  (SWIG_funcptr) _wrap_Geometry_buffer,
  (SWIG_funcptr) _wrap_Geometry_convexHull,
  (SWIG_funcptr) _wrap_Geometry_difference,
  (SWIG_funcptr) _wrap_Geometry_symDifference,
  (SWIG_funcptr) _wrap_Geometry_boundary,
  (SWIG_funcptr) _wrap_Geometry_Union,
  (SWIG_funcptr) _wrap_Geometry_pointOnSurface,
  (SWIG_funcptr) _wrap_Geometry_getCentroid,
  (SWIG_funcptr) _wrap_Geometry_getEnvelope,
  (SWIG_funcptr) _wrap_Geometry_relate,
  (SWIG_funcptr) _wrap_Geometry_lineMerge,
  (SWIG_funcptr) _wrap_Geometry_simplify,
  (SWIG_funcptr) _wrap_Geometry_topologyPreserveSimplify,
  (SWIG_funcptr) _wrap_Geometry_relatePattern,
  (SWIG_funcptr) _wrap_Geometry_disjoint,
  (SWIG_funcptr) _wrap_Geometry_touches,
  (SWIG_funcptr) _wrap_Geometry_intersects,
  (SWIG_funcptr) _wrap_Geometry_crosses,
  (SWIG_funcptr) _wrap_Geometry_within,
  (SWIG_funcptr) _wrap_Geometry_contains,
  (SWIG_funcptr) _wrap_Geometry_overlaps,
  (SWIG_funcptr) _wrap_Geometry_equals,
  (SWIG_funcptr) _wrap_Geometry_equalsExact,
  (SWIG_funcptr) _wrap_Geometry_isEmpty,
  (SWIG_funcptr) _wrap_Geometry_isValid,
  (SWIG_funcptr) _wrap_Geometry_isSimple,
  (SWIG_funcptr) _wrap_Geometry_isRing,
  (SWIG_funcptr) _wrap_Geometry_hasZ,
  (SWIG_funcptr) _wrap_Geometry_area,
  (SWIG_funcptr) _wrap_Geometry_length,
  (SWIG_funcptr) _wrap_Geometry_distance,
  (SWIG_funcptr) _wrap_GeometryCollection_getGeometryN
};

void SWIG_delete_GeometryCollection(GeosGeometryCollection *arg) {
  delete_GeosGeometryCollection(arg);
}

void * SWIGSTDCALL SWIG_wrapGeometryCollection(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapGeometryCollectionvtable;
  res->SWIGWrappedObject_vtable = _wrapGeometryCollectionSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapGeometryCollectionaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_GeometryCollection;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_IGeometryCollection, &res->typeInfo);
  return (void *) res;
}

GUID IID_IMultiPoint = { 0xa73af551, 0xcb91, 0x5877, { 0x80, 0x27, 0xc9, 0x12, 0x6d, 0xd5, 0x11, 0x9f}};

HRESULT SWIGSTDCALL _wrapMultiPointQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_IMultiPoint) ||
        SWIGIsEqual(iid, &IID_IGeometryCollection) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapMultiPointQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapMultiPointQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapMultiPointQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_IMultiPoint) ||
        SWIGIsEqual(iid, &IID_IGeometryCollection) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapMultiPointSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapMultiPointQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapMultiPointaggregated_vtable[] = {
  (SWIG_funcptr) _wrapMultiPointQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapMultiPointvtable[] = {
  (SWIG_funcptr) _wrapMultiPointQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_Geometry_clone,
  (SWIG_funcptr) _wrap_Geometry_geomType,
  (SWIG_funcptr) _wrap_Geometry_typeId,
  (SWIG_funcptr) _wrap_Geometry_normalize,
  (SWIG_funcptr) _wrap_Geometry_getSRID,
  (SWIG_funcptr) _wrap_Geometry_setSRID,
  (SWIG_funcptr) _wrap_Geometry_getDimensions,
  (SWIG_funcptr) _wrap_Geometry_getNumGeometries,
  (SWIG_funcptr) _wrap_Geometry_intersection,
  (SWIG_funcptr) _wrap_Geometry_buffer,
  (SWIG_funcptr) _wrap_Geometry_convexHull,
  (SWIG_funcptr) _wrap_Geometry_difference,
  (SWIG_funcptr) _wrap_Geometry_symDifference,
  (SWIG_funcptr) _wrap_Geometry_boundary,
  (SWIG_funcptr) _wrap_Geometry_Union,
  (SWIG_funcptr) _wrap_Geometry_pointOnSurface,
  (SWIG_funcptr) _wrap_Geometry_getCentroid,
  (SWIG_funcptr) _wrap_Geometry_getEnvelope,
  (SWIG_funcptr) _wrap_Geometry_relate,
  (SWIG_funcptr) _wrap_Geometry_lineMerge,
  (SWIG_funcptr) _wrap_Geometry_simplify,
  (SWIG_funcptr) _wrap_Geometry_topologyPreserveSimplify,
  (SWIG_funcptr) _wrap_Geometry_relatePattern,
  (SWIG_funcptr) _wrap_Geometry_disjoint,
  (SWIG_funcptr) _wrap_Geometry_touches,
  (SWIG_funcptr) _wrap_Geometry_intersects,
  (SWIG_funcptr) _wrap_Geometry_crosses,
  (SWIG_funcptr) _wrap_Geometry_within,
  (SWIG_funcptr) _wrap_Geometry_contains,
  (SWIG_funcptr) _wrap_Geometry_overlaps,
  (SWIG_funcptr) _wrap_Geometry_equals,
  (SWIG_funcptr) _wrap_Geometry_equalsExact,
  (SWIG_funcptr) _wrap_Geometry_isEmpty,
  (SWIG_funcptr) _wrap_Geometry_isValid,
  (SWIG_funcptr) _wrap_Geometry_isSimple,
  (SWIG_funcptr) _wrap_Geometry_isRing,
  (SWIG_funcptr) _wrap_Geometry_hasZ,
  (SWIG_funcptr) _wrap_Geometry_area,
  (SWIG_funcptr) _wrap_Geometry_length,
  (SWIG_funcptr) _wrap_Geometry_distance,
  (SWIG_funcptr) _wrap_GeometryCollection_getGeometryN
};

void SWIG_delete_MultiPoint(GeosMultiPoint *arg) {
  delete_GeosMultiPoint(arg);
}

void * SWIGSTDCALL SWIG_wrapMultiPoint(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapMultiPointvtable;
  res->SWIGWrappedObject_vtable = _wrapMultiPointSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapMultiPointaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_MultiPoint;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_IMultiPoint, &res->typeInfo);
  return (void *) res;
}

GUID IID_IMultiLineString = { 0x9473df4e, 0x61ce, 0x5b5b, { 0xa5, 0xf0, 0x0f, 0x54, 0x43, 0x24, 0x73, 0xbf}};

HRESULT SWIGSTDCALL _wrapMultiLineStringQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_IMultiLineString) ||
        SWIGIsEqual(iid, &IID_IGeometryCollection) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapMultiLineStringQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapMultiLineStringQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapMultiLineStringQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_IMultiLineString) ||
        SWIGIsEqual(iid, &IID_IGeometryCollection) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapMultiLineStringSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapMultiLineStringQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapMultiLineStringaggregated_vtable[] = {
  (SWIG_funcptr) _wrapMultiLineStringQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapMultiLineStringvtable[] = {
  (SWIG_funcptr) _wrapMultiLineStringQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_Geometry_clone,
  (SWIG_funcptr) _wrap_Geometry_geomType,
  (SWIG_funcptr) _wrap_Geometry_typeId,
  (SWIG_funcptr) _wrap_Geometry_normalize,
  (SWIG_funcptr) _wrap_Geometry_getSRID,
  (SWIG_funcptr) _wrap_Geometry_setSRID,
  (SWIG_funcptr) _wrap_Geometry_getDimensions,
  (SWIG_funcptr) _wrap_Geometry_getNumGeometries,
  (SWIG_funcptr) _wrap_Geometry_intersection,
  (SWIG_funcptr) _wrap_Geometry_buffer,
  (SWIG_funcptr) _wrap_Geometry_convexHull,
  (SWIG_funcptr) _wrap_Geometry_difference,
  (SWIG_funcptr) _wrap_Geometry_symDifference,
  (SWIG_funcptr) _wrap_Geometry_boundary,
  (SWIG_funcptr) _wrap_Geometry_Union,
  (SWIG_funcptr) _wrap_Geometry_pointOnSurface,
  (SWIG_funcptr) _wrap_Geometry_getCentroid,
  (SWIG_funcptr) _wrap_Geometry_getEnvelope,
  (SWIG_funcptr) _wrap_Geometry_relate,
  (SWIG_funcptr) _wrap_Geometry_lineMerge,
  (SWIG_funcptr) _wrap_Geometry_simplify,
  (SWIG_funcptr) _wrap_Geometry_topologyPreserveSimplify,
  (SWIG_funcptr) _wrap_Geometry_relatePattern,
  (SWIG_funcptr) _wrap_Geometry_disjoint,
  (SWIG_funcptr) _wrap_Geometry_touches,
  (SWIG_funcptr) _wrap_Geometry_intersects,
  (SWIG_funcptr) _wrap_Geometry_crosses,
  (SWIG_funcptr) _wrap_Geometry_within,
  (SWIG_funcptr) _wrap_Geometry_contains,
  (SWIG_funcptr) _wrap_Geometry_overlaps,
  (SWIG_funcptr) _wrap_Geometry_equals,
  (SWIG_funcptr) _wrap_Geometry_equalsExact,
  (SWIG_funcptr) _wrap_Geometry_isEmpty,
  (SWIG_funcptr) _wrap_Geometry_isValid,
  (SWIG_funcptr) _wrap_Geometry_isSimple,
  (SWIG_funcptr) _wrap_Geometry_isRing,
  (SWIG_funcptr) _wrap_Geometry_hasZ,
  (SWIG_funcptr) _wrap_Geometry_area,
  (SWIG_funcptr) _wrap_Geometry_length,
  (SWIG_funcptr) _wrap_Geometry_distance,
  (SWIG_funcptr) _wrap_GeometryCollection_getGeometryN
};

void SWIG_delete_MultiLineString(GeosMultiLineString *arg) {
  delete_GeosMultiLineString(arg);
}

void * SWIGSTDCALL SWIG_wrapMultiLineString(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapMultiLineStringvtable;
  res->SWIGWrappedObject_vtable = _wrapMultiLineStringSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapMultiLineStringaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_MultiLineString;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_IMultiLineString, &res->typeInfo);
  return (void *) res;
}

GUID IID_IMultiLinearRing = { 0x066c9e59, 0x826c, 0x5868, { 0x8a, 0x06, 0x40, 0x56, 0x4b, 0xda, 0xea, 0xe1}};

HRESULT SWIGSTDCALL _wrapMultiLinearRingQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_IMultiLinearRing) ||
        SWIGIsEqual(iid, &IID_IGeometryCollection) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapMultiLinearRingQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapMultiLinearRingQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapMultiLinearRingQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_IMultiLinearRing) ||
        SWIGIsEqual(iid, &IID_IGeometryCollection) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapMultiLinearRingSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapMultiLinearRingQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapMultiLinearRingaggregated_vtable[] = {
  (SWIG_funcptr) _wrapMultiLinearRingQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapMultiLinearRingvtable[] = {
  (SWIG_funcptr) _wrapMultiLinearRingQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_Geometry_clone,
  (SWIG_funcptr) _wrap_Geometry_geomType,
  (SWIG_funcptr) _wrap_Geometry_typeId,
  (SWIG_funcptr) _wrap_Geometry_normalize,
  (SWIG_funcptr) _wrap_Geometry_getSRID,
  (SWIG_funcptr) _wrap_Geometry_setSRID,
  (SWIG_funcptr) _wrap_Geometry_getDimensions,
  (SWIG_funcptr) _wrap_Geometry_getNumGeometries,
  (SWIG_funcptr) _wrap_Geometry_intersection,
  (SWIG_funcptr) _wrap_Geometry_buffer,
  (SWIG_funcptr) _wrap_Geometry_convexHull,
  (SWIG_funcptr) _wrap_Geometry_difference,
  (SWIG_funcptr) _wrap_Geometry_symDifference,
  (SWIG_funcptr) _wrap_Geometry_boundary,
  (SWIG_funcptr) _wrap_Geometry_Union,
  (SWIG_funcptr) _wrap_Geometry_pointOnSurface,
  (SWIG_funcptr) _wrap_Geometry_getCentroid,
  (SWIG_funcptr) _wrap_Geometry_getEnvelope,
  (SWIG_funcptr) _wrap_Geometry_relate,
  (SWIG_funcptr) _wrap_Geometry_lineMerge,
  (SWIG_funcptr) _wrap_Geometry_simplify,
  (SWIG_funcptr) _wrap_Geometry_topologyPreserveSimplify,
  (SWIG_funcptr) _wrap_Geometry_relatePattern,
  (SWIG_funcptr) _wrap_Geometry_disjoint,
  (SWIG_funcptr) _wrap_Geometry_touches,
  (SWIG_funcptr) _wrap_Geometry_intersects,
  (SWIG_funcptr) _wrap_Geometry_crosses,
  (SWIG_funcptr) _wrap_Geometry_within,
  (SWIG_funcptr) _wrap_Geometry_contains,
  (SWIG_funcptr) _wrap_Geometry_overlaps,
  (SWIG_funcptr) _wrap_Geometry_equals,
  (SWIG_funcptr) _wrap_Geometry_equalsExact,
  (SWIG_funcptr) _wrap_Geometry_isEmpty,
  (SWIG_funcptr) _wrap_Geometry_isValid,
  (SWIG_funcptr) _wrap_Geometry_isSimple,
  (SWIG_funcptr) _wrap_Geometry_isRing,
  (SWIG_funcptr) _wrap_Geometry_hasZ,
  (SWIG_funcptr) _wrap_Geometry_area,
  (SWIG_funcptr) _wrap_Geometry_length,
  (SWIG_funcptr) _wrap_Geometry_distance,
  (SWIG_funcptr) _wrap_GeometryCollection_getGeometryN
};

void SWIG_delete_MultiLinearRing(GeosMultiLinearRing *arg) {
  delete_GeosMultiLinearRing(arg);
}

void * SWIGSTDCALL SWIG_wrapMultiLinearRing(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapMultiLinearRingvtable;
  res->SWIGWrappedObject_vtable = _wrapMultiLinearRingSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapMultiLinearRingaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_MultiLinearRing;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_IMultiLinearRing, &res->typeInfo);
  return (void *) res;
}

GUID IID_IMultiPolygon = { 0xa30c8553, 0xa922, 0x5421, { 0x92, 0x60, 0xea, 0xe8, 0x74, 0xa7, 0x45, 0xf4}};

HRESULT SWIGSTDCALL _wrapMultiPolygonQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_IMultiPolygon) ||
        SWIGIsEqual(iid, &IID_IGeometryCollection) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapMultiPolygonQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapMultiPolygonQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapMultiPolygonQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_IMultiPolygon) ||
        SWIGIsEqual(iid, &IID_IGeometryCollection) ||
        SWIGIsEqual(iid, &IID_IGeometry)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapMultiPolygonSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapMultiPolygonQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapMultiPolygonaggregated_vtable[] = {
  (SWIG_funcptr) _wrapMultiPolygonQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapMultiPolygonvtable[] = {
  (SWIG_funcptr) _wrapMultiPolygonQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_Geometry_clone,
  (SWIG_funcptr) _wrap_Geometry_geomType,
  (SWIG_funcptr) _wrap_Geometry_typeId,
  (SWIG_funcptr) _wrap_Geometry_normalize,
  (SWIG_funcptr) _wrap_Geometry_getSRID,
  (SWIG_funcptr) _wrap_Geometry_setSRID,
  (SWIG_funcptr) _wrap_Geometry_getDimensions,
  (SWIG_funcptr) _wrap_Geometry_getNumGeometries,
  (SWIG_funcptr) _wrap_Geometry_intersection,
  (SWIG_funcptr) _wrap_Geometry_buffer,
  (SWIG_funcptr) _wrap_Geometry_convexHull,
  (SWIG_funcptr) _wrap_Geometry_difference,
  (SWIG_funcptr) _wrap_Geometry_symDifference,
  (SWIG_funcptr) _wrap_Geometry_boundary,
  (SWIG_funcptr) _wrap_Geometry_Union,
  (SWIG_funcptr) _wrap_Geometry_pointOnSurface,
  (SWIG_funcptr) _wrap_Geometry_getCentroid,
  (SWIG_funcptr) _wrap_Geometry_getEnvelope,
  (SWIG_funcptr) _wrap_Geometry_relate,
  (SWIG_funcptr) _wrap_Geometry_lineMerge,
  (SWIG_funcptr) _wrap_Geometry_simplify,
  (SWIG_funcptr) _wrap_Geometry_topologyPreserveSimplify,
  (SWIG_funcptr) _wrap_Geometry_relatePattern,
  (SWIG_funcptr) _wrap_Geometry_disjoint,
  (SWIG_funcptr) _wrap_Geometry_touches,
  (SWIG_funcptr) _wrap_Geometry_intersects,
  (SWIG_funcptr) _wrap_Geometry_crosses,
  (SWIG_funcptr) _wrap_Geometry_within,
  (SWIG_funcptr) _wrap_Geometry_contains,
  (SWIG_funcptr) _wrap_Geometry_overlaps,
  (SWIG_funcptr) _wrap_Geometry_equals,
  (SWIG_funcptr) _wrap_Geometry_equalsExact,
  (SWIG_funcptr) _wrap_Geometry_isEmpty,
  (SWIG_funcptr) _wrap_Geometry_isValid,
  (SWIG_funcptr) _wrap_Geometry_isSimple,
  (SWIG_funcptr) _wrap_Geometry_isRing,
  (SWIG_funcptr) _wrap_Geometry_hasZ,
  (SWIG_funcptr) _wrap_Geometry_area,
  (SWIG_funcptr) _wrap_Geometry_length,
  (SWIG_funcptr) _wrap_Geometry_distance,
  (SWIG_funcptr) _wrap_GeometryCollection_getGeometryN
};

void SWIG_delete_MultiPolygon(GeosMultiPolygon *arg) {
  delete_GeosMultiPolygon(arg);
}

void * SWIGSTDCALL SWIG_wrapMultiPolygon(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapMultiPolygonvtable;
  res->SWIGWrappedObject_vtable = _wrapMultiPolygonSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapMultiPolygonaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_MultiPolygon;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_IMultiPolygon, &res->typeInfo);
  return (void *) res;
}

GUID IID_IWktReader = { 0xb9456944, 0x09f2, 0x5e98, { 0xaa, 0xe6, 0xeb, 0x4e, 0x90, 0xbc, 0x48, 0xbd}};

HRESULT SWIGSTDCALL _wrapWktReaderQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_IWktReader)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapWktReaderQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapWktReaderQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapWktReaderQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_IWktReader)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapWktReaderSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapWktReaderQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapWktReaderaggregated_vtable[] = {
  (SWIG_funcptr) _wrapWktReaderQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapWktReadervtable[] = {
  (SWIG_funcptr) _wrapWktReaderQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_WktReader_read
};

void SWIG_delete_WktReader(GeosWktReader *arg) {
  delete_GeosWktReader(arg);
}

void * SWIGSTDCALL SWIG_wrapWktReader(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapWktReadervtable;
  res->SWIGWrappedObject_vtable = _wrapWktReaderSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapWktReaderaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_WktReader;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_IWktReader, &res->typeInfo);
  return (void *) res;
}

GUID IID_IWktReaderStatic = { 0x7af915c7, 0x1c12, 0x5bca, { 0xb2, 0x86, 0x5a, 0x50, 0x02, 0x1b, 0xbb, 0xb4}};

extern SWIG_funcptr _wrapWktReaderStatic_vtable[];

SWIG_funcptr _wrapWktReaderStatic_vtable[] = {
  (SWIG_funcptr) _wrap_staticclass_QueryInterface,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_new_WktReader
};

GUID IID_IWktWriter = { 0xb82bf568, 0xd1c0, 0x58f4, { 0x87, 0xfb, 0x90, 0xa3, 0xf3, 0x08, 0x3c, 0xa9}};

HRESULT SWIGSTDCALL _wrapWktWriterQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_IWktWriter)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapWktWriterQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapWktWriterQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapWktWriterQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_IWktWriter)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapWktWriterSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapWktWriterQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapWktWriteraggregated_vtable[] = {
  (SWIG_funcptr) _wrapWktWriterQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapWktWritervtable[] = {
  (SWIG_funcptr) _wrapWktWriterQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_WktWriter_write
};

void SWIG_delete_WktWriter(GeosWktWriter *arg) {
  delete_GeosWktWriter(arg);
}

void * SWIGSTDCALL SWIG_wrapWktWriter(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapWktWritervtable;
  res->SWIGWrappedObject_vtable = _wrapWktWriterSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapWktWriteraggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_WktWriter;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_IWktWriter, &res->typeInfo);
  return (void *) res;
}

GUID IID_IWktWriterStatic = { 0xf16294bb, 0xac1d, 0x5e93, { 0xb0, 0x84, 0x12, 0x81, 0xd8, 0x9c, 0x00, 0x06}};

extern SWIG_funcptr _wrapWktWriterStatic_vtable[];

SWIG_funcptr _wrapWktWriterStatic_vtable[] = {
  (SWIG_funcptr) _wrap_staticclass_QueryInterface,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_new_WktWriter
};

GUID IID_IWkbReader = { 0xb3b28a97, 0x96f7, 0x556f, { 0xa8, 0xcf, 0x7f, 0x2d, 0xfa, 0xd1, 0xd4, 0x8d}};

HRESULT SWIGSTDCALL _wrapWkbReaderQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_IWkbReader)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapWkbReaderQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapWkbReaderQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapWkbReaderQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_IWkbReader)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapWkbReaderSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapWkbReaderQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapWkbReaderaggregated_vtable[] = {
  (SWIG_funcptr) _wrapWkbReaderQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapWkbReadervtable[] = {
  (SWIG_funcptr) _wrapWkbReaderQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_WkbReader_read,
  (SWIG_funcptr) _wrap_WkbReader_readHEX
};

void SWIG_delete_WkbReader(GeosWkbReader *arg) {
  delete_GeosWkbReader(arg);
}

void * SWIGSTDCALL SWIG_wrapWkbReader(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapWkbReadervtable;
  res->SWIGWrappedObject_vtable = _wrapWkbReaderSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapWkbReaderaggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_WkbReader;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_IWkbReader, &res->typeInfo);
  return (void *) res;
}

GUID IID_IWkbReaderStatic = { 0xea584621, 0xdee3, 0x5230, { 0xbd, 0x48, 0x67, 0x23, 0x68, 0x19, 0x20, 0x1e}};

extern SWIG_funcptr _wrapWkbReaderStatic_vtable[];

SWIG_funcptr _wrapWkbReaderStatic_vtable[] = {
  (SWIG_funcptr) _wrap_staticclass_QueryInterface,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_new_WkbReader
};

GUID IID_IWkbWriter = { 0xd8ecd1f7, 0xb5d5, 0x5bf1, { 0x91, 0x95, 0xaf, 0x9d, 0xe5, 0x3e, 0xd2, 0xa7}};

HRESULT SWIGSTDCALL _wrapWkbWriterQueryInterface1(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) that;

  if (obj->outer != NULL) {
    return ((HRESULT (SWIGSTDCALL *)(SWIGIUnknown *, GUID *, void **))
        obj->outer->vtable[0])(obj->outer, iid, ppvObject);
  } else {
    if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
      /* FIXME: This could be more elegant */
      SWIGAddRef1(that);
      *ppvObject = &obj->SWIGWrappedObject_vtable;
      return S_OK;
    } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
      SWIGAddRef1(that);
      *ppvObject = &obj->ISupportErrorInfo_vtable;
      return S_OK;
    }

    if (SWIGIsEqual(iid, &IID_IUnknown) ||
        SWIGIsEqual(iid, &IID_IDispatch) ||
        SWIGIsEqual(iid, &IID_IWkbWriter)) {
      SWIGAddRef1(that);
      *ppvObject = obj;
      return S_OK;
    }

    return E_NOINTERFACE;
  }
}

HRESULT SWIGSTDCALL _wrapWkbWriterQueryInterface2(void *that, GUID *iid, void ** ppvObject) {
  return _wrapWkbWriterQueryInterface1((void *) ((void **) that - 1), iid, ppvObject);
}

HRESULT SWIGSTDCALL _wrapWkbWriterQueryInterface3(void *that, GUID *iid, void ** ppvObject) {
  SWIGWrappedObject *obj = (SWIGWrappedObject *) ((void **)that - 2);

  if (SWIGIsEqual(iid, &IID_ISWIGWrappedObject)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->SWIGWrappedObject_vtable;
    return S_OK;
  } else if (SWIGIsEqual(iid, &IID_ISupportErrorInfo)) {
    SWIGAddRef1(that);
    *ppvObject = &obj->ISupportErrorInfo_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IUnknown)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = &obj->aggregated_vtable;
    return S_OK;
  }

  if (SWIGIsEqual(iid, &IID_IDispatch) ||
      SWIGIsEqual(iid, &IID_IWkbWriter)) {
    /* FIXME: This could be more elegant */
    SWIGAddRef3(that);
    *ppvObject = obj;
    return S_OK;
  }

  return E_NOINTERFACE;
}

SWIG_funcptr _wrapWkbWriterSWIGWrappedObject_vtable[] = {
  (SWIG_funcptr) _wrapWkbWriterQueryInterface2,
  (SWIG_funcptr) SWIGAddRef2,
  (SWIG_funcptr) SWIGRelease2,
  (SWIG_funcptr) SWIGGetCPtr
};

SWIG_funcptr _wrapWkbWriteraggregated_vtable[] = {
  (SWIG_funcptr) _wrapWkbWriterQueryInterface3,
  (SWIG_funcptr) SWIGAddRef3,
  (SWIG_funcptr) SWIGRelease3
};

SWIG_funcptr _wrapWkbWritervtable[] = {
  (SWIG_funcptr) _wrapWkbWriterQueryInterface1,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_WkbWriter_getOutputDimension,
  (SWIG_funcptr) _wrap_WkbWriter_setOutputDimension,
  (SWIG_funcptr) _wrap_WkbWriter_getByteOrder,
  (SWIG_funcptr) _wrap_WkbWriter_setByteOrder,
  (SWIG_funcptr) _wrap_WkbWriter_getIncludeSRID,
  (SWIG_funcptr) _wrap_WkbWriter_setIncludeSRID,
  (SWIG_funcptr) _wrap_WkbWriter_write,
  (SWIG_funcptr) _wrap_WkbWriter_writeHEX
};

void SWIG_delete_WkbWriter(GeosWkbWriter *arg) {
  delete_GeosWkbWriter(arg);
}

void * SWIGSTDCALL SWIG_wrapWkbWriter(void *arg, int cMemOwn) {
#ifdef __cplusplus
  SWIGWrappedObject *res = new SWIGWrappedObject;
#else
  SWIGWrappedObject *res = (SWIGWrappedObject *) malloc(sizeof(SWIGWrappedObject));
#endif
  res->vtable = _wrapWkbWritervtable;
  res->SWIGWrappedObject_vtable = _wrapWkbWriterSWIGWrappedObject_vtable;
  res->aggregated_vtable = _wrapWkbWriteraggregated_vtable;
  res->ISupportErrorInfo_vtable = ISupportErrorInfo_vtable;
  res->cPtr = arg;
  res->cMemOwn = cMemOwn;
  res->outer = NULL;
  InterlockedIncrement(&globalRefCount);
  res->refCount = 1;
  res->deleteInstance = (void (*)(void *)) SWIG_delete_WkbWriter;
  /* GetTypeInfoOfGuid */
  ((HRESULT (SWIGSTDCALL *)(ITypeLib *, GUID *, ITypeInfo **)) (((SWIGIUnknown *) SWIG_typelib)->vtable[6]))(SWIG_typelib, &IID_IWkbWriter, &res->typeInfo);
  return (void *) res;
}

GUID IID_IWkbWriterStatic = { 0x22962328, 0xc01d, 0x50d8, { 0xa5, 0x1d, 0x34, 0xd0, 0xb0, 0x1c, 0x56, 0x23}};

extern SWIG_funcptr _wrapWkbWriterStatic_vtable[];

SWIG_funcptr _wrapWkbWriterStatic_vtable[] = {
  (SWIG_funcptr) _wrap_staticclass_QueryInterface,
  (SWIG_funcptr) SWIGAddRef1,
  (SWIG_funcptr) SWIGRelease1,
  (SWIG_funcptr) SWIGGetTypeInfoCount,
  (SWIG_funcptr) SWIGGetTypeInfo,
  (SWIG_funcptr) SWIGGetIDsOfNames,
  (SWIG_funcptr) SWIGInvoke,
  (SWIG_funcptr) _wrap_new_WkbWriter
};

static TCHAR * SWIG_tlb_guid_string = _T("{28d0d0e2-75e0-5b3f-9621-bc0ccd3dad79}");

static SWIGClassDescription_t SWIGClassDescription[] = {
  { (SWIG_funcptr) _wrap_new_geos, &CLSID_geos, _T("{37091295-e126-5e8f-b293-eab4783b6033}"), _T("geos.geos"), 0 },
  { NULL, NULL, NULL, NULL } /* guard element */
};



static HMODULE SWIGModule;

STDAPI DllGetClassObject(REFCLSID _rclsid, REFIID _riid, LPVOID *_ppv) {
#if defined(__cplusplus) || defined(CINTERFACE)
  const GUID *rclsid = &_rclsid;
  const GUID *riid = &_riid;
#else
  const GUID *rclsid = _rclsid;
  const GUID *riid = _riid;
#endif

  int i;
  SWIGClassFactory **ppv = (SWIGClassFactory **)(void *) _ppv;

  if (!SWIGIsEqual(riid, &IID_IUnknown) && !SWIGIsEqual(riid, &IID_IClassFactory))
    return E_NOINTERFACE;

  for (i = 0; SWIGClassDescription[i].newInstance != NULL; ++i) {
    if (SWIGIsEqual(rclsid, SWIGClassDescription[i].guid)) {
      /* Create a new class factory for the requested CLSID */
#ifdef __cplusplus
      *ppv = new SWIGClassFactory;
#else
      *ppv = (SWIGClassFactory *) malloc(sizeof(SWIGClassFactory));
#endif
      (*ppv)->vtable = SWIGClassFactory_vtable;
      (*ppv)->newInstance = SWIGClassDescription[i].newInstance;
      (*ppv)->aggregatable = SWIGClassDescription[i].aggregatable;
      InterlockedIncrement(&globalRefCount);
      (*ppv)->refCount = 1;

      return S_OK;
    }
  }

  return CLASS_E_CLASSNOTAVAILABLE;
}

STDAPI DllCanUnloadNow(void) {
  /* Get the value of globalRefCount in a thread-safe manner */
  /* Could be maybe more elegant */
  LONG value = InterlockedExchangeAdd(&globalRefCount, 0);

  /*
   * Note - we have a guarantee that while we are in DllCanUnloadNow
   * all CoGetClassObject calls are put on hold. There is a really tiny
   * possibility of a race condition if there is a thread that
   * just decremented globalRefCount to 0 and is just performing the
   * return instruction.
   */

  if (value == 0)
    return S_OK;
  else
    return S_FALSE;
}

STDAPI DllRegisterServer(void) {
  TCHAR module_name[MAX_PATH + 1];
  TCHAR typelib_name[MAX_PATH + 1];
  int i;
  HRESULT hres = S_OK;
  int module_name_len;

#ifdef __WINE__
  /*
   * Wine has a broken implementation of GetModuleFileName, which does not
   * work correctly with Winelib DLLs. This is a very dumb workaround.
   * If you know how to fix it properly, please send a patch :)
   */
  if (GetCurrentDirectory(MAX_PATH + 1, module_name) == 0 ||
      _tcslen(module_name) + _tcslen(_T("\\geos.dll.so")) > MAX_PATH) {
    /* DLL name will not fit into MAX_PATH characters */
    return E_UNEXPECTED;
  }

  _tcscat(module_name, _T("\\geos.dll.so"));
#else
  GetModuleFileName(SWIGModule, module_name, MAX_PATH + 1);
#endif

  _tcscpy(typelib_name, module_name);
  module_name_len = _tcslen(module_name);

/* This needs to be made more flexible                     */
/* For now we assume that the TLB is a resource in the DLL */
#if 0
  /* Change .dll to .tlb */
  typelib_name[used - 3] = 't';
  typelib_name[used - 2] = 'l';
  typelib_name[used - 1] = 'b';
#endif

  for (i = 0; SWIGClassDescription[i].newInstance != NULL; ++i) {
    HKEY hkey_clsid = NULL,
        hkey = NULL,
        hsubkey = NULL;

    if (hres == S_OK &&
       RegOpenKeyEx(HKEY_CLASSES_ROOT, _T("CLSID"), 0, KEY_ALL_ACCESS, &hkey_clsid) != ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hres == S_OK &&
        RegCreateKeyEx(hkey_clsid, SWIGClassDescription[i].guid_string, 0, NULL,
        0, KEY_ALL_ACCESS, NULL, &hkey, NULL) != ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hres == S_OK &&
        RegCreateKeyEx(hkey, _T("InprocServer32"), 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hsubkey, NULL) !=
        ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hres == S_OK &&
        RegSetValueEx(hsubkey, _T(""), 0, REG_SZ, (BYTE *) module_name,
        sizeof(TCHAR) * (module_name_len + 1)) != ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hres == S_OK &&
        RegSetValueEx(hsubkey, _T("ThreadingModel"), 0, REG_SZ, (BYTE *) _T("Both"),
        sizeof(TCHAR) * 5) != ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hkey_clsid != NULL)
      CloseHandle(hkey_clsid);
    if (hkey != NULL)
      CloseHandle(hkey);
    if (hsubkey != NULL)
      CloseHandle(hsubkey);

    hkey = hkey_clsid = NULL;

    if (hres == S_OK &&
        RegCreateKeyEx(HKEY_CLASSES_ROOT, SWIGClassDescription[i].oleaut_string, 0, NULL,
        0, KEY_ALL_ACCESS, NULL, &hkey, NULL) != ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hres == S_OK &&
        RegCreateKeyEx(hkey, _T("CLSID"), 0, NULL,
        0, KEY_ALL_ACCESS, NULL, &hkey_clsid, NULL) != ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hres == S_OK &&
        RegSetValueEx(hkey_clsid, _T(""), 0, REG_SZ, (BYTE *) SWIGClassDescription[i].guid_string,
        sizeof(TCHAR) * 39) != ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hkey_clsid != NULL)
      CloseHandle(hkey_clsid);
    if (hkey != NULL)
      CloseHandle(hkey);
  }

  {
    HKEY hkey_typelib = NULL,
        hkey = NULL,
        hkey_version = NULL,
        hkey_helpdir = NULL,
        hkey_flags = NULL,
        hkey_lcid = NULL,
        hkey_win32 = NULL;

    if (hres == S_OK &&
        RegOpenKeyEx(HKEY_CLASSES_ROOT, _T("TypeLib"), 0, KEY_ALL_ACCESS, &hkey_typelib) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegCreateKeyEx(hkey_typelib, SWIG_tlb_guid_string, 0, NULL,
        0, KEY_ALL_ACCESS, NULL, &hkey, NULL) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegCreateKeyEx(hkey, /* FIXME */ _T("1.0"), 0, NULL,
        0, KEY_ALL_ACCESS, NULL, &hkey_version, NULL) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegSetValueEx(hkey_version, _T(""), 0, REG_SZ, (BYTE *) _T("geos"),
        sizeof(TCHAR) * _tcslen(_T("geos"))) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegCreateKeyEx(hkey_version, _T("HELPDIR"), 0, NULL,
        0, KEY_ALL_ACCESS, NULL, &hkey_helpdir, NULL) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegSetValueEx(hkey_helpdir, _T(""), 0, REG_SZ, (BYTE *) "0",
        sizeof(TCHAR) * 2) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegCreateKeyEx(hkey_version, _T("FLAGS"), 0, NULL,
        0, KEY_ALL_ACCESS, NULL, &hkey_flags, NULL) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegSetValueEx(hkey_flags, _T(""), 0, REG_SZ, (BYTE *) _T("0"),
        sizeof(TCHAR) * 2) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegCreateKeyEx(hkey_version, _T("0"), 0, NULL,
        0, KEY_ALL_ACCESS, NULL, &hkey_lcid, NULL) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegCreateKeyEx(hkey_lcid, _T("win32"), 0, NULL,
        0, KEY_ALL_ACCESS, NULL, &hkey_win32, NULL) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegSetValueEx(hkey_win32, _T(""), 0, REG_SZ, (BYTE *) typelib_name,
        sizeof(TCHAR) * (module_name_len + 1)) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hkey_helpdir != NULL)
      CloseHandle(hkey_helpdir);
    if (hkey_flags != NULL)
      CloseHandle(hkey_flags);
    if (hkey_typelib != NULL)
      CloseHandle(hkey_typelib);
    if (hkey != NULL)
      CloseHandle(hkey);
    if (hkey_version != NULL)
      CloseHandle(hkey_version);
    if (hkey_lcid != NULL)
      CloseHandle(hkey_lcid);
    if (hkey_win32 != NULL)
      CloseHandle(hkey_win32);
  }

  return hres;
}

STDAPI DllUnregisterServer(void) {
  HRESULT hres = S_OK;
  /*
   * We may only remove keys that we created. Therefore some operation may fail
   * if we are trying to delete a non-empty key, but this is not an error.
   */
  int leftovers = 0;
  int i;

  for (i = 0; SWIGClassDescription[i].newInstance != NULL; ++i) {
    HKEY hkey_clsid = NULL,
        hkey = NULL;

    if (hres == S_OK &&
       RegOpenKeyEx(HKEY_CLASSES_ROOT, _T("CLSID"), 0, KEY_ALL_ACCESS, &hkey_clsid) != ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hres == S_OK &&
        RegOpenKeyEx(hkey_clsid, SWIGClassDescription[i].guid_string, 0, KEY_ALL_ACCESS, &hkey) != ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hres == S_OK &&
        RegDeleteKey(hkey, _T("InprocServer32")) != ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hkey != NULL)
      CloseHandle(hkey);

    if (hres == S_OK &&
        RegDeleteKey(hkey_clsid, SWIGClassDescription[i].guid_string) != ERROR_SUCCESS) {
      leftovers = 1;
    }

    if (hkey_clsid != NULL)
      CloseHandle(hkey_clsid);

    hkey = NULL;

    if (hres == S_OK &&
        RegOpenKeyEx(HKEY_CLASSES_ROOT, SWIGClassDescription[i].oleaut_string, 0, KEY_ALL_ACCESS, &hkey) != ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hres == S_OK &&
        RegDeleteKey(hkey, _T("CLSID")) != ERROR_SUCCESS) {
      hres = SELFREG_E_CLASS;
    }

    if (hkey != NULL)
      CloseHandle(hkey);

    if (hres == S_OK &&
        RegDeleteKey(HKEY_CLASSES_ROOT, SWIGClassDescription[i].oleaut_string) != ERROR_SUCCESS) {
      leftovers = 1;
    }
  }

  {
    HKEY hkey_typelib = NULL,
        hkey = NULL,
        hkey_version = NULL,
        hkey_lcid = NULL;

    if (hres == S_OK &&
        RegOpenKeyEx(HKEY_CLASSES_ROOT, _T("TypeLib"), 0, KEY_ALL_ACCESS, &hkey_typelib) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegOpenKeyEx(hkey_typelib, SWIG_tlb_guid_string, 0, KEY_ALL_ACCESS, &hkey) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegOpenKeyEx(hkey, /* FIXME */ _T("1.0"), 0, KEY_ALL_ACCESS, &hkey_version) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegDeleteKey(hkey_version, _T("HELPDIR")) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegDeleteKey(hkey_version, _T("FLAGS")) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegOpenKeyEx(hkey_version, _T("0"), 0, KEY_ALL_ACCESS, &hkey_lcid) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hres == S_OK &&
        RegDeleteKey(hkey_lcid, _T("win32")) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hkey_lcid != NULL)
      CloseHandle(hkey_lcid);

    if (hres == S_OK &&
        RegDeleteKey(hkey_version, _T("0")) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hkey_version != NULL)
      CloseHandle(hkey_version);

    if (hres == S_OK &&
        RegDeleteKey(hkey, _T("1.0")) != ERROR_SUCCESS) {
      hres = SELFREG_E_TYPELIB;
    }

    if (hkey != NULL)
      CloseHandle(hkey);

    if (hres == S_OK &&
        RegDeleteKey(hkey_typelib, SWIG_tlb_guid_string) != ERROR_SUCCESS) {
      leftovers = 1;
    }

    if (hkey_typelib != NULL)
      CloseHandle(hkey_typelib);
  }

  if (hres == S_OK && leftovers) {
    /* Procedure successful, but some leftover keys present */
    return S_FALSE;
  }

  return hres;
}

#ifdef __cplusplus
extern "C"
#endif
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason,
    LPVOID lpvReserved) {
  if (fdwReason == DLL_PROCESS_ATTACH) {
    HRESULT hres = S_OK;

    SWIGModule = hinstDLL;

#ifdef __WINE__
    /*
     * Wine has a broken implementation of GetModuleFileName, which does not
     * work correctly with Winelib DLLs. Here we try to get the module file
     * name from the registry.
     */
    {
      HKEY hkey_typelib = NULL,
          hkey = NULL,
          hkey_version = NULL,
          hkey_lcid = NULL;
      LONG bytesRead = MAX_PATH + 1;

      if (hres == S_OK &&
          RegOpenKeyEx(HKEY_CLASSES_ROOT, _T("TypeLib"), 0, KEY_ALL_ACCESS, &hkey_typelib) != ERROR_SUCCESS) {
        hres = E_UNEXPECTED;
      }

      if (hres == S_OK &&
          RegOpenKeyEx(hkey_typelib, SWIG_tlb_guid_string, 0, KEY_ALL_ACCESS, &hkey) != ERROR_SUCCESS) {
        hres = E_UNEXPECTED;
      }

      if (hres == S_OK &&
          RegOpenKeyEx(hkey, /* FIXME */ _T("1.0"), 0, KEY_ALL_ACCESS, &hkey_version) != ERROR_SUCCESS) {
        hres = E_UNEXPECTED;
      }

      if (hres == S_OK &&
          RegOpenKeyEx(hkey_version, _T("0"), 0, KEY_ALL_ACCESS, &hkey_lcid) != ERROR_SUCCESS) {
        hres = E_UNEXPECTED;
      }

      if (hres == S_OK &&
          /* NOTE: we explicitly need to use the wide-char version here */
          RegQueryValueW(hkey_lcid, L"win32", SWIG_typelib_path, &bytesRead) != ERROR_SUCCESS) {
        hres = E_UNEXPECTED;
      }

      if (hkey_typelib != NULL)
        CloseHandle(hkey_typelib);
      if (hkey != NULL)
        CloseHandle(hkey);
      if (hkey_version != NULL)
        CloseHandle(hkey_version);
      if (hkey_lcid != NULL)
        CloseHandle(hkey_lcid);
    }
#else
    GetModuleFileNameW(SWIGModule, SWIG_typelib_path, MAX_PATH + 1);
#endif

    if (hres == S_OK) {
      LoadTypeLib(SWIG_typelib_path, &SWIG_typelib);
    }
  } else if (fdwReason == DLL_PROCESS_DETACH) {
    if (SWIG_typelib != NULL) {
      /* Call release on the typelib */
      SWIGIUnknown *tlb_unknown = (SWIGIUnknown *) SWIG_typelib;
      ((long (SWIGSTDCALL *)(SWIGIUnknown *)) (tlb_unknown->vtable[2]))(tlb_unknown);
    }
  }

  return TRUE;
}


