Attribute VB_Name = "GeosTestsModule"
Option Explicit

Public geos As New geosTLB.geos

Private tests As New Scripting.Dictionary

Private current As String

Sub setup(name)
    tests.Add name, ""
    current = name
End Sub

Sub assert(result, message)
    If result = False Then
        tests(current) = tests(current) + "assert: " + message + vbCrLf
    End If
End Sub

Sub assertEqual(expected, result, message)
    If expected <> result Then
        tests(current) = tests(current) + _
         "assertEqual: " + message + vbCrLf + "expected:" + vbTab + CStr(expected) + vbCrLf + "result:" + vbTab + CStr(result) + vbCrLf
    End If
End Sub

Sub report()
    Dim sum, failures, result, message
    sum = 0
    failures = 0
    result = ""
    message = ""
    Dim name
    For Each name In tests.Keys
        sum = sum + 1
        If Len(tests(name)) > 0 Then
            failures = failures + 1
            message = message + vbCrLf + tests(name)
            result = result + "F"
        Else
            result = result + "."
        End If
    Next
    result = result + message + vbCrLf + CStr(sum) + " tests, " + CStr(failures) + " failures"
    GeosTestsForm.txtReport.Text = result
    tests.RemoveAll
End Sub


