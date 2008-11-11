VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "TestGeosRelations"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Private Const X = -9999

Private testHelper

Sub Class_Initialize()
    Set testHelper = New GeosTestHelper
End Sub

Function getExpectedResult(value)
    ' 0 is False and 1 is True
    Select Case value
        Case 0
            getExpectedResult = False
        Case 1
            getExpectedResult = True
    End Select
End Function

Sub testContains()
    MsgBox "testContains"
    
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    Dim results
    results = Array( _
        Array(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0), _
        Array(X, X, X, X, X, X, X, 0, 0, 0, 0, X), _
        Array(0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1) _
    )
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            expected = getExpectedResult(results(i)(j))
            If IsEmpty(expected) Then
                'TODO:
            Else
                result = geoms1(i).contains(geoms2(j))
                assertEqual expected, result, "testContains(" + CStr(i) + ")(" + CStr(j) + ")"
            End If
        Next
    Next
    report
End Sub

Sub testCrosses()
    MsgBox "testCrosses"
    
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    Dim results
    results = Array( _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 1, 0, 0, 0, X, 1, 1, 1, 1, 0), _
        Array(0, 1, 0, 1, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 1, 0, 0, 0, X, 1, 1, 1, 1, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(X, X, X, X, X, X, X, X, X, X, X, X), _
        Array(0, 1, 0, 1, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 1, 0, 1, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 1, 0, 1, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 1, 0, 1, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0) _
    )
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            expected = getExpectedResult(results(i)(j))
            If IsEmpty(expected) Then
                'TODO:
            Else
                result = geoms1(i).crosses(geoms2(j))
                assertEqual expected, result, "testCrosses(" + CStr(i) + ")(" + CStr(j) + ")"
            End If
        Next
    Next
    report
End Sub

Sub testDisjoint()
    MsgBox "testDisjoint"
    
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    Dim results
    results = Array( _
        Array(0, 1, 1, 1, 1, 0, X, 1, 1, 1, 1, 1), _
        Array(1, 0, 0, 0, 1, 1, X, 0, 0, 0, 0, 1), _
        Array(1, 0, 0, 0, 1, 1, X, 1, 1, 1, 1, 1), _
        Array(1, 0, 0, 0, 1, 1, X, 0, 0, 0, 0, 1), _
        Array(1, 1, 1, 1, 0, 0, X, 1, 1, 1, 1, 1), _
        Array(0, 1, 1, 1, 0, 0, X, 1, 1, 1, 1, 1), _
        Array(X, X, X, X, X, X, X, X, X, X, X, X), _
        Array(1, 0, 1, 0, 1, 1, X, 0, 0, 0, 0, 1), _
        Array(1, 0, 1, 0, 1, 1, X, 0, 0, 0, 0, 1), _
        Array(1, 0, 1, 0, 1, 1, X, 0, 0, 0, 0, 1), _
        Array(1, 0, 1, 0, 1, 1, X, 0, 0, 0, 0, 1), _
        Array(1, 1, 1, 1, 1, 1, X, 1, 1, 1, 1, 0) _
    )
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            expected = getExpectedResult(results(i)(j))
            If IsEmpty(expected) Then
                'TODO:
            Else
                result = geoms1(i).disjoint(geoms2(j))
                assertEqual expected, result, "testDisjoint(" + CStr(i) + ")(" + CStr(j) + ")"
            End If
        Next
    Next
    report
End Sub

Sub testEquals()
    MsgBox "testEquals"
    
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    Dim results
    results = Array( _
        Array(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1) _
    )
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            expected = getExpectedResult(results(i)(j))
            If IsEmpty(expected) Then
                'TODO:
            Else
                result = geoms1(i).equals(geoms2(j))
                assertEqual expected, result, "testEquals(" + CStr(i) + ")(" + CStr(j) + ")"
            End If
        Next
    Next
    report
End Sub

Sub testEqualsExact()
    MsgBox "testEqualsExact"
    
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    Dim results
    results = Array( _
        Array(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1) _
    )
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            expected = getExpectedResult(results(i)(j))
            If IsEmpty(expected) Then
                'TODO:
            Else
                result = geoms1(i).equalsExact(geoms2(j), 0)
                assertEqual expected, result, "testEqualsExact(" + CStr(i) + ")(" + CStr(j) + ")"
            End If
        Next
    Next
    report
End Sub

Sub testIntersects()
    MsgBox "testIntersects"
    
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    Dim results
    results = Array( _
        Array(1, 0, 0, 0, 0, 1, X, 0, 0, 0, 0, 0), _
        Array(0, 1, 1, 1, 0, 0, X, 1, 1, 1, 1, 0), _
        Array(0, 1, 1, 1, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 1, 1, 1, 0, 0, X, 1, 1, 1, 1, 0), _
        Array(0, 0, 0, 0, 1, 1, X, 0, 0, 0, 0, 0), _
        Array(1, 0, 0, 0, 1, 1, X, 0, 0, 0, 0, 0), _
        Array(X, X, X, X, X, X, X, X, X, 1, 1, X), _
        Array(0, 1, 0, 1, 0, 0, X, 1, 1, 1, 1, 0), _
        Array(0, 1, 0, 1, 0, 0, X, 1, 1, 1, 1, 0), _
        Array(0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0), _
        Array(0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 1) _
    )
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            expected = getExpectedResult(results(i)(j))
            If IsEmpty(expected) Then
                'TODO:
            Else
                result = geoms1(i).intersects(geoms2(j))
                assertEqual expected, result, "testIntersects(" + CStr(i) + ")(" + CStr(j) + ")"
            End If
        Next
    Next
    report
End Sub

'   Sub testIsWithinDistance()
'       MsgBox "testIsWithinDistance"
'
'       Dim geoms1, geoms2
'       geoms1 = testHelper.createGeoms()
'       geoms2 = testHelper.createGeoms()
'       Dim results
'       results = Array( _
'           Array(1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0), _
'           Array(0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0), _
'           Array(0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0), _
'           Array(0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0), _
'           Array(0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0), _
'           Array(1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0), _
'           Array(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0), _
'           Array(0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0), _
'           Array(0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0), _
'           Array(0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0), _
'           Array(0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0), _
'           Array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1) _
'       )
'
'       Dim i, j
'       For i = LBound(geoms1) To UBound(geoms1)
'           For j = LBound(geoms2) To UBound(geoms2)
'               Dim expected, result
'               expected = getExpectedResult(results(i)(j))
'               If IsEmpty(expected) Then
'                   'TODO:
'               Else
'                   result = geoms1(i).isWithinDistance(geoms2(j))
'                   assertEqual expected, result, "testIsWithinDistance(" + CStr(i) + ")(" + CStr(j) + ")"
'               End If
'           Next
'       Next
'       report
'   End Sub

Sub testOverlaps()
    MsgBox "testOverlaps"
    
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    Dim results
    results = Array( _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 1, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 1, 0, X, 0, 0, 0, 0, 0), _
        Array(X, X, X, X, X, X, X, X, X, X, X, X), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 1, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 1, 0, 1, 1, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 1, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 1, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0) _
    )
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            expected = getExpectedResult(results(i)(j))
            If IsEmpty(expected) Then
                'TODO:
            Else
                result = geoms1(i).overlaps(geoms2(j))
                assertEqual expected, result, "testOverlaps(" + CStr(i) + ")(" + CStr(j) + ")"
            End If
        Next
    Next
    report
End Sub

Sub testRelatePattern()
    MsgBox "testRelatePattern"
    
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    Dim results
    results = Array( _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(X, X, X, X, X, X, X, X, X, X, X, X), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 1, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 1, 0, 1, 1, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 1, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 1, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0) _
    )
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            expected = getExpectedResult(results(i)(j))
            If IsEmpty(expected) Then
                'TODO:
            Else
                result = geoms1(i).relatePattern(geoms2(j), "212101212")
                assertEqual expected, result, "testRelatePattern(" + CStr(i) + ")(" + CStr(j) + ")"
            End If
        Next
    Next
    report
End Sub

Sub testRelate()
    MsgBox "testRelate"
    
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    Dim results
    results = Array( _
        Array("0FFFFFFF2", "FF0FFF1F2", "FF0FFF102", "FF0FFF1F2", "FF0FFF212", "F0FFFF212", Null, "FF0FFF212", "FF0FFF212", "FF0FFF212", "FF0FFF212", "FF0FFF102"), _
        Array("FF1FFF0F2", "1FFFFFFF2", "0F1FFF102", "1FFFFFFF2", "FF1FFF212", "FF1FFF212", Null, "101FFF212", "101FFF212", "101FFF212", "101FFF212", "FF1FFF102"), _
        Array("FF1FF00F2", "0F1FF01F2", "1FFF0FFF2", "0F1FF01F2", "FF1FF0212", "FF1FF0212", Null, "FF1FF0212", "FF1FF0212", "FF1FF0212", "FF1FF0212", "FF1FF0102"), _
        Array("FF1FFF0F2", "1FFFFFFF2", "0F1FFF102", "1FFFFFFF2", "FF1FFF212", "FF1FFF212", Null, "101FFF212", "101FFF212", "101FFF212", "101FFF212", "FF1FFF102"), _
        Array("FF2FF10F2", "FF2FF11F2", "FF2FF1102", "FF2FF11F2", "2FFF1FFF2", "212111212", Null, "FF2FF1212", "FF2FF1212", "FF2FF1212", "FF2FF1212", "FF2FF1102"), _
        Array("FF20F1FF2", "FF2FF11F2", "FF2FF1102", "FF2FF11F2", "212111212", "2FFF1FFF2", Null, "FF2FF1212", "FF2FF1212", "FF2FF1212", "FF2FF1212", "FF2FF1102"), _
        Array(Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null), _
        Array("FF2FF10F2", "1F20F11F2", "FF2FF1102", "1F20F11F2", "FF2FF1212", "FF2FF1212", Null, "2FFF1FFF2", "212101212", "2FF10F212", "2FF10F212", "FF2FF1102"), _
        Array("FF2FF10F2", "1F20F11F2", "FF2FF1102", "1F20F11F2", "FF2FF1212", "FF2FF1212", Null, "212101212", "2FFF1FFF2", "212101212", "212101212", "FF2FF1102"), _
        Array("FF2FF10F2", "1F20F11F2", "FF2FF1102", "1F20F11F2", "FF2FF1212", "FF2FF1212", Null, "212F01FF2", "212101212", "2FFF1FFF2", "2FF11F212", "FF2FF1102"), _
        Array("FF2FF10F2", "1F20F11F2", "FF2FF1102", "1F20F11F2", "FF2FF1212", "FF2FF1212", Null, "212F01FF2", "212101212", "212F11FF2", "2FFF1FFF2", "FF2FF1102"), _
        Array("FF1FF00F2", "FF1FF01F2", "FF1FF0102", "FF1FF01F2", "FF1FF0212", "FF1FF0212", Null, "FF1FF0212", "FF1FF0212", "FF1FF0212", "FF1FF0212", "1FFF0FFF2") _
    )
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            expected = results(i)(j)
            If IsNull(expected) Then
                'TODO:
            Else
                result = geoms1(i).relate(geoms2(j))
                assertEqual expected, result, "testRelate(" + CStr(i) + ")(" + CStr(j) + ")"
            End If
        Next
    Next
    report
End Sub

Sub testTouches()
    MsgBox "testTouches"
    
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    Dim results
    results = Array( _
        Array(0, 0, 0, 0, 0, 1, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(1, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(X, X, X, X, X, X, X, X, X, X, X, X), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0) _
    )
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            expected = getExpectedResult(results(i)(j))
            If IsEmpty(expected) Then
                'TODO:
            Else
                result = geoms1(i).touches(geoms2(j))
                assertEqual expected, result, "testTouches(" + CStr(i) + ")(" + CStr(j) + ")"
            End If
        Next
    Next
    report
End Sub

Sub testWithin()
    MsgBox "testWithin"
    
    Dim geoms1, geoms2
    geoms1 = testHelper.createGeoms()
    geoms2 = testHelper.createGeoms()
    Dim results
    results = Array( _
        Array(1, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 1, 0, 1, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 1, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 1, 0, 1, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 1, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 1, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0), _
        Array(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0), _
        Array(0, 0, 0, 0, 0, 0, X, 0, 0, 0, 0, 1) _
    )
    
    Dim i, j
    For i = LBound(geoms1) To UBound(geoms1)
        For j = LBound(geoms2) To UBound(geoms2)
            Dim expected, result
            expected = getExpectedResult(results(i)(j))
            If IsEmpty(expected) Then
                'TODO:
            Else
                result = geoms1(i).within(geoms2(j))
                assertEqual expected, result, "testWithin(" + CStr(i) + ")(" + CStr(j) + ")"
            End If
        Next
    Next
    report
End Sub
