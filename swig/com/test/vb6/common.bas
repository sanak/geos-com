Attribute VB_Name = "GeosTestsModule"
Option Explicit

Public geos As New geosTLB.geos
Private results As String

Public Sub assert(result, message)
    If result = False Then
        MsgBox "assert: " & message
        results = results & "x"
    Else
        results = results & "o"
    End If
End Sub

Public Sub assertEqual(expected, result, message)
    If expected <> result Then
        MsgBox "assertEqual: " & message & vbCrLf & "expected:" & vbTab & CStr(expected) & vbCrLf & "result:" & vbTab & CStr(result)
        results = results & "x"
    Else
        results = results & "o"
    End If
End Sub

Public Sub report()
    If InStr(1, results, "x") > 0 Then
        MsgBox "Failed! - " & results
    Else
        MsgBox "Succeeded! - " & results
    End If
    results = ""
End Sub
