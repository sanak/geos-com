Option Explicit

Dim geos
Set geos = WScript.CreateObject("geos.geos")

Dim results
results = ""

Sub assert(result, message)
	If result = False Then
		WScript.Echo "assert: " + message
		results = results + "x"
	Else
		results = results + "o"
	End If
End Sub

Sub assertEqual(expected, result, message)
	If expected = result Then
		results = results + "o"
	Else
		WScript.Echo "assertEqual: " + message + vbCrLf + "expected:" + vbTab + CStr(expected) + vbCrLf + "result:" + vbTab + CStr(result)
		results = results + "x"
	End If
End Sub

Sub report()
	If InStr(1, results, "x") > 0 Then
		WScript.Echo "Failed! - " + results
	Else
		WScript.Echo "Succeeded! - " + results
	End If
	results = ""
End Sub
