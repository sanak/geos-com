VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "TestVersion"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Sub Class_Initialize()
    setup "testVersions": testVersions
    report
End Sub

Public Sub testVersions()
    assertEqual "3.0.3-CAPI-1.4.2", geos.version, "geos.version"
    assertEqual 3, geos.GEOS_VERSION_MAJOR, "geos.GEOS_VERSION_MAJOR"
    assertEqual 0, geos.GEOS_VERSION_MINOR, "geos.GEOS_VERSION_MINOR"
    assertEqual 3, geos.GEOS_VERSION_PATCH, "geos.GEOS_VERSION_PATCH"
    assertEqual "3.0.3", geos.GEOS_VERSION, "geos.GEOS_VERSION"
    assertEqual "1.7.1", geos.GEOS_JTS_PORT, "geos.GEOS_JTS_PORT"
    assertEqual 1, geos.GEOS_CAPI_VERSION_MAJOR, "geos.GEOS_CAPI_VERSION_MAJOR"
    assertEqual 4, geos.GEOS_CAPI_VERSION_MINOR, "geos.GEOS_CAPI_VERSION_MINOR"
    assertEqual 2, geos.GEOS_CAPI_VERSION_PATCH, "geos.GEOS_CAPI_VERSION_PATCH"
End Sub

