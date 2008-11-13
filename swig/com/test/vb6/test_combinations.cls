VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "TestGeosCombinations"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private testHelper

Sub Class_Initialize()
    Set testHelper = New GeosTestHelper

    setup "testUnion": testUnion
    setup "testIntersection": testIntersection
    setup "testDifference": testDifference
    setup "testSymDifference": testSymDifference
    report
End Sub

Sub testUnion()
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            Set result = geoms1(i).Union(geoms2(j))
            ' TODO:
        Next
    Next
End Sub

Sub testIntersection()
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            Set result = geoms1(i).intersection(geoms2(j))
            ' TODO:
        Next
    Next
End Sub

Sub testDifference()
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            Set result = geoms1(i).difference(geoms2(j))
            ' TODO:
        Next
    Next
End Sub

Sub testSymDifference()
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            Set result = geoms1(i).symDifference(geoms2(j))
            ' TODO:
        Next
    Next
End Sub
